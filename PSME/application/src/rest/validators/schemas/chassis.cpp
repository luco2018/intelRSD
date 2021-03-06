/*!
 * @copyright
 * Copyright (c) 2015-2018 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * */

#include "psme/rest/validators/schemas/chassis.hpp"
#include "psme/rest/constants/constants.hpp"
#include "agent-framework/module/constants/regular_expressions.hpp"


using namespace psme::rest;
using namespace psme::rest::validators::schema;
using namespace agent_framework::model;


const jsonrpc::ProcedureValidator& ChassisPatchSchema::get_procedure() {
    static jsonrpc::ProcedureValidator procedure{
        jsonrpc::PARAMS_BY_NAME,
        constants::Common::ASSET_TAG, VALID_OPTIONAL(VALID_JSON_STRING),
        constants::Common::OEM, VALID_OPTIONAL(VALID_ATTRIBUTE(OemSchema)),
        nullptr
    };
    return procedure;
}

const jsonrpc::ProcedureValidator& ChassisPatchSchema::OemSchema::get_procedure() {
    static jsonrpc::ProcedureValidator procedure{
        jsonrpc::PARAMS_BY_NAME,
        constants::Common::RACKSCALE, VALID_OPTIONAL(VALID_ATTRIBUTE(RackScaleSchema)),
        nullptr
    };
    return procedure;
}

const jsonrpc::ProcedureValidator& ChassisPatchSchema::OemSchema::RackScaleSchema::get_procedure() {
    static jsonrpc::ProcedureValidator procedure{
        jsonrpc::PARAMS_BY_NAME,
        constants::Chassis::LOCATION, VALID_OPTIONAL(VALID_ATTRIBUTE(LocationSchema)),
        constants::Chassis::GEO_TAG, VALID_OPTIONAL(VALID_JSON_STRING),
        nullptr
    };
    return procedure;
}

const jsonrpc::ProcedureValidator& ChassisPatchSchema::OemSchema::RackScaleSchema::LocationSchema::get_procedure() {
    static jsonrpc::ProcedureValidator procedure{
        jsonrpc::PARAMS_BY_NAME,
        constants::Common::ID, VALID_OPTIONAL(VALID_REGEX(literals::regex::Chassis::LOCATION_ID)),
        nullptr
    };
    return procedure;
}
