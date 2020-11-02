
.section ._archive_cpio,"aw"
.globl _capdl_archive, _capdl_archive_end
_capdl_archive:
.incbin "archive.capdl-loader_archive.o.cpio"
_capdl_archive_end:

