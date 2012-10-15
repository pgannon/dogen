/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012 Kitanda <info@kitanda.co.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#include <functional>
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include "dogen/utility/io/list_io.hpp"
#include "dogen/utility/test/asserter.hpp"
#include "dogen/utility/test_data/validating_resolver.hpp"
#include "dogen/utility/test_data/tds_test_good.hpp"
#include "dogen/utility/test/logging.hpp"
#include "dogen/generator/backends/cpp/cpp_location_manager.hpp"
#include "dogen/generator/backends/cpp/cpp_location_request.hpp"
#include "dogen/generator/test/mock_settings_factory.hpp"
#include "dogen/generator/backends/cpp/cpp_inclusion_manager.hpp"

namespace  {

const std::string test_suite("inclusion_manager_spec");
const std::string test_module("generator");
const std::string domain("domain");
const std::string hash("hash");
const std::string test_data("test_data");
const std::string io("io");
const std::string database("database");
const std::string serialization("serialization");
const std::string versioned_key("versioned_key");
const std::string io_postfix("_io.hpp");
const std::string database_postfix("_db.hpp");
const std::string serialization_postfix("_ser.hpp");
const std::string hash_postfix("_hash.hpp");
const std::string test_data_postfix("_td.hpp");
const std::string one_pod_model_name("one_pod");
const std::string pod_parent_name("parent");
const std::string pod_name("pod0");
const std::string pod_child_name("child");
const boost::filesystem::path project_dir("project directory");
const boost::filesystem::path src_dir("source directory");
const boost::filesystem::path include_dir("include directory");

dogen::generator::config::cpp_settings mock_settings() {
    return dogen::generator::test::mock_settings_factory::
        build_cpp_settings(project_dir);
}

dogen::sml::pod
mock_pod(const std::string& type_name, const std::string& model_name) {
    dogen::sml::qualified_name qn;
    qn.model_name(model_name);
    qn.type_name(type_name);
    qn.meta_type(dogen::sml::meta_types::pod);

    dogen::sml::pod r;
    r.name(qn);
    r.generate(true);
    return r;
}

dogen::sml::model one_pod_model() {
    const auto p(mock_pod(pod_name, one_pod_model_name));
    const std::unordered_map<dogen::sml::qualified_name, dogen::sml::pod> pods {
        { p.name(), p }
    };
    dogen::sml::model r;
    r.name(one_pod_model_name);
    r.pods(pods);
    return r;
}

dogen::generator::backends::cpp::cpp_inclusion_manager
default_inclusion_manager(const dogen::sml::model& m) {
    const auto s(mock_settings());

    using namespace dogen::generator::backends::cpp;
    cpp_location_manager lm(m.name(), s);

    bool no_keys(false);
    bool integrated_io(false);
    bool no_io(false);
    return cpp_inclusion_manager(m, lm, no_keys, integrated_io, no_io);
}

typedef std::function<
    dogen::generator::backends::cpp::cpp_inclusion_manager
    (const dogen::sml::model&)
    > inclusion_manager_factory;

std::vector<std::list<std::string> >
includes_for_one_pod_model(dogen::generator::backends::cpp::cpp_facet_types ft,
    const inclusion_manager_factory& factory) {
    const auto m(one_pod_model());
    const auto pods(m.pods());
    BOOST_CHECK(pods.size() == 1);
    const auto p(pods.begin()->second);

    auto d(factory(m));
    std::vector<std::list<std::string> > r;
    r.reserve(4);

    using namespace dogen::generator::backends::cpp;
    const cpp_aspect_types main(cpp_aspect_types::main);
    r.push_back(d.user(p, ft,  cpp_file_types::header, main));
    r.push_back(d.system(p, ft,  cpp_file_types::header, main));

    r.push_back(d.user(p, ft,  cpp_file_types::implementation, main));
    r.push_back(d.system(p, ft,  cpp_file_types::implementation, main));
    return r;
}

const unsigned int header_user(0);
const unsigned int header_system(1);
const unsigned int implementation_user(2);
const unsigned int implementation_system(3);

}

using dogen::utility::test::asserter;

BOOST_AUTO_TEST_SUITE(inclusion_manager)

