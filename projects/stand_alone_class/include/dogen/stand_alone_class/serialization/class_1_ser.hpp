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
#ifndef DOGEN_STAND_ALONE_CLASS_SERIALIZATION_CLASS_1_SER_HPP
#define DOGEN_STAND_ALONE_CLASS_SERIALIZATION_CLASS_1_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/nvp.hpp>
#include "dogen/stand_alone_class/domain/class_1.hpp"
#include "dogen/stand_alone_class/serialization/versioned_key_ser.hpp"

namespace dogen {
namespace stand_alone_class {

class class_1_serializer {
public:
    template<typename Archive>
    void serialize(Archive & archive,
        dogen::stand_alone_class::class_1& value,
        const unsigned int /*version*/) {
        using boost::serialization::make_nvp;

        archive & make_nvp("versioned_key", value.versioned_key_);
    }
};

} }

namespace boost {
namespace serialization {

template<class Archive>
inline void serialize(Archive & archive,
    dogen::stand_alone_class::class_1& value,
    const unsigned int version) {
    dogen::stand_alone_class::class_1_serializer serializer;
    serializer.serialize<Archive>(archive, value, version);
}

} }

#endif
