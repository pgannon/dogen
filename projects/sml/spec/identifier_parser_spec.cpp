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
#include <sstream>
#include <boost/test/unit_test.hpp>
#include "dogen/utility/test/logging.hpp"
#include "dogen/utility/test/asserter.hpp"
#include "dogen/utility/io/list_io.hpp"
#include "dogen/sml/types/model.hpp"
#include "dogen/sml/types/parsing_error.hpp"
#include "dogen/sml/io/nested_qname_io.hpp"
#include "dogen/sml/io/qname_io.hpp"
#include "dogen/sml/types/merging_error.hpp"
#include "dogen/sml/types/identifier_parser.hpp"
#include "dogen/sml/types/merger.hpp"
#include "dogen/utility/test/exception_checkers.hpp"

using dogen::utility::test::asserter;

namespace  {

const std::string empty;
const std::string test_module("sml");
const std::string test_suite("identifier_parser_spec");

bool test_primitive(const std::string& s) {
    dogen::sml::identifier_parser ip;
    const auto a(ip.parse_qname(s));

    dogen::sml::nested_qname nqn;
    dogen::sml::qname e;
    e.simple_name(s);
    nqn.type(e);
    return asserter::assert_equals(nqn, a);
}

}

using dogen::sml::parsing_error;

BOOST_AUTO_TEST_SUITE(identifier_parser)

BOOST_AUTO_TEST_CASE(parsing_string_with_many_nested_scopes_produces_expected_qname) {
    SETUP_TEST_LOG_SOURCE("parsing_string_with_many_nested_scopes_produces_expected_qname");
    const std::string s("a::b::c::z");
    BOOST_LOG_SEV(lg, info) << "input: " << s;

    dogen::sml::identifier_parser ip;
    const auto a(ip.parse_qname(s));

    dogen::sml::nested_qname nqn;
    dogen::sml::qname e;
    e.simple_name("z");
    e.module_path(std::list<std::string> { "b", "c"});
    e.model_name("a");
    nqn.type(e);
    BOOST_CHECK(asserter::assert_equals(nqn, a));
}

BOOST_AUTO_TEST_CASE(parsing_string_without_scope_operator_produces_expected_qname) {
    SETUP_TEST_LOG_SOURCE("parsing_string_without_scope_operator_produces_expected_qname");
    const std::string s("zeta");
    BOOST_LOG_SEV(lg, info) << "input: " << s;

    dogen::sml::identifier_parser ip;
    const auto a(ip.parse_qname(s));

    dogen::sml::nested_qname nqn;
    dogen::sml::qname e;
    e.simple_name("zeta");
    nqn.type(e);
    BOOST_CHECK(asserter::assert_equals(nqn, a));
}

BOOST_AUTO_TEST_CASE(parsing_string_with_one_scope_operator_produces_expected_qname) {
    SETUP_TEST_LOG_SOURCE("parsing_string_with_one_scope_operator_produces_expected_qname");
    const std::string s("a::z");
    BOOST_LOG_SEV(lg, info) << "input: " << s;

    dogen::sml::identifier_parser ip;
    const auto a(ip.parse_qname(s));

    dogen::sml::nested_qname nqn;
    dogen::sml::qname e;
    e.model_name("a");
    e.simple_name("z");
    nqn.type(e);
    BOOST_CHECK(asserter::assert_equals(nqn, a));
}

BOOST_AUTO_TEST_CASE(parsing_string_with_single_colon_fails_to_parse) {
    SETUP_TEST_LOG_SOURCE("parsing_string_with_single_colon_fails_to_parse");
    const std::string s("a:z");
    BOOST_LOG_SEV(lg, info) << "input: " << s;
    dogen::sml::identifier_parser ip;
    BOOST_CHECK_THROW(ip.parse_qname(s), parsing_error);
}

BOOST_AUTO_TEST_CASE(string_starting_with_digit_fails_to_parse) {
    SETUP_TEST_LOG_SOURCE("string_starting_with_digit_fails_to_parse");
    const std::string s("0a");
    BOOST_LOG_SEV(lg, info) << "input: " << s;
    dogen::sml::identifier_parser ip;
    BOOST_CHECK_THROW(ip.parse_qname(s), parsing_error);
}

BOOST_AUTO_TEST_CASE(string_ending_with_scope_operator_fails_to_parse) {
    SETUP_TEST_LOG_SOURCE("string_ending_with_scope_operator_fails_to_parse");
    const std::string s("a::");
    BOOST_LOG_SEV(lg, info) << "input: " << s;
    dogen::sml::identifier_parser ip;
    BOOST_CHECK_THROW(ip.parse_qname(s), parsing_error);
}

