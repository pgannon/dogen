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
#include "dogen/frontend/types/frontend_settings.hpp"

namespace dogen {
namespace frontend {

frontend_settings::frontend_settings()
    : save_pre_processed_input_(static_cast<bool>(0)) { }

frontend_settings::frontend_settings(frontend_settings&& rhs)
    : save_pre_processed_input_(std::move(rhs.save_pre_processed_input_)),
      pre_processed_input_path_(std::move(rhs.pre_processed_input_path_)) { }

frontend_settings::frontend_settings(
    const bool save_pre_processed_input,
    const boost::filesystem::path& pre_processed_input_path)
    : save_pre_processed_input_(save_pre_processed_input),
      pre_processed_input_path_(pre_processed_input_path) { }

void frontend_settings::swap(frontend_settings& other) noexcept {
    using std::swap;
    swap(save_pre_processed_input_, other.save_pre_processed_input_);
    swap(pre_processed_input_path_, other.pre_processed_input_path_);
}

bool frontend_settings::operator==(const frontend_settings& rhs) const {
    return save_pre_processed_input_ == rhs.save_pre_processed_input_ &&
        pre_processed_input_path_ == rhs.pre_processed_input_path_;
}

frontend_settings& frontend_settings::operator=(frontend_settings other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

bool frontend_settings::save_pre_processed_input() const {
    return save_pre_processed_input_;
}

void frontend_settings::save_pre_processed_input(const bool v) {
    save_pre_processed_input_ = v;
}

const boost::filesystem::path& frontend_settings::pre_processed_input_path() const {
    return pre_processed_input_path_;
}

boost::filesystem::path& frontend_settings::pre_processed_input_path() {
    return pre_processed_input_path_;
}

void frontend_settings::pre_processed_input_path(const boost::filesystem::path& v) {
    pre_processed_input_path_ = v;
}

void frontend_settings::pre_processed_input_path(const boost::filesystem::path&& v) {
    pre_processed_input_path_ = std::move(v);
}

} }
