/*
 * Copyright (c) 2005-2019 Imperas Software Ltd., www.imperas.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied.
 *
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */


////////////////////////////////////////////////////////////////////////////////
//
//                W R I T T E N   B Y   I M P E R A S   I G E N
//
//                             Version 20191106.0
//
////////////////////////////////////////////////////////////////////////////////

#define UNUSED   __attribute__((unused))

// instantiate module components
static OP_CONSTRUCT_FN(instantiateComponents) {



    // Bus bus0

    optBusP bus0_b = opBusNew(mi, "bus0", 32, 0, 0);


    // Bus bus1

    optBusP bus1_b = opBusNew(mi, "bus1", 32, 0, 0);


    // Bus bus2

    optBusP bus2_b = opBusNew(mi, "bus2", 32, 0, 0);


    // Processor P0

    const char *P0_path = opVLNVString(
        0, // use the default VLNV path
        "ovpworld.org",
        "processor",
        "or1k",
        "1.0",
        OP_PROCESSOR,
        1   // report errors
    );

    optProcessorP P0_c = opProcessorNew(
        mi,
        P0_path,
        "P0",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus0_b, "INSTRUCTION"),
                OP_BUS_CONNECT(bus0_b, "DATA")
            )
        ),
        OP_PARAMS(
             OP_PARAM_ENUM_SET("variant", "generic")
        )
    );

    const char *or1kNewlib_0_expath = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1kNewlib",
        0,
        OP_EXTENSION,
        1   // report errors
    );

    opProcessorExtensionNew(
        P0_c,
        or1kNewlib_0_expath,
        "or1kNewlib_0_ex",
        0
    );

    // Processor P1

    const char *P1_path = opVLNVString(
        0, // use the default VLNV path
        "riscv.ovpworld.org",
        "processor",
        "riscv",
        "1.0",
        OP_PROCESSOR,
        1   // report errors
    );

    optProcessorP P1_c = opProcessorNew(
        mi,
        P1_path,
        "P1",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus1_b, "INSTRUCTION"),
                OP_BUS_CONNECT(bus1_b, "DATA")
            )
        ),
        OP_PARAMS(
             OP_PARAM_UNS32_SET("cpuid", 1)
            ,OP_PARAM_ENUM_SET("variant", "RV32I")
        )
    );

    const char *pk_1_expath = opVLNVString(
        0, // use the default VLNV path
        "riscv.ovpworld.org",
        0,
        "pk",
        0,
        OP_EXTENSION,
        1   // report errors
    );

    opProcessorExtensionNew(
        P1_c,
        pk_1_expath,
        "pk_1_ex",
        0
    );

    // Processor P2

    const char *P2_path = opVLNVString(
        0, // use the default VLNV path
        "riscv.ovpworld.org",
        "processor",
        "riscv",
        "1.0",
        OP_PROCESSOR,
        1   // report errors
    );

    optProcessorP P2_c = opProcessorNew(
        mi,
        P2_path,
        "P2",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus2_b, "INSTRUCTION"),
                OP_BUS_CONNECT(bus2_b, "DATA")
            )
        ),
        OP_PARAMS(
             OP_PARAM_UNS32_SET("cpuid", 2)
            ,OP_PARAM_ENUM_SET("variant", "RV32I")
        )
    );

    const char *pk_2_expath = opVLNVString(
        0, // use the default VLNV path
        "riscv.ovpworld.org",
        0,
        "pk",
        0,
        OP_EXTENSION,
        1   // report errors
    );

    opProcessorExtensionNew(
        P2_c,
        pk_2_expath,
        "pk_2_ex",
        0
    );

    // Memory local0

    opMemoryNew(
        mi,
        "local0",
        OP_PRIV_RWX,
        (0x4ffffULL) - (0x10000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus0_b, "sp0", .slave=1, .addrLo=0x10000ULL, .addrHi=0x4ffffULL)
            )
        ),
        0
    );

    // Memory stack0

    opMemoryNew(
        mi,
        "stack0",
        OP_PRIV_RWX,
        (0xffffffffULL) - (0xffff0000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus0_b, "sp0", .slave=1, .addrLo=0xffff0000ULL, .addrHi=0xffffffffULL)
            )
        ),
        0
    );

    // Memory local1

    opMemoryNew(
        mi,
        "local1",
        OP_PRIV_RWX,
        (0x4ffffULL) - (0x10000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus1_b, "sp1", .slave=1, .addrLo=0x10000ULL, .addrHi=0x4ffffULL)
            )
        ),
        0
    );

    // Memory stack1

    opMemoryNew(
        mi,
        "stack1",
        OP_PRIV_RWX,
        (0xffffffffULL) - (0xffff0000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus1_b, "sp1", .slave=1, .addrLo=0xffff0000ULL, .addrHi=0xffffffffULL)
            )
        ),
        0
    );

    // Memory local2

    opMemoryNew(
        mi,
        "local2",
        OP_PRIV_RWX,
        (0x4ffffULL) - (0x10000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus2_b, "sp2", .slave=1, .addrLo=0x10000ULL, .addrHi=0x4ffffULL)
            )
        ),
        0
    );

    // Memory stack2

    opMemoryNew(
        mi,
        "stack2",
        OP_PRIV_RWX,
        (0xffffffffULL) - (0xffff0000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus2_b, "sp2", .slave=1, .addrLo=0xffff0000ULL, .addrHi=0xffffffffULL)
            )
        ),
        0
    );

    // Memory shared

    opMemoryNew(
        mi,
        "shared",
        OP_PRIV_RWX,
        (0xffffULL) - (0x0ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus0_b, "sp0", .slave=1, .addrLo=0x0ULL, .addrHi=0xffffULL),
                OP_BUS_CONNECT(bus1_b, "sp1", .slave=1, .addrLo=0x0ULL, .addrHi=0xffffULL),
                OP_BUS_CONNECT(bus2_b, "sp2", .slave=1, .addrLo=0x0ULL, .addrHi=0xffffULL)
            )
        ),
        0
    );

}

optModuleAttr modelAttrs = {
    .versionString        = OP_VERSION,
    .type                 = OP_MODULE,
    .name                 = MODULE_NAME,
    .objectSize           = sizeof(optModuleObject),
    .releaseStatus        = OP_UNSET,
    .purpose              = OP_PP_BAREMETAL,
    .visibility           = OP_VISIBLE,
    .vlnv          = {
        .vendor  = "defaultVendor",
        .library = "work",
        .name    = "hetProcessorShared",
        .version = "1.0"
    },
    .constructCB          = moduleConstructor,
    .preSimulateCB        = modulePreSimulate,
    .simulateCB           = moduleSimulateStart,
    .postSimulateCB       = modulePostSimulate,
    .destructCB           = moduleDestruct,
};
