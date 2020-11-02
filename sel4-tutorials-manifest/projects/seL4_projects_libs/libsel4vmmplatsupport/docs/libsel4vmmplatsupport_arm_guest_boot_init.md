<!--
     Copyright 2020, Data61
     Commonwealth Scientific and Industrial Research Organisation (CSIRO)
     ABN 41 687 119 230.

     This software may be distributed and modified according to the terms of
     the BSD 2-Clause license. Note that NO WARRANTY is provided.
     See "LICENSE_BSD2.txt" for details.

     @TAG(DATA61_BSD)
-->

## Interface `guest_boot_init.h`

The libsel4vmmplatsupport arm guest boot init interface provides helpers to initialise the booting state of
a VM instance. This currently only targets booting a Linux guest OS.

### Brief content:

**Functions**:

> [`vcpu_set_bootargs(vcpu, pc, mach_type, atags)`](#function-vcpu_set_bootargsvcpu-pc-mach_type-atags)


## Functions

The interface `guest_boot_init.h` defines the following functions.

### Function `vcpu_set_bootargs(vcpu, pc, mach_type, atags)`

Set the boot args and pc for the VM.
For linux:
r0 -> 0
r1 -> MACH_TYPE  (e.g #4151 for EXYNOS5410 eval. platform smdk5410)
r2 -> atags/dtb address

**Parameters:**

- `vcpu {vm_vcpu_t *}`: A handle to the boot VCPU
- `pc {seL4_Word}`: The initial PC for the VM
- `mach_type {seL4_Word}`: Linux specific machine ID see http://www.arm.linux.org.uk/developer/machines/
- `atags {seL4_Word}`: Linux specific IPA of atags. Can also be substituted with dtb address

**Returns:**

- 0 on success, otherwise -1 for failure

Back to [interface description](#module-guest_boot_inith).


Back to [top](#).

