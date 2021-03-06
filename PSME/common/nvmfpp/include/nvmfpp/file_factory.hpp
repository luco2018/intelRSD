/*!
 * @header{License}
 * @copyright Copyright (c) 2017-2018 Intel Corporation.
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
 * @file file_factory.hpp
 */

#pragma once


#include "base_file_factory.hpp"
#include "file.hpp"


#include <memory>
#include <fstream>


namespace nvmfpp {

class FileFactory final : public nvmfpp::BaseFileFactory {
public:
    ~FileFactory();

    /*!
     * @param path Path to file.
     * @param mode File access mode.
     * @return Unique pointer to File object.
     */
    std::unique_ptr<BaseFile> create_file(const std::string& path, FileMode mode) {
        return std::unique_ptr<BaseFile>(new File(path, mode));
    }

};

}
