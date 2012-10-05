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
#ifndef DOGEN_CLASSES_WITHOUT_PACKAGE_SERIALIZATION_VERSIONED_KEY_SER_HPP
#define DOGEN_CLASSES_WITHOUT_PACKAGE_SERIALIZATION_VERSIONED_KEY_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/nvp.hpp>
#include "dogen/classes_without_package/domain/versioned_key.hpp"

namespace dogen {
namespace classes_without_package {

class versioned_key_serializer {
public:
    template<typename Archive>
    void serialize(Archive & archive,
        dogen::classes_without_package::versioned_key& value,
        const unsigned int /*version*/) {
        using boost::serialization::make_nvp;

        archive & make_nvp("id", value.id_);
        archive & make_nvp("version", value.version_);
    }
};

} }

namespace boost {
namespace serialization {

template<class Archive>
inline void serialize(Archive & archive,
    dogen::classes_without_package::versioned_key& value,
    const unsigned int version) {
    dogen::classes_without_package::versioned_key_serializer serializer;
    serializer.serialize<Archive>(archive, value, version);
}

} }

#endif