BOOST_AUTO_TEST_CASE(one_pod_model_with_default_includes_generates_expected_domain_includes) {
    SETUP_TEST_LOG_SOURCE("one_pod_model_with_default_includes_generates_expected_domain_includes");

    using namespace dogen::generator::backends::cpp;
    const auto i(includes_for_one_pod_model(cpp_facet_types::domain,
            default_inclusion_manager));

    // header
    const auto hu(i[header_user]);
    BOOST_LOG_SEV(lg, debug) << "header user dependencies: " << hu;
    BOOST_CHECK(hu.size() == 1);
    BOOST_CHECK(asserter::assert_contains(versioned_key, hu.front()));

    // FIXME: no iosfwd, expected with current impl
    const auto hs(i[header_system]);
    BOOST_LOG_SEV(lg, debug) << "header  system dependencies: " << hs;
    BOOST_CHECK(hs.empty());

    // implementation
    const auto iu(i[implementation_user]);
    BOOST_LOG_SEV(lg, debug) << "implementation user dependencies: " << iu;
    BOOST_CHECK(iu.size() == 2);
    std::string a(iu.front()), b(iu.back());
    if (!boost::ends_with(b, io_postfix))
        std::swap(a,b);

    BOOST_CHECK(asserter::assert_contains(pod_name, a));
    BOOST_CHECK(asserter::assert_contains(domain, a));

    BOOST_CHECK(asserter::assert_contains(versioned_key, b));
    BOOST_CHECK(asserter::assert_contains(io, b));

    const auto is(i[implementation_system]);
    BOOST_LOG_SEV(lg, debug) << "implementation system dependencies: " << is;
    BOOST_CHECK(is.empty());
}

BOOST_AUTO_TEST_CASE(one_pod_model_with_default_includes_generates_expected_io_includes) {
    SETUP_TEST_LOG_SOURCE("one_pod_model_with_default_includes_generates_expected_io_includes");

    using namespace dogen::generator::backends::cpp;
    const auto i(includes_for_one_pod_model(cpp_facet_types::io,
            default_inclusion_manager));

    // header
    const auto hu(i[header_user]);
    BOOST_LOG_SEV(lg, debug) << "header user dependencies: " << hu;
    BOOST_CHECK(hu.size() == 1);
    BOOST_CHECK(asserter::assert_contains(pod_name, hu.front()));
    BOOST_CHECK(asserter::assert_contains(domain, hu.front()));

    // FIXME: no iosfwd, expected with current code
    const auto hs(i[header_system]);
    BOOST_LOG_SEV(lg, debug) << "header system dependencies: " << hs;
    BOOST_CHECK(hs.empty());

    // implementation
    const auto iu(i[implementation_user]);
    BOOST_LOG_SEV(lg, debug) << "implementation user dependencies: " << iu;
    BOOST_CHECK(iu.size() == 1);
    BOOST_CHECK(asserter::assert_contains(pod_name, iu.front()));
    BOOST_CHECK(asserter::assert_contains(io, iu.front()));

    // FIXME: no ostream
    const auto is(i[implementation_system]);
    BOOST_LOG_SEV(lg, debug) << "implementation system dependencies: " << is;
    BOOST_CHECK(is.empty());
}

BOOST_AUTO_TEST_CASE(one_pod_model_with_default_includes_generates_expected_serialisation_includes) {
    SETUP_TEST_LOG_SOURCE("one_pod_model_with_default_includes_generates_expected_serialisation_includes");

    using namespace dogen::generator::backends::cpp;
    const auto i(includes_for_one_pod_model(cpp_facet_types::serialization,
            default_inclusion_manager));

    // header
    const auto hu(i[header_user]);
    BOOST_LOG_SEV(lg, debug) << "header user dependencies: "
                             << hu;
    BOOST_CHECK(hu.size() == 2);
    auto a(hu.front());
    auto b(hu.back());
    if (!boost::ends_with(b, serialization_postfix))
        std::swap(a,b);

    BOOST_CHECK(asserter::assert_contains(pod_name, a));
    BOOST_CHECK(asserter::assert_contains(domain, a));

    BOOST_CHECK(asserter::assert_contains(versioned_key, b));
    BOOST_CHECK(asserter::assert_contains(serialization, b));

    // FIXME: missing serialisation headers
    const auto hs(i[header_system]);
    BOOST_LOG_SEV(lg, debug) << "header system dependencies: " << hs;
    BOOST_CHECK(hs.empty());

    // implementation
    const auto iu(i[implementation_user]);
    BOOST_LOG_SEV(lg, debug) << "implementation user dependencies: " << iu;

    a = iu.front();
    BOOST_CHECK(boost::ends_with(a, serialization_postfix));
    BOOST_CHECK(asserter::assert_contains(pod_name, a));
    BOOST_CHECK(asserter::assert_contains(serialization, a));

    const auto is(i[implementation_system]);
    BOOST_LOG_SEV(lg, debug) << "implementation system dependencies: " << is;
    BOOST_CHECK(is.empty());
}

