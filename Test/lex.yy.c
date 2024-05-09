#define YY_CHAR char
#line 1 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.cc"
/* A lexical scanner generated by flex */
/* scanner skeleton version:
 * $Header: c:\\Program\040Files\\Development\\CVS\040Repository/flex++/flexskel.cc,v 1.1.1.1 2002/04/13 06:01:32 Bear Exp $
 */
/* MODIFIED FOR C++ CLASS BY Alain Coetmeur: coetmeur(at)icdc.fr */
/* Note that (at) mean the 'at' symbol that I cannot write */
/* because it is expanded to the class name */
/* made at Informatique-CDC, Research&development department */
/* company from the Caisse Des Depots et Consignations */
/* institutional financial group  */

/* theses symbols are added before this file */
/* #define YY_CHAR 'unsigned char' if 8bit or 'char' if 7bit */
/* #define FLEX_DEBUG if debug mode */
#define FLEX_SCANNER
/* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
/* Old MSC, before c7 */
#ifdef MSDOS
#ifndef _MSDOS
#define _MSDOS
#endif
#endif
/* turboc */
#ifdef __MSDOS__
#ifndef _MSDOS
#define _MSDOS
#endif
#endif

#ifdef __cplusplus
#include <stdlib.h>
#define YY_USE_CONST
#define YY_USE_PROTOS
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#ifndef _MSDOS
#include <osfcn.h>
#endif
#else   /* ! __cplusplus */
#ifdef __STDC__
#ifdef __GNUC__
#include <stddef.h>
void *malloc( size_t );
void free( void* );
int read();
#else
#include <stdlib.h>
#endif  /* __GNUC__ */
#define YY_USE_PROTOS
#define YY_USE_CONST
#endif  /* __STDC__ */
#endif  /* ! __cplusplus */
#ifdef __TURBOC__
#define YY_USE_CONST
#endif
#include <stdio.h>


/*********************************************/
/* COMPILER DEPENDENT   MACROS               */
/*********************************************/
/* use prototypes in function declarations */
/* the "const" storage-class-modifier is valid */
#ifndef YY_USE_CONST
#define const
#endif
/* use prototypes in function declarations */
#ifndef YY_PROTO
#ifdef YY_USE_PROTOS
#define YY_PROTO(proto) proto
#else
#define YY_PROTO(proto) ()
#endif
#endif


/*********************/
/* parameters        */

/* amount of stuff to slurp up with each read */
#ifndef YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#endif
/* size of default input buffer */
#ifndef YY_BUF_SIZE
#define YY_BUF_SIZE (YY_READ_BUF_SIZE * 2) 
#endif

/***********************************/
/* to be redefined for application */

/* returned upon end-of-file */
#define YY_END_TOK 0
/* no semi-colon after return; correct usage is to write "yyterminate();" -
 * we don't want an extra ';' after the "return" because that will cause
 * some compilers to complain about unreachable statements.
 */
#define yyterminate() return ( YY_NULL )

/* code executed at the end of each rule */
#define YY_BREAK break;

/* #define YY_USER_ACTION */
/* #define YY_USER_INIT */


#ifndef YY_USE_CLASS
/* copy whatever the last rule matched to the standard output */
/* cast to (char *) is because for 8-bit chars, yy___text is (unsigned char *) */
/* this used to be an fputs(), but since the string might contain NUL's,
 * we now use fwrite()
 */
#define ECHO (void) fwrite( (char *) yy___text, yy___leng, 1, yy___out )

/* gets input and stuffs it into "buf".  number of characters read, or YY_NULL,
 * is returned in "result".
 */
#ifdef _MSDOS
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread(buf,1,max_size,yy___in)) < 0 ) \
	    YY_FATAL_ERROR( "fread() in flex scanner failed" );
#else
#define YY_INPUT(buf,result,max_size) \
	if ( (result = read( fileno(yy___in), (char *) buf, max_size )) < 0 ) \
	    YY_FATAL_ERROR( "read() in flex scanner failed" );

#endif
/* report a fatal error */

/* The funky do-while is used to turn this macro definition into
 * a single C statement (which needs a semi-colon terminator).
 * This avoids problems with code like:
 *
 *      if ( something_happens )
 *              YY_FATAL_ERROR( "oops, the something happened" );
 *      else
 *              everything_okay();
 *
 * Prior to using the do-while the compiler would get upset at the
 * "else" because it interpreted the "if" statement as being all
 * done when it reached the ';' after the YY_FATAL_ERROR() call.
 */

#define YY_FATAL_ERROR(msg) \
	do \
		{ \
		(void) fputs( msg, yy___stderr  ); \
		(void) putc( '\n', yy___stderr  ); \
		exit( 1 ); \
		} \
	while ( 0 )

/* default yywrap function - always treat EOF as an EOF */
#define yywrap() 1


/* default declaration of generated scanner - a define so the user can
 * easily add parameters
 */
#define YY_DECL int yylex YY_PROTO(( void )) 
#else 
/* c++ */
#define ECHO yy___echo()
#define YY_INPUT(buf,result,max_size) \
	if ( yy___input((char *)buf, result,max_size) < 0 ) \
	    YY_FATAL_ERROR( "YY_INPUT() in flex scanner failed" );

#define YY_FATAL_ERROR(msg) yy___fatal_error(msg)
#define yywrap() yy___wrap()

#endif
/***********************************/
/* not to be changed */
#define YY_NULL 0
#define YY_END_OF_BUFFER_CHAR 0
/* special action meaning "start processing a new file" */
#define YY_NEW_FILE yy___newfile 
/* enter a start condition.  This macro really ought to take a parameter,
 * but we do it the disgusting crufty way forced on us by the ()-less
 * definition of BEGIN
 */
#define BEGIN yy_start = 1 + 2 *

/* action number for EOF rule of a given start state */
#define YY_STATE_EOF(state) (YY_END_OF_BUFFER + state + 1)



/* % section 1 definitions go here */ 
#line 1 "test.l"
#define INITIAL 0
#line 2 "test.l"
int line=1;
#define YY_lex_FLEX_SCANNER
#define YY_lex_CHAR char
#line 1 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.h"
/* A lexical scanner header generated by flex */
/* MODIFIED FOR C++ CLASS BY Alain Coetmeur: coetmeur(at)icdc.fr */
/* Note that (at) mean the 'at' symbol that I cannot write */
/* because it is expanded to the class name */
/* made at Informatique-CDC, Research&development department */
/* company from the Caisse Des Depots et Consignations */


