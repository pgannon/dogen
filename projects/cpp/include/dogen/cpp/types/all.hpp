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
#ifndef DOGEN_CPP_TYPES_ALL_HPP
#define DOGEN_CPP_TYPES_ALL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "dogen/cpp/types/cpp.hpp"
#include "dogen/cpp/types/traits.hpp"
#include "dogen/cpp/types/workflow.hpp"
#include "dogen/cpp/types/initializer.hpp"
#include "dogen/cpp/types/workflow_error.hpp"
#include "dogen/cpp/types/settings/bundle.hpp"
#include "dogen/cpp/types/formatters/io/io.hpp"
#include "dogen/cpp/types/formatters/traits.hpp"
#include "dogen/cpp/types/settings/settings.hpp"
#include "dogen/cpp/types/formatters/odb/odb.hpp"
#include "dogen/cpp/types/settings/registrar.hpp"
#include "dogen/cpp/types/formattables/entity.hpp"
#include "dogen/cpp/types/formatters/workflow.hpp"
#include "dogen/cpp/types/formattables/factory.hpp"
#include "dogen/cpp/types/formatters/container.hpp"
#include "dogen/cpp/types/formatters/hash/hash.hpp"
#include "dogen/cpp/types/formatters/io/traits.hpp"
#include "dogen/cpp/types/formatters/registrar.hpp"
#include "dogen/cpp/types/settings/initializer.hpp"
#include "dogen/cpp/types/formattables/workflow.hpp"
#include "dogen/cpp/types/formatters/file_types.hpp"
#include "dogen/cpp/types/formatters/formatters.hpp"
#include "dogen/cpp/types/formatters/odb/traits.hpp"
#include "dogen/cpp/types/settings/odb_settings.hpp"
#include "dogen/cpp/types/formattables/container.hpp"
#include "dogen/cpp/types/formattables/enum_info.hpp"
#include "dogen/cpp/types/formattables/registrar.hpp"
#include "dogen/cpp/types/formatters/hash/traits.hpp"
#include "dogen/cpp/types/formatters/initializer.hpp"
#include "dogen/cpp/types/formatters/types/types.hpp"
#include "dogen/cpp/types/settings/path_settings.hpp"
#include "dogen/cpp/types/formattables/class_info.hpp"
#include "dogen/cpp/types/formatters/types/traits.hpp"
#include "dogen/cpp/types/settings/building_error.hpp"
#include "dogen/cpp/types/settings/bundle_factory.hpp"
#include "dogen/cpp/types/formattables/formattable.hpp"
#include "dogen/cpp/types/formattables/parent_info.hpp"
#include "dogen/cpp/types/formattables/transformer.hpp"
#include "dogen/cpp/types/settings/aspect_settings.hpp"
#include "dogen/cpp/types/settings/opaque_settings.hpp"
#include "dogen/cpp/types/settings/registrar_error.hpp"
#include "dogen/cpp/types/formattables/concept_info.hpp"
#include "dogen/cpp/types/formattables/formattables.hpp"
#include "dogen/cpp/types/formattables/name_builder.hpp"
#include "dogen/cpp/types/formattables/origin_types.hpp"
#include "dogen/cpp/types/formattables/visitor_info.hpp"
#include "dogen/cpp/types/formatters/io/initializer.hpp"
#include "dogen/cpp/types/formattables/property_info.hpp"
#include "dogen/cpp/types/formatters/odb/initializer.hpp"
#include "dogen/cpp/types/formatters/registrar_error.hpp"
#include "dogen/cpp/types/settings/bundle_repository.hpp"
#include "dogen/cpp/types/formattables/building_error.hpp"
#include "dogen/cpp/types/formattables/exception_info.hpp"
#include "dogen/cpp/types/formattables/includers_info.hpp"
#include "dogen/cpp/types/formattables/namespace_info.hpp"
#include "dogen/cpp/types/formattables/primitive_info.hpp"
#include "dogen/cpp/types/formattables/registrar_info.hpp"
#include "dogen/cpp/types/formatters/formatting_error.hpp"
#include "dogen/cpp/types/formatters/hash/initializer.hpp"
#include "dogen/cpp/types/formatters/test_data/traits.hpp"
#include "dogen/cpp/types/formattables/cmakelists_info.hpp"
#include "dogen/cpp/types/formattables/enumerator_info.hpp"
#include "dogen/cpp/types/formattables/provision_error.hpp"
#include "dogen/cpp/types/formattables/registrar_error.hpp"
#include "dogen/cpp/types/formatters/types/initializer.hpp"
#include "dogen/cpp/types/formattables/nested_type_info.hpp"
#include "dogen/cpp/types/formattables/odb_options_info.hpp"
#include "dogen/cpp/types/formattables/path_derivatives.hpp"
#include "dogen/cpp/types/settings/odb_settings_factory.hpp"
#include "dogen/cpp/types/formattables/visited_type_info.hpp"
#include "dogen/cpp/types/formatters/formatter_interface.hpp"
#include "dogen/cpp/types/formatters/includers_formatter.hpp"
#include "dogen/cpp/types/formatters/inclusion_constants.hpp"
#include "dogen/cpp/types/formatters/test_data/test_data.hpp"
#include "dogen/cpp/types/settings/path_settings_factory.hpp"
#include "dogen/cpp/types/formattables/enablement_factory.hpp"
#include "dogen/cpp/types/formatters/formatting_assistant.hpp"
#include "dogen/cpp/types/formatters/serialization/traits.hpp"
#include "dogen/cpp/types/formattables/formattable_visitor.hpp"
#include "dogen/cpp/types/formatters/test_data/initializer.hpp"
#include "dogen/cpp/types/settings/aspect_settings_factory.hpp"
#include "dogen/cpp/types/settings/opaque_settings_builder.hpp"
#include "dogen/cpp/types/formattables/formatter_properties.hpp"
#include "dogen/cpp/types/formattables/transformation_error.hpp"
#include "dogen/cpp/types/settings/directory_names_settings.hpp"
#include "dogen/cpp/types/formattables/enablement_repository.hpp"
#include "dogen/cpp/types/settings/bundle_repository_factory.hpp"
#include "dogen/cpp/types/formatters/enum_formatter_interface.hpp"
#include "dogen/cpp/types/formatters/io/enum_header_formatter.hpp"
#include "dogen/cpp/types/formatters/class_formatter_interface.hpp"
#include "dogen/cpp/types/formatters/io/class_header_formatter.hpp"
#include "dogen/cpp/types/formatters/odb/enum_header_formatter.hpp"
#include "dogen/cpp/types/formatters/odb/odb_options_formatter.hpp"
#include "dogen/cpp/types/formatters/serialization/initializer.hpp"
#include "dogen/cpp/types/formattables/path_derivatives_factory.hpp"
#include "dogen/cpp/types/formatters/hash/enum_header_formatter.hpp"
#include "dogen/cpp/types/formatters/odb/class_header_formatter.hpp"
#include "dogen/cpp/types/settings/inclusion_directive_settings.hpp"
#include "dogen/cpp/types/formattables/forward_declarations_info.hpp"
#include "dogen/cpp/types/formatters/concept_formatter_interface.hpp"
#include "dogen/cpp/types/formatters/entity_formatting_assistant.hpp"
#include "dogen/cpp/types/formatters/hash/class_header_formatter.hpp"
#include "dogen/cpp/types/formatters/io/helper_methods_formatter.hpp"
#include "dogen/cpp/types/formatters/serialization/serialization.hpp"
#include "dogen/cpp/types/formatters/source_cmakelists_formatter.hpp"
#include "dogen/cpp/types/formatters/types/enum_header_formatter.hpp"
#include "dogen/cpp/types/formatters/visitor_formatter_interface.hpp"
#include "dogen/cpp/types/settings/inclusion_directives_settings.hpp"
#include "dogen/cpp/types/formatters/include_cmakelists_formatter.hpp"
#include "dogen/cpp/types/formatters/trivial_formatting_assistant.hpp"
#include "dogen/cpp/types/formatters/types/class_header_formatter.hpp"
#include "dogen/cpp/types/formattables/path_derivatives_repository.hpp"
#include "dogen/cpp/types/formatters/exception_formatter_interface.hpp"
#include "dogen/cpp/types/formatters/hash/helper_methods_formatter.hpp"
#include "dogen/cpp/types/formatters/includers_formatter_interface.hpp"
#include "dogen/cpp/types/formatters/namespace_formatter_interface.hpp"
#include "dogen/cpp/types/formatters/primitive_formatter_interface.hpp"
#include "dogen/cpp/types/formatters/registrar_formatter_interface.hpp"
#include "dogen/cpp/types/formattables/formatter_properties_factory.hpp"
#include "dogen/cpp/types/formattables/global_enablement_properties.hpp"
#include "dogen/cpp/types/formattables/inclusion_directives_factory.hpp"
#include "dogen/cpp/types/formattables/integrated_facets_repository.hpp"
#include "dogen/cpp/types/formatters/cmakelists_formatter_interface.hpp"
#include "dogen/cpp/types/formatters/types/helper_methods_formatter.hpp"
#include "dogen/cpp/types/formatters/types/visitor_header_formatter.hpp"
#include "dogen/cpp/types/settings/directory_names_settings_factory.hpp"
#include "dogen/cpp/types/formattables/enablement_repository_factory.hpp"
#include "dogen/cpp/types/formatters/odb_options_formatter_interface.hpp"
#include "dogen/cpp/types/formatters/test_data/enum_header_formatter.hpp"
#include "dogen/cpp/types/settings/opaque_settings_factory_interface.hpp"
#include "dogen/cpp/types/formattables/inclusion_dependencies_builder.hpp"
#include "dogen/cpp/types/formattables/inclusion_dependencies_factory.hpp"
#include "dogen/cpp/types/formatters/io/enum_implementation_formatter.hpp"
#include "dogen/cpp/types/formatters/nested_type_formatting_assistant.hpp"
#include "dogen/cpp/types/formatters/test_data/class_header_formatter.hpp"
#include "dogen/cpp/types/formatters/types/exception_header_formatter.hpp"
#include "dogen/cpp/types/formatters/types/namespace_header_formatter.hpp"
#include "dogen/cpp/types/formattables/formatter_properties_repository.hpp"
#include "dogen/cpp/types/formattables/inclusion_directives_repository.hpp"
#include "dogen/cpp/types/formatters/io/class_implementation_formatter.hpp"
#include "dogen/cpp/types/formatters/test_data/helper_methods_formatter.hpp"
#include "dogen/cpp/types/formattables/inclusion_dependencies_repository.hpp"
#include "dogen/cpp/types/formatters/hash/class_implementation_formatter.hpp"
#include "dogen/cpp/types/formatters/serialization/enum_header_formatter.hpp"
#include "dogen/cpp/types/settings/inclusion_directives_settings_factory.hpp"
#include "dogen/cpp/types/formatters/serialization/class_header_formatter.hpp"
#include "dogen/cpp/types/formatters/types/class_implementation_formatter.hpp"
#include "dogen/cpp/types/formatters/types/forward_declarations_formatter.hpp"
#include "dogen/cpp/types/formattables/path_derivatives_repository_factory.hpp"
#include "dogen/cpp/types/formattables/integrated_facets_repository_factory.hpp"
#include "dogen/cpp/types/formatters/test_data/enum_implementation_formatter.hpp"
#include "dogen/cpp/types/formattables/inclusion_dependencies_builder_factory.hpp"
#include "dogen/cpp/types/formatters/forward_declarations_formatter_interface.hpp"
#include "dogen/cpp/types/formatters/serialization/registrar_header_formatter.hpp"
#include "dogen/cpp/types/formatters/test_data/class_implementation_formatter.hpp"
#include "dogen/cpp/types/formattables/formatter_properties_repository_factory.hpp"
#include "dogen/cpp/types/formattables/inclusion_directives_repository_factory.hpp"
#include "dogen/cpp/types/formattables/inclusion_dependencies_provider_interface.hpp"
#include "dogen/cpp/types/formattables/inclusion_dependencies_repository_factory.hpp"
#include "dogen/cpp/types/formatters/serialization/class_implementation_formatter.hpp"
#include "dogen/cpp/types/formatters/serialization/forward_declarations_formatter.hpp"
#include "dogen/cpp/types/formatters/serialization/registrar_implementation_formatter.hpp"

#endif
