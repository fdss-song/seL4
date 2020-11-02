/*
 * Copyright 2017, Data61
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

#include <sel4/sel4.h>

#include <sel4vm/guest_vm.h>

int vm_vmcs_read(seL4_CPtr vcpu, seL4_Word field, unsigned int *value);
int vm_vmcs_write(seL4_CPtr vcpu, seL4_Word field, seL4_Word value);
void vm_vmcs_init_guest(vm_vcpu_t *vcpu);
