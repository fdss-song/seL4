/*
 * Copyright 2020, Data61
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

/***
 * @module guest_vcpu_util.h
 * The guest vcpu util interface provides abstractions and helpers for managing libsel4vm vcpus.
 */

#include <sel4vm/guest_vm.h>
#include <sel4vmmplatsupport/arch/guest_vcpu_util.h>

/***
 * @function create_vmm_plat_vcpu(vm, priority)
 * Create a new platform vcpu. This is a wrapper around the libsel4vm function `vm_create_vcpu` however
 * further intialises and configures the vcpu with platform specific attributes
 * @param {vm_t *} vm       A handle to the VM
 * @param {int} priority    Priority of the new vcpu thread
 * @return                  NULL for error, otherwise pointer to created vm_vcpu_t object
 */
vm_vcpu_t *create_vmm_plat_vcpu(vm_t *vm, int priority);
