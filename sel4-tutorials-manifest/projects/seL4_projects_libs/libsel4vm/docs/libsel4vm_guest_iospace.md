<!--
     Copyright 2020, Data61
     Commonwealth Scientific and Industrial Research Organisation (CSIRO)
     ABN 41 687 119 230.

     This software may be distributed and modified according to the terms of
     the BSD 2-Clause license. Note that NO WARRANTY is provided.
     See "LICENSE_BSD2.txt" for details.

     @TAG(DATA61_BSD)
-->

## Interface `guest_iospace.h`

The libsel4vm iospace interface enables the registration and management of a guest VM's IO Space. This
being used when supporting IOMMU (x86) and SMMU (ARM) VM features.

### Brief content:

**Functions**:

> [`vm_guest_add_iospace(vm, loader, iospace)`](#function-vm_guest_add_iospacevm-loader-iospace)


## Functions

The interface `guest_iospace.h` defines the following functions.

### Function `vm_guest_add_iospace(vm, loader, iospace)`

Attach an additional IO space to the given VM

**Parameters:**

- `vm {vm_t *}`: A handle to the VM
- `loader {vspace_t *}`: Host loader vspace to create a new iospace
- `iospace {seL4_CPtr}`: Capability to iospace being added

**Returns:**

- 0 on success, otherwise -1 for error

Back to [interface description](#module-guest_iospaceh).


Back to [top](#).

