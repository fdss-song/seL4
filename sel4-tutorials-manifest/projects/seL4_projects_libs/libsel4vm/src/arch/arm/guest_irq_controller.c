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

#include "vgic/vgic.h"

int vm_create_default_irq_controller(vm_t *vm)
{
    if (!vm) {
        ZF_LOGE("Failed to initialise default irq controller: Invalid vm");
        return -1;
    }
    return vm_install_vgic(vm);
}
