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
#ifndef DOGEN_CONFIG_TYPES_REFERENCE_HPP
#define DOGEN_CONFIG_TYPES_REFERENCE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <algorithm>
#include <boost/filesystem/path.hpp>
#include "dogen/config/serialization/reference_fwd_ser.hpp"

namespace dogen {
namespace config {

/**
 * @brief Reference to a model used by the target model.
 */
class reference final {
public:
    reference() = default;
    reference(const reference&) = default;
    ~reference() = default;

public:
    reference(reference&& rhs);

public:
    reference(
        const boost::filesystem::path& path,
        const std::string& external_module_path);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const reference& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, reference& v, unsigned int version);

public:
    /**
     * @brief Path to the model we're referring to.
     */
    /**@{*/
    const boost::filesystem::path& path() const;
    boost::filesystem::path& path();
    void path(const boost::filesystem::path& v);
    void path(const boost::filesystem::path&& v);
    /**@}*/

    /**
     * @brief External module path to dependent model.
     */
    /**@{*/
    const std::string& external_module_path() const;
    std::string& external_module_path();
    void external_module_path(const std::string& v);
    void external_module_path(const std::string&& v);
    /**@}*/

public:
    bool operator==(const reference& rhs) const;
    bool operator!=(const reference& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(reference& other) noexcept;
    reference& operator=(reference other);

private:
    boost::filesystem::path path_;
    std::string external_module_path_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::config::reference& lhs,
    dogen::config::reference& rhs) {
    lhs.swap(rhs);
}

}

#endif
