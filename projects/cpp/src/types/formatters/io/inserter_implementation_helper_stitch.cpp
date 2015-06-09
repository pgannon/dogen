/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright(C) 2012 Kitanda <info@kitanda.co.uk>
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
#include "dogen/formatters/types/sequence_formatter.hpp"
#include "dogen/cpp/types/formatters/io/inserter_implementation_helper_stitch.hpp"

namespace dogen {
namespace cpp {
namespace formatters {
namespace io {

void inserter_implementation_helper_stitch(
    formatters::entity_formatting_assistant& fa,
    const formattables::class_info& c) {

    if (c.requires_stream_manipulators()) {
fa.stream() << "    boost::io::ios_flags_saver ifs(s);" << std::endl;
fa.stream() << "    s.setf(std::ios_base::boolalpha);" << std::endl;
fa.stream() << "    s.setf(std::ios::fixed, std::ios::floatfield);" << std::endl;
fa.stream() << "    s.precision(6);" << std::endl;
fa.stream() << "    s.setf(std::ios::showpoint);" << std::endl;
    }


    const bool no_parents_and_no_properties(c.parents().empty() &&
        c.all_properties().empty());
fa.stream() << "    s << \" { \"" << std::endl;
fa.stream() << "      << \"\\\"__type__\\\": \" << \"\\\"" << c.qualified_name() << "\\\"\"" << (no_parents_and_no_properties ? " << \" }\";" : " << \", \"") << std::endl;

    dogen::formatters::sequence_formatter sf(c.parents().size());
    sf.prefix_configuration().first("  << ").not_first("s << ");
    sf.element_separator("");
    for (const auto p : c.parents()) {
fa.stream() << "    " << sf.prefix() << "\"\\\"__parent_" << sf.current_position() << "__\\\": \"" << sf.postfix() << ";" << std::endl;
fa.stream() << "    " << p.name() << "::to_stream(s);" << std::endl;
    }

    auto ntfa(fa.make_nested_type_formatting_assistant());
    for (const auto p : c.properties()) {
fa.stream() << "    s << \", \"" << std::endl;
fa.stream() << "      << \"\\\"" << p.name() << "\\\": \" << " << ntfa.streaming_for_type(p.type(), "v") << std::endl;
    }

    if (!c.properties().empty())
fa.stream() << "      << \" }\";" << std::endl;
    else
fa.stream() << "    s << \" }\";" << std::endl;
}
} } } }
