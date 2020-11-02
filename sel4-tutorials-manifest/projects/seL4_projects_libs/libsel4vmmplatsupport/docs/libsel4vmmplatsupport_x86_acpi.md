<!--
     Copyright 2020, Data61
     Commonwealth Scientific and Industrial Research Organisation (CSIRO)
     ABN 41 687 119 230.

     This software may be distributed and modified according to the terms of
     the BSD 2-Clause license. Note that NO WARRANTY is provided.
     See "LICENSE_BSD2.txt" for details.

     @TAG(DATA61_BSD)
-->

## Interface `acpi.h`

The ACPI module provides support for generating ACPI table in a guest x86 VM. This being particularly leveraged
for booting a guest Linux VM.

### Brief content:

**Functions**:

> [`make_guest_acpi_tables(vm)`](#function-make_guest_acpi_tablesvm)


## Functions

The interface `acpi.h` defines the following functions.

### Function `make_guest_acpi_tables(vm)`

Creates ACPI table for the guest VM

**Parameters:**

- `vm {vm_t *}`: A handle to the guest VM instance

**Returns:**

- 0 for success, -1 for error

Back to [interface description](#module-acpih).


Back to [top](#).