/*********************************************/
/* SYSTEM dependent declaration, includes... */
/*********************************************/
/* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_PROTOS
#define YY_USE_PROTOS
#endif
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else	/* ! __cplusplus */
#ifdef __STDC__
#ifdef __GNUC__
#else
#endif	/* __GNUC__ */
#ifndef YY_USE_PROTOS
#define YY_USE_PROTOS
#endif
#endif	/* __STDC__ */
#endif	/* ! __cplusplus */
/*********************************************/
/* COMPILER DEPENDENT   MACROS               */
/*********************************************/
/* use prototypes in function declarations */
#ifndef YY_PROTO
#ifdef YY_USE_PROTOS
#define YY_PROTO(proto) proto
#else
#define YY_PROTO(proto) ()
#endif
#endif
#include <stdio.h>




/* % here is the declaration from section1 %header{  */ 
#line 5 "test.l"
#line 5 "test.l"
#line 8 "test.l"
#line 52 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.h"

#ifdef YY_USE_CLASS
#ifdef YY_lex_IOSTREAM
#include <iostream.h>
#define YY_lex_IFILE  istream
#define YY_lex_OFILE ostream 
#define YY_lex_ERRFILE cerr

#ifndef YY_lex_IFILE_DEFAULT
#define YY_lex_IFILE_DEFAULT &cin
#endif

#ifndef YY_lex_OFILE_DEFAULT
#define YY_lex_OFILE_DEFAULT &cout
#endif

#endif
#endif

#ifndef YY_lex_IFILE
#define YY_lex_IFILE FILE 
#endif

#ifndef YY_lex_OFILE
#define YY_lex_OFILE FILE 
#endif

#ifndef YY_lex_ERRFILE
#define YY_lex_ERRFILE stderr
#endif

#ifndef YY_lex_IFILE_DEFAULT
#define YY_lex_IFILE_DEFAULT stdin
#endif

#ifndef YY_lex_OFILE_DEFAULT
#define YY_lex_OFILE_DEFAULT stdout
#endif




#ifndef YY_lex_TEXT
#define YY_lex_TEXT yytext
#endif
#ifndef YY_lex_LENG
#define YY_lex_LENG yyleng
#endif
#ifndef YY_lex_IN
#define YY_lex_IN yyin
#endif
#ifndef YY_lex_OUT
#define YY_lex_OUT yyout
#endif

#ifndef YY_lex_LEX_RETURN
#define YY_lex_LEX_RETURN int
#else
#ifndef YY_lex_LEX_DEFINED
#define YY_lex_LEX_DEFINED 
#endif
#endif

#ifndef YY_lex_LEX
#define YY_lex_LEX yylex
#else
#ifndef YY_lex_LEX_DEFINED
#define YY_lex_LEX_DEFINED 
#endif
#endif

#ifndef YY_lex_LEX_PARAM
#ifndef YY_USE_PROTOS
#define YY_lex_LEX_PARAM 
#else
#define YY_lex_LEX_PARAM void
#endif
#else
#ifndef YY_lex_LEX_DEFINED
#define YY_lex_LEX_DEFINED 
#endif
#endif

#ifndef YY_lex_LEX_PARAM_DEF
#define YY_lex_LEX_PARAM_DEF
#else
#ifndef YY_lex_LEX_DEFINED
#define YY_lex_LEX_DEFINED 
#endif
#endif

#ifndef YY_lex_RESTART
#define YY_lex_RESTART yyrestart
#endif
#ifndef YY_lex_SWITCH_TO_BUFFER
#define YY_lex_SWITCH_TO_BUFFER yy_switch_to_buffer
#endif
#ifndef YY_lex_LOAD_BUFFER_STATE
#define YY_lex_LOAD_BUFFER_STATE yy_load_buffer_state
#endif

#ifndef YY_lex_CREATE_BUFFER
#define YY_lex_CREATE_BUFFER yy_create_buffer
#ifndef YY_USE_CLASS
#ifndef yy_new_buffer
#define yy_new_buffer yy_create_buffer
#endif
#endif
#endif
#ifndef YY_lex_DELETE_BUFFER
#define YY_lex_DELETE_BUFFER yy_delete_buffer
#endif
#ifndef YY_lex_INIT_BUFFER
#define YY_lex_INIT_BUFFER yy_init_buffer
#endif



#ifdef YY_lex_FLEX_DEBUG
#ifndef YY_lex_DEBUG
#define YY_lex_DEBUG 1
#endif
#else
#ifndef YY_lex_DEBUG
#define YY_lex_DEBUG 0
#endif
#endif

#if YY_lex_DEBUG != 0
#ifndef YY_lex_DEBUG_FLAG
#define YY_lex_DEBUG_FLAG yy_flex_debug
#endif
#ifndef YY_lex_DEBUG_INIT
#define YY_lex_DEBUG_INIT 1
#endif
#endif




#ifndef YY_USE_CLASS
#ifndef YY_lex_CURRENT_BUFFER
#define YY_lex_CURRENT_BUFFER yy_current_buffer
#endif
typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern void YY_lex_RESTART YY_PROTO(( YY_lex_IFILE *input_file ));
extern void YY_lex_SWITCH_TO_BUFFER YY_PROTO(( YY_BUFFER_STATE new_buffer ));
extern void YY_lex_LOAD_BUFFER_STATE YY_PROTO(( void ));
extern YY_BUFFER_STATE YY_lex_CREATE_BUFFER YY_PROTO(( YY_lex_IFILE *file, int size ));
extern void YY_lex_DELETE_BUFFER YY_PROTO(( YY_BUFFER_STATE b ));
extern void YY_lex_INIT_BUFFER YY_PROTO(( YY_BUFFER_STATE b, YY_lex_IFILE *file ));

#if YY_lex_DEBUG != 0
extern int YY_lex_DEBUG_FLAG ;
#endif
extern YY_lex_CHAR  *YY_lex_TEXT;
extern int YY_lex_LENG;
extern YY_lex_IFILE *YY_lex_IN;
extern YY_lex_OFILE *YY_lex_OUT;
#ifdef YY_lex_LEX_DEFINED
extern YY_lex_LEX_RETURN YY_lex_LEX ( YY_lex_LEX_PARAM )
YY_lex_LEX_PARAM_DEF
#else
#ifndef YY_DECL
extern YY_lex_LEX_RETURN YY_lex_LEX ( YY_lex_LEX_PARAM )
YY_lex_LEX_PARAM_DEF
#else
/* no declaration if oldstyle flex */
#endif
#endif
#else

