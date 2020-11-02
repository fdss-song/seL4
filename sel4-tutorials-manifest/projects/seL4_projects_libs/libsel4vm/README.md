<!--
     Copyright 2019, Data61
     Commonwealth Scientific and Industrial Research Organisation (CSIRO)
     ABN 41 687 119 230.

     This software may be distributed and modified according to the terms of
     the BSD 2-Clause license. Note that NO WARRANTY is provided.
     See "LICENSE_BSD2.txt" for details.

     @TAG(DATA61_BSD)
-->

# libsel4vm

A guest hardware virtualisation library for X86 (32-bit) and ARM (aarch32 & aarch64) for use on seL4-based systems.
Reference implementations using this library are:
* CAmkES VM (x86) - https://github.com/seL4/camkes-vm
* CAmkES ARM VM (arm) - https://github.com/SEL4PROJ/camkes-arm-vm

For documentation on the libsel4vm interface see [here](docs/)

### Features
* Hardware virtualisation support for the following architectures:
    * ARM
        * ARMv7 (+ Virtualisation Extensions)
        * ARMv8
    * X86
        * ia32 (Intel VTX)
* IRQ Controller emulation
    * GICv2 (aarch32, aarch64)
    * PIC & LAPIC (ia32)
* Guest VM Memory and RAM Management
* Guest VCPU Fault and Context Management
* VM Runtime Management

#### Architecture Specific Features

#####  ARM
* SMP support for GICv2 (ARM) platforms
##### X86
* IOPort fault registration handler
* VMCall handler registration interface

### Potential future features (yet to be implemented)

#### Architecture Specific Features
##### ARM
* Virtual GICv3 support (aarch32 & aarch64)
    * + SMP support for GICv3 platforms
##### X86
* x86-64 support (Intel VTX)
* SMP support on x86 platforms (ia32 & x86\_64)

*Note: This is a consolidated library composed of libraries previously known as (but now deprecated) 'libsel4vmm' (x86)
and 'libsel4arm-vmm' (arm).*
