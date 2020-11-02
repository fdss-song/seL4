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

#include <sel4vm/guest_vcpu_fault.h>

seL4_Word emulate_vcpu_fault(vm_vcpu_t *vcpu, seL4_Word data)
{
    seL4_Word fault_data, mask, byte_shift;
    byte_shift = (get_vcpu_fault_address(vcpu) & 0x3) * 8;
    mask = get_vcpu_fault_data_mask(vcpu);
    fault_data = get_vcpu_fault_data(vcpu);
    if (is_vcpu_read_fault(vcpu)) {
        /* Read data must be shifted to lsb */
        return (data & ~(mask >> byte_shift)) | ((fault_data & mask) >> byte_shift);
    } else {
        /* Data to write must be shifted left to compensate for alignment */
        return (data & ~mask) | ((fault_data << byte_shift) & mask);
    }
}
