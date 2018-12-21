#ifndef	H_TYPEDEFS
#define	H_TYPEDEFS
/****************************************************************************\
* 																			 *
* Template:		<^f^>														 *
* 																			 *
* File:		typedefs.h														 *
* 																			 *
* Description:	This file contains commonly used type and macro definitions. *
* 																			 *
* Created by:	Bruce A. Mallett	07-August-1987							 *
* 																			 *
\****************************************************************************/

#include	"config.h"

#if	CC_C86|CC_MSC
typedef char    byte;					/* At least  8 bits */
typedef int     word;					/* At least 16 bits */
typedef long    lword;					/* At least 32 bits */

typedef unsigned char u_byte;			/* At least 8 bits */
typedef unsigned int u_word;			/* At least 16 bits */
typedef unsigned long u_lword;			/* At least 32 bits */

#endif

#if	CC_RT|CC_VMS|(CC_UNIX&HW_VAX)|HW_SUN68K
typedef char    byte;					/* At least  8 bits */
typedef short   word;					/* At least 16 bits */
typedef int     lword;					/* At least 32 bits */

typedef unsigned char u_byte;			/* At least 8 bits */
typedef unsigned short u_word;			/* At least 16 bits */
typedef unsigned int u_lword;			/* At least 32 bits */

#endif

#undef bool
typedef u_byte  bool;					/* Boolean variable */

typedef u_word  bit;					/* Declares bit fields */
typedef void    (*FUNC) ();				/* Pointer to void function */
typedef int     (*IFUNC) ();			/* Pointer to integer function */

#undef	NULL

#if		ANSI_C
#define	NIL		((void *)0)
#else
#define	NIL		((long)0)
#endif									/* ANSI_C */
#define	NULL	NIL

/*************************************************************************\
* 																		  *
* Take care of some things which are not available in non-ANSII			  *
* compatible C compilers:												  *
* 																		  *
\*************************************************************************/

#if		!ANSI_C

#define	const

#endif									/* ANSI_C */

/*************************************************************************\
* 																		  *
* Define the exit codes which may be passed to exit():					  *
* 																		  *
\*************************************************************************/

#if	CC_VMS
#define	EXIT_FAILED	0
#define	EXIT_SUCCESS	1
#else
#define	EXIT_FAILED		1
#define	EXIT_SUCCESS	0
#endif

/*************************************************************************\
* 																		  *
* PRIVATE																  *
* PUBLIC																  *
* 	These are useful substitutions for declaring the scope of a			  *
* 	name.  PUBLIC makes things available outside the current			  *
* 	context (globally available).  PRIVATE restricts the scope			  *
* 	of the name to the current context.									  *
* 																		  *
\*************************************************************************/

#define	PRIVATE	static
#define	PUBLIC

/*************************************************************************\
* 																		  *
* lengthof(x[])															  *
* 	This macro will return the number of elements in the array x[]		  *
* 																		  *
\*************************************************************************/

#define	lengthof(x)	(sizeof(x)/sizeof(x[0]))

#endif									/* H_TYPEDEFS */
