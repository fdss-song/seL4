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

project(libsel4rpc C)

include(nanopb)

SEL4_GENERATE_PROTOBUF(proto_srcs proto_hdrs ${CMAKE_CURRENT_SOURCE_DIR}/rpc.proto)
file(GLOB sel4rpc_src src/*.c)

add_library(sel4rpc EXCLUDE_FROM_ALL ${sel4rpc_src} ${proto_srcs})
target_include_directories(
    sel4rpc
    PUBLIC include ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(
    sel4rpc
    PUBLIC
        muslc
        utils
        sel4
        sel4nanopb
        sel4utils
        sel4vka
        nanopb
    PRIVATE sel4_autoconf
)
