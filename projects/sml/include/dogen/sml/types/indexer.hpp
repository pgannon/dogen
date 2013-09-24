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
#ifndef DOGEN_SML_TYPES_INDEXER_HPP
#define DOGEN_SML_TYPES_INDEXER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "dogen/sml/types/model.hpp"
#include "dogen/sml/types/indexer_interface.hpp"

namespace dogen {
namespace sml {

class indexer : public indexer_interface {
public:
    indexer() = delete;
    indexer(const indexer&) = default;
    indexer(indexer&&) = default;
    indexer& operator=(const indexer&) = default;

public:
    virtual ~indexer() noexcept { }

public:
    /**
     * @brief Initialises the indexer.
     *
     * Note that no setup is done until @e index() is called.
     *
     * @param m model to index. must outlive the indexer.
     */
    explicit indexer(const model& m);

public:
    /**
     * @brief Populates all the data structures required for querying.
     */
    void index();

    /**
     * @brief Returns true if indexing has been done, false otherwise.
     */
    bool is_indexed() const;

private:
    /**
     * @brief If not indexed throws an indexing error.
     */
    void ensure_indexed() const;

public:
    /**
     * @pre is_indexed must be true.
     */
    std::list<property> all_properties(const abstract_object& o) const override;

    /**
     * @pre is_indexed must be true.
     */
    std::list<property>
    local_properties(const abstract_object& o) const override;

    /**
     * @pre is_indexed must be true.
     */
    std::unordered_map<qname, std::list<property> >
    inehrited_properties(const abstract_object& o) const override;

private:
    const model& model_;
    bool is_indexed_;
    std::unordered_map<qname, std::list<property> > all_properties_;
    std::unordered_map<qname, std::list<property> > local_properties_;
    std::unordered_map<qname, std::list<property> > inherited_properties_;
};

} }

#endif