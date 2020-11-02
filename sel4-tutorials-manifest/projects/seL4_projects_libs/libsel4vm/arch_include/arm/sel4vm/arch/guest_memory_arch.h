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

typedef struct vm vm_t;

/**
 * Convert an intermediate physical address belonging to a guest VM to a physical address
 * @param[in] vm            A handle to the vm
 * @param[in] ipa_base      The intermediate physical address
 * @param[in] size          Size of the memory region
 * @return                  Physical address value
 */
uintptr_t vm_arm_ipa_to_pa(vm_t *vm, uintptr_t ipa_base, size_t size);
