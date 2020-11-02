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

#include <sel4vm/guest_vm.h>

/* Init function */
int i8259_pre_init(vm_t *vm);

/* Functions to retrieve interrupt state */
int i8259_get_interrupt(vm_t *vm);
int i8259_has_interrupt(vm_t *vm);