#ifndef YY_lex_CURRENT_BUFFER
#define YY_lex_CURRENT_BUFFER YY_CURRENT_BUFFER
#endif
#ifndef YY_lex_CLASS
#define YY_lex_CLASS lex
#endif
#ifndef YY_lex_ECHO
#define YY_lex_ECHO yy_echo
#endif
#ifdef YY_lex_ECHO_PURE
#define YY_lex_ECHO_NOCODE
#endif

#ifndef YY_lex_ECHO_CODE
#ifndef YY_lex_IOSTREAM
#define YY_lex_ECHO_CODE fwrite( (char *) YY_lex_TEXT, YY_lex_LENG, 1, YY_lex_OUT );
#else
#define YY_lex_ECHO_CODE (YY_lex_OUT->write( (char *) YY_lex_TEXT, YY_lex_LENG));
#endif
#endif

#ifndef YY_lex_INPUT
#define YY_lex_INPUT yy_input
#endif
#ifdef YY_lex_INPUT_PURE
#define YY_lex_INPUT_NOCODE
#endif

#ifndef YY_lex_INPUT_CODE
#ifndef YY_lex_IOSTREAM
#define YY_lex_INPUT_CODE return result= fread(  buffer, 1,max_size,YY_lex_IN );
#else
#define YY_lex_INPUT_CODE if(YY_lex_IN->eof())  result=0;else {YY_lex_IN->read(buffer,max_size);result=YY_lex_IN->gcount();YY_lex_IN->clear(YY_lex_IN->rdstate()&(~ios::failbit));if(YY_lex_IN->bad()) result= -1;} return result;
#endif
#endif

#ifdef YY_lex_FATAL_ERROR_PURE
#define YY_lex_FATAL_ERRO_NOCODE
#endif
#ifndef YY_lex_FATAL_ERROR
#define YY_lex_FATAL_ERROR yy_fatal_error
#endif

#ifndef YY_lex_FATAL_ERROR_CODE
#ifndef YY_lex_IOSTREAM
#define YY_lex_FATAL_ERROR_CODE fputs( msg, YY_lex_ERRFILE );putc( '\n', YY_lex_ERRFILE );exit( 1 );
#else
#define YY_lex_FATAL_ERROR_CODE YY_lex_ERRFILE<< msg <<endl;exit( 1 );
#endif
#endif

#ifndef YY_lex_WRAP
#define YY_lex_WRAP yy_wrap
#endif
#ifdef YY_lex_WRAP_PURE
#define YY_lex_WRAP_NOCODE
#endif
#ifndef YY_lex_WRAP_CODE
#define YY_lex_WRAP_CODE return 1;
#endif


#ifndef YY_lex_INHERIT
#define YY_lex_INHERIT
#endif
#ifndef YY_lex_MEMBERS
#define YY_lex_MEMBERS 
#endif
#ifndef YY_lex_CONSTRUCTOR_PARAM
#define YY_lex_CONSTRUCTOR_PARAM
#endif
#ifndef YY_lex_CONSTRUCTOR_CODE
#define YY_lex_CONSTRUCTOR_CODE
#endif
#ifndef YY_lex_CONSTRUCTOR_INIT
#define YY_lex_CONSTRUCTOR_INIT
#endif
#ifndef YY_lex_DESTRUCTOR_CODE
#define YY_lex_DESTRUCTOR_CODE
#endif
typedef struct yy_buffer_state *YY_BUFFER_STATE;

class YY_lex_CLASS YY_lex_INHERIT
{
 private:/* data */
 YY_lex_CHAR  *yy_c_buf_p;
 YY_lex_CHAR  yy_hold_char;
 int yy_n_chars;
 int yy_init;
 int yy_start;
 int yy_did_buffer_switch_on_eof;
 private: /* functions */
 void yy_initialize();
 int input();
 int yyinput() {return input();};
 int yy_get_next_buffer();
 void yyunput( YY_lex_CHAR  c, YY_lex_CHAR  *buf_ptr );
 /* use long instead of yy_state_type because it is undef */
 long yy_get_previous_state_ ( void );
 long yy_try_NUL_trans_  ( long current_state_ );
 protected:/* non virtual */
 YY_BUFFER_STATE YY_lex_CURRENT_BUFFER;
 void YY_lex_RESTART ( YY_lex_IFILE *input_file );
 void YY_lex_SWITCH_TO_BUFFER( YY_BUFFER_STATE new_buffer );
 void YY_lex_LOAD_BUFFER_STATE( void );
 YY_BUFFER_STATE YY_lex_CREATE_BUFFER( YY_lex_IFILE *file, int size );
 void YY_lex_DELETE_BUFFER( YY_BUFFER_STATE b );
 void YY_lex_INIT_BUFFER( YY_BUFFER_STATE b, YY_lex_IFILE *file );
 protected: /* virtual */
 virtual void YY_lex_ECHO()
#ifdef YY_lex_ECHO_PURE
  =0
#endif
  ;
 virtual int  YY_lex_INPUT(char  *buf,int &result,int max_size)
#ifdef YY_lex_INPUT_PURE
  =0
#endif
  ;
 virtual void  YY_lex_FATAL_ERROR(char *msg)
#ifdef YY_lex_FATAL_ERROR_PURE
  =0
#endif
  ;
 virtual int  YY_lex_WRAP()
#ifdef YY_lex_WRAP_PURE
  =0
#endif
  ;
 public:
 YY_lex_CHAR  *YY_lex_TEXT;
 int YY_lex_LENG;
 YY_lex_IFILE *YY_lex_IN;
 YY_lex_OFILE *YY_lex_OUT;
 YY_lex_LEX_RETURN YY_lex_LEX ( YY_lex_LEX_PARAM);
 YY_lex_CLASS(YY_lex_CONSTRUCTOR_PARAM) ;
 virtual ~YY_lex_CLASS() ;
#if YY_lex_DEBUG != 0
 int YY_lex_DEBUG_FLAG;
#endif
 public: /* added members */
 YY_lex_MEMBERS 
};
#endif



/* declaration of externs for public use of yylex scanner */

/* % here is the declaration from section2 %header{ */ 
#line 196 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.cc"

#define yy___stderr YY_lex_ERRFILE
#define yy___text YY_lex_TEXT
#define yy___leng YY_lex_LENG
#define yy___in YY_lex_IN
#define yy___out YY_lex_OUT
#define yy___newfile \
	do \
		{ \
		YY_lex_INIT_BUFFER( YY_lex_CURRENT_BUFFER, yy___in ); \
		YY_lex_LOAD_BUFFER_STATE(); \
		} \
	while ( 0 )
