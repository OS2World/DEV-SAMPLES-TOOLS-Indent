/*------------------------------------------------------------------------------

    proto.h

    Function prototypes.  Only used if ANSIC is defined.

------------------------------------------------------------------------------*/

void set_profile(void);
void set_defaults(void);
void set_option(register char *);
void parsefont(register struct fstate *, char *);
void writefdef(struct fstate *, int);
void fill_buffer(void);
void parse(int);
void dump_line(void);
int lexi(void);
void diag(int, char *,...);
char *chfont(struct fstate *, struct fstate *, char *);
void pr_comment(void);
int compute_label_target(void);
int compute_code_target(void);
int count_spaces(int, char *);
void addkey(char *, int);
