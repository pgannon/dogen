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
#include <boost/test/unit_test.hpp>
#include "dogen/utility/io/vector_io.hpp"
#include "dogen/utility/test/logging.hpp"
#include "dogen/utility/test/macros.hpp"
#include "dogen/utility/test/canned_tests.hpp"
#include "dogen/utility/test/eos_serialization_tester.hpp"
#include "dogen/test_models/eos_serialization/serialization/all_ser.hpp"
#include "dogen/test_models/test_model_sanitizer/register_eos_types.hpp"
#include "dogen/test_models/eos_serialization/types/all.hpp"

namespace {

const std::string empty;
const std::string test_module("test_model_sanitizer");
const std::string test_suite("eos_serialization");

class first_class_generator {
public:
    typedef dogen::test_models::eos_serialization::first_class result_type;

public:
    result_type operator()() {
        result_type r;
        r.public_attribute(15 + pos_++);
        return r;
    }

private:
    unsigned int pos_ = 0;
};

template<typename Sequence>
void eos_roundtrip_type() {
    Sequence sequence;
    sequence(); // throw the first one away
    dogen::utility::test::eos_serialization_tester<
        typename Sequence::result_type>::
        all_roundtrips_produce_the_same_entity(sequence());
}

}

namespace dogen {
namespace test_models {
namespace eos_serialization {

std::ostream& operator<<(std::ostream& o, const first_class& v) {
    o << "outputting first class: " << v.public_attribute() << std::endl;
    return o;
}

} } }

using namespace dogen::test_models::eos_serialization;
using namespace dogen::utility::test;

BOOST_AUTO_TEST_SUITE(eos_serialization)

BOOST_AUTO_TEST_CASE(validate_equality) {
    SETUP_TEST_LOG("validate_equality");
    test_equality<first_class_generator>();
}

BOOST_AUTO_TEST_CASE(validate_serialisation) {
    SETUP_TEST_LOG("validate_serialisation");
    eos_roundtrip_type<first_class_generator>();
}

BOOST_AUTO_TEST_CASE(validate_swap) {
    SETUP_TEST_LOG("validate_swap");
    test_swap<first_class_generator>();
}

BOOST_AUTO_TEST_CASE(validate_move_assignment_copy) {
    SETUP_TEST_LOG("validate_move_assignment_copy");
    test_move_assignment_copy<first_class_generator>();
}

BOOST_AUTO_TEST_SUITE_END()
