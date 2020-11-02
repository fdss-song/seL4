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

#include <sel4vm/guest_vm.h>
#include <sel4vm/guest_memory.h>

memory_fault_result_t default_error_fault_callback(vm_t *vm, vm_vcpu_t *vcpu, uintptr_t fault_addr,
                                                   size_t fault_length, void *cookie)
{
    ZF_LOGE("Failed to handle fault addr: 0x%x", fault_addr);
    return FAULT_ERROR;
}