#if YY_lex_DEBUG != 0
#define yy___flex_debug YY_lex_DEBUG_FLAG
#endif


#ifdef YY_USE_CLASS

#define yy___echo YY_lex_ECHO
#define yy___input YY_lex_INPUT
#define yy___fatal_error YY_lex_FATAL_ERROR
#define yy___wrap YY_lex_WRAP

#endif

/* done after the current pattern has been matched and before the
 * corresponding action - sets up yy___text
 */
#define YY_DO_BEFORE_ACTION \
	yy___text = yy_bp; \
/* % code to fiddle yy___text and yy___leng for yymore() goes here */ \
	yy___leng = yy_cp - yy_bp; \
	yy_hold_char = *yy_cp; \
	*yy_cp = '\0'; \
	yy_c_buf_p = yy_cp;

#define EOB_ACT_CONTINUE_SCAN 0
#define EOB_ACT_END_OF_FILE 1
#define EOB_ACT_LAST_MATCH 2

/* return all but the first 'n' matched characters back to the input stream */
#define yyless(n) \
	do \
		{ \
		/* undo effects of setting up yy___text */ \
		*yy_cp = yy_hold_char; \
		yy_c_buf_p = yy_cp = yy_bp + n; \
		YY_DO_BEFORE_ACTION; /* set up yy___text again */ \
		} \
	while ( 0 )

#define unput(c) yyunput( c, yy___text )



struct yy_buffer_state
    {
    YY_lex_IFILE  *yy_input_file;

    YY_lex_CHAR *yy_ch_buf;               /* input buffer */
    YY_lex_CHAR *yy_buf_pos;      /* current position in input buffer */

    /* size of input buffer in bytes, not including room for EOB characters */
    int yy_buf_size;    

    /* number of characters read into yy_ch_buf, not including EOB characters */
    int yy_n_chars;

    int yy_eof_status;          /* whether we've seen an EOF on this buffer */
#define EOF_NOT_SEEN 0
    /* "pending" happens when the EOF has been seen but there's still
     * some text process
     */
#define EOF_PENDING 1
#define EOF_DONE 2
    };

/* we provide macros for accessing buffer states in case in the
 * future we want to put the buffer states in a more general
 * "scanner state"
 */

#ifndef YY_USE_CLASS

#if YY_lex_DEBUG != 0
int YY_lex_DEBUG_FLAG=YY_lex_DEBUG_INIT;
#endif
#define YY_CURRENT_BUFFER YY_lex_CURRENT_BUFFER
static YY_BUFFER_STATE YY_lex_CURRENT_BUFFER;
/* yy_hold_char holds the character lost when yy___text is formed */
static YY_lex_CHAR yy_hold_char;

static int yy_n_chars;          /* number of characters read into yy_ch_buf */

/* GLOBAL */
YY_lex_CHAR *yy___text;
int yy___leng;

YY_lex_IFILE  *yy___in = (YY_lex_IFILE  *) 0;
YY_lex_OFILE *yy___out = (YY_lex_OFILE  *) 0;

#ifdef __cplusplus
static int yyinput YY_PROTO(( void ));
#else
static int input YY_PROTO(( void ));
#endif
/* these variables are all declared out here so that section 3 code can
 * manipulate them
 */
/* points to current character in buffer */
static YY_lex_CHAR *yy_c_buf_p = (YY_lex_CHAR *) 0;
static int yy_init = 1;         /* whether we need to initialize */
static int yy_start = 0;        /* start state number */

/* flag which is used to allow yywrap()'s to do buffer switches
 * instead of setting up a fresh yy___in.  A bit of a hack ...
 */
static int yy_did_buffer_switch_on_eof;

static int yy_get_next_buffer YY_PROTO(( void ));
static void yyunput YY_PROTO(( YY_lex_CHAR c, YY_lex_CHAR *buf_ptr ));

#else
/* c++ */
#ifndef YY_lex_ECHO_NOCODE
void YY_lex_CLASS::yy___echo()
{YY_lex_ECHO_CODE
}
#endif
#ifndef YY_lex_INPUT_NOCODE
int  YY_lex_CLASS::yy___input(char * buffer,int &result,int max_size)
{YY_lex_INPUT_CODE
}
#endif
#ifndef YY_lex_FATAL_ERROR_NOCODE
void YY_lex_CLASS::yy___fatal_error(char *msg)
{YY_lex_FATAL_ERROR_CODE
}
#endif
#ifndef YY_lex_WRAP_NOCODE
int  YY_lex_CLASS::yy___wrap()
{YY_lex_WRAP_CODE
}
#endif
void YY_lex_CLASS::yy_initialize()
{
 yy___in=0;yy___out=0;yy_init = 1;
 yy_start=0;
 yy___text=0;yy___leng=0;
 YY_lex_CURRENT_BUFFER=0;
 yy_did_buffer_switch_on_eof=0;
 yy_c_buf_p=0;yy_hold_char=0;yy_n_chars=0;
#if YY_lex_DEBUG != 0
 YY_lex_DEBUG_FLAG=YY_lex_DEBUG_INIT;
#endif
}

YY_lex_CLASS::YY_lex_CLASS(YY_lex_CONSTRUCTOR_PARAM) YY_lex_CONSTRUCTOR_INIT
{yy_initialize();
 YY_lex_CONSTRUCTOR_CODE;
}
YY_lex_CLASS::~YY_lex_CLASS() 
{YY_lex_DESTRUCTOR_CODE;
 if(YY_lex_CURRENT_BUFFER)
  YY_lex_DELETE_BUFFER(YY_lex_CURRENT_BUFFER);
}

#endif


#ifndef YY_USER_ACTION
#define YY_USER_ACTION
#endif

#ifndef YY_USER_INIT
#define YY_USER_INIT
#endif

/* % data tables for the DFA go here */ 
#define YY_END_OF_BUFFER 4
typedef int yy_state_type;
static const short int yy_accept[7] =
    {   0,
        0,    0,    4,    2,    1,    0
    } ;

static const YY_CHAR yy_ec[128] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    2,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,

        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1
    } ;

static const YY_CHAR yy_meta[3] =
    {   0,
        1,    1
    } ;

static const short int yy_base[7] =
    {   0,
        0,    0,    3,    4,    4,    4
    } ;

static const short int yy_def[7] =
    {   0,
        6,    1,    6,    6,    6,    0
    } ;

static const short int yy_nxt[7] =
    {   0,
        4,    5,    6,    3,    6,    6
    } ;

