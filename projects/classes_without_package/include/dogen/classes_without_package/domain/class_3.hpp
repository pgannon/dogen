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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. Seethe
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General PublicLicense
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#ifndef DOGEN_CLASSES_WITHOUT_PACKAGE_DOMAIN_CLASS_3_HPP
#define DOGEN_CLASSES_WITHOUT_PACKAGE_DOMAIN_CLASS_3_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <iosfwd>
#include "dogen/classes_without_package/domain/versioned_key.hpp"

namespace dogen {
namespace classes_without_package {

class class_3_serializer;

class class_3 {
public:
    class_3() = default;
    class_3(const class_3&) = default;
    ~class_3() = default;
    class_3(class_3&&) = default;

public:
    explicit class_3(dogen::classes_without_package::versioned_key versioned_key);

public:
    friend class dogen::classes_without_package::class_3_serializer;

public:
    void to_stream(std::ostream& stream) const;

public:
    dogen::classes_without_package::versioned_key versioned_key() const {
        return versioned_key_;
    }

    void versioned_key(dogen::classes_without_package::versioned_key value) {
        versioned_key_ = value;
    }

public:
    bool operator==(const class_3& rhs) const {
        return versioned_key_ == rhs.versioned_key_;
    }

    bool operator!=(const class_3 rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(class_3& other);
    class_3& operator=(class_3 other);

private:
    dogen::classes_without_package::versioned_key versioned_key_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::classes_without_package::class_3& lhs,
    dogen::classes_without_package::class_3& rhs) {
    lhs.swap(rhs);
}

}

#endif
