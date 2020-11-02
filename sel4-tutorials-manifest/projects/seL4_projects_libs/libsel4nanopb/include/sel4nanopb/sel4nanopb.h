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

#include <pb.h>
#include <sel4/sel4.h>

/* bind a nanopb stream to the IPC buffer of the thread */
pb_ostream_t pb_ostream_from_IPC(seL4_Word offset);
pb_istream_t pb_istream_from_IPC(seL4_Word offset);
