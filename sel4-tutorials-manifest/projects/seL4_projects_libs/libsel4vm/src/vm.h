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

#include <sel4vm/guest_vm.h>

/* Internal exit codes */
#define VM_EXIT_UNHANDLED           0
#define VM_EXIT_HANDLED             1
#define VM_EXIT_HANDLE_ERROR       -1

typedef int(*vm_exit_handler_fn_t)(vm_vcpu_t *vcpu);

int vm_run_arch(vm_t *vm);
