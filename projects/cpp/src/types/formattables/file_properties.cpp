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
#include "dogen/cpp/types/formattables/file_properties.hpp"

namespace dogen {
namespace cpp {
namespace formattables {

file_properties::file_properties(file_properties&& rhs)
    : relative_path_(std::move(rhs.relative_path_)),
      includes_(std::move(rhs.includes_)) { }

file_properties::file_properties(
    const boost::filesystem::path& relative_path,
    const dogen::cpp::formattables::includes& includes)
    : relative_path_(relative_path),
      includes_(includes) { }

void file_properties::swap(file_properties& other) noexcept {
    using std::swap;
    swap(relative_path_, other.relative_path_);
    swap(includes_, other.includes_);
}

bool file_properties::operator==(const file_properties& rhs) const {
    return relative_path_ == rhs.relative_path_ &&
        includes_ == rhs.includes_;
}

file_properties& file_properties::operator=(file_properties other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const boost::filesystem::path& file_properties::relative_path() const {
    return relative_path_;
}

boost::filesystem::path& file_properties::relative_path() {
    return relative_path_;
}

void file_properties::relative_path(const boost::filesystem::path& v) {
    relative_path_ = v;
}

void file_properties::relative_path(const boost::filesystem::path&& v) {
    relative_path_ = std::move(v);
}

const dogen::cpp::formattables::includes& file_properties::includes() const {
    return includes_;
}

dogen::cpp::formattables::includes& file_properties::includes() {
    return includes_;
}

void file_properties::includes(const dogen::cpp::formattables::includes& v) {
    includes_ = v;
}

void file_properties::includes(const dogen::cpp::formattables::includes&& v) {
    includes_ = std::move(v);
}

} } }