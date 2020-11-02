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

typedef enum vm_exit_codes {
    VM_GUEST_MMIO_EXIT,
    VM_GUEST_IO_EXIT,
    VM_GUEST_NOTIFICATION_EXIT,
    VM_GUEST_UNKNOWN_EXIT
} vm_exit_codes_t;

#define VM_GUEST_ERROR_EXIT -1
