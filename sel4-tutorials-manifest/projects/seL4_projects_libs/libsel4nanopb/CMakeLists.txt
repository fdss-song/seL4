#
# Copyright 2019, Data61
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

project(libsel4nanopb C)

include(nanopb)

include_directories(${NANOPB_INCLUDE_DIRS})

add_library(sel4nanopb EXCLUDE_FROM_ALL src/common.c)
target_include_directories(sel4nanopb PUBLIC include)
target_link_libraries(sel4nanopb muslc utils sel4 nanopb)
