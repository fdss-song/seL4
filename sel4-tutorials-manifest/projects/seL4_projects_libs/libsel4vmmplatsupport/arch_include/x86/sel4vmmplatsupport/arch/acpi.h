/*
 * Copyright 2019, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(DATA61_GPL)
 */

#pragma once

/***
 * @module acpi.h
 * The ACPI module provides support for generating ACPI table in a guest x86 VM. This being particularly leveraged
 * for booting a guest Linux VM.
 */

#define LOWER_BIOS_START (0xE0000)
#define LOWER_BIOS_SIZE (0xFFFF)

#define ACPI_START (LOWER_BIOS_START) // Start of ACPI tables; RSD PTR is right here
#define XSDT_START (ACPI_START + 0x1000)

#define MAX_ACPI_TABLES (2)

#include <sel4vm/guest_vm.h>

/***
 * @function make_guest_acpi_tables(vm)
 * Creates ACPI table for the guest VM
 * @param {vm_t *} vm       A handle to the guest VM instance
 * @return                  0 for success, -1 for error
 */
int make_guest_acpi_tables(vm_t *vm);
