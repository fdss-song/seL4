<!--
     Copyright 2020, Data61
     Commonwealth Scientific and Industrial Research Organisation (CSIRO)
     ABN 41 687 119 230.

     This software may be distributed and modified according to the terms of
     the BSD 2-Clause license. Note that NO WARRANTY is provided.
     See "LICENSE_BSD2.txt" for details.

     @TAG(DATA61_BSD)
-->

## Interface `guest_vcpu_util.h`

The ARM guest vcpu util interface provides abstractions and helpers for managing libsel4vm vcpus on an ARM platform.

### Brief content:

**Functions**:

> [`fdt_generate_plat_vcpu_node(vm, fdt)`](#function-fdt_generate_plat_vcpu_nodevm-fdt)


## Functions

The interface `guest_vcpu_util.h` defines the following functions.

### Function `fdt_generate_plat_vcpu_node(vm, fdt)`

Generate a CPU device node for a given fdt. This taking into account
the vcpus created for the VM.

**Parameters:**

- `vm {vm_t *}`: A handle to the VM
- `fdt {void *}`: FDT blob to append generated device node

**Returns:**

- 0 for success, -1 for error

Back to [interface description](#module-guest_vcpu_utilh).


Back to [top](#).

