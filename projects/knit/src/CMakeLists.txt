# -*- mode: cmake; tab-width: 4; indent-tabs-mode: nil -*-
#
# Copyright (C) 2012 Kitanda <info@kitanda.co.uk>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.
#
set(knit_files "")
file(GLOB_RECURSE knit_files RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}/"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(knit STATIC ${knit_files})
target_link_libraries(knit
    sml
    dia
    dia_to_sml
    frontend
    backend
    formatters
    cpp
    config
    utility
    ${LIBXML2_LIBRARIES}
    ${Boost_LIBRARIES})

set_target_properties(knit
    PROPERTIES OUTPUT_NAME dogen_knit)
set_target_properties(knit
    PROPERTIES VERSION ${DOGEN_VERSION} SOVERSION ${DOGEN_MAJOR_VERSION})

install(TARGETS knit ARCHIVE DESTINATION lib COMPONENT libraries)
