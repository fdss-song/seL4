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

#include <sel4/sel4.h>
#include <vka/object.h>
#include <vka/capops.h>

#include <sel4vm/guest_vm.h>
#include <sel4vmmplatsupport/arch/service.h>

int vmm_install_service(vm_t *vm, seL4_CPtr service, int index, uint32_t b)
{
    cspacepath_t src, dst;
    seL4_Word badge = b;
    int err;
    vka_cspace_make_path(vm->vka, service, &src);
    dst.root = vm->cspace.cspace_obj.cptr;
    dst.capPtr = index;
    dst.capDepth = VM_CSPACE_SIZE_BITS;
    err =  vka_cnode_mint(&dst, &src, seL4_AllRights, badge);
    return err;
}