BOOST_AUTO_TEST_CASE(scope_operator_followed_by_scope_operator_fails_to_parse) {
    SETUP_TEST_LOG_SOURCE("scope_operator_followed_by_scope_operator_fails_to_parse");
    const std::string s("A::::");
    BOOST_LOG_SEV(lg, info) << "input: " << s;
    dogen::sml::identifier_parser ip;
    BOOST_CHECK_THROW(ip.parse_qname(s), parsing_error);
}

BOOST_AUTO_TEST_CASE(all_primitive_types_are_valid) {
    SETUP_TEST_LOG("all_primitive_types_are_valid");

    BOOST_CHECK(test_primitive("char"));
    BOOST_CHECK(test_primitive("unsigned char"));
    BOOST_CHECK(test_primitive("wchar_t"));
    BOOST_CHECK(test_primitive("unsigned wchar_t"));
    BOOST_CHECK(test_primitive("bool"));
    BOOST_CHECK(test_primitive("short"));
    BOOST_CHECK(test_primitive("unsigned short"));
    BOOST_CHECK(test_primitive("int"));
    BOOST_CHECK(test_primitive("unsigned int"));
    BOOST_CHECK(test_primitive("long"));
    BOOST_CHECK(test_primitive("unsigned long"));
    BOOST_CHECK(test_primitive("long long"));
    BOOST_CHECK(test_primitive("unsigned long long"));
    BOOST_CHECK(test_primitive("void"));
    BOOST_CHECK(test_primitive("float"));
    BOOST_CHECK(test_primitive("double"));
}

BOOST_AUTO_TEST_CASE(unsignable_types_cannot_be_unsigned) {
    SETUP_TEST_LOG("unsignable_types_cannot_be_unsigned");
    dogen::sml::identifier_parser ip;
    BOOST_CHECK_THROW(ip.parse_qname("unsigned bool"), parsing_error);
    BOOST_CHECK_THROW(ip.parse_qname("unsigned x"), parsing_error);
    BOOST_CHECK_THROW(ip.parse_qname("unsigned float"), parsing_error);
    BOOST_CHECK_THROW(ip.parse_qname("unsigned double"), parsing_error);
}

BOOST_AUTO_TEST_CASE(parsing_string_with_single_template_argument_produces_expected_nested_qnames) {
    SETUP_TEST_LOG_SOURCE("parsing_string_with_single_template_argument_produces_expected_nested_qnames");

    dogen::sml::identifier_parser ip;
    dogen::sml::nested_qname nqn;
    dogen::sml::qname e;
    e.simple_name("type");
    nqn.type(e);

    dogen::sml::qname f;
    f.simple_name("abc");
    dogen::sml::nested_qname c;
    c.type(f);
    nqn.children(std::list<dogen::sml::nested_qname> { c });

    const auto a(ip.parse_qname("type<abc>"));
    BOOST_CHECK(asserter::assert_equals(nqn, a));
}

BOOST_AUTO_TEST_CASE(parsing_string_with_two_template_argument_produces_expected_nested_qnames) {
    SETUP_TEST_LOG_SOURCE("parsing_string_with_two_template_argument_produces_expected_nested_qnames");
    dogen::sml::identifier_parser ip;
    dogen::sml::nested_qname nqn;
    dogen::sml::qname e;
    e.simple_name("type");
    nqn.type(e);

    dogen::sml::qname f;
    f.simple_name("abc");
    dogen::sml::nested_qname c;
    c.type(f);

    dogen::sml::qname g;
    g.simple_name("cde");
    dogen::sml::nested_qname d;
    d.type(g);
    nqn.children(std::list<dogen::sml::nested_qname> { c, d });

    const std::string s("type<abc,cde>");
    BOOST_LOG_SEV(lg, info) << "input: " << s;

    const auto a(ip.parse_qname(s));
    BOOST_CHECK(asserter::assert_equals(nqn, a));
}

BOOST_AUTO_TEST_CASE(parsing_vector_of_string_produces_expected_nested_qnames) {
    SETUP_TEST_LOG_SOURCE("parsing_vector_of_string_produces_expected_nested_qnames");
    dogen::sml::identifier_parser ip;
    dogen::sml::nested_qname nqn;
    dogen::sml::qname e;
    e.simple_name("vector");
    e.model_name("std");
    nqn.type(e);

    dogen::sml::qname f;
    f.simple_name("string");
    f.model_name("std");
    dogen::sml::nested_qname c;
    c.type(f);
    nqn.children(std::list<dogen::sml::nested_qname> { c });

    const std::string s("std::vector<std::string>");
    BOOST_LOG_SEV(lg, info) << "input: " << s;

    const auto a(ip.parse_qname(s));
    BOOST_CHECK(asserter::assert_equals(nqn, a));
}