BOOST_AUTO_TEST_CASE(one_pod_model_with_default_includes_generates_expected_hash_includes) {
    SETUP_TEST_LOG_SOURCE("one_pod_model_with_default_includes_generates_expected_hash_includes");

    using namespace dogen::generator::backends::cpp;
    const auto i(includes_for_one_pod_model(cpp_facet_types::hash,
            default_inclusion_manager));

    // header
    const auto hu(i[header_user]);
    BOOST_LOG_SEV(lg, debug) << "header user dependencies: " << hu;
    BOOST_CHECK(hu.size() == 2);
    auto a(hu.front());
    auto b(hu.back());
    if (!boost::ends_with(b, hash_postfix))
        std::swap(a,b);

    BOOST_CHECK(asserter::assert_contains(pod_name, a));
    BOOST_CHECK(asserter::assert_contains(domain, a));

    BOOST_CHECK(asserter::assert_contains(versioned_key, b));
    BOOST_CHECK(asserter::assert_contains(hash, b));

    // FIXME: missing hash headers
    const auto hs(i[header_system]);
    BOOST_LOG_SEV(lg, debug) << "header system dependencies: " << hs;
    BOOST_CHECK(hs.empty());

    // implementation
    const auto iu(i[implementation_user]);
    BOOST_LOG_SEV(lg, debug) << "implementation user dependencies: " << iu;
    a = iu.front();
    BOOST_CHECK(boost::ends_with(a, hash_postfix));
    BOOST_CHECK(asserter::assert_contains(pod_name, a));
    BOOST_CHECK(asserter::assert_contains(hash, a));

    const auto is(i[implementation_system]);
    BOOST_LOG_SEV(lg, debug) << "implementation system dependencies: " << is;
    BOOST_CHECK(is.empty());
}

BOOST_AUTO_TEST_CASE(one_pod_model_with_default_includes_generates_expected_test_data_includes) {
    SETUP_TEST_LOG_SOURCE("one_pod_model_with_default_includes_generates_expected_test_data_includes");

    using namespace dogen::generator::backends::cpp;
    const auto i(includes_for_one_pod_model(cpp_facet_types::test_data,
            default_inclusion_manager));

    // header
    const auto hu(i[header_user]);
    BOOST_LOG_SEV(lg, debug) << "header user dependencies: " << hu;
    BOOST_CHECK(hu.size() == 1);

    BOOST_CHECK(asserter::assert_contains(pod_name, hu.front()));
    BOOST_CHECK(asserter::assert_contains(domain, hu.front()));

    const auto hs(i[header_system]);
    BOOST_LOG_SEV(lg, debug) << "header system dependencies: " << hs;
    BOOST_CHECK(hs.empty());

    // implementation
    const auto iu(i[implementation_user]);
    BOOST_LOG_SEV(lg, debug) << "implementation user dependencies: " << iu;
    BOOST_CHECK(iu.size() == 2);

    auto a(iu.front());
    auto b(iu.back());
    if (!boost::ends_with(b, test_data_postfix))
        std::swap(a,b);

    BOOST_CHECK(asserter::assert_contains(pod_name, a));
    BOOST_CHECK(asserter::assert_contains(test_data, a));

    BOOST_CHECK(asserter::assert_contains(versioned_key, b));
    BOOST_CHECK(asserter::assert_contains(test_data, b));

    const auto is(i[implementation_system]);
    BOOST_LOG_SEV(lg, debug) << "implementation system dependencies: " << is;
    BOOST_CHECK(is.empty());
}

BOOST_AUTO_TEST_CASE(one_pod_model_with_default_includes_generates_expected_database_includes) {
    SETUP_TEST_LOG_SOURCE("one_pod_model_with_default_includes_generates_expected_database_includes");

    using namespace dogen::generator::backends::cpp;
    const auto i(includes_for_one_pod_model(cpp_facet_types::database,
            default_inclusion_manager));

    // header
    const auto hu(i[header_user]);
    BOOST_LOG_SEV(lg, debug) << "header user dependencies: " << hu;
    BOOST_CHECK(hu.size() == 1);

    BOOST_CHECK(asserter::assert_contains(pod_name, hu.front()));
    BOOST_CHECK(asserter::assert_contains(domain, hu.front()));

    const auto hs(i[header_system]);
    BOOST_LOG_SEV(lg, debug) << "header system dependencies: " << hs;
    BOOST_CHECK(hs.empty());

    // implementation
    const auto iu(i[implementation_user]);
    BOOST_LOG_SEV(lg, debug) << "implementation user dependencies: " << iu;
    BOOST_CHECK(iu.size() == 1);

    const auto a(iu.front());
    BOOST_CHECK(boost::ends_with(a, database_postfix));
    BOOST_CHECK(asserter::assert_contains(pod_name, a));
    BOOST_CHECK(asserter::assert_contains(database, a));

    const auto is(i[implementation_system]);
    BOOST_LOG_SEV(lg, debug) << "implementation system dependencies: " << is;
    BOOST_CHECK(is.empty());
}

BOOST_AUTO_TEST_SUITE_END()
