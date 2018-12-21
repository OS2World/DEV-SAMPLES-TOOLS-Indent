PROJ = indent
PROJFILE = indent.mak
DEBUG = 0

PWBRMAKE	= pwbrmake
NMAKEBSC1  = set
NMAKEBSC2  = nmake
CC	= cl
CFLAGS_G	= /W2 /BATCH /FR$*.sbr
CFLAGS_D	= /qc /Girel\$(PROJ).mdt /Zr /Zi /Od
CFLAGS_R	= /Ot /Ol /Og /Oe /Oi /Gs
ASM  = ml
AFLAGS_G	= /Cx /W2 /WX /FR$*.sbr
AFLAGS_D	= /Zi
AFLAGS_R	= /nologo
MAPFILE_D  = NUL
MAPFILE_R  = NUL
LFLAGS_G	=  /NOI  /BATCH
LFLAGS_D	= /CO /FAR /PACKC /PACKD /PMTYPE:VIO
LFLAGS_R	=  /EXE /FAR /PACKC /PACKD	/PMTYPE:VIO
LINKER	= link
ILINK  = ilink
LRF  = echo > NUL
BIND	= bind
LLIBS_R  =	/NOD:SLIBCE SLIBCEP
LLIBS_D  =	/NOD:SLIBCE SLIBCEP
BRFLAGS  =	/o rel\$(PROJ).bsc
BROWSE	= 1

OBJS	= rel\ARGS.obj rel\COMMENT.obj rel\INDENT.obj rel\LEXI.obj rel\IO.obj\
				rel\PARSE.obj
SBRS	= rel\ARGS.sbr rel\COMMENT.sbr rel\INDENT.sbr rel\LEXI.sbr rel\IO.sbr\
				rel\PARSE.sbr

all: rel\$(PROJ).exe

.SUFFIXES:
.SUFFIXES: .sbr .obj .c

rel\ARGS.obj : ARGS.C globs.h msdos.h C:\CMPLRS\C600\INCLUDE\malloc.h\
				C:\CMPLRS\C600\INCLUDE\sys\types.h C:\CMPLRS\C600\INCLUDE\ctype.h\
				C:\CMPLRS\C600\INCLUDE\stdio.h typedefs.h config.h
!IF $(DEBUG)
				$(CC) /c $(CFLAGS_G) $(CFLAGS_D) /Forel\ARGS.obj ARGS.C
!ELSE
				$(CC) /c $(CFLAGS_G) $(CFLAGS_R) /Forel\ARGS.obj ARGS.C
!ENDIF

rel\ARGS.sbr : ARGS.C globs.h msdos.h C:\CMPLRS\C600\INCLUDE\malloc.h\
				C:\CMPLRS\C600\INCLUDE\sys\types.h C:\CMPLRS\C600\INCLUDE\ctype.h\
				C:\CMPLRS\C600\INCLUDE\stdio.h typedefs.h config.h
!IF $(DEBUG)
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_D) /FRrel\ARGS.sbr ARGS.C
!ELSE
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_R) /FRrel\ARGS.sbr ARGS.C
!ENDIF

rel\COMMENT.obj : COMMENT.C config.h C:\CMPLRS\C600\INCLUDE\malloc.h globs.h\
				C:\CMPLRS\C600\INCLUDE\stdio.h typedefs.h
!IF $(DEBUG)
				$(CC) /c $(CFLAGS_G) $(CFLAGS_D) /Forel\COMMENT.obj COMMENT.C
!ELSE
				$(CC) /c $(CFLAGS_G) $(CFLAGS_R) /Forel\COMMENT.obj COMMENT.C
!ENDIF

rel\COMMENT.sbr : COMMENT.C config.h C:\CMPLRS\C600\INCLUDE\malloc.h globs.h\
				C:\CMPLRS\C600\INCLUDE\stdio.h typedefs.h
!IF $(DEBUG)
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_D) /FRrel\COMMENT.sbr COMMENT.C
!ELSE
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_R) /FRrel\COMMENT.sbr COMMENT.C
!ENDIF

rel\INDENT.obj : INDENT.C config.h globs.h codes.h msdos.h\
				C:\CMPLRS\C600\INCLUDE\malloc.h C:\CMPLRS\C600\INCLUDE\ctype.h\
				C:\CMPLRS\C600\INCLUDE\memory.h C:\CMPLRS\C600\INCLUDE\string.h\
				C:\CMPLRS\C600\INCLUDE\stdio.h typedefs.h
!IF $(DEBUG)
				$(CC) /c $(CFLAGS_G) $(CFLAGS_D) /Forel\INDENT.obj INDENT.C
!ELSE
				$(CC) /c $(CFLAGS_G) $(CFLAGS_R) /Forel\INDENT.obj INDENT.C
!ENDIF

rel\INDENT.sbr : INDENT.C config.h globs.h codes.h msdos.h\
				C:\CMPLRS\C600\INCLUDE\malloc.h C:\CMPLRS\C600\INCLUDE\ctype.h\
				C:\CMPLRS\C600\INCLUDE\memory.h C:\CMPLRS\C600\INCLUDE\string.h\
				C:\CMPLRS\C600\INCLUDE\stdio.h typedefs.h
