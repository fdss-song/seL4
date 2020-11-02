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

/* ARM VM Exit Reasons */
enum arm_vm_exit_reasons {
    VM_GUEST_ABORT_EXIT,
    VM_SYSCALL_EXIT,
    VM_USER_EXCEPTION_EXIT,
    VM_VGIC_MAINTENANCE_EXIT,
    VM_VCPU_EXIT,
    VM_VPPI_EXIT,
    VM_UNKNOWN_EXIT,
    VM_NUM_EXITS
};
