#
# Copyright (c) 2005-2019 Imperas Software Ltd., www.imperas.com
#
# The contents of this file are provided under the Software License
# Agreement that you accepted before downloading this file.
#
# This source forms part of the Software and can be used for educational,
# training, and demonstration purposes but cannot be used for derivative
# works except in cases where the derivative works require OVP technology
# to run.
#
# For open source models released under licenses that you can use for
# derivative works, please visit www.OVPworld.org or www.imperas.com
# for the location of the open source models.
#

# module.op.tcl

ihwnew -name hetProcessorShared

# add the processors
ihwaddprocessor -instancename P0 \
                -vendor ovpworld.org -library processor -type or1k -version 1.0 \
                -variant generic \
                -semihostname or1kNewlib

ihwaddprocessor -instancename P1 \
                -vendor riscv.ovpworld.org -library processor -type riscv -version 1.0 \
                -variant RV32I \
                -semihostvendor riscv.ovpworld.org -semihostname pk

ihwaddprocessor -instancename P2 \
                -vendor riscv.ovpworld.org -library processor -type riscv -version 1.0 \
                -variant RV32I \
                -semihostvendor riscv.ovpworld.org -semihostname pk


# add memories (local and shared)
ihwaddmemory -type ram -instancename local0
ihwaddmemory -type ram -instancename stack0

ihwaddmemory -type ram -instancename local1
ihwaddmemory -type ram -instancename stack1

ihwaddmemory -type ram -instancename local2
ihwaddmemory -type ram -instancename stack2

ihwaddmemory -type ram -instancename shared

# add the buses
ihwaddbus -instancename bus0     -addresswidth "32"
ihwaddbus -instancename bus1     -addresswidth "32"
ihwaddbus -instancename bus2     -addresswidth "32"

# add connections to bus0
ihwconnect -bus bus0 -instancename P0         -busmasterport "INSTRUCTION"
ihwconnect -bus bus0 -instancename P0         -busmasterport "DATA"
ihwconnect -bus bus0 -instancename local0     -busslaveport  "sp0" -loaddress "0x00010000" -hiaddress "0x0004ffff"
ihwconnect -bus bus0 -instancename stack0     -busslaveport  "sp0" -loaddress "0xffff0000" -hiaddress "0xffffffff"
ihwconnect -bus bus0 -instancename shared     -busslaveport  "sp0" -loaddress "0x00000000" -hiaddress "0x0000ffff"


# add connections to bus1
ihwconnect -bus bus1 -instancename P1         -busmasterport "INSTRUCTION"
ihwconnect -bus bus1 -instancename P1         -busmasterport "DATA"
ihwconnect -bus bus1 -instancename local1     -busslaveport  "sp1" -loaddress "0x00010000" -hiaddress "0x0004ffff"
ihwconnect -bus bus1 -instancename stack1     -busslaveport  "sp1" -loaddress "0xffff0000" -hiaddress "0xffffffff"
ihwconnect -bus bus1 -instancename shared     -busslaveport  "sp1" -loaddress "0x00000000" -hiaddress "0x0000ffff"

# add connections to bus2
ihwconnect -bus bus2 -instancename P2         -busmasterport "INSTRUCTION"
ihwconnect -bus bus2 -instancename P2         -busmasterport "DATA"
ihwconnect -bus bus2 -instancename local2     -busslaveport  "sp2" -loaddress "0x00010000" -hiaddress "0x0004ffff"
ihwconnect -bus bus2 -instancename stack2     -busslaveport  "sp2" -loaddress "0xffff0000" -hiaddress "0xffffffff"
ihwconnect -bus bus2 -instancename shared     -busslaveport  "sp2" -loaddress "0x00000000" -hiaddress "0x0000ffff"

