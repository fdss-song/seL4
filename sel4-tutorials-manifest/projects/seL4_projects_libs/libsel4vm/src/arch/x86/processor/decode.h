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

#include <sel4vm/guest_vm.h>
#include <sel4vm/arch/guest_x86_context.h>

#define MAX_INSTR_OPCODES 255
#define OP_ESCAPE 0xf

int vm_fetch_instruction(vm_vcpu_t *vcpu, uint32_t eip, uintptr_t cr3, int len, uint8_t *buf);

int vm_decode_instruction(uint8_t *instr, int instr_len, int *reg, uint32_t *imm, int *op_len);

void vm_decode_ept_violation(vm_vcpu_t *vcpu, int *reg, uint32_t *imm, int *size);

/* Interpret just enough virtual 8086 instructions to run trampoline code.
   Returns the final jump address */
uintptr_t vm_emulate_realmode(vm_vcpu_t *vcpu, uint8_t *instr_buf,
                              uint16_t *segment, uintptr_t eip, uint32_t len, guest_state_t *gs);

// TODO don't have these in a header, make them inline functions
const static int vm_decoder_reg_mapw[] = {
    VCPU_CONTEXT_EAX,
    VCPU_CONTEXT_ECX,
    VCPU_CONTEXT_EDX,
    VCPU_CONTEXT_EBX,
    /*VCPU_CONTEXT_ESP*/ -1,
    VCPU_CONTEXT_EBP,
    VCPU_CONTEXT_ESI,
    VCPU_CONTEXT_EDI
};

const static int vm_decoder_reg_mapb[] = {
    VCPU_CONTEXT_EAX,
    VCPU_CONTEXT_ECX,
    VCPU_CONTEXT_EDX,
    VCPU_CONTEXT_EBX,
    VCPU_CONTEXT_EAX,
    VCPU_CONTEXT_ECX,
    VCPU_CONTEXT_EDX,
    VCPU_CONTEXT_EBX
};

