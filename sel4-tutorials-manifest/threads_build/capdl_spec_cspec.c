/* Generated file. Your changes will be overwritten. */

#include <capdl.h>
#include <sel4/sel4.h>

#ifndef INVALID_SLOT
#define INVALID_SLOT (-1)
#endif

#define MAX_OBJECTS 332

CDL_Model capdl_spec = {
#if !defined(CONFIG_ARCH_X86_64)
#    error "invalid target architecture; expecting X86_64"
#endif
.num = 332,
.num_irqs = 1,
.irqs = (CDL_ObjID[]){
-1
},
.objects = (CDL_Object[]) {
[0] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "buf2_frame_cap",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 102400
}},}
 },
},
[1] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0000",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 548,
.file_data_type = {.filename = "threads",
.file_offset = 0
}},}
 },
},
[2] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0001",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 4096
}},}
 },
},
[3] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0002",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 8192
}},}
 },
},
[4] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0003",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 12288
}},}
 },
},
[5] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0004",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 16384
}},}
 },
},
[6] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0005",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 20480
}},}
 },
},
[7] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0006",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 24576
}},}
 },
},
[8] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0007",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 28672
}},}
 },
},
[9] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0008",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 32768
}},}
 },
},
[10] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0009",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 36864
}},}
 },
},
[11] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0010",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 40960
}},}
 },
},
[12] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0011",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 45056
}},}
 },
},
[13] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0012",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 49152
}},}
 },
},
[14] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0013",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 53248
}},}
 },
},
[15] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0014",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 57344
}},}
 },
},
[16] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0015",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 61440
}},}
 },
},
[17] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0016",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 65536
}},}
 },
},
[18] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0017",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 69632
}},}
 },
},
[19] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0018",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 582,
.file_data_type = {.filename = "threads",
.file_offset = 73728
}},}
 },
},
[20] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0019",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 77824
}},}
 },
},
[21] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0020",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 81920
}},}
 },
},
[22] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0021",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 86016
}},}
 },
},
[23] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0022",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 2672,
.file_data_type = {.filename = "threads",
.file_offset = 90112
}},}
 },
},
[24] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0023",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 4040,
.dest_len = 56,
.file_data_type = {.filename = "threads",
.file_offset = 94152
}},}
 },
},
[25] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0024",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 94208
}},}
 },
},
[26] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0025",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 98304
}},}
 },
},
[27] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0028",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 110592
}},}
 },
},
[28] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0029",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 114688
}},}
 },
},
[29] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0030",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 118784
}},}
 },
},
[30] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0031",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 122880
}},}
 },
},
[31] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0032",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 126976
}},}
 },
},
[32] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0033",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 131072
}},}
 },
},
[33] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0034",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 135168
}},}
 },
},
[34] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0035",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 139264
}},}
 },
},
[35] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0036",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 143360
}},}
 },
},
[36] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0037",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 147456
}},}
 },
},
[37] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0038",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 151552
}},}
 },
},
[38] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0039",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 155648
}},}
 },
},
[39] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0040",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 159744
}},}
 },
},
[40] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0041",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 163840
}},}
 },
},
[41] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0042",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 167936
}},}
 },
},
[42] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0043",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 172032
}},}
 },
},
[43] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0061",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 8,
.file_data_type = {.filename = "threads",
.file_offset = 245760
}},}
 },
},
[44] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0062",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[45] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0063",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[46] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0064",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[47] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0065",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[48] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0066",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[49] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0067",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[50] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0068",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[51] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0069",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[52] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0070",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[53] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0071",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[54] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0072",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[55] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0073",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[56] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0074",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[57] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0075",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[58] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0076",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[59] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0077",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[60] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0078",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[61] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0079",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[62] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0080",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[63] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0081",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[64] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0082",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[65] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0083",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[66] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0084",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[67] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0085",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[68] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0086",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[69] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0087",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[70] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0088",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[71] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0089",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[72] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0090",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[73] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0091",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[74] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0092",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[75] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0093",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[76] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0094",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[77] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0095",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[78] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0096",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[79] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0097",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[80] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0098",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[81] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0099",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[82] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0100",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[83] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0101",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[84] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0102",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[85] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0103",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[86] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0104",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[87] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0105",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[88] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0106",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[89] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0107",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[90] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0108",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[91] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0109",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[92] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0110",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[93] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0111",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[94] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0112",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[95] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0113",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[96] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0114",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[97] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0115",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[98] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0116",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[99] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0117",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[100] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0118",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[101] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0119",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[102] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0120",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[103] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0121",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[104] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0122",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[105] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0123",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[106] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0124",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[107] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0125",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[108] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0126",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[109] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0127",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[110] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0128",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[111] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0129",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[112] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0130",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[113] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0131",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[114] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0132",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[115] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0133",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[116] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0134",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[117] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0135",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[118] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0136",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[119] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0137",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[120] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0138",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[121] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0139",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[122] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0140",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[123] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0141",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[124] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0142",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[125] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0143",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[126] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0144",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[127] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0145",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[128] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0146",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[129] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0147",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[130] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0148",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[131] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0149",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[132] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0150",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[133] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0151",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[134] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0152",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[135] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0153",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[136] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0154",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[137] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0155",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[138] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0156",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[139] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0157",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[140] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0158",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[141] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0159",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[142] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0160",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[143] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0161",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[144] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0162",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[145] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0163",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[146] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0164",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[147] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0165",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[148] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0166",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[149] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0167",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[150] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0168",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[151] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0169",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[152] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0170",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[153] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0171",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[154] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0172",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[155] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0173",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[156] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0174",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[157] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0175",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[158] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0176",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[159] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0177",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[160] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0178",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[161] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0179",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[162] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0180",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[163] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0181",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[164] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0182",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[165] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0183",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[166] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0184",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[167] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0185",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[168] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0186",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[169] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0187",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[170] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0188",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[171] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0189",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[172] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0190",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[173] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0191",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[174] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0192",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[175] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0193",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[176] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0194",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[177] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0195",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[178] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0196",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[179] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0197",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[180] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0198",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[181] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0199",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[182] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0200",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[183] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0201",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[184] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0202",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[185] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0203",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[186] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0204",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[187] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0205",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[188] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0206",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[189] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0207",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[190] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0208",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[191] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0209",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[192] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0210",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[193] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0211",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[194] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0212",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[195] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0213",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[196] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0214",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[197] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0215",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[198] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0216",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[199] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0217",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[200] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0218",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[201] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0219",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[202] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0220",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[203] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0221",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[204] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0222",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[205] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0223",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[206] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0224",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[207] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0225",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[208] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0226",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[209] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0227",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[210] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0228",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[211] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0229",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[212] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0230",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[213] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0231",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[214] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0232",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[215] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0233",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[216] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0234",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[217] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0235",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[218] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0236",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[219] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0237",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[220] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0238",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[221] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0239",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[222] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0240",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[223] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0241",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[224] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0242",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[225] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0243",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[226] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0244",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[227] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0245",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[228] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0246",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[229] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0247",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[230] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0248",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[231] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0249",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[232] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0250",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[233] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0251",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[234] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0252",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[235] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0253",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[236] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0254",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[237] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0255",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[238] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0256",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[239] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0257",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[240] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0258",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[241] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0259",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[242] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0260",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[243] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0261",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[244] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0262",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[245] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0263",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[246] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0264",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[247] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0265",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[248] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0266",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[249] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0267",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[250] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0268",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[251] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0269",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[252] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0270",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[253] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0271",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[254] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0272",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[255] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0273",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[256] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0274",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[257] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0275",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[258] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0276",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[259] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0277",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[260] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0278",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[261] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0279",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[262] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0280",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[263] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0281",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[264] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0282",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[265] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0283",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[266] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0284",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[267] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0285",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[268] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0286",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[269] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0287",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[270] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0288",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[271] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0289",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[272] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0290",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[273] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0291",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[274] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0292",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[275] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0293",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[276] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0294",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[277] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0295",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[278] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0296",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[279] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0297",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[280] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0298",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[281] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0299",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[282] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0300",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[283] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0301",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[284] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0302",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[285] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0303",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[286] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0304",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[287] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0305",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[288] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0306",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[289] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0307",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[290] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0308",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[291] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0309",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[292] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0310",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[293] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0311",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[294] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0312",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[295] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0313",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[296] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0314",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[297] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0315",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[298] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0316",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[299] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0317",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[300] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0318",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[301] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0319",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[302] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0320",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[303] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0321",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[304] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0322",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[305] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0323",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[306] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "frame_threads_0324",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { }
 },
},
[307] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "ipc_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 241664
}},}
 },
},
[308] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "pd_threads_0001",
#endif
.type = CDL_PD,
.slots.num = 1,
.slots.slot = (CDL_CapSlot[]) {
{2, {.type = CDL_PTCap, .obj_id = 310 /* pt_threads_0002 */, .is_orig = true}},

},
},
[309] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "pdpt_threads_0000",
#endif
.type = CDL_PDPT,
.slots.num = 1,
.slots.slot = (CDL_CapSlot[]) {
{0, {.type = CDL_PDCap, .obj_id = 308 /* pd_threads_0001 */, .is_orig = true}},

},
},
[310] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "pt_threads_0002",
#endif
.type = CDL_PT,
.slots.num = 325,
.slots.slot = (CDL_CapSlot[]) {
{0, {.type = CDL_FrameCap, .obj_id = 1 /* frame_threads_0000 */, .is_orig = true, .rights = (CDL_CanRead), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{1, {.type = CDL_FrameCap, .obj_id = 2 /* frame_threads_0001 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{2, {.type = CDL_FrameCap, .obj_id = 3 /* frame_threads_0002 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{3, {.type = CDL_FrameCap, .obj_id = 4 /* frame_threads_0003 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{4, {.type = CDL_FrameCap, .obj_id = 5 /* frame_threads_0004 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{5, {.type = CDL_FrameCap, .obj_id = 6 /* frame_threads_0005 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{6, {.type = CDL_FrameCap, .obj_id = 7 /* frame_threads_0006 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{7, {.type = CDL_FrameCap, .obj_id = 8 /* frame_threads_0007 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{8, {.type = CDL_FrameCap, .obj_id = 9 /* frame_threads_0008 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{9, {.type = CDL_FrameCap, .obj_id = 10 /* frame_threads_0009 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{10, {.type = CDL_FrameCap, .obj_id = 11 /* frame_threads_0010 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{11, {.type = CDL_FrameCap, .obj_id = 12 /* frame_threads_0011 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{12, {.type = CDL_FrameCap, .obj_id = 13 /* frame_threads_0012 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{13, {.type = CDL_FrameCap, .obj_id = 14 /* frame_threads_0013 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{14, {.type = CDL_FrameCap, .obj_id = 15 /* frame_threads_0014 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{15, {.type = CDL_FrameCap, .obj_id = 16 /* frame_threads_0015 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{16, {.type = CDL_FrameCap, .obj_id = 17 /* frame_threads_0016 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{17, {.type = CDL_FrameCap, .obj_id = 18 /* frame_threads_0017 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{18, {.type = CDL_FrameCap, .obj_id = 19 /* frame_threads_0018 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{19, {.type = CDL_FrameCap, .obj_id = 20 /* frame_threads_0019 */, .is_orig = true, .rights = (CDL_CanRead), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{20, {.type = CDL_FrameCap, .obj_id = 21 /* frame_threads_0020 */, .is_orig = true, .rights = (CDL_CanRead), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{21, {.type = CDL_FrameCap, .obj_id = 22 /* frame_threads_0021 */, .is_orig = true, .rights = (CDL_CanRead), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{22, {.type = CDL_FrameCap, .obj_id = 23 /* frame_threads_0022 */, .is_orig = true, .rights = (CDL_CanRead), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{23, {.type = CDL_FrameCap, .obj_id = 24 /* frame_threads_0023 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{24, {.type = CDL_FrameCap, .obj_id = 25 /* frame_threads_0024 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{25, {.type = CDL_FrameCap, .obj_id = 26 /* frame_threads_0025 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{26, {.type = CDL_FrameCap, .obj_id = 0 /* buf2_frame_cap */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{27, {.type = CDL_FrameCap, .obj_id = 327 /* tcb_ipc_frame */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{28, {.type = CDL_FrameCap, .obj_id = 27 /* frame_threads_0028 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{29, {.type = CDL_FrameCap, .obj_id = 28 /* frame_threads_0029 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{30, {.type = CDL_FrameCap, .obj_id = 29 /* frame_threads_0030 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{31, {.type = CDL_FrameCap, .obj_id = 30 /* frame_threads_0031 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{32, {.type = CDL_FrameCap, .obj_id = 31 /* frame_threads_0032 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{33, {.type = CDL_FrameCap, .obj_id = 32 /* frame_threads_0033 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{34, {.type = CDL_FrameCap, .obj_id = 33 /* frame_threads_0034 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{35, {.type = CDL_FrameCap, .obj_id = 34 /* frame_threads_0035 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{36, {.type = CDL_FrameCap, .obj_id = 35 /* frame_threads_0036 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{37, {.type = CDL_FrameCap, .obj_id = 36 /* frame_threads_0037 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{38, {.type = CDL_FrameCap, .obj_id = 37 /* frame_threads_0038 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{39, {.type = CDL_FrameCap, .obj_id = 38 /* frame_threads_0039 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{40, {.type = CDL_FrameCap, .obj_id = 39 /* frame_threads_0040 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{41, {.type = CDL_FrameCap, .obj_id = 40 /* frame_threads_0041 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{42, {.type = CDL_FrameCap, .obj_id = 41 /* frame_threads_0042 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{43, {.type = CDL_FrameCap, .obj_id = 42 /* frame_threads_0043 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{44, {.type = CDL_FrameCap, .obj_id = 311 /* stack_0_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{45, {.type = CDL_FrameCap, .obj_id = 318 /* stack_1_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{46, {.type = CDL_FrameCap, .obj_id = 319 /* stack_2_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{47, {.type = CDL_FrameCap, .obj_id = 320 /* stack_3_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{48, {.type = CDL_FrameCap, .obj_id = 321 /* stack_4_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{49, {.type = CDL_FrameCap, .obj_id = 322 /* stack_5_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{50, {.type = CDL_FrameCap, .obj_id = 323 /* stack_6_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{51, {.type = CDL_FrameCap, .obj_id = 324 /* stack_7_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{52, {.type = CDL_FrameCap, .obj_id = 325 /* stack_8_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{53, {.type = CDL_FrameCap, .obj_id = 326 /* stack_9_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{54, {.type = CDL_FrameCap, .obj_id = 312 /* stack_10_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{55, {.type = CDL_FrameCap, .obj_id = 313 /* stack_11_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{56, {.type = CDL_FrameCap, .obj_id = 314 /* stack_12_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{57, {.type = CDL_FrameCap, .obj_id = 315 /* stack_13_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{58, {.type = CDL_FrameCap, .obj_id = 316 /* stack_14_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{59, {.type = CDL_FrameCap, .obj_id = 317 /* stack_15_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{60, {.type = CDL_FrameCap, .obj_id = 307 /* ipc_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{61, {.type = CDL_FrameCap, .obj_id = 43 /* frame_threads_0061 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{62, {.type = CDL_FrameCap, .obj_id = 44 /* frame_threads_0062 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{63, {.type = CDL_FrameCap, .obj_id = 45 /* frame_threads_0063 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{64, {.type = CDL_FrameCap, .obj_id = 46 /* frame_threads_0064 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{65, {.type = CDL_FrameCap, .obj_id = 47 /* frame_threads_0065 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{66, {.type = CDL_FrameCap, .obj_id = 48 /* frame_threads_0066 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{67, {.type = CDL_FrameCap, .obj_id = 49 /* frame_threads_0067 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{68, {.type = CDL_FrameCap, .obj_id = 50 /* frame_threads_0068 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{69, {.type = CDL_FrameCap, .obj_id = 51 /* frame_threads_0069 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{70, {.type = CDL_FrameCap, .obj_id = 52 /* frame_threads_0070 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{71, {.type = CDL_FrameCap, .obj_id = 53 /* frame_threads_0071 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{72, {.type = CDL_FrameCap, .obj_id = 54 /* frame_threads_0072 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{73, {.type = CDL_FrameCap, .obj_id = 55 /* frame_threads_0073 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{74, {.type = CDL_FrameCap, .obj_id = 56 /* frame_threads_0074 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{75, {.type = CDL_FrameCap, .obj_id = 57 /* frame_threads_0075 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{76, {.type = CDL_FrameCap, .obj_id = 58 /* frame_threads_0076 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{77, {.type = CDL_FrameCap, .obj_id = 59 /* frame_threads_0077 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{78, {.type = CDL_FrameCap, .obj_id = 60 /* frame_threads_0078 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{79, {.type = CDL_FrameCap, .obj_id = 61 /* frame_threads_0079 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{80, {.type = CDL_FrameCap, .obj_id = 62 /* frame_threads_0080 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{81, {.type = CDL_FrameCap, .obj_id = 63 /* frame_threads_0081 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{82, {.type = CDL_FrameCap, .obj_id = 64 /* frame_threads_0082 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{83, {.type = CDL_FrameCap, .obj_id = 65 /* frame_threads_0083 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{84, {.type = CDL_FrameCap, .obj_id = 66 /* frame_threads_0084 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{85, {.type = CDL_FrameCap, .obj_id = 67 /* frame_threads_0085 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{86, {.type = CDL_FrameCap, .obj_id = 68 /* frame_threads_0086 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{87, {.type = CDL_FrameCap, .obj_id = 69 /* frame_threads_0087 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{88, {.type = CDL_FrameCap, .obj_id = 70 /* frame_threads_0088 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{89, {.type = CDL_FrameCap, .obj_id = 71 /* frame_threads_0089 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{90, {.type = CDL_FrameCap, .obj_id = 72 /* frame_threads_0090 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{91, {.type = CDL_FrameCap, .obj_id = 73 /* frame_threads_0091 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{92, {.type = CDL_FrameCap, .obj_id = 74 /* frame_threads_0092 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{93, {.type = CDL_FrameCap, .obj_id = 75 /* frame_threads_0093 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{94, {.type = CDL_FrameCap, .obj_id = 76 /* frame_threads_0094 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{95, {.type = CDL_FrameCap, .obj_id = 77 /* frame_threads_0095 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{96, {.type = CDL_FrameCap, .obj_id = 78 /* frame_threads_0096 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{97, {.type = CDL_FrameCap, .obj_id = 79 /* frame_threads_0097 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{98, {.type = CDL_FrameCap, .obj_id = 80 /* frame_threads_0098 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{99, {.type = CDL_FrameCap, .obj_id = 81 /* frame_threads_0099 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{100, {.type = CDL_FrameCap, .obj_id = 82 /* frame_threads_0100 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{101, {.type = CDL_FrameCap, .obj_id = 83 /* frame_threads_0101 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{102, {.type = CDL_FrameCap, .obj_id = 84 /* frame_threads_0102 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{103, {.type = CDL_FrameCap, .obj_id = 85 /* frame_threads_0103 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{104, {.type = CDL_FrameCap, .obj_id = 86 /* frame_threads_0104 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{105, {.type = CDL_FrameCap, .obj_id = 87 /* frame_threads_0105 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{106, {.type = CDL_FrameCap, .obj_id = 88 /* frame_threads_0106 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{107, {.type = CDL_FrameCap, .obj_id = 89 /* frame_threads_0107 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{108, {.type = CDL_FrameCap, .obj_id = 90 /* frame_threads_0108 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{109, {.type = CDL_FrameCap, .obj_id = 91 /* frame_threads_0109 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{110, {.type = CDL_FrameCap, .obj_id = 92 /* frame_threads_0110 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{111, {.type = CDL_FrameCap, .obj_id = 93 /* frame_threads_0111 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{112, {.type = CDL_FrameCap, .obj_id = 94 /* frame_threads_0112 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{113, {.type = CDL_FrameCap, .obj_id = 95 /* frame_threads_0113 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{114, {.type = CDL_FrameCap, .obj_id = 96 /* frame_threads_0114 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{115, {.type = CDL_FrameCap, .obj_id = 97 /* frame_threads_0115 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{116, {.type = CDL_FrameCap, .obj_id = 98 /* frame_threads_0116 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{117, {.type = CDL_FrameCap, .obj_id = 99 /* frame_threads_0117 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{118, {.type = CDL_FrameCap, .obj_id = 100 /* frame_threads_0118 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{119, {.type = CDL_FrameCap, .obj_id = 101 /* frame_threads_0119 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{120, {.type = CDL_FrameCap, .obj_id = 102 /* frame_threads_0120 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{121, {.type = CDL_FrameCap, .obj_id = 103 /* frame_threads_0121 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{122, {.type = CDL_FrameCap, .obj_id = 104 /* frame_threads_0122 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{123, {.type = CDL_FrameCap, .obj_id = 105 /* frame_threads_0123 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{124, {.type = CDL_FrameCap, .obj_id = 106 /* frame_threads_0124 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{125, {.type = CDL_FrameCap, .obj_id = 107 /* frame_threads_0125 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{126, {.type = CDL_FrameCap, .obj_id = 108 /* frame_threads_0126 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{127, {.type = CDL_FrameCap, .obj_id = 109 /* frame_threads_0127 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{128, {.type = CDL_FrameCap, .obj_id = 110 /* frame_threads_0128 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{129, {.type = CDL_FrameCap, .obj_id = 111 /* frame_threads_0129 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{130, {.type = CDL_FrameCap, .obj_id = 112 /* frame_threads_0130 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{131, {.type = CDL_FrameCap, .obj_id = 113 /* frame_threads_0131 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{132, {.type = CDL_FrameCap, .obj_id = 114 /* frame_threads_0132 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{133, {.type = CDL_FrameCap, .obj_id = 115 /* frame_threads_0133 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{134, {.type = CDL_FrameCap, .obj_id = 116 /* frame_threads_0134 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{135, {.type = CDL_FrameCap, .obj_id = 117 /* frame_threads_0135 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{136, {.type = CDL_FrameCap, .obj_id = 118 /* frame_threads_0136 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{137, {.type = CDL_FrameCap, .obj_id = 119 /* frame_threads_0137 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{138, {.type = CDL_FrameCap, .obj_id = 120 /* frame_threads_0138 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{139, {.type = CDL_FrameCap, .obj_id = 121 /* frame_threads_0139 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{140, {.type = CDL_FrameCap, .obj_id = 122 /* frame_threads_0140 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{141, {.type = CDL_FrameCap, .obj_id = 123 /* frame_threads_0141 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{142, {.type = CDL_FrameCap, .obj_id = 124 /* frame_threads_0142 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{143, {.type = CDL_FrameCap, .obj_id = 125 /* frame_threads_0143 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{144, {.type = CDL_FrameCap, .obj_id = 126 /* frame_threads_0144 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{145, {.type = CDL_FrameCap, .obj_id = 127 /* frame_threads_0145 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{146, {.type = CDL_FrameCap, .obj_id = 128 /* frame_threads_0146 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{147, {.type = CDL_FrameCap, .obj_id = 129 /* frame_threads_0147 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{148, {.type = CDL_FrameCap, .obj_id = 130 /* frame_threads_0148 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{149, {.type = CDL_FrameCap, .obj_id = 131 /* frame_threads_0149 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{150, {.type = CDL_FrameCap, .obj_id = 132 /* frame_threads_0150 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{151, {.type = CDL_FrameCap, .obj_id = 133 /* frame_threads_0151 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{152, {.type = CDL_FrameCap, .obj_id = 134 /* frame_threads_0152 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{153, {.type = CDL_FrameCap, .obj_id = 135 /* frame_threads_0153 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{154, {.type = CDL_FrameCap, .obj_id = 136 /* frame_threads_0154 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{155, {.type = CDL_FrameCap, .obj_id = 137 /* frame_threads_0155 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{156, {.type = CDL_FrameCap, .obj_id = 138 /* frame_threads_0156 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{157, {.type = CDL_FrameCap, .obj_id = 139 /* frame_threads_0157 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{158, {.type = CDL_FrameCap, .obj_id = 140 /* frame_threads_0158 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{159, {.type = CDL_FrameCap, .obj_id = 141 /* frame_threads_0159 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{160, {.type = CDL_FrameCap, .obj_id = 142 /* frame_threads_0160 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{161, {.type = CDL_FrameCap, .obj_id = 143 /* frame_threads_0161 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{162, {.type = CDL_FrameCap, .obj_id = 144 /* frame_threads_0162 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{163, {.type = CDL_FrameCap, .obj_id = 145 /* frame_threads_0163 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{164, {.type = CDL_FrameCap, .obj_id = 146 /* frame_threads_0164 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{165, {.type = CDL_FrameCap, .obj_id = 147 /* frame_threads_0165 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{166, {.type = CDL_FrameCap, .obj_id = 148 /* frame_threads_0166 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{167, {.type = CDL_FrameCap, .obj_id = 149 /* frame_threads_0167 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{168, {.type = CDL_FrameCap, .obj_id = 150 /* frame_threads_0168 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{169, {.type = CDL_FrameCap, .obj_id = 151 /* frame_threads_0169 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{170, {.type = CDL_FrameCap, .obj_id = 152 /* frame_threads_0170 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{171, {.type = CDL_FrameCap, .obj_id = 153 /* frame_threads_0171 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{172, {.type = CDL_FrameCap, .obj_id = 154 /* frame_threads_0172 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{173, {.type = CDL_FrameCap, .obj_id = 155 /* frame_threads_0173 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{174, {.type = CDL_FrameCap, .obj_id = 156 /* frame_threads_0174 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{175, {.type = CDL_FrameCap, .obj_id = 157 /* frame_threads_0175 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{176, {.type = CDL_FrameCap, .obj_id = 158 /* frame_threads_0176 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{177, {.type = CDL_FrameCap, .obj_id = 159 /* frame_threads_0177 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{178, {.type = CDL_FrameCap, .obj_id = 160 /* frame_threads_0178 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{179, {.type = CDL_FrameCap, .obj_id = 161 /* frame_threads_0179 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{180, {.type = CDL_FrameCap, .obj_id = 162 /* frame_threads_0180 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{181, {.type = CDL_FrameCap, .obj_id = 163 /* frame_threads_0181 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{182, {.type = CDL_FrameCap, .obj_id = 164 /* frame_threads_0182 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{183, {.type = CDL_FrameCap, .obj_id = 165 /* frame_threads_0183 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{184, {.type = CDL_FrameCap, .obj_id = 166 /* frame_threads_0184 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{185, {.type = CDL_FrameCap, .obj_id = 167 /* frame_threads_0185 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{186, {.type = CDL_FrameCap, .obj_id = 168 /* frame_threads_0186 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{187, {.type = CDL_FrameCap, .obj_id = 169 /* frame_threads_0187 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{188, {.type = CDL_FrameCap, .obj_id = 170 /* frame_threads_0188 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{189, {.type = CDL_FrameCap, .obj_id = 171 /* frame_threads_0189 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{190, {.type = CDL_FrameCap, .obj_id = 172 /* frame_threads_0190 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{191, {.type = CDL_FrameCap, .obj_id = 173 /* frame_threads_0191 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{192, {.type = CDL_FrameCap, .obj_id = 174 /* frame_threads_0192 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{193, {.type = CDL_FrameCap, .obj_id = 175 /* frame_threads_0193 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{194, {.type = CDL_FrameCap, .obj_id = 176 /* frame_threads_0194 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{195, {.type = CDL_FrameCap, .obj_id = 177 /* frame_threads_0195 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{196, {.type = CDL_FrameCap, .obj_id = 178 /* frame_threads_0196 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{197, {.type = CDL_FrameCap, .obj_id = 179 /* frame_threads_0197 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{198, {.type = CDL_FrameCap, .obj_id = 180 /* frame_threads_0198 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{199, {.type = CDL_FrameCap, .obj_id = 181 /* frame_threads_0199 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{200, {.type = CDL_FrameCap, .obj_id = 182 /* frame_threads_0200 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{201, {.type = CDL_FrameCap, .obj_id = 183 /* frame_threads_0201 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{202, {.type = CDL_FrameCap, .obj_id = 184 /* frame_threads_0202 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{203, {.type = CDL_FrameCap, .obj_id = 185 /* frame_threads_0203 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{204, {.type = CDL_FrameCap, .obj_id = 186 /* frame_threads_0204 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{205, {.type = CDL_FrameCap, .obj_id = 187 /* frame_threads_0205 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{206, {.type = CDL_FrameCap, .obj_id = 188 /* frame_threads_0206 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{207, {.type = CDL_FrameCap, .obj_id = 189 /* frame_threads_0207 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{208, {.type = CDL_FrameCap, .obj_id = 190 /* frame_threads_0208 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{209, {.type = CDL_FrameCap, .obj_id = 191 /* frame_threads_0209 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{210, {.type = CDL_FrameCap, .obj_id = 192 /* frame_threads_0210 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{211, {.type = CDL_FrameCap, .obj_id = 193 /* frame_threads_0211 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{212, {.type = CDL_FrameCap, .obj_id = 194 /* frame_threads_0212 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{213, {.type = CDL_FrameCap, .obj_id = 195 /* frame_threads_0213 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{214, {.type = CDL_FrameCap, .obj_id = 196 /* frame_threads_0214 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{215, {.type = CDL_FrameCap, .obj_id = 197 /* frame_threads_0215 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{216, {.type = CDL_FrameCap, .obj_id = 198 /* frame_threads_0216 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{217, {.type = CDL_FrameCap, .obj_id = 199 /* frame_threads_0217 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{218, {.type = CDL_FrameCap, .obj_id = 200 /* frame_threads_0218 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{219, {.type = CDL_FrameCap, .obj_id = 201 /* frame_threads_0219 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{220, {.type = CDL_FrameCap, .obj_id = 202 /* frame_threads_0220 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{221, {.type = CDL_FrameCap, .obj_id = 203 /* frame_threads_0221 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{222, {.type = CDL_FrameCap, .obj_id = 204 /* frame_threads_0222 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{223, {.type = CDL_FrameCap, .obj_id = 205 /* frame_threads_0223 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{224, {.type = CDL_FrameCap, .obj_id = 206 /* frame_threads_0224 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{225, {.type = CDL_FrameCap, .obj_id = 207 /* frame_threads_0225 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{226, {.type = CDL_FrameCap, .obj_id = 208 /* frame_threads_0226 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{227, {.type = CDL_FrameCap, .obj_id = 209 /* frame_threads_0227 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{228, {.type = CDL_FrameCap, .obj_id = 210 /* frame_threads_0228 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{229, {.type = CDL_FrameCap, .obj_id = 211 /* frame_threads_0229 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{230, {.type = CDL_FrameCap, .obj_id = 212 /* frame_threads_0230 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{231, {.type = CDL_FrameCap, .obj_id = 213 /* frame_threads_0231 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{232, {.type = CDL_FrameCap, .obj_id = 214 /* frame_threads_0232 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{233, {.type = CDL_FrameCap, .obj_id = 215 /* frame_threads_0233 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{234, {.type = CDL_FrameCap, .obj_id = 216 /* frame_threads_0234 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{235, {.type = CDL_FrameCap, .obj_id = 217 /* frame_threads_0235 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{236, {.type = CDL_FrameCap, .obj_id = 218 /* frame_threads_0236 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{237, {.type = CDL_FrameCap, .obj_id = 219 /* frame_threads_0237 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{238, {.type = CDL_FrameCap, .obj_id = 220 /* frame_threads_0238 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{239, {.type = CDL_FrameCap, .obj_id = 221 /* frame_threads_0239 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{240, {.type = CDL_FrameCap, .obj_id = 222 /* frame_threads_0240 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{241, {.type = CDL_FrameCap, .obj_id = 223 /* frame_threads_0241 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{242, {.type = CDL_FrameCap, .obj_id = 224 /* frame_threads_0242 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{243, {.type = CDL_FrameCap, .obj_id = 225 /* frame_threads_0243 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{244, {.type = CDL_FrameCap, .obj_id = 226 /* frame_threads_0244 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{245, {.type = CDL_FrameCap, .obj_id = 227 /* frame_threads_0245 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{246, {.type = CDL_FrameCap, .obj_id = 228 /* frame_threads_0246 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{247, {.type = CDL_FrameCap, .obj_id = 229 /* frame_threads_0247 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{248, {.type = CDL_FrameCap, .obj_id = 230 /* frame_threads_0248 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{249, {.type = CDL_FrameCap, .obj_id = 231 /* frame_threads_0249 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{250, {.type = CDL_FrameCap, .obj_id = 232 /* frame_threads_0250 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{251, {.type = CDL_FrameCap, .obj_id = 233 /* frame_threads_0251 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{252, {.type = CDL_FrameCap, .obj_id = 234 /* frame_threads_0252 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{253, {.type = CDL_FrameCap, .obj_id = 235 /* frame_threads_0253 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{254, {.type = CDL_FrameCap, .obj_id = 236 /* frame_threads_0254 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{255, {.type = CDL_FrameCap, .obj_id = 237 /* frame_threads_0255 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{256, {.type = CDL_FrameCap, .obj_id = 238 /* frame_threads_0256 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{257, {.type = CDL_FrameCap, .obj_id = 239 /* frame_threads_0257 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{258, {.type = CDL_FrameCap, .obj_id = 240 /* frame_threads_0258 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{259, {.type = CDL_FrameCap, .obj_id = 241 /* frame_threads_0259 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{260, {.type = CDL_FrameCap, .obj_id = 242 /* frame_threads_0260 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{261, {.type = CDL_FrameCap, .obj_id = 243 /* frame_threads_0261 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{262, {.type = CDL_FrameCap, .obj_id = 244 /* frame_threads_0262 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{263, {.type = CDL_FrameCap, .obj_id = 245 /* frame_threads_0263 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{264, {.type = CDL_FrameCap, .obj_id = 246 /* frame_threads_0264 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{265, {.type = CDL_FrameCap, .obj_id = 247 /* frame_threads_0265 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{266, {.type = CDL_FrameCap, .obj_id = 248 /* frame_threads_0266 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{267, {.type = CDL_FrameCap, .obj_id = 249 /* frame_threads_0267 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{268, {.type = CDL_FrameCap, .obj_id = 250 /* frame_threads_0268 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{269, {.type = CDL_FrameCap, .obj_id = 251 /* frame_threads_0269 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{270, {.type = CDL_FrameCap, .obj_id = 252 /* frame_threads_0270 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{271, {.type = CDL_FrameCap, .obj_id = 253 /* frame_threads_0271 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{272, {.type = CDL_FrameCap, .obj_id = 254 /* frame_threads_0272 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{273, {.type = CDL_FrameCap, .obj_id = 255 /* frame_threads_0273 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{274, {.type = CDL_FrameCap, .obj_id = 256 /* frame_threads_0274 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{275, {.type = CDL_FrameCap, .obj_id = 257 /* frame_threads_0275 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{276, {.type = CDL_FrameCap, .obj_id = 258 /* frame_threads_0276 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{277, {.type = CDL_FrameCap, .obj_id = 259 /* frame_threads_0277 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{278, {.type = CDL_FrameCap, .obj_id = 260 /* frame_threads_0278 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{279, {.type = CDL_FrameCap, .obj_id = 261 /* frame_threads_0279 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{280, {.type = CDL_FrameCap, .obj_id = 262 /* frame_threads_0280 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{281, {.type = CDL_FrameCap, .obj_id = 263 /* frame_threads_0281 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{282, {.type = CDL_FrameCap, .obj_id = 264 /* frame_threads_0282 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{283, {.type = CDL_FrameCap, .obj_id = 265 /* frame_threads_0283 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{284, {.type = CDL_FrameCap, .obj_id = 266 /* frame_threads_0284 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{285, {.type = CDL_FrameCap, .obj_id = 267 /* frame_threads_0285 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{286, {.type = CDL_FrameCap, .obj_id = 268 /* frame_threads_0286 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{287, {.type = CDL_FrameCap, .obj_id = 269 /* frame_threads_0287 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{288, {.type = CDL_FrameCap, .obj_id = 270 /* frame_threads_0288 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{289, {.type = CDL_FrameCap, .obj_id = 271 /* frame_threads_0289 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{290, {.type = CDL_FrameCap, .obj_id = 272 /* frame_threads_0290 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{291, {.type = CDL_FrameCap, .obj_id = 273 /* frame_threads_0291 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{292, {.type = CDL_FrameCap, .obj_id = 274 /* frame_threads_0292 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{293, {.type = CDL_FrameCap, .obj_id = 275 /* frame_threads_0293 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{294, {.type = CDL_FrameCap, .obj_id = 276 /* frame_threads_0294 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{295, {.type = CDL_FrameCap, .obj_id = 277 /* frame_threads_0295 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{296, {.type = CDL_FrameCap, .obj_id = 278 /* frame_threads_0296 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{297, {.type = CDL_FrameCap, .obj_id = 279 /* frame_threads_0297 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{298, {.type = CDL_FrameCap, .obj_id = 280 /* frame_threads_0298 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{299, {.type = CDL_FrameCap, .obj_id = 281 /* frame_threads_0299 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{300, {.type = CDL_FrameCap, .obj_id = 282 /* frame_threads_0300 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{301, {.type = CDL_FrameCap, .obj_id = 283 /* frame_threads_0301 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{302, {.type = CDL_FrameCap, .obj_id = 284 /* frame_threads_0302 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{303, {.type = CDL_FrameCap, .obj_id = 285 /* frame_threads_0303 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{304, {.type = CDL_FrameCap, .obj_id = 286 /* frame_threads_0304 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{305, {.type = CDL_FrameCap, .obj_id = 287 /* frame_threads_0305 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{306, {.type = CDL_FrameCap, .obj_id = 288 /* frame_threads_0306 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{307, {.type = CDL_FrameCap, .obj_id = 289 /* frame_threads_0307 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{308, {.type = CDL_FrameCap, .obj_id = 290 /* frame_threads_0308 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{309, {.type = CDL_FrameCap, .obj_id = 291 /* frame_threads_0309 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{310, {.type = CDL_FrameCap, .obj_id = 292 /* frame_threads_0310 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{311, {.type = CDL_FrameCap, .obj_id = 293 /* frame_threads_0311 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{312, {.type = CDL_FrameCap, .obj_id = 294 /* frame_threads_0312 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{313, {.type = CDL_FrameCap, .obj_id = 295 /* frame_threads_0313 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{314, {.type = CDL_FrameCap, .obj_id = 296 /* frame_threads_0314 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{315, {.type = CDL_FrameCap, .obj_id = 297 /* frame_threads_0315 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{316, {.type = CDL_FrameCap, .obj_id = 298 /* frame_threads_0316 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{317, {.type = CDL_FrameCap, .obj_id = 299 /* frame_threads_0317 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{318, {.type = CDL_FrameCap, .obj_id = 300 /* frame_threads_0318 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{319, {.type = CDL_FrameCap, .obj_id = 301 /* frame_threads_0319 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{320, {.type = CDL_FrameCap, .obj_id = 302 /* frame_threads_0320 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{321, {.type = CDL_FrameCap, .obj_id = 303 /* frame_threads_0321 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{322, {.type = CDL_FrameCap, .obj_id = 304 /* frame_threads_0322 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{323, {.type = CDL_FrameCap, .obj_id = 305 /* frame_threads_0323 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{324, {.type = CDL_FrameCap, .obj_id = 306 /* frame_threads_0324 */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},

},
},
[311] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_0_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 176128
}},}
 },
},
[312] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_10_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 217088
}},}
 },
},
[313] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_11_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 221184
}},}
 },
},
[314] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_12_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 225280
}},}
 },
},
[315] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_13_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 229376
}},}
 },
},
[316] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_14_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 233472
}},}
 },
},
[317] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_15_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 237568
}},}
 },
},
[318] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_1_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 180224
}},}
 },
},
[319] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_2_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 184320
}},}
 },
},
[320] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_3_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 188416
}},}
 },
},
[321] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_4_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 192512
}},}
 },
},
[322] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_5_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 196608
}},}
 },
},
[323] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_6_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 200704
}},}
 },
},
[324] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_7_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 204800
}},}
 },
},
[325] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_8_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 208896
}},}
 },
},
[326] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "stack_9_threads_obj",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 212992
}},}
 },
},
[327] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "tcb_ipc_frame",
#endif
.type = CDL_Frame,
.size_bits = 12,
.frame_extra = { .paddr = 0,.fill = { {.type = CDL_FrameFill_FileData,
.dest_offset = 0,
.dest_len = 4096,
.file_data_type = {.filename = "threads",
.file_offset = 106496
}},}
 },
},
[328] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "vspace_threads",
#endif
.type = CDL_PML4,
.slots.num = 1,
.slots.slot = (CDL_CapSlot[]) {
{0, {.type = CDL_PDPTCap, .obj_id = 309 /* pdpt_threads_0000 */, .is_orig = true}},

},
},
[329] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "tcb_threads",
#endif
.type = CDL_TCB,
.tcb_extra = {
#if (0x43c000 & ((1 << seL4_IPCBufferSizeBits) - 1)) != 0
#    error "IPC buffer not correctly aligned"
#endif
.ipcbuffer_addr = 0x43c000,
.priority = 254,
.max_priority = 254,
.affinity = 0,
.pc = 0x401034,
.sp = 0x42d000,
.init = (const seL4_Word[]){0, 0, 0, 0, 2, 4292672, 1, 0, 0, 32, 4212419, 0, 0},
.init_sz = 13,
.domain = 0,
.resume = 1,
.fault_ep = 0,
},
.slots.num = 3,
.slots.slot = (CDL_CapSlot[]) {
{0, {.type = CDL_CNodeCap, .obj_id = 331 /* cnode_threads */, .is_orig = true, .rights = CDL_AllRights, .data = CDL_CapData_MakeGuard(60, 0)}},
{1, {.type = CDL_PML4Cap, .obj_id = 328 /* vspace_threads */, .is_orig = true}},
{4, {.type = CDL_FrameCap, .obj_id = 307 /* ipc_threads_obj */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},

},
},
[330] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "tcb_untyped",
#endif
.type = CDL_Untyped,
.size_bits = 11,
.paddr = 0,
},
[331] = {
#ifdef CONFIG_DEBUG_BUILD
.name = "cnode_threads",
#endif
.type = CDL_CNode,
.size_bits = 4,
.slots.num = 7,
.slots.slot = (CDL_CapSlot[]) {
{1, {.type = CDL_CNodeCap, .obj_id = 331 /* cnode_threads */, .is_orig = true, .rights = CDL_AllRights, .data = CDL_CapData_MakeGuard(60, 0)}},
{2, {.type = CDL_PML4Cap, .obj_id = 328 /* vspace_threads */, .is_orig = true}},
{3, {.type = CDL_TCBCap, .obj_id = 329 /* tcb_threads */, .is_orig = true, .rights = CDL_AllRights}},
{4, {.type = CDL_UntypedCap, .obj_id = 330 /* tcb_untyped */}},
{5, {.type = CDL_FrameCap, .obj_id = 0 /* buf2_frame_cap */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{7, {.type = CDL_FrameCap, .obj_id = 327 /* tcb_ipc_frame */, .is_orig = true, .rights = (CDL_CanRead|CDL_CanWrite|CDL_CanGrant), .vm_attribs = seL4_ARCH_Default_VMAttributes, .mapping_container_id = INVALID_OBJ_ID, .mapping_slot = 0}},
{8, {.type = CDL_TCBCap, .obj_id = 329 /* tcb_threads */, .is_orig = true, .rights = CDL_AllRights}},

},
},

},
.num_untyped = 0,
.untyped = NULL,
.num_asid_slots = 1,
.asid_slots = (CDL_ObjID[]){
    (CDL_ObjID)-1 /* slot reserved for root thread, ignored */
},
};