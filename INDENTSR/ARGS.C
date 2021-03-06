/*
 * Copyright (c) 1985 Sun Microsystems, Inc.
 * Copyright (c) 1980 The Regents of the University of California.
 * Copyright (c) 1976 Board of Trustees of the University of Illinois.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley, the University of Illinois,
 * Urbana, and Sun Microsystems, Inc.  The name of either University
 * or Sun Microsystems may not be used to endorse or promote products
 * derived from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef lint
static char sccsid[] = "@(#)args.c  5.6 (Berkeley) 88/09/15";

#endif					/* not lint */

/*
 * Argument scanning and profile reading code.	Default parameters are set
 * here as well.
 */

#include "globals.h"
#include <sys/types.h>
#include <ctype.h>

#ifdef MSDOS				/* or OS/2 */
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define index(a,b) strchr(a,b)
#else
char *getenv(), *index();

#endif

#ifdef ANSIC
void scan_profile(FILE *);

#endif

/* profile types */
#define PRO_SPECIAL 1			/* special case */
#define PRO_BOOL    2			/* boolean */
#define PRO_INT	    3			/* integer */
#define PRO_FONT    4			/* troff font */

/* profile specials for booleans */
#define ON	1			/* turn it on */
#define OFF	0			/* turn it off */

/* profile specials for specials */
#define IGN	1			/* ignore it */
#define CLI	2			/* case label indent (float) */
#define STDIN	    3			/* use stdin */
#define KEY	4			/* type (keyword) */
#define CCI	5			/* case code indent (float) */

/*
 * N.B.: because of the way the table here is scanned, options whose names are
 * substrings of other options must occur later; that is, with -lp vs -l, -lp
 * must be first.  Also, while (most) booleans occur more than once, the last
 * default value is the one actually assigned.
 */
struct pro {
    char *p_name;			/* name, eg -bl, -cli */
    int p_type;				/* type (int, bool, special) */
    int p_default;			/* the default value (if int) */
    int p_special;			/* depends on type */
    int *p_obj;				/* the associated variable */
} pro[] =

