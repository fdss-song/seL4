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

#include <sel4vm/guest_vm.h>

#define dev_vconsole dev_uart2
extern const struct device dev_uart0;
extern const struct device dev_uart1;
extern const struct device dev_uart2;
extern const struct device dev_uart3;

/**
 * Installs a UART device which provides access to FIFO and IRQ
 * control registers, but prevents access to configuration registers
 * @param[in] vm  The vm in which to install the device
 * @param[in] d   A description of the UART device
 * @return        0 on success
 */
int vm_install_ac_uart(vm_t *vm, const struct device *d);

/**
 * Installs the default console device. Characters written to the
 * console are buffered until end of line. The output data will
 * be printed with a background colour to identify the VM
 * @param[in] vm The VM in which to install the vconsole device
 * @return       0 on success
 */
int vm_install_vconsole(vm_t *vm);
