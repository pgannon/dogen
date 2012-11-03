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
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include "dogen/trivial_inheritance/serialization/child_of_a_child1_ser.hpp"
#include "dogen/trivial_inheritance/serialization/child_of_a_child2_ser.hpp"
#include "dogen/trivial_inheritance/serialization/parent_with_members_ser.hpp"
#include "dogen/trivial_inheritance/serialization/third_child_with_members_ser.hpp"

#ifdef __linux__
#include "eos/portable_iarchive.hpp"
#include "eos/portable_oarchive.hpp"
#endif

BOOST_CLASS_TRACKING(
    dogen::trivial_inheritance::third_child_with_members,
    boost::serialization::track_selectively)

namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar,
    const dogen::trivial_inheritance::third_child_with_members& v,
    const unsigned int /*version*/) {
    ar.template register_type<dogen::trivial_inheritance::child_of_a_child1>();
    ar.template register_type<dogen::trivial_inheritance::child_of_a_child2>();
    ar << make_nvp("parent_with_members", base_object<dogen::trivial_inheritance::parent_with_members>(v));

    ar << make_nvp("prop_1", v.prop_1_);
}

template<typename Archive>
void load(Archive& ar,
    dogen::trivial_inheritance::third_child_with_members& v,
    const unsigned int /*version*/) {
    ar.template register_type<dogen::trivial_inheritance::child_of_a_child1>();
    ar.template register_type<dogen::trivial_inheritance::child_of_a_child2>();
    ar >> make_nvp("parent_with_members", base_object<dogen::trivial_inheritance::parent_with_members>(v));

    ar >> make_nvp("prop_1", v.prop_1_);
}

} }

namespace boost {
namespace serialization {

template void save(archive::polymorphic_oarchive& ar, const dogen::trivial_inheritance::third_child_with_members& v, unsigned int version);
template void load(archive::polymorphic_iarchive& ar, dogen::trivial_inheritance::third_child_with_members& v, unsigned int version);

template void save(archive::text_oarchive& ar, const dogen::trivial_inheritance::third_child_with_members& v, unsigned int version);
template void load(archive::text_iarchive& ar, dogen::trivial_inheritance::third_child_with_members& v, unsigned int version);

template void save(archive::binary_oarchive& ar, const dogen::trivial_inheritance::third_child_with_members& v, unsigned int version);
template void load(archive::binary_iarchive& ar, dogen::trivial_inheritance::third_child_with_members& v, unsigned int version);

template void save(archive::xml_oarchive& ar, const dogen::trivial_inheritance::third_child_with_members& v, unsigned int version);
template void load(archive::xml_iarchive& ar, dogen::trivial_inheritance::third_child_with_members& v, unsigned int version);

#ifdef __linux__
template void save(eos::portable_oarchive& ar, const dogen::trivial_inheritance::third_child_with_members& v, unsigned int version);
template void load(eos::portable_iarchive& ar, dogen::trivial_inheritance::third_child_with_members& v, unsigned int version);
#endif

} }