static const short int yy_chk[7] =
    {   0,
        1,    1,    3,    6,    6,    6
    } ;

static yy_state_type yy_last_accepting_state;
static YY_CHAR *yy_last_accepting_cpos;

#if YY_lex_DEBUG != 0
static const short int yy_rule_linenum[3] =
    {   0,
        6,    7
    } ;

#endif
/* the intent behind this definition is that it'll catch
 * any uses of REJECT which flex missed
 */
#define REJECT reject_used_but_not_detected
#define yymore() yymore_used_but_not_detected
#define YY_MORE_ADJ 0
#line 376 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.cc"
#ifndef YY_USE_CLASS
static yy_state_type yy_get_previous_state YY_PROTO(( void ));
static yy_state_type yy_try_NUL_trans YY_PROTO(( yy_state_type current_state ));
#else
#define yy_get_previous_state() ((yy_state_type)(yy_get_previous_state_()))
#define yy_try_NUL_trans(c) ((yy_state_type)(yy_try_NUL_trans_(c)))
#endif

#ifndef YY_USE_CLASS
#ifdef YY_lex_LEX_DEFINED
YY_lex_LEX_RETURN YY_lex_LEX ( YY_lex_LEX_PARAM )
YY_lex_LEX_PARAM_DEF
#else
YY_DECL
#endif
#else
YY_lex_LEX_RETURN YY_lex_CLASS::YY_lex_LEX ( YY_lex_LEX_PARAM)

#endif
    {
    register yy_state_type yy_current_state;
    register YY_lex_CHAR *yy_cp, *yy_bp;
    register int yy_act;

/* % user's declarations go here */ 

/* % end of prolog */ 
#line 401 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.cc"

    if ( yy_init )
	{
	 
	 {
	 YY_USER_INIT;
	 }
	if ( ! yy_start )
	    yy_start = 1;       /* first start state */

	if ( ! yy___in )
	    yy___in = YY_lex_IFILE_DEFAULT;

	if ( ! yy___out )
	    yy___out = YY_lex_OFILE_DEFAULT;

	if ( YY_lex_CURRENT_BUFFER )
	    YY_lex_INIT_BUFFER( YY_lex_CURRENT_BUFFER, yy___in );
	else
	    YY_lex_CURRENT_BUFFER = YY_lex_CREATE_BUFFER( yy___in, YY_BUF_SIZE );

	YY_lex_LOAD_BUFFER_STATE();
	yy_init=0;
	}

    while ( 1 )         /* loops until end-of-file is reached */
	{
/* % yymore()-related code goes here */ 
#line 429 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.cc"
	yy_cp = yy_c_buf_p;

	/* support of yy___text */
	*yy_cp = yy_hold_char;

	/* yy_bp points to the position in yy_ch_buf of the start of the
	 * current run.
	 */
	yy_bp = yy_cp;

/* % code to set up and find next match goes here */ 
	yy_current_state = yy_start;
yy_match:
	do
	    {
	    register YY_CHAR yy_c = yy_ec[*yy_cp];
	    if ( yy_accept[yy_current_state] )
		{
		yy_last_accepting_state = yy_current_state;
		yy_last_accepting_cpos = yy_cp;
		}
	    while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
		{
		yy_current_state = yy_def[yy_current_state];
		if ( yy_current_state >= 7 )
		    yy_c = yy_meta[yy_c];
		}
	    yy_current_state = yy_nxt[yy_base[yy_current_state] + yy_c];
	    ++yy_cp;
	    }
	while ( yy_current_state != 6 );
	yy_cp = yy_last_accepting_cpos;
	yy_current_state = yy_last_accepting_state;
#line 440 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.cc"

yy_find_action:
/* % code to find the action number goes here */ 
	yy_act = yy_accept[yy_current_state];
#line 443 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.cc"

	YY_DO_BEFORE_ACTION;
	YY_USER_ACTION;

do_action:      /* this label is used only to access EOF actions */
#if YY_lex_DEBUG != 0
	if ( yy___flex_debug )
		{
		if ( yy_act == 0 )
#ifndef YY_lex_IOSTREAM
			fprintf( yy___stderr , "--scanner backtracking\n" );
#else
			yy___stderr <<"--scanner backtracking"<<endl;
#endif
		else if ( yy_act < YY_END_OF_BUFFER -1 )
#ifndef YY_lex_IOSTREAM
			fprintf( yy___stderr , 
			 "--accepting rule at line %d (\"%s\")\n",
			 yy_rule_linenum[yy_act], yy___text );
#else
			yy___stderr <<"--accepting rule at line "
                          <<(int)yy_rule_linenum[yy_act]
                          <<" (\""<<(char *)yy___text<<"\")"<<endl;
#endif
		else if ( yy_act == YY_END_OF_BUFFER -1 )
#ifndef YY_lex_IOSTREAM
			fprintf( yy___stderr , 
			 "--accepting default rule (\"%s\")\n",
			 yy___text );
#else
			yy___stderr <<"--accepting default rule"
                          <<" (\""<<(char *)yy___text<<"\")"<<endl;
#endif
		else if ( yy_act == YY_END_OF_BUFFER )
#ifndef YY_lex_IOSTREAM
			fprintf( yy___stderr , "--(end of buffer or a NUL)\n" );
#else
			yy___stderr <<"--(end of buffer or a NUL)"<<endl;
#endif
		else
#ifndef YY_lex_IOSTREAM
			fprintf( yy___stderr , "--EOF\n" );
#else
			yy___stderr <<"--EOF"<<endl;
#endif
		}
#endif
	switch ( yy_act )
	    {
/* % actions go here */ 
	    case 0: /* must backtrack */
	    /* undo the effects of YY_DO_BEFORE_ACTION */
	    *yy_cp = yy_hold_char;
	    yy_cp = yy_last_accepting_cpos;
	    yy_current_state = yy_last_accepting_state;
	    goto yy_find_action;

case 1:
#line 6 "test.l"
{line++;  printf("\n%d:",line);}
	YY_BREAK
case 2:
#line 7 "test.l"
ECHO;
	YY_BREAK
case 3:
#line 8 "test.l"
ECHO;
	YY_BREAK
case YY_STATE_EOF(INITIAL):
    yyterminate();
#line 493 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.cc"

	    case YY_END_OF_BUFFER:
		{
		/* amount of text matched not including the EOB char */
		int yy_amount_of_matched_text = yy_cp - yy___text - 1;

		/* undo the effects of YY_DO_BEFORE_ACTION */
		*yy_cp = yy_hold_char;

		/* note that here we test for yy_c_buf_p "<=" to the position
		 * of the first EOB in the buffer, since yy_c_buf_p will
		 * already have been incremented past the NUL character
		 * (since all states make transitions on EOB to the end-
		 * of-buffer state).  Contrast this with the test in yyinput().
		 */
		if ( yy_c_buf_p <= &YY_lex_CURRENT_BUFFER->yy_ch_buf[yy_n_chars] )
		    /* this was really a NUL */
		    {
		    yy_state_type yy_next_state;

		    yy_c_buf_p = yy___text + yy_amount_of_matched_text;

		    yy_current_state = yy_get_previous_state();

		    /* okay, we're now positioned to make the
		     * NUL transition.  We couldn't have
		     * yy_get_previous_state() go ahead and do it
		     * for us because it doesn't know how to deal
		     * with the possibility of jamming (and we
		     * don't want to build jamming into it because
		     * then it will run more slowly)
		     */

		    yy_next_state = yy_try_NUL_trans( yy_current_state );

		    yy_bp = yy___text + YY_MORE_ADJ;

		    if ( yy_next_state )
			{
			/* consume the NUL */
			yy_cp = ++yy_c_buf_p;
			yy_current_state = yy_next_state;
			goto yy_match;
			}

		    else
			{
/* % code to do backtracking for compressed tables and set up yy_cp goes here */ 
			    yy_cp = yy_last_accepting_cpos;
			    yy_current_state = yy_last_accepting_state;
#line 541 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.cc"
			goto yy_find_action;
			}
		    }

		else switch ( yy_get_next_buffer() )
		    {
		    case EOB_ACT_END_OF_FILE:
			{
			yy_did_buffer_switch_on_eof = 0;

			if ( yywrap() )
			    {
			    /* note: because we've taken care in
			     * yy_get_next_buffer() to have set up yy___text,
			     * we can now set up yy_c_buf_p so that if some
			     * total hoser (like flex itself) wants
			     * to call the scanner after we return the
			     * YY_NULL, it'll still work - another YY_NULL
			     * will get returned.
			     */
			    yy_c_buf_p = yy___text + YY_MORE_ADJ;

			    yy_act = YY_STATE_EOF((yy_start - 1) / 2);
			    goto do_action;
			    }

			else
			    {
			    if ( ! yy_did_buffer_switch_on_eof )
				YY_NEW_FILE;
			    }
			}
			break;

		    case EOB_ACT_CONTINUE_SCAN:
			yy_c_buf_p = yy___text + yy_amount_of_matched_text;

			yy_current_state = yy_get_previous_state();

			yy_cp = yy_c_buf_p;
			yy_bp = yy___text + YY_MORE_ADJ;
			goto yy_match;

		    case EOB_ACT_LAST_MATCH:
			yy_c_buf_p =
			    &YY_lex_CURRENT_BUFFER->yy_ch_buf[yy_n_chars];

			yy_current_state = yy_get_previous_state();

			yy_cp = yy_c_buf_p;
			yy_bp = yy___text + YY_MORE_ADJ;
			goto yy_find_action;
		    }
		break;
		}

	    default:
#if YY_lex_DEBUG != 0
#ifndef YY_lex_IOSTREAM
		fprintf(yy___stderr , "action # %d\n", yy_act );
#else
		yy___stderr <<"action # "<<(int)yy_act<<endl;
#endif
#endif
		YY_FATAL_ERROR(
			"fatal flex scanner internal error--no action found" );
	    }
	}
	yyterminate();/* avoid the no return value error message on MS-C7/dos */
    }


