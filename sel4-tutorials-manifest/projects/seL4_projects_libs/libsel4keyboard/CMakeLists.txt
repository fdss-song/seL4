#
# Copyright 2018, Data61
# Commonwealth Scientific and Industrial Research Organisation (CSIRO)
# ABN 41 687 119 230.
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(DATA61_BSD)
#

cmake_minimum_required(VERSION 3.7.2)

project(libsel4keyboard C)

# Exclude this project in ARM builds as it will have no sources and thus not be a valid library

if(KernelArchX86)

    set(deps src/arch-x86/keyboard.c src/codes.c)

    add_library(sel4keyboard STATIC EXCLUDE_FROM_ALL ${deps})
    target_include_directories(sel4keyboard PUBLIC include "arch_include/x86")
    target_link_libraries(sel4keyboard muslc)

endif()
