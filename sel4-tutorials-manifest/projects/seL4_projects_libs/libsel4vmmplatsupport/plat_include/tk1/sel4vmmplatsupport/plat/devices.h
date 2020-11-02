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

#include <sel4vmmplatsupport/device.h>
#include <sel4vmmplatsupport/plat/device_map.h>

#define dev_vconsole dev_uartd

extern const struct device dev_uartd;
extern const struct device dev_clkcar;
extern const struct device dev_usb1;
extern const struct device dev_usb3;
extern const struct device dev_sdmmc;
extern const struct device dev_rtc_kbc_pmc;
extern const struct device dev_data_memory;
extern const struct device dev_exception_vectors;
extern const struct device dev_system_registers;
extern const struct device dev_ictlr;
extern const struct device dev_apb_misc;
extern const struct device dev_fuse;
extern const struct device dev_gpios;

typedef int (*vm_power_cb)(vm_t* vm, void* token);
int vm_install_vpower(vm_t* vm, vm_power_cb shutdown_cb, void* shutdown_token,
                      vm_power_cb reboot_cb, void* reboot_token);
