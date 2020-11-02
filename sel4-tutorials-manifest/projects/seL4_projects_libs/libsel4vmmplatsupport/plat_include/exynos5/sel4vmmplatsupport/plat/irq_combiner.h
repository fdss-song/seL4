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

/**
 * vm_combiner_irq_handler should be called when an IRQ combiner IRQ occurs.
 * The caller is responsible for acknowledging the IRQ once this function
 * returns
 */
int vm_install_vcombiner(vm_t *vm);
void vm_combiner_irq_handler(vm_t *vm, int irq);
