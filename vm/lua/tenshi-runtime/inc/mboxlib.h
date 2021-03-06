// Licensed to Pioneers in Engineering under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  Pioneers in Engineering licenses
// this file to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
//  with the License.  You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License

#ifndef INC_MBOXLIB_H_
#define INC_MBOXLIB_H_

#include <stdint.h>
#include <stdlib.h>
#include "inc/runtime_entry.h"
#include "lua.h"  // NOLINT(build/include)
#include "lauxlib.h"    // NOLINT(build/include)

// Key used to store the changed actuator table
#define RIDX_CHANGED_TABLE                "tenshi.changed_actuators"
// Key used to store the mailbox metatable in the Lua registry
#define RIDX_MBOXLIB_METATABLE            "tenshi.mboxlib.metatable"

// This is used as a somewhat hacky way to get mailbox functions into e.g.
// actors rather than actually handling inheritance using more metatables.
extern const luaL_Reg mbox_metatable_funcs[];

extern void tenshi_open_mbox(lua_State *L);

// Creates a new mailbox internal state (not associated with anything)
// and leaves it at the top of the stack. To be called in protected mode.
extern int MBoxCreateInternal(lua_State *L);

// Creates a new public, Lua-facing mailbox wrapping the internal mailbox
// state on the stack and returns the new mailbox wrapper. To be called in
// protected mode.
extern int MBoxCreate(lua_State *L);

#endif  // INC_MBOXLIB_H_
