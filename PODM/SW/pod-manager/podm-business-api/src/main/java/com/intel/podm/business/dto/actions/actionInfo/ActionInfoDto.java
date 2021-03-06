/*
 * Copyright (c) 2017-2018 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.intel.podm.business.dto.actions.actionInfo;

import com.fasterxml.jackson.annotation.JsonPropertyOrder;
import com.intel.podm.business.dto.RedfishDto;

import java.util.ArrayList;
import java.util.List;

@JsonPropertyOrder({
    "@odata.type", "@odata.context", "@odata.id", "id", "name", "description", "parameters", "oem"
})
public class ActionInfoDto extends RedfishDto {

    private List<ParameterDto> parameters = new ArrayList<>();

    public ActionInfoDto() {
        super("#ActionInfo.v1_0_2.ActionInfo");
    }

    public List<ParameterDto> getParameters() {
        return parameters;
    }

    public void setParameters(List<ParameterDto> parameters) {
        this.parameters = parameters;
    }

    public void addParameters(List<ParameterDto> parameters) {
        this.parameters.addAll(parameters);
    }
}