!IF $(DEBUG)
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_D) /FRrel\INDENT.sbr INDENT.C
!ELSE
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_R) /FRrel\INDENT.sbr INDENT.C
!ENDIF

rel\LEXI.obj : LEXI.C globs.h codes.h C:\CMPLRS\C600\INCLUDE\ctype.h\
				C:\CMPLRS\C600\INCLUDE\stdio.h typedefs.h config.h
!IF $(DEBUG)
				$(CC) /c $(CFLAGS_G) $(CFLAGS_D) /Forel\LEXI.obj LEXI.C
!ELSE
				$(CC) /c $(CFLAGS_G) $(CFLAGS_R) /Forel\LEXI.obj LEXI.C
!ENDIF

rel\LEXI.sbr : LEXI.C globs.h codes.h C:\CMPLRS\C600\INCLUDE\ctype.h\
				C:\CMPLRS\C600\INCLUDE\stdio.h typedefs.h config.h
!IF $(DEBUG)
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_D) /FRrel\LEXI.sbr LEXI.C
!ELSE
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_R) /FRrel\LEXI.sbr LEXI.C
!ENDIF

rel\IO.obj : IO.C globs.h C:\CMPLRS\C600\INCLUDE\ctype.h\
				C:\CMPLRS\C600\INCLUDE\memory.h C:\CMPLRS\C600\INCLUDE\stdio.h\
				typedefs.h config.h
!IF $(DEBUG)
				$(CC) /c $(CFLAGS_G) $(CFLAGS_D) /Forel\IO.obj IO.C
!ELSE
				$(CC) /c $(CFLAGS_G) $(CFLAGS_R) /Forel\IO.obj IO.C
!ENDIF

rel\IO.sbr : IO.C globs.h C:\CMPLRS\C600\INCLUDE\ctype.h\
				C:\CMPLRS\C600\INCLUDE\memory.h C:\CMPLRS\C600\INCLUDE\stdio.h\
				typedefs.h config.h
!IF $(DEBUG)
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_D) /FRrel\IO.sbr IO.C
!ELSE
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_R) /FRrel\IO.sbr IO.C
!ENDIF

rel\PARSE.obj : PARSE.C globs.h codes.h C:\CMPLRS\C600\INCLUDE\stdio.h\
				typedefs.h config.h
!IF $(DEBUG)
				$(CC) /c $(CFLAGS_G) $(CFLAGS_D) /Forel\PARSE.obj PARSE.C
!ELSE
				$(CC) /c $(CFLAGS_G) $(CFLAGS_R) /Forel\PARSE.obj PARSE.C
!ENDIF

rel\PARSE.sbr : PARSE.C globs.h codes.h C:\CMPLRS\C600\INCLUDE\stdio.h\
				typedefs.h config.h
!IF $(DEBUG)
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_D) /FRrel\PARSE.sbr PARSE.C
!ELSE
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_R) /FRrel\PARSE.sbr PARSE.C
!ENDIF


rel\$(PROJ).bsc : $(SBRS)
				$(PWBRMAKE) @<<
$(BRFLAGS) $(SBRS)
<<

rel\$(PROJ).exe : $(OBJS)
!IF $(DEBUG)
				$(LRF) @<<rel\$(PROJ).lrf
$(RT_OBJS: = +^
) $(OBJS: = +^
)
$@
$(MAPFILE_D)
$(LLIBS_G: = +^
) +
$(LLIBS_D: = +^
) +
$(LIBS: = +^
)
$(DEF_FILE) $(LFLAGS_G) $(LFLAGS_D);
<<
!ELSE
				$(LRF) @<<rel\$(PROJ).lrf
$(RT_OBJS: = +^
) $(OBJS: = +^
)
$@
$(MAPFILE_R)
$(LLIBS_G: = +^
) +
$(LLIBS_R: = +^
) +
$(LIBS: = +^
)
$(DEF_FILE) $(LFLAGS_G) $(LFLAGS_R);
<<
!ENDIF
				$(LINKER) @rel\$(PROJ).lrf
				$(BIND) $@ api.lib -o $@
				$(NMAKEBSC1) MAKEFLAGS=
				$(NMAKEBSC2) $(NMFLAGS) -f $(PROJFILE) rel\$(PROJ).bsc


.c.sbr :
!IF $(DEBUG)
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_D) /FR$@ $<
!ELSE
				$(CC) /Zs $(CFLAGS_G) $(CFLAGS_R) /FR$@ $<
!ENDIF

.c.obj :
!IF $(DEBUG)
				$(CC) /c $(CFLAGS_G) $(CFLAGS_D) /Fo$@ $<
!ELSE
				$(CC) /c $(CFLAGS_G) $(CFLAGS_R) /Fo$@ $<
!ENDIF


run: rel\$(PROJ).exe
				rel\$(PROJ).exe $(RUNFLAGS)

debug: rel\$(PROJ).exe
				CVP $(CVFLAGS) rel\$(PROJ).exe $(RUNFLAGS)
