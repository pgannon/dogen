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
#ifndef DOGEN_SML_TYPES_KEYED_ENTITY_HPP
#define DOGEN_SML_TYPES_KEYED_ENTITY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <boost/optional.hpp>
#include <iosfwd>
#include "dogen/sml/serialization/keyed_entity_fwd_ser.hpp"
#include "dogen/sml/types/abstract_entity.hpp"
#include "dogen/sml/types/qname.hpp"
#include "dogen/sml/types/type_visitor.hpp"

namespace dogen {
namespace sml {

/**
 * @brief Entity which has keys as an external representation of its identity operation.
 */
class keyed_entity final : public dogen::sml::abstract_entity {
public:
    keyed_entity() = default;
    keyed_entity(const keyed_entity&) = default;

    virtual ~keyed_entity() noexcept { }

public:
    keyed_entity(keyed_entity&& rhs);

public:
    keyed_entity(
        const std::string& documentation,
        const std::vector<std::pair<std::string, std::string> >& implementation_specific_parameters,
        const dogen::sml::qname& name,
        const dogen::sml::generation_types& generation_type,
        const std::list<dogen::sml::property>& properties,
        const boost::optional<dogen::sml::qname>& parent_name,
        const boost::optional<dogen::sml::qname>& original_parent_name,
        const std::list<dogen::sml::qname>& leaves,
        const bool is_parent,
        const unsigned int number_of_type_arguments,
        const bool is_visitable,
        const bool is_immutable,
        const bool is_versioned,
        const bool is_keyed,
        const bool is_comparable,
        const bool is_fluent,
        const std::list<dogen::sml::qname>& modeled_concepts,
        const bool is_aggregate_root,
        const std::list<dogen::sml::property>& identity_operation,
        const dogen::sml::qname& unversioned_key,
        const boost::optional<dogen::sml::qname>& versioned_key);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const keyed_entity& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, keyed_entity& v, unsigned int version);

public:
    virtual void accept(const type_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(type_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(const type_visitor& v) override {
        v.visit(*this);
    }

    virtual void accept(type_visitor& v) override {
        v.visit(*this);
    }

public:
    void to_stream(std::ostream& s) const override;

public:
    /**
     * @brief Identity operation for the entity, without taking version into account.
     */
    /**@{*/
    const dogen::sml::qname& unversioned_key() const;
    dogen::sml::qname& unversioned_key();
    void unversioned_key(const dogen::sml::qname& v);
    void unversioned_key(const dogen::sml::qname&& v);
    /**@}*/

    /**
     * @brief If the type is a versioned keyed entity, its versioned key.
     */
    /**@{*/
    const boost::optional<dogen::sml::qname>& versioned_key() const;
    boost::optional<dogen::sml::qname>& versioned_key();
    void versioned_key(const boost::optional<dogen::sml::qname>& v);
    void versioned_key(const boost::optional<dogen::sml::qname>&& v);
    /**@}*/

public:
    bool operator==(const keyed_entity& rhs) const;
    bool operator!=(const keyed_entity& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const dogen::sml::type& other) const override;

public:
    void swap(keyed_entity& other) noexcept;
    keyed_entity& operator=(keyed_entity other);

private:
    dogen::sml::qname unversioned_key_;
    boost::optional<dogen::sml::qname> versioned_key_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::sml::keyed_entity& lhs,
    dogen::sml::keyed_entity& rhs) {
    lhs.swap(rhs);
}

}

#endif