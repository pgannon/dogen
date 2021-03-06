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
#include "dogen/config/test_data/archive_types_td.hpp"
#include "dogen/config/test_data/troubleshooting_options_td.hpp"

namespace {

boost::filesystem::path
create_boost_filesystem_path(const unsigned int position) {
    std::ostringstream s;
    s << "/a/path/number_" << position;
    return boost::filesystem::path(s.str());
}

dogen::config::archive_types
create_dogen_config_archive_types(const unsigned int position) {
    return dogen::config::archive_types_generator::create(position);
}

bool create_bool(const unsigned int position) {
    return (position % 2) == 0;
}

}

namespace dogen {
namespace config {

troubleshooting_options_generator::troubleshooting_options_generator() : position_(0) { }

void troubleshooting_options_generator::
populate(const unsigned int position, result_type& v) {
    v.debug_dir(create_boost_filesystem_path(position + 0));
    v.save_dia_model(create_dogen_config_archive_types(position + 1));
    v.save_sml_model(create_dogen_config_archive_types(position + 2));
    v.stop_after_formatting(create_bool(position + 3));
    v.stop_after_merging(create_bool(position + 4));
}

troubleshooting_options_generator::result_type
troubleshooting_options_generator::create(const unsigned int position) {
    troubleshooting_options r;
    troubleshooting_options_generator::populate(position, r);
    return r;
}

troubleshooting_options_generator::result_type*
troubleshooting_options_generator::create_ptr(const unsigned int position) {
    troubleshooting_options* p = new troubleshooting_options();
    troubleshooting_options_generator::populate(position, *p);
    return p;
}

troubleshooting_options_generator::result_type
troubleshooting_options_generator::operator()() {
    return create(position_++);
}

} }
