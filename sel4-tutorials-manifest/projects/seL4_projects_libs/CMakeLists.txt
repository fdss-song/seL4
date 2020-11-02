#
# Copyright 2017, Data61
# Commonwealth Scientific and Industrial Research Organisation (CSIRO)
# ABN 41 687 119 230.
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(DATA61_BSD)
#

cmake_minimum_required(VERSION 3.8.2)

add_subdirectory(libsel4vm)
add_subdirectory(libsel4vchan)
add_subdirectory(libsel4dma)
add_subdirectory(libsel4bga)
add_subdirectory(libsel4keyboard)
add_subdirectory(libsel4vmmplatsupport)

set(configure_string "")
config_option(LibNanopb BUILD_NANOPB "Build Nanopb and related libraries" DEFAULT OFF)
mark_as_advanced(LibNanopb)
if(LibNanopb)
    add_subdirectory(libsel4nanopb)
    add_subdirectory(libsel4rpc)
endif()