{

    "T", PRO_SPECIAL, 0, KEY, 0,
    "bacc", PRO_BOOL, false, ON, &blanklines_around_conditional_compilation,
    "badp", PRO_BOOL, false, ON, &blanklines_after_declarations_at_proctop,
    "bad", PRO_BOOL, false, ON, &blanklines_after_declarations,
    "bap", PRO_BOOL, false, ON, &blanklines_after_procs,
    "bbb", PRO_BOOL, false, ON, &blanklines_before_blockcomments,
    "bc", PRO_BOOL, true, OFF, &ps.leave_comma,
    "bl", PRO_BOOL, false, OFF, &btype_2,
    "brr", PRO_BOOL, false, ON, &btype_3,
    "br", PRO_BOOL, true, ON, &btype_2,
    "bs", PRO_BOOL, false, ON, &Bill_Shannon,
    "cdb", PRO_BOOL, true, ON, &comment_delimiter_on_blankline,
    "cd", PRO_INT, 0, 0, &ps.decl_com_ind,
    "ce", PRO_BOOL, true, ON, &cuddle_else,
    "ci", PRO_INT, 0, 0, &continuation_indent,
    "cli", PRO_SPECIAL, 0, CLI, 0,
    "cci", PRO_SPECIAL, 0, CCI, 0,
    "c", PRO_INT, 33, 0, &ps.com_ind,
    "di", PRO_INT, 16, 0, &ps.decl_indent,
    "dj", PRO_BOOL, false, ON, &ps.ljust_decl,
    "d", PRO_INT, 0, 0, &ps.unindent_displace,
    "eei", PRO_BOOL, false, ON, &extra_expression_indent,
    "ei", PRO_BOOL, true, ON, &ps.else_if,
    "fbc", PRO_FONT, 0, 0, (int *) &blkcomf,
    "fbx", PRO_FONT, 0, 0, (int *) &boxcomf,
    "fb", PRO_FONT, 0, 0, (int *) &bodyf,
    "fc1", PRO_BOOL, true, ON, &format_col1_comments,
    "fc", PRO_FONT, 0, 0, (int *) &scomf,
    "fk", PRO_FONT, 0, 0, (int *) &keywordf,
    "fs", PRO_FONT, 0, 0, (int *) &stringf,
    "ip", PRO_BOOL, true, ON, &ps.indent_parameters,
    "i", PRO_INT, 8, 0, &ps.ind_size,
    "lc", PRO_INT, 0, 0, &block_comment_max_col,
    "lp", PRO_BOOL, true, ON, &lineup_to_parens,
    "l", PRO_INT, 78, 0, &max_col,
    "nbacc", PRO_BOOL, false, OFF, &blanklines_around_conditional_compilation,
    "nbadp", PRO_BOOL, false, OFF, &blanklines_after_declarations_at_proctop,
    "nbad", PRO_BOOL, false, OFF, &blanklines_after_declarations,
    "nbap", PRO_BOOL, false, OFF, &blanklines_after_procs,
    "nbbb", PRO_BOOL, false, OFF, &blanklines_before_blockcomments,
    "nbc", PRO_BOOL, true, ON, &ps.leave_comma,
    "nbs", PRO_BOOL, false, OFF, &Bill_Shannon,
    "ncdb", PRO_BOOL, true, OFF, &comment_delimiter_on_blankline,
    "nce", PRO_BOOL, true, OFF, &cuddle_else,
    "ndj", PRO_BOOL, false, OFF, &ps.ljust_decl,
    "neei", PRO_BOOL, false, OFF, &extra_expression_indent,
    "nei", PRO_BOOL, true, OFF, &ps.else_if,
    "nfc1", PRO_BOOL, true, OFF, &format_col1_comments,
    "nip", PRO_BOOL, true, OFF, &ps.indent_parameters,
    "nlp", PRO_BOOL, true, OFF, &lineup_to_parens,
    "npcs", PRO_BOOL, false, OFF, &proc_calls_space,
    "npro", PRO_SPECIAL, 0, IGN, 0,
    "nprs", PRO_BOOL, false, OFF, &parens_space,
    "npsl", PRO_BOOL, true, OFF, &procnames_start_line,
    "nps", PRO_BOOL, false, OFF, &pointer_as_binop,
    "nsc", PRO_BOOL, true, OFF, &star_comment_cont,
    "nsob", PRO_BOOL, false, OFF, &swallow_optional_blanklines,
    "nv", PRO_BOOL, false, OFF, &verbose,
    "pcs", PRO_BOOL, false, ON, &proc_calls_space,
    "prs", PRO_BOOL, false, ON, &parens_space,
    "psl", PRO_BOOL, true, ON, &procnames_start_line,
    "ps", PRO_BOOL, false, ON, &pointer_as_binop,
    "sc", PRO_BOOL, true, ON, &star_comment_cont,
    "sob", PRO_BOOL, false, ON, &swallow_optional_blanklines,
    "st", PRO_SPECIAL, 0, STDIN, 0,
    "tabs", PRO_INT, 8, 0, &tabsize,
    "troff", PRO_BOOL, false, ON, &troff,
    "v", PRO_BOOL, false, ON, &verbose,
    "+", PRO_BOOL, false, ON, &cplus,
    /* whew! */
    0, 0, 0, 0, 0
};

/*
 * set_profile reads $HOME/.indent.pro and ./.indent.pro and handles arguments
 * given in these files.
 */
