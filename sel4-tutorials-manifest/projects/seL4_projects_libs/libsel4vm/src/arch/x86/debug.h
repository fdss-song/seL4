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

#include <autoconf.h>
#include <sel4vm/gen_config.h>
#include <sel4vm/guest_vm.h>

#ifndef COLOUR
#define COLOUR "\033[;1;%dm"
#define COLOUR_R "\033[;1;31m"
#define COLOUR_G "\033[;1;32m"
#define COLOUR_Y "\033[;1;33m"
#define COLOUR_B "\033[;1;34m"
#define COLOUR_M "\033[;1;35m"
#define COLOUR_C "\033[;1;36m"
#define COLOUR_RESET "\033[0m"
#endif

void vm_print_guest_context(vm_vcpu_t *);