BOOST_AUTO_TEST_CASE(parsing_vector_of_primitive_produces_expected_nested_qnames) {
    SETUP_TEST_LOG_SOURCE("parsing_vector_of_primitive_produces_expected_nested_qnames");
    dogen::sml::identifier_parser ip;
    dogen::sml::nested_qname nqn;
    dogen::sml::qname e;
    e.simple_name("vector");
    e.model_name("std");
    nqn.type(e);

    dogen::sml::qname f;
    f.simple_name("unsigned int");
    dogen::sml::nested_qname c;
    c.type(f);
    nqn.children(std::list<dogen::sml::nested_qname> { c });

    const std::string s("std::vector<unsigned int>");
    BOOST_LOG_SEV(lg, info) << "input: " << s;

    const auto a(ip.parse_qname(s));
    BOOST_CHECK(asserter::assert_equals(nqn, a));
}

BOOST_AUTO_TEST_CASE(parsing_unordered_map_produces_expected_nested_qnames) {
    SETUP_TEST_LOG_SOURCE("parsing_unordered_map_produces_expected_nested_qnames");
    dogen::sml::identifier_parser ip;
    dogen::sml::nested_qname nqn;
    dogen::sml::qname e;
    e.simple_name("unordered_map");
    e.model_name("std");
    nqn.type(e);

    dogen::sml::qname f;
    f.simple_name("string");
    f.model_name("std");
    dogen::sml::nested_qname c;
    c.type(f);
    dogen::sml::qname g;
    g.simple_name("type");
    g.model_name("my");
    dogen::sml::nested_qname d;
    d.type(g);

    nqn.children(std::list<dogen::sml::nested_qname> { c, d });

    const std::string s1("std::unordered_map<std::string,my::type>");
    BOOST_LOG_SEV(lg, info) << "input: " << s1;
    const auto a1(ip.parse_qname(s1));
    BOOST_CHECK(asserter::assert_equals(nqn, a1));

    const std::string s2("std::unordered_map<std::string,    my::type>");
    BOOST_LOG_SEV(lg, info) << "input: " << s2;
    const auto a2(ip.parse_qname(s2));
    BOOST_CHECK(asserter::assert_equals(nqn, a2));
}

BOOST_AUTO_TEST_CASE(parsing_vector_of_shared_ptr_produces_expected_nested_qnames) {
    SETUP_TEST_LOG_SOURCE("parsing_vector_of_shared_ptr_produces_expected_nested_qnames");
    dogen::sml::identifier_parser ip;
    dogen::sml::nested_qname nqn;
    dogen::sml::qname e;
    e.simple_name("vector");
    e.model_name("std");
    nqn.type(e);

    dogen::sml::qname f;
    f.simple_name("shared_ptr");
    f.model_name("std");
    dogen::sml::nested_qname c;
    c.type(f);

    dogen::sml::qname g;
    g.simple_name("string");
    g.model_name("std");
    dogen::sml::nested_qname d;
    d.type(g);
    c.children(std::list<dogen::sml::nested_qname> { d });
    nqn.children(std::list<dogen::sml::nested_qname> { c });

    const std::string s("std::vector<std::shared_ptr<std::string>>");
    BOOST_LOG_SEV(lg, info) << "input: " << s;

    const auto a(ip.parse_qname(s));
    BOOST_CHECK(asserter::assert_equals(nqn, a));
}

BOOST_AUTO_TEST_CASE(names_that_partially_match_primitives_produce_expected_nested_qname) {
    SETUP_TEST_LOG("names_that_partially_match_primitives_produce_expected_nested_qname");

    BOOST_CHECK(test_primitive("character"));
    BOOST_CHECK(test_primitive("cha"));
    BOOST_CHECK(test_primitive("wchar_test"));
    BOOST_CHECK(test_primitive("wcha"));
    BOOST_CHECK(test_primitive("boolean"));
    BOOST_CHECK(test_primitive("boo"));
    BOOST_CHECK(test_primitive("shorter"));
    BOOST_CHECK(test_primitive("shor"));
    BOOST_CHECK(test_primitive("integer"));
    BOOST_CHECK(test_primitive("in"));
    BOOST_CHECK(test_primitive("voidest"));
    BOOST_CHECK(test_primitive("voi"));
    BOOST_CHECK(test_primitive("floating"));
    BOOST_CHECK(test_primitive("floa"));
    BOOST_CHECK(test_primitive("doubler"));
    BOOST_CHECK(test_primitive("doubl"));
}

BOOST_AUTO_TEST_SUITE_END()
