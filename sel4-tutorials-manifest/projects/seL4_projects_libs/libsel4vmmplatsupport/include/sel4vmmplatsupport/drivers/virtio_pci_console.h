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

typedef void (*console_handle_irq_fn_t)(void *cookie);
typedef void (*console_putchar_fn_t)(char c);

struct console_passthrough {
    console_handle_irq_fn_t handleIRQ;
    console_putchar_fn_t    putchar;
    void                   *console_data;
};

typedef int (*console_driver_init)(struct console_passthrough *driver, ps_io_ops_t io_ops, void *config);
