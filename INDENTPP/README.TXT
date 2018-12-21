---------------------------------------------------------------------

Indent is a C/C++ program formatter.  It reformats the C/C++ program
in the input-file according to a long list of command line switches.

The original indent (part of the Berkeley Software Distribution) was
only for C programs.  It has since been modified to understand C++
syntax as well.

---------------------------------------------------------------------

			A quick guide to indent
		(for impatient users of OS/2 or MSDOS)

Assuming you have managed to unpack the distribution sources and have
compiled indent.exe:-

1. Set up an environment variable called HOME pointing at some directory
   where you keep useful things.  Copy indent.pro into that directory.

2. If you use a brain-damaged editor which doesn't allow tabs to be set
   at any interval other than 8 columns, either change the line in
   indent.pro which says
	-tabs 4
   or simply remove it altogether.

3. Copy indent.exe to some directory on your PATH.

4. Change directory to where your messy C or C++ programs reside.

5. To clean up all the programs issue the command:
	for %f in (*.c *.cpp) do indent %f

---------------------------------------------------------------------

		     An even quicker guide to indent
		(for impatient users of BSD-flavoured UNIX)

Read the guide for OS/2-MSDOS and make the following changes:

1. Copy indent.pro into your home directory, calling it .indent.pro

5. Use a loop syntax appropriate for your shell.

---------------------------------------------------------------------

                      OS/2 implementor's note
                      -----------------------

There seems to have been three streams of development for this program.

The original indent was ported to MSDOS by Bruce Mallett and various fixes
were done by Bruce Mallett and James Thompson.  James Thompson also imple-
mented the handling of tabs at spacings other than 8 (surely a most worth-
while enhancement; who programs in C with tabs set at 8 anyway?)

While all this good stuff was going on, other (unnamed) people upgraded the
original program to handle C++ syntax as well as ordinary C and apparently
fixed a few minor annoyances which were extant in the version from which
the MSDOS implementation was derived.

Then of course, the GNU project people have been doing things with sources
obviously derived from the BSD version.  I have not looked at the GNU
version of indent.

I started with the BSD C++ formatter sources and modified them for
compilation with Microsoft C386 under OS/2 2.0.  That gave me a working
baseline version to which I made the following modifications:

1  Changed some of the file names to allow compilation with Microsoft C
   version 6.00A which objects to files whose names do not conform to
   MSDOS's 8.3 format.

2  Built new makefiles for OS/2 2.0 and for OS/2 1.X.  (The MSDOS version
   is created by post-processing the OS/2 1.X version.)

   Note that when you use Makefile.1x you'll see some warning messages
   concerning the truncation of variable names.  You may safely ignore
   them.  The messages do not appear when compiling the 32-bit version.

2  Added James Thompson's tab stuff.

3  Fixed a bug which was causing //-style comments to be followed by an
   extra newline or an extra space depending on context.

4  Corrected the stack overflow problem in the OS/2 1.x and MSDOS versions.
   (This seems to have been independently discovered and fixed twice
   previously but the sources contained no trace of the fix.)

5  Patched the manual source to reflect the new -tabs option and generated
   a human-readable version.

Finally, I put the sources through the indenter to clean up the mess.

More recently still, I built the program using the IBM C Set/2 tools after
generating yet another Makefile.  I also fixed a bug notified by Steve
Comen which was causing overlength // comments to be split incorrectly.

Now, if I have done the job properly, the current source should combine both
the BSD development streams.  Furthermore, it should compile under OS/2 1.x
for OS/2 and MSDOS, under OS/2 2.0 for the 32-bit 'flat' model using either
the Microsoft C386 compiler or the IBM C Set/2 compiler and on the original
BSD UNIX platform.

I am indebted to Steve Comen and his colleagues for help with testing and
verifying the BSD compatibility and for several patches.

Now all that remains to be done is to incorporate the nicer features of this
version into the GNU one.  Any volunteers?

Jon Saxton
April 1992

-------------------------------------------------------------------------

Manifest

	args.c		\
	comment.c	 \
	indent.c	  \_	Program source files
	io.c		  /
	lexi.c		 /
	parse.c		/

	codes.h		\
	globals.h	 >-	Header files
	proto.h		/

	indent.1		Manual source

	indent.man		Manual in human-readable form

	indent.def		Used only when compiling
				under OS/2 for OS/2 or MSDOS

	indent.pro		A sample profile (the one used to format
				these sources).  Rename to .indent.pro
				for use with BSD UNIX.

	Makefile.1x		Makefile for compiling under OS/2 1.x.
				Generates a bound 16-bit executable which
				will run under OS/2 or MSDOS.

	Makefile.20		Makefile for compiling under OS/2 2.0 using
				the Microsoft C386 compiler.  Generates a
				32-bit executable.

	Makefile.cs2		Makefile for compiling under OS/2 2.0 using
				the IBM C Set/2 compiler.  Generates a 32-
				bit executable.

	Makefile.bsd		Untouched.  This is the original Makefile
				as distributed with the BSD version.

	readme			This file