/* yy_get_next_buffer - try to read in a new buffer
 *
 * synopsis
 *     int yy_get_next_buffer();
 *     
 * returns a code representing an action
 *     EOB_ACT_LAST_MATCH - 
 *     EOB_ACT_CONTINUE_SCAN - continue scanning from current position
 *     EOB_ACT_END_OF_FILE - end of file
 */
#ifndef YY_USE_CLASS
static int yy_get_next_buffer()
#else
int YY_lex_CLASS::yy_get_next_buffer()
#endif
    {
    register YY_lex_CHAR *dest = YY_lex_CURRENT_BUFFER->yy_ch_buf;
    register YY_lex_CHAR *source = yy___text - 1; /* copy prev. char, too */
    register int number_to_move, i;
    int ret_val;

    if ( yy_c_buf_p > &YY_lex_CURRENT_BUFFER->yy_ch_buf[yy_n_chars + 1] )
	YY_FATAL_ERROR(
		"fatal flex scanner internal error--end of buffer missed" );

    /* try to read more data */

    /* first move last chars to start of buffer */
    number_to_move = yy_c_buf_p - yy___text;

    for ( i = 0; i < number_to_move; ++i )
	*(dest++) = *(source++);

    if ( YY_lex_CURRENT_BUFFER->yy_eof_status != EOF_NOT_SEEN )
	/* don't do the read, it's not guaranteed to return an EOF,
	 * just force an EOF
	 */
	yy_n_chars = 0;

    else
	{
	int num_to_read = YY_lex_CURRENT_BUFFER->yy_buf_size - number_to_move - 1;

	if ( num_to_read > YY_READ_BUF_SIZE )
	    num_to_read = YY_READ_BUF_SIZE;

	else if ( num_to_read <= 0 )
	    YY_FATAL_ERROR( "fatal error - scanner input buffer overflow" );

	/* read in more data */
	YY_INPUT( (&YY_lex_CURRENT_BUFFER->yy_ch_buf[number_to_move]),
		  yy_n_chars, num_to_read );
	}

    if ( yy_n_chars == 0 )
	{
	if ( number_to_move - YY_MORE_ADJ == 1 )
	    {
	    ret_val = EOB_ACT_END_OF_FILE;
	    YY_lex_CURRENT_BUFFER->yy_eof_status = EOF_DONE;
	    }

	else
	    {
	    ret_val = EOB_ACT_LAST_MATCH;
	    YY_lex_CURRENT_BUFFER->yy_eof_status = EOF_PENDING;
	    }
	}

    else
	ret_val = EOB_ACT_CONTINUE_SCAN;

    yy_n_chars += number_to_move;
    YY_lex_CURRENT_BUFFER->yy_ch_buf[yy_n_chars] = YY_END_OF_BUFFER_CHAR;
    YY_lex_CURRENT_BUFFER->yy_ch_buf[yy_n_chars + 1] = YY_END_OF_BUFFER_CHAR;

    /* yy___text begins at the second character in yy_ch_buf; the first
     * character is the one which preceded it before reading in the latest
     * buffer; it needs to be kept around in case it's a newline, so
     * yy_get_previous_state() will have with '^' rules active
     */

    yy___text = &YY_lex_CURRENT_BUFFER->yy_ch_buf[1];

    return ( ret_val );
    }


