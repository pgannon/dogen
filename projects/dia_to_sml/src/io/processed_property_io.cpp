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
#include <boost/algorithm/string.hpp>
#include "dogen/dia_to_sml/io/processed_comment_io.hpp"
#include "dogen/dia_to_sml/io/processed_property_io.hpp"

inline std::string tidy_up_string(std::string s) {
    boost::replace_all(s, "\r\n", "<new_line>");
    boost::replace_all(s, "\n", "<new_line>");
    boost::replace_all(s, "\"", "<quote>");
    return s;
}

namespace dogen {
namespace dia_to_sml {

std::ostream& operator<<(std::ostream& s, const processed_property& v) {
    s << " { "
      << "\"__type__\": " << "\"dogen::dia_to_sml::processed_property\"" << ", "
      << "\"name\": " << "\"" << tidy_up_string(v.name()) << "\"" << ", "
      << "\"type\": " << "\"" << tidy_up_string(v.type()) << "\"" << ", "
      << "\"comment\": " << v.comment()
      << " }";
    return(s);
}

} }
