#ifndef	H_CONFIG
#define	H_CONFIG
/****************************************************************************\
* 																			 *
* Template:		<^f^>														 *
* 																			 *
* File:		config.h														 *
* 																			 *
* Description:	This file contains definitions which describe the			 *
* 				configuration of the target machine.						 *
* 																			 *
* Created by:	Bruce A. Mallett	12-NOV-86								 *
* 																			 *
\****************************************************************************/

/****************************************************************************\
* 																			 *
* Define the hardware upon which this package is to be run.  Only one of	 *
* the following constants may have a value of 1, all others must be zero.	 *
* The current definitons are:												 *
* 																			 *
*   HW_IBMRT	An IBM RT													 *
*   HW_IBMPC   An IBM PC or compatible										 *
*   HW_IBMAT   An IBM AT or compatible										 *
*   HW_SUN68K	A Sun MicroSystems based on a Motorola 680x0 processor		 *
*   HW_VAX	A Digital Equipment Corporation VAX								 *
* 																			 *
\****************************************************************************/

#define	HW_IBMAT	1
#define	HW_IBMPC	0
#define	HW_IBMRT	0
#define	HW_SUN68K	0
#define	HW_VAX		0


/****************************************************************************\
* 																			 *
* Define the operating system under which this package is to be run.  Only	 *
* one of the following constants may have a value of one, all others must	 *
* be zero.  The constants are as follows:									 *
* 																			 *
*   OS_CPM	Digital Research CP/M											 *
*   OS_MSDOS	Microsoft MS-DOS or IBM PC-DOS								 *
*   OS_VMS	Digital Equipment Corp. Vax-VMS									 *
*   OS_UNIX	Unix (one flavor or another)									 *
* 																			 *
\****************************************************************************/

#define	OS_CPM		0
#define	OS_MSDOS	1
#define	OS_VMS		0
#define	OS_UNIX		0


/****************************************************************************\
* 																			 *
* Define the C Compiler.  Set only one of the following constants to 1		 *
* according to the C environment in use.  The current definitions are:		 *
* 																			 *
*   CC_C86		Computer Innovations C86									 *
*   CC_MSC		Microsoft C													 *
*   CC_RT		Standard IBM RT												 *
*   CC_UNIX		Unix (or something close)									 *
*   CC_VMS		Standard Vax VMS											 *
* 																			 *
\****************************************************************************/

#define	CC_C86		0
#define	CC_MSC		1
#define	CC_RT		0
#define	CC_UNIX		0
#define	CC_VMS		0


/****************************************************************************\
* 																			 *
* ANSI_C																	 *
* 	Set this definiton to 1 if the C compiler is ANSI_C compatible.			 *
* 	Set it to zero otherwise.												 *
* 																			 *
\****************************************************************************/
#define	ANSI_C		0


/****************************************************************************\
* 																			 *
* PROTOTYPE																	 *
* 	In your makefile use the /DEFINE, -D, or /D switch (or whatever			 *
* 	is appropriate for your compiler) to define PROTOTYPE iff your			 *
* 	compiler supports statement prototyping.								 *
* 																			 *
\****************************************************************************/

/* #define	PROTOTYPE *//* Define on compiler invocation line */

#endif									/* H_CONFIG */
