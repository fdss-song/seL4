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
#include <stdio.h>
#include <pb_encode.h>
#include <pb_decode.h>
#include <utils/fence.h>
#include <sel4nanopb/sel4nanopb.h>
#include <sel4/sel4.h>

pb_ostream_t pb_ostream_from_IPC(seL4_Word offset)
{
    char *msg_buffer = (char *) & (seL4_GetIPCBuffer()->msg[offset]);
    size_t size = seL4_MsgMaxLength * sizeof(seL4_Word) - offset;
    return pb_ostream_from_buffer(msg_buffer, size);
}

pb_istream_t pb_istream_from_IPC(seL4_Word offset)
{
    char *msg_buffer = (char *) & (seL4_GetIPCBuffer()->msg[offset]);
    size_t size = seL4_MsgMaxLength * sizeof(seL4_Word) - offset;
    return pb_istream_from_buffer(msg_buffer, size);
}