/* yy_get_previous_state - get the state just before the EOB char was reached
 *
 * synopsis
 *     yy_state_type yy_get_previous_state();
 */

#ifndef YY_USE_CLASS
static yy_state_type yy_get_previous_state()
#else
long YY_lex_CLASS::yy_get_previous_state_()
#endif
    {
    register yy_state_type yy_current_state;
    register YY_lex_CHAR *yy_cp;

/* % code to get the start state into yy_current_state goes here */ 
    yy_current_state = yy_start;
#line 717 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.cc"

    for ( yy_cp = yy___text + YY_MORE_ADJ; yy_cp < yy_c_buf_p; ++yy_cp )
	{
/* % code to find the next state goes here */ 
	register YY_CHAR yy_c = (*yy_cp ? yy_ec[*yy_cp] : 1);
	if ( yy_accept[yy_current_state] )
	    {
	    yy_last_accepting_state = yy_current_state;
	    yy_last_accepting_cpos = yy_cp;
	    }
	while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
	    {
	    yy_current_state = yy_def[yy_current_state];
	    if ( yy_current_state >= 7 )
		yy_c = yy_meta[yy_c];
	    }
	yy_current_state = yy_nxt[yy_base[yy_current_state] + yy_c];
#line 721 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.cc"
	}

#ifndef YY_USE_CLASS
    return ( yy_current_state );
#else
    return (long)( yy_current_state );
#endif
    }


/* yy_try_NUL_trans - try to make a transition on the NUL character
 *
 * synopsis
 *     next_state = yy_try_NUL_trans( current_state );
 */

#ifndef YY_USE_CLASS
#ifdef YY_USE_PROTOS
static yy_state_type yy_try_NUL_trans( register yy_state_type yy_current_state )
#else
static yy_state_type yy_try_NUL_trans( yy_current_state )
register yy_state_type yy_current_state;
#endif
#else
long YY_lex_CLASS::yy_try_NUL_trans_(long yy_current_state_)
#endif

    {
#ifndef YY_USE_CLASS
#else
    yy_state_type yy_current_state=(yy_state_type)yy_current_state_;
#endif
    register int yy_is_jam;
/* % code to find the next state, and perhaps do backtracking, goes here */ 
    register YY_CHAR *yy_cp = yy_c_buf_p;

    register YY_CHAR yy_c = 1;
    if ( yy_accept[yy_current_state] )
	{
	yy_last_accepting_state = yy_current_state;
	yy_last_accepting_cpos = yy_cp;
	}
    while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
	{
	yy_current_state = yy_def[yy_current_state];
	if ( yy_current_state >= 7 )
	    yy_c = yy_meta[yy_c];
	}
    yy_current_state = yy_nxt[yy_base[yy_current_state] + yy_c];
    yy_is_jam = (yy_current_state == 6);
#line 755 "D:\\Bitbucket\\hit-compilation\\Test\\flexskel.cc"

#ifndef YY_USE_CLASS
    return ( yy_is_jam ? 0 : yy_current_state );
#else
    return (long)( yy_is_jam ? 0 : yy_current_state );
#endif
    }

#ifndef YY_USE_CLASS
#ifdef YY_USE_PROTOS
static void yyunput( YY_lex_CHAR c, register YY_lex_CHAR *yy_bp )
#else
static void yyunput( c, yy_bp )
YY_lex_CHAR c;
register YY_lex_CHAR *yy_bp;
#endif
#else
void YY_lex_CLASS::yyunput( YY_lex_CHAR c, YY_lex_CHAR *yy_bp )
#endif

    {
    register YY_lex_CHAR *yy_cp = yy_c_buf_p;

    /* undo effects of setting up yy___text */
    *yy_cp = yy_hold_char;

    if ( yy_cp < YY_lex_CURRENT_BUFFER->yy_ch_buf + 2 )
	{ /* need to shift things up to make room */
	register int number_to_move = yy_n_chars + 2; /* +2 for EOB chars */
	register YY_lex_CHAR *dest =
	    &YY_lex_CURRENT_BUFFER->yy_ch_buf[YY_lex_CURRENT_BUFFER->yy_buf_size + 2];
	register YY_lex_CHAR *source =
	    &YY_lex_CURRENT_BUFFER->yy_ch_buf[number_to_move];

	while ( source > YY_lex_CURRENT_BUFFER->yy_ch_buf )
	    *--dest = *--source;

	yy_cp += dest - source;
	yy_bp += dest - source;
	yy_n_chars = YY_lex_CURRENT_BUFFER->yy_buf_size;

	if ( yy_cp < YY_lex_CURRENT_BUFFER->yy_ch_buf + 2 )
	    YY_FATAL_ERROR( "flex scanner push-back overflow" );
	}

    if ( yy_cp > yy_bp && yy_cp[-1] == '\n' )
	yy_cp[-2] = '\n';

    *--yy_cp = c;

    /* note: the formal parameter *must* be called "yy_bp" for this
     *       macro to now work correctly
     */
    YY_DO_BEFORE_ACTION; /* set up yy___text again */
    }

#ifndef YY_USE_CLASS
#ifdef __cplusplus
static int yyinput()
#else
static int input()
#endif
#else
int YY_lex_CLASS::input()
#endif
    {
    int c;
    YY_lex_CHAR *yy_cp = yy_c_buf_p;

    *yy_cp = yy_hold_char;

    if ( *yy_c_buf_p == YY_END_OF_BUFFER_CHAR )
	{
	/* yy_c_buf_p now points to the character we want to return.
	 * If this occurs *before* the EOB characters, then it's a
	 * valid NUL; if not, then we've hit the end of the buffer.
	 */
	if ( yy_c_buf_p < &YY_lex_CURRENT_BUFFER->yy_ch_buf[yy_n_chars] )
	    /* this was really a NUL */
	    *yy_c_buf_p = '\0';

	else
	    { /* need more input */
	    yy___text = yy_c_buf_p;
	    ++yy_c_buf_p;

	    switch ( yy_get_next_buffer() )
		{
		case EOB_ACT_END_OF_FILE:
		    {
		    if ( yywrap() )
			{
			yy_c_buf_p = yy___text + YY_MORE_ADJ;
			return ( EOF );
			}

		    YY_NEW_FILE;
#ifndef YY_USE_CLASS
#ifdef __cplusplus
		    return ( yyinput() );
#else
		    return ( input() );
#endif
#else
		    return ( input() );
#endif
		    }
		    break;

		case EOB_ACT_CONTINUE_SCAN:
		    yy_c_buf_p = yy___text + YY_MORE_ADJ;
		    break;

		case EOB_ACT_LAST_MATCH:
#ifndef YY_USE_CLASS
#ifdef __cplusplus
		    YY_FATAL_ERROR( "unexpected last match in yyinput()" );
#else
		    YY_FATAL_ERROR( "unexpected last match in input()" );
#endif
#else
		    YY_FATAL_ERROR( "unexpected last match in YY_lex_CLASS::input()" );
#endif
		}
	    }
	}

    c = *yy_c_buf_p;
    yy_hold_char = *++yy_c_buf_p;

    return ( c );
    }


