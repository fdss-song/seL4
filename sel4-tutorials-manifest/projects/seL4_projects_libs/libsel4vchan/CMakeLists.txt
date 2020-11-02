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

project(libsel4vchan C)

add_compile_options(-std=gnu99)

file(GLOB sources src/*.c)

add_library(sel4vchan STATIC EXCLUDE_FROM_ALL ${sources})
target_include_directories(sel4vchan PUBLIC include)
target_link_libraries(sel4vchan muslc sel4 sel4simple utils sel4utils sel4vka sel4vspace sel4dma)
