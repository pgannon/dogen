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
#include <boost/lexical_cast.hpp>
#include <boost/throw_exception.hpp>
#include "dogen/utility/log/logger.hpp"
#include "dogen/sml/types/string_converter.hpp"
#include "dogen/cpp/io/formatters/file_types_io.hpp"
#include "dogen/cpp/io/formatters/path_ingredients_io.hpp"
#include "dogen/cpp/types/formatters/building_error.hpp"
#include "dogen/cpp/types/formatters/path_ingredients_factory.hpp"

using namespace dogen::utility::log;

namespace {

auto lg(logger_factory("cpp.formatters.path_ingredients_factory"));

const std::string unsupported_file_type("File type not supported: ");

}

namespace dogen {
namespace cpp {
namespace formatters {

path_ingredients path_ingredients_factory::make(const settings::selector& s,
    const formatter_interface& f, const sml::qname qn) const {

    BOOST_LOG_SEV(lg, debug) << "Creating path ingredients for: "
                             << sml::string_converter::convert(qn);
    path_ingredients r;
    r.file_type(f.file_type());

    const auto& cs(s.select_cpp_settings());
    r.split_project(cs.split_project());
    r.source_directory_name(cs.source_directory_name());
    r.include_directory_name(cs.include_directory_name());
    r.project_directory_path(cs.project_directory_path());
    r.source_directory_path(cs.source_directory_path());
    r.include_directory_path(cs.include_directory_path());

    const auto& fcts(s.select_global_facet_settings(f.facet_name()));
    if (cs.enable_facet_folders())
        r.facet_directory(fcts.directory());

    r.facet_postfix(fcts.postfix());

    const auto& fmts(s.select_global_formatter_settings(
            qn, f.formatter_name()));
    r.formatter_postfix(fmts.postfix());

    const auto ft(f.file_type());
    switch (ft) {
    case file_types::cpp_header:
        r.extension(cs.header_file_extension());
        break;
    case file_types::cpp_implementation:
        r.extension(cs.implementation_file_extension());
        break;
    default:
        BOOST_LOG_SEV(lg, error) << unsupported_file_type << ft;
        BOOST_THROW_EXCEPTION(building_error(unsupported_file_type +
                boost::lexical_cast<std::string>(ft)));
    }

    BOOST_LOG_SEV(lg, debug) << "Path ingredients: " << r;
    BOOST_LOG_SEV(lg, debug) << "Done creating path ingredients for: "
                             << sml::string_converter::convert(qn);
    return r;
}

} } }
