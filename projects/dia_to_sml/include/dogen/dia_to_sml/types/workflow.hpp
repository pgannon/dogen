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
#ifndef DOGEN_DIA_TO_SML_TYPES_WORKFLOW_HPP
#define DOGEN_DIA_TO_SML_TYPES_WORKFLOW_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <memory>
#include "dogen/dia/types/diagram_fwd.hpp"
#include "dogen/dynamic/types/workflow.hpp"
#include "dogen/sml/types/model_fwd.hpp"
#include "dogen/dia_to_sml/types/context.hpp"
#include "dogen/dia_to_sml/types/profiler.hpp"
#include "dogen/dia_to_sml/types/validator.hpp"
#include "dogen/dia_to_sml/types/transformer.hpp"
#include "dogen/dia_to_sml/types/grapher.hpp"

namespace dogen {
namespace dia_to_sml {

class workflow {
public:
    workflow(const workflow&) = delete;
    workflow(workflow&&) = default;
    ~workflow() = default;

public:
    explicit workflow(const dynamic::workflow& w);

private:
    /**
     * @brief Creates a qualified name for the module.
     */
    sml::qname create_qualified_name_for_model(const std::string& model_name,
        const std::string& external_module_path) const;

    /**
     * @brief Creates a module representing the model.
     */
    sml::module create_module_for_model(const sml::qname& qn,
        const bool is_target) const;

private:
    /**
     * @brief Reset context and set it up with arguments supplied.
     */
    void initialise_context_activity(const std::string& model_name,
        const std::string& external_module_path, const bool is_target);

    /**
     * @brief Setup the DAG of processed objects.
     */
    graph_type generate_graph_activity(const dia::diagram& diagram);

    /**
     * @brief Perform the transformation sub-workflow on the supplied
     * processed object.
     */
    void transformation_activity(const processed_object& o);

    /**
     * @brief Transforms the entire graph of processed objects into a
     * SML model.
     */
    void graph_to_context_activity(const graph_type& g);

public:
    sml::model execute(const dia::diagram& diagram,
        const std::string& model_name,
        const std::string& external_module_path,
        bool is_target);

private:
    context context_;
    profiler profiler_;
    validator validator_;
    std::unique_ptr<transformer> transformer_;
    const dynamic::workflow& dynamic_workflow_;
};

} }

#endif
