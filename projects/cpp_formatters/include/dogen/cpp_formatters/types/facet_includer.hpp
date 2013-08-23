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
#ifndef DOGEN_CPP_FORMATTERS_TYPES_FACET_INCLUDER_HPP
#define DOGEN_CPP_FORMATTERS_TYPES_FACET_INCLUDER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <iosfwd>
#include <boost/filesystem/path.hpp>
#include "dogen/cpp/types/source_file.hpp"
#include "dogen/cpp_formatters/types/indenter.hpp"
#include "dogen/cpp_formatters/types/utility.hpp"
#include "dogen/cpp_formatters/types/file_formatter.hpp"

namespace dogen {
namespace cpp_formatters {

class facet_includer : public file_formatter {
public:
    facet_includer() = delete;
    facet_includer(const facet_includer&) = default;
    facet_includer(facet_includer&&) = default;
    facet_includer& operator=(const facet_includer&) = default;

public:
    explicit facet_includer(std::ostream& stream);
    virtual ~facet_includer() noexcept {}

public:
    static file_formatter::shared_ptr create(std::ostream& stream);

public:
    virtual void format(const cpp::source_file& f) override;

private:
    std::ostream& stream_;
    indenter indenter_;
    utility utility_;
};

} }

#endif