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
#include "dogen/sml/test_data/qname_td.hpp"
#include "dogen/cpp/test_data/formattables/inclusion_dependencies_repository_td.hpp"

namespace {

dogen::sml::qname
create_dogen_sml_qname(const unsigned int position) {
    return dogen::sml::qname_generator::create(position);
}

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

std::list<std::string> create_std_list_std_string(unsigned int position) {
    std::list<std::string> r;
    for (unsigned int i(0); i < 4; ++i) {
        r.push_back(create_std_string(position + i));
    }
    return r;
}

std::unordered_map<std::string, std::list<std::string> > create_std_unordered_map_std_string_std_list_std_string_(unsigned int position) {
    std::unordered_map<std::string, std::list<std::string> > r;
    for (unsigned int i(0); i < 4; ++i) {
        r.insert(std::make_pair(create_std_string(position + i), create_std_list_std_string(position + i)));
    }
    return r;
}

std::unordered_map<dogen::sml::qname, std::unordered_map<std::string, std::list<std::string> > > create_std_unordered_map_dogen_sml_qname_std_unordered_map_std_string_std_list_std_string__(unsigned int position) {
    std::unordered_map<dogen::sml::qname, std::unordered_map<std::string, std::list<std::string> > > r;
    for (unsigned int i(0); i < 4; ++i) {
        r.insert(std::make_pair(create_dogen_sml_qname(position + i), create_std_unordered_map_std_string_std_list_std_string_(position + i)));
    }
    return r;
}

}

namespace dogen {
namespace cpp {
namespace formattables {

inclusion_dependencies_repository_generator::inclusion_dependencies_repository_generator() : position_(0) { }

void inclusion_dependencies_repository_generator::
populate(const unsigned int position, result_type& v) {
    v.inclusion_dependencies_by_qname(create_std_unordered_map_dogen_sml_qname_std_unordered_map_std_string_std_list_std_string__(position + 0));
}

inclusion_dependencies_repository_generator::result_type
inclusion_dependencies_repository_generator::create(const unsigned int position) {
    inclusion_dependencies_repository r;
    inclusion_dependencies_repository_generator::populate(position, r);
    return r;
}

inclusion_dependencies_repository_generator::result_type*
inclusion_dependencies_repository_generator::create_ptr(const unsigned int position) {
    inclusion_dependencies_repository* p = new inclusion_dependencies_repository();
    inclusion_dependencies_repository_generator::populate(position, *p);
    return p;
}

inclusion_dependencies_repository_generator::result_type
inclusion_dependencies_repository_generator::operator()() {
    return create(position_++);
}

} } }
