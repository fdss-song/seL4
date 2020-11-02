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
#include <stdlib.h>
#include <string.h>

#include <sel4vmmplatsupport/plat/devices.h>
#include <platsupport/plat/serial.h>

const struct device dev_uartd = {
    .name = "uartd",
    .pstart = UARTD_PADDR,
    .size = PAGE_SIZE,
    .handle_device_fault = NULL,
    .priv = NULL
};
