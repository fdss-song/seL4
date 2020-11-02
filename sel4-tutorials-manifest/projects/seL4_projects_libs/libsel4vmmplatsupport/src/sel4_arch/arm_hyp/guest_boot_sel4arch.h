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
#include <sel4vm/sel4_arch/processor.h>

static inline void sel4arch_set_bootargs(seL4_UserContext *regs, seL4_Word pc,
                                         seL4_Word mach_type, seL4_Word atags)
{
    regs->r0 = 0;
    regs->r1 = mach_type;
    regs->r2 = atags;
    regs->pc = pc;
    regs->cpsr = MODE_SUPERVISOR;
}
