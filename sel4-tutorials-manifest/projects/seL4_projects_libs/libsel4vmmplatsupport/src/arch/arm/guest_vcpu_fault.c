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
#include <sel4vm/arch/processor.h>
#include <sel4vm/sel4_arch/processor.h>
#include <sel4vmmplatsupport/arch/guest_vcpu_fault.h>

#include <vcpu_fault_handlers.h>

int vmm_handle_arm_vcpu_exception(vm_vcpu_t *vcpu, uint32_t hsr, void *cookie)
{
    uint32_t ec_class = HSR_EXCEPTION_CLASS(hsr);
    vcpu_exception_handler_fn exception_handler = vcpu_exception_handlers[ec_class];
    if (!exception_handler) {
        ZF_LOGE("Unknown VCPU HSR Exception Class: No registered handler");
        return -1;
    }
    return exception_handler(vcpu, hsr);
}

int register_arm_vcpu_exception_handler(uint32_t ec_class, vcpu_exception_handler_fn exception_handler)
{
    if (ec_class > HSR_MAX_EXCEPTION) {
        ZF_LOGE("Failed to register vcpu exception handler: Invalid handler");
        return -1;
    }
    vcpu_exception_handlers[ec_class] = exception_handler;
    return 0;
}
