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
#include "dogen/cpp/types/settings/bundle_repository.hpp"

namespace dogen {
namespace cpp {
namespace settings {

bundle_repository::bundle_repository(const std::unordered_map<dogen::sml::qname, dogen::cpp::settings::bundle>& bundles_by_qname)
    : bundles_by_qname_(bundles_by_qname) { }

void bundle_repository::swap(bundle_repository& other) noexcept {
    using std::swap;
    swap(bundles_by_qname_, other.bundles_by_qname_);
}

bool bundle_repository::operator==(const bundle_repository& rhs) const {
    return bundles_by_qname_ == rhs.bundles_by_qname_;
}

bundle_repository& bundle_repository::operator=(bundle_repository other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::unordered_map<dogen::sml::qname, dogen::cpp::settings::bundle>& bundle_repository::bundles_by_qname() const {
    return bundles_by_qname_;
}

std::unordered_map<dogen::sml::qname, dogen::cpp::settings::bundle>& bundle_repository::bundles_by_qname() {
    return bundles_by_qname_;
}

void bundle_repository::bundles_by_qname(const std::unordered_map<dogen::sml::qname, dogen::cpp::settings::bundle>& v) {
    bundles_by_qname_ = v;
}

void bundle_repository::bundles_by_qname(const std::unordered_map<dogen::sml::qname, dogen::cpp::settings::bundle>&& v) {
    bundles_by_qname_ = std::move(v);
}

} } }
