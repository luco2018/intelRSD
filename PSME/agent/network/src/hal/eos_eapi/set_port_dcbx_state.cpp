/*!
 * @brief Set port DCBX mode command class definition.
 *
 * @header{License}
 * @copyright Copyright (c) 2018 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @header{Filesystem}
 * @file set_port_dcbx_state.cpp
 */

#include "hal/eos_eapi/set_port_dcbx_state.hpp"

using namespace agent::network::hal;


std::vector<std::string> SetPortDcbxState::serialize() const {
    std::map<agent_framework::model::enums::DcbxState, std::string> dcbx_state = {
        {agent_framework::model::enums::DcbxState::EnabledIEEE, "ieee"},
        {agent_framework::model::enums::DcbxState::EnabledCEE, "cee"},
        {agent_framework::model::enums::DcbxState::Disabled, "none"}
    };
    std::vector<std::string> commands;
    commands.emplace_back("configure");
    commands.push_back("interface " + m_interface);
    commands.push_back("dcbx mode " + dcbx_state.at(m_dcbx_state));
    return commands;
}

SetPortDcbxState::~SetPortDcbxState() { }