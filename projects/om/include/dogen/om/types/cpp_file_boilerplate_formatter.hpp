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
#ifndef DOGEN_OM_TYPES_CPP_FILE_BOILERPLATE_FORMATTER_HPP
#define DOGEN_OM_TYPES_CPP_FILE_BOILERPLATE_FORMATTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <iosfwd>
#include <string>
#include <boost/filesystem/path.hpp>
#include "dogen/om/types/licence.hpp"
#include "dogen/om/types/modeline.hpp"
#include "dogen/om/types/cpp_includes.hpp"

namespace dogen {
namespace om {

/**
 * @brief Formats all of the boilerplate content in a C++ file such as
 * licence, modeline, includes, etc.
 */
class cpp_file_boilerplate_formatter {
public:
    cpp_file_boilerplate_formatter() = default;
    cpp_file_boilerplate_formatter(
        const cpp_file_boilerplate_formatter&) = default;
    cpp_file_boilerplate_formatter& operator=(
        const cpp_file_boilerplate_formatter&) = delete;
    cpp_file_boilerplate_formatter(
        cpp_file_boilerplate_formatter&& rhs) = default;

private:
    /**
     * @brief Adds the formatted modeline to the content.
     */
    void add_modeline(std::list<std::string>& content, const modeline& m) const;

    /**
     * @brief Adds the formatted modeline to the content.
     */
    void add_marker(std::list<std::string>& content,
        const std::string& marker) const;

    /**
     * @brief Adds the formatted modeline to the content.
     */
    void add_licence(std::list<std::string>& content, const licence& l) const;

    /**
     * @brief Formats the file's preamble.
     *
     * The preamble is made up of the modeline, any potential code
     * generation marker and the licence.
     */
    void format_preamble(std::ostream& s, const licence& l, const modeline& m,
        const std::string& marker) const;

    /**
     * @brief Formats the file's postamble.
     *
     * The postamble is composed of a bottom modeline, if any.
     */
    void format_postamble(std::ostream& s, const modeline& m) const;

    /**
     * @brief Formats the starting part of the header guards.
     */
    void format_guards_begin(std::ostream& s,
        const boost::filesystem::path& relative_file_path) const;

    /**
     * @brief Formats the ending part of the header guards.
     */
    void format_guards_end(std::ostream& s,
        const boost::filesystem::path& relative_file_path) const;

public:
    /**
     * @brief Formats the initial section of boilerplate.
     */
    void format_begin(std::ostream& s, const licence& l, const modeline& m,
        const std::string& marker, const cpp_includes& i,
        const boost::filesystem::path& relative_file_path) const;

    /**
     * @brief Formats the end of the boilerplate.
     */
    void format_end(std::ostream& s, const modeline& m,
        const boost::filesystem::path& relative_file_path) const;
};

} }

#endif