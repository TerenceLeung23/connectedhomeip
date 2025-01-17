/*
 *
 *    Copyright (c) 2023 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

#include "Endpoint.h"
#include "Types.h"

#include "lib/support/logging/CHIPLogging.h"

namespace matter {
namespace casting {
namespace core {

class Endpoint;

// Base cluster class
class BaseCluster
{
private:
protected:
    memory::Weak<Endpoint> mEndpoint;

public:
    BaseCluster(memory::Weak<Endpoint> endpoint) { this->mEndpoint = endpoint; }

    virtual ~BaseCluster() {}

    BaseCluster()                       = delete;
    BaseCluster(BaseCluster & other)    = delete;
    void operator=(const BaseCluster &) = delete;

protected:
    memory::Weak<Endpoint> GetEndpoint() const { return mEndpoint.lock(); }
};

}; // namespace core
}; // namespace casting
}; // namespace matter
