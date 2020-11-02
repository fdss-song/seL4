/*
 * Copyright 2019, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_BSD)
 */

#pragma once

#include <sel4/sel4.h>
#include <vspace/vspace.h>
#include <vka/vka.h>
#include <sel4vm/guest_vm.h>

/***
 * @module guest_iospace.h
 * The libsel4vm iospace interface enables the registration and management of a guest VM's IO Space. This
 * being used when supporting IOMMU (x86) and SMMU (ARM) VM features.
 */

/***
 * @function vm_guest_add_iospace(vm, loader, iospace)
 * Attach an additional IO space to the given VM
 * @param {vm_t *} vm           A handle to the VM
 * @param {vspace_t *} loader   Host loader vspace to create a new iospace
 * @param {seL4_CPtr} iospace   Capability to iospace being added
 * @return                      0 on success, otherwise -1 for error
 */
int vm_guest_add_iospace(vm_t *vm, vspace_t *loader, seL4_CPtr iospace);
