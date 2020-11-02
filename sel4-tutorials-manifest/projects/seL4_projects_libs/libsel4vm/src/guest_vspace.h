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

#include <sel4/sel4.h>
#include <vspace/vspace.h>
#include <vka/vka.h>

/* Constructs a vspace that will duplicate mappings between a page directory and several IO spaces */
int vm_init_guest_vspace(vspace_t *loader, vspace_t *vmm, vspace_t *new_vspace, vka_t *vka, seL4_CPtr page_directory);
