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

enum img_type {
    /* Binary file, or unknown type */
    IMG_BIN,
    /* Elf file */
    IMG_ELF,
    /* u-boot image */
    IMG_UIMAGE,
    /* Android boot image */
    IMG_ABOOT,
    /* Self decompressing linux image file */
    IMG_ZIMAGE,
    /* Initrd image */
    IMG_INITRD_GZ,
    /* Flattened device tree blob */
    IMG_DTB,
};

struct guest_kernel_image_arch {};
