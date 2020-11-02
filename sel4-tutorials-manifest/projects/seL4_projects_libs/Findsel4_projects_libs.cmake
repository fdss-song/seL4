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

set(SEL4_PROJECTS_LIBS_DIR "${CMAKE_CURRENT_LIST_DIR}" CACHE STRING "")
mark_as_advanced(SEL4_PROJECTS_LIBS_DIR)

function(sel4_projects_libs_import_libraries)
    add_subdirectory(${SEL4_PROJECTS_LIBS_DIR} sel4_projects_libs)
endfunction()

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(sel4_projects_libs DEFAULT_MSG SEL4_PROJECTS_LIBS_DIR)