#ifndef YY_USE_CLASS
#ifdef YY_USE_PROTOS
void YY_lex_RESTART( YY_lex_IFILE  *input_file )
#else
void YY_lex_RESTART( input_file )
YY_lex_IFILE  *input_file;
#endif
#else
void YY_lex_CLASS::YY_lex_RESTART ( YY_lex_IFILE  *input_file )
#endif

    {
    YY_lex_INIT_BUFFER( YY_lex_CURRENT_BUFFER, input_file );
    YY_lex_LOAD_BUFFER_STATE();
    }


#ifndef YY_USE_CLASS
#ifdef YY_USE_PROTOS
void YY_lex_SWITCH_TO_BUFFER( YY_BUFFER_STATE new_buffer )
#else
void YY_lex_SWITCH_TO_BUFFER( new_buffer )
YY_BUFFER_STATE new_buffer;
#endif
#else
void YY_lex_CLASS::YY_lex_SWITCH_TO_BUFFER( YY_BUFFER_STATE new_buffer )
#endif

    {
    if ( YY_lex_CURRENT_BUFFER == new_buffer )
	return;

    if ( YY_lex_CURRENT_BUFFER )
	{
	/* flush out information for old buffer */
	*yy_c_buf_p = yy_hold_char;
	YY_lex_CURRENT_BUFFER->yy_buf_pos = yy_c_buf_p;
	YY_lex_CURRENT_BUFFER->yy_n_chars = yy_n_chars;
	}

    YY_lex_CURRENT_BUFFER = new_buffer;
    YY_lex_LOAD_BUFFER_STATE();

    /* we don't actually know whether we did this switch during
     * EOF (yywrap()) processing, but the only time this flag
     * is looked at is after yywrap() is called, so it's safe
     * to go ahead and always set it.
     */
    yy_did_buffer_switch_on_eof = 1;
    }


#ifndef YY_USE_CLASS
#ifdef YY_USE_PROTOS
void YY_lex_LOAD_BUFFER_STATE( void )
#else
void YY_lex_LOAD_BUFFER_STATE()
#endif
#else
void YY_lex_CLASS::YY_lex_LOAD_BUFFER_STATE(  )
#endif

    {
    yy_n_chars = YY_lex_CURRENT_BUFFER->yy_n_chars;
    yy___text = yy_c_buf_p = YY_lex_CURRENT_BUFFER->yy_buf_pos;
    yy___in = YY_lex_CURRENT_BUFFER->yy_input_file;
    yy_hold_char = *yy_c_buf_p;
    }


#ifndef YY_USE_CLASS
#ifdef YY_USE_PROTOS
YY_BUFFER_STATE YY_lex_CREATE_BUFFER( YY_lex_IFILE  *file, int size )
#else
YY_BUFFER_STATE YY_lex_CREATE_BUFFER( file, size )
YY_lex_IFILE  *file;
int size;
#endif
#else
YY_BUFFER_STATE YY_lex_CLASS::YY_lex_CREATE_BUFFER( YY_lex_IFILE  *file, int size )
#endif

    {
    YY_BUFFER_STATE b;

    b = (YY_BUFFER_STATE) malloc( sizeof( struct yy_buffer_state ) );

    if ( ! b )
	YY_FATAL_ERROR( "out of dynamic memory in YY_lex_CREATE_BUFFER()" );

    b->yy_buf_size = size;

    /* yy_ch_buf has to be 2 characters longer than the size given because
     * we need to put in 2 end-of-buffer characters.
     */
    b->yy_ch_buf = (YY_lex_CHAR *) malloc( (unsigned) (b->yy_buf_size + 2) );

    if ( ! b->yy_ch_buf )
	YY_FATAL_ERROR( "out of dynamic memory in YY_lex_CREATE_BUFFER()" );

    YY_lex_INIT_BUFFER( b, file );

    return ( b );
    }


#ifndef YY_USE_CLASS
#ifdef YY_USE_PROTOS
void YY_lex_DELETE_BUFFER( YY_BUFFER_STATE b )
#else
void YY_lex_DELETE_BUFFER( b )
YY_BUFFER_STATE b;
#endif
#else
void YY_lex_CLASS::YY_lex_DELETE_BUFFER( YY_BUFFER_STATE b )
#endif

    {
    if ( b == YY_lex_CURRENT_BUFFER )
	YY_lex_CURRENT_BUFFER = (YY_BUFFER_STATE) 0;

    free( (char *) b->yy_ch_buf );
    free( (char *) b );
    }


#ifndef YY_USE_CLASS
#ifdef YY_USE_PROTOS
void YY_lex_INIT_BUFFER( YY_BUFFER_STATE b, YY_lex_IFILE  *file )
#else
void YY_lex_INIT_BUFFER( b, file )
YY_BUFFER_STATE b;
YY_lex_IFILE  *file;
#endif
#else
void YY_lex_CLASS::YY_lex_INIT_BUFFER( YY_BUFFER_STATE b, YY_lex_IFILE  *file)
#endif

    {
    b->yy_input_file = file;

    /* we put in the '\n' and start reading from [1] so that an
     * initial match-at-newline will be true.
     */

    b->yy_ch_buf[0] = '\n';
    b->yy_n_chars = 1;

    /* we always need two end-of-buffer characters.  The first causes
     * a transition to the end-of-buffer state.  The second causes
     * a jam in that state.
     */
    b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;
    b->yy_ch_buf[2] = YY_END_OF_BUFFER_CHAR;

    b->yy_buf_pos = &b->yy_ch_buf[1];

    b->yy_eof_status = EOF_NOT_SEEN;
    }
#line 8 "test.l"

void main(int argc, char* argv[])
{
	yyin=fopen(argv[1],"r");
	printf("1:");
	yylex();
}