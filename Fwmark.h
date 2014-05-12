/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SYSTEM_NETD_FWMARK_H
#define SYSTEM_NETD_FWMARK_H

#include "Permission.h"

#include <utils/Debug.h>
#include <stdint.h>

union Fwmark {
    Fwmark() : intValue(0) {}
    uint32_t intValue;
    struct {
        unsigned netId          : 16;
        bool explicitlySelected :  1;
        bool protectedFromVpn   :  1;
        Permission permission   :  2;
    };
};

static const unsigned FWMARK_NET_ID_MASK = 0xffff;

namespace android {

// Ensure that all the fwmark fields fit into 32 bits.
COMPILE_TIME_ASSERT(sizeof(Fwmark) == sizeof(uint32_t));

}  // namespace android

#endif  // SYSTEM_NETD_FWMARK_H
