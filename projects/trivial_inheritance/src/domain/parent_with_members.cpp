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
#include <ostream>
#include "dogen/trivial_inheritance/domain/parent_with_members.hpp"
#include "dogen/trivial_inheritance/io/versioned_key_io.hpp"

namespace dogen {
namespace trivial_inheritance {

parent_with_members::parent_with_members()
    : prop_0_(static_cast<int>(0)) { }

parent_with_members::parent_with_members(
    const int prop_0,
    const dogen::trivial_inheritance::versioned_key& versioned_key)
    : prop_0_(prop_0),
      versioned_key_(versioned_key) { }

void parent_with_members::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"parent_with_members\"" << ", "
      << "\"prop_0\": " << prop_0_ << ", "
      << "\"versioned_key\": " << versioned_key_
      << " }";
}

void parent_with_members::swap(parent_with_members& other) noexcept {
    using std::swap;
    swap(prop_0_, other.prop_0_);
    swap(versioned_key_, other.versioned_key_);
}

bool parent_with_members::compare(const parent_with_members& rhs) const {
    return prop_0_ == rhs.prop_0_ &&
        versioned_key_ == rhs.versioned_key_;
}

} }