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

#include "i8259/i8259.h"
#include "processor/apicdef.h"
#include "processor/lapic.h"

int vm_create_default_irq_controller(vm_t *vm)
{
    int err;

    if (!vm) {
        ZF_LOGE("Failed to initialise default irq controller: Invalid vm");
        return -1;
    }

    err = i8259_pre_init(vm);
    if (err) {
        return -1;
    }

    /* Add local apic memory handler */
    vm_memory_reservation_t *apic_reservation = vm_reserve_memory_at(vm, APIC_DEFAULT_PHYS_BASE,
                                                                     sizeof(struct local_apic_regs), apic_fault_callback, NULL);
    if (!apic_reservation) {
        ZF_LOGE("Failed to reserve apic memory");
        return -1;
    }

    return 0;
}
