/*
 * Copyright 2017, Data61
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

typedef struct vm_vcpu vm_vcpu_t;

/* Request that the guest exist as soon as it is ready to receive
 * interrupts */
void wait_for_guest_ready(vm_vcpu_t *vcpu);

/* inject an exception */
void vm_inject_exception(vm_vcpu_t *vcpu, int exception, int has_error, uint32_t error_code);

/* Start an AP vcpu after a sipi with the requested vector */
void vm_start_ap_vcpu(vm_vcpu_t *vcpu, unsigned int sipi_vector);

/* Got interrupt(s) from PIC, propagate to relevant vcpu lapic */
void vm_check_external_interrupt(vm_t *vm);

/* inject an interrupt from the lapic on the vcpu, whether or not it is in an exit */
void vm_vcpu_accept_interrupt(vm_vcpu_t *vcpu);

/* This function is called when a new interrupt has occured. */
void vm_have_pending_interrupt(vm_vcpu_t *vcpu);

