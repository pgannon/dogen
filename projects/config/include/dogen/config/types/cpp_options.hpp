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
#ifndef DOGEN_CONFIG_TYPES_CPP_OPTIONS_HPP
#define DOGEN_CONFIG_TYPES_CPP_OPTIONS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <boost/filesystem/path.hpp>
#include "dogen/config/serialization/cpp_options_fwd_ser.hpp"

namespace dogen {
namespace config {

/**
 * @brief Options for C++ code generation.
 */
class cpp_options final {
public:
    cpp_options(const cpp_options&) = default;
    ~cpp_options() = default;

public:
    cpp_options();

public:
    cpp_options(cpp_options&& rhs);

public:
    cpp_options(
        const bool split_project,
        const boost::filesystem::path& project_directory_path,
        const boost::filesystem::path& source_directory_path,
        const boost::filesystem::path& include_directory_path,
        const bool disable_cmakelists);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_options& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_options& v, unsigned int version);

public:
    /**
     * @brief If true, project is split into source and include
     * directories, both configurable.
     *
     * If false, there is only a single top-level directory for the
     * entire project, containing as sub-directories both the source
     * and include directories.
     */
    /**@{*/
    bool split_project() const;
    void split_project(const bool v);
    /**@}*/

    /**
     * @brief Path to the directory in which to place all of the C++ code.
     *
     * Implies project splitting is off.
     */
    /**@{*/
    const boost::filesystem::path& project_directory_path() const;
    boost::filesystem::path& project_directory_path();
    void project_directory_path(const boost::filesystem::path& v);
    void project_directory_path(const boost::filesystem::path&& v);
    /**@}*/

    /**
     * @brief Path to the directory in which to place the C++ implementation files.
     *
     * Can only be supplied if split project is set to true.
     */
    /**@{*/
    const boost::filesystem::path& source_directory_path() const;
    boost::filesystem::path& source_directory_path();
    void source_directory_path(const boost::filesystem::path& v);
    void source_directory_path(const boost::filesystem::path&& v);
    /**@}*/

    /**
     * @brief Path to the directory in which to place the C++ header files.
     *
     * Can only be supplied if split project is set to true.
     */
    /**@{*/
    const boost::filesystem::path& include_directory_path() const;
    boost::filesystem::path& include_directory_path();
    void include_directory_path(const boost::filesystem::path& v);
    void include_directory_path(const boost::filesystem::path&& v);
    /**@}*/

    /**
     * @brief Do not generate CMakeLists.txt for C++ projects.
     */
    /**@{*/
    bool disable_cmakelists() const;
    void disable_cmakelists(const bool v);
    /**@}*/

public:
    bool operator==(const cpp_options& rhs) const;
    bool operator!=(const cpp_options& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(cpp_options& other) noexcept;
    cpp_options& operator=(cpp_options other);

private:
    bool split_project_;
    boost::filesystem::path project_directory_path_;
    boost::filesystem::path source_directory_path_;
    boost::filesystem::path include_directory_path_;
    bool disable_cmakelists_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::config::cpp_options& lhs,
    dogen::config::cpp_options& rhs) {
    lhs.swap(rhs);
}

}

#endif
