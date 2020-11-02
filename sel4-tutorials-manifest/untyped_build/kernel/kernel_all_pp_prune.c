# 1 "kernel/kernel_all_pp_prune_wrapper_temp.c"
# 1 "/host/untyped_build//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "kernel/kernel_all_pp_prune_wrapper_temp.c"
# 1 "/host/kernel/src/api/faults.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

# 1 "/host/kernel/include/config.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

/* Compile-time configuration parameters. Might be set by the build system. */


# 1 "kernel/autoconf/autoconf.h" 1



# 1 "kernel/gen_config/kernel/gen_config.h" 1
# 5 "kernel/autoconf/autoconf.h" 2
# 13 "/host/kernel/include/config.h" 2


/* size of the initial thread's root CNode (2^x slots, x >= 4) */




/* number of timer ticks until a thread is preempted  */
# 37 "/host/kernel/include/config.h"
/* the number of scheduler domains */




/* number of priorities per domain */




/* maximum number of caps that can be created in one retype invocation */




/* chunk size for memory clears during retype, in bits. */




/* maximum number of iterations until we preempt a delete/revoke invocation */




/* address range to flush per preemption work unit */




/* maximum number of untyped caps in bootinfo */
/* WARNING: must match value in libsel4! */
/* CONSTRAINT: (16 * CONFIG_MAX_NUM_BOOTINFO_DEVICE_REGIONS) + (5 * CONFIG_MAX_NUM_BOOTINFO_UNTYPED_CAPS) <= 4036 */





/* length of a timer tick in ms  */





/* maximum number of different tracepoints which can be placed in the kernel */




/* maximum number of IOMMU RMRR entries we can record while ACPI parsing */




/* maximum number of IOAPIC supported */




/* Alias CONFIG_MAX_NUM_NODES > 1 to ENABLE_SMP_SUPPORT */
# 8 "/host/kernel/src/api/faults.c" 2
# 1 "/host/kernel/include/types.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

# 1 "/host/kernel/include/basic_types.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

# 1 "/host/kernel/include/stdint.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

# 1 "/host/kernel/include/64/mode/stdint.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 10 "/host/kernel/include/stdint.h" 2

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;
# 10 "/host/kernel/include/basic_types.h" 2
# 1 "/host/kernel/include/arch/x86/arch/types.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


# 1 "/host/kernel/include/assert.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


# 1 "/host/kernel/include/util.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 20 "/host/kernel/include/util.h"
/* time constants */
# 55 "/host/kernel/include/util.h"
/** MODIFIES: */
void __builtin_unreachable(void);







/* Borrowed from linux/include/linux/compiler.h */







/* need that for compiling with c99 instead of gnu99 */


/* Evaluate a Kconfig-provided configuration setting at compile-time. */






/* Check the existence of a configuration setting, returning one value if it
 * exists and a different one if it does not */





/** MODIFIES:
    FNSPEC
        halt_spec: "\<Gamma> \<turnstile> {} Call halt_'proc {}"
*/
void halt(void) __attribute__((__noreturn__));
void memzero(void *s, unsigned long n);
void *memset(void *s, unsigned long c, unsigned long n) __attribute__((externally_visible));
void *memcpy(void *ptr_dst, const void *ptr_src, unsigned long n) __attribute__((externally_visible));
int __attribute__((__pure__)) strncmp(const char *s1, const char *s2, int n);
long __attribute__((__const__)) char_to_long(char c);
long __attribute__((__pure__)) str_to_long(const char *str);


int __builtin_clzl(unsigned long x);
int __builtin_ctzl(unsigned long x);







/** MODIFIES: */
/** DONT_TRANSLATE */
/** FNSPEC clzl_spec:
  "\<forall>s. \<Gamma> \<turnstile>
    {\<sigma>. s = \<sigma> \<and> x_' s \<noteq> 0 }
      \<acute>ret__long :== PROC clzl(\<acute>x)
    \<lbrace> \<acute>ret__long = of_nat (word_clz (x_' s)) \<rbrace>"
*/
static inline long
__attribute__((__const__)) clzl(unsigned long x)
{
    return __builtin_clzl(x);
}

/** MODIFIES: */
/** DONT_TRANSLATE */
/** FNSPEC ctzl_spec:
  "\<forall>s. \<Gamma> \<turnstile>
    {\<sigma>. s = \<sigma> \<and> x_' s \<noteq> 0 }
      \<acute>ret__long :== PROC ctzl(\<acute>x)
    \<lbrace> \<acute>ret__long = of_nat (word_ctz (x_' s)) \<rbrace>"
*/
static inline long
__attribute__((__const__)) ctzl(unsigned long x)
{
    return __builtin_ctzl(x);
}



int __builtin_popcountl(unsigned long x);

/** DONT_TRANSLATE */
/** FNSPEC clzll_spec:
  "\<forall>s. \<Gamma> \<turnstile>
    {\<sigma>. s = \<sigma> \<and> x_' s \<noteq> 0 }
      \<acute>ret__longlong :== PROC clzll(\<acute>x)
    \<lbrace> \<acute>ret__longlong = of_nat (word_clz (x_' s)) \<rbrace>"
*/
static inline long long __attribute__((__const__)) clzll(unsigned long long x)
{
    return __builtin_clzll(x);
}

/** DONT_TRANSLATE */
static inline long
__attribute__((__const__)) popcountl(unsigned long mask)
{
# 167 "/host/kernel/include/util.h"
    return __builtin_popcountl(mask);

}



/* Can be used to insert padding to the next L1 cache line boundary */
# 11 "/host/kernel/include/assert.h" 2



void _fail(
    const char *str,
    const char *file,
    unsigned int line,
    const char *function
) __attribute__((__noreturn__));



void _assert_fail(
    const char *assertion,
    const char *file,
    unsigned int line,
    const char *function
) __attribute__((__noreturn__));
# 41 "/host/kernel/include/assert.h"
/* Create an assert that will trigger a compile error if it fails. */



/* Sometimes compile asserts contain expressions that the C parser cannot
 * handle. For such expressions unverified_compile_assert should be used. */
# 11 "/host/kernel/include/arch/x86/arch/types.h" 2





typedef int __assert_failed_long_is_64bits[(sizeof(unsigned long) == 8) ? 1 : -1];


typedef unsigned long word_t;
typedef signed long sword_t;
typedef word_t vptr_t;
typedef word_t paddr_t;
typedef word_t pptr_t;
typedef word_t cptr_t;
typedef word_t dev_id_t;
typedef word_t cpu_id_t;
typedef uint32_t logical_id_t;
typedef word_t node_id_t;
typedef word_t dom_t;

/* for libsel4 headers that the kernel shares */
typedef word_t seL4_Word;
typedef cptr_t seL4_CPtr;
typedef uint16_t seL4_Uint16;
typedef uint32_t seL4_Uint32;
typedef uint8_t seL4_Uint8;
typedef node_id_t seL4_NodeId;
typedef paddr_t seL4_PAddr;
typedef dom_t seL4_Domain;

typedef uint64_t timestamp_t;
# 11 "/host/kernel/include/basic_types.h" 2

enum _bool {
    false = 0,
    true = 1
};
typedef word_t bool_t;

typedef struct region {
    pptr_t start;
    pptr_t end;
} region_t;

typedef struct p_region {
    paddr_t start;
    paddr_t end;
} p_region_t;

typedef struct v_region {
    vptr_t start;
    vptr_t end;
} v_region_t;




/* equivalent to a word_t except that we tell the compiler that we may alias with
 * any other type (similar to a char pointer) */
typedef word_t __attribute__((__may_alias__)) word_t_may_alias;
# 10 "/host/kernel/include/types.h" 2
# 1 "/host/kernel/include/compound_types.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


# 1 "/host/kernel/include/api/types.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




# 1 "/host/untyped_build/kernel/generated_prune/sel4/shared_types_gen.h" 1
# 13 "/host/kernel/include/api/types.h" 2
# 1 "/host/kernel/include/arch/x86/arch/api/types.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

# 1 "/host/kernel/libsel4/include/sel4/objecttype.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       
typedef enum api_object {
    seL4_UntypedObject,
    seL4_TCBObject,
    seL4_EndpointObject,
    seL4_NotificationObject,
    seL4_CapTableObject,




    seL4_NonArchObjectTypeCount,
} seL4_ObjectType;

__attribute__((deprecated("use seL4_NotificationObject"))) static const seL4_ObjectType seL4_AsyncEndpointObject =
    seL4_NotificationObject;

typedef seL4_Word api_object_t;
# 10 "/host/kernel/include/arch/x86/arch/api/types.h" 2

# 1 "/host/kernel/libsel4/sel4_arch_include/x86_64/sel4/sel4_arch/objecttype.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       


# 1 "kernel/autoconf/autoconf.h" 1
# 11 "/host/kernel/libsel4/sel4_arch_include/x86_64/sel4/sel4_arch/objecttype.h" 2


typedef enum _mode_object {
    seL4_X86_PDPTObject = seL4_NonArchObjectTypeCount,
    seL4_X64_PML4Object,

    seL4_X64_HugePageObject,

    seL4_ModeObjectTypeCount
} seL4_seL4ArchObjectType;

/* allow seL4_X86_PDPTObject and seL4_IA32_PDPTObject to be used interchangeable */
# 12 "/host/kernel/include/arch/x86/arch/api/types.h" 2
# 1 "/host/kernel/libsel4/arch_include/x86/sel4/arch/objecttype.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       


# 1 "kernel/autoconf/autoconf.h" 1
# 11 "/host/kernel/libsel4/arch_include/x86/sel4/arch/objecttype.h" 2


typedef enum _object {
    seL4_X86_4K = seL4_ModeObjectTypeCount,
    seL4_X86_LargePageObject,
    seL4_X86_PageTableObject,
    seL4_X86_PageDirectoryObject,
# 28 "/host/kernel/libsel4/arch_include/x86/sel4/arch/objecttype.h"
    seL4_ObjectTypeCount
} seL4_ArchObjectType;
typedef seL4_Word object_t;
# 13 "/host/kernel/include/arch/x86/arch/api/types.h" 2



enum asidConstants {
    asidInvalid = 0
};



typedef word_t asid_t;
# 14 "/host/kernel/include/api/types.h" 2

# 1 "/host/kernel/libsel4/include/sel4/macros.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       

# 1 "kernel/autoconf/autoconf.h" 1
# 10 "/host/kernel/libsel4/include/sel4/macros.h" 2

/*
 * Some compilers attempt to pack enums into the smallest possible type.
 * For ABI compatibility with the kernel, we need to ensure they remain
 * the same size as a 'long'.
 */
# 16 "/host/kernel/include/api/types.h" 2
# 1 "/host/kernel/libsel4/include/sel4/constants.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       


# 1 "kernel/autoconf/autoconf.h" 1
# 11 "/host/kernel/libsel4/include/sel4/constants.h" 2
# 46 "/host/kernel/libsel4/include/sel4/constants.h"
enum priorityConstants {
    seL4_InvalidPrio = -1,
    seL4_MinPrio = 0,
    seL4_MaxPrio = 256 - 1
};

/* seL4_MessageInfo_t defined in api/shared_types.bf */

enum seL4_MsgLimits {
    seL4_MsgLengthBits = 7,
    seL4_MsgExtraCapBits = 2
};

enum {
    seL4_MsgMaxLength = 120,
};


/* seL4_CapRights_t defined in shared_types_*.bf */


typedef enum {
    seL4_NoFailure = 0,
    seL4_InvalidRoot,
    seL4_MissingCapability,
    seL4_DepthMismatch,
    seL4_GuardMismatch,
    _enum_pad_seL4_LookupFailureType = (1ULL << ((sizeof(long)*8) - 1)) - 1,
} seL4_LookupFailureType;
# 17 "/host/kernel/include/api/types.h" 2
# 1 "/host/kernel/libsel4/include/sel4/shared_types.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       

/* this file is shared between the kernel and libsel4 */

typedef struct seL4_IPCBuffer_ {
    seL4_MessageInfo_t tag;
    seL4_Word msg[seL4_MsgMaxLength];
    seL4_Word userData;
    seL4_Word caps_or_badges[((1ul<<(seL4_MsgExtraCapBits))-1)];
    seL4_CPtr receiveCNode;
    seL4_CPtr receiveIndex;
    seL4_Word receiveDepth;
} seL4_IPCBuffer __attribute__((__aligned__(sizeof(struct seL4_IPCBuffer_))));

typedef enum {
    seL4_CapFault_IP,
    seL4_CapFault_Addr,
    seL4_CapFault_InRecvPhase,
    seL4_CapFault_LookupFailureType,
    seL4_CapFault_BitsLeft,
    seL4_CapFault_DepthMismatch_BitsFound,
    seL4_CapFault_GuardMismatch_GuardFound = seL4_CapFault_DepthMismatch_BitsFound,
    seL4_CapFault_GuardMismatch_BitsFound,
    _enum_pad_seL4_CapFault_Msg = (1ULL << ((sizeof(long)*8) - 1)) - 1,
} seL4_CapFault_Msg;
# 18 "/host/kernel/include/api/types.h" 2
# 1 "/host/kernel/include/machine/io.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 17 "/host/kernel/include/machine/io.h"
void putDebugChar(unsigned char c);



/* io for dumping capdl */
unsigned char getDebugChar(void);



/* printf will result in output */
void putchar(char c);

word_t kprintf(const char *format, ...) __attribute__((externally_visible)) __attribute__((format(printf, 1, 2)));
word_t ksnprintf(char *str, word_t size, const char *format, ...);
word_t puts(const char *s) __attribute__((externally_visible));
# 19 "/host/kernel/include/api/types.h" 2

/* seL4_CapRights_t defined in mode/api/shared_types.bf */

typedef word_t prio_t;
typedef uint64_t ticks_t;
typedef uint64_t time_t;

enum domainConstants {
    minDom = 0,
    maxDom = 1 - 1
};

struct cap_transfer {
    cptr_t ctReceiveRoot;
    cptr_t ctReceiveIndex;
    word_t ctReceiveDepth;
};
typedef struct cap_transfer cap_transfer_t;

enum ctLimits {
    capTransferDataSize = 3
};

static inline seL4_CapRights_t __attribute__((__const__)) rightsFromWord(word_t w)
{
    seL4_CapRights_t seL4_CapRights;

    seL4_CapRights.words[0] = w;
    return seL4_CapRights;
}

static inline word_t __attribute__((__const__)) wordFromRights(seL4_CapRights_t seL4_CapRights)
{
    return seL4_CapRights.words[0] & ((1ul << (4))-1ul);
}

static inline cap_transfer_t __attribute__((__pure__)) capTransferFromWords(word_t *wptr)
{
    cap_transfer_t transfer;

    transfer.ctReceiveRoot = (cptr_t)wptr[0];
    transfer.ctReceiveIndex = (cptr_t)wptr[1];
    transfer.ctReceiveDepth = wptr[2];
    return transfer;
}

static inline seL4_MessageInfo_t __attribute__((__const__)) messageInfoFromWord_raw(word_t w)
{
    seL4_MessageInfo_t mi;

    mi.words[0] = w;
    return mi;
}

static inline seL4_MessageInfo_t __attribute__((__const__)) messageInfoFromWord(word_t w)
{
    seL4_MessageInfo_t mi;
    word_t len;

    mi.words[0] = w;

    len = seL4_MessageInfo_get_length(mi);
    if (len > seL4_MsgMaxLength) {
        mi = seL4_MessageInfo_set_length(mi, seL4_MsgMaxLength);
    }

    return mi;
}

static inline word_t __attribute__((__const__)) wordFromMessageInfo(seL4_MessageInfo_t mi)
{
    return mi.words[0];
}
# 104 "/host/kernel/include/api/types.h"
/*
 * thread name is only available if the kernel is built in debug mode.
 */
# 123 "/host/kernel/include/api/types.h"
/*
 * Print to serial a message helping userspace programmers to determine why the
 * kernel is not performing their requested operation.
 */
# 11 "/host/kernel/include/compound_types.h" 2
# 1 "/host/kernel/include/object/structures.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




# 1 "/host/untyped_build/kernel/generated_prune/arch/object/structures_gen.h" 1
# 13 "/host/kernel/include/object/structures.h" 2
# 1 "/host/kernel/include/arch/x86/arch/64/mode/types.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 14 "/host/kernel/include/object/structures.h" 2

# 1 "/host/kernel/libsel4/arch_include/x86/sel4/arch/constants.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       

/* Currently MSIs do not go through a vt-d translation by
 * the kernel, therefore when the user programs an MSI they
 * need to know how the 'vector' they allocated relates to
 * the actual vector table. In this case if they allocate
 * vector X they need to program their MSI to interrupt
 * vector X + IRQ_OFFSET */


/* When allocating vectors for IOAPIC or MSI interrupts,
 * this represent the valid range */



/* Legacy definitions */
# 16 "/host/kernel/include/object/structures.h" 2
# 1 "/host/kernel/libsel4/sel4_arch_include/x86_64/sel4/sel4_arch/constants.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       

# 1 "kernel/autoconf/autoconf.h" 1
# 10 "/host/kernel/libsel4/sel4_arch_include/x86_64/sel4/sel4_arch/constants.h" 2
# 20 "/host/kernel/libsel4/sel4_arch_include/x86_64/sel4/sel4_arch/constants.h"
/* for x86-64, the large page size is 2 MiB and huge page size is 1 GiB */
# 62 "/host/kernel/libsel4/sel4_arch_include/x86_64/sel4/sel4_arch/constants.h"
/* Untyped size limits */





typedef int __assert_failed_seL4_PageTableEntryBitsseL4_PageTableIndexBitsseL4_PageTableBits[(3 + 9 == 12) ? 1 : -1];;
typedef int __assert_failed_seL4_PageDirEntryBitsseL4_PageDirIndexBitsseL4_PageDirBits[(3 + 9 == 12) ? 1 : -1];;
typedef int __assert_failed_seL4_PDPTEntryBitsseL4_PDPTIndexBitsseL4_PDPTBits[(3 + 9 == 12) ? 1 : -1];;
typedef int __assert_failed_seL4_PML4EntryBitsseL4_PML4IndexBitsseL4_PML4Bits[(3 + 9 == 12) ? 1 : -1];;
typedef int __assert_failed_seL4_WordSizeBitsseL4_ASIDPoolIndexBitsseL4_ASIDPoolBits[(3 + 9 == 12) ? 1 : -1];;

typedef enum {
    seL4_VMFault_IP,
    seL4_VMFault_Addr,
    seL4_VMFault_PrefetchFault,
    seL4_VMFault_FSR,
    seL4_VMFault_Length,
    _enum_pad_seL4_VMFault_Msg = (1ULL << ((sizeof(long)*8) - 1)) - 1,
} seL4_VMFault_Msg;

typedef enum {
    seL4_UnknownSyscall_RAX,
    seL4_UnknownSyscall_RBX,
    seL4_UnknownSyscall_RCX,
    seL4_UnknownSyscall_RDX,
    seL4_UnknownSyscall_RSI,
    seL4_UnknownSyscall_RDI,
    seL4_UnknownSyscall_RBP,
    seL4_UnknownSyscall_R8,
    seL4_UnknownSyscall_R9,
    seL4_UnknownSyscall_R10,
    seL4_UnknownSyscall_R11,
    seL4_UnknownSyscall_R12,
    seL4_UnknownSyscall_R13,
    seL4_UnknownSyscall_R14,
    seL4_UnknownSyscall_R15,
    seL4_UnknownSyscall_FaultIP,
    seL4_UnknownSyscall_SP,
    seL4_UnknownSyscall_FLAGS,
    seL4_UnknownSyscall_Syscall,
    seL4_UnknownSyscall_Length,
    _enum_pad_seL4_UnknownSyscall_Msg = (1ULL << ((sizeof(long)*8) - 1)) - 1
} seL4_UnknownSyscall_Msg;

typedef enum {
    seL4_UserException_FaultIP,
    seL4_UserException_SP,
    seL4_UserException_FLAGS,
    seL4_UserException_Number,
    seL4_UserException_Code,
    seL4_UserException_Length,
    _enum_pad_seL4_UserException_Msg = (1ULL << ((sizeof(long)*8) - 1)) - 1
} seL4_UserException_Msg;
# 152 "/host/kernel/libsel4/sel4_arch_include/x86_64/sel4/sel4_arch/constants.h"
/* IPC buffer is 1024 bytes, giving size bits of 10 */


/* First address in the virtual address space that is not accessible to user level */
# 17 "/host/kernel/include/object/structures.h" 2
# 1 "/host/kernel/include/benchmark/benchmark_utilisation_.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 18 "/host/kernel/include/object/structures.h" 2

enum irq_state {
    IRQInactive = 0,
    IRQSignal = 1,
    IRQTimer = 2,



    IRQReserved
};
typedef word_t irq_state_t;

typedef struct dschedule {
    dom_t domain;
    word_t length;
} dschedule_t;

enum asidSizeConstants {
    asidHighBits = 3,
    asidLowBits = 9
};

/* Arch-independent object types */
enum endpoint_state {
    EPState_Idle = 0,
    EPState_Send = 1,
    EPState_Recv = 2
};
typedef word_t endpoint_state_t;

enum notification_state {
    NtfnState_Idle = 0,
    NtfnState_Waiting = 1,
    NtfnState_Active = 2
};
typedef word_t notification_state_t;
# 68 "/host/kernel/include/object/structures.h"
// We would like the actual 'tcb' region (the portion that contains the tcb_t) of the tcb
// to be as large as possible, but it still needs to be aligned. As the TCB object contains
// two sub objects the largest we can make either sub object whilst preserving size alignment
// is half the total size. To halve an object size defined in bits we just subtract 1
//
// A diagram of a TCB kernel object that is created from untyped:
//  _______________________________________
// |     |             |                   |
// |     |             |                   |
// |cte_t|   unused    |       tcb_t       |
// |     |(debug_tcb_t)|                   |
// |_____|_____________|___________________|
// 0     a             b                   c
// a = tcbCNodeEntries * sizeof(cte_t)
// b = BIT(TCB_SIZE_BITS)
// c = BIT(seL4_TCBBits)
//






/* Generate a tcb_t or cte_t pointer from a tcb block reference */




/* Generate a cte_t pointer from a tcb_t pointer */
# 112 "/host/kernel/include/object/structures.h"
static inline cap_t __attribute__((__const__)) Zombie_new(word_t number, word_t type, word_t ptr)
{
    word_t mask;

    if (type == (1ul << (6))) {
        mask = ((1ul << (4 + 1))-1ul);
    } else {
        mask = ((1ul << (type + 1))-1ul);
    }

    return cap_zombie_cap_new((ptr & ~mask) | (number & mask), type);
}

static inline word_t __attribute__((__const__)) cap_zombie_cap_get_capZombieBits(cap_t cap)
{
    word_t type = cap_zombie_cap_get_capZombieType(cap);
    if (type == (1ul << (6))) {
        return 4;
    }
    return ((type) & ((1ul << (6))-1ul)); /* cnode radix */
}

static inline word_t __attribute__((__const__)) cap_zombie_cap_get_capZombieNumber(cap_t cap)
{
    word_t radix = cap_zombie_cap_get_capZombieBits(cap);
    return cap_zombie_cap_get_capZombieID(cap) & ((1ul << (radix + 1))-1ul);
}

static inline word_t __attribute__((__const__)) cap_zombie_cap_get_capZombiePtr(cap_t cap)
{
    word_t radix = cap_zombie_cap_get_capZombieBits(cap);
    return cap_zombie_cap_get_capZombieID(cap) & ~((1ul << (radix + 1))-1ul);
}

static inline cap_t __attribute__((__const__)) cap_zombie_cap_set_capZombieNumber(cap_t cap, word_t n)
{
    word_t radix = cap_zombie_cap_get_capZombieBits(cap);
    word_t ptr = cap_zombie_cap_get_capZombieID(cap) & ~((1ul << (radix + 1))-1ul);
    return cap_zombie_cap_set_capZombieID(cap, ptr | (n & ((1ul << (radix + 1))-1ul)));
}

/* Capability table entry (CTE) */
struct cte {
    cap_t cap;
    mdb_node_t cteMDBNode;
};
typedef struct cte cte_t;



/* Thread state */
enum _thread_state {
    ThreadState_Inactive = 0,
    ThreadState_Running,
    ThreadState_Restart,
    ThreadState_BlockedOnReceive,
    ThreadState_BlockedOnSend,
    ThreadState_BlockedOnReply,
    ThreadState_BlockedOnNotification,



    ThreadState_IdleThreadState
};
typedef word_t _thread_state_t;

/* A TCB CNode and a TCB are always allocated together, and adjacently.
 * The CNode comes first. */
enum tcb_cnode_index {
    /* CSpace root */
    tcbCTable = 0,

    /* VSpace root */
    tcbVTable = 1,
# 197 "/host/kernel/include/object/structures.h"
    /* Reply cap slot */
    tcbReply = 2,

    /* TCB of most recent IPC sender */
    tcbCaller = 3,

    /* IPC buffer cap slot */
    tcbBuffer = 4,

    tcbCNodeEntries
};
typedef word_t tcb_cnode_index_t;

# 1 "/host/kernel/include/arch/x86/arch/object/structures.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       







# 1 "/host/untyped_build/kernel/generated_prune/arch/object/structures_gen.h" 1
# 16 "/host/kernel/include/arch/x86/arch/object/structures.h" 2
# 1 "/host/kernel/include/arch/x86/arch/machine/hardware.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




# 1 "/host/kernel/include/linker.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


# 1 "/host/kernel/include/arch/x86/arch/linker.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       



/* code that is linked to physical addresses */


/* data that is linked to physical addresses */


/* bss data that is linked to physical addresses */
# 11 "/host/kernel/include/linker.h" 2

/* code that is only used during kernel bootstrapping */


/* read-only data only used during kernel bootstrapping */


/* read/write data only used during kernel bootstrapping */


/* node-local bss data that is only used during kernel bootstrapping */


/* data will be aligned to n bytes in a special BSS section */


/* data that will be mapped into and permitted to be used in the restricted SKIM
 * address space */


/* bss data that is permitted to be used in the restricted SKIM address space */
# 13 "/host/kernel/include/arch/x86/arch/machine/hardware.h" 2







enum vm_fault_type {
    X86DataFault = 0,
    X86InstructionFault = 1
};

typedef word_t vm_fault_type_t;

enum vm_page_size {
    X86_SmallPage,
    X86_LargePage,
    X64_HugePage
};
typedef word_t vm_page_size_t;

enum frameSizeConstants {
    X64SmallPageBits = 12,
    X64LargePageBits = 21,
    X64HugePageBits = 30
};

enum vm_page_map_type {
    X86_MappingNone = 0,
    X86_MappingVSpace,






};
typedef word_t vm_page_map_type_t;

/* Any changes to this function need to be replicated in pageBitsForSize_phys.
 */
static inline word_t __attribute__((__const__)) pageBitsForSize(vm_page_size_t pagesize)
{
    switch (pagesize) {
    case X86_SmallPage:
        return 12;

    case X86_LargePage:
        return 21;

    case X64_HugePage:
        return 30;

    default:
        _fail("Invalid page size", "/host/kernel/include/arch/x86/arch/machine/hardware.h", 67, __func__);
    }
}

/* This function is a duplicate of pageBitsForSize, needed for calls that occur
 * before the MMU is turned on. Note that any changes to this function need to
 * be replicated in pageBitsForSize.
 */
__attribute__((__section__(".phys.text")))
static inline word_t __attribute__((__const__)) pageBitsForSize_phys(vm_page_size_t pagesize)
{
    switch (pagesize) {
    case X86_SmallPage:
        return 12;

    case X86_LargePage:
        return 21;

    case X64_HugePage:
        return 30;

    default:
        _fail("Invalid page size", "/host/kernel/include/arch/x86/arch/machine/hardware.h", 89, __func__);
    }
}

/* Returns the size of CPU's cacheline */
uint32_t __attribute__((__const__)) getCacheLineSize(void);
uint32_t __attribute__((__const__)) getCacheLineSizeBits(void);

/* Flushes a specific memory range from the CPU cache */
static inline void flushCacheLine(volatile void *vaddr)
{
    __asm__ volatile("clflush %[vaddr]" : [vaddr] "+m"(*((volatile char *)vaddr)));
}

void flushCacheRange(void *vaddr, uint32_t size_bits);

/* Disables a variety of prefetchers */
bool_t disablePrefetchers(void);

/* Enable user level access to the performance counters */
__attribute__((__section__(".boot.text"))) void enablePMCUser(void);

/* Flushes entire CPU Cache */
static inline void x86_wbinvd(void)
{
    __asm__ volatile("wbinvd" ::: "memory");
}

static inline void arch_clean_invalidate_caches(void)
{
    x86_wbinvd();
}

/* Initialize Indirect Branch Restricted Speculation into the mode specified by the build configuration */
bool_t init_ibrs(void);
# 17 "/host/kernel/include/arch/x86/arch/object/structures.h" 2
# 1 "/host/kernel/include/arch/x86/arch/machine/registerset.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       






# 1 "/host/kernel/include/arch/x86/arch/64/mode/machine/registerset.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

/* These are the indices of the registers in the
 * saved thread context. The values are determined
 * by the order in which they're saved in the trap
 * handler.
 *
 * BEWARE:
 * You will have to adapt traps.S extensively if
 * you change anything in this enum!
 */

/* This register layout is optimized for usage with
 * the syscall and sysret instructions. Interrupts
 * and sysenter have to do some juggling to make
 * things work */
enum _register {
    // User registers that will be preserved during syscall
    // Deliberately place the cap and badge registers early
    // So that when popping on the fastpath we can just not
    // pop these
    RDI = 0, /* 0x00 */
    capRegister = 0,
    badgeRegister = 0,
    RSI = 1, /* 0x08 */
    msgInfoRegister = 1,
    RAX = 2, /* 0x10 */
    RBX = 3, /* 0x18 */
    RBP = 4, /* 0x20 */
    R12 = 5, /* 0x28 */



    R13 = 6, /* 0x30 */



    R14 = 7, /* 0x38 */
    RDX = 8, /* 0x40 */
    // Group the message registers so they can be efficiently copied
    R10 = 9, /* 0x48 */
    R8 = 10, /* 0x50 */
    R9 = 11, /* 0x58 */
    R15 = 12, /* 0x60 */
    FLAGS = 13, /* 0x68 */
    // Put the NextIP, which is a virtual register, here as we
    // need to set this in the syscall path
    NextIP = 14, /* 0x70 */
    // Same for the error code
    Error = 15, /* 0x78 */
    /* Kernel stack points here on kernel entry */
    RSP = 16, /* 0x80 */
    FaultIP = 17, /* 0x88 */
    // Now user Registers that get clobbered by syscall
    R11 = 18, /* 0x90 */
    RCX = 19, /* 0x98 */
    CS = 20, /* 0xa0 */
    SS = 21, /* 0xa8 */
    n_immContextRegisters = 22, /* 0xb0 */

    // For locality put these here as well
    FS_BASE = 22, /* 0xb0 */
    TLS_BASE = FS_BASE,
    GS_BASE = 23, /* 0xb8 */

    n_contextRegisters = 24 /* 0xc0 */
};

typedef uint32_t register_t;

enum messageSizes {
    n_msgRegisters = 4,
    n_frameRegisters = 18,
    n_gpRegisters = 2,
    n_exceptionMessage = 3,
    n_syscallMessage = 18,



};
# 140 "/host/kernel/include/arch/x86/arch/64/mode/machine/registerset.h"
extern const register_t msgRegisters[];
extern const register_t frameRegisters[];
extern const register_t gpRegisters[];
# 15 "/host/kernel/include/arch/x86/arch/machine/registerset.h" 2

/* Minimum hardware-enforced alignment needed for FPU state. */
# 56 "/host/kernel/include/arch/x86/arch/machine/registerset.h"
/* X86 FPU context. */
struct user_fpu_state {
    uint8_t state[512];
};
typedef struct user_fpu_state user_fpu_state_t;

/* X86 user-code context */
struct user_context {
    user_fpu_state_t fpuState;
    word_t registers[n_contextRegisters];







};
typedef struct user_context user_context_t;

void Mode_initContext(user_context_t *context);
void Arch_initContext(user_context_t *context);
word_t Mode_sanitiseRegister(register_t reg, word_t v);

/* Ensure FPU state is aligned within user context. */
typedef int __assert_failed_fpu_state_alignment_valid[(__builtin_offsetof(user_context_t, fpuState) % 64 == 0) ? 1 : -1];
# 18 "/host/kernel/include/arch/x86/arch/object/structures.h" 2


enum tcb_arch_cnode_index {





    tcbArchCNodeEntries = tcbCNodeEntries

};

typedef struct arch_tcb {
    user_context_t tcbContext;





} arch_tcb_t;
# 61 "/host/kernel/include/arch/x86/arch/object/structures.h"
typedef int __assert_failed_vtd_pt_size_sane[(9 + 3 == 12) ? 1 : -1];
# 120 "/host/kernel/include/arch/x86/arch/object/structures.h"
struct rdmsr_safe_result {
    uint64_t value;
    bool_t success;
};

typedef struct rdmsr_safe_result rdmsr_safe_result_t;

/* helper structure for filling descriptor registers */
typedef struct gdt_idt_ptr {
    uint16_t limit;
    word_t base;
} __attribute__((packed)) gdt_idt_ptr_t;

enum vm_rights {
    VMKernelOnly = 1,
    VMReadOnly = 2,
    VMReadWrite = 3
};
typedef word_t vm_rights_t;

# 1 "/host/kernel/include/arch/x86/arch/64/mode/object/structures.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


/* x86-64 specific object types */
/* sysexitq (64-bit) user code = cs + 32, user data = cs + 40.
 * sysexit user code = cs + 16, user data = cs + 24, so we need to arrange
 * user CS and DS as 5 and 6.
 * */
# 25 "/host/kernel/include/arch/x86/arch/64/mode/object/structures.h"
typedef int __assert_failed_gdt_idt_ptr_packed[(sizeof(gdt_idt_ptr_t) == sizeof(uint16_t) * 5) ? 1 : -1];


typedef int __assert_failed_unsigned_long_size_64[(sizeof(unsigned long) == 8) ? 1 : -1];


typedef int __assert_failed_unsinged_int_size_32[(sizeof(unsigned int) == 4) ? 1 : -1];


typedef int __assert_failed_uint64_t_size_64[(sizeof(uint64_t) == 8) ? 1 : -1];
# 59 "/host/kernel/include/arch/x86/arch/64/mode/object/structures.h"
typedef pml4e_t vspace_root_t;
# 94 "/host/kernel/include/arch/x86/arch/64/mode/object/structures.h"
/* there are 1^12 hardware PCID; now we match the software ASID
 * to the available PCID. Since each ASID pool is 4K in size,
 * it contains 512 vroots.
 */

struct asid_pool {
    asid_map_t array[(1ul << (asidLowBits))];
};

typedef struct asid_pool asid_pool_t;
# 114 "/host/kernel/include/arch/x86/arch/64/mode/object/structures.h"
static inline asid_t __attribute__((__pure__)) cap_get_capMappedASID(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {

    case cap_pml4_cap:
        return cap_pml4_cap_get_capPML4MappedASID(cap);

    case cap_pdpt_cap:
        return cap_pdpt_cap_get_capPDPTMappedASID(cap);

    case cap_page_directory_cap:
        return cap_page_directory_cap_get_capPDMappedASID(cap);






    default:
        _fail("Invalid arch cap type", "/host/kernel/include/arch/x86/arch/64/mode/object/structures.h", 137, __func__);
    }
}

static inline word_t __attribute__((__const__)) cap_get_modeCapSizeBits(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {
    case cap_pml4_cap:
        return 12;

    case cap_pdpt_cap:
        return 12;

    default:
        return 0;
    }
}

static inline bool_t __attribute__((__const__)) cap_get_modeCapIsPhysical(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {

    case cap_pml4_cap:
        return true;

    case cap_pdpt_cap:
        return true;

    default:
        return false;
    }
}

static inline void *__attribute__((__const__)) cap_get_modeCapPtr(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {
    case cap_pml4_cap:
        return ((pml4e_t *)(cap_pml4_cap_get_capPML4BasePtr(cap)));

    case cap_pdpt_cap:
        return ((pdpte_t *)(cap_pdpt_cap_get_capPDPTBasePtr(cap)));

    default:
        return ((void *)0);
    }
}
# 141 "/host/kernel/include/arch/x86/arch/object/structures.h" 2

static inline word_t __attribute__((__const__)) cap_get_archCapSizeBits(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {
    case cap_frame_cap:
        return pageBitsForSize(cap_frame_cap_get_capFSize(cap));

    case cap_page_table_cap:
        return 12;

    case cap_page_directory_cap:
        return 12;

    case cap_io_port_cap:
        return 0;
# 168 "/host/kernel/include/arch/x86/arch/object/structures.h"
    case cap_asid_control_cap:
        return 0;

    case cap_asid_pool_cap:
        return 12;
# 188 "/host/kernel/include/arch/x86/arch/object/structures.h"
    default:
        return cap_get_modeCapSizeBits(cap);
    }
}

static inline bool_t __attribute__((__const__)) cap_get_archCapIsPhysical(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {

    case cap_frame_cap:
        return true;

    case cap_page_table_cap:
        return true;

    case cap_page_directory_cap:
        return true;

    case cap_io_port_cap:
        return false;
# 221 "/host/kernel/include/arch/x86/arch/object/structures.h"
    case cap_asid_control_cap:
        return false;

    case cap_asid_pool_cap:
        return true;
# 241 "/host/kernel/include/arch/x86/arch/object/structures.h"
    default:
        return cap_get_modeCapIsPhysical(cap);
    }
}

static inline void *__attribute__((__const__)) cap_get_archCapPtr(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {

    case cap_frame_cap:
        return (void *)(cap_frame_cap_get_capFBasePtr(cap));

    case cap_page_table_cap:
        return ((pte_t *)(cap_page_table_cap_get_capPTBasePtr(cap)));

    case cap_page_directory_cap:
        return ((pde_t *)(cap_page_directory_cap_get_capPDBasePtr(cap)));

    case cap_io_port_cap:
        return ((void *)0);
# 274 "/host/kernel/include/arch/x86/arch/object/structures.h"
    case cap_asid_control_cap:
        return ((void *)0);

    case cap_asid_pool_cap:
        return ((asid_pool_t*)cap_asid_pool_cap_get_capASIDPool(cap));
# 294 "/host/kernel/include/arch/x86/arch/object/structures.h"
    default:
        return cap_get_modeCapPtr(cap);
    }
}

static inline bool_t __attribute__((__const__)) Arch_isCapRevocable(cap_t derivedCap, cap_t srcCap)
{
    switch (cap_get_capType(derivedCap)) {
    case cap_io_port_cap:
        return cap_get_capType(srcCap) == cap_io_port_control_cap;

    default:
        return false;
    }
}
# 211 "/host/kernel/include/object/structures.h" 2

struct user_data {
    word_t words[(1ul << (12)) / sizeof(word_t)];
};
typedef struct user_data user_data_t;

struct user_data_device {
    word_t words[(1ul << (12)) / sizeof(word_t)];
};
typedef struct user_data_device user_data_device_t;

static inline word_t __attribute__((__const__)) wordFromVMRights(vm_rights_t vm_rights)
{
    return (word_t)vm_rights;
}

static inline vm_rights_t __attribute__((__const__)) vmRightsFromWord(word_t w)
{
    return (vm_rights_t)w;
}

static inline vm_attributes_t __attribute__((__const__)) vmAttributesFromWord(word_t w)
{
    vm_attributes_t attr;

    attr.words[0] = w;
    return attr;
}






/* TCB: size >= 18 words + sizeof(arch_tcb_t) + 1 word on MCS (aligned to nearest power of 2) */
struct tcb {
    /* arch specific tcb state (including context)*/
    arch_tcb_t tcbArch;

    /* Thread state, 3 words */
    thread_state_t tcbState;

    /* Notification that this TCB is bound to. If this is set, when this TCB waits on
     * any sync endpoint, it may receive a signal from a Notification object.
     * 1 word*/
    notification_t *tcbBoundNotification;

    /* Current fault, 2 words */
    seL4_Fault_t tcbFault;

    /* Current lookup failure, 2 words */
    lookup_fault_t tcbLookupFailure;

    /* Domain, 1 byte (padded to 1 word) */
    dom_t tcbDomain;

    /*  maximum controlled priority, 1 byte (padded to 1 word) */
    prio_t tcbMCP;

    /* Priority, 1 byte (padded to 1 word) */
    prio_t tcbPriority;
# 281 "/host/kernel/include/object/structures.h"
    /* Timeslice remaining, 1 word */
    word_t tcbTimeSlice;

    /* Capability pointer to thread fault handler, 1 word */
    cptr_t tcbFaultHandler;


    /* userland virtual address of thread IPC buffer, 1 word */
    word_t tcbIPCBuffer;






    /* Previous and next pointers for scheduler queues , 2 words */
    struct tcb *tcbSchedNext;
    struct tcb *tcbSchedPrev;
    /* Preivous and next pointers for endpoint and notification queues, 2 words */
    struct tcb *tcbEPNext;
    struct tcb *tcbEPPrev;
# 311 "/host/kernel/include/object/structures.h"
};
typedef struct tcb tcb_t;


/* This debug_tcb object is inserted into the 'unused' region of a TCB object
   for debug build configurations. */
struct debug_tcb {

    /* Pointers for list of all tcbs that is maintained
     * when CONFIG_DEBUG_BUILD is enabled, 2 words */
    struct tcb *tcbDebugNext;
    struct tcb *tcbDebugPrev;
    /* Use any remaining space for a thread name */
    char tcbName[];

};
typedef struct debug_tcb debug_tcb_t;
# 399 "/host/kernel/include/object/structures.h"
/* Ensure object sizes are sane */
typedef int __assert_failed_cte_size_sane[(sizeof(cte_t) <= (1ul << (5))) ? 1 : -1];
typedef int __assert_failed_tcb_cte_size_sane[((4 + 5) <= (11 - 1)) ? 1 : -1];
typedef int __assert_failed_tcb_size_sane[((1ul << ((11 - 1))) >= sizeof(tcb_t)) ? 1 : -1];

typedef int __assert_failed_tcb_size_not_excessive[((1ul << ((11 - 1) - 1)) < sizeof(tcb_t)) ? 1 : -1];

typedef int __assert_failed_ep_size_sane[(sizeof(endpoint_t) <= (1ul << (4))) ? 1 : -1];
typedef int __assert_failed_notification_size_sane[(sizeof(notification_t) <= (1ul << (5))) ? 1 : -1];

/* Check the IPC buffer is the right size */
typedef int __assert_failed_ipc_buf_size_sane[(sizeof(seL4_IPCBuffer) == (1ul << (10))) ? 1 : -1];







/* helper functions */

static inline word_t __attribute__((__const__))
isArchCap(cap_t cap)
{
    return (cap_get_capType(cap) % 2);
}

static inline word_t __attribute__((__const__)) cap_get_capSizeBits(cap_t cap)
{

    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {
    case cap_untyped_cap:
        return cap_untyped_cap_get_capBlockSize(cap);

    case cap_endpoint_cap:
        return 4;

    case cap_notification_cap:
        return 5;

    case cap_cnode_cap:
        return cap_cnode_cap_get_capCNodeRadix(cap) + 5;

    case cap_thread_cap:
        return 11;

    case cap_zombie_cap: {
        word_t type = cap_zombie_cap_get_capZombieType(cap);
        if (type == (1ul << (6))) {
            return 11;
        }
        return ((type) & ((1ul << (6))-1ul)) + 5;
    }

    case cap_null_cap:
        return 0;

    case cap_domain_cap:
        return 0;

    case cap_reply_cap:



        return 0;


    case cap_irq_control_cap:



        return 0;

    case cap_irq_handler_cap:
        return 0;






    default:
        return cap_get_archCapSizeBits(cap);
    }

}

/* Returns whether or not this capability has memory associated
 * with it or not. Referring to this as 'being physical' is to
 * match up with the Haskell and abstract specifications */
static inline bool_t __attribute__((__const__)) cap_get_capIsPhysical(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {
    case cap_untyped_cap:
        return true;

    case cap_endpoint_cap:
        return true;

    case cap_notification_cap:
        return true;

    case cap_cnode_cap:
        return true;

    case cap_thread_cap:



        return true;

    case cap_zombie_cap:
        return true;

    case cap_domain_cap:
        return false;

    case cap_reply_cap:



        return false;


    case cap_irq_control_cap:



        return false;

    case cap_irq_handler_cap:
        return false;

    default:
        return cap_get_archCapIsPhysical(cap);
    }
}

static inline void *__attribute__((__const__)) cap_get_capPtr(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {
    case cap_untyped_cap:
        return ((word_t *)(cap_untyped_cap_get_capPtr(cap)));

    case cap_endpoint_cap:
        return ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(cap)));

    case cap_notification_cap:
        return ((notification_t *)(cap_notification_cap_get_capNtfnPtr(cap)));

    case cap_cnode_cap:
        return ((cte_t *)(cap_cnode_cap_get_capCNodePtr(cap)));

    case cap_thread_cap:
        return (((cte_t *)((word_t)(cap_thread_cap_get_capTCBPtr(cap))&~((1ul << (11))-1ul)))+(0));

    case cap_zombie_cap:
        return ((cte_t *)(cap_zombie_cap_get_capZombiePtr(cap)));

    case cap_domain_cap:
        return ((void *)0);

    case cap_reply_cap:



        return ((void *)0);


    case cap_irq_control_cap:



        return ((void *)0);

    case cap_irq_handler_cap:
        return ((void *)0);






    default:
        return cap_get_archCapPtr(cap);

    }
}

static inline bool_t __attribute__((__const__)) isCapRevocable(cap_t derivedCap, cap_t srcCap)
{
    if (isArchCap(derivedCap)) {
        return Arch_isCapRevocable(derivedCap, srcCap);
    }
    switch (cap_get_capType(derivedCap)) {
    case cap_endpoint_cap:
        return (cap_endpoint_cap_get_capEPBadge(derivedCap) !=
                cap_endpoint_cap_get_capEPBadge(srcCap));

    case cap_notification_cap:
        return (cap_notification_cap_get_capNtfnBadge(derivedCap) !=
                cap_notification_cap_get_capNtfnBadge(srcCap));

    case cap_irq_handler_cap:
        return (cap_get_capType(srcCap) ==
                cap_irq_control_cap);

    case cap_untyped_cap:
        return true;

    default:
        return false;
    }
}
# 12 "/host/kernel/include/compound_types.h" 2


struct pde_range {
    pde_t *base;
    word_t length;
};
typedef struct pde_range pde_range_t;

struct pte_range {
    pte_t *base;
    word_t length;
};
typedef struct pte_range pte_range_t;

typedef cte_t *cte_ptr_t;

struct extra_caps {
    cte_ptr_t excaprefs[((1ul<<(seL4_MsgExtraCapBits))-1)];
};
typedef struct extra_caps extra_caps_t;
# 11 "/host/kernel/include/types.h" 2
# 9 "/host/kernel/src/api/faults.c" 2
# 1 "/host/kernel/include/api/faults.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




word_t setMRs_fault(tcb_t *sender, tcb_t *receiver, word_t *receiveIPCBuffer);
word_t Arch_setMRs_fault(tcb_t *sender, tcb_t *receiver, word_t *receiveIPCBuffer, word_t faultType);

bool_t handleFaultReply(tcb_t *receiver, tcb_t *sender);
bool_t Arch_handleFaultReply(tcb_t *receiver, tcb_t *sender, word_t faultType);
# 10 "/host/kernel/src/api/faults.c" 2
# 1 "/host/kernel/include/api/syscall.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


# 1 "/host/kernel/include/machine.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

# 1 "/host/kernel/include/plat/pc99/plat/machine.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

# 1 "/host/kernel/include/machine/interrupt.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       





/**
 * irq_t is an identifier that represents a hardware interrupt.
 * irq handler capabilities refer to an irq_t which is then used by the
 * kernel to track irq state. An irq_t is also used to interface with an
 * interrupt controller driver using the functions below.
 * For most configurations an irq_t is a word_t type and the irq_t values
 * directly map to harware irq numbers and are also used as indexes into the
 * kernel's irq cnode that it uses for tracking state.
 * However on SMP configurations where there can be multiple irq_t identifiers
 * for a single hardware irq number, such as when there are core local interrupts,
 * irq_t cannot be assumed to be only a hardware irq number.
 * In this case, irq_t can be defined as a struct containing additional information.
 *
 * Macros are provided to hide this structural difference across configurations:
 * CORE_IRQ_TO_IRQT: converts from a core id and hw irq number to an irq_t
 * IRQT_TO_IDX: converts an irq_t to an index in the irq cnode. It is also used
 *   to encode the irq_t as a single word_t type for sending over IPIs.
 * IDX_TO_IRQT: converts an index in the irq cnode to an irq_t
 * IRQT_TO_CORE: extracts the core out of an irq_t
 * IRQT_TO_IRQL extracts a hw irq out of an irq_t.
 *
 * It is expected that interrupt controller drivers that support SMP provide
 * implementations of these Macros.
 * Currently only Arm SMP configurations use this scheme.
 */






typedef word_t irq_t;







/**
 * Return a currently pending IRQ.
 *
 * This function can be called multiple times and needs to return the same IRQ
 * until ackInterrupt is called. getActiveIRQ returns irqInvalid if no interrupt
 * is pending. It is assumed that if isIRQPending is true, then getActiveIRQ
 * will not return irqInvalid. irqInvalid is a per platform constant that cannot
 * correspond to an actual IRQ raised by the platform.
 *
 * @return     The active IRQ. irqInvalid if no IRQ is pending.
 */
static inline irq_t getActiveIRQ(void);

/**
 * Checks if an IRQ is currently pending in the hardware.
 *
 * isIRQPending is used to determine whether to preempt long running operations
 * at various preemption points throughout the kernel. If this returns true, it
 * means that if the Kernel were to return to user mode, it would then
 * immediately take an interrupt.
 *
 * @return     True if irq pending, False otherwise.
 */
static inline bool_t isIRQPending(void);

/**
 * maskInterrupt disables and enables IRQs.
 *
 * When an IRQ is disabled, it should not raise an interrupt on the processor.
 *
 * @param[in]  disable  True to disable IRQ, False to enable IRQ
 * @param[in]  irq      The irq to modify
 */
static inline void maskInterrupt(bool_t disable, irq_t irq);

/**
 * Acks the interrupt
 *
 * ackInterrupt is used by the kernel to indicate it has processed the interrupt
 * delivery and getActiveIRQ is now able to return a different IRQ number. Note
 * that this is called after a notification has been signalled to user level,
 * but before user level has handled the cause and does not imply that the cause
 * of the interrupt has been handled.
 *
 * @param[in]  irq   irq to ack
 */
static inline void ackInterrupt(irq_t irq);

/**
 * Called when getActiveIRQ returns irqInvalid while the kernel is handling an
 * interrupt entry. An implementation is not required to do anything here, but
 * can report the spurious IRQ or try prevent it from reoccuring.
 */
static inline void handleSpuriousIRQ(void);

/**
 * Handle a platform-reserved IRQ.
 *
 * Platform specific implementation for handling IRQs for interrupts that are
 * reserved and not made available to user-level. Will be called if getActiveIRQ
 * returns an IRQ number that is reserved. After this function returns,
 * ackInterrupt will likely be immediately called after.
 *
 * @param[in]  irq   The irq
 */
static inline void handleReservedIRQ(irq_t irq);
# 10 "/host/kernel/include/plat/pc99/plat/machine.h" 2




/* interrupt vectors (corresponds to IDT entries) */




typedef enum _interrupt_t {
    int_invalid = -1,
    int_debug = 1,
    int_software_break_request = 3,
    int_unimpl_dev = 7,
    int_gp_fault = 13,
    int_page_fault = 14,
    int_irq_min = 0x20, /* First IRQ. */
    int_irq_isa_min = 0x20, /* Beginning of PIC IRQs */
    int_irq_isa_max = 0x20 + 16 - 1, /* End of PIC IRQs */
    int_irq_user_min = 0x20 + 16, /* First user available vector */
    int_irq_user_max = 155,



    int_timer = 157,





    int_irq_max = 157, /* int_timer is the max irq */

    int_trap_min,
    int_trap_max = 254,
    int_spurious = 255,
    int_max = 255
} interrupt_t;

typedef enum _platform_irq_t {
    irq_isa_min = int_irq_isa_min - 0x20,
    irq_isa_max = int_irq_isa_max - 0x20,
    irq_user_min = int_irq_user_min - 0x20,
    irq_user_max = int_irq_user_max - 0x20,



    irq_timer = int_timer - 0x20,




    maxIRQ = int_irq_max - 0x20,
    /* This is explicitly 255, instead of -1 like on some other platforms, to ensure
     * that comparisons between an irq_t (a uint8_t) and irqInvalid (some kind of signed int)
     * are well defined and behave as expected */
    irqInvalid = 255,
} platform_irq_t;






/* The text mode framebuffer exists part way into the video ram region */
# 10 "/host/kernel/include/machine.h" 2
# 1 "/host/kernel/include/machine/registerset.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       






typedef enum {
    MessageID_Syscall,
    MessageID_Exception,



} MessageID_t;






extern const register_t fault_messages[][(((n_syscallMessage)>(n_exceptionMessage))?(n_syscallMessage):(n_exceptionMessage))] __attribute__((externally_visible));

static inline void setRegister(tcb_t *thread, register_t reg, word_t w)
{
    thread->tcbArch.tcbContext.registers[reg] = w;
}

static inline word_t __attribute__((__pure__)) getRegister(tcb_t *thread, register_t reg)
{
    return thread->tcbArch.tcbContext.registers[reg];
}
# 11 "/host/kernel/include/machine.h" 2
# 1 "/host/kernel/include/hardware.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
       

/* Each architecture defines a set of constants in #defines. These
 * constants describe the memory regions of the kernel's portion of the
 * address space including the physical memory window, the kernel ELF
 * region, and the device region.
 *
 *  - USER_TOP: The first address after the end of user memory
 *
 *  - PADDR_BASE: The first physical address mapped in the kernel's
 *    physical memory window.
 *  - PPTR_BASE: The first virtual address of the kernel's physical
 *    memory window.
 *  - PPTR_TOP: The first virtual address after the end of the kernel's
 *    physical memory window.
 *
 *  - KERNEL_ELF_PADDR_BASE: The first physical address used to map the
 *    initial kernel image. The kernel ELF is mapped contiguously
 *    starting at this address.
 *  - KERNEL_ELF_BASE: The first virtual address used to map the initial
 *    kernel image.
 *
 *  - KDEV_BASE: The first virtual address used to map devices.
 */

/* The offset from a physical address to a virtual address in the
 * physical memory window. */


/* The last address in the physical memory region mapped into the
 * physical memory window */


/* The kernel base offset is a way to translate the kernel image segment
 * from virtual to physical. This translation must be a single offset
 * for for the entire segment (i.e. the kernel image must be contiguous
 * both virtually and physically) */




/* This symbol is generated by the linker and marks the last valid
 * address in the kernel's virtual region */
extern char ki_end[];





# 1 "/host/kernel/include/arch/x86/arch/64/mode/hardware.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


# 1 "/host/kernel/include/plat/pc99/plat/64/plat_mode/machine/hardware.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       



/*
 *          2^64 +-------------------+
 *               | Kernel Page PDPT  | --+
 *   2^64 - 2^39 +-------------------+ PPTR_BASE
 *               |    TLB Bitmaps    |   |
 *               +-------------------+   |
 *               |                   |   |
 *               |     Unmapped      |   |
 *               |                   |   |
 *   2^64 - 2^47 +-------------------+   |
 *               |                   |   |
 *               |   Unaddressable   |   |
 *               |                   |   |
 *          2^47 +-------------------+ USER_TOP
 *               |                   |   |
 *               |       User        |   |
 *               |                   |   |
 *           0x0 +-------------------+   |
 *                                       |
 *                         +-------------+
 *                         |
 *                         v
 *          2^64 +-------------------+
 *               |                   |
 *               |                   |     +------+     +------+
 *               |  Kernel Devices   | --> |  PD  | --> |  PT  |
 *               |                   |     +------+     +------+
 *               |                   |
 *   2^64 - 2^30 +-------------------+ KDEV_BASE
 *               |                   |
 *               |                   |     +------+
 *               |    Kernel ELF     | --> |  PD  |
 *               |                   |     +------+
 *               |                   |
 *   2^64 - 2^29 +-------------------+ PPTR_TOP / KERNEL_ELF_BASE
 *               |                   |
 *               |  Physical Memory  |
 *               |       Window      |
 *               |                   |
 *   2^64 - 2^39 +-------------------+ PPTR_BASE
 */

/* WARNING: some of these constants are also defined in linker.lds
 * These constants are written out in full instead of using bit arithmetic
 * because they need to defined like this in linker.lds
 */

/* Define USER_TOP to be 1 before the last address before sign extension occurs.
 * This ensures that
 *  1. user addresses never needed to be sign extended to be valid canonical addresses
 *  2. the user cannot map the last page before addresses need sign extension. This prevents
 *     the user doing a syscall as the very last instruction and the CPU calculated PC + 2
 *     from being an invalid (non sign extended) address
 */


/* The first physical address to map into the kernel's physical memory
 * window */


/* The base address in virtual memory to use for the 1:1 physical memory
 * mapping. Our kernel window is 2^39 bits (2^9 * 1gb) and the virtual
 * address range is 48 bits. Therefore our base is 2^48 - 2^39 */


/* Below the main kernel window we have any slots for the TLB bitmap */



/* The kernel binary itself is placed in the bottom 1gb of the top
 * 2gb of virtual address space. This is so we can use the 'kernel'
 * memory model of GCC, which requires all symbols to be linked
 * within the top 2GiB of memory. This is (2^48 - 2 ^ 31) */


/* The physical memory address to use for mapping the kernel ELF */


/* Kernel mapping starts directly after the physical memory window */


/* Put the kernel devices at the very beginning of the top
 * 1GB. This means they are precisely after the kernel binary
 * region. This is 2^48 - 2^30 */







# 1 "/host/untyped_build/kernel/generated_prune/plat_mode/machine/hardware_gen.h" 1
# 103 "/host/kernel/include/plat/pc99/plat/64/plat_mode/machine/hardware.h" 2
# 1 "/host/kernel/include/arch/x86/arch/kernel/tlb_bitmap_defs.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 104 "/host/kernel/include/plat/pc99/plat/64/plat_mode/machine/hardware.h" 2

/* ensure the user top and tlb bitmap do not overlap if multicore */




/* since we have two kernel VM windows, we have two pptr to paddr
 * conversion functions.
 * paddr_to_kpptr converts physical address to the second small kernel
 * window which locates at the top 2GiB.
 */
static inline void *__attribute__((__const__))
paddr_to_kpptr(paddr_t paddr)
{
    if(!(paddr < (((paddr_t)(&ki_end)) - ((0xffffffff80000000ul + 0x00100000ul) - 0x00100000ul)))) _assert_fail("paddr < KERNEL_ELF_PADDR_TOP", "/host/kernel/include/plat/pc99/plat/64/plat_mode/machine/hardware.h", 118, __FUNCTION__);
    return (void *)(paddr + ((0xffffffff80000000ul + 0x00100000ul) - 0x00100000ul));
}

static inline paddr_t __attribute__((__const__)) kpptr_to_paddr(void *pptr)
{
    if(!((word_t)pptr >= (0xffffffff80000000ul + 0x00100000ul))) _assert_fail("(word_t)pptr >= KERNEL_ELF_BASE", "/host/kernel/include/plat/pc99/plat/64/plat_mode/machine/hardware.h", 124, __FUNCTION__);
    return (paddr_t)pptr - ((0xffffffff80000000ul + 0x00100000ul) - 0x00100000ul);
}
# 11 "/host/kernel/include/arch/x86/arch/64/mode/hardware.h" 2
# 55 "/host/kernel/include/hardware.h" 2
# 12 "/host/kernel/include/machine.h" 2

/* When translating a physical address into an address accessible to the
 * kernel via virtual addressing we always use the mapping of the memory
 * into the physical memory window, even if the mapping originally
 * referred to a kernel virtual address. */
static inline void *__attribute__((__const__)) ptrFromPAddr(paddr_t paddr)
{
    return (void *)(paddr + (0xffffff8000000000ul - 0x00000000ul));
}

/* When obtaining a physical address from a reference to any object in
 * the physical mapping window, this function must be used. */
static inline paddr_t __attribute__((__const__)) addrFromPPtr(void *pptr)
{
    return (paddr_t)pptr - (0xffffff8000000000ul - 0x00000000ul);
}

static inline region_t __attribute__((__const__)) paddr_to_pptr_reg(p_region_t p_reg)
{
    return (region_t) {
        p_reg.start + (0xffffff8000000000ul - 0x00000000ul), p_reg.end + (0xffffff8000000000ul - 0x00000000ul)
    };
}

static inline p_region_t __attribute__((__const__)) pptr_to_paddr_reg(region_t reg)
{
    return (p_region_t) {
        reg.start - (0xffffff8000000000ul - 0x00000000ul), reg.end - (0xffffff8000000000ul - 0x00000000ul)
    };
}




# 1 "/host/kernel/include/arch/x86/arch/64/mode/machine.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       



# 1 "/host/kernel/include/arch/x86/arch/model/statedata.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       






# 1 "/host/kernel/include/plat/pc99/plat/machine/devices.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 15 "/host/kernel/include/arch/x86/arch/model/statedata.h" 2
# 1 "/host/kernel/include/arch/x86/arch/object/vcpu.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


# 1 "/host/kernel/include/api/failures.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


# 1 "/host/kernel/libsel4/include/sel4/errors.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       

typedef enum {
    seL4_NoError = 0,
    seL4_InvalidArgument,
    seL4_InvalidCapability,
    seL4_IllegalOperation,
    seL4_RangeError,
    seL4_AlignmentError,
    seL4_FailedLookup,
    seL4_TruncatedMessage,
    seL4_DeleteFirst,
    seL4_RevokeFirst,
    seL4_NotEnoughMemory,

    /* This should always be the last item in the list
     * so it gives a count of the number of errors in the
     * enum.
     */
    seL4_NumErrors
} seL4_Error;
# 11 "/host/kernel/include/api/failures.h" 2

/* These datatypes differ markedly from haskell, due to the
 * different implementation of the various fault monads */


enum exception {
    EXCEPTION_NONE,
    EXCEPTION_FAULT,
    EXCEPTION_LOOKUP_FAULT,
    EXCEPTION_SYSCALL_ERROR,
    EXCEPTION_PREEMPTED
};
typedef word_t exception_t;

typedef word_t syscall_error_type_t;

struct syscall_error {
    word_t invalidArgumentNumber;
    word_t invalidCapNumber;
    word_t rangeErrorMin;
    word_t rangeErrorMax;
    word_t memoryLeft;
    bool_t failedLookupWasSource;

    syscall_error_type_t type;
};
typedef struct syscall_error syscall_error_t;
# 47 "/host/kernel/include/api/failures.h"
extern lookup_fault_t current_lookup_fault;
extern seL4_Fault_t current_fault;
extern syscall_error_t current_syscall_error;
# 11 "/host/kernel/include/arch/x86/arch/object/vcpu.h" 2
# 167 "/host/kernel/include/arch/x86/arch/object/vcpu.h"
/* Exit reasons. */
enum exit_reasons {
    EXCEPTION_OR_NMI = 0x00,
    EXTERNAL_INTERRUPT = 0x01,
    TRIPLE_FAULT = 0x02,
    INIT_SIGNAL = 0x03,
    SIPI = 0x04,
    /*IO_SMI = 0x05,
     *   OTHER_SMI = 0x06,*/
    INTERRUPT_WINDOW = 0x07,
    NMI_WINDOW = 0x08,
    TASK_SWITCH = 0x09,
    CPUID = 0x0A,
    GETSEC = 0x0B,
    HLT = 0x0C,
    INVD = 0x0D,
    INVLPG = 0x0E,
    RDPMC = 0x0F,
    RDTSC = 0x10,
    RSM = 0x11,
    VMCALL = 0x12,
    VMCLEAR = 0x13,
    VMLAUNCH = 0x14,
    VMPTRLD = 0x15,
    VMPTRST = 0x16,
    VMREAD = 0x17,
    VMRESUME = 0x18,
    VMWRITE = 0x19,
    VMXOFF = 0x1A,
    VMXON = 0x1B,
    CONTROL_REGISTER = 0x1C,
    MOV_DR = 0x1D,
    IO = 0x1E,
    RDMSR = 0x1F,
    WRMSR = 0x20,
    INVALID_GUEST_STATE = 0x21,
    MSR_LOAD_FAIL = 0x22,
    /* 0x23 */
    MWAIT = 0x24,
    MONITOR_TRAP_FLAG = 0x25,
    /* 0x26 */
    MONITOR = 0x27,
    PAUSE = 0x28,
    MACHINE_CHECK = 0x29,
    /* 0x2A */
    TPR_BELOW_THRESHOLD = 0x2B,
    APIC_ACCESS = 0x2C,
    GDTR_OR_IDTR = 0x2E,
    LDTR_OR_TR = 0x2F,
    EPT_VIOLATION = 0x30,
    EPT_MISCONFIGURATION = 0x31,
    INVEPT = 0x32,
    RDTSCP = 0x33,
    VMX_PREEMPTION_TIMER = 0x34,
    INVVPID = 0x35,
    WBINVD = 0x36,
    XSETBV = 0x37
};





typedef uint16_t vpid_t;
# 16 "/host/kernel/include/arch/x86/arch/model/statedata.h" 2
# 1 "/host/kernel/include/arch/x86/arch/object/iospace.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 17 "/host/kernel/include/arch/x86/arch/model/statedata.h" 2
# 1 "/host/kernel/include/arch/x86/arch/object/ioport.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       







/* given a pointer to an 8K IO port bitmap, set a range of bits to 0 or 1 based on the `set` parameter */
void setIOPortMask(void *ioport_bitmap, uint16_t low, uint16_t high, bool_t set);

exception_t decodeX86PortInvocation(word_t invLabel, word_t length, cptr_t cptr, cte_t *slot, cap_t cap,
                                    extra_caps_t excaps, bool_t call, word_t *buffer);
exception_t decodeX86PortControlInvocation(word_t invLabel, word_t length, cptr_t cptr, cte_t *slot, cap_t cap,
                                           extra_caps_t excaps, word_t *buffer);

/* used to clean up the final capability to an allocated I/O port range */
void freeIOPortRange(uint16_t first_port, uint16_t last_port);
# 18 "/host/kernel/include/arch/x86/arch/model/statedata.h" 2


# 1 "/host/kernel/include/arch/x86/arch/64/mode/model/statedata.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




# 1 "/host/kernel/include/model/statedata.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




# 1 "/host/kernel/include/object/tcb.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       






# 1 "/host/kernel/include/object/cnode.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       





struct slot_range {
    cte_t *cnode;
    word_t offset;
    word_t length;
};
typedef struct slot_range slot_range_t;

exception_t decodeCNodeInvocation(word_t invLabel, word_t length,
                                  cap_t cap, extra_caps_t excaps,
                                  word_t *buffer);
exception_t invokeCNodeRevoke(cte_t *destSlot);
exception_t invokeCNodeDelete(cte_t *destSlot);
exception_t invokeCNodeCancelBadgedSends(cap_t cap);
exception_t invokeCNodeInsert(cap_t cap, cte_t *srcSlot, cte_t *destSlot);
exception_t invokeCNodeMove(cap_t cap, cte_t *srcSlot, cte_t *destSlot);
exception_t invokeCNodeRotate(cap_t cap1, cap_t cap2, cte_t *slot1,
                              cte_t *slot2, cte_t *slot3);
void cteInsert(cap_t newCap, cte_t *srcSlot, cte_t *destSlot);
void cteMove(cap_t newCap, cte_t *srcSlot, cte_t *destSlot);
void capSwapForDelete(cte_t *slot1, cte_t *slot2);
void cteSwap(cap_t cap1, cte_t *slot1, cap_t cap2, cte_t *slot2);
exception_t cteRevoke(cte_t *slot);
exception_t cteDelete(cte_t *slot, bool_t exposed);
void cteDeleteOne(cte_t *slot);
void insertNewCap(cte_t *parent, cte_t *slot, cap_t cap);
bool_t __attribute__((__pure__)) isMDBParentOf(cte_t *cte_a, cte_t *cte_b);
exception_t ensureNoChildren(cte_t *slot);
exception_t ensureEmptySlot(cte_t *slot);
bool_t __attribute__((__pure__)) isFinalCapability(cte_t *cte);
bool_t __attribute__((__pure__)) slotCapLongRunningDelete(cte_t *slot);
cte_t *getReceiveSlots(tcb_t *thread, word_t *buffer);
cap_transfer_t __attribute__((__pure__)) loadCapTransfer(word_t *buffer);


exception_t invokeCNodeSaveCaller(cte_t *destSlot);
void setupReplyMaster(tcb_t *thread);
# 15 "/host/kernel/include/object/tcb.h" 2


/* Maximum length of the tcb name, including null terminator */

typedef int __assert_failed_tcb_name_fits[(((1ul << (11 -1)) - (tcbCNodeEntries * sizeof(cte_t)) - sizeof(debug_tcb_t)) > 0) ? 1 : -1];


struct tcb_queue {
    tcb_t *head;
    tcb_t *end;
};
typedef struct tcb_queue tcb_queue_t;

static inline unsigned int setMR(tcb_t *receiver, word_t *receiveIPCBuffer,
                                 unsigned int offset, word_t reg)
{
    if (offset >= n_msgRegisters) {
        if (receiveIPCBuffer) {
            receiveIPCBuffer[offset + 1] = reg;
            return offset + 1;
        } else {
            return n_msgRegisters;
        }
    } else {
        setRegister(receiver, msgRegisters[offset], reg);
        return offset + 1;
    }
}

void tcbSchedEnqueue(tcb_t *tcb);
void tcbSchedAppend(tcb_t *tcb);
void tcbSchedDequeue(tcb_t *tcb);


void tcbDebugAppend(tcb_t *tcb);
void tcbDebugRemove(tcb_t *tcb);
# 117 "/host/kernel/include/object/tcb.h"
tcb_queue_t tcbEPAppend(tcb_t *tcb, tcb_queue_t queue);
tcb_queue_t tcbEPDequeue(tcb_t *tcb, tcb_queue_t queue);

void setupCallerCap(tcb_t *sender, tcb_t *receiver, bool_t canGrant);
void deleteCallerCap(tcb_t *receiver);


word_t copyMRs(tcb_t *sender, word_t *sendBuf, tcb_t *receiver,
               word_t *recvBuf, word_t n);
exception_t decodeTCBInvocation(word_t invLabel, word_t length, cap_t cap,
                                cte_t *slot, extra_caps_t excaps, bool_t call,
                                word_t *buffer);
exception_t decodeCopyRegisters(cap_t cap, word_t length,
                                extra_caps_t excaps, word_t *buffer);
exception_t decodeReadRegisters(cap_t cap, word_t length, bool_t call,
                                word_t *buffer);
exception_t decodeWriteRegisters(cap_t cap, word_t length, word_t *buffer);
exception_t decodeTCBConfigure(cap_t cap, word_t length,
                               cte_t *slot, extra_caps_t rootCaps, word_t *buffer);
exception_t decodeSetPriority(cap_t cap, word_t length, extra_caps_t excaps, word_t *buffer);
exception_t decodeSetMCPriority(cap_t cap, word_t length, extra_caps_t excaps, word_t *buffer);



exception_t decodeSetSchedParams(cap_t cap, word_t length, extra_caps_t excaps, word_t *buffer);

exception_t decodeSetIPCBuffer(cap_t cap, word_t length,
                               cte_t *slot, extra_caps_t excaps, word_t *buffer);
exception_t decodeSetSpace(cap_t cap, word_t length,
                           cte_t *slot, extra_caps_t excaps, word_t *buffer);
exception_t decodeDomainInvocation(word_t invLabel, word_t length,
                                   extra_caps_t excaps, word_t *buffer);
exception_t decodeBindNotification(cap_t cap, extra_caps_t excaps);
exception_t decodeUnbindNotification(cap_t cap);
# 171 "/host/kernel/include/object/tcb.h"
enum thread_control_flag {
    thread_control_update_priority = 0x1,
    thread_control_update_ipc_buffer = 0x2,
    thread_control_update_space = 0x4,
    thread_control_update_mcp = 0x8,





};


typedef word_t thread_control_flag_t;

exception_t invokeTCB_Suspend(tcb_t *thread);
exception_t invokeTCB_Resume(tcb_t *thread);
# 203 "/host/kernel/include/object/tcb.h"
exception_t invokeTCB_ThreadControl(tcb_t *target, cte_t *slot, cptr_t faultep,
                                    prio_t mcp, prio_t priority, cap_t cRoot_newCap,
                                    cte_t *cRoot_srcSlot, cap_t vRoot_newCap,
                                    cte_t *vRoot_srcSlot, word_t bufferAddr,
                                    cap_t bufferCap, cte_t *bufferSrcSlot,
                                    thread_control_flag_t updateFlags);

exception_t invokeTCB_CopyRegisters(tcb_t *dest, tcb_t *src,
                                    bool_t suspendSource, bool_t resumeTarget,
                                    bool_t transferFrame, bool_t transferInteger,
                                    word_t transferArch);
exception_t invokeTCB_ReadRegisters(tcb_t *src, bool_t suspendSource,
                                    word_t n, word_t arch, bool_t call);
exception_t invokeTCB_WriteRegisters(tcb_t *dest, bool_t resumeTarget,
                                     word_t n, word_t arch, word_t *buffer);
exception_t invokeTCB_NotificationControl(tcb_t *tcb, notification_t *ntfnPtr);

cptr_t __attribute__((__pure__)) getExtraCPtr(word_t *bufferPtr, word_t i);
void setExtraBadge(word_t *bufferPtr, word_t badge, word_t i);

exception_t lookupExtraCaps(tcb_t *thread, word_t *bufferPtr, seL4_MessageInfo_t info);
word_t setMRs_syscall_error(tcb_t *thread, word_t *receiveIPCBuffer);
word_t __attribute__((__const__)) Arch_decodeTransfer(word_t flags);
exception_t __attribute__((__const__)) Arch_performTransfer(word_t arch, tcb_t *tcb_src,
                                       tcb_t *tcb_dest);






void setThreadName(tcb_t *thread, const char *name);
# 13 "/host/kernel/include/model/statedata.h" 2
# 38 "/host/kernel/include/model/statedata.h"
/* UP states are declared as VISIBLE so that they are accessible in assembly */
# 58 "/host/kernel/include/model/statedata.h"

extern tcb_queue_t ksReadyQueues[(1 * 256)] __attribute__((externally_visible));
extern word_t ksReadyQueuesL1Bitmap[1] __attribute__((externally_visible));
extern word_t ksReadyQueuesL2Bitmap[1][((256 + (1 << 6) - 1) / (1 << 6))] __attribute__((externally_visible));
extern tcb_t *ksCurThread __attribute__((externally_visible));
extern tcb_t *ksIdleThread __attribute__((externally_visible));
extern tcb_t *ksSchedulerAction __attribute__((externally_visible));
# 75 "/host/kernel/include/model/statedata.h"
/* Current state installed in the FPU, or NULL if the FPU is currently invalid */
extern user_fpu_state_t * ksActiveFPUState __attribute__((externally_visible));
/* Number of times we have restored a user context with an active FPU without switching it */
extern word_t ksFPURestoresSinceSwitch __attribute__((externally_visible));


extern tcb_t * ksDebugTCBs __attribute__((externally_visible));
# 92 "/host/kernel/include/model/statedata.h"
;

extern word_t ksNumCPUs;






extern word_t ksWorkUnitsCompleted;
extern irq_state_t intStateIRQTable[];
extern cte_t intStateIRQNode[];

extern const dschedule_t ksDomSchedule[];
extern const word_t ksDomScheduleLength;
extern word_t ksDomScheduleIdx;
extern dom_t ksCurDomain;



extern word_t ksDomainTime;

extern word_t tlbLockCount __attribute__((externally_visible));

extern char ksIdleThreadTCB[1][(1ul << (11))];
# 13 "/host/kernel/include/arch/x86/arch/64/mode/model/statedata.h" 2

extern pml4e_t x64KSKernelPML4[(1ul << (9))] __attribute__((externally_visible));
extern pdpte_t x64KSKernelPDPT[(1ul << (9))];

extern pde_t x64KSKernelPD[(1ul << (9))];



extern pte_t x64KSKernelPT[(1ul << (9))];


extern pml4e_t x64KSSKIMPML4[(1ul << (9))] __attribute__((__aligned__((1ul << (12)))));
extern pdpte_t x64KSSKIMPDPT[(1ul << (9))] __attribute__((__aligned__((1ul << (12)))));
/* we only need a single PD regardless of huge pages or not as the skim window
   just has a few 2M entries out of the 1gb region of the kernel image */
extern pde_t x64KSSKIMPD[(1ul << (9))] __attribute__((__aligned__((1ul << (12)))));




/* we declare this as a word_t and not a cr3_t as we cache both state and potentially
 * command information (state being pml4 base and pcid) and command being whether or not
 * to flush translation. the formal cr3_t type only talks about the state */
extern word_t x64KSCurrentUserCR3 __attribute__((externally_visible));



;

/* hardware interrupt handlers push up to 6 words onto the stack. The order of the
 words is Error, RIP, CS, FLAGS, RSP, SS. It also needs to be 16byte aligned for
 the hardware to push correctly. For better SMP performance we add 2 words to the
 array (such that each array is 64 bytes) and align to 64 bytes as well (which is
 the typical L1 cache line size). Note that we do not align to the L1_CACHE_LINE_SZ
 macro as that *could* be configured to be less than 16, which would be incorrect
 for us here */

extern word_t x64KSIRQStack[1][6 + 2] __attribute__((__aligned__(64))) __attribute__((externally_visible)) __attribute__((__section__(".skim.bss")));
# 21 "/host/kernel/include/arch/x86/arch/model/statedata.h" 2




typedef struct {
    tss_t tss;
    word_t io_map[(65536 / 8 / sizeof(word_t) + 1)];
} __attribute__((packed)) tss_io_t;


/* Interrupt currently being handled, not preserved across kernel entries */
extern interrupt_t x86KScurInterrupt __attribute__((externally_visible));
/* Interrupt that the hardware believes we are currently handling (is marked in service
 * in the APIC) but we have not yet gotten around to handling */
extern interrupt_t x86KSPendingInterrupt __attribute__((externally_visible));
/* Bitmask of all cores should receive the reschedule IPI */
extern word_t ipiReschedulePending __attribute__((externally_visible));





extern word_t x86KSCurrentFSBase __attribute__((externally_visible));
extern word_t x86KSCurrentGSBase __attribute__((externally_visible));

/* If a GP exception occurs and this is non NULL then the exception should return to
 * this location instead of faulting. In addition the GP exception will clear this
 * back to NULL */
extern word_t x86KSGPExceptReturnTo __attribute__((externally_visible));

;
;

/* this is per core state grouped into a separate struct as it needs to be available
 * at all times by the hardware, even when we are running in user mode */
typedef struct x86_arch_global_state {
    /* Task State Segment (TSS), contains currently running TCB in ESP0 */
    tss_io_t x86KStss;
    /* Global Descriptor Table (GDT) */
    gdt_entry_t x86KSgdt[9];
    /* Interrupt Descriptor Table (IDT) */
    idt_entry_t x86KSidt[256];
    char padding[64 - ((sizeof(tss_io_t) + 9 *sizeof(gdt_entry_t) + 256 *sizeof(idt_entry_t)) % 64)];
} x86_arch_global_state_t;
typedef int __assert_failed_x86_arch_global_state_padded[((sizeof(x86_arch_global_state_t) % 64) == 0) ? 1 : -1];

extern x86_arch_global_state_t x86KSGlobalState[1] __attribute__((__aligned__(64))) __attribute__((__section__(".skim.bss")));

extern asid_pool_t *x86KSASIDTable[];
extern uint32_t x86KScacheLineSizeBits;
extern user_fpu_state_t x86KSnullFpuState __attribute__((__aligned__(64)));
# 82 "/host/kernel/include/arch/x86/arch/model/statedata.h"
extern uint16_t x86KSconsolePort;


extern uint16_t x86KSdebugPort;


extern x86_irq_state_t x86KSIRQState[];

extern word_t x86KSAllocatedIOPorts[(1ul << (16)) / 64];
# 12 "/host/kernel/include/arch/x86/arch/64/mode/machine.h" 2
# 1 "/host/kernel/include/arch/x86/arch/machine/cpu_registers.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 29 "/host/kernel/include/arch/x86/arch/machine/cpu_registers.h"
/* We use a dummy variable to synchronize reads and writes to the control registers.
 * this allows us to write inline asm blocks that do not have enforced memory
 * clobbers for ordering. */
static unsigned long control_reg_order;

# 1 "/host/kernel/include/arch/x86/arch/64/mode/machine/cpu_registers.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

static inline unsigned long read_cr3(void)
{
    word_t cr3;
    __asm__ volatile("movq %%cr3, %0" : "=r"(cr3), "=m"(control_reg_order));
    return cr3;
}

static inline void write_cr3(unsigned long val)
{
    __asm__ volatile("movq %0, %%cr3" :: "r"(val), "m"(control_reg_order));
}

static inline unsigned long read_cr0(void)
{
    unsigned long val;
    __asm__ volatile("movq %%cr0, %0" : "=r"(val), "=m"(control_reg_order));
    return val;
}

static inline void write_cr0(unsigned long val)
{
    __asm__ volatile("movq %0, %%cr0" :: "r"(val), "m"(control_reg_order));
}

static inline unsigned long read_cr2(void)
{
    unsigned long val;
    __asm__ volatile("movq %%cr2, %0" : "=r"(val), "=m"(control_reg_order));
    return val;
}

static inline unsigned long read_cr4(void)
{
    unsigned long val;
    __asm__ volatile("movq %%cr4, %0" : "=r"(val), "=m"(control_reg_order));
    return val;
}

static inline void write_cr4(unsigned long val)
{
    __asm__ volatile("movq %0, %%cr4" :: "r"(val), "m"(control_reg_order));
}
# 35 "/host/kernel/include/arch/x86/arch/machine/cpu_registers.h" 2

static inline void xsetbv(uint32_t reg, uint64_t value)
{
    __asm__ volatile("xsetbv" :: "d"((uint32_t)(value >> 32)), "a"((uint32_t)(value & 0xffffffff)), "c"(reg), "m"(control_reg_order));
}

static inline void write_xcr0(uint64_t value)
{
    xsetbv(0, value);
}
# 13 "/host/kernel/include/arch/x86/arch/64/mode/machine.h" 2
# 1 "/host/kernel/include/arch/x86/arch/model/smp.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       





# 1 "/host/kernel/include/model/smp.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 14 "/host/kernel/include/arch/x86/arch/model/smp.h" 2
# 1 "/host/kernel/include/arch/x86/arch/64/mode/model/smp.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 15 "/host/kernel/include/arch/x86/arch/model/smp.h" 2
# 14 "/host/kernel/include/arch/x86/arch/64/mode/machine.h" 2
# 1 "/host/kernel/include/arch/x86/arch/machine.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




# 1 "/host/kernel/include/arch/x86/arch/machine/pat.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 13 "/host/kernel/include/arch/x86/arch/machine.h" 2



# 1 "/host/kernel/include/object/interrupt.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




# 1 "/host/kernel/include/arch/x86/arch/object/interrupt.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       






exception_t Arch_decodeIRQControlInvocation(word_t invLabel, word_t length,
                                            cte_t *srcSlot, extra_caps_t excaps,
                                            word_t *buffer);
void Arch_irqStateInit(void);
exception_t Arch_checkIRQ(word_t irq_w);
# 13 "/host/kernel/include/object/interrupt.h" 2


exception_t decodeIRQControlInvocation(word_t invLabel, word_t length,
                                       cte_t *srcSlot, extra_caps_t excaps,
                                       word_t *buffer);
exception_t invokeIRQControl(irq_t irq, cte_t *handlerSlot, cte_t *controlSlot);
exception_t decodeIRQHandlerInvocation(word_t invLabel, irq_t irq,
                                       extra_caps_t excaps);
void invokeIRQHandler_AckIRQ(irq_t irq);
void invokeIRQHandler_SetIRQHandler(irq_t irq, cap_t cap, cte_t *slot);
void invokeIRQHandler_ClearIRQHandler(irq_t irq);
void deletingIRQHandler(irq_t irq);
void deletedIRQHandler(irq_t irq);
void handleInterrupt(irq_t irq);
bool_t isIRQActive(irq_t irq);
void setIRQState(irq_state_t irqState, irq_t irq);
# 17 "/host/kernel/include/arch/x86/arch/machine.h" 2
# 52 "/host/kernel/include/arch/x86/arch/machine.h"
/* These values taken from:
 *  * Intel manuals, Vol3, table 35-1.
 *  * https://software.intel.com/en-us/articles/intel-architecture-and-processor-identification-with-cpuid-model-and-family-numbers
 */
# 82 "/host/kernel/include/arch/x86/arch/machine.h"
/* This article discloses prefetcher control on Intel processors; Nehalem, Westmere, Sandy Bridge,
   Ivy Bridge, Haswell, and Broadwell. It is currently undocumented in the regular intel manuals.
   https://software.intel.com/en-us/articles/disclosure-of-hw-prefetcher-control-on-some-intel-processors */
# 97 "/host/kernel/include/arch/x86/arch/machine.h"
word_t __attribute__((__pure__)) getRestartPC(tcb_t *thread);
void setNextPC(tcb_t *thread, word_t v);

static uint64_t x86_rdmsr(const uint32_t reg)
{
    uint32_t low, high;
    uint64_t value;
    __asm__ volatile("rdmsr" : "=a"(low), "=d"(high) : "c"(reg));
    value = ((uint64_t)high << 32) | (uint64_t)low;
    return value;
}

/* Read model specific register */
static inline uint32_t x86_rdmsr_low(const uint32_t reg)
{
    return (uint32_t)x86_rdmsr(reg);
}

static inline uint32_t x86_rdmsr_high(const uint32_t reg)
{
    return (uint32_t)(x86_rdmsr(reg) >> 32ull);
}

/* Write model specific register */
static inline void x86_wrmsr_parts(const uint32_t reg, const uint32_t high, const uint32_t low)
{
    __asm__ volatile("wrmsr" :: "a"(low), "d"(high), "c"(reg));
}

static inline void x86_wrmsr(const uint32_t reg, const uint64_t val)
{
    uint32_t low = (uint32_t)val;
    uint32_t high = (uint32_t)(val >> 32);
    x86_wrmsr_parts(reg, high, low);
}

/* Read different parts of CPUID */
static inline uint32_t x86_cpuid_edx(uint32_t eax, uint32_t ecx)
{
    uint32_t edx, ebx;
    __asm__ volatile("cpuid"
                 : "=a"(eax),
                 "=b"(ebx),
                 "=c"(ecx),
                 "=d"(edx)
                 : "a"(eax), "c"(ecx)
                 : "memory");
    return edx;
}

static inline uint32_t x86_cpuid_eax(uint32_t eax, uint32_t ecx)
{
    uint32_t edx, ebx;
    __asm__ volatile("cpuid"
                 : "=a"(eax),
                 "=b"(ebx),
                 "=c"(ecx),
                 "=d"(edx)
                 : "a"(eax), "c"(ecx)
                 : "memory");
    return eax;
}

static inline uint32_t x86_cpuid_ecx(uint32_t eax, uint32_t ecx)
{
    uint32_t edx, ebx;
    __asm__ volatile("cpuid"
                 : "=a"(eax),
                 "=b"(ebx),
                 "=c"(ecx),
                 "=d"(edx)
                 : "a"(eax), "c"(ecx)
                 : "memory");
    return ecx;
}

static inline uint32_t x86_cpuid_ebx(uint32_t eax, uint32_t ecx)
{
    uint32_t edx, ebx;
    __asm__ volatile("cpuid"
                 : "=a"(eax),
                 "=b"(ebx),
                 "=c"(ecx),
                 "=d"(edx)
                 : "a"(eax), "c"(ecx)
                 : "memory");
    return ebx;
}

static inline uint64_t x86_rdtsc(void)
{
    uint32_t hi, lo;
    __asm__ volatile("rdtsc"
                 : "=a"(lo),
                 "=d"(hi)
                );
    return ((uint64_t) hi) << 32llu | (uint64_t) lo;
}
# 203 "/host/kernel/include/arch/x86/arch/machine.h"
enum x86_vendor {
    X86_VENDOR_INTEL = 0,
    X86_VENDOR_AMD,
    X86_VENDOR_OTHER
};

typedef struct _x86_cpu_identity {
    uint8_t family, model, stepping, extended_family, extended_model;
    uint8_t brand;
} x86_cpu_identity_t;

typedef struct _cpu_identity {
    enum x86_vendor vendor;
    char vendor_string[(12) + 1];

    /* Adjusted and normalized family, model and stepping values as recommended
     * by Intel. The name "display" was chosen because that's the nomenclature
     * Intel uses.
     */
    x86_cpu_identity_t display;
} cpu_identity_t;

/* This, and all its adjoint routines will be called at init time; see boot.c */
__attribute__((__section__(".boot.text"))) bool_t x86_cpuid_initialize(void);

/** To be used by code that wants to know the family/model/stepping/brand of
 * a CPU.
 */
x86_cpu_identity_t *x86_cpuid_get_model_info(void);

/** To be used by code that wants to get the CPU vendor name.
 */
cpu_identity_t *x86_cpuid_get_identity(void);

/*
 * Forward declarations here as these may instead be later defined in
 * mode-specific machine.h
 */

static inline void x86_write_fs_base_impl(word_t base);
static inline word_t x86_read_fs_base_impl(void);
static inline void x86_write_gs_base_impl(word_t base);
static inline word_t x86_read_gs_base_impl(void);



static inline void x86_write_fs_base_impl(word_t base)
{
    x86_wrmsr(0xC0000100, base);
}

static inline word_t x86_read_fs_base_impl(void)
{
    return x86_rdmsr(0xC0000100);
}
# 294 "/host/kernel/include/arch/x86/arch/machine.h"
/* Writing the fs/gs bases can be expensive (especially if it requires a MSR
   write), so we avoid actually writing them if they aren't actually changed. */

static inline void x86_write_fs_base(word_t base, cpu_id_t cpu)
{
    if (base != x86KSCurrentFSBase) {
        x86KSCurrentFSBase = base;
        x86_write_fs_base_impl(base);
    }
}

static inline void x86_write_gs_base(word_t base, cpu_id_t cpu)
{
    if (__builtin_expect(!!(base != x86KSCurrentGSBase), 1)) {
        x86KSCurrentGSBase = base;
        x86_write_gs_base_impl(base);
    }
}

static inline word_t x86_read_fs_base(cpu_id_t cpu)
{
    return x86KSCurrentFSBase;
}

static inline word_t x86_read_gs_base(cpu_id_t cpu)
{
    return x86KSCurrentGSBase;
}




static inline void x86_load_fsgs_base(tcb_t *thread, cpu_id_t cpu)
{
    /*
     * Restore the FS and GS base registers.
     *
     * These should only be accessed inside the kernel, between the
     * entry and exit calls to swapgs if used.
     */
    word_t fs_base = getRegister(thread, FS_BASE);
    x86_write_fs_base(fs_base, cpu);
    word_t gs_base = getRegister(thread, GS_BASE);
    x86_write_gs_base(gs_base, cpu);
}

/* Cleaning memory before user-level access */
static inline void clearMemory(void *ptr, unsigned int bits)
{
    memzero(ptr, (1ul << (bits)));
    /* no cleaning of caches necessary on IA-32 */
}

/* Initialises MSRs required to setup sysenter and sysexit */
void init_sysenter_msrs(void);

/* Read/write memory fence */
static inline void x86_mfence(void)
{
    __asm__ volatile("mfence" ::: "memory");
}

/* Get page fault address from CR2 register */
static inline unsigned long getFaultAddr(void)
{
    return read_cr2();
}

static inline void Arch_finaliseInterrupt(void)
{
    x86KScurInterrupt = int_invalid;
}

static inline void x86_set_tls_segment_base(word_t tls_base);

/* Update the value of the actual regsiter to hold the expected value */
static inline exception_t Arch_setTLSRegister(word_t tls_base)
{
    word_t sanitised = Mode_sanitiseRegister(TLS_BASE, tls_base);

    if (sanitised != tls_base) {
        return EXCEPTION_SYSCALL_ERROR;
    }


    /*
     * The context is only updated from the register on a context switch
     * if the FSGS instructions are enabled. When they aren't it msut be
     * manually stored here.
     */
    setRegister(ksCurThread, TLS_BASE, tls_base);


    x86_set_tls_segment_base(sanitised);

    return EXCEPTION_NONE;
}

/* we do not cache the IBRS value as writing the enable bit is meaningful even if it
 * is already set. On some processors if the enable bit was set it must be 're-written'
 * in order for a higher privilege to correctly not have its branch predictions affected */
static inline void x86_enable_ibrs(void)
{
    /* we always enable the STIBP bit since we want it on if its supported and it
     * isn't a fault to set the bit if support is missing */
    x86_wrmsr(0x48, (1ul << (0)) /* Indirect Branch Restricted Speculation */ | (1ul << (1)) /* Single Thread Indirect Branch Predictors */);
}

static inline void x86_disable_ibrs(void)
{
    /* we always enable the STIBP bit since we want it on if its supported and it
     * isn't a fault to set the bit if support is missing */
    x86_wrmsr(0x48, (1ul << (1)) /* Single Thread Indirect Branch Predictors */);
}

static inline void x86_ibpb(void)
{
    x86_wrmsr(0x49, 1);
}

static inline void x86_flush_rsb(void)
{
    /* perform 32 near calls with a non zero displacement to flush the rsb with
     * speculation traps. */
    word_t iter = 32;
    __asm__ volatile(
        "1:\n"
        "sub $2, %[iter]\n"
        "call 2f\n"
        "pause\n"
        "jmp 1b\n"
        "2:\n"
        "call 3f\n"
        "pause\n"
        "jmp 2b\n"
        "3:\n"
        "cmp $0, %[iter]\n"
        "jne 1b\n"

        "add %[stack_amount], %%rsp\n"



        : [iter]"+r"(iter)
        : [stack_amount]"i"(sizeof(word_t) * iter)
        : "cc"
    );
}

/* sysenter entry point */
void handle_syscall(void);

/** MODIFIES: phantom_machine_state */
void int_00(void);
/** MODIFIES: phantom_machine_state */
void int_01(void);
/** MODIFIES: phantom_machine_state */
void int_02(void);
/** MODIFIES: phantom_machine_state */
void int_03(void);
/** MODIFIES: phantom_machine_state */
void int_04(void);
/** MODIFIES: phantom_machine_state */
void int_05(void);
/** MODIFIES: phantom_machine_state */
void int_06(void);
/** MODIFIES: phantom_machine_state */
void int_07(void);
/** MODIFIES: phantom_machine_state */
void int_08(void);
/** MODIFIES: phantom_machine_state */
void int_09(void);
/** MODIFIES: phantom_machine_state */
void int_0a(void);
/** MODIFIES: phantom_machine_state */
void int_0b(void);
/** MODIFIES: phantom_machine_state */
void int_0c(void);
/** MODIFIES: phantom_machine_state */
void int_0d(void);
/** MODIFIES: phantom_machine_state */
void int_0e(void);
/** MODIFIES: phantom_machine_state */
void int_0f(void);

/** MODIFIES: phantom_machine_state */
void int_10(void);
/** MODIFIES: phantom_machine_state */
void int_11(void);
/** MODIFIES: phantom_machine_state */
void int_12(void);
/** MODIFIES: phantom_machine_state */
void int_13(void);
/** MODIFIES: phantom_machine_state */
void int_14(void);
/** MODIFIES: phantom_machine_state */
void int_15(void);
/** MODIFIES: phantom_machine_state */
void int_16(void);
/** MODIFIES: phantom_machine_state */
void int_17(void);
/** MODIFIES: phantom_machine_state */
void int_18(void);
/** MODIFIES: phantom_machine_state */
void int_19(void);
/** MODIFIES: phantom_machine_state */
void int_1a(void);
/** MODIFIES: phantom_machine_state */
void int_1b(void);
/** MODIFIES: phantom_machine_state */
void int_1c(void);
/** MODIFIES: phantom_machine_state */
void int_1d(void);
/** MODIFIES: phantom_machine_state */
void int_1e(void);
/** MODIFIES: phantom_machine_state */
void int_1f(void);

/** MODIFIES: phantom_machine_state */
void int_20(void);
/** MODIFIES: phantom_machine_state */
void int_21(void);
/** MODIFIES: phantom_machine_state */
void int_22(void);
/** MODIFIES: phantom_machine_state */
void int_23(void);
/** MODIFIES: phantom_machine_state */
void int_24(void);
/** MODIFIES: phantom_machine_state */
void int_25(void);
/** MODIFIES: phantom_machine_state */
void int_26(void);
/** MODIFIES: phantom_machine_state */
void int_27(void);
/** MODIFIES: phantom_machine_state */
void int_28(void);
/** MODIFIES: phantom_machine_state */
void int_29(void);
/** MODIFIES: phantom_machine_state */
void int_2a(void);
/** MODIFIES: phantom_machine_state */
void int_2b(void);
/** MODIFIES: phantom_machine_state */
void int_2c(void);
/** MODIFIES: phantom_machine_state */
void int_2d(void);
/** MODIFIES: phantom_machine_state */
void int_2e(void);
/** MODIFIES: phantom_machine_state */
void int_2f(void);

/** MODIFIES: phantom_machine_state */
void int_30(void);
/** MODIFIES: phantom_machine_state */
void int_31(void);
/** MODIFIES: phantom_machine_state */
void int_32(void);
/** MODIFIES: phantom_machine_state */
void int_33(void);
/** MODIFIES: phantom_machine_state */
void int_34(void);
/** MODIFIES: phantom_machine_state */
void int_35(void);
/** MODIFIES: phantom_machine_state */
void int_36(void);
/** MODIFIES: phantom_machine_state */
void int_37(void);
/** MODIFIES: phantom_machine_state */
void int_38(void);
/** MODIFIES: phantom_machine_state */
void int_39(void);
/** MODIFIES: phantom_machine_state */
void int_3a(void);
/** MODIFIES: phantom_machine_state */
void int_3b(void);
/** MODIFIES: phantom_machine_state */
void int_3c(void);
/** MODIFIES: phantom_machine_state */
void int_3d(void);
/** MODIFIES: phantom_machine_state */
void int_3e(void);
/** MODIFIES: phantom_machine_state */
void int_3f(void);

/** MODIFIES: phantom_machine_state */
void int_40(void);
/** MODIFIES: phantom_machine_state */
void int_41(void);
/** MODIFIES: phantom_machine_state */
void int_42(void);
/** MODIFIES: phantom_machine_state */
void int_43(void);
/** MODIFIES: phantom_machine_state */
void int_44(void);
/** MODIFIES: phantom_machine_state */
void int_45(void);
/** MODIFIES: phantom_machine_state */
void int_46(void);
/** MODIFIES: phantom_machine_state */
void int_47(void);
/** MODIFIES: phantom_machine_state */
void int_48(void);
/** MODIFIES: phantom_machine_state */
void int_49(void);
/** MODIFIES: phantom_machine_state */
void int_4a(void);
/** MODIFIES: phantom_machine_state */
void int_4b(void);
/** MODIFIES: phantom_machine_state */
void int_4c(void);
/** MODIFIES: phantom_machine_state */
void int_4d(void);
/** MODIFIES: phantom_machine_state */
void int_4e(void);
/** MODIFIES: phantom_machine_state */
void int_4f(void);

/** MODIFIES: phantom_machine_state */
void int_50(void);
/** MODIFIES: phantom_machine_state */
void int_51(void);
/** MODIFIES: phantom_machine_state */
void int_52(void);
/** MODIFIES: phantom_machine_state */
void int_53(void);
/** MODIFIES: phantom_machine_state */
void int_54(void);
/** MODIFIES: phantom_machine_state */
void int_55(void);
/** MODIFIES: phantom_machine_state */
void int_56(void);
/** MODIFIES: phantom_machine_state */
void int_57(void);
/** MODIFIES: phantom_machine_state */
void int_58(void);
/** MODIFIES: phantom_machine_state */
void int_59(void);
/** MODIFIES: phantom_machine_state */
void int_5a(void);
/** MODIFIES: phantom_machine_state */
void int_5b(void);
/** MODIFIES: phantom_machine_state */
void int_5c(void);
/** MODIFIES: phantom_machine_state */
void int_5d(void);
/** MODIFIES: phantom_machine_state */
void int_5e(void);
/** MODIFIES: phantom_machine_state */
void int_5f(void);

/** MODIFIES: phantom_machine_state */
void int_60(void);
/** MODIFIES: phantom_machine_state */
void int_61(void);
/** MODIFIES: phantom_machine_state */
void int_62(void);
/** MODIFIES: phantom_machine_state */
void int_63(void);
/** MODIFIES: phantom_machine_state */
void int_64(void);
/** MODIFIES: phantom_machine_state */
void int_65(void);
/** MODIFIES: phantom_machine_state */
void int_66(void);
/** MODIFIES: phantom_machine_state */
void int_67(void);
/** MODIFIES: phantom_machine_state */
void int_68(void);
/** MODIFIES: phantom_machine_state */
void int_69(void);
/** MODIFIES: phantom_machine_state */
void int_6a(void);
/** MODIFIES: phantom_machine_state */
void int_6b(void);
/** MODIFIES: phantom_machine_state */
void int_6c(void);
/** MODIFIES: phantom_machine_state */
void int_6d(void);
/** MODIFIES: phantom_machine_state */
void int_6e(void);
/** MODIFIES: phantom_machine_state */
void int_6f(void);

/** MODIFIES: phantom_machine_state */
void int_70(void);
/** MODIFIES: phantom_machine_state */
void int_71(void);
/** MODIFIES: phantom_machine_state */
void int_72(void);
/** MODIFIES: phantom_machine_state */
void int_73(void);
/** MODIFIES: phantom_machine_state */
void int_74(void);
/** MODIFIES: phantom_machine_state */
void int_75(void);
/** MODIFIES: phantom_machine_state */
void int_76(void);
/** MODIFIES: phantom_machine_state */
void int_77(void);
/** MODIFIES: phantom_machine_state */
void int_78(void);
/** MODIFIES: phantom_machine_state */
void int_79(void);
/** MODIFIES: phantom_machine_state */
void int_7a(void);
/** MODIFIES: phantom_machine_state */
void int_7b(void);
/** MODIFIES: phantom_machine_state */
void int_7c(void);
/** MODIFIES: phantom_machine_state */
void int_7d(void);
/** MODIFIES: phantom_machine_state */
void int_7e(void);
/** MODIFIES: phantom_machine_state */
void int_7f(void);

/** MODIFIES: phantom_machine_state */
void int_80(void);
/** MODIFIES: phantom_machine_state */
void int_81(void);
/** MODIFIES: phantom_machine_state */
void int_82(void);
/** MODIFIES: phantom_machine_state */
void int_83(void);
/** MODIFIES: phantom_machine_state */
void int_84(void);
/** MODIFIES: phantom_machine_state */
void int_85(void);
/** MODIFIES: phantom_machine_state */
void int_86(void);
/** MODIFIES: phantom_machine_state */
void int_87(void);
/** MODIFIES: phantom_machine_state */
void int_88(void);
/** MODIFIES: phantom_machine_state */
void int_89(void);
/** MODIFIES: phantom_machine_state */
void int_8a(void);
/** MODIFIES: phantom_machine_state */
void int_8b(void);
/** MODIFIES: phantom_machine_state */
void int_8c(void);
/** MODIFIES: phantom_machine_state */
void int_8d(void);
/** MODIFIES: phantom_machine_state */
void int_8e(void);
/** MODIFIES: phantom_machine_state */
void int_8f(void);

/** MODIFIES: phantom_machine_state */
void int_90(void);
/** MODIFIES: phantom_machine_state */
void int_91(void);
/** MODIFIES: phantom_machine_state */
void int_92(void);
/** MODIFIES: phantom_machine_state */
void int_93(void);
/** MODIFIES: phantom_machine_state */
void int_94(void);
/** MODIFIES: phantom_machine_state */
void int_95(void);
/** MODIFIES: phantom_machine_state */
void int_96(void);
/** MODIFIES: phantom_machine_state */
void int_97(void);
/** MODIFIES: phantom_machine_state */
void int_98(void);
/** MODIFIES: phantom_machine_state */
void int_99(void);
/** MODIFIES: phantom_machine_state */
void int_9a(void);
/** MODIFIES: phantom_machine_state */
void int_9b(void);
/** MODIFIES: phantom_machine_state */
void int_9c(void);
/** MODIFIES: phantom_machine_state */
void int_9d(void);
/** MODIFIES: phantom_machine_state */
void int_9e(void);
/** MODIFIES: phantom_machine_state */
void int_9f(void);

/** MODIFIES: phantom_machine_state */
void int_a0(void);
/** MODIFIES: phantom_machine_state */
void int_a1(void);
/** MODIFIES: phantom_machine_state */
void int_a2(void);
/** MODIFIES: phantom_machine_state */
void int_a3(void);
/** MODIFIES: phantom_machine_state */
void int_a4(void);
/** MODIFIES: phantom_machine_state */
void int_a5(void);
/** MODIFIES: phantom_machine_state */
void int_a6(void);
/** MODIFIES: phantom_machine_state */
void int_a7(void);
/** MODIFIES: phantom_machine_state */
void int_a8(void);
/** MODIFIES: phantom_machine_state */
void int_a9(void);
/** MODIFIES: phantom_machine_state */
void int_aa(void);
/** MODIFIES: phantom_machine_state */
void int_ab(void);
/** MODIFIES: phantom_machine_state */
void int_ac(void);
/** MODIFIES: phantom_machine_state */
void int_ad(void);
/** MODIFIES: phantom_machine_state */
void int_ae(void);
/** MODIFIES: phantom_machine_state */
void int_af(void);

/** MODIFIES: phantom_machine_state */
void int_b0(void);
/** MODIFIES: phantom_machine_state */
void int_b1(void);
/** MODIFIES: phantom_machine_state */
void int_b2(void);
/** MODIFIES: phantom_machine_state */
void int_b3(void);
/** MODIFIES: phantom_machine_state */
void int_b4(void);
/** MODIFIES: phantom_machine_state */
void int_b5(void);
/** MODIFIES: phantom_machine_state */
void int_b6(void);
/** MODIFIES: phantom_machine_state */
void int_b7(void);
/** MODIFIES: phantom_machine_state */
void int_b8(void);
/** MODIFIES: phantom_machine_state */
void int_b9(void);
/** MODIFIES: phantom_machine_state */
void int_ba(void);
/** MODIFIES: phantom_machine_state */
void int_bb(void);
/** MODIFIES: phantom_machine_state */
void int_bc(void);
/** MODIFIES: phantom_machine_state */
void int_bd(void);
/** MODIFIES: phantom_machine_state */
void int_be(void);
/** MODIFIES: phantom_machine_state */
void int_bf(void);

/** MODIFIES: phantom_machine_state */
void int_c0(void);
/** MODIFIES: phantom_machine_state */
void int_c1(void);
/** MODIFIES: phantom_machine_state */
void int_c2(void);
/** MODIFIES: phantom_machine_state */
void int_c3(void);
/** MODIFIES: phantom_machine_state */
void int_c4(void);
/** MODIFIES: phantom_machine_state */
void int_c5(void);
/** MODIFIES: phantom_machine_state */
void int_c6(void);
/** MODIFIES: phantom_machine_state */
void int_c7(void);
/** MODIFIES: phantom_machine_state */
void int_c8(void);
/** MODIFIES: phantom_machine_state */
void int_c9(void);
/** MODIFIES: phantom_machine_state */
void int_ca(void);
/** MODIFIES: phantom_machine_state */
void int_cb(void);
/** MODIFIES: phantom_machine_state */
void int_cc(void);
/** MODIFIES: phantom_machine_state */
void int_cd(void);
/** MODIFIES: phantom_machine_state */
void int_ce(void);
/** MODIFIES: phantom_machine_state */
void int_cf(void);

/** MODIFIES: phantom_machine_state */
void int_d0(void);
/** MODIFIES: phantom_machine_state */
void int_d1(void);
/** MODIFIES: phantom_machine_state */
void int_d2(void);
/** MODIFIES: phantom_machine_state */
void int_d3(void);
/** MODIFIES: phantom_machine_state */
void int_d4(void);
/** MODIFIES: phantom_machine_state */
void int_d5(void);
/** MODIFIES: phantom_machine_state */
void int_d6(void);
/** MODIFIES: phantom_machine_state */
void int_d7(void);
/** MODIFIES: phantom_machine_state */
void int_d8(void);
/** MODIFIES: phantom_machine_state */
void int_d9(void);
/** MODIFIES: phantom_machine_state */
void int_da(void);
/** MODIFIES: phantom_machine_state */
void int_db(void);
/** MODIFIES: phantom_machine_state */
void int_dc(void);
/** MODIFIES: phantom_machine_state */
void int_dd(void);
/** MODIFIES: phantom_machine_state */
void int_de(void);
/** MODIFIES: phantom_machine_state */
void int_df(void);

/** MODIFIES: phantom_machine_state */
void int_e0(void);
/** MODIFIES: phantom_machine_state */
void int_e1(void);
/** MODIFIES: phantom_machine_state */
void int_e2(void);
/** MODIFIES: phantom_machine_state */
void int_e3(void);
/** MODIFIES: phantom_machine_state */
void int_e4(void);
/** MODIFIES: phantom_machine_state */
void int_e5(void);
/** MODIFIES: phantom_machine_state */
void int_e6(void);
/** MODIFIES: phantom_machine_state */
void int_e7(void);
/** MODIFIES: phantom_machine_state */
void int_e8(void);
/** MODIFIES: phantom_machine_state */
void int_e9(void);
/** MODIFIES: phantom_machine_state */
void int_ea(void);
/** MODIFIES: phantom_machine_state */
void int_eb(void);
/** MODIFIES: phantom_machine_state */
void int_ec(void);
/** MODIFIES: phantom_machine_state */
void int_ed(void);
/** MODIFIES: phantom_machine_state */
void int_ee(void);
/** MODIFIES: phantom_machine_state */
void int_ef(void);

/** MODIFIES: phantom_machine_state */
void int_f0(void);
/** MODIFIES: phantom_machine_state */
void int_f1(void);
/** MODIFIES: phantom_machine_state */
void int_f2(void);
/** MODIFIES: phantom_machine_state */
void int_f3(void);
/** MODIFIES: phantom_machine_state */
void int_f4(void);
/** MODIFIES: phantom_machine_state */
void int_f5(void);
/** MODIFIES: phantom_machine_state */
void int_f6(void);
/** MODIFIES: phantom_machine_state */
void int_f7(void);
/** MODIFIES: phantom_machine_state */
void int_f8(void);
/** MODIFIES: phantom_machine_state */
void int_f9(void);
/** MODIFIES: phantom_machine_state */
void int_fa(void);
/** MODIFIES: phantom_machine_state */
void int_fb(void);
/** MODIFIES: phantom_machine_state */
void int_fc(void);
/** MODIFIES: phantom_machine_state */
void int_fd(void);
/** MODIFIES: phantom_machine_state */
void int_fe(void);
/** MODIFIES: phantom_machine_state */
void int_ff(void);
# 15 "/host/kernel/include/arch/x86/arch/64/mode/machine.h" 2

static inline cr3_t makeCR3(paddr_t addr, word_t pcid)
{
    return cr3_new(addr, 0 ? pcid : 0);
}

/* Address space control */
static inline cr3_t getCurrentCR3(void)
{

    /* If we're running in the kernel to call this function, then by definition
     * this must be the current cr3 */
    return cr3_new(kpptr_to_paddr(x64KSKernelPML4), 0);



}

static inline cr3_t getCurrentUserCR3(void)
{

    // Construct a cr3_t from the state word, dropping any command information
    // if needed
    word_t cr3_word = x64KSCurrentUserCR3;
    cr3_t cr3_ret;
    if (0) {
        cr3_word &= ~(1ul << (63));
    }
    cr3_ret.words[0] = cr3_word;
    return cr3_ret;



}

static inline paddr_t getCurrentUserVSpaceRoot(void)
{
    return cr3_get_pml4_base_address(getCurrentUserCR3());
}

static inline void setCurrentCR3(cr3_t cr3, word_t preserve_translation)
{

    /* we should only ever be enabling the kernel window, as the bulk of the
     * cr3 loading when using the SKIM window will happen on kernel entry/exit
     * in assembly stubs */
    if(!(cr3_get_pml4_base_address(cr3) == kpptr_to_paddr(x64KSKernelPML4))) _assert_fail("cr3_get_pml4_base_address(cr3) == kpptr_to_paddr(x64KSKernelPML4)", "/host/kernel/include/arch/x86/arch/64/mode/machine.h", 61, __FUNCTION__);



    word_t cr3_word = cr3.words[0];
    if (0) {
        if (preserve_translation) {
            cr3_word |= (1ul << (63));
        }
    } else {
        if(!(cr3_get_pcid(cr3) == 0)) _assert_fail("cr3_get_pcid(cr3) == 0", "/host/kernel/include/arch/x86/arch/64/mode/machine.h", 71, __FUNCTION__);
    }
    write_cr3(cr3_word);
}

/* there is no option for preservation translation when setting the user cr3
   as it is assumed you want it preserved as you are doing a context switch.
   If translation needs to be flushed then setCurrentCR3 should be used instead */
static inline void setCurrentUserCR3(cr3_t cr3)
{

    // To make the restore stubs more efficient we will set the preserve_translation
    // command in the state. If we look at the cr3 later on we need to remember to
    // remove that bit
    word_t cr3_word = cr3.words[0];
    if (0) {
        cr3_word |= (1ul << (63));
    }
    x64KSCurrentUserCR3 = cr3_word;



}

static inline void setCurrentVSpaceRoot(paddr_t addr, word_t pcid)
{
    setCurrentCR3(makeCR3(addr, pcid), 1);
}

static inline void setCurrentUserVSpaceRoot(paddr_t addr, word_t pcid)
{

    setCurrentUserCR3(makeCR3(addr, pcid));



}

/* GDT installation */
void x64_install_gdt(gdt_idt_ptr_t *gdt_idt_ptr);

/* IDT installation */
void x64_install_idt(gdt_idt_ptr_t *gdt_idt_ptr);

/* LDT installation */
void x64_install_ldt(uint32_t ldt_sel);

/* TSS installation */
void x64_install_tss(uint32_t tss_sel);

void handle_fastsyscall(void);

void init_syscall_msrs(void);

/* Get current stack pointer */
static inline void *get_current_esp(void)
{
    word_t stack;
    void *result;
    __asm__ volatile("movq %[stack_address], %[result]" : [result] "=r"(result) : [stack_address] "r"(&stack));
    return result;
}

typedef struct invpcid_desc {
    uint64_t asid;
    uint64_t addr;
} invpcid_desc_t;






static inline void invalidateLocalPCID(word_t type, void *vaddr, asid_t asid)
{
    if (0) {
        invpcid_desc_t desc;
        desc.asid = asid & 0xfff;
        desc.addr = (uint64_t)vaddr;
        __asm__ volatile("invpcid %1, %0" :: "r"(type), "m"(desc));
    } else {
        switch (type) {
        case 0:
            __asm__ volatile("invlpg (%[vptr])" :: [vptr] "r"(vaddr));
            break;
        case 1:
        case 3:
            /* reload CR3 to perform a full flush */
            setCurrentCR3(getCurrentCR3(), 0);
            break;
        case 2 /* also invalidate global */: {
            /* clear and reset the global bit to flush global mappings */
            unsigned long cr4 = read_cr4();
            write_cr4(cr4 & ~(1ul << (7)));
            write_cr4(cr4);
        }
        break;
        }
    }
}

static inline void invalidateLocalTranslationSingle(vptr_t vptr)
{
    /* As this may be used to invalidate global mappings by the kernel,
     * and as its only used in boot code, we can just invalidate
     * absolutely everything form the tlb */
    invalidateLocalPCID(2 /* also invalidate global */, (void *)0, 0);
}

static inline void invalidateLocalTranslationSingleASID(vptr_t vptr, asid_t asid)
{
    invalidateLocalPCID(0, (void *)vptr, asid);
}

static inline void invalidateLocalTranslationAll(void)
{
    invalidateLocalPCID(2 /* also invalidate global */, (void *)0, 0);
}

static inline void invalidateLocalPageStructureCacheASID(paddr_t root, asid_t asid)
{
    if (0) {
        /* store our previous cr3 */
        cr3_t cr3 = getCurrentCR3();
        /* we load the new vspace root, invalidating translation for it
         * and then switch back to the old CR3. We do this in a single
         * asm block to ensure we only rely on the code being mapped in
         * the temporary address space and not the stack. We preserve the
         * translation of the old cr3 */
        __asm__ volatile(
            "mov %[new_cr3], %%cr3\n"
            "mov %[old_cr3], %%cr3\n"
            ::
            [new_cr3] "r"(makeCR3(root, asid).words[0]),
            [old_cr3] "r"(cr3.words[0] | (1ul << (63)))
        );
    } else {
        /* just invalidate the page structure cache as per normal, by
         * doing a dummy invalidation of a tlb entry */
        __asm__ volatile("invlpg (%[vptr])" :: [vptr] "r"(0));
    }
}

static inline void swapgs(void)
{
    __asm__ volatile("swapgs");
}

static inline rdmsr_safe_result_t x86_rdmsr_safe(const uint32_t reg)
{
    uint32_t low;
    uint32_t high;
    word_t returnto;
    word_t temp;
    rdmsr_safe_result_t result;
    __asm__ volatile(
        "movabs $1f, %[temp] \n"
        "movq %[temp], (%[returnto_addr]) \n         rdmsr \n         1: \n         movq (%[returnto_addr]), %[returnto] \n         movq $0, (%[returnto_addr])"




        : [returnto] "=&r"(returnto),
        [temp] "=&r"(temp),
        [high] "=&d"(high),
        [low] "=&a"(low)
        : [returnto_addr] "r"(&x86KSGPExceptReturnTo),
        [reg] "c"(reg)
        : "memory"
    );
    result.success = returnto != 0;
    result.value = ((uint64_t)high << 32) | (uint64_t)low;
    return result;
}
# 320 "/host/kernel/include/arch/x86/arch/64/mode/machine.h"
static inline void x86_write_gs_base_impl(word_t base)
{
    x86_wrmsr(0xC0000101, base);
}

static inline word_t x86_read_gs_base_impl(void)
{
    return x86_rdmsr(0xC0000101);
}



static inline void x86_set_tls_segment_base(word_t tls_base)
{
    x86_write_fs_base(tls_base, 0);
}
# 46 "/host/kernel/include/machine.h" 2
# 11 "/host/kernel/include/api/syscall.h" 2


# 1 "/host/kernel/include/kernel/vspace.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
       


# 1 "/host/kernel/include/arch/x86/arch/kernel/vspace.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 18 "/host/kernel/include/arch/x86/arch/kernel/vspace.h"
struct lookupPTSlot_ret {
    exception_t status;
    pte_t *ptSlot;
};
typedef struct lookupPTSlot_ret lookupPTSlot_ret_t;

struct lookupPDSlot_ret {
    exception_t status;
    pde_t *pdSlot;
};
typedef struct lookupPDSlot_ret lookupPDSlot_ret_t;

struct findVSpaceForASID_ret {
    exception_t status;
    vspace_root_t *vspace_root;
};
typedef struct findVSpaceForASID_ret findVSpaceForASID_ret_t;

void init_boot_pd(void);
void enable_paging(void);
bool_t map_kernel_window(
    uint32_t num_ioapic,
    paddr_t *ioapic_paddrs,
    uint32_t num_drhu,
    paddr_t *drhu_list
);
bool_t map_skim_window(vptr_t skim_start, vptr_t skim_end);
bool_t map_kernel_window_devices(
    pte_t *pt,
    uint32_t num_ioapic,
    paddr_t *ioapic_paddrs,
    uint32_t num_drhu,
    paddr_t *drhu_list
);

void init_tss(tss_t *tss);
void init_gdt(gdt_entry_t *gdt, tss_t *tss);
void init_idt_entry(idt_entry_t *idt, interrupt_t interrupt, void(*handler)(void));
vspace_root_t *getValidNativeRoot(cap_t vspace_cap);
pde_t *get_boot_pd(void);
void *map_temp_boot_page(void *entry, uint32_t large_pages);
bool_t init_vm_state(void);
void init_dtrs(void);
void map_it_pt_cap(cap_t vspace_cap, cap_t pt_cap);
void map_it_pd_cap(cap_t vspace_cap, cap_t pd_cap);
void map_it_frame_cap(cap_t vspace_cap, cap_t frame_cap);
void write_it_asid_pool(cap_t it_ap_cap, cap_t it_vspace_cap);
bool_t init_pat_msr(void);
cap_t create_it_address_space(cap_t root_cnode_cap, v_region_t it_v_reg);

/* ==================== BOOT CODE FINISHES HERE ==================== */

void idle_thread(void);


bool_t isVTableRoot(cap_t cap);

asid_map_t findMapForASID(asid_t asid);

lookupPTSlot_ret_t lookupPTSlot(vspace_root_t *vspace, vptr_t vptr);
lookupPDSlot_ret_t lookupPDSlot(vspace_root_t *vspace, vptr_t vptr);
void copyGlobalMappings(vspace_root_t *new_vspace);
word_t *__attribute__((__pure__)) lookupIPCBuffer(bool_t isReceiver, tcb_t *thread);
exception_t handleVMFault(tcb_t *thread, vm_fault_type_t vm_faultType);
void unmapPageDirectory(asid_t asid, vptr_t vaddr, pde_t *pd);
void unmapPageTable(asid_t, vptr_t vaddr, pte_t *pt);

exception_t performASIDPoolInvocation(asid_t asid, asid_pool_t *poolPtr, cte_t *vspaceCapSlot);
exception_t performASIDControlInvocation(void *frame, cte_t *slot, cte_t *parent, asid_t asid_base);
void hwASIDInvalidate(asid_t asid, vspace_root_t *vspace);
void deleteASIDPool(asid_t asid_base, asid_pool_t *pool);
void deleteASID(asid_t asid, vspace_root_t *vspace);
findVSpaceForASID_ret_t findVSpaceForASID(asid_t asid);

void unmapPage(vm_page_size_t page_size, asid_t asid, vptr_t vptr, void *pptr);
/* returns whether the translation was removed and needs to be flushed from the hardware (i.e. tlb) */
bool_t modeUnmapPage(vm_page_size_t page_size, vspace_root_t *vroot, vptr_t vptr, void *pptr);
exception_t decodeX86ModeMapPage(word_t invLabel, vm_page_size_t page_size, cte_t *cte, cap_t cap,
                                 vspace_root_t *vroot, vptr_t vptr, paddr_t paddr, vm_rights_t vm_rights, vm_attributes_t vm_attr);
void setVMRoot(tcb_t *tcb);
bool_t __attribute__((__const__)) isValidVTableRoot(cap_t cap);
bool_t __attribute__((__const__)) isValidNativeRoot(cap_t cap);
exception_t checkValidIPCBuffer(vptr_t vptr, cap_t cap);
vm_rights_t __attribute__((__const__)) maskVMRights(vm_rights_t vm_rights, seL4_CapRights_t cap_rights_mask);
void flushTable(vspace_root_t *vspace, word_t vptr, pte_t *pt, asid_t asid);

exception_t decodeX86MMUInvocation(word_t invLabel, word_t length, cptr_t cptr, cte_t *cte,
                                   cap_t cap, extra_caps_t excaps, word_t *buffer);

exception_t decodeX86ModeMMUInvocation(word_t invLabel, word_t length, cptr_t cptr, cte_t *cte,
                                       cap_t cap, extra_caps_t excaps, word_t *buffer);

exception_t decodeIA32PageDirectoryInvocation(word_t invLabel, word_t length, cte_t *cte, cap_t cap,
                                              extra_caps_t excaps, word_t *buffer);

/* common functions for x86 */
exception_t decodeX86FrameInvocation(word_t invLabel, word_t length, cte_t *cte, cap_t cap, extra_caps_t excaps,
                                     word_t *buffer);

uint32_t __attribute__((__const__)) WritableFromVMRights(vm_rights_t vm_rights);
uint32_t __attribute__((__const__)) SuperUserFromVMRights(vm_rights_t vm_rights);

/* the following functions have the same names, but different
 * implementations for 32-bit and 64-bit.
 */

pte_t __attribute__((__const__)) makeUserPTE(paddr_t paddr, vm_attributes_t vm_attr, vm_rights_t vm_rights);
pte_t __attribute__((__const__)) makeUserPTEInvalid(void);
pde_t __attribute__((__const__)) makeUserPDELargePage(paddr_t paddr, vm_attributes_t vm_attr, vm_rights_t vm_rights);
pde_t __attribute__((__const__)) makeUserPDEPageTable(paddr_t paddr, vm_attributes_t vm_attr);
pde_t __attribute__((__const__)) makeUserPDEInvalid(void);



void Arch_userStackTrace(tcb_t *tptr);


static inline bool_t checkVPAlignment(vm_page_size_t sz, word_t w)
{
    return (!((w) & ((1ul << (pageBitsForSize(sz)))-1ul)));
}
# 10 "/host/kernel/include/kernel/vspace.h" 2
# 14 "/host/kernel/include/api/syscall.h" 2
# 1 "kernel/gen_headers/arch/api/syscall.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */


/* This header was generated by kernel/tools/syscall_header_gen.py.
 *
 * To add a system call number, edit kernel/include/api/syscall.xml
 *
 */
# 35 "kernel/gen_headers/arch/api/syscall.h"
enum syscall {
    SysCall = -1,
    SysReplyRecv = -2,
    SysSend = -3,
    SysNBSend = -4,
    SysRecv = -5,
    SysReply = -6,
    SysYield = -7,
    SysNBRecv = -8,

    SysDebugPutChar = -9,
    SysDebugDumpScheduler = -10,


    SysDebugHalt = -11,
    SysDebugCapIdentify = -12,
    SysDebugSnapshot = -13,
    SysDebugNameThread = -14,
# 83 "kernel/gen_headers/arch/api/syscall.h"
    SysSetTLSBase = -29,

};
typedef word_t syscall_t;

/* System call names */

static char *syscall_names[] __attribute__((unused)) = {
         [1] = "Call",
         [2] = "ReplyRecv",
         [3] = "Send",
         [4] = "NBSend",
         [5] = "Recv",
         [6] = "Reply",
         [7] = "Yield",
         [8] = "NBRecv",
};
# 15 "/host/kernel/include/api/syscall.h" 2
# 1 "/host/kernel/include/api/debug.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




       

# 1 "/host/kernel/include/benchmark/benchmark_track.h" 1
/*
 * Copyright 2016, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


# 1 "/host/kernel/include/arch/x86/arch/benchmark.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 11 "/host/kernel/include/benchmark/benchmark_track.h" 2
# 1 "/host/kernel/libsel4/include/sel4/benchmark_track_types.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       




# 1 "kernel/autoconf/autoconf.h" 1
# 13 "/host/kernel/libsel4/include/sel4/benchmark_track_types.h" 2




/* the following code can be used at any point in the kernel
 * to determine detail about the kernel entry point */
typedef enum {
    Entry_Interrupt,
    Entry_UnknownSyscall,
    Entry_UserLevelFault,
    Entry_DebugFault,
    Entry_VMFault,
    Entry_Syscall,
    Entry_UnimplementedDevice,




    Entry_VMExit,

} entry_type_t;

/**
 * @brief Kernel entry logging
 *
 * Encapsulates useful info about the cause of the kernel entry
 */
typedef struct __attribute__((packed)) kernel_entry {
    seL4_Word path: 3;
    union {
        struct {
            seL4_Word core: 3;
            seL4_Word word: 26;
        };
        /* Tracked kernel entry info filled from outside this file */
        struct {
            seL4_Word syscall_no: 4;
            seL4_Word cap_type: 5;
            seL4_Word is_fastpath: 1;
            seL4_Word invocation_tag: 19;
        };
    };
} kernel_entry_t;
# 12 "/host/kernel/include/benchmark/benchmark_track.h" 2


# 1 "/host/kernel/include/kernel/cspace.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       






struct lookupCap_ret {
    exception_t status;
    cap_t cap;
};
typedef struct lookupCap_ret lookupCap_ret_t;

struct lookupCapAndSlot_ret {
    exception_t status;
    cap_t cap;
    cte_t *slot;
};
typedef struct lookupCapAndSlot_ret lookupCapAndSlot_ret_t;

struct lookupSlot_raw_ret {
    exception_t status;
    cte_t *slot;
};
typedef struct lookupSlot_raw_ret lookupSlot_raw_ret_t;

struct lookupSlot_ret {
    exception_t status;
    cte_t *slot;
};
typedef struct lookupSlot_ret lookupSlot_ret_t;

struct resolveAddressBits_ret {
    exception_t status;
    cte_t *slot;
    word_t bitsRemaining;
};
typedef struct resolveAddressBits_ret resolveAddressBits_ret_t;

lookupCap_ret_t lookupCap(tcb_t *thread, cptr_t cPtr);
lookupCapAndSlot_ret_t lookupCapAndSlot(tcb_t *thread, cptr_t cPtr);
lookupSlot_raw_ret_t lookupSlot(tcb_t *thread, cptr_t capptr);
lookupSlot_ret_t lookupSlotForCNodeOp(bool_t isSource,
                                      cap_t root, cptr_t capptr,
                                      word_t depth);
lookupSlot_ret_t lookupSourceSlot(cap_t root, cptr_t capptr,
                                  word_t depth);
lookupSlot_ret_t lookupTargetSlot(cap_t root, cptr_t capptr,
                                  word_t depth);
lookupSlot_ret_t lookupPivotSlot(cap_t root, cptr_t capptr,
                                 word_t depth);
resolveAddressBits_ret_t resolveAddressBits(cap_t nodeCap,
                                            cptr_t capptr,
                                            word_t n_bits);
# 15 "/host/kernel/include/benchmark/benchmark_track.h" 2





extern kernel_entry_t ksKernelEntry;
# 50 "/host/kernel/include/benchmark/benchmark_track.h"
static inline void benchmark_debug_syscall_start(word_t cptr, word_t msgInfo, word_t syscall)
{
    seL4_MessageInfo_t info = messageInfoFromWord_raw(msgInfo);
    lookupCapAndSlot_ret_t lu_ret = lookupCapAndSlot(ksCurThread, cptr);
    ksKernelEntry.path = Entry_Syscall;
    ksKernelEntry.syscall_no = -syscall;
    ksKernelEntry.cap_type = cap_get_capType(lu_ret.cap);
    ksKernelEntry.invocation_tag = seL4_MessageInfo_get_label(info);
}
# 13 "/host/kernel/include/api/debug.h" 2
# 1 "kernel/gen_headers/arch/api/syscall.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */


/* This header was generated by kernel/tools/syscall_header_gen.py.
 *
 * To add a system call number, edit kernel/include/api/syscall.xml
 *
 */
# 14 "/host/kernel/include/api/debug.h" 2


# 1 "/host/kernel/include/kernel/thread.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 19 "/host/kernel/include/kernel/thread.h"
static inline __attribute__((__const__)) word_t ready_queues_index(word_t dom, word_t prio)
{
    if (1 > 1) {
        return dom * 256 + prio;
    } else {
        if(!(dom == 0)) _assert_fail("dom == 0", "/host/kernel/include/kernel/thread.h", 24, __FUNCTION__);
        return prio;
    }
}

static inline __attribute__((__const__)) word_t prio_to_l1index(word_t prio)
{
    return (prio >> 6);
}

static inline __attribute__((__const__)) word_t l1index_to_prio(word_t l1index)
{
    return (l1index << 6);
}

static inline bool_t __attribute__((__pure__)) isRunnable(const tcb_t *thread)
{
    switch (thread_state_get_tsType(thread->tcbState)) {
    case ThreadState_Running:
    case ThreadState_Restart:



        return true;

    default:
        return false;
    }
}

static inline __attribute__((__const__)) word_t invert_l1index(word_t l1index)
{
    word_t inverted = (((256 + (1 << 6) - 1) / (1 << 6)) - 1 - l1index);
    if(!(inverted < ((256 + (1 << 6) - 1) / (1 << 6)))) _assert_fail("inverted < L2_BITMAP_SIZE", "/host/kernel/include/kernel/thread.h", 57, __FUNCTION__);
    return inverted;
}

static inline prio_t getHighestPrio(word_t dom)
{
    word_t l1index;
    word_t l2index;
    word_t l1index_inverted;

    /* it's undefined to call clzl on 0 */
    if(!(ksReadyQueuesL1Bitmap[dom] != 0)) _assert_fail("NODE_STATE(ksReadyQueuesL1Bitmap)[dom] != 0", "/host/kernel/include/kernel/thread.h", 68, __FUNCTION__);

    l1index = (1 << 6) - 1 - clzl(ksReadyQueuesL1Bitmap[dom]);
    l1index_inverted = invert_l1index(l1index);
    if(!(ksReadyQueuesL2Bitmap[dom][l1index_inverted] != 0)) _assert_fail("NODE_STATE(ksReadyQueuesL2Bitmap)[dom][l1index_inverted] != 0", "/host/kernel/include/kernel/thread.h", 72, __FUNCTION__);
    l2index = (1 << 6) - 1 - clzl(ksReadyQueuesL2Bitmap[dom][l1index_inverted]);
    return (l1index_to_prio(l1index) | l2index);
}

static inline bool_t isHighestPrio(word_t dom, prio_t prio)
{
    return ksReadyQueuesL1Bitmap[dom] == 0 ||
           prio >= getHighestPrio(dom);
}

static inline bool_t __attribute__((__pure__)) isBlocked(const tcb_t *thread)
{
    switch (thread_state_get_tsType(thread->tcbState)) {
    case ThreadState_BlockedOnReceive:
    case ThreadState_BlockedOnSend:
    case ThreadState_BlockedOnNotification:
    case ThreadState_BlockedOnReply:
        return true;

    default:
        return false;
    }
}

static inline bool_t __attribute__((__pure__)) isStopped(const tcb_t *thread)
{
    switch (thread_state_get_tsType(thread->tcbState)) {
    case ThreadState_Inactive:
    case ThreadState_BlockedOnReceive:
    case ThreadState_BlockedOnSend:
    case ThreadState_BlockedOnNotification:
    case ThreadState_BlockedOnReply:
        return true;

    default:
        return false;
    }
}
# 172 "/host/kernel/include/kernel/thread.h"
void configureIdleThread(tcb_t *tcb);
void activateThread(void);
void suspend(tcb_t *target);
void restart(tcb_t *target);
void doIPCTransfer(tcb_t *sender, endpoint_t *endpoint,
                   word_t badge, bool_t grant, tcb_t *receiver);



void doReplyTransfer(tcb_t *sender, tcb_t *receiver, cte_t *slot, bool_t grant);
void timerTick(void);

void doNormalTransfer(tcb_t *sender, word_t *sendBuffer, endpoint_t *endpoint,
                      word_t badge, bool_t canGrant, tcb_t *receiver,
                      word_t *receiveBuffer);
void doFaultTransfer(word_t badge, tcb_t *sender, tcb_t *receiver,
                     word_t *receiverIPCBuffer);
void doNBRecvFailedTransfer(tcb_t *thread);
void schedule(void);
void chooseThread(void);
void switchToThread(tcb_t *thread);
void switchToIdleThread(void);
void setDomain(tcb_t *tptr, dom_t dom);
void setPriority(tcb_t *tptr, prio_t prio);
void setMCPriority(tcb_t *tptr, prio_t mcp);
void scheduleTCB(tcb_t *tptr);
void possibleSwitchTo(tcb_t *tptr);
void setThreadState(tcb_t *tptr, _thread_state_t ts);
void rescheduleRequired(void);

/* declare that the thread has had its registers (in its user_context_t) modified and it
 * should ignore any 'efficient' restores next time it is run, and instead restore all
 * registers into their correct place */
void Arch_postModifyRegisters(tcb_t *tptr);

/* Updates a threads FaultIP to match its NextIP. This is used to indicate that a
 * thread has completed its fault and by updating the restartPC means that if the thread
 * should get restarted in the future for any reason it is restart in such a way as to
 * not cause the fault again. */
static inline void updateRestartPC(tcb_t *tcb)
{
    setRegister(tcb, FaultIP, getRegister(tcb, NextIP));
}
# 17 "/host/kernel/include/api/debug.h" 2



static inline void debug_printKernelEntryReason(void)
{
    kprintf("\nKernel entry via ");
    switch (ksKernelEntry.path) {
    case Entry_Interrupt:
        kprintf("Interrupt, irq %lu\n", (unsigned long) ksKernelEntry.word);
        break;
    case Entry_UnknownSyscall:
        kprintf("Unknown syscall, word: %lu", (unsigned long) ksKernelEntry.word);
        break;
    case Entry_VMFault:
        kprintf("VM Fault, fault type: %lu\n", (unsigned long) ksKernelEntry.word);
        break;
    case Entry_UserLevelFault:
        kprintf("User level fault, number: %lu", (unsigned long) ksKernelEntry.word);
        break;





    case Entry_Syscall:
        kprintf("Syscall, number: %ld, %s\n", (long) ksKernelEntry.syscall_no, syscall_names[ksKernelEntry.syscall_no]);
        if (ksKernelEntry.syscall_no == -SysSend ||
            ksKernelEntry.syscall_no == -SysNBSend ||
            ksKernelEntry.syscall_no == -SysCall) {

            kprintf("Cap type: %lu, Invocation tag: %lu\n", (unsigned long) ksKernelEntry.cap_type, (unsigned long) ksKernelEntry.invocation_tag)
                                                                ;
        }
        break;
# 61 "/host/kernel/include/api/debug.h"
    default:
        kprintf("Unknown\n");
        break;

    }
}

/* Prints the user context and stack trace of the current thread */
static inline void debug_printUserState(void)
{
    tcb_t *tptr = ksCurThread;
    kprintf("Current thread: %s\n", ((debug_tcb_t *)(((cte_t *)((word_t)(tptr)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName);
    kprintf("Next instruction adress: %lx\n", getRestartPC(tptr));
    kprintf("Stack:\n");
    Arch_userStackTrace(tptr);
}

static inline void debug_printTCB(tcb_t *tcb)
{
    kprintf("%40s\t", ((debug_tcb_t *)(((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName);
    char *state;
    switch (thread_state_get_tsType(tcb->tcbState)) {
    case ThreadState_Inactive:
        state = "inactive";
        break;
    case ThreadState_Running:
        state = "running";
        break;
    case ThreadState_Restart:
        state = "restart";
        break;
    case ThreadState_BlockedOnReceive:
        state = "blocked on recv";
        break;
    case ThreadState_BlockedOnSend:
        state = "blocked on send";
        break;
    case ThreadState_BlockedOnReply:
        state = "blocked on reply";
        break;
    case ThreadState_BlockedOnNotification:
        state = "blocked on ntfn";
        break;





    case ThreadState_IdleThreadState:
        state = "idle";
        break;
    default:
        _fail("Unknown thread state", "/host/kernel/include/api/debug.h", 113, __func__);
    }

    word_t core = 0;
    kprintf("%15s\t%p\t%20lu\t%lu", state, (void *) getRestartPC(tcb), tcb->tcbPriority, core);



    kprintf("\n");
}

static inline void debug_dumpScheduler(void)
{
    kprintf("Dumping all tcbs!\n");
    kprintf("Name                                    \tState          \tIP                  \t Prio \t Core%s\n", 0 ? "\t InReleaseQueue" : "")
                                                                     ;
    kprintf("--------------------------------------------------------------------------------------\n");
    for (tcb_t *curr = ksDebugTCBs; curr != ((void *)0); curr = ((debug_tcb_t *)(((cte_t *)((word_t)(curr)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbDebugNext) {
        debug_printTCB(curr);
    }
}
# 16 "/host/kernel/include/api/syscall.h" 2
# 32 "/host/kernel/include/api/syscall.h"
exception_t handleSyscall(syscall_t syscall);
exception_t handleInterruptEntry(void);
exception_t handleUnknownSyscall(word_t w);
exception_t handleUserLevelFault(word_t w_a, word_t w_b);
exception_t handleVMFaultEvent(vm_fault_type_t vm_faultType);

static inline word_t __attribute__((__pure__)) getSyscallArg(word_t i, word_t *ipc_buffer)
{
    if (i < n_msgRegisters) {
        return getRegister(ksCurThread, msgRegisters[i]);
    }

    if(!(ipc_buffer != ((void *)0))) _assert_fail("ipc_buffer != NULL", "/host/kernel/include/api/syscall.h", 44, __FUNCTION__);
    return ipc_buffer[i + 1];
}

extern extra_caps_t current_extra_caps;
# 11 "/host/kernel/src/api/faults.c" 2

# 1 "/host/kernel/include/arch/x86/arch/kernel/thread.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

# 1 "/host/kernel/include/object.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


# 1 "/host/kernel/include/object/objecttype.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       





# 1 "/host/kernel/include/plat/pc99/plat/machine/hardware.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

# 1 "/host/kernel/include/plat/pc99/plat/machine/interrupt.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       







# 1 "/host/kernel/include/arch/x86/arch/kernel/apic.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




# 1 "/host/kernel/include/arch/x86/arch/kernel/xapic.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       





typedef enum _apic_reg_t {
    APIC_ID = 0x020,
    APIC_VERSION = 0x030,
    APIC_TASK_PRIO = 0x080,
    APIC_ARBITR_PRIO = 0x090,
    APIC_PROC_PRIO = 0x0A0,
    APIC_EOI = 0x0B0,
    APIC_LOGICAL_DEST = 0x0D0,
    APIC_DEST_FORMAT = 0x0E0,
    APIC_SVR = 0x0F0,
    APIC_ISR_BASE = 0x100,
    APIC_TMR_BASE = 0x180,
    APIC_IRR_BASE = 0x200,
    APIC_ERR_STATUS = 0x280,
    APIC_ICR1 = 0x300,
    APIC_ICR2 = 0x310,
    APIC_LVT_TIMER = 0x320,
    APIC_LVT_THERMAL = 0x330,
    APIC_LVT_PERF_CNTR = 0x340,
    APIC_LVT_LINT0 = 0x350,
    APIC_LVT_LINT1 = 0x360,
    APIC_LVT_ERROR = 0x370,
    APIC_TIMER_COUNT = 0x380,
    APIC_TIMER_CURRENT = 0x390,
    APIC_TIMER_DIVIDE = 0x3E0
} apic_reg_t;




static inline uint32_t apic_read_reg(apic_reg_t reg)
{
    return *(volatile uint32_t *)(0xffffffffc0000000ul + reg);
}

static inline void apic_write_reg(apic_reg_t reg, uint32_t val)
{
    *(volatile uint32_t *)(0xffffffffc0000000ul + reg) = val;
}

static inline logical_id_t apic_get_logical_id(void)
{
    return apic_read_reg(APIC_LOGICAL_DEST) >> 24;
}

static inline word_t apic_get_cluster(logical_id_t logical_id)
{
    return 0; /* always return 0 as 'init_xapic_ldr' uses flat cluster */
}

static inline void apic_write_icr(word_t high, word_t low)
{
    apic_write_reg(APIC_ICR2, high);
    apic_write_reg(APIC_ICR1, low);
}
# 13 "/host/kernel/include/arch/x86/arch/kernel/apic.h" 2
# 1 "/host/kernel/include/arch/x86/arch/kernel/x2apic.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




__attribute__((__section__(".boot.text"))) bool_t x2apic_is_enabled(void);
# 14 "/host/kernel/include/arch/x86/arch/kernel/apic.h" 2

__attribute__((__section__(".boot.text"))) bool_t apic_enable(void);
__attribute__((__section__(".boot.text"))) void apic_send_init_ipi(cpu_id_t cpu_id);
__attribute__((__section__(".boot.text"))) void apic_send_startup_ipi(cpu_id_t cpu_id, paddr_t startup_addr);
__attribute__((__section__(".boot.text"))) paddr_t apic_get_base_paddr(void);
__attribute__((__section__(".boot.text"))) bool_t apic_init(bool_t mask_legacy_irqs);

uint32_t apic_read_reg(apic_reg_t reg);
void apic_write_reg(apic_reg_t reg, uint32_t val);
void apic_write_icr(word_t high, word_t low);

logical_id_t apic_get_logical_id(void);
word_t apic_get_cluster(logical_id_t logical_id);
void apic_ack_active_interrupt(void);
bool_t apic_is_interrupt_pending(void);

void apic_send_ipi_core(irq_t vector, cpu_id_t cpu_id);
void apic_send_ipi_cluster(irq_t vector, word_t mda);
# 16 "/host/kernel/include/plat/pc99/plat/machine/interrupt.h" 2

# 1 "/host/kernel/include/plat/pc99/plat/machine/acpi.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       





enum acpi_size {
    ACPI_V1_SIZE = 20,
    ACPI_V2_SIZE = 36
};

/* Generic System Descriptor Table Header */
typedef struct acpi_header {
    char signature[4];
    uint32_t length;
    uint8_t revision;
    uint8_t checksum;
    char oem_id[6];
    char oem_table_id[8];
    uint32_t oem_revision;
    char creater_id[4];
    uint32_t creater_revision;
} __attribute__((packed)) acpi_header_t;

/* Root System Descriptor Pointer */
typedef struct acpi_rsdp {
    char signature[8];
    uint8_t checksum;
    char oem_id[6];
    uint8_t revision;
    uint32_t rsdt_address;
    uint32_t length;
    uint64_t xsdt_address;
    uint8_t extended_checksum;
    char reserved[3];
} __attribute__((packed)) acpi_rsdp_t;
typedef int __assert_failed_acpi_rsdp_packed[(sizeof(acpi_rsdp_t) == ACPI_V2_SIZE) ? 1 : -1];

/* Root System Descriptor Table */
typedef struct acpi_rsdt {
    acpi_header_t header;
    uint32_t entry[1];
} __attribute__((packed)) acpi_rsdt_t;

/* Attemps to initialize acpi by searching for a valid RSDP block. If found a copy is placed in rsdp_data
 * and true is returned, otherwise the contents of rsdp_data are undefined and false is returned. */
bool_t acpi_init(acpi_rsdp_t *rsdp_data);

/* Validates that a given rsdp block is in fact valid */
__attribute__((__section__(".boot.text"))) bool_t acpi_validate_rsdp(acpi_rsdp_t *acpi_rsdp);

uint32_t acpi_madt_scan(
    acpi_rsdp_t *acpi_rsdp,
    cpu_id_t *cpu_list,
    uint32_t *num_ioapic,
    paddr_t *ioapic_addrs
);

typedef struct acpi_rmrr_entry {
    dev_id_t device;
    uint32_t base;
    uint32_t limit;
} acpi_rmrr_entry_t;

typedef struct acpi_rmrr_list {
    acpi_rmrr_entry_t entries[1];
    int num;
} acpi_rmrr_list_t;

void acpi_dmar_scan(
    acpi_rsdp_t *acpi_rsdp,
    paddr_t *drhu_list,
    uint32_t *num_drhu,
    uint32_t max_dhru_list_len,
    acpi_rmrr_list_t *rmrr_list
);

bool_t acpi_fadt_scan(
    acpi_rsdp_t *acpi_rsdp
);
# 18 "/host/kernel/include/plat/pc99/plat/machine/interrupt.h" 2
# 1 "/host/kernel/include/plat/pc99/plat/machine/ioapic.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       





void ioapic_init(uint32_t num_nodes, cpu_id_t *cpu_list, uint32_t num_ioapic);
void ioapic_mask(bool_t mask, uint32_t ioapic, uint32_t pin);

/* Checks if a pin can be mapped to an interrupt vector, returning
 * a suitable exception */
exception_t ioapic_decode_map_pin_to_vector(word_t ioapic, word_t pin, word_t level, word_t polarity, word_t vector);
/* The function maps a pin to an interrupt vector, does not perform
 * any checks, use ioapic_decode_map_pin_to_vector first */
void ioapic_map_pin_to_vector(word_t ioapic, word_t pin, word_t level, word_t polarity, word_t vector);
# 19 "/host/kernel/include/plat/pc99/plat/machine/interrupt.h" 2
# 1 "/host/kernel/include/plat/pc99/plat/machine/pic.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




/* Even if not using the PIC as the main interrupt controller we still
 * need to interact with it to remap and disable it */
void pic_remap_irqs(interrupt_t vector);
void pic_disable(void);

void pic_mask_irq(bool_t mask, irq_t irq);
bool_t pic_is_irq_pending(void);
void pic_ack_active_irq(void);
# 20 "/host/kernel/include/plat/pc99/plat/machine/interrupt.h" 2
# 1 "/host/kernel/include/plat/pc99/plat/machine/intel-vtd.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 21 "/host/kernel/include/plat/pc99/plat/machine/interrupt.h" 2

static inline void handleReservedIRQ(irq_t irq)
{
# 32 "/host/kernel/include/plat/pc99/plat/machine/interrupt.h"
    kprintf("Received unhandled reserved IRQ: %d\n", (int)irq);

}

static inline void receivePendingIRQ(void)
{
    if(!(x86KSPendingInterrupt == int_invalid)) _assert_fail("ARCH_NODE_STATE(x86KSPendingInterrupt) == int_invalid", "/host/kernel/include/plat/pc99/plat/machine/interrupt.h", 38, __FUNCTION__);
    __asm__ volatile("sti\n"
                 "nop\n"
                 "cli\n"
                 : "=m"(x86KSPendingInterrupt));
}

static inline interrupt_t servicePendingIRQ(void)
{
    if(!(x86KScurInterrupt == int_invalid)) _assert_fail("ARCH_NODE_STATE(x86KScurInterrupt) == int_invalid", "/host/kernel/include/plat/pc99/plat/machine/interrupt.h", 47, __FUNCTION__);
    if(!(x86KSPendingInterrupt != int_invalid)) _assert_fail("ARCH_NODE_STATE(x86KSPendingInterrupt) != int_invalid", "/host/kernel/include/plat/pc99/plat/machine/interrupt.h", 48, __FUNCTION__);
    interrupt_t ret = x86KSPendingInterrupt;
    x86KSPendingInterrupt = int_invalid;
    return ret;
}

/* Get the IRQ number currently working on. */
static inline irq_t getActiveIRQ(void)
{
    if (x86KScurInterrupt == int_invalid) {
        /* If we tried to get the active IRQ when we don't have one then
         * we are polling for an interrupt for some reason, in which case
         * we should try to get a pending interrupt if there isn't already
         * one.
         * This logic is here and not in the main call sites in handleSyscall
         * because this is only relevant on some interrupt controllers (notably
         * the x86 APIC) and is cleaner to have here */
        if (x86KSPendingInterrupt == int_invalid) {
            receivePendingIRQ();
            /* Check if there was no pending IRQ */
            if (x86KSPendingInterrupt == int_invalid) {
                return irqInvalid;
            }
        }
        /* Prepare to handle pending IRQ */
        x86KScurInterrupt = servicePendingIRQ();
    }
    return x86KScurInterrupt - 0x20;
}

/* Checks for pending IRQ */
static inline bool_t isIRQPending(void)
{
    if (apic_is_interrupt_pending()) {
        return true;
    }

    if (0 && pic_is_irq_pending()) {
        return true;
    }

    return false;
}

static inline void ackInterrupt(irq_t irq)
{
    if (0 && irq <= irq_isa_max) {
        pic_ack_active_irq();
    } else {
        apic_ack_active_interrupt();
    }
}

static inline void handleSpuriousIRQ(void)
{
    /* do nothing */
}

static void inline updateIRQState(irq_t irq, x86_irq_state_t state)
{
    if(!(irq <= maxIRQ)) _assert_fail("irq <= maxIRQ", "/host/kernel/include/plat/pc99/plat/machine/interrupt.h", 108, __FUNCTION__);
    x86KSIRQState[irq] = state;
}

static inline void maskInterrupt(bool_t disable, irq_t irq)
{
    if (irq >= irq_isa_min && irq <= irq_isa_max) {
        if (0) {
            pic_mask_irq(disable, irq);
        } else {
            /* We shouldn't receive interrupts on the PIC range
             * if not using the PIC, but soldier on anyway */
        }
    } else if (irq >= irq_user_min && irq <= irq_user_max) {
        x86_irq_state_t state = x86KSIRQState[irq];
        switch (x86_irq_state_get_irqType(state)) {
        case x86_irq_state_irq_ioapic: {
            uint32_t ioapic = x86_irq_state_irq_ioapic_get_id(state);
            uint32_t pin = x86_irq_state_irq_ioapic_get_pin(state);
            ioapic_mask(disable, ioapic, pin);
            state = x86_irq_state_irq_ioapic_set_masked(state, disable);
            updateIRQState(irq, state);
        }
        break;
        case x86_irq_state_irq_msi:
            /* currently MSI interrupts can not be disabled */
            break;
        case x86_irq_state_irq_free:
            /* A spurious interrupt, and the resulting mask here,
             * could be from a user ripping out a vector before
             * the interrupt reached the kernel. Silently ignore */
            break;
        }
    } else {
        /* masking some other kind of interrupt source, this probably
         * shouldn't happen, but soldier on */
    }
}
# 10 "/host/kernel/include/plat/pc99/plat/machine/hardware.h" 2

# 1 "/host/untyped_build/kernel/generated_prune/plat_mode/machine/hardware_gen.h" 1
# 12 "/host/kernel/include/plat/pc99/plat/machine/hardware.h" 2


bool_t platAddDevices(void);
# 14 "/host/kernel/include/object/objecttype.h" 2
# 1 "/host/kernel/include/object/cap.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

struct deriveCap_ret {
    exception_t status;
    cap_t cap;
};
typedef struct deriveCap_ret deriveCap_ret_t;

struct finaliseCap_ret {
    cap_t remainder;
    /* potential cap holding information for cleanup that needs to be happen *after* a
     * cap has been deleted. Where deleted here means been removed from the slot in emptySlot */
    cap_t cleanupInfo;
};
typedef struct finaliseCap_ret finaliseCap_ret_t;
# 15 "/host/kernel/include/object/objecttype.h" 2
# 1 "/host/kernel/include/arch/x86/arch/object/objecttype.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       







deriveCap_ret_t Arch_deriveCap(cte_t *slot, cap_t cap);
cap_t __attribute__((__const__)) Arch_updateCapData(bool_t preserve, word_t data, cap_t cap);
cap_t __attribute__((__const__)) Arch_maskCapRights(seL4_CapRights_t cap_rights_mask, cap_t cap);
finaliseCap_ret_t Arch_finaliseCap(cap_t cap, bool_t final);
bool_t __attribute__((__const__)) Arch_sameRegionAs(cap_t cap_a, cap_t cap_b);
bool_t __attribute__((__const__)) Arch_sameObjectAs(cap_t cap_a, cap_t cap_b);
bool_t __attribute__((__const__)) Arch_isFrameType(word_t type);
cap_t Arch_createObject(object_t t, void *regionBase, word_t userSize, bool_t deviceMemory);
exception_t Arch_decodeInvocation(word_t invLabel, word_t length, cptr_t cptr, cte_t *slot, cap_t cap,
                                  extra_caps_t excaps, bool_t call, word_t *buffer);
void Arch_prepareThreadDelete(tcb_t *thread);
word_t Arch_getObjectSize(word_t t);

/* the following functions are specific to 32-bit and 64-bit */

deriveCap_ret_t Mode_deriveCap(cte_t *slot, cap_t cap);
finaliseCap_ret_t Mode_finaliseCap(cap_t cap, bool_t final);
bool_t __attribute__((__const__)) Mode_sameRegionAs(cap_t cap_a, cap_t cap_b);
cap_t Mode_createObject(object_t t, void *regionBase, word_t userSize, bool_t deviceMemory);
exception_t Mode_decodeInvocation(word_t invLabel, word_t length, cptr_t cptr, cte_t *slot, cap_t cap,
                                  extra_caps_t excaps, word_t *buffer);
word_t Mode_getObjectSize(word_t t);

void Arch_postCapDeletion(cap_t cap);
# 16 "/host/kernel/include/object/objecttype.h" 2


deriveCap_ret_t deriveCap(cte_t *slot, cap_t cap);
finaliseCap_ret_t finaliseCap(cap_t cap, bool_t final, bool_t exposed);
bool_t __attribute__((__const__)) hasCancelSendRights(cap_t cap);
bool_t __attribute__((__const__)) sameRegionAs(cap_t cap_a, cap_t cap_b);
bool_t __attribute__((__const__)) sameObjectAs(cap_t cap_a, cap_t cap_b);
cap_t __attribute__((__const__)) updateCapData(bool_t preserve, word_t newData, cap_t cap);
cap_t __attribute__((__const__)) maskCapRights(seL4_CapRights_t seL4_CapRights, cap_t cap);
cap_t createObject(object_t t, void *regionBase, word_t, bool_t deviceMemory);
void createNewObjects(object_t t, cte_t *parent, slot_range_t slots,
                      void *regionBase, word_t userSize, bool_t deviceMemory);
# 40 "/host/kernel/include/object/objecttype.h"
exception_t decodeInvocation(word_t invLabel, word_t length,
                             cptr_t capIndex, cte_t *slot, cap_t cap,
                             extra_caps_t excaps, bool_t block, bool_t call,
                             word_t *buffer);
exception_t performInvocation_Endpoint(endpoint_t *ep, word_t badge,
                                       bool_t canGrant, bool_t canGrantReply,
                                       bool_t block, bool_t call);
exception_t performInvocation_Notification(notification_t *ntfn,
                                           word_t badge);
exception_t performInvocation_Reply(tcb_t *thread, cte_t *slot, bool_t canGrant);

word_t getObjectSize(word_t t, word_t userObjSize);

static inline void postCapDeletion(cap_t cap)
{
    if (cap_get_capType(cap) == cap_irq_handler_cap) {
        irq_t irq = (cap_irq_handler_cap_get_capIRQ(cap));
        deletedIRQHandler(irq);
    } else if (isArchCap(cap)) {
        Arch_postCapDeletion(cap);
    }
}
# 11 "/host/kernel/include/object.h" 2
# 1 "/host/kernel/include/object/notification.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




void sendSignal(notification_t *ntfnPtr, word_t badge);
void receiveSignal(tcb_t *thread, cap_t cap, bool_t isBlocking);
void cancelAllSignals(notification_t *ntfnPtr);
void cancelSignal(tcb_t *threadPtr, notification_t *ntfnPtr);
void completeSignal(notification_t *ntfnPtr, tcb_t *tcb);
void unbindMaybeNotification(notification_t *ntfnPtr);
void unbindNotification(tcb_t *tcb);
void bindNotification(tcb_t *tcb, notification_t *ntfnPtr);
# 12 "/host/kernel/include/object.h" 2

# 1 "/host/kernel/include/object/endpoint.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




static inline tcb_queue_t __attribute__((__pure__)) ep_ptr_get_queue(endpoint_t *epptr)
{
    tcb_queue_t queue;

    queue.head = (tcb_t *)endpoint_ptr_get_epQueue_head(epptr);
    queue.end = (tcb_t *)endpoint_ptr_get_epQueue_tail(epptr);

    return queue;
}
# 29 "/host/kernel/include/object/endpoint.h"
void sendIPC(bool_t blocking, bool_t do_call, word_t badge,
             bool_t canGrant, bool_t canGrantReply, tcb_t *thread,
             endpoint_t *epptr);
void receiveIPC(tcb_t *thread, cap_t cap, bool_t isBlocking);

void cancelIPC(tcb_t *tptr);
void cancelAllIPC(endpoint_t *epptr);
void cancelBadgedSends(endpoint_t *epptr, word_t badge);
void replyFromKernel_error(tcb_t *thread);
void replyFromKernel_success_empty(tcb_t *thread);
# 14 "/host/kernel/include/object.h" 2




# 1 "/host/kernel/include/object/untyped.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 16 "/host/kernel/include/object/untyped.h"
/* It is assumed that every untyped is within seL4_MinUntypedBits and seL4_MaxUntypedBits
 * (inclusive). This means that every untyped stored as seL4_MinUntypedBits
 * subtracted from its size before it is stored in capBlockSize, and
 * capFreeIndex counts in chunks of size 2^seL4_MinUntypedBits. The seL4_MaxUntypedBits
 * is the minimal untyped that can be stored when considering both how
 * many bits of capBlockSize there are, and the largest offset that can
 * be stored in capFreeIndex */







exception_t decodeUntypedInvocation(word_t invLabel, word_t length,
                                    cte_t *slot, cap_t cap,
                                    extra_caps_t excaps, bool_t call,
                                    word_t *buffer);
exception_t invokeUntyped_Retype(cte_t *srcSlot, bool_t reset,
                                 void *retypeBase, object_t newType,
                                 word_t userSize, slot_range_t destSlots,
                                 bool_t deviceMemory);
# 19 "/host/kernel/include/object.h" 2
# 10 "/host/kernel/include/arch/x86/arch/kernel/thread.h" 2

void Arch_switchToThread(tcb_t *tcb);
void Arch_switchToIdleThread(void);
void Arch_configureIdleThread(tcb_t *tcb);
void Arch_activateIdleThread(tcb_t *tcb);
word_t sanitiseRegister(register_t reg, word_t v, bool_t archInfo);

static inline bool_t __attribute__((__const__)) Arch_getSanitiseRegisterInfo(tcb_t *thread)
{
    return 0;
}

void Mode_postModifyRegisters(tcb_t *tptr);
# 13 "/host/kernel/src/api/faults.c" 2
# 1 "/host/kernel/include/machine/debug.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 14 "/host/kernel/src/api/faults.c" 2





/* consistency with libsel4 */
typedef int __assert_failed_InvalidRoot[(lookup_fault_invalid_root + 1 == seL4_InvalidRoot) ? 1 : -1];
typedef int __assert_failed_MissingCapability[(lookup_fault_missing_capability + 1 == seL4_MissingCapability) ? 1 : -1];
typedef int __assert_failed_DepthMismatch[(lookup_fault_depth_mismatch + 1 == seL4_DepthMismatch) ? 1 : -1];
typedef int __assert_failed_GuardMismatch[(lookup_fault_guard_mismatch + 1 == seL4_GuardMismatch) ? 1 : -1];
typedef int __assert_failed_seL4_UnknownSyscall_Syscall[((word_t) n_syscallMessage == seL4_UnknownSyscall_Syscall) ? 1 : -1];
typedef int __assert_failed_seL4_UserException_Number[((word_t) n_exceptionMessage == seL4_UserException_Number) ? 1 : -1];
typedef int __assert_failed_seL4_UserException_Code[((word_t) n_exceptionMessage + 1 == seL4_UserException_Code) ? 1 : -1];

static inline unsigned int
setMRs_lookup_failure(tcb_t *receiver, word_t *receiveIPCBuffer,
                      lookup_fault_t luf, unsigned int offset)
{
    word_t lufType = lookup_fault_get_lufType(luf);
    word_t i;

    i = setMR(receiver, receiveIPCBuffer, offset, lufType + 1);

    /* check constants match libsel4 */
    if (offset == seL4_CapFault_LookupFailureType) {
        if(!(offset + 1 == seL4_CapFault_BitsLeft)) _assert_fail("offset + 1 == seL4_CapFault_BitsLeft", "/host/kernel/src/api/faults.c", 39, __FUNCTION__);
        if(!(offset + 2 == seL4_CapFault_DepthMismatch_BitsFound)) _assert_fail("offset + 2 == seL4_CapFault_DepthMismatch_BitsFound", "/host/kernel/src/api/faults.c", 40, __FUNCTION__);
        if(!(offset + 2 == seL4_CapFault_GuardMismatch_GuardFound)) _assert_fail("offset + 2 == seL4_CapFault_GuardMismatch_GuardFound", "/host/kernel/src/api/faults.c", 41, __FUNCTION__);
        if(!(offset + 3 == seL4_CapFault_GuardMismatch_BitsFound)) _assert_fail("offset + 3 == seL4_CapFault_GuardMismatch_BitsFound", "/host/kernel/src/api/faults.c", 42, __FUNCTION__);
    } else {
        if(!(offset == 1)) _assert_fail("offset == 1", "/host/kernel/src/api/faults.c", 44, __FUNCTION__);
    }

    switch (lufType) {
    case lookup_fault_invalid_root:
        return i;

    case lookup_fault_missing_capability:
        return setMR(receiver, receiveIPCBuffer, offset + 1,
                     lookup_fault_missing_capability_get_bitsLeft(luf));

    case lookup_fault_depth_mismatch:
        setMR(receiver, receiveIPCBuffer, offset + 1,
              lookup_fault_depth_mismatch_get_bitsLeft(luf));
        return setMR(receiver, receiveIPCBuffer, offset + 2,
                     lookup_fault_depth_mismatch_get_bitsFound(luf));

    case lookup_fault_guard_mismatch:
        setMR(receiver, receiveIPCBuffer, offset + 1,
              lookup_fault_guard_mismatch_get_bitsLeft(luf));
        setMR(receiver, receiveIPCBuffer, offset + 2,
              lookup_fault_guard_mismatch_get_guardFound(luf));
        return setMR(receiver, receiveIPCBuffer, offset + 3,
                     lookup_fault_guard_mismatch_get_bitsFound(luf));

    default:
        _fail("Invalid lookup failure", "/host/kernel/src/api/faults.c", 70, __func__);
    }
}

static inline void copyMRsFaultReply(tcb_t *sender, tcb_t *receiver, MessageID_t id, word_t length)
{
    word_t i;
    bool_t archInfo;

    archInfo = Arch_getSanitiseRegisterInfo(receiver);

    for (i = 0; i < (((length)<(n_msgRegisters))?(length):(n_msgRegisters)); i++) {
        register_t r = fault_messages[id][i];
        word_t v = getRegister(sender, msgRegisters[i]);
        setRegister(receiver, r, sanitiseRegister(r, v, archInfo));
    }

    if (i < length) {
        word_t *sendBuf = lookupIPCBuffer(false, sender);
        if (sendBuf) {
            for (; i < length; i++) {
                register_t r = fault_messages[id][i];
                word_t v = sendBuf[i + 1];
                setRegister(receiver, r, sanitiseRegister(r, v, archInfo));
            }
        }
    }
}

static inline void copyMRsFault(tcb_t *sender, tcb_t *receiver, MessageID_t id,
                                word_t length, word_t *receiveIPCBuffer)
{
    word_t i;
    for (i = 0; i < (((length)<(n_msgRegisters))?(length):(n_msgRegisters)); i++) {
        setRegister(receiver, msgRegisters[i], getRegister(sender, fault_messages[id][i]));
    }

    if (receiveIPCBuffer) {
        for (; i < length; i++) {
            receiveIPCBuffer[i + 1] = getRegister(sender, fault_messages[id][i]);
        }
    }
}

bool_t handleFaultReply(tcb_t *receiver, tcb_t *sender)
{
    /* These lookups are moved inward from doReplyTransfer */
    seL4_MessageInfo_t tag = messageInfoFromWord(getRegister(sender, msgInfoRegister));
    word_t label = seL4_MessageInfo_get_label(tag);
    word_t length = seL4_MessageInfo_get_length(tag);
    seL4_Fault_t fault = receiver->tcbFault;

    switch (seL4_Fault_get_seL4_FaultType(fault)) {
    case seL4_Fault_CapFault:
        return true;

    case seL4_Fault_UnknownSyscall:
        copyMRsFaultReply(sender, receiver, MessageID_Syscall, (((length)<(n_syscallMessage))?(length):(n_syscallMessage)));
        return (label == 0);

    case seL4_Fault_UserException:
        copyMRsFaultReply(sender, receiver, MessageID_Exception, (((length)<(n_exceptionMessage))?(length):(n_exceptionMessage)));
        return (label == 0);
# 186 "/host/kernel/src/api/faults.c"
    default:
        return Arch_handleFaultReply(receiver, sender, seL4_Fault_get_seL4_FaultType(fault));
    }
}

word_t setMRs_fault(tcb_t *sender, tcb_t *receiver, word_t *receiveIPCBuffer)
{
    switch (seL4_Fault_get_seL4_FaultType(sender->tcbFault)) {
    case seL4_Fault_CapFault:
        setMR(receiver, receiveIPCBuffer, seL4_CapFault_IP, getRestartPC(sender));
        setMR(receiver, receiveIPCBuffer, seL4_CapFault_Addr,
              seL4_Fault_CapFault_get_address(sender->tcbFault));
        setMR(receiver, receiveIPCBuffer, seL4_CapFault_InRecvPhase,
              seL4_Fault_CapFault_get_inReceivePhase(sender->tcbFault));
        return setMRs_lookup_failure(receiver, receiveIPCBuffer,
                                     sender->tcbLookupFailure, seL4_CapFault_LookupFailureType);

    case seL4_Fault_UnknownSyscall: {
        copyMRsFault(sender, receiver, MessageID_Syscall, n_syscallMessage,
                     receiveIPCBuffer);

        return setMR(receiver, receiveIPCBuffer, n_syscallMessage,
                     seL4_Fault_UnknownSyscall_get_syscallNumber(sender->tcbFault));
    }

    case seL4_Fault_UserException: {
        copyMRsFault(sender, receiver, MessageID_Exception,
                     n_exceptionMessage, receiveIPCBuffer);
        setMR(receiver, receiveIPCBuffer, n_exceptionMessage,
              seL4_Fault_UserException_get_number(sender->tcbFault));
        return setMR(receiver, receiveIPCBuffer, n_exceptionMessage + 1u,
                     seL4_Fault_UserException_get_code(sender->tcbFault));
    }
# 256 "/host/kernel/src/api/faults.c"
    default:
        return Arch_setMRs_fault(sender, receiver, receiveIPCBuffer,
                                 seL4_Fault_get_seL4_FaultType(sender->tcbFault));
    }
}
# 1 "/host/kernel/src/api/syscall.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */


# 1 "/host/kernel/include/benchmark/benchmark.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       





# 1 "/host/kernel/libsel4/include/sel4/benchmark_tracepoints_types.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       


# 1 "kernel/autoconf/autoconf.h" 1
# 11 "/host/kernel/libsel4/include/sel4/benchmark_tracepoints_types.h" 2
# 14 "/host/kernel/include/benchmark/benchmark.h" 2
# 9 "/host/kernel/src/api/syscall.c" 2


# 1 "/host/kernel/include/benchmark/benchmark_utilisation.h" 1
/*
 * Copyright 2016, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       



# 1 "/host/kernel/libsel4/include/sel4/benchmark_utilisation_types.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       


# 1 "kernel/autoconf/autoconf.h" 1
# 11 "/host/kernel/libsel4/include/sel4/benchmark_utilisation_types.h" 2
# 12 "/host/kernel/include/benchmark/benchmark_utilisation.h" 2
# 12 "/host/kernel/src/api/syscall.c" 2




# 1 "/host/kernel/include/kernel/faulthandler.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 21 "/host/kernel/include/kernel/faulthandler.h"
exception_t sendFaultIPC(tcb_t *tptr);
void handleDoubleFault(tcb_t *tptr, seL4_Fault_t ex1);

void handleFault(tcb_t *tptr);
# 17 "/host/kernel/src/api/syscall.c" 2






# 1 "/host/kernel/include/string.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       



word_t strnlen(const char *s, word_t maxlen);
word_t strlcpy(char *dest, const char *src, word_t size);
word_t strlcat(char *dest, const char *src, word_t size);
# 24 "/host/kernel/src/api/syscall.c" 2
# 1 "/host/kernel/include/kernel/traps.h" 1
/*
 * Copyright 2016, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       



# 1 "/host/kernel/include/arch/x86/arch/kernel/traps.h" 1
/*
 * Copyright 2016, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




static inline void arch_c_entry_hook(void)
{




}

static inline void arch_c_exit_hook(void)
{
    /* Restore the values ofthe FS and GS base. */
    tcb_t *tcb = ksCurThread;
    x86_load_fsgs_base(tcb, 0);
}




void c_handle_syscall(word_t cptr, word_t msgInfo, syscall_t syscall)

__attribute__((externally_visible)) __attribute__((__noreturn__));

void restore_user_context(void)
__attribute__((externally_visible)) __attribute__((__noreturn__));

void c_nested_interrupt(int irq)
__attribute__((externally_visible));

void c_handle_interrupt(int irq, int syscall)
__attribute__((externally_visible)) __attribute__((__noreturn__));

void c_handle_vmexit(void)
__attribute__((externally_visible)) __attribute__((__noreturn__));
# 12 "/host/kernel/include/kernel/traps.h" 2
# 1 "/host/kernel/include/smp/lock.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       






# 1 "/host/kernel/include/smp/ipi.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




# 1 "/host/kernel/include/arch/x86/arch/smp/ipi.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 13 "/host/kernel/include/smp/ipi.h" 2
# 15 "/host/kernel/include/smp/lock.h" 2
# 13 "/host/kernel/include/kernel/traps.h" 2

/* This C function should be the first thing called from C after entry from
 * assembly. It provides a single place to do any entry work that is not
 * done in assembly for various reasons */
static inline void c_entry_hook(void)
{
    arch_c_entry_hook();



}

/* This C function should be the last thing called from C before exiting
 * the kernel (be it to assembly or returning to user space). It provides
 * a place to provide any additional instrumentation or functionality
 * in C before leaving the kernel */
static inline void c_exit_hook(void)
{
# 44 "/host/kernel/include/kernel/traps.h"
    arch_c_exit_hook();
}
# 25 "/host/kernel/src/api/syscall.c" 2



# 1 "/host/kernel/include/arch/x86/arch/machine/capdl.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

# 1 "/host/kernel/include/machine/capdl.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       



/* helpers */
void add_to_seen(cap_t c);
void reset_seen_list(void);
bool_t seen(cap_t c);
bool_t same_cap(cap_t a, cap_t b);
bool_t root_or_idle_tcb(tcb_t *tcb);

/* common */
void obj_tcb_print_cnodes(cap_t cnode, tcb_t *tcb);
void print_caps(void);
void print_objects(void);
void print_cap(cap_t cap);
void print_object(cap_t cap);

void obj_tcb_print_attrs(tcb_t *tcb);
void obj_sc_print_attrs(cap_t sc);
void obj_cnode_print_attrs(cap_t cnode);
void obj_ut_print_attrs(cte_t *slot, tcb_t *tcb);

void obj_tcb_print_slots(tcb_t *tcb);
void obj_cnode_print_slots(tcb_t *tcb);
void obj_irq_print_slots(cap_t irq_cap);
void obj_irq_print_maps(void);

void cap_ep_print_attrs(cap_t ep);
void cap_ntfn_print_attrs(cap_t ntfn);
void cap_cnode_print_attrs(cap_t cnode);

/* arch specific functions */
void print_ipc_buffer_slot(tcb_t *tcb);
/* TBD: currently the capDL extractor declaring an object for every entry in the vspace.
 * However, frames can be mapped into multiple locations but sould only be declared once.
 */
void obj_vtable_print_slots(tcb_t *tcb);
word_t get_tcb_sp(tcb_t *tcb);
void print_cap_arch(cap_t cap);
void print_object_arch(cap_t cap);
void obj_tcb_print_vtable(tcb_t *tcb);
# 10 "/host/kernel/include/arch/x86/arch/machine/capdl.h" 2

void x86_obj_ioports_print_attrs(cap_t ioports_cap);






void capDL(void);
# 29 "/host/kernel/src/api/syscall.c" 2


/* The haskell function 'handleEvent' is split into 'handleXXX' variants
 * for each event causing a kernel entry */

exception_t handleInterruptEntry(void)
{
    irq_t irq;

    irq = getActiveIRQ();







    if ((irq) != (irqInvalid)) {
        handleInterrupt(irq);
        Arch_finaliseInterrupt();
    } else {

        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Spurious interrupt!" ">>" "\033[0m" "\n", 0lu, __func__, 51, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);

        handleSpuriousIRQ();
    }




        schedule();
        activateThread();




    return EXCEPTION_NONE;
}

exception_t handleUnknownSyscall(word_t w)
{

    if (w == SysDebugPutChar) {
        putchar(getRegister(ksCurThread, capRegister));
        return EXCEPTION_NONE;
    }
    if (w == SysDebugDumpScheduler) {

        debug_dumpScheduler();

        return EXCEPTION_NONE;
    }


    if (w == SysDebugHalt) {
        tcb_t *__attribute__((unused)) tptr = ksCurThread;
        kprintf("Debug halt syscall from user thread %p \"%s\"\n", tptr, ((debug_tcb_t *)(((cte_t *)((word_t)(tptr)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName);
        halt();
    }
    if (w == SysDebugSnapshot) {

        tcb_t *__attribute__((unused)) tptr = ksCurThread;
        kprintf("Debug snapshot syscall from user thread %p \"%s\"\n", tptr, ((debug_tcb_t *)(((cte_t *)((word_t)(tptr)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName);
        capDL();



        return EXCEPTION_NONE;
    }
    if (w == SysDebugCapIdentify) {
        word_t cptr = getRegister(ksCurThread, capRegister);
        lookupCapAndSlot_ret_t lu_ret = lookupCapAndSlot(ksCurThread, cptr);
        word_t cap_type = cap_get_capType(lu_ret.cap);
        setRegister(ksCurThread, capRegister, cap_type);
        return EXCEPTION_NONE;
    }

    if (w == SysDebugNameThread) {
        /* This is a syscall meant to aid debugging, so if anything goes wrong
         * then assume the system is completely misconfigured and halt */
        const char *name;
        word_t len;
        word_t cptr = getRegister(ksCurThread, capRegister);
        lookupCapAndSlot_ret_t lu_ret = lookupCapAndSlot(ksCurThread, cptr);
        /* ensure we got a TCB cap */
        word_t cap_type = cap_get_capType(lu_ret.cap);
        if (cap_type != cap_thread_cap) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "SysDebugNameThread: cap is not a TCB, halting" ">>" "\033[0m" "\n", 0lu, __func__, 116, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            halt();
        }
        /* Add 1 to the IPC buffer to skip the message info word */
        name = (const char *)(lookupIPCBuffer(true, ksCurThread) + 1);
        if (!name) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "SysDebugNameThread: Failed to lookup IPC buffer, halting" ">>" "\033[0m" "\n", 0lu, __func__, 122, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            halt();
        }
        /* ensure the name isn't too long */
        len = strnlen(name, seL4_MsgMaxLength * sizeof(word_t));
        if (len == seL4_MsgMaxLength * sizeof(word_t)) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "SysDebugNameThread: Name too long, halting" ">>" "\033[0m" "\n", 0lu, __func__, 128, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            halt();
        }
        setThreadName(((tcb_t *)(cap_thread_cap_get_capTCBPtr(lu_ret.cap))), name);
        return EXCEPTION_NONE;
    }
# 312 "/host/kernel/src/api/syscall.c"
    { { if (w == SysSetTLSBase) { word_t tls_base = getRegister(ksCurThread, capRegister); /*
             * This updates the real register as opposed to the thread state
             * value. For many architectures, the TLS variables only get
             * updated on a thread switch.
             */
# 312 "/host/kernel/src/api/syscall.c"
    return Arch_setTLSRegister(tls_base); } current_fault = seL4_Fault_UnknownSyscall_new(w); handleFault(ksCurThread); } }
# 329 "/host/kernel/src/api/syscall.c"
    schedule();
    activateThread();

    return EXCEPTION_NONE;
}

exception_t handleUserLevelFault(word_t w_a, word_t w_b)
{
    { { current_fault = seL4_Fault_UserException_new(w_a, w_b); handleFault(ksCurThread); } }



    schedule();
    activateThread();

    return EXCEPTION_NONE;
}

exception_t handleVMFaultEvent(vm_fault_type_t vm_faultType)
{
    { { exception_t status = handleVMFault(ksCurThread, vm_faultType); if (status != EXCEPTION_NONE) { handleFault(ksCurThread); } } }
# 358 "/host/kernel/src/api/syscall.c"
    schedule();
    activateThread();

    return EXCEPTION_NONE;
}




static exception_t handleInvocation(bool_t isCall, bool_t isBlocking)

{
    seL4_MessageInfo_t info;
    lookupCapAndSlot_ret_t lu_ret;
    word_t *buffer;
    exception_t status;
    word_t length;
    tcb_t *thread;

    thread = ksCurThread;

    info = messageInfoFromWord(getRegister(thread, msgInfoRegister));

    cptr_t cptr = getRegister(thread, capRegister);


    /* faulting section */
    lu_ret = lookupCapAndSlot(thread, cptr);

    if (__builtin_expect(!!(lu_ret.status != EXCEPTION_NONE), 0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Invocation of invalid cap #%lu." ">>" "\033[0m" "\n", 0lu, __func__, 388, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), cptr); } while (0);
        current_fault = seL4_Fault_CapFault_new(cptr, false);

        if (isBlocking) {
            handleFault(thread);
        }

        return EXCEPTION_NONE;
    }

    buffer = lookupIPCBuffer(false, thread);

    status = lookupExtraCaps(thread, buffer, info);

    if (__builtin_expect(!!(status != EXCEPTION_NONE), 0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Lookup of extra caps failed." ">>" "\033[0m" "\n", 0lu, __func__, 403, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        if (isBlocking) {
            handleFault(thread);
        }
        return EXCEPTION_NONE;
    }

    /* Syscall error/Preemptible section */
    length = seL4_MessageInfo_get_length(info);
    if (__builtin_expect(!!(length > n_msgRegisters && !buffer), 0)) {
        length = n_msgRegisters;
    }






    status = decodeInvocation(seL4_MessageInfo_get_label(info), length,
                              cptr, lu_ret.slot, lu_ret.cap,
                              current_extra_caps, isBlocking, isCall,
                              buffer);


    if (__builtin_expect(!!(status == EXCEPTION_PREEMPTED), 0)) {
        return status;
    }

    if (__builtin_expect(!!(status == EXCEPTION_SYSCALL_ERROR), 0)) {
        if (isCall) {
            replyFromKernel_error(thread);
        }
        return EXCEPTION_NONE;
    }

    if (__builtin_expect(!!(thread_state_get_tsType(thread->tcbState) == ThreadState_Restart), 0)
                                                                             ) {
        if (isCall) {
            replyFromKernel_success_empty(thread);
        }
        setThreadState(thread, ThreadState_Running);
    }

    return EXCEPTION_NONE;
}
# 472 "/host/kernel/src/api/syscall.c"
static void handleReply(void)
{
    cte_t *callerSlot;
    cap_t callerCap;

    callerSlot = (((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbCaller));
    callerCap = callerSlot->cap;

    switch (cap_get_capType(callerCap)) {
    case cap_reply_cap: {
        tcb_t *caller;

        if (cap_reply_cap_get_capReplyMaster(callerCap)) {
            break;
        }
        caller = ((tcb_t *)(cap_reply_cap_get_capTCBPtr(callerCap)));
        /* Haskell error:
         * "handleReply: caller must not be the current thread" */
        if(!(caller != ksCurThread)) _assert_fail("caller != NODE_STATE(ksCurThread)", "/host/kernel/src/api/syscall.c", 490, __FUNCTION__);
        doReplyTransfer(ksCurThread, caller, callerSlot,
                        cap_reply_cap_get_capReplyCanGrant(callerCap));
        return;
    }

    case cap_null_cap:
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Attempted reply operation when no reply cap present." ">>" "\033[0m" "\n", 0lu, __func__, 497, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        return;

    default:
        break;
    }

    _fail("handleReply: invalid caller cap", "/host/kernel/src/api/syscall.c", 504, __func__);
}





static void handleRecv(bool_t isBlocking)

{
    word_t epCPtr;
    lookupCap_ret_t lu_ret;

    epCPtr = getRegister(ksCurThread, capRegister);

    lu_ret = lookupCap(ksCurThread, epCPtr);

    if (__builtin_expect(!!(lu_ret.status != EXCEPTION_NONE), 0)) {
        /* current_lookup_fault has been set by lookupCap */
        current_fault = seL4_Fault_CapFault_new(epCPtr, true);
        handleFault(ksCurThread);
        return;
    }

    switch (cap_get_capType(lu_ret.cap)) {
    case cap_endpoint_cap:
        if (__builtin_expect(!!(!cap_endpoint_cap_get_capCanReceive(lu_ret.cap)), 0)) {
            current_lookup_fault = lookup_fault_missing_capability_new(0);
            current_fault = seL4_Fault_CapFault_new(epCPtr, true);
            handleFault(ksCurThread);
            break;
        }
# 550 "/host/kernel/src/api/syscall.c"
        deleteCallerCap(ksCurThread);
        receiveIPC(ksCurThread, lu_ret.cap, isBlocking);

        break;

    case cap_notification_cap: {
        notification_t *ntfnPtr;
        tcb_t *boundTCB;
        ntfnPtr = ((notification_t *)(cap_notification_cap_get_capNtfnPtr(lu_ret.cap)));
        boundTCB = (tcb_t *)notification_ptr_get_ntfnBoundTCB(ntfnPtr);
        if (__builtin_expect(!!(!cap_notification_cap_get_capNtfnCanReceive(lu_ret.cap) || (boundTCB && boundTCB != ksCurThread)), 0)
                                                                          ) {
            current_lookup_fault = lookup_fault_missing_capability_new(0);
            current_fault = seL4_Fault_CapFault_new(epCPtr, true);
            handleFault(ksCurThread);
            break;
        }

        receiveSignal(ksCurThread, lu_ret.cap, isBlocking);
        break;
    }
    default:
        current_lookup_fault = lookup_fault_missing_capability_new(0);
        current_fault = seL4_Fault_CapFault_new(epCPtr, true);
        handleFault(ksCurThread);
        break;
    }
}
# 606 "/host/kernel/src/api/syscall.c"
static void handleYield(void)
{







    tcbSchedDequeue(ksCurThread);
    tcbSchedAppend(ksCurThread);
    rescheduleRequired();

}

exception_t handleSyscall(syscall_t syscall)
{
    exception_t ret;
    irq_t irq;
    { { switch (syscall) { case SysSend: ret = handleInvocation(false, true); if (__builtin_expect(!!(ret != EXCEPTION_NONE), 0)) { irq = getActiveIRQ(); if ((irq) != (irqInvalid)) { ; handleInterrupt(irq); Arch_finaliseInterrupt(); } } break; case SysNBSend: ret = handleInvocation(false, false); if (__builtin_expect(!!(ret != EXCEPTION_NONE), 0)) { irq = getActiveIRQ(); if ((irq) != (irqInvalid)) { ; handleInterrupt(irq); Arch_finaliseInterrupt(); } } break; case SysCall: ret = handleInvocation(true, true); if (__builtin_expect(!!(ret != EXCEPTION_NONE), 0)) { irq = getActiveIRQ(); if ((irq) != (irqInvalid)) { ; handleInterrupt(irq); Arch_finaliseInterrupt(); } } break; case SysRecv: handleRecv(true); break; case SysReply: handleReply(); break; case SysReplyRecv: handleReply(); handleRecv(true); break; case SysNBRecv: handleRecv(false); break; case SysYield: handleYield(); break; default: _fail("Invalid syscall", "/host/kernel/src/api/syscall.c", 737, __func__); } } }
# 739 "/host/kernel/src/api/syscall.c"
    schedule();
    activateThread();

    return EXCEPTION_NONE;
}
# 1 "/host/kernel/src/arch/x86/64/c_traps.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */



# 1 "/host/kernel/include/machine/fpu.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       




# 1 "/host/kernel/include/arch/x86/arch/machine/fpu.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 19 "/host/kernel/include/arch/x86/arch/machine/fpu.h"
/* The state format, as saved by FXSAVE and restored by FXRSTOR instructions. */
typedef struct i387_state {
    uint16_t cwd; /* control word */
    uint16_t swd; /* status word */
    uint16_t twd; /* tag word */
    uint16_t fop; /* last instruction opcode */
    uint32_t reserved[4]; /* instruction and data pointers */
    uint32_t mxcsr; /* MXCSR register state */
    uint32_t mxcsr_mask; /* MXCSR mask */
    uint32_t st_space[32]; /* FPU registers */
    uint32_t xmm_space[64]; /* XMM registers */
    uint32_t padding[13];
} __attribute__((packed)) i387_state_t;

/* The state format, as saved by XSAVE and restored by XRSTOR instructions. */
typedef struct xsave_state {
    i387_state_t i387;
    struct {
        uint64_t xfeatures;
        uint64_t xcomp_bv; /* state-component bitmap */
        uint64_t reserved[6];
    } header;
} __attribute__((packed)) xsave_state_t;

/* Initialise the FPU. */
bool_t Arch_initFpu(void);

/* Initialise the FPU state of the given user context. */
void Arch_initFpuContext(user_context_t *context);

static inline uint32_t xsave_features_high(void)
{
    uint64_t features = 1;
    return (uint32_t)(features >> 32);
}

static inline uint32_t xsave_features_low(void)
{
    uint64_t features = 1;
    return (uint32_t)(features & 0xffffffff);
}

/* Store state in the FPU registers into memory. */
static inline void saveFpuState(user_fpu_state_t *dest)
{
    if (1) {
        __asm__ volatile("fxsave %[dest]" : [dest] "=m"(*dest));
    } else if (0) {
        __asm__ volatile("xsaveopt %[dest]" : [dest] "=m"(*dest) : "d"(xsave_features_high()), "a"(xsave_features_low()));
    } else if (0) {
        __asm__ volatile("xsave %[dest]" : [dest] "=m"(*dest) : "d"(xsave_features_high()), "a"(xsave_features_low()));
    } else if (0) {
        __asm__ volatile("xsavec %[dest]" : [dest] "=m"(*dest) : "d"(xsave_features_high()), "a"(xsave_features_low()));
    } else if (0) {
        __asm__ volatile("xsaves %[dest]" : [dest] "=m"(*dest) : "d"(xsave_features_high()), "a"(xsave_features_low()));
    }
}

/* Load FPU state from memory into the FPU registers. */
static inline void loadFpuState(user_fpu_state_t *src)
{
    if (1) {
        __asm__ volatile("fxrstor %[src]" :: [src] "m"(*src));
    } else if (0) {
        if (0) {
            __asm__ volatile("xrstors %[src]" :: [src] "m"(*src), "d"(xsave_features_high()), "a"(xsave_features_low()));
        } else {
            __asm__ volatile("xrstor %[src]" :: [src] "m"(*src), "d"(xsave_features_high()), "a"(xsave_features_low()));
        }
    }
}

/* Reset the FPU registers into their initial blank state. */
static inline void finit(void)
{
    __asm__ volatile("finit" :: "m"(control_reg_order));
}

/*
 * Enable the FPU to be used without faulting.
 * Required even if the kernel attempts to use the FPU.
 */
static inline void enableFpu(void)
{
    __asm__ volatile("clts" :: "m"(control_reg_order));
}

/*
 * Disable the FPU so that usage of it causes a fault
 */
static inline void disableFpu(void)
{
    write_cr0(read_cr0() | (1ul << (3)) /* Trap on any FPU usage, for lazy FPU. */);
}
# 13 "/host/kernel/include/machine/fpu.h" 2



/* Perform any actions required for the deletion of the given thread. */
void fpuThreadDelete(tcb_t *thread);

/* Handle an FPU exception. */
exception_t handleFPUFault(void);

void switchLocalFpuOwner(user_fpu_state_t *new_owner);

/* Switch the current owner of the FPU state on the core specified by 'cpu'. */
void switchFpuOwner(user_fpu_state_t *new_owner, word_t cpu);

/* Returns whether or not the passed thread is using the current active fpu state */
static inline bool_t nativeThreadUsingFPU(tcb_t *thread)
{
    return &thread->tcbArch.tcbContext.fpuState ==
           ksActiveFPUState;
}

static inline void __attribute__((always_inline)) lazyFPURestore(tcb_t *thread)
{
    if (__builtin_expect(!!(ksActiveFPUState), 0)) {
        /* If we have enabled/disabled the FPU too many times without
         * someone else trying to use it, we assume it is no longer
         * in use and switch out its state. */
        if (__builtin_expect(!!(ksFPURestoresSinceSwitch > 64), 0)) {
            switchLocalFpuOwner(((void *)0));
            ksFPURestoresSinceSwitch = 0;
        } else {
            if (__builtin_expect(!!(nativeThreadUsingFPU(thread)), 1)) {
                /* We are using the FPU, make sure it is enabled */
                enableFpu();
            } else {
                /* Someone is using the FPU and it might be enabled */
                disableFpu();
            }
            ksFPURestoresSinceSwitch++;
        }
    } else {
        /* No-one (including us) is using the FPU, so we assume it
         * is currently disabled */
    }
}
# 10 "/host/kernel/src/arch/x86/64/c_traps.c" 2

# 1 "/host/kernel/include/arch/x86/arch/machine/debug.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 12 "/host/kernel/src/arch/x86/64/c_traps.c" 2
# 1 "/host/kernel/include/kernel/stack.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       



# 1 "/host/kernel/include/arch/x86/arch/64/mode/kernel/stack.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 12 "/host/kernel/include/kernel/stack.h" 2

/* These are the stacks used in kernel, shared between architectures/modes.
 * CONFIG_KERNEL_STACK_BITS is defined in kernel/Kconfig. The physical/offset
 * address of the stack is per-arch-mode aligned. KERNEL_STACK_ALIGNMENT is
 * defined for each arch/mode in <mode/kernel/stack.h>
 */
extern char kernel_stack_alloc[1][(1ul << (12))];
# 13 "/host/kernel/src/arch/x86/64/c_traps.c" 2
# 129 "/host/kernel/src/arch/x86/64/c_traps.c"
void __attribute__((externally_visible)) __attribute__((__noreturn__)) restore_user_context(void)
{
    do {} while (0);
    c_exit_hook();

    /* we've now 'exited' the kernel. If we have a pending interrupt
     * we should 'enter' it again */
    if (x86KSPendingInterrupt != int_invalid) {
        interrupt_t irq = servicePendingIRQ();
        /* reset our stack and jmp to the IRQ entry point */
        __asm__ volatile(
            "movq %[stack_top], %%rsp\n"
            "movq %[syscall], %%rsi\n"
            "movq %[irq], %%rdi\n"
            "call c_handle_interrupt"
            :
            : [stack_top] "r"(&(kernel_stack_alloc[0][(1ul << (12))])),
            [syscall] "i"(0), /* syscall is unused for irq path */
            [irq] "r"((seL4_Word)irq)
            : "memory");
        __builtin_unreachable();
    }

    tcb_t *cur_thread = ksCurThread;
    word_t *irqstack = x64KSIRQStack[0];





    lazyFPURestore(cur_thread);
# 172 "/host/kernel/src/arch/x86/64/c_traps.c"
    if (0) {
        x86_disable_ibrs();
    }

    // Check if we are returning from a syscall/sysenter or from an interrupt
    // There is a special case where if we would be returning from a sysenter,
    // but are current singlestepping, do a full return like an interrupt
    if (__builtin_expect(!!(cur_thread->tcbArch.tcbContext.registers[Error] == -1), 1) &&
        (!0 || !0
         || ((cur_thread->tcbArch.tcbContext.registers[FLAGS] & (1ul << (8)) /* Trap Flag */) == 0))) {
        if (1) {
            /* if we are using the SKIM window then we are trying to hide kernel state from
             * the user in the case of Meltdown where the kernel region is effectively readable
             * by the user. To prevent a storage channel across threads through the irq stack,
             * which is idirectly controlled by the user, we need to clear the stack. We perform
             * this here since when we return *from* an interrupt we must use this stack and
             * cannot clear it. This means if we restore from interrupt, then enter from a syscall
             * and switch to a different thread we must either on syscall entry, or before leaving
             * the kernel, clear the irq stack. */
            irqstack[0] = 0;
            irqstack[1] = 0;
            irqstack[2] = 0;
            irqstack[3] = 0;
            irqstack[4] = 0;
            irqstack[5] = 0;
        }
        if (0) {
            cur_thread->tcbArch.tcbContext.registers[FLAGS] &= ~(1ul << (9)) /* Interrupt enable Flag */;



            __asm__ volatile(
                // Set our stack pointer to the top of the tcb so we can efficiently pop
                "movq %0, %%rsp\n"
                "popq %%rdi\n"
                "popq %%rsi\n"
                "popq %%rax\n"
                "popq %%rbx\n"
                "popq %%rbp\n"
                "popq %%r12\n"
                "popq %%r13\n"
                "popq %%r14\n"
                // skip RDX
                "addq $8, %%rsp\n"
                "popq %%r10\n"
                "popq %%r8\n"
                "popq %%r9\n"
                "popq %%r15\n"
                //restore RFLAGS
                "popfq\n"
                // reset interrupt bit
                "orq %[IF], -8(%%rsp)\n"
                // Restore NextIP
                "popq %%rdx\n"
                // Skip ERROR
                "addq $8, %%rsp\n"
                // Restore RSP
                "popq %%rcx\n"
                // Skip FaultIP
                "addq $8, %%rsp\n"





                "popq %%r11\n"

                "movq (x64KSCurrentUserCR3), %%rsp\n"
                "movq %%rsp, %%cr3\n"


                // More register but we can ignore and are done restoring
                // enable interrupt disabled by sysenter
                "sti\n"
                /* Return to user.
                 *
                 * SYSEXIT  0F 35     ; Return to compatibility mode from fast system call.
                 * SYSEXITQ 48 0F 35  ; Return to 64-bit mode from fast system call.
                 * */
                "sysexitq\n"
                :
                : "r"(&cur_thread->tcbArch.tcbContext.registers[RDI]),



                [IF] "i"((1ul << (9)) /* Interrupt enable Flag */)
                // Clobber memory so the compiler is forced to complete all stores
                // before running this assembler
                : "memory"
            );
        } else {
            __asm__ volatile(
                // Set our stack pointer to the top of the tcb so we can efficiently pop
                "movq %0, %%rsp\n"
                "popq %%rdi\n"
                "popq %%rsi\n"
                "popq %%rax\n"
                "popq %%rbx\n"
                "popq %%rbp\n"
                "popq %%r12\n"
                "popq %%r13\n"
                "popq %%r14\n"
                "popq %%rdx\n"
                "popq %%r10\n"
                "popq %%r8\n"
                "popq %%r9\n"
                "popq %%r15\n"
                //restore RFLAGS
                "popq %%r11\n"
                // Restore NextIP





                "popq %%rcx\n"

                "movq (x64KSCurrentUserCR3), %%rsp\n"
                "movq %%rsp, %%cr3\n"


                // clear RSP to not leak information to the user
                "xor %%rsp, %%rsp\n"
                // More register but we can ignore and are done restoring
                // enable interrupt disabled by sysenter
                "sysretq\n"
                :
                : "r"(&cur_thread->tcbArch.tcbContext.registers[RDI])



                // Clobber memory so the compiler is forced to complete all stores
                // before running this assembler
                : "memory"
            );
        }
    } else {
        /* construct our return from interrupt frame */

        /* Have to zero this to prevent storage channel */
        irqstack[0] = 0;

        irqstack[1] = getRegister(cur_thread, NextIP);
        irqstack[2] = getRegister(cur_thread, CS);
        irqstack[3] = getRegister(cur_thread, FLAGS);
        irqstack[4] = getRegister(cur_thread, RSP);
        irqstack[5] = getRegister(cur_thread, SS);
        __asm__ volatile(
            // Set our stack pointer to the top of the tcb so we can efficiently pop
            "movq %0, %%rsp\n"
            "popq %%rdi\n"
            "popq %%rsi\n"
            "popq %%rax\n"
            "popq %%rbx\n"
            "popq %%rbp\n"
            "popq %%r12\n"
            "popq %%r13\n"
            "popq %%r14\n"
            "popq %%rdx\n"
            "popq %%r10\n"
            "popq %%r8\n"
            "popq %%r9\n"
            "popq %%r15\n"
            /* skip RFLAGS, Error, NextIP, RSP, and FaultIP */
            "addq $40, %%rsp\n"
            "popq %%r11\n"






            "popq %%rcx\n"
# 368 "/host/kernel/src/arch/x86/64/c_traps.c"
            "movq (x64KSCurrentUserCR3), %%rsp\n"
            "movq %%rsp, %%cr3\n"

            "leaq x64KSIRQStack + 8, %%rsp\n"

            "iretq\n"
            :
            : "r"(&cur_thread->tcbArch.tcbContext.registers[RDI])




            // Clobber memory so the compiler is forced to complete all stores
            // before running this assembler
            : "memory"
        );
    }
    __builtin_unreachable();
}

void __attribute__((externally_visible)) __attribute__((__noreturn__)) c_x64_handle_interrupt(int irq, int syscall);
void __attribute__((externally_visible)) __attribute__((__noreturn__)) c_x64_handle_interrupt(int irq, int syscall)
{
    if (0) {
        x86_enable_ibrs();
    }
    word_t *irq_stack = x64KSIRQStack[0];
    setRegister(ksCurThread, Error, irq_stack[0]);
    /* In the case of an interrupt the NextIP and the FaultIP should be the same value,
     * i.e. the address of the instruction the CPU was about to execute before the
     * interrupt. This is the 5th value pushed on by the hardware, so indexing from
     * the bottom is x64KSIRQStack[1] */
    setRegister(ksCurThread, NextIP, irq_stack[1]);
    setRegister(ksCurThread, FaultIP, irq_stack[1]);
    setRegister(ksCurThread, FLAGS, irq_stack[3]);
    setRegister(ksCurThread, RSP, irq_stack[4]);
    c_handle_interrupt(irq, syscall);
    __builtin_unreachable();
}
# 1 "/host/kernel/src/arch/x86/64/kernel/elf.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

# 1 "/host/kernel/include/arch/x86/arch/kernel/elf.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


# 1 "/host/kernel/include/arch/x86/arch/64/mode/kernel/elf.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       



/* minimal ELF structures needed for loading GRUB boot module */
typedef struct Elf64_Header {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Header_t, Elf_Header_t;

typedef struct Elf64_Phdr {
    uint32_t p_type;
    uint32_t p_flags;
    uint64_t p_offset;
    uint64_t p_vaddr;
    uint64_t p_paddr;
    uint64_t p_filesz;
    uint64_t p_memsz;
    uint64_t p_align;
} Elf64_Phdr_t, Elf_Phdr_t;
# 11 "/host/kernel/include/arch/x86/arch/kernel/elf.h" 2

/* minimal ELF functionality for loading GRUB boot module */
bool_t elf_checkFile(Elf_Header_t *elfFile);
v_region_t elf_getMemoryBounds(Elf_Header_t *elfFile);
void elf_load(Elf_Header_t *elfFile, seL4_Word offset);
# 8 "/host/kernel/src/arch/x86/64/kernel/elf.c" 2


__attribute__((__section__(".boot.text"))) bool_t elf_checkFile(Elf64_Header_t *elf)
{
    return (
               elf->e_ident[0] == '\177' &&
               elf->e_ident[1] == 'E' &&
               elf->e_ident[2] == 'L' &&
               elf->e_ident[3] == 'F' &&
               elf->e_ident[4] == 2
           );
}


__attribute__((__section__(".boot.text"))) v_region_t elf_getMemoryBounds(Elf64_Header_t *elf)
{
    v_region_t elf_reg;
    vptr_t sect_start;
    vptr_t sect_end;
    uint32_t i;
    Elf64_Phdr_t *phdr = (Elf64_Phdr_t *)((paddr_t)elf + elf->e_phoff);

    elf_reg.start = 0x7fffffffffffffffUL;
    elf_reg.end = 0;

    for (i = 0; i < elf->e_phnum; i++) {
        if (phdr[i].p_memsz > 0) {
            sect_start = phdr[i].p_vaddr;
            sect_end = sect_start + phdr[i].p_memsz;
            if (sect_start < elf_reg.start) {
                elf_reg.start = sect_start;
            }
            if (sect_end > elf_reg.end) {
                elf_reg.end = sect_end;
            }
        }
    }

    return elf_reg;
}

__attribute__((__section__(".boot.text"))) void elf_load(Elf64_Header_t *elf, seL4_Word offset)
{
    paddr_t src;
    paddr_t dst;
    uint64_t len;
    uint32_t i;
    Elf64_Phdr_t *phdr = (Elf64_Phdr_t *)((paddr_t)elf + elf->e_phoff);

    for (i = 0; i < elf->e_phnum; i++) {
        src = (paddr_t)elf + phdr[i].p_offset;
        dst = phdr[i].p_vaddr + offset;
        len = phdr[i].p_filesz;
        memcpy((void *)dst, (char *)src, len);
        dst += len;
        memset((void *)dst, 0, phdr[i].p_memsz - len);
    }
}
# 1 "/host/kernel/src/arch/x86/64/kernel/thread.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 14 "/host/kernel/src/arch/x86/64/kernel/thread.c"
void Arch_switchToThread(tcb_t *tcb)
{
    /* set PD */
    setVMRoot(tcb);






    if (0) {
        x86_ibpb();
    }

    if (0) {
        x86_flush_rsb();
    }
}

__attribute__((__section__(".boot.text"))) void Arch_configureIdleThread(tcb_t *tcb)
{
    setRegister(tcb, FLAGS, (1ul << (9)) /* Interrupt enable Flag */ | (1ul << (1)) /* Bits in the FLAGS register that must be high */);
    setRegister(tcb, NextIP, (uint64_t)(&idle_thread));
    setRegister(tcb, CS, (1 << 3));
    setRegister(tcb, SS, (2 << 3));
    /* We set the RSP to 0, even though the idle thread will never touch it, as it
     * allows us to distinguish an interrupt from the idle thread from an interrupt
     * from kernel execution, just by examining the saved RSP value (since the kernel
     * thread will have a valid RSP, and never 0). See traps.S for the other side of this
     */
    setRegister(tcb, RSP, 0);
}

void Arch_switchToIdleThread(void)
{
    tcb_t *tcb = ksIdleThread;
    /* Force the idle thread to run on kernel page table */
    setVMRoot(tcb);






}

void Arch_activateIdleThread(tcb_t *tcb)
{
    /* Don't need to do anything */
}

void Mode_postModifyRegisters(tcb_t *tptr)
{
    /* Setting Error to 0 will force a return by the interrupt path, which
     * does a full restore. Unless we're the current thread, in which case
     * we still have to go back out via a sysret */
    if (tptr != ksCurThread) {
        setRegister(tptr, Error, 0);
    }
}
# 1 "/host/kernel/src/arch/x86/64/kernel/vspace.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




# 1 "/host/kernel/include/kernel/boot.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 1 "/host/kernel/include/bootinfo.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       



# 1 "/host/kernel/libsel4/include/sel4/bootinfo_types.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       


# 1 "kernel/autoconf/autoconf.h" 1
# 11 "/host/kernel/libsel4/include/sel4/bootinfo_types.h" 2


/* caps with fixed slot positions in the root CNode */

enum {
    seL4_CapNull = 0, /* null cap */
    seL4_CapInitThreadTCB = 1, /* initial thread's TCB cap */
    seL4_CapInitThreadCNode = 2, /* initial thread's root CNode cap */
    seL4_CapInitThreadVSpace = 3, /* initial thread's VSpace cap */
    seL4_CapIRQControl = 4, /* global IRQ controller cap */
    seL4_CapASIDControl = 5, /* global ASID controller cap */
    seL4_CapInitThreadASIDPool = 6, /* initial thread's ASID pool cap */
    seL4_CapIOPortControl = 7, /* global IO port control cap (null cap if not supported) */
    seL4_CapIOSpace = 8, /* global IO space cap (null cap if no IOMMU support) */
    seL4_CapBootInfoFrame = 9, /* bootinfo frame cap */
    seL4_CapInitThreadIPCBuffer = 10, /* initial thread's IPC buffer frame cap */
    seL4_CapDomain = 11, /* global domain controller cap */




    seL4_NumInitialCaps = 12

};

/* Legacy code will have assumptions on the vspace root being a Page Directory
 * type, so for now we define one to the other */


/* types */
typedef seL4_Word seL4_SlotPos;

typedef struct seL4_SlotRegion {
    seL4_SlotPos start; /* first CNode slot position OF region */
    seL4_SlotPos end; /* first CNode slot position AFTER region */
} seL4_SlotRegion;

typedef struct seL4_UntypedDesc {
    seL4_Word paddr; /* physical address of untyped cap  */
    seL4_Uint8 sizeBits;/* size (2^n) bytes of each untyped */
    seL4_Uint8 isDevice;/* whether the untyped is a device  */
    seL4_Uint8 padding[sizeof(seL4_Word) - 2 * sizeof(seL4_Uint8)];
} seL4_UntypedDesc;

typedef struct seL4_BootInfo {
    seL4_Word extraLen; /* length of any additional bootinfo information */
    seL4_NodeId nodeID; /* ID [0..numNodes-1] of the seL4 node (0 if uniprocessor) */
    seL4_Word numNodes; /* number of seL4 nodes (1 if uniprocessor) */
    seL4_Word numIOPTLevels; /* number of IOMMU PT levels (0 if no IOMMU support) */
    seL4_IPCBuffer *ipcBuffer; /* pointer to initial thread's IPC buffer */
    seL4_SlotRegion empty; /* empty slots (null caps) */
    seL4_SlotRegion sharedFrames; /* shared-frame caps (shared between seL4 nodes) */
    seL4_SlotRegion userImageFrames; /* userland-image frame caps */
    seL4_SlotRegion userImagePaging; /* userland-image paging structure caps */
    seL4_SlotRegion ioSpaceCaps; /* IOSpace caps for ARM SMMU */
    seL4_SlotRegion extraBIPages; /* caps for any pages used to back the additional bootinfo information */
    seL4_Word initThreadCNodeSizeBits; /* initial thread's root CNode size (2^n slots) */
    seL4_Domain initThreadDomain; /* Initial thread's domain ID */



    seL4_SlotRegion untyped; /* untyped-object caps (untyped caps) */
    seL4_UntypedDesc untypedList[230]; /* information about each untyped */
    /* the untypedList should be the last entry in this struct, in order
     * to make this struct easier to represent in other languages */
} seL4_BootInfo;

/* If extraLen > 0 then 4K after the start of bootinfo is a region of extraLen additional
 * bootinfo structures. Bootinfo structures are arch/platform specific and may or may not
 * exist in any given execution. */
typedef struct seL4_BootInfoHeader {
    /* identifier of the following chunk. IDs are arch/platform specific */
    seL4_Word id;
    /* length of the chunk, including this header */
    seL4_Word len;
} seL4_BootInfoHeader;

/* Bootinfo identifiers share a global namespace, even if they are arch or platform specific
 * and are enumerated here */
# 12 "/host/kernel/include/bootinfo.h" 2






/* adjust constants in config.h if this assert fails */
typedef int __assert_failed_bi_size[(sizeof(seL4_BootInfo) <= (1ul << (12))) ? 1 : -1];
# 9 "/host/kernel/include/kernel/boot.h" 2
# 1 "/host/kernel/include/arch/x86/arch/bootinfo.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       



/*
 * The maximum number of reserved regions we have is:
 * - 1 for each physical memory region (MAX_NUM_FREEMEM_REG)
 * - 1 for each kernel device:
 *      - ioapics (CONFIG_MAX_NUM_IOAPIC)
 *      - iommus (MAX_NUM_DRHU)
 *      - apic (1)
 *      - the reserved MSI region (1)
 */
# 10 "/host/kernel/include/kernel/boot.h" 2
# 21 "/host/kernel/include/kernel/boot.h"
/*
 * Resolve naming differences between the abstract specifications
 * of the bootstrapping phase and the runtime phase of the kernel.
 */
typedef cte_t slot_t;
typedef cte_t *slot_ptr_t;



/* (node-local) state accessed only during bootstrapping */

typedef struct ndks_boot {
    p_region_t reserved[(16 + 1 + ((-((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1)) >> 12) + 2)];
    word_t resv_count;
    region_t freemem[16];
    seL4_BootInfo *bi_frame;
    seL4_SlotPos slot_pos_cur;
    seL4_SlotPos slot_pos_max;
} ndks_boot_t;

extern ndks_boot_t ndks_boot;

/* function prototypes */

static inline bool_t is_reg_empty(region_t reg)
{
    return reg.start == reg.end;
}

void init_freemem(word_t n_available, const p_region_t *available,
                  word_t n_reserved, region_t *reserved,
                  v_region_t it_v_reg, word_t extra_bi_size_bits);
bool_t reserve_region(p_region_t reg);
bool_t insert_region(region_t reg);
void write_slot(slot_ptr_t slot_ptr, cap_t cap);
cap_t create_root_cnode(void);
bool_t provide_cap(cap_t root_cnode_cap, cap_t cap);
cap_t create_it_asid_pool(cap_t root_cnode_cap);
void write_it_pd_pts(cap_t root_cnode_cap, cap_t it_pd_cap);
bool_t create_idle_thread(void);
bool_t create_untypeds_for_region(cap_t root_cnode_cap, bool_t device_memory, region_t reg,
                                  seL4_SlotPos first_untyped_slot);
bool_t create_device_untypeds(cap_t root_cnode_cap, seL4_SlotPos slot_pos_before);
bool_t create_kernel_untypeds(cap_t root_cnode_cap, region_t boot_mem_reuse_reg, seL4_SlotPos first_untyped_slot);
void bi_finalise(void);
void create_domain_cap(cap_t root_cnode_cap);

cap_t create_ipcbuf_frame_cap(cap_t root_cnode_cap, cap_t pd_cap, vptr_t vptr);
word_t calculate_extra_bi_size_bits(word_t extra_size);
void populate_bi_frame(node_id_t node_id, word_t num_nodes, vptr_t ipcbuf_vptr,
                       word_t extra_bi_size_bits);
void create_bi_frame_cap(cap_t root_cnode_cap, cap_t pd_cap, vptr_t vptr);





typedef struct create_frames_of_region_ret {
    seL4_SlotRegion region;
    bool_t success;
} create_frames_of_region_ret_t;

create_frames_of_region_ret_t
create_frames_of_region(
    cap_t root_cnode_cap,
    cap_t pd_cap,
    region_t reg,
    bool_t do_map,
    sword_t pv_offset
);

cap_t
create_it_pd_pts(
    cap_t root_cnode_cap,
    v_region_t ui_v_reg,
    vptr_t ipcbuf_vptr,
    vptr_t bi_frame_vptr
);

tcb_t *
create_initial_thread(
    cap_t root_cnode_cap,
    cap_t it_pd_cap,
    vptr_t ui_v_entry,
    vptr_t bi_frame_vptr,
    vptr_t ipcbuf_vptr,
    cap_t ipcbuf_cap
);

void init_core_state(tcb_t *scheduler_action);

/* state tracking the memory allocated for root server objects */
typedef struct {
    pptr_t cnode;
    pptr_t vspace;
    pptr_t asid_pool;
    pptr_t ipc_buf;
    pptr_t boot_info;
    pptr_t extra_bi;
    pptr_t tcb;



    region_t paging;
} rootserver_mem_t;

extern rootserver_mem_t rootserver;

/* get the number of paging structures required to cover it_v_reg, with
 * the paging structure covering `bits` of the address range - for a 4k page
 * `bits` would be 12 */
static inline __attribute__((__section__(".boot.text"))) word_t get_n_paging(v_region_t v_reg, word_t bits)
{
    vptr_t start = (((v_reg.start) >> (bits)) << (bits));
    vptr_t end = (((((v_reg.end) - 1ul) >> (bits)) + 1ul) << (bits));
    return (end - start) / (1ul << (bits));
}

/* allocate a page table sized structure from rootserver.paging */
static inline __attribute__((__section__(".boot.text"))) pptr_t it_alloc_paging(void)
{
    pptr_t allocated = rootserver.paging.start;
    rootserver.paging.start += (1ul << (12));
    if(!(rootserver.paging.start <= rootserver.paging.end)) _assert_fail("rootserver.paging.start <= rootserver.paging.end", "/host/kernel/include/kernel/boot.h", 144, __FUNCTION__);
    return allocated;
}

/* return the amount of paging structures required to cover v_reg */
word_t arch_get_n_paging(v_region_t it_veg);

/* Create pptrs for all root server objects, starting at pptr, to cover the
 * virtual memory region v_reg, and any extra boot info. */
void create_rootserver_objects(pptr_t start, v_region_t v_reg, word_t extra_bi_size_bits);
# 11 "/host/kernel/src/arch/x86/64/kernel/vspace.c" 2


# 1 "/host/kernel/include/arch/x86/arch/kernel/boot.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       





# 1 "/host/kernel/libsel4/arch_include/x86/sel4/arch/bootinfo_types.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       




typedef struct seL4_VBEInfoBlock {
    char signature[4];
    seL4_Uint16 version;
    seL4_Uint32 oemStringPtr;
    seL4_Uint32 capabilities;
    seL4_Uint32 modeListPtr;
    seL4_Uint16 totalMemory;
    seL4_Uint16 oemSoftwareRev;
    seL4_Uint32 oemVendorNamePtr;
    seL4_Uint32 oemProductNamePtr;
    seL4_Uint32 oemProductRevPtr;
    seL4_Uint8 reserved[222];
    seL4_Uint8 oemData[256];
} __attribute__((packed)) seL4_VBEInfoBlock_t;

/* the seL4_VBEModeInfoBlock struct is split into multiple parts to aid the C parser */
typedef struct seL4_VBEModeInfoCommon {
    seL4_Uint16 modeAttr;
    seL4_Uint8 winAAttr;
    seL4_Uint8 winBAttr;
    seL4_Uint16 winGranularity;
    seL4_Uint16 winSize;
    seL4_Uint16 winASeg;
    seL4_Uint16 winBSeg;
    seL4_Uint32 winFuncPtr;
    seL4_Uint16 bytesPerScanLine;
} __attribute__((packed)) seL4_VBEModeInfoCommon_t;

typedef struct seL4_VBEInfo12Part1 {
    seL4_Uint16 xRes;
    seL4_Uint16 yRes;
    seL4_Uint8 xCharSize;
    seL4_Uint8 yCharSize;
    seL4_Uint8 planes;
    seL4_Uint8 bitsPerPixel;
    seL4_Uint8 banks;
    seL4_Uint8 memoryModel;
    seL4_Uint8 bankSize;
    seL4_Uint8 imagePages;
    seL4_Uint8 reserved1;
} __attribute__((packed)) seL4_VBEInfo12Part1_t;

typedef struct seL4_VBEInfo12Part2 {
    seL4_Uint8 redLen;
    seL4_Uint8 redOff;
    seL4_Uint8 greenLen;
    seL4_Uint8 greenOff;
    seL4_Uint8 blueLen;
    seL4_Uint8 blueOff;
    seL4_Uint8 rsvdLen;
    seL4_Uint8 rsvdOff;
    seL4_Uint8 directColorInfo; /* direct color mode attributes */
} __attribute__((packed)) seL4_VBEInfo12Part2_t;

typedef struct seL4_VBEInfo20 {
    seL4_Uint32 physBasePtr;
    seL4_Uint8 reserved2[6];
} __attribute__((packed)) seL4_VBEInfo20_t;

typedef struct seL4_VBEInfo30 {
    seL4_Uint16 linBytesPerScanLine;
    seL4_Uint8 bnkImagePages;
    seL4_Uint8 linImagePages;
    seL4_Uint8 linRedLen;
    seL4_Uint8 linRedOff;
    seL4_Uint8 linGreenLen;
    seL4_Uint8 linGreenOff;
    seL4_Uint8 linBlueLen;
    seL4_Uint8 linBlueOff;
    seL4_Uint8 linRsvdLen;
    seL4_Uint8 linRsvdOff;
    seL4_Uint32 maxPixelClock;
    seL4_Uint16 modeId;
    seL4_Uint8 depth;
} __attribute__((packed)) seL4_VBEInfo30_t;

typedef struct seL4_VBEModeInfoBlock {
    /* All VBE revisions */
    seL4_VBEModeInfoCommon_t vbe_common;
    /* VBE 1.2+ */
    seL4_VBEInfo12Part1_t vbe12_part1;
    seL4_VBEInfo12Part2_t vbe12_part2;

    /* VBE 2.0+ */
    seL4_VBEInfo20_t vbe20;

    /* VBE 3.0+ */
    seL4_VBEInfo30_t vbe30;

    seL4_Uint8 reserved3[187];
} __attribute__((packed)) seL4_VBEModeInfoBlock_t;

typedef struct _seL4_X86_BootInfo_VBE {
    seL4_BootInfoHeader header;
    seL4_VBEInfoBlock_t vbeInfoBlock;
    seL4_VBEModeInfoBlock_t vbeModeInfoBlock;
    seL4_Uint32 vbeMode;
    seL4_Uint32 vbeInterfaceSeg;
    seL4_Uint32 vbeInterfaceOff;
    seL4_Uint32 vbeInterfaceLen;
} __attribute__((packed)) seL4_X86_BootInfo_VBE;

/**
 * Copy of multiboot mmap fields.
 * https://www.gnu.org/software/grub/manual/multiboot/multiboot.html
 */
typedef struct seL4_X86_mb_mmap {
    uint32_t size; // size of this struct in bytes
    uint64_t base_addr; // physical address of start of this region
    uint64_t length; // length of the region this struct represents in bytes
    uint32_t type; // memory type of region. Type 1 corresponds to RAM.
} __attribute__((packed)) seL4_X86_mb_mmap_t;

typedef struct seL4_X86_BootInfo_mmap {
    seL4_BootInfoHeader header;
    seL4_Uint32 mmap_length;
    seL4_X86_mb_mmap_t mmap[50];
} __attribute__((packed)) seL4_X86_BootInfo_mmap_t;

typedef struct multiboot2_fb seL4_X86_BootInfo_fb_t;
# 14 "/host/kernel/include/arch/x86/arch/kernel/boot.h" 2

typedef struct mem_p_regs {
    word_t count;
    p_region_t list[16];
} mem_p_regs_t;

typedef struct ui_info {
    p_region_t p_reg; /* region where the userland image lies in */
    sword_t pv_offset; /* UI virtual address + pv_offset = UI physical address */
    vptr_t v_entry; /* entry point (virtual address) of userland image */
} ui_info_t;

cap_t create_unmapped_it_frame_cap(pptr_t pptr, bool_t use_large);
cap_t create_mapped_it_frame_cap(cap_t pd_cap, pptr_t pptr, vptr_t vptr, asid_t asid, bool_t use_large,
                                 bool_t executable);

bool_t init_sys_state(
    cpu_id_t cpu_id,
    mem_p_regs_t *mem_p_regs,
    ui_info_t ui_info,
    p_region_t boot_mem_reuse_p_reg,
    /* parameters below not modeled in abstract specification */
    uint32_t num_drhu,
    paddr_t *drhu_list,
    acpi_rmrr_list_t *rmrr_list,
    acpi_rsdp_t *acpi_rsdp,
    seL4_X86_BootInfo_VBE *vbe,
    seL4_X86_BootInfo_mmap_t *mb_mmap,
    seL4_X86_BootInfo_fb_t *fb_info
);

bool_t init_cpu(
    bool_t mask_legacy_irqs
);

bool_t add_allocated_p_region(p_region_t reg);
void init_allocated_p_regions(void);
# 14 "/host/kernel/src/arch/x86/64/kernel/vspace.c" 2
# 1 "/host/kernel/include/arch/x86/arch/kernel/boot_sys.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

# 1 "/host/kernel/include/arch/x86/arch/kernel/multiboot.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
/* Adapted from the MultiBoot Specification:  */
/* www.gnu.org/software/grub/manual/multiboot */






typedef struct multiboot_module {
    uint32_t start;
    uint32_t end;
    uint32_t name;
    uint32_t reserved;
} __attribute__((packed)) multiboot_module_t;

typedef struct multiboot_mmap {
    uint32_t size;
    uint64_t base_addr;
    uint64_t length;
    uint32_t type;
} __attribute__((packed)) multiboot_mmap_t;

typedef struct multiboot_info {
    /* struct split into multiple parts due to details of how C parser works */
    struct multiboot_part1 {
        uint32_t flags;
        uint32_t mem_lower;
        uint32_t mem_upper;
        uint32_t boot_device;
        uint32_t cmdline;
        uint32_t mod_count;
        uint32_t mod_list;
    } part1;
    /* The symbol table information in the multiboot header is comprised of a union
     * as we neither a. support unions in the kernel or b. need the symbol information
     * we will just skip the 4 words of this */
    struct multiboot_part2 {
        uint32_t syms[4];
        uint32_t mmap_length;
        uint32_t mmap_addr;
        uint32_t drives_length;
        uint32_t drives_addr;
        uint32_t config_table;
        uint32_t boot_loader_name;
        uint32_t apm_table;
        uint32_t vbe_control_info;
        uint32_t vbe_mode_info;
        uint16_t vbe_mode;
        uint16_t vbe_interface_seg;
        uint16_t vbe_interface_off;
        uint16_t vbe_interface_len;
    } part2;
} __attribute__((packed)) multiboot_info_t;
# 10 "/host/kernel/include/arch/x86/arch/kernel/boot_sys.h" 2
# 1 "/host/kernel/include/arch/x86/arch/kernel/multiboot2.h" 1
/*
 * Copyright 2017, Genode Labs GmbH
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       





typedef struct multiboot2_header {
    uint32_t total_size;
    uint32_t unknown;
} __attribute__((packed)) multiboot2_header_t;

typedef struct multiboot2_tag {
    uint32_t type;
    uint32_t size;
} __attribute__((packed)) multiboot2_tag_t;

typedef struct multiboot2_memory {
    uint64_t addr;
    uint64_t size;
    uint32_t type;
    uint32_t reserved;
} __attribute__((packed)) multiboot2_memory_t;

typedef struct multiboot2_module {
    uint32_t start;
    uint32_t end;
    char string [1];
} __attribute__((packed)) multiboot2_module_t;

typedef struct multiboot2_fb {
    uint64_t addr;
    uint32_t pitch;
    uint32_t width;
    uint32_t height;
    uint8_t bpp;
    uint8_t type;
} __attribute__((packed)) multiboot2_fb_t;

enum multiboot2_tags {
    MULTIBOOT2_TAG_END = 0,
    MULTIBOOT2_TAG_CMDLINE = 1,
    MULTIBOOT2_TAG_MODULE = 3,
    MULTIBOOT2_TAG_MEMORY = 6,
    MULTIBOOT2_TAG_FB = 8,
    MULTIBOOT2_TAG_ACPI_1 = 14,
    MULTIBOOT2_TAG_ACPI_2 = 15,
};
# 11 "/host/kernel/include/arch/x86/arch/kernel/boot_sys.h" 2

/* type definitions (directly corresponding to abstract specification) */
typedef struct boot_state {
    p_region_t avail_p_reg; /* region of available physical memory on platform */
    p_region_t ki_p_reg; /* region where the kernel image is in */
    ui_info_t ui_info; /* info about userland images */
    uint32_t num_ioapic; /* number of IOAPICs detected */
    paddr_t ioapic_paddr[1];
    uint32_t num_drhu; /* number of IOMMUs */
    paddr_t drhu_list[((-((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1)) >> 12)]; /* list of physical addresses of the IOMMUs */
    acpi_rmrr_list_t rmrr_list;
    acpi_rsdp_t acpi_rsdp; /* copy of the rsdp */
    paddr_t mods_end_paddr; /* physical address where boot modules end */
    paddr_t boot_module_start; /* physical address of first boot module */
    uint32_t num_cpus; /* number of detected cpus */
    uint32_t mem_lower; /* lower memory size for boot code of APs to run in real mode */
    cpu_id_t cpus[1];
    mem_p_regs_t mem_p_regs; /* physical memory regions */
    seL4_X86_BootInfo_VBE vbe_info; /* Potential VBE information from multiboot */
    seL4_X86_BootInfo_mmap_t mb_mmap_info; /* memory map information from multiboot */
    seL4_X86_BootInfo_fb_t fb_info; /* framebuffer information as set by bootloader */
} boot_state_t;

extern boot_state_t boot_state;

void boot_sys(
    unsigned long multiboot_magic,
    void *multiboot
);
# 15 "/host/kernel/src/arch/x86/64/kernel/vspace.c" 2
# 1 "kernel/gen_headers/arch/api/invocation.h" 1

/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 ** SPDX-License-Identifier: GPL-2.0-only
 */

/* This header was generated by kernel/tools/invocation_header_gen.py.
 *
 * To add an invocation call number, edit libsel4/include/interfaces/sel4.xml.
 *
 */


# 1 "kernel/gen_headers/arch/api/sel4_invocation.h" 1

/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 ** SPDX-License-Identifier: GPL-2.0-only
 */

/* This header was generated by kernel/tools/invocation_header_gen.py.
 *
 * To add an invocation call number, edit libsel4/include/interfaces/sel4.xml.
 *
 */


# 1 "kernel/gen_headers/api/invocation.h" 1

/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 ** SPDX-License-Identifier: GPL-2.0-only
 */

/* This header was generated by kernel/tools/invocation_header_gen.py.
 *
 * To add an invocation call number, edit libsel4/include/interfaces/sel4.xml.
 *
 */



enum invocation_label {
    InvalidInvocation,
    UntypedRetype,
    TCBReadRegisters,
    TCBWriteRegisters,
    TCBCopyRegisters,

    TCBConfigure,




    TCBSetPriority,
    TCBSetMCPriority,

    TCBSetSchedParams,







    TCBSetIPCBuffer,

    TCBSetSpace,




    TCBSuspend,
    TCBResume,
    TCBBindNotification,
    TCBUnbindNotification,
# 64 "kernel/gen_headers/api/invocation.h"
    TCBSetTLSBase,
    CNodeRevoke,
    CNodeDelete,
    CNodeCancelBadgedSends,
    CNodeCopy,
    CNodeMint,
    CNodeMove,
    CNodeMutate,
    CNodeRotate,

    CNodeSaveCaller,

    IRQIssueIRQHandler,
    IRQAckIRQ,
    IRQSetIRQHandler,
    IRQClearIRQHandler,
    DomainSetSet,
# 99 "kernel/gen_headers/api/invocation.h"
    nInvocationLabels
};
# 15 "kernel/gen_headers/arch/api/sel4_invocation.h" 2
enum sel4_arch_invocation_label {
    X86PDPTMap = nInvocationLabels,
    X86PDPTUnmap,
    nSeL4ArchInvocationLabels
};
# 15 "kernel/gen_headers/arch/api/invocation.h" 2
enum arch_invocation_label {
    X86PageDirectoryMap = nSeL4ArchInvocationLabels,
    X86PageDirectoryUnmap,



    X86PageTableMap,
    X86PageTableUnmap,






    X86PageMap,
    X86PageUnmap,



    X86PageGetAddress,



    X86ASIDControlMakePool,
    X86ASIDPoolAssign,
    X86IOPortControlIssue,
    X86IOPortIn8,
    X86IOPortIn16,
    X86IOPortIn32,
    X86IOPortOut8,
    X86IOPortOut16,
    X86IOPortOut32,
    X86IRQIssueIRQHandlerIOAPIC,
    X86IRQIssueIRQHandlerMSI,
# 88 "kernel/gen_headers/arch/api/invocation.h"
    nArchInvocationLabels
};
# 16 "/host/kernel/src/arch/x86/64/kernel/vspace.c" 2
# 1 "/host/kernel/include/arch/x86/arch/64/mode/kernel/tlb.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       


# 1 "/host/kernel/include/arch/x86/arch/kernel/tlb.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

# 1 "/host/kernel/include/arch/x86/arch/smp/ipi_inline.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 10 "/host/kernel/include/arch/x86/arch/kernel/tlb.h" 2

static inline void invalidatePageStructureCacheASID(paddr_t root, asid_t asid, word_t mask)
{
    invalidateLocalPageStructureCacheASID(root, asid);
    ;
}

static inline void invalidateTranslationSingle(vptr_t vptr, word_t mask)
{
    invalidateLocalTranslationSingle(vptr);
    ;
}

static inline void invalidateTranslationSingleASID(vptr_t vptr, asid_t asid, word_t mask)
{
    invalidateLocalTranslationSingleASID(vptr, asid);
    ;
}

static inline void invalidateTranslationAll(word_t mask)
{
    invalidateLocalTranslationAll();
    ;
}
# 11 "/host/kernel/include/arch/x86/arch/64/mode/kernel/tlb.h" 2
# 1 "/host/kernel/include/arch/x86/arch/64/mode/smp/ipi.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 12 "/host/kernel/include/arch/x86/arch/64/mode/kernel/tlb.h" 2
# 1 "/host/kernel/include/arch/x86/arch/kernel/tlb_bitmap.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       






# 1 "/host/kernel/include/arch/x86/arch/64/mode/kernel/vspace.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       



struct lookupPDPTSlot_ret {
    exception_t status;
    pdpte_t *pdptSlot;
};
typedef struct lookupPDPTSlot_ret lookupPDPTSlot_ret_t;

static inline pte_t x86_make_device_pte(paddr_t phys)
{
    return pte_new(
               0, /* xd */
               phys, /* page_base_address    */
               1, /* global               */
               0, /* pat                  */
               0, /* dirty                */
               0, /* accessed             */
               1, /* cache_disabled       */
               1, /* write_through        */
               0, /* super_user           */
               1, /* read_write           */
               1 /* present              */
           );
}

static inline pte_t x86_make_empty_pte(void)
{
    return pte_new(
               0, /* xd */
               0, /* page_base_address    */
               0, /* global               */
               0, /* pat                  */
               0, /* dirty                */
               0, /* accessed             */
               0, /* cache_disabled       */
               0, /* write_through        */
               0, /* super_user           */
               0, /* read_write           */
               0 /* present              */
           );
}

static inline __attribute__((__const__)) pml4e_t x86_make_empty_root_mapping(void)
{
    return pml4e_new(
               0, /* xd               */
               0, /* pdpt_base_addr   */
               0, /* accessed         */
               0, /* cache_disabled   */
               0, /* write through    */
               0, /* super user       */
               0, /* read_write       */
               0 /* present          */
           );
}
# 15 "/host/kernel/include/arch/x86/arch/kernel/tlb_bitmap.h" 2
# 13 "/host/kernel/include/arch/x86/arch/64/mode/kernel/tlb.h" 2

/*
 * This is a wrapper around invalidatePCID that can be used to invalidate
 * an ASID and, in the case of SMP, potentially clear a vspace of having
 * any translations on this core
 */
static inline void invalidateLocalASID(vspace_root_t *vspace, asid_t asid)
{
    invalidateLocalPCID(1, (void *)0, asid);





}

static inline void invalidatePCID(word_t type, void *vaddr, asid_t asid, word_t mask)
{
    invalidateLocalPCID(type, vaddr, asid);
    ;
}

static inline void invalidateASID(vspace_root_t *vspace, asid_t asid, word_t mask)
{
    invalidateLocalASID(vspace, asid);
    ;
}
# 17 "/host/kernel/src/arch/x86/64/kernel/vspace.c" 2



/* When using the SKIM window to isolate the kernel from the user we also need to
 * not use global mappings as having global mappings and entries in the TLB is
 * equivalent, for the purpose of exploitation, to having the mappings in the
 * kernel window */


/* For the boot code we create two windows into the physical address space
 * One is at the same location as the kernel window, and is placed up high
 * The other is a 1-to-1 mapping of the first 512gb of memory. The purpose
 * of this is to have a 1-to-1 mapping for the low parts of memory, so that
 * when we switch paging on, and are still running at physical addresses,
 * we don't explode. Then we also want the high mappings so we can start
 * running at proper kernel virtual addresses */
pml4e_t boot_pml4[(1ul << (9))] __attribute__((__aligned__((1ul << (12))))) __attribute__((externally_visible)) __attribute__((__section__(".phys.bss")));
pdpte_t boot_pdpt[(1ul << (9))] __attribute__((__aligned__((1ul << (12))))) __attribute__((externally_visible)) __attribute__((__section__(".phys.bss")));

/* 'gdt_idt_ptr' is declared globally because of a C-subset restriction.
 * It is only used in init_drts(), which therefore is non-reentrant.
 */
gdt_idt_ptr_t gdt_idt_ptr;

__attribute__((__section__(".boot.text"))) bool_t map_kernel_window(
    uint32_t num_ioapic,
    paddr_t *ioapic_paddrs,
    uint32_t num_drhu,
    paddr_t *drhu_list
)
{

    uint64_t paddr;
    uint64_t vaddr;


    /* using 1 GiB page size */

    /* verify that the kernel window as at the last entry of the PML4 */
    if(!(( ((0xffffff8000000000ul) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)) == (1ul << (9)) - 1)) _assert_fail("GET_PML4_INDEX(PPTR_BASE) == BIT(PML4_INDEX_BITS) - 1", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 56, __FUNCTION__);
    /* verify that the kernel_base is located in the last entry of the PML4,
     * the second last entry of the PDPT, is 1gb aligned and 1gb in size */
    if(!(( (((0xffffffff80000000ul + 0x00100000ul)) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)) == (1ul << (9)) - 1)) _assert_fail("GET_PML4_INDEX(KERNEL_ELF_BASE) == BIT(PML4_INDEX_BITS) - 1", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 59, __FUNCTION__);
    if(!(( (((0xffffffff80000000ul + 0x00100000ul)) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)) == (1ul << (9)) - 2)) _assert_fail("GET_PDPT_INDEX(KERNEL_ELF_BASE) == BIT(PML4_INDEX_BITS) - 2", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 60, __FUNCTION__);
    if(!(( ((0xffffffffc0000000ul) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)) == (1ul << (9)) - 1)) _assert_fail("GET_PDPT_INDEX(KDEV_BASE) == BIT(PML4_INDEX_BITS) - 1", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 61, __FUNCTION__);
    if(!((!(((0xffffffff80000000ul + 0x00100000ul) - 0x00100000ul) & ((1ul << (30))-1ul))))) _assert_fail("IS_ALIGNED(KERNEL_ELF_BASE - KERNEL_ELF_PADDR_BASE, seL4_HugePageBits)", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 62, __FUNCTION__);
    if(!((!((0xffffffffc0000000ul) & ((1ul << (30))-1ul))))) _assert_fail("IS_ALIGNED(KDEV_BASE, seL4_HugePageBits)", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 63, __FUNCTION__);
    /* place the PDPT into the PML4 */
    x64KSKernelPML4[( ((0xffffff8000000000ul) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul))] = pml4e_new(
                                                     0, /* xd */
                                                     kpptr_to_paddr(x64KSKernelPDPT),
                                                     0, /* accessed */
                                                     0, /* cache_disabled */
                                                     0, /* write_through */
                                                     0, /* super_user */
                                                     1, /* read_write */
                                                     1 /* present */
                                                 );
    /* put the 1GB kernel_base mapping into the PDPT */
    x64KSKernelPDPT[( (((0xffffffff80000000ul + 0x00100000ul)) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul))] = pdpte_pdpte_1g_new(
                                                           0, /* xd */
                                                           0x00000000ul,
                                                           0, /* PAT */
                                                           (1 ? 0 : 1), /* global */
                                                           0, /* dirty */
                                                           0, /* accessed */
                                                           0, /* cache_disabled */
                                                           0, /* write_through */
                                                           0, /* super_user */
                                                           1, /* read_write */
                                                           1 /* present */
                                                       );
    /* also map the physical memory into the big kernel window */
    paddr = 0;
    vaddr = 0xffffff8000000000ul;
    for (paddr = 0; paddr < (0xffffffff80000000ul - (0xffffff8000000000ul - 0x00000000ul));
         paddr += (1ul << (30))) {

        int pdpte_index = ( ((vaddr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul));
        x64KSKernelPDPT[pdpte_index] = pdpte_pdpte_1g_new(
                                           0, /* xd               */
                                           paddr, /* physical address */
                                           0, /* PAT              */
                                           (1 ? 0 : 1), /* global   */
                                           0, /* dirty            */
                                           0, /* accessed         */
                                           0, /* cache_disabled   */
                                           0, /* write_through    */
                                           0, /* super_user       */
                                           1, /* read_write       */
                                           1 /* present          */
                                       );

        vaddr += (1ul << (30));
    }

    /* put the PD into the PDPT */
    x64KSKernelPDPT[( ((0xffffffffc0000000ul) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul))] = pdpte_pdpte_pd_new(
                                                     0, /* xd */
                                                     kpptr_to_paddr(x64KSKernelPD),
                                                     0, /* accessed */
                                                     0, /* cache_disabled */
                                                     0, /* write_through */
                                                     0, /* super_user */
                                                     1, /* read_write */
                                                     1 /* present */
                                                 );
    /* put the PT into the PD */
    x64KSKernelPD[0] = pde_pde_pt_new(
                           0, /* xd */
                           kpptr_to_paddr(x64KSKernelPT),
                           0, /* accessed */
                           0, /* cache_disabled */
                           0, /* write_through */
                           0, /* super_user */
                           1, /* read_write */
                           1 /* present */
                       );
# 243 "/host/kernel/src/arch/x86/64/kernel/vspace.c"
    /* now map in the kernel devices */
    if (!map_kernel_window_devices(x64KSKernelPT, num_ioapic, ioapic_paddrs, num_drhu, drhu_list)) {
        return false;
    }






    /* In boot code, so fine to just trash everything here */
    invalidateLocalTranslationAll();
    kprintf("Mapping kernel window is done\n");
    return true;
}


__attribute__((__section__(".boot.text"))) bool_t map_skim_window(vptr_t skim_start, vptr_t skim_end)
{
    /* place the PDPT into the PML4 */
    x64KSSKIMPML4[( ((0xffffff8000000000ul) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul))] = pml4e_new(
                                                   0, /* xd */
                                                   kpptr_to_paddr(x64KSSKIMPDPT),
                                                   0, /* accessed */
                                                   0, /* cache_disabled */
                                                   0, /* write_through */
                                                   0, /* super_user */
                                                   1, /* read_write */
                                                   1 /* present */
                                               );
    /* place the PD into the kernel_base slot of the PDPT */
    x64KSSKIMPDPT[( (((0xffffffff80000000ul + 0x00100000ul)) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul))] = pdpte_pdpte_pd_new(
                                                         0, /* xd */
                                                         kpptr_to_paddr(x64KSSKIMPD),
                                                         0, /* accessed */
                                                         0, /* cache_disabled */
                                                         0, /* write_through */
                                                         0, /* super_user */
                                                         1, /* read_write */
                                                         1 /* present */
                                                     );
    /* map the skim portion into the PD. we expect it to be 2M aligned */
    if(!((skim_start % (1ul << (21))) == 0)) _assert_fail("(skim_start % BIT(seL4_LargePageBits)) == 0", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 285, __FUNCTION__);
    if(!((skim_end % (1ul << (21))) == 0)) _assert_fail("(skim_end % BIT(seL4_LargePageBits)) == 0", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 286, __FUNCTION__);
    uint64_t paddr = kpptr_to_paddr((void *)skim_start);
    for (int i = ( ((skim_start) >> (((12) + 9))) & ((1ul << (9))-1ul)); i < ( ((skim_end) >> (((12) + 9))) & ((1ul << (9))-1ul)); i++) {
        x64KSSKIMPD[i] = pde_pde_large_new(
                             0, /* xd */
                             paddr,
                             0, /* pat */
                             (1 ? 0 : 1), /* global */
                             0, /* dirty */
                             0, /* accessed */
                             0, /* cache_disabled */
                             0, /* write_through */
                             0, /* super_user */
                             1, /* read_write */
                             1 /* present */
                         );
        paddr += (1ul << (21));
    }
    return true;
}


__attribute__((__section__(".boot.text"))) void init_tss(tss_t *tss)
{
    word_t base = (word_t)&x64KSIRQStack[0][6];
    *tss = tss_new(
               sizeof(*tss), /* io map base */
               0, 0, /* ist 7 */
               0, 0,
               0, 0,
               0, 0,
               0, 0,
               0, 0,
               /* ist 1 is the stack frame we use for interrupts */
               base >> 32, base & 0xffffffff, /* ist 1 */
               0, 0, /* rsp 2 */
               0, 0, /* rsp 1 */
               0, 0 /* rsp 0 */
           );
    /* set the IO map to all 1 to block user IN/OUT instructions */
    memset(&x86KSGlobalState[0].x86KStss.io_map[0], 0xff,
           sizeof(x86KSGlobalState[0].x86KStss.io_map));
}

__attribute__((__section__(".boot.text"))) void init_syscall_msrs(void)
{
    x86_wrmsr(0xC0000082, (uint64_t)&handle_fastsyscall);
    // mask bit 9 in the kernel (which is the interrupt enable bit)
    // also mask bit 8, which is the Trap Flag, to prevent the kernel
    // from single stepping
    x86_wrmsr(0xC0000084, (1ul << (8)) /* Trap Flag */ | (1ul << (9)) /* Interrupt enable Flag */);
    x86_wrmsr(0xC0000081, ((uint64_t)(1 << 3) << 32) | ((uint64_t)((5 << 3) | 3) << 48));
}

__attribute__((__section__(".boot.text"))) void init_gdt(gdt_entry_t *gdt, tss_t *tss)
{

    uint64_t tss_base = (uint64_t)tss;
    gdt_tss_t gdt_tss;

    gdt[0] = gdt_entry_gdt_null_new();

    gdt[1] = gdt_entry_gdt_code_new(
                        0, /* base high */
                        1, /* granularity */
                        0, /* operation size, must be 0 when 64-bit is set */
                        1, /* long mode */
                        0, /* avl */
                        0xf, /* limit high */
                        1, /* present */
                        0, /* dpl */
                        1, /* always 1 for segment */
                        0, /* base middle */
                        0, /* base low */
                        0xffff /* limit low */
                    );

    gdt[2] = gdt_entry_gdt_data_new(
                        0, /* base high */
                        1, /* granularity */
                        1, /* operation size */
                        0, /* avl */
                        0xf, /* seg limit high */
                        1, /* present */
                        0, /* dpl */
                        1, /* always 1 */
                        0, /* base mid */
                        0, /* base low */
                        0xffff /* seg limit low */
                    );

    gdt[5] = gdt_entry_gdt_code_new(
                        0, /* base high */
                        1, /* granularity */
                        0, /* operation size, must be 0 when 64-bit is set */
                        1, /* long mode */
                        0, /* avl */
                        0xf, /* limit high */
                        1, /* present */
                        3, /* dpl */
                        1, /* always 1 */
                        0, /* base middle */
                        0, /* base low */
                        0xffff /* limit low */
                    );

    gdt[6] = gdt_entry_gdt_data_new(
                        0,
                        1,
                        1,
                        0,
                        0xf,
                        1,
                        3,
                        1,
                        0,
                        0,
                        0xffff
                    );

    gdt[7] = gdt_entry_gdt_data_new(
                      0,
                      1,
                      1,
                      0,
                      0xf,
                      1,
                      3,
                      1,
                      0,
                      0,
                      0xffff
                  );

    gdt[8] = gdt_entry_gdt_data_new(
                      0,
                      1,
                      1,
                      0,
                      0xf,
                      1,
                      3,
                      1,
                      0,
                      0,
                      0xffff
                  );

    gdt_tss = gdt_tss_new(
                  tss_base >> 32, /* base 63 - 32 */
                  (tss_base & 0xff000000UL) >> 24, /* base 31 - 24 */
                  1, /* granularity */
                  0, /* avl */
                  0, /* limit high */
                  1, /* present */
                  0, /* dpl */
                  9, /* desc type */
                  (tss_base & 0xff0000UL) >> 16, /* base 23-16 */
                  (tss_base & 0xffffUL), /* base 15 - 0 */
                  sizeof(tss_io_t) - 1
              );

    gdt[3 /*TSS is two slots in x86-64*/].words[0] = gdt_tss.words[0];
    gdt[3 /*TSS is two slots in x86-64*/ + 1].words[0] = gdt_tss.words[1];
}

__attribute__((__section__(".boot.text"))) void init_idt_entry(idt_entry_t *idt, interrupt_t interrupt, void(*handler)(void))
{
    uint64_t handler_addr = (uint64_t)handler;
    uint64_t dpl = 3;

    if (interrupt < int_trap_min && interrupt != int_software_break_request) {
        dpl = 0;
    }

    idt[interrupt] = idt_entry_interrupt_gate_new(
                         handler_addr >> 32, /* offset 63 - 32 */
                         ((handler_addr >> 16) & 0xffff),
                         1, /* present */
                         dpl, /* dpl */
                         1, /* ist */
                         (1 << 3), /* segment selector */
                         (handler_addr & 0xffff) /* offset 15 - 0 */
                     );
}

void setVMRoot(tcb_t *tcb)
{
    cap_t threadRoot;
    asid_t asid;
    pml4e_t *pml4;
    findVSpaceForASID_ret_t find_ret;
    cr3_t cr3;

    threadRoot = (((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap;

    if (cap_get_capType(threadRoot) != cap_pml4_cap ||
        !cap_pml4_cap_get_capPML4IsMapped(threadRoot)) {
        setCurrentUserVSpaceRoot(kpptr_to_paddr(x64KSSKIMPML4), 0);
        return;
    }

    pml4 = ((pml4e_t *)(cap_pml4_cap_get_capPML4BasePtr(threadRoot)));
    asid = cap_pml4_cap_get_capPML4MappedASID(threadRoot);
    find_ret = findVSpaceForASID(asid);
    if (__builtin_expect(!!(find_ret.status != EXCEPTION_NONE || find_ret.vspace_root != pml4), 0)) {
        setCurrentUserVSpaceRoot(kpptr_to_paddr(x64KSSKIMPML4), 0);
        return;
    }
    cr3 = makeCR3(addrFromPPtr(pml4), asid);
    if (getCurrentUserCR3().words[0] != cr3.words[0]) {
       
        setCurrentUserCR3(cr3);
    }
}


__attribute__((__section__(".boot.text"))) void init_dtrs(void)
{
    gdt_idt_ptr.limit = (sizeof(gdt_entry_t) * 9) - 1;
    gdt_idt_ptr.base = (uint64_t)x86KSGlobalState[0].x86KSgdt;

    /* When we install the gdt it will clobber any value of gs that
     * we have. Since we might be using it for TLS we can stash
     * and unstash any gs value using swapgs
     */
    swapgs();
    x64_install_gdt(&gdt_idt_ptr);
    swapgs();

    gdt_idt_ptr.limit = (sizeof(idt_entry_t) * (int_max + 1)) - 1;
    gdt_idt_ptr.base = (uint64_t)x86KSGlobalState[0].x86KSidt;
    x64_install_idt(&gdt_idt_ptr);

    x64_install_ldt(0);

    x64_install_tss((3 /*TSS is two slots in x86-64*/ << 3));
}

__attribute__((__section__(".boot.text"))) void map_it_frame_cap(cap_t pd_cap, cap_t frame_cap)
{
    pml4e_t *pml4 = ((pml4e_t *)((pptr_t)cap_get_capPtr(pd_cap)));
    pdpte_t *pdpt;
    pde_t *pd;
    pte_t *pt;
    vptr_t vptr = cap_frame_cap_get_capFMappedAddress(frame_cap);
    void *pptr = (void *)cap_frame_cap_get_capFBasePtr(frame_cap);

    if(!(cap_frame_cap_get_capFMapType(frame_cap) == X86_MappingVSpace)) _assert_fail("cap_frame_cap_get_capFMapType(frame_cap) == X86_MappingVSpace", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 534, __FUNCTION__);
    if(!(cap_frame_cap_get_capFMappedASID(frame_cap) != asidInvalid)) _assert_fail("cap_frame_cap_get_capFMappedASID(frame_cap) != asidInvalid", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 535, __FUNCTION__);
    pml4 += ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul));
    if(!(pml4e_ptr_get_present(pml4))) _assert_fail("pml4e_ptr_get_present(pml4)", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 537, __FUNCTION__);
    pdpt = ptrFromPAddr(pml4e_ptr_get_pdpt_base_address(pml4));
    pdpt += ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul));
    if(!(pdpte_pdpte_pd_ptr_get_present(pdpt))) _assert_fail("pdpte_pdpte_pd_ptr_get_present(pdpt)", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 540, __FUNCTION__);
    pd = ptrFromPAddr(pdpte_pdpte_pd_ptr_get_pd_base_address(pdpt));
    pd += ( ((vptr) >> (((12) + 9))) & ((1ul << (9))-1ul));
    if(!(pde_pde_pt_ptr_get_present(pd))) _assert_fail("pde_pde_pt_ptr_get_present(pd)", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 543, __FUNCTION__);
    pt = ptrFromPAddr(pde_pde_pt_ptr_get_pt_base_address(pd));
    *(pt + ( ((vptr) >> ((12))) & ((1ul << (9))-1ul))) = pte_new(
                                     0, /* xd                   */
                                     addrFromPPtr(pptr), /* page_base_address    */
                                     0, /* global               */
                                     0, /* pat                  */
                                     0, /* dirty                */
                                     0, /* accessed             */
                                     0, /* cache_disabled       */
                                     0, /* write_through        */
                                     1, /* super_user           */
                                     1, /* read_write           */
                                     1 /* present              */
                                 );
}

static __attribute__((__section__(".boot.text"))) void map_it_pdpt_cap(cap_t vspace_cap, cap_t pdpt_cap)
{
    pml4e_t *pml4 = ((pml4e_t *)((pptr_t)cap_get_capPtr(vspace_cap)));
    pdpte_t *pdpt = ((pdpte_t *)(cap_pdpt_cap_get_capPDPTBasePtr(pdpt_cap)));
    vptr_t vptr = cap_pdpt_cap_get_capPDPTMappedAddress(pdpt_cap);

    if(!(cap_pdpt_cap_get_capPDPTIsMapped(pdpt_cap))) _assert_fail("cap_pdpt_cap_get_capPDPTIsMapped(pdpt_cap)", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 566, __FUNCTION__);
    *(pml4 + ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul))) = pml4e_new(
                                         0, /* xd                   */
                                         addrFromPPtr(pdpt), /* pdpt_base_address    */
                                         0, /* accessed             */
                                         0, /* cache_disabled       */
                                         0, /* write_through        */
                                         1, /* super_user           */
                                         1, /* read_write           */
                                         1 /* present              */
                                     );
}

__attribute__((__section__(".boot.text"))) void map_it_pd_cap(cap_t vspace_cap, cap_t pd_cap)
{
    pml4e_t *pml4 = ((pml4e_t *)((pptr_t)cap_get_capPtr(vspace_cap)));
    pdpte_t *pdpt;
    pde_t *pd = ((pde_t *)(cap_page_directory_cap_get_capPDBasePtr(pd_cap)));
    vptr_t vptr = cap_page_directory_cap_get_capPDMappedAddress(pd_cap);

    if(!(cap_page_directory_cap_get_capPDIsMapped(pd_cap))) _assert_fail("cap_page_directory_cap_get_capPDIsMapped(pd_cap)", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 586, __FUNCTION__);
    pml4 += ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul));
    if(!(pml4e_ptr_get_present(pml4))) _assert_fail("pml4e_ptr_get_present(pml4)", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 588, __FUNCTION__);
    pdpt = ptrFromPAddr(pml4e_ptr_get_pdpt_base_address(pml4));
    *(pdpt + ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul))) = pdpte_pdpte_pd_new(
                                         0, /* xd                   */
                                         addrFromPPtr(pd), /* pd_base_address      */
                                         0, /* accessed             */
                                         0, /* cache_disabled       */
                                         0, /* write_through        */
                                         1, /* super_user           */
                                         1, /* read_write           */
                                         1 /* present              */
                                     );
}

__attribute__((__section__(".boot.text"))) void map_it_pt_cap(cap_t vspace_cap, cap_t pt_cap)
{
    pml4e_t *pml4 = ((pml4e_t *)((pptr_t)cap_get_capPtr(vspace_cap)));
    pdpte_t *pdpt;
    pde_t *pd;
    pte_t *pt = ((pte_t *)(cap_page_table_cap_get_capPTBasePtr(pt_cap)));
    vptr_t vptr = cap_page_table_cap_get_capPTMappedAddress(pt_cap);

    if(!(cap_page_table_cap_get_capPTIsMapped(pt_cap))) _assert_fail("cap_page_table_cap_get_capPTIsMapped(pt_cap)", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 610, __FUNCTION__);
    pml4 += ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul));
    if(!(pml4e_ptr_get_present(pml4))) _assert_fail("pml4e_ptr_get_present(pml4)", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 612, __FUNCTION__);
    pdpt = ptrFromPAddr(pml4e_ptr_get_pdpt_base_address(pml4));
    pdpt += ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul));
    if(!(pdpte_pdpte_pd_ptr_get_present(pdpt))) _assert_fail("pdpte_pdpte_pd_ptr_get_present(pdpt)", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 615, __FUNCTION__);
    pd = ptrFromPAddr(pdpte_pdpte_pd_ptr_get_pd_base_address(pdpt));
    *(pd + ( ((vptr) >> (((12) + 9))) & ((1ul << (9))-1ul))) = pde_pde_pt_new(
                                     0, /* xd                   */
                                     addrFromPPtr(pt), /* pt_base_address      */
                                     0, /* accessed             */
                                     0, /* cache_disabled       */
                                     0, /* write_through        */
                                     1, /* super_user           */
                                     1, /* read_write           */
                                     1 /* present              */
                                 );
}

__attribute__((__section__(".boot.text"))) void *map_temp_boot_page(void *entry, uint32_t large_pages)
{
    /* this function is for legacy 32-bit systems where the ACPI tables might
     * collide with the kernel window. Here we just assert that the table is
     * in fact in the lower 4GiB region (which is already 1-to-1 mapped) and
     * continue */
    if(!((word_t)entry < (1ul << (32)))) _assert_fail("(word_t)entry < BIT(32)", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 635, __FUNCTION__);
    return entry;
}

static __attribute__((__section__(".boot.text"))) cap_t create_it_pdpt_cap(cap_t vspace_cap, pptr_t pptr, vptr_t vptr, asid_t asid)
{
    cap_t cap;
    cap = cap_pdpt_cap_new(
              asid, /* capPDPTMappedASID    */
              pptr, /* capPDPTBasePtr       */
              1, /* capPDPTIsMapped      */
              vptr /* capPDPTMappedAddress */
          );
    map_it_pdpt_cap(vspace_cap, cap);
    return cap;
}

static __attribute__((__section__(".boot.text"))) cap_t create_it_pd_cap(cap_t vspace_cap, pptr_t pptr, vptr_t vptr, asid_t asid)
{
    cap_t cap;
    cap = cap_page_directory_cap_new(
              asid, /* capPDMappedASID      */
              pptr, /* capPDBasePtr         */
              1, /* capPDIsMapped        */
              vptr /* capPDMappedAddress   */
          );
    map_it_pd_cap(vspace_cap, cap);
    return cap;
}

static __attribute__((__section__(".boot.text"))) cap_t create_it_pt_cap(cap_t vspace_cap, pptr_t pptr, vptr_t vptr, asid_t asid)
{
    cap_t cap;
    cap = cap_page_table_cap_new(
              asid, /* capPTMappedASID      */
              pptr, /* capPTBasePtr         */
              1, /* capPTIsMapped        */
              vptr /* capPTMappedAddress   */
          );
    map_it_pt_cap(vspace_cap, cap);
    return cap;
}


__attribute__((__section__(".boot.text"))) word_t arch_get_n_paging(v_region_t it_v_reg)
{
    word_t n = get_n_paging(it_v_reg, ((12) + 9));
    n += get_n_paging(it_v_reg, (((12) + 9) + 9));
    n += get_n_paging(it_v_reg, ((((12) + 9) + 9) + 9));



    return n;
}

__attribute__((__section__(".boot.text"))) cap_t create_it_address_space(cap_t root_cnode_cap, v_region_t it_v_reg)
{
    cap_t vspace_cap;
    vptr_t vptr;
    seL4_SlotPos slot_pos_before;
    seL4_SlotPos slot_pos_after;

    slot_pos_before = ndks_boot.slot_pos_cur;
    copyGlobalMappings(((pml4e_t *)(rootserver.vspace)));
    vspace_cap = cap_pml4_cap_new(
                     1 /* initial thread's ASID */, /* capPML4MappedASID */
                     rootserver.vspace, /* capPML4BasePtr   */
                     1 /* capPML4IsMapped   */
                 );


    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadVSpace)), vspace_cap);

    /* Create any PDPTs needed for the user land image */
    for (vptr = (((it_v_reg.start) >> (((((12) + 9) + 9) + 9))) << (((((12) + 9) + 9) + 9)));
         vptr < it_v_reg.end;
         vptr += (1ul << (((((12) + 9) + 9) + 9)))) {
        if (!provide_cap(root_cnode_cap,
                         create_it_pdpt_cap(vspace_cap, it_alloc_paging(), vptr, 1 /* initial thread's ASID */))
           ) {
            return cap_null_cap_new();
        }
    }

    /* Create any PDs needed for the user land image */
    for (vptr = (((it_v_reg.start) >> ((((12) + 9) + 9))) << ((((12) + 9) + 9)));
         vptr < it_v_reg.end;
         vptr += (1ul << ((((12) + 9) + 9)))) {
        if (!provide_cap(root_cnode_cap,
                         create_it_pd_cap(vspace_cap, it_alloc_paging(), vptr, 1 /* initial thread's ASID */))
           ) {
            return cap_null_cap_new();
        }
    }

    /* Create any PTs needed for the user land image */
    for (vptr = (((it_v_reg.start) >> (((12) + 9))) << (((12) + 9)));
         vptr < it_v_reg.end;
         vptr += (1ul << (((12) + 9)))) {
        if (!provide_cap(root_cnode_cap,
                         create_it_pt_cap(vspace_cap, it_alloc_paging(), vptr, 1 /* initial thread's ASID */))
           ) {
            return cap_null_cap_new();
        }
    }

    slot_pos_after = ndks_boot.slot_pos_cur;
    ndks_boot.bi_frame->userImagePaging = (seL4_SlotRegion) {
        slot_pos_before, slot_pos_after
    };
    return vspace_cap;
}

void copyGlobalMappings(vspace_root_t *new_vspace)
{
    unsigned long i;
    pml4e_t *vspace = (pml4e_t *)new_vspace;

    /* Copy from the tlbbitmap_pptr so that we copy the default entries of the
     * tlb bitmap (if it exists). If it doesn't exist then this loop
     * will be equivalent to copying from PPTR_BASE
     */
    for (i = ( (((0xffffff8000000000ul - (0 * (1ul << (((((12) + 9) + 9) + 9)))))) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)); i < (1ul << (9)); i++) {
        vspace[i] = x64KSSKIMPML4[i];
    }
}

static __attribute__((__section__(".boot.text"))) cap_t create_it_frame_cap(pptr_t pptr, vptr_t vptr, asid_t asid, bool_t use_large, seL4_Word map_type)
{
    vm_page_size_t frame_size;

    if (use_large) {
        frame_size = X86_LargePage;
    } else {
        frame_size = X86_SmallPage;
    }

    return
        cap_frame_cap_new(
            asid, /* capFMappedASID     */
            pptr, /* capFBasePtr        */
            frame_size, /* capFSize           */
            map_type, /* capFMapType        */
            vptr, /* capFMappedAddress  */
            wordFromVMRights(VMReadWrite), /* capFVMRights       */
            0 /* capFIsDevice       */
        );
}

__attribute__((__section__(".boot.text"))) cap_t create_unmapped_it_frame_cap(pptr_t pptr, bool_t use_large)
{
    return create_it_frame_cap(pptr, 0, asidInvalid, use_large, X86_MappingNone);
}

__attribute__((__section__(".boot.text"))) cap_t create_mapped_it_frame_cap(cap_t vspace_cap, pptr_t pptr, vptr_t vptr, asid_t asid, bool_t use_large,
                                           bool_t executable __attribute__((unused)))
{
    cap_t cap = create_it_frame_cap(pptr, vptr, asid, use_large, X86_MappingVSpace);
    map_it_frame_cap(vspace_cap, cap);
    return cap;
}

/* ====================== BOOT CODE FINISHES HERE ======================== */



exception_t performASIDPoolInvocation(asid_t asid, asid_pool_t *poolPtr, cte_t *vspaceCapSlot)
{
    asid_map_t asid_map;







    {
        if(!(cap_get_capType(vspaceCapSlot->cap) == cap_pml4_cap)) _assert_fail("cap_get_capType(vspaceCapSlot->cap) == cap_pml4_cap", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 812, __FUNCTION__);
        cap_pml4_cap_ptr_set_capPML4MappedASID(&vspaceCapSlot->cap, asid);
        cap_pml4_cap_ptr_set_capPML4IsMapped(&vspaceCapSlot->cap, 1);
        asid_map = asid_map_asid_map_vspace_new(cap_pml4_cap_get_capPML4BasePtr(vspaceCapSlot->cap));
    }
    poolPtr->array[asid & ((1ul << (asidLowBits))-1ul)] = asid_map;
    return EXCEPTION_NONE;
}

bool_t __attribute__((__const__)) isVTableRoot(cap_t cap)
{
    return cap_get_capType(cap) == cap_pml4_cap;
}

bool_t __attribute__((__const__)) isValidNativeRoot(cap_t cap)
{
    return isVTableRoot(cap) &&
           cap_pml4_cap_get_capPML4IsMapped(cap);
}

static pml4e_t __attribute__((__const__)) makeUserPML4E(paddr_t paddr, vm_attributes_t vm_attr)
{
    return pml4e_new(
               0,
               paddr,
               0,
               vm_attributes_get_x86PCDBit(vm_attr),
               vm_attributes_get_x86PWTBit(vm_attr),
               1,
               1,
               1
           );
}

static pml4e_t __attribute__((__const__)) makeUserPML4EInvalid(void)
{
    return pml4e_new(
               0, /* xd               */
               0, /* pdpt_base_addr   */
               0, /* accessed         */
               0, /* cache_disabled   */
               0, /* write through    */
               0, /* super user       */
               0, /* read_write       */
               0 /* present          */
           );
}

static pdpte_t __attribute__((__const__)) makeUserPDPTEHugePage(paddr_t paddr, vm_attributes_t vm_attr, vm_rights_t vm_rights)
{
    return pdpte_pdpte_1g_new(
               0, /* xd               */
               paddr, /* physical address */
               0, /* PAT              */
               0, /* global           */
               0, /* dirty            */
               0, /* accessed         */
               vm_attributes_get_x86PCDBit(vm_attr), /* cache disabled */
               vm_attributes_get_x86PWTBit(vm_attr), /* write through  */
               SuperUserFromVMRights(vm_rights), /* super user     */
               WritableFromVMRights(vm_rights), /* read write     */
               1 /* present        */
           );
}

static pdpte_t __attribute__((__const__)) makeUserPDPTEPageDirectory(paddr_t paddr, vm_attributes_t vm_attr)
{
    return pdpte_pdpte_pd_new(
               0, /* xd       */
               paddr, /* paddr    */
               0, /* accessed */
               vm_attributes_get_x86PCDBit(vm_attr), /* cache disabled */
               vm_attributes_get_x86PWTBit(vm_attr), /* write through  */
               1, /* super user */
               1, /* read write */
               1 /* present    */
           );
}

static pdpte_t __attribute__((__const__)) makeUserPDPTEInvalid(void)
{
    return pdpte_pdpte_pd_new(
               0, /* xd               */
               0, /* physical address */
               0, /* accessed         */
               0, /* cache disabled */
               0, /* write through  */
               0, /* super user     */
               0, /* read write     */
               0 /* present        */
           );
}

pde_t __attribute__((__const__)) makeUserPDELargePage(paddr_t paddr, vm_attributes_t vm_attr, vm_rights_t vm_rights)
{
    return pde_pde_large_new(
               0, /* xd                   */
               paddr, /* page_base_address    */
               vm_attributes_get_x86PATBit(vm_attr), /* pat                  */
               0, /* global               */
               0, /* dirty                */
               0, /* accessed             */
               vm_attributes_get_x86PCDBit(vm_attr), /* cache_disabled       */
               vm_attributes_get_x86PWTBit(vm_attr), /* write_through        */
               SuperUserFromVMRights(vm_rights), /* super_user           */
               WritableFromVMRights(vm_rights), /* read_write           */
               1 /* present              */
           );
}

pde_t __attribute__((__const__)) makeUserPDEPageTable(paddr_t paddr, vm_attributes_t vm_attr)
{

    return pde_pde_pt_new(
                0, /* xd               */
                paddr, /* pt_base_address  */
                0, /* accessed         */
                vm_attributes_get_x86PCDBit(vm_attr), /* cache_disabled   */
                vm_attributes_get_x86PWTBit(vm_attr), /* write_through    */
                1, /* super_user       */
                1, /* read_write       */
                1 /* present          */
            );
}

pde_t __attribute__((__const__)) makeUserPDEInvalid(void)
{
    /* The bitfield only declares two kinds of PDE entries (page tables or large pages)
     * and an invalid entry should really be a third type, but we can simulate it by
     * creating an invalid (present bit 0) entry of either of the defined types */
    return pde_pde_pt_new(
               0, /* xd               */
               0, /* pt_base_addr     */
               0, /* accessed         */
               0, /* cache_disabled   */
               0, /* write_through    */
               0, /* super_user       */
               0, /* read_write       */
               0 /* present          */
           );
}

pte_t __attribute__((__const__)) makeUserPTE(paddr_t paddr, vm_attributes_t vm_attr, vm_rights_t vm_rights)
{
    return pte_new(
               0, /* xd                   */
               paddr, /* page_base_address    */
               0, /* global               */
               vm_attributes_get_x86PATBit(vm_attr), /* pat                  */
               0, /* dirty                */
               0, /* accessed             */
               vm_attributes_get_x86PCDBit(vm_attr), /* cache_disabled       */
               vm_attributes_get_x86PWTBit(vm_attr), /* write_through        */
               SuperUserFromVMRights(vm_rights), /* super_user           */
               WritableFromVMRights(vm_rights), /* read_write           */
               1 /* present              */
           );
}

pte_t __attribute__((__const__)) makeUserPTEInvalid(void)
{
    return pte_new(
               0, /* xd                   */
               0, /* page_base_address    */
               0, /* global               */
               0, /* pat                  */
               0, /* dirty                */
               0, /* accessed             */
               0, /* cache_disabled       */
               0, /* write_through        */
               0, /* super_user           */
               0, /* read_write           */
               0 /* present              */
           );
}


static pml4e_t *lookupPML4Slot(vspace_root_t *pml4, vptr_t vptr)
{
    pml4e_t *pml4e = ((pml4e_t *)(pml4));
    word_t pml4Index = ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul));
    return pml4e + pml4Index;
}

static lookupPDPTSlot_ret_t lookupPDPTSlot(vspace_root_t *pml4, vptr_t vptr)
{
    pml4e_t *pml4Slot = lookupPML4Slot(pml4, vptr);
    lookupPDPTSlot_ret_t ret;

    if (!pml4e_ptr_get_present(pml4Slot)) {
        current_lookup_fault = lookup_fault_missing_capability_new(((((12) + 9) + 9) + 9));

        ret.pdptSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    } else {
        pdpte_t *pdpt;
        pdpte_t *pdptSlot;
        word_t pdptIndex = ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul));
        pdpt = ptrFromPAddr(pml4e_ptr_get_pdpt_base_address(pml4Slot));
        pdptSlot = pdpt + pdptIndex;

        ret.status = EXCEPTION_NONE;
        ret.pdptSlot = pdptSlot;
        return ret;
    }
}

lookupPDSlot_ret_t lookupPDSlot(vspace_root_t *pml4, vptr_t vptr)
{
    lookupPDPTSlot_ret_t pdptSlot;
    lookupPDSlot_ret_t ret;

    pdptSlot = lookupPDPTSlot(pml4, vptr);

    if (pdptSlot.status != EXCEPTION_NONE) {
        ret.pdSlot = ((void *)0);
        ret.status = pdptSlot.status;
        return ret;
    }
    if ((pdpte_ptr_get_page_size(pdptSlot.pdptSlot) != pdpte_pdpte_pd) ||
        !pdpte_pdpte_pd_ptr_get_present(pdptSlot.pdptSlot)) {
        current_lookup_fault = lookup_fault_missing_capability_new((((12) + 9) + 9));

        ret.pdSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    } else {
        pde_t *pd;
        pde_t *pdSlot;
        word_t pdIndex = ( ((vptr) >> (((12) + 9))) & ((1ul << (9))-1ul));
        pd = ptrFromPAddr(pdpte_pdpte_pd_ptr_get_pd_base_address(pdptSlot.pdptSlot));
        pdSlot = pd + pdIndex;

        ret.status = EXCEPTION_NONE;
        ret.pdSlot = pdSlot;
        return ret;
    }
}

static void flushPD(vspace_root_t *vspace, word_t vptr, pde_t *pd, asid_t asid)
{
    /* clearing the entire PCID vs flushing the virtual addresses
     * one by one using invplg.
     * choose the easy way, invalidate the PCID
     */
    invalidateASID(vspace, asid, 0);

}

static void flushPDPT(vspace_root_t *vspace, word_t vptr, pdpte_t *pdpt, asid_t asid)
{
    /* similar here */
    invalidateASID(vspace, asid, 0);
    return;
}

void hwASIDInvalidate(asid_t asid, vspace_root_t *vspace)
{
    invalidateASID(vspace, asid, 0);
}

void unmapPageDirectory(asid_t asid, vptr_t vaddr, pde_t *pd)
{
    findVSpaceForASID_ret_t find_ret;
    lookupPDPTSlot_ret_t lu_ret;

    find_ret = findVSpaceForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        return;
    }

    lu_ret = lookupPDPTSlot(find_ret.vspace_root, vaddr);
    if (lu_ret.status != EXCEPTION_NONE) {
        return;
    }

    /* check if the PDPT has the PD */
    if (!(pdpte_ptr_get_page_size(lu_ret.pdptSlot) == pdpte_pdpte_pd &&
          pdpte_pdpte_pd_ptr_get_present(lu_ret.pdptSlot) &&
          (pdpte_pdpte_pd_ptr_get_pd_base_address(lu_ret.pdptSlot) == addrFromPPtr(pd)))) {
        return;
    }

    flushPD(find_ret.vspace_root, vaddr, pd, asid);

    *lu_ret.pdptSlot = makeUserPDPTEInvalid();

    invalidatePageStructureCacheASID(addrFromPPtr(find_ret.vspace_root), asid,
                                     0);
}


static exception_t performX64PageDirectoryInvocationUnmap(cap_t cap, cte_t *ctSlot)
{

    if (cap_page_directory_cap_get_capPDIsMapped(cap)) {
        pde_t *pd = ((pde_t *)(cap_page_directory_cap_get_capPDBasePtr(cap)));
        unmapPageDirectory(
            cap_page_directory_cap_get_capPDMappedASID(cap),
            cap_page_directory_cap_get_capPDMappedAddress(cap),
            pd
        );
        clearMemory((void *)pd, cap_get_capSizeBits(cap));
    }

    cap_page_directory_cap_ptr_set_capPDIsMapped(&(ctSlot->cap), 0);

    return EXCEPTION_NONE;
}

static exception_t performX64PageDirectoryInvocationMap(cap_t cap, cte_t *ctSlot, pdpte_t pdpte, pdpte_t *pdptSlot,
                                                        vspace_root_t *vspace)
{
    ctSlot->cap = cap;
    *pdptSlot = pdpte;
    invalidatePageStructureCacheASID(addrFromPPtr(vspace), cap_page_directory_cap_get_capPDMappedASID(cap),
                                     0);
    return EXCEPTION_NONE;
}


static exception_t decodeX64PageDirectoryInvocation(
    word_t label,
    word_t length,
    cte_t *cte,
    cap_t cap,
    extra_caps_t extraCaps,
    word_t *buffer
)
{
    word_t vaddr;
    vm_attributes_t vm_attr;
    cap_t vspaceCap;
    vspace_root_t *vspace;
    pdpte_t pdpte;
    paddr_t paddr;
    asid_t asid;
    lookupPDPTSlot_ret_t pdptSlot;

    if (label == X86PageDirectoryUnmap) {
        if (!isFinalCapability(cte)) {
            current_syscall_error.type = seL4_RevokeFirst;
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86PageDirectory: Cannot unmap if more than one cap exist." ">>" "\033[0m" "\n", 0lu, __func__, 1155, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            return EXCEPTION_SYSCALL_ERROR;
        }
        setThreadState(ksCurThread, ThreadState_Restart);

        return performX64PageDirectoryInvocationUnmap(cap, cte);
    }

    if (label != X86PageDirectoryMap) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X64Directory: Illegal operation." ">>" "\033[0m" "\n", 0lu, __func__, 1164, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (length < 2 || extraCaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X64PageDirectory: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 1170, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cap_page_directory_cap_get_capPDIsMapped(cap)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X64PageDirectory: PD is already mapped to a PML4." ">>" "\033[0m" "\n", 0lu, __func__, 1176, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vaddr = getSyscallArg(0, buffer) & (~((1ul << ((((12) + 9) + 9)))-1ul));
    vm_attr = vmAttributesFromWord(getSyscallArg(1, buffer));
    vspaceCap = extraCaps.excaprefs[0]->cap;

    if (!isValidNativeRoot(vspaceCap)) {
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vspace = (vspace_root_t *)(pptr_t)cap_get_capPtr(vspaceCap);
    asid = cap_get_capMappedASID(vspaceCap);

    if (vaddr > 0x7FFFFFFFFFFFul) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X64PageDirectory: Mapping address too high." ">>" "\033[0m" "\n", 0lu, __func__, 1198, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    findVSpaceForASID_ret_t find_ret;

    find_ret = findVSpaceForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        return EXCEPTION_SYSCALL_ERROR;
    }

    if (find_ret.vspace_root != vspace) {
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    pdptSlot = lookupPDPTSlot(vspace, vaddr);
    if (pdptSlot.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        return EXCEPTION_SYSCALL_ERROR;
    }

    if ((pdpte_ptr_get_page_size(pdptSlot.pdptSlot) == pdpte_pdpte_pd &&
         pdpte_pdpte_pd_ptr_get_present(pdptSlot.pdptSlot)) ||
        (pdpte_ptr_get_page_size(pdptSlot.pdptSlot) == pdpte_pdpte_1g
         && pdpte_pdpte_1g_ptr_get_present(pdptSlot.pdptSlot))) {
        current_syscall_error.type = seL4_DeleteFirst;

        return EXCEPTION_SYSCALL_ERROR;
    }

    paddr = addrFromPPtr(((pde_t *)(cap_page_directory_cap_get_capPDBasePtr(cap))));
    pdpte = makeUserPDPTEPageDirectory(paddr, vm_attr);

    cap = cap_page_directory_cap_set_capPDIsMapped(cap, 1);
    cap = cap_page_directory_cap_set_capPDMappedASID(cap, asid);
    cap = cap_page_directory_cap_set_capPDMappedAddress(cap, vaddr);

    setThreadState(ksCurThread, ThreadState_Restart);
    return performX64PageDirectoryInvocationMap(cap, cte, pdpte, pdptSlot.pdptSlot, vspace);
}

static void unmapPDPT(asid_t asid, vptr_t vaddr, pdpte_t *pdpt)
{
    findVSpaceForASID_ret_t find_ret;
    pml4e_t *pml4Slot;

    find_ret = findVSpaceForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        return;
    }

    pml4Slot = lookupPML4Slot(find_ret.vspace_root, vaddr);

    /* check if the PML4 has the PDPT */
    if (!(pml4e_ptr_get_present(pml4Slot) &&
          pml4e_ptr_get_pdpt_base_address(pml4Slot) == addrFromPPtr(pdpt))) {
        return;
    }

    flushPDPT(find_ret.vspace_root, vaddr, pdpt, asid);

    *pml4Slot = makeUserPML4EInvalid();
}

static exception_t performX64PDPTInvocationUnmap(cap_t cap, cte_t *ctSlot)
{
    if (cap_pdpt_cap_get_capPDPTIsMapped(cap)) {
        pdpte_t *pdpt = ((pdpte_t *)(cap_pdpt_cap_get_capPDPTBasePtr(cap)));
        unmapPDPT(cap_pdpt_cap_get_capPDPTMappedASID(cap),
                  cap_pdpt_cap_get_capPDPTMappedAddress(cap),
                  pdpt);
        clearMemory((void *)pdpt, cap_get_capSizeBits(cap));
    }

    cap_pdpt_cap_ptr_set_capPDPTIsMapped(&(ctSlot->cap), 0);

    return EXCEPTION_NONE;
}

static exception_t performX64PDPTInvocationMap(cap_t cap, cte_t *ctSlot, pml4e_t pml4e, pml4e_t *pml4Slot,
                                               vspace_root_t *vspace)
{
    ctSlot->cap = cap;
    *pml4Slot = pml4e;
    invalidatePageStructureCacheASID(addrFromPPtr(vspace), cap_pdpt_cap_get_capPDPTMappedASID(cap),
                                     0);

    return EXCEPTION_NONE;
}

static exception_t decodeX64PDPTInvocation(
    word_t label,
    word_t length,
    cte_t *cte,
    cap_t cap,
    extra_caps_t extraCaps,
    word_t *buffer)
{
    word_t vaddr;
    vm_attributes_t attr;
    pml4e_t *pml4Slot;
    cap_t vspaceCap;
    vspace_root_t *vspace;
    pml4e_t pml4e;
    paddr_t paddr;
    asid_t asid;

    if (label == X86PDPTUnmap) {
        if (!isFinalCapability(cte)) {
            current_syscall_error.type = seL4_RevokeFirst;
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86PDPT: Cannot unmap if more than one cap exist." ">>" "\033[0m" "\n", 0lu, __func__, 1319, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksCurThread, ThreadState_Restart);

        return performX64PDPTInvocationUnmap(cap, cte);
    }

    if (label != X86PDPTMap) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86PDPT: Illegal operation." ">>" "\033[0m" "\n", 0lu, __func__, 1329, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (length < 2 || extraCaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X64PDPT: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 1335, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cap_pdpt_cap_get_capPDPTIsMapped(cap)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X64PDPT: PDPT is already mapped to a PML4." ">>" "\033[0m" "\n", 0lu, __func__, 1341, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vaddr = getSyscallArg(0, buffer) & (~((1ul << (((((12) + 9) + 9) + 9)))-1ul));
    attr = vmAttributesFromWord(getSyscallArg(1, buffer));
    vspaceCap = extraCaps.excaprefs[0]->cap;

    if (!isValidNativeRoot(vspaceCap)) {
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vspace = (vspace_root_t *)(pptr_t)cap_get_capPtr(vspaceCap);
    asid = cap_get_capMappedASID(vspaceCap);

    if (vaddr > 0x7FFFFFFFFFFFul) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X64PDPT: Mapping address too high." ">>" "\033[0m" "\n", 0lu, __func__, 1363, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    findVSpaceForASID_ret_t find_ret;

    find_ret = findVSpaceForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        return EXCEPTION_SYSCALL_ERROR;
    }

    if (find_ret.vspace_root != vspace) {
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    pml4Slot = lookupPML4Slot(vspace, vaddr);

    if (pml4e_ptr_get_present(pml4Slot)) {
        current_syscall_error.type = seL4_DeleteFirst;

        return EXCEPTION_SYSCALL_ERROR;
    }

    paddr = addrFromPPtr(((pdpte_t *)((cap_pdpt_cap_get_capPDPTBasePtr(cap)))));
    pml4e = makeUserPML4E(paddr, attr);

    cap = cap_pdpt_cap_set_capPDPTIsMapped(cap, 1);
    cap = cap_pdpt_cap_set_capPDPTMappedASID(cap, asid);
    cap = cap_pdpt_cap_set_capPDPTMappedAddress(cap, vaddr);

    setThreadState(ksCurThread, ThreadState_Restart);
    return performX64PDPTInvocationMap(cap, cte, pml4e, pml4Slot, vspace);
}

exception_t decodeX86ModeMMUInvocation(
    word_t label,
    word_t length,
    cptr_t cptr,
    cte_t *cte,
    cap_t cap,
    extra_caps_t extraCaps,
    word_t *buffer
)
{
    switch (cap_get_capType(cap)) {

    case cap_pml4_cap:
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;

    case cap_pdpt_cap:
        return decodeX64PDPTInvocation(label, length, cte, cap, extraCaps, buffer);

    case cap_page_directory_cap:
        return decodeX64PageDirectoryInvocation(label, length, cte, cap, extraCaps, buffer);

    default:
        _fail("Invalid arch cap type", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 1429, __func__);
    }
}

bool_t modeUnmapPage(vm_page_size_t page_size, vspace_root_t *vroot, vptr_t vaddr, void *pptr)
{
    if (1 && page_size == X64_HugePage) {
        pdpte_t *pdpte;
        lookupPDPTSlot_ret_t pdpt_ret = lookupPDPTSlot(vroot, vaddr);
        if (pdpt_ret.status != EXCEPTION_NONE) {
            return false;
        }
        pdpte = pdpt_ret.pdptSlot;


        if (!(pdpte_ptr_get_page_size(pdpte) == pdpte_pdpte_1g
              && pdpte_pdpte_1g_ptr_get_present(pdpte)
              && (pdpte_pdpte_1g_ptr_get_page_base_address(pdpte)
                  == addrFromPPtr(pptr)))) {
            return false;
        }

        *pdpte = makeUserPDPTEInvalid();
        return true;
    }
    _fail("Invalid page type", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 1454, __func__);
    return false;
}

static exception_t updatePDPTE(asid_t asid, pdpte_t pdpte, pdpte_t *pdptSlot, vspace_root_t *vspace)
{
    *pdptSlot = pdpte;
    invalidatePageStructureCacheASID(addrFromPPtr(vspace), asid,
                                     0);
    return EXCEPTION_NONE;
}

static exception_t performX64ModeMap(cap_t cap, cte_t *ctSlot, pdpte_t pdpte, pdpte_t *pdptSlot, vspace_root_t *vspace)
{
    ctSlot->cap = cap;
    return updatePDPTE(cap_frame_cap_get_capFMappedASID(cap), pdpte, pdptSlot, vspace);
}

struct create_mapping_pdpte_return {
    exception_t status;
    pdpte_t pdpte;
    pdpte_t *pdptSlot;
};
typedef struct create_mapping_pdpte_return create_mapping_pdpte_return_t;

static create_mapping_pdpte_return_t createSafeMappingEntries_PDPTE(paddr_t base, word_t vaddr, vm_rights_t vmRights,
                                                                    vm_attributes_t attr,
                                                                    vspace_root_t *vspace)
{
    create_mapping_pdpte_return_t ret;
    lookupPDPTSlot_ret_t lu_ret;

    lu_ret = lookupPDPTSlot(vspace, vaddr);
    if (lu_ret.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;
        ret.status = EXCEPTION_SYSCALL_ERROR;
        /* current_lookup_fault will have been set by lookupPDSlot */
        return ret;
    }
    ret.pdptSlot = lu_ret.pdptSlot;

    /* check for existing page directory */
    if ((pdpte_ptr_get_page_size(ret.pdptSlot) == pdpte_pdpte_pd) &&
        (pdpte_pdpte_pd_ptr_get_present(ret.pdptSlot))) {
        current_syscall_error.type = seL4_DeleteFirst;
        ret.status = EXCEPTION_SYSCALL_ERROR;
        return ret;
    }

    ret.pdpte = makeUserPDPTEHugePage(base, attr, vmRights);
    ret.status = EXCEPTION_NONE;
    return ret;
}

exception_t decodeX86ModeMapPage(word_t label, vm_page_size_t page_size, cte_t *cte, cap_t cap,
                                 vspace_root_t *vroot, vptr_t vaddr, paddr_t paddr, vm_rights_t vm_rights, vm_attributes_t vm_attr)
{
    if (1 && page_size == X64_HugePage) {
        create_mapping_pdpte_return_t map_ret;

        map_ret = createSafeMappingEntries_PDPTE(paddr, vaddr, vm_rights, vm_attr, vroot);
        if (map_ret.status != EXCEPTION_NONE) {
            return map_ret.status;
        }

        setThreadState(ksCurThread, ThreadState_Restart);

        switch (label) {
        case X86PageMap:
            return performX64ModeMap(cap, cte, map_ret.pdpte, map_ret.pdptSlot, vroot);

        default:
            current_syscall_error.type = seL4_IllegalOperation;
            return EXCEPTION_SYSCALL_ERROR;
        }
    }
    _fail("Invalid Page type", "/host/kernel/src/arch/x86/64/kernel/vspace.c", 1531, __func__);
}


typedef struct readWordFromVSpace_ret {
    exception_t status;
    word_t value;
} readWordFromVSpace_ret_t;

static readWordFromVSpace_ret_t readWordFromVSpace(vspace_root_t *vspace, word_t vaddr)
{
    readWordFromVSpace_ret_t ret;
    lookupPTSlot_ret_t ptSlot;
    lookupPDSlot_ret_t pdSlot;
    lookupPDPTSlot_ret_t pdptSlot;
    paddr_t paddr;
    word_t offset;
    pptr_t kernel_vaddr;
    word_t *value;

    pdptSlot = lookupPDPTSlot(vspace, vaddr);
    if (pdptSlot.status == EXCEPTION_NONE &&
        pdpte_ptr_get_page_size(pdptSlot.pdptSlot) == pdpte_pdpte_1g &&
        pdpte_pdpte_1g_ptr_get_present(pdptSlot.pdptSlot)) {

        paddr = pdpte_pdpte_1g_ptr_get_page_base_address(pdptSlot.pdptSlot);
        offset = vaddr & ((1ul << (30))-1ul);
    } else {
        pdSlot = lookupPDSlot(vspace, vaddr);
        if (pdSlot.status == EXCEPTION_NONE &&
            ((pde_ptr_get_page_size(pdSlot.pdSlot) == pde_pde_large) &&
             pde_pde_large_ptr_get_present(pdSlot.pdSlot))) {

            paddr = pde_pde_large_ptr_get_page_base_address(pdSlot.pdSlot);
            offset = vaddr & ((1ul << (21))-1ul);
        } else {
            ptSlot = lookupPTSlot(vspace, vaddr);
            if (ptSlot.status == EXCEPTION_NONE && pte_ptr_get_present(ptSlot.ptSlot)) {
                paddr = pte_ptr_get_page_base_address(ptSlot.ptSlot);
                offset = vaddr & ((1ul << (12))-1ul);
            } else {
                ret.status = EXCEPTION_LOOKUP_FAULT;
                return ret;
            }
        }
    }


    kernel_vaddr = (word_t)ptrFromPAddr(paddr);
    value = (word_t *)(kernel_vaddr + offset);
    ret.status = EXCEPTION_NONE;
    ret.value = *value;
    return ret;
}

void Arch_userStackTrace(tcb_t *tptr)
{
    cap_t threadRoot;
    vspace_root_t *vspace_root;
    word_t sp;
    int i;

    threadRoot = (((cte_t *)((word_t)(tptr)&~((1ul << (11))-1ul)))+(tcbVTable))->cap;

    /* lookup the PD */
    if (cap_get_capType(threadRoot) != cap_pml4_cap) {
        kprintf("Invalid vspace\n");
        return;
    }

    vspace_root = (vspace_root_t *)(pptr_t)cap_get_capPtr(threadRoot);

    sp = getRegister(tptr, RSP);
    /* check for alignment so we don't have to worry about accessing
     * words that might be on two different pages */
    if (!(!((sp) & ((1ul << (3))-1ul)))) {
        kprintf("RSP not aligned\n");
        return;
    }

    for (i = 0; i < 16; i++) {
        word_t address = sp + (i * sizeof(word_t));
        readWordFromVSpace_ret_t result;
        result = readWordFromVSpace(vspace_root, address);
        if (result.status == EXCEPTION_NONE) {
            kprintf("0x%lx: 0x%lx\n", (long)address, (long)result.value);
        } else {
            kprintf("0x%lx: INVALID\n", (long)address);
        }
    }
}
# 1 "/host/kernel/src/arch/x86/64/machine/capdl.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 14 "/host/kernel/src/arch/x86/64/machine/capdl.c"
static void obj_frame_print_attrs(paddr_t paddr, word_t page_size);
static void _cap_frame_print_attrs_vptr(word_t vptr, vspace_root_t *vspace);
static void cap_frame_print_attrs_vptr(word_t vptr, cap_t vspace);
static void obj_asidpool_print_attrs(cap_t asid_cap);
static void cap_frame_print_attrs_pdpt(pdpte_t *pdptSlot);
static void cap_frame_print_attrs_pd(pde_t *pdSlot);
static void cap_frame_print_attrs_pt(pte_t *ptSlot);
static void cap_frame_print_attrs_impl(word_t super_user, word_t read_write, word_t cache_disabled, word_t xd);

word_t get_tcb_sp(tcb_t *tcb)
{
    return tcb->tcbArch.tcbContext.registers[RSP];
}

/* use when only have access to pte of frames */
static void cap_frame_print_attrs_pdpt(pdpte_t *pdptSlot)
{
    cap_frame_print_attrs_impl(pdpte_pdpte_1g_ptr_get_super_user(pdptSlot),
                               pdpte_pdpte_1g_ptr_get_read_write(pdptSlot),
                               pdpte_pdpte_1g_ptr_get_cache_disabled(pdptSlot),
                               pdpte_pdpte_1g_ptr_get_xd(pdptSlot));
}
static void cap_frame_print_attrs_pd(pde_t *pdSlot)
{
    cap_frame_print_attrs_impl(pde_pde_large_ptr_get_super_user(pdSlot),
                               pde_pde_large_ptr_get_read_write(pdSlot),
                               pde_pde_large_ptr_get_cache_disabled(pdSlot),
                               pde_pde_large_ptr_get_xd(pdSlot));
}

static void cap_frame_print_attrs_pt(pte_t *ptSlot)
{
    cap_frame_print_attrs_impl(pte_ptr_get_super_user(ptSlot),
                               pte_ptr_get_read_write(ptSlot),
                               pte_ptr_get_cache_disabled(ptSlot),
                               pte_ptr_get_xd(ptSlot));
}

static void cap_frame_print_attrs_impl(word_t super_user, word_t read_write, word_t cache_disabled, word_t xd)
{
    kprintf("(");

    /* rights */
    if (read_write) {
        kprintf("RW");
    } else if (super_user) {
        kprintf("R");
    }

    if (!xd) {
        kprintf("X");
    }

    /* asid, mapping */

    if (cache_disabled) {
        kprintf(", uncached");
    }

    kprintf(")\n");
}

static void obj_frame_print_attrs(paddr_t paddr, word_t page_size)
{
    kprintf("(");

    /* VM size */
    switch (page_size) {
    case 30:
        kprintf("1G");
        break;
    case 21:
        kprintf("2M");
        break;
    case 12:
        kprintf("4k");
        break;
    }

    kprintf(", paddr: 0x%p)\n", (void *)paddr);
}

static void x86_64_obj_pt_print_slots(pde_t *pdSlot)
{
    paddr_t paddr;
    word_t page_size;
    pte_t *pt = ptrFromPAddr(pde_pde_pt_ptr_get_pt_base_address(pdSlot));

    for (word_t i = 0; i < (1ul << ((12) + 9)); i += (1UL << (12))) {
        pte_t *ptSlot = pt + ( ((i) >> ((12))) & ((1ul << (9))-1ul));

        if (pte_ptr_get_present(ptSlot)) {
            paddr = pte_ptr_get_page_base_address(ptSlot);
            page_size = 12;
            kprintf("frame_%p_%04lu = frame ", ptSlot, ( ((i) >> ((12))) & ((1ul << (9))-1ul)));
            obj_frame_print_attrs(paddr, page_size);
        }
    }
}

static void x86_64_obj_pd_print_slots(pdpte_t *pdptSlot)
{
    paddr_t paddr;
    word_t page_size;
    pde_t *pd = ptrFromPAddr(pdpte_pdpte_pd_ptr_get_pd_base_address(pdptSlot));

    for (word_t i = 0; i < (1ul << (((12) + 9) + 9)); i += (1UL << ((12) + 9))) {
        pde_t *pdSlot = pd + ( ((i) >> (((12) + 9))) & ((1ul << (9))-1ul));

        if ((pde_ptr_get_page_size(pdSlot) == pde_pde_large) && pde_pde_large_ptr_get_present(pdSlot)) {
            paddr = pde_pde_large_ptr_get_page_base_address(pdSlot);
            page_size = 21;

            kprintf("frame_%p_%04lu = frame ", pdSlot, ( ((i) >> (((12) + 9))) & ((1ul << (9))-1ul)));
            obj_frame_print_attrs(paddr, page_size);

        } else if (pde_pde_pt_ptr_get_present(pdSlot)) {
            kprintf("pt_%p_%04lu = pt\n", pdSlot, ( ((i) >> (((12) + 9))) & ((1ul << (9))-1ul)));
            x86_64_obj_pt_print_slots(pdSlot);
        }
    }
}

static void x86_64_obj_pdpt_print_slots(pml4e_t *pml4Slot)
{
    paddr_t paddr;
    word_t page_size;
    pdpte_t *pdpt = ptrFromPAddr(pml4e_ptr_get_pdpt_base_address(pml4Slot));

    for (word_t i = 0; i < (1ul << ((((12) + 9) + 9) + 9)); i += (1UL << (((12) + 9) + 9))) {
        pdpte_t *pdptSlot = pdpt + ( ((i) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul));

        if (pdpte_ptr_get_page_size(pdptSlot) == pdpte_pdpte_1g &&
            pdpte_pdpte_1g_ptr_get_present(pdptSlot)) {
            paddr = pdpte_pdpte_1g_ptr_get_page_base_address(pdptSlot);
            page_size = 30;

            kprintf("frame_%p_%04lu = frame ", pdptSlot, ( ((i) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)));
            obj_frame_print_attrs(paddr, page_size);

        } else if (pdpte_pdpte_pd_ptr_get_present(pdptSlot)) {
            kprintf("pd_%p_%04lu = pd\n", pdptSlot, ( ((i) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)));
            x86_64_obj_pd_print_slots(pdptSlot);
        }
    }
}

static void x86_64_obj_pml4_print_slots(pml4e_t *pml4)
{
    for (word_t i = 0; i < (1ul << (((((12) + 9) + 9) + 9) + 9)); i += (1UL << ((((12) + 9) + 9) + 9))) {
        pml4e_t *pml4Slot = lookupPML4Slot(pml4, i);
        if (pml4e_ptr_get_present(pml4Slot)) {
            kprintf("pdpt_%p_%04lu = pdpt\n", pml4Slot, ( ((i) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)));
            x86_64_obj_pdpt_print_slots(pml4Slot);
        }
    }
}

void obj_tcb_print_vtable(tcb_t *tcb)
{
    /* levels: PML4 -> PDPT -> PD -> PT */
    if (isValidVTableRoot((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap) && !seen((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap)) {
        pml4e_t *pml4 = ((pml4e_t *)(cap_pml4_cap_get_capPML4BasePtr((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap)));
        add_to_seen((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap);
        kprintf("%p_pd = pml4\n", pml4);
        x86_64_obj_pml4_print_slots(pml4);
    }
}

/* use when only have access to vptr of frames */
static void _cap_frame_print_attrs_vptr(word_t vptr, vspace_root_t *vspace)
{
    lookupPDPTSlot_ret_t pdptSlot = lookupPDPTSlot(vspace, vptr);
    lookupPTSlot_ret_t ptSlot;
    lookupPDSlot_ret_t pdSlot;

    if (pdptSlot.status == EXCEPTION_NONE &&
        pdpte_ptr_get_page_size(pdptSlot.pdptSlot) == pdpte_pdpte_1g &&
        pdpte_pdpte_1g_ptr_get_present(pdptSlot.pdptSlot)) {
        kprintf("frame_%p_%04lu ", pdptSlot.pdptSlot, ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)));
        cap_frame_print_attrs_pdpt(pdptSlot.pdptSlot);
    } else {
        pdSlot = lookupPDSlot(vspace, vptr);
        if (pdSlot.status == EXCEPTION_NONE &&
            ((pde_ptr_get_page_size(pdSlot.pdSlot) == pde_pde_large) &&
             pde_pde_large_ptr_get_present(pdSlot.pdSlot))) {
            kprintf("frame_%p_%04lu ", pdSlot.pdSlot, ( ((vptr) >> (((12) + 9))) & ((1ul << (9))-1ul)));
            cap_frame_print_attrs_pd(pdSlot.pdSlot);
        } else {
            ptSlot = lookupPTSlot(vspace, vptr);
            if(!(ptSlot.status == EXCEPTION_NONE && pte_ptr_get_present(ptSlot.ptSlot))) _assert_fail("ptSlot.status == EXCEPTION_NONE && pte_ptr_get_present(ptSlot.ptSlot)", "/host/kernel/src/arch/x86/64/machine/capdl.c", 204, __FUNCTION__);
            kprintf("frame_%p_%04lu ", ptSlot.ptSlot, ( ((vptr) >> ((12))) & ((1ul << (9))-1ul)));
            cap_frame_print_attrs_pt(ptSlot.ptSlot);
        }
    }
}

static void cap_frame_print_attrs_vptr(word_t vptr, cap_t vspace)
{
    asid_t asid = cap_pml4_cap_get_capPML4MappedASID(vspace);
    findVSpaceForASID_ret_t find_ret = findVSpaceForASID(asid);
    _cap_frame_print_attrs_vptr(vptr, find_ret.vspace_root);
}

void print_cap_arch(cap_t cap)
{
    switch (cap_get_capType(cap)) {
    /* arch specific caps */
    case cap_page_table_cap: {
        asid_t asid = cap_page_table_cap_get_capPTMappedASID(cap);
        findVSpaceForASID_ret_t find_ret = findVSpaceForASID(asid);
        vptr_t vptr = cap_page_table_cap_get_capPTMappedAddress(cap);
        if (asid) {
            kprintf("pt_%p_%04lu (asid: %lu)\n", lookupPDSlot(find_ret.vspace_root, vptr).pdSlot, ( ((vptr) >> (((12) + 9))) & ((1ul << (9))-1ul)), (long unsigned int)asid)
                                                                                                                ;
        } else {
            kprintf("pt_%p_%04lu\n", lookupPDSlot(find_ret.vspace_root, vptr).pdSlot, ( ((vptr) >> (((12) + 9))) & ((1ul << (9))-1ul)));
        }
        break;
    }
    case cap_page_directory_cap: {
        asid_t asid = cap_page_directory_cap_get_capPDMappedASID(cap);
        findVSpaceForASID_ret_t find_ret = findVSpaceForASID(asid);
        vptr_t vptr = cap_page_directory_cap_get_capPDMappedAddress(cap);
        if (asid) {
            kprintf("pd_%p_%04lu (asid: %lu)\n", lookupPDPTSlot(find_ret.vspace_root, vptr).pdptSlot, ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)), (long unsigned int)asid)
                                                                                                                      ;
        } else {
            kprintf("pd_%p_%04lu\n", lookupPDPTSlot(find_ret.vspace_root, vptr).pdptSlot, ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)));
        }
        break;
    }
    case cap_pdpt_cap: {
        asid_t asid = cap_pdpt_cap_get_capPDPTMappedASID(cap);
        findVSpaceForASID_ret_t find_ret = findVSpaceForASID(asid);
        vptr_t vptr = cap_pdpt_cap_get_capPDPTMappedAddress(cap);
        if (asid) {
            kprintf("pdpt_%p_%04lu (asid: %lu)\n", lookupPML4Slot(find_ret.vspace_root, vptr), ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)), (long unsigned int)asid)
                                                                                                             ;
        } else {
            kprintf("pdpt_%p_%04lu\n", lookupPML4Slot(find_ret.vspace_root, vptr), ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)));
        }
        break;
    }
    case cap_pml4_cap: {
        asid_t asid = cap_pml4_cap_get_capPML4MappedASID(cap);
        findVSpaceForASID_ret_t find_ret = findVSpaceForASID(asid);
        if (asid) {
            kprintf("%p_pd (asid: %lu)\n", find_ret.vspace_root, (long unsigned int)asid)
                                                                 ;
        } else {
            kprintf("%p_pd\n", find_ret.vspace_root);
        }
        break;
    }
    case cap_asid_control_cap: {
        /* only one in the system */
        kprintf("asid_control\n");
        break;
    }
    case cap_frame_cap: {
        vptr_t vptr = cap_frame_cap_get_capFMappedAddress(cap);
        findVSpaceForASID_ret_t find_ret = findVSpaceForASID(cap_frame_cap_get_capFMappedASID(cap));
        if(!(find_ret.status == EXCEPTION_NONE)) _assert_fail("find_ret.status == EXCEPTION_NONE", "/host/kernel/src/arch/x86/64/machine/capdl.c", 277, __FUNCTION__);
        _cap_frame_print_attrs_vptr(vptr, find_ret.vspace_root);
        break;
    }
    case cap_asid_pool_cap: {
        kprintf("%p_asid_pool\n", (void *)cap_asid_pool_cap_get_capASIDPool(cap));
        break;
    }






    /* X86 specific caps */
    case cap_io_port_cap: {
        kprintf("%p%p_io_port\n", (void *)cap_io_port_cap_get_capIOPortFirstPort(cap), (void *)cap_io_port_cap_get_capIOPortLastPort(cap))
                                                                  ;
        break;
    }
# 307 "/host/kernel/src/arch/x86/64/machine/capdl.c"
    default: {
        kprintf("[unknown cap %lu]\n", (long unsigned int)cap_get_capType(cap));
        break;
    }
    }
}

static void obj_asidpool_print_attrs(cap_t asid_cap)
{
    asid_t asid = cap_asid_pool_cap_get_capASIDBase(asid_cap);
    kprintf("(asid_high: 0x%lx)\n", ((asid >> asidLowBits) & ((1ul << (asidHighBits))-1ul)));
}

void print_object_arch(cap_t cap)
{
    switch (cap_get_capType(cap)) {
    /* arch specific objects */
    case cap_frame_cap:
    case cap_page_table_cap:
    case cap_page_directory_cap:
    case cap_pdpt_cap:
    case cap_pml4_cap:
        /* don't need to deal with these objects since they get handled from vtable */
        break;

    case cap_asid_pool_cap: {
        kprintf("%p_asid_pool = asid_pool ", (void *)cap_asid_pool_cap_get_capASIDPool(cap))
                                                              ;
        obj_asidpool_print_attrs(cap);
        break;
    }






    /* X86 specific caps */
    case cap_io_port_cap: {
        kprintf("%p%p_io_port = io_port ", (void *)cap_io_port_cap_get_capIOPortFirstPort(cap), (void *)cap_io_port_cap_get_capIOPortLastPort(cap))

                                                                  ;
        x86_obj_ioports_print_attrs(cap);
        break;
    }
# 364 "/host/kernel/src/arch/x86/64/machine/capdl.c"
    default: {
        kprintf("[unknown object %lu]\n", (long unsigned int)cap_get_capType(cap));
        break;
    }
    }
}

void print_ipc_buffer_slot(tcb_t *tcb)
{
    word_t vptr = tcb->tcbIPCBuffer;
    kprintf("ipc_buffer_slot: ");
    cap_frame_print_attrs_vptr(vptr, (((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap);
}

static void x86_64_cap_pt_print_slots(pde_t *pdSlot, vptr_t vptr)
{
    pte_t *pt = ptrFromPAddr(pde_pde_pt_ptr_get_pt_base_address(pdSlot));
    kprintf("pt_%p_%04lu {\n", pdSlot, ( ((vptr) >> (((12) + 9))) & ((1ul << (9))-1ul)));

    for (word_t i = 0; i < (1ul << ((12) + 9)); i += (1UL << (12))) {
        pte_t *ptSlot = pt + ( ((i) >> ((12))) & ((1ul << (9))-1ul));

        if (pte_ptr_get_present(ptSlot)) {
            kprintf("0x%lx: frame_%p_%04lu ", ( ((i) >> ((12))) & ((1ul << (9))-1ul)), ptSlot, ( ((i) >> ((12))) & ((1ul << (9))-1ul)));
            cap_frame_print_attrs_pt(ptSlot);
        }
    }
    kprintf("}\n"); /* pt */
}

static void x86_64_cap_pd_print_slots(pdpte_t *pdptSlot, vptr_t vptr)
{
    pde_t *pd = ptrFromPAddr(pdpte_pdpte_pd_ptr_get_pd_base_address(pdptSlot));
    kprintf("pd_%p_%04lu {\n", pdptSlot, ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)));

    for (word_t i = 0; i < (1ul << (((12) + 9) + 9)); i += (1UL << ((12) + 9))) {
        pde_t *pdSlot = pd + ( ((i) >> (((12) + 9))) & ((1ul << (9))-1ul));

        if ((pde_ptr_get_page_size(pdSlot) == pde_pde_large) && pde_pde_large_ptr_get_present(pdSlot)) {
            kprintf("0x%lx: frame_%p_%04lu ", ( ((i) >> (((12) + 9))) & ((1ul << (9))-1ul)), pdSlot, ( ((i) >> (((12) + 9))) & ((1ul << (9))-1ul)));
            cap_frame_print_attrs_pd(pdSlot);

        } else if (pde_pde_pt_ptr_get_present(pdSlot)) {
            kprintf("0x%lx: pt_%p_%04lu\n", ( ((i) >> (((12) + 9))) & ((1ul << (9))-1ul)), pdSlot, ( ((i) >> (((12) + 9))) & ((1ul << (9))-1ul)));
        }
    }
    kprintf("}\n"); /* pd */

    for (word_t i = 0; i < (1ul << (((12) + 9) + 9)); i += (1UL << ((12) + 9))) {
        pde_t *pdSlot = pd + ( ((i) >> (((12) + 9))) & ((1ul << (9))-1ul));
        if ((pde_ptr_get_page_size(pdSlot) == pde_pde_pt) && pde_pde_pt_ptr_get_present(pdSlot)) {
            x86_64_cap_pt_print_slots(pdSlot, i);
        }
    }
}

static void x86_64_cap_pdpt_print_slots(pml4e_t *pml4Slot, vptr_t vptr)
{
    pdpte_t *pdpt = ptrFromPAddr(pml4e_ptr_get_pdpt_base_address(pml4Slot));

    kprintf("pdpt_%p_%04lu {\n", pml4Slot, ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)));
    for (word_t i = 0; i < (1ul << ((((12) + 9) + 9) + 9)); i += (1UL << (((12) + 9) + 9))) {
        pdpte_t *pdptSlot = pdpt + ( ((i) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul));

        if (pdpte_ptr_get_page_size(pdptSlot) == pdpte_pdpte_1g &&
            pdpte_pdpte_1g_ptr_get_present(pdptSlot)) {
            kprintf("0x%lx: frame_%p_%04lu ", ( ((i) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)), pdptSlot, ( ((i) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)));
            cap_frame_print_attrs_pdpt(pdptSlot);

        } else if (pdpte_pdpte_pd_ptr_get_present(pdptSlot)) {
            kprintf("0x%lx: pd_%p_%04lu\n", ( ((i) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)), pdptSlot, ( ((i) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)));
        }
    }
    kprintf("}\n"); /* pdpt */

    for (word_t i = 0; i < (1ul << ((((12) + 9) + 9) + 9)); i += (1UL << (((12) + 9) + 9))) {
        pdpte_t *pdptSlot = pdpt + ( ((i) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul));

        if (pdpte_ptr_get_page_size(pdptSlot) == pdpte_pdpte_pd && pdpte_pdpte_pd_ptr_get_present(pdptSlot)) {
            x86_64_cap_pd_print_slots(pdptSlot, i);
        }
    }
}

static void x86_64_cap_pml4_print_slots(pml4e_t *pml4)
{
    kprintf("%p_pd {\n", pml4);
    for (word_t i = 0; i < (1ul << (((((12) + 9) + 9) + 9) + 9)); i += (1UL << ((((12) + 9) + 9) + 9))) {
        pml4e_t *pml4Slot = lookupPML4Slot(pml4, i);
        if (pml4e_ptr_get_present(pml4Slot)) {
            kprintf("0x%lx: pdpt_%p_%04lu\n", ( ((i) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)), pml4Slot, ( ((i) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)));
        }
    }
    kprintf("}\n"); /* pml4 */

    for (word_t i = 0; i < (1ul << (((((12) + 9) + 9) + 9) + 9)); i += (1UL << ((((12) + 9) + 9) + 9))) {
        pml4e_t *pml4Slot = lookupPML4Slot(pml4, i);
        if (pml4e_ptr_get_present(pml4Slot)) {
            x86_64_cap_pdpt_print_slots(pml4Slot, i);
        }
    }
}

void obj_vtable_print_slots(tcb_t *tcb)
{
    /* levels: PML4 -> PDPT -> PD -> PT */
    if (isValidVTableRoot((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap) && !seen((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap)) {
        pml4e_t *pml4 = ((pml4e_t *)(cap_pml4_cap_get_capPML4BasePtr((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap)));
        add_to_seen((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap);
        x86_64_cap_pml4_print_slots(pml4);
    }
}

void capDL(void)
{
    kprintf("arch x86_64\n");
    kprintf("objects {\n");
    print_objects();
    kprintf("}\n");

    kprintf("caps {\n");

    /* reset the seen list */
    reset_seen_list();

    print_caps();
    kprintf("}\n");

    obj_irq_print_maps();
}
# 1 "/host/kernel/src/arch/x86/64/machine/registerset.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */






const register_t msgRegisters[] = {
    R10, R8, R9, R15
};
typedef int __assert_failed_consistent_message_registers[(sizeof(msgRegisters) / sizeof(msgRegisters[0]) == n_msgRegisters) ? 1 : -1];


 ;

const register_t frameRegisters[] = {
    FaultIP, RSP, FLAGS, RAX, RBX, RCX, RDX, RSI, RDI, RBP,
    R8, R9, R10, R11, R12, R13, R14, R15
};
typedef int __assert_failed_consistent_frame_registers[(sizeof(frameRegisters) / sizeof(frameRegisters[0]) == n_frameRegisters) ? 1 : -1];


 ;

const register_t gpRegisters[] = {
    FS_BASE, GS_BASE
};
typedef int __assert_failed_consistent_gp_registers[(sizeof(gpRegisters) / sizeof(gpRegisters[0]) == n_gpRegisters) ? 1 : -1];


 ;

void Mode_initContext(user_context_t *context)
{
    context->registers[RAX] = 0;
    context->registers[RBX] = 0;
    context->registers[RCX] = 0;
    context->registers[RDX] = 0;
    context->registers[RSI] = 0;
    context->registers[RDI] = 0;
    context->registers[RBP] = 0;
    context->registers[R8] = 0;
    context->registers[R9] = 0;
    context->registers[R10] = 0;
    context->registers[R11] = 0;
    context->registers[R12] = 0;
    context->registers[R13] = 0;
    context->registers[R14] = 0;
    context->registers[R15] = 0;
    context->registers[RSP] = 0;
}

word_t Mode_sanitiseRegister(register_t reg, word_t v)
{
    if (reg == FaultIP || reg == NextIP || reg == FS_BASE || reg == GS_BASE) {
        /* ensure instruction address is canonical */
        if (v > 0x00007fffffffffff && v < 0xffff800000000000) {
            /* no way to guess what the user wanted so give them zero */
            v = 0;
        }
    }
    return v;
}
# 1 "/host/kernel/src/arch/x86/64/model/smp.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/arch/x86/64/model/statedata.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */



/* The privileged kernel mapping PD & PT */
pml4e_t x64KSKernelPML4[(1ul << (9))] __attribute__((__aligned__((1ul << (12))))) __attribute__((externally_visible));
pdpte_t x64KSKernelPDPT[(1ul << (9))] __attribute__((__aligned__((1ul << (12)))));

pde_t x64KSKernelPD[(1ul << (9))] __attribute__((__aligned__((1ul << (12)))));



pte_t x64KSKernelPT[(1ul << (9))] __attribute__((__aligned__((1ul << (12)))));


pml4e_t x64KSSKIMPML4[(1ul << (9))] __attribute__((__aligned__((1ul << (12)))));
pdpte_t x64KSSKIMPDPT[(1ul << (9))] __attribute__((__aligned__((1ul << (12)))));
pde_t x64KSSKIMPD[(1ul << (9))] __attribute__((__aligned__((1ul << (12)))));



word_t x64KSCurrentUserCR3;




word_t x64KSIRQStack[1][6 + 2] __attribute__((__aligned__(64))) __attribute__((externally_visible)) __attribute__((__section__(".skim.bss")));
# 1 "/host/kernel/src/arch/x86/64/object/objecttype.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 17 "/host/kernel/src/arch/x86/64/object/objecttype.c"
# 1 "/host/kernel/include/arch/x86/arch/kernel/ept.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 18 "/host/kernel/src/arch/x86/64/object/objecttype.c" 2





bool_t Arch_isFrameType(word_t type)
{
    switch (type) {
    case seL4_X86_4K:
        return true;
    case seL4_X86_LargePageObject:
        return true;
    case seL4_X64_HugePageObject:
        return true;
    default:
        return false;
    }
}

deriveCap_ret_t Mode_deriveCap(cte_t *slot, cap_t cap)
{
    deriveCap_ret_t ret;

    switch (cap_get_capType(cap)) {
    case cap_pml4_cap:
        if (cap_pml4_cap_get_capPML4IsMapped(cap)) {
            ret.cap = cap;
            ret.status = EXCEPTION_NONE;
        } else {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Deriving a PML4 cap without an assigned ASID" ">>" "\033[0m" "\n", 0lu, __func__, 47, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            ret.cap = cap_null_cap_new();
            ret.status = EXCEPTION_SYSCALL_ERROR;
        }
        return ret;

    case cap_pdpt_cap:
        if (cap_pdpt_cap_get_capPDPTIsMapped(cap)) {
            ret.cap = cap;
            ret.status = EXCEPTION_NONE;
        } else {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Deriving an unmapped PTPD cap" ">>" "\033[0m" "\n", 0lu, __func__, 59, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            ret.cap = cap_null_cap_new();
            ret.status = EXCEPTION_SYSCALL_ERROR;
        }
        return ret;

    case cap_frame_cap:
        cap = cap_frame_cap_set_capFMapType(cap, X86_MappingNone);
        ret.cap = cap_frame_cap_set_capFMappedASID(cap, asidInvalid);
        ret.status = EXCEPTION_NONE;
        return ret;

    default:
        _fail("Invalid arch cap type", "/host/kernel/src/arch/x86/64/object/objecttype.c", 73, __func__);
    }
}

finaliseCap_ret_t Mode_finaliseCap(cap_t cap, bool_t final)
{
    finaliseCap_ret_t fc_ret;

    switch (cap_get_capType(cap)) {

    case cap_pml4_cap:
        if (final && cap_pml4_cap_get_capPML4IsMapped(cap)) {
            deleteASID(
                cap_pml4_cap_get_capPML4MappedASID(cap),
                ((pml4e_t *)(cap_pml4_cap_get_capPML4BasePtr(cap)))
            );
        }
        break;

    case cap_pdpt_cap:
        if (final && cap_pdpt_cap_get_capPDPTIsMapped(cap)) {
            unmapPDPT(
                cap_pdpt_cap_get_capPDPTMappedASID(cap),
                cap_pdpt_cap_get_capPDPTMappedAddress(cap),
                ((pdpte_t *)(cap_pdpt_cap_get_capPDPTBasePtr(cap)))
            );
        }
        break;

    case cap_frame_cap:
        if (cap_frame_cap_get_capFMappedASID(cap)) {
            switch (cap_frame_cap_get_capFMapType(cap)) {
# 120 "/host/kernel/src/arch/x86/64/object/objecttype.c"
            case X86_MappingVSpace:
                unmapPage(
                    cap_frame_cap_get_capFSize(cap),
                    cap_frame_cap_get_capFMappedASID(cap),
                    cap_frame_cap_get_capFMappedAddress(cap),
                    (void *)cap_frame_cap_get_capFBasePtr(cap)
                );
                break;
            default:
                _fail("Invalid map type", "/host/kernel/src/arch/x86/64/object/objecttype.c", 129, __func__);
            }
        }
        break;

    default:
        _fail("Invalid arch cap type", "/host/kernel/src/arch/x86/64/object/objecttype.c", 135, __func__);
    }

    fc_ret.remainder = cap_null_cap_new();
    fc_ret.cleanupInfo = cap_null_cap_new();
    return fc_ret;
}

bool_t __attribute__((__const__)) Mode_sameRegionAs(cap_t cap_a, cap_t cap_b)
{
    switch (cap_get_capType(cap_a)) {

    case cap_pdpt_cap:
        if (cap_get_capType(cap_b) == cap_pdpt_cap) {
            return cap_pdpt_cap_get_capPDPTBasePtr(cap_a) ==
                   cap_pdpt_cap_get_capPDPTBasePtr(cap_b);
        }
        return false;

    case cap_pml4_cap:
        if (cap_get_capType(cap_b) == cap_pml4_cap) {
            return cap_pml4_cap_get_capPML4BasePtr(cap_a) ==
                   cap_pml4_cap_get_capPML4BasePtr(cap_b);
        }
        return false;
    default:
        return false;
    }
}

word_t Mode_getObjectSize(word_t t)
{
    switch (t) {
    case seL4_X64_PML4Object:
        return 12;

    case seL4_X64_HugePageObject:
        return pageBitsForSize(X64_HugePage);

    default:
        _fail("Invalid object type", "/host/kernel/src/arch/x86/64/object/objecttype.c", 175, __func__);
        return 0;
    }
}

cap_t Mode_createObject(object_t t, void *regionBase, word_t userSize, bool_t deviceMemory)
{
    switch (t) {

    case seL4_X86_4K:
        if (deviceMemory) {
            /** AUXUPD: "(True, ptr_retyps 1
                     (Ptr (ptr_val \<acute>regionBase) :: user_data_device_C ptr))" */
            /** GHOSTUPD: "(True, gs_new_frames vmpage_size.X64SmallPage
                                                    (ptr_val \<acute>regionBase)
                                                    (unat X64SmallPageBits))" */
        } else {
            /** AUXUPD: "(True, ptr_retyps 1
                     (Ptr (ptr_val \<acute>regionBase) :: user_data_C ptr))" */
            /** GHOSTUPD: "(True, gs_new_frames vmpage_size.X64SmallPage
                                                    (ptr_val \<acute>regionBase)
                                                    (unat X64SmallPageBits))" */
        }
        return cap_frame_cap_new(
                   asidInvalid, /* capFMappedASID           */
                   (word_t)regionBase, /* capFBasePtr              */
                   X86_SmallPage, /* capFSize                 */
                   X86_MappingNone, /* capFMapType              */
                   0, /* capFMappedAddress        */
                   VMReadWrite, /* capFVMRights             */
                   deviceMemory /* capFIsDevice             */
               );

    case seL4_X86_LargePageObject:
        if (deviceMemory) {
            /** AUXUPD: "(True, ptr_retyps 512
                     (Ptr (ptr_val \<acute>regionBase) :: user_data_device_C ptr))" */
            /** GHOSTUPD: "(True, gs_new_frames vmpage_size.X64LargePage
                                                    (ptr_val \<acute>regionBase)
                                                    (unat X64LargePageBits))" */
        } else {
            /** AUXUPD: "(True, ptr_retyps 512
                     (Ptr (ptr_val \<acute>regionBase) :: user_data_C ptr))" */
            /** GHOSTUPD: "(True, gs_new_frames vmpage_size.X64LargePage
                                                    (ptr_val \<acute>regionBase)
                                                    (unat X64LargePageBits))" */
        }
        return cap_frame_cap_new(
                   asidInvalid, /* capFMappedASID           */
                   (word_t)regionBase, /* capFBasePtr              */
                   X86_LargePage, /* capFSize                 */
                   X86_MappingNone, /* capFMapType              */
                   0, /* capFMappedAddress        */
                   VMReadWrite, /* capFVMRights             */
                   deviceMemory /* capFIsDevice             */
               );

    case seL4_X64_HugePageObject:
        if (deviceMemory) {
            /** AUXUPD: "(True, ptr_retyps 262144
                     (Ptr (ptr_val \<acute>regionBase) :: user_data_device_C ptr))" */
            /** GHOSTUPD: "(True, gs_new_frames vmpage_size.X64HugePage
                                                    (ptr_val \<acute>regionBase)
                                                    (unat X64HugePageBits))" */
        } else {
            /** AUXUPD: "(True, ptr_retyps 262144
                     (Ptr (ptr_val \<acute>regionBase) :: user_data_C ptr))" */
            /** GHOSTUPD: "(True, gs_new_frames vmpage_size.X64HugePage
                                                    (ptr_val \<acute>regionBase)
                                                    (unat X64HugePageBits))" */
        }
        return cap_frame_cap_new(
                   asidInvalid, /* capFMappedASID           */
                   (word_t)regionBase, /* capFBasePtr              */
                   X64_HugePage, /* capFSize                 */
                   X86_MappingNone, /* capFMapType              */
                   0, /* capFMappedAddress        */
                   VMReadWrite, /* capFVMRights             */
                   deviceMemory /* capFIsDevice             */
               );

    case seL4_X86_PageTableObject:
        /** AUXUPD: "(True, ptr_retyps 1
              (Ptr (ptr_val \<acute>regionBase) :: (pte_C[512]) ptr))" */
        return cap_page_table_cap_new(
                   asidInvalid, /* capPTMappedASID    */
                   (word_t)regionBase, /* capPTBasePtr       */
                   0, /* capPTIsMapped      */
                   0 /* capPTMappedAddress */
               );

    case seL4_X86_PageDirectoryObject:
        /** AUXUPD: "(True, ptr_retyps 1
              (Ptr (ptr_val \<acute>regionBase) :: (pde_C[512]) ptr))" */
        return cap_page_directory_cap_new(
                   asidInvalid, /* capPDMappedASID      */
                   (word_t)regionBase, /* capPDBasePtr         */
                   0, /* capPDIsMapped        */
                   0 /* capPDMappedAddress   */
               );

    case seL4_X86_PDPTObject:
        /** AUXUPD: "(True, ptr_retyps 1
              (Ptr (ptr_val \<acute>regionBase) :: (pdpte_C[512]) ptr))" */
        return cap_pdpt_cap_new(
                   asidInvalid, /* capPDPTMappedASID    */
                   (word_t)regionBase, /* capPDPTBasePtr       */
                   0, /* capPDPTIsMapped      */
                   0 /* capPDPTMappedAddress */
               );

    case seL4_X64_PML4Object:
        /** AUXUPD: "(True, ptr_retyps 1
              (Ptr (ptr_val \<acute>regionBase) :: (pml4e_C[512]) ptr))" */
        copyGlobalMappings(((pml4e_t *)(regionBase)));
        return cap_pml4_cap_new(
                   asidInvalid, /* capPML4MappedASID   */
                   (word_t)regionBase, /* capPML4BasePtr      */
                   0 /* capPML4IsMapped     */
               );
# 307 "/host/kernel/src/arch/x86/64/object/objecttype.c"
    default:
        /*
         * This is a conflation of the haskell error: "Arch.createNewCaps
         * got an API type" and the case where an invalid object type is
         * passed (which is impossible in haskell).
         */
        _fail("Arch_createObject got an API type or invalid object type", "/host/kernel/src/arch/x86/64/object/objecttype.c", 313, __func__);
    }
}

exception_t Mode_decodeInvocation(
    word_t label,
    word_t length,
    cptr_t cptr,
    cte_t *slot,
    cap_t cap,
    extra_caps_t extraCaps,
    word_t *buffer
)
{
    switch (cap_get_capType(cap)) {
    case cap_pml4_cap:
    case cap_pdpt_cap:
    case cap_page_directory_cap:
    case cap_page_table_cap:
    case cap_frame_cap:
        return decodeX86MMUInvocation(label, length, cptr, slot, cap, extraCaps, buffer);

    default:
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;
        return EXCEPTION_SYSCALL_ERROR;
    }
}
# 1 "/host/kernel/src/arch/x86/64/smp/ipi.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/arch/x86/api/faults.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */







bool_t Arch_handleFaultReply(tcb_t *receiver, tcb_t *sender, word_t faultType)
{
    switch (faultType) {
    case seL4_Fault_VMFault:
        return true;

    default:
        _fail("Invalid fault", "/host/kernel/src/arch/x86/api/faults.c", 20, __func__);
    }
}

word_t Arch_setMRs_fault(tcb_t *sender, tcb_t *receiver, word_t *receiveIPCBuffer, word_t faultType)
{
    switch (faultType) {
    case seL4_Fault_VMFault: {
        setMR(receiver, receiveIPCBuffer, seL4_VMFault_IP, getRestartPC(sender));
        setMR(receiver, receiveIPCBuffer, seL4_VMFault_Addr,
              seL4_Fault_VMFault_get_address(sender->tcbFault));
        setMR(receiver, receiveIPCBuffer, seL4_VMFault_PrefetchFault,
              seL4_Fault_VMFault_get_instructionFault(sender->tcbFault));
        return setMR(receiver, receiveIPCBuffer, seL4_VMFault_FSR,
                     seL4_Fault_VMFault_get_FSR(sender->tcbFault));
    }
    default:
        _fail("Invalid fault", "/host/kernel/src/arch/x86/api/faults.c", 37, __func__);
    }
}

word_t handleKernelException(
    word_t vector,
    word_t errcode,
    word_t ip,
    word_t sp,
    word_t flags,
    word_t cr0,
    word_t cr2,
    word_t cr3,
    word_t cr4
);

__attribute__((externally_visible))
word_t handleKernelException(
    word_t vector,
    word_t errcode,
    word_t ip,
    word_t sp,
    word_t flags,
    word_t cr0,
    word_t cr2,
    word_t cr3,
    word_t cr4
)
{
    word_t i;

    /* Check if we are in a state where we expect a GP fault, if so record it and return */
    if (vector == int_gp_fault && x86KSGPExceptReturnTo != 0) {
        word_t ret = x86KSGPExceptReturnTo;
        x86KSGPExceptReturnTo = 0;
        return ret;
    }
    kprintf("\n========== KERNEL EXCEPTION ==========\n");
    kprintf("Vector:  0x%lx\n", vector);
    kprintf("ErrCode: 0x%lx\n", errcode);
    kprintf("IP:      0x%lx\n", ip);
    kprintf("SP:      0x%lx\n", sp);
    kprintf("FLAGS:   0x%lx\n", flags);
    kprintf("CR0:     0x%lx\n", cr0);
    kprintf("CR2:     0x%lx (page-fault address)\n", cr2);
    kprintf("CR3:     0x%lx (page-directory physical address)\n", cr3);
    kprintf("CR4:     0x%lx\n", cr4);
    kprintf("\nStack Dump:\n");
    for (i = 0; i < 20; i++) {
        word_t __attribute__((unused)) stack = sp + i * sizeof(word_t);
        kprintf("*0x%lx == 0x%lx\n", stack, *(word_t *)stack);
    }
    kprintf("\nHalting...\n");
    halt();
    __builtin_unreachable();
}
# 1 "/host/kernel/src/arch/x86/benchmark/benchmark.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/arch/x86/c_traps.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




# 1 "/host/kernel/include/arch/x86/arch/fastpath/fastpath.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

# 1 "/host/kernel/include/arch/x86/arch/64/mode/fastpath/fastpath.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       







/* seL4 is always in the top of memory, so the high bits of pointers are always 1.
   The autogenerated unpacking code doesn't know that, however, so will try to
   conditionally sign extend (in 64-bit mode), which wastes cycles in the fast
   path. Instead, we can do the unpacking ourselves and explicitly set the high
   bits. */

static inline tcb_t *endpoint_ptr_get_epQueue_tail_fp(endpoint_t *ep_ptr)
{
    uint64_t ret = ep_ptr->words[0] & 0xfffffffffffcull;
    return __builtin_expect(!!(ret), 0) ? ((tcb_t *)(ret | 0xffffff8000000000ul)) : ((void *)0);
}

static inline vspace_root_t *cap_vtable_cap_get_vspace_root_fp(cap_t vtable_cap)
{
    return ((pml4e_t *)(vtable_cap.words[1]));
}

static inline word_t cap_pml4_cap_get_capPML4MappedASID_fp(cap_t vtable_cap)
{
    return (uint32_t)vtable_cap.words[0];
}

static inline void __attribute__((always_inline)) switchToThread_fp(tcb_t *thread, vspace_root_t *vroot, pde_t stored_hw_asid)
{
    word_t new_vroot = addrFromPPtr(vroot);
    /* the asid is the 12-bit PCID */
    asid_t asid = (asid_t)(stored_hw_asid.words[0] & 0xfff);
    cr3_t next_cr3 = makeCR3(new_vroot, asid);
    if (__builtin_expect(!!(getCurrentUserCR3().words[0] != next_cr3.words[0]), 1)) {
       
        setCurrentUserCR3(next_cr3);
    }
# 55 "/host/kernel/include/arch/x86/arch/64/mode/fastpath/fastpath.h"
    if (0) {
        x86_ibpb();
    }

    if (0) {
        x86_flush_rsb();
    }





    ksCurThread = thread;
}


static inline void thread_state_ptr_set_blockingIPCDiminish_np(thread_state_t *ts_ptr, word_t dim)
{
    ts_ptr->words[1] = (ts_ptr->words[1] & 1) | dim;
}

static inline void mdb_node_ptr_mset_mdbNext_mdbRevocable_mdbFirstBadged(
    mdb_node_t *node_ptr, word_t mdbNext,
    word_t mdbRevocable, word_t mdbFirstBadged)
{
    node_ptr->words[1] = mdbNext | (mdbRevocable << 1) | mdbFirstBadged;
}

static inline void mdb_node_ptr_set_mdbPrev_np(mdb_node_t *node_ptr, word_t mdbPrev)
{
    node_ptr->words[0] = mdbPrev;
}


static inline bool_t isValidVTableRoot_fp(cap_t vspace_root_cap)
{
    /* Check the cap is a pml4_cap, and that it is mapped. The fields are next
       to each other, so they can be read and checked in parallel */
    return (vspace_root_cap.words[0] >> (64 - 6)) == ((cap_pml4_cap << 1) | 0x1);
}

static inline void fastpath_copy_mrs(word_t length, tcb_t *src, tcb_t *dest)
{
    word_t i;
    register_t reg;

    /* assuming that length < n_msgRegisters */
    for (i = 0; i < length; i ++) {
        /* assuming that the message registers simply increment */
        reg = msgRegisters[0] + i;
        setRegister(dest, reg, getRegister(src, reg));
    }
}

/* This is an accelerated check that msgLength, which appears
   in the bottom of the msgInfo word, is <= 4 and that msgExtraCaps
   which appears above it is zero. We are assuming that n_msgRegisters == 4
   for this check to be useful. By masking out the bottom 3 bits, we are
   really checking that n + 3 <= MASK(3), i.e. n + 3 <= 7 or n <= 4. */
typedef int __assert_failed_n_msgRegisters_eq_4[(n_msgRegisters == 4) ? 1 : -1];
static inline int
fastpath_mi_check(word_t msgInfo)
{
    return ((msgInfo & ((1ul << (seL4_MsgLengthBits + seL4_MsgExtraCapBits))-1ul))
            + 3) & ~((1ul << (3))-1ul);
}

static inline void __attribute__((__noreturn__)) __attribute__((always_inline)) fastpath_restore(word_t badge, word_t msgInfo, tcb_t *cur_thread)
{
    if (0 && 0
        && ((getRegister(ksCurThread, FLAGS) & (1ul << (8)) /* Trap Flag */) != 0)) {
        /* If single stepping using sysenter we need to do a return using iret to avoid
         * a race condition in restoring the flags (which enables stepping and interrupts) and
         * calling sysexit. This case is handled in restore_user_context so we just go there
         */
        restore_user_context();
    }
    do {} while (0);
    c_exit_hook();
    lazyFPURestore(cur_thread);

    if (1) {
        /* see restore_user_context for a full explanation of why we do this */
        word_t *irqstack = x64KSIRQStack[0];
        irqstack[0] = 0;
        irqstack[1] = 0;
        irqstack[2] = 0;
        irqstack[3] = 0;
        irqstack[4] = 0;
        irqstack[5] = 0;
    }
# 158 "/host/kernel/include/arch/x86/arch/64/mode/fastpath/fastpath.h"
    if (0) {
        x86_disable_ibrs();
    }

    if (0) {
        cur_thread->tcbArch.tcbContext.registers[FLAGS] &= ~(1ul << (9)) /* Interrupt enable Flag */;




        __asm__ volatile(
            "movq %%rcx, %%rsp\n"
            "popq %%rax\n"
            "popq %%rbx\n"
            "popq %%rbp\n"
            "popq %%r12\n"
            "popq %%r13\n"
            "popq %%r14\n"
            // Skip RDX, we need to put NextIP into it
            "addq $8, %%rsp\n"
            "popq %%r10\n"
            "popq %%r8\n"
            "popq %%r9\n"
            "popq %%r15\n"
            // restore RFLAGS
            "popfq\n"
            // reset interrupt bit
            "orq %[IF], -8(%%rsp)\n"
            // Restore NextIP
            "popq %%rdx\n"
            // skip Error
            "addq $8, %%rsp\n"
            // restore RSP
            "popq %%rcx\n"
            // Skip FaultIP
            "addq $8, %%rsp\n"





            "popq %%r11\n"

            "movq (x64KSCurrentUserCR3), %%rsp\n"
            "movq %%rsp, %%cr3\n"


            "sti\n"
            "sysexitq\n"
            :
            : "c"(&cur_thread->tcbArch.tcbContext.registers[RAX]),
            "D"(badge),
            "S"(msgInfo),



            [IF] "i"((1ul << (9)) /* Interrupt enable Flag */)
            : "memory"
        );
    } else {
        __asm__ volatile(
            // Set our stack pointer to the top of the tcb so we can efficiently pop
            "movq %0, %%rsp\n"
            "popq %%rax\n"
            "popq %%rbx\n"
            "popq %%rbp\n"
            "popq %%r12\n"
            "popq %%r13\n"
            "popq %%r14\n"
            "popq %%rdx\n"
            "popq %%r10\n"
            "popq %%r8\n"
            "popq %%r9\n"
            "popq %%r15\n"
            //restore RFLAGS
            "popq %%r11\n"
            // Restore NextIP





            "popq %%rcx\n"

            "movq (x64KSCurrentUserCR3), %%rsp\n"
            "movq %%rsp, %%cr3\n"


            // clear RSP to not leak information to the user
            "xor %%rsp, %%rsp\n"
            // More register but we can ignore and are done restoring
            // enable interrupt disabled by sysenter
            "sysretq\n"
            :
            : "r"(&cur_thread->tcbArch.tcbContext.registers[RAX]),
            "D"(badge),
            "S"(msgInfo)



            : "memory"
        );
    }
    __builtin_unreachable();
}
# 10 "/host/kernel/include/arch/x86/arch/fastpath/fastpath.h" 2


static inline int fastpath_reply_cap_check(cap_t cap)
{
    return cap_capType_equals(cap, cap_reply_cap);
}


void slowpath(syscall_t syscall)
__attribute__((__noreturn__));

void fastpath_call(word_t cptr, word_t r_msgInfo)
__attribute__((__noreturn__));




void fastpath_reply_recv(word_t cptr, word_t r_msgInfo)

__attribute__((__noreturn__));
# 11 "/host/kernel/src/arch/x86/c_traps.c" 2




# 1 "/host/kernel/libsel4/arch_include/x86/sel4/arch/vmenter.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

       

/*
 * When performing a seL4_SysVMEnter seL4 expects certain guest state to be
 * placed in the message registers. These defines indicates which MRs hold
 * which values. Whenever a VMEnter returns seL4 will also fill these registers
 * with the corresponding guest state
 */




/*
 * In addition to the above message registers, if a VMEnter results in
 * a fault the following constants describe the contents of the message
 * registers that contain fault specific information
 */
# 39 "/host/kernel/libsel4/arch_include/x86/sel4/arch/vmenter.h"
/*
 * After performing a seL4_SysVMEnter the msgInfo register is set to indicate
 * whether a return back to this thread happened due to a fault in the associated
 * VCPU, or a notification was received on the bound notification object.
 * If using the seL4_VMEnter wrapper function, then this is the return value
 *
 * In the case of a notification the badge register is the received notification
 * and the message registers are set in the same format as we passed them to
 * seL4_SysVMEnter
 *
 * If a fault is returned then the badge register is empty and the message
 * format is a combination of the format we passed to seL4_SysVMEnter with
 * additional registers described with the SEL4_VMENTER_FAULT_ constants
 */



/*
 * Constants describing the number of message registers returned by the
 * kernel for each of the return cases of VMEnter
 */
# 16 "/host/kernel/src/arch/x86/c_traps.c" 2




void __attribute__((externally_visible)) c_nested_interrupt(int irq)
{
    /* This is not a real entry point, so we do not grab locks or
     * run c_entry/exit_hooks, since this occurs only if we're already
     * running inside the kernel. Just record the irq and return */
    if(!(x86KSPendingInterrupt == int_invalid)) _assert_fail("ARCH_NODE_STATE(x86KSPendingInterrupt) == int_invalid", "/host/kernel/src/arch/x86/c_traps.c", 25, __FUNCTION__);
    x86KSPendingInterrupt = irq;
}

void __attribute__((externally_visible)) __attribute__((__noreturn__)) c_handle_interrupt(int irq, int syscall)
{
    /* need to run this first as the NODE_LOCK code might end up as a function call
     * with a return, and we need to make sure returns are not exploitable yet
     * on x64 this code ran already */
    if (0 && 0) {
        x86_enable_ibrs();
    }

    /* Only grab the lock if we are not handeling 'int_remote_call_ipi' interrupt
     * also flag this lock as IRQ lock if handling the irq interrupts. */
    do {} while (0)
                                                          ;

    c_entry_hook();

    if (irq == int_unimpl_dev) {
        handleFPUFault();

        ksKernelEntry.path = Entry_UnimplementedDevice;
        ksKernelEntry.word = irq;

    } else if (irq == int_page_fault) {
        /* Error code is in Error. Pull out bit 5, which is whether it was instruction or data */
        vm_fault_type_t type = (ksCurThread->tcbArch.tcbContext.registers[Error] >> 4u) & 1u;

        ksKernelEntry.path = Entry_VMFault;
        ksKernelEntry.word = type;

        handleVMFaultEvent(type);
# 68 "/host/kernel/src/arch/x86/c_traps.c"
    } else if (irq < int_irq_min) {

        ksKernelEntry.path = Entry_UserLevelFault;
        ksKernelEntry.word = irq;

        handleUserLevelFault(irq, ksCurThread->tcbArch.tcbContext.registers[Error]);
    } else if (__builtin_expect(!!(irq < int_trap_min), 1)) {
        x86KScurInterrupt = irq;

        ksKernelEntry.path = Entry_Interrupt;
        ksKernelEntry.word = irq;

        handleInterruptEntry();
        /* check for other pending interrupts */
        receivePendingIRQ();
    } else if (irq == int_spurious) {
        /* fall through to restore_user_context and do nothing */
    } else {
        /* Interpret a trap as an unknown syscall */
        /* Adjust FaultIP to point to trapping INT
         * instruction by subtracting 2 */
        int sys_num;
        ksCurThread->tcbArch.tcbContext.registers[FaultIP] -= 2;
        /* trap number is MSBs of the syscall number and the LSBS of EAX */
        sys_num = (irq << 24) | (syscall & 0x00ffffff);

        ksKernelEntry.path = Entry_UnknownSyscall;
        ksKernelEntry.word = sys_num;

        handleUnknownSyscall(sys_num);
    }
    restore_user_context();
    __builtin_unreachable();
}

void __attribute__((__noreturn__)) slowpath(syscall_t syscall)
{
# 123 "/host/kernel/src/arch/x86/c_traps.c"
    /* check for undefined syscall */
    if (__builtin_expect(!!(syscall < (-8) || syscall > (-1)), 0)) {

        ksKernelEntry.path = Entry_UnknownSyscall;
        /* ksKernelEntry.word word is already set to syscall */

        handleUnknownSyscall(syscall);
    } else {

        ksKernelEntry.is_fastpath = 0;

        handleSyscall(syscall);
    }

    restore_user_context();
    __builtin_unreachable();
}




void __attribute__((externally_visible)) __attribute__((__noreturn__)) c_handle_syscall(word_t cptr, word_t msgInfo, syscall_t syscall)

{
    /* need to run this first as the NODE_LOCK code might end up as a function call
     * with a return, and we need to make sure returns are not exploitable yet */
    if (0) {
        x86_enable_ibrs();
    }

    do {} while (0);

    c_entry_hook();


    benchmark_debug_syscall_start(cptr, msgInfo, syscall);
    ksKernelEntry.is_fastpath = 1;


    if (0) {
        /* increment NextIP to skip sysenter */
        ksCurThread->tcbArch.tcbContext.registers[NextIP] += 2;
    } else {
        /* set FaultIP */
        setRegister(ksCurThread, FaultIP, getRegister(ksCurThread, NextIP) - 2);
    }


    if (syscall == (syscall_t)SysCall) {
        fastpath_call(cptr, msgInfo);
        __builtin_unreachable();
    } else if (syscall == (syscall_t)SysReplyRecv) {



        fastpath_reply_recv(cptr, msgInfo);

        __builtin_unreachable();
    }

    slowpath(syscall);
    __builtin_unreachable();
}
# 1 "/host/kernel/src/arch/x86/idle.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




void idle_thread(void)
{
    while (1) {
        __asm__ volatile("hlt");
    }
}

/** DONT_TRANSLATE */
void __attribute__((externally_visible)) halt(void)
{
    /* halt is actually, idle thread without the interrupts */
    __asm__ volatile("cli");


    kprintf("halting...");

    debug_printKernelEntryReason();


    idle_thread();
    __builtin_unreachable();
}
# 1 "/host/kernel/src/arch/x86/kernel/apic.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */







# 1 "/host/kernel/include/plat/pc99/plat/machine/pit.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

/* ms after which a wraparound occurs (max. 54) */


void pit_init(void);
void pit_wait_wraparound(void);
# 14 "/host/kernel/src/arch/x86/kernel/apic.c" 2





static __attribute__((__section__(".boot.text"))) uint32_t apic_measure_freq(void)
{
    pit_init();
    /* wait for 1st PIT wraparound */
    pit_wait_wraparound();

    /* start APIC timer countdown */
    apic_write_reg(APIC_TIMER_DIVIDE, 0xb); /* divisor = 1 */
    apic_write_reg(APIC_TIMER_COUNT, 0xffffffff);

    /* wait for 2nd PIT wraparound */
    pit_wait_wraparound();

    /* calculate APIC/bus cycles per ms = frequency in kHz */
    return (0xffffffff - apic_read_reg(APIC_TIMER_CURRENT)) / 50;
}

__attribute__((__section__(".boot.text"))) paddr_t apic_get_base_paddr(void)
{
    apic_base_msr_t apic_base_msr;

    apic_base_msr.words[0] = x86_rdmsr_low(0x01B);
    return apic_base_msr_get_base_addr(apic_base_msr);
}

__attribute__((__section__(".boot.text"))) bool_t apic_init(bool_t mask_legacy_irqs)
{
    apic_version_t apic_version;
    uint32_t num_lvt_entries;
    uint32_t apic_khz;

    if (!apic_enable()) {
        return false;
    }
# 69 "/host/kernel/src/arch/x86/kernel/apic.c"
    apic_khz = apic_measure_freq();

    apic_version.words[0] = apic_read_reg(APIC_VERSION);

    /* check for correct version (both APIC and x2APIC): 0x1X */
    if (apic_version_get_version(apic_version) >> 4 != 1) {
        kprintf("APIC: apic_version must be 0x1X\n");
        return false;
    }
# 86 "/host/kernel/src/arch/x86/kernel/apic.c"
    /* check for correct number of LVT entries */
    num_lvt_entries = apic_version_get_max_lvt_entry(apic_version) + 1;
    if (num_lvt_entries < 3) {
        kprintf("APIC: number of LVT entries: %d\n", num_lvt_entries);
        kprintf("APIC: number of LVT entries must be >= 3\n");
        return false;
    }


    /* initialise APIC timer */
    apic_write_reg(APIC_TIMER_DIVIDE, 0xb); /* divisor = 1 */
    apic_write_reg(APIC_TIMER_COUNT, apic_khz * 2);


    /* enable APIC using SVR register */
    apic_write_reg(
        APIC_SVR,
        apic_svr_new(
            0, /* focus_processor_chk */
            1, /* enabled             */
            int_spurious /* spurious_vector     */
        ).words[0]
    );

    /* mask/unmask LINT0 (used for legacy IRQ delivery) */
    apic_write_reg(
        APIC_LVT_LINT0,
        apic_lvt_new(
            0, /* timer_mode      */
            mask_legacy_irqs, /* masked          */
            0, /* trigger_mode    */
            0, /* remote_irr      */
            0, /* pin_polarity    */
            0, /* delivery_status */
            7, /* delivery_mode   */
            0 /* vector          */
        ).words[0]
    );

    /* mask LINT1 (used for NMI delivery) */
    apic_write_reg(
        APIC_LVT_LINT1,
        apic_lvt_new(
            0, /* timer_mode      */
            1, /* masked          */
            0, /* trigger_mode    */
            0, /* remote_irr      */
            0, /* pin_polarity    */
            0, /* delivery_status */
            0, /* delivery_mode   */
            0 /* vector          */
        ).words[0]
    );

    /* initialise timer */




    uint32_t timer_mode = 1;

    apic_write_reg(
        APIC_LVT_TIMER,
        apic_lvt_new(
            timer_mode,
            0, /* masked          */
            0, /* trigger_mode    */
            0, /* remote_irr      */
            0, /* pin_polarity    */
            0, /* delivery_status */
            0, /* delivery_mode   */
            int_timer /* vector          */
        ).words[0]
    );

    /*
    printf("APIC: ID=0x%x\n", apic_read_reg(APIC_ID) >> 24);
    printf("APIC: SVR=0x%x\n", apic_read_reg(APIC_SVR));
    printf("APIC: LVT_TIMER=0x%x\n", apic_read_reg(APIC_LVT_TIMER));
    printf("APIC: LVT_LINT0=0x%x\n", apic_read_reg(APIC_LVT_LINT0));
    printf("APIC: LVT_LINT1=0x%x\n", apic_read_reg(APIC_LVT_LINT1));
    printf("APIC: LVT_ERROR=0x%x\n", apic_read_reg(APIC_LVT_ERROR));
    printf("APIC: LVT_PERF_CNTR=0x%x\n", apic_read_reg(APIC_LVT_PERF_CNTR));
    printf("APIC: LVT_THERMAL=0x%x\n", apic_read_reg(APIC_LVT_THERMAL));
    */
    return true;
}

void apic_ack_active_interrupt(void)
{
    apic_write_reg(APIC_EOI, 0);
}
# 1 "/host/kernel/src/arch/x86/kernel/boot.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 19 "/host/kernel/src/arch/x86/kernel/boot.c"
# 1 "/host/kernel/include/arch/x86/arch/machine/timer.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 69 "/host/kernel/include/arch/x86/arch/machine/timer.h"
static inline void resetTimer(void)
{
    /* nothing to do */
}



__attribute__((__section__(".boot.text"))) uint32_t tsc_init(void);
# 20 "/host/kernel/src/arch/x86/kernel/boot.c" 2







__attribute__((__section__(".boot.data"))) static region_t reserved[1];

/* functions exactly corresponding to abstract specification */

__attribute__((__section__(".boot.text"))) static void init_irqs(cap_t root_cnode_cap)
{
    irq_t i;

    for (i = 0; i <= maxIRQ; i++) {
        if (i == irq_timer) {
            setIRQState(IRQTimer, i);
# 46 "/host/kernel/src/arch/x86/kernel/boot.c"
        } else if (i == 2 && 0) {
            /* cascaded legacy PIC */
            setIRQState(IRQReserved, i);
        } else if (i >= irq_isa_min && i <= irq_isa_max) {
            if (0) {
                setIRQState(IRQInactive, i);
            } else {
                setIRQState(IRQReserved, i);
            }
        } else if (i >= irq_user_min && i <= irq_user_max) {
            if (1) {
                setIRQState(IRQInactive, i);
            } else {
                setIRQState(IRQReserved, i);
            }
        } else {
            setIRQState(IRQReserved, i);
        }
    }
    Arch_irqStateInit();
    /* provide the IRQ control cap */
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapIRQControl)), cap_irq_control_cap_new());
}

__attribute__((__section__(".boot.text"))) static bool_t create_untypeds(
    cap_t root_cnode_cap,
    region_t boot_mem_reuse_reg)
{
    seL4_SlotPos slot_pos_before;
    seL4_SlotPos slot_pos_after;

    slot_pos_before = ndks_boot.slot_pos_cur;
    create_device_untypeds(root_cnode_cap, slot_pos_before);
    create_kernel_untypeds(root_cnode_cap, boot_mem_reuse_reg, slot_pos_before);

    slot_pos_after = ndks_boot.slot_pos_cur;
    ndks_boot.bi_frame->untyped = (seL4_SlotRegion) {
        slot_pos_before, slot_pos_after
    };
    return true;
}

__attribute__((__section__(".boot.text"))) static void arch_init_freemem(p_region_t ui_p_reg, v_region_t v_reg,
                                        mem_p_regs_t *mem_p_regs, word_t extra_bi_size_bits)
{
    ui_p_reg.start = 0;
    reserved[0] = paddr_to_pptr_reg(ui_p_reg);
    init_freemem(mem_p_regs->count, mem_p_regs->list, 1, reserved, v_reg, extra_bi_size_bits);
}

/* This function initialises a node's kernel state. It does NOT initialise the CPU. */

__attribute__((__section__(".boot.text"))) bool_t init_sys_state(
    cpu_id_t cpu_id,
    mem_p_regs_t *mem_p_regs,
    ui_info_t ui_info,
    p_region_t boot_mem_reuse_p_reg,
    /* parameters below not modeled in abstract specification */
    uint32_t num_drhu,
    paddr_t *drhu_list,
    acpi_rmrr_list_t *rmrr_list,
    acpi_rsdp_t *acpi_rsdp,
    seL4_X86_BootInfo_VBE *vbe,
    seL4_X86_BootInfo_mmap_t *mb_mmap,
    seL4_X86_BootInfo_fb_t *fb_info
)
{
    cap_t root_cnode_cap;
    vptr_t extra_bi_frame_vptr;
    vptr_t bi_frame_vptr;
    vptr_t ipcbuf_vptr;
    cap_t it_vspace_cap;
    cap_t it_ap_cap;
    cap_t ipcbuf_cap;
    word_t extra_bi_size = sizeof(seL4_BootInfoHeader);
    pptr_t extra_bi_offset = 0;
    uint32_t tsc_freq;
    create_frames_of_region_ret_t create_frames_ret;
    create_frames_of_region_ret_t extra_bi_ret;

    /* convert from physical addresses to kernel pptrs */
    region_t ui_reg = paddr_to_pptr_reg(ui_info.p_reg);
    region_t boot_mem_reuse_reg = paddr_to_pptr_reg(boot_mem_reuse_p_reg);

    /* convert from physical addresses to userland vptrs */
    v_region_t ui_v_reg;
    v_region_t it_v_reg;
    ui_v_reg.start = ui_info.p_reg.start - ui_info.pv_offset;
    ui_v_reg.end = ui_info.p_reg.end - ui_info.pv_offset;

    ipcbuf_vptr = ui_v_reg.end;
    bi_frame_vptr = ipcbuf_vptr + (1ul << (12));
    extra_bi_frame_vptr = bi_frame_vptr + (1ul << (12));

    if (vbe->vbeMode != -1) {
        extra_bi_size += sizeof(seL4_X86_BootInfo_VBE);
    }
    if (acpi_rsdp) {
        extra_bi_size += sizeof(seL4_BootInfoHeader) + sizeof(*acpi_rsdp);
    }
    if (fb_info && fb_info->addr) {
        extra_bi_size += sizeof(seL4_BootInfoHeader) + sizeof(*fb_info);
    }

    word_t mb_mmap_size = sizeof(seL4_X86_BootInfo_mmap_t);
    extra_bi_size += mb_mmap_size;

    // room for tsc frequency
    extra_bi_size += sizeof(seL4_BootInfoHeader) + 4;
    word_t extra_bi_size_bits = calculate_extra_bi_size_bits(extra_bi_size);

    /* The region of the initial thread is the user image + ipcbuf and boot info */
    it_v_reg.start = ui_v_reg.start;
    it_v_reg.end = (((((extra_bi_frame_vptr + (1ul << (extra_bi_size_bits))) - 1ul) >> (12)) + 1ul) << (12));







    arch_init_freemem(ui_info.p_reg, it_v_reg, mem_p_regs, extra_bi_size_bits);

    /* create the root cnode */
    root_cnode_cap = create_root_cnode();

    /* create the IO port cap */
    write_slot(
        (((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapIOPortControl)),
        cap_io_port_control_cap_new()
    );

    /* create the cap for managing thread domains */
    create_domain_cap(root_cnode_cap);

    /* initialise the IRQ states and provide the IRQ control cap */
    init_irqs(root_cnode_cap);

    tsc_freq = tsc_init();

    /* populate the bootinfo frame */
    populate_bi_frame(0, ksNumCPUs, ipcbuf_vptr, extra_bi_size);
    region_t extra_bi_region = {
        .start = rootserver.extra_bi,
        .end = rootserver.extra_bi + (1ul << (extra_bi_size_bits))
    };

    /* populate vbe info block */
    if (vbe->vbeMode != -1) {
        vbe->header.id = 1;
        vbe->header.len = sizeof(seL4_X86_BootInfo_VBE);
        memcpy((void *)(rootserver.extra_bi + extra_bi_offset), vbe, sizeof(seL4_X86_BootInfo_VBE));
        extra_bi_offset += sizeof(seL4_X86_BootInfo_VBE);
    }

    /* populate acpi rsdp block */
    if (acpi_rsdp) {
        seL4_BootInfoHeader header;
        header.id = 3;
        header.len = sizeof(header) + sizeof(*acpi_rsdp);
        *(seL4_BootInfoHeader *)(rootserver.extra_bi + extra_bi_offset) = header;
        extra_bi_offset += sizeof(header);
        memcpy((void *)(rootserver.extra_bi + extra_bi_offset), acpi_rsdp, sizeof(*acpi_rsdp));
        extra_bi_offset += sizeof(*acpi_rsdp);
    }

    /* populate framebuffer information block */
    if (fb_info && fb_info->addr) {
        seL4_BootInfoHeader header;
        header.id = 4;
        header.len = sizeof(header) + sizeof(*fb_info);
        *(seL4_BootInfoHeader *)(rootserver.extra_bi + extra_bi_offset) = header;
        extra_bi_offset += sizeof(header);
        memcpy((void *)(rootserver.extra_bi + extra_bi_offset), fb_info, sizeof(*fb_info));
        extra_bi_offset += sizeof(*fb_info);
    }

    /* populate multiboot mmap block */
    mb_mmap->header.id = 2;
    mb_mmap->header.len = mb_mmap_size;
    memcpy((void *)(rootserver.extra_bi + extra_bi_offset), mb_mmap, mb_mmap_size);
    extra_bi_offset += mb_mmap_size;

    /* populate tsc frequency block */
    {
        seL4_BootInfoHeader header;
        header.id = 5 /* frequency is in mhz*/;
        header.len = sizeof(header) + 4;
        *(seL4_BootInfoHeader *)(extra_bi_region.start + extra_bi_offset) = header;
        extra_bi_offset += sizeof(header);
        *(uint32_t *)(extra_bi_region.start + extra_bi_offset) = tsc_freq;
        extra_bi_offset += 4;
    }

    /* provde a chunk for any leftover padding in the extended boot info */
    seL4_BootInfoHeader padding_header;
    padding_header.id = 0;
    padding_header.len = (extra_bi_region.end - extra_bi_region.start) - extra_bi_offset;
    *(seL4_BootInfoHeader *)(extra_bi_region.start + extra_bi_offset) = padding_header;






    /* Construct an initial address space with enough virtual addresses
     * to cover the user image + ipc buffer and bootinfo frames */
    it_vspace_cap = create_it_address_space(root_cnode_cap, it_v_reg);
    if (cap_get_capType(it_vspace_cap) == cap_null_cap) {
        return false;
    }

    /* Create and map bootinfo frame cap */
    create_bi_frame_cap(
        root_cnode_cap,
        it_vspace_cap,
        bi_frame_vptr
    );

    /* create and map extra bootinfo region */
    extra_bi_ret =
        create_frames_of_region(
            root_cnode_cap,
            it_vspace_cap,
            extra_bi_region,
            true,
            addrFromPPtr((void *)(extra_bi_region.start - extra_bi_frame_vptr))
        );
    if (!extra_bi_ret.success) {
        return false;
    }
    ndks_boot.bi_frame->extraBIPages = extra_bi_ret.region;

    /* create the initial thread's IPC buffer */
    ipcbuf_cap = create_ipcbuf_frame_cap(root_cnode_cap, it_vspace_cap, ipcbuf_vptr);
    if (cap_get_capType(ipcbuf_cap) == cap_null_cap) {
        return false;
    }

    /* create all userland image frames */
    create_frames_ret =
        create_frames_of_region(
            root_cnode_cap,
            it_vspace_cap,
            ui_reg,
            true,
            ui_info.pv_offset
        );
    if (!create_frames_ret.success) {
        return false;
    }
    ndks_boot.bi_frame->userImageFrames = create_frames_ret.region;

    /* create the initial thread's ASID pool */
    it_ap_cap = create_it_asid_pool(root_cnode_cap);
    if (cap_get_capType(it_ap_cap) == cap_null_cap) {
        return false;
    }
    write_it_asid_pool(it_ap_cap, it_vspace_cap);





    /* create the idle thread */
    if (!create_idle_thread()) {
        return false;
    }

    /* create the initial thread */
    tcb_t *initial = create_initial_thread(root_cnode_cap,
                                           it_vspace_cap,
                                           ui_info.v_entry,
                                           bi_frame_vptr,
                                           ipcbuf_vptr,
                                           ipcbuf_cap);
    if (initial == ((void *)0)) {
        return false;
    }
    init_core_state(initial);
# 339 "/host/kernel/src/arch/x86/kernel/boot.c"
    ndks_boot.bi_frame->numIOPTLevels = -1;


    /* create all of the untypeds. Both devices and kernel window memory */
    if (!create_untypeds(root_cnode_cap, boot_mem_reuse_reg)) {
        return false;
    }

    /* finalise the bootinfo frame */
    bi_finalise();

    return true;
}

/* This function initialises the CPU. It does NOT initialise any kernel state. */

__attribute__((__section__(".boot.text"))) bool_t init_cpu(
    bool_t mask_legacy_irqs
)
{
    /* initialise virtual-memory-related data structures */
    if (!init_vm_state()) {
        return false;
    }

    /* initialise CPU's descriptor table registers (GDTR, IDTR, LDTR, TR) */
    init_dtrs();

    if (0) {
        /* initialise MSRs (needs an initialised TSS) */
        init_sysenter_msrs();
    } else if (1) {
        init_syscall_msrs();
    } else {
        return false;
    }

    /* setup additional PAT MSR */
    if (!init_pat_msr()) {
        return false;
    }

    /* enable the Write Protect bit in cr0. This prevents the kernel from writing to
     * read only memory, which we shouldn't do under correct execution */
    write_cr0(read_cr0() | (1ul << (16)) /* Write protection in supervisor mode. */);

    /* check for SMAP and SMEP and enable */
    cpuid_007h_ebx_t ebx_007;
    ebx_007.words[0] = x86_cpuid_ebx(0x7, 0);
    if (cpuid_007h_ebx_get_smap(ebx_007)) {
        /* if we have user stack trace enabled or dangerous code injection then we cannot
         * enable this as SMAP will make them fault. */
        if (!1 && !0) {
            write_cr4(read_cr4() | (1ul << (21)) /* Supervisor Mode Access Prevention. */);
        }
    }
    if (cpuid_007h_ebx_get_smep(ebx_007)) {
        /* similar to smap we cannot enable smep if using dangerous code injection. it
         * does not affect stack trace printing though */
        if (!0) {
            write_cr4(read_cr4() | (1ul << (20)) /* Supervisor Mode Execution Prevention. */);
        }
    }

    if (!init_ibrs()) {
        return false;
    }






    /* initialise floating-point unit */
    if (!Arch_initFpu()) {
        return false;
    }

    /* initialise local APIC */
    if (!apic_init(mask_legacy_irqs)) {
        return false;
    }







    if (0) {
        enablePMCUser();
    }
# 439 "/host/kernel/src/arch/x86/kernel/boot.c"
    return true;
}
# 1 "/host/kernel/src/arch/x86/kernel/boot_sys.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */







# 1 "/host/kernel/include/arch/x86/arch/kernel/cmdline.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
       


typedef struct cmdline_opt {

    uint16_t console_port;


    uint16_t debug_port;

    bool_t disable_iommu;
} cmdline_opt_t;

void cmdline_parse(const char *cmdline, cmdline_opt_t *cmdline_opt);
# 14 "/host/kernel/src/arch/x86/kernel/boot_sys.c" 2


# 1 "/host/kernel/include/arch/x86/arch/kernel/smp_sys.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
/* Lower memory address to copy APs boot code in real mode. Actual memory starts at
 * 0x500 but we need to round up to a page aligned address in order to send the
 * startup IPI */

/* Limit of memory region we can copy the AP to */
# 17 "/host/kernel/src/arch/x86/kernel/boot_sys.c" 2
# 27 "/host/kernel/src/arch/x86/kernel/boot_sys.c"
/* addresses defined in linker script */
/* need a fake array to get the pointer from the linker script */

/* start/end of CPU boot code */
extern char boot_cpu_start[1];
extern char boot_cpu_end[1];

/* start/end of boot stack */
extern char boot_stack_bottom[1];
extern char boot_stack_top[1];

/* locations in kernel image */
extern char ki_boot_end[1];
extern char ki_end[1];
extern char ki_skim_start[1];
extern char ki_skim_end[1];


/* kernel entry point */
extern char _start[1];


/* constants */



__attribute__((__section__(".boot.bss")))
boot_state_t boot_state;

/* global variables (not covered by abstract specification) */

__attribute__((__section__(".boot.bss")))
cmdline_opt_t cmdline_opt;

/* functions not modeled in abstract specification */

__attribute__((__section__(".boot.text"))) static paddr_t find_load_paddr(paddr_t min_paddr, word_t image_size)
{
    int i;

    for (i = 0; i < boot_state.mem_p_regs.count; i++) {
        paddr_t start = (((min_paddr)>(boot_state.mem_p_regs.list[i].start))?(min_paddr):(boot_state.mem_p_regs.list[i].start));
        paddr_t end = boot_state.mem_p_regs.list[i].end;
        word_t region_size = end - start;

        if (region_size >= image_size) {
            return start;
        }
    }

    return 0;
}

__attribute__((__section__(".boot.text"))) static paddr_t load_boot_module(word_t boot_module_start, paddr_t load_paddr)
{
    v_region_t v_reg;
    word_t entry;
    Elf_Header_t *elf_file = (Elf_Header_t *)boot_module_start;

    if (!elf_checkFile(elf_file)) {
        kprintf("Boot module does not contain a valid ELF image\n");
        return 0;
    }

    v_reg = elf_getMemoryBounds(elf_file);
    entry = elf_file->e_entry;

    if (v_reg.end == 0) {
        kprintf("ELF image in boot module does not contain any segments\n");
        return 0;
    }
    v_reg.end = (((((v_reg.end) - 1ul) >> (12)) + 1ul) << (12));

    kprintf("size=0x%lx v_entry=%p v_start=%p v_end=%p ", v_reg.end - v_reg.start, (void *)entry, (void *)v_reg.start, (void *)v_reg.end)




           ;

    if (!(!((v_reg.start) & ((1ul << (12))-1ul)))) {
        kprintf("Userland image virtual start address must be 4KB-aligned\n");
        return 0;
    }
    if (v_reg.end + 2 * (1ul << (12)) > 0x7FFFFFFFFFFFul) {
        /* for IPC buffer frame and bootinfo frame, need 2*4K of additional userland virtual memory */
        kprintf("Userland image virtual end address too high\n");
        return 0;
    }
    if ((entry < v_reg.start) || (entry >= v_reg.end)) {
        kprintf("Userland image entry point does not lie within userland image\n");
        return 0;
    }

    load_paddr = find_load_paddr(load_paddr, v_reg.end - v_reg.start);
    if(!(load_paddr)) _assert_fail("load_paddr", "/host/kernel/src/arch/x86/kernel/boot_sys.c", 122, __FUNCTION__);

    /* fill ui_info struct */
    boot_state.ui_info.pv_offset = load_paddr - v_reg.start;
    boot_state.ui_info.p_reg.start = load_paddr;
    load_paddr += v_reg.end - v_reg.start;
    boot_state.ui_info.p_reg.end = load_paddr;
    boot_state.ui_info.v_entry = entry;

    kprintf("p_start=0x%lx p_end=0x%lx\n", boot_state.ui_info.p_reg.start, boot_state.ui_info.p_reg.end)


           ;

    /* initialise all initial userland memory and load potentially sparse ELF image */
    memzero(
        (void *)boot_state.ui_info.p_reg.start,
        boot_state.ui_info.p_reg.end - boot_state.ui_info.p_reg.start
    );
    elf_load(elf_file, boot_state.ui_info.pv_offset);

    return load_paddr;
}

static __attribute__((__section__(".boot.text"))) bool_t try_boot_sys_node(cpu_id_t cpu_id)
{
    p_region_t boot_mem_reuse_p_reg;

    if (!map_kernel_window(
            boot_state.num_ioapic,
            boot_state.ioapic_paddr,
            boot_state.num_drhu,
            boot_state.drhu_list
        )) {
        return false;
    }
    setCurrentVSpaceRoot(kpptr_to_paddr(x64KSKernelPML4), 0);
    /* Sync up the compilers view of the world here to force the PD to actually
     * be set *right now* instead of delayed */
    __asm__ volatile("" ::: "memory");


    if (!map_skim_window((vptr_t)ki_skim_start, (vptr_t)ki_skim_end)) {
        return false;
    }


    /* reuse boot code/data memory */
    boot_mem_reuse_p_reg.start = 0x00100000ul;
    boot_mem_reuse_p_reg.end = kpptr_to_paddr(ki_boot_end);

    /* initialise the CPU */
    if (!init_cpu(1 ? 1 : 0)) {
        return false;
    }

    /* initialise NDKS and kernel heap */
    if (!init_sys_state(
            cpu_id,
            &boot_state.mem_p_regs,
            boot_state.ui_info,
            boot_mem_reuse_p_reg,
            /* parameters below not modeled in abstract specification */
            boot_state.num_drhu,
            boot_state.drhu_list,
            &boot_state.rmrr_list,
            &boot_state.acpi_rsdp,
            &boot_state.vbe_info,
            &boot_state.mb_mmap_info,
            &boot_state.fb_info
        )) {
        return false;
    }

    return true;
}

static __attribute__((__section__(".boot.text"))) bool_t add_mem_p_regs(p_region_t reg)
{
    if (reg.end > (0xffffffff80000000ul - (0xffffff8000000000ul - 0x00000000ul)) && reg.start > (0xffffffff80000000ul - (0xffffff8000000000ul - 0x00000000ul))) {
        /* Return true here as it's not an error for there to exist memory outside the kernel window,
         * we're just going to ignore it and leave it to be given out as device memory */
        return true;
    }
    if (boot_state.mem_p_regs.count == 16) {
        kprintf("Dropping memory region 0x%lx-0x%lx, try increasing MAX_NUM_FREEMEM_REG\n", reg.start, reg.end);
        return false;
    }
    if (reg.end > (0xffffffff80000000ul - (0xffffff8000000000ul - 0x00000000ul))) {
        if(!(reg.start <= (0xffffffff80000000ul - (0xffffff8000000000ul - 0x00000000ul)))) _assert_fail("reg.start <= PADDR_TOP", "/host/kernel/src/arch/x86/kernel/boot_sys.c", 211, __FUNCTION__);
        /* Clamp a region to the top of the kernel window if it extends beyond */
        reg.end = (0xffffffff80000000ul - (0xffffff8000000000ul - 0x00000000ul));
    }
    kprintf("Adding physical memory region 0x%lx-0x%lx\n", reg.start, reg.end);
    boot_state.mem_p_regs.list[boot_state.mem_p_regs.count] = reg;
    boot_state.mem_p_regs.count++;
    return reserve_region(reg);
}

/*
 * the code relies that the GRUB provides correct information
 * about the actual physical memory regions.
 */
static __attribute__((__section__(".boot.text"))) bool_t parse_mem_map(uint32_t mmap_length, uint32_t mmap_addr)
{
    multiboot_mmap_t *mmap = (multiboot_mmap_t *)((word_t)mmap_addr);
    kprintf("Parsing GRUB physical memory map\n");

    while ((word_t)mmap < (word_t)(mmap_addr + mmap_length)) {
        uint64_t mem_start = mmap->base_addr;
        uint64_t mem_length = mmap->length;
        uint32_t type = mmap->type;
        if (mem_start != (uint64_t)(word_t)mem_start) {
            kprintf("\tPhysical memory region not addressable\n");
        } else {
            kprintf("\tPhysical Memory Region from %lx size %lx type %d\n", (long)mem_start, (long)mem_length, type);
            if (type == 1 && mem_start >= 0x100000) {
                if (!add_mem_p_regs((p_region_t) {
                mem_start, mem_start + mem_length
            })) {
                    return false;
                }
            }
        }
        mmap++;
    }
    return true;
}

static __attribute__((__section__(".boot.text"))) bool_t is_compiled_for_microarchitecture(void)
{
    word_t microarch_generation = 0;
    x86_cpu_identity_t *model_info = x86_cpuid_get_model_info();

    if (0) {
        microarch_generation = 7;
    } else if (0) {
        microarch_generation = 6;
    } else if (0) {
        microarch_generation = 5;
    } else if (0) {
        microarch_generation = 4;
    } else if (0) {
        microarch_generation = 3;
    } else if (0) {
        microarch_generation = 2;
    } else if (1) {
        microarch_generation = 1;
    }

    switch (model_info->model) {
    case 0x4E:
    case 0x5E:
        if (microarch_generation > 7) {
            return false;
        }
        break;

    case 0x4D:
    case 0x56:
    case 0x4F:
    case 0x47:
    case 0x3D:
        if (microarch_generation > 6) {
            return false;
        }
        break;

    case 0x3C:
    case 0x3F:
    case 0x45:
    case 0x46:
        if (microarch_generation > 5) {
            return false;
        }
        break;

    case 0x9A:
    case 0x3E:
    case 0x3A:
        if (microarch_generation > 4) {
            return false;
        }
        break;

    case 0x2A /* Sandy Bridge */:
    case 0x2D /* Sandy Bridge-E, Sandy Bridge-EN and Sandy Bridge-EP */:
        if (microarch_generation > 3) {
            return false;
        }
        break;

    case 0x25 /* Arrandale and Clarksdale */:
    case 0x2C /* Gulftown and Westmere-EP */:
    case 0x2F /* Westemere-EX */:
        if (microarch_generation > 2) {
            return false;
        }
        break;

    case 0x1E /* Clarksfield, Lynnfield and Jasper Forest */:
    case 0x1A /* Bloomfield and Nehalem-EP */:
    case 0x2E /* Nehalem-EX */:
        if (microarch_generation > 1) {
            return false;
        }
        break;

    default:
        if (!0) {
            return false;
        }
    }

    return true;
}

static __attribute__((__section__(".boot.text"))) bool_t try_boot_sys(void)
{
    paddr_t mods_end_paddr = boot_state.mods_end_paddr;
    p_region_t ui_p_regs;
    paddr_t load_paddr;

    boot_state.ki_p_reg.start = 0x00100000ul;
    boot_state.ki_p_reg.end = kpptr_to_paddr(ki_end);

    if (!x86_cpuid_initialize()) {
        kprintf("Warning: Your x86 CPU has an unsupported vendor, '%s'.\n" "\tYour setup may not be able to competently run seL4 as " "intended.\n" "\tCurrently supported x86 vendors are AMD and Intel.\n", x86_cpuid_get_identity()->vendor_string)



                                                       ;
    }

    if (!is_compiled_for_microarchitecture()) {
        kprintf("Warning: Your kernel was not compiled for the current microarchitecture.\n");
    }

    cpuid_007h_edx_t edx;
    edx.words[0] = x86_cpuid_edx(0x7, 0);
    /* see if we can definitively say whether or not we need the skim window by
     * checking whether the CPU is vulnerable to rogue data cache loads (rdcl) */
    if (cpuid_007h_edx_get_ia32_arch_cap_msr(edx)) {
        ia32_arch_capabilities_msr_t cap_msr;
        cap_msr.words[0] = x86_rdmsr(0x10A);
        if (ia32_arch_capabilities_msr_get_rdcl_no(cap_msr) && 1) {
            kprintf("CPU reports not vulnerable to Rogue Data Cache Load (aka Meltdown https://meltdownattack.com) " "yet SKIM window is enabled. Performance is needlessly being impacted, consider disabling.\n")
                                                                                                                 ;
        } else if (!ia32_arch_capabilities_msr_get_rdcl_no(cap_msr) && !1) {
            kprintf("CPU reports vulnerable to Rogue Data Cache Load (aka Meltdown https://meltdownattack.com) " "yet SKIM window is *not* enabled. Please re-build with SKIM window enabled.")
                                                                                                 ;
            return false;
        }
    } else {
        /* hardware doesn't tell us directly so guess based on CPU vendor */
        if (1 && x86_cpuid_get_identity()->vendor == X86_VENDOR_AMD) {
            kprintf("SKIM window for mitigating Meltdown (https://www.meltdownattack.com) " "not necessary for AMD and performance is being needlessly affected, " "consider disabling\n")

                                          ;
        }
        if (!1 && x86_cpuid_get_identity()->vendor == X86_VENDOR_INTEL) {
            kprintf("***WARNING*** SKIM window not enabled, this machine is probably vulnerable " "to Meltdown (https://www.meltdownattack.com), consider enabling\n")
                                                                                       ;
        }
    }
# 397 "/host/kernel/src/arch/x86/kernel/boot_sys.c"
    kprintf("Kernel loaded to: start=0x%lx end=0x%lx size=0x%lx entry=0x%lx\n", boot_state.ki_p_reg.start, boot_state.ki_p_reg.end, boot_state.ki_p_reg.end - boot_state.ki_p_reg.start, (paddr_t)_start)




           ;

    /* remapping legacy IRQs to their correct vectors */
    pic_remap_irqs(0x20);
    if (1) {
        /* Disable the PIC so that it does not generate any interrupts. We need to
         * do this *before* we initialize the apic */
        pic_disable();
    }

    /* validate the ACPI table */
    if (!acpi_validate_rsdp(&boot_state.acpi_rsdp)) {
        return false;
    }

    /* check if kernel configuration matches platform requirments */
    if (!acpi_fadt_scan(&boot_state.acpi_rsdp)) {
        return false;
    }

    if (!0 || cmdline_opt.disable_iommu) {
        boot_state.num_drhu = 0;
    } else {
        /* query available IOMMUs from ACPI */
        acpi_dmar_scan(
            &boot_state.acpi_rsdp,
            boot_state.drhu_list,
            &boot_state.num_drhu,
            ((-((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1)) >> 12),
            &boot_state.rmrr_list
        );
    }

    /* query available CPUs from ACPI */
    boot_state.num_cpus = acpi_madt_scan(&boot_state.acpi_rsdp, boot_state.cpus, &boot_state.num_ioapic,
                                         boot_state.ioapic_paddr);
    if (boot_state.num_cpus == 0) {
        kprintf("No CPUs detected\n");
        return false;
    }

    if (1) {
        if (boot_state.num_ioapic == 0) {
            kprintf("No IOAPICs detected\n");
            return false;
        }
    } else {
        if (boot_state.num_ioapic > 0) {
            kprintf("Detected %d IOAPICs, but configured to use PIC instead\n", boot_state.num_ioapic);
        }
    }

    mods_end_paddr = (((((mods_end_paddr) - 1ul) >> (12)) + 1ul) << (12));
    if(!(mods_end_paddr > boot_state.ki_p_reg.end)) _assert_fail("mods_end_paddr > boot_state.ki_p_reg.end", "/host/kernel/src/arch/x86/kernel/boot_sys.c", 455, __FUNCTION__);

    kprintf("ELF-loading userland images from boot modules:\n");
    load_paddr = mods_end_paddr;

    load_paddr = load_boot_module(boot_state.boot_module_start, load_paddr);
    if (!load_paddr) {
        return false;
    }

    /* calculate final location of userland images */
    ui_p_regs.start = boot_state.ki_p_reg.end;
    ui_p_regs.end = ui_p_regs.start + load_paddr - mods_end_paddr;

    kprintf("Moving loaded userland images to final location: from=0x%lx to=0x%lx size=0x%lx\n", mods_end_paddr, ui_p_regs.start, ui_p_regs.end - ui_p_regs.start)




     ;
    memcpy((void *)ui_p_regs.start, (void *)mods_end_paddr, ui_p_regs.end - ui_p_regs.start);

    /* adjust p_reg and pv_offset to final load address */
    boot_state.ui_info.p_reg.start -= mods_end_paddr - ui_p_regs.start;
    boot_state.ui_info.p_reg.end -= mods_end_paddr - ui_p_regs.start;
    boot_state.ui_info.pv_offset -= mods_end_paddr - ui_p_regs.start;

    /* ==== following code corresponds to abstract specification after "select" ==== */

    if (!platAddDevices()) {
        return false;
    }

    /* Total number of cores we intend to boot */
    ksNumCPUs = boot_state.num_cpus;

    kprintf("Starting node #0 with APIC ID %lu\n", boot_state.cpus[0]);
    if (!try_boot_sys_node(boot_state.cpus[0])) {
        return false;
    }

    if (1) {
        ioapic_init(1, boot_state.cpus, boot_state.num_ioapic);
    }

    /* initialize BKL before booting up APs */
    ;
    ;

    /* grab BKL before leaving the kernel */
    do {} while (0);

    kprintf("Booting all finished, dropped to user space\n");

    return true;
}

static __attribute__((__section__(".boot.text"))) bool_t try_boot_sys_mbi1(
    multiboot_info_t *mbi
)
{
    word_t i;
    multiboot_module_t *modules = (multiboot_module_t *)(word_t)mbi->part1.mod_list;

    cmdline_parse((const char *)(word_t)mbi->part1.cmdline, &cmdline_opt);

    if ((mbi->part1.flags & (1ul << (0))) == 0) {
        kprintf("Boot loader did not provide information about physical memory size\n");
        return false;
    }

    if (!(mbi->part1.flags & (1ul << (3)))) {
        kprintf("Boot loader did not provide information about boot modules\n");
        return false;
    }

    kprintf("Detected %d boot module(s):\n", mbi->part1.mod_count);

    if (mbi->part1.mod_count < 1) {
        kprintf("Expect at least one boot module (containing a userland image)\n");
        return false;
    }

    for (i = 0; i < mbi->part1.mod_count; i++) {
        kprintf("  module #%ld: start=0x%x end=0x%x size=0x%x name='%s'\n", i, modules[i].start, modules[i].end, modules[i].end - modules[i].start, (char *)(long)modules[i].name)






         ;
        if ((sword_t)(modules[i].end - modules[i].start) <= 0) {
            kprintf("Invalid boot module size! Possible cause: boot module file not found by QEMU\n");
            return false;
        }
        if (boot_state.mods_end_paddr < modules[i].end) {
            boot_state.mods_end_paddr = modules[i].end;
        }
    }

    /* initialize the memory. We track two kinds of memory regions. Physical memory
     * that we will use for the kernel, and physical memory regions that we must
     * not give to the user. Memory regions that must not be given to the user
     * include all the physical memory in the kernel window, but also includes any
     * important or kernel devices. */
    boot_state.mem_p_regs.count = 0;
    if (mbi->part1.flags & (1ul << (6))) {
        if (!parse_mem_map(mbi->part2.mmap_length, mbi->part2.mmap_addr)) {
            return false;
        }
        uint32_t multiboot_mmap_length = mbi->part2.mmap_length;
        if (multiboot_mmap_length > (50 * sizeof(seL4_X86_mb_mmap_t))) {
            multiboot_mmap_length = 50 * sizeof(seL4_X86_mb_mmap_t);
            kprintf("Warning: Multiboot has reported more memory map entries, %zd, " "than the max amount that will be passed in the bootinfo, %d. " "These extra regions will still be turned into untyped caps.", multiboot_mmap_length / sizeof(seL4_X86_mb_mmap_t), 50)


                                                                                                       ;
        }
        memcpy(&boot_state.mb_mmap_info.mmap, (void *)(word_t)mbi->part2.mmap_addr, multiboot_mmap_length);
        boot_state.mb_mmap_info.mmap_length = multiboot_mmap_length;
    } else {
        /* calculate memory the old way */
        p_region_t avail;
        avail.start = 0x100000;
        avail.end = (((avail.start + (mbi->part1.mem_upper << 10)) >> (12)) << (12));
        if (!add_mem_p_regs(avail)) {
            return false;
        }
    }

    /* copy VESA information from multiboot header */
    if ((mbi->part1.flags & (1ul << (11))) == 0) {
        boot_state.vbe_info.vbeMode = -1;
        kprintf("Multiboot gave us no video information\n");
    } else {
        boot_state.vbe_info.vbeInfoBlock = *(seL4_VBEInfoBlock_t *)(seL4_Word)mbi->part2.vbe_control_info;
        boot_state.vbe_info.vbeModeInfoBlock = *(seL4_VBEModeInfoBlock_t *)(seL4_Word)mbi->part2.vbe_mode_info;
        boot_state.vbe_info.vbeMode = mbi->part2.vbe_mode;
        kprintf("Got VBE info in multiboot. Current video mode is %d\n", mbi->part2.vbe_mode);
        boot_state.vbe_info.vbeInterfaceSeg = mbi->part2.vbe_interface_seg;
        boot_state.vbe_info.vbeInterfaceOff = mbi->part2.vbe_interface_off;
        boot_state.vbe_info.vbeInterfaceLen = mbi->part2.vbe_interface_len;
    }

    boot_state.mem_lower = mbi->part1.mem_lower;
    boot_state.boot_module_start = modules->start;

    /* Initialize ACPI */
    if (!acpi_init(&boot_state.acpi_rsdp)) {
        return false;
    }

    return true;
}

static __attribute__((__section__(".boot.text"))) bool_t try_boot_sys_mbi2(
    multiboot2_header_t *mbi2
)
{
    int mod_count = 0;
    multiboot2_tag_t const *tag = (multiboot2_tag_t *)(mbi2 + 1);
    multiboot2_tag_t const *tag_e = (multiboot2_tag_t *)((word_t)mbi2 + mbi2->total_size);

    /* initialize the memory. We track two kinds of memory regions. Physical memory
     * that we will use for the kernel, and physical memory regions that we must
     * not give to the user. Memory regions that must not be given to the user
     * include all the physical memory in the kernel window, but also includes any
     * important or kernel devices. */
    boot_state.mem_p_regs.count = 0;
    boot_state.mb_mmap_info.mmap_length = 0;
    boot_state.vbe_info.vbeMode = -1;

    while (tag < tag_e && tag->type != MULTIBOOT2_TAG_END) {
        word_t const behind_tag = (word_t)tag + sizeof(*tag);

        if (tag->type == MULTIBOOT2_TAG_CMDLINE) {
            char const *const cmdline = (char const * const)(behind_tag);
            cmdline_parse(cmdline, &cmdline_opt);
        } else if (tag->type == MULTIBOOT2_TAG_ACPI_1) {
            if (ACPI_V1_SIZE == tag->size - sizeof(*tag)) {
                memcpy(&boot_state.acpi_rsdp, (void *)behind_tag, tag->size - sizeof(*tag));
            }
        } else if (tag->type == MULTIBOOT2_TAG_ACPI_2) {
            if (sizeof(boot_state.acpi_rsdp) == tag->size - sizeof(*tag)) {
                memcpy(&boot_state.acpi_rsdp, (void *)behind_tag, sizeof(boot_state.acpi_rsdp));
            }
        } else if (tag->type == MULTIBOOT2_TAG_MODULE) {
            multiboot2_module_t const *module = (multiboot2_module_t const *)behind_tag;
            kprintf("  module #%d: start=0x%x end=0x%x size=0x%x name='%s'\n", mod_count, module->start, module->end, module->end - module->start, module->string)






             ;

            if (mod_count == 0) {
                boot_state.boot_module_start = module->start;
            }

            mod_count ++;
            if ((sword_t)(module->end - module->start) <= 0) {
                kprintf("Invalid boot module size! Possible cause: boot module file not found\n");
                return false;
            }
            if (boot_state.mods_end_paddr < module->end) {
                boot_state.mods_end_paddr = module->end;
            }
        } else if (tag->type == MULTIBOOT2_TAG_MEMORY) {
            multiboot2_memory_t const *s = (multiboot2_memory_t *)(behind_tag + 8);
            multiboot2_memory_t const *e = (multiboot2_memory_t *)((word_t)tag + tag->size);

            for (multiboot2_memory_t const *m = s; m < e; m++) {
                if (!m->addr) {
                    boot_state.mem_lower = m->size;
                }

                kprintf("\tPhysical Memory Region from %llx size %llx type %u\n", m->addr, m->size, m->type);
                if (m->addr != (uint64_t)(word_t)m->addr) {
                    kprintf("\t\tPhysical memory region not addressable\n");
                }

                if (m->type == 1 && m->addr >= 0x100000) {
                    if (!add_mem_p_regs((p_region_t) {
                    m->addr, m->addr + m->size
                }))
                    return false;
                }
            }
        } else if (tag->type == MULTIBOOT2_TAG_FB) {
            multiboot2_fb_t const *fb = (multiboot2_fb_t const *)behind_tag;
            kprintf("Got framebuffer info in multiboot2. Current video mode is at physical address=%llx pitch=%u resolution=%ux%u@%u type=%u\n", fb->addr, fb->pitch, fb->width, fb->height, fb->bpp, fb->type)
                                                                                 ;
            boot_state.fb_info = *fb;
        }

        tag = (multiboot2_tag_t const *)((word_t)tag + (((((tag->size) - 1ul) >> (3)) + 1ul) << (3)));
    }

    kprintf("Detected %d boot module(s):\n", mod_count);

    if (mod_count < 1) {
        kprintf("Expect at least one boot module (containing a userland image)\n");
        return false;
    }

    return true;
}

__attribute__((__section__(".boot.text"))) __attribute__((externally_visible)) void boot_sys(
    unsigned long multiboot_magic,
    void *mbi)
{
    bool_t result = false;

    if (multiboot_magic == 0x2BADB002) {
        result = try_boot_sys_mbi1(mbi);
    } else if (multiboot_magic == 0x36d76289) {
        result = try_boot_sys_mbi2(mbi);
    } else {
        kprintf("Boot loader is not multiboot 1 or 2 compliant %lx\n", multiboot_magic);
    }

    if (result) {
        result = try_boot_sys();
    }

    if (!result) {
        _fail("boot_sys failed for some reason :(\n", "/host/kernel/src/arch/x86/kernel/boot_sys.c", 725, __func__);
    }

    x86KScurInterrupt = int_invalid;
    x86KSPendingInterrupt = int_invalid;






    schedule();
    activateThread();
}
# 1 "/host/kernel/src/arch/x86/kernel/cmdline.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */







# 1 "/host/kernel/include/plat/pc99/plat/machine/io.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       





/** MODIFIES: phantom_machine_state */
void out8(uint16_t port, uint8_t value);
/** MODIFIES: phantom_machine_state */
void out16(uint16_t port, uint16_t value);
/** MODIFIES: phantom_machine_state */
void out32(uint16_t port, uint32_t value);
/** MODIFIES: */
uint8_t in8(uint16_t port);
/** MODIFIES: */
uint16_t in16(uint16_t port);
/** MODIFIES: */
uint32_t in32(uint16_t port);


void serial_init(uint16_t port);
# 14 "/host/kernel/src/arch/x86/kernel/cmdline.c" 2

/* 'cmdline_val' is declared globally because of a C-subset restriction.
 * It is only used in cmdline_parse(), which therefore is non-reentrant.
 */

__attribute__((__section__(".boot.bss")))
char cmdline_val[1000];

/* workaround because string literals are not supported by C parser */
const char cmdline_str_max_num_nodes[] = {'m', 'a', 'x', '_', 'n', 'u', 'm', '_', 'n', 'o', 'd', 'e', 's', 0};
const char cmdline_str_num_sh_frames[] = {'n', 'u', 'm', '_', 's', 'h', '_', 'f', 'r', 'a', 'm', 'e', 's', 0};
const char cmdline_str_disable_iommu[] = {'d', 'i', 's', 'a', 'b', 'l', 'e', '_', 'i', 'o', 'm', 'm', 'u', 0};

static int is_space(char c)
{
    return c <= ' ';
}

static int __attribute__((unused)) parse_opt(const char *cmdline, const char *opt, char *value, int bufsize)
{
    int len = -1;
    const char *optptr = ((void *)0);

    while (true) {
        for (; is_space(*cmdline) && (*cmdline != 0); cmdline++);
        if (*cmdline == 0) {
            break;
        }

        for (optptr = opt; *optptr && *cmdline && (*cmdline != '=') && !is_space(*cmdline)
             && (*optptr == *cmdline); optptr++, cmdline++);

        if (*optptr == '\0' && *cmdline == '=') {
            cmdline++;

            for (len = 0; !is_space(*cmdline) && (len < bufsize - 1); cmdline++, len++) {
                value[len] = *cmdline;
            }
            if (bufsize) {
                value[len] = '\0';
            }
        }
        for (; !is_space(*cmdline); cmdline++);
    }

    return len;
}

static int parse_bool(const char *cmdline, const char *opt)
{
    const char *optptr = ((void *)0);

    while (1) {
        for (; is_space(*cmdline) && (*cmdline != 0); cmdline++);
        if (*cmdline == 0) {
            return 0;
        }

        for (optptr = opt; *optptr && *cmdline && !is_space(*cmdline) && (*optptr == *cmdline); optptr++, cmdline++);

        if (*optptr == '\0' && is_space(*cmdline)) {
            return 1;
        } else {
            for (; !is_space(*cmdline); cmdline++);
        }
    }
}

static void __attribute__((unused)) parse_uint16_array(char *str, uint16_t *array, int array_size)
{
    char *last;
    int i = 0;
    int v;

    while (str && i < array_size) {
        for (last = str; *str && *str != ','; str++);
        if (*str == 0) {
            str = 0;
        } else {
            *str = 0;
            str++;
        }
        v = str_to_long(last);
        if (v == -1) {
            array[i] = 0;
        } else {
            array[i] = v;
        }
        i++;
    }
}

void cmdline_parse(const char *cmdline, cmdline_opt_t *cmdline_opt)
{

    /* use BIOS data area to read serial configuration. The BDA is not
     * fully standardized and parts are absolete. See http://wiki.osdev.org/Memory_Map_(x86)#BIOS_Data_Area_.28BDA.29
     * for an explanation */
    const unsigned short *bda_port = (unsigned short *)0x400;
    const unsigned short *bda_equi = (unsigned short *)0x410;
    int const bda_ports_count = (*bda_equi >> 9) & 0x7;



    /* initialise to default or use BDA if available */
    cmdline_opt->console_port = bda_ports_count && *bda_port ? *bda_port : 0x3f8;

    if (parse_opt(cmdline, "console_port", cmdline_val, 1000) != -1) {
        parse_uint16_array(cmdline_val, &cmdline_opt->console_port, 1);
    }

    /* initialise console ports to enable debug output */
    if (cmdline_opt->console_port) {
        serial_init(cmdline_opt->console_port);
        x86KSconsolePort = cmdline_opt->console_port;
    }

    /* only start printing here after having parsed/set/initialised the console_port */
    kprintf("\nBoot config: parsing cmdline '%s'\n", cmdline);

    if (cmdline_opt->console_port) {
        kprintf("Boot config: console_port = 0x%x\n", cmdline_opt->console_port);
    }



    /* initialise to default or use BDA if available */
    cmdline_opt->debug_port = bda_ports_count && *bda_port ? *bda_port : 0x3f8;
    if (parse_opt(cmdline, "debug_port", cmdline_val, 1000) != -1) {
        parse_uint16_array(cmdline_val, &cmdline_opt->debug_port, 1);
    }

    /* initialise debug ports */
    if (cmdline_opt->debug_port) {
        serial_init(cmdline_opt->debug_port);
        x86KSdebugPort = cmdline_opt->debug_port;
        kprintf("Boot config: debug_port = 0x%x\n", cmdline_opt->debug_port);
    }


    cmdline_opt->disable_iommu = parse_bool(cmdline, cmdline_str_disable_iommu);
    kprintf("Boot config: disable_iommu = %s\n", cmdline_opt->disable_iommu ? "true" : "false");
}
# 1 "/host/kernel/src/arch/x86/kernel/ept.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/arch/x86/kernel/smp_sys.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/arch/x86/kernel/thread.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




void Arch_postModifyRegisters(tcb_t *tptr)
{
    Mode_postModifyRegisters(tptr);
}
# 1 "/host/kernel/src/arch/x86/kernel/vspace.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */







# 1 "kernel/gen_headers/arch/api/invocation.h" 1

/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 ** SPDX-License-Identifier: GPL-2.0-only
 */

/* This header was generated by kernel/tools/invocation_header_gen.py.
 *
 * To add an invocation call number, edit libsel4/include/interfaces/sel4.xml.
 *
 */
# 14 "/host/kernel/src/arch/x86/kernel/vspace.c" 2




static exception_t performPageGetAddress(void *vbase_ptr)
{
    paddr_t capFBasePtr;

    /* Get the physical address of this frame. */
    capFBasePtr = addrFromPPtr(vbase_ptr);

    /* return it in the first message register */
    setRegister(ksCurThread, msgRegisters[0], capFBasePtr);
    setRegister(ksCurThread, msgInfoRegister,
                wordFromMessageInfo(seL4_MessageInfo_new(0, 0, 0, 1)));

    return EXCEPTION_NONE;
}


void deleteASIDPool(asid_t asid_base, asid_pool_t *pool)
{
    /* Haskell error: "ASID pool's base must be aligned" */
    if(!((!((asid_base) & ((1ul << (asidLowBits))-1ul))))) _assert_fail("IS_ALIGNED(asid_base, asidLowBits)", "/host/kernel/src/arch/x86/kernel/vspace.c", 37, __FUNCTION__);

    if (x86KSASIDTable[asid_base >> asidLowBits] == pool) {
        for (unsigned int offset = 0; offset < (1ul << (asidLowBits)); offset++) {
            asid_map_t asid_map = pool->array[offset];
            if (asid_map_get_type(asid_map) == asid_map_asid_map_vspace) {
                vspace_root_t *vspace = (vspace_root_t *)asid_map_asid_map_vspace_get_vspace_root(asid_map);
                hwASIDInvalidate(asid_base + offset, vspace);
            }
        }
        x86KSASIDTable[asid_base >> asidLowBits] = ((void *)0);
        setVMRoot(ksCurThread);
    }
}

exception_t performASIDControlInvocation(void *frame, cte_t *slot, cte_t *parent, asid_t asid_base)
{
    /** AUXUPD: "(True, typ_region_bytes (ptr_val \<acute>frame) 12)" */
    /** GHOSTUPD: "(True, gs_clear_region (ptr_val \<acute>frame) 12)" */
    cap_untyped_cap_ptr_set_capFreeIndex(&(parent->cap),
                                         ((1ul << ((cap_untyped_cap_get_capBlockSize(parent->cap)) - 4))));

    memzero(frame, (1ul << (pageBitsForSize(X86_SmallPage))));
    /** AUXUPD: "(True, ptr_retyps 1 (Ptr (ptr_val \<acute>frame) :: asid_pool_C ptr))" */

    cteInsert(
        cap_asid_pool_cap_new(
            asid_base, /* capASIDBase  */
            ((word_t)(frame)) /* capASIDPool  */
        ),
        parent,
        slot
    );
    /* Haskell error: "ASID pool's base must be aligned" */
    if(!((asid_base & ((1ul << (asidLowBits))-1ul)) == 0)) _assert_fail("(asid_base & MASK(asidLowBits)) == 0", "/host/kernel/src/arch/x86/kernel/vspace.c", 71, __FUNCTION__);
    x86KSASIDTable[asid_base >> asidLowBits] = (asid_pool_t *)frame;

    return EXCEPTION_NONE;
}

void deleteASID(asid_t asid, vspace_root_t *vspace)
{
    asid_pool_t *poolPtr;

    poolPtr = x86KSASIDTable[asid >> asidLowBits];
    if (poolPtr != ((void *)0)) {
        asid_map_t asid_map = poolPtr->array[asid & ((1ul << (asidLowBits))-1ul)];
        if (asid_map_get_type(asid_map) == asid_map_asid_map_vspace &&
            (vspace_root_t *)asid_map_asid_map_vspace_get_vspace_root(asid_map) == vspace) {
            hwASIDInvalidate(asid, vspace);
            poolPtr->array[asid & ((1ul << (asidLowBits))-1ul)] = asid_map_asid_map_none_new();
            setVMRoot(ksCurThread);
        }
    }
}

word_t *__attribute__((__pure__)) lookupIPCBuffer(bool_t isReceiver, tcb_t *thread)
{
    word_t w_bufferPtr;
    cap_t bufferCap;
    vm_rights_t vm_rights;

    w_bufferPtr = thread->tcbIPCBuffer;
    bufferCap = (((cte_t *)((word_t)(thread)&~((1ul << (11))-1ul)))+(tcbBuffer))->cap;

    if (cap_get_capType(bufferCap) != cap_frame_cap) {
        return ((void *)0);
    }
    if (__builtin_expect(!!(cap_frame_cap_get_capFIsDevice(bufferCap)), 0)) {
        return ((void *)0);
    }

    vm_rights = cap_frame_cap_get_capFVMRights(bufferCap);
    if (vm_rights == VMReadWrite || (!isReceiver && vm_rights == VMReadOnly)) {
        word_t basePtr, pageBits;

        basePtr = cap_frame_cap_get_capFBasePtr(bufferCap);
        pageBits = pageBitsForSize(cap_frame_cap_get_capFSize(bufferCap));
        return (word_t *)(basePtr + (w_bufferPtr & ((1ul << (pageBits))-1ul)));
    } else {
        return ((void *)0);
    }
}

bool_t __attribute__((__const__)) isValidVTableRoot(cap_t cap)
{
    return isValidNativeRoot(cap);
}


__attribute__((__section__(".boot.text"))) bool_t map_kernel_window_devices(pte_t *pt, uint32_t num_ioapic, paddr_t *ioapic_paddrs, uint32_t num_drhu,
                                           paddr_t *drhu_list)
{
    word_t idx = (0xffffffffc0000000ul & ((1ul << (21))-1ul)) >> 12;
    paddr_t phys;
    pte_t pte;
    unsigned int i;
    /* map kernel devices: APIC */
    phys = apic_get_base_paddr();
    if (!phys) {
        return false;
    }
    if (!reserve_region((p_region_t) {
    phys, phys + 0x1000
})) {
        return false;
    }
    pte = x86_make_device_pte(phys);

    if(!(idx == (0xffffffffc0000000ul & ((1ul << (21))-1ul)) >> 12)) _assert_fail("idx == (PPTR_APIC & MASK(LARGE_PAGE_BITS)) >> PAGE_BITS", "/host/kernel/src/arch/x86/kernel/vspace.c", 146, __FUNCTION__);
    pt[idx] = pte;
    idx++;
    for (i = 0; i < num_ioapic; i++) {
        phys = ioapic_paddrs[i];
        if (!reserve_region((p_region_t) {
        phys, phys + 0x1000
    })) {
            return false;
        }
        pte = x86_make_device_pte(phys);
        if(!(idx == (((0xffffffffc0000000ul + (1ul << (12))) + i * (1ul << (12))) & ((1ul << (21))-1ul)) >> 12)) _assert_fail("idx == ((PPTR_IOAPIC_START + i * BIT(PAGE_BITS)) & MASK(LARGE_PAGE_BITS)) >> PAGE_BITS", "/host/kernel/src/arch/x86/kernel/vspace.c", 157, __FUNCTION__);
        pt[idx] = pte;
        idx++;
        if (idx == (1ul << (9))) {
            return false;
        }
    }
    /* put in null mappings for any extra IOAPICs */
    for (; i < 1; i++) {
        pte = x86_make_empty_pte();
        if(!(idx == (((0xffffffffc0000000ul + (1ul << (12))) + i * (1ul << (12))) & ((1ul << (21))-1ul)) >> 12)) _assert_fail("idx == ((PPTR_IOAPIC_START + i * BIT(PAGE_BITS)) & MASK(LARGE_PAGE_BITS)) >> PAGE_BITS", "/host/kernel/src/arch/x86/kernel/vspace.c", 167, __FUNCTION__);
        pt[idx] = pte;
        idx++;
    }

    /* map kernel devices: IOMMUs */
    for (i = 0; i < num_drhu; i++) {
        phys = (paddr_t)drhu_list[i];
        if (!reserve_region((p_region_t) {
        phys, phys + 0x1000
    })) {
            return false;
        }
        pte = x86_make_device_pte(phys);

        if(!(idx == ((((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1) + i * (1ul << (12))) & ((1ul << (21))-1ul)) >> 12)) _assert_fail("idx == ((PPTR_DRHU_START + i * BIT(PAGE_BITS)) & MASK(LARGE_PAGE_BITS)) >> PAGE_BITS", "/host/kernel/src/arch/x86/kernel/vspace.c", 182, __FUNCTION__);
        pt[idx] = pte;
        idx++;
        if (idx == (1ul << (9))) {
            return false;
        }
    }

    /* mark unused kernel-device pages as 'not present' */
    while (idx < (1ul << (9))) {
        pte = x86_make_empty_pte();
        pt[idx] = pte;
        idx++;
    }

    /* Check we haven't added too many kernel-device mappings.*/
    if(!(idx == (1ul << (9)))) _assert_fail("idx == BIT(PT_INDEX_BITS)", "/host/kernel/src/arch/x86/kernel/vspace.c", 198, __FUNCTION__);
    return true;
}

__attribute__((__section__(".boot.text"))) static void init_idt(idt_entry_t *idt)
{
    init_idt_entry(idt, 0x00, int_00);
    init_idt_entry(idt, 0x01, int_01);
    init_idt_entry(idt, 0x02, int_02);
    init_idt_entry(idt, 0x03, int_03);
    init_idt_entry(idt, 0x04, int_04);
    init_idt_entry(idt, 0x05, int_05);
    init_idt_entry(idt, 0x06, int_06);
    init_idt_entry(idt, 0x07, int_07);
    init_idt_entry(idt, 0x08, int_08);
    init_idt_entry(idt, 0x09, int_09);
    init_idt_entry(idt, 0x0a, int_0a);
    init_idt_entry(idt, 0x0b, int_0b);
    init_idt_entry(idt, 0x0c, int_0c);
    init_idt_entry(idt, 0x0d, int_0d);
    init_idt_entry(idt, 0x0e, int_0e);
    init_idt_entry(idt, 0x0f, int_0f);

    init_idt_entry(idt, 0x10, int_10);
    init_idt_entry(idt, 0x11, int_11);
    init_idt_entry(idt, 0x12, int_12);
    init_idt_entry(idt, 0x13, int_13);
    init_idt_entry(idt, 0x14, int_14);
    init_idt_entry(idt, 0x15, int_15);
    init_idt_entry(idt, 0x16, int_16);
    init_idt_entry(idt, 0x17, int_17);
    init_idt_entry(idt, 0x18, int_18);
    init_idt_entry(idt, 0x19, int_19);
    init_idt_entry(idt, 0x1a, int_1a);
    init_idt_entry(idt, 0x1b, int_1b);
    init_idt_entry(idt, 0x1c, int_1c);
    init_idt_entry(idt, 0x1d, int_1d);
    init_idt_entry(idt, 0x1e, int_1e);
    init_idt_entry(idt, 0x1f, int_1f);

    init_idt_entry(idt, 0x20, int_20);
    init_idt_entry(idt, 0x21, int_21);
    init_idt_entry(idt, 0x22, int_22);
    init_idt_entry(idt, 0x23, int_23);
    init_idt_entry(idt, 0x24, int_24);
    init_idt_entry(idt, 0x25, int_25);
    init_idt_entry(idt, 0x26, int_26);
    init_idt_entry(idt, 0x27, int_27);
    init_idt_entry(idt, 0x28, int_28);
    init_idt_entry(idt, 0x29, int_29);
    init_idt_entry(idt, 0x2a, int_2a);
    init_idt_entry(idt, 0x2b, int_2b);
    init_idt_entry(idt, 0x2c, int_2c);
    init_idt_entry(idt, 0x2d, int_2d);
    init_idt_entry(idt, 0x2e, int_2e);
    init_idt_entry(idt, 0x2f, int_2f);

    init_idt_entry(idt, 0x30, int_30);
    init_idt_entry(idt, 0x31, int_31);
    init_idt_entry(idt, 0x32, int_32);
    init_idt_entry(idt, 0x33, int_33);
    init_idt_entry(idt, 0x34, int_34);
    init_idt_entry(idt, 0x35, int_35);
    init_idt_entry(idt, 0x36, int_36);
    init_idt_entry(idt, 0x37, int_37);
    init_idt_entry(idt, 0x38, int_38);
    init_idt_entry(idt, 0x39, int_39);
    init_idt_entry(idt, 0x3a, int_3a);
    init_idt_entry(idt, 0x3b, int_3b);
    init_idt_entry(idt, 0x3c, int_3c);
    init_idt_entry(idt, 0x3d, int_3d);
    init_idt_entry(idt, 0x3e, int_3e);
    init_idt_entry(idt, 0x3f, int_3f);

    init_idt_entry(idt, 0x40, int_40);
    init_idt_entry(idt, 0x41, int_41);
    init_idt_entry(idt, 0x42, int_42);
    init_idt_entry(idt, 0x43, int_43);
    init_idt_entry(idt, 0x44, int_44);
    init_idt_entry(idt, 0x45, int_45);
    init_idt_entry(idt, 0x46, int_46);
    init_idt_entry(idt, 0x47, int_47);
    init_idt_entry(idt, 0x48, int_48);
    init_idt_entry(idt, 0x49, int_49);
    init_idt_entry(idt, 0x4a, int_4a);
    init_idt_entry(idt, 0x4b, int_4b);
    init_idt_entry(idt, 0x4c, int_4c);
    init_idt_entry(idt, 0x4d, int_4d);
    init_idt_entry(idt, 0x4e, int_4e);
    init_idt_entry(idt, 0x4f, int_4f);

    init_idt_entry(idt, 0x50, int_50);
    init_idt_entry(idt, 0x51, int_51);
    init_idt_entry(idt, 0x52, int_52);
    init_idt_entry(idt, 0x53, int_53);
    init_idt_entry(idt, 0x54, int_54);
    init_idt_entry(idt, 0x55, int_55);
    init_idt_entry(idt, 0x56, int_56);
    init_idt_entry(idt, 0x57, int_57);
    init_idt_entry(idt, 0x58, int_58);
    init_idt_entry(idt, 0x59, int_59);
    init_idt_entry(idt, 0x5a, int_5a);
    init_idt_entry(idt, 0x5b, int_5b);
    init_idt_entry(idt, 0x5c, int_5c);
    init_idt_entry(idt, 0x5d, int_5d);
    init_idt_entry(idt, 0x5e, int_5e);
    init_idt_entry(idt, 0x5f, int_5f);

    init_idt_entry(idt, 0x60, int_60);
    init_idt_entry(idt, 0x61, int_61);
    init_idt_entry(idt, 0x62, int_62);
    init_idt_entry(idt, 0x63, int_63);
    init_idt_entry(idt, 0x64, int_64);
    init_idt_entry(idt, 0x65, int_65);
    init_idt_entry(idt, 0x66, int_66);
    init_idt_entry(idt, 0x67, int_67);
    init_idt_entry(idt, 0x68, int_68);
    init_idt_entry(idt, 0x69, int_69);
    init_idt_entry(idt, 0x6a, int_6a);
    init_idt_entry(idt, 0x6b, int_6b);
    init_idt_entry(idt, 0x6c, int_6c);
    init_idt_entry(idt, 0x6d, int_6d);
    init_idt_entry(idt, 0x6e, int_6e);
    init_idt_entry(idt, 0x6f, int_6f);

    init_idt_entry(idt, 0x70, int_70);
    init_idt_entry(idt, 0x71, int_71);
    init_idt_entry(idt, 0x72, int_72);
    init_idt_entry(idt, 0x73, int_73);
    init_idt_entry(idt, 0x74, int_74);
    init_idt_entry(idt, 0x75, int_75);
    init_idt_entry(idt, 0x76, int_76);
    init_idt_entry(idt, 0x77, int_77);
    init_idt_entry(idt, 0x78, int_78);
    init_idt_entry(idt, 0x79, int_79);
    init_idt_entry(idt, 0x7a, int_7a);
    init_idt_entry(idt, 0x7b, int_7b);
    init_idt_entry(idt, 0x7c, int_7c);
    init_idt_entry(idt, 0x7d, int_7d);
    init_idt_entry(idt, 0x7e, int_7e);
    init_idt_entry(idt, 0x7f, int_7f);

    init_idt_entry(idt, 0x80, int_80);
    init_idt_entry(idt, 0x81, int_81);
    init_idt_entry(idt, 0x82, int_82);
    init_idt_entry(idt, 0x83, int_83);
    init_idt_entry(idt, 0x84, int_84);
    init_idt_entry(idt, 0x85, int_85);
    init_idt_entry(idt, 0x86, int_86);
    init_idt_entry(idt, 0x87, int_87);
    init_idt_entry(idt, 0x88, int_88);
    init_idt_entry(idt, 0x89, int_89);
    init_idt_entry(idt, 0x8a, int_8a);
    init_idt_entry(idt, 0x8b, int_8b);
    init_idt_entry(idt, 0x8c, int_8c);
    init_idt_entry(idt, 0x8d, int_8d);
    init_idt_entry(idt, 0x8e, int_8e);
    init_idt_entry(idt, 0x8f, int_8f);

    init_idt_entry(idt, 0x90, int_90);
    init_idt_entry(idt, 0x91, int_91);
    init_idt_entry(idt, 0x92, int_92);
    init_idt_entry(idt, 0x93, int_93);
    init_idt_entry(idt, 0x94, int_94);
    init_idt_entry(idt, 0x95, int_95);
    init_idt_entry(idt, 0x96, int_96);
    init_idt_entry(idt, 0x97, int_97);
    init_idt_entry(idt, 0x98, int_98);
    init_idt_entry(idt, 0x99, int_99);
    init_idt_entry(idt, 0x9a, int_9a);
    init_idt_entry(idt, 0x9b, int_9b);
    init_idt_entry(idt, 0x9c, int_9c);
    init_idt_entry(idt, 0x9d, int_9d);
    init_idt_entry(idt, 0x9e, int_9e);
    init_idt_entry(idt, 0x9f, int_9f);

    init_idt_entry(idt, 0xa0, int_a0);
    init_idt_entry(idt, 0xa1, int_a1);
    init_idt_entry(idt, 0xa2, int_a2);
    init_idt_entry(idt, 0xa3, int_a3);
    init_idt_entry(idt, 0xa4, int_a4);
    init_idt_entry(idt, 0xa5, int_a5);
    init_idt_entry(idt, 0xa6, int_a6);
    init_idt_entry(idt, 0xa7, int_a7);
    init_idt_entry(idt, 0xa8, int_a8);
    init_idt_entry(idt, 0xa9, int_a9);
    init_idt_entry(idt, 0xaa, int_aa);
    init_idt_entry(idt, 0xab, int_ab);
    init_idt_entry(idt, 0xac, int_ac);
    init_idt_entry(idt, 0xad, int_ad);
    init_idt_entry(idt, 0xae, int_ae);
    init_idt_entry(idt, 0xaf, int_af);

    init_idt_entry(idt, 0xb0, int_b0);
    init_idt_entry(idt, 0xb1, int_b1);
    init_idt_entry(idt, 0xb2, int_b2);
    init_idt_entry(idt, 0xb3, int_b3);
    init_idt_entry(idt, 0xb4, int_b4);
    init_idt_entry(idt, 0xb5, int_b5);
    init_idt_entry(idt, 0xb6, int_b6);
    init_idt_entry(idt, 0xb7, int_b7);
    init_idt_entry(idt, 0xb8, int_b8);
    init_idt_entry(idt, 0xb9, int_b9);
    init_idt_entry(idt, 0xba, int_ba);
    init_idt_entry(idt, 0xbb, int_bb);
    init_idt_entry(idt, 0xbc, int_bc);
    init_idt_entry(idt, 0xbd, int_bd);
    init_idt_entry(idt, 0xbe, int_be);
    init_idt_entry(idt, 0xbf, int_bf);

    init_idt_entry(idt, 0xc0, int_c0);
    init_idt_entry(idt, 0xc1, int_c1);
    init_idt_entry(idt, 0xc2, int_c2);
    init_idt_entry(idt, 0xc3, int_c3);
    init_idt_entry(idt, 0xc4, int_c4);
    init_idt_entry(idt, 0xc5, int_c5);
    init_idt_entry(idt, 0xc6, int_c6);
    init_idt_entry(idt, 0xc7, int_c7);
    init_idt_entry(idt, 0xc8, int_c8);
    init_idt_entry(idt, 0xc9, int_c9);
    init_idt_entry(idt, 0xca, int_ca);
    init_idt_entry(idt, 0xcb, int_cb);
    init_idt_entry(idt, 0xcc, int_cc);
    init_idt_entry(idt, 0xcd, int_cd);
    init_idt_entry(idt, 0xce, int_ce);
    init_idt_entry(idt, 0xcf, int_cf);

    init_idt_entry(idt, 0xd0, int_d0);
    init_idt_entry(idt, 0xd1, int_d1);
    init_idt_entry(idt, 0xd2, int_d2);
    init_idt_entry(idt, 0xd3, int_d3);
    init_idt_entry(idt, 0xd4, int_d4);
    init_idt_entry(idt, 0xd5, int_d5);
    init_idt_entry(idt, 0xd6, int_d6);
    init_idt_entry(idt, 0xd7, int_d7);
    init_idt_entry(idt, 0xd8, int_d8);
    init_idt_entry(idt, 0xd9, int_d9);
    init_idt_entry(idt, 0xda, int_da);
    init_idt_entry(idt, 0xdb, int_db);
    init_idt_entry(idt, 0xdc, int_dc);
    init_idt_entry(idt, 0xdd, int_dd);
    init_idt_entry(idt, 0xde, int_de);
    init_idt_entry(idt, 0xdf, int_df);

    init_idt_entry(idt, 0xe0, int_e0);
    init_idt_entry(idt, 0xe1, int_e1);
    init_idt_entry(idt, 0xe2, int_e2);
    init_idt_entry(idt, 0xe3, int_e3);
    init_idt_entry(idt, 0xe4, int_e4);
    init_idt_entry(idt, 0xe5, int_e5);
    init_idt_entry(idt, 0xe6, int_e6);
    init_idt_entry(idt, 0xe7, int_e7);
    init_idt_entry(idt, 0xe8, int_e8);
    init_idt_entry(idt, 0xe9, int_e9);
    init_idt_entry(idt, 0xea, int_ea);
    init_idt_entry(idt, 0xeb, int_eb);
    init_idt_entry(idt, 0xec, int_ec);
    init_idt_entry(idt, 0xed, int_ed);
    init_idt_entry(idt, 0xee, int_ee);
    init_idt_entry(idt, 0xef, int_ef);

    init_idt_entry(idt, 0xf0, int_f0);
    init_idt_entry(idt, 0xf1, int_f1);
    init_idt_entry(idt, 0xf2, int_f2);
    init_idt_entry(idt, 0xf3, int_f3);
    init_idt_entry(idt, 0xf4, int_f4);
    init_idt_entry(idt, 0xf5, int_f5);
    init_idt_entry(idt, 0xf6, int_f6);
    init_idt_entry(idt, 0xf7, int_f7);
    init_idt_entry(idt, 0xf8, int_f8);
    init_idt_entry(idt, 0xf9, int_f9);
    init_idt_entry(idt, 0xfa, int_fa);
    init_idt_entry(idt, 0xfb, int_fb);
    init_idt_entry(idt, 0xfc, int_fc);
    init_idt_entry(idt, 0xfd, int_fd);
    init_idt_entry(idt, 0xfe, int_fe);
    init_idt_entry(idt, 0xff, int_ff);
}

__attribute__((__section__(".boot.text"))) bool_t init_vm_state(void)
{
    word_t cacheLineSize;
    x86KScacheLineSizeBits = getCacheLineSizeBits();
    if (!x86KScacheLineSizeBits) {
        return false;
    }

    cacheLineSize = (1ul << (x86KScacheLineSizeBits));
    if (cacheLineSize != 64) {
        kprintf("Configured cache line size is %d but detected size is %lu\n", 64, cacheLineSize)
                                                 ;
        ;
    }

    /*
     * Work around -Waddress-of-packed-member. TSS is the first thing
     * in the struct and so it's safe to take its address.
     */
    void *tss_ptr = &x86KSGlobalState[0].x86KStss.tss;
    init_tss(tss_ptr);
    init_gdt(x86KSGlobalState[0].x86KSgdt, tss_ptr);
    init_idt(x86KSGlobalState[0].x86KSidt);
    return true;
}

__attribute__((__section__(".boot.text"))) bool_t init_pat_msr(void)
{
    x86_pat_msr_t pat_msr;
    /* First verify PAT is supported by the machine.
     *      See section 11.12.1 of Volume 3 of the Intel manual */
    if ((x86_cpuid_edx(0x1, 0x0) & (1ul << (16))) == 0) {
        kprintf("PAT support not found\n");
        return false;
    }
    pat_msr.words[0] = x86_rdmsr_low(0x277);
    pat_msr.words[1] = x86_rdmsr_high(0x277);
    /* Set up the PAT MSR to the Intel defaults, just in case
     * they have been changed but a bootloader somewhere along the way */
    pat_msr = x86_pat_msr_set_pa0(pat_msr, 0x06);
    pat_msr = x86_pat_msr_set_pa1(pat_msr, 0x04);
    pat_msr = x86_pat_msr_set_pa2(pat_msr, 0x07);
    pat_msr = x86_pat_msr_set_pa3(pat_msr, 0x00);
    /* Add the WriteCombining cache type to the PAT */
    pat_msr = x86_pat_msr_set_pa4(pat_msr, 0x01);
    x86_wrmsr(0x277, ((uint64_t)pat_msr.words[1]) << 32 | pat_msr.words[0]);
    return true;
}

__attribute__((__section__(".boot.text"))) void write_it_asid_pool(cap_t it_ap_cap, cap_t it_vspace_cap)
{
    asid_pool_t *ap = ((asid_pool_t*)(pptr_t)cap_get_capPtr(it_ap_cap));
    ap->array[1 /* initial thread's ASID */] = asid_map_asid_map_vspace_new((pptr_t)cap_get_capPtr(it_vspace_cap));
    x86KSASIDTable[1 /* initial thread's ASID */ >> asidLowBits] = ap;
}

asid_map_t findMapForASID(asid_t asid)
{
    asid_pool_t *poolPtr;

    poolPtr = x86KSASIDTable[asid >> asidLowBits];
    if (!poolPtr) {
        return asid_map_asid_map_none_new();
    }

    return poolPtr->array[asid & ((1ul << (asidLowBits))-1ul)];
}

findVSpaceForASID_ret_t findVSpaceForASID(asid_t asid)
{
    findVSpaceForASID_ret_t ret;
    asid_map_t asid_map;

    asid_map = findMapForASID(asid);
    if (asid_map_get_type(asid_map) != asid_map_asid_map_vspace) {
        current_lookup_fault = lookup_fault_invalid_root_new();

        ret.vspace_root = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }

    ret.vspace_root = (vspace_root_t *)asid_map_asid_map_vspace_get_vspace_root(asid_map);
    ret.status = EXCEPTION_NONE;
    return ret;
}

exception_t handleVMFault(tcb_t *thread, vm_fault_type_t vm_faultType)
{
    word_t addr;
    uint32_t fault;

    addr = getFaultAddr();
    fault = getRegister(thread, Error);

    switch (vm_faultType) {
    case X86DataFault:
        current_fault = seL4_Fault_VMFault_new(addr, fault, false);
        return EXCEPTION_FAULT;

    case X86InstructionFault:
        current_fault = seL4_Fault_VMFault_new(addr, fault, true);
        return EXCEPTION_FAULT;

    default:
        _fail("Invalid VM fault type", "/host/kernel/src/arch/x86/kernel/vspace.c", 582, __func__);
    }
}

uint32_t __attribute__((__const__)) WritableFromVMRights(vm_rights_t vm_rights)
{
    switch (vm_rights) {
    case VMReadOnly:
        return 0;

    case VMKernelOnly:
    case VMReadWrite:
        return 1;

    default:
        _fail("Invalid VM rights", "/host/kernel/src/arch/x86/kernel/vspace.c", 597, __func__);
    }
}

uint32_t __attribute__((__const__)) SuperUserFromVMRights(vm_rights_t vm_rights)
{
    switch (vm_rights) {
    case VMKernelOnly:
        return 0;

    case VMReadOnly:
    case VMReadWrite:
        return 1;

    default:
        _fail("Invalid VM rights", "/host/kernel/src/arch/x86/kernel/vspace.c", 612, __func__);
    }
}

lookupPTSlot_ret_t lookupPTSlot(vspace_root_t *vspace, vptr_t vptr)
{
    lookupPTSlot_ret_t ret;
    lookupPDSlot_ret_t pdSlot;

    pdSlot = lookupPDSlot(vspace, vptr);
    if (pdSlot.status != EXCEPTION_NONE) {
        ret.ptSlot = ((void *)0);
        ret.status = pdSlot.status;
        return ret;
    }
    if ((pde_ptr_get_page_size(pdSlot.pdSlot) != pde_pde_pt) ||
        !pde_pde_pt_ptr_get_present(pdSlot.pdSlot)) {
        current_lookup_fault = lookup_fault_missing_capability_new(12 + 9);
        ret.ptSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    } else {
        pte_t *pt;
        pte_t *ptSlot;
        word_t ptIndex;

        pt = ptrFromPAddr(pde_pde_pt_ptr_get_pt_base_address(pdSlot.pdSlot));
        ptIndex = (vptr >> 12) & ((1ul << (9))-1ul);
        ptSlot = pt + ptIndex;

        ret.ptSlot = ptSlot;
        ret.status = EXCEPTION_NONE;
        return ret;
    }
}

exception_t checkValidIPCBuffer(vptr_t vptr, cap_t cap)
{
    if (cap_get_capType(cap) != cap_frame_cap) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IPC Buffer is an invalid cap." ">>" "\033[0m" "\n", 0lu, __func__, 651, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
    if (__builtin_expect(!!(cap_frame_cap_get_capFIsDevice(cap)), 0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Specifying a device frame as an IPC buffer is not permitted." ">>" "\033[0m" "\n", 0lu, __func__, 656, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (!(!((vptr) & ((1ul << (10))-1ul)))) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IPC Buffer vaddr 0x%x is not aligned." ">>" "\033[0m" "\n", 0lu, __func__, 662, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (int)vptr); } while (0);
        current_syscall_error.type = seL4_AlignmentError;
        return EXCEPTION_SYSCALL_ERROR;
    }

    return EXCEPTION_NONE;
}

vm_rights_t __attribute__((__const__)) maskVMRights(vm_rights_t vm_rights, seL4_CapRights_t cap_rights_mask)
{
    if (vm_rights == VMReadOnly && seL4_CapRights_get_capAllowRead(cap_rights_mask)) {
        return VMReadOnly;
    }
    if (vm_rights == VMReadWrite && seL4_CapRights_get_capAllowRead(cap_rights_mask)) {
        if (!seL4_CapRights_get_capAllowWrite(cap_rights_mask)) {
            return VMReadOnly;
        } else {
            return VMReadWrite;
        }
    }
    return VMKernelOnly;
}

void flushTable(vspace_root_t *vspace, word_t vptr, pte_t *pt, asid_t asid)
{
    word_t i;
    cap_t threadRoot;

    if(!((!((vptr) & ((1ul << (9 + 12))-1ul))))) _assert_fail("IS_ALIGNED(vptr, PT_INDEX_BITS + PAGE_BITS)", "/host/kernel/src/arch/x86/kernel/vspace.c", 690, __FUNCTION__);

    /* check if page table belongs to current address space */
    threadRoot = (((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbVTable))->cap;
    /* find valid mappings */
    for (i = 0; i < (1ul << (9)); i++) {
        if (pte_get_present(pt[i])) {
            if (0 || (isValidNativeRoot(threadRoot)
                                                    && (vspace_root_t *)(pptr_t)cap_get_capPtr(threadRoot) == vspace)) {
                invalidateTranslationSingleASID(vptr + (i << 12), asid,
                                                0);
            }
        }
    }
}


void unmapPage(vm_page_size_t page_size, asid_t asid, vptr_t vptr, void *pptr)
{
    findVSpaceForASID_ret_t find_ret;
    lookupPTSlot_ret_t lu_ret;
    lookupPDSlot_ret_t pd_ret;
    pde_t *pde;

    find_ret = findVSpaceForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        return;
    }

    switch (page_size) {
    case X86_SmallPage:
        lu_ret = lookupPTSlot(find_ret.vspace_root, vptr);
        if (lu_ret.status != EXCEPTION_NONE) {
            return;
        }
        if (!(pte_ptr_get_present(lu_ret.ptSlot)
              && (pte_ptr_get_page_base_address(lu_ret.ptSlot)
                  == addrFromPPtr(pptr)))) {
            return;
        }
        *lu_ret.ptSlot = makeUserPTEInvalid();
        break;

    case X86_LargePage:
        pd_ret = lookupPDSlot(find_ret.vspace_root, vptr);
        if (pd_ret.status != EXCEPTION_NONE) {
            return;
        }
        pde = pd_ret.pdSlot;
        if (!(pde_ptr_get_page_size(pde) == pde_pde_large
              && pde_pde_large_ptr_get_present(pde)
              && (pde_pde_large_ptr_get_page_base_address(pde)
                  == addrFromPPtr(pptr)))) {
            return;
        }
        *pde = makeUserPDEInvalid();
        break;

    default:
        if (!modeUnmapPage(page_size, find_ret.vspace_root, vptr, pptr)) {
            return;
        }
        break;
    }

    invalidateTranslationSingleASID(vptr, asid,
                                    0);
}

void unmapPageTable(asid_t asid, vptr_t vaddr, pte_t *pt)
{
    findVSpaceForASID_ret_t find_ret;
    lookupPDSlot_ret_t lu_ret;

    find_ret = findVSpaceForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        return;
    }

    lu_ret = lookupPDSlot(find_ret.vspace_root, vaddr);
    if (lu_ret.status != EXCEPTION_NONE) {
        return;
    }

    /* check if the PD actually refers to the PT */
    if (!(pde_ptr_get_page_size(lu_ret.pdSlot) == pde_pde_pt &&
          pde_pde_pt_ptr_get_present(lu_ret.pdSlot) &&
          (pde_pde_pt_ptr_get_pt_base_address(lu_ret.pdSlot) == addrFromPPtr(pt)))) {
        return;
    }

    flushTable(find_ret.vspace_root, vaddr, pt, asid);

    *lu_ret.pdSlot = makeUserPDEInvalid();

    invalidatePageStructureCacheASID(addrFromPPtr(find_ret.vspace_root), asid,
                                     0);
}

static exception_t performX86PageInvocationMapPTE(cap_t cap, cte_t *ctSlot, pte_t *ptSlot, pte_t pte,
                                                  vspace_root_t *vspace)
{
    ctSlot->cap = cap;
    *ptSlot = pte;
    invalidatePageStructureCacheASID(addrFromPPtr(vspace), cap_frame_cap_get_capFMappedASID(cap),
                                     0);
    return EXCEPTION_NONE;
}

static exception_t performX86PageInvocationMapPDE(cap_t cap, cte_t *ctSlot, pde_t *pdSlot, pde_t pde,
                                                  vspace_root_t *vspace)
{
    ctSlot->cap = cap;
    *pdSlot = pde;
    invalidatePageStructureCacheASID(addrFromPPtr(vspace), cap_frame_cap_get_capFMappedASID(cap),
                                     0);
    return EXCEPTION_NONE;
}


static exception_t performX86PageInvocationUnmap(cap_t cap, cte_t *ctSlot)
{
    if(!(cap_frame_cap_get_capFMappedASID(cap))) _assert_fail("cap_frame_cap_get_capFMappedASID(cap)", "/host/kernel/src/arch/x86/kernel/vspace.c", 812, __FUNCTION__);
    if(!(cap_frame_cap_get_capFMapType(cap) == X86_MappingVSpace)) _assert_fail("cap_frame_cap_get_capFMapType(cap) == X86_MappingVSpace", "/host/kernel/src/arch/x86/kernel/vspace.c", 813, __FUNCTION__);
    // We have this `if` for something we just asserted to be true for simplicity of verification
    // This has no performance implications as when this function is inlined this `if` will be
    // inside an identical `if` and will therefore be elided
    if (cap_frame_cap_get_capFMappedASID(cap)) {
        unmapPage(
            cap_frame_cap_get_capFSize(cap),
            cap_frame_cap_get_capFMappedASID(cap),
            cap_frame_cap_get_capFMappedAddress(cap),
            (void *)cap_frame_cap_get_capFBasePtr(cap)
        );
    }

    cap_frame_cap_ptr_set_capFMappedAddress(&ctSlot->cap, 0);
    cap_frame_cap_ptr_set_capFMappedASID(&ctSlot->cap, asidInvalid);
    cap_frame_cap_ptr_set_capFMapType(&ctSlot->cap, X86_MappingNone);

    return EXCEPTION_NONE;
}

static exception_t performX86FrameInvocationUnmap(cap_t cap, cte_t *cte)
{
    if (cap_frame_cap_get_capFMappedASID(cap) != asidInvalid) {
        switch (cap_frame_cap_get_capFMapType(cap)) {
        case X86_MappingVSpace:
            return performX86PageInvocationUnmap(cap, cte);
# 847 "/host/kernel/src/arch/x86/kernel/vspace.c"
        case X86_MappingNone:
            _fail("Mapped frame cap was not mapped", "/host/kernel/src/arch/x86/kernel/vspace.c", 848, __func__);
            break;
        }
    }

    return EXCEPTION_NONE;
}

struct create_mapping_pte_return {
    exception_t status;
    pte_t pte;
    pte_t *ptSlot;
};
typedef struct create_mapping_pte_return create_mapping_pte_return_t;

static create_mapping_pte_return_t createSafeMappingEntries_PTE(paddr_t base, word_t vaddr, vm_rights_t vmRights,
                                                                vm_attributes_t attr,
                                                                vspace_root_t *vspace)
{
    create_mapping_pte_return_t ret;
    lookupPTSlot_ret_t lu_ret;

    lu_ret = lookupPTSlot(vspace, vaddr);
    if (lu_ret.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;
        ret.status = EXCEPTION_SYSCALL_ERROR;
        /* current_lookup_fault will have been set by lookupPTSlot */
        return ret;
    }

    ret.pte = makeUserPTE(base, attr, vmRights);
    ret.ptSlot = lu_ret.ptSlot;
    ret.status = EXCEPTION_NONE;
    return ret;
}

struct create_mapping_pde_return {
    exception_t status;
    pde_t pde;
    pde_t *pdSlot;
};
typedef struct create_mapping_pde_return create_mapping_pde_return_t;

static create_mapping_pde_return_t createSafeMappingEntries_PDE(paddr_t base, word_t vaddr, vm_rights_t vmRights,
                                                                vm_attributes_t attr,
                                                                vspace_root_t *vspace)
{
    create_mapping_pde_return_t ret;
    lookupPDSlot_ret_t lu_ret;

    lu_ret = lookupPDSlot(vspace, vaddr);
    if (lu_ret.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;
        ret.status = EXCEPTION_SYSCALL_ERROR;
        /* current_lookup_fault will have been set by lookupPDSlot */
        return ret;
    }
    ret.pdSlot = lu_ret.pdSlot;

    /* check for existing page table */
    if ((pde_ptr_get_page_size(ret.pdSlot) == pde_pde_pt) &&
        (pde_pde_pt_ptr_get_present(ret.pdSlot))) {
        current_syscall_error.type = seL4_DeleteFirst;
        ret.status = EXCEPTION_SYSCALL_ERROR;
        return ret;
    }


    ret.pde = makeUserPDELargePage(base, attr, vmRights);
    ret.status = EXCEPTION_NONE;
    return ret;
}


exception_t decodeX86FrameInvocation(
    word_t invLabel,
    word_t length,
    cte_t *cte,
    cap_t cap,
    extra_caps_t excaps,
    word_t *buffer
)
{
    switch (invLabel) {
    case X86PageMap: { /* Map */
        word_t vaddr;
        word_t vtop;
        word_t w_rightsMask;
        paddr_t paddr;
        cap_t vspaceCap;
        vspace_root_t *vspace;
        vm_rights_t capVMRights;
        vm_rights_t vmRights;
        vm_attributes_t vmAttr;
        vm_page_size_t frameSize;
        asid_t asid;

        if (length < 3 || excaps.excaprefs[0] == ((void *)0)) {
            current_syscall_error.type = seL4_TruncatedMessage;

            return EXCEPTION_SYSCALL_ERROR;
        }

        frameSize = cap_frame_cap_get_capFSize(cap);
        vaddr = getSyscallArg(0, buffer);
        w_rightsMask = getSyscallArg(1, buffer);
        vmAttr = vmAttributesFromWord(getSyscallArg(2, buffer));
        vspaceCap = excaps.excaprefs[0]->cap;

        capVMRights = cap_frame_cap_get_capFVMRights(cap);

        if (!isValidNativeRoot(vspaceCap)) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86FrameMap: Attempting to map frame into invalid page directory cap." ">>" "\033[0m" "\n", 0lu, __func__, 962, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 1;

            return EXCEPTION_SYSCALL_ERROR;
        }
        vspace = (vspace_root_t *)(pptr_t)cap_get_capPtr(vspaceCap);
        asid = cap_get_capMappedASID(vspaceCap);

        if (cap_frame_cap_get_capFMappedASID(cap) != asidInvalid) {
            if (cap_frame_cap_get_capFMappedASID(cap) != asid) {
                current_syscall_error.type = seL4_InvalidCapability;
                current_syscall_error.invalidCapNumber = 1;

                return EXCEPTION_SYSCALL_ERROR;
            }

            if (cap_frame_cap_get_capFMapType(cap) != X86_MappingVSpace) {
                do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86Frame: Attempting to remap frame with different mapping type" ">>" "\033[0m" "\n", 0lu, __func__, 980, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
                current_syscall_error.type = seL4_IllegalOperation;

                return EXCEPTION_SYSCALL_ERROR;
            }

            if (cap_frame_cap_get_capFMappedAddress(cap) != vaddr) {
                do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86Frame: Attempting to map frame into multiple addresses" ">>" "\033[0m" "\n", 0lu, __func__, 987, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
                current_syscall_error.type = seL4_InvalidArgument;
                current_syscall_error.invalidArgumentNumber = 0;

                return EXCEPTION_SYSCALL_ERROR;
            }
        } else {
            vtop = vaddr + (1ul << (pageBitsForSize(frameSize)));

            /* check vaddr and vtop against USER_TOP to catch case where vaddr + frame_size wrapped around */
            if (vaddr > 0x7FFFFFFFFFFFul || vtop > 0x7FFFFFFFFFFFul) {
                do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86Frame: Mapping address too high." ">>" "\033[0m" "\n", 0lu, __func__, 998, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
                current_syscall_error.type = seL4_InvalidArgument;
                current_syscall_error.invalidArgumentNumber = 0;

                return EXCEPTION_SYSCALL_ERROR;
            }
        }

        {
            findVSpaceForASID_ret_t find_ret;

            find_ret = findVSpaceForASID(asid);
            if (find_ret.status != EXCEPTION_NONE) {
                current_syscall_error.type = seL4_FailedLookup;
                current_syscall_error.failedLookupWasSource = false;

                return EXCEPTION_SYSCALL_ERROR;
            }

            if (find_ret.vspace_root != vspace) {
                current_syscall_error.type = seL4_InvalidCapability;
                current_syscall_error.invalidCapNumber = 1;

                return EXCEPTION_SYSCALL_ERROR;
            }
        }

        vmRights = maskVMRights(capVMRights, rightsFromWord(w_rightsMask));

        if (!checkVPAlignment(frameSize, vaddr)) {
            current_syscall_error.type = seL4_AlignmentError;

            return EXCEPTION_SYSCALL_ERROR;
        }

        paddr = addrFromPPtr((void *)cap_frame_cap_get_capFBasePtr(cap));

        cap = cap_frame_cap_set_capFMappedASID(cap, asid);
        cap = cap_frame_cap_set_capFMappedAddress(cap, vaddr);
        cap = cap_frame_cap_set_capFMapType(cap, X86_MappingVSpace);

        switch (frameSize) {
        /* PTE mappings */
        case X86_SmallPage: {
            create_mapping_pte_return_t map_ret;

            map_ret = createSafeMappingEntries_PTE(paddr, vaddr, vmRights, vmAttr, vspace);
            if (map_ret.status != EXCEPTION_NONE) {
                return map_ret.status;
            }

            setThreadState(ksCurThread, ThreadState_Restart);
            return performX86PageInvocationMapPTE(cap, cte, map_ret.ptSlot, map_ret.pte, vspace);
        }

        /* PDE mappings */
        case X86_LargePage: {
            create_mapping_pde_return_t map_ret;

            map_ret = createSafeMappingEntries_PDE(paddr, vaddr, vmRights, vmAttr, vspace);
            if (map_ret.status != EXCEPTION_NONE) {
                return map_ret.status;
            }

            setThreadState(ksCurThread, ThreadState_Restart);
            return performX86PageInvocationMapPDE(cap, cte, map_ret.pdSlot, map_ret.pde, vspace);
        }

        default: {
            return decodeX86ModeMapPage(invLabel, frameSize, cte, cap, vspace, vaddr, paddr, vmRights, vmAttr);
        }
        }

        return EXCEPTION_SYSCALL_ERROR;
    }

    case X86PageUnmap: { /* Unmap */
        setThreadState(ksCurThread, ThreadState_Restart);
        return performX86FrameInvocationUnmap(cap, cte);
    }
# 1090 "/host/kernel/src/arch/x86/kernel/vspace.c"
    case X86PageGetAddress: {
        /* Return it in the first message register. */
        if(!(n_msgRegisters >= 1)) _assert_fail("n_msgRegisters >= 1", "/host/kernel/src/arch/x86/kernel/vspace.c", 1092, __FUNCTION__);

        setThreadState(ksCurThread, ThreadState_Restart);
        return performPageGetAddress((void *)cap_frame_cap_get_capFBasePtr(cap));
    }

    default:
        current_syscall_error.type = seL4_IllegalOperation;

        return EXCEPTION_SYSCALL_ERROR;
    }
}

static exception_t performX86PageTableInvocationUnmap(cap_t cap, cte_t *ctSlot)
{

    if (cap_page_table_cap_get_capPTIsMapped(cap)) {
        pte_t *pt = ((pte_t *)(cap_page_table_cap_get_capPTBasePtr(cap)));
        unmapPageTable(
            cap_page_table_cap_get_capPTMappedASID(cap),
            cap_page_table_cap_get_capPTMappedAddress(cap),
            pt
        );
        clearMemory((void *)pt, cap_get_capSizeBits(cap));
    }
    cap_page_table_cap_ptr_set_capPTIsMapped(&(ctSlot->cap), 0);

    return EXCEPTION_NONE;
}

static exception_t performX86PageTableInvocationMap(cap_t cap, cte_t *ctSlot, pde_t pde, pde_t *pdSlot,
                                                    vspace_root_t *root)
{
    ctSlot->cap = cap;
    *pdSlot = pde;
    invalidatePageStructureCacheASID(addrFromPPtr(root), cap_page_table_cap_get_capPTMappedASID(cap),
                                     0);
    return EXCEPTION_NONE;
}

static exception_t decodeX86PageTableInvocation(
    word_t invLabel,
    word_t length,
    cte_t *cte, cap_t cap,
    extra_caps_t excaps,
    word_t *buffer
)
{
    word_t vaddr;
    vm_attributes_t attr;
    lookupPDSlot_ret_t pdSlot;
    cap_t vspaceCap;
    vspace_root_t *vspace;
    pde_t pde;
    paddr_t paddr;
    asid_t asid;

    if (invLabel == X86PageTableUnmap) {
        if (! isFinalCapability(cte)) {
            current_syscall_error.type = seL4_RevokeFirst;
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86PageTable: Cannot unmap if more than one cap exists." ">>" "\033[0m" "\n", 0lu, __func__, 1152, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            return EXCEPTION_SYSCALL_ERROR;
        }
        setThreadState(ksCurThread, ThreadState_Restart);
        return performX86PageTableInvocationUnmap(cap, cte);
    }

    if (invLabel != X86PageTableMap) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86PageTable: Illegal operation." ">>" "\033[0m" "\n", 0lu, __func__, 1160, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (length < 2 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86PageTable: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 1166, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cap_page_table_cap_get_capPTIsMapped(cap)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86PageTable: Page table is already mapped to a page directory." ">>" "\033[0m" "\n", 0lu, __func__, 1172, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type =
            seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vaddr = getSyscallArg(0, buffer) & (~((1ul << (9 + 12))-1ul));
    attr = vmAttributesFromWord(getSyscallArg(1, buffer));
    vspaceCap = excaps.excaprefs[0]->cap;

    if (!isValidNativeRoot(vspaceCap)) {
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vspace = (vspace_root_t *)(pptr_t)cap_get_capPtr(vspaceCap);
    asid = cap_get_capMappedASID(vspaceCap);

    if (vaddr > 0x7FFFFFFFFFFFul) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86PageTable: Mapping address too high." ">>" "\033[0m" "\n", 0lu, __func__, 1195, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    {
        findVSpaceForASID_ret_t find_ret;

        find_ret = findVSpaceForASID(asid);
        if (find_ret.status != EXCEPTION_NONE) {
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = false;

            return EXCEPTION_SYSCALL_ERROR;
        }

        if (find_ret.vspace_root != vspace) {
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 1;

            return EXCEPTION_SYSCALL_ERROR;
        }
    }

    pdSlot = lookupPDSlot(vspace, vaddr);
    if (pdSlot.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        return EXCEPTION_SYSCALL_ERROR;
    }

    if (((pde_ptr_get_page_size(pdSlot.pdSlot) == pde_pde_pt) && pde_pde_pt_ptr_get_present(pdSlot.pdSlot)) ||
        ((pde_ptr_get_page_size(pdSlot.pdSlot) == pde_pde_large) && pde_pde_large_ptr_get_present(pdSlot.pdSlot))) {
        current_syscall_error.type = seL4_DeleteFirst;

        return EXCEPTION_SYSCALL_ERROR;
    }

    paddr = addrFromPPtr(((pte_t *)(cap_page_table_cap_get_capPTBasePtr(cap))));
    pde = makeUserPDEPageTable(paddr, attr);

    cap = cap_page_table_cap_set_capPTIsMapped(cap, 1);
    cap = cap_page_table_cap_set_capPTMappedASID(cap, asid);
    cap = cap_page_table_cap_set_capPTMappedAddress(cap, vaddr);

    setThreadState(ksCurThread, ThreadState_Restart);
    return performX86PageTableInvocationMap(cap, cte, pde, pdSlot.pdSlot, vspace);
}

exception_t decodeX86MMUInvocation(
    word_t invLabel,
    word_t length,
    cptr_t cptr,
    cte_t *cte,
    cap_t cap,
    extra_caps_t excaps,
    word_t *buffer
)
{
    switch (cap_get_capType(cap)) {

    case cap_frame_cap:
        return decodeX86FrameInvocation(invLabel, length, cte, cap, excaps, buffer);

    case cap_page_table_cap:
        return decodeX86PageTableInvocation(invLabel, length, cte, cap, excaps, buffer);

    case cap_asid_control_cap: {
        word_t i;
        asid_t asid_base;
        word_t index;
        word_t depth;
        cap_t untyped;
        cap_t root;
        cte_t *parentSlot;
        cte_t *destSlot;
        lookupSlot_ret_t lu_ret;
        void *frame;
        exception_t status;

        if (invLabel != X86ASIDControlMakePool) {
            current_syscall_error.type = seL4_IllegalOperation;

            return EXCEPTION_SYSCALL_ERROR;
        }

        if (length < 2 || excaps.excaprefs[0] == ((void *)0)
            || excaps.excaprefs[1] == ((void *)0)) {
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }

        index = getSyscallArg(0, buffer);
        depth = getSyscallArg(1, buffer);
        parentSlot = excaps.excaprefs[0];
        untyped = parentSlot->cap;
        root = excaps.excaprefs[1]->cap;

        /* Find first free pool */
        for (i = 0; i < (1ul << (asidHighBits)) && x86KSASIDTable[i]; i++);

        if (i == (1ul << (asidHighBits))) {
            /* no unallocated pool is found */
            current_syscall_error.type = seL4_DeleteFirst;

            return EXCEPTION_SYSCALL_ERROR;
        }

        asid_base = i << asidLowBits;


        if (cap_get_capType(untyped) != cap_untyped_cap ||
            cap_untyped_cap_get_capBlockSize(untyped) != 12 ||
            cap_untyped_cap_get_capIsDevice(untyped)) {
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 1;

            return EXCEPTION_SYSCALL_ERROR;
        }

        status = ensureNoChildren(parentSlot);
        if (status != EXCEPTION_NONE) {
            return status;
        }

        frame = ((word_t *)(cap_untyped_cap_get_capPtr(untyped)));

        lu_ret = lookupTargetSlot(root, index, depth);
        if (lu_ret.status != EXCEPTION_NONE) {
            return lu_ret.status;
        }
        destSlot = lu_ret.slot;

        status = ensureEmptySlot(destSlot);
        if (status != EXCEPTION_NONE) {
            return status;
        }

        setThreadState(ksCurThread, ThreadState_Restart);
        return performASIDControlInvocation(frame, destSlot, parentSlot, asid_base);
    }

    case cap_asid_pool_cap: {
        cap_t vspaceCap;
        cte_t *vspaceCapSlot;
        asid_pool_t *pool;
        word_t i;
        asid_t asid;

        if (invLabel != X86ASIDPoolAssign) {
            current_syscall_error.type = seL4_IllegalOperation;

            return EXCEPTION_SYSCALL_ERROR;
        }
        if (excaps.excaprefs[0] == ((void *)0)) {
            current_syscall_error.type = seL4_TruncatedMessage;

            return EXCEPTION_SYSCALL_ERROR;
        }

        vspaceCapSlot = excaps.excaprefs[0];
        vspaceCap = vspaceCapSlot->cap;

        if (!(isVTableRoot(vspaceCap) || 0)
            || cap_get_capMappedASID(vspaceCap) != asidInvalid) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "X86ASIDPool: Invalid vspace root." ">>" "\033[0m" "\n", 0lu, __func__, 1363, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 1;

            return EXCEPTION_SYSCALL_ERROR;
        }

        pool = x86KSASIDTable[cap_asid_pool_cap_get_capASIDBase(cap) >> asidLowBits];
        if (!pool) {
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = false;
            current_lookup_fault = lookup_fault_invalid_root_new();
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (pool != ((asid_pool_t*)cap_asid_pool_cap_get_capASIDPool(cap))) {
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 0;
            return EXCEPTION_SYSCALL_ERROR;
        }

        /* Find first free ASID */
        asid = cap_asid_pool_cap_get_capASIDBase(cap);
        for (i = 0; i < (1ul << (asidLowBits)) && (asid + i == 0
                                             || asid_map_get_type(pool->array[i]) != asid_map_asid_map_none); i++);

        if (i == (1ul << (asidLowBits))) {
            current_syscall_error.type = seL4_DeleteFirst;

            return EXCEPTION_SYSCALL_ERROR;
        }

        asid += i;

        setThreadState(ksCurThread, ThreadState_Restart);
        return performASIDPoolInvocation(asid, pool, vspaceCapSlot);
    }

    default:
        return decodeX86ModeMMUInvocation(invLabel, length, cptr, cte, cap, excaps, buffer);
    }
}
# 1 "/host/kernel/src/arch/x86/kernel/x2apic.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




__attribute__((__section__(".boot.text"))) bool_t x2apic_is_enabled(void)
{
    apic_base_msr_t apic_base_msr;
    apic_base_msr.words[0] = x86_rdmsr_low(0x01B);

    if ((x86_cpuid_ecx(1, 0) & (1ul << (21))) &&
        apic_base_msr_get_enabled(apic_base_msr) &&
        apic_base_msr_get_x2apic(apic_base_msr)) {
        return true;
    }
    return false;
}
# 1 "/host/kernel/src/arch/x86/kernel/xapic.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 28 "/host/kernel/src/arch/x86/kernel/xapic.c"
__attribute__((__section__(".boot.text"))) bool_t apic_enable(void)
{
    apic_base_msr_t apic_base_msr;
    apic_base_msr.words[0] = x86_rdmsr_low(0x01B);

    if (!apic_base_msr_get_enabled(apic_base_msr)) {
        kprintf("APIC: Enabled bit not set\n");
        return false;
    }

    if (x2apic_is_enabled()) {
        kprintf("x2APIC enabled in BIOS but kernel does not support that\n");
        return false;
    }





    return true;
}

bool_t apic_is_interrupt_pending(void)
{
    word_t i;

    /* read 256-bit register: each 32-bit word is 16 byte aligned */
    if(!(int_irq_min % 32 == 0)) _assert_fail("int_irq_min % 32 == 0", "/host/kernel/src/arch/x86/kernel/xapic.c", 55, __FUNCTION__);
    for (i = int_irq_min; i <= int_irq_max; i += 32) {
        if (apic_read_reg(APIC_IRR_BASE + i / 2) != 0) {
            return true;
        }
    }
    return false;
}

__attribute__((__section__(".boot.text"))) void apic_send_init_ipi(cpu_id_t cpu_id)
{
    apic_write_icr(
        apic_icr2_new(
            cpu_id /* dest */
        ).words[0],
        apic_icr1_new(
            0, /* dest_shorthand  */
            1, /* trigger_mode    */
            1, /* level           */
            0, /* delivery_status */
            0, /* dest_mode       */
            5, /* delivery_mode   */
            0 /* vector          */
        ).words[0]
    );
    apic_write_icr(
        apic_icr2_new(
            cpu_id /* dest */
        ).words[0],
        apic_icr1_new(
            0, /* dest_shorthand  */
            1, /* trigger_mode    */
            0, /* level           */
            0, /* delivery_status */
            0, /* dest_mode       */
            5, /* delivery_mode   */
            0 /* vector          */
        ).words[0]
    );
}

__attribute__((__section__(".boot.text"))) void apic_send_startup_ipi(cpu_id_t cpu_id, paddr_t startup_addr)
{
    /* check if 4K aligned */
    if(!((!((startup_addr) & ((1ul << (12))-1ul))))) _assert_fail("IS_ALIGNED(startup_addr, PAGE_BITS)", "/host/kernel/src/arch/x86/kernel/xapic.c", 99, __FUNCTION__);
    /* check if startup_addr < 640K */
    if(!(startup_addr < 0xa0000)) _assert_fail("startup_addr < 0xa0000", "/host/kernel/src/arch/x86/kernel/xapic.c", 101, __FUNCTION__);
    startup_addr >>= 12;

    apic_write_icr(
        apic_icr2_new(
            cpu_id /* dest */
        ).words[0],
        apic_icr1_new(
            0, /* dest_shorthand  */
            0, /* trigger_mode    */
            0, /* level           */
            0, /* delivery_status */
            0, /* dest_mode       */
            6, /* delivery_mode   */
            startup_addr /* vector          */
        ).words[0]
    );
}

void apic_send_ipi_core(irq_t vector, cpu_id_t cpu_id)
{
    apic_icr1_t icr1;
    /* wait till we can send an IPI */
    do {
        icr1.words[0] = apic_read_reg(APIC_ICR1);
    } while (apic_icr1_get_delivery_status(icr1));

    apic_write_icr(
        apic_icr2_new(
            cpu_id /* dest */
        ).words[0],
        apic_icr1_new(
            0, /* dest_shorthand  */
            0, /* trigger_mode    */
            0, /* level           */
            0, /* delivery_status */
            0, /* dest_mode       */
            0, /* delivery_mode   */
            vector /* vector          */
        ).words[0]
    );
}

void apic_send_ipi_cluster(irq_t vector, word_t mda)
{
    apic_icr1_t icr1;
    /* wait till we can send an IPI */
    do {
        icr1.words[0] = apic_read_reg(APIC_ICR1);
    } while (apic_icr1_get_delivery_status(icr1));

    apic_write_icr(
        apic_icr2_new(
            mda /* message destination address */
        ).words[0],
        apic_icr1_new(
            0, /* dest_shorthand  */
            0, /* trigger_mode    */
            0, /* level           */
            0, /* delivery_status */
            1, /* dest_mode       */
            0, /* delivery_mode   */
            vector /* vector          */
        ).words[0]
    );
}
# 1 "/host/kernel/src/arch/x86/machine/breakpoint.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/arch/x86/machine/capdl.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 15 "/host/kernel/src/arch/x86/machine/capdl.c"
void x86_obj_ioports_print_attrs(cap_t ioports_cap)
{
    kprintf("(ports: (%lu, %lu))\n", (long unsigned int)cap_io_port_cap_get_capIOPortFirstPort(ioports_cap), (long unsigned int)cap_io_port_cap_get_capIOPortLastPort(ioports_cap))

                                                                                 ;
}
# 1 "/host/kernel/src/arch/x86/machine/cpu_identification.c"
/*
 * Copyright 2016, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */





/** @file Support routines for identifying the processor family, model, etc
 * on INTEL x86 processors, as well as attempting to determine the model string.
 *
 * AMD processors would be different.
 */

const char X86_CPUID_VENDOR_STRING_INTEL[] = {'G', 'e', 'n', 'u', 'i', 'n', 'e', 'I', 'n', 't', 'e', 'l', 0};
const char X86_CPUID_VENDOR_STRING_AMD_LEGACY[] = { 'A', 'M', 'D', 'i', 's', 'b', 'e', 't', 't', 'e', 'r', '!', 0};
const char X86_CPUID_VENDOR_STRING_AMD[] = {'A', 'u', 't', 'h', 'e', 'n', 't', 'i', 'c', 'A', 'M', 'D', 0};

__attribute__((__section__(".boot.bss"))) static cpu_identity_t cpu_identity;

__attribute__((__section__(".boot.text"))) cpu_identity_t *x86_cpuid_get_identity(void)
{
    return &cpu_identity;
}

__attribute__((__section__(".boot.text"))) x86_cpu_identity_t *x86_cpuid_get_model_info(void)
{
    return &cpu_identity.display;
}

/** Extracts the vendor string from CPUID_000H.E[BCD]X.
 * Will be one of "GenuineIntel", "AMDisbetter!", "AuthenticAMD", "CentaurHauls"
 * etc. We don't support x86 CPUs from vendors other than AMD and Intel.
 */
__attribute__((__section__(".boot.text"))) static void x86_cpuid_fill_vendor_string(cpu_identity_t *ci)
{
    __attribute__((may_alias)) uint32_t *vendor_string32 = (uint32_t *)ci->vendor_string;

    if (ci == ((void *)0)) {
        return;
    }

    vendor_string32[0] = x86_cpuid_ebx(0, 0);
    vendor_string32[1] = x86_cpuid_edx(0, 0);
    vendor_string32[2] = x86_cpuid_ecx(0, 0);

    ci->vendor_string[(12)] = '\0';
}

struct family_model {
    uint8_t family, model;
};

__attribute__((__section__(".boot.text"))) static void x86_cpuid_intel_identity_initialize(cpu_identity_t *ci,
                                                          struct family_model original)
{
    /* Next, there are some values which require additional adjustment, and
     * require you to take into account an additional extended family and model
     * ID.
     *
     * See Intel manuals vol2, section 3.2 for the literal constants.
     */
    if (original.family != 0x0F) {
        ci->display.family = original.family;
    } else {
        ci->display.family = ci->display.extended_family + original.family;
    }

    /* The Intel manuals' wording would make you think you should use the
     * original family_ID value read from CPUID.EAX, like:
     *      if (original->family == 0x06 || original->family == 0x0F) {
     *
     * But Linux doesn't do that, Linux uses the family_ID value AFTER
     * adjustment, like:
     *      if (ci->display.family == 0x06 || ci->display.family == 0x0F) {
     *
     * Additionally, even though the Intel manuals say to adjust the model
     * number if the family number is 0x6 OR 0xF, Linux just adusts it as long
     * as the family number is GREATER THAN OR EQUAL to 0x6.
     *
     * I have followed Linux in the first case, where it could be a case of
     * them having the correct interpretation of the text, but in the second case
     * where they flagrantly disobey the manual, I have not followed them.
     *
     * See Linux source at: /arch/x86/lib/cpu.c:
     *      http://lxr.free-electrons.com/source/arch/x86/lib/cpu.c
     */
    if (ci->display.family == 0x06 || ci->display.family == 0x0F) {
        ci->display.model = (ci->display.extended_model << 4u) + original.model;
    } else {
        ci->display.model = original.model;
    }
}

__attribute__((__section__(".boot.text"))) static void x86_cpuid_amd_identity_initialize(cpu_identity_t *ci,
                                                        struct family_model original)
{
    /* Intel and AMD's specifications give slightly different ways to compose
     * the family and model IDs (AMD CPUID manual, section 2.)
     *
     * AMD says that if family is LESS THAN 0xF, then adjustments are needed.
     * Intel says that if family == 0xF || family == 0x6, then adjustments are
     * needed.
     */
    if (original.family < 0xF) {
        ci->display.family = original.family;
        ci->display.model = original.model;
    } else {
        ci->display.family = original.family + ci->display.extended_family;
        ci->display.family = (ci->display.extended_model << 4u) + original.model;
    }
}

bool_t x86_cpuid_initialize(void)
{
    cpu_identity_t *ci = x86_cpuid_get_identity();
    struct family_model original;
    cpuid_001h_eax_t eax;
    cpuid_001h_ebx_t ebx;

    memset(ci, 0, sizeof(*ci));

    /* First determine which vendor manufactured the CPU. */
    x86_cpuid_fill_vendor_string(ci);

    /* Need both eax and ebx ouput values. */
    eax.words[0] = x86_cpuid_eax(1, 0);
    ebx.words[0] = x86_cpuid_ebx(1, 0);

    /* We now use EAX for the family, model, stepping values, and EBX for the
     * brand index. Store the original values from CPUID_001H.EAX.
     */
    original.family = cpuid_001h_eax_get_family(eax);
    original.model = cpuid_001h_eax_get_model(eax);
    ci->display.stepping = cpuid_001h_eax_get_stepping(eax);

    /* Also store extended family and model values used for adjustment */
    ci->display.extended_family = cpuid_001h_eax_get_extended_family(eax);
    ci->display.extended_model = cpuid_001h_eax_get_extended_model(eax);

    /* Also store the brand index value given in EBX */
    ci->display.brand = cpuid_001h_ebx_get_brand(ebx);

    if (strncmp(ci->vendor_string, X86_CPUID_VENDOR_STRING_INTEL,
                (12)) == 0) {
        ci->vendor = X86_VENDOR_INTEL;
        x86_cpuid_intel_identity_initialize(ci, original);
        return true;
    } else if (strncmp(ci->vendor_string, X86_CPUID_VENDOR_STRING_AMD_LEGACY,
                       (12)) == 0
               || strncmp(ci->vendor_string, X86_CPUID_VENDOR_STRING_AMD,
                          (12)) == 0) {
        ci->vendor = X86_VENDOR_AMD;
        x86_cpuid_amd_identity_initialize(ci, original);
        return true;
    } else {
        /* CPU from unsupported vendor. Examples could be Cyrix, Centaur, etc.
         * The old time x86 clones. Return false to the boot and let the upper
         * level caller decide what to do.
         */
        ci->vendor = X86_VENDOR_OTHER;
        return false;
    }
}
# 1 "/host/kernel/src/arch/x86/machine/fpu.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */







/*
 * Setup the FPU register state for a new thread.
 */
void Arch_initFpuContext(user_context_t *context)
{
    context->fpuState = x86KSnullFpuState;
}

/*
 * Initialise the FPU for this machine.
 */
__attribute__((__section__(".boot.text"))) bool_t Arch_initFpu(void)
{
    /* Enable FPU / SSE / SSE2 / SSE3 / SSSE3 / SSE4 Extensions. */
    write_cr4(read_cr4() | (1ul << (9)) /* Enable SSE et. al. features. */);

    /* Enable the FPU in general. */
    write_cr0((read_cr0() & ~(1ul << (2)) /* Enable OS emulation of FPU. */) | (1ul << (1)) /* Trap on FPU "WAIT" commands. */ | (1ul << (5)) /* Internally handle FPU problems. */);
    enableFpu();

    /* Initialize the fpu state */
    finit();

    if (0) {
        uint64_t xsave_features;
        uint32_t xsave_instruction;
        uint64_t desired_features = 1;
        xsave_state_t *nullFpuState = (xsave_state_t *) &x86KSnullFpuState;

        /* create NULL state for FPU to be used by XSAVE variants */
        memzero(&x86KSnullFpuState, sizeof(x86KSnullFpuState));

        /* check for XSAVE support */
        if (!(x86_cpuid_ecx(1, 0) & (1ul << (26)))) {
            kprintf("XSAVE not supported\n");
            return false;
        }
        /* enable XSAVE support */
        write_cr4(read_cr4() | (1ul << (18)) /* Enavle XSAVE feature set */);
        /* check feature mask */
        xsave_features = ((uint64_t)x86_cpuid_edx(0x0d, 0x0) << 32) | x86_cpuid_eax(0x0d, 0x0);
        if ((xsave_features & desired_features) != desired_features) {
            kprintf("Requested feature mask is 0x%llx, but only 0x%llx supported\n", desired_features, (long long)xsave_features);
            return false;
        }
        /* enable feature mask */
        write_xcr0(desired_features);
        /* validate the xsave buffer size and instruction */
        if (x86_cpuid_ebx(0x0d, 0x0) > 512) {
            kprintf("XSAVE buffer set set to %d, but needs to be at least %d\n", 512, x86_cpuid_ebx(0x0d, 0x0));
            return false;
        }
        if (x86_cpuid_ebx(0x0d, 0x0) < 512) {
            kprintf("XSAVE buffer set set to %d, but only needs to be %d.\n" "Warning: Memory may be wasted with larger than needed TCBs.\n", 512, x86_cpuid_ebx(0x0d, 0x0))

                                                               ;
        }
        /* check if a specialized XSAVE instruction was requested */
        xsave_instruction = x86_cpuid_eax(0x0d, 0x1);
        if (0) {
            if (!(xsave_instruction & (1ul << (0)))) {
                kprintf("XSAVEOPT requested, but not supported\n");
                return false;
            }
        } else if (0) {
            if (!(xsave_instruction & (1ul << (1)))) {
                kprintf("XSAVEC requested, but not supported\n");
                return false;
            }
        } else if (0) {
            if (!(xsave_instruction & (1ul << (3)))) {
                kprintf("XSAVES requested, but not supported\n");
                return false;
            }

            /* AVX state from extended region should be in compacted format */
            nullFpuState->header.xcomp_bv = (1ull << 63);

            /* initialize the XSS MSR */
            x86_wrmsr(0xD0A, desired_features);
        }

        /* copy i387 FPU initial state from FPU */
        saveFpuState(&x86KSnullFpuState);
        nullFpuState->i387.mxcsr = 0x1f80;
    } else {
        /* Store the null fpu state */
        saveFpuState(&x86KSnullFpuState);
    }
    /* Set the FPU to lazy switch mode */
    disableFpu();
    return true;
}
# 1 "/host/kernel/src/arch/x86/machine/hardware.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 16 "/host/kernel/src/arch/x86/machine/hardware.c"
/* initialises MSRs required to setup sysenter and sysexit */
__attribute__((__section__(".boot.text"))) void init_sysenter_msrs(void)
{
    x86_wrmsr(0x174, (uint64_t)(word_t)(1 << 3));
    x86_wrmsr(0x176, (uint64_t)(word_t)&handle_syscall);
    if (0 && !0) {
        /* manually add 4 bytes to x86KStss so that it is valid for both
         * 32-bit and 64-bit, although only ia32 actually requires a valid
         * sysenter esp */
        x86_wrmsr(0x175, (uint64_t)(word_t)((char *)&x86KSGlobalState[0].x86KStss.tss.words[0]
                                                            + 4));
    }
}

word_t __attribute__((__pure__)) getRestartPC(tcb_t *thread)
{
    return getRegister(thread, FaultIP);
}

void setNextPC(tcb_t *thread, word_t v)
{
    setRegister(thread, NextIP, v);
}

/* Returns the size of CPU's cacheline */
__attribute__((__section__(".boot.text"))) uint32_t __attribute__((__const__)) getCacheLineSizeBits(void)
{
    uint32_t line_size;
    uint32_t n;

    line_size = getCacheLineSize();
    if (line_size == 0) {
        kprintf("Cacheline size must be >0\n");
        return 0;
    }

    /* determine size_bits */
    n = 0;
    while (!(line_size & 1)) {
        line_size >>= 1;
        n++;
    }

    if (line_size != 1) {
        kprintf("Cacheline size must be a power of two\n");
        return 0;
    }

    return n;
}

/* Flushes a specific memory range from the CPU cache */

void flushCacheRange(void *vaddr, uint32_t size_bits)
{
    word_t v;

    if(!(size_bits < 64)) _assert_fail("size_bits < seL4_WordBits", "/host/kernel/src/arch/x86/machine/hardware.c", 73, __FUNCTION__);
    if(!((!(((word_t)vaddr) & ((1ul << (size_bits))-1ul))))) _assert_fail("IS_ALIGNED((word_t)vaddr, size_bits)", "/host/kernel/src/arch/x86/machine/hardware.c", 74, __FUNCTION__);

    x86_mfence();

    for (v = ((((word_t)vaddr) >> (x86KScacheLineSizeBits)) << (x86KScacheLineSizeBits));
         v < (word_t)vaddr + (1ul << (size_bits));
         v += (1ul << (x86KScacheLineSizeBits))) {
        flushCacheLine((void *)v);
    }
    x86_mfence();
}

/* Disables as many prefetchers as possible */
__attribute__((__section__(".boot.text"))) bool_t disablePrefetchers(void)
{
    x86_cpu_identity_t *model_info;
    uint32_t low, high;
    word_t i;

    uint32_t valid_models[] = { 0x4D, 0x56,
                                0x4F, 0x47,
                                0x3D,
                                0x3C, 0x3F,
                                0x45, 0x46,
                                0x9A, 0x3E,
                                0x3A,
                                0x2A /* Sandy Bridge */, 0x2D /* Sandy Bridge-E, Sandy Bridge-EN and Sandy Bridge-EP */, 0x25 /* Arrandale and Clarksdale */, 0x2C /* Gulftown and Westmere-EP */,
                                0x2F /* Westemere-EX */, 0x1E /* Clarksfield, Lynnfield and Jasper Forest */, 0x1A /* Bloomfield and Nehalem-EP */, 0x2E /* Nehalem-EX */,
                                0x4E, 0x5E
                              };

    model_info = x86_cpuid_get_model_info();

    for (i = 0; i < (sizeof(valid_models) / sizeof(valid_models[0])); i++) {
        /* The model ID is only useful when hashed together with the family ID.
         * They are both meant to be combined to form a unique identifier.
         *
         * As far as I can tell though, we might be able to actually just
         * disable prefetching on anything that matches family_ID==0x6, and
         * there is no need to also look at the model_ID.
         */
        if (model_info->family == (0x06)
            && model_info->model == valid_models[i]) {
            low = x86_rdmsr_low(0x1A4);
            high = x86_rdmsr_high(0x1A4);

            low |= (1ul << (0));
            low |= (1ul << (1));
            low |= (1ul << (2));
            low |= (1ul << (3));

            x86_wrmsr(0x1A4, ((uint64_t)high) << 32 | low);

            return true;
        }
    }

    kprintf("Disabling prefetchers not implemented for CPU fam %x model %x\n", model_info->family, model_info->model)
                                                 ;
    return false;
}

__attribute__((__section__(".boot.text"))) void enablePMCUser(void)
{
    write_cr4(read_cr4() | (1ul << (8)) /* Performance-Monitoring Counter enable. */);
}

__attribute__((__section__(".boot.text"))) bool_t init_ibrs(void)
{
    cpuid_007h_edx_t edx;
    edx.words[0] = x86_cpuid_edx(0x7, 0);
    bool_t support_ibrs = cpuid_007h_edx_get_ibrs_ibpb(edx);
    if ((0 || 0) && !support_ibrs) {
        kprintf("IBRS not supported by CPU\n");
        return false;
    } else if (support_ibrs) {
        /* 'disable' IBRS. For IBRS_BASIC this does nothing, and for STIBP this will cause
         * us to enable STIBP, and we can then forget about it */
        x86_disable_ibrs();
    }
    /* IBRS is also the feature flag for IBPB */
    if (0 && !support_ibrs) {
        kprintf("IBPB not supported by CPU\n");
        return false;
    }
    /* check for enhanced IBRS */
    bool_t enhanced_ibrs = false;
    if (cpuid_007h_edx_get_ia32_arch_cap_msr(edx)) {
        ia32_arch_capabilities_msr_t cap_msr;
        cap_msr.words[0] = x86_rdmsr(0x10A);
        if (ia32_arch_capabilities_msr_get_ibrs_all(cap_msr)) {
            enhanced_ibrs = true;
        }
    }
    if (0 && enhanced_ibrs) {
        kprintf("Kernel configured for basic IBRS, but CPU supports enhanced IBRS. " "Enable enhanced IBRS for improved performance\n")
                                                                 ;
    }
    if (0) {
        if (!enhanced_ibrs) {
            kprintf("Enhanced IBRS not supported by CPU\n");
            return false;
        }
        /* enable IBRS and then we can forget about it */
        x86_enable_ibrs();
    }
    return true;
}
# 1 "/host/kernel/src/arch/x86/machine/registerset.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




void Arch_initContext(user_context_t *context)
{
    Mode_initContext(context);
    context->registers[FS_BASE] = 0;
    context->registers[GS_BASE] = 0;
    context->registers[Error] = 0;
    context->registers[FaultIP] = 0;
    context->registers[NextIP] = 0; /* overwritten by setNextPC() later on */
    context->registers[CS] = ((5 << 3) | 3);
    context->registers[FLAGS] = (1ul << (9)) /* Interrupt enable Flag */ | (1ul << (1)) /* Bits in the FLAGS register that must be high */;
    context->registers[SS] = ((6 << 3) | 3);

    Arch_initFpuContext(context);



}

word_t sanitiseRegister(register_t reg, word_t v, bool_t archInfo)
{
    /* First perform any mode specific sanitization */
    v = Mode_sanitiseRegister(reg, v);
    if (reg == FLAGS) {
        /* Set architecturally defined high and low bits */
        v |= (1ul << (1)) /* Bits in the FLAGS register that must be high */;
        v &= ~((1ul << (3)) | (1ul << (5))) /* Bits in the FLAGS register that must be low */;
        /* require user to have interrupts and no traps */
        v |= (1ul << (9)) /* Interrupt enable Flag */;
        v &= ~(1ul << (8)) /* Trap Flag */;
        /* remove any other bits that shouldn't be set */
        v &= ((1ul << (12))-1ul)/* Only the first 12 bits of the FLAGS are used, rest should be zero */;
    }
    return v;
}
# 1 "/host/kernel/src/arch/x86/model/statedata.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 14 "/host/kernel/src/arch/x86/model/statedata.c"
/* ==== read/write kernel state not preserved across kernel entries ==== */

/* Interrupt currently being handled */
interrupt_t x86KScurInterrupt __attribute__((externally_visible));

interrupt_t x86KSPendingInterrupt;

/* ==== proper read/write kernel state ==== */

x86_arch_global_state_t x86KSGlobalState[1] __attribute__((__aligned__(64))) __attribute__((__section__(".skim.bss")));

/* The top level ASID table */
asid_pool_t *x86KSASIDTable[(1ul << (asidHighBits))];

/* Current user value of the fs/gs base */
word_t x86KSCurrentFSBase;
word_t x86KSCurrentGSBase;

word_t x86KSGPExceptReturnTo;

/* ==== read-only kernel state (only written during bootstrapping) ==== */

/* Defines a translation of cpu ids from an index of our actual CPUs */
;

/* CPU Cache Line Size */
uint32_t x86KScacheLineSizeBits;

/* A valid initial FPU state, copied to every new thread. */
user_fpu_state_t x86KSnullFpuState __attribute__((__aligned__(64)));

/* Number of IOMMUs (DMA Remapping Hardware Units) */
uint32_t x86KSnumDrhu;
# 61 "/host/kernel/src/arch/x86/model/statedata.c"
uint16_t x86KSconsolePort;


uint16_t x86KSdebugPort;


/* State data tracking what IRQ source is related to each
 * CPU vector */
x86_irq_state_t x86KSIRQState[maxIRQ + 1];

word_t x86KSAllocatedIOPorts[(1ul << (16)) / 64];
# 1 "/host/kernel/src/arch/x86/object/interrupt.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




# 1 "kernel/gen_headers/arch/api/invocation.h" 1

/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 ** SPDX-License-Identifier: GPL-2.0-only
 */

/* This header was generated by kernel/tools/invocation_header_gen.py.
 *
 * To add an invocation call number, edit libsel4/include/interfaces/sel4.xml.
 *
 */
# 11 "/host/kernel/src/arch/x86/object/interrupt.c" 2


# 1 "/host/kernel/include/plat/pc99/plat/machine/pci.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 14 "/host/kernel/src/arch/x86/object/interrupt.c" 2

void Arch_irqStateInit(void)
{
    int i = 0;
    for (i = 0; i <= maxIRQ; i++) {
        if (i == irq_timer



           ) {
            x86KSIRQState[i] = x86_irq_state_irq_reserved_new();
        } else {
            x86KSIRQState[i] = x86_irq_state_irq_free_new();
        }
    }
}

/* for x86, the IRQIssueIRQHandler is only allowed to
 * issue a hander for IRQ 0-15, the isa IRQs.
 * Use getIRQHandlerIOAPIC and getIRQHandlerMSI for
 * the IRQs >= 16. Additionally these IRQs only exist
 * if using the legacy PIC interrupt
 */
exception_t Arch_checkIRQ(word_t irq_w)
{
    if (0 && irq_w >= irq_isa_min && irq_w <= irq_isa_max) {
        return EXCEPTION_NONE;
    }
    if (1) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IRQControl: Illegal operation" ">>" "\033[0m" "\n", 0lu, __func__, 43, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
    } else {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IRQControl: IRQ %ld should be in range %ld - %ld" ">>" "\033[0m" "\n", 0lu, __func__, 46, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), irq_w, (long)irq_isa_min, (long)irq_isa_max); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = irq_isa_min;
        current_syscall_error.rangeErrorMax = irq_isa_max;
    }
    return EXCEPTION_SYSCALL_ERROR;
}

static exception_t Arch_invokeIRQControl(irq_t irq, cte_t *handlerSlot, cte_t *controlSlot, x86_irq_state_t irqState)
{
    updateIRQState(irq, irqState);
    return invokeIRQControl(irq, handlerSlot, controlSlot);
}

static exception_t invokeIssueIRQHandlerIOAPIC(irq_t irq, word_t ioapic, word_t pin, word_t level, word_t polarity,
                                               word_t vector,
                                               cte_t *handlerSlot, cte_t *controlSlot)
{
    x86_irq_state_t irqState = x86_irq_state_irq_ioapic_new(ioapic, pin, level, polarity, 1);
    ioapic_map_pin_to_vector(ioapic, pin, level, polarity, vector);
    return Arch_invokeIRQControl(irq, handlerSlot, controlSlot, irqState);
}

exception_t Arch_decodeIRQControlInvocation(word_t invLabel, word_t length, cte_t *srcSlot, extra_caps_t excaps,
                                            word_t *buffer)
{
    word_t index, depth;
    cte_t *destSlot;
    cap_t cnodeCap;
    lookupSlot_ret_t lu_ret;
    exception_t status;
    irq_t irq;
    word_t vector;

    if (!1) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IRQControl: Illegal operation." ">>" "\033[0m" "\n", 0lu, __func__, 81, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    /* ensure we have a valid invocation before continuing any decoding */
    if (invLabel != X86IRQIssueIRQHandlerIOAPIC && invLabel != X86IRQIssueIRQHandlerMSI) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IRQControl: Illegal operation" ">>" "\033[0m" "\n", 0lu, __func__, 88, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    /* check the common parameters */

    if (length < 7 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IRQControl: Truncated message" ">>" "\033[0m" "\n", 0lu, __func__, 96, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }
    index = getSyscallArg(0, buffer);
    depth = getSyscallArg(1, buffer);
    cnodeCap = excaps.excaprefs[0]->cap;
    irq = getSyscallArg(6, buffer);
    if (irq > irq_user_max - irq_user_min) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IRQControl: Invalid irq %ld should be between 0-%ld" ">>" "\033[0m" "\n", 0lu, __func__, 105, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (long)irq, (long)(irq_user_max - irq_user_min)); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = irq_user_max - irq_user_min;
        return EXCEPTION_SYSCALL_ERROR;
    }
    irq += irq_user_min;

    if (isIRQActive(irq)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IRQControl: IRQ %d is already active." ">>" "\033[0m" "\n", 0lu, __func__, 114, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (int)irq); } while (0);
        current_syscall_error.type = seL4_RevokeFirst;
        return EXCEPTION_SYSCALL_ERROR;
    }

    vector = (word_t)irq + 0x20;

    lu_ret = lookupTargetSlot(cnodeCap, index, depth);
    if (lu_ret.status != EXCEPTION_NONE) {
        return lu_ret.status;
    }

    destSlot = lu_ret.slot;

    status = ensureEmptySlot(destSlot);
    if (status != EXCEPTION_NONE) {
        return status;
    }

    switch (invLabel) {
    case X86IRQIssueIRQHandlerIOAPIC: {
        word_t ioapic = getSyscallArg(2, buffer);
        word_t pin = getSyscallArg(3, buffer);
        word_t level = getSyscallArg(4, buffer);
        word_t polarity = getSyscallArg(5, buffer);

        status = ioapic_decode_map_pin_to_vector(ioapic, pin, level, polarity, vector);
        if (status != EXCEPTION_NONE) {
            return status;
        }

        setThreadState(ksCurThread, ThreadState_Restart);
        return invokeIssueIRQHandlerIOAPIC(irq, ioapic, pin, level, polarity, vector, destSlot, srcSlot);
    }
    break;
    case X86IRQIssueIRQHandlerMSI: {
        word_t pci_bus = getSyscallArg(2, buffer);
        word_t pci_dev = getSyscallArg(3, buffer);
        word_t pci_func = getSyscallArg(4, buffer);
        word_t handle = getSyscallArg(5, buffer);
        x86_irq_state_t irqState;
        /* until we support msi interrupt remaping through vt-d we ignore the
         * vector and trust the user */

        if (pci_bus > 255) {
            current_syscall_error.type = seL4_RangeError;
            current_syscall_error.rangeErrorMin = 0;
            current_syscall_error.rangeErrorMax = 255;
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (pci_dev > 31) {
            current_syscall_error.type = seL4_RangeError;
            current_syscall_error.rangeErrorMin = 0;
            current_syscall_error.rangeErrorMax = 31;
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (pci_func > 7) {
            current_syscall_error.type = seL4_RangeError;
            current_syscall_error.rangeErrorMin = 0;
            current_syscall_error.rangeErrorMax = 7;
            return EXCEPTION_SYSCALL_ERROR;
        }

        irqState = x86_irq_state_irq_msi_new(pci_bus, pci_dev, pci_func, handle);

        setThreadState(ksCurThread, ThreadState_Restart);
        return Arch_invokeIRQControl(irq, destSlot, srcSlot, irqState);
    }
    break;
    default:
        /* the check at the start of this function should guarantee we do not get here */
        _fail("IRQControl: Illegal operation", "/host/kernel/src/arch/x86/object/interrupt.c", 187, __func__);
    }
}
# 1 "/host/kernel/src/arch/x86/object/ioport.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */






# 1 "kernel/gen_headers/arch/api/invocation.h" 1

/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 ** SPDX-License-Identifier: GPL-2.0-only
 */

/* This header was generated by kernel/tools/invocation_header_gen.py.
 *
 * To add an invocation call number, edit libsel4/include/interfaces/sel4.xml.
 *
 */
# 13 "/host/kernel/src/arch/x86/object/ioport.c" 2


static inline void apply_pattern(word_t_may_alias *w, word_t pattern, bool_t set)
{
    if (set) {
        *w |= pattern;
    } else {
        *w &= ~pattern;
    }
}

static inline word_t make_pattern(int start, int end)
{
    // number of bits we want to have set
    int num_bits = end - start;
    // shift down to cut off the bits we don't want, then shift up to put the
    // bits into position
    return (~(word_t)0) >> (64 - num_bits) << start;
}

static exception_t ensurePortOperationAllowed(cap_t cap, uint32_t start_port, uint32_t size)
{
    uint32_t first_allowed = cap_io_port_cap_get_capIOPortFirstPort(cap);
    uint32_t last_allowed = cap_io_port_cap_get_capIOPortLastPort(cap);
    uint32_t end_port = start_port + size - 1;
    if(!(first_allowed <= last_allowed)) _assert_fail("first_allowed <= last_allowed", "/host/kernel/src/arch/x86/object/ioport.c", 38, __FUNCTION__);
    if(!(start_port <= end_port)) _assert_fail("start_port <= end_port", "/host/kernel/src/arch/x86/object/ioport.c", 39, __FUNCTION__);

    if ((start_port < first_allowed) || (end_port > last_allowed)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IOPort: Ports %d--%d fall outside permitted range %d--%d." ">>" "\033[0m" "\n", 0lu, __func__, 44, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (int)start_port, (int)end_port, (int)first_allowed, (int)last_allowed); } while (0)

                                                        ;
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    return EXCEPTION_NONE;
}

void freeIOPortRange(uint16_t first_port, uint16_t last_port)
{
    setIOPortMask(x86KSAllocatedIOPorts, first_port, last_port, false);
}

static bool_t isIOPortRangeFree(uint16_t first_port, uint16_t last_port)
{
    int low_word = first_port >> 6;
    int high_word = last_port >> 6;
    int low_index = first_port & ((1ul << (6))-1ul);
    int high_index = last_port & ((1ul << (6))-1ul);

    // check if we are operating on a partial word
    if (low_word == high_word) {
        if ((x86KSAllocatedIOPorts[low_word] & make_pattern(low_index, high_index + 1)) != 0) {
            return false;
        }
        return true;
    }
    // check the starting word
    if ((x86KSAllocatedIOPorts[low_word] & make_pattern(low_index, 64)) != 0) {
        return false;
    }
    low_word++;
    // check the rest of the whole words
    while (low_word < high_word) {
        if (x86KSAllocatedIOPorts[low_word] != 0) {
            return false;
        }
        low_word++;
    }
    // check any trailing bits
    if ((x86KSAllocatedIOPorts[low_word] & make_pattern(0, high_index + 1)) != 0) {
        return false;
    }
    return true;
}

static exception_t invokeX86PortControl(uint16_t first_port, uint16_t last_port, cte_t *ioportSlot, cte_t *controlSlot)
{
    setIOPortMask(x86KSAllocatedIOPorts, first_port, last_port, true);
    cteInsert(cap_io_port_cap_new(first_port, last_port



                                 ),
              controlSlot, ioportSlot);

    return EXCEPTION_NONE;
}

exception_t decodeX86PortControlInvocation(
    word_t invLabel,
    word_t length,
    cptr_t cptr,
    cte_t *slot,
    cap_t cap,
    extra_caps_t excaps,
    word_t *buffer
)
{
    uint16_t first_port;
    uint16_t last_port;
    word_t index, depth;
    cap_t cnodeCap;
    cte_t *destSlot;
    lookupSlot_ret_t lu_ret;
    exception_t status;

    if (invLabel != X86IOPortControlIssue) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IOPortControl: Unknown operation." ">>" "\033[0m" "\n", 0lu, __func__, 122, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (length < 4 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IOPortControl: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 128, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    first_port = getSyscallArg(0, buffer) & 0xffff;
    last_port = getSyscallArg(1, buffer) & 0xffff;
    index = getSyscallArg(2, buffer);
    depth = getSyscallArg(3, buffer);

    cnodeCap = excaps.excaprefs[0]->cap;

    if (last_port < first_port) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IOPortControl: Last port must be > first port." ">>" "\033[0m" "\n", 0lu, __func__, 141, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (!isIOPortRangeFree(first_port, last_port)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IOPortControl: Some ports in range already in use." ">>" "\033[0m" "\n", 0lu, __func__, 148, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_RevokeFirst;
        return EXCEPTION_SYSCALL_ERROR;
    }

    lu_ret = lookupTargetSlot(cnodeCap, index, depth);
    if (lu_ret.status != EXCEPTION_NONE) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Target slot for new IO Port cap invalid: cap %lu." ">>" "\033[0m" "\n", 0lu, __func__, 155, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), getExtraCPtr(buffer, 0)); } while (0);
        return lu_ret.status;
    }
    destSlot = lu_ret.slot;

    status = ensureEmptySlot(destSlot);
    if (status != EXCEPTION_NONE) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Target slot for new IO Port cap not empty: cap %lu." ">>" "\033[0m" "\n", 0lu, __func__, 162, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), getExtraCPtr(buffer, 0)); } while (0);
        return status;
    }

    setThreadState(ksCurThread, ThreadState_Restart);
    return invokeX86PortControl(first_port, last_port, destSlot, slot);
}

static exception_t invokeX86PortIn(word_t invLabel, uint16_t port, bool_t call)
{
    uint32_t res;
    word_t len;

    switch (invLabel) {
    case X86IOPortIn8:
        res = in8(port);
        break;
    case X86IOPortIn16:
        res = in16(port);
        break;
    case X86IOPortIn32:
        res = in32(port);
        break;
    }

    if (call) {
        setRegister(ksCurThread, badgeRegister, 0);

        if (n_msgRegisters < 1) {
            word_t *ipcBuffer;
            ipcBuffer = lookupIPCBuffer(true, ksCurThread);
            if (ipcBuffer != ((void *)0)) {
                ipcBuffer[1] = res;
                len = 1;
            } else {
                len = 0;
            }
        } else {
            setRegister(ksCurThread, msgRegisters[0], res);
            len = 1;
        }

        setRegister(ksCurThread, msgInfoRegister,
                    wordFromMessageInfo(seL4_MessageInfo_new(0, 0, 0, len)));
    }
    // Prevent handleInvocation from attempting to complete the 'call' with an empty
    // message (via replyFromKernel_success_empty) by forcing the thread state to
    // be running. This prevents our stored message we just created from being
    // overwritten.
    setThreadState(ksCurThread, ThreadState_Running);

    return EXCEPTION_NONE;
}

static exception_t invokeX86PortOut(word_t invLabel, uint16_t port, uint32_t data)
{
    switch (invLabel) {
    case X86IOPortOut8:
        out8(port, data);
        break;
    case X86IOPortOut16:
        out16(port, data);
        break;
    case X86IOPortOut32:
        out32(port, data);
        break;
    }

    return EXCEPTION_NONE;
}

exception_t decodeX86PortInvocation(
    word_t invLabel,
    word_t length,
    cptr_t cptr,
    cte_t *slot,
    cap_t cap,
    extra_caps_t excaps,
    bool_t call,
    word_t *buffer
)
{
    exception_t ret;

    if (invLabel == X86IOPortIn8 || invLabel == X86IOPortIn16 || invLabel == X86IOPortIn32) {
        if (length < 1) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IOPort: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 248, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }
        /* Get the port the user is trying to read from. */
        uint16_t port = getSyscallArg(0, buffer) & 0xffff;
        switch (invLabel) {
        case X86IOPortIn8:
            ret = ensurePortOperationAllowed(cap, port, 1);
            break;
        case X86IOPortIn16:
            ret = ensurePortOperationAllowed(cap, port, 2);
            break;
        case X86IOPortIn32:
            ret = ensurePortOperationAllowed(cap, port, 4);
            break;
        }
        if (ret != EXCEPTION_NONE) {
            return ret;
        }
        setThreadState(ksCurThread, ThreadState_Restart);
        return invokeX86PortIn(invLabel, port, call);
    } else if (invLabel == X86IOPortOut8 || invLabel == X86IOPortOut16 || invLabel == X86IOPortOut32) {
        /* Ensure the incoming message is long enough for the write. */
        if (length < 2) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IOPort Out: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 273, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }
        /* Get the port the user is trying to write to. */
        uint16_t port = getSyscallArg(0, buffer) & 0xffff;
        seL4_Word raw_data = getSyscallArg(1, buffer);
        /* We construct the value for data from raw_data based on the actual size of the port
           operation. This ensures that there is no 'random' user data left over in the value
           passed to invokeX86PortOut. Whilst invokeX86PortOut will ignore any extra data and
           cast down to the correct word size removing the extra here is currently relied upon
           for verification */
        uint32_t data;

        switch (invLabel) {
        case X86IOPortOut8:
            ret = ensurePortOperationAllowed(cap, port, 1);
            data = raw_data & 0xff;
            break;
        case X86IOPortOut16:
            ret = ensurePortOperationAllowed(cap, port, 2);
            data = raw_data & 0xffff;
            break;
        case X86IOPortOut32:
            ret = ensurePortOperationAllowed(cap, port, 4);
            data = raw_data & 0xffffffff;
            break;
        }
        if (ret != EXCEPTION_NONE) {
            return ret;
        }
        setThreadState(ksCurThread, ThreadState_Restart);
        return invokeX86PortOut(invLabel, port, data);
    } else {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IOPort: Unknown operation." ">>" "\033[0m" "\n", 0lu, __func__, 307, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
}

void setIOPortMask(void *ioport_bitmap, uint16_t low, uint16_t high, bool_t set)
{
    //get an aliasing pointer
    word_t_may_alias *bitmap = ioport_bitmap;

    int low_word = low >> 6;
    int high_word = high >> 6;
    int low_index = low & ((1ul << (6))-1ul);
    int high_index = high & ((1ul << (6))-1ul);

    // see if we are just manipulating bits inside a single word. handling this
    // specially makes reasoning easier
    if (low_word == high_word) {
        apply_pattern(bitmap + low_word, make_pattern(low_index, high_index + 1), set);
    } else {
        // operate on the potentially partial first word
        apply_pattern(bitmap + low_word, make_pattern(low_index, 64), set);
        low_word++;
        // iterate over the whole words
        while (low_word < high_word) {
            apply_pattern(bitmap + low_word, ~(word_t)0, set);
            low_word++;
        }
        // apply to any remaining bits
        apply_pattern(bitmap + low_word, make_pattern(0, high_index + 1), set);
    }
}
# 1 "/host/kernel/src/arch/x86/object/iospace.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/arch/x86/object/objecttype.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 23 "/host/kernel/src/arch/x86/object/objecttype.c"
deriveCap_ret_t Arch_deriveCap(cte_t *slot, cap_t cap)
{
    deriveCap_ret_t ret;

    switch (cap_get_capType(cap)) {
    case cap_page_table_cap:
        if (cap_page_table_cap_get_capPTIsMapped(cap)) {
            ret.cap = cap;
            ret.status = EXCEPTION_NONE;
        } else {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Deriving an unmapped PT cap" ">>" "\033[0m" "\n", 0lu, __func__, 33, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            ret.cap = cap_null_cap_new();
            ret.status = EXCEPTION_SYSCALL_ERROR;
        }
        return ret;

    case cap_page_directory_cap:
        if (cap_page_directory_cap_get_capPDIsMapped(cap)) {
            ret.cap = cap;
            ret.status = EXCEPTION_NONE;
        } else {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Deriving a PD cap without an assigned ASID" ">>" "\033[0m" "\n", 0lu, __func__, 45, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            ret.cap = cap_null_cap_new();
            ret.status = EXCEPTION_SYSCALL_ERROR;
        }
        return ret;

    case cap_asid_control_cap:
    case cap_asid_pool_cap:
        ret.cap = cap;
        ret.status = EXCEPTION_NONE;
        return ret;
    case cap_io_port_control_cap:
        ret.status = EXCEPTION_NONE;
        ret.cap = cap_null_cap_new();
        return ret;
    case cap_io_port_cap:
        ret.cap = cap;
        ret.status = EXCEPTION_NONE;
        return ret;
# 136 "/host/kernel/src/arch/x86/object/objecttype.c"
    default:
        return Mode_deriveCap(slot, cap);
    }
}

cap_t __attribute__((__const__)) Arch_updateCapData(bool_t preserve, word_t data, cap_t cap)
{
    /* Avoid a switch statement with just a 'default' case as the C parser does not like this */
# 164 "/host/kernel/src/arch/x86/object/objecttype.c"
    return cap;
}

cap_t __attribute__((__const__)) Arch_maskCapRights(seL4_CapRights_t cap_rights_mask, cap_t cap)
{
    if (cap_get_capType(cap) == cap_frame_cap) {
        vm_rights_t vm_rights;

        vm_rights = vmRightsFromWord(cap_frame_cap_get_capFVMRights(cap));
        vm_rights = maskVMRights(vm_rights, cap_rights_mask);
        return cap_frame_cap_set_capFVMRights(cap, wordFromVMRights(vm_rights));
    } else {
        return cap;
    }
}

finaliseCap_ret_t Arch_finaliseCap(cap_t cap, bool_t final)
{
    finaliseCap_ret_t fc_ret;

    switch (cap_get_capType(cap)) {
    case cap_page_directory_cap:
        if (final && cap_page_directory_cap_get_capPDIsMapped(cap)) {
            unmapPageDirectory(
                cap_page_directory_cap_get_capPDMappedASID(cap),
                cap_page_directory_cap_get_capPDMappedAddress(cap),
                ((pde_t *)(cap_page_directory_cap_get_capPDBasePtr(cap)))
            );
        }
        break;

    case cap_page_table_cap:
        if (final && cap_page_table_cap_get_capPTIsMapped(cap)) {
            unmapPageTable(
                cap_page_table_cap_get_capPTMappedASID(cap),
                cap_page_table_cap_get_capPTMappedAddress(cap),
                ((pte_t *)(cap_page_table_cap_get_capPTBasePtr(cap)))
            );
        }
        break;

    case cap_asid_pool_cap:
        if (final) {
            deleteASIDPool(
                cap_asid_pool_cap_get_capASIDBase(cap),
                ((asid_pool_t*)cap_asid_pool_cap_get_capASIDPool(cap))
            );
        }
        break;
    case cap_asid_control_cap:
    case cap_io_port_control_cap:
        break;
    case cap_io_port_cap:





        if (final) {
            fc_ret.remainder = cap_null_cap_new();
            fc_ret.cleanupInfo = cap;
            return fc_ret;
        }
        break;
# 283 "/host/kernel/src/arch/x86/object/objecttype.c"
    default:
        return Mode_finaliseCap(cap, final);
    }

    fc_ret.remainder = cap_null_cap_new();
    fc_ret.cleanupInfo = cap_null_cap_new();
    return fc_ret;
}

bool_t __attribute__((__const__)) Arch_sameRegionAs(cap_t cap_a, cap_t cap_b)
{
    switch (cap_get_capType(cap_a)) {
    case cap_frame_cap:
        if (cap_get_capType(cap_b) == cap_frame_cap) {
            word_t botA, botB, topA, topB;
            botA = cap_frame_cap_get_capFBasePtr(cap_a);
            botB = cap_frame_cap_get_capFBasePtr(cap_b);
            topA = botA + ((1ul << (pageBitsForSize(cap_frame_cap_get_capFSize(cap_a))))-1ul);
            topB = botB + ((1ul << (pageBitsForSize(cap_frame_cap_get_capFSize(cap_b))))-1ul);
            return ((botA <= botB) && (topA >= topB) && (botB <= topB));
        }
        break;

    case cap_page_table_cap:
        if (cap_get_capType(cap_b) == cap_page_table_cap) {
            return cap_page_table_cap_get_capPTBasePtr(cap_a) ==
                   cap_page_table_cap_get_capPTBasePtr(cap_b);
        }
        break;

    case cap_page_directory_cap:
        if (cap_get_capType(cap_b) == cap_page_directory_cap) {
            return cap_page_directory_cap_get_capPDBasePtr(cap_a) ==
                   cap_page_directory_cap_get_capPDBasePtr(cap_b);
        }
        break;

    case cap_asid_control_cap:
        if (cap_get_capType(cap_b) == cap_asid_control_cap) {
            return true;
        }
        break;

    case cap_asid_pool_cap:
        if (cap_get_capType(cap_b) == cap_asid_pool_cap) {
            return cap_asid_pool_cap_get_capASIDPool(cap_a) ==
                   cap_asid_pool_cap_get_capASIDPool(cap_b);
        }
        break;

    case cap_io_port_control_cap:
        if (cap_get_capType(cap_b) == cap_io_port_control_cap ||
            cap_get_capType(cap_b) == cap_io_port_cap) {
            return true;
        }
        break;

    case cap_io_port_cap:
        if (cap_get_capType(cap_b) == cap_io_port_cap) {
            return cap_io_port_cap_get_capIOPortFirstPort(cap_a) ==
                    cap_io_port_cap_get_capIOPortFirstPort(cap_b) &&
                    cap_io_port_cap_get_capIOPortLastPort(cap_a) ==
                    cap_io_port_cap_get_capIOPortLastPort(cap_b);
        }
        break;
# 403 "/host/kernel/src/arch/x86/object/objecttype.c"
    }

    return Mode_sameRegionAs(cap_a, cap_b);
}

bool_t __attribute__((__const__)) Arch_sameObjectAs(cap_t cap_a, cap_t cap_b)
{
    if (cap_get_capType(cap_a) == cap_io_port_control_cap &&
        cap_get_capType(cap_b) == cap_io_port_cap) {
        return false;
    }
    if (cap_get_capType(cap_a) == cap_frame_cap) {
        if (cap_get_capType(cap_b) == cap_frame_cap) {
            return ((cap_frame_cap_get_capFBasePtr(cap_a) ==
                     cap_frame_cap_get_capFBasePtr(cap_b)) &&
                    (cap_frame_cap_get_capFSize(cap_a) ==
                     cap_frame_cap_get_capFSize(cap_b)) &&
                    ((cap_frame_cap_get_capFIsDevice(cap_a) == 0) ==
                     (cap_frame_cap_get_capFIsDevice(cap_b) == 0)));
        }
    }
    return Arch_sameRegionAs(cap_a, cap_b);
}

word_t Arch_getObjectSize(word_t t)
{
    switch (t) {
    case seL4_X86_4K:
        return pageBitsForSize(X86_SmallPage);
    case seL4_X86_LargePageObject:
        return pageBitsForSize(X86_LargePage);
    case seL4_X86_PageTableObject:
        return 12;
    case seL4_X86_PageDirectoryObject:
        return 12;
    case seL4_X86_PDPTObject:
        return 12;
    case 0xffffff:
        return 12;
# 454 "/host/kernel/src/arch/x86/object/objecttype.c"
    default:
        return Mode_getObjectSize(t);
    }
}

cap_t Arch_createObject(object_t t, void *regionBase, word_t userSize, bool_t deviceMemory)
{
# 498 "/host/kernel/src/arch/x86/object/objecttype.c"
        return Mode_createObject(t, regionBase, userSize, deviceMemory);



}

exception_t Arch_decodeInvocation(
    word_t invLabel,
    word_t length,
    cptr_t cptr,
    cte_t *slot,
    cap_t cap,
    extra_caps_t excaps,
    bool_t call,
    word_t *buffer
)
{
    switch (cap_get_capType(cap)) {
    case cap_asid_control_cap:
    case cap_asid_pool_cap:
        return decodeX86MMUInvocation(invLabel, length, cptr, slot, cap, excaps, buffer);
    case cap_io_port_control_cap:
        return decodeX86PortControlInvocation(invLabel, length, cptr, slot, cap, excaps, buffer);
    case cap_io_port_cap:
        return decodeX86PortInvocation(invLabel, length, cptr, slot, cap, excaps, call, buffer);
# 538 "/host/kernel/src/arch/x86/object/objecttype.c"
    default:
        return Mode_decodeInvocation(invLabel, length, cptr, slot, cap, excaps, buffer);
    }
}

void Arch_prepareThreadDelete(tcb_t *thread)
{
    /* Notify the lazy FPU module about this thread's deletion. */
    fpuThreadDelete(thread);
}

void Arch_postCapDeletion(cap_t cap)
{
    if (cap_get_capType(cap) == cap_io_port_cap) {
        uint16_t first_port = cap_io_port_cap_get_capIOPortFirstPort(cap);
        uint16_t last_port = cap_io_port_cap_get_capIOPortLastPort(cap);

        freeIOPortRange(first_port, last_port);
    }
}
# 1 "/host/kernel/src/arch/x86/object/tcb.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */





# 1 "/host/kernel/include/arch/x86/arch/object/tcb.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 12 "/host/kernel/src/arch/x86/object/tcb.c" 2


word_t __attribute__((__const__)) Arch_decodeTransfer(word_t flags)
{
    return 0;
}

exception_t __attribute__((__const__)) Arch_performTransfer(word_t arch, tcb_t *tcb_src, tcb_t *tcb_dest)
{
    return EXCEPTION_NONE;
}
# 1 "/host/kernel/src/arch/x86/object/vcpu.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/arch/x86/smp/ipi.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/assert.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */






void _fail(
    const char *s,
    const char *file,
    unsigned int line,
    const char *function)
{
    kprintf("seL4 called fail at %s:%u in function %s, saying \"%s\"\n", file, line, function, s)





     ;
    halt();
}

void _assert_fail(
    const char *assertion,
    const char *file,
    unsigned int line,
    const char *function)
{
    kprintf("seL4 failed assertion '%s' at %s:%u in function %s\n", assertion, file, line, function)




           ;
    halt();
}
# 1 "/host/kernel/src/benchmark/benchmark_track.c"
/*
 * Copyright 2016, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/benchmark/benchmark_utilisation.c"
/*
 * Copyright 2016, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/fastpath/fastpath.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */


# 1 "/host/kernel/include/fastpath/fastpath.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       

/* Fastpath cap lookup.  Returns a null_cap on failure. */
static inline cap_t __attribute__((always_inline)) lookup_fp(cap_t cap, cptr_t cptr)
{
    word_t cptr2;
    cte_t *slot;
    word_t guardBits, radixBits, bits;
    word_t radix, capGuard;

    bits = 0;

    if (__builtin_expect(!!(! cap_capType_equals(cap, cap_cnode_cap)), 0)) {
        return cap_null_cap_new();
    }

    do {
        guardBits = cap_cnode_cap_get_capCNodeGuardSize(cap);
        radixBits = cap_cnode_cap_get_capCNodeRadix(cap);
        cptr2 = cptr << bits;

        capGuard = cap_cnode_cap_get_capCNodeGuard(cap);

        /* Check the guard. Depth mismatch check is deferred.
           The 32MinusGuardSize encoding contains an exception
           when the guard is 0, when 32MinusGuardSize will be
           reported as 0 also. In this case we skip the check */
        if (__builtin_expect(!!(guardBits), 1) && __builtin_expect(!!(cptr2 >> ((1 << 6) - guardBits) != capGuard), 0)) {
            return cap_null_cap_new();
        }

        radix = cptr2 << guardBits >> ((1 << 6) - radixBits);
        slot = ((cte_t *)(cap_cnode_cap_get_capCNodePtr(cap))) + radix;

        cap = slot->cap;
        bits += guardBits + radixBits;

    } while (__builtin_expect(!!(bits < (1 << 6) && cap_capType_equals(cap, cap_cnode_cap)), 0));

    if (__builtin_expect(!!(bits > (1 << 6)), 0)) {
        /* Depth mismatch. We've overshot wordBits bits. The lookup we've done is
           safe, but wouldn't be allowed by the slowpath. */
        return cap_null_cap_new();
    }

    return cap;
}
/* make sure the fastpath functions conform with structure_*.bf */
static inline void thread_state_ptr_set_tsType_np(thread_state_t *ts_ptr, word_t tsType)
{
    ts_ptr->words[0] = tsType;
}

static inline void thread_state_ptr_mset_blockingObject_tsType(thread_state_t *ts_ptr,
                                                               word_t ep_ref,
                                                               word_t tsType)
{
    ts_ptr->words[0] = ep_ref | tsType;
}


static inline void cap_reply_cap_ptr_new_np(cap_t *cap_ptr, word_t capReplyCanGrant,
                                            word_t capReplyMaster, word_t capTCBPtr)
{

    cap_ptr->words[1] = (word_t)capTCBPtr;
    cap_ptr->words[0] = (capReplyMaster) | (capReplyCanGrant << 1) |
                        ((word_t)cap_reply_cap << 59);




}


static inline void endpoint_ptr_mset_epQueue_tail_state(endpoint_t *ep_ptr, word_t epQueue_tail,
                                                        word_t state)
{
    ep_ptr->words[0] = epQueue_tail | state;
}

static inline void endpoint_ptr_set_epQueue_head_np(endpoint_t *ep_ptr, word_t epQueue_head)
{
    ep_ptr->words[1] = epQueue_head;
}
# 9 "/host/kernel/src/fastpath/fastpath.c" 2
# 24 "/host/kernel/src/fastpath/fastpath.c"
void __attribute__((__noreturn__)) fastpath_call(word_t cptr, word_t msgInfo)
{
    seL4_MessageInfo_t info;
    cap_t ep_cap;
    endpoint_t *ep_ptr;
    word_t length;
    tcb_t *dest;
    word_t badge;
    cap_t newVTable;
    vspace_root_t *cap_pd;
    pde_t stored_hw_asid;
    word_t fault_type;
    dom_t dom;

    /* Get message info, length, and fault type. */
    info = messageInfoFromWord_raw(msgInfo);
    length = seL4_MessageInfo_get_length(info);
    fault_type = seL4_Fault_get_seL4_FaultType(ksCurThread->tcbFault);

    /* Check there's no extra caps, the length is ok and there's no
     * saved fault. */
    if (__builtin_expect(!!(fastpath_mi_check(msgInfo) || fault_type != seL4_Fault_NullFault), 0)
                                                    ) {
        slowpath(SysCall);
    }

    /* Lookup the cap */
    ep_cap = lookup_fp((((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbCTable))->cap, cptr);

    /* Check it's an endpoint */
    if (__builtin_expect(!!(!cap_capType_equals(ep_cap, cap_endpoint_cap) || !cap_endpoint_cap_get_capCanSend(ep_cap)), 0)
                                                          ) {
        slowpath(SysCall);
    }

    /* Get the endpoint address */
    ep_ptr = ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(ep_cap)));

    /* Get the destination thread, which is only going to be valid
     * if the endpoint is valid. */
    dest = ((tcb_t *)(endpoint_ptr_get_epQueue_head(ep_ptr)));

    /* Check that there's a thread waiting to receive */
    if (__builtin_expect(!!(endpoint_ptr_get_state(ep_ptr) != EPState_Recv), 0)) {
        slowpath(SysCall);
    }

    /* ensure we are not single stepping the destination in ia32 */






    /* Get destination thread.*/
    newVTable = (((cte_t *)((word_t)(dest)&~((1ul << (11))-1ul)))+(tcbVTable))->cap;

    /* Get vspace root. */
    cap_pd = cap_vtable_cap_get_vspace_root_fp(newVTable);

    /* Ensure that the destination has a valid VTable. */
    if (__builtin_expect(!!(! isValidVTableRoot_fp(newVTable)), 0)) {
        slowpath(SysCall);
    }







    /* borrow the stored_hw_asid for PCID */
    stored_hw_asid.words[0] = cap_pml4_cap_get_capPML4MappedASID_fp(newVTable);
# 112 "/host/kernel/src/fastpath/fastpath.c"
    /* let gcc optimise this out for 1 domain */
    dom = maxDom ? ksCurDomain : 0;
    /* ensure only the idle thread or lower prio threads are present in the scheduler */
    if (__builtin_expect(!!(dest->tcbPriority < ksCurThread->tcbPriority && !isHighestPrio(dom, dest->tcbPriority)), 0)
                                                        ) {
        slowpath(SysCall);
    }

    /* Ensure that the endpoint has has grant or grant-reply rights so that we can
     * create the reply cap */
    if (__builtin_expect(!!(!cap_endpoint_cap_get_capCanGrant(ep_cap) && !cap_endpoint_cap_get_capCanGrantReply(ep_cap)), 0)
                                                                ) {
        slowpath(SysCall);
    }







    /* Ensure the original caller is in the current domain and can be scheduled directly. */
    if (__builtin_expect(!!(dest->tcbDomain != ksCurDomain && maxDom), 0)) {
        slowpath(SysCall);
    }
# 156 "/host/kernel/src/fastpath/fastpath.c"
    /*
     * --- POINT OF NO RETURN ---
     *
     * At this stage, we have committed to performing the IPC.
     */





    /* Dequeue the destination. */
    endpoint_ptr_set_epQueue_head_np(ep_ptr, ((word_t)(dest->tcbEPNext)));
    if (__builtin_expect(!!(dest->tcbEPNext), 0)) {
        dest->tcbEPNext->tcbEPPrev = ((void *)0);
    } else {
        endpoint_ptr_mset_epQueue_tail_state(ep_ptr, 0, EPState_Idle);
    }

    badge = cap_endpoint_cap_get_capEPBadge(ep_cap);

    /* Unlink dest <-> reply, link src (cur thread) <-> reply */
    thread_state_ptr_set_tsType_np(&ksCurThread->tcbState,
                                   ThreadState_BlockedOnReply);
# 197 "/host/kernel/src/fastpath/fastpath.c"
    /* Get sender reply slot */
    cte_t *replySlot = (((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbReply));

    /* Get dest caller slot */
    cte_t *callerSlot = (((cte_t *)((word_t)(dest)&~((1ul << (11))-1ul)))+(tcbCaller));

    /* Insert reply cap */
    word_t replyCanGrant = thread_state_ptr_get_blockingIPCCanGrant(&dest->tcbState);;
    cap_reply_cap_ptr_new_np(&callerSlot->cap, replyCanGrant, 0,
                             ((word_t)(ksCurThread)));
    mdb_node_ptr_set_mdbPrev_np(&callerSlot->cteMDBNode, ((word_t)(replySlot)));
    mdb_node_ptr_mset_mdbNext_mdbRevocable_mdbFirstBadged(
        &replySlot->cteMDBNode, ((word_t)(callerSlot)), 1, 1);


    fastpath_copy_mrs(length, ksCurThread, dest);

    /* Dest thread is set Running, but not queued. */
    thread_state_ptr_set_tsType_np(&dest->tcbState,
                                   ThreadState_Running);
    switchToThread_fp(dest, cap_pd, stored_hw_asid);

    msgInfo = wordFromMessageInfo(seL4_MessageInfo_set_capsUnwrapped(info, 0));

    fastpath_restore(badge, msgInfo, ksCurThread);
}
# 233 "/host/kernel/src/fastpath/fastpath.c"
void __attribute__((__noreturn__)) fastpath_reply_recv(word_t cptr, word_t msgInfo)

{
    seL4_MessageInfo_t info;
    cap_t ep_cap;
    endpoint_t *ep_ptr;
    word_t length;
    tcb_t *caller;
    word_t badge;
    tcb_t *endpointTail;
    word_t fault_type;

    cap_t newVTable;
    vspace_root_t *cap_pd;
    pde_t stored_hw_asid;
    dom_t dom;

    /* Get message info and length */
    info = messageInfoFromWord_raw(msgInfo);
    length = seL4_MessageInfo_get_length(info);
    fault_type = seL4_Fault_get_seL4_FaultType(ksCurThread->tcbFault);

    /* Check there's no extra caps, the length is ok and there's no
     * saved fault. */
    if (__builtin_expect(!!(fastpath_mi_check(msgInfo) || fault_type != seL4_Fault_NullFault), 0)
                                                    ) {
        slowpath(SysReplyRecv);
    }

    /* Lookup the cap */
    ep_cap = lookup_fp((((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbCTable))->cap,
                       cptr);

    /* Check it's an endpoint */
    if (__builtin_expect(!!(!cap_capType_equals(ep_cap, cap_endpoint_cap) || !cap_endpoint_cap_get_capCanReceive(ep_cap)), 0)
                                                             ) {
        slowpath(SysReplyRecv);
    }
# 282 "/host/kernel/src/fastpath/fastpath.c"
    /* Check there is nothing waiting on the notification */
    if (__builtin_expect(!!(ksCurThread->tcbBoundNotification && notification_ptr_get_state(ksCurThread->tcbBoundNotification) == NtfnState_Active), 0)
                                                                                                               ) {
        slowpath(SysReplyRecv);
    }

    /* Get the endpoint address */
    ep_ptr = ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(ep_cap)));

    /* Check that there's not a thread waiting to send */
    if (__builtin_expect(!!(endpoint_ptr_get_state(ep_ptr) == EPState_Send), 0)) {
        slowpath(SysReplyRecv);
    }
# 310 "/host/kernel/src/fastpath/fastpath.c"
    /* Only reply if the reply cap is valid. */
    cte_t *callerSlot = (((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbCaller));
    cap_t callerCap = callerSlot->cap;
    if (__builtin_expect(!!(!fastpath_reply_cap_check(callerCap)), 0)) {
        slowpath(SysReplyRecv);
    }

    /* Determine who the caller is. */
    caller = ((tcb_t *)(cap_reply_cap_get_capTCBPtr(callerCap)));


    /* ensure we are not single stepping the caller in ia32 */






    /* Check that the caller has not faulted, in which case a fault
       reply is generated instead. */
    fault_type = seL4_Fault_get_seL4_FaultType(caller->tcbFault);
    if (__builtin_expect(!!(fault_type != seL4_Fault_NullFault), 0)) {
        slowpath(SysReplyRecv);
    }

    /* Get destination thread.*/
    newVTable = (((cte_t *)((word_t)(caller)&~((1ul << (11))-1ul)))+(tcbVTable))->cap;

    /* Get vspace root. */
    cap_pd = cap_vtable_cap_get_vspace_root_fp(newVTable);

    /* Ensure that the destination has a valid MMU. */
    if (__builtin_expect(!!(! isValidVTableRoot_fp(newVTable)), 0)) {
        slowpath(SysReplyRecv);
    }







    stored_hw_asid.words[0] = cap_pml4_cap_get_capPML4MappedASID(newVTable);
# 366 "/host/kernel/src/fastpath/fastpath.c"
    /* Ensure the original caller can be scheduled directly. */
    dom = maxDom ? ksCurDomain : 0;
    if (__builtin_expect(!!(!isHighestPrio(dom, caller->tcbPriority)), 0)) {
        slowpath(SysReplyRecv);
    }
# 379 "/host/kernel/src/fastpath/fastpath.c"
    /* Ensure the original caller is in the current domain and can be scheduled directly. */
    if (__builtin_expect(!!(caller->tcbDomain != ksCurDomain && maxDom), 0)) {
        slowpath(SysReplyRecv);
    }
# 402 "/host/kernel/src/fastpath/fastpath.c"
    /*
     * --- POINT OF NO RETURN ---
     *
     * At this stage, we have committed to performing the IPC.
     */





    /* Set thread state to BlockedOnReceive */
    thread_state_ptr_mset_blockingObject_tsType(
        &ksCurThread->tcbState, (word_t)ep_ptr, ThreadState_BlockedOnReceive);







    thread_state_ptr_set_blockingIPCCanGrant(&ksCurThread->tcbState,
                                             cap_endpoint_cap_get_capCanGrant(ep_cap));;


    /* Place the thread in the endpoint queue */
    endpointTail = endpoint_ptr_get_epQueue_tail_fp(ep_ptr);
    if (__builtin_expect(!!(!endpointTail), 1)) {
        ksCurThread->tcbEPPrev = ((void *)0);
        ksCurThread->tcbEPNext = ((void *)0);

        /* Set head/tail of queue and endpoint state. */
        endpoint_ptr_set_epQueue_head_np(ep_ptr, ((word_t)(ksCurThread)));
        endpoint_ptr_mset_epQueue_tail_state(ep_ptr, ((word_t)(ksCurThread)),
                                             EPState_Recv);
    } else {






        /* Append current thread onto the queue. */
        endpointTail->tcbEPNext = ksCurThread;
        ksCurThread->tcbEPPrev = endpointTail;
        ksCurThread->tcbEPNext = ((void *)0);

        /* Update tail of queue. */
        endpoint_ptr_mset_epQueue_tail_state(ep_ptr, ((word_t)(ksCurThread)),
                                             EPState_Recv);

    }
# 471 "/host/kernel/src/fastpath/fastpath.c"
    /* Delete the reply cap. */
    mdb_node_ptr_mset_mdbNext_mdbRevocable_mdbFirstBadged(
        &((cte_t *)(mdb_node_get_mdbPrev(callerSlot->cteMDBNode)))->cteMDBNode,
        0, 1, 1);
    callerSlot->cap = cap_null_cap_new();
    callerSlot->cteMDBNode = mdb_node_new(0, false, false, 0);


    /* I know there's no fault, so straight to the transfer. */

    /* Replies don't have a badge. */
    badge = 0;

    fastpath_copy_mrs(length, ksCurThread, caller);

    /* Dest thread is set Running, but not queued. */
    thread_state_ptr_set_tsType_np(&caller->tcbState,
                                   ThreadState_Running);
    switchToThread_fp(caller, cap_pd, stored_hw_asid);

    msgInfo = wordFromMessageInfo(seL4_MessageInfo_set_capsUnwrapped(info, 0));

    fastpath_restore(badge, msgInfo, ksCurThread);
}
# 1 "/host/kernel/src/inlines.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




lookup_fault_t current_lookup_fault;
seL4_Fault_t current_fault;
syscall_error_t current_syscall_error;
# 1 "/host/kernel/src/kernel/boot.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 20 "/host/kernel/src/kernel/boot.c"
/* (node-local) state accessed only during bootstrapping */
ndks_boot_t ndks_boot __attribute__((__section__(".boot.data")));

rootserver_mem_t rootserver __attribute__((__section__(".boot.data")));
static region_t rootserver_mem __attribute__((__section__(".boot.data")));

__attribute__((__section__(".boot.text"))) static void merge_regions(void)
{
    /* Walk through reserved regions and see if any can be merged */
    for (word_t i = 1; i < ndks_boot.resv_count;) {
        if (ndks_boot.reserved[i - 1].end == ndks_boot.reserved[i].start) {
            /* extend earlier region */
            ndks_boot.reserved[i - 1].end = ndks_boot.reserved[i].end;
            /* move everything else down */
            for (word_t j = i + 1; j < ndks_boot.resv_count; j++) {
                ndks_boot.reserved[j - 1] = ndks_boot.reserved[j];
            }

            ndks_boot.resv_count--;
            /* don't increment i in case there are multiple adjacent regions */
        } else {
            i++;
        }
    }
}

__attribute__((__section__(".boot.text"))) bool_t reserve_region(p_region_t reg)
{
    word_t i;
    if(!(reg.start <= reg.end)) _assert_fail("reg.start <= reg.end", "/host/kernel/src/kernel/boot.c", 49, __FUNCTION__);
    if (reg.start == reg.end) {
        return true;
    }

    /* keep the regions in order */
    for (i = 0; i < ndks_boot.resv_count; i++) {
        /* Try and merge the region to an existing one, if possible */
        if (ndks_boot.reserved[i].start == reg.end) {
            ndks_boot.reserved[i].start = reg.start;
            merge_regions();
            return true;
        }
        if (ndks_boot.reserved[i].end == reg.start) {
            ndks_boot.reserved[i].end = reg.end;
            merge_regions();
            return true;
        }
        /* Otherwise figure out where it should go. */
        if (ndks_boot.reserved[i].start > reg.end) {
            /* move regions down, making sure there's enough room */
            if (ndks_boot.resv_count + 1 >= (16 + 1 + ((-((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1)) >> 12) + 2)) {
                kprintf("Can't mark region 0x%lx-0x%lx as reserved, try increasing MAX_NUM_RESV_REG (currently %d)\n", reg.start, reg.end, (int)(16 + 1 + ((-((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1)) >> 12) + 2))
                                                                 ;
                return false;
            }
            for (word_t j = ndks_boot.resv_count; j > i; j--) {
                ndks_boot.reserved[j] = ndks_boot.reserved[j - 1];
            }
            /* insert the new region */
            ndks_boot.reserved[i] = reg;
            ndks_boot.resv_count++;
            return true;
        }
    }

    if (i + 1 == (16 + 1 + ((-((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1)) >> 12) + 2)) {
        kprintf("Can't mark region 0x%lx-0x%lx as reserved, try increasing MAX_NUM_RESV_REG (currently %d)\n", reg.start, reg.end, (int)(16 + 1 + ((-((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1)) >> 12) + 2))
                                                         ;
        return false;
    }

    ndks_boot.reserved[i] = reg;
    ndks_boot.resv_count++;

    return true;
}

__attribute__((__section__(".boot.text"))) bool_t insert_region(region_t reg)
{
    word_t i;

    if(!(reg.start <= reg.end)) _assert_fail("reg.start <= reg.end", "/host/kernel/src/kernel/boot.c", 101, __FUNCTION__);
    if (is_reg_empty(reg)) {
        return true;
    }
    for (i = 0; i < 16; i++) {
        if (is_reg_empty(ndks_boot.freemem[i])) {
            reserve_region(pptr_to_paddr_reg(reg));
            ndks_boot.freemem[i] = reg;
            return true;
        }
    }
# 122 "/host/kernel/src/kernel/boot.c"
    kprintf("Dropping memory region 0x%lx-0x%lx, try increasing MAX_NUM_FREEMEM_REG (currently %d)\n", reg.start, reg.end, (int)16)
                                                        ;

    return false;
}

__attribute__((__section__(".boot.text"))) static pptr_t alloc_rootserver_obj(word_t size_bits, word_t n)
{
    pptr_t allocated = rootserver_mem.start;
    /* allocated memory must be aligned */
    if(!(allocated % (1ul << (size_bits)) == 0)) _assert_fail("allocated % BIT(size_bits) == 0", "/host/kernel/src/kernel/boot.c", 132, __FUNCTION__);
    rootserver_mem.start += (n * (1ul << (size_bits)));
    /* we must not have run out of memory */
    if(!(rootserver_mem.start <= rootserver_mem.end)) _assert_fail("rootserver_mem.start <= rootserver_mem.end", "/host/kernel/src/kernel/boot.c", 135, __FUNCTION__);
    memzero((void *) allocated, n * (1ul << (size_bits)));
    return allocated;
}

__attribute__((__section__(".boot.text"))) static word_t rootserver_max_size_bits(word_t extra_bi_size_bits)
{
    word_t cnode_size_bits = 16 + 5;
    word_t max = (((cnode_size_bits)>(12))?(cnode_size_bits):(12));
    return (((max)>(extra_bi_size_bits))?(max):(extra_bi_size_bits));
}

__attribute__((__section__(".boot.text"))) static word_t calculate_rootserver_size(v_region_t v_reg, word_t extra_bi_size_bits)
{
    /* work out how much memory we need for root server objects */
    word_t size = (1ul << (16 + 5));
    size += (1ul << (11)); // root thread tcb
    size += 2 * (1ul << (12)); // boot info + ipc buf
    size += (1ul << (12));
    size += extra_bi_size_bits > 0 ? (1ul << (extra_bi_size_bits)) : 0;
    size += (1ul << (12)); // root vspace



    /* for all archs, seL4_PageTable Bits is the size of all non top-level paging structures */
    return size + arch_get_n_paging(v_reg) * (1ul << (12));
}

__attribute__((__section__(".boot.text"))) static void maybe_alloc_extra_bi(word_t cmp_size_bits, word_t extra_bi_size_bits)
{
    if (extra_bi_size_bits >= cmp_size_bits && rootserver.extra_bi == 0) {
        rootserver.extra_bi = alloc_rootserver_obj(extra_bi_size_bits, 1);
    }
}

__attribute__((__section__(".boot.text"))) void create_rootserver_objects(pptr_t start, v_region_t v_reg, word_t extra_bi_size_bits)
{
    /* the largest object the PD, the root cnode, or the extra boot info */
    word_t cnode_size_bits = 16 + 5;
    word_t max = rootserver_max_size_bits(extra_bi_size_bits);

    word_t size = calculate_rootserver_size(v_reg, extra_bi_size_bits);
    rootserver_mem.start = start;
    rootserver_mem.end = start + size;

    maybe_alloc_extra_bi(max, extra_bi_size_bits);

    /* the root cnode is at least 4k, so it could be larger or smaller than a pd. */

    rootserver.cnode = alloc_rootserver_obj(cnode_size_bits, 1);
    maybe_alloc_extra_bi(12, extra_bi_size_bits);
    rootserver.vspace = alloc_rootserver_obj(12, 1);






    /* at this point we are up to creating 4k objects - which is the min size of
     * extra_bi so this is the last chance to allocate it */
    maybe_alloc_extra_bi(12, extra_bi_size_bits);
    rootserver.asid_pool = alloc_rootserver_obj(12, 1);
    rootserver.ipc_buf = alloc_rootserver_obj(12, 1);
    rootserver.boot_info = alloc_rootserver_obj(12, 1);

    /* TCBs on aarch32 can be larger than page tables in certain configs */




    /* paging structures are 4k on every arch except aarch32 (1k) */
    word_t n = arch_get_n_paging(v_reg);
    rootserver.paging.start = alloc_rootserver_obj(12, n);
    rootserver.paging.end = rootserver.paging.start + n * (1ul << (12));

    /* for most archs, TCBs are smaller than page tables */

    rootserver.tcb = alloc_rootserver_obj(11, 1);





    /* we should have allocated all our memory */
    if(!(rootserver_mem.start == rootserver_mem.end)) _assert_fail("rootserver_mem.start == rootserver_mem.end", "/host/kernel/src/kernel/boot.c", 219, __FUNCTION__);
}

__attribute__((__section__(".boot.text"))) void write_slot(slot_ptr_t slot_ptr, cap_t cap)
{
    slot_ptr->cap = cap;

    slot_ptr->cteMDBNode = mdb_node_new(0, false, false, 0);
    mdb_node_ptr_set_mdbRevocable(&slot_ptr->cteMDBNode, true);
    mdb_node_ptr_set_mdbFirstBadged(&slot_ptr->cteMDBNode, true);
}

/* Our root CNode needs to be able to fit all the initial caps and not
 * cover all of memory.
 */
typedef int __assert_failed_root_cnode_size_valid[(16 < 32 - 5 && (1ul << (16)) >= seL4_NumInitialCaps && (1ul << (16)) >= (12 - 5)) ? 1 : -1];




__attribute__((__section__(".boot.text"))) cap_t
create_root_cnode(void)
{
    /* write the number of root CNode slots to global state */
    ndks_boot.slot_pos_max = (1ul << (16));

    cap_t cap =
        cap_cnode_cap_new(
            16, /* radix      */
            (1 << 6) - 16, /* guard size */
            0, /* guard      */
            rootserver.cnode /* pptr       */
        );

    /* write the root CNode cap into the root CNode */
    write_slot((((slot_ptr_t)(rootserver.cnode)) + (seL4_CapInitThreadCNode)), cap);

    return cap;
}

/* Check domain scheduler assumptions. */
typedef int __assert_failed_num_domains_valid[(1 >= 1 && 1 <= 256) ? 1 : -1];

typedef int __assert_failed_num_priorities_valid[(256 >= 1 && 256 <= 256) ? 1 : -1];


__attribute__((__section__(".boot.text"))) void
create_domain_cap(cap_t root_cnode_cap)
{
    /* Check domain scheduler assumptions. */
    if(!(ksDomScheduleLength > 0)) _assert_fail("ksDomScheduleLength > 0", "/host/kernel/src/kernel/boot.c", 269, __FUNCTION__);
    for (word_t i = 0; i < ksDomScheduleLength; i++) {
        if(!(ksDomSchedule[i].domain < 1)) _assert_fail("ksDomSchedule[i].domain < CONFIG_NUM_DOMAINS", "/host/kernel/src/kernel/boot.c", 271, __FUNCTION__);
        if(!(ksDomSchedule[i].length > 0)) _assert_fail("ksDomSchedule[i].length > 0", "/host/kernel/src/kernel/boot.c", 272, __FUNCTION__);
    }

    cap_t cap = cap_domain_cap_new();
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapDomain)), cap);
}


__attribute__((__section__(".boot.text"))) cap_t create_ipcbuf_frame_cap(cap_t root_cnode_cap, cap_t pd_cap, vptr_t vptr)
{
    clearMemory((void *)rootserver.ipc_buf, 12);

    /* create a cap of it and write it into the root CNode */
    cap_t cap = create_mapped_it_frame_cap(pd_cap, rootserver.ipc_buf, vptr, 1 /* initial thread's ASID */, false, false);
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadIPCBuffer)), cap);

    return cap;
}

__attribute__((__section__(".boot.text"))) void create_bi_frame_cap(cap_t root_cnode_cap, cap_t pd_cap, vptr_t vptr)
{
    /* create a cap of it and write it into the root CNode */
    cap_t cap = create_mapped_it_frame_cap(pd_cap, rootserver.boot_info, vptr, 1 /* initial thread's ASID */, false, false);
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapBootInfoFrame)), cap);
}

__attribute__((__section__(".boot.text"))) word_t calculate_extra_bi_size_bits(word_t extra_size)
{
    if (extra_size == 0) {
        return 0;
    }

    word_t clzl_ret = clzl((((((extra_size) - 1ul) >> (12)) + 1ul) << (12)));
    word_t msb = 64 - 1 - clzl_ret;
    /* If region is bigger than a page, make sure we overallocate rather than underallocate */
    if (extra_size > (1ul << (msb))) {
        msb++;
    }
    return msb;
}

__attribute__((__section__(".boot.text"))) void populate_bi_frame(node_id_t node_id, word_t num_nodes, vptr_t ipcbuf_vptr,
                                 word_t extra_bi_size)
{
    clearMemory((void *) rootserver.boot_info, 12);
    if (extra_bi_size) {
        clearMemory((void *) rootserver.extra_bi, calculate_extra_bi_size_bits(extra_bi_size));
    }

    /* initialise bootinfo-related global state */
    ndks_boot.bi_frame = ((seL4_BootInfo*)(rootserver.boot_info));
    ndks_boot.slot_pos_cur = seL4_NumInitialCaps;
    ((seL4_BootInfo*)(rootserver.boot_info))->nodeID = node_id;
    ((seL4_BootInfo*)(rootserver.boot_info))->numNodes = num_nodes;
    ((seL4_BootInfo*)(rootserver.boot_info))->numIOPTLevels = 0;
    ((seL4_BootInfo*)(rootserver.boot_info))->ipcBuffer = (seL4_IPCBuffer *) ipcbuf_vptr;
    ((seL4_BootInfo*)(rootserver.boot_info))->initThreadCNodeSizeBits = 16;
    ((seL4_BootInfo*)(rootserver.boot_info))->initThreadDomain = ksDomSchedule[ksDomScheduleIdx].domain;
    ((seL4_BootInfo*)(rootserver.boot_info))->extraLen = extra_bi_size;
}

__attribute__((__section__(".boot.text"))) bool_t provide_cap(cap_t root_cnode_cap, cap_t cap)
{
    if (ndks_boot.slot_pos_cur >= ndks_boot.slot_pos_max) {
        kprintf("Kernel init failed: ran out of cap slots\n");
        return false;
    }
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (ndks_boot.slot_pos_cur)), cap);
    ndks_boot.slot_pos_cur++;
    return true;
}

__attribute__((__section__(".boot.text"))) create_frames_of_region_ret_t create_frames_of_region(
    cap_t root_cnode_cap,
    cap_t pd_cap,
    region_t reg,
    bool_t do_map,
    sword_t pv_offset
)
{
    pptr_t f;
    cap_t frame_cap;
    seL4_SlotPos slot_pos_before;
    seL4_SlotPos slot_pos_after;

    slot_pos_before = ndks_boot.slot_pos_cur;

    for (f = reg.start; f < reg.end; f += (1ul << (12))) {
        if (do_map) {
            frame_cap = create_mapped_it_frame_cap(pd_cap, f, addrFromPPtr((void *)(f - pv_offset)), 1 /* initial thread's ASID */, false, true);
        } else {
            frame_cap = create_unmapped_it_frame_cap(f, false);
        }
        if (!provide_cap(root_cnode_cap, frame_cap))
            return (create_frames_of_region_ret_t) {
            (seL4_SlotRegion){ .start = 0, .end = 0 }, false
        };
    }

    slot_pos_after = ndks_boot.slot_pos_cur;

    return (create_frames_of_region_ret_t) {
        (seL4_SlotRegion) { slot_pos_before, slot_pos_after }, true
    };
}

__attribute__((__section__(".boot.text"))) cap_t create_it_asid_pool(cap_t root_cnode_cap)
{
    cap_t ap_cap = cap_asid_pool_cap_new(1 /* initial thread's ASID */ >> asidLowBits, rootserver.asid_pool);
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadASIDPool)), ap_cap);

    /* create ASID control cap */
    write_slot(
        (((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapASIDControl)),
        cap_asid_control_cap_new()
    );

    return ap_cap;
}
# 425 "/host/kernel/src/kernel/boot.c"
__attribute__((__section__(".boot.text"))) bool_t create_idle_thread(void)
{
    pptr_t pptr;




        pptr = (pptr_t) &ksIdleThreadTCB[0];
        ksIdleThread = ((tcb_t *)(pptr + (1ul << ((11 - 1)))));
        configureIdleThread(ksIdleThread);

        setThreadName(ksIdleThread, "idle_thread");

        ;
# 451 "/host/kernel/src/kernel/boot.c"
    return true;
}

__attribute__((__section__(".boot.text"))) tcb_t *create_initial_thread(cap_t root_cnode_cap, cap_t it_pd_cap, vptr_t ui_v_entry, vptr_t bi_frame_vptr,
                                       vptr_t ipcbuf_vptr, cap_t ipcbuf_cap)
{
    tcb_t *tcb = ((tcb_t *)(rootserver.tcb + (1ul << ((11 - 1)))));

    tcb->tcbTimeSlice = 5;


    Arch_initContext(&tcb->tcbArch.tcbContext);

    /* derive a copy of the IPC buffer cap for inserting */
    deriveCap_ret_t dc_ret = deriveCap((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadIPCBuffer)), ipcbuf_cap);
    if (dc_ret.status != EXCEPTION_NONE) {
        kprintf("Failed to derive copy of IPC Buffer\n");
        return ((void *)0);
    }

    /* initialise TCB (corresponds directly to abstract specification) */
    cteInsert(
        root_cnode_cap,
        (((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadCNode)),
        (((slot_ptr_t)(rootserver.tcb)) + (tcbCTable))
    );
    cteInsert(
        it_pd_cap,
        (((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadVSpace)),
        (((slot_ptr_t)(rootserver.tcb)) + (tcbVTable))
    );
    cteInsert(
        dc_ret.cap,
        (((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadIPCBuffer)),
        (((slot_ptr_t)(rootserver.tcb)) + (tcbBuffer))
    );
    tcb->tcbIPCBuffer = ipcbuf_vptr;

    setRegister(tcb, capRegister, bi_frame_vptr);
    setNextPC(tcb, ui_v_entry);

    /* initialise TCB */






    tcb->tcbPriority = seL4_MaxPrio;
    tcb->tcbMCP = seL4_MaxPrio;
    tcb->tcbDomain = ksDomSchedule[ksDomScheduleIdx].domain;

    setupReplyMaster(tcb);

    setThreadState(tcb, ThreadState_Running);

    ksCurDomain = ksDomSchedule[ksDomScheduleIdx].domain;



    ksDomainTime = ksDomSchedule[ksDomScheduleIdx].length;

    if(!(ksCurDomain < 1 && ksDomainTime > 0)) _assert_fail("ksCurDomain < CONFIG_NUM_DOMAINS && ksDomainTime > 0", "/host/kernel/src/kernel/boot.c", 513, __FUNCTION__);


    ;


    /* create initial thread's TCB cap */
    cap_t cap = cap_thread_cap_new(((word_t)(tcb)));
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadTCB)), cap);






    setThreadName(tcb, "rootserver");


    return tcb;
}

__attribute__((__section__(".boot.text"))) void init_core_state(tcb_t *scheduler_action)
{

    ksActiveFPUState = ((void *)0);


    /* add initial threads to the debug queue */
    ksDebugTCBs = ((void *)0);
    if (scheduler_action != ((tcb_t*)0) &&
        scheduler_action != ((tcb_t*) 1)) {
        tcbDebugAppend(scheduler_action);
    }
    tcbDebugAppend(ksIdleThread);

    ksSchedulerAction = scheduler_action;
    ksCurThread = ksIdleThread;







}

__attribute__((__section__(".boot.text"))) static bool_t provide_untyped_cap(
    cap_t root_cnode_cap,
    bool_t device_memory,
    pptr_t pptr,
    word_t size_bits,
    seL4_SlotPos first_untyped_slot
)
{
    bool_t ret;
    cap_t ut_cap;
    word_t i = ndks_boot.slot_pos_cur - first_untyped_slot;
    if (i < 230) {
        ndks_boot.bi_frame->untypedList[i] = (seL4_UntypedDesc) {
            addrFromPPtr((void *)pptr), size_bits, device_memory, {0}
        };
        ut_cap = cap_untyped_cap_new(((1ul << ((size_bits) - 4))),
                                     device_memory, size_bits, pptr);
        ret = provide_cap(root_cnode_cap, ut_cap);
    } else {
        kprintf("Kernel init: Too many untyped regions for boot info\n");
        ret = true;
    }
    return ret;
}

__attribute__((__section__(".boot.text"))) bool_t create_untypeds_for_region(
    cap_t root_cnode_cap,
    bool_t device_memory,
    region_t reg,
    seL4_SlotPos first_untyped_slot
)
{
    word_t align_bits;
    word_t size_bits;

    while (!is_reg_empty(reg)) {
        /* Determine the maximum size of the region */
        size_bits = 64 - 1 - clzl(reg.end - reg.start);

        /* Determine the alignment of the region */
        if (reg.start != 0) {
            align_bits = ctzl(reg.start);
        } else {
            align_bits = size_bits;
        }
        /* Reduce size bits to align if needed */
        if (align_bits < size_bits) {
            size_bits = align_bits;
        }
        if (size_bits > 47) {
            size_bits = 47;
        }

        if (size_bits >= 4) {
            if (!provide_untyped_cap(root_cnode_cap, device_memory, reg.start, size_bits, first_untyped_slot)) {
                return false;
            }
        }
        reg.start += (1ul << (size_bits));
    }
    return true;
}

__attribute__((__section__(".boot.text"))) bool_t create_device_untypeds(cap_t root_cnode_cap, seL4_SlotPos slot_pos_before)
{
    paddr_t start = 0;
    for (word_t i = 0; i < ndks_boot.resv_count; i++) {
        if (start < ndks_boot.reserved[i].start) {
            region_t reg = paddr_to_pptr_reg((p_region_t) {
                start, ndks_boot.reserved[i].start
            });
            if (!create_untypeds_for_region(root_cnode_cap, true, reg, slot_pos_before)) {
                return false;
            }
        }

        start = ndks_boot.reserved[i].end;
    }

    if (start < 140737488355328) {
        region_t reg = paddr_to_pptr_reg((p_region_t) {
            start, 140737488355328
        });
        /*
         * The auto-generated bitfield code will get upset if the
         * end pptr is larger than the maximum pointer size for this architecture.
         */
        if (reg.end > 0xffffffff80000000ul) {
            reg.end = 0xffffffff80000000ul;
        }
        if (!create_untypeds_for_region(root_cnode_cap, true, reg, slot_pos_before)) {
            return false;
        }
    }
    return true;
}

__attribute__((__section__(".boot.text"))) bool_t create_kernel_untypeds(cap_t root_cnode_cap, region_t boot_mem_reuse_reg,
                                        seL4_SlotPos first_untyped_slot)
{
    word_t i;
    region_t reg;

    /* if boot_mem_reuse_reg is not empty, we can create UT objs from boot code/data frames */
    if (!create_untypeds_for_region(root_cnode_cap, false, boot_mem_reuse_reg, first_untyped_slot)) {
        return false;
    }

    /* convert remaining freemem into UT objects and provide the caps */
    for (i = 0; i < 16; i++) {
        reg = ndks_boot.freemem[i];
        ndks_boot.freemem[i] = (region_t){ .start = 0, .end = 0 };
        if (!create_untypeds_for_region(root_cnode_cap, false, reg, first_untyped_slot)) {
            return false;
        }
    }

    return true;
}

__attribute__((__section__(".boot.text"))) void bi_finalise(void)
{
    seL4_SlotPos slot_pos_start = ndks_boot.slot_pos_cur;
    seL4_SlotPos slot_pos_end = ndks_boot.slot_pos_max;
    ndks_boot.bi_frame->empty = (seL4_SlotRegion) {
        slot_pos_start, slot_pos_end
    };
}

static inline pptr_t ceiling_kernel_window(pptr_t p)
{
    /* Adjust address if it exceeds the kernel window
     * Note that we compare physical address in case of overflow.
     */
    if (addrFromPPtr((void *)p) > (0xffffffff80000000ul - (0xffffff8000000000ul - 0x00000000ul))) {
        p = 0xffffffff80000000ul;
    }
    return p;
}

/* we can't delcare arrays on the stack, so this is space for
 * the below function to use. */
static __attribute__((__section__(".boot.data"))) region_t avail_reg[16];
/**
 * Dynamically initialise the available memory on the platform.
 * A region represents an area of memory.
 */
__attribute__((__section__(".boot.text"))) void init_freemem(word_t n_available, const p_region_t *available,
                            word_t n_reserved, region_t *reserved,
                            v_region_t it_v_reg, word_t extra_bi_size_bits)
{
    /* Force ordering and exclusivity of reserved regions */
    for (word_t i = 0; n_reserved > 0 && i < n_reserved - 1; i++) {
        if(!(reserved[i].start <= reserved[i].end)) _assert_fail("reserved[i].start <= reserved[i].end", "/host/kernel/src/kernel/boot.c", 712, __FUNCTION__);
        if(!(reserved[i].end <= reserved[i + 1].start)) _assert_fail("reserved[i].end <= reserved[i + 1].start", "/host/kernel/src/kernel/boot.c", 713, __FUNCTION__);
    }

    /* Force ordering and exclusivity of available regions */
    if(!(n_available > 0)) _assert_fail("n_available > 0", "/host/kernel/src/kernel/boot.c", 717, __FUNCTION__);
    for (word_t i = 0; i < n_available - 1; i++) {
        if(!(available[i].start < available[i].end)) _assert_fail("available[i].start < available[i].end", "/host/kernel/src/kernel/boot.c", 719, __FUNCTION__);
        if(!(available[i].end <= available[i + 1].start)) _assert_fail("available[i].end <= available[i + 1].start", "/host/kernel/src/kernel/boot.c", 720, __FUNCTION__);
    }

    for (word_t i = 0; i < 16; i++) {
        ndks_boot.freemem[i] = (region_t){ .start = 0, .end = 0 };
    }

    /* convert the available regions to pptrs */
    for (word_t i = 0; i < n_available; i++) {
        avail_reg[i] = paddr_to_pptr_reg(available[i]);
        avail_reg[i].end = ceiling_kernel_window(avail_reg[i].end);
        avail_reg[i].start = ceiling_kernel_window(avail_reg[i].start);
    }

    word_t a = 0;
    word_t r = 0;
    /* Now iterate through the available regions, removing any reserved regions. */
    while (a < n_available && r < n_reserved) {
        if (reserved[r].start == reserved[r].end) {
            /* reserved region is empty - skip it */
            r++;
        } else if (avail_reg[a].start >= avail_reg[a].end) {
            /* skip the entire region - it's empty now after trimming */
            a++;
        } else if (reserved[r].end <= avail_reg[a].start) {
            /* the reserved region is below the available region - skip it*/
            reserve_region(pptr_to_paddr_reg(reserved[r]));
            r++;
        } else if (reserved[r].start >= avail_reg[a].end) {
            /* the reserved region is above the available region - take the whole thing */
            insert_region(avail_reg[a]);
            a++;
        } else {
            /* the reserved region overlaps with the available region */
            if (reserved[r].start <= avail_reg[a].start) {
                /* the region overlaps with the start of the available region.
                 * trim start of the available region */
                avail_reg[a].start = (((avail_reg[a].end)<(reserved[r].end))?(avail_reg[a].end):(reserved[r].end));
                reserve_region(pptr_to_paddr_reg(reserved[r]));
                r++;
            } else {
                if(!(reserved[r].start < avail_reg[a].end)) _assert_fail("reserved[r].start < avail_reg[a].end", "/host/kernel/src/kernel/boot.c", 761, __FUNCTION__);
                /* take the first chunk of the available region and move
                 * the start to the end of the reserved region */
                region_t m = avail_reg[a];
                m.end = reserved[r].start;
                insert_region(m);
                if (avail_reg[a].end > reserved[r].end) {
                    avail_reg[a].start = reserved[r].end;
                    reserve_region(pptr_to_paddr_reg(reserved[r]));
                    r++;
                } else {
                    a++;
                }
            }
        }
    }

    for (; r < n_reserved; r++) {
        if (reserved[r].start < reserved[r].end) {
            reserve_region(pptr_to_paddr_reg(reserved[r]));
        }
    }

    /* no more reserved regions - add the rest */
    for (; a < n_available; a++) {
        if (avail_reg[a].start < avail_reg[a].end) {
            insert_region(avail_reg[a]);
        }
    }

    /* now try to fit the root server objects into a region */
    word_t i = 16 - 1;
    if (!is_reg_empty(ndks_boot.freemem[i])) {
        kprintf("Insufficient MAX_NUM_FREEMEM_REG");
        halt();
    }
    /* skip any empty regions */
    for (; is_reg_empty(ndks_boot.freemem[i]) && i >= 0; i--);

    /* try to grab the last available p region to create the root server objects
     * from. If possible, retain any left over memory as an extra p region */
    word_t size = calculate_rootserver_size(it_v_reg, extra_bi_size_bits);
    word_t max = rootserver_max_size_bits(extra_bi_size_bits);
    for (; i >= 0; i--) {
        word_t next = i + 1;
        pptr_t start = (((ndks_boot.freemem[i].end - size) >> (max)) << (max));
        if (start >= ndks_boot.freemem[i].start) {
            create_rootserver_objects(start, it_v_reg, extra_bi_size_bits);
            if (i < 16) {
                ndks_boot.freemem[next].end = ndks_boot.freemem[i].end;
                ndks_boot.freemem[next].start = start + size;
            }
            ndks_boot.freemem[i].end = start;
            break;
        } else if (i < 16) {
            ndks_boot.freemem[next] = ndks_boot.freemem[i];
        }
    }
}
# 1 "/host/kernel/src/kernel/cspace.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 15 "/host/kernel/src/kernel/cspace.c"
lookupCap_ret_t lookupCap(tcb_t *thread, cptr_t cPtr)
{
    lookupSlot_raw_ret_t lu_ret;
    lookupCap_ret_t ret;

    lu_ret = lookupSlot(thread, cPtr);
    if (__builtin_expect(!!(lu_ret.status != EXCEPTION_NONE), 0)) {
        ret.status = lu_ret.status;
        ret.cap = cap_null_cap_new();
        return ret;
    }

    ret.status = EXCEPTION_NONE;
    ret.cap = lu_ret.slot->cap;
    return ret;
}

lookupCapAndSlot_ret_t lookupCapAndSlot(tcb_t *thread, cptr_t cPtr)
{
    lookupSlot_raw_ret_t lu_ret;
    lookupCapAndSlot_ret_t ret;

    lu_ret = lookupSlot(thread, cPtr);
    if (__builtin_expect(!!(lu_ret.status != EXCEPTION_NONE), 0)) {
        ret.status = lu_ret.status;
        ret.slot = ((void *)0);
        ret.cap = cap_null_cap_new();
        return ret;
    }

    ret.status = EXCEPTION_NONE;
    ret.slot = lu_ret.slot;
    ret.cap = lu_ret.slot->cap;
    return ret;
}

lookupSlot_raw_ret_t lookupSlot(tcb_t *thread, cptr_t capptr)
{
    cap_t threadRoot;
    resolveAddressBits_ret_t res_ret;
    lookupSlot_raw_ret_t ret;

    threadRoot = (((cte_t *)((word_t)(thread)&~((1ul << (11))-1ul)))+(tcbCTable))->cap;
    res_ret = resolveAddressBits(threadRoot, capptr, (1 << 6));

    ret.status = res_ret.status;
    ret.slot = res_ret.slot;
    return ret;
}

lookupSlot_ret_t lookupSlotForCNodeOp(bool_t isSource, cap_t root, cptr_t capptr,
                                      word_t depth)
{
    resolveAddressBits_ret_t res_ret;
    lookupSlot_ret_t ret;

    ret.slot = ((void *)0);

    if (__builtin_expect(!!(cap_get_capType(root) != cap_cnode_cap), 0)) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = isSource;
        current_lookup_fault = lookup_fault_invalid_root_new();
        ret.status = EXCEPTION_SYSCALL_ERROR;
        return ret;
    }

    if (__builtin_expect(!!(depth < 1 || depth > (1 << 6)), 0)) {
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 1;
        current_syscall_error.rangeErrorMax = (1 << 6);
        ret.status = EXCEPTION_SYSCALL_ERROR;
        return ret;
    }
    res_ret = resolveAddressBits(root, capptr, depth);
    if (__builtin_expect(!!(res_ret.status != EXCEPTION_NONE), 0)) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = isSource;
        /* current_lookup_fault will have been set by resolveAddressBits */
        ret.status = EXCEPTION_SYSCALL_ERROR;
        return ret;
    }

    if (__builtin_expect(!!(res_ret.bitsRemaining != 0), 0)) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = isSource;
        current_lookup_fault =
            lookup_fault_depth_mismatch_new(0, res_ret.bitsRemaining);
        ret.status = EXCEPTION_SYSCALL_ERROR;
        return ret;
    }

    ret.slot = res_ret.slot;
    ret.status = EXCEPTION_NONE;
    return ret;
}

lookupSlot_ret_t lookupSourceSlot(cap_t root, cptr_t capptr, word_t depth)
{
    return lookupSlotForCNodeOp(true, root, capptr, depth);
}

lookupSlot_ret_t lookupTargetSlot(cap_t root, cptr_t capptr, word_t depth)
{
    return lookupSlotForCNodeOp(false, root, capptr, depth);
}

lookupSlot_ret_t lookupPivotSlot(cap_t root, cptr_t capptr, word_t depth)
{
    return lookupSlotForCNodeOp(true, root, capptr, depth);
}

resolveAddressBits_ret_t resolveAddressBits(cap_t nodeCap, cptr_t capptr, word_t n_bits)
{
    resolveAddressBits_ret_t ret;
    word_t radixBits, guardBits, levelBits, guard;
    word_t capGuard, offset;
    cte_t *slot;

    ret.bitsRemaining = n_bits;
    ret.slot = ((void *)0);

    if (__builtin_expect(!!(cap_get_capType(nodeCap) != cap_cnode_cap), 0)) {
        current_lookup_fault = lookup_fault_invalid_root_new();
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }

    while (1) {
        radixBits = cap_cnode_cap_get_capCNodeRadix(nodeCap);
        guardBits = cap_cnode_cap_get_capCNodeGuardSize(nodeCap);
        levelBits = radixBits + guardBits;

        /* Haskell error: "All CNodes must resolve bits" */
        if(!(levelBits != 0)) _assert_fail("levelBits != 0", "/host/kernel/src/kernel/cspace.c", 148, __FUNCTION__);

        capGuard = cap_cnode_cap_get_capCNodeGuard(nodeCap);

        /* sjw --- the MASK(5) here is to avoid the case where n_bits = 32
           and guardBits = 0, as it violates the C spec to >> by more
           than 31 */

        guard = (capptr >> ((n_bits - guardBits) & ((1ul << (6))-1ul))) & ((1ul << (guardBits))-1ul);
        if (__builtin_expect(!!(guardBits > n_bits || guard != capGuard), 0)) {
            current_lookup_fault =
                lookup_fault_guard_mismatch_new(capGuard, n_bits, guardBits);
            ret.status = EXCEPTION_LOOKUP_FAULT;
            return ret;
        }

        if (__builtin_expect(!!(levelBits > n_bits), 0)) {
            current_lookup_fault =
                lookup_fault_depth_mismatch_new(levelBits, n_bits);
            ret.status = EXCEPTION_LOOKUP_FAULT;
            return ret;
        }

        offset = (capptr >> (n_bits - levelBits)) & ((1ul << (radixBits))-1ul);
        slot = ((cte_t *)(cap_cnode_cap_get_capCNodePtr(nodeCap))) + offset;

        if (__builtin_expect(!!(n_bits <= levelBits), 1)) {
            ret.status = EXCEPTION_NONE;
            ret.slot = slot;
            ret.bitsRemaining = 0;
            return ret;
        }

        /** GHOSTUPD: "(\<acute>levelBits > 0, id)" */

        n_bits -= levelBits;
        nodeCap = slot->cap;

        if (__builtin_expect(!!(cap_get_capType(nodeCap) != cap_cnode_cap), 0)) {
            ret.status = EXCEPTION_NONE;
            ret.slot = slot;
            ret.bitsRemaining = n_bits;
            return ret;
        }
    }

    ret.status = EXCEPTION_NONE;
    return ret;
}
# 1 "/host/kernel/src/kernel/faulthandler.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 53 "/host/kernel/src/kernel/faulthandler.c"
void handleFault(tcb_t *tptr)
{
    exception_t status;
    seL4_Fault_t fault = current_fault;

    status = sendFaultIPC(tptr);
    if (status != EXCEPTION_NONE) {
        handleDoubleFault(tptr, fault);
    }
}

exception_t sendFaultIPC(tcb_t *tptr)
{
    cptr_t handlerCPtr;
    cap_t handlerCap;
    lookupCap_ret_t lu_ret;
    lookup_fault_t original_lookup_fault;

    original_lookup_fault = current_lookup_fault;

    handlerCPtr = tptr->tcbFaultHandler;
    lu_ret = lookupCap(tptr, handlerCPtr);
    if (lu_ret.status != EXCEPTION_NONE) {
        current_fault = seL4_Fault_CapFault_new(handlerCPtr, false);
        return EXCEPTION_FAULT;
    }
    handlerCap = lu_ret.cap;

    if (cap_get_capType(handlerCap) == cap_endpoint_cap &&
        cap_endpoint_cap_get_capCanSend(handlerCap) &&
        (cap_endpoint_cap_get_capCanGrant(handlerCap) ||
         cap_endpoint_cap_get_capCanGrantReply(handlerCap))) {
        tptr->tcbFault = current_fault;
        if (seL4_Fault_get_seL4_FaultType(current_fault) == seL4_Fault_CapFault) {
            tptr->tcbLookupFailure = original_lookup_fault;
        }
        sendIPC(true, true,
                cap_endpoint_cap_get_capEPBadge(handlerCap),
                cap_endpoint_cap_get_capCanGrant(handlerCap), true, tptr,
                ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(handlerCap))));

        return EXCEPTION_NONE;
    } else {
        current_fault = seL4_Fault_CapFault_new(handlerCPtr, false);
        current_lookup_fault = lookup_fault_missing_capability_new(0);

        return EXCEPTION_FAULT;
    }
}



static void print_fault(seL4_Fault_t f)
{
    switch (seL4_Fault_get_seL4_FaultType(f)) {
    case seL4_Fault_NullFault:
        kprintf("null fault");
        break;
    case seL4_Fault_CapFault:
        kprintf("cap fault in %s phase at address %p", seL4_Fault_CapFault_get_inReceivePhase(f) ? "receive" : "send", (void *)seL4_Fault_CapFault_get_address(f))

                                                          ;
        break;
    case seL4_Fault_VMFault:
        kprintf("vm fault on %s at address %p with status %p", seL4_Fault_VMFault_get_instructionFault(f) ? "code" : "data", (void *)seL4_Fault_VMFault_get_address(f), (void *)seL4_Fault_VMFault_get_FSR(f))


                                                     ;
        break;
    case seL4_Fault_UnknownSyscall:
        kprintf("unknown syscall %p", (void *)seL4_Fault_UnknownSyscall_get_syscallNumber(f))
                                                                      ;
        break;
    case seL4_Fault_UserException:
        kprintf("user exception %p code %p", (void *)seL4_Fault_UserException_get_number(f), (void *)seL4_Fault_UserException_get_code(f))

                                                            ;
        break;





    default:
        kprintf("unknown fault");
        break;
    }
}





/* The second fault, ex2, is stored in the global current_fault */
void handleDoubleFault(tcb_t *tptr, seL4_Fault_t ex1)

{





    seL4_Fault_t ex2 = current_fault;
    kprintf("Caught ");
    print_fault(ex2);
    kprintf("\nwhile trying to handle:\n");
    print_fault(ex1);


    kprintf("\nin thread %p \"%s\" ", tptr, ((debug_tcb_t *)(((cte_t *)((word_t)(tptr)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName);


    kprintf("at address %p\n", (void *)getRestartPC(tptr));
    kprintf("With stack:\n");
    Arch_userStackTrace(tptr);


    setThreadState(tptr, ThreadState_Inactive);
}
# 1 "/host/kernel/src/kernel/stack.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */



__attribute__((externally_visible)) __attribute__((__aligned__(16)))
char kernel_stack_alloc[1][(1ul << (12))];
# 1 "/host/kernel/src/kernel/thread.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 24 "/host/kernel/src/kernel/thread.c"
static seL4_MessageInfo_t
transferCaps(seL4_MessageInfo_t info, extra_caps_t caps,
             endpoint_t *endpoint, tcb_t *receiver,
             word_t *receiveBuffer);

__attribute__((__section__(".boot.text"))) void configureIdleThread(tcb_t *tcb)
{
    Arch_configureIdleThread(tcb);
    setThreadState(tcb, ThreadState_IdleThreadState);
}

void activateThread(void)
{







    switch (thread_state_get_tsType(ksCurThread->tcbState)) {
    case ThreadState_Running:



        break;

    case ThreadState_Restart: {
        word_t pc;

        pc = getRestartPC(ksCurThread);
        setNextPC(ksCurThread, pc);
        setThreadState(ksCurThread, ThreadState_Running);
        break;
    }

    case ThreadState_IdleThreadState:
        Arch_activateIdleThread(ksCurThread);
        break;

    default:
        _fail("Current thread is blocked", "/host/kernel/src/kernel/thread.c", 65, __func__);
    }
}

void suspend(tcb_t *target)
{
    cancelIPC(target);
    if (thread_state_get_tsType(target->tcbState) == ThreadState_Running) {
        /* whilst in the running state it is possible that restart pc of a thread is
         * incorrect. As we do not know what state this thread will transition to
         * after we make it inactive we update its restart pc so that the thread next
         * runs at the correct address whether it is restarted or moved directly to
         * running */
        updateRestartPC(target);
    }
    setThreadState(target, ThreadState_Inactive);
    tcbSchedDequeue(target);




}

void restart(tcb_t *target)
{
    if (isStopped(target)) {
        cancelIPC(target);







        setupReplyMaster(target);
        setThreadState(target, ThreadState_Restart);
        tcbSchedEnqueue(target);
        possibleSwitchTo(target);

    }
}

void doIPCTransfer(tcb_t *sender, endpoint_t *endpoint, word_t badge,
                   bool_t grant, tcb_t *receiver)
{
    void *receiveBuffer, *sendBuffer;

    receiveBuffer = lookupIPCBuffer(true, receiver);

    if (__builtin_expect(!!(seL4_Fault_get_seL4_FaultType(sender->tcbFault) == seL4_Fault_NullFault), 1)) {
        sendBuffer = lookupIPCBuffer(false, sender);
        doNormalTransfer(sender, sendBuffer, endpoint, badge, grant,
                         receiver, receiveBuffer);
    } else {
        doFaultTransfer(badge, sender, receiver, receiveBuffer);
    }
}




void doReplyTransfer(tcb_t *sender, tcb_t *receiver, cte_t *slot, bool_t grant)

{
# 141 "/host/kernel/src/kernel/thread.c"
    if(!(thread_state_get_tsType(receiver->tcbState) == ThreadState_BlockedOnReply)) _assert_fail("thread_state_get_tsType(receiver->tcbState) == ThreadState_BlockedOnReply",
                                     "/host/kernel/src/kernel/thread.c"
# 141 "/host/kernel/src/kernel/thread.c"
    ,
                                     142
# 141 "/host/kernel/src/kernel/thread.c"
    , __FUNCTION__)
                                      ;


    word_t fault_type = seL4_Fault_get_seL4_FaultType(receiver->tcbFault);
    if (__builtin_expect(!!(fault_type == seL4_Fault_NullFault), 1)) {
        doIPCTransfer(sender, ((void *)0), 0, grant, receiver);



        /** GHOSTUPD: "(True, gs_set_assn cteDeleteOne_'proc (ucast cap_reply_cap))" */
        cteDeleteOne(slot);
        setThreadState(receiver, ThreadState_Running);
        possibleSwitchTo(receiver);

    } else {

        /** GHOSTUPD: "(True, gs_set_assn cteDeleteOne_'proc (ucast cap_reply_cap))" */
        cteDeleteOne(slot);

        bool_t restart = handleFaultReply(receiver, sender);
        receiver->tcbFault = seL4_Fault_NullFault_new();
        if (restart) {
            setThreadState(receiver, ThreadState_Restart);

            possibleSwitchTo(receiver);

        } else {
            setThreadState(receiver, ThreadState_Inactive);
        }
    }
# 187 "/host/kernel/src/kernel/thread.c"
}

void doNormalTransfer(tcb_t *sender, word_t *sendBuffer, endpoint_t *endpoint,
                      word_t badge, bool_t canGrant, tcb_t *receiver,
                      word_t *receiveBuffer)
{
    word_t msgTransferred;
    seL4_MessageInfo_t tag;
    exception_t status;
    extra_caps_t caps;

    tag = messageInfoFromWord(getRegister(sender, msgInfoRegister));

    if (canGrant) {
        status = lookupExtraCaps(sender, sendBuffer, tag);
        caps = current_extra_caps;
        if (__builtin_expect(!!(status != EXCEPTION_NONE), 0)) {
            caps.excaprefs[0] = ((void *)0);
        }
    } else {
        caps = current_extra_caps;
        caps.excaprefs[0] = ((void *)0);
    }

    msgTransferred = copyMRs(sender, sendBuffer, receiver, receiveBuffer,
                             seL4_MessageInfo_get_length(tag));

    tag = transferCaps(tag, caps, endpoint, receiver, receiveBuffer);

    tag = seL4_MessageInfo_set_length(tag, msgTransferred);
    setRegister(receiver, msgInfoRegister, wordFromMessageInfo(tag));
    setRegister(receiver, badgeRegister, badge);
}

void doFaultTransfer(word_t badge, tcb_t *sender, tcb_t *receiver,
                     word_t *receiverIPCBuffer)
{
    word_t sent;
    seL4_MessageInfo_t msgInfo;

    sent = setMRs_fault(sender, receiver, receiverIPCBuffer);
    msgInfo = seL4_MessageInfo_new(
                  seL4_Fault_get_seL4_FaultType(sender->tcbFault), 0, 0, sent);
    setRegister(receiver, msgInfoRegister, wordFromMessageInfo(msgInfo));
    setRegister(receiver, badgeRegister, badge);
}

/* Like getReceiveSlots, this is specialised for single-cap transfer. */
static seL4_MessageInfo_t transferCaps(seL4_MessageInfo_t info, extra_caps_t caps,
                                       endpoint_t *endpoint, tcb_t *receiver,
                                       word_t *receiveBuffer)
{
    word_t i;
    cte_t *destSlot;

    info = seL4_MessageInfo_set_extraCaps(info, 0);
    info = seL4_MessageInfo_set_capsUnwrapped(info, 0);

    if (__builtin_expect(!!(!caps.excaprefs[0] || !receiveBuffer), 1)) {
        return info;
    }

    destSlot = getReceiveSlots(receiver, receiveBuffer);

    for (i = 0; i < ((1ul<<(seL4_MsgExtraCapBits))-1) && caps.excaprefs[i] != ((void *)0); i++) {
        cte_t *slot = caps.excaprefs[i];
        cap_t cap = slot->cap;

        if (cap_get_capType(cap) == cap_endpoint_cap &&
            ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(cap))) == endpoint) {
            /* If this is a cap to the endpoint on which the message was sent,
             * only transfer the badge, not the cap. */
            setExtraBadge(receiveBuffer,
                          cap_endpoint_cap_get_capEPBadge(cap), i);

            info = seL4_MessageInfo_set_capsUnwrapped(info,
                                                      seL4_MessageInfo_get_capsUnwrapped(info) | (1 << i));

        } else {
            deriveCap_ret_t dc_ret;

            if (!destSlot) {
                break;
            }

            dc_ret = deriveCap(slot, cap);

            if (dc_ret.status != EXCEPTION_NONE) {
                break;
            }
            if (cap_get_capType(dc_ret.cap) == cap_null_cap) {
                break;
            }

            cteInsert(dc_ret.cap, slot, destSlot);

            destSlot = ((void *)0);
        }
    }

    return seL4_MessageInfo_set_extraCaps(info, i);
}

void doNBRecvFailedTransfer(tcb_t *thread)
{
    /* Set the badge register to 0 to indicate there was no message */
    setRegister(thread, badgeRegister, 0);
}

static void nextDomain(void)
{
    ksDomScheduleIdx++;
    if (ksDomScheduleIdx >= ksDomScheduleLength) {
        ksDomScheduleIdx = 0;
    }



    ksWorkUnitsCompleted = 0;
    ksCurDomain = ksDomSchedule[ksDomScheduleIdx].domain;



    ksDomainTime = ksDomSchedule[ksDomScheduleIdx].length;

}
# 335 "/host/kernel/src/kernel/thread.c"
static void scheduleChooseNewThread(void)
{
    if (ksDomainTime == 0) {
        nextDomain();
    }
    chooseThread();
}

void schedule(void)
{




    if (ksSchedulerAction != ((tcb_t*)0)) {
        bool_t was_runnable;
        if (isRunnable(ksCurThread)) {
            was_runnable = true;
            tcbSchedEnqueue(ksCurThread);
        } else {
            was_runnable = false;
        }

        if (ksSchedulerAction == ((tcb_t*) 1)) {
            scheduleChooseNewThread();
        } else {
            tcb_t *candidate = ksSchedulerAction;
            if(!(isRunnable(candidate))) _assert_fail("isSchedulable(candidate)", "/host/kernel/src/kernel/thread.c", 362, __FUNCTION__);
            /* Avoid checking bitmap when ksCurThread is higher prio, to
             * match fast path.
             * Don't look at ksCurThread prio when it's idle, to respect
             * information flow in non-fastpath cases. */
            bool_t fastfail =
                ksCurThread == ksIdleThread
                || (candidate->tcbPriority < ksCurThread->tcbPriority);
            if (fastfail &&
                !isHighestPrio(ksCurDomain, candidate->tcbPriority)) {
                tcbSchedEnqueue(candidate);
                /* we can't, need to reschedule */
                ksSchedulerAction = ((tcb_t*) 1);
                scheduleChooseNewThread();
            } else if (was_runnable && candidate->tcbPriority == ksCurThread->tcbPriority) {
                /* We append the candidate at the end of the scheduling queue, that way the
                 * current thread, that was enqueued at the start of the scheduling queue
                 * will get picked during chooseNewThread */
                tcbSchedAppend(candidate);
                ksSchedulerAction = ((tcb_t*) 1);
                scheduleChooseNewThread();
            } else {
                if(!(candidate != ksCurThread)) _assert_fail("candidate != NODE_STATE(ksCurThread)", "/host/kernel/src/kernel/thread.c", 384, __FUNCTION__);
                switchToThread(candidate);
            }
        }
    }
    ksSchedulerAction = ((tcb_t*)0);
# 403 "/host/kernel/src/kernel/thread.c"
}

void chooseThread(void)
{
    word_t prio;
    word_t dom;
    tcb_t *thread;

    if (1 > 1) {
        dom = ksCurDomain;
    } else {
        dom = 0;
    }

    if (__builtin_expect(!!(ksReadyQueuesL1Bitmap[dom]), 1)) {
        prio = getHighestPrio(dom);
        thread = ksReadyQueues[ready_queues_index(dom, prio)].head;
        if(!(thread)) _assert_fail("thread", "/host/kernel/src/kernel/thread.c", 420, __FUNCTION__);
        if(!(isRunnable(thread))) _assert_fail("isSchedulable(thread)", "/host/kernel/src/kernel/thread.c", 421, __FUNCTION__);




        switchToThread(thread);
    } else {
        switchToIdleThread();
    }
}

void switchToThread(tcb_t *thread)
{
# 444 "/host/kernel/src/kernel/thread.c"
    Arch_switchToThread(thread);
    tcbSchedDequeue(thread);
    ksCurThread = thread;
}

void switchToIdleThread(void)
{



    Arch_switchToIdleThread();
    ksCurThread = ksIdleThread;
}

void setDomain(tcb_t *tptr, dom_t dom)
{
    tcbSchedDequeue(tptr);
    tptr->tcbDomain = dom;
    if (isRunnable(tptr)) {
        tcbSchedEnqueue(tptr);
    }
    if (tptr == ksCurThread) {
        rescheduleRequired();
    }
}

void setMCPriority(tcb_t *tptr, prio_t mcp)
{
    tptr->tcbMCP = mcp;
}
# 504 "/host/kernel/src/kernel/thread.c"
void setPriority(tcb_t *tptr, prio_t prio)
{
    tcbSchedDequeue(tptr);
    tptr->tcbPriority = prio;
    if (isRunnable(tptr)) {
        if (tptr == ksCurThread) {
            rescheduleRequired();
        } else {
            possibleSwitchTo(tptr);
        }
    }
}


/* Note that this thread will possibly continue at the end of this kernel
 * entry. Do not queue it yet, since a queue+unqueue operation is wasteful
 * if it will be picked. Instead, it waits in the 'ksSchedulerAction' site
 * on which the scheduler will take action. */
void possibleSwitchTo(tcb_t *target)
{



        if (ksCurDomain != target->tcbDomain
            ) {
            tcbSchedEnqueue(target);
        } else if (ksSchedulerAction != ((tcb_t*)0)) {
            /* Too many threads want special treatment, use regular queues. */
            rescheduleRequired();
            tcbSchedEnqueue(target);
        } else {
            ksSchedulerAction = target;
        }




}

void setThreadState(tcb_t *tptr, _thread_state_t ts)
{
    thread_state_ptr_set_tsType(&tptr->tcbState, ts);
    scheduleTCB(tptr);
}

void scheduleTCB(tcb_t *tptr)
{
    if (tptr == ksCurThread &&
        ksSchedulerAction == ((tcb_t*)0) &&
        !isRunnable(tptr)) {
        rescheduleRequired();
    }
}
# 621 "/host/kernel/src/kernel/thread.c"
void timerTick(void)
{
    if (__builtin_expect(!!(thread_state_get_tsType(ksCurThread->tcbState) == ThreadState_Running), 1)





       ) {
        if (ksCurThread->tcbTimeSlice > 1) {
            ksCurThread->tcbTimeSlice--;
        } else {
            ksCurThread->tcbTimeSlice = 5;
            tcbSchedAppend(ksCurThread);
            rescheduleRequired();
        }
    }

    if (1 > 1) {
        ksDomainTime--;
        if (ksDomainTime == 0) {
            rescheduleRequired();
        }
    }
}


void rescheduleRequired(void)
{
    if (ksSchedulerAction != ((tcb_t*)0)
        && ksSchedulerAction != ((tcb_t*) 1)



       ) {




        tcbSchedEnqueue(ksSchedulerAction);
    }
    ksSchedulerAction = ((tcb_t*) 1);
}
# 1 "/host/kernel/src/machine/capdl.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */



# 1 "/host/kernel/include/machine/timer.h" 1
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       
# 32 "/host/kernel/include/machine/timer.h"
static inline void resetTimer(void);
# 10 "/host/kernel/src/machine/capdl.c" 2
# 21 "/host/kernel/src/machine/capdl.c"
/* seen list - check this array before we print cnode and vspace */
/* TBD: This is to avoid traversing the same cnode. It should be applied to object
 * as well since the extractor might comes across multiple caps to the same object.
 */
cap_t seen_list[256];
int watermark = 0;

void add_to_seen(cap_t c)
{
    /* Won't work well if there're more than SEEN_SZ cnode */
    if (watermark <= 256) {
        seen_list[watermark] = c;
        watermark++;
    }
}

void reset_seen_list(void)
{
    memset(seen_list, 0, 256 * sizeof(seen_list[0]));
    watermark = 0;
}

bool_t seen(cap_t c)
{
    for (int i = 0; i < watermark; i++) {
        if (same_cap(seen_list[i], c)) {
            return true;
        }
    }
    return false;
}

bool_t same_cap(cap_t a, cap_t b)
{
    return (a.words[0] == b.words[0] && a.words[1] == b.words[1]);
}

/* Return true if strings are the same */
static inline bool_t strings_equal(const char *str1, const char *str2)
{
    while (*str1 && *str2 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return !(*(const unsigned char *)str1 - * (const unsigned char *)str2);
}

/* Return true if the tcb is for rootserver or idle thread */
bool_t root_or_idle_tcb(tcb_t *tcb)
{
    return (strings_equal(((debug_tcb_t *)(((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, "rootserver")
            || strings_equal(((debug_tcb_t *)(((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, "idle_thread"));
}

/*
 * Print objects
 */

void obj_tcb_print_attrs(tcb_t *tcb)
{
    kprintf("(addr: 0x%lx, ip: 0x%lx, sp: 0x%lx, prio: %lu, max_prio: %lu", (long unsigned int)tcb->tcbIPCBuffer, (long unsigned int)getRestartPC(tcb), (long unsigned int)get_tcb_sp(tcb), (long unsigned int)tcb->tcbPriority, (long unsigned int)tcb->tcbMCP)




                                          ;





    /* init */
# 101 "/host/kernel/src/machine/capdl.c"
    kprintf(", dom: %ld)\n", tcb->tcbDomain);
}
# 134 "/host/kernel/src/machine/capdl.c"
void obj_ut_print_attrs(cte_t *slot, tcb_t *tcb)
{
    /* might have two untypeds with the same address but different size */
    kprintf("%p_%lu_untyped = ut (%lu bits, paddr: %p) {", (void *)cap_untyped_cap_get_capPtr(slot->cap), (long unsigned int)cap_untyped_cap_get_capBlockSize(slot->cap), (long unsigned int)cap_untyped_cap_get_capBlockSize(slot->cap), ((word_t *)(cap_untyped_cap_get_capPtr(slot->cap))))



                                                           ;

    /* there is no need to check for a NullCap as NullCaps are
    always accompanied by null mdb pointers */
    for (cte_t *nextPtr = ((cte_t *)(mdb_node_get_mdbNext(slot->cteMDBNode)));
         nextPtr && isMDBParentOf(slot, nextPtr);
         nextPtr = ((cte_t *)(mdb_node_get_mdbNext(slot->cteMDBNode)))) {
        if (!sameRegionAs(slot->cap, nextPtr->cap)) {
            /* TBD:
             * - this will print out the attributes of the cap, which it shouldn't
             *
             * - might be a pathological case where an untyped has a child cap that
             *   isn't reachable from any of the non root threads. This would result
             *   in an object being mentioned but never properly defined
             */
            print_cap(nextPtr->cap);
        }
    }
    kprintf("}\n");
}

void obj_cnode_print_attrs(cap_t cnode)
{
    kprintf("(%lu bits)\n", (long unsigned int)cap_cnode_cap_get_capCNodeRadix(cnode));
}

void obj_tcb_print_cnodes(cap_t cnode, tcb_t *tcb)
{
    if (seen(cnode)) {
        return;
    }
    add_to_seen(cnode);
    kprintf("%p_cnode = cnode ", (void *)cap_cnode_cap_get_capCNodePtr(cnode));
    obj_cnode_print_attrs(cnode);
    word_t radix = cap_cnode_cap_get_capCNodeRadix(cnode);

    for (uint32_t i = 0; i < (1 << radix); i++) {
        lookupCapAndSlot_ret_t c = lookupCapAndSlot(tcb, i);
        if (cap_get_capType(c.cap) == cap_untyped_cap) {
            /* we need `cte_t *` to print out the slots of an untyped object */
            obj_ut_print_attrs(c.slot, tcb);

        } else if (cap_get_capType(c.cap) == cap_cnode_cap) {
            /* TBD: deal with nested cnodes */

        } else if (cap_get_capType(c.cap) != cap_null_cap) {
            print_object(c.cap);
        }
    }
}

/*
 * Caps
 */

void cap_cnode_print_attrs(cap_t cnode)
{
    kprintf("(guard: %lu, guard_size: %lu)\n", (long unsigned int)cap_cnode_cap_get_capCNodeGuard(cnode), (long unsigned int)cap_cnode_cap_get_capCNodeGuardSize(cnode))

                                                                         ;
}

void cap_ep_print_attrs(cap_t ep)
{
    kprintf("(");
    cap_endpoint_cap_get_capCanReceive(ep) ? putchar('R') : 0;
    cap_endpoint_cap_get_capCanSend(ep) ? putchar('W') : 0;
    cap_endpoint_cap_get_capCanGrant(ep) ? putchar('G') : 0;
    cap_endpoint_cap_get_capCanGrantReply(ep) ? putchar('P') : 0;
    long unsigned int badge = cap_endpoint_cap_get_capEPBadge(ep);
    badge ? kprintf(", badge: %lu)\n", badge) : kprintf(")\n");
}

void cap_ntfn_print_attrs(cap_t ntfn)
{
    kprintf("(");
    cap_notification_cap_get_capNtfnCanReceive(ntfn) ? putchar('R') : 0;
    cap_notification_cap_get_capNtfnCanSend(ntfn) ? putchar('W') : 0;
    long unsigned int badge = cap_notification_cap_get_capNtfnBadge(ntfn);
    badge ? kprintf(", badge: %lu)\n", badge) : kprintf(")\n");
}

/*
 * print object slots
 */

void obj_tcb_print_slots(tcb_t *tcb)
{
    kprintf("%p_tcb {\n", tcb);

    /* CSpace root */
    if (cap_get_capType((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbCTable))->cap) != cap_null_cap) {
        kprintf("cspace: %p_cnode ", (void *)cap_cnode_cap_get_capCNodePtr((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbCTable))->cap))
                                                                                           ;
        cap_cnode_print_attrs((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbCTable))->cap);
    }

    /* VSpace root */
    if (cap_get_capType((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap) != cap_null_cap) {
        kprintf("vspace: %p_pd\n", cap_vtable_cap_get_vspace_root_fp((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap))
                                                                                       ;

    }

    /* IPC buffer cap slot */
    if (cap_get_capType((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbBuffer))->cap) != cap_null_cap) {
        /* TBD: print out the bound vcpu */
        print_ipc_buffer_slot(tcb);
    }
# 273 "/host/kernel/src/machine/capdl.c"
    /* Reply cap slot */
    if (cap_get_capType((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbReply))->cap) != cap_null_cap) {
        kprintf("reply_slot: %p_reply\n", (void *)cap_reply_cap_get_capTCBPtr((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbReply))->cap))
                                                                                        ;
    }

    /* TCB of most recent IPC sender */
    if (cap_get_capType((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbCaller))->cap) != cap_null_cap) {
        tcb_t *caller = ((tcb_t *)(cap_thread_cap_get_capTCBPtr((((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbCaller))->cap)));
        kprintf("caller_slot: %p_tcb\n", caller);
    }

    kprintf("}\n");
}

/* TBD: deal with nested cnodes */
void obj_cnode_print_slots(tcb_t *tcb)
{
    cap_t root = (((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbCTable))->cap;
    if (cap_get_capType(root) != cap_cnode_cap) {
        return;
    }

    word_t radix = cap_cnode_cap_get_capCNodeRadix(root);
    if (seen(root)) {
        return;
    }
    add_to_seen(root);

    kprintf("%p_cnode {\n", (void *)cap_cnode_cap_get_capCNodePtr(root));

    for (uint32_t i = 0; i < (1 << radix); i++) {
        lookupCapAndSlot_ret_t c = lookupCapAndSlot(tcb, i);
        if (cap_get_capType(c.cap) != cap_null_cap) {
            kprintf("0x%x: ", i);
            print_cap(c.cap);
        }
    }
    kprintf("}\n");

    for (uint32_t i = 0; i < (1 << radix); i++) {
        lookupCapAndSlot_ret_t c = lookupCapAndSlot(tcb, i);
        if (cap_get_capType(c.cap) == cap_irq_handler_cap) {
            /* TBD: should instead print it from IRQNode */
            obj_irq_print_slots(c.cap);
        }
    }
}

void obj_irq_print_maps(void)
{
    kprintf("irq maps {\n");

    for (seL4_Word target = 0; target < 1; target++) {
        for (unsigned i = 0; i <= maxIRQ; i++) {
            irq_t irq = (i);
            if (isIRQActive(irq)) {
                cap_t cap = intStateIRQNode[(irq)].cap;
                if (cap_get_capType(cap) != cap_null_cap) {
                    kprintf("%d: 0x%lx_%lu_irq\n", i, (long unsigned int)irq, (long unsigned int)target)






                                                     ;
                }
            }
        }
    }
    kprintf("}\n");
}

void obj_irq_print_slots(cap_t irq_cap)
{
    irq_t irq = (cap_irq_handler_cap_get_capIRQ(irq_cap));
    if (isIRQActive(irq)) {
        kprintf("0x%lx_%lu_irq {\n", (long unsigned int)irq, (long unsigned int)0)





                                                    ;
        cap_t ntfn_cap = intStateIRQNode[(irq)].cap;
        if (cap_get_capType(ntfn_cap) != cap_null_cap) {
            kprintf("0x0: ");
            print_cap(ntfn_cap);
        }
        kprintf("}\n");
    }
}

void print_objects(void)
{
    for (tcb_t *curr = ksDebugTCBs; curr != ((void *)0); curr = ((debug_tcb_t *)(((cte_t *)((word_t)(curr)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbDebugNext) {
        if (root_or_idle_tcb(curr)) {
            continue;
        }
        /* print the contains of the tcb's vtable as objects */
        obj_tcb_print_vtable(curr);
    }

    for (tcb_t *curr = ksDebugTCBs; curr != ((void *)0); curr = ((debug_tcb_t *)(((cte_t *)((word_t)(curr)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbDebugNext) {
        if (root_or_idle_tcb(curr)) {
            continue;
        }

        /* print the tcb as objects */
        kprintf("%p_tcb = tcb ", curr);
        obj_tcb_print_attrs(curr);

        /* print the contains of the tcb's ctable as objects */
        if (cap_get_capType((((cte_t *)((word_t)(curr)&~((1ul << (11))-1ul)))+(tcbCTable))->cap) == cap_cnode_cap) {
            obj_tcb_print_cnodes((((cte_t *)((word_t)(curr)&~((1ul << (11))-1ul)))+(tcbCTable))->cap, curr);
        }
    }
}

void print_caps(void)
{
    for (tcb_t *curr = ksDebugTCBs; curr != ((void *)0); curr = ((debug_tcb_t *)(((cte_t *)((word_t)(curr)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbDebugNext) {
        if (root_or_idle_tcb(curr)) {
            continue;
        }
        obj_cnode_print_slots(curr);
        obj_vtable_print_slots(curr);
        obj_tcb_print_slots(curr);
    }
}

void print_cap(cap_t cap)
{
    switch (cap_get_capType(cap)) {
    case cap_endpoint_cap: {
        kprintf("%p_ep ", (void *)cap_endpoint_cap_get_capEPPtr(cap))
                                                          ;
        cap_ep_print_attrs(cap);
        break;
    }
    case cap_notification_cap: {
        kprintf("%p_notification ", (void *)cap_notification_cap_get_capNtfnPtr(cap))
                                                                ;
        cap_ntfn_print_attrs(cap);
        break;
    }
    case cap_untyped_cap: {
        kprintf("%p_untyped\n", (void *)cap_untyped_cap_get_capPtr(cap))
                                                       ;
        break;
    }
    case cap_thread_cap: {
        kprintf("%p_tcb\n", (void *)cap_thread_cap_get_capTCBPtr(cap))
                                                         ;
        break;
    }
    case cap_cnode_cap: {
        kprintf("%p_cnode ", (void *)cap_cnode_cap_get_capCNodePtr(cap))
                                                          ;
        cap_cnode_print_attrs(cap);
        break;
    }
# 453 "/host/kernel/src/machine/capdl.c"
    case cap_irq_control_cap: {
        kprintf("irq_control\n"); /* only one in the system */
        break;
    }
    case cap_irq_handler_cap: {
        kprintf("%p_%lu_irq\n", (void *)cap_irq_handler_cap_get_capIRQ(cap), (long unsigned int)0)

                                                                                                 ;
        break;
    }
    default: {
        print_cap_arch(cap);
        break;
    }
    }
}

void print_object(cap_t cap)
{
    switch (cap_get_capType(cap)) {
    case cap_endpoint_cap: {
        kprintf("%p_ep = ep\n", (void *)cap_endpoint_cap_get_capEPPtr(cap))
                                                          ;
        break;
    }
    case cap_notification_cap: {
        kprintf("%p_notification = notification\n", (void *)cap_notification_cap_get_capNtfnPtr(cap))
                                                                ;
        break;
    }
    case cap_thread_cap: {
        /* this object has already got handle by `print_objects` */
        break;
    }
    case cap_cnode_cap: {
        if(!(!"should not happend")) _assert_fail("!\"should not happend\"", "/host/kernel/src/machine/capdl.c", 488, __FUNCTION__);
    }
# 503 "/host/kernel/src/machine/capdl.c"
    case cap_irq_handler_cap: {
        kprintf("%p_%lu_irq = irq\n", (void *)cap_irq_handler_cap_get_capIRQ(cap), (long unsigned int)0)

                                                                                                 ;
        break;
    }
    default:
        print_object_arch(cap);
        break;
    }
}
# 1 "/host/kernel/src/machine/fpu.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 14 "/host/kernel/src/machine/fpu.c"
/* Switch the owner of the FPU to the given thread on local core. */
void switchLocalFpuOwner(user_fpu_state_t *new_owner)
{
    enableFpu();
    if (ksActiveFPUState) {
        saveFpuState(ksActiveFPUState);
    }
    if (new_owner) {
        ksFPURestoresSinceSwitch = 0;
        loadFpuState(new_owner);
    } else {
        disableFpu();
    }
    ksActiveFPUState = new_owner;
}

void switchFpuOwner(user_fpu_state_t *new_owner, word_t cpu)
{





    {
        switchLocalFpuOwner(new_owner);
    }
}

/* Handle an FPU fault.
 *
 * This CPU exception is thrown when userspace attempts to use the FPU while
 * it is disabled. We need to save the current state of the FPU, and hand
 * it over. */
exception_t handleFPUFault(void)
{
    /* If we have already given the FPU to the user, we should not reach here.
     * This should only be able to occur on CPUs without an FPU at all, which
     * we presumably are happy to assume will not be running seL4. */
    if(!(!nativeThreadUsingFPU(ksCurThread))) _assert_fail("!nativeThreadUsingFPU(NODE_STATE(ksCurThread))", "/host/kernel/src/machine/fpu.c", 52, __FUNCTION__);

    /* Otherwise, lazily switch over the FPU. */
    switchLocalFpuOwner(&ksCurThread->tcbArch.tcbContext.fpuState);

    return EXCEPTION_NONE;
}

/* Prepare for the deletion of the given thread. */
void fpuThreadDelete(tcb_t *thread)
{
    /* If the thread being deleted currently owns the FPU, switch away from it
     * so that 'ksActiveFPUState' doesn't point to invalid memory. */
    if (nativeThreadUsingFPU(thread)) {
        switchFpuOwner(((void *)0), 0);
    }
}
# 1 "/host/kernel/src/machine/io.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 *
 * Portions derived from musl:
 *
 * Copyright © 2005-2020 Rich Felker, et al.
 *
 * SPDX-License-Identifier: MIT
 */






# 1 "/host/kernel/include/stdarg.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       





typedef __builtin_va_list va_list;
# 19 "/host/kernel/src/machine/io.c" 2


/*
 * a handle defining how to output a character
 */
typedef void (*out_fn)(char character, char *buf, word_t idx);

/*
 * structure to allow a generic vprintf
 * a out_fn handle and a buf to work on
 */
typedef struct {
    out_fn putchar;
    char *buf;
    word_t idx;
    word_t maxlen;
} out_wrap_t;

/*
 * putchar would then just call the handle with its buf
 * and current idx and then increment idx
 */
static void putchar_wrap(out_wrap_t *out, char c)
{
    if (out->maxlen < 0 || out->idx < out->maxlen) {
        out->putchar(c, out->buf, out->idx);
        out->idx++;
    }
}


void putchar(char c)
{
    if (c == '\n') {
        putDebugChar('\r');
    }
    putDebugChar(c);
}

static inline bool_t isdigit(char c)
{
    return c >= '0' &&
           c <= '9';
}

/* Convenient bit representation for modifier flags, which all fall
 * within 31 codepoints of the space character. */
# 83 "/host/kernel/src/machine/io.c"
/* State machine to accept length modifiers + conversion specifiers.
 * Result is 0 on failure, or an argument type to pop on success. */

enum {
    BARE, LPRE, LLPRE, HPRE, HHPRE, BIGLPRE,
    ZTPRE, JPRE,
    STOP,
    PTR, INT, UINT, ULLONG,
    LONG, ULONG,
    SHORT, USHORT, CHAR, UCHAR,
    WORDT, LLONG,




    NOARG,
    MAXSTATE
};



static const unsigned char states[]['z' - 'A' + 1] = {
    { /* 0: bare types */
        [('d')-'A'] = INT, [('i')-'A'] = INT,
        [('o')-'A'] = UINT, [('u')-'A'] = UINT, [('x')-'A'] = UINT, [('X')-'A'] = UINT,
        [('c')-'A'] = CHAR,
        [('s')-'A'] = PTR, [('p')-'A'] = ULONG, [('n')-'A'] = PTR,
        [('l')-'A'] = LPRE, [('h')-'A'] = HPRE,
        [('z')-'A'] = ZTPRE, [('j')-'A'] = JPRE, [('t')-'A'] = ZTPRE,
    }, { /* 1: l-prefixed */
        [('d')-'A'] = LONG, [('i')-'A'] = LONG,
        [('o')-'A'] = ULONG, [('u')-'A'] = ULONG, [('x')-'A'] = ULONG, [('X')-'A'] = ULONG,
        [('n')-'A'] = PTR,
        [('l')-'A'] = LLPRE,
    }, { /* 2: ll-prefixed */
        [('d')-'A'] = LLONG, [('i')-'A'] = LLONG,
        [('o')-'A'] = ULLONG, [('u')-'A'] = ULLONG,
        [('x')-'A'] = ULLONG, [('X')-'A'] = ULLONG,
        [('n')-'A'] = PTR,
    }, { /* 3: h-prefixed */
        [('d')-'A'] = SHORT, [('i')-'A'] = SHORT,
        [('o')-'A'] = USHORT, [('u')-'A'] = USHORT,
        [('x')-'A'] = USHORT, [('X')-'A'] = USHORT,
        [('n')-'A'] = PTR,
        [('h')-'A'] = HHPRE,
    }, { /* 4: hh-prefixed */
        [('d')-'A'] = CHAR, [('i')-'A'] = CHAR,
        [('o')-'A'] = UCHAR, [('u')-'A'] = UCHAR,
        [('x')-'A'] = UCHAR, [('X')-'A'] = UCHAR,
        [('n')-'A'] = PTR,
    }, { /* 5: L-prefixed not supported */
    }, { /* 6: z- or t-prefixed (assumed to be same size) */
        [('d')-'A'] = LONG, [('i')-'A'] = LONG,
        [('o')-'A'] = WORDT, [('u')-'A'] = WORDT,
        [('x')-'A'] = WORDT, [('X')-'A'] = WORDT,
        [('n')-'A'] = PTR,
    }, { /* 7: j-prefixed */
        [('d')-'A'] = LLONG, [('i')-'A'] = LLONG,
        [('o')-'A'] = ULLONG, [('u')-'A'] = ULLONG,
        [('x')-'A'] = ULLONG, [('X')-'A'] = ULLONG,
        [('n')-'A'] = PTR,
    }
};




union arg {
    word_t i;
    long double f;
    void *p;
};

static void pop_arg(union arg *arg, int type, va_list *ap)
{
    switch (type) {
    case PTR:
        arg->p = __builtin_va_arg(*ap,void *);
        break;
    case INT:
        arg->i = __builtin_va_arg(*ap,int);
        break;
    case UINT:
        arg->i = __builtin_va_arg(*ap,unsigned int);
        break;
    case LONG:
        arg->i = __builtin_va_arg(*ap,long);
        break;
    case ULONG:
        arg->i = __builtin_va_arg(*ap,unsigned long);
        break;
    case LLONG:
        arg->i = __builtin_va_arg(*ap,long long);
        break;
    case ULLONG:
        arg->i = __builtin_va_arg(*ap,unsigned long long);
        break;
    case SHORT:
        arg->i = (short)__builtin_va_arg(*ap,int);
        break;
    case USHORT:
        arg->i = (unsigned short)__builtin_va_arg(*ap,int);
        break;
    case CHAR:
        arg->i = (signed char)__builtin_va_arg(*ap,int);
        break;
    case UCHAR:
        arg->i = (unsigned char)__builtin_va_arg(*ap,int);
        break;
    case WORDT:
        arg->i = __builtin_va_arg(*ap,word_t);
    }
}

static void out(out_wrap_t *f, const char *s, word_t l)
{
    for (word_t i = 0; i < l; i++) {
        putchar_wrap(f, s[i]);
    }
}

static void pad(out_wrap_t *f, char c, int w, int l, int fl)
{
    char pad[256];
    if (fl & ((1U<<('-'-' ')) | (1U<<('0'-' '))) || l >= w) {
        return;
    }
    l = w - l;
    memset(pad, c, l > sizeof pad ? sizeof pad : l);
    for (; l >= sizeof pad; l -= sizeof pad) {
        out(f, pad, sizeof pad);
    }
    out(f, pad, l);
}

static const char xdigits[16] = {
    "0123456789ABCDEF"
};

static char *fmt_x(word_t x, char *s, int lower)
{
    for (; x; x >>= 4) {
        *--s = xdigits[(x & 15)] | lower;
    }
    return s;
}

static char *fmt_o(word_t x, char *s)
{
    for (; x; x >>= 3) {
        *--s = '0' + (x & 7);
    }
    return s;
}

static char *fmt_u(word_t x, char *s)
{
    unsigned long y;
    for (; x > ((unsigned long)(-1)); x /= 10) {
        *--s = '0' + x % 10;
    }
    for (y = x; y; y /= 10) {
        *--s = '0' + y % 10;
    }
    return s;
}

// Maximum buffer size taken to ensure correct adaptation
// However, it could be reduced/removed if we could measure
// the buf length under all code paths




static int getint(char **s)
{
    int i;
    for (i = 0; isdigit(**s); (*s)++) {
        if (i > 0x7fffffff / 10U || (**s - '0') > 0x7fffffff - 10 * i) {
            i = -1;
        } else {
            i = 10 * i + (**s - '0');
        }
    }
    return i;
}

static int printf_core(out_wrap_t *f, const char *fmt, va_list *ap, union arg *nl_arg, int *nl_type)
{
    char *a, *z, *s = (char *)fmt;
    unsigned l10n = 0, fl;
    int w, p, xp;
    union arg arg;
    int argpos;
    unsigned st, ps;
    int cnt = 0, l = 0;
    word_t i;
    char buf[sizeof(word_t) * 3 + 3 + 113 / 4];
    const char *prefix;
    int t, pl;

    for (;;) {
        /* This error is only specified for snprintf, but since it's
         * unspecified for other forms, do the same. Stop immediately
         * on overflow; otherwise %n could produce wrong results. */
        if (l > 0x7fffffff - cnt) {
            goto overflow;
        }

        /* Update output count, end loop when fmt is exhausted */
        cnt += l;
        if (!*s) {
            break;
        }

        /* Handle literal text and %% format specifiers */
        for (a = s; *s && *s != '%'; s++);
        for (z = s; s[0] == '%' && s[1] == '%'; z++, s += 2);
        if (z - a > 0x7fffffff - cnt) {
            goto overflow;
        }
        l = z - a;
        if (f) {
            out(f, a, l);
        }
        if (l) {
            continue;
        }

        if (isdigit(s[1]) && s[2] == '$') {
            l10n = 1;
            argpos = (s[1] - '0');
            s += 3;
        } else {
            argpos = -1;
            s++;
        }

        /* Read modifier flags */
        for (fl = 0; (unsigned)*s - ' ' < 32 && (((1U<<('#'-' '))|(1U<<('0'-' '))|(1U<<('-'-' '))|(1U<<(' '-' '))|(1U<<('+'-' '))|(1U<<('\''-' '))) & (1U<<( *s -' '))); s++) {
            fl |= (1U<<( *s -' '));
        }

        /* Read field width */
        if (*s == '*') {
            if (isdigit(s[1]) && s[2] == '$') {
                l10n = 1;
                nl_type[(s[1] - '0')] = INT;
                w = nl_arg[(s[1] - '0')].i;
                s += 3;
            } else if (!l10n) {
                w = f ? __builtin_va_arg(*ap,int) : 0;
                s++;
            } else {
                goto inval;
            }
            if (w < 0) {
                fl |= (1U<<('-'-' '));
                w = -w;
            }
        } else if ((w = getint(&s)) < 0) {
            goto overflow;
        }

        /* Read precision */
        if (*s == '.' && s[1] == '*') {
            if (isdigit(s[2]) && s[3] == '$') {
                nl_type[(s[2] - '0')] = INT;
                p = nl_arg[(s[2] - '0')].i;
                s += 4;
            } else if (!l10n) {
                p = f ? __builtin_va_arg(*ap,int) : 0;
                s += 2;
            } else {
                goto inval;
            }
            xp = (p >= 0);
        } else if (*s == '.') {
            s++;
            p = getint(&s);
            xp = 1;
        } else {
            p = -1;
            xp = 0;
        }

        /* Format specifier state machine */
        st = 0;
        do {
            if (((unsigned)(*s)-'A' > 'z'-'A')) {
                goto inval;
            }
            ps = st;
            st = states[st][(*s++)-'A'];
        } while (st - 1 < STOP);
        if (!st) {
            goto inval;
        }

        /* Check validity of argument type (nl/normal) */
        if (st == NOARG) {
            if (argpos >= 0) {
                goto inval;
            }
        } else {
            if (argpos >= 0) {
                nl_type[argpos] = st;
                arg = nl_arg[argpos];
            } else if (f) {
                pop_arg(&arg, st, ap);
            } else {
                return 0;
            }
        }

        if (!f) {
            continue;
        }

        z = buf + sizeof(buf);
        prefix = "-+   0X0x";
        pl = 0;
        t = s[-1];

        /* - and 0 flags are mutually exclusive */
        if (fl & (1U<<('-'-' '))) {
            fl &= ~(1U<<('0'-' '));
        }

        if (t == 'n') {
            if (!arg.p) {
                continue;
            }
            switch (ps) {
            case BARE:
                *(int *)arg.p = cnt;
                break;
            case LPRE:
                *(long *)arg.p = cnt;
                break;
            case LLPRE:
                *(long long *)arg.p = cnt;
                break;
            case HPRE:
                *(unsigned short *)arg.p = cnt;
                break;
            case HHPRE:
                *(unsigned char *)arg.p = cnt;
                break;
            case ZTPRE:
                *(word_t *)arg.p = cnt;
                break;
            case JPRE:
                *(word_t *)arg.p = cnt;
                break;
            }
            continue;
        } else if (t == 'c') {
            p = 1;
            a = z - p;
            *a = arg.i;
            fl &= ~(1U<<('0'-' '));
        } else if (t == 's') {
            a = arg.p ? arg.p : "(null)";
            z = a + strnlen(a, p < 0 ? 0x7fffffff : p);
            if (p < 0 && *z) {
                goto overflow;
            }
            p = z - a;
            fl &= ~(1U<<('0'-' '));
        } else {
            switch (t) {
            case 'p':
                p = (((p)>(2 * sizeof(void *)))?(p):(2 * sizeof(void *)));
                t = 'x';
                fl |= (1U<<('#'-' '));
            case 'x':
            case 'X':
                a = fmt_x(arg.i, z, t & 32);
                if (arg.i && (fl & (1U<<('#'-' ')))) {
                    prefix += (t >> 4);
                    pl = 2;
                }
                break;
            case 'o':
                a = fmt_o(arg.i, z);
                if ((fl & (1U<<('#'-' '))) && p < (z - a + 1)) {
                    p = z - a + 1;
                }
                break;
            case 'd':
            case 'i':
                pl = 1;
                if (arg.i > (0x7FFFFFFF)) {
                    arg.i = -arg.i;
                } else if (fl & (1U<<('+'-' '))) {
                    prefix++;
                } else if (fl & (1U<<(' '-' '))) {
                    prefix += 2;
                } else {
                    pl = 0;
                }
            case 'u':
                a = fmt_u(arg.i, z);
                break;
            }
            if (xp && p < 0) {
                goto overflow;
            }
            if (xp) {
                fl &= ~(1U<<('0'-' '));
            }
            if (!arg.i && !p) {
                a = z;
            } else {
                p = (((p)>(z - a + !arg.i))?(p):(z - a + !arg.i));
            }
        }

        if (p < z - a) {
            p = z - a;
        }
        if (p > 0x7fffffff - pl) {
            goto overflow;
        }
        if (w < pl + p) {
            w = pl + p;
        }
        if (w > 0x7fffffff - cnt) {
            goto overflow;
        }

        pad(f, ' ', w, pl + p, fl);
        out(f, prefix, pl);
        pad(f, '0', w, pl + p, fl ^ (1U<<('0'-' ')));
        pad(f, '0', p, z - a, 0);
        out(f, a, z - a);
        pad(f, ' ', w, pl + p, fl ^ (1U<<('-'-' ')));

        l = w;
    }

    if (f) {
        return cnt;
    }
    if (!l10n) {
        return 0;
    }

    for (i = 1; i <= 9 && nl_type[i]; i++) {
        pop_arg(nl_arg + i, nl_type[i], ap);
    }
    for (; i <= 9 && !nl_type[i]; i++);
    if (i <= 9) {
        goto inval;
    }
    return 1;

// goto for potential debug error support
inval:
overflow:
    return -1;
}

// sprintf fills its buf with the given character
static void buf_out_fn(char c, char *buf, word_t idx)
{
    buf[idx] = c;
}

// printf only needs to call kernel_putchar
static void kernel_out_fn(char c, char *buf, word_t idx)
{
    putchar(c);
}

word_t puts(const char *s)
{
    for (; *s; s++) {
        putchar(*s);
    }
    putchar('\n');
    return 0;
}

static int vprintf(out_wrap_t *out, const char *fmt, va_list ap)
{
    va_list ap2;
    int nl_type[9 + 1] = {0};
    union arg nl_arg[9 + 1];
    int ret;

    // validate format string
    __builtin_va_copy(ap2,ap);
    if (printf_core(0, fmt, &ap2, nl_arg, nl_type) < 0) {
        __builtin_va_end(ap2);
        return -1;
    }

    ret = printf_core(out, fmt, &ap2, nl_arg, nl_type);
    __builtin_va_end(ap2);
    return ret;
}

word_t kprintf(const char *format, ...)
{
    va_list args;
    word_t ret;

    out_wrap_t out = { kernel_out_fn, ((void *)0), 0, -1 };

    __builtin_va_start(args,format);
    ret = vprintf(&out, format, args);
    __builtin_va_end(args);
    return ret;
}

word_t ksnprintf(char *str, word_t size, const char *format, ...)
{
    va_list args;
    word_t i;

    out_wrap_t out = { buf_out_fn, str, 0, size };

    __builtin_va_start(args,format);
    i = vprintf(&out, format, args);
    __builtin_va_end(args);

    // make sure there is space for a 0 byte
    if (i >= size) {
        i = size - 1;
    }
    str[i] = 0;

    return i;
}
# 1 "/host/kernel/src/machine/registerset.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */



const register_t fault_messages[][(((n_syscallMessage)>(n_exceptionMessage))?(n_syscallMessage):(n_exceptionMessage))] = {
    [MessageID_Syscall] = { [seL4_UnknownSyscall_RAX] = RAX, [seL4_UnknownSyscall_RBX] = RBX, [seL4_UnknownSyscall_RCX] = RCX, [seL4_UnknownSyscall_RDX] = RDX, [seL4_UnknownSyscall_RSI] = RSI, [seL4_UnknownSyscall_RDI] = RDI, [seL4_UnknownSyscall_RBP] = RBP, [seL4_UnknownSyscall_R8] = R8, [seL4_UnknownSyscall_R9] = R9, [seL4_UnknownSyscall_R10] = R10, [seL4_UnknownSyscall_R11] = R11, [seL4_UnknownSyscall_R12] = R12, [seL4_UnknownSyscall_R13] = R13, [seL4_UnknownSyscall_R14] = R14, [seL4_UnknownSyscall_R15] = R15, [seL4_UnknownSyscall_FaultIP] = FaultIP, [seL4_UnknownSyscall_SP] = RSP, [seL4_UnknownSyscall_FLAGS] = FLAGS},
    [MessageID_Exception] = { [seL4_UserException_FaultIP] = FaultIP, [seL4_UserException_SP] = RSP, [seL4_UserException_FLAGS] = FLAGS},



};
# 1 "/host/kernel/src/model/preemption.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */


# 1 "/host/kernel/include/model/preemption.h" 1
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

       



exception_t preemptionPoint(void);
# 9 "/host/kernel/src/model/preemption.c" 2




/*
 * Possibly preempt the current thread to allow an interrupt to be handled.
 */
exception_t preemptionPoint(void)
{
    /* Record that we have performed some work. */
    ksWorkUnitsCompleted++;

    /*
     * If we have performed a non-trivial amount of work since last time we
     * checked for preemption, and there is an interrupt pending, handle the
     * interrupt.
     *
     * We avoid checking for pending IRQs every call, as our callers tend to
     * call us in a tight loop and checking for pending IRQs can be quite slow.
     */
    if (ksWorkUnitsCompleted >= 100) {
        ksWorkUnitsCompleted = 0;
        if (isIRQPending()) {
            return EXCEPTION_PREEMPTED;







        }
    }

    return EXCEPTION_NONE;
}
# 1 "/host/kernel/src/model/smp.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/model/statedata.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 17 "/host/kernel/src/model/statedata.c"
/* Collective cpu states, including both pre core architecture dependant and independent data */
;

/* Global count of how many cpus there are */
word_t ksNumCPUs;

/* Pointer to the head of the scheduler queue for each priority */
tcb_queue_t ksReadyQueues[(1 * 256)];
word_t ksReadyQueuesL1Bitmap[1];
word_t ksReadyQueuesL2Bitmap[1][((256 + (1 << 6) - 1) / (1 << 6))];
typedef int __assert_failed_ksReadyQueuesL1BitmapBigEnough[((((256 + (1 << 6) - 1) / (1 << 6)) - 1) <= (1 << 6)) ? 1 : -1];





/* Current thread TCB pointer */
tcb_t * ksCurThread;

/* Idle thread TCB pointer */
tcb_t * ksIdleThread;

/* Values of 0 and ~0 encode ResumeCurrentThread and ChooseNewThread
 * respectively; other values encode SwitchToThread and must be valid
 * tcb pointers */
tcb_t * ksSchedulerAction;


/* Currently active FPU state, or NULL if there is no active FPU state */
user_fpu_state_t * ksActiveFPUState;

word_t ksFPURestoresSinceSwitch;
# 62 "/host/kernel/src/model/statedata.c"
tcb_t * ksDebugTCBs;
# 73 "/host/kernel/src/model/statedata.c"
/* Units of work we have completed since the last time we checked for
 * pending interrupts */
word_t ksWorkUnitsCompleted;

irq_state_t intStateIRQTable[(maxIRQ + 1)];
/* CNode containing interrupt handler endpoints - like all seL4 objects, this CNode needs to be
 * of a size that is a power of 2 and aligned to its size. */
cte_t intStateIRQNode[(1ul << (8))] __attribute__((__aligned__((1ul << (8 + 5)))));
typedef int __assert_failed_irqCNodeSize[(sizeof(intStateIRQNode) >= (((maxIRQ + 1)) *sizeof(cte_t))) ? 1 : -1];;

/* Currently active domain */
dom_t ksCurDomain;

/* Domain timeslice remaining */



word_t ksDomainTime;


/* An index into ksDomSchedule for active domain and length. */
word_t ksDomScheduleIdx;

/* Only used by lockTLBEntry */
word_t tlbLockCount = 0;

/* Idle thread. */
__attribute__((__section__("._idle_thread"))) char ksIdleThreadTCB[1][(1ul << (11))] __attribute__((__aligned__((1ul << ((11 - 1))))));







kernel_entry_t ksKernelEntry;
# 1 "/host/kernel/src/object/cnode.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




# 1 "kernel/gen_headers/api/invocation.h" 1

/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 ** SPDX-License-Identifier: GPL-2.0-only
 */

/* This header was generated by kernel/tools/invocation_header_gen.py.
 *
 * To add an invocation call number, edit libsel4/include/interfaces/sel4.xml.
 *
 */
# 11 "/host/kernel/src/object/cnode.c" 2
# 25 "/host/kernel/src/object/cnode.c"
struct finaliseSlot_ret {
    exception_t status;
    bool_t success;
    cap_t cleanupInfo;
};
typedef struct finaliseSlot_ret finaliseSlot_ret_t;

static finaliseSlot_ret_t finaliseSlot(cte_t *slot, bool_t exposed);
static void emptySlot(cte_t *slot, cap_t cleanupInfo);
static exception_t reduceZombie(cte_t *slot, bool_t exposed);







exception_t decodeCNodeInvocation(word_t invLabel, word_t length, cap_t cap,
                                  extra_caps_t excaps, word_t *buffer)
{
    lookupSlot_ret_t lu_ret;
    cte_t *destSlot;
    word_t index, w_bits;
    exception_t status;

    /* Haskell error: "decodeCNodeInvocation: invalid cap" */
    if(!(cap_get_capType(cap) == cap_cnode_cap)) _assert_fail("cap_get_capType(cap) == cap_cnode_cap", "/host/kernel/src/object/cnode.c", 51, __FUNCTION__);

    if (invLabel < CNodeRevoke || invLabel > CNodeSaveCaller) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNodeCap: Illegal Operation attempted." ">>" "\033[0m" "\n", 0lu, __func__, 54, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (length < 2) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode operation: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 60, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }
    index = getSyscallArg(0, buffer);
    w_bits = getSyscallArg(1, buffer);

    lu_ret = lookupTargetSlot(cap, index, w_bits);
    if (lu_ret.status != EXCEPTION_NONE) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode operation: Target slot invalid." ">>" "\033[0m" "\n", 0lu, __func__, 69, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        return lu_ret.status;
    }
    destSlot = lu_ret.slot;

    if (invLabel >= CNodeCopy && invLabel <= CNodeMutate) {
        cte_t *srcSlot;
        word_t srcIndex, srcDepth, capData;
        bool_t isMove;
        seL4_CapRights_t cap_rights;
        cap_t srcRoot, newCap;
        deriveCap_ret_t dc_ret;
        cap_t srcCap;

        if (length < 4 || excaps.excaprefs[0] == ((void *)0)) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode Copy/Mint/Move/Mutate: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 84, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }
        srcIndex = getSyscallArg(2, buffer);
        srcDepth = getSyscallArg(3, buffer);

        srcRoot = excaps.excaprefs[0]->cap;

        status = ensureEmptySlot(destSlot);
        if (status != EXCEPTION_NONE) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode Copy/Mint/Move/Mutate: Destination not empty." ">>" "\033[0m" "\n", 0lu, __func__, 95, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            return status;
        }

        lu_ret = lookupSourceSlot(srcRoot, srcIndex, srcDepth);
        if (lu_ret.status != EXCEPTION_NONE) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode Copy/Mint/Move/Mutate: Invalid source slot." ">>" "\033[0m" "\n", 0lu, __func__, 101, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            return lu_ret.status;
        }
        srcSlot = lu_ret.slot;

        if (cap_get_capType(srcSlot->cap) == cap_null_cap) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode Copy/Mint/Move/Mutate: Source slot invalid or empty." ">>" "\033[0m" "\n", 0lu, __func__, 107, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = 1;
            current_lookup_fault =
                lookup_fault_missing_capability_new(srcDepth);
            return EXCEPTION_SYSCALL_ERROR;
        }

        switch (invLabel) {
        case CNodeCopy:

            if (length < 5) {
                do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Truncated message for CNode Copy operation." ">>" "\033[0m" "\n", 0lu, __func__, 119, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
                current_syscall_error.type = seL4_TruncatedMessage;
                return EXCEPTION_SYSCALL_ERROR;
            }

            cap_rights = rightsFromWord(getSyscallArg(4, buffer));
            srcCap = maskCapRights(cap_rights, srcSlot->cap);
            dc_ret = deriveCap(srcSlot, srcCap);
            if (dc_ret.status != EXCEPTION_NONE) {
                do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Error deriving cap for CNode Copy operation." ">>" "\033[0m" "\n", 0lu, __func__, 128, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
                return dc_ret.status;
            }
            newCap = dc_ret.cap;
            isMove = false;

            break;

        case CNodeMint:
            if (length < 6) {
                do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode Mint: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 138, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
                current_syscall_error.type = seL4_TruncatedMessage;
                return EXCEPTION_SYSCALL_ERROR;
            }

            cap_rights = rightsFromWord(getSyscallArg(4, buffer));
            capData = getSyscallArg(5, buffer);
            srcCap = maskCapRights(cap_rights, srcSlot->cap);
            dc_ret = deriveCap(srcSlot,
                               updateCapData(false, capData, srcCap));
            if (dc_ret.status != EXCEPTION_NONE) {
                do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Error deriving cap for CNode Mint operation." ">>" "\033[0m" "\n", 0lu, __func__, 149, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
                return dc_ret.status;
            }
            newCap = dc_ret.cap;
            isMove = false;

            break;

        case CNodeMove:
            newCap = srcSlot->cap;
            isMove = true;

            break;

        case CNodeMutate:
            if (length < 5) {
                do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode Mutate: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 165, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
                current_syscall_error.type = seL4_TruncatedMessage;
                return EXCEPTION_SYSCALL_ERROR;
            }

            capData = getSyscallArg(4, buffer);
            newCap = updateCapData(true, capData, srcSlot->cap);
            isMove = true;

            break;

        default:
            if(!(0)) _assert_fail("0", "/host/kernel/src/object/cnode.c", 177, __FUNCTION__);
            return EXCEPTION_NONE;
        }

        if (cap_get_capType(newCap) == cap_null_cap) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode Copy/Mint/Move/Mutate: Mutated cap would be invalid." ">>" "\033[0m" "\n", 0lu, __func__, 182, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksCurThread, ThreadState_Restart);
        if (isMove) {
            return invokeCNodeMove(newCap, srcSlot, destSlot);
        } else {
            return invokeCNodeInsert(newCap, srcSlot, destSlot);
        }
    }

    if (invLabel == CNodeRevoke) {
        setThreadState(ksCurThread, ThreadState_Restart);
        return invokeCNodeRevoke(destSlot);
    }

    if (invLabel == CNodeDelete) {
        setThreadState(ksCurThread, ThreadState_Restart);
        return invokeCNodeDelete(destSlot);
    }


    if (invLabel == CNodeSaveCaller) {
        status = ensureEmptySlot(destSlot);
        if (status != EXCEPTION_NONE) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode SaveCaller: Destination slot not empty." ">>" "\033[0m" "\n", 0lu, __func__, 209, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            return status;
        }

        setThreadState(ksCurThread, ThreadState_Restart);
        return invokeCNodeSaveCaller(destSlot);
    }


    if (invLabel == CNodeCancelBadgedSends) {
        cap_t destCap;

        destCap = destSlot->cap;

        if (!hasCancelSendRights(destCap)) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode CancelBadgedSends: Target cap invalid." ">>" "\033[0m" "\n", 0lu, __func__, 224, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            return EXCEPTION_SYSCALL_ERROR;
        }
        setThreadState(ksCurThread, ThreadState_Restart);
        return invokeCNodeCancelBadgedSends(destCap);
    }

    if (invLabel == CNodeRotate) {
        word_t pivotNewData, pivotIndex, pivotDepth;
        word_t srcNewData, srcIndex, srcDepth;
        cte_t *pivotSlot, *srcSlot;
        cap_t pivotRoot, srcRoot, newSrcCap, newPivotCap;

        if (length < 8 || excaps.excaprefs[0] == ((void *)0)
            || excaps.excaprefs[1] == ((void *)0)) {
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }
        pivotNewData = getSyscallArg(2, buffer);
        pivotIndex = getSyscallArg(3, buffer);
        pivotDepth = getSyscallArg(4, buffer);
        srcNewData = getSyscallArg(5, buffer);
        srcIndex = getSyscallArg(6, buffer);
        srcDepth = getSyscallArg(7, buffer);

        pivotRoot = excaps.excaprefs[0]->cap;
        srcRoot = excaps.excaprefs[1]->cap;

        lu_ret = lookupSourceSlot(srcRoot, srcIndex, srcDepth);
        if (lu_ret.status != EXCEPTION_NONE) {
            return lu_ret.status;
        }
        srcSlot = lu_ret.slot;

        lu_ret = lookupPivotSlot(pivotRoot, pivotIndex, pivotDepth);
        if (lu_ret.status != EXCEPTION_NONE) {
            return lu_ret.status;
        }
        pivotSlot = lu_ret.slot;

        if (pivotSlot == srcSlot || pivotSlot == destSlot) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode Rotate: Pivot slot the same as source or dest slot." ">>" "\033[0m" "\n", 0lu, __func__, 266, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (srcSlot != destSlot) {
            status = ensureEmptySlot(destSlot);
            if (status != EXCEPTION_NONE) {
                return status;
            }
        }

        if (cap_get_capType(srcSlot->cap) == cap_null_cap) {
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = 1;
            current_lookup_fault = lookup_fault_missing_capability_new(srcDepth);
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (cap_get_capType(pivotSlot->cap) == cap_null_cap) {
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = 0;
            current_lookup_fault = lookup_fault_missing_capability_new(pivotDepth);
            return EXCEPTION_SYSCALL_ERROR;
        }

        newSrcCap = updateCapData(true, srcNewData, srcSlot->cap);
        newPivotCap = updateCapData(true, pivotNewData, pivotSlot->cap);

        if (cap_get_capType(newSrcCap) == cap_null_cap) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode Rotate: Source cap invalid." ">>" "\033[0m" "\n", 0lu, __func__, 296, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (cap_get_capType(newPivotCap) == cap_null_cap) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode Rotate: Pivot cap invalid." ">>" "\033[0m" "\n", 0lu, __func__, 302, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksCurThread, ThreadState_Restart);
        return invokeCNodeRotate(newSrcCap, newPivotCap,
                                 srcSlot, pivotSlot, destSlot);
    }

    return EXCEPTION_NONE;
}

exception_t invokeCNodeRevoke(cte_t *destSlot)
{
    return cteRevoke(destSlot);
}

exception_t invokeCNodeDelete(cte_t *destSlot)
{
    return cteDelete(destSlot, true);
}

exception_t invokeCNodeCancelBadgedSends(cap_t cap)
{
    word_t badge = cap_endpoint_cap_get_capEPBadge(cap);
    if (badge) {
        endpoint_t *ep = (endpoint_t *)
                         cap_endpoint_cap_get_capEPPtr(cap);
        cancelBadgedSends(ep, badge);
    }
    return EXCEPTION_NONE;
}

exception_t invokeCNodeInsert(cap_t cap, cte_t *srcSlot, cte_t *destSlot)
{
    cteInsert(cap, srcSlot, destSlot);

    return EXCEPTION_NONE;
}

exception_t invokeCNodeMove(cap_t cap, cte_t *srcSlot, cte_t *destSlot)
{
    cteMove(cap, srcSlot, destSlot);

    return EXCEPTION_NONE;
}

exception_t invokeCNodeRotate(cap_t cap1, cap_t cap2, cte_t *slot1,
                              cte_t *slot2, cte_t *slot3)
{
    if (slot1 == slot3) {
        cteSwap(cap1, slot1, cap2, slot2);
    } else {
        cteMove(cap2, slot2, slot3);
        cteMove(cap1, slot1, slot2);
    }

    return EXCEPTION_NONE;
}


exception_t invokeCNodeSaveCaller(cte_t *destSlot)
{
    cap_t cap;
    cte_t *srcSlot;

    srcSlot = (((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbCaller));
    cap = srcSlot->cap;

    switch (cap_get_capType(cap)) {
    case cap_null_cap:
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "CNode SaveCaller: Reply cap not present." ">>" "\033[0m" "\n", 0lu, __func__, 374, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        break;

    case cap_reply_cap:
        if (!cap_reply_cap_get_capReplyMaster(cap)) {
            cteMove(cap, srcSlot, destSlot);
        }
        break;

    default:
        _fail("caller capability must be null or reply", "/host/kernel/src/object/cnode.c", 384, __func__);
        break;
    }

    return EXCEPTION_NONE;
}


/*
 * If creating a child UntypedCap, don't allow new objects to be created in the
 * parent.
 */
static void setUntypedCapAsFull(cap_t srcCap, cap_t newCap, cte_t *srcSlot)
{
    if ((cap_get_capType(srcCap) == cap_untyped_cap)
        && (cap_get_capType(newCap) == cap_untyped_cap)) {
        if ((cap_untyped_cap_get_capPtr(srcCap)
             == cap_untyped_cap_get_capPtr(newCap))
            && (cap_untyped_cap_get_capBlockSize(newCap)
                == cap_untyped_cap_get_capBlockSize(srcCap))) {
            cap_untyped_cap_ptr_set_capFreeIndex(&(srcSlot->cap),
                                                 ((1ul << ((cap_untyped_cap_get_capBlockSize(srcCap)) - 4))));
        }
    }
}

void cteInsert(cap_t newCap, cte_t *srcSlot, cte_t *destSlot)
{
    mdb_node_t srcMDB, newMDB;
    cap_t srcCap;
    bool_t newCapIsRevocable;

    srcMDB = srcSlot->cteMDBNode;
    srcCap = srcSlot->cap;

    newCapIsRevocable = isCapRevocable(newCap, srcCap);

    newMDB = mdb_node_set_mdbPrev(srcMDB, ((word_t)(srcSlot)));
    newMDB = mdb_node_set_mdbRevocable(newMDB, newCapIsRevocable);
    newMDB = mdb_node_set_mdbFirstBadged(newMDB, newCapIsRevocable);

    /* Haskell error: "cteInsert to non-empty destination" */
    if(!(cap_get_capType(destSlot->cap) == cap_null_cap)) _assert_fail("cap_get_capType(destSlot->cap) == cap_null_cap", "/host/kernel/src/object/cnode.c", 426, __FUNCTION__);
    /* Haskell error: "cteInsert: mdb entry must be empty" */
    if(!((cte_t *)mdb_node_get_mdbNext(destSlot->cteMDBNode) == ((void *)0) && (cte_t *)mdb_node_get_mdbPrev(destSlot->cteMDBNode) == ((void *)0))) _assert_fail("(cte_t *)mdb_node_get_mdbNext(destSlot->cteMDBNode) == NULL && (cte_t *)mdb_node_get_mdbPrev(destSlot->cteMDBNode) == NULL",
                                                                      "/host/kernel/src/object/cnode.c"
# 428 "/host/kernel/src/object/cnode.c"
    ,
                                                                      429
# 428 "/host/kernel/src/object/cnode.c"
    , __FUNCTION__)
                                                                       ;

    /* Prevent parent untyped cap from being used again if creating a child
     * untyped from it. */
    setUntypedCapAsFull(srcCap, newCap, srcSlot);

    destSlot->cap = newCap;
    destSlot->cteMDBNode = newMDB;
    mdb_node_ptr_set_mdbNext(&srcSlot->cteMDBNode, ((word_t)(destSlot)));
    if (mdb_node_get_mdbNext(newMDB)) {
        mdb_node_ptr_set_mdbPrev(
            &((cte_t *)(mdb_node_get_mdbNext(newMDB)))->cteMDBNode,
            ((word_t)(destSlot)));
    }
}

void cteMove(cap_t newCap, cte_t *srcSlot, cte_t *destSlot)
{
    mdb_node_t mdb;
    word_t prev_ptr, next_ptr;

    /* Haskell error: "cteMove to non-empty destination" */
    if(!(cap_get_capType(destSlot->cap) == cap_null_cap)) _assert_fail("cap_get_capType(destSlot->cap) == cap_null_cap", "/host/kernel/src/object/cnode.c", 451, __FUNCTION__);
    /* Haskell error: "cteMove: mdb entry must be empty" */
    if(!((cte_t *)mdb_node_get_mdbNext(destSlot->cteMDBNode) == ((void *)0) && (cte_t *)mdb_node_get_mdbPrev(destSlot->cteMDBNode) == ((void *)0))) _assert_fail("(cte_t *)mdb_node_get_mdbNext(destSlot->cteMDBNode) == NULL && (cte_t *)mdb_node_get_mdbPrev(destSlot->cteMDBNode) == NULL",
                                                                      "/host/kernel/src/object/cnode.c"
# 453 "/host/kernel/src/object/cnode.c"
    ,
                                                                      454
# 453 "/host/kernel/src/object/cnode.c"
    , __FUNCTION__)
                                                                       ;

    mdb = srcSlot->cteMDBNode;
    destSlot->cap = newCap;
    srcSlot->cap = cap_null_cap_new();
    destSlot->cteMDBNode = mdb;
    srcSlot->cteMDBNode = mdb_node_new(0, false, false, 0);

    prev_ptr = mdb_node_get_mdbPrev(mdb);
    if (prev_ptr)
        mdb_node_ptr_set_mdbNext(
            &((cte_t *)(prev_ptr))->cteMDBNode,
            ((word_t)(destSlot)));

    next_ptr = mdb_node_get_mdbNext(mdb);
    if (next_ptr)
        mdb_node_ptr_set_mdbPrev(
            &((cte_t *)(next_ptr))->cteMDBNode,
            ((word_t)(destSlot)));
}

void capSwapForDelete(cte_t *slot1, cte_t *slot2)
{
    cap_t cap1, cap2;

    if (slot1 == slot2) {
        return;
    }

    cap1 = slot1->cap;
    cap2 = slot2->cap;

    cteSwap(cap1, slot1, cap2, slot2);
}

void cteSwap(cap_t cap1, cte_t *slot1, cap_t cap2, cte_t *slot2)
{
    mdb_node_t mdb1, mdb2;
    word_t next_ptr, prev_ptr;

    slot1->cap = cap2;
    slot2->cap = cap1;

    mdb1 = slot1->cteMDBNode;

    prev_ptr = mdb_node_get_mdbPrev(mdb1);
    if (prev_ptr)
        mdb_node_ptr_set_mdbNext(
            &((cte_t *)(prev_ptr))->cteMDBNode,
            ((word_t)(slot2)));

    next_ptr = mdb_node_get_mdbNext(mdb1);
    if (next_ptr)
        mdb_node_ptr_set_mdbPrev(
            &((cte_t *)(next_ptr))->cteMDBNode,
            ((word_t)(slot2)));

    mdb2 = slot2->cteMDBNode;
    slot1->cteMDBNode = mdb2;
    slot2->cteMDBNode = mdb1;

    prev_ptr = mdb_node_get_mdbPrev(mdb2);
    if (prev_ptr)
        mdb_node_ptr_set_mdbNext(
            &((cte_t *)(prev_ptr))->cteMDBNode,
            ((word_t)(slot1)));

    next_ptr = mdb_node_get_mdbNext(mdb2);
    if (next_ptr)
        mdb_node_ptr_set_mdbPrev(
            &((cte_t *)(next_ptr))->cteMDBNode,
            ((word_t)(slot1)));
}

exception_t cteRevoke(cte_t *slot)
{
    cte_t *nextPtr;
    exception_t status;

    /* there is no need to check for a NullCap as NullCaps are
       always accompanied by null mdb pointers */
    for (nextPtr = ((cte_t *)(mdb_node_get_mdbNext(slot->cteMDBNode)));
         nextPtr && isMDBParentOf(slot, nextPtr);
         nextPtr = ((cte_t *)(mdb_node_get_mdbNext(slot->cteMDBNode)))) {
        status = cteDelete(nextPtr, true);
        if (status != EXCEPTION_NONE) {
            return status;
        }

        status = preemptionPoint();
        if (status != EXCEPTION_NONE) {
            return status;
        }
    }

    return EXCEPTION_NONE;
}

exception_t cteDelete(cte_t *slot, bool_t exposed)
{
    finaliseSlot_ret_t fs_ret;

    fs_ret = finaliseSlot(slot, exposed);
    if (fs_ret.status != EXCEPTION_NONE) {
        return fs_ret.status;
    }

    if (exposed || fs_ret.success) {
        emptySlot(slot, fs_ret.cleanupInfo);
    }
    return EXCEPTION_NONE;
}

static void emptySlot(cte_t *slot, cap_t cleanupInfo)
{
    if (cap_get_capType(slot->cap) != cap_null_cap) {
        mdb_node_t mdbNode;
        cte_t *prev, *next;

        mdbNode = slot->cteMDBNode;
        prev = ((cte_t *)(mdb_node_get_mdbPrev(mdbNode)));
        next = ((cte_t *)(mdb_node_get_mdbNext(mdbNode)));

        if (prev) {
            mdb_node_ptr_set_mdbNext(&prev->cteMDBNode, ((word_t)(next)));
        }
        if (next) {
            mdb_node_ptr_set_mdbPrev(&next->cteMDBNode, ((word_t)(prev)));
        }
        if (next)
            mdb_node_ptr_set_mdbFirstBadged(&next->cteMDBNode,
                                            mdb_node_get_mdbFirstBadged(next->cteMDBNode) ||
                                            mdb_node_get_mdbFirstBadged(mdbNode));
        slot->cap = cap_null_cap_new();
        slot->cteMDBNode = mdb_node_new(0, false, false, 0);

        postCapDeletion(cleanupInfo);
    }
}

static inline bool_t __attribute__((__const__)) capRemovable(cap_t cap, cte_t *slot)
{
    switch (cap_get_capType(cap)) {
    case cap_null_cap:
        return true;
    case cap_zombie_cap: {
        word_t n = cap_zombie_cap_get_capZombieNumber(cap);
        cte_t *z_slot = (cte_t *)cap_zombie_cap_get_capZombiePtr(cap);
        return (n == 0 || (n == 1 && slot == z_slot));
    }
    default:
        _fail("finaliseCap should only return Zombie or NullCap", "/host/kernel/src/object/cnode.c", 605, __func__);
    }
}

static inline bool_t __attribute__((__const__)) capCyclicZombie(cap_t cap, cte_t *slot)
{
    return cap_get_capType(cap) == cap_zombie_cap &&
           ((cte_t *)(cap_zombie_cap_get_capZombiePtr(cap))) == slot;
}

static finaliseSlot_ret_t finaliseSlot(cte_t *slot, bool_t immediate)
{
    bool_t final;
    finaliseCap_ret_t fc_ret;
    exception_t status;
    finaliseSlot_ret_t ret;

    while (cap_get_capType(slot->cap) != cap_null_cap) {
        final = isFinalCapability(slot);
        fc_ret = finaliseCap(slot->cap, final, false);

        if (capRemovable(fc_ret.remainder, slot)) {
            ret.status = EXCEPTION_NONE;
            ret.success = true;
            ret.cleanupInfo = fc_ret.cleanupInfo;
            return ret;
        }

        slot->cap = fc_ret.remainder;

        if (!immediate && capCyclicZombie(fc_ret.remainder, slot)) {
            ret.status = EXCEPTION_NONE;
            ret.success = false;
            ret.cleanupInfo = fc_ret.cleanupInfo;
            return ret;
        }

        status = reduceZombie(slot, immediate);
        if (status != EXCEPTION_NONE) {
            ret.status = status;
            ret.success = false;
            ret.cleanupInfo = cap_null_cap_new();
            return ret;
        }

        status = preemptionPoint();
        if (status != EXCEPTION_NONE) {
            ret.status = status;
            ret.success = false;
            ret.cleanupInfo = cap_null_cap_new();
            return ret;
        }
    }
    ret.status = EXCEPTION_NONE;
    ret.success = true;
    ret.cleanupInfo = cap_null_cap_new();
    return ret;
}

static exception_t reduceZombie(cte_t *slot, bool_t immediate)
{
    cte_t *ptr;
    word_t n, type;
    exception_t status;

    if(!(cap_get_capType(slot->cap) == cap_zombie_cap)) _assert_fail("cap_get_capType(slot->cap) == cap_zombie_cap", "/host/kernel/src/object/cnode.c", 670, __FUNCTION__);
    ptr = (cte_t *)cap_zombie_cap_get_capZombiePtr(slot->cap);
    n = cap_zombie_cap_get_capZombieNumber(slot->cap);
    type = cap_zombie_cap_get_capZombieType(slot->cap);

    /* Haskell error: "reduceZombie: expected unremovable zombie" */
    if(!(n > 0)) _assert_fail("n > 0", "/host/kernel/src/object/cnode.c", 676, __FUNCTION__);

    if (immediate) {
        cte_t *endSlot = &ptr[n - 1];

        status = cteDelete(endSlot, false);
        if (status != EXCEPTION_NONE) {
            return status;
        }

        switch (cap_get_capType(slot->cap)) {
        case cap_null_cap:
            break;

        case cap_zombie_cap: {
            cte_t *ptr2 =
                (cte_t *)cap_zombie_cap_get_capZombiePtr(slot->cap);

            if (ptr == ptr2 &&
                cap_zombie_cap_get_capZombieNumber(slot->cap) == n &&
                cap_zombie_cap_get_capZombieType(slot->cap) == type) {
                if(!(cap_get_capType(endSlot->cap) == cap_null_cap)) _assert_fail("cap_get_capType(endSlot->cap) == cap_null_cap", "/host/kernel/src/object/cnode.c", 697, __FUNCTION__);
                slot->cap =
                    cap_zombie_cap_set_capZombieNumber(slot->cap, n - 1);
            } else {
                /* Haskell error:
                 * "Expected new Zombie to be self-referential."
                 */
                if(!(ptr2 == slot && ptr != slot)) _assert_fail("ptr2 == slot && ptr != slot", "/host/kernel/src/object/cnode.c", 704, __FUNCTION__);
            }
            break;
        }

        default:
            _fail("Expected recursion to result in Zombie.", "/host/kernel/src/object/cnode.c", 710, __func__);
        }
    } else {
        /* Haskell error: "Cyclic zombie passed to unexposed reduceZombie" */
        if(!(ptr != slot)) _assert_fail("ptr != slot", "/host/kernel/src/object/cnode.c", 714, __FUNCTION__);

        if (cap_get_capType(ptr->cap) == cap_zombie_cap) {
            /* Haskell error: "Moving self-referential Zombie aside." */
            if(!(ptr != ((cte_t *)(cap_zombie_cap_get_capZombiePtr(ptr->cap))))) _assert_fail("ptr != CTE_PTR(cap_zombie_cap_get_capZombiePtr(ptr->cap))", "/host/kernel/src/object/cnode.c", 718, __FUNCTION__);
        }

        capSwapForDelete(ptr, slot);
    }
    return EXCEPTION_NONE;
}

void cteDeleteOne(cte_t *slot)
{
    word_t cap_type = cap_get_capType(slot->cap);
    if (cap_type != cap_null_cap) {
        bool_t final;
        finaliseCap_ret_t fc_ret __attribute__((unused));

        /** GHOSTUPD: "(gs_get_assn cteDeleteOne_'proc \<acute>ghost'state = (-1)
            \<or> gs_get_assn cteDeleteOne_'proc \<acute>ghost'state = \<acute>cap_type, id)" */

        final = isFinalCapability(slot);
        fc_ret = finaliseCap(slot->cap, final, true);
        /* Haskell error: "cteDeleteOne: cap should be removable" */
        if(!(capRemovable(fc_ret.remainder, slot) && cap_get_capType(fc_ret.cleanupInfo) == cap_null_cap)) _assert_fail("capRemovable(fc_ret.remainder, slot) && cap_get_capType(fc_ret.cleanupInfo) == cap_null_cap",
                                                                  "/host/kernel/src/object/cnode.c"
# 739 "/host/kernel/src/object/cnode.c"
        ,
                                                                  740
# 739 "/host/kernel/src/object/cnode.c"
        , __FUNCTION__)
                                                                   ;
        emptySlot(slot, cap_null_cap_new());
    }
}

void insertNewCap(cte_t *parent, cte_t *slot, cap_t cap)
{
    cte_t *next;

    next = ((cte_t *)(mdb_node_get_mdbNext(parent->cteMDBNode)));
    slot->cap = cap;
    slot->cteMDBNode = mdb_node_new(((word_t)(next)), true, true, ((word_t)(parent)));
    if (next) {
        mdb_node_ptr_set_mdbPrev(&next->cteMDBNode, ((word_t)(slot)));
    }
    mdb_node_ptr_set_mdbNext(&parent->cteMDBNode, ((word_t)(slot)));
}


void setupReplyMaster(tcb_t *thread)
{
    cte_t *slot;

    slot = (((cte_t *)((word_t)(thread)&~((1ul << (11))-1ul)))+(tcbReply));
    if (cap_get_capType(slot->cap) == cap_null_cap) {
        /* Haskell asserts that no reply caps exist for this thread here. This
         * cannot be translated. */
        slot->cap = cap_reply_cap_new(true, true, ((word_t)(thread)));
        slot->cteMDBNode = mdb_node_new(0, false, false, 0);
        mdb_node_ptr_set_mdbRevocable(&slot->cteMDBNode, true);
        mdb_node_ptr_set_mdbFirstBadged(&slot->cteMDBNode, true);
    }
}


bool_t __attribute__((__pure__)) isMDBParentOf(cte_t *cte_a, cte_t *cte_b)
{
    if (!mdb_node_get_mdbRevocable(cte_a->cteMDBNode)) {
        return false;
    }
    if (!sameRegionAs(cte_a->cap, cte_b->cap)) {
        return false;
    }
    switch (cap_get_capType(cte_a->cap)) {
    case cap_endpoint_cap: {
        word_t badge;

        badge = cap_endpoint_cap_get_capEPBadge(cte_a->cap);
        if (badge == 0) {
            return true;
        }
        return (badge == cap_endpoint_cap_get_capEPBadge(cte_b->cap)) &&
               !mdb_node_get_mdbFirstBadged(cte_b->cteMDBNode);
        break;
    }

    case cap_notification_cap: {
        word_t badge;

        badge = cap_notification_cap_get_capNtfnBadge(cte_a->cap);
        if (badge == 0) {
            return true;
        }
        return
            (badge == cap_notification_cap_get_capNtfnBadge(cte_b->cap)) &&
            !mdb_node_get_mdbFirstBadged(cte_b->cteMDBNode);
        break;
    }

    default:
        return true;
        break;
    }
}

exception_t ensureNoChildren(cte_t *slot)
{
    if (mdb_node_get_mdbNext(slot->cteMDBNode) != 0) {
        cte_t *next;

        next = ((cte_t *)(mdb_node_get_mdbNext(slot->cteMDBNode)));
        if (isMDBParentOf(slot, next)) {
            current_syscall_error.type = seL4_RevokeFirst;
            return EXCEPTION_SYSCALL_ERROR;
        }
    }

    return EXCEPTION_NONE;
}

exception_t ensureEmptySlot(cte_t *slot)
{
    if (cap_get_capType(slot->cap) != cap_null_cap) {
        current_syscall_error.type = seL4_DeleteFirst;
        return EXCEPTION_SYSCALL_ERROR;
    }

    return EXCEPTION_NONE;
}

bool_t __attribute__((__pure__)) isFinalCapability(cte_t *cte)
{
    mdb_node_t mdb;
    bool_t prevIsSameObject;

    mdb = cte->cteMDBNode;

    if (mdb_node_get_mdbPrev(mdb) == 0) {
        prevIsSameObject = false;
    } else {
        cte_t *prev;

        prev = ((cte_t *)(mdb_node_get_mdbPrev(mdb)));
        prevIsSameObject = sameObjectAs(prev->cap, cte->cap);
    }

    if (prevIsSameObject) {
        return false;
    } else {
        if (mdb_node_get_mdbNext(mdb) == 0) {
            return true;
        } else {
            cte_t *next;

            next = ((cte_t *)(mdb_node_get_mdbNext(mdb)));
            return !sameObjectAs(cte->cap, next->cap);
        }
    }
}

bool_t __attribute__((__pure__)) slotCapLongRunningDelete(cte_t *slot)
{
    if (cap_get_capType(slot->cap) == cap_null_cap) {
        return false;
    } else if (! isFinalCapability(slot)) {
        return false;
    }
    switch (cap_get_capType(slot->cap)) {
    case cap_thread_cap:
    case cap_zombie_cap:
    case cap_cnode_cap:
        return true;
    default:
        return false;
    }
}

/* This implementation is specialised to the (current) limit
 * of one cap receive slot. */
cte_t *getReceiveSlots(tcb_t *thread, word_t *buffer)
{
    cap_transfer_t ct;
    cptr_t cptr;
    lookupCap_ret_t luc_ret;
    lookupSlot_ret_t lus_ret;
    cte_t *slot;
    cap_t cnode;

    if (!buffer) {
        return ((void *)0);
    }

    ct = loadCapTransfer(buffer);
    cptr = ct.ctReceiveRoot;

    luc_ret = lookupCap(thread, cptr);
    if (luc_ret.status != EXCEPTION_NONE) {
        return ((void *)0);
    }
    cnode = luc_ret.cap;

    lus_ret = lookupTargetSlot(cnode, ct.ctReceiveIndex, ct.ctReceiveDepth);
    if (lus_ret.status != EXCEPTION_NONE) {
        return ((void *)0);
    }
    slot = lus_ret.slot;

    if (cap_get_capType(slot->cap) != cap_null_cap) {
        return ((void *)0);
    }

    return slot;
}

cap_transfer_t __attribute__((__pure__)) loadCapTransfer(word_t *buffer)
{
    const int offset = seL4_MsgMaxLength + ((1ul<<(seL4_MsgExtraCapBits))-1) + 2;
    return capTransferFromWords(buffer + offset);
}
# 1 "/host/kernel/src/object/endpoint.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 19 "/host/kernel/src/object/endpoint.c"
static inline void ep_ptr_set_queue(endpoint_t *epptr, tcb_queue_t queue)
{
    endpoint_ptr_set_epQueue_head(epptr, (word_t)queue.head);
    endpoint_ptr_set_epQueue_tail(epptr, (word_t)queue.end);
}





void sendIPC(bool_t blocking, bool_t do_call, word_t badge,
             bool_t canGrant, bool_t canGrantReply, tcb_t *thread, endpoint_t *epptr)

{
    switch (endpoint_ptr_get_state(epptr)) {
    case EPState_Idle:
    case EPState_Send:
        if (blocking) {
            tcb_queue_t queue;

            /* Set thread state to BlockedOnSend */
            thread_state_ptr_set_tsType(&thread->tcbState,
                                        ThreadState_BlockedOnSend);
            thread_state_ptr_set_blockingObject(
                &thread->tcbState, ((word_t)(epptr)));
            thread_state_ptr_set_blockingIPCBadge(
                &thread->tcbState, badge);
            thread_state_ptr_set_blockingIPCCanGrant(
                &thread->tcbState, canGrant);
            thread_state_ptr_set_blockingIPCCanGrantReply(
                &thread->tcbState, canGrantReply);
            thread_state_ptr_set_blockingIPCIsCall(
                &thread->tcbState, do_call);

            scheduleTCB(thread);

            /* Place calling thread in endpoint queue */
            queue = ep_ptr_get_queue(epptr);
            queue = tcbEPAppend(thread, queue);
            endpoint_ptr_set_state(epptr, EPState_Send);
            ep_ptr_set_queue(epptr, queue);
        }
        break;

    case EPState_Recv: {
        tcb_queue_t queue;
        tcb_t *dest;

        /* Get the head of the endpoint queue. */
        queue = ep_ptr_get_queue(epptr);
        dest = queue.head;

        /* Haskell error "Receive endpoint queue must not be empty" */
        if(!(dest)) _assert_fail("dest", "/host/kernel/src/object/endpoint.c", 72, __FUNCTION__);

        /* Dequeue the first TCB */
        queue = tcbEPDequeue(dest, queue);
        ep_ptr_set_queue(epptr, queue);

        if (!queue.head) {
            endpoint_ptr_set_state(epptr, EPState_Idle);
        }

        /* Do the transfer */
        doIPCTransfer(thread, epptr, badge, canGrant, dest);
# 108 "/host/kernel/src/object/endpoint.c"
        bool_t replyCanGrant = thread_state_ptr_get_blockingIPCCanGrant(&dest->tcbState);;

        setThreadState(dest, ThreadState_Running);
        possibleSwitchTo(dest);

        if (do_call) {
            if (canGrant || canGrantReply) {
                setupCallerCap(thread, dest, replyCanGrant);
            } else {
                setThreadState(thread, ThreadState_Inactive);
            }
        }

        break;
    }
    }
}




void receiveIPC(tcb_t *thread, cap_t cap, bool_t isBlocking)

{
    endpoint_t *epptr;
    notification_t *ntfnPtr;

    /* Haskell error "receiveIPC: invalid cap" */
    if(!(cap_get_capType(cap) == cap_endpoint_cap)) _assert_fail("cap_get_capType(cap) == cap_endpoint_cap", "/host/kernel/src/object/endpoint.c", 136, __FUNCTION__);

    epptr = ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(cap)));
# 151 "/host/kernel/src/object/endpoint.c"
    /* Check for anything waiting in the notification */
    ntfnPtr = thread->tcbBoundNotification;
    if (ntfnPtr && notification_ptr_get_state(ntfnPtr) == NtfnState_Active) {
        completeSignal(ntfnPtr, thread);
    } else {
# 166 "/host/kernel/src/object/endpoint.c"
        switch (endpoint_ptr_get_state(epptr)) {
        case EPState_Idle:
        case EPState_Recv: {
            tcb_queue_t queue;

            if (isBlocking) {
                /* Set thread state to BlockedOnReceive */
                thread_state_ptr_set_tsType(&thread->tcbState,
                                            ThreadState_BlockedOnReceive);
                thread_state_ptr_set_blockingObject(
                    &thread->tcbState, ((word_t)(epptr)));






                thread_state_ptr_set_blockingIPCCanGrant(
                    &thread->tcbState, cap_endpoint_cap_get_capCanGrant(cap));

                scheduleTCB(thread);

                /* Place calling thread in endpoint queue */
                queue = ep_ptr_get_queue(epptr);
                queue = tcbEPAppend(thread, queue);
                endpoint_ptr_set_state(epptr, EPState_Recv);
                ep_ptr_set_queue(epptr, queue);
            } else {
                doNBRecvFailedTransfer(thread);
            }
            break;
        }

        case EPState_Send: {
            tcb_queue_t queue;
            tcb_t *sender;
            word_t badge;
            bool_t canGrant;
            bool_t canGrantReply;
            bool_t do_call;

            /* Get the head of the endpoint queue. */
            queue = ep_ptr_get_queue(epptr);
            sender = queue.head;

            /* Haskell error "Send endpoint queue must not be empty" */
            if(!(sender)) _assert_fail("sender", "/host/kernel/src/object/endpoint.c", 212, __FUNCTION__);

            /* Dequeue the first TCB */
            queue = tcbEPDequeue(sender, queue);
            ep_ptr_set_queue(epptr, queue);

            if (!queue.head) {
                endpoint_ptr_set_state(epptr, EPState_Idle);
            }

            /* Get sender IPC details */
            badge = thread_state_ptr_get_blockingIPCBadge(&sender->tcbState);
            canGrant =
                thread_state_ptr_get_blockingIPCCanGrant(&sender->tcbState);
            canGrantReply =
                thread_state_ptr_get_blockingIPCCanGrantReply(&sender->tcbState);

            /* Do the transfer */
            doIPCTransfer(sender, epptr, badge,
                          canGrant, thread);

            do_call = thread_state_ptr_get_blockingIPCIsCall(&sender->tcbState);
# 251 "/host/kernel/src/object/endpoint.c"
            if (do_call) {
                if (canGrant || canGrantReply) {
                    setupCallerCap(sender, thread, cap_endpoint_cap_get_capCanGrant(cap));
                } else {
                    setThreadState(sender, ThreadState_Inactive);
                }
            } else {
                setThreadState(sender, ThreadState_Running);
                possibleSwitchTo(sender);
            }

            break;
        }
        }
    }
}

void replyFromKernel_error(tcb_t *thread)
{
    word_t len;
    word_t *ipcBuffer;

    ipcBuffer = lookupIPCBuffer(true, thread);
    setRegister(thread, badgeRegister, 0);
    len = setMRs_syscall_error(thread, ipcBuffer);
# 285 "/host/kernel/src/object/endpoint.c"
    setRegister(thread, msgInfoRegister, wordFromMessageInfo(
                    seL4_MessageInfo_new(current_syscall_error.type, 0, 0, len)));
}

void replyFromKernel_success_empty(tcb_t *thread)
{
    setRegister(thread, badgeRegister, 0);
    setRegister(thread, msgInfoRegister, wordFromMessageInfo(
                    seL4_MessageInfo_new(0, 0, 0, 0)));
}

void cancelIPC(tcb_t *tptr)
{
    thread_state_t *state = &tptr->tcbState;






    switch (thread_state_ptr_get_tsType(state)) {
    case ThreadState_BlockedOnSend:
    case ThreadState_BlockedOnReceive: {
        /* blockedIPCCancel state */
        endpoint_t *epptr;
        tcb_queue_t queue;

        epptr = ((endpoint_t *)(thread_state_ptr_get_blockingObject(state)));

        /* Haskell error "blockedIPCCancel: endpoint must not be idle" */
        if(!(endpoint_ptr_get_state(epptr) != EPState_Idle)) _assert_fail("endpoint_ptr_get_state(epptr) != EPState_Idle", "/host/kernel/src/object/endpoint.c", 315, __FUNCTION__);

        /* Dequeue TCB */
        queue = ep_ptr_get_queue(epptr);
        queue = tcbEPDequeue(tptr, queue);
        ep_ptr_set_queue(epptr, queue);

        if (!queue.head) {
            endpoint_ptr_set_state(epptr, EPState_Idle);
        }







        setThreadState(tptr, ThreadState_Inactive);
        break;
    }

    case ThreadState_BlockedOnNotification:
        cancelSignal(tptr,
                     ((notification_t *)(thread_state_ptr_get_blockingObject(state))));
        break;

    case ThreadState_BlockedOnReply: {



        cte_t *slot, *callerCap;

        tptr->tcbFault = seL4_Fault_NullFault_new();

        /* Get the reply cap slot */
        slot = (((cte_t *)((word_t)(tptr)&~((1ul << (11))-1ul)))+(tcbReply));

        callerCap = ((cte_t *)(mdb_node_get_mdbNext(slot->cteMDBNode)));
        if (callerCap) {
            /** GHOSTUPD: "(True,
                gs_set_assn cteDeleteOne_'proc (ucast cap_reply_cap))" */
            cteDeleteOne(callerCap);
        }


        break;
    }
    }
}

void cancelAllIPC(endpoint_t *epptr)
{
    switch (endpoint_ptr_get_state(epptr)) {
    case EPState_Idle:
        break;

    default: {
        tcb_t *thread = ((tcb_t *)(endpoint_ptr_get_epQueue_head(epptr)));

        /* Make endpoint idle */
        endpoint_ptr_set_state(epptr, EPState_Idle);
        endpoint_ptr_set_epQueue_head(epptr, 0);
        endpoint_ptr_set_epQueue_tail(epptr, 0);

        /* Set all blocked threads to restart */
        for (; thread; thread = thread->tcbEPNext) {
# 393 "/host/kernel/src/object/endpoint.c"
            setThreadState(thread, ThreadState_Restart);
            tcbSchedEnqueue(thread);

        }

        rescheduleRequired();
        break;
    }
    }
}

void cancelBadgedSends(endpoint_t *epptr, word_t badge)
{
    switch (endpoint_ptr_get_state(epptr)) {
    case EPState_Idle:
    case EPState_Recv:
        break;

    case EPState_Send: {
        tcb_t *thread, *next;
        tcb_queue_t queue = ep_ptr_get_queue(epptr);

        /* this is a de-optimisation for verification
         * reasons. it allows the contents of the endpoint
         * queue to be ignored during the for loop. */
        endpoint_ptr_set_state(epptr, EPState_Idle);
        endpoint_ptr_set_epQueue_head(epptr, 0);
        endpoint_ptr_set_epQueue_tail(epptr, 0);

        for (thread = queue.head; thread; thread = next) {
            word_t b = thread_state_ptr_get_blockingIPCBadge(
                           &thread->tcbState);
            next = thread->tcbEPNext;
# 440 "/host/kernel/src/object/endpoint.c"
            if (b == badge) {
                setThreadState(thread, ThreadState_Restart);
                tcbSchedEnqueue(thread);
                queue = tcbEPDequeue(thread, queue);
            }

        }
        ep_ptr_set_queue(epptr, queue);

        if (queue.head) {
            endpoint_ptr_set_state(epptr, EPState_Send);
        }

        rescheduleRequired();

        break;
    }

    default:
        _fail("invalid EP state", "/host/kernel/src/object/endpoint.c", 459, __func__);
    }
}
# 1 "/host/kernel/src/object/interrupt.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




# 1 "kernel/gen_headers/api/invocation.h" 1

/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 ** SPDX-License-Identifier: GPL-2.0-only
 */

/* This header was generated by kernel/tools/invocation_header_gen.py.
 *
 * To add an invocation call number, edit libsel4/include/interfaces/sel4.xml.
 *
 */
# 11 "/host/kernel/src/object/interrupt.c" 2
# 23 "/host/kernel/src/object/interrupt.c"
exception_t decodeIRQControlInvocation(word_t invLabel, word_t length,
                                       cte_t *srcSlot, extra_caps_t excaps,
                                       word_t *buffer)
{
    if (invLabel == IRQIssueIRQHandler) {
        word_t index, depth, irq_w;
        irq_t irq;
        cte_t *destSlot;
        cap_t cnodeCap;
        lookupSlot_ret_t lu_ret;
        exception_t status;

        if (length < 3 || excaps.excaprefs[0] == ((void *)0)) {
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }
        irq_w = getSyscallArg(0, buffer);
        irq = (irq_w);
        index = getSyscallArg(1, buffer);
        depth = getSyscallArg(2, buffer);

        cnodeCap = excaps.excaprefs[0]->cap;

        status = Arch_checkIRQ(irq_w);
        if (status != EXCEPTION_NONE) {
            return status;
        }

        if (isIRQActive(irq)) {
            current_syscall_error.type = seL4_RevokeFirst;
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Rejecting request for IRQ %u. Already active." ">>" "\033[0m" "\n", 0lu, __func__, 53, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (int)(irq)); } while (0);
            return EXCEPTION_SYSCALL_ERROR;
        }

        lu_ret = lookupTargetSlot(cnodeCap, index, depth);
        if (lu_ret.status != EXCEPTION_NONE) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Target slot for new IRQ Handler cap invalid: cap %lu, IRQ %u." ">>" "\033[0m" "\n", 0lu, __func__, 60, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), getExtraCPtr(buffer, 0), (int)(irq)); } while (0)
                                                                     ;
            return lu_ret.status;
        }
        destSlot = lu_ret.slot;

        status = ensureEmptySlot(destSlot);
        if (status != EXCEPTION_NONE) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Target slot for new IRQ Handler cap not empty: cap %lu, IRQ %u." ">>" "\033[0m" "\n", 0lu, __func__, 68, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), getExtraCPtr(buffer, 0), (int)(irq)); } while (0)
                                                                     ;
            return status;
        }

        setThreadState(ksCurThread, ThreadState_Restart);
        return invokeIRQControl(irq, destSlot, srcSlot);
    } else {
        return Arch_decodeIRQControlInvocation(invLabel, length, srcSlot, excaps, buffer);
    }
}

exception_t invokeIRQControl(irq_t irq, cte_t *handlerSlot, cte_t *controlSlot)
{
    setIRQState(IRQSignal, irq);
    cteInsert(cap_irq_handler_cap_new((irq)), controlSlot, handlerSlot);

    return EXCEPTION_NONE;
}

exception_t decodeIRQHandlerInvocation(word_t invLabel, irq_t irq,
                                       extra_caps_t excaps)
{
    switch (invLabel) {
    case IRQAckIRQ:
        setThreadState(ksCurThread, ThreadState_Restart);
        invokeIRQHandler_AckIRQ(irq);
        return EXCEPTION_NONE;

    case IRQSetIRQHandler: {
        cap_t ntfnCap;
        cte_t *slot;

        if (excaps.excaprefs[0] == ((void *)0)) {
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }
        ntfnCap = excaps.excaprefs[0]->cap;
        slot = excaps.excaprefs[0];

        if (cap_get_capType(ntfnCap) != cap_notification_cap ||
            !cap_notification_cap_get_capNtfnCanSend(ntfnCap)) {
            if (cap_get_capType(ntfnCap) != cap_notification_cap) {
                do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IRQSetHandler: provided cap is not an notification capability." ">>" "\033[0m" "\n", 0lu, __func__, 110, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            } else {
                do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IRQSetHandler: caller does not have send rights on the endpoint." ">>" "\033[0m" "\n", 0lu, __func__, 112, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            }
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 0;
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksCurThread, ThreadState_Restart);
        invokeIRQHandler_SetIRQHandler(irq, ntfnCap, slot);
        return EXCEPTION_NONE;
    }

    case IRQClearIRQHandler:
        setThreadState(ksCurThread, ThreadState_Restart);
        invokeIRQHandler_ClearIRQHandler(irq);
        return EXCEPTION_NONE;

    default:
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "IRQHandler: Illegal operation." ">>" "\033[0m" "\n", 0lu, __func__, 130, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
}

void invokeIRQHandler_AckIRQ(irq_t irq)
{
# 147 "/host/kernel/src/object/interrupt.c"
    maskInterrupt(false, irq);

}

void invokeIRQHandler_SetIRQHandler(irq_t irq, cap_t cap, cte_t *slot)
{
    cte_t *irqSlot;

    irqSlot = intStateIRQNode + (irq);
    /** GHOSTUPD: "(True, gs_set_assn cteDeleteOne_'proc (-1))" */
    cteDeleteOne(irqSlot);
    cteInsert(cap, slot, irqSlot);
}

void invokeIRQHandler_ClearIRQHandler(irq_t irq)
{
    cte_t *irqSlot;

    irqSlot = intStateIRQNode + (irq);
    /** GHOSTUPD: "(True, gs_set_assn cteDeleteOne_'proc (-1))" */
    cteDeleteOne(irqSlot);
}

void deletingIRQHandler(irq_t irq)
{
    cte_t *slot;

    slot = intStateIRQNode + (irq);
    /** GHOSTUPD: "(True, gs_set_assn cteDeleteOne_'proc (ucast cap_notification_cap))" */
    cteDeleteOne(slot);
}

void deletedIRQHandler(irq_t irq)
{
    setIRQState(IRQInactive, irq);
}

void handleInterrupt(irq_t irq)
{
    if (__builtin_expect(!!((irq) > maxIRQ), 0)) {
        /* mask, ack and pretend it didn't happen. We assume that because
         * the interrupt controller for the platform returned this IRQ that
         * it is safe to use in mask and ack operations, even though it is
         * above the claimed maxIRQ. i.e. we're assuming maxIRQ is wrong */
        kprintf("Received IRQ %d, which is above the platforms maxIRQ of %d\n", (int)(irq), (int)maxIRQ);
        maskInterrupt(true, irq);
        ackInterrupt(irq);
        return;
    }
    switch (intStateIRQTable[(irq)]) {
    case IRQSignal: {
        cap_t cap;

        cap = intStateIRQNode[(irq)].cap;

        if (cap_get_capType(cap) == cap_notification_cap &&
            cap_notification_cap_get_capNtfnCanSend(cap)) {
            sendSignal(((notification_t *)(cap_notification_cap_get_capNtfnPtr(cap))),
                       cap_notification_cap_get_capNtfnBadge(cap));
        } else {

            kprintf("Undelivered IRQ: %d\n", (int)(irq));

        }

        maskInterrupt(true, irq);

        break;
    }

    case IRQTimer:




        timerTick();
        resetTimer();

        break;







    case IRQReserved:
        handleReservedIRQ(irq);
        break;

    case IRQInactive:
        /*
         * This case shouldn't happen anyway unless the hardware or
         * platform code is broken. Hopefully masking it again should make
         * the interrupt go away.
         */
        maskInterrupt(true, irq);

        kprintf("Received disabled IRQ: %d\n", (int)(irq));

        break;

    default:
        /* No corresponding haskell error */
        _fail("Invalid IRQ state", "/host/kernel/src/object/interrupt.c", 251, __func__);
    }

    ackInterrupt(irq);
}

bool_t isIRQActive(irq_t irq)
{
    return intStateIRQTable[(irq)] != IRQInactive;
}

void setIRQState(irq_state_t irqState, irq_t irq)
{
    intStateIRQTable[(irq)] = irqState;






    maskInterrupt(irqState == IRQInactive, irq);
}
# 1 "/host/kernel/src/object/notification.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 19 "/host/kernel/src/object/notification.c"
static inline tcb_queue_t __attribute__((__pure__)) ntfn_ptr_get_queue(notification_t *ntfnPtr)
{
    tcb_queue_t ntfn_queue;

    ntfn_queue.head = (tcb_t *)notification_ptr_get_ntfnQueue_head(ntfnPtr);
    ntfn_queue.end = (tcb_t *)notification_ptr_get_ntfnQueue_tail(ntfnPtr);

    return ntfn_queue;
}

static inline void ntfn_ptr_set_queue(notification_t *ntfnPtr, tcb_queue_t ntfn_queue)
{
    notification_ptr_set_ntfnQueue_head(ntfnPtr, (word_t)ntfn_queue.head);
    notification_ptr_set_ntfnQueue_tail(ntfnPtr, (word_t)ntfn_queue.end);
}

static inline void ntfn_set_active(notification_t *ntfnPtr, word_t badge)
{
    notification_ptr_set_state(ntfnPtr, NtfnState_Active);
    notification_ptr_set_ntfnMsgIdentifier(ntfnPtr, badge);
}
# 76 "/host/kernel/src/object/notification.c"
void sendSignal(notification_t *ntfnPtr, word_t badge)
{
    switch (notification_ptr_get_state(ntfnPtr)) {
    case NtfnState_Idle: {
        tcb_t *tcb = (tcb_t *)notification_ptr_get_ntfnBoundTCB(ntfnPtr);
        /* Check if we are bound and that thread is waiting for a message */
        if (tcb) {
            if (thread_state_ptr_get_tsType(&tcb->tcbState) == ThreadState_BlockedOnReceive) {
                /* Send and start thread running */
                cancelIPC(tcb);
                setThreadState(tcb, ThreadState_Running);
                setRegister(tcb, badgeRegister, badge);
                { { possibleSwitchTo(tcb); } }
# 108 "/host/kernel/src/object/notification.c"
            } else {
                /* In particular, this path is taken when a thread
                 * is waiting on a reply cap since BlockedOnReply
                 * would also trigger this path. I.e, a thread
                 * with a bound notification will not be awakened
                 * by signals on that bound notification if it is
                 * in the middle of an seL4_Call.
                 */
                ntfn_set_active(ntfnPtr, badge);
            }
        } else {
            ntfn_set_active(ntfnPtr, badge);
        }
        break;
    }
    case NtfnState_Waiting: {
        tcb_queue_t ntfn_queue;
        tcb_t *dest;

        ntfn_queue = ntfn_ptr_get_queue(ntfnPtr);
        dest = ntfn_queue.head;

        /* Haskell error "WaitingNtfn Notification must have non-empty queue" */
        if(!(dest)) _assert_fail("dest", "/host/kernel/src/object/notification.c", 131, __FUNCTION__);

        /* Dequeue TCB */
        ntfn_queue = tcbEPDequeue(dest, ntfn_queue);
        ntfn_ptr_set_queue(ntfnPtr, ntfn_queue);

        /* set the thread state to idle if the queue is empty */
        if (!ntfn_queue.head) {
            notification_ptr_set_state(ntfnPtr, NtfnState_Idle);
        }

        setThreadState(dest, ThreadState_Running);
        setRegister(dest, badgeRegister, badge);
        { { possibleSwitchTo(dest); } }


        break;
    }

    case NtfnState_Active: {
        word_t badge2;

        badge2 = notification_ptr_get_ntfnMsgIdentifier(ntfnPtr);
        badge2 |= badge;

        notification_ptr_set_ntfnMsgIdentifier(ntfnPtr, badge2);
        break;
    }
    }
}

void receiveSignal(tcb_t *thread, cap_t cap, bool_t isBlocking)
{
    notification_t *ntfnPtr;

    ntfnPtr = ((notification_t *)(cap_notification_cap_get_capNtfnPtr(cap)));

    switch (notification_ptr_get_state(ntfnPtr)) {
    case NtfnState_Idle:
    case NtfnState_Waiting: {
        tcb_queue_t ntfn_queue;

        if (isBlocking) {
            /* Block thread on notification object */
            thread_state_ptr_set_tsType(&thread->tcbState,
                                        ThreadState_BlockedOnNotification);
            thread_state_ptr_set_blockingObject(&thread->tcbState,
                                                ((word_t)(ntfnPtr)));



            scheduleTCB(thread);

            /* Enqueue TCB */
            ntfn_queue = ntfn_ptr_get_queue(ntfnPtr);
            ntfn_queue = tcbEPAppend(thread, ntfn_queue);

            notification_ptr_set_state(ntfnPtr, NtfnState_Waiting);
            ntfn_ptr_set_queue(ntfnPtr, ntfn_queue);
        } else {
            doNBRecvFailedTransfer(thread);
        }

        break;
    }

    case NtfnState_Active:
        setRegister(
            thread, badgeRegister,
            notification_ptr_get_ntfnMsgIdentifier(ntfnPtr));
        notification_ptr_set_state(ntfnPtr, NtfnState_Idle);



        break;
    }
}

void cancelAllSignals(notification_t *ntfnPtr)
{
    if (notification_ptr_get_state(ntfnPtr) == NtfnState_Waiting) {
        tcb_t *thread = ((tcb_t *)(notification_ptr_get_ntfnQueue_head(ntfnPtr)));

        notification_ptr_set_state(ntfnPtr, NtfnState_Idle);
        notification_ptr_set_ntfnQueue_head(ntfnPtr, 0);
        notification_ptr_set_ntfnQueue_tail(ntfnPtr, 0);

        /* Set all waiting threads to Restart */
        for (; thread; thread = thread->tcbEPNext) {
            setThreadState(thread, ThreadState_Restart);



            tcbSchedEnqueue(thread);

        }
        rescheduleRequired();
    }
}

void cancelSignal(tcb_t *threadPtr, notification_t *ntfnPtr)
{
    tcb_queue_t ntfn_queue;

    /* Haskell error "cancelSignal: notification object must be in a waiting" state */
    if(!(notification_ptr_get_state(ntfnPtr) == NtfnState_Waiting)) _assert_fail("notification_ptr_get_state(ntfnPtr) == NtfnState_Waiting", "/host/kernel/src/object/notification.c", 236, __FUNCTION__);

    /* Dequeue TCB */
    ntfn_queue = ntfn_ptr_get_queue(ntfnPtr);
    ntfn_queue = tcbEPDequeue(threadPtr, ntfn_queue);
    ntfn_ptr_set_queue(ntfnPtr, ntfn_queue);

    /* Make notification object idle */
    if (!ntfn_queue.head) {
        notification_ptr_set_state(ntfnPtr, NtfnState_Idle);
    }

    /* Make thread inactive */
    setThreadState(threadPtr, ThreadState_Inactive);
}

void completeSignal(notification_t *ntfnPtr, tcb_t *tcb)
{
    word_t badge;

    if (__builtin_expect(!!(tcb && notification_ptr_get_state(ntfnPtr) == NtfnState_Active), 1)) {
        badge = notification_ptr_get_ntfnMsgIdentifier(ntfnPtr);
        setRegister(tcb, badgeRegister, badge);
        notification_ptr_set_state(ntfnPtr, NtfnState_Idle);



    } else {
        _fail("tried to complete signal with inactive notification object", "/host/kernel/src/object/notification.c", 264, __func__);
    }
}

static inline void doUnbindNotification(notification_t *ntfnPtr, tcb_t *tcbptr)
{
    notification_ptr_set_ntfnBoundTCB(ntfnPtr, (word_t) 0);
    tcbptr->tcbBoundNotification = ((void *)0);
}

void unbindMaybeNotification(notification_t *ntfnPtr)
{
    tcb_t *boundTCB;
    boundTCB = (tcb_t *)notification_ptr_get_ntfnBoundTCB(ntfnPtr);

    if (boundTCB) {
        doUnbindNotification(ntfnPtr, boundTCB);
    }
}

void unbindNotification(tcb_t *tcb)
{
    notification_t *ntfnPtr;
    ntfnPtr = tcb->tcbBoundNotification;

    if (ntfnPtr) {
        doUnbindNotification(ntfnPtr, tcb);
    }
}

void bindNotification(tcb_t *tcb, notification_t *ntfnPtr)
{
    notification_ptr_set_ntfnBoundTCB(ntfnPtr, (word_t)tcb);
    tcb->tcbBoundNotification = ntfnPtr;
}
# 1 "/host/kernel/src/object/objecttype.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 33 "/host/kernel/src/object/objecttype.c"
word_t getObjectSize(word_t t, word_t userObjSize)
{
    if (t >= seL4_NonArchObjectTypeCount) {
        return Arch_getObjectSize(t);
    } else {
        switch (t) {
        case seL4_TCBObject:
            return 11;
        case seL4_EndpointObject:
            return 4;
        case seL4_NotificationObject:
            return 5;
        case seL4_CapTableObject:
            return 5 + userObjSize;
        case seL4_UntypedObject:
            return userObjSize;






        default:
            _fail("Invalid object type", "/host/kernel/src/object/objecttype.c", 56, __func__);
            return 0;
        }
    }
}

deriveCap_ret_t deriveCap(cte_t *slot, cap_t cap)
{
    deriveCap_ret_t ret;

    if (isArchCap(cap)) {
        return Arch_deriveCap(slot, cap);
    }

    switch (cap_get_capType(cap)) {
    case cap_zombie_cap:
        ret.status = EXCEPTION_NONE;
        ret.cap = cap_null_cap_new();
        break;

    case cap_irq_control_cap:
        ret.status = EXCEPTION_NONE;
        ret.cap = cap_null_cap_new();
        break;

    case cap_untyped_cap:
        ret.status = ensureNoChildren(slot);
        if (ret.status != EXCEPTION_NONE) {
            ret.cap = cap_null_cap_new();
        } else {
            ret.cap = cap;
        }
        break;


    case cap_reply_cap:
        ret.status = EXCEPTION_NONE;
        ret.cap = cap_null_cap_new();
        break;

    default:
        ret.status = EXCEPTION_NONE;
        ret.cap = cap;
    }

    return ret;
}

finaliseCap_ret_t finaliseCap(cap_t cap, bool_t final, bool_t exposed)
{
    finaliseCap_ret_t fc_ret;

    if (isArchCap(cap)) {
        return Arch_finaliseCap(cap, final);
    }

    switch (cap_get_capType(cap)) {
    case cap_endpoint_cap:
        if (final) {
            cancelAllIPC(((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(cap))));
        }

        fc_ret.remainder = cap_null_cap_new();
        fc_ret.cleanupInfo = cap_null_cap_new();
        return fc_ret;

    case cap_notification_cap:
        if (final) {
            notification_t *ntfn = ((notification_t *)(cap_notification_cap_get_capNtfnPtr(cap)));



            unbindMaybeNotification(ntfn);
            cancelAllSignals(ntfn);
        }
        fc_ret.remainder = cap_null_cap_new();
        fc_ret.cleanupInfo = cap_null_cap_new();
        return fc_ret;

    case cap_reply_cap:
# 156 "/host/kernel/src/object/objecttype.c"
    case cap_null_cap:
    case cap_domain_cap:
        fc_ret.remainder = cap_null_cap_new();
        fc_ret.cleanupInfo = cap_null_cap_new();
        return fc_ret;
    }

    if (exposed) {
        _fail("finaliseCap: failed to finalise immediately.", "/host/kernel/src/object/objecttype.c", 164, __func__);
    }

    switch (cap_get_capType(cap)) {
    case cap_cnode_cap: {
        if (final) {
            fc_ret.remainder =
                Zombie_new(
                    1ul << cap_cnode_cap_get_capCNodeRadix(cap),
                    cap_cnode_cap_get_capCNodeRadix(cap),
                    cap_cnode_cap_get_capCNodePtr(cap)
                );
            fc_ret.cleanupInfo = cap_null_cap_new();
            return fc_ret;
        }
        break;
    }

    case cap_thread_cap: {
        if (final) {
            tcb_t *tcb;
            cte_t *cte_ptr;

            tcb = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap)));
           
            cte_ptr = (((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbCTable));
            unbindNotification(tcb);






            suspend(tcb);

            tcbDebugRemove(tcb);

            Arch_prepareThreadDelete(tcb);
            fc_ret.remainder =
                Zombie_new(
                    tcbArchCNodeEntries,
                    (1ul << (6)),
                    ((word_t)(cte_ptr))
                );
            fc_ret.cleanupInfo = cap_null_cap_new();
            return fc_ret;
        }
        break;
    }
# 237 "/host/kernel/src/object/objecttype.c"
    case cap_zombie_cap:
        fc_ret.remainder = cap;
        fc_ret.cleanupInfo = cap_null_cap_new();
        return fc_ret;

    case cap_irq_handler_cap:
        if (final) {
            irq_t irq = (cap_irq_handler_cap_get_capIRQ(cap));

            deletingIRQHandler(irq);

            fc_ret.remainder = cap_null_cap_new();
            fc_ret.cleanupInfo = cap;
            return fc_ret;
        }
        break;
    }

    fc_ret.remainder = cap_null_cap_new();
    fc_ret.cleanupInfo = cap_null_cap_new();
    return fc_ret;
}

bool_t __attribute__((__const__)) hasCancelSendRights(cap_t cap)
{
    switch (cap_get_capType(cap)) {
    case cap_endpoint_cap:
        return cap_endpoint_cap_get_capCanSend(cap) &&
               cap_endpoint_cap_get_capCanReceive(cap) &&
               cap_endpoint_cap_get_capCanGrantReply(cap) &&
               cap_endpoint_cap_get_capCanGrant(cap);

    default:
        return false;
    }
}

bool_t __attribute__((__const__)) sameRegionAs(cap_t cap_a, cap_t cap_b)
{
    switch (cap_get_capType(cap_a)) {
    case cap_untyped_cap:
        if (cap_get_capIsPhysical(cap_b)) {
            word_t aBase, bBase, aTop, bTop;

            aBase = (word_t)((word_t *)(cap_untyped_cap_get_capPtr(cap_a)));
            bBase = (word_t)cap_get_capPtr(cap_b);

            aTop = aBase + ((1ul << (cap_untyped_cap_get_capBlockSize(cap_a)))-1ul);
            bTop = bBase + ((1ul << (cap_get_capSizeBits(cap_b)))-1ul);

            return (aBase <= bBase) && (bTop <= aTop) && (bBase <= bTop);
        }
        break;

    case cap_endpoint_cap:
        if (cap_get_capType(cap_b) == cap_endpoint_cap) {
            return cap_endpoint_cap_get_capEPPtr(cap_a) ==
                   cap_endpoint_cap_get_capEPPtr(cap_b);
        }
        break;

    case cap_notification_cap:
        if (cap_get_capType(cap_b) == cap_notification_cap) {
            return cap_notification_cap_get_capNtfnPtr(cap_a) ==
                   cap_notification_cap_get_capNtfnPtr(cap_b);
        }
        break;

    case cap_cnode_cap:
        if (cap_get_capType(cap_b) == cap_cnode_cap) {
            return (cap_cnode_cap_get_capCNodePtr(cap_a) ==
                    cap_cnode_cap_get_capCNodePtr(cap_b)) &&
                   (cap_cnode_cap_get_capCNodeRadix(cap_a) ==
                    cap_cnode_cap_get_capCNodeRadix(cap_b));
        }
        break;

    case cap_thread_cap:
        if (cap_get_capType(cap_b) == cap_thread_cap) {
            return cap_thread_cap_get_capTCBPtr(cap_a) ==
                   cap_thread_cap_get_capTCBPtr(cap_b);
        }
        break;

    case cap_reply_cap:
        if (cap_get_capType(cap_b) == cap_reply_cap) {




            return cap_reply_cap_get_capTCBPtr(cap_a) ==
                   cap_reply_cap_get_capTCBPtr(cap_b);

        }
        break;

    case cap_domain_cap:
        if (cap_get_capType(cap_b) == cap_domain_cap) {
            return true;
        }
        break;

    case cap_irq_control_cap:
        if (cap_get_capType(cap_b) == cap_irq_control_cap ||
            cap_get_capType(cap_b) == cap_irq_handler_cap) {
            return true;
        }
        break;

    case cap_irq_handler_cap:
        if (cap_get_capType(cap_b) == cap_irq_handler_cap) {
            return (word_t)cap_irq_handler_cap_get_capIRQ(cap_a) ==
                   (word_t)cap_irq_handler_cap_get_capIRQ(cap_b);
        }
        break;
# 368 "/host/kernel/src/object/objecttype.c"
    default:
        if (isArchCap(cap_a) &&
            isArchCap(cap_b)) {
            return Arch_sameRegionAs(cap_a, cap_b);
        }
        break;
    }

    return false;
}

bool_t __attribute__((__const__)) sameObjectAs(cap_t cap_a, cap_t cap_b)
{
    if (cap_get_capType(cap_a) == cap_untyped_cap) {
        return false;
    }
    if (cap_get_capType(cap_a) == cap_irq_control_cap &&
        cap_get_capType(cap_b) == cap_irq_handler_cap) {
        return false;
    }
    if (isArchCap(cap_a) && isArchCap(cap_b)) {
        return Arch_sameObjectAs(cap_a, cap_b);
    }
    return sameRegionAs(cap_a, cap_b);
}

cap_t __attribute__((__const__)) updateCapData(bool_t preserve, word_t newData, cap_t cap)
{
    if (isArchCap(cap)) {
        return Arch_updateCapData(preserve, newData, cap);
    }

    switch (cap_get_capType(cap)) {
    case cap_endpoint_cap:
        if (!preserve && cap_endpoint_cap_get_capEPBadge(cap) == 0) {
            return cap_endpoint_cap_set_capEPBadge(cap, newData);
        } else {
            return cap_null_cap_new();
        }

    case cap_notification_cap:
        if (!preserve && cap_notification_cap_get_capNtfnBadge(cap) == 0) {
            return cap_notification_cap_set_capNtfnBadge(cap, newData);
        } else {
            return cap_null_cap_new();
        }

    case cap_cnode_cap: {
        word_t guard, guardSize;
        seL4_CNode_CapData_t w = { .words = { newData } };

        guardSize = seL4_CNode_CapData_get_guardSize(w);

        if (guardSize + cap_cnode_cap_get_capCNodeRadix(cap) > (1 << 6)) {
            return cap_null_cap_new();
        } else {
            cap_t new_cap;

            guard = seL4_CNode_CapData_get_guard(w) & ((1ul << (guardSize))-1ul);
            new_cap = cap_cnode_cap_set_capCNodeGuard(cap, guard);
            new_cap = cap_cnode_cap_set_capCNodeGuardSize(new_cap,
                                                          guardSize);

            return new_cap;
        }
    }

    default:
        return cap;
    }
}

cap_t __attribute__((__const__)) maskCapRights(seL4_CapRights_t cap_rights, cap_t cap)
{
    if (isArchCap(cap)) {
        return Arch_maskCapRights(cap_rights, cap);
    }

    switch (cap_get_capType(cap)) {
    case cap_null_cap:
    case cap_domain_cap:
    case cap_cnode_cap:
    case cap_untyped_cap:
    case cap_irq_control_cap:
    case cap_irq_handler_cap:
    case cap_zombie_cap:
    case cap_thread_cap:




        return cap;

    case cap_endpoint_cap: {
        cap_t new_cap;

        new_cap = cap_endpoint_cap_set_capCanSend(
                      cap, cap_endpoint_cap_get_capCanSend(cap) &
                      seL4_CapRights_get_capAllowWrite(cap_rights));
        new_cap = cap_endpoint_cap_set_capCanReceive(
                      new_cap, cap_endpoint_cap_get_capCanReceive(cap) &
                      seL4_CapRights_get_capAllowRead(cap_rights));
        new_cap = cap_endpoint_cap_set_capCanGrant(
                      new_cap, cap_endpoint_cap_get_capCanGrant(cap) &
                      seL4_CapRights_get_capAllowGrant(cap_rights));
        new_cap = cap_endpoint_cap_set_capCanGrantReply(
                      new_cap, cap_endpoint_cap_get_capCanGrantReply(cap) &
                      seL4_CapRights_get_capAllowGrantReply(cap_rights));

        return new_cap;
    }

    case cap_notification_cap: {
        cap_t new_cap;

        new_cap = cap_notification_cap_set_capNtfnCanSend(
                      cap, cap_notification_cap_get_capNtfnCanSend(cap) &
                      seL4_CapRights_get_capAllowWrite(cap_rights));
        new_cap = cap_notification_cap_set_capNtfnCanReceive(new_cap,
                                                             cap_notification_cap_get_capNtfnCanReceive(cap) &
                                                             seL4_CapRights_get_capAllowRead(cap_rights));

        return new_cap;
    }
    case cap_reply_cap: {
        cap_t new_cap;

        new_cap = cap_reply_cap_set_capReplyCanGrant(
                      cap, cap_reply_cap_get_capReplyCanGrant(cap) &
                      seL4_CapRights_get_capAllowGrant(cap_rights));
        return new_cap;
    }


    default:
        _fail("Invalid cap type", "/host/kernel/src/object/objecttype.c", 503, __func__); /* Sentinel for invalid enums */
    }
}

cap_t createObject(object_t t, void *regionBase, word_t userSize, bool_t deviceMemory)
{
    /* Handle architecture-specific objects. */
    if (t >= (object_t) seL4_NonArchObjectTypeCount) {
        return Arch_createObject(t, regionBase, userSize, deviceMemory);
    }

    /* Create objects. */
    switch ((api_object_t)t) {
    case seL4_TCBObject: {
        tcb_t *tcb;
        tcb = ((tcb_t *)((word_t)regionBase + (1ul << ((11 - 1)))));
        /** AUXUPD: "(True, ptr_retyps 1
          (Ptr ((ptr_val \<acute>tcb) - ctcb_offset) :: (cte_C[5]) ptr)
            o (ptr_retyp \<acute>tcb))" */

        /* Setup non-zero parts of the TCB. */

        Arch_initContext(&tcb->tcbArch.tcbContext);

        tcb->tcbTimeSlice = 5;

        tcb->tcbDomain = ksCurDomain;

        /* Initialize the new TCB to the current core */
        ;


        strlcpy(((debug_tcb_t *)(((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, "child of: '", ((1ul << (11 -1)) - (tcbCNodeEntries * sizeof(cte_t)) - sizeof(debug_tcb_t)));
        strlcat(((debug_tcb_t *)(((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, ((1ul << (11 -1)) - (tcbCNodeEntries * sizeof(cte_t)) - sizeof(debug_tcb_t)));
        strlcat(((debug_tcb_t *)(((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, "'", ((1ul << (11 -1)) - (tcbCNodeEntries * sizeof(cte_t)) - sizeof(debug_tcb_t)));
        tcbDebugAppend(tcb);


        return cap_thread_cap_new(((word_t)(tcb)));
    }

    case seL4_EndpointObject:
        /** AUXUPD: "(True, ptr_retyp
          (Ptr (ptr_val \<acute>regionBase) :: endpoint_C ptr))" */
        return cap_endpoint_cap_new(0, true, true, true, true,
                                    ((word_t)(regionBase)));

    case seL4_NotificationObject:
        /** AUXUPD: "(True, ptr_retyp
              (Ptr (ptr_val \<acute>regionBase) :: notification_C ptr))" */
        return cap_notification_cap_new(0, true, true,
                                        ((word_t)(regionBase)));

    case seL4_CapTableObject:
        /** AUXUPD: "(True, ptr_arr_retyps (2 ^ (unat \<acute>userSize))
          (Ptr (ptr_val \<acute>regionBase) :: cte_C ptr))" */
        /** GHOSTUPD: "(True, gs_new_cnodes (unat \<acute>userSize)
                                (ptr_val \<acute>regionBase)
                                (4 + unat \<acute>userSize))" */
        return cap_cnode_cap_new(userSize, 0, 0, ((word_t)(regionBase)));

    case seL4_UntypedObject:
        /*
         * No objects need to be created; instead, just insert caps into
         * the destination slots.
         */
        return cap_untyped_cap_new(0, !!deviceMemory, userSize, ((word_t)(regionBase)));
# 581 "/host/kernel/src/object/objecttype.c"
    default:
        _fail("Invalid object type", "/host/kernel/src/object/objecttype.c", 582, __func__);
    }
}

void createNewObjects(object_t t, cte_t *parent, slot_range_t slots,
                      void *regionBase, word_t userSize, bool_t deviceMemory)
{
    word_t objectSize;
    void *nextFreeArea;
    word_t i;
    word_t totalObjectSize __attribute__((unused));

    /* ghost check that we're visiting less bytes than the max object size */
    objectSize = getObjectSize(t, userSize);
    totalObjectSize = slots.length << objectSize;
    /** GHOSTUPD: "(gs_get_assn cap_get_capSizeBits_'proc \<acute>ghost'state = 0
        \<or> \<acute>totalObjectSize <= gs_get_assn cap_get_capSizeBits_'proc \<acute>ghost'state, id)" */

    /* Create the objects. */
    nextFreeArea = regionBase;
    for (i = 0; i < slots.length; i++) {
        /* Create the object. */
        /** AUXUPD: "(True, typ_region_bytes (ptr_val \<acute> nextFreeArea + ((\<acute> i) << unat (\<acute> objectSize))) (unat (\<acute> objectSize)))" */
        cap_t cap = createObject(t, (void *)((word_t)nextFreeArea + (i << objectSize)), userSize, deviceMemory);

        /* Insert the cap into the user's cspace. */
        insertNewCap(parent, &slots.cnode[slots.offset + i], cap);

        /* Move along to the next region of memory. been merged into a formula of i */
    }
}







exception_t decodeInvocation(word_t invLabel, word_t length,
                             cptr_t capIndex, cte_t *slot, cap_t cap,
                             extra_caps_t excaps, bool_t block, bool_t call,
                             word_t *buffer)

{
    if (isArchCap(cap)) {
        return Arch_decodeInvocation(invLabel, length, capIndex,
                                     slot, cap, excaps, call, buffer);
    }

    switch (cap_get_capType(cap)) {
    case cap_null_cap:
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Attempted to invoke a null cap #%lu." ">>" "\033[0m" "\n", 0lu, __func__, 633, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), capIndex); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;
        return EXCEPTION_SYSCALL_ERROR;

    case cap_zombie_cap:
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Attempted to invoke a zombie cap #%lu." ">>" "\033[0m" "\n", 0lu, __func__, 639, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), capIndex); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;
        return EXCEPTION_SYSCALL_ERROR;

    case cap_endpoint_cap:
        if (__builtin_expect(!!(!cap_endpoint_cap_get_capCanSend(cap)), 0)) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Attempted to invoke a read-only endpoint cap #%lu." ">>" "\033[0m" "\n", 0lu, __func__, 647, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), capIndex); } while (0)
                               ;
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 0;
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksCurThread, ThreadState_Restart);







        return performInvocation_Endpoint(
                   ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(cap))),
                   cap_endpoint_cap_get_capEPBadge(cap),
                   cap_endpoint_cap_get_capCanGrant(cap),
                   cap_endpoint_cap_get_capCanGrantReply(cap), block, call);


    case cap_notification_cap: {
        if (__builtin_expect(!!(!cap_notification_cap_get_capNtfnCanSend(cap)), 0)) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Attempted to invoke a read-only notification cap #%lu." ">>" "\033[0m" "\n", 0lu, __func__, 671, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), capIndex); } while (0)
                               ;
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 0;
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksCurThread, ThreadState_Restart);
        return performInvocation_Notification(
                   ((notification_t *)(cap_notification_cap_get_capNtfnPtr(cap))),
                   cap_notification_cap_get_capNtfnBadge(cap));
    }
# 691 "/host/kernel/src/object/objecttype.c"
    case cap_reply_cap:
        if (__builtin_expect(!!(cap_reply_cap_get_capReplyMaster(cap)), 0)) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Attempted to invoke an invalid reply cap #%lu." ">>" "\033[0m" "\n", 0lu, __func__, 694, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), capIndex); } while (0)
                               ;
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 0;
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksCurThread, ThreadState_Restart);
        return performInvocation_Reply(
                   ((tcb_t *)(cap_reply_cap_get_capTCBPtr(cap))), slot,
                   cap_reply_cap_get_capReplyCanGrant(cap));



    case cap_thread_cap:
# 716 "/host/kernel/src/object/objecttype.c"
        return decodeTCBInvocation(invLabel, length, cap,
                                   slot, excaps, call, buffer);

    case cap_domain_cap:
# 728 "/host/kernel/src/object/objecttype.c"
        return decodeDomainInvocation(invLabel, length, excaps, buffer);

    case cap_cnode_cap:
# 739 "/host/kernel/src/object/objecttype.c"
        return decodeCNodeInvocation(invLabel, length, cap, excaps, buffer);

    case cap_untyped_cap:
        return decodeUntypedInvocation(invLabel, length, slot, cap, excaps,
                                       call, buffer);

    case cap_irq_control_cap:
        return decodeIRQControlInvocation(invLabel, length, slot,
                                          excaps, buffer);

    case cap_irq_handler_cap:
        return decodeIRQHandlerInvocation(invLabel,
                                          (cap_irq_handler_cap_get_capIRQ(cap)), excaps);
# 772 "/host/kernel/src/object/objecttype.c"
    default:
        _fail("Invalid cap type", "/host/kernel/src/object/objecttype.c", 773, __func__);
    }
}
# 787 "/host/kernel/src/object/objecttype.c"
exception_t performInvocation_Endpoint(endpoint_t *ep, word_t badge,
                                       bool_t canGrant, bool_t canGrantReply,
                                       bool_t block, bool_t call)
{
    sendIPC(block, call, badge, canGrant, canGrantReply, ksCurThread, ep);

    return EXCEPTION_NONE;
}


exception_t performInvocation_Notification(notification_t *ntfn, word_t badge)
{
    sendSignal(ntfn, badge);

    return EXCEPTION_NONE;
}
# 811 "/host/kernel/src/object/objecttype.c"
exception_t performInvocation_Reply(tcb_t *thread, cte_t *slot, bool_t canGrant)
{
    doReplyTransfer(ksCurThread, thread, slot, canGrant);
    return EXCEPTION_NONE;
}
# 1 "/host/kernel/src/object/tcb.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




# 1 "kernel/gen_headers/api/invocation.h" 1

/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 ** SPDX-License-Identifier: GPL-2.0-only
 */

/* This header was generated by kernel/tools/invocation_header_gen.py.
 *
 * To add an invocation call number, edit libsel4/include/interfaces/sel4.xml.
 *
 */
# 11 "/host/kernel/src/object/tcb.c" 2
# 32 "/host/kernel/src/object/tcb.c"
static exception_t checkPrio(prio_t prio, tcb_t *auth)
{
    prio_t mcp;

    mcp = auth->tcbMCP;

    /* system invariant: existing MCPs are bounded */
    if(!(mcp <= seL4_MaxPrio)) _assert_fail("mcp <= seL4_MaxPrio", "/host/kernel/src/object/tcb.c", 39, __FUNCTION__);

    /* can't assign a priority greater than our own mcp */
    if (prio > mcp) {
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = seL4_MinPrio;
        current_syscall_error.rangeErrorMax = mcp;
        return EXCEPTION_SYSCALL_ERROR;
    }

    return EXCEPTION_NONE;
}

static inline void addToBitmap(word_t cpu, word_t dom, word_t prio)
{
    word_t l1index;
    word_t l1index_inverted;

    l1index = prio_to_l1index(prio);
    l1index_inverted = invert_l1index(l1index);

    ksReadyQueuesL1Bitmap[dom] |= (1ul << (l1index));
    /* we invert the l1 index when accessed the 2nd level of the bitmap in
       order to increase the liklihood that high prio threads l2 index word will
       be on the same cache line as the l1 index word - this makes sure the
       fastpath is fastest for high prio threads */
    ksReadyQueuesL2Bitmap[dom][l1index_inverted] |= (1ul << (prio & ((1ul << (6))-1ul)));
}

static inline void removeFromBitmap(word_t cpu, word_t dom, word_t prio)
{
    word_t l1index;
    word_t l1index_inverted;

    l1index = prio_to_l1index(prio);
    l1index_inverted = invert_l1index(l1index);
    ksReadyQueuesL2Bitmap[dom][l1index_inverted] &= ~(1ul << (prio & ((1ul << (6))-1ul)));
    if (__builtin_expect(!!(!ksReadyQueuesL2Bitmap[dom][l1index_inverted]), 0)) {
        ksReadyQueuesL1Bitmap[dom] &= ~(1ul << (l1index));
    }
}

/* Add TCB to the head of a scheduler queue */
void tcbSchedEnqueue(tcb_t *tcb)
{





    if (!thread_state_get_tcbQueued(tcb->tcbState)) {
        tcb_queue_t queue;
        dom_t dom;
        prio_t prio;
        word_t idx;

        dom = tcb->tcbDomain;
        prio = tcb->tcbPriority;
        idx = ready_queues_index(dom, prio);
        queue = ksReadyQueues[idx];

        if (!queue.end) { /* Empty list */
            queue.end = tcb;
            addToBitmap(0, dom, prio);
        } else {
            queue.head->tcbSchedPrev = tcb;
        }
        tcb->tcbSchedPrev = ((void *)0);
        tcb->tcbSchedNext = queue.head;
        queue.head = tcb;

        ksReadyQueues[idx] = queue;

        thread_state_ptr_set_tcbQueued(&tcb->tcbState, true);
    }
}

/* Add TCB to the end of a scheduler queue */
void tcbSchedAppend(tcb_t *tcb)
{





    if (!thread_state_get_tcbQueued(tcb->tcbState)) {
        tcb_queue_t queue;
        dom_t dom;
        prio_t prio;
        word_t idx;

        dom = tcb->tcbDomain;
        prio = tcb->tcbPriority;
        idx = ready_queues_index(dom, prio);
        queue = ksReadyQueues[idx];

        if (!queue.head) { /* Empty list */
            queue.head = tcb;
            addToBitmap(0, dom, prio);
        } else {
            queue.end->tcbSchedNext = tcb;
        }
        tcb->tcbSchedPrev = queue.end;
        tcb->tcbSchedNext = ((void *)0);
        queue.end = tcb;

        ksReadyQueues[idx] = queue;

        thread_state_ptr_set_tcbQueued(&tcb->tcbState, true);
    }
}

/* Remove TCB from a scheduler queue */
void tcbSchedDequeue(tcb_t *tcb)
{
    if (thread_state_get_tcbQueued(tcb->tcbState)) {
        tcb_queue_t queue;
        dom_t dom;
        prio_t prio;
        word_t idx;

        dom = tcb->tcbDomain;
        prio = tcb->tcbPriority;
        idx = ready_queues_index(dom, prio);
        queue = ksReadyQueues[idx];

        if (tcb->tcbSchedPrev) {
            tcb->tcbSchedPrev->tcbSchedNext = tcb->tcbSchedNext;
        } else {
            queue.head = tcb->tcbSchedNext;
            if (__builtin_expect(!!(!tcb->tcbSchedNext), 1)) {
                removeFromBitmap(0, dom, prio);
            }
        }

        if (tcb->tcbSchedNext) {
            tcb->tcbSchedNext->tcbSchedPrev = tcb->tcbSchedPrev;
        } else {
            queue.end = tcb->tcbSchedPrev;
        }

        ksReadyQueues[idx] = queue;

        thread_state_ptr_set_tcbQueued(&tcb->tcbState, false);
    }
}


void tcbDebugAppend(tcb_t *tcb)
{
    debug_tcb_t *debug_tcb = ((debug_tcb_t *)(((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)));
    /* prepend to the list */
    debug_tcb->tcbDebugPrev = ((void *)0);

    debug_tcb->tcbDebugNext = ksDebugTCBs;

    if (ksDebugTCBs) {
        ((debug_tcb_t *)(((cte_t *)((word_t)(ksDebugTCBs)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbDebugPrev = tcb;
    }

    ksDebugTCBs = tcb;
}

void tcbDebugRemove(tcb_t *tcb)
{
    debug_tcb_t *debug_tcb = ((debug_tcb_t *)(((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)));

    if(!(ksDebugTCBs != ((void *)0))) _assert_fail("NODE_STATE_ON_CORE(ksDebugTCBs, tcb->tcbAffinity) != NULL", "/host/kernel/src/object/tcb.c", 206, __FUNCTION__);
    if (tcb == ksDebugTCBs) {
        ksDebugTCBs = ((debug_tcb_t *)(((cte_t *)((word_t)(ksDebugTCBs)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))
                                                                                                                   ->tcbDebugNext;
    } else {
        if(!(((debug_tcb_t *)(((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbDebugPrev)) _assert_fail("TCB_PTR_DEBUG_PTR(tcb)->tcbDebugPrev", "/host/kernel/src/object/tcb.c", 211, __FUNCTION__);
        ((debug_tcb_t *)(((cte_t *)((word_t)(debug_tcb->tcbDebugPrev)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbDebugNext = debug_tcb->tcbDebugNext;
    }

    if (debug_tcb->tcbDebugNext) {
        ((debug_tcb_t *)(((cte_t *)((word_t)(debug_tcb->tcbDebugNext)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbDebugPrev = debug_tcb->tcbDebugPrev;
    }

    debug_tcb->tcbDebugPrev = ((void *)0);
    debug_tcb->tcbDebugNext = ((void *)0);
}



/* Add TCB to the end of an endpoint queue */
tcb_queue_t tcbEPAppend(tcb_t *tcb, tcb_queue_t queue)
{
    if (!queue.head) { /* Empty list */
        queue.head = tcb;
    } else {
        queue.end->tcbEPNext = tcb;
    }
    tcb->tcbEPPrev = queue.end;
    tcb->tcbEPNext = ((void *)0);
    queue.end = tcb;

    return queue;
}


/* Remove TCB from an endpoint queue */
tcb_queue_t tcbEPDequeue(tcb_t *tcb, tcb_queue_t queue)
{
    if (tcb->tcbEPPrev) {
        tcb->tcbEPPrev->tcbEPNext = tcb->tcbEPNext;
    } else {
        queue.head = tcb->tcbEPNext;
    }

    if (tcb->tcbEPNext) {
        tcb->tcbEPNext->tcbEPPrev = tcb->tcbEPPrev;
    } else {
        queue.end = tcb->tcbEPPrev;
    }

    return queue;
}
# 339 "/host/kernel/src/object/tcb.c"
cptr_t __attribute__((__pure__)) getExtraCPtr(word_t *bufferPtr, word_t i)
{
    return (cptr_t)bufferPtr[seL4_MsgMaxLength + 2 + i];
}

void setExtraBadge(word_t *bufferPtr, word_t badge,
                   word_t i)
{
    bufferPtr[seL4_MsgMaxLength + 2 + i] = badge;
}


void setupCallerCap(tcb_t *sender, tcb_t *receiver, bool_t canGrant)
{
    cte_t *replySlot, *callerSlot;
    cap_t masterCap __attribute__((unused)), callerCap __attribute__((unused));

    setThreadState(sender, ThreadState_BlockedOnReply);
    replySlot = (((cte_t *)((word_t)(sender)&~((1ul << (11))-1ul)))+(tcbReply));
    masterCap = replySlot->cap;
    /* Haskell error: "Sender must have a valid master reply cap" */
    if(!(cap_get_capType(masterCap) == cap_reply_cap)) _assert_fail("cap_get_capType(masterCap) == cap_reply_cap", "/host/kernel/src/object/tcb.c", 360, __FUNCTION__);
    if(!(cap_reply_cap_get_capReplyMaster(masterCap))) _assert_fail("cap_reply_cap_get_capReplyMaster(masterCap)", "/host/kernel/src/object/tcb.c", 361, __FUNCTION__);
    if(!(cap_reply_cap_get_capReplyCanGrant(masterCap))) _assert_fail("cap_reply_cap_get_capReplyCanGrant(masterCap)", "/host/kernel/src/object/tcb.c", 362, __FUNCTION__);
    if(!(((tcb_t *)(cap_reply_cap_get_capTCBPtr(masterCap))) == sender)) _assert_fail("TCB_PTR(cap_reply_cap_get_capTCBPtr(masterCap)) == sender", "/host/kernel/src/object/tcb.c", 363, __FUNCTION__);
    callerSlot = (((cte_t *)((word_t)(receiver)&~((1ul << (11))-1ul)))+(tcbCaller));
    callerCap = callerSlot->cap;
    /* Haskell error: "Caller cap must not already exist" */
    if(!(cap_get_capType(callerCap) == cap_null_cap)) _assert_fail("cap_get_capType(callerCap) == cap_null_cap", "/host/kernel/src/object/tcb.c", 367, __FUNCTION__);
    cteInsert(cap_reply_cap_new(canGrant, false, ((word_t)(sender))),
              replySlot, callerSlot);
}

void deleteCallerCap(tcb_t *receiver)
{
    cte_t *callerSlot;

    callerSlot = (((cte_t *)((word_t)(receiver)&~((1ul << (11))-1ul)))+(tcbCaller));
    /** GHOSTUPD: "(True, gs_set_assn cteDeleteOne_'proc (ucast cap_reply_cap))" */
    cteDeleteOne(callerSlot);
}


extra_caps_t current_extra_caps;

exception_t lookupExtraCaps(tcb_t *thread, word_t *bufferPtr, seL4_MessageInfo_t info)
{
    lookupSlot_raw_ret_t lu_ret;
    cptr_t cptr;
    word_t i, length;

    if (!bufferPtr) {
        current_extra_caps.excaprefs[0] = ((void *)0);
        return EXCEPTION_NONE;
    }

    length = seL4_MessageInfo_get_extraCaps(info);

    for (i = 0; i < length; i++) {
        cptr = getExtraCPtr(bufferPtr, i);

        lu_ret = lookupSlot(thread, cptr);
        if (lu_ret.status != EXCEPTION_NONE) {
            current_fault = seL4_Fault_CapFault_new(cptr, false);
            return lu_ret.status;
        }

        current_extra_caps.excaprefs[i] = lu_ret.slot;
    }
    if (i < ((1ul<<(seL4_MsgExtraCapBits))-1)) {
        current_extra_caps.excaprefs[i] = ((void *)0);
    }

    return EXCEPTION_NONE;
}

/* Copy IPC MRs from one thread to another */
word_t copyMRs(tcb_t *sender, word_t *sendBuf, tcb_t *receiver,
               word_t *recvBuf, word_t n)
{
    word_t i;

    /* Copy inline words */
    for (i = 0; i < n && i < n_msgRegisters; i++) {
        setRegister(receiver, msgRegisters[i],
                    getRegister(sender, msgRegisters[i]));
    }

    if (!recvBuf || !sendBuf) {
        return i;
    }

    /* Copy out-of-line words */
    for (; i < n; i++) {
        recvBuf[i + 1] = sendBuf[i + 1];
    }

    return i;
}
# 746 "/host/kernel/src/object/tcb.c"
static exception_t invokeSetTLSBase(tcb_t *thread, word_t tls_base)
{
    setRegister(thread, TLS_BASE, tls_base);
    if (thread == ksCurThread) {
        /* If this is the current thread force a reschedule to ensure that any changes
         * to the TLS_BASE are realized */
        rescheduleRequired();
    }

    return EXCEPTION_NONE;
}

static exception_t decodeSetTLSBase(cap_t cap, word_t length, word_t *buffer)
{
    word_t tls_base;

    if (length < 1) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetTLSBase: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 763, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    tls_base = getSyscallArg(0, buffer);

    setThreadState(ksCurThread, ThreadState_Restart);
    return invokeSetTLSBase(((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), tls_base);
}

/* The following functions sit in the syscall error monad, but include the
 * exception cases for the preemptible bottom end, as they call the invoke
 * functions directly.  This is a significant deviation from the Haskell
 * spec. */
exception_t decodeTCBInvocation(word_t invLabel, word_t length, cap_t cap,
                                cte_t *slot, extra_caps_t excaps, bool_t call,
                                word_t *buffer)
{
    /* Stall the core if we are operating on a remote TCB that is currently running */
   

    switch (invLabel) {
    case TCBReadRegisters:
        /* Second level of decoding */
        return decodeReadRegisters(cap, length, call, buffer);

    case TCBWriteRegisters:
        return decodeWriteRegisters(cap, length, buffer);

    case TCBCopyRegisters:
        return decodeCopyRegisters(cap, length, excaps, buffer);

    case TCBSuspend:
        /* Jump straight to the invoke */
        setThreadState(ksCurThread, ThreadState_Restart);
        return invokeTCB_Suspend(
                   ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))));

    case TCBResume:
        setThreadState(ksCurThread, ThreadState_Restart);
        return invokeTCB_Resume(
                   ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))));

    case TCBConfigure:
        return decodeTCBConfigure(cap, length, slot, excaps, buffer);

    case TCBSetPriority:
        return decodeSetPriority(cap, length, excaps, buffer);

    case TCBSetMCPriority:
        return decodeSetMCPriority(cap, length, excaps, buffer);

    case TCBSetSchedParams:



        return decodeSetSchedParams(cap, length, excaps, buffer);


    case TCBSetIPCBuffer:
        return decodeSetIPCBuffer(cap, length, slot, excaps, buffer);

    case TCBSetSpace:
        return decodeSetSpace(cap, length, slot, excaps, buffer);

    case TCBBindNotification:
        return decodeBindNotification(cap, excaps);

    case TCBUnbindNotification:
        return decodeUnbindNotification(cap);
# 845 "/host/kernel/src/object/tcb.c"
        /* There is no notion of arch specific TCB invocations so this needs to go here */
# 865 "/host/kernel/src/object/tcb.c"
    case TCBSetTLSBase:
        return decodeSetTLSBase(cap, length, buffer);

    default:
        /* Haskell: "throw IllegalOperation" */
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB: Illegal operation." ">>" "\033[0m" "\n", 0lu, __func__, 870, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
}

enum CopyRegistersFlags {
    CopyRegisters_suspendSource = 0,
    CopyRegisters_resumeTarget = 1,
    CopyRegisters_transferFrame = 2,
    CopyRegisters_transferInteger = 3
};

exception_t decodeCopyRegisters(cap_t cap, word_t length,
                                extra_caps_t excaps, word_t *buffer)
{
    word_t transferArch;
    tcb_t *srcTCB;
    cap_t source_cap;
    word_t flags;

    if (length < 1 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB CopyRegisters: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 892, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    flags = getSyscallArg(0, buffer);

    transferArch = Arch_decodeTransfer(flags >> 8);

    source_cap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(source_cap) == cap_thread_cap) {
        srcTCB = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(source_cap)));
    } else {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB CopyRegisters: Invalid source TCB." ">>" "\033[0m" "\n", 0lu, __func__, 906, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksCurThread, ThreadState_Restart);
    return invokeTCB_CopyRegisters(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), srcTCB,
               flags & (1ul << (CopyRegisters_suspendSource)),
               flags & (1ul << (CopyRegisters_resumeTarget)),
               flags & (1ul << (CopyRegisters_transferFrame)),
               flags & (1ul << (CopyRegisters_transferInteger)),
               transferArch);

}

enum ReadRegistersFlags {
    ReadRegisters_suspend = 0
};

exception_t decodeReadRegisters(cap_t cap, word_t length, bool_t call,
                                word_t *buffer)
{
    word_t transferArch, flags, n;
    tcb_t *thread;

    if (length < 2) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB ReadRegisters: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 934, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    flags = getSyscallArg(0, buffer);
    n = getSyscallArg(1, buffer);

    if (n < 1 || n > n_frameRegisters + n_gpRegisters) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB ReadRegisters: Attempted to read an invalid number of registers (%d)." ">>" "\033[0m" "\n", 0lu, __func__, 944, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (int)n); } while (0)
                         ;
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 1;
        current_syscall_error.rangeErrorMax = n_frameRegisters +
                                              n_gpRegisters;
        return EXCEPTION_SYSCALL_ERROR;
    }

    transferArch = Arch_decodeTransfer(flags >> 8);

    thread = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap)));
    if (thread == ksCurThread) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB ReadRegisters: Attempted to read our own registers." ">>" "\033[0m" "\n", 0lu, __func__, 956, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksCurThread, ThreadState_Restart);
    return invokeTCB_ReadRegisters(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))),
               flags & (1ul << (ReadRegisters_suspend)),
               n, transferArch, call);
}

enum WriteRegistersFlags {
    WriteRegisters_resume = 0
};

exception_t decodeWriteRegisters(cap_t cap, word_t length, word_t *buffer)
{
    word_t flags, w;
    word_t transferArch;
    tcb_t *thread;

    if (length < 2) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB WriteRegisters: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 979, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    flags = getSyscallArg(0, buffer);
    w = getSyscallArg(1, buffer);

    if (length - 2 < w) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB WriteRegisters: Message too short for requested write size (%d/%d)." ">>" "\033[0m" "\n", 0lu, __func__, 989, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (int)(length - 2), (int)w); } while (0)
                                            ;
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    transferArch = Arch_decodeTransfer(flags >> 8);

    thread = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap)));
    if (thread == ksCurThread) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB WriteRegisters: Attempted to write our own registers." ">>" "\033[0m" "\n", 0lu, __func__, 998, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksCurThread, ThreadState_Restart);
    return invokeTCB_WriteRegisters(thread,
                                    flags & (1ul << (WriteRegisters_resume)),
                                    w, transferArch, buffer);
}
# 1032 "/host/kernel/src/object/tcb.c"
/* TCBConfigure batches SetIPCBuffer and parts of SetSpace. */
exception_t decodeTCBConfigure(cap_t cap, word_t length, cte_t *slot,
                               extra_caps_t rootCaps, word_t *buffer)
{
    cte_t *bufferSlot, *cRootSlot, *vRootSlot;
    cap_t bufferCap, cRootCap, vRootCap;
    deriveCap_ret_t dc_ret;
    word_t cRootData, vRootData, bufferAddr;





    if (length < 4 || rootCaps.excaprefs[0] == ((void *)0)
        || rootCaps.excaprefs[1] == ((void *)0)
        || rootCaps.excaprefs[2] == ((void *)0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB Configure: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 1048, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }






    cptr_t faultEP = getSyscallArg(0, buffer);
    cRootData = getSyscallArg(1, buffer);
    vRootData = getSyscallArg(2, buffer);
    bufferAddr = getSyscallArg(3, buffer);


    cRootSlot = rootCaps.excaprefs[0];
    cRootCap = rootCaps.excaprefs[0]->cap;
    vRootSlot = rootCaps.excaprefs[1];
    vRootCap = rootCaps.excaprefs[1]->cap;
    bufferSlot = rootCaps.excaprefs[2];
    bufferCap = rootCaps.excaprefs[2]->cap;

    if (bufferAddr == 0) {
        bufferSlot = ((void *)0);
    } else {
        dc_ret = deriveCap(bufferSlot, bufferCap);
        if (dc_ret.status != EXCEPTION_NONE) {
            return dc_ret.status;
        }
        bufferCap = dc_ret.cap;

        exception_t e = checkValidIPCBuffer(bufferAddr, bufferCap);
        if (e != EXCEPTION_NONE) {
            return e;
        }
    }

    if (slotCapLongRunningDelete(
            (((cte_t *)((word_t)(cap_thread_cap_get_capTCBPtr(cap))&~((1ul << (11))-1ul)))+(tcbCTable))) ||
        slotCapLongRunningDelete(
            (((cte_t *)((word_t)(cap_thread_cap_get_capTCBPtr(cap))&~((1ul << (11))-1ul)))+(tcbVTable)))) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB Configure: CSpace or VSpace currently being deleted." ">>" "\033[0m" "\n", 0lu, __func__, 1090, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cRootData != 0) {
        cRootCap = updateCapData(false, cRootData, cRootCap);
    }

    dc_ret = deriveCap(cRootSlot, cRootCap);
    if (dc_ret.status != EXCEPTION_NONE) {
        return dc_ret.status;
    }
    cRootCap = dc_ret.cap;

    if (cap_get_capType(cRootCap) != cap_cnode_cap) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB Configure: CSpace cap is invalid." ">>" "\033[0m" "\n", 0lu, __func__, 1106, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (vRootData != 0) {
        vRootCap = updateCapData(false, vRootData, vRootCap);
    }

    dc_ret = deriveCap(vRootSlot, vRootCap);
    if (dc_ret.status != EXCEPTION_NONE) {
        return dc_ret.status;
    }
    vRootCap = dc_ret.cap;

    if (!isValidVTableRoot(vRootCap)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB Configure: VSpace cap is invalid." ">>" "\033[0m" "\n", 0lu, __func__, 1122, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksCurThread, ThreadState_Restart);
# 1139 "/host/kernel/src/object/tcb.c"
    return invokeTCB_ThreadControl(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), slot,
               faultEP, 0, 0,
               cRootCap, cRootSlot,
               vRootCap, vRootSlot,
               bufferAddr, bufferCap,
               bufferSlot, thread_control_update_space |
               thread_control_update_ipc_buffer);

}

exception_t decodeSetPriority(cap_t cap, word_t length, extra_caps_t excaps, word_t *buffer)
{
    if (length < 1 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetPriority: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 1153, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    prio_t newPrio = getSyscallArg(0, buffer);
    cap_t authCap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(authCap) != cap_thread_cap) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Set priority: authority cap not a TCB." ">>" "\033[0m" "\n", 0lu, __func__, 1162, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    tcb_t *authTCB = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(authCap)));
    exception_t status = checkPrio(newPrio, authTCB);
    if (status != EXCEPTION_NONE) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetPriority: Requested priority %lu too high (max %lu)." ">>" "\033[0m" "\n", 0lu, __func__, 1172, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (unsigned long) newPrio, (unsigned long) authTCB->tcbMCP); } while (0)
                                                                           ;
        return status;
    }

    setThreadState(ksCurThread, ThreadState_Restart);







    return invokeTCB_ThreadControl(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), ((void *)0),
               0, 0, newPrio,
               cap_null_cap_new(), ((void *)0),
               cap_null_cap_new(), ((void *)0),
               0, cap_null_cap_new(),
               ((void *)0), thread_control_update_priority);

}

exception_t decodeSetMCPriority(cap_t cap, word_t length, extra_caps_t excaps, word_t *buffer)
{
    if (length < 1 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetMCPriority: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 1197, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    prio_t newMcp = getSyscallArg(0, buffer);
    cap_t authCap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(authCap) != cap_thread_cap) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetMCPriority: authority cap not a TCB." ">>" "\033[0m" "\n", 0lu, __func__, 1206, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    tcb_t *authTCB = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(authCap)));
    exception_t status = checkPrio(newMcp, authTCB);
    if (status != EXCEPTION_NONE) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetMCPriority: Requested maximum controlled priority %lu too high (max %lu)." ">>" "\033[0m" "\n", 0lu, __func__, 1216, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (unsigned long) newMcp, (unsigned long) authTCB->tcbMCP); } while (0)
                                                                          ;
        return status;
    }

    setThreadState(ksCurThread, ThreadState_Restart);







    return invokeTCB_ThreadControl(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), ((void *)0),
               0, newMcp, 0,
               cap_null_cap_new(), ((void *)0),
               cap_null_cap_new(), ((void *)0),
               0, cap_null_cap_new(),
               ((void *)0), thread_control_update_mcp);

}
# 1271 "/host/kernel/src/object/tcb.c"
exception_t decodeSetSchedParams(cap_t cap, word_t length, extra_caps_t excaps, word_t *buffer)

{
    if (length < 2 || excaps.excaprefs[0] == ((void *)0)



       ) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetSchedParams: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 1279, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    prio_t newMcp = getSyscallArg(0, buffer);
    prio_t newPrio = getSyscallArg(1, buffer);
    cap_t authCap = excaps.excaprefs[0]->cap;






    if (cap_get_capType(authCap) != cap_thread_cap) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetSchedParams: authority cap not a TCB." ">>" "\033[0m" "\n", 0lu, __func__, 1294, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    tcb_t *authTCB = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(authCap)));
    exception_t status = checkPrio(newMcp, authTCB);
    if (status != EXCEPTION_NONE) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetSchedParams: Requested maximum controlled priority %lu too high (max %lu)." ">>" "\033[0m" "\n", 0lu, __func__, 1304, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (unsigned long) newMcp, (unsigned long) authTCB->tcbMCP); } while (0)
                                                                          ;
        return status;
    }

    status = checkPrio(newPrio, authTCB);
    if (status != EXCEPTION_NONE) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetSchedParams: Requested priority %lu too high (max %lu)." ">>" "\033[0m" "\n", 0lu, __func__, 1311, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (unsigned long) newPrio, (unsigned long) authTCB->tcbMCP); } while (0)
                                                                           ;
        return status;
    }
# 1353 "/host/kernel/src/object/tcb.c"
    setThreadState(ksCurThread, ThreadState_Restart);
# 1365 "/host/kernel/src/object/tcb.c"
    return invokeTCB_ThreadControl(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), ((void *)0),
               0, newMcp, newPrio,
               cap_null_cap_new(), ((void *)0),
               cap_null_cap_new(), ((void *)0),
               0, cap_null_cap_new(),
               ((void *)0), thread_control_update_mcp |
               thread_control_update_priority);

}


exception_t decodeSetIPCBuffer(cap_t cap, word_t length, cte_t *slot,
                               extra_caps_t excaps, word_t *buffer)
{
    cptr_t cptr_bufferPtr;
    cap_t bufferCap;
    cte_t *bufferSlot;

    if (length < 1 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetIPCBuffer: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 1385, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    cptr_bufferPtr = getSyscallArg(0, buffer);
    bufferSlot = excaps.excaprefs[0];
    bufferCap = excaps.excaprefs[0]->cap;

    if (cptr_bufferPtr == 0) {
        bufferSlot = ((void *)0);
    } else {
        exception_t e;
        deriveCap_ret_t dc_ret;

        dc_ret = deriveCap(bufferSlot, bufferCap);
        if (dc_ret.status != EXCEPTION_NONE) {
            return dc_ret.status;
        }
        bufferCap = dc_ret.cap;
        e = checkValidIPCBuffer(cptr_bufferPtr, bufferCap);
        if (e != EXCEPTION_NONE) {
            return e;
        }
    }

    setThreadState(ksCurThread, ThreadState_Restart);
# 1422 "/host/kernel/src/object/tcb.c"
    return invokeTCB_ThreadControl(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), slot,
               0, 0, 0,
               cap_null_cap_new(), ((void *)0),
               cap_null_cap_new(), ((void *)0),
               cptr_bufferPtr, bufferCap,
               bufferSlot, thread_control_update_ipc_buffer);


}






exception_t decodeSetSpace(cap_t cap, word_t length, cte_t *slot,
                           extra_caps_t excaps, word_t *buffer)
{
    word_t cRootData, vRootData;
    cte_t *cRootSlot, *vRootSlot;
    cap_t cRootCap, vRootCap;
    deriveCap_ret_t dc_ret;

    if (length < 3 || excaps.excaprefs[0] == ((void *)0)
        || excaps.excaprefs[1] == ((void *)0)



       ) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetSpace: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 1452, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }
# 1468 "/host/kernel/src/object/tcb.c"
    cptr_t faultEP = getSyscallArg(0, buffer);
    cRootData = getSyscallArg(1, buffer);
    vRootData = getSyscallArg(2, buffer);

    cRootSlot = excaps.excaprefs[0];
    cRootCap = excaps.excaprefs[0]->cap;
    vRootSlot = excaps.excaprefs[1];
    vRootCap = excaps.excaprefs[1]->cap;


    if (slotCapLongRunningDelete(
            (((cte_t *)((word_t)(cap_thread_cap_get_capTCBPtr(cap))&~((1ul << (11))-1ul)))+(tcbCTable))) ||
        slotCapLongRunningDelete(
            (((cte_t *)((word_t)(cap_thread_cap_get_capTCBPtr(cap))&~((1ul << (11))-1ul)))+(tcbVTable)))) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetSpace: CSpace or VSpace currently being deleted." ">>" "\033[0m" "\n", 0lu, __func__, 1482, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cRootData != 0) {
        cRootCap = updateCapData(false, cRootData, cRootCap);
    }

    dc_ret = deriveCap(cRootSlot, cRootCap);
    if (dc_ret.status != EXCEPTION_NONE) {
        return dc_ret.status;
    }
    cRootCap = dc_ret.cap;

    if (cap_get_capType(cRootCap) != cap_cnode_cap) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetSpace: Invalid CNode cap." ">>" "\033[0m" "\n", 0lu, __func__, 1498, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (vRootData != 0) {
        vRootCap = updateCapData(false, vRootData, vRootCap);
    }

    dc_ret = deriveCap(vRootSlot, vRootCap);
    if (dc_ret.status != EXCEPTION_NONE) {
        return dc_ret.status;
    }
    vRootCap = dc_ret.cap;

    if (!isValidVTableRoot(vRootCap)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB SetSpace: Invalid VSpace cap." ">>" "\033[0m" "\n", 0lu, __func__, 1514, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
# 1528 "/host/kernel/src/object/tcb.c"
    setThreadState(ksCurThread, ThreadState_Restart);
# 1538 "/host/kernel/src/object/tcb.c"
    return invokeTCB_ThreadControl(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), slot,
               faultEP,
               0, 0,
               cRootCap, cRootSlot,
               vRootCap, vRootSlot,
               0, cap_null_cap_new(), ((void *)0), thread_control_update_space);

}

exception_t decodeDomainInvocation(word_t invLabel, word_t length, extra_caps_t excaps, word_t *buffer)
{
    word_t domain;
    cap_t tcap;

    if (__builtin_expect(!!(invLabel != DomainSetSet), 0)) {
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (__builtin_expect(!!(length == 0), 0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Domain Configure: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 1559, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    } else {
        domain = getSyscallArg(0, buffer);
        if (domain >= 1) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Domain Configure: invalid domain (%lu >= %u)." ">>" "\033[0m" "\n", 0lu, __func__, 1566, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), domain, 1); } while (0)
                                                 ;
            current_syscall_error.type = seL4_InvalidArgument;
            current_syscall_error.invalidArgumentNumber = 0;
            return EXCEPTION_SYSCALL_ERROR;
        }
    }

    if (__builtin_expect(!!(excaps.excaprefs[0] == ((void *)0)), 0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Domain Configure: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 1574, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    tcap = excaps.excaprefs[0]->cap;
    if (__builtin_expect(!!(cap_get_capType(tcap) != cap_thread_cap), 0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Domain Configure: thread cap required." ">>" "\033[0m" "\n", 0lu, __func__, 1581, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksCurThread, ThreadState_Restart);
    setDomain(((tcb_t *)(cap_thread_cap_get_capTCBPtr(tcap))), domain);
    return EXCEPTION_NONE;
}

exception_t decodeBindNotification(cap_t cap, extra_caps_t excaps)
{
    notification_t *ntfnPtr;
    tcb_t *tcb;
    cap_t ntfn_cap;

    if (excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB BindNotification: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 1599, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    tcb = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap)));

    if (tcb->tcbBoundNotification) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB BindNotification: TCB already has a bound notification." ">>" "\033[0m" "\n", 0lu, __func__, 1607, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    ntfn_cap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(ntfn_cap) == cap_notification_cap) {
        ntfnPtr = ((notification_t *)(cap_notification_cap_get_capNtfnPtr(ntfn_cap)));
    } else {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB BindNotification: Notification is invalid." ">>" "\033[0m" "\n", 0lu, __func__, 1617, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (!cap_notification_cap_get_capNtfnCanReceive(ntfn_cap)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB BindNotification: Insufficient access rights" ">>" "\033[0m" "\n", 0lu, __func__, 1623, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if ((tcb_t *)notification_ptr_get_ntfnQueue_head(ntfnPtr)
        || (tcb_t *)notification_ptr_get_ntfnBoundTCB(ntfnPtr)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB BindNotification: Notification cannot be bound." ">>" "\033[0m" "\n", 0lu, __func__, 1630, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }


    setThreadState(ksCurThread, ThreadState_Restart);
    return invokeTCB_NotificationControl(tcb, ntfnPtr);
}

exception_t decodeUnbindNotification(cap_t cap)
{
    tcb_t *tcb;

    tcb = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap)));

    if (!tcb->tcbBoundNotification) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "TCB UnbindNotification: TCB already has no bound Notification." ">>" "\033[0m" "\n", 0lu, __func__, 1647, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksCurThread, ThreadState_Restart);
    return invokeTCB_NotificationControl(tcb, ((void *)0));
}

/* The following functions sit in the preemption monad and implement the
 * preemptible, non-faulting bottom end of a TCB invocation. */
exception_t invokeTCB_Suspend(tcb_t *thread)
{
    suspend(thread);
    return EXCEPTION_NONE;
}

exception_t invokeTCB_Resume(tcb_t *thread)
{
    restart(thread);
    return EXCEPTION_NONE;
}
# 1752 "/host/kernel/src/object/tcb.c"
exception_t invokeTCB_ThreadControl(tcb_t *target, cte_t *slot,
                                    cptr_t faultep, prio_t mcp, prio_t priority,
                                    cap_t cRoot_newCap, cte_t *cRoot_srcSlot,
                                    cap_t vRoot_newCap, cte_t *vRoot_srcSlot,
                                    word_t bufferAddr, cap_t bufferCap,
                                    cte_t *bufferSrcSlot,
                                    thread_control_flag_t updateFlags)
{
    exception_t e;
    cap_t tCap = cap_thread_cap_new((word_t)target);

    if (updateFlags & thread_control_update_space) {
        target->tcbFaultHandler = faultep;
    }

    if (updateFlags & thread_control_update_mcp) {
        setMCPriority(target, mcp);
    }

    if (updateFlags & thread_control_update_space) {
        cte_t *rootSlot;

        rootSlot = (((cte_t *)((word_t)(target)&~((1ul << (11))-1ul)))+(tcbCTable));
        e = cteDelete(rootSlot, true);
        if (e != EXCEPTION_NONE) {
            return e;
        }
        if (sameObjectAs(cRoot_newCap, cRoot_srcSlot->cap) &&
            sameObjectAs(tCap, slot->cap)) {
            cteInsert(cRoot_newCap, cRoot_srcSlot, rootSlot);
        }
    }

    if (updateFlags & thread_control_update_space) {
        cte_t *rootSlot;

        rootSlot = (((cte_t *)((word_t)(target)&~((1ul << (11))-1ul)))+(tcbVTable));
        e = cteDelete(rootSlot, true);
        if (e != EXCEPTION_NONE) {
            return e;
        }
        if (sameObjectAs(vRoot_newCap, vRoot_srcSlot->cap) &&
            sameObjectAs(tCap, slot->cap)) {
            cteInsert(vRoot_newCap, vRoot_srcSlot, rootSlot);
        }
    }

    if (updateFlags & thread_control_update_ipc_buffer) {
        cte_t *bufferSlot;

        bufferSlot = (((cte_t *)((word_t)(target)&~((1ul << (11))-1ul)))+(tcbBuffer));
        e = cteDelete(bufferSlot, true);
        if (e != EXCEPTION_NONE) {
            return e;
        }
        target->tcbIPCBuffer = bufferAddr;

        if (bufferSrcSlot && sameObjectAs(bufferCap, bufferSrcSlot->cap) &&
            sameObjectAs(tCap, slot->cap)) {
            cteInsert(bufferCap, bufferSrcSlot, bufferSlot);
        }

        if (target == ksCurThread) {
            rescheduleRequired();
        }
    }

    if (updateFlags & thread_control_update_priority) {
        setPriority(target, priority);
    }

    return EXCEPTION_NONE;
}
# 1862 "/host/kernel/src/object/tcb.c"
exception_t invokeTCB_CopyRegisters(tcb_t *dest, tcb_t *tcb_src,
                                    bool_t suspendSource, bool_t resumeTarget,
                                    bool_t transferFrame, bool_t transferInteger,
                                    word_t transferArch)
{
    if (suspendSource) {
        suspend(tcb_src);
    }

    if (resumeTarget) {
        restart(dest);
    }

    if (transferFrame) {
        word_t i;
        word_t v;
        word_t pc;

        for (i = 0; i < n_frameRegisters; i++) {
            v = getRegister(tcb_src, frameRegisters[i]);
            setRegister(dest, frameRegisters[i], v);
        }

        pc = getRestartPC(dest);
        setNextPC(dest, pc);
    }

    if (transferInteger) {
        word_t i;
        word_t v;

        for (i = 0; i < n_gpRegisters; i++) {
            v = getRegister(tcb_src, gpRegisters[i]);
            setRegister(dest, gpRegisters[i], v);
        }
    }

    Arch_postModifyRegisters(dest);

    if (dest == ksCurThread) {
        /* If we modified the current thread we may need to reschedule
         * due to changing registers are only reloaded in Arch_switchToThread */
        rescheduleRequired();
    }

    return Arch_performTransfer(transferArch, tcb_src, dest);
}

/* ReadRegisters is a special case: replyFromKernel & setMRs are
 * unfolded here, in order to avoid passing the large reply message up
 * to the top level in a global (and double-copying). We prevent the
 * top-level replyFromKernel_success_empty() from running by setting the
 * thread state. Retype does this too.
 */
exception_t invokeTCB_ReadRegisters(tcb_t *tcb_src, bool_t suspendSource,
                                    word_t n, word_t arch, bool_t call)
{
    word_t i, j;
    exception_t e;
    tcb_t *thread;

    thread = ksCurThread;

    if (suspendSource) {
        suspend(tcb_src);
    }

    e = Arch_performTransfer(arch, tcb_src, ksCurThread);
    if (e != EXCEPTION_NONE) {
        return e;
    }

    if (call) {
        word_t *ipcBuffer;

        ipcBuffer = lookupIPCBuffer(true, thread);

        setRegister(thread, badgeRegister, 0);

        for (i = 0; i < n && i < n_frameRegisters && i < n_msgRegisters; i++) {
            setRegister(thread, msgRegisters[i],
                        getRegister(tcb_src, frameRegisters[i]));
        }

        if (ipcBuffer != ((void *)0) && i < n && i < n_frameRegisters) {
            for (; i < n && i < n_frameRegisters; i++) {
                ipcBuffer[i + 1] = getRegister(tcb_src, frameRegisters[i]);
            }
        }

        j = i;

        for (i = 0; i < n_gpRegisters && i + n_frameRegisters < n
             && i + n_frameRegisters < n_msgRegisters; i++) {
            setRegister(thread, msgRegisters[i + n_frameRegisters],
                        getRegister(tcb_src, gpRegisters[i]));
        }

        if (ipcBuffer != ((void *)0) && i < n_gpRegisters
            && i + n_frameRegisters < n) {
            for (; i < n_gpRegisters && i + n_frameRegisters < n; i++) {
                ipcBuffer[i + n_frameRegisters + 1] =
                    getRegister(tcb_src, gpRegisters[i]);
            }
        }

        setRegister(thread, msgInfoRegister, wordFromMessageInfo(
                        seL4_MessageInfo_new(0, 0, 0, i + j)));
    }
    setThreadState(thread, ThreadState_Running);

    return EXCEPTION_NONE;
}

exception_t invokeTCB_WriteRegisters(tcb_t *dest, bool_t resumeTarget,
                                     word_t n, word_t arch, word_t *buffer)
{
    word_t i;
    word_t pc;
    exception_t e;
    bool_t archInfo;

    e = Arch_performTransfer(arch, ksCurThread, dest);
    if (e != EXCEPTION_NONE) {
        return e;
    }

    if (n > n_frameRegisters + n_gpRegisters) {
        n = n_frameRegisters + n_gpRegisters;
    }

    archInfo = Arch_getSanitiseRegisterInfo(dest);

    for (i = 0; i < n_frameRegisters && i < n; i++) {
        /* Offset of 2 to get past the initial syscall arguments */
        setRegister(dest, frameRegisters[i],
                    sanitiseRegister(frameRegisters[i],
                                     getSyscallArg(i + 2, buffer), archInfo));
    }

    for (i = 0; i < n_gpRegisters && i + n_frameRegisters < n; i++) {
        setRegister(dest, gpRegisters[i],
                    sanitiseRegister(gpRegisters[i],
                                     getSyscallArg(i + n_frameRegisters + 2,
                                                   buffer), archInfo));
    }

    pc = getRestartPC(dest);
    setNextPC(dest, pc);

    Arch_postModifyRegisters(dest);

    if (resumeTarget) {
        restart(dest);
    }

    if (dest == ksCurThread) {
        /* If we modified the current thread we may need to reschedule
         * due to changing registers are only reloaded in Arch_switchToThread */
        rescheduleRequired();
    }

    return EXCEPTION_NONE;
}

exception_t invokeTCB_NotificationControl(tcb_t *tcb, notification_t *ntfnPtr)
{
    if (ntfnPtr) {
        bindNotification(tcb, ntfnPtr);
    } else {
        unbindNotification(tcb);
    }

    return EXCEPTION_NONE;
}


void setThreadName(tcb_t *tcb, const char *name)
{
    strlcpy(((debug_tcb_t *)(((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, name, ((1ul << (11 -1)) - (tcbCNodeEntries * sizeof(cte_t)) - sizeof(debug_tcb_t)));
}


word_t setMRs_syscall_error(tcb_t *thread, word_t *receiveIPCBuffer)
{
    switch (current_syscall_error.type) {
    case seL4_InvalidArgument:
        return setMR(thread, receiveIPCBuffer, 0,
                     current_syscall_error.invalidArgumentNumber);

    case seL4_InvalidCapability:
        return setMR(thread, receiveIPCBuffer, 0,
                     current_syscall_error.invalidCapNumber);

    case seL4_IllegalOperation:
        return 0;

    case seL4_RangeError:
        setMR(thread, receiveIPCBuffer, 0,
              current_syscall_error.rangeErrorMin);
        return setMR(thread, receiveIPCBuffer, 1,
                     current_syscall_error.rangeErrorMax);

    case seL4_AlignmentError:
        return 0;

    case seL4_FailedLookup:
        setMR(thread, receiveIPCBuffer, 0,
              current_syscall_error.failedLookupWasSource ? 1 : 0);
        return setMRs_lookup_failure(thread, receiveIPCBuffer,
                                     current_lookup_fault, 1);

    case seL4_TruncatedMessage:
    case seL4_DeleteFirst:
    case seL4_RevokeFirst:
        return 0;
    case seL4_NotEnoughMemory:
        return setMR(thread, receiveIPCBuffer, 0,
                     current_syscall_error.memoryLeft);
    default:
        _fail("Invalid syscall error", "/host/kernel/src/object/tcb.c", 2082, __func__);
    }
}
# 1 "/host/kernel/src/object/untyped.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */





# 1 "kernel/gen_headers/api/invocation.h" 1

/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 ** SPDX-License-Identifier: GPL-2.0-only
 */

/* This header was generated by kernel/tools/invocation_header_gen.py.
 *
 * To add an invocation call number, edit libsel4/include/interfaces/sel4.xml.
 *
 */
# 12 "/host/kernel/src/object/untyped.c" 2
# 21 "/host/kernel/src/object/untyped.c"
static word_t alignUp(word_t baseValue, word_t alignment)
{
    return (baseValue + ((1ul << (alignment)) - 1)) & ~((1ul << (alignment))-1ul);
}

exception_t decodeUntypedInvocation(word_t invLabel, word_t length, cte_t *slot,
                                    cap_t cap, extra_caps_t excaps,
                                    bool_t call, word_t *buffer)
{
    word_t newType, userObjSize, nodeIndex;
    word_t nodeDepth, nodeOffset, nodeWindow;
    cte_t *rootSlot __attribute__((unused));
    exception_t status;
    cap_t nodeCap;
    lookupSlot_ret_t lu_ret;
    word_t nodeSize;
    word_t i;
    slot_range_t slots;
    word_t freeRef, alignedFreeRef, objectSize, untypedFreeBytes;
    word_t freeIndex;
    bool_t deviceMemory;
    bool_t reset;

    /* Ensure operation is valid. */
    if (invLabel != UntypedRetype) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped cap: Illegal operation attempted." ">>" "\033[0m" "\n", 0lu, __func__, 46, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    /* Ensure message length valid. */
    if (length < 6 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped invocation: Truncated message." ">>" "\033[0m" "\n", 0lu, __func__, 53, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    /* Fetch arguments. */
    newType = getSyscallArg(0, buffer);
    userObjSize = getSyscallArg(1, buffer);
    nodeIndex = getSyscallArg(2, buffer);
    nodeDepth = getSyscallArg(3, buffer);
    nodeOffset = getSyscallArg(4, buffer);
    nodeWindow = getSyscallArg(5, buffer);

    rootSlot = excaps.excaprefs[0];

    /* Is the requested object type valid? */
    if (newType >= seL4_ObjectTypeCount) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped Retype: Invalid object type." ">>" "\033[0m" "\n", 0lu, __func__, 70, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 0;
        return EXCEPTION_SYSCALL_ERROR;
    }

    objectSize = getObjectSize(newType, userObjSize);

    /* Exclude impossibly large object sizes. getObjectSize can overflow if userObjSize
       is close to 2^wordBits, which is nonsensical in any case, so we check that this
       did not happen. userObjSize will always need to be less than wordBits. */
    if (userObjSize >= (1 << 6) || objectSize > 47) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped Retype: Invalid object size." ">>" "\033[0m" "\n", 0lu, __func__, 82, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = 47;
        return EXCEPTION_SYSCALL_ERROR;
    }

    /* If the target object is a CNode, is it at least size 1? */
    if (newType == seL4_CapTableObject && userObjSize == 0) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped Retype: Requested CapTable size too small." ">>" "\033[0m" "\n", 0lu, __func__, 91, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    /* If the target object is a Untyped, is it at least size 4? */
    if (newType == seL4_UntypedObject && userObjSize < 4) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped Retype: Requested UntypedItem size too small." ">>" "\033[0m" "\n", 0lu, __func__, 99, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }
# 114 "/host/kernel/src/object/untyped.c"
    /* Lookup the destination CNode (where our caps will be placed in). */
    if (nodeDepth == 0) {
        nodeCap = excaps.excaprefs[0]->cap;
    } else {
        cap_t rootCap = excaps.excaprefs[0]->cap;
        lu_ret = lookupTargetSlot(rootCap, nodeIndex, nodeDepth);
        if (lu_ret.status != EXCEPTION_NONE) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped Retype: Invalid destination address." ">>" "\033[0m" "\n", 0lu, __func__, 121, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
            return lu_ret.status;
        }
        nodeCap = lu_ret.slot->cap;
    }

    /* Is the destination actually a CNode? */
    if (cap_get_capType(nodeCap) != cap_cnode_cap) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped Retype: Destination cap invalid or read-only." ">>" "\033[0m" "\n", 0lu, __func__, 129, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = 0;
        current_lookup_fault = lookup_fault_missing_capability_new(nodeDepth);
        return EXCEPTION_SYSCALL_ERROR;
    }

    /* Is the region where the user wants to put the caps valid? */
    nodeSize = 1ul << cap_cnode_cap_get_capCNodeRadix(nodeCap);
    if (nodeOffset > nodeSize - 1) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped Retype: Destination node offset #%d too large." ">>" "\033[0m" "\n", 0lu, __func__, 140, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (int)nodeOffset); } while (0)
                                  ;
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = nodeSize - 1;
        return EXCEPTION_SYSCALL_ERROR;
    }
    if (nodeWindow < 1 || nodeWindow > 256) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped Retype: Number of requested objects (%d) too small or large." ">>" "\033[0m" "\n", 0lu, __func__, 148, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (int)nodeWindow); } while (0)
                                  ;
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 1;
        current_syscall_error.rangeErrorMax = 256;
        return EXCEPTION_SYSCALL_ERROR;
    }
    if (nodeWindow > nodeSize - nodeOffset) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped Retype: Requested destination window overruns size of node." ">>" "\033[0m" "\n", 0lu, __func__, 155, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 1;
        current_syscall_error.rangeErrorMax = nodeSize - nodeOffset;
        return EXCEPTION_SYSCALL_ERROR;
    }

    /* Ensure that the destination slots are all empty. */
    slots.cnode = ((cte_t *)(cap_cnode_cap_get_capCNodePtr(nodeCap)));
    slots.offset = nodeOffset;
    slots.length = nodeWindow;
    for (i = nodeOffset; i < nodeOffset + nodeWindow; i++) {
        status = ensureEmptySlot(slots.cnode + i);
        if (status != EXCEPTION_NONE) {
            do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped Retype: Slot #%d in destination window non-empty." ">>" "\033[0m" "\n", 0lu, __func__, 170, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (int)i); } while (0)
                             ;
            return status;
        }
    }

    /*
     * Determine where in the Untyped region we should start allocating new
     * objects.
     *
     * If we have no children, we can start allocating from the beginning of
     * our untyped, regardless of what the "free" value in the cap states.
     * (This may happen if all of the objects beneath us got deleted).
     *
     * If we have children, we just keep allocating from the "free" value
     * recorded in the cap.
     */
    status = ensureNoChildren(slot);
    if (status != EXCEPTION_NONE) {
        freeIndex = cap_untyped_cap_get_capFreeIndex(cap);
        reset = false;
    } else {
        freeIndex = 0;
        reset = true;
    }
    freeRef = ((word_t)(((word_t)(cap_untyped_cap_get_capPtr(cap))) + ((freeIndex)<<4)));

    /*
     * Determine the maximum number of objects we can create, and return an
     * error if we don't have enough space.
     *
     * We don't need to worry about alignment in this case, because if anything
     * fits, it will also fit aligned up (by packing it on the right hand side
     * of the untyped).
     */
    untypedFreeBytes = (1ul << (cap_untyped_cap_get_capBlockSize(cap))) -
                       ((freeIndex)<<4);

    if ((untypedFreeBytes >> objectSize) < nodeWindow) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped Retype: Insufficient memory " "(%lu * %lu bytes needed, %lu bytes available)." ">>" "\033[0m" "\n", 0lu, __func__, 212, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (word_t)nodeWindow, (objectSize >= (1 << 6) ? -1 : (1ul << objectSize)), (word_t)(untypedFreeBytes)); } while (0)



                                             ;
        current_syscall_error.type = seL4_NotEnoughMemory;
        current_syscall_error.memoryLeft = untypedFreeBytes;
        return EXCEPTION_SYSCALL_ERROR;
    }

    deviceMemory = cap_untyped_cap_get_capIsDevice(cap);
    if ((deviceMemory && !Arch_isFrameType(newType))
        && newType != seL4_UntypedObject) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Untyped Retype: Creating kernel objects with device untyped" ">>" "\033[0m" "\n", 0lu, __func__, 221, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    /* Align up the free region so that it is aligned to the target object's
     * size. */
    alignedFreeRef = alignUp(freeRef, objectSize);

    /* Perform the retype. */
    setThreadState(ksCurThread, ThreadState_Restart);
    return invokeUntyped_Retype(slot, reset,
                                (void *)alignedFreeRef, newType, userObjSize,
                                slots, deviceMemory);
}

static exception_t resetUntypedCap(cte_t *srcSlot)
{
    cap_t prev_cap = srcSlot->cap;
    word_t block_size = cap_untyped_cap_get_capBlockSize(prev_cap);
    void *regionBase = ((word_t *)(cap_untyped_cap_get_capPtr(prev_cap)));
    int chunk = 8;
    word_t offset = ((cap_untyped_cap_get_capFreeIndex(prev_cap))<<4);
    exception_t status;
    bool_t deviceMemory = cap_untyped_cap_get_capIsDevice(prev_cap);

    if (offset == 0) {
        return EXCEPTION_NONE;
    }

    /** AUXUPD: "(True, typ_region_bytes (ptr_val \<acute>regionBase)
        (unat \<acute>block_size))" */
    /** GHOSTUPD: "(True, gs_clear_region (ptr_val \<acute>regionBase)
        (unat \<acute>block_size))" */

    if (deviceMemory || block_size < chunk) {
        if (! deviceMemory) {
            clearMemory(regionBase, block_size);
        }
        srcSlot->cap = cap_untyped_cap_set_capFreeIndex(prev_cap, 0);
    } else {
        for (offset = (((offset - 1) >> (chunk)) << (chunk));
             offset != - (1ul << (chunk)); offset -= (1ul << (chunk))) {
            clearMemory(((void *)(((word_t)(regionBase)) + (offset))), chunk);
            srcSlot->cap = cap_untyped_cap_set_capFreeIndex(prev_cap, ((offset)>>4));
            status = preemptionPoint();
            if (status != EXCEPTION_NONE) {
                return status;
            }
        }
    }
    return EXCEPTION_NONE;
}

exception_t invokeUntyped_Retype(cte_t *srcSlot,
                                 bool_t reset, void *retypeBase,
                                 object_t newType, word_t userSize,
                                 slot_range_t destSlots, bool_t deviceMemory)
{
    word_t freeRef;
    word_t totalObjectSize;
    void *regionBase = ((word_t *)(cap_untyped_cap_get_capPtr(srcSlot->cap)));
    exception_t status;

    freeRef = ((word_t)(((word_t)(regionBase)) + ((cap_untyped_cap_get_capFreeIndex(srcSlot->cap))<<4)));

    if (reset) {
        status = resetUntypedCap(srcSlot);
        if (status != EXCEPTION_NONE) {
            return status;
        }
    }

    /* Update the amount of free space left in this untyped cap.
     *
     * Note that userSize is not necessarily the true size of the object in
     * memory. In the case where newType is seL4_CapTableObject, the size is
     * transformed by getObjectSize. */
    totalObjectSize = destSlots.length << getObjectSize(newType, userSize);
    freeRef = (word_t)retypeBase + totalObjectSize;
    srcSlot->cap = cap_untyped_cap_set_capFreeIndex(srcSlot->cap,
                                                    (((word_t)(freeRef) - (word_t)(regionBase))>>4));

    /* Create new objects and caps. */
    createNewObjects(newType, srcSlot, destSlots, retypeBase, userSize,
                     deviceMemory);

    return EXCEPTION_NONE;
}
# 1 "/host/kernel/src/plat/pc99/machine/acpi.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 16 "/host/kernel/src/plat/pc99/machine/acpi.c"
enum acpi_type {
    ACPI_RSDP,
    ACPI_RSDT
};

/* DMA Remapping Reporting Table */
typedef struct acpi_dmar {
    acpi_header_t header;
    uint8_t host_addr_width;
    uint8_t flags;
    uint8_t reserved[10];
} acpi_dmar_t;
typedef int __assert_failed_acpi_dmar_packed[(sizeof(acpi_dmar_t) == sizeof(acpi_header_t) + 12) ? 1 : -1];


/* DMA Remapping Structure Header */
typedef struct acpi_dmar_header {
    uint16_t type;
    uint16_t length;
} acpi_dmar_header_t;
typedef int __assert_failed_acpi_dmar_header_packed[(sizeof(acpi_dmar_header_t) == 4) ? 1 : -1];

/* DMA Remapping Structure Types */
enum acpi_table_dmar_struct_type {
    DMAR_DRHD = 0,
    DMAR_RMRR = 1,
    DMAR_ATSR = 2,
};

/* DMA Remapping Hardware unit Definition */
typedef struct acpi_dmar_drhd {
    acpi_dmar_header_t header;
    uint8_t flags;
    uint8_t reserved;
    uint16_t segment;
    uint32_t reg_base[2];
} acpi_dmar_drhd_t;
typedef int __assert_failed_acpi_dmar_drhd_packed[(sizeof(acpi_dmar_drhd_t) == sizeof(acpi_dmar_header_t) + 12) ? 1 : -1];


/* Reserved Memory Region Reporting structure Definition */
typedef struct acpi_dmar_devscope {
    uint8_t type;
    uint8_t length;
    uint16_t reserved;
    uint8_t enum_id;
    uint8_t start_bus;
    struct {
        uint8_t dev;
        uint8_t fun;
    } path_0;
} acpi_dmar_devscope_t;
typedef int __assert_failed_acpi_dmar_devscope_packed[(sizeof(acpi_dmar_devscope_t) == 8) ? 1 : -1];

/* Reserved Memory Region Reporting structure Definition */
typedef struct acpi_dmar_rmrr {
    acpi_dmar_header_t header;
    uint16_t reserved;
    uint16_t segment;
    uint32_t reg_base[2];
    uint32_t reg_limit[2];
    acpi_dmar_devscope_t devscope_0;
} acpi_dmar_rmrr_t;
typedef int __assert_failed_acpi_dmar_rmrr_packed[(sizeof(acpi_dmar_rmrr_t) == sizeof(acpi_dmar_header_t) + 20 + sizeof(acpi_dmar_devscope_t)) ? 1 : -1];


/* Fixed ACPI Description Table (FADT), partial as we only need flags */
typedef struct acpi_fadt {
    acpi_header_t header;
    uint8_t reserved[76];
    uint32_t flags;
} acpi_fadt_t;
typedef int __assert_failed_acpi_fadt_packed[(sizeof(acpi_fadt_t) == sizeof(acpi_header_t) + 80) ? 1 : -1];


/* Multiple APIC Description Table (MADT) */
typedef struct acpi_madt {
    acpi_header_t header;
    uint32_t apic_addr;
    uint32_t flags;
} acpi_madt_t;
typedef int __assert_failed_acpi_madt_packed[(sizeof(acpi_madt_t) == sizeof(acpi_header_t) + 8) ? 1 : -1];


typedef struct acpi_madt_header {
    uint8_t type;
    uint8_t length;
} acpi_madt_header_t;
typedef int __assert_failed_acpi_madt_header_packed[(sizeof(acpi_madt_header_t) == 2) ? 1 : -1];

enum acpi_table_madt_struct_type {
    MADT_APIC = 0,
    MADT_IOAPIC = 1,
    MADT_ISO = 2,
    MADT_x2APIC = 9
};

typedef struct acpi_madt_apic {
    acpi_madt_header_t header;
    uint8_t cpu_id;
    uint8_t apic_id;
    uint32_t flags;
} acpi_madt_apic_t;
typedef int __assert_failed_acpi_madt_apic_packed[(sizeof(acpi_madt_apic_t) == sizeof(acpi_madt_header_t) + 6) ? 1 : -1];


typedef struct acpi_madt_x2apic {
    acpi_madt_header_t header;
    uint16_t reserved;
    uint32_t x2apic_id;
    uint32_t flags;
    uint32_t acpi_processor_uid;
} acpi_madt_x2apic_t;
typedef int __assert_failed_acpi_madt_x2apic_packed[(sizeof(acpi_madt_x2apic_t) == sizeof(acpi_madt_header_t) + 14) ? 1 : -1];


typedef struct acpi_madt_ioapic {
    acpi_madt_header_t header;
    uint8_t ioapic_id;
    uint8_t reserved[1];
    uint32_t ioapic_addr;
    uint32_t gsib;
} acpi_madt_ioapic_t;
typedef int __assert_failed_acpi_madt_ioapic_packed[(sizeof(acpi_madt_ioapic_t) == sizeof(acpi_madt_header_t) + 10) ? 1 : -1];


typedef struct acpi_madt_iso {
    acpi_madt_header_t header;
    uint8_t bus; /* always 0 (ISA) */
    uint8_t source;
    uint32_t gsi;
    uint16_t flags;
} acpi_madt_iso_t;
/* We can't assert on the sizeof acpi_madt_iso because it contains trailing
 * padding.
 */
typedef int __assert_failed_acpi_madt_iso_packed[(__builtin_offsetof(acpi_madt_iso_t, flags) == sizeof(acpi_madt_header_t) + 6) ? 1 : -1];


/* workaround because string literals are not supported by C parser */
const char acpi_str_rsd[] = {'R', 'S', 'D', ' ', 'P', 'T', 'R', ' ', 0};
const char acpi_str_fadt[] = {'F', 'A', 'C', 'P', 0};
const char acpi_str_apic[] = {'A', 'P', 'I', 'C', 0};
const char acpi_str_dmar[] = {'D', 'M', 'A', 'R', 0};

__attribute__((__section__(".boot.text"))) static uint8_t acpi_calc_checksum(char *start, uint32_t length)
{
    uint8_t checksum = 0;

    while (length > 0) {
        checksum += *start;
        start++;
        length--;
    }
    return checksum;
}

__attribute__((__section__(".boot.text"))) static acpi_rsdp_t *acpi_get_rsdp(void)
{
    char *addr;

    for (addr = (char *)0x0e0000; addr < (char *)0x100000; addr += 16) {
        if (strncmp(addr, acpi_str_rsd, 8) == 0) {
            if (acpi_calc_checksum(addr, ACPI_V1_SIZE) == 0) {
                return (acpi_rsdp_t *)addr;
            }
        }
    }
    return ((void *)0);
}

__attribute__((__section__(".boot.text"))) static void *acpi_table_init(void *entry, enum acpi_type table_type)
{
    void *acpi_table;
    unsigned int pages_for_table;
    unsigned int pages_for_header = 1;

    /* if we need to map another page to read header */
    unsigned long offset_in_page = (unsigned long)entry & ((1ul << (21))-1ul);
    if (((1ul << (21))-1ul) - offset_in_page < sizeof(acpi_rsdp_t)) {
        pages_for_header++;
    }

    /* map in table's header */
    acpi_table = map_temp_boot_page(entry, pages_for_header);

    switch (table_type) {
    case ACPI_RSDP: {
        acpi_rsdp_t *rsdp_entry = (acpi_rsdp_t *)entry;
        pages_for_table = (rsdp_entry->length + offset_in_page) / ((1ul << (21))-1ul) + 1;
        break;
    }
    case ACPI_RSDT: { // RSDT, MADT, DMAR etc.
        acpi_rsdt_t *rsdt_entry = (acpi_rsdt_t *)entry;
        pages_for_table = (rsdt_entry->header.length + offset_in_page) / ((1ul << (21))-1ul) + 1;
        break;
    }
    default:
        kprintf("Error: Mapping unknown ACPI table type\n");
        if(!(false)) _assert_fail("false", "/host/kernel/src/plat/pc99/machine/acpi.c", 215, __FUNCTION__);
        return ((void *)0);
    }

    /* map in full table */
    acpi_table = map_temp_boot_page(entry, pages_for_table);

    return acpi_table;
}

__attribute__((__section__(".boot.text"))) bool_t acpi_init(acpi_rsdp_t *rsdp_data)
{
    acpi_rsdp_t *acpi_rsdp = acpi_get_rsdp();

    if (acpi_rsdp == ((void *)0)) {
        kprintf("BIOS: No ACPI support detected\n");
        return false;
    }
    kprintf("ACPI: RSDP paddr=%p\n", acpi_rsdp);
    acpi_rsdp = acpi_table_init(acpi_rsdp, ACPI_RSDP);
    kprintf("ACPI: RSDP vaddr=%p\n", acpi_rsdp);

    /* create a copy of the rsdp data */
    *rsdp_data = *acpi_rsdp;

    /* perform final validation */
    return acpi_validate_rsdp(rsdp_data);
}

__attribute__((__section__(".boot.text"))) bool_t acpi_validate_rsdp(acpi_rsdp_t *acpi_rsdp)
{
    acpi_rsdt_t *acpi_rsdt;
    acpi_rsdt_t *acpi_rsdt_mapped;

    if (acpi_calc_checksum((char *)acpi_rsdp, ACPI_V1_SIZE) != 0) {
        kprintf("BIOS: ACPIv1 information corrupt\n");
        return false;
    }

    if (acpi_rsdp->revision > 0 && acpi_calc_checksum((char *)acpi_rsdp, sizeof(*acpi_rsdp)) != 0) {
        kprintf("BIOS: ACPIv2 information corrupt\n");
        return false;
    }

    /* verify the rsdt, even though we do not actually make use of the mapping right now */
    acpi_rsdt = (acpi_rsdt_t *)(word_t)acpi_rsdp->rsdt_address;
    kprintf("ACPI: RSDT paddr=%p\n", acpi_rsdt);
    acpi_rsdt_mapped = (acpi_rsdt_t *)acpi_table_init(acpi_rsdt, ACPI_RSDT);
    kprintf("ACPI: RSDT vaddr=%p\n", acpi_rsdt_mapped);

    if(!(acpi_rsdt_mapped->header.length > 0)) _assert_fail("acpi_rsdt_mapped->header.length > 0", "/host/kernel/src/plat/pc99/machine/acpi.c", 265, __FUNCTION__);
    if (acpi_calc_checksum((char *)acpi_rsdt_mapped, acpi_rsdt_mapped->header.length) != 0) {
        kprintf("ACPI: RSDT checksum failure\n");
        return false;
    }

    return true;
}

__attribute__((__section__(".boot.text"))) uint32_t acpi_madt_scan(
    acpi_rsdp_t *acpi_rsdp,
    cpu_id_t *cpu_list,
    uint32_t *num_ioapic,
    paddr_t *ioapic_paddrs
)
{
    unsigned int entries;
    uint32_t num_cpu;
    uint32_t count;
    acpi_madt_t *acpi_madt;
    acpi_madt_header_t *acpi_madt_header;

    acpi_rsdt_t *acpi_rsdt_mapped;
    acpi_madt_t *acpi_madt_mapped;
    acpi_rsdt_mapped = (acpi_rsdt_t *)acpi_table_init((acpi_rsdt_t *)(word_t)acpi_rsdp->rsdt_address, ACPI_RSDT);

    num_cpu = 0;
    *num_ioapic = 0;

    if(!(acpi_rsdt_mapped->header.length >= sizeof(acpi_header_t))) _assert_fail("acpi_rsdt_mapped->header.length >= sizeof(acpi_header_t)", "/host/kernel/src/plat/pc99/machine/acpi.c", 294, __FUNCTION__);
    /* Divide by uint32_t explicitly as this is the size as mandated by the ACPI standard */
    entries = (acpi_rsdt_mapped->header.length - sizeof(acpi_header_t)) / sizeof(uint32_t);
    for (count = 0; count < entries; count++) {
        acpi_madt = (acpi_madt_t *)(word_t)acpi_rsdt_mapped->entry[count];
        acpi_madt_mapped = (acpi_madt_t *)acpi_table_init(acpi_madt, ACPI_RSDT);

        if (strncmp(acpi_str_apic, acpi_madt_mapped->header.signature, 4) == 0) {
            kprintf("ACPI: MADT paddr=%p\n", acpi_madt);
            kprintf("ACPI: MADT vaddr=%p\n", acpi_madt_mapped);
            kprintf("ACPI: MADT apic_addr=0x%x\n", acpi_madt_mapped->apic_addr);
            kprintf("ACPI: MADT flags=0x%x\n", acpi_madt_mapped->flags);

            acpi_madt_header = (acpi_madt_header_t *)(acpi_madt_mapped + 1);

            while ((char *)acpi_madt_header < (char *)acpi_madt_mapped + acpi_madt_mapped->header.length) {
                switch (acpi_madt_header->type) {
                /* ACPI specifies the following rules when listing APIC IDs:
                 *  - Boot processor is listed first
                 *  - For multi-threaded processors, BIOS should list the first logical
                 *    processor of each of the individual multi-threaded processors in MADT
                 *    before listing any of the second logical processors.
                 *  - APIC IDs < 0xFF should be listed in APIC subtable, APIC IDs >= 0xFF
                 *    should be listed in X2APIC subtable */
                case MADT_APIC: {
                    /* what Intel calls apic_id is what is called cpu_id in seL4! */
                    uint8_t cpu_id = ((acpi_madt_apic_t *)acpi_madt_header)->apic_id;
                    uint32_t flags = ((acpi_madt_apic_t *)acpi_madt_header)->flags;
                    if (flags == 1) {
                        kprintf("ACPI: MADT_APIC apic_id=0x%x\n", cpu_id);
                        if (num_cpu == 1) {
                            kprintf("ACPI: Not recording this APIC, only support %d\n", 1);
                        } else {
                            cpu_list[num_cpu] = cpu_id;
                            num_cpu++;
                        }
                    }
                    break;
                }
                case MADT_x2APIC: {
                    uint32_t cpu_id = ((acpi_madt_x2apic_t *)acpi_madt_header)->x2apic_id;
                    uint32_t flags = ((acpi_madt_x2apic_t *)acpi_madt_header)->flags;
                    if (flags == 1) {
                        kprintf("ACPI: MADT_x2APIC apic_id=0x%x\n", cpu_id);
                        if (num_cpu == 1) {
                            kprintf("ACPI: Not recording this APIC, only support %d\n", 1);
                        } else {
                            cpu_list[num_cpu] = cpu_id;
                            num_cpu++;
                        }
                    }
                    break;
                }
                case MADT_IOAPIC:
                    kprintf("ACPI: MADT_IOAPIC ioapic_id=%d ioapic_addr=0x%x gsib=%d\n", ((acpi_madt_ioapic_t *)acpi_madt_header)->ioapic_id, ((acpi_madt_ioapic_t *)acpi_madt_header)->ioapic_addr, ((acpi_madt_ioapic_t *)acpi_madt_header)->gsib)




                     ;
                    if (*num_ioapic == 1) {
                        kprintf("ACPI: Not recording this IOAPIC, only support %d\n", 1);
                    } else {
                        ioapic_paddrs[*num_ioapic] = ((acpi_madt_ioapic_t *)acpi_madt_header)->ioapic_addr;
                        (*num_ioapic)++;
                    }
                    break;
                case MADT_ISO:
                    kprintf("ACPI: MADT_ISO bus=%d source=%d gsi=%d flags=0x%x\n", ((acpi_madt_iso_t *)acpi_madt_header)->bus, ((acpi_madt_iso_t *)acpi_madt_header)->source, ((acpi_madt_iso_t *)acpi_madt_header)->gsi, ((acpi_madt_iso_t *)acpi_madt_header)->flags)



                                                                        ;
                    break;
                default:
                    break;
                }
                acpi_madt_header = (acpi_madt_header_t *)((char *)acpi_madt_header + acpi_madt_header->length);
            }
        }
    }

    kprintf("ACPI: %d CPU(s) detected\n", num_cpu);

    return num_cpu;
}

__attribute__((__section__(".boot.text"))) bool_t acpi_fadt_scan(
    acpi_rsdp_t *acpi_rsdp
)
{
    unsigned int entries;
    uint32_t count;
    acpi_fadt_t *acpi_fadt;

    acpi_rsdt_t *acpi_rsdt_mapped;
    acpi_fadt_t *acpi_fadt_mapped;
    acpi_rsdt_mapped = (acpi_rsdt_t *)acpi_table_init((acpi_rsdt_t *)(word_t)acpi_rsdp->rsdt_address, ACPI_RSDT);

    if(!(acpi_rsdt_mapped->header.length >= sizeof(acpi_header_t))) _assert_fail("acpi_rsdt_mapped->header.length >= sizeof(acpi_header_t)", "/host/kernel/src/plat/pc99/machine/acpi.c", 393, __FUNCTION__);
    /* Divide by uint32_t explicitly as this is the size as mandated by the ACPI standard */
    entries = (acpi_rsdt_mapped->header.length - sizeof(acpi_header_t)) / sizeof(uint32_t);
    for (count = 0; count < entries; count++) {
        acpi_fadt = (acpi_fadt_t *)(word_t)acpi_rsdt_mapped->entry[count];
        acpi_fadt_mapped = (acpi_fadt_t *)acpi_table_init(acpi_fadt, ACPI_RSDT);

        if (strncmp(acpi_str_fadt, acpi_fadt_mapped->header.signature, 4) == 0) {
            kprintf("ACPI: FADT paddr=%p\n", acpi_fadt);
            kprintf("ACPI: FADT vaddr=%p\n", acpi_fadt_mapped);
            kprintf("ACPI: FADT flags=0x%x\n", acpi_fadt_mapped->flags);

            if (0 &&
                acpi_fadt_mapped->flags & (1ul << (19))) {
                kprintf("system requires apic physical mode\n");
                return false;
            }
        }
    }

    return true;
}

__attribute__((__section__(".boot.text"))) void acpi_dmar_scan(
    acpi_rsdp_t *acpi_rsdp,
    paddr_t *drhu_list,
    uint32_t *num_drhu,
    uint32_t max_drhu_list_len,
    acpi_rmrr_list_t *rmrr_list
)
{
    word_t i;
    unsigned int entries;
    uint32_t count;
    uint32_t reg_basel, reg_baseh;
    int rmrr_count;
    dev_id_t dev_id;

    acpi_dmar_t *acpi_dmar;
    acpi_dmar_header_t *acpi_dmar_header;
    acpi_dmar_rmrr_t *acpi_dmar_rmrr;
    acpi_dmar_devscope_t *acpi_dmar_devscope;

    acpi_rsdt_t *acpi_rsdt_mapped;
    acpi_dmar_t *acpi_dmar_mapped;

    acpi_rsdt_mapped = (acpi_rsdt_t *)acpi_table_init((acpi_rsdt_t *)(word_t)acpi_rsdp->rsdt_address, ACPI_RSDT);

    *num_drhu = 0;
    rmrr_count = 0;

    if(!(acpi_rsdt_mapped->header.length >= sizeof(acpi_header_t))) _assert_fail("acpi_rsdt_mapped->header.length >= sizeof(acpi_header_t)", "/host/kernel/src/plat/pc99/machine/acpi.c", 444, __FUNCTION__);
    entries = (acpi_rsdt_mapped->header.length - sizeof(acpi_header_t)) / sizeof(uint32_t);
    for (count = 0; count < entries; count++) {
        acpi_dmar = (acpi_dmar_t *)(word_t)acpi_rsdt_mapped->entry[count];
        acpi_dmar_mapped = (acpi_dmar_t *)acpi_table_init(acpi_dmar, ACPI_RSDT);

        if (strncmp(acpi_str_dmar, acpi_dmar_mapped->header.signature, 4) == 0) {
            kprintf("ACPI: DMAR paddr=%p\n", acpi_dmar);
            kprintf("ACPI: DMAR vaddr=%p\n", acpi_dmar_mapped);
            kprintf("ACPI: IOMMU host address width: %d\n", acpi_dmar_mapped->host_addr_width + 1);
            acpi_dmar_header = (acpi_dmar_header_t *)(acpi_dmar_mapped + 1);

            while ((char *)acpi_dmar_header < (char *)acpi_dmar_mapped + acpi_dmar_mapped->header.length) {
                switch (acpi_dmar_header->type) {

                case DMAR_DRHD:
                    if (*num_drhu == max_drhu_list_len) {
                        kprintf("ACPI: too many IOMMUs, disabling IOMMU support\n");
                        /* try to increase MAX_NUM_DRHU in config.h */
                        *num_drhu = 0; /* report zero IOMMUs */
                        return;
                    }
                    reg_basel = ((acpi_dmar_drhd_t *)acpi_dmar_header)->reg_base[0];
                    reg_baseh = ((acpi_dmar_drhd_t *)acpi_dmar_header)->reg_base[1];
                    /* check if value fits into uint32_t */
                    if (reg_baseh != 0) {
                        kprintf("ACPI: DMAR_DRHD reg_base exceeds 32 bit, disabling IOMMU support\n");
                        /* try to make BIOS map it below 4G */
                        *num_drhu = 0; /* report zero IOMMUs */
                        return;
                    }
                    drhu_list[*num_drhu] = (paddr_t)reg_basel;
                    (*num_drhu)++;
                    break;

                case DMAR_RMRR:
                    /* loop through all device scopes of this RMRR */
                    acpi_dmar_rmrr = (acpi_dmar_rmrr_t *)acpi_dmar_header;
                    if (acpi_dmar_rmrr->reg_base[1] != 0 ||
                        acpi_dmar_rmrr->reg_limit[1] != 0) {
                        kprintf("ACPI: RMRR device above 4GiB, disabling IOMMU support\n");
                        *num_drhu = 0;
                        return ;
                    }

                    for (i = 0; i <= (acpi_dmar_header->length - sizeof(acpi_dmar_rmrr_t)) / sizeof(acpi_dmar_devscope_t); i++) {
                        acpi_dmar_devscope = &acpi_dmar_rmrr->devscope_0 + i;

                        if (acpi_dmar_devscope->type != 1) {
                            /* FIXME - bugzilla bug 170 */
                            kprintf("ACPI: RMRR device scope: non-PCI-Endpoint-Devices not supported yet, disabling IOMMU support\n");
                            *num_drhu = 0; /* report zero IOMMUs */
                            return;
                        }

                        if (acpi_dmar_devscope->length > sizeof(acpi_dmar_devscope_t)) {
                            /* FIXME - bugzilla bug 170 */
                            kprintf("ACPI: RMRR device scope: devices behind bridges not supported yet, disabling IOMMU support\n");
                            *num_drhu = 0; /* report zero IOMMUs */
                            return;
                        }

                        dev_id =
                            (((acpi_dmar_devscope->start_bus) << 8u) | ((acpi_dmar_devscope->path_0.dev) << 3u) | (acpi_dmar_devscope->path_0.fun))



                             ;

                        if (rmrr_count == 1) {
                            kprintf("ACPI: Too many RMRR entries, disabling IOMMU support\n");
                            *num_drhu = 0;
                            return;
                        }
                        kprintf("\tACPI: registering RMRR entry for region for device: bus=0x%x dev=0x%x fun=0x%x\n", acpi_dmar_devscope->start_bus, acpi_dmar_devscope->path_0.dev, acpi_dmar_devscope->path_0.fun)



                               ;

                        rmrr_list->entries[rmrr_count].device = dev_id;
                        rmrr_list->entries[rmrr_count].base = acpi_dmar_rmrr->reg_base[0];
                        rmrr_list->entries[rmrr_count].limit = acpi_dmar_rmrr->reg_limit[0];
                        rmrr_count++;
                    }
                    break;

                case DMAR_ATSR:
                    /* not implemented yet */
                    break;

                default:
                    kprintf("ACPI: Unknown DMA remapping structure type: %x\n", acpi_dmar_header->type);
                }
                acpi_dmar_header = (acpi_dmar_header_t *)((char *)acpi_dmar_header + acpi_dmar_header->length);
            }
        }
    }
    rmrr_list->num = rmrr_count;
    kprintf("ACPI: %d IOMMUs detected\n", *num_drhu);
}
# 1 "/host/kernel/src/plat/pc99/machine/hardware.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 18 "/host/kernel/src/plat/pc99/machine/hardware.c"
__attribute__((__section__(".boot.text"))) bool_t platAddDevices(void)
{
    /* remove the MSI region as poking at this is undefined and may allow for
     * the user to generate arbitrary MSI interrupts. Only need to consider
     * this if it would actually be in the user device region */
    if (140737488355328 > 0xFFFFFFF8) {
        if (!reserve_region((p_region_t) {
        (word_t)0xFFFFFFF8, (word_t)0xFFFFFFF8 + 8
        })) {
            return false;
        }
    }
    return true;
}

/* ============================== timer ============================== */



__attribute__((__section__(".boot.text"))) static inline uint32_t measure_tsc_khz(void)
{
    /* The frequency is repeatedly measured until the number of TSC
     * ticks in the pit wraparound interval (~50ms) fits in 32 bits.
     * On bare metal, this should succeed immediately, since x86
     * guarantees the number of TSC ticks in a second can be stored
     * in 32 bits. When running in a simulator, it's possible for
     * the emulation (or not) of the PIT and TSC to occasionally
     * allow too many TSC ticks per PIT wraparound. This loop
     * repeatedly measures the TSC ticks per PIT wraparound under
     * the expectation that it will eventually yield a sensible
     * result.
     */
    for (int i = 0; i < 10; i++) {

        /* read tsc */
        uint64_t old_ticks = x86_rdtsc();

        /* measure how many tsc cycles pass while PIT wraps around */
        pit_wait_wraparound();

        uint64_t new_ticks = x86_rdtsc();

        uint64_t diff = new_ticks - old_ticks;

        if ((uint32_t)diff == diff && new_ticks > old_ticks) {
            return (uint32_t)diff / 50;
        }

        kprintf("warning: TSC frequency too high (%d retries remaining)\n", 10 - i - 1)
                                        ;
    }

    _fail("TSC frequency too high", "/host/kernel/src/plat/pc99/machine/hardware.c", 70, __func__);

    /* should never get here */
    return 0;
}

__attribute__((__section__(".boot.text"))) uint32_t tsc_init(void)
{

    x86_cpu_identity_t *model_info = x86_cpuid_get_model_info();
    uint32_t valid_models[] = {
        0x1E /* Clarksfield, Lynnfield and Jasper Forest */, 0x1A /* Bloomfield and Nehalem-EP */, 0x2E /* Nehalem-EX */,
        0x2A /* Sandy Bridge */, 0x2D /* Sandy Bridge-E, Sandy Bridge-EN and Sandy Bridge-EP */,
        0x3C, 0x3F, 0x45, 0x46,
        0x9A, 0x3E, 0x3A,
        /* BROADWELL_1_MODEL_ID is an Atom that doesn't support the MSR */
        0x56, 0x4F, 0x47, 0x3D,
        0x4E, 0x5E
    };

    /* try to read the frequency from the platform info MSR */
    if (model_info->family == (0x06)) {
        for (int i = 0; i < (sizeof(valid_models) / sizeof(valid_models[0])); i++) {
            if (model_info->model == valid_models[i]) {

                /* read tsc freq from the platform info msr. Under some environments such
                 * as KVM this MSR will cause a GP fault even though it should be there.
                 * As such we perform a 'safe' rdmsr, which will catch a GP fault and
                 * tells through .success whether or not one happened */
                rdmsr_safe_result_t info = x86_rdmsr_safe(0xCE);
                if (info.success) {
                    uint32_t ratio = (((uint32_t) info.value) & 0xFF00) >> 8u;
                    /* Ignore hardware that claims a tsc frequency of zero */
                    if (ratio != 0) {
                        /* Convert to MHz */
                        if (model_info->model == 0x1E /* Clarksfield, Lynnfield and Jasper Forest */ ||
                            model_info->model == 0x1A /* Bloomfield and Nehalem-EP */ ||
                            model_info->model == 0x2E /* Nehalem-EX */) {
                            return ratio * 13333u / 100u;
                        } else {
                            return ratio * 100u;
                        }
                    }
                }
                /* We just found the matching model, so no point continuing the search */
                break;
            }
        }
    }

    /* otherwise use the pit to find out the tsc freq */
    pit_init();

    /* wait for pit to wraparound */
    pit_wait_wraparound();

    /* count tsc ticks per ms */
    uint32_t tsc_khz = measure_tsc_khz();

    /* finally, return mhz */
    return tsc_khz / 1000u;
}
# 1 "/host/kernel/src/plat/pc99/machine/intel-vtd.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/plat/pc99/machine/io.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 14 "/host/kernel/src/plat/pc99/machine/io.c"
void serial_init(uint16_t port)
{
    while (!(in8(port + 5) & 0x60)); /* wait until not busy */

    out8(port + 1, 0x00); /* disable generating interrupts */
    out8(port + 3, 0x80); /* line control register: command: set divisor */
    out8(port, 0x01); /* set low byte of divisor to 0x01 = 115200 baud */
    out8(port + 1, 0x00); /* set high byte of divisor to 0x00 */
    out8(port + 3, 0x03); /* line control register: set 8 bit, no parity, 1 stop bit */
    out8(port + 4, 0x0b); /* modem control register: set DTR/RTS/OUT2 */

    in8(port); /* clear receiver port */
    in8(port + 5); /* clear line status port */
    in8(port + 6); /* clear modem status port */
}

void putDebugChar(unsigned char a)
{
    while (x86KSdebugPort && (in8(x86KSdebugPort + 5) & 0x20) == 0);
    out8(x86KSdebugPort, a);
}




unsigned char getDebugChar(void)
{
    while ((in8(x86KSdebugPort + 5) & 1) == 0);
    return in8(x86KSdebugPort);
}
# 1 "/host/kernel/src/plat/pc99/machine/ioapic.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 35 "/host/kernel/src/plat/pc99/machine/ioapic.c"
/* Cache what we believe is in the low word of the IOREDTBL. This
 * has all the state of trigger modes etc etc */
static uint32_t ioredtbl_state[24 * 1];

/* Number of IOAPICs in the system */
static uint32_t num_ioapics = 0;

static void ioapic_write(uint32_t ioapic, word_t reg, uint32_t value)
{
    *(volatile uint32_t *)((word_t)((0xffffffffc0000000ul + (1ul << (12))) + ioapic * (1ul << (12))) + reg) = value;
}

static uint32_t ioapic_read(uint32_t ioapic, word_t reg)
{
    return *(volatile uint32_t *)((word_t)((0xffffffffc0000000ul + (1ul << (12))) + ioapic * (1ul << (12))) + reg);
}

static void single_ioapic_init(word_t ioapic, cpu_id_t delivery_cpu)
{
    uint32_t i;

    /* Mask all the IRQs. In doing so we happen to set
     * the vector to 0, which we can assert against in
     * mask_interrupt to ensure a vector is assigned
     * before we unmask */
    for (i = 0; i < 24; i++) {
        /* Send to desired cpu */
        ioapic_write(ioapic, 0x00, ((0x10 + (i) * 2) + 1));
        ioapic_write(ioapic, 0x10, (ioapic_read(ioapic,
                                                         0x10) & ((1ul << (24))-1ul)) | (delivery_cpu << 24));
        /* mask and set 0 vector */
        ioredtbl_state[i] = (1ul << (16));
        ioapic_write(ioapic, 0x00, (0x10 + (i) * 2));
        /* The upper 16 bits are reserved, so we make sure to preserve them */
        ioredtbl_state[i] |= ioapic_read(ioapic, 0x10) & ~((1ul << (16))-1ul);
        ioapic_write(ioapic, 0x10, ioredtbl_state[i]);
    }
}

static cpu_id_t ioapic_target_cpu = 0;
void ioapic_init(uint32_t num_nodes, cpu_id_t *cpu_list, uint32_t num_ioapic)
{
    uint32_t ioapic;
    num_ioapics = num_ioapic;
    ioapic_target_cpu = cpu_list[0];

    for (ioapic = 0; ioapic < num_ioapic; ioapic++) {
        /* Init this ioapic */
        single_ioapic_init(ioapic, cpu_list[0]);
    }
}

void ioapic_mask(bool_t mask, uint32_t ioapic, uint32_t pin)
{
    int index = ioapic * 24 + pin;
    if (ioapic >= num_ioapics || pin >= 24) {
        /* silently ignore requests to non existent parts of the interrupt space */
        return;
    }
    if (mask) {
        ioredtbl_state[index] |= (1ul << (16));
    } else {
        ioredtbl_state[index] &= ~(1ul << (16));
        /* it should not be possible to be unmasking an interrupt, without
         * it having been mapped to a vector, assert that this is the case */
        if(!((ioredtbl_state[index] & 0xff) != 0)) _assert_fail("(ioredtbl_state[index] & 0xff) != 0", "/host/kernel/src/plat/pc99/machine/ioapic.c", 100, __FUNCTION__);
    }
    ioapic_write(ioapic, 0x00, (0x10 + (pin) * 2));
    ioapic_write(ioapic, 0x10, ioredtbl_state[index]);
}

exception_t ioapic_decode_map_pin_to_vector(word_t ioapic, word_t pin, word_t level,
                                            word_t polarity, word_t vector)
{
    if (num_ioapics == 0) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "System has no IOAPICs" ">>" "\033[0m" "\n", 0lu, __func__, 110, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread)); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
    if (ioapic >= num_ioapics) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Invalid IOAPIC %ld, only have %ld" ">>" "\033[0m" "\n", 0lu, __func__, 115, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (long)ioapic, (long)num_ioapics); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = num_ioapics - 1;
        return EXCEPTION_SYSCALL_ERROR;
    }
    if (pin >= 24) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Invalid IOAPIC pin %ld, there are %d pins" ">>" "\033[0m" "\n", 0lu, __func__, 122, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (long)pin, 24); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = 24 - 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (level != 0 && level != 1) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Level should be 0 or 1, not %d" ">>" "\033[0m" "\n", 0lu, __func__, 130, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (int)level); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }
    if (polarity != 0 && polarity != 1) {
        do { kprintf("\033[0m" "\033[30;1m" "<<" "\033[0m" "\033[32m" "seL4(CPU %lu)" "\033[0m" "\033[30;1m" " [%s/%d T%p \"%s\" @%lx]: " "Polarity should be 0 or 1, not %d" ">>" "\033[0m" "\n", 0lu, __func__, 137, ksCurThread, ((debug_tcb_t *)(((cte_t *)((word_t)(ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchCNodeEntries)))->tcbName, (word_t)getRestartPC(ksCurThread), (int)polarity); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }
    return EXCEPTION_NONE;
}

void ioapic_map_pin_to_vector(word_t ioapic, word_t pin, word_t level,
                              word_t polarity, word_t vector)
{
    uint32_t ioredtbl_high = 0;
    uint32_t index = 0;

    index = ioapic * 24 + pin;
    ioapic_write(ioapic, 0x00, ((0x10 + (pin) * 2) + 1));
    ioredtbl_high = ioapic_read(ioapic, 0x10) & ((1ul << (24))-1ul);
    /* delivery mode: physical mode only, using APIC ID */
    ioredtbl_high |= (ioapic_target_cpu << 24);
    ioapic_write(ioapic, 0x10, ioredtbl_high);
    /* we do not need to add IRQ_INT_OFFSET to the vector here */
    ioredtbl_state[index] = (1ul << (16)) |
                            (level << 15) |
                            (polarity << 13) |
                            vector;

    ioapic_write(ioapic, 0x00, (0x10 + (pin) * 2));
    /* the upper 16 bits are reserved */
    ioredtbl_state[index] |= ioapic_read(ioapic, 0x10) & ~((1ul << (16))-1ul);
    ioapic_write(ioapic, 0x10, ioredtbl_state[index]);
}
# 1 "/host/kernel/src/plat/pc99/machine/pic.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */






/* PIC (i8259) base registers */



/* Program PIC (i8259) to remap IRQs 0-15 to interrupt vectors starting at 'interrupt' */
__attribute__((__section__(".boot.text"))) void pic_remap_irqs(interrupt_t interrupt)
{
    out8(0x20, 0x11);
    out8(0xa0, 0x11);
    out8(0x20 + 1, interrupt);
    out8(0xa0 + 1, interrupt + 8);
    out8(0x20 + 1, 0x04);
    out8(0xa0 + 1, 0x02);
    out8(0x20 + 1, 0x01);
    out8(0xa0 + 1, 0x01);
    out8(0x20 + 1, 0x0);
    out8(0xa0 + 1, 0x0);
}

__attribute__((__section__(".boot.text"))) void pic_disable(void)
{
    /* We assume that pic_remap_irqs has already been called and
     * just mask all the irqs */
    out8(0x20 + 1, 0xff);
    out8(0xa0 + 1, 0xff);
}

void pic_mask_irq(bool_t mask, irq_t irq)
{
    uint8_t bit_mask;
    uint16_t pic_port;

    if(!(irq >= irq_isa_min)) _assert_fail("irq >= irq_isa_min", "/host/kernel/src/plat/pc99/machine/pic.c", 44, __FUNCTION__);
    if(!(irq <= irq_isa_max)) _assert_fail("irq <= irq_isa_max", "/host/kernel/src/plat/pc99/machine/pic.c", 45, __FUNCTION__);

    if (irq < 8) {
        bit_mask = (1ul << (irq));
        pic_port = 0x20 + 1;
    } else {
        bit_mask = (1ul << (irq - 8));
        pic_port = 0xa0 + 1;
    }

    if (mask) {
        /* Disables the interrupt */
        out8(pic_port, (in8(pic_port) | bit_mask));
    } else {
        /* Enables the interrupt */
        out8(pic_port, (in8(pic_port) & ~bit_mask));
    }
}

bool_t pic_is_irq_pending(void)
{
    /* Interrupt Request Register (IRR) - holds pending IRQs */
    uint8_t irr;

    /* Send to PIC1's OCW3, in order to read IRR from next inb instruction */
    out8(0x20, 0x0a);

    /* Read IRR */
    irr = in8(0x20);

    /* Since slave PIC is connected to IRQ2 of master PIC,
     * there is no need to check IRR of slave PIC.
     */
    return irr != 0;
}

static uint16_t pic_get_isr(void)
{
    out8(0x20, 0x0b);
    out8(0xa0, 0x0b);
    return (((uint16_t)in8(0xa0)) << 8) | in8(0x20);
}

void pic_ack_active_irq(void)
{
    irq_t irq = getActiveIRQ();
    if (irq >= irq_isa_min + 8) {
        /* ack slave PIC, unless we got a spurious irq 15
         * It is spurious if the bit is not set in the ISR
         * Even if it was spurious we will still need to
         * acknowledge the master PIC */
        if (irq != irq_isa_min + 15 || (pic_get_isr() & (1ul << (15)))) {
            out8(0xa0, 0x20);
        }
    }
    /* ack master PIC, unless we got a spurious IRQ 7
     * It is spurious if the bit is not set in the ISR */
    if (irq != irq_isa_min + 7 || (pic_get_isr() & (1ul << (7)))) {
        out8(0x20, 0x20);
    }
}
# 1 "/host/kernel/src/plat/pc99/machine/pit.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */





/* PIT (i8253) registers */



/* Count frequency in Hz */


__attribute__((__section__(".boot.text"))) void pit_init(void)
{
    uint16_t divisor = (1193182 * 50) / 1000;

    out8(0x43, 0x34); /* Set mode 2 and wait for divisor bytes */
    out8(0x40, divisor & 0xff); /* Set low byte of divisor */
    out8(0x40, divisor >> 8); /* Set high byte of divisor */
}

__attribute__((__section__(".boot.text"))) void pit_wait_wraparound(void)
{
    uint16_t count;
    uint16_t count_old;

    out8(0x43, 0x00);
    count = in8(0x40);
    count |= (in8(0x40) << 8);
    count_old = count;

    while (count <= count_old) {
        count_old = count;
        out8(0x43, 0x00);
        count = in8(0x40);
        count |= (in8(0x40) << 8);
    }
}
# 1 "/host/kernel/src/smp/ipi.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/smp/lock.c"
/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
# 1 "/host/kernel/src/string.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */





word_t strnlen(const char *s, word_t maxlen)
{
    word_t len;
    for (len = 0; len < maxlen && s[len]; len++);
    return len;
}

word_t strlcpy(char *dest, const char *src, word_t size)
{
    word_t len;
    for (len = 0; len + 1 < size && src[len]; len++) {
        dest[len] = src[len];
    }
    dest[len] = '\0';
    return len;
}

word_t strlcat(char *dest, const char *src, word_t size)
{
    word_t len;
    /* get to the end of dest */
    for (len = 0; len < size && dest[len]; len++);
    /* check that dest was at least 'size' length to prevent inserting
     * a null byte when we shouldn't */
    if (len < size) {
        for (; len + 1 < size && *src; len++, src++) {
            dest[len] = *src;
        }
        dest[len] = '\0';
    }
    return len;
}
# 1 "/host/kernel/src/util.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */





/*
 * memzero needs a custom type that allows us to use a word
 * that has the aliasing properties of a char.
 */
typedef unsigned long __attribute__((__may_alias__)) ulong_alias;

/*
 * Zero 'n' bytes of memory starting from 's'.
 *
 * 'n' and 's' must be word aligned.
 */
void memzero(void *s, unsigned long n)
{
    uint8_t *p = s;

    /* Ensure alignment constraints are met. */
    if(!((unsigned long)s % sizeof(unsigned long) == 0)) _assert_fail("(unsigned long)s % sizeof(unsigned long) == 0", "/host/kernel/src/util.c", 27, __FUNCTION__);
    if(!(n % sizeof(unsigned long) == 0)) _assert_fail("n % sizeof(unsigned long) == 0", "/host/kernel/src/util.c", 28, __FUNCTION__);

    /* We will never memzero an area larger than the largest current
       live object */
    /** GHOSTUPD: "(gs_get_assn cap_get_capSizeBits_'proc \<acute>ghost'state = 0
        \<or> \<acute>n <= gs_get_assn cap_get_capSizeBits_'proc \<acute>ghost'state, id)" */

    /* Write out words. */
    while (n != 0) {
        *(ulong_alias *)p = 0;
        p += sizeof(ulong_alias);
        n -= sizeof(ulong_alias);
    }
}

void *__attribute__((externally_visible)) memset(void *s, unsigned long c, unsigned long n)
{
    uint8_t *p;

    /*
     * If we are only writing zeros and we are word aligned, we can
     * use the optimized 'memzero' function.
     */
    if (__builtin_expect(!!(c == 0 && ((unsigned long)s % sizeof(unsigned long)) == 0 && (n % sizeof(unsigned long)) == 0), 1)) {
        memzero(s, n);
    } else {
        /* Otherwise, we use a slower, simple memset. */
        for (p = (uint8_t *)s; n > 0; n--, p++) {
            *p = (uint8_t)c;
        }
    }

    return s;
}

void *__attribute__((externally_visible)) memcpy(void *ptr_dst, const void *ptr_src, unsigned long n)
{
    uint8_t *p;
    const uint8_t *q;

    for (p = (uint8_t *)ptr_dst, q = (const uint8_t *)ptr_src; n; n--, p++, q++) {
        *p = *q;
    }

    return ptr_dst;
}

int __attribute__((__pure__)) strncmp(const char *s1, const char *s2, int n)
{
    word_t i;
    int diff;

    for (i = 0; i < n; i++) {
        diff = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
        if (diff != 0 || s1[i] == '\0') {
            return diff;
        }
    }

    return 0;
}

long __attribute__((__const__)) char_to_long(char c)
{
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return -1;
}

long __attribute__((__pure__)) str_to_long(const char *str)
{
    unsigned int base;
    long res;
    long val = 0;
    char c;

    /*check for "0x" */
    if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X')) {
        base = 16;
        str += 2;
    } else {
        base = 10;
    }

    if (!*str) {
        return -1;
    }

    c = *str;
    while (c != '\0') {
        res = char_to_long(c);
        if (res == -1 || res >= base) {
            return -1;
        }
        val = val * base + res;
        str++;
        c = *str;
    }

    return val;
}
# 1 "/host/kernel/src/config/default_domain.c"
/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */




/* Default schedule. */
const dschedule_t ksDomSchedule[] = {
    { .domain = 0, .length = 1 },
};

const word_t ksDomScheduleLength = sizeof(ksDomSchedule) / sizeof(dschedule_t);
