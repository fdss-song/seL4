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

/* The following constants are found in the virtio spec: http://docs.oasis-open.org/virtio/virtio/v1.0/cs04/virtio-v1.0-cs04.html#x1-650001
 * Necessary for identifying a virtio pci device */

/* Virtio PCI Vendor ID. A PCI device with the following vendor ID is a
 * virtio device */
#define VIRTIO_PCI_VENDOR_ID            0x1af4
#define VIRTIO_PCI_SUBSYSTEM_VENDOR_ID  0x1af4

/* Virtio device IDs  */
#define VIRTIO_NET_PCI_DEVICE_ID        0x1000
#define VIRTIO_CONSOLE_PCI_DEVICE_ID    0x1003

/* Virtio subsystem device ids */
#define VIRTIO_ID_NET                   1
#define VIRTIO_ID_CONSOLE               3

/* Virtio PCI device classes  */
#define VIRTIO_PCI_CLASS_NET            0x020000
#define VIRTIO_PCI_CLASS_CONSOLE        0x078000