#ifdef ANSIC
void 
set_profile(void)
#else
set_profile()
#endif
{
    FILE *f;
    char fname[BUFSIZ];

#ifdef MSDOS				/* or OS/2 */
    static char prof[] = "indent.pro";

#else
    static char prof[] = ".indent.pro";

#endif
    sprintf(fname, "%s/%s", getenv("HOME"), prof);
    if ((f = fopen(fname, "r")) != NULL) {
	scan_profile(f);
	(void) fclose(f);
    }
    if ((f = fopen(prof, "r")) != NULL) {
	scan_profile(f);
	(void) fclose(f);
    }
}

#ifdef ANSIC
void 
scan_profile(FILE * f)
#else
scan_profile(f)
    FILE *f;

#endif
{
    register int i;
    register char *p;
    char buf[BUFSIZ];

    while (1) {
	for (p = buf; (i = getc(f)) != EOF && (*p = (char) i) > ' '; ++p);
	if (p != buf) {
	    *p++ = 0;
	    if (verbose)
		printf("profile: %s\n", buf);
	    set_option(buf);
	} else if (i == EOF)
	    return;
    }
}

static char *param_start;

#ifdef ANSIC
static int 
eqin(register char *s1, register char *s2)
#else
eqin(s1, s2)
    register char *s1;
    register char *s2;

#endif
{
    while (*s1) {
	if (*s1++ != *s2++)
	    return (false);
    }
    param_start = s2;
    return (true);
}

/*
 * Set the defaults.
 */
#ifdef ANSIC
void 
set_defaults(void)
#else
set_defaults()
#endif
{
    register struct pro *p;

    /*
     * Because ps.case_indent and ps.case_code_indent are floats, we can't
     * initialize them from the table:
     */
    ps.case_indent = (float) 0;		/* -cli0.0 */
    ps.case_code_indent = (float) 1;	/* -cci1.0 */
    for (p = pro; p->p_name != NULL; p++)
	if (p->p_type != PRO_SPECIAL && p->p_type != PRO_FONT)
	    *p->p_obj = p->p_default;
}

#ifdef ANSIC
void 
set_option(register char *arg)
#else
set_option(arg)
    register char *arg;

#endif
{
    register struct pro *p;

#ifndef ANSIC
    extern double atof();

#endif
    arg++;				/* ignore leading "-" */
    for (p = pro; p->p_name; p++)
	if (*p->p_name == *arg && eqin(p->p_name, arg))
	    goto found;
    fprintf(stderr, "indent: unknown parameter \"%s\"\n", arg - 1);
    exit(1);
found:
    switch (p->p_type) {

    case PRO_SPECIAL:
	switch (p->p_special) {

	case IGN:
	    break;

	case CLI:
	    if (*param_start == 0)
		goto need_param;
	    ps.case_indent = (float) atof(param_start);
	    break;

	case CCI:
	    if (*param_start == 0)
		goto need_param;
	    ps.case_code_indent = (float) atof(param_start);
	    break;

	case STDIN:
	    if (input == NULL)
		input = stdin;
	    if (output == NULL)
		output = stdout;
	    break;

	case KEY:
	    if (*param_start == 0)
		goto need_param;
	    {
		register char *str = (char *) malloc(strlen(param_start) + 1);

		strcpy(str, param_start);
		addkey(str, 4);
	    }
	    break;

	default:
	    fprintf(stderr,
		"indent: set_option: internal error: p_special %d\n",
		p->p_special);
	    exit(1);
	}
	break;

    case PRO_BOOL:
	if (p->p_special == OFF)
	    *p->p_obj = false;
	else
	    *p->p_obj = true;
	break;

    case PRO_INT:
	if (*param_start == 0) {
    need_param:
	    fprintf(stderr, "indent: ``%s'' requires a parameter\n",
		arg - 1);
	    exit(1);
	}
	*p->p_obj = atoi(param_start);
	break;

    case PRO_FONT:
	parsefont((struct fstate *) p->p_obj, param_start);
	break;

    default:
	fprintf(stderr, "indent: set_option: internal error: p_type %d\n",
	    p->p_type);
	exit(1);
    }
}
