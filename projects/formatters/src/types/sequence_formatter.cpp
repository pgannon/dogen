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
#include <sstream>
#include "dogen/formatters/types/sequence_formatter.hpp"

namespace dogen {
namespace formatters {

sequence_formatter::sequence_formatter(const unsigned int sequence_size,
    const std::string& element_separator)
    : sequence_size_(sequence_size), element_separator_(element_separator),
      position_(0) {}


bool sequence_formatter::is_first() const {
    return position_ == 0;
}

bool sequence_formatter::is_last() const {
    return position_ == sequence_size_ - 1;
}

bool sequence_formatter::is_single() const {
    return is_first() && is_last();
}

std::string sequence_formatter::
value_for_position(const infix_configuration& ic) const {
    if (is_single()) {
        if (!ic.first().empty()) {
            // when we are single, first takes priority if supplied.
            return ic.first();
        }
        return ic.last();
    } else if (is_first())
        return ic.first();
    else if (!is_last() || !ic.not_first().empty()) {
        // when we are last, not first takes precedence if supplied.
        return ic.not_first();
    }

    return ic.last();
}

infix_configuration& sequence_formatter::prefix_configuration() {
    return prefix_configuration_;
}

infix_configuration& sequence_formatter::postfix_configuration() {
    return postfix_configuration_;
}

std::string sequence_formatter::prefix() const {
    return value_for_position(prefix_configuration_);
}

std::string sequence_formatter::postfix() {
    std::ostringstream s;
    s << value_for_position(postfix_configuration_);
    if (!is_last())
        s << element_separator_;

    ++position_;
    return s.str();
}

unsigned int sequence_formatter::current_position() const {
    return position_;
}

void sequence_formatter::reset() {
    position_ = 0;
    prefix_configuration_ = infix_configuration();
    postfix_configuration_ = infix_configuration();
}

void sequence_formatter::reset(const unsigned int sequence_size) {
    sequence_size_ = sequence_size;
}

} }
