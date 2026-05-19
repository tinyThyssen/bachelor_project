/* Automatically generated file. Do not edit. 
 * Format:     ANSI C source code
 * Creator:    McStas <http://www.mcstas.org>
 * Instrument: FullInstrument_v5_working.instr (PSI_CAMEA)
 * Date:       Tue May 19 11:48:22 2026
 * File:       ./FullInstrument_v5_working.c
 * CFLAGS=
 */

#ifndef WIN32
#  ifndef OPENACC
#    define _GNU_SOURCE
#  endif
#  define _POSIX_C_SOURCE 200809L
#endif
/* In case of cl.exe on Windows, supppress warnings about #pragma acc */
#ifdef _MSC_EXTENSIONS
#pragma warning(disable: 4068)
#endif

#define MCCODE_STRING " 3.6.14, git"
#define FLAVOR        "mcstas"
#define FLAVOR_UPPER  "MCSTAS"

#define MC_USE_DEFAULT_MAIN
#define MC_TRACE_ENABLED

#include <string.h>
#include <inttypes.h>

typedef double MCNUM;
typedef struct {MCNUM x, y, z;} Coords;
typedef MCNUM Rotation[3][3];
#define MCCODE_BASE_TYPES

/* available random number generators */
#define _RNG_ALG_MT         1
#define _RNG_ALG_KISS       2
/* selection of random number generator */
#ifndef RNG_ALG
#  define RNG_ALG  _RNG_ALG_KISS
#endif
#if RNG_ALG == _RNG_ALG_MT // MT 
#define randstate_t uint32_t
#elif RNG_ALG == _RNG_ALG_KISS  // KISS
#define randstate_t uint64_t
#endif

#ifndef MC_NUSERVAR
#define MC_NUSERVAR 10
#endif

/* Particle JUMP control logic */
struct particle_logic_struct {
int dummy;
};

struct _struct_particle {
  double x,y,z; /* position [m] */
  double vx,vy,vz; /* velocity [m/s] */
  double sx,sy,sz; /* spin [0-1] */
  int mcgravitation; /* gravity-state */
  void *mcMagnet;    /* precession-state */
  int allow_backprop; /* allow backprop */
  /* Generic Temporaries: */
  /* May be used internally by components e.g. for special */
  /* return-values from functions used in trace, thusreturned via */
  /* particle struct. (Example: Wolter Conics from McStas, silicon slabs.) */
  double _mctmp_a; /* temp a */
  double _mctmp_b; /* temp b */
  double _mctmp_c; /* temp c */
  randstate_t randstate[7];
  double t, p;     /* time, event weight */
  long long _uid;  /* Unique event ID */
  long _index;     /* component index where to send this event */
  long _absorbed;  /* flag set to TRUE when this event is to be removed/ignored */
  long _scattered; /* flag set to TRUE when this event has interacted with the last component instance */
  long _restore;   /* set to true if neutron event must be restored */
  long flag_nocoordschange;   /* set to true if particle is jumping */
  struct particle_logic_struct _logic;
  // user variables and comp-injections:
  int  ncol_19;
  int  nrow_19;
  double  res_pi_39;
  double  res_ki_x_39;
  double  res_ki_y_39;
  double  res_ki_z_39;
  double  res_kf_x_39;
  double  res_kf_y_39;
  double  res_kf_z_39;
  double  res_rx_39;
  double  res_ry_39;
  double  res_rz_39;
};
typedef struct _struct_particle _class_particle;

_class_particle _particle_global_randnbuse_var;
_class_particle* _particle = &_particle_global_randnbuse_var;

#pragma acc routine
_class_particle mcgenstate(void);
#pragma acc routine
_class_particle mcsetstate(double x, double y, double z, double vx, double vy, double vz,
			   double t, double sx, double sy, double sz, double p, int mcgravitation, void *mcMagnet, int mcallowbackprop);
#pragma acc routine
_class_particle mcgetstate(_class_particle mcneutron, double *x, double *y, double *z,
                           double *vx, double *vy, double *vz, double *t,
                           double *sx, double *sy, double *sz, double *p);

extern int mcgravitation;      /* flag to enable gravitation */
#pragma acc declare create ( mcgravitation )

_class_particle mcgenstate(void) {
  _class_particle particle = mcsetstate(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, mcgravitation, NULL, 0);
  return(particle);
}
/*Generated user variable handlers:*/

#pragma acc routine
double particle_getvar(_class_particle *p, char *name, int *suc);

#ifdef OPENACC
#pragma acc routine
int str_comp(char *str1, char *str2);
#endif

double particle_getvar(_class_particle *p, char *name, int *suc){
#ifndef OPENACC
#define str_comp strcmp
#endif
  int s=1;
  double rval=0;
  if(!str_comp("x",name)){rval=p->x;s=0;}
  if(!str_comp("y",name)){rval=p->y;s=0;}
  if(!str_comp("z",name)){rval=p->z;s=0;}
  if(!str_comp("vx",name)){rval=p->vx;s=0;}
  if(!str_comp("vy",name)){rval=p->vy;s=0;}
  if(!str_comp("vz",name)){rval=p->vz;s=0;}
  if(!str_comp("sx",name)){rval=p->sx;s=0;}
  if(!str_comp("sy",name)){rval=p->sy;s=0;}
  if(!str_comp("sz",name)){rval=p->sz;s=0;}
  if(!str_comp("t",name)){rval=p->t;s=0;}
  if(!str_comp("p",name)){rval=p->p;s=0;}
  if(!str_comp("_mctmp_a",name)){rval=p->_mctmp_a;s=0;}
  if(!str_comp("_mctmp_b",name)){rval=p->_mctmp_b;s=0;}
  if(!str_comp("_mctmp_c",name)){rval=p->_mctmp_c;s=0;}
  if(!str_comp("ncol_19",name)){rval=*( (double *)(&(p->ncol_19)) );s=0;}
  if(!str_comp("nrow_19",name)){rval=*( (double *)(&(p->nrow_19)) );s=0;}
  if(!str_comp("res_pi_39",name)){rval=*( (double *)(&(p->res_pi_39)) );s=0;}
  if(!str_comp("res_ki_x_39",name)){rval=*( (double *)(&(p->res_ki_x_39)) );s=0;}
  if(!str_comp("res_ki_y_39",name)){rval=*( (double *)(&(p->res_ki_y_39)) );s=0;}
  if(!str_comp("res_ki_z_39",name)){rval=*( (double *)(&(p->res_ki_z_39)) );s=0;}
  if(!str_comp("res_kf_x_39",name)){rval=*( (double *)(&(p->res_kf_x_39)) );s=0;}
  if(!str_comp("res_kf_y_39",name)){rval=*( (double *)(&(p->res_kf_y_39)) );s=0;}
  if(!str_comp("res_kf_z_39",name)){rval=*( (double *)(&(p->res_kf_z_39)) );s=0;}
  if(!str_comp("res_rx_39",name)){rval=*( (double *)(&(p->res_rx_39)) );s=0;}
  if(!str_comp("res_ry_39",name)){rval=*( (double *)(&(p->res_ry_39)) );s=0;}
  if(!str_comp("res_rz_39",name)){rval=*( (double *)(&(p->res_rz_39)) );s=0;}
  if (suc!=0x0) {*suc=s;}
  return rval;
}

#pragma acc routine
void* particle_getvar_void(_class_particle *p, char *name, int *suc);

#ifdef OPENACC
#pragma acc routine
int str_comp(char *str1, char *str2);
#endif

void* particle_getvar_void(_class_particle *p, char *name, int *suc){
#ifndef OPENACC
#define str_comp strcmp
#endif
  int s=1;
  void* rval=0;
  if(!str_comp("x",name)) {rval=(void*)&(p->x); s=0;}
  if(!str_comp("y",name)) {rval=(void*)&(p->y); s=0;}
  if(!str_comp("z",name)) {rval=(void*)&(p->z); s=0;}
  if(!str_comp("vx",name)){rval=(void*)&(p->vx);s=0;}
  if(!str_comp("vy",name)){rval=(void*)&(p->vy);s=0;}
  if(!str_comp("vz",name)){rval=(void*)&(p->vz);s=0;}
  if(!str_comp("sx",name)){rval=(void*)&(p->sx);s=0;}
  if(!str_comp("sy",name)){rval=(void*)&(p->sy);s=0;}
  if(!str_comp("sz",name)){rval=(void*)&(p->sz);s=0;}
  if(!str_comp("t",name)) {rval=(void*)&(p->t); s=0;}
  if(!str_comp("p",name)) {rval=(void*)&(p->p); s=0;}
  if(!str_comp("ncol_19",name)){rval=(void*)&(p->ncol_19);s=0;}
  if(!str_comp("nrow_19",name)){rval=(void*)&(p->nrow_19);s=0;}
  if(!str_comp("res_pi_39",name)){rval=(void*)&(p->res_pi_39);s=0;}
  if(!str_comp("res_ki_x_39",name)){rval=(void*)&(p->res_ki_x_39);s=0;}
  if(!str_comp("res_ki_y_39",name)){rval=(void*)&(p->res_ki_y_39);s=0;}
  if(!str_comp("res_ki_z_39",name)){rval=(void*)&(p->res_ki_z_39);s=0;}
  if(!str_comp("res_kf_x_39",name)){rval=(void*)&(p->res_kf_x_39);s=0;}
  if(!str_comp("res_kf_y_39",name)){rval=(void*)&(p->res_kf_y_39);s=0;}
  if(!str_comp("res_kf_z_39",name)){rval=(void*)&(p->res_kf_z_39);s=0;}
  if(!str_comp("res_rx_39",name)){rval=(void*)&(p->res_rx_39);s=0;}
  if(!str_comp("res_ry_39",name)){rval=(void*)&(p->res_ry_39);s=0;}
  if(!str_comp("res_rz_39",name)){rval=(void*)&(p->res_rz_39);s=0;}
  if (suc!=0x0) {*suc=s;}
  return rval;
}

#pragma acc routine
int particle_setvar_void(_class_particle *, char *, void*);

int particle_setvar_void(_class_particle *p, char *name, void* value){
#ifndef OPENACC
#define str_comp strcmp
#endif
  int rval=1;
  if(!str_comp("x",name)) {memcpy(&(p->x),  value, sizeof(double)); rval=0;}
  if(!str_comp("y",name)) {memcpy(&(p->y),  value, sizeof(double)); rval=0;}
  if(!str_comp("z",name)) {memcpy(&(p->z),  value, sizeof(double)); rval=0;}
  if(!str_comp("vx",name)){memcpy(&(p->vx), value, sizeof(double)); rval=0;}
  if(!str_comp("vy",name)){memcpy(&(p->vy), value, sizeof(double)); rval=0;}
  if(!str_comp("vz",name)){memcpy(&(p->vz), value, sizeof(double)); rval=0;}
  if(!str_comp("sx",name)){memcpy(&(p->sx), value, sizeof(double)); rval=0;}
  if(!str_comp("sy",name)){memcpy(&(p->sy), value, sizeof(double)); rval=0;}
  if(!str_comp("sz",name)){memcpy(&(p->sz), value, sizeof(double)); rval=0;}
  if(!str_comp("p",name)) {memcpy(&(p->p),  value, sizeof(double)); rval=0;}
  if(!str_comp("t",name)) {memcpy(&(p->t),  value, sizeof(double)); rval=0;}
  if(!str_comp("ncol_19",name)){memcpy(&(p->ncol_19), value, sizeof(int )); rval=0;}
  if(!str_comp("nrow_19",name)){memcpy(&(p->nrow_19), value, sizeof(int )); rval=0;}
  if(!str_comp("res_pi_39",name)){memcpy(&(p->res_pi_39), value, sizeof(double )); rval=0;}
  if(!str_comp("res_ki_x_39",name)){memcpy(&(p->res_ki_x_39), value, sizeof(double )); rval=0;}
  if(!str_comp("res_ki_y_39",name)){memcpy(&(p->res_ki_y_39), value, sizeof(double )); rval=0;}
  if(!str_comp("res_ki_z_39",name)){memcpy(&(p->res_ki_z_39), value, sizeof(double )); rval=0;}
  if(!str_comp("res_kf_x_39",name)){memcpy(&(p->res_kf_x_39), value, sizeof(double )); rval=0;}
  if(!str_comp("res_kf_y_39",name)){memcpy(&(p->res_kf_y_39), value, sizeof(double )); rval=0;}
  if(!str_comp("res_kf_z_39",name)){memcpy(&(p->res_kf_z_39), value, sizeof(double )); rval=0;}
  if(!str_comp("res_rx_39",name)){memcpy(&(p->res_rx_39), value, sizeof(double )); rval=0;}
  if(!str_comp("res_ry_39",name)){memcpy(&(p->res_ry_39), value, sizeof(double )); rval=0;}
  if(!str_comp("res_rz_39",name)){memcpy(&(p->res_rz_39), value, sizeof(double )); rval=0;}
  return rval;
}

#pragma acc routine
int particle_setvar_void_array(_class_particle *, char *, void*, int);

int particle_setvar_void_array(_class_particle *p, char *name, void* value, int elements){
#ifndef OPENACC
#define str_comp strcmp
#endif
  int rval=1;
  return rval;
}

#pragma acc routine
void particle_restore(_class_particle *p, _class_particle *p0);

void particle_restore(_class_particle *p, _class_particle *p0) {
  p->x  = p0->x;  p->y  = p0->y;  p->z  = p0->z;
  p->vx = p0->vx; p->vy = p0->vy; p->vz = p0->vz;
  p->sx = p0->sx; p->sy = p0->sy; p->sz = p0->sz;
  p->t = p0->t;  p->p  = p0->p;
  p->_absorbed=0; p->_restore=0;
}

#pragma acc routine
double particle_getuservar_byid(_class_particle *p, int id, int *suc){
  int s=1;
  double rval=0;
  switch(id){
  case 0: { rval=*( (double *)(&(p->ncol_19)) );s=0;break;}
  case 1: { rval=*( (double *)(&(p->nrow_19)) );s=0;break;}
  case 2: { rval=*( (double *)(&(p->res_pi_39)) );s=0;break;}
  case 3: { rval=*( (double *)(&(p->res_ki_x_39)) );s=0;break;}
  case 4: { rval=*( (double *)(&(p->res_ki_y_39)) );s=0;break;}
  case 5: { rval=*( (double *)(&(p->res_ki_z_39)) );s=0;break;}
  case 6: { rval=*( (double *)(&(p->res_kf_x_39)) );s=0;break;}
  case 7: { rval=*( (double *)(&(p->res_kf_y_39)) );s=0;break;}
  case 8: { rval=*( (double *)(&(p->res_kf_z_39)) );s=0;break;}
  case 9: { rval=*( (double *)(&(p->res_rx_39)) );s=0;break;}
  case 10: { rval=*( (double *)(&(p->res_ry_39)) );s=0;break;}
  case 11: { rval=*( (double *)(&(p->res_rz_39)) );s=0;break;}
  }
  if (suc!=0x0) {*suc=s;}
  return rval;
}

#pragma acc routine
void particle_uservar_init(_class_particle *p){
  p->ncol_19=0;
  p->nrow_19=0;
  p->res_pi_39=0;
  p->res_ki_x_39=0;
  p->res_ki_y_39=0;
  p->res_ki_z_39=0;
  p->res_kf_x_39=0;
  p->res_kf_y_39=0;
  p->res_kf_z_39=0;
  p->res_rx_39=0;
  p->res_ry_39=0;
  p->res_rz_39=0;
}

#define MC_EMBEDDED_RUNTIME
/* embedding file "mccode-r.h" */

/*******************************************************************************
*
* McCode, neutron/xray ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mccode-r.h
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: mcstas 3.6.14
* Version: $Revision$
*
* Runtime system header for McStas/McXtrace.
*
* In order to use this library as an external library, the following variables
* and macros must be declared (see details in the code)
*
*   struct mcinputtable_struct mcinputtable[];
*   int numipar;
*   metadata_table_t metadata_table[];
*   int num_metadata;
*   char instrument_name[], instrument_source[];
*   int traceenabled, defaultmain;
*   extern MCNUM  mccomp_storein[];
*   extern MCNUM  mcAbsorbProp[];
*   extern MCNUM  mcScattered;
*   #define MCCODE_STRING "the McStas/McXtrace version"
*
* Usage: Automatically embbeded in the c code.
*
* $Id$
*
*******************************************************************************/

#ifndef MCCODE_R_H
#define MCCODE_R_H "$Revision$"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#ifndef _MSC_EXTENSIONS
#include <sys/time.h>
#endif
#include <float.h>
#include <inttypes.h>
#include <stdint.h>
#ifdef OPENACC
#include <openacc.h>
#ifndef GCCOFFLOAD
#include <accelmath.h>
#else
#include <math.h>
#endif
#pragma acc routine
int noprintf();
#pragma acc routine
size_t str_len(const char *s);
#else
#include <math.h>
#endif

/* In case of gcc / clang, ensure to use
   the built-in isnan/isinf functions */
#if defined(__GNUC__) || defined(__clang__)
#  ifdef isnan
#    undef isnan
#  endif
#  ifdef isinf
#    undef isinf
#  endif
#  define isnan(x) __builtin_isnan(x)
#  define isinf(x) __builtin_isinf(x)
#endif

#ifdef _MSC_EXTENSIONS
#ifndef _TIMES_H
#define _TIMES_H

#if defined(WIN32) || defined(_WIN32)
#include <sys/timeb.h>
#include <sys/types.h>
#include <winsock2.h>

int gettimeofday(struct timeval* t,void* timezone);

#define __need_clock_t
#include <time.h>


/* Structure describing CPU time used by a process and its children.  */
struct tms
  {
    clock_t tms_utime;          /* User CPU time.  */
    clock_t tms_stime;          /* System CPU time.  */

    clock_t tms_cutime;         /* User CPU time of dead children.  */
    clock_t tms_cstime;         /* System CPU time of dead children.  */
  };

/* Store the CPU time used by this process and all its
   dead children (and their dead children) in BUFFER.
   Return the elapsed real time, or (clock_t) -1 for errors.
   All times are in CLK_TCKths of a second.  */
clock_t times (struct tms *__buffer);

typedef long long suseconds_t ;



int gettimeofday(struct timeval* t,void* timezone)
{       struct _timeb timebuffer;
        _ftime( &timebuffer );
        t->tv_sec=timebuffer.time;
        t->tv_usec=1000*timebuffer.millitm;
		return 0;
}

clock_t times (struct tms *__buffer) {

	__buffer->tms_utime = clock();
	__buffer->tms_stime = 0;
	__buffer->tms_cstime = 0;
	__buffer->tms_cutime = 0;
	return __buffer->tms_utime;
}


#endif
#endif
#endif

/* If the runtime is embedded in the simulation program, some definitions can
   be made static. */

#ifdef MC_EMBEDDED_RUNTIME
#  define mcstatic
#else
#  define mcstatic
#endif

#ifdef __dest_os
#  if (__dest_os == __mac_os)
#    define MAC
#  endif
#endif

#ifdef __FreeBSD__
#  define NEED_STAT_H
#endif

#if defined(__APPLE__) && defined(__GNUC__)
#  define NEED_STAT_H
#endif

#if defined(WIN32) || defined(_WIN32)
#  define NEED_STAT_H
#  define NEED_TYPES_H
#endif

#ifdef NEED_STAT_H
#  include <sys/stat.h>
#endif

#ifdef NEED_TYPES_H
#  include <sys/types.h>
#endif

#ifndef MC_PATHSEP_C
#if defined(WIN32) || defined(_WIN32)
#    define MC_PATHSEP_C '\\'
#    define MC_PATHSEP_S "\\"
#  else  /* !WIN32 */
#    define MC_PATHSEP_C '/'
#    define MC_PATHSEP_S "/"
#  endif /* !WIN32 */
#endif /* MC_PATHSEP_C */

#if defined(WIN32) || defined(_WIN32)
#if defined _MSC_VER
#include <direct.h>
#elif defined __GNUC__
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
#define mkdir(a,b) mkdir(a)
#define getpid() _getpid()
#endif

/* the version string is replaced when building distribution with mkdist */
#ifndef MCCODE_STRING
#  define MCCODE_STRING " 3.6.14, git"
#endif

#ifndef MCCODE_DATE
#  define MCCODE_DATE "git"
#endif

#ifndef MCCODE_VERSION
#  define MCCODE_VERSION "3.6.14"
#endif

#ifndef __MCCODE_VERSION__
#define __MCCODE_VERSION__ 306014L
#endif

#ifndef MCCODE_NAME
#  define MCCODE_NAME "mcstas"
#endif

#ifndef MCCODE_PARTICLE
#  define MCCODE_PARTICLE "neutron"
#endif

#ifndef MCCODE_PARTICLE_CODE
#  define MCCODE_PARTICLE_CODE 2112
#endif

#ifndef MCCODE_LIBENV
#  define MCCODE_LIBENV "MCSTAS"
#endif

#ifndef FLAVOR_UPPER
#  define FLAVOR_UPPER MCCODE_NAME
#endif

#ifdef MC_PORTABLE
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#ifdef MAC
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#if (USE_MPI == 0)
#  undef USE_MPI
#endif

#ifdef USE_MPI  /* default is to disable signals with MPI, as MPICH uses them to communicate */
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#ifdef OPENACC  /* default is to disable signals with PGI/OpenACC */
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#ifndef OPENACC
#  ifndef USE_OFF  /* default is to enable OFF when not using PGI/OpenACC */
#    define USE_OFF
#  endif
#  ifndef CPUFUNNEL  /* allow to enable FUNNEL-mode on CPU */
#  ifdef FUNNEL      /* by default disable FUNNEL-mode when not using PGI/OpenACC */
#    undef FUNNEL
#  endif
#  endif
#endif

#if (NOSIGNALS == 0)
#  undef NOSIGNALS
#endif

/** Header information for metadata-r.c ----------------------------------------------------------------------------- */
struct metadata_table_struct { /* stores metadata strings from components */
  char * source;  // component name which provided the metadata
  char * name;    // the name of the metadata
  char * type;    // the MIME type of the metadata (free form, valid identifier)
  char * value;   // the metadata string contents
};
typedef struct metadata_table_struct metadata_table_t;
char * metadata_table_key_component(char* key);
char * metadata_table_key_literal(char * key);
int metadata_table_defined(int, metadata_table_t *, char *);
char * metadata_table_name(int, metadata_table_t *, char *);
char * metadata_table_type(int, metadata_table_t *, char *);
char * metadata_table_literal(int, metadata_table_t *, char *);
void metadata_table_print_all_keys(int no, metadata_table_t * tab);
int metadata_table_print_all_components(int no, metadata_table_t * tab);
int metadata_table_print_component_keys(int no, metadata_table_t * tab, char * key);
/* -------------------------------------------------------------------------- Header information for metadata-r.c --- */

/* Note: the enum instr_formal_types definition MUST be kept
   synchronized with the one in mccode.h and with the
   instr_formal_type_names array in cogen.c. */
enum instr_formal_types
  {
    instr_type_int,
    instr_type_string, instr_type_char,
    instr_type_vector, instr_type_double
  };
struct mcinputtable_struct { /* defines instrument parameters */
  char *name; /* name of parameter */
  void *par;  /* pointer to instrument parameter (variable) */
  enum instr_formal_types type;
  char *val;  /* default value */
  char *unit; /* expected unit for parameter; informational only */
};


#ifndef MCCODE_BASE_TYPES
typedef double MCNUM;
typedef struct {MCNUM x, y, z;} Coords;
typedef MCNUM Rotation[3][3];
#endif

/* the following variables are defined in the McStas generated C code
   but should be defined externally in case of independent library usage */
#ifndef DANSE
extern struct mcinputtable_struct mcinputtable[];         /* list of instrument parameters */
extern int    numipar;                                    /* number of instrument parameters */
extern metadata_table_t metadata_table[];                 /* list of component-defined string metadata */
extern int    num_metadata;                               /* number of component-defined string metadata */
extern char   instrument_name[], instrument_source[]; /* instrument name and filename */
extern char  *instrument_exe;                           /* executable path = argv[0] or NULL */
extern char   instrument_code[];                        /* contains the initial 'instr' file */

#ifndef MC_ANCIENT_COMPATIBILITY
extern int traceenabled, defaultmain;
#endif
#endif


/* Useful macros ============================================================ */


/* SECTION: Dynamic Arrays */
typedef int* IArray1d;
IArray1d create_iarr1d(int n);
void destroy_iarr1d(IArray1d a);

typedef int** IArray2d;
IArray2d create_iarr2d(int nx, int ny);
void destroy_iarr2d(IArray2d a);

typedef int*** IArray3d;
IArray3d create_iarr3d(int nx, int ny, int nz);
void destroy_iarr3d(IArray3d a);

typedef double* DArray1d;
DArray1d create_darr1d(int n);
void destroy_darr1d(DArray1d a);

typedef double** DArray2d;
DArray2d create_darr2d(int nx, int ny);
void destroy_darr2d(DArray2d a);

typedef double*** DArray3d;
DArray3d create_darr3d(int nx, int ny, int nz);
void destroy_darr3d(DArray3d a);


/* MPI stuff */
#ifdef USE_MPI
#include "mpi.h"

#ifdef OMPI_MPI_H  /* openmpi does not use signals: we may install our sighandler */
#ifndef OPENACC    /* ... but only if we are not also running on GPU */
#undef NOSIGNALS
#endif
#endif

/*
 * MPI_MASTER(i):
 * execution of i only on master node
 */
#define MPI_MASTER(statement) { \
  if(mpi_node_rank == mpi_node_root)\
  { statement; } \
}

#ifndef MPI_REDUCE_BLOCKSIZE
#define MPI_REDUCE_BLOCKSIZE 100000
#endif

int mc_MPI_Sum(double* buf, long count);
int mc_MPI_Send(void *sbuf, long count, MPI_Datatype dtype, int dest);
int mc_MPI_Recv(void *rbuf, long count, MPI_Datatype dtype, int source);

/* MPI_Finalize exits gracefully and should be preferred to MPI_Abort */
#define exit(code) do {                                   \
    MPI_Finalize();                                       \
    exit(code);                                           \
  } while(0)

#else /* !USE_MPI */
#define MPI_MASTER(instr) instr
#endif /* USE_MPI */


#ifdef USE_MPI
static int mpi_node_count;
#endif

#ifdef USE_THREADS  /* user want threads */
#error Threading (USE_THREADS) support has been removed for very poor efficiency. Use MPI/SSH grid instead.
#endif


void   mcset_ncount(unsigned long long count);    /* wrapper to get mcncount */
#pragma acc routine
unsigned long long int mcget_ncount(void);            /* wrapper to set mcncount */
unsigned long long mcget_run_num(void);           /* wrapper to get mcrun_num=0:mcncount-1 */

/* Following part is only embedded when not redundant with mccode.h ========= */

#ifndef MCCODE_H

#ifndef NOSIGNALS
#include <signal.h>
char  *mcsig_message;
#define SIG_MESSAGE(msg) mcsig_message=(char *)(msg);
#else
#define SIG_MESSAGE(...)
#endif /* !NOSIGNALS */


/* Useful macros and constants ============================================== */


#ifndef FLT_MAX
#define FLT_MAX         3.40282347E+38F /* max decimal value of a "float" */
#endif

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef SQR
#define SQR(x) ( (x) * (x) )
#endif
#ifndef SIGN
#define SIGN(x) (((x)>0.0)?(1):(-1))
#endif


#  ifndef M_E
#    define M_E        2.71828182845904523536  // e
#  endif
#  ifndef M_LOG2E
#    define M_LOG2E    1.44269504088896340736  //  log2(e)
#  endif
#  ifndef M_LOG10E
#    define M_LOG10E   0.434294481903251827651 //  log10(e)
#  endif
#  ifndef M_LN2
#    define M_LN2      0.693147180559945309417 //  ln(2)
#  endif
#  ifndef M_LN10
#    define M_LN10     2.30258509299404568402  //  ln(10)
#  endif
#  ifndef M_PI
#    define M_PI       3.14159265358979323846  //  pi
#  endif
#  ifndef PI
#    define PI       M_PI                      //  pi - also used in some places
#  endif
#  ifndef M_PI_2
#    define M_PI_2     1.57079632679489661923  //  pi/2
#  endif
#  ifndef M_PI_4
#    define M_PI_4     0.785398163397448309616 //  pi/4
#  endif
#  ifndef M_1_PI
#    define M_1_PI     0.318309886183790671538 //  1/pi
#  endif
#  ifndef M_2_PI
#    define M_2_PI     0.636619772367581343076 //  2/pi
#  endif
#  ifndef M_2_SQRTPI
#    define M_2_SQRTPI 1.12837916709551257390  //  2/sqrt(pi)
#  endif
#  ifndef M_SQRT2
#    define M_SQRT2    1.41421356237309504880  //  sqrt(2)
#  endif
#  ifndef M_SQRT1_2
#    define M_SQRT1_2  0.707106781186547524401 //  1/sqrt(2)
#  endif

#define RAD2MIN  ((180*60)/PI)
#define MIN2RAD  (PI/(180*60))
#define DEG2RAD  (PI/180)
#define RAD2DEG  (180/PI)
#define FWHM2RMS 0.424660900144    /* Convert between full-width-half-max and */
#define RMS2FWHM 2.35482004503     /* root-mean-square (standard deviation) */
#define HBAR     1.05457168e-34    /* [Js] h bar Planck constant CODATA 2002 */
#define MNEUTRON 1.67492728e-27    /* [kg] mass of neutron CODATA 2002 */
#define GRAVITY  9.81              /* [m/s^2] gravitational acceleration */
#define NA       6.02214179e23     /* [#atoms/g .mole] Avogadro's number*/


#define UNSET nan("0x6E6F74736574")
int nans_match(double, double);
int is_unset(double);
int is_valid(double);
int is_set(double);
int all_unset(int n, ...);
int all_set(int n, ...);
int any_unset(int n, ...);
int any_set(int n, ...);


/* wrapper to get absolute and relative position of comp */
/* mccomp_posa and mccomp_posr are defined in McStas generated C code */
#define POS_A_COMP_INDEX(index) (instrument->_position_absolute[index])
#define POS_R_COMP_INDEX(index) (instrument->_position_relative[index])

/* setting parameters based COMP_GETPAR (returned as pointer)         */
/* compname must be given as a string, type and par are symbols.      */
#define COMP_GETPAR3(type, compname, par) \
    &( ((_class_ ## type ##_parameters *) _getvar_parameters(compname))->par )
/* the body of this function depends on component instances, and is cogen'd */
void* _getvar_parameters(char* compname);

int _getcomp_index(char* compname);

/* Note: The two-stage approach to COMP_GETPAR is NOT redundant; without it,
* after #define C sample, COMP_GETPAR(C,x) would refer to component C, not to
* component sample. Such are the joys of ANSI C.

* Anyway the usage of COMP_GETPAR requires that we use sometimes bare names...
* NOTE: This can ONLY be used in instrument descriptions, not components.
*/
#define COMP_GETPAR2(comp, par) (_ ## comp ## _var._parameters.par)
#define COMP_GETPAR(comp, par) COMP_GETPAR2(comp,par)

#define INSTRUMENT_GETPAR(par) (_instrument_var._parameters.par)

/* Current component name, index, position and orientation */
/* These macros work because, using class-based functions, "comp" is usually
*  the local variable of the active/current component. */
#define INDEX_CURRENT_COMP (_comp->_index)
#define NAME_CURRENT_COMP (_comp->_name)
#define TYPE_CURRENT_COMP (_comp->_type)
#define POS_A_CURRENT_COMP (_comp->_position_absolute)
#define POS_R_CURRENT_COMP (_comp->_position_relative)
#define ROT_A_CURRENT_COMP (_comp->_rotation_absolute)
#define ROT_R_CURRENT_COMP (_comp->_rotation_relative)

#define NAME_INSTRUMENT (instrument->_name)


/* MCDISPLAY/trace and debugging message sent to stdout */
#ifdef MC_TRACE_ENABLED
#define DEBUG
#endif

#ifdef DEBUG
#define DEBUG_INSTR() if(!mcdotrace); else { printf("INSTRUMENT:\n"); printf("Instrument '%s' (%s)\n", instrument_name, instrument_source); }
#define DEBUG_COMPONENT(name,c,t) if(!mcdotrace); else {\
     printf("COMPONENT: \"%s\"\n"					  \
     "POS: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
     name, c.x, c.y, c.z, t[0][0], t[0][1], t[0][2], \
     t[1][0], t[1][1], t[1][2], t[2][0], t[2][1], t[2][2]); \
     printf("Component %30s AT (%g,%g,%g)\n", name, c.x, c.y, c.z); }
#define DEBUG_INSTR_END() if(!mcdotrace); else printf("INSTRUMENT END:\n");
#define DEBUG_ENTER() if(!mcdotrace); else printf("ENTER:\n");
#define DEBUG_COMP(c) if(!mcdotrace); else printf("COMP: \"%s\"\n", c);
#define DEBUG_LEAVE() if(!mcdotrace); else printf("LEAVE:\n");
#define DEBUG_ABSORB() if(!mcdotrace); else printf("ABSORB:\n");
#else
#define DEBUG_INSTR()
#define DEBUG_COMPONENT(name,c,t)
#define DEBUG_INSTR_END()
#define DEBUG_ENTER()
#define DEBUG_COMP(c)
#define DEBUG_LEAVE()
#define DEBUG_ABSORB()
#endif

// mcDEBUG_STATE and mcDEBUG_SCATTER are defined by mcstas-r.h and mcxtrace-r.h



#ifdef TEST
#define test_printf printf
#else
#define test_printf while(0) printf
#endif

/* send MCDISPLAY message to stdout to show gemoetry */
void mcdis_magnify(char *what);
void mcdis_line(double x1, double y1, double z1,
                double x2, double y2, double z2);
void mcdis_dashed_line(double x1, double y1, double z1,
		       double x2, double y2, double z2, int n);
void mcdis_multiline(int count, ...);
void mcdis_rectangle(char* plane, double x, double y, double z,
		     double width, double height);
void mcdis_box(double x, double y, double z,
	       double width, double height, double length, double thickness, double nx, double ny, double nz);
void mcdis_circle(char *plane, double x, double y, double z, double r);
void mcdis_Circle(double x, double y, double z, double r, double nx, double ny, double nz);
void mcdis_cylinder( double x, double y, double z,
		     double r, double height, double thickness, double nx, double ny, double nz);
void mcdis_cone( double x, double y, double z,
        double r, double height, double nx, double ny, double nz);
void mcdis_sphere(double x, double y, double z, double r);


/* random number generation. ================================================ */

#if RNG_ALG == _RNG_ALG_MT  // MT (currently not functional for GPU)
#  define MC_RAND_MAX ((uint32_t)0xffffffffUL)
#  define RANDSTATE_LEN 1
#  define srandom(seed) mt_srandom_empty()
#  define random() mt_random()
#  define _random() mt_random()
#elif RNG_ALG == _RNG_ALG_KISS  // KISS
#  ifndef UINT64_MAX
#    define UINT64_MAX ((uint64_t)0xffffffffffffffffULL)
#  endif
#  define MC_RAND_MAX UINT64_MAX
#  define RANDSTATE_LEN 7
#  define srandom(seed) kiss_srandom(_particle->randstate, seed)
#  define random() kiss_random(_particle->randstate)
#  define _random() kiss_random(state)
#endif

#pragma acc routine
double _randnorm2(randstate_t* state);

// Component writer interface
#define randnorm() _randnorm2(_particle->randstate)        // NOTE: can't use _randnorm on GPU
#define rand01() _rand01(_particle->randstate)
#define randpm1() _randpm1(_particle->randstate)
#define rand0max(p1) _rand0max(p1, _particle->randstate)
#define randminmax(p1, p2) _randminmax(p1, p2, _particle->randstate)
#define randtriangle() _randtriangle(_particle->randstate)

// Mersenne Twister rng
uint32_t mt_random(void);
void mt_srandom (uint32_t x);
void mt_srandom_empty();

// KISS rng
#pragma acc routine
uint64_t *kiss_srandom(uint64_t state[7], uint64_t seed);
#pragma acc routine
uint64_t kiss_random(uint64_t state[7]);

// Scrambler / hash function
#pragma acc routine seq
randstate_t _hash(randstate_t x);

// internal RNG (transforms) interface
#pragma acc routine
double _rand01(randstate_t* state);
#pragma acc routine
double _randpm1(randstate_t* state);
#pragma acc routine
double _rand0max(double max, randstate_t* state);
#pragma acc routine
double _randminmax(double min, double max, randstate_t* state);
#pragma acc routine
double _randtriangle(randstate_t* state);


#ifdef USE_OPENCL
#include "opencl-lib.h"
#include "opencl-lib.c"
#endif

#ifndef DANSE
int init(void);
int raytrace(_class_particle*);
int save(FILE *);
int finally(void);
int display(void);
#endif


/* GPU related algorithms =================================================== */

/*
*  Divide-and-conquer strategy for parallel sort absorbed last.
*/
#ifdef FUNNEL
long sort_absorb_last(_class_particle* particles, _class_particle* pbuffer, long len, long buffer_len, long flag_split, long* multiplier);
#endif
long sort_absorb_last_serial(_class_particle* particles, long len);


/* simple vector algebra ==================================================== */


#define vec_prod(x, y, z, x1, y1, z1, x2, y2, z2) \
	vec_prod_func(&x, &y, &z, x1, y1, z1, x2, y2, z2)
#pragma acc routine seq
mcstatic void vec_prod_func(double *x, double *y, double *z,
		double x1, double y1, double z1, double x2, double y2, double z2);

#pragma acc routine seq
mcstatic double scalar_prod(
		double x1, double y1, double z1, double x2, double y2, double z2);

#pragma acc routine seq
mcstatic void norm_func(double *x, double *y, double *z);
#define NORM(x,y,z)	norm_func(&x, &y, &z)

#pragma acc routine seq
void normal_vec(double *nx, double *ny, double *nz,
    double x, double y, double z);

/**
 * Rotate the vector vx,vy,vz psi radians around the vector ax,ay,az
 * and put the result in x,y,z.
 */
#define rotate(x, y, z, vx, vy, vz, phi, ax, ay, az) \
  do { \
    double mcrt_tmpx = (ax), mcrt_tmpy = (ay), mcrt_tmpz = (az); \
    double mcrt_vp, mcrt_vpx, mcrt_vpy, mcrt_vpz; \
    double mcrt_vnx, mcrt_vny, mcrt_vnz, mcrt_vn1x, mcrt_vn1y, mcrt_vn1z; \
    double mcrt_bx, mcrt_by, mcrt_bz; \
    double mcrt_cos, mcrt_sin; \
    NORM(mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_vp = scalar_prod((vx), (vy), (vz), mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_vpx = mcrt_vp*mcrt_tmpx; \
    mcrt_vpy = mcrt_vp*mcrt_tmpy; \
    mcrt_vpz = mcrt_vp*mcrt_tmpz; \
    mcrt_vnx = (vx) - mcrt_vpx; \
    mcrt_vny = (vy) - mcrt_vpy; \
    mcrt_vnz = (vz) - mcrt_vpz; \
    vec_prod(mcrt_bx, mcrt_by, mcrt_bz, \
             mcrt_tmpx, mcrt_tmpy, mcrt_tmpz, mcrt_vnx, mcrt_vny, mcrt_vnz); \
    mcrt_cos = cos((phi)); mcrt_sin = sin((phi)); \
    mcrt_vn1x = mcrt_vnx*mcrt_cos + mcrt_bx*mcrt_sin; \
    mcrt_vn1y = mcrt_vny*mcrt_cos + mcrt_by*mcrt_sin; \
    mcrt_vn1z = mcrt_vnz*mcrt_cos + mcrt_bz*mcrt_sin; \
    (x) = mcrt_vpx + mcrt_vn1x; \
    (y) = mcrt_vpy + mcrt_vn1y; \
    (z) = mcrt_vpz + mcrt_vn1z; \
  } while(0)

/**
 * Mirror (xyz) in the plane given by the point (rx,ry,rz) and normal (nx,ny,nz)
 *
 * TODO: This define is seemingly never used...
 */
#define mirror(x,y,z,rx,ry,rz,nx,ny,nz) \
  do { \
    double mcrt_tmpx= (nx), mcrt_tmpy = (ny), mcrt_tmpz = (nz); \
    double mcrt_tmpt; \
    NORM(mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_tmpt=scalar_prod((rx),(ry),(rz),mcrt_tmpx,mcrt_tmpy,mcrt_tmpz); \
    (x) = rx -2 * mcrt_tmpt*mcrt_rmpx; \
    (y) = ry -2 * mcrt_tmpt*mcrt_rmpy; \
    (z) = rz -2 * mcrt_tmpt*mcrt_rmpz; \
  } while (0)

#pragma acc routine
Coords coords_set(MCNUM x, MCNUM y, MCNUM z);
#pragma acc routine
Coords coords_get(Coords a, MCNUM *x, MCNUM *y, MCNUM *z);
#pragma acc routine
Coords coords_add(Coords a, Coords b);
#pragma acc routine
Coords coords_sub(Coords a, Coords b);
#pragma acc routine
Coords coords_neg(Coords a);
#pragma acc routine
Coords coords_scale(Coords b, double scale);
#pragma acc routine
double coords_sp(Coords a, Coords b);
#pragma acc routine
Coords coords_xp(Coords b, Coords c);
#pragma acc routine
double coords_len(Coords a);
#pragma acc routine seq
void   coords_print(Coords a);
#pragma acc routine seq
mcstatic void coords_norm(Coords* c);

#pragma acc routine seq
void rot_set_rotation(Rotation t, double phx, double phy, double phz);
#pragma acc routine seq
int  rot_test_identity(Rotation t);
#pragma acc routine seq
void rot_mul(Rotation t1, Rotation t2, Rotation t3);
#pragma acc routine seq
void rot_copy(Rotation dest, Rotation src);
#pragma acc routine seq
void rot_transpose(Rotation src, Rotation dst);
#pragma acc routine seq
Coords rot_apply(Rotation t, Coords a);

#pragma acc routine seq
void mccoordschange(Coords a, Rotation t, _class_particle *particle);
#pragma acc routine seq
void mccoordschange_polarisation(Rotation t, double *sx, double *sy, double *sz);

double mcestimate_error(double N, double p1, double p2);
void mcreadparams(void);

/* this is now in mcstas-r.h and mcxtrace-r.h as the number of state parameters
is no longer equal */

_class_particle mcgenstate(void);

// trajectory/shape intersection routines
#pragma acc routine seq
int inside_rectangle(double, double, double, double);
#pragma acc routine seq
int box_intersect(double *dt_in, double *dt_out, double x, double y, double z,
      double vx, double vy, double vz, double dx, double dy, double dz);
#pragma acc routine seq
int cylinder_intersect(double *t0, double *t1, double x, double y, double z,
      double vx, double vy, double vz, double r, double h);
#pragma acc routine seq
int sphere_intersect(double *t0, double *t1, double x, double y, double z,
      double vx, double vy, double vz, double r);
// second order equation roots
#pragma acc routine seq
int solve_2nd_order(double *t1, double *t2,
      double A,  double B,  double C);

// random vector generation to shape
// defines silently introducing _particle as the last argument
#define randvec_target_circle(xo, yo, zo, solid_angle, xi, yi, zi, radius) \
  _randvec_target_circle(xo, yo, zo, solid_angle, xi, yi, zi, radius, _particle)
#define randvec_target_rect_angular(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A) \
  _randvec_target_rect_angular(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A, _particle)
#define randvec_target_rect_real(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A, lx, ly, lz, order) \
  _randvec_target_rect_real(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A, lx, ly, lz, order, _particle)
// defines forwarding to "inner" functions
#define randvec_target_sphere randvec_target_circle
#define randvec_target_rect(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9) \
  randvec_target_rect_real(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,0,0,0,1)
// headers for randvec
#pragma acc routine seq
void _randvec_target_circle(double *xo, double *yo, double *zo,
  double *solid_angle, double xi, double yi, double zi, double radius,
  _class_particle* _particle);
#pragma acc routine seq
void _randvec_target_rect_angular(double *xo, double *yo, double *zo,
  double *solid_angle, double xi, double yi, double zi, double height,
  double width, Rotation A,
  _class_particle* _particle);
#pragma acc routine seq
void _randvec_target_rect_real(double *xo, double *yo, double *zo, double *solid_angle,
  double xi, double yi, double zi, double height, double width, Rotation A,
  double lx, double ly, double lz, int order,
  _class_particle* _particle);


// this is the main()
int mccode_main(int argc, char *argv[]);


#endif /* !MCCODE_H */

#ifndef MCCODE_R_IO_H
#define MCCODE_R_IO_H "$Revision$"

#if (USE_NEXUS == 0)
#undef USE_NEXUS
#endif

#ifndef CHAR_BUF_LENGTH
#define CHAR_BUF_LENGTH 1024
#endif


/* I/O section part ========================================================= */

/* ========================================================================== */

/*                               MCCODE_R_IO_C                                */

/* ========================================================================== */


/* main DETECTOR structure which stores most information to write to data files */
struct mcdetector_struct {
  char   filename[CHAR_BUF_LENGTH];   /* file name of monitor */
  double Position[3];                 /* position of detector component*/
  char   position[CHAR_BUF_LENGTH];   /* position of detector component (string)*/
  Rotation Rotation;                  /* position of detector component*/
  char   options[CHAR_BUF_LENGTH];    /* Monitor_nD style list-mode'options' (string)*/
  char   component[CHAR_BUF_LENGTH];  /* component instance name */
  char   nexuscomp[CHAR_BUF_LENGTH];  /* component naming in NeXus/HDF case */
  char   instrument[CHAR_BUF_LENGTH]; /* instrument name */
  char   type[CHAR_BUF_LENGTH];       /* data type, e.g. 0d, 1d, 2d, 3d */
  char   user[CHAR_BUF_LENGTH];       /* user name, e.g. HOME */
  char   date[CHAR_BUF_LENGTH];       /* date of simulation end/write time */
  char   title[CHAR_BUF_LENGTH];      /* title of detector */
  char   xlabel[CHAR_BUF_LENGTH];     /* X axis label */
  char   ylabel[CHAR_BUF_LENGTH];     /* Y axis label */
  char   zlabel[CHAR_BUF_LENGTH];     /* Z axis label */
  char   xvar[CHAR_BUF_LENGTH];       /* X variable name */
  char   yvar[CHAR_BUF_LENGTH];       /* Y variable name */
  char   zvar[CHAR_BUF_LENGTH];       /* Z variable name */
  char   ncount[CHAR_BUF_LENGTH];     /* number of events initially generated */
  char   limits[CHAR_BUF_LENGTH];     /* X Y Z limits, e.g. [xmin xmax ymin ymax zmin zmax] */
  char   variables[CHAR_BUF_LENGTH];  /* variables written into data block */
  char   statistics[CHAR_BUF_LENGTH]; /* center, mean and half width along axis */
  char   signal[CHAR_BUF_LENGTH];     /* min max and mean of signal (data block) */
  char   values[CHAR_BUF_LENGTH];     /* integrated values e.g. [I I_err N] */
  double xmin,xmax;                   /* min max of axes */
  double ymin,ymax;
  double zmin,zmax;
  double intensity;                   /* integrated values for data block */
  double error;
  double events;
  double min;                         /* statistics for data block */
  double max;
  double mean;
  double centerX;                     /* statistics for axes */
  double halfwidthX;
  double centerY;
  double halfwidthY;
  int    rank;                        /* dimensionaly of monitor, e.g. 0 1 2 3 */
  char   istransposed;                /* flag to transpose matrix for some formats */

  long   m,n,p;                       /* dimensions of data block and along axes */
  long   date_l;                      /* same as date, but in sec since 1970 */

  double *p0, *p1, *p2;               /* pointers to saved data, NULL when freed */
  char   format[CHAR_BUF_LENGTH];    /* format for file generation */
};

typedef struct mcdetector_struct MCDETECTOR;

static   char *dirname             = NULL;      /* name of output directory */
static   char *siminfo_name        = "mccode";  /* default output sim file name */
char    *mcformat                    = NULL;      /* NULL (default) or a specific format */

/* file I/O definitions and function prototypes */

#ifndef MC_EMBEDDED_RUNTIME /* the mcstatic variables (from mccode-r.c) */
extern FILE * siminfo_file;     /* handle to the output siminfo file */
extern int    mcgravitation;      /* flag to enable gravitation */
extern int    mcdotrace;          /* flag to print MCDISPLAY messages */
#else
mcstatic FILE *siminfo_file        = NULL;
#endif

/* I/O function prototypes ================================================== */

// from msysgit: https://code.google.com/p/msysgit/source/browse/compat/strcasestr.c
char *strcasestr(const char *haystack, const char *needle);

/* output functions */
MCDETECTOR mcdetector_out_0D(char *t, double p0, double p1, double p2, char *c, Coords pos, Rotation rot, int index);
MCDETECTOR mcdetector_out_1D(char *t, char *xl, char *yl,
                  char *xvar, double x1, double x2, long n,
                  double *p0, double *p1, double *p2, char *f, char *c, Coords pos, Rotation rot, int index);
MCDETECTOR mcdetector_out_2D(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2, long m,
                  long n, double *p0, double *p1, double *p2, char *f,
                  char *c, Coords pos, Rotation rot, int index);
MCDETECTOR mcdetector_out_list(char *t, char *xl, char *yl,
                  long m, long n,
                  double *p1, char *f,
	          char *c, Coords posa, Rotation rot,char* options, int index);

/* wrappers to output functions, that automatically set NAME and POSITION */
#define DETECTOR_OUT(p0,p1,p2) mcdetector_out_0D(NAME_CURRENT_COMP,p0,p1,p2,NAME_CURRENT_COMP,POS_A_CURRENT_COMP,ROT_A_CURRENT_COMP,INDEX_CURRENT_COMP)
#define DETECTOR_OUT_0D(t,p0,p1,p2) mcdetector_out_0D(t,p0,p1,p2,NAME_CURRENT_COMP,POS_A_CURRENT_COMP,ROT_A_CURRENT_COMP,INDEX_CURRENT_COMP)
#define DETECTOR_OUT_1D(t,xl,yl,xvar,x1,x2,n,p0,p1,p2,f) \
     mcdetector_out_1D(t,xl,yl,xvar,x1,x2,n,p0,p1,p2,f,NAME_CURRENT_COMP,POS_A_CURRENT_COMP,ROT_A_CURRENT_COMP,INDEX_CURRENT_COMP)
#define DETECTOR_OUT_2D(t,xl,yl,x1,x2,y1,y2,m,n,p0,p1,p2,f) \
     mcdetector_out_2D(t,xl,yl,x1,x2,y1,y2,m,n,p0,p1,p2,f,NAME_CURRENT_COMP,POS_A_CURRENT_COMP,ROT_A_CURRENT_COMP,INDEX_CURRENT_COMP)

#ifdef USE_NEXUS
#include "napi.h"
NXhandle nxhandle;
#endif

#endif /* ndef MCCODE_R_IO_H */

#endif /* MCCODE_R_H */
/* End of file "mccode-r.h". */

/* embedding file "mcstas-r.h" */

/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mcstas-r.h
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McStas X.Y
* Version: $Revision$
*
* Runtime system header for McStas.
*
* In order to use this library as an external library, the following variables
* and macros must be declared (see details in the code)
*
*   struct mcinputtable_struct mcinputtable[];
*   int mcnumipar;
*   char instrument_name[], instrument_source[];
*   int traceenabled, defaultmain;
*   extern MCNUM  mccomp_storein[];
*   extern MCNUM  instrument.counter_AbsorbProp[];
*   extern MCNUM  mcScattered;
*   #define MCCODE_STRING "the McStas version"
*
* Usage: Automatically embbeded in the c code.
*
* $Id$
*
*******************************************************************************/

#ifndef MCSTAS_R_H
#define MCSTAS_R_H "$Revision$"

/* Following part is only embedded when not redundent with mcstas.h */

#ifndef MCCODE_H

#define AA2MS    629.622368        /* Convert k[1/AA] to v[m/s] */
#define MS2AA    1.58825361e-3     /* Convert v[m/s] to k[1/AA] */
#define K2V      AA2MS
#define V2K      MS2AA
#define Q2V      AA2MS
#define V2Q      MS2AA
#define SE2V     437.393377        /* Convert sqrt(E)[meV] to v[m/s] */
#define VS2E     5.22703725e-6     /* Convert (v[m/s])**2 to E[meV] */

#define SCATTER0 do {DEBUG_SCATTER(); SCATTERED++;} while(0)
#define SCATTER SCATTER0

#define JUMPTOCOMP(comp) mcneutron->_index = INDEX_COMP(comp);

#define MAGNET_ON \
  do { \
    mcMagnet = 1; \
  } while(0)

#define MAGNET_OFF \
  do { \
    mcMagnet = 0; \
  } while(0)

#define ALLOW_BACKPROP \
  do { \
    allow_backprop = 1; \
  } while(0)

#define DISALLOW_BACKPROP \
  do { \
    allow_backprop = 0; \
  } while(0)

#define PROP_MAGNET(dt) \
  do { \
  } while (0)
    /* change coordinates from local system to magnet system */
/*    Rotation rotLM, rotTemp; \
      Coords   posLM = coords_sub(POS_A_CURRENT_COMP, mcMagnetPos); \
      rot_transpose(ROT_A_CURRENT_COMP, rotTemp); \
      rot_mul(rotTemp, mcMagnetRot, rotLM); \
      mcMagnetPrecession(x, y, z, t, vx, vy, vz, \
               &sx, &sy, &sz, dt, posLM, rotLM); \
      } while(0)
*/

#define mcPROP_DT(dt) \
  do { \
    if (mcMagnet && dt > 0) PROP_MAGNET(dt);\
    x += vx*(dt); \
    y += vy*(dt); \
    z += vz*(dt); \
    t += (dt); \
    if (isnan(p) || isinf(p)) { ABSORB; }\
  } while(0)

/* ADD: E. Farhi, Aug 6th, 2001 PROP_GRAV_DT propagation with acceleration */
#define PROP_GRAV_DT(dt, Ax, Ay, Az) \
  do { \
    if(dt < 0 && allow_backprop == 0) { ABSORB; }\
    if (mcMagnet) /*printf("Spin precession gravity\n")*/; \
    x  += vx*(dt) + (Ax)*(dt)*(dt)/2; \
    y  += vy*(dt) + (Ay)*(dt)*(dt)/2; \
    z  += vz*(dt) + (Az)*(dt)*(dt)/2; \
    vx += (Ax)*(dt); \
    vy += (Ay)*(dt); \
    vz += (Az)*(dt); \
    t  += (dt); \
    DISALLOW_BACKPROP;\
  } while(0)


#define PROP_DT(dt) \
  do { \
    if(dt < 0 && allow_backprop == 0) { RESTORE=1; ABSORB; }; \
    if (mcgravitation) { Coords mcLocG; double mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    PROP_GRAV_DT(dt, mc_gx, mc_gy, mc_gz); } \
    else mcPROP_DT(dt); \
    DISALLOW_BACKPROP;\
  } while(0)


#define PROP_Z0 \
  do { \
    if (mcgravitation) { Coords mcLocG; int mc_ret; \
    double mc_dt, mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    mc_ret = solve_2nd_order(&mc_dt, NULL, -mc_gz/2, -vz, -z); \
    if (mc_ret) {PROP_GRAV_DT(mc_dt, mc_gx, mc_gy, mc_gz); z=0;}\
    else if (allow_backprop == 0 && mc_dt < 0) { ABSORB; }; } \
    else mcPROP_Z0; \
    DISALLOW_BACKPROP;\
  } while(0)

#define mcPROP_Z0 \
  do { \
    double mc_dt; \
    if(vz == 0) { ABSORB; }; \
    mc_dt = -z/vz; \
    if(mc_dt < 0 && allow_backprop == 0) { ABSORB; }; \
    mcPROP_DT(mc_dt); \
    z = 0; \
    DISALLOW_BACKPROP;\
  } while(0)

#define PROP_X0 \
  do { \
    if (mcgravitation) { Coords mcLocG; int mc_ret; \
    double mc_dt, mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    mc_ret = solve_2nd_order(&mc_dt, NULL, -mc_gx/2, -vx, -x); \
    if (mc_ret) {PROP_GRAV_DT(mc_dt, mc_gx, mc_gy, mc_gz); x=0;}\
    else if (allow_backprop == 0 && mc_dt < 0) { ABSORB; }; } \
    else mcPROP_X0; \
    DISALLOW_BACKPROP;\
  } while(0)

#define mcPROP_X0 \
  do { \
    double mc_dt; \
    if(vx == 0) { ABSORB; }; \
    mc_dt = -x/vx; \
    if(mc_dt < 0 && allow_backprop == 0) { ABSORB; }; \
    mcPROP_DT(mc_dt); \
    x = 0; \
    DISALLOW_BACKPROP;\
  } while(0)

#define PROP_Y0 \
  do { \
    if (mcgravitation) { Coords mcLocG; int mc_ret; \
    double mc_dt, mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    mc_ret = solve_2nd_order(&mc_dt, NULL, -mc_gy/2, -vy, -y); \
    if (mc_ret) {PROP_GRAV_DT(mc_dt, mc_gx, mc_gy, mc_gz); y=0;}\
    else if (allow_backprop == 0 && mc_dt < 0) { ABSORB; }; } \
    else mcPROP_Y0; \
    DISALLOW_BACKPROP;\
  } while(0)


#define mcPROP_Y0 \
  do { \
    double mc_dt; \
    if(vy == 0) { ABSORB; }; \
    mc_dt = -y/vy; \
    if(mc_dt < 0 && allow_backprop == 0) { ABSORB; }; \
    mcPROP_DT(mc_dt); \
    y = 0; \
    DISALLOW_BACKPROP; \
  } while(0)


#ifdef DEBUG

#define DEBUG_STATE() if(!mcdotrace); else \
  printf("STATE: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
         x,y,z,vx,vy,vz,t,sx,sy,sz,p);
#define DEBUG_SCATTER() if(!mcdotrace); else \
  printf("SCATTER: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
         x,y,z,vx,vy,vz,t,sx,sy,sz,p);

#else

#define DEBUG_STATE()
#define DEBUG_SCATTER()

#endif

#endif /* !MCCODE_H */

#endif /* MCSTAS_R_H */
/* End of file "mcstas-r.h". */

/* embedding file "mccode-r.c" */

/*******************************************************************************
*
* McCode, neutron/xray ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mccode-r.c
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McStas X.Y/McXtrace X.Y
* Version: $Revision$
*
* Runtime system for McStas and McXtrace.
* Embedded within instrument in runtime mode.
* Contains SECTIONS:
*   MPI handling (sum, send, recv)
*   format definitions
*   I/O
*   mcdisplay support
*   random numbers
*   coordinates handling
*   vectors math (solve 2nd order, normals, randvec...)
*   parameter handling
*   signal and main handlers
*
* Usage: Automatically embbeded in the c code whenever required.
*
* $Id$
*
*******************************************************************************/

/*******************************************************************************
* The I/O format definitions and functions
*******************************************************************************/


/** Include header files to avoid implicit declarations (not allowed on LLVM) */
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

// UNIX specific headers (non-Windows)
#if defined(__unix__) || defined(__APPLE__)
#include <unistd.h>
#include <sys/stat.h>
#endif


#ifndef DANSE
#ifdef MC_ANCIENT_COMPATIBILITY
int traceenabled = 0;
int defaultmain  = 0;
#endif
/* else defined directly in the McCode generated C code */

static   long mcseed                 = 0; /* seed for random generator */
#pragma acc declare create ( mcseed )
static   long mcstartdate            = 0; /* start simulation time */
static   int  mcdisable_output_files = 0; /* --no-output-files */
mcstatic int  mcgravitation          = 0; /* use gravitation flag, for PROP macros */
mcstatic int  mcusedefaults          = 0; /* assume default value for all parameters */
mcstatic int  mcappend               = 0; /* flag to allow append mode on datasets/directories */
mcstatic int  mcdotrace              = 0; /* flag for --trace and messages for DISPLAY */
mcstatic int  mcnexus_embed_idf      = 0; /* flag to embed xml-formatted IDF file for Mantid */
#pragma acc declare create ( mcdotrace )
int      mcallowbackprop             = 0;         /* flag to enable negative/backprop */

/* OpenACC-related segmentation parameters: */
int vecsize = 128;
int numgangs = 7813;
long gpu_innerloop = 2147483647;

/* Monitor_nD list/buffer-size default */
/* Starting value may be defined using -DND_BUFFER=N */
/* Can further be controlled dynamically using --bufsiz input */
long MONND_BUFSIZ = 10000000;
#ifdef ND_BUFFER
MONND_BUFSIZ = ND_BUFFER;
#endif
 

/* Number of particle histories to simulate. */
#ifdef NEUTRONICS
mcstatic unsigned long long int mcncount             = 1;
mcstatic unsigned long long int mcrun_num            = 0;
#else
#ifdef MCDEFAULT_NCOUNT
mcstatic unsigned long long int mcncount             = MCDEFAULT_NCOUNT;
#else
mcstatic unsigned long long int mcncount             = 1000000;
#endif
#pragma acc declare create ( mcncount )
mcstatic unsigned long long int mcrun_num            = 0;
#pragma acc declare create ( mcrun_num )
#endif /* NEUTRONICS */

#else
#include "mcstas-globals.h"
#endif /* !DANSE */

#ifndef NX_COMPRESSION
#define NX_COMPRESSION NX_COMP_NONE
#endif

/* String nullification on GPU and other replacements */
#ifdef OPENACC
int noprintf() {
  return 0;
}

int str_comp(char *str1, char *str2) {
  while (*str1 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return (*str1 - *str2);
}

size_t str_len(const char *s)
{
  size_t len = 0;
  if(s != NULL)
  {
    while(*s != '\0')
    {
      ++len;
      ++s;
    }
  }
  return len;
}

#endif

/* SECTION: Predefine (component) parameters ================================= */

int nans_match(double a, double b){
  return (*(uint64_t*)&a == *(uint64_t*)&b);
}
int is_unset(double x){
  return nans_match(x, UNSET);
}
int is_set(double x){
  return !nans_match(x, UNSET);
}
int is_valid(double x){
  return !isnan(x)||is_unset(x);
}
int all_unset(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=1;
  for (int i=0; i<n; ++i) if(is_set(va_arg(ptr, double))) ret=0;
  va_end(ptr);
  return ret;
}
int all_set(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=1;
  for (int i=0; i<n; ++i) if(is_unset(va_arg(ptr, double))) ret=0;
  va_end(ptr);
  return ret;
}
int any_unset(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=0;
  for (int i=0; i<n; ++i) if(is_unset(va_arg(ptr, double))) ret=1;
  va_end(ptr);
  return ret;
}
int any_set(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=0;
  for (int i=0; i<n; ++i) if(is_set(va_arg(ptr, double))) ret=1;
  va_end(ptr);
  return ret;
}


/* SECTION: Dynamic Arrays ================================================== */
IArray1d create_iarr1d(int n){
  IArray1d arr1d;
  arr1d = calloc(n, sizeof(int));
  if (!arr1d) {
    fprintf(stderr, "Error allocating IArray1d of dimension %i\n",n);
    exit(-1);
  }
  return arr1d;
}

void destroy_iarr1d(IArray1d a){
  free(a);
}

IArray2d create_iarr2d(int nx, int ny){
  IArray2d arr2d;
  arr2d = calloc(nx, sizeof(int *));
  if (!arr2d) {
    fprintf(stderr, "Error allocating IArray2d of dimension %i x %i\n",nx,ny);
    exit(-1);
  }

  int *p1;
  p1 = calloc(nx*ny, sizeof(int));

  if (!p1) {
    fprintf(stderr, "Error allocating int* array of dimension %i\n",nx*ny);
    exit(-1);
  }
  
  int i;
  for (i=0; i<nx; i++){
    arr2d[i] = &(p1[i*ny]);
  }
  return arr2d;
}

void destroy_iarr2d(IArray2d a){
  free(a[0]);
  free(a);
}

IArray3d create_iarr3d(int nx, int ny, int nz){
  IArray3d arr3d;
  int i, j;

  // 1d
  arr3d = calloc(nx, sizeof(int **));
  if (!arr3d) {
    fprintf(stderr, "Error allocating IArray3d of dimension %i x %i x %i\n",nx,ny,nz);
    exit(-1);
  }

  // d2
  int **p1;
  p1 = calloc(nx*ny, sizeof(int *));

  if (!p1) {
    fprintf(stderr, "Error allocating int** array of dimension %i\n",nx*ny);
    exit(-1);
  }
  
  for (i=0; i<nx; i++){
    arr3d[i] = &(p1[i*ny]);
  }

  // 3d
  int *p2;
  p2 = calloc(nx*ny*nz, sizeof(int));
  if (!p2) {
    fprintf(stderr, "Error allocating int* array of dimension %i\n",nx*ny*nz);
    exit(-1);
  }
  for (i=0; i<nx; i++){
    for (j=0; j<ny; j++){
      arr3d[i][j] = &(p2[(i*ny+j)*nz]);
    }
  }
  return arr3d;
}

void destroy_iarr3d(IArray3d a){
  free(a[0][0]);
  free(a[0]);
  free(a);
}

DArray1d create_darr1d(int n){
  DArray1d arr1d;
  arr1d = calloc(n, sizeof(double));
  if (!arr1d) {
    fprintf(stderr, "Error allocating DArray1d of dimension %i\n",n);
    exit(-1);
  }
  return arr1d;
}

void destroy_darr1d(DArray1d a){
  free(a);
}

DArray2d create_darr2d(int nx, int ny){
  DArray2d arr2d;
  arr2d = calloc(nx, sizeof(double *));
  if (!arr2d) {
    fprintf(stderr, "Error allocating DArray2d of dimension %i x %i\n",nx,ny);
    exit(-1);
  }
  double *p1;
  p1 = calloc(nx*ny, sizeof(double));
  if (!p1) {
    fprintf(stderr, "Error allocating double* array of dimension %i\n",nx*ny);
    exit(-1);
  }
  int i;
  for (i=0; i<nx; i++){
    arr2d[i] = &(p1[i*ny]);
  }
  return arr2d;
}

void destroy_darr2d(DArray2d a){
  free(a[0]);
  free(a);
}

DArray3d create_darr3d(int nx, int ny, int nz){
  DArray3d arr3d;

  int i, j;

  // 1d
  arr3d = calloc(nx, sizeof(double **));
  if (!arr3d) {
    fprintf(stderr, "Error allocating DArray3d of dimension %i x %i x %i\n",nx,ny,nz);
    exit(-1);
  }
  // d2
  double **p1;
  p1 = calloc(nx*ny, sizeof(double *));
  if (!p1) {
    fprintf(stderr, "Error allocating double** array of dimension %i\n",nx*ny);
    exit(-1);
  }
  for (i=0; i<nx; i++){
    arr3d[i] = &(p1[i*ny]);
  }

  // 3d
  double *p2;
  p2 = calloc(nx*ny*nz, sizeof(double));
  if (!p2) {
    fprintf(stderr, "Error allocating double* array of dimension %i\n",nx*ny*nz);
    exit(-1);
  }
  for (i=0; i<nx; i++){
    for (j=0; j<ny; j++){
      arr3d[i][j] = &(p2[(i*ny+j)*nz]);
    }
  }
  return arr3d;
}

void destroy_darr3d(DArray3d a){
  free(a[0][0]);
  free(a[0]);
  free(a);
}


/* SECTION: MPI handling ==================================================== */

#ifdef USE_MPI
/* MPI rank */
static int mpi_node_rank;
static int mpi_node_root = 0;


/*******************************************************************************
* mc_MPI_Reduce: Gathers arrays from MPI nodes using Reduce function.
*******************************************************************************/
int mc_MPI_Sum(double *sbuf, long count)
{
  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to reduce */
  else {
    /* we must cut the buffer into blocks not exceeding the MPI max buffer size of 32000 */
    long   offset=0;
    double *rbuf=NULL;
    int    length=MPI_REDUCE_BLOCKSIZE; /* defined in mccode-r.h */
    int    i=0;
    rbuf = calloc(count, sizeof(double));
    if (!rbuf)
      exit(-fprintf(stderr, "Error: Out of memory %zi (mc_MPI_Sum)\n", count*sizeof(double)));
    while (offset < count) {
      if (!length || offset+length > count-1) length=count-offset;
      else length=MPI_REDUCE_BLOCKSIZE;
      if (MPI_Allreduce((double*)(sbuf+offset), (double*)(rbuf+offset),
              length, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD) != MPI_SUCCESS)
        return MPI_ERR_COUNT;
      offset += length;
    }

    for (i=0; i<count; i++) sbuf[i] = rbuf[i];
    free(rbuf);
  }
  return MPI_SUCCESS;
} /* mc_MPI_Sum */

/*******************************************************************************
* mc_MPI_Send: Send array to MPI node by blocks to avoid buffer limit
*******************************************************************************/
int mc_MPI_Send(void *sbuf,
                  long count, MPI_Datatype dtype,
                  int dest)
{
  int dsize;
  long offset=0;
  int  tag=1;
  int  length=MPI_REDUCE_BLOCKSIZE; /* defined in mccode-r.h */

  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to send */
  MPI_Type_size(dtype, &dsize);

  while (offset < count) {
    if (offset+length > count-1) length=count-offset;
    else length=MPI_REDUCE_BLOCKSIZE;
    if (MPI_Send((void*)((char*)sbuf+offset*dsize), length, dtype, dest, tag++, MPI_COMM_WORLD) != MPI_SUCCESS)
      return MPI_ERR_COUNT;
    offset += length;
  }

  return MPI_SUCCESS;
} /* mc_MPI_Send */

/*******************************************************************************
* mc_MPI_Recv: Receives arrays from MPI nodes by blocks to avoid buffer limit
*             the buffer must have been allocated previously.
*******************************************************************************/
int mc_MPI_Recv(void *sbuf,
                  long count, MPI_Datatype dtype,
                  int source)
{
  int dsize;
  long offset=0;
  int  tag=1;
  int  length=MPI_REDUCE_BLOCKSIZE; /* defined in mccode-r.h */

  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to recv */
  MPI_Type_size(dtype, &dsize);

  while (offset < count) {
    if (offset+length > count-1) length=count-offset;
    else length=MPI_REDUCE_BLOCKSIZE;
    if (MPI_Recv((void*)((char*)sbuf+offset*dsize), length, dtype, source, tag++,
            MPI_COMM_WORLD, MPI_STATUS_IGNORE) != MPI_SUCCESS)
      return MPI_ERR_COUNT;
    offset += length;
  }

  return MPI_SUCCESS;
} /* mc_MPI_Recv */

#endif /* USE_MPI */

/* SECTION: parameters handling ============================================= */

/* Instrument input parameter type handling. */
/*******************************************************************************
* mcparm_double: extract double value from 's' into 'vptr'
*******************************************************************************/
static int
mcparm_double(char *s, void *vptr)
{
  char *p;
  double *v = (double *)vptr;

  if (!s) { *v = 0; return(1); }
  *v = strtod(s, &p);
  if(*s == '\0' || (p != NULL && *p != '\0') || errno == ERANGE)
    return 0;                        /* Failed */
  else
    return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_double: display parameter type double
*******************************************************************************/
static char *
mcparminfo_double(char *parmname)
{
  return "double";
}

/*******************************************************************************
* mcparmerror_double: display error message when failed extract double
*******************************************************************************/
static void
mcparmerror_double(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for floating point parameter %s (mcparmerror_double)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_double: convert double to string
*******************************************************************************/
static void
mcparmprinter_double(char *f, void *vptr)
{
  double *v = (double *)vptr;
  sprintf(f, "%g", *v);
}

/*******************************************************************************
* mcparm_int: extract int value from 's' into 'vptr'
*******************************************************************************/
static int
mcparm_int(char *s, void *vptr)
{
  char *p;
  int *v = (int *)vptr;
  long x;

  if (!s) { *v = 0; return(1); }
  *v = 0;
  x = strtol(s, &p, 10);
  if(x < INT_MIN || x > INT_MAX)
    return 0;                        /* Under/overflow */
  *v = x;
  if(*s == '\0' || (p != NULL && *p != '\0') || errno == ERANGE)
    return 0;                        /* Failed */
  else
    return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_int: display parameter type int
*******************************************************************************/
static char *
mcparminfo_int(char *parmname)
{
  return "int";
}

/*******************************************************************************
* mcparmerror_int: display error message when failed extract int
*******************************************************************************/
static void
mcparmerror_int(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for integer parameter %s (mcparmerror_int)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_int: convert int to string
*******************************************************************************/
static void
mcparmprinter_int(char *f, void *vptr)
{
  int *v = (int *)vptr;
  sprintf(f, "%d", *v);
}

/*******************************************************************************
* mcparm_string: extract char* value from 's' into 'vptr' (copy)
*******************************************************************************/
static int
mcparm_string(char *s, void *vptr)
{
  char **v = (char **)vptr;
  if (!s) { *v = NULL; return(1); }
  *v = (char *)malloc(strlen(s) + 1);
  if(*v == NULL)
  {
    exit(-fprintf(stderr, "Error: Out of memory %li (mcparm_string).\n", (long)strlen(s) + 1));
  }
  strcpy(*v, s);
  return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_string: display parameter type string
*******************************************************************************/
static char *
mcparminfo_string(char *parmname)
{
  return "string";
}

/*******************************************************************************
* mcparmerror_string: display error message when failed extract string
*******************************************************************************/
static void
mcparmerror_string(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for string parameter %s (mcparmerror_string)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_string: convert string to string (including esc chars)
*******************************************************************************/
static void
mcparmprinter_string(char *f, void *vptr)
{
  char **v = (char **)vptr;
  char *p;

  if (!*v) { *f='\0'; return; }
  strcpy(f, "");
  for(p = *v; *p != '\0'; p++)
  {
    switch(*p)
    {
      case '\n':
        strcat(f, "\\n");
        break;
      case '\r':
        strcat(f, "\\r");
        break;
      case '"':
        strcat(f, "\\\"");
        break;
      case '\\':
        strcat(f, "\\\\");
        break;
      default:
        strncat(f, p, 1);
    }
  }
  /* strcat(f, "\""); */
} /* mcparmprinter_string */

/* now we may define the parameter structure, using previous functions */
static struct
  {
    int (*getparm)(char *, void *);
    char * (*parminfo)(char *);
    void (*error)(char *, char *);
    void (*printer)(char *, void *);
} mcinputtypes[] = {
  {
    mcparm_int, mcparminfo_int, mcparmerror_int,
    mcparmprinter_int
  }, {
    mcparm_string, mcparminfo_string, mcparmerror_string,
    mcparmprinter_string
  }, {
    mcparm_string, mcparminfo_string, mcparmerror_string,
    mcparmprinter_string
  }, {
    mcparm_double, mcparminfo_double, mcparmerror_double,
    mcparmprinter_double
  }, {
    mcparm_double, mcparminfo_double, mcparmerror_double,
    mcparmprinter_double
  }
};

/*******************************************************************************
* mcestimate_error: compute sigma from N,p,p2 in Gaussian large numbers approx
*******************************************************************************/
double mcestimate_error(double N, double p1, double p2)
{
  double pmean, n1;
  if(N <= 1)
    return p1;
  pmean = p1 / N;
  n1 = N - 1;
  /* Note: underflow may cause p2 to become zero; the fabs() below guards
     against this. */
  return sqrt((N/n1)*fabs(p2 - pmean*pmean));
}

double (*mcestimate_error_p)
  (double V2, double psum, double p2sum)=mcestimate_error;

/* ========================================================================== */

/*                               MCCODE_R_IO_C                                */

/* ========================================================================== */

#ifndef MCCODE_R_IO_C
#define MCCODE_R_IO_C "$Revision$"

/* SECTION: file i/o handling ================================================ */

#ifndef HAVE_STRCASESTR
// from msysgit: https://code.google.com/p/msysgit/source/browse/compat/strcasestr.c
char *strcasestr(const char *haystack, const char *needle)
{
  int nlen = strlen(needle);
  int hlen = strlen(haystack) - nlen + 1;
  int i;

  for (i = 0; i < hlen; i++) {
    int j;
    for (j = 0; j < nlen; j++) {
            unsigned char c1 = haystack[i+j];
            unsigned char c2 = needle[j];
            if (toupper(c1) != toupper(c2))
                    goto next;
    }
    return (char *) haystack + i;
  next:
    ;
  }
  return NULL;
}


#endif
#ifndef HAVE_STRCASECMP
int strcasecmp( const char *s1, const char *s2 )
{
  int c1, c2;
  do {
    c1 = tolower( (unsigned char) *s1++ );
    c2 = tolower( (unsigned char) *s2++ );
  } while (c1 == c2 && c1 != 0);
  return c2 > c1 ? -1 : c1 > c2;
}
#endif

#ifndef STRACPY
/* this is a replacement to strncpy, but ensures that the copy ends with NULL */
/* http://stracpy.blogspot.fr/2011/04/stracpy-strncpy-replacement.html */
#define STRACPY
char *stracpy(char *destination, const char *source, size_t amount)
{
        if (!destination || !source || !amount) return(NULL);
        while(amount--)
          if((*destination++ = *source++) == '\0') break;
        *destination = '\0';
        return destination;
}
#endif

/*******************************************************************************
* mcfull_file: allocates a full file name=dirname+file. Catenate extension if missing.
*******************************************************************************/
char *mcfull_file(char *name, char *ext)
{
  int   dirlen=0;
  char *mem   =NULL;

  dirlen = dirname ? strlen(dirname) : 0;
  mem = (char*)malloc(dirlen + strlen(name) + CHAR_BUF_LENGTH);
  if(!mem) {
    exit(-fprintf(stderr, "Error: Out of memory %li (mcfull_file)\n", (long)(dirlen + strlen(name) + 256)));
  }
  strcpy(mem, "");

  /* prepend directory name to path if name does not contain a path */
  if (dirlen > 0 && !strchr(name, MC_PATHSEP_C)) {
    strcat(mem, dirname);
    strcat(mem, MC_PATHSEP_S);
  } /* dirlen */

  strcat(mem, name);
  if (!strchr(name, '.') && ext && strlen(ext))
  { /* add extension if not in file name already */
    strcat(mem, ".");
    strcat(mem, ext);
  }
  return(mem);
} /* mcfull_file */

/*******************************************************************************
* mcnew_file: opens a new file within dirname if non NULL
*             the file is opened in "a" (append, create if does not exist)
*             the extension 'ext' is added if the file name does not include one.
*             the last argument is set to 0 if file did not exist, else to 1.
*******************************************************************************/
FILE *mcnew_file(char *name, char *ext, int *exists)
{
  char *mem;
  FILE *file=NULL;

  if (!name || strlen(name) == 0 || mcdisable_output_files) return(NULL);

  mem  = mcfull_file(name, ext); /* create dirname/name.ext */

  /* check for existence */
  file = fopen(mem, "r"); /* for reading -> fails if does not exist */
  if (file) {
    fclose(file);
    *exists=1;
  } else
    *exists=0;

  /* open the file for writing/appending */
#ifdef USE_NEXUS
  if (mcformat && strcasestr(mcformat, "NeXus")) {
    /* NXhandle nxhandle is defined in the .h with USE_NEXUS */
    NXaccess mode = (*exists ? NXACC_CREATE5 | NXACC_RDWR : NXACC_CREATE5);

    if (NXopen(mem, mode, &nxhandle) != NX_OK)
      file = NULL;
    else
      file = (FILE*)&nxhandle; /* to make it non NULL */
  } else
#endif
    file = fopen(mem, "a+");

  if(!file)
    fprintf(stderr, "Warning: could not open output file '%s' for %s (mcnew_file)\n",
      mem, *exists ? "append" : "create");
  free(mem);

  return file;
} /* mcnew_file */

/*******************************************************************************
* mcdetector_statistics: compute detector statistics, error bars, [x I I_err N] 1D
* RETURN:            updated detector structure
* Used by: detector_import
*******************************************************************************/
MCDETECTOR mcdetector_statistics(
  MCDETECTOR detector)
{

  if (!detector.p1 || !detector.m)
    return(detector);

  /* compute statistics and update MCDETECTOR structure ===================== */
  double sum_z  = 0, min_z  = 0, max_z  = 0;
  double fmon_x =0,  smon_x = 0, fmon_y =0, smon_y=0, mean_z=0;
  double Nsum=0, P2sum=0;

  double sum_xz = 0, sum_yz = 0, sum_x = 0, sum_y = 0, sum_x2z = 0, sum_y2z = 0;
  int    i,j;
  char   hasnan=0, hasinf=0;
  char   israw = ((char*)strcasestr(detector.format,"raw") != NULL);
  double *this_p1=NULL; /* new 1D McCode array [x I E N]. Freed after writing data */

  /* if McCode/PGPLOT and rank==1 we create a new m*4 data block=[x I E N] */
  if (detector.rank == 1 && strcasestr(detector.format,"McCode")) {
    this_p1 = (double *)calloc(detector.m*detector.n*detector.p*4, sizeof(double));
    if (!this_p1)
      exit(-fprintf(stderr, "Error: Out of memory creating %zi 1D " MCCODE_STRING " data set for file '%s' (detector_import)\n",
        detector.m*detector.n*detector.p*4*sizeof(double*), detector.filename));
  }

  max_z = min_z = detector.p1[0];

  /* compute sum and moments (not for lists) */
  if (!strcasestr(detector.format,"list") && detector.m)
  for(j = 0; j < detector.n*detector.p; j++)
  {
    for(i = 0; i < detector.m; i++)
    {
      double x,y,z;
      double N, E;
      long   index= !detector.istransposed ? i*detector.n*detector.p + j : i+j*detector.m;
      char   hasnaninf=0;

      if (detector.m)
        x = detector.xmin + (i + 0.5)/detector.m*(detector.xmax - detector.xmin);
      else x = 0;
      if (detector.n && detector.p)
        y = detector.ymin + (j + 0.5)/detector.n/detector.p*(detector.ymax - detector.ymin);
      else y = 0;
      z = detector.p1[index];
      N = detector.p0 ? detector.p0[index] : 1;
      E = detector.p2 ? detector.p2[index] : 0;
      if (detector.p2 && !israw)
        detector.p2[index] = (*mcestimate_error_p)(detector.p0[index],detector.p1[index],detector.p2[index]); /* set sigma */

      if (detector.rank == 1 && this_p1 && strcasestr(detector.format,"McCode")) {
        /* fill-in 1D McCode array [x I E N] */
        this_p1[index*4]   = x;
        this_p1[index*4+1] = z;
        this_p1[index*4+2] = detector.p2 ? detector.p2[index] : 0;
        this_p1[index*4+3] = N;
      }

      if (isnan(z) || isnan(E) || isnan(N)) hasnaninf=hasnan=1;
      if (isinf(z) || isinf(E) || isinf(N)) hasnaninf=hasinf=1;

      /* compute stats integrals */
      if (!hasnaninf) {
        sum_xz += x*z;
        sum_yz += y*z;
        sum_x  += x;
        sum_y  += y;
        sum_z  += z;
        sum_x2z += x*x*z;
        sum_y2z += y*y*z;
        if (z > max_z) max_z = z;
        if (z < min_z) min_z = z;

        Nsum += N;
        P2sum += E;
      }

    }
  } /* for j */

  /* compute 1st and 2nd moments. For lists, sum_z=0 so this is skipped. */
  if (sum_z && detector.n*detector.m*detector.p)
  {
    fmon_x = sum_xz/sum_z;
    fmon_y = sum_yz/sum_z;
    smon_x = sum_x2z/sum_z-fmon_x*fmon_x; smon_x = smon_x > 0 ? sqrt(smon_x) : 0;
    smon_y = sum_y2z/sum_z-fmon_y*fmon_y; smon_y = smon_y > 0 ? sqrt(smon_y) : 0;
    mean_z = sum_z/detector.n/detector.m/detector.p;
  }
  /* store statistics into detector */
  detector.intensity = sum_z;
  detector.error     = Nsum ? (*mcestimate_error_p)(Nsum, sum_z, P2sum) : 0;
  detector.events    = Nsum;
  detector.min       = min_z;
  detector.max       = max_z;
  detector.mean      = mean_z;
  detector.centerX   = fmon_x;
  detector.halfwidthX= smon_x;
  detector.centerY   = fmon_y;
  detector.halfwidthY= smon_y;

  /* if McCode/PGPLOT and rank==1 replace p1 with new m*4 1D McCode and clear others */
  if (detector.rank == 1 && this_p1 && strcasestr(detector.format,"McCode")) {

    detector.p1 = this_p1;
    detector.n  = detector.m; detector.m  = 4;
    detector.p0 = detector.p2 = NULL;
    detector.istransposed = 1;
  }

  if (detector.n*detector.m*detector.p > 1)
    snprintf(detector.signal, CHAR_BUF_LENGTH,
      "Min=%g; Max=%g; Mean=%g;", detector.min, detector.max, detector.mean);
  else
    strcpy(detector.signal, "None");
  snprintf(detector.values, CHAR_BUF_LENGTH,
    "%g %g %g", detector.intensity, detector.error, detector.events);

  switch (detector.rank) {
    case 1:  snprintf(detector.statistics, CHAR_BUF_LENGTH, "X0=%g; dX=%g;",
      detector.centerX, detector.halfwidthX); break;
    case 2:
    case 3:  snprintf(detector.statistics, CHAR_BUF_LENGTH, "X0=%g; dX=%g; Y0=%g; dY=%g;",
      detector.centerX, detector.halfwidthX, detector.centerY, detector.halfwidthY);
      break;
    default: strcpy(detector.statistics, "None");
  }

  if (hasnan)
    printf("WARNING: Nan detected in component/file %s %s\n",
      detector.component, strlen(detector.filename) ? detector.filename : "");
  if (hasinf)
    printf("WARNING: Inf detected in component/file %s %s\n",
      detector.component, strlen(detector.filename) ? detector.filename : "");

  return(detector);

} /* mcdetector_statistics */

/*******************************************************************************
* detector_import: build detector structure, merge non-lists from MPI
*                    compute basic stat, write "Detector:" line
* RETURN:            detector structure. Invalid data if detector.p1 == NULL
*                    Invalid detector sets m=0 and filename=""
*                    Simulation data  sets m=0 and filename=siminfo_name
* This function is equivalent to the old 'mcdetector_out', returning a structure
*******************************************************************************/
MCDETECTOR detector_import(
  char *format,
  char *component, char *title,
  long m, long n,  long p,
  char *xlabel, char *ylabel, char *zlabel,
  char *xvar, char *yvar, char *zvar,
  double x1, double x2, double y1, double y2, double z1, double z2,
  char *filename,
  double *p0, double *p1, double *p2,
  Coords position, Rotation rotation, int index)
{
  time_t t;       /* for detector.date */
  long   date_l;  /* date as a long number */
  char   istransposed=0;
  char   c[CHAR_BUF_LENGTH]; /* temp var for signal label */

  MCDETECTOR detector;

  /* build MCDETECTOR structure ============================================= */
  /* make sure we do not have NULL for char fields */

  /* these also apply to simfile */
  strncpy (detector.filename,  filename ? filename : "",        CHAR_BUF_LENGTH);
  strncpy (detector.format,    format   ? format   : "McCode" , CHAR_BUF_LENGTH);
  /* add extension if missing */
  if (strlen(detector.filename) && !strchr(detector.filename, '.'))
  { /* add extension if not in file name already */
    strcat(detector.filename, ".dat");
  }
  strncpy (detector.component, component ? component : MCCODE_STRING " component", CHAR_BUF_LENGTH);
  #ifdef USE_NEXUS
  char pref[5];
  if (index-1 < 10) {
    sprintf(pref,"000");
  } else if (index-1 < 100) {
    sprintf(pref,"00");
  } else if (index-1 < 1000) {
    sprintf(pref,"0");
  } else if (index-1 < 10000) {
    sprintf(pref,"");
  } else {
    fprintf(stderr,"Error, no support for > 10000 comps at the moment!\n");
    exit(-1);
  }
  sprintf(detector.nexuscomp,"%s%d_%s",pref,index-1,detector.component);
  #endif

  snprintf(detector.instrument, CHAR_BUF_LENGTH, "%s (%s)", instrument_name, instrument_source);
  snprintf(detector.user, CHAR_BUF_LENGTH,      "%s on %s",
        getenv("USER") ? getenv("USER") : MCCODE_NAME,
        getenv("HOST") ? getenv("HOST") : "localhost");
  time(&t);         /* get current write time */
  date_l = (long)t; /* same but as a long */
  snprintf(detector.date, CHAR_BUF_LENGTH, "%s", ctime(&t));
  if (strlen(detector.date))   detector.date[strlen(detector.date)-1] = '\0'; /* remove last \n in date */
  detector.date_l = date_l;

  if (!mcget_run_num() || mcget_run_num() >= mcget_ncount())
    snprintf(detector.ncount, CHAR_BUF_LENGTH, "%llu", mcget_ncount()
#ifdef USE_MPI
*mpi_node_count
#endif
  );
  else
    snprintf(detector.ncount, CHAR_BUF_LENGTH, "%g/%g", (double)mcget_run_num(), (double)mcget_ncount());

  detector.p0         = p0;
  detector.p1         = p1;
  detector.p2         = p2;

  /* handle transposition (not for NeXus) */
  if (!strcasestr(detector.format, "NeXus")) {
    if (m<0 || n<0 || p<0)             istransposed = !istransposed;
    if (strcasestr(detector.format, "transpose")) istransposed = !istransposed;
    if (istransposed) { /* do the swap once for all */
      long i=m; m=n; n=i;
    }
  }

  m=labs(m); n=labs(n); p=labs(p); /* make sure dimensions are positive */
  detector.istransposed = istransposed;

  /* determine detector rank (dimensionality) */
  if (!m || !n || !p || !p1) detector.rank = 4; /* invalid: exit with m=0 filename="" */
  else if (m*n*p == 1)       detector.rank = 0; /* 0D */
  else if (n == 1 || m == 1) detector.rank = 1; /* 1D */
  else if (p == 1)           detector.rank = 2; /* 2D */
  else                       detector.rank = 3; /* 3D */

  /* from rank, set type */
  switch (detector.rank) {
    case 0:  strcpy(detector.type,  "array_0d"); m=n=p=1; break;
    case 1:  snprintf(detector.type, CHAR_BUF_LENGTH, "array_1d(%ld)", m*n*p); m *= n*p; n=p=1; break;
    case 2:  snprintf(detector.type, CHAR_BUF_LENGTH, "array_2d(%ld, %ld)", m, n*p); n *= p; p=1; break;
    case 3:  snprintf(detector.type, CHAR_BUF_LENGTH, "array_3d(%ld, %ld, %ld)", m, n, p); break;
    default: m=0; strcpy(detector.type, ""); strcpy(detector.filename, "");/* invalid */
  }

  detector.m    = m;
  detector.n    = n;
  detector.p    = p;

  /* these only apply to detector files ===================================== */

  detector.Position[0]=position.x;
  detector.Position[1]=position.y;
  detector.Position[2]=position.z;
  rot_copy(detector.Rotation,rotation);
  snprintf(detector.position, CHAR_BUF_LENGTH, "%g %g %g", position.x, position.y, position.z);
  /* may also store actual detector orientation in the future */

  strncpy(detector.title,      title && strlen(title) ? title : component,       CHAR_BUF_LENGTH);
  strncpy(detector.xlabel,     xlabel && strlen(xlabel) ? xlabel : "X", CHAR_BUF_LENGTH); /* axis labels */
  strncpy(detector.ylabel,     ylabel && strlen(ylabel) ? ylabel : "Y", CHAR_BUF_LENGTH);
  strncpy(detector.zlabel,     zlabel && strlen(zlabel) ? zlabel : "Z", CHAR_BUF_LENGTH);
  strncpy(detector.xvar,       xvar && strlen(xvar) ? xvar :       "x", CHAR_BUF_LENGTH); /* axis variables */
  strncpy(detector.yvar,       yvar && strlen(yvar) ? yvar :       detector.xvar, CHAR_BUF_LENGTH);
  strncpy(detector.zvar,       zvar && strlen(zvar) ? zvar :       detector.yvar, CHAR_BUF_LENGTH);

  /* set "variables" as e.g. "I I_err N" */
  strcpy(c, "I ");
  if (strlen(detector.zvar))      strncpy(c, detector.zvar,32);
  else if (strlen(detector.yvar)) strncpy(c, detector.yvar,32);
  else if (strlen(detector.xvar)) strncpy(c, detector.xvar,32);

  if (detector.rank == 1)
    snprintf(detector.variables, CHAR_BUF_LENGTH, "%s %s %s_err N", detector.xvar, c, c);
  else
    snprintf(detector.variables, CHAR_BUF_LENGTH, "%s %s_err N", c, c);

  /* limits */
  detector.xmin = x1;
  detector.xmax = x2;
  detector.ymin = y1;
  detector.ymax = y2;
  detector.zmin = z1;
  detector.zmax = z2;
  if (abs(detector.rank) == 1)
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g", x1, x2);
  else if (detector.rank == 2)
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g %g %g", x1, x2, y1, y2);
  else
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g %g %g %g %g", x1, x2, y1, y2, z1, z2);

  /* if MPI and nodes_nb > 1: reduce data sets when using MPI =============== */
#ifdef USE_MPI
  if (!strcasestr(detector.format,"list") && mpi_node_count > 1 && m) {
    /* we save additive data: reduce everything into mpi_node_root */
    if (p0) mc_MPI_Sum(p0, m*n*p);
    if (p1) mc_MPI_Sum(p1, m*n*p);
    if (p2) mc_MPI_Sum(p2, m*n*p);
    if (!p0) {  /* additive signal must be then divided by the number of nodes */
      int i;
      for (i=0; i<m*n*p; i++) {
        p1[i] /= mpi_node_count;
        if (p2) p2[i] /= mpi_node_count;
      }
    }
  }
#endif /* USE_MPI */

  /* compute statistics, Nsum, intensity, Error bars */
  detector = mcdetector_statistics(detector);

#ifdef USE_MPI
  /* slaves are done */
  if(mpi_node_rank != mpi_node_root) {
    return detector;
  }
#endif

  /* output "Detector:" line ================================================ */
  /* when this is a detector written by a component (not the SAVE from instrument),
     not an event lists */
  if (!m) return(detector);
  if (!strcasestr(detector.format,"list")) {
    if (!strcmp(detector.component, instrument_name)) {
      if (strlen(detector.filename))  /* we name it from its filename, or from its title */
        strncpy(c, detector.filename, CHAR_BUF_LENGTH);
      else
        snprintf(c, CHAR_BUF_LENGTH, "%s", instrument_name);
    } else
      strncpy(c, detector.component, CHAR_BUF_LENGTH);  /* usual detectors written by components */

    printf("Detector: %s_I=%g %s_ERR=%g %s_N=%g",
           c, detector.intensity,
           c, detector.error,
           c, detector.events);
    printf(" \"%s\"\n", strlen(detector.filename) ? detector.filename : detector.component);
  }


  return(detector);
} /* detector_import */

/* end MCDETECTOR import section ============================================ */

















/* ========================================================================== */

/*                               ASCII output                                 */
/*     The SIM file is YAML based, the data files have '#' headers            */

/* ========================================================================== */


/*******************************************************************************
* mcinfo_out: output instrument tags/info (only in SIM)
* Used in: siminfo_init (ascii), mcinfo(stdout)
*******************************************************************************/
static void mcinfo_out(char *pre, FILE *f)
{
  char Parameters[CHAR_BUF_LENGTH] = "";
  int  i;

  if (!f || mcdisable_output_files) return;

  /* create parameter string ================================================ */
  for(i = 0; i < numipar; i++)
  {
    char ThisParam[CHAR_BUF_LENGTH];
    if (strlen(mcinputtable[i].name) > CHAR_BUF_LENGTH) break;
    snprintf(ThisParam, CHAR_BUF_LENGTH, " %s(%s)", mcinputtable[i].name,
            (*mcinputtypes[mcinputtable[i].type].parminfo)
                (mcinputtable[i].name));
    if (strlen(Parameters) + strlen(ThisParam) + 1 >= CHAR_BUF_LENGTH) break;
    strcat(Parameters, ThisParam);
  }

  /* output data ============================================================ */
  if (f != stdout)
    fprintf(f, "%sFile: %s%c%s\n",    pre, dirname, MC_PATHSEP_C, siminfo_name);
  else
    fprintf(f, "%sCreator: %s\n",     pre, MCCODE_STRING);

  fprintf(f, "%sSource: %s\n",   pre, instrument_source);
  fprintf(f, "%sParameters: %s\n",    pre, Parameters);

  fprintf(f, "%sTrace_enabled: %s\n", pre, traceenabled ? "yes" : "no");
  fprintf(f, "%sDefault_main: %s\n",  pre, defaultmain ?  "yes" : "no");
#ifdef MC_EMBEDDED_RUNTIME
  fprintf(f, "%sEmbedded_runtime: %s\n", pre, "yes");
#else
  fprintf(f, "%sEmbedded_runtime: %s\n", pre, "no");
#endif

  fflush(f);
} /* mcinfo_out */

/*******************************************************************************
* mcruninfo_out: output simulation tags/info (both in SIM and data files)
* Used in: siminfo_init (ascii case), mcdetector_out_xD_ascii
*******************************************************************************/
static void mcruninfo_out(char *pre, FILE *f)
{
  int i;
  char Parameters[CHAR_BUF_LENGTH];

  if (!f || mcdisable_output_files) return;

  fprintf(f, "%sFormat: %s%s\n",      pre,
    mcformat && strlen(mcformat) ? mcformat : MCCODE_NAME,
    mcformat && strcasestr(mcformat,"McCode") ? " with text headers" : "");
  fprintf(f, "%sURL: %s\n",         pre, "http://www.mccode.org");
  fprintf(f, "%sCreator: %s\n",     pre, MCCODE_STRING);
  fprintf(f, "%sInstrument: %s\n", pre, instrument_source);
  fprintf(f, "%sNcount: %llu\n",        pre, mcget_ncount());
  fprintf(f, "%sTrace: %s\n",       pre, mcdotrace ? "yes" : "no");
  fprintf(f, "%sGravitation: %s\n", pre, mcgravitation ? "yes" : "no");
  snprintf(Parameters, CHAR_BUF_LENGTH, "%ld", mcseed);
  fprintf(f, "%sSeed: %s\n",        pre, Parameters);
  fprintf(f, "%sDirectory: %s\n",        pre, dirname ? dirname : ".");
#ifdef USE_MPI
  if (mpi_node_count > 1)
    fprintf(f, "%sNodes: %i\n",        pre, mpi_node_count);
#endif

  // TODO Consider replacing this by a a call to `mcparameterinfo_out(pre+"Param: ", f)`
  /* output parameter string ================================================ */
  for(i = 0; i < numipar; i++) {
      if (mcinputtable[i].par){
	/* Parameters with a default value */
	if(mcinputtable[i].val && strlen(mcinputtable[i].val)){
	  (*mcinputtypes[mcinputtable[i].type].printer)(Parameters, mcinputtable[i].par);
	  fprintf(f, "%sParam: %s=%s\n", pre, mcinputtable[i].name, Parameters);
        /* ... and those without */
	}else{
	  fprintf(f, "%sParam: %s=NULL\n", pre, mcinputtable[i].name);
	}
      }
  }
  fflush(f);
} /* mcruninfo_out */

/*******************************************************************************
 * @brief Print parameter information to the specified file
 * @param pre any beginning-of-line padding
 * @param f the output file
 */
static void mcparameterinfo_out(char * pre, FILE *f){
  if (!f || mcdisable_output_files) return;

  unsigned int nchar = 4;
  for (int i=0; i < numipar; ++i){
    if (mcinputtable[i].par && mcinputtable[i].val && strlen(mcinputtable[i].val) > nchar)
      nchar = strlen(mcinputtable[i].val);
  }
  char * buffer = calloc(nchar+1, sizeof(char));

  if (!buffer) {
    exit(1);
  }

  for (int i=0; i < numipar; ++i) {
    if (mcinputtable[i].par) {
      char * name = mcinputtable[i].name;
      if (mcinputtable[i].val && strlen(mcinputtable[i].val)) {
        mcinputtypes[mcinputtable[i].type].printer(buffer, mcinputtable[i].par);
      } else {
        strcpy(buffer, "NULL");
      }
      if (strlen(mcinputtable[i].unit)){
        //fprintf(f, "%s%s %s (\"%s\") = %s\n", pre, mcinputtypes[mcinputtable[i].type].parminfo(name), name, mcinputtable[i].unit, buffer);
        fprintf(f, "%s%s %s/\"%s\" = %s\n", pre, mcinputtypes[mcinputtable[i].type].parminfo(name), name, mcinputtable[i].unit, buffer);
      } else {
        fprintf(f, "%s%s %s = %s\n", pre, mcinputtypes[mcinputtable[i].type].parminfo(name), name, buffer);
      }
    }
  }

  free(buffer);
}

/*******************************************************************************
* siminfo_out:    wrapper to fprintf(siminfo_file)
*******************************************************************************/
void siminfo_out(char *format, ...)
{
  va_list ap;

  if(siminfo_file && !mcdisable_output_files)
  {
    va_start(ap, format);
    vfprintf(siminfo_file, format, ap);
    va_end(ap);
  }
} /* siminfo_out */


/*******************************************************************************
* mcdatainfo_out: output detector header
*   mcdatainfo_out(prefix, file_handle, detector) writes info to data file
*******************************************************************************/
static void
mcdatainfo_out(char *pre, FILE *f, MCDETECTOR detector)
{
  if (!f || !detector.m || mcdisable_output_files) return;

  /* output data ============================================================ */
  fprintf(f, "%sDate: %s (%li)\n",       pre, detector.date, detector.date_l);
  fprintf(f, "%stype: %s\n",       pre, detector.type);
  fprintf(f, "%sSource: %s\n",     pre, detector.instrument);
  fprintf(f, "%scomponent: %s\n",  pre, detector.component);
  fprintf(f, "%sposition: %s\n",   pre, detector.position);

  fprintf(f, "%stitle: %s\n",      pre, detector.title);
  fprintf(f, !mcget_run_num() || mcget_run_num() >= mcget_ncount() ?
             "%sNcount: %s\n" :
             "%sratio: %s\n",  pre, detector.ncount);

  if (strlen(detector.filename)) {
    fprintf(f, "%sfilename: %s\n", pre, detector.filename);
  }

  fprintf(f, "%sstatistics: %s\n", pre, detector.statistics);
  fprintf(f, "%ssignal: %s\n",     pre, detector.signal);
  fprintf(f, "%svalues: %s\n",     pre, detector.values);

  if (detector.rank >= 1)
  {
    fprintf(f, "%sxvar: %s\n",     pre, detector.xvar);
    fprintf(f, "%syvar: %s\n",     pre, detector.yvar);
    fprintf(f, "%sxlabel: %s\n",   pre, detector.xlabel);
    fprintf(f, "%sylabel: %s\n",   pre, detector.ylabel);
    if (detector.rank > 1) {
      fprintf(f, "%szvar: %s\n",   pre, detector.zvar);
      fprintf(f, "%szlabel: %s\n", pre, detector.zlabel);
    }
  }

  fprintf(f,
    abs(detector.rank)==1 ?
             "%sxlimits: %s\n" :
             "%sxylimits: %s\n", pre, detector.limits);
  fprintf(f, "%svariables: %s\n", pre,
    strcasestr(detector.format, "list") ? detector.ylabel : detector.variables);

  fflush(f);

} /* mcdatainfo_out */

/* mcdetector_out_array_ascii: output a single array to a file
 *   m: columns
 *   n: rows
 *   p: array
 *   f: file handle (already opened)
 */
static void mcdetector_out_array_ascii(long m, long n, double *p, FILE *f, char istransposed)
{
  if(f)
  {
    int i,j;
    for(j = 0; j < n; j++)
    {
      for(i = 0; i < m; i++)
      {
          fprintf(f, "%.10g ", p[!istransposed ? i*n + j : j*m+i]);
      }
      fprintf(f,"\n");
    }
  }
} /* mcdetector_out_array_ascii */

/*******************************************************************************
* mcdetector_out_0D_ascii: called by mcdetector_out_0D for ascii output
*******************************************************************************/
MCDETECTOR mcdetector_out_0D_ascii(MCDETECTOR detector)
{
  int exists=0;
  FILE *outfile = NULL;

  /* Write data set information to simulation description file. */
  MPI_MASTER(
    siminfo_out("\nbegin data\n"); // detector.component
    mcdatainfo_out("  ", siminfo_file, detector);
    siminfo_out("end data\n");
    /* Don't write if filename is NULL: mcnew_file handles this (return NULL) */
    outfile = mcnew_file(detector.component, "dat", &exists);
    if(outfile)
    {
      /* write data file header and entry in simulation description file */
      mcruninfo_out( "# ", outfile);
      mcdatainfo_out("# ", outfile, detector);
      /* write I I_err N */
      fprintf(outfile, "%g %g %g\n",
        detector.intensity, detector.error, detector.events);
      fclose(outfile);
    }
  ); /* MPI_MASTER */
  return(detector);
} /* mcdetector_out_0D_ascii */

/*******************************************************************************
* mcdetector_out_1D_ascii: called by mcdetector_out_1D for ascii output
*******************************************************************************/
MCDETECTOR mcdetector_out_1D_ascii(MCDETECTOR detector)
{
  int exists=0;
  FILE *outfile = NULL;

  MPI_MASTER(
    /* Write data set information to simulation description file. */
    siminfo_out("\nbegin data\n"); // detector.filename
    mcdatainfo_out("  ", siminfo_file, detector);
    siminfo_out("end data\n");
    /* Loop over array elements, writing to file. */
    /* Don't write if filename is NULL: mcnew_file handles this (return NULL) */
    outfile = mcnew_file(detector.filename, "dat", &exists);
    if(outfile)
    {
      /* write data file header and entry in simulation description file */
      mcruninfo_out( "# ", outfile);
      mcdatainfo_out("# ", outfile, detector);
      /* output the 1D array columns */
      mcdetector_out_array_ascii(detector.m, detector.n, detector.p1, outfile, detector.istransposed);

      fclose(outfile);
    }
  ); /* MPI_MASTER */
  return(detector);

}  /* mcdetector_out_1D_ascii */

/*******************************************************************************
* mcdetector_out_2D_ascii: called by mcdetector_out_2D for ascii output
*******************************************************************************/
MCDETECTOR mcdetector_out_2D_ascii(MCDETECTOR detector)
{
  int exists=0;
  FILE *outfile = NULL;

  MPI_MASTER(
    /* Loop over array elements, writing to file. */
    /* Don't write if filename is NULL: mcnew_file handles this (return NULL) */
    outfile = mcnew_file(detector.filename, "dat", &exists);
    if(outfile)
    {
      /* write header only if file has just been created (not appending) */
      if (!exists) {
        /* Write data set information to simulation description file. */
        siminfo_out("\nbegin data\n"); // detector.filename
        mcdatainfo_out("  ", siminfo_file, detector);
        siminfo_out("end data\n");

        mcruninfo_out( "# ", outfile);
        mcdatainfo_out("# ", outfile,   detector);
      }
      /* Add # Data entry for any write to the file (e.g. via -USR2, see GitHub issue #2174 ) */
      fprintf(outfile, "# Data [%s/%s] %s:\n", detector.component, detector.filename, detector.zvar);
      mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p1,
        outfile, detector.istransposed);
      if (detector.p2) {
        fprintf(outfile, "# Errors [%s/%s] %s_err:\n", detector.component, detector.filename, detector.zvar);
        mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p2,
          outfile, detector.istransposed);
      }
      if (detector.p0) {
        fprintf(outfile, "# Events [%s/%s] N:\n", detector.component, detector.filename);
        mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p0,
          outfile, detector.istransposed);
      }
      fclose(outfile);

      if (!exists) {
        if (strcasestr(detector.format, "list"))
          printf("Events:   \"%s\"\n",
            strlen(detector.filename) ? detector.filename : detector.component);
      }
    } /* if outfile */
  ); /* MPI_MASTER */
#ifdef USE_MPI
  if (strcasestr(detector.format, "list") && mpi_node_count > 1) {
    int node_i=0;
    /* loop along MPI nodes to write sequentially */
    for(node_i=0; node_i<mpi_node_count; node_i++) {
      /* MPI: slaves wait for the master to write its block, then append theirs */
      MPI_Barrier(MPI_COMM_WORLD);
      if (node_i != mpi_node_root && node_i == mpi_node_rank) {
        if(strlen(detector.filename) && !mcdisable_output_files)	/* Don't write if filename is NULL */
          outfile = mcnew_file(detector.filename, "dat", &exists);
        if (!exists)
          fprintf(stderr, "Warning: [MPI node %i] file '%s' does not exist yet, "
                          "MASTER should have opened it before.\n",
            mpi_node_rank, detector.filename);
        if(outfile) {
          mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p1,
            outfile, detector.istransposed);
          fclose(outfile);
        }
      }
    }
  } /* if strcasestr list */
#endif
  return(detector);
} /* mcdetector_out_2D_ascii */

/*******************************************************************************
* strcpy_valid: makes a valid string for variable names.
*   copy 'original' into 'valid', replacing invalid characters by '_'
*   char arrays must be pre-allocated
*******************************************************************************/
static char *strcpy_valid(char *valid, char *original)
{
  long i;
  int  n=CHAR_BUF_LENGTH; /* max length of valid names */

  if (original == NULL || !strlen(original)) return(NULL);

  if (n > strlen(original)) n = strlen(original);
  else original += strlen(original)-n;
  strncpy(valid, original, n);

  for (i=0; i < n; i++)
  {
    if ( (valid[i] > 122)
      || (valid[i] < 32)
      || (strchr("!\"#$%&'()*+,-.:;<=>?@[\\]^`/ \n\r\t", valid[i]) != NULL) )
    {
      if (i) valid[i] = '_'; else valid[i] = 'm';
    }
  }
  valid[i] = '\0';

  return(valid);
} /* strcpy_valid */

/* end ascii output section ================================================= */







#ifdef USE_NEXUS

/* ========================================================================== */

/*                               NeXus output                                 */

/* ========================================================================== */

#define nxprintf(...)    nxstr('d', __VA_ARGS__)
#define nxprintattr(...) nxstr('a', __VA_ARGS__)

/*******************************************************************************
* nxstr: output a tag=value data set (char) in NeXus/current group
*   when 'format' is larger that 1024 chars it is used as value for the 'tag'
*   else the value is assembled with format and following arguments.
*   type='d' -> data set
*        'a' -> attribute for current data set
*******************************************************************************/
static int nxstr(char type, NXhandle *f, char *tag, char *format, ...)
{
  va_list ap;
  char value[CHAR_BUF_LENGTH];
  int  i;
  int  ret=NX_OK;

  if (!tag || !format || !strlen(tag) || !strlen(format)) return(NX_OK);

  /* assemble the value string */
  if (strlen(format) < CHAR_BUF_LENGTH) {
    va_start(ap, format);
    ret = vsnprintf(value, CHAR_BUF_LENGTH, format, ap);
    va_end(ap);

    i = strlen(value);
  } else {
    i = strlen(format);
  }

  if (type == 'd') {
    /* open/put/close data set */
    if (NXmakedata (f, tag, NX_CHAR, 1, &i) != NX_OK) return(NX_ERROR);
    NXopendata (f, tag);
    if (strlen(format) < CHAR_BUF_LENGTH)
      ret = NXputdata  (f, value);
    else
      ret = NXputdata  (f, format);
    NXclosedata(f);
  } else {
    if (strlen(format) < CHAR_BUF_LENGTH)
      ret = NXputattr  (f, tag, value, strlen(value), NX_CHAR);
    else
      ret = NXputattr  (f, tag, format, strlen(format), NX_CHAR);
  }

  return(ret);

} /* nxstr */

/*******************************************************************************
* mcinfo_readfile: read a full file into a string buffer which is allocated
*   Think to free the buffer after use.
* Used in: mcinfo_out_nexus (nexus)
*******************************************************************************/
char *mcinfo_readfile(char *filename)
{
  FILE *f = fopen(filename, "rb");
  if (!f) return(NULL);
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  rewind(f);
  char *string = malloc(fsize + 1);
  if (string) {
    int n = fread(string, fsize, 1, f);
    fclose(f);

    string[fsize] = 0;
  }
  return(string);
}

/*******************************************************************************
* mcinfo_out: output instrument/simulation groups in NeXus file
* Used in: siminfo_init (nexus)
*******************************************************************************/
static void mcinfo_out_nexus(NXhandle f)
{
  FILE  *fid;     /* for intrument source code/C/IDF */
  char  *buffer=NULL;
  time_t t     =time(NULL); /* for date */
  char   entry0[CHAR_BUF_LENGTH];
  int    count=0;
  char   name[CHAR_BUF_LENGTH];
  char   class[CHAR_BUF_LENGTH];

  if (!f || mcdisable_output_files) return;

  /* write NeXus NXroot attributes */
  /* automatically added: file_name, HDF5_Version, file_time, NeXus_version */
  nxprintattr(f, "creator",   "%s generated with " MCCODE_STRING, instrument_name);

  /* count the number of existing NXentry and create the next one */
  NXgetgroupinfo(f, &count, name, class);
  sprintf(entry0, "entry%i", count+1);

  /* create the main NXentry (mandatory in NeXus) */
  if (NXmakegroup(f, entry0, "NXentry") == NX_OK)
  if (NXopengroup(f, entry0, "NXentry") == NX_OK) {
    nxprintf(nxhandle, "program_name", MCCODE_STRING);
    nxprintf(f, "start_time", ctime(&t));
    nxprintf(f, "title", "%s%s%s simulation generated by instrument %s",
      dirname && strlen(dirname) ? dirname : ".", MC_PATHSEP_S, siminfo_name,
      instrument_name);
    nxprintattr(f, "program_name", MCCODE_STRING);
    nxprintattr(f, "instrument",   instrument_name);
    nxprintattr(f, "simulation",   "%s%s%s",
        dirname && strlen(dirname) ? dirname : ".", MC_PATHSEP_S, siminfo_name);

    /* write NeXus instrument group */
    if (NXmakegroup(f, "instrument", "NXinstrument") == NX_OK)
    if (NXopengroup(f, "instrument", "NXinstrument") == NX_OK) {
      int   i;
      char *string=NULL;

      /* write NeXus parameters(types) data =================================== */
      string = (char*)malloc(CHAR_BUF_LENGTH);
      if (string) {
        strcpy(string, "");
        for(i = 0; i < numipar; i++)
        {
          char ThisParam[CHAR_BUF_LENGTH];
          snprintf(ThisParam, CHAR_BUF_LENGTH, " %s(%s)", mcinputtable[i].name,
                  (*mcinputtypes[mcinputtable[i].type].parminfo)
                      (mcinputtable[i].name));
          if (strlen(string) + strlen(ThisParam) < CHAR_BUF_LENGTH)
            strcat(string, ThisParam);
        }
        nxprintattr(f, "Parameters",    string);
        free(string);
      }

      nxprintattr(f, "name",          instrument_name);
      nxprintf   (f, "name",          instrument_name);
      nxprintattr(f, "Source",        instrument_source);

      nxprintattr(f, "Trace_enabled", traceenabled ? "yes" : "no");
      nxprintattr(f, "Default_main",  defaultmain ?  "yes" : "no");
#ifdef MC_EMBEDDED_RUNTIME
      nxprintattr(f, "Embedded_runtime", "yes");
#else
      nxprintattr(f, "Embedded_runtime", "no");
#endif

      /* add instrument source code when available */
      buffer = mcinfo_readfile(instrument_source);
      if (buffer && strlen(buffer)) {
        long length=strlen(buffer);
        nxprintf (f, "description", buffer);
        NXopendata(f,"description");
        nxprintattr(f, "file_name", instrument_source);
        nxprintattr(f, "file_size", "%li", length);
        nxprintattr(f, "MCCODE_STRING", MCCODE_STRING);
        NXclosedata(f);
        nxprintf (f,"instrument_source", "%s " MCCODE_NAME " " MCCODE_PARTICLE " Monte Carlo simulation", instrument_name);
        free(buffer);
      } else
        nxprintf (f, "description", "File %s not found (instrument description %s is missing)",
          instrument_source, instrument_name);

      if (mcnexus_embed_idf) {
        /* add Mantid/IDF.xml when available */
        char *IDFfile=NULL;
        IDFfile = (char*)malloc(CHAR_BUF_LENGTH);
        sprintf(IDFfile,"%s%s",instrument_source,".xml");
        buffer = mcinfo_readfile(IDFfile);
        if (buffer && strlen(buffer)) {
          NXmakegroup (nxhandle, "instrument_xml", "NXnote");
          NXopengroup (nxhandle, "instrument_xml", "NXnote");
          nxprintf(f, "data", buffer);
          nxprintf(f, "description", "IDF.xml file found with instrument %s", instrument_source);
          nxprintf(f, "type", "text/xml");
          NXclosegroup(f); /* instrument_xml */
          free(buffer);
        }
        free(IDFfile);
      }

      /* Add "components" entry */
      if (NXmakegroup(f, "components", "NXdata") == NX_OK) {
        NXopengroup(f, "components", "NXdata");
        nxprintattr(f, "description", "Component list for instrument %s",  instrument_name);
	NXclosegroup(f); /* components */
      } else {
	printf("Failed to create NeXus component hierarchy\n");
      }
      NXclosegroup(f); /* instrument */
    } /* NXinstrument */

    /* write NeXus simulation group */
    if (NXmakegroup(f, "simulation", "NXnote") == NX_OK)
    if (NXopengroup(f, "simulation", "NXnote") == NX_OK) {

      nxprintattr(f, "name",   "%s%s%s",
        dirname && strlen(dirname) ? dirname : ".", MC_PATHSEP_S, siminfo_name);

      nxprintf   (f, "name",      "%s",     siminfo_name);
      nxprintattr(f, "Format",    mcformat && strlen(mcformat) ? mcformat : MCCODE_NAME);
      nxprintattr(f, "URL",       "http://www.mccode.org");
      nxprintattr(f, "program",   MCCODE_STRING);
      nxprintattr(f, "Instrument",instrument_source);
      nxprintattr(f, "Trace",     mcdotrace ?     "yes" : "no");
      nxprintattr(f, "Gravitation",mcgravitation ? "yes" : "no");
      nxprintattr(f, "Seed",      "%li", mcseed);
      nxprintattr(f, "Directory", dirname);
    #ifdef USE_MPI
      if (mpi_node_count > 1)
        nxprintf(f, "Nodes", "%i",        mpi_node_count);
    #endif

      /* output parameter string ================================================ */
      if (NXmakegroup(f, "Param", "NXparameters") == NX_OK) {
	NXopengroup(f,"Param", "NXparameters");
        int i;
        char string[CHAR_BUF_LENGTH];
        for(i = 0; i < numipar; i++) {
          if (mcget_run_num() || (mcinputtable[i].val && strlen(mcinputtable[i].val))) {
            if (mcinputtable[i].par == NULL)
              strncpy(string, (mcinputtable[i].val ? mcinputtable[i].val : ""), CHAR_BUF_LENGTH);
            else
              (*mcinputtypes[mcinputtable[i].type].printer)(string, mcinputtable[i].par);

            nxprintf(f,  mcinputtable[i].name, "%s", string);
            nxprintattr(f, mcinputtable[i].name, string);
          }
        }
        NXclosegroup(f); /* Param */
      } /* NXparameters */
      NXclosegroup(f); /* simulation */
    } /* NXsimulation */

    /* create a group to hold all links for all monitors */
    NXmakegroup(f, "data", "NXdetector");

    /* leave the NXentry opened (closed at exit) */
  } /* NXentry */
} /* mcinfo_out_nexus */

/*******************************************************************************
* mccomp_placement_type_nexus:
*   Places
*    - absolute (3x1) position
*    - absolute (3x3) rotation
*    - type / class of component instance into attributes under
*     entry<N>/instrument/compname
*   requires: NXentry to be opened
*******************************************************************************/
static void mccomp_placement_type_nexus(NXhandle nxhandle, char* component, Coords position, Rotation rotation, char* comptype)
{
  /* open NeXus instrument group */

  #ifdef USE_NEXUS
  if(nxhandle) {
    if (NXopengroup(nxhandle, "instrument", "NXinstrument") == NX_OK) {
      if (NXopengroup(nxhandle, "components", "NXdata") == NX_OK) {
	if (NXmakegroup(nxhandle, component, "NXdata") == NX_OK) {
	  if (NXopengroup(nxhandle, component, "NXdata") == NX_OK) {
	    int64_t pdims[3]; pdims[0]=3; pdims[1]=0; pdims[2]=0;
	    if (NXcompmakedata64(nxhandle, "Position", NX_FLOAT64, 1, pdims, NX_COMPRESSION, pdims) == NX_OK) {
	      if (NXopendata(nxhandle, "Position") == NX_OK) {
		double pos[3]; coords_get(position, &pos[0], &pos[1], &pos[2]);
		if (NXputdata (nxhandle, pos) == NX_OK) {
		  NXclosedata(nxhandle);
		} else {
		  fprintf(stderr, "COULD NOT PUT Position field for component %s\n",component);
		}
	      } else {
		fprintf(stderr, "Warning: could not open Position field for component %s\n",component);
	      }
	    }
	    int64_t rdims[3]; rdims[0]=3; rdims[1]=3; rdims[2]=0;
	    if (NXcompmakedata64(nxhandle, "Rotation", NX_FLOAT64, 2, rdims, NX_COMPRESSION, rdims) == NX_OK) {
	      if (NXopendata(nxhandle, "Rotation") == NX_OK) {
		if (NXputdata (nxhandle, rotation) == NX_OK) {
		  NXclosedata(nxhandle);
		} else {
		  fprintf(stderr, "COULD NOT PUT Rotation field for component %s\n",component);
		}
	      } else {
		fprintf(stderr, "Warning: could not open Rotation field for component %s\n",component);
	      }
	    }
	    nxprintf(nxhandle, "Component_type", comptype);
	    NXclosegroup(nxhandle); // component
	  } else {
	    printf("FAILED to open comp data group %s\n",component);
	  }
	} else {
	  printf("FAILED to create comp data group %s\n",component);
	}
	NXclosegroup(nxhandle); // components
      } else {
	printf("Failed to open NeXus component hierarchy\n");
      }
      NXclosegroup(nxhandle); // instrument
    } else {
      printf("Failed to open NeXus instrument hierarchy\n");
    }
  } else {
    fprintf(stderr,"NO NEXUS FILE\n");
  }
  #endif
} /* mccomp_placement_nexus */

/*******************************************************************************
* mccomp_param_nexus:
*   Output parameter/value pair for component instance into
*   the attribute
*     entry<N>/instrument/compname/parameter
*   requires: NXentry to be opened
*******************************************************************************/
static void mccomp_param_nexus(NXhandle nxhandle, char* component, char* parameter, char* defval, char* value, char* type)
{
  /* open NeXus instrument group */

  #ifdef USE_NEXUS
  if(nxhandle) {
    if (NXopengroup(nxhandle, "instrument", "NXinstrument") == NX_OK) {
      if (NXopengroup(nxhandle, "components", "NXdata") == NX_OK) {
	if (NXopengroup(nxhandle, component, "NXdata") == NX_OK) {
	  NXMDisableErrorReporting(); /* inactivate NeXus error messages, as creation may fail */
	  NXmakegroup(nxhandle, "parameters", "NXdata");
	  NXMEnableErrorReporting();  /* re-enable NeXus error messages */
	  if (NXopengroup(nxhandle, "parameters", "NXdata") == NX_OK) {
	    NXmakegroup(nxhandle, parameter, "NXnote");
	    if (NXopengroup(nxhandle, parameter, "NXnote") == NX_OK) {
	      nxprintattr(nxhandle, "type", type);
	      nxprintattr(nxhandle, "default",  defval);
	      nxprintattr(nxhandle, "value",  value);
	      NXclosegroup(nxhandle); // parameter
	    } else {
	      printf("FAILED to open parameters %s data group \n",parameter);
	    }
	    NXclosegroup(nxhandle); // "parameters"
	  } else {
	    printf("FAILED to open comp/parameters data group \n");
	  }
	  NXclosegroup(nxhandle); // component
	  } else {
	  printf("FAILED to open comp data group %s\n",component);
	}
	NXclosegroup(nxhandle); // components
      } else {
	printf("Failed to open NeXus component hierarchy\n");
      }
      NXclosegroup(nxhandle); // instrument
    } else {
      printf("Failed to open NeXus instrument hierarchy\n");
    }
  } else {
    fprintf(stderr,"NO NEXUS FILE\n");
  }
#endif
} /* mccomp_param_nexus */

/*******************************************************************************
* mcdatainfo_out_nexus: output detector header
*   mcdatainfo_out_nexus(detector) create group and write info to NeXus data file
*   open data:NXdetector then filename:NXdata and write headers/attributes
*   requires: NXentry to be opened
*******************************************************************************/
static void
mcdatainfo_out_nexus(NXhandle f, MCDETECTOR detector)
{
  char data_name[CHAR_BUF_LENGTH];
  if (!f || !detector.m || mcdisable_output_files) return;

  strcpy_valid(data_name,
    strlen(detector.filename) ?
      detector.filename : detector.component);

  /* the NXdetector group has been created in mcinfo_out_nexus (siminfo_init) */
  if (NXopengroup(f, "instrument", "NXinstrument") == NX_OK) {
    if (NXopengroup(f, "components", "NXdata") == NX_OK) {
      NXMDisableErrorReporting(); /* inactivate NeXus error messages, as creation may fail */
      NXmakegroup(f, detector.nexuscomp, "NXdata");
      if (NXopengroup(f, detector.nexuscomp, "NXdata") == NX_OK) {
	NXmakegroup(f, "output", "NXdetector");
	if (NXopengroup(f, "output", "NXdetector") == NX_OK) {
	  if (NXmakegroup(f, data_name, "NXdata") == NX_OK) {
	    if (NXopengroup(f, data_name, "NXdata") == NX_OK) {
	      /* output metadata (as attributes) ======================================== */
	      nxprintattr(f, "Date",       detector.date);
	      nxprintattr(f, "type",       detector.type);
	      nxprintattr(f, "Source",     detector.instrument);
	      nxprintattr(f, "component",  detector.component);
	      nxprintattr(f, "position",   detector.position);

	      nxprintattr(f, "title",      detector.title);
	      nxprintattr(f, !mcget_run_num() || mcget_run_num() >= mcget_ncount() ?
			  "Ncount" :
			  "ratio",  detector.ncount);

	      if (strlen(detector.filename)) {
		nxprintattr(f, "filename", detector.filename);
	      }

	      nxprintattr(f, "statistics", detector.statistics);
	      nxprintattr(f, "signal",     detector.signal);
	      nxprintattr(f, "values",     detector.values);

	      if (detector.rank >= 1)
		{
		  nxprintattr(f, "xvar",     detector.xvar);
		  nxprintattr(f, "yvar",     detector.yvar);
		  nxprintattr(f, "xlabel",   detector.xlabel);
		  nxprintattr(f, "ylabel",   detector.ylabel);
		  if (detector.rank > 1) {
		    nxprintattr(f, "zvar",   detector.zvar);
		    nxprintattr(f, "zlabel", detector.zlabel);
		  }
		}

	      nxprintattr(f, abs(detector.rank)==1 ?
			  "xlimits" :
			  "xylimits", detector.limits);
	      nxprintattr(f, "variables",
			  strcasestr(detector.format, "list") ? detector.ylabel : detector.variables);

	      NXclosegroup(f); // data_name
	    }
	  }
	}
	NXclosegroup(f); // output
	NXclosegroup(f); // detector.nexuscomp
      }
      NXclosegroup(f); // components
    }
    NXMEnableErrorReporting();  /* re-enable NeXus error messages */
    NXclosegroup(f); // instrument
  } /* NXdetector (instrument) */ 
} /* mcdatainfo_out_nexus */

/*******************************************************************************
* mcdetector_out_axis_nexus: write detector axis into current NXdata
*   requires: NXdata to be opened
*******************************************************************************/
int mcdetector_out_axis_nexus(NXhandle f, char *label, char *var, int rank, long length, double min, double max)
{
  if (!f || length <= 1 || mcdisable_output_files || max == min) return(NX_OK);
  else {
    double *axis;
    axis=malloc(sizeof(double)*length);
    if (!axis ) {
      printf("Fatal memory error allocating NeXus axis of length %li, exiting!\n", length);
      return(NX_ERROR);
    }
    char *valid;
    valid=malloc(sizeof(char)*CHAR_BUF_LENGTH);
    if (!valid ) {
      printf("Fatal memory error allocating label axis of length %i, exiting!\n", CHAR_BUF_LENGTH);
      free(axis);
      return(NX_ERROR);
    }
    int dim=(int)length;
    int i;
    int nprimary=1;
    /* create an axis from [min:max] */
    for(i = 0; i < length; i++)
      axis[i] = min+(max-min)*(i+0.5)/length;
    /* create the data set */
    strcpy_valid(valid, label);
    NXcompmakedata(f, valid, NX_FLOAT64, 1, &dim, NX_COMPRESSION, &dim);
    /* open it */
    if (NXopendata(f, valid) != NX_OK) {
      fprintf(stderr, "Warning: could not open axis rank %i '%s' (NeXus)\n",
        rank, valid);
      free(axis);
      free(valid);
      return(NX_ERROR);
    }
    /* put the axis and its attributes */
    NXputdata  (f, axis);
    nxprintattr(f, "long_name",  label);
    nxprintattr(f, "short_name", var);
    NXputattr  (f, "axis",       &rank,     1, NX_INT32);
    nxprintattr(f, "units",      var);
    NXputattr  (f, "primary",    &nprimary, 1, NX_INT32);
    NXclosedata(f);
    free(axis);
    free(valid);
    return(NX_OK);
  }
} /* mcdetector_out_axis_nexus */

/*******************************************************************************
* mcdetector_out_array_nexus: write detector array into current NXdata (1D,2D)
*   requires: NXdata to be opened
*******************************************************************************/
int mcdetector_out_array_nexus(NXhandle f, char *part, double *data, MCDETECTOR detector)
{

  int64_t dims[3]={detector.m,detector.n,detector.p};  /* number of elements to write */
  int64_t fulldims[3]={detector.m,detector.n,detector.p};
  int signal=1;
  int exists=0;
  int64_t current_dims[3]={0,0,0};
  int ret=NX_OK;

  if (!f || !data || !detector.m || mcdisable_output_files) return(NX_OK);

  /* when this is a list, we set 1st dimension to NX_UNLIMITED for creation */
  if (strcasestr(detector.format, "list")) fulldims[0] = NX_UNLIMITED;

  /* create the data set in NXdata group */
  NXMDisableErrorReporting(); /* inactivate NeXus error messages, as creation may fail */
  ret = NXcompmakedata64(f, part, NX_FLOAT64, detector.rank, fulldims, NX_COMPRESSION, dims);
  if (ret != NX_OK) {
    /* failed: data set already exists */
    int datatype=0;
    int rank=0;
    exists=1;
    /* inquire current size of data set (nb of events stored) */
    NXopendata(f, part);
    NXgetinfo64(f, &rank, current_dims, &datatype);
    NXclosedata(f);
  }
  NXMEnableErrorReporting();  /* re-enable NeXus error messages */

  /* open the data set */
  if (NXopendata(f, part) == NX_ERROR) {
    fprintf(stderr, "Warning: could not open DataSet %s '%s' (NeXus)\n",
      part, detector.title);
    return(NX_ERROR);
  }
  if (strcasestr(detector.format, "list")) {
    current_dims[1] = current_dims[2] = 0; /* set starting location for writing slab */
    NXputslab64(f, data, current_dims, dims);
    if (!exists)
      printf("Events:   \"%s\"\n",
        strlen(detector.filename) ? detector.filename : detector.component);
    else
      printf("Append:   \"%s\"\n",
	     strlen(detector.filename) ? detector.filename : detector.component);
  } else {
    NXputdata (f, data);
  }

  if (strstr(part,"data") || strstr(part, "events")) {
    NXputattr(f, "signal", &signal, 1, NX_INT32);
    nxprintattr(f, "short_name", strlen(detector.filename) ?
      detector.filename : detector.component);
  }
  nxprintattr(f, "long_name", "%s '%s'", part, detector.title);
  NXclosedata(f);

  return(NX_OK);
} /* mcdetector_out_array_nexus */

/*******************************************************************************
* mcdetector_out_data_nexus: write detector axes+data into current NXdata
*   The data:NXdetector is opened, then filename:NXdata
*   requires: NXentry to be opened
*******************************************************************************/
int mcdetector_out_data_nexus(NXhandle f, MCDETECTOR detector)
{
  char data_name[CHAR_BUF_LENGTH];

  if (!f || !detector.m || mcdisable_output_files) return(NX_OK);

  strcpy_valid(data_name,
    strlen(detector.filename) ?
      detector.filename : detector.component);
  NXlink pLink;
  /* the NXdetector group has been created in mcinfo_out_nexus (siminfo_init) */
  if (NXopengroup(f, "instrument", "NXinstrument") == NX_OK) {
    if (NXopengroup(f, "components", "NXdata") == NX_OK) {
      if (NXopengroup(f, detector.nexuscomp, "NXdata") == NX_OK) {
	if (NXopengroup(f, "output", "NXdetector") == NX_OK) {

	  /* the NXdata group has been created in mcdatainfo_out_nexus */
	  if (NXopengroup(f, data_name, "NXdata") == NX_OK) {
	    
	    MPI_MASTER(
		       nxprintattr(f, "options",
				   strlen(detector.options) ? detector.options : "None");
		       );
	    /* write axes, for histogram data sets, not for lists */
	    if (!strcasestr(detector.format, "list")) {
	      mcdetector_out_axis_nexus(f, detector.xlabel, detector.xvar,
					1, detector.m, detector.xmin, detector.xmax);
	      mcdetector_out_axis_nexus(f, detector.ylabel, detector.yvar,
					2, detector.n, detector.ymin, detector.ymax);
	      mcdetector_out_axis_nexus(f, detector.zlabel, detector.zvar,
					3, detector.p, detector.zmin, detector.zmax); 
	    } else {
	      	    MPI_MASTER(
			       nxprintattr(f, "dataset columns",
					   strlen(detector.ylabel) ? detector.ylabel : "None");
		    );
	    }

	    /* write the actual data (appended if already exists) */
	    if (!strcasestr(detector.format, "list") && !strcasestr(detector.format, "pixels")) {
	      mcdetector_out_array_nexus(f, "data", detector.p1, detector);
	      mcdetector_out_array_nexus(f, "errors", detector.p2, detector);
	      mcdetector_out_array_nexus(f, "ncount", detector.p0, detector);
	    } else if (strcasestr(detector.format, "pixels")) {
	      mcdetector_out_array_nexus(  f, "pixels", detector.p1, detector);
	    } else {
	      mcdetector_out_array_nexus(  f, "events", detector.p1, detector);
	    }
	    NXclosegroup(f);
	    NXopengroup(f, data_name, "NXdata");
	    NXgetgroupID(nxhandle, &pLink);
	    NXclosegroup(f);
	  } /* NXdata data_name*/
	  NXclosegroup(f);
	} /* NXdetector output */
	NXclosegroup(f);
      } /* NXdata detector.nexuscomp */
      NXclosegroup(f);
    } /* NXdata components */
    NXclosegroup(f);
  } /* NXdata instrument */
  
  if (!strcasestr(detector.format, "pixels")) {
    if (NXopengroup(f, "data", "NXdetector") == NX_OK) {
      NXmakelink(nxhandle, &pLink);
      NXclosegroup(f);
    }
  }
  return(NX_OK);
} /* mcdetector_out_array_nexus */

#ifdef USE_MPI
/*******************************************************************************
* mcdetector_out_list_slaves: slaves send their list data to master which writes
*   requires: NXentry to be opened
* WARNING: this method has a flaw: it requires all nodes to flush the lists
*   the same number of times. In case one node is just below the buffer size
*   when finishing (e.g. monitor_nd), it may not trigger save but others may.
*   Then the number of recv/send is not constant along nodes, and simulation stalls.
*******************************************************************************/
MCDETECTOR mcdetector_out_list_slaves(MCDETECTOR detector)
{
  int     node_i=0;
  MPI_MASTER(
	     printf("\n** MPI master gathering slave node list data ** \n");
  );

  if (mpi_node_rank != mpi_node_root) {
    /* MPI slave: slaves send their data to master: 2 MPI_Send calls */
    /* m, n, p must be sent first, since all slaves do not have the same number of events */
    int mnp[3]={detector.m,detector.n,detector.p};

    if (mc_MPI_Send(mnp, 3, MPI_INT, mpi_node_root)!= MPI_SUCCESS)
      fprintf(stderr, "Warning: proc %i to master: MPI_Send mnp list error (mcdetector_out_list_slaves)\n", mpi_node_rank);
    if (!detector.p1
     || mc_MPI_Send(detector.p1, mnp[0]*mnp[1]*mnp[2], MPI_DOUBLE, mpi_node_root) != MPI_SUCCESS)
      fprintf(stderr, "Warning: proc %i to master: MPI_Send p1 list error: mnp=%i (mcdetector_out_list_slaves)\n", mpi_node_rank, abs(mnp[0]*mnp[1]*mnp[2]));
    /* slaves are done: sent mnp and p1 */
  } /* end slaves */

  /* MPI master: receive data from slaves sequentially: 2 MPI_Recv calls */

  if (mpi_node_rank == mpi_node_root) {
    for(node_i=0; node_i<mpi_node_count; node_i++) {
      double *this_p1=NULL;                               /* buffer to hold the list from slaves */
      int     mnp[3]={0,0,0};  /* size of this buffer */
      if (node_i != mpi_node_root) { /* get data from slaves */
	if (mc_MPI_Recv(mnp, 3, MPI_INT, node_i) != MPI_SUCCESS)
	  fprintf(stderr, "Warning: master from proc %i: "
		  "MPI_Recv mnp list error (mcdetector_write_data)\n", node_i);
	if (mnp[0]*mnp[1]*mnp[2]) {
	  this_p1 = (double *)calloc(mnp[0]*mnp[1]*mnp[2], sizeof(double));
	  if (!this_p1 || mc_MPI_Recv(this_p1, abs(mnp[0]*mnp[1]*mnp[2]), MPI_DOUBLE, node_i)!= MPI_SUCCESS)
	    fprintf(stderr, "Warning: master from proc %i: "
		    "MPI_Recv p1 list error: mnp=%i (mcdetector_write_data)\n", node_i, mnp[0]*mnp[1]*mnp[2]);
	  else {
	    printf(". MPI master writing data for slave node %i\n",node_i);
	    detector.p1 = this_p1;
	    detector.m  = mnp[0]; detector.n  = mnp[1]; detector.p  = mnp[2];

	    mcdetector_out_data_nexus(nxhandle, detector);
	  }
	}
      } /* if not master */
      free(this_p1);
    } /* for */
  MPI_MASTER(
	     printf("\n** Done ** \n");
  );
  }
  // Common return statement for slaves / master alike
  return(detector);
}
#endif

MCDETECTOR mcdetector_out_0D_nexus(MCDETECTOR detector)
{
  /* Write data set information to NeXus file. */
  MPI_MASTER(
    mcdatainfo_out_nexus(nxhandle, detector);
  );

  return(detector);
} /* mcdetector_out_0D_ascii */

MCDETECTOR mcdetector_out_1D_nexus(MCDETECTOR detector)
{
  MPI_MASTER(
  mcdatainfo_out_nexus(nxhandle, detector);
  mcdetector_out_data_nexus(nxhandle, detector);
  );
  return(detector);
} /* mcdetector_out_1D_ascii */

MCDETECTOR mcdetector_out_2D_nexus(MCDETECTOR detector)
{
  MPI_MASTER(
  mcdatainfo_out_nexus(nxhandle, detector);
  mcdetector_out_data_nexus(nxhandle, detector);
  );

#ifdef USE_MPI // and USE_NEXUS
  /* NeXus: slave nodes have master write their lists */
  if (strcasestr(detector.format, "list") && mpi_node_count > 1) {
    mcdetector_out_list_slaves(detector);
  }
#endif /* USE_MPI */

  return(detector);
} /* mcdetector_out_2D_nexus */

MCDETECTOR mcdetector_out_3D_nexus(MCDETECTOR detector)
{
  printf("Received detector from %s\n",detector.component);
  MPI_MASTER(
  mcdatainfo_out_nexus(nxhandle, detector);
  mcdetector_out_data_nexus(nxhandle, detector);
  );
  return(detector);
} /* mcdetector_out_3D_nexus */


#endif /* USE_NEXUS*/








/* ========================================================================== */

/*                            Main input functions                            */
/*            DETECTOR_OUT_xD function calls -> ascii or NeXus                */

/* ========================================================================== */

/*******************************************************************************
* siminfo_init:   open SIM and write header
*******************************************************************************/
FILE *siminfo_init(FILE *f)
{
  int exists=0;

  /* check format */
  if (!mcformat || !strlen(mcformat)
   || !strcasecmp(mcformat, "MCSTAS") || !strcasecmp(mcformat, "MCXTRACE")
   || !strcasecmp(mcformat, "PGPLOT") || !strcasecmp(mcformat, "GNUPLOT") || !strcasecmp(mcformat, "MCCODE")
   || !strcasecmp(mcformat, "MATLAB")) {
    mcformat="McCode";
#ifdef USE_NEXUS
  } else if (strcasestr(mcformat, "NeXus")) {
    /* Do nothing */
#endif
  } else {
    fprintf(stderr,
	    "Warning: You have requested the output format %s which is unsupported by this binary. Resetting to standard %s format.\n",mcformat ,"McCode");
    mcformat="McCode";
  }

  /* open the SIM file if not defined yet */
  if (siminfo_file || mcdisable_output_files)
    return (siminfo_file);

#ifdef USE_NEXUS
  /* only master writes NeXus header: calls NXopen(nxhandle) */
  if (mcformat && strcasestr(mcformat, "NeXus")) {
	  MPI_MASTER(
	  siminfo_file = mcnew_file(siminfo_name, "h5", &exists);
    if(!siminfo_file)
      fprintf(stderr,
	      "Warning: could not open simulation description file '%s'\n",
	      siminfo_name);
	  else
	    mcinfo_out_nexus(nxhandle);
	  );
    return(siminfo_file); /* points to nxhandle */
  }
#endif

  /* write main description file (only MASTER) */
  MPI_MASTER(

  siminfo_file = mcnew_file(siminfo_name, "sim", &exists);
  if(!siminfo_file)
    fprintf(stderr,
	    "Warning: could not open simulation description file '%s'\n",
	    siminfo_name);
  else
  {
    /* write SIM header */
    time_t t=time(NULL);
    siminfo_out("%s simulation description file for %s.\n",
      MCCODE_NAME, instrument_name);
    siminfo_out("Date:    %s", ctime(&t)); /* includes \n */
    siminfo_out("Program: %s\n\n", MCCODE_STRING);

    siminfo_out("begin instrument: %s\n", instrument_name);
    mcinfo_out(   "  ", siminfo_file);
    siminfo_out("end instrument\n");

    siminfo_out("\nbegin simulation: %s\n", dirname);
    mcruninfo_out("  ", siminfo_file);
    siminfo_out("end simulation\n");

  }
  ); /* MPI_MASTER */
  return (siminfo_file);

} /* siminfo_init */

/*******************************************************************************
*   siminfo_close:  close SIM
*******************************************************************************/
void siminfo_close()
{
#ifdef USE_MPI
  if(mpi_node_rank == mpi_node_root) {
#endif
  if(siminfo_file && !mcdisable_output_files) {
#ifdef USE_NEXUS
    if (mcformat && strcasestr(mcformat, "NeXus")) {
      time_t t=time(NULL);
      nxprintf(nxhandle, "end_time", ctime(&t));
      nxprintf(nxhandle, "duration", "%li", (long)t-mcstartdate);
      NXclosegroup(nxhandle); /* NXentry */
      NXclose(&nxhandle);
    } else {
#endif
      fclose(siminfo_file);
#ifdef USE_NEXUS
    }
#endif
#ifdef USE_MPI
  }
#endif
    siminfo_file = NULL;
  }
} /* siminfo_close */

/*******************************************************************************
* mcdetector_out_0D: wrapper for 0D (single value).
*   Output single detector/monitor data (p0, p1, p2).
*   Title is t, component name is c.
*******************************************************************************/
MCDETECTOR mcdetector_out_0D(char *t, double p0, double p1, double p2,
			     char *c, Coords posa, Rotation rota, int index)
{
  /* import and perform basic detector analysis (and handle MPI reduce) */
  MCDETECTOR detector = detector_import(mcformat,
    c, (t ? t : MCCODE_STRING " data"),
    1, 1, 1,
    "I", "", "",
    "I", "", "",
    0, 0, 0, 0, 0, 0, c,
    &p0, &p1, &p2, posa, rota, index); /* write Detector: line */

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    return(mcdetector_out_0D_nexus(detector));
  else
#endif
    return(mcdetector_out_0D_ascii(detector));

} /* mcdetector_out_0D */



/*******************************************************************************
* mcdetector_out_1D: wrapper for 1D.
*   Output 1d detector data (p0, p1, p2) for n bins linearly
*   distributed across the range x1..x2 (x1 is lower limit of first
*   bin, x2 is upper limit of last bin). Title is t, axis labels are xl
*   and yl. File name is f, component name is c.
*
*   t:    title
*   xl:   x-label
*   yl:   y-label
*   xvar: measured variable length
*   x1:   x axus min
*   x2:   x axis max
*   n:    1d data vector lenght
*   p0:   pntr to start of data block#0
*   p1:   pntr to start of data block#1
*   p2:   pntr to start of data block#2
*   f:    filename
*
*   Not included in the macro, and here forwarded to detector_import:
*   c:    ?
*   posa: ?
*******************************************************************************/
MCDETECTOR mcdetector_out_1D(char *t, char *xl, char *yl,
        char *xvar, double x1, double x2,
        long n,
        double *p0, double *p1, double *p2, char *f,
        char *c, Coords posa, Rotation rota, int index)
{
  /* import and perform basic detector analysis (and handle MPI_Reduce) */
  // detector_import calls mcdetector_statistics, which will return different
  // MCDETECTOR versions for 1-D data based on the value of mcformat.
  //
  MCDETECTOR detector = detector_import(mcformat,
    c, (t ? t : MCCODE_STRING " 1D data"),
    n, 1, 1,
    xl, yl, (n > 1 ? "Signal per bin" : " Signal"),
    xvar, "(I,I_err)", "I",
    x1, x2, 0, 0, 0, 0, f,
    p0, p1, p2, posa, rota, index); /* write Detector: line */
  if (!detector.p1 || !detector.m) return(detector);

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    detector = mcdetector_out_1D_nexus(detector);
  else
#endif
    detector = mcdetector_out_1D_ascii(detector);
  if (detector.p1 != p1 && detector.p1) {
    // mcdetector_statistics allocated memory but it hasn't been freed.
    free(detector.p1);
    // plus undo the other damage done there:
    detector.p0 = p0; // was set to NULL
    detector.p1 = p1; // was set to this_p1
    detector.p2 = p2; // was set to NULL
    detector.m = detector.n; // (e.g., labs(n))
    detector.n = 1;  // not (n x n)
    detector.istransposed = n < 0 ? 1 : 0;
  }
  return detector;

} /* mcdetector_out_1D */

/*******************************************************************************
* mcdetector_out_2D: wrapper for 2D.
*   Special case for list: master creates file first, then slaves append their
*   blocks without header-
*
*   t:    title
*   xl:   x-label
*   yl:   y-label
*   x1:   x axus min
*   x2:   x axis max
*   y1:   y axis min
*   y2:   y axis max
*   m:    dim 1 (x) size
*   n:    dim 2 (y) size
*   p0:   pntr to start of data block#0
*   p1:   pntr to start of data block#1
*   p2:   pntr to start of data block#2
*   f:    filename
*
*   Not included in the macro, and here forwarded to detector_import:
*   c:    ?
*   posa: ?
*   rota: ?
*******************************************************************************/
MCDETECTOR mcdetector_out_2D(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2,
                  long m, long n,
                  double *p0, double *p1, double *p2, char *f,
		  char *c, Coords posa, Rotation rota, int index)
{
  char xvar[CHAR_BUF_LENGTH];
  char yvar[CHAR_BUF_LENGTH];

  /* create short axes labels */
  if (xl && strlen(xl)) { strncpy(xvar, xl, CHAR_BUF_LENGTH); xvar[2]='\0'; }
  else strcpy(xvar, "x");
  if (yl && strlen(yl)) { strncpy(yvar, yl, CHAR_BUF_LENGTH); yvar[2]='\0'; }
  else strcpy(yvar, "y");

  MCDETECTOR detector;

  /* import and perform basic detector analysis (and handle MPI_Reduce) */
  if (labs(m) == 1) {/* n>1 on Y, m==1 on X: 1D, no X axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      n, 1, 1,
      yl, "", "Signal per bin",
      yvar, "(I,Ierr)", "I",
      y1, y2, x1, x2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  } else if (labs(n)==1) {/* m>1 on X, n==1 on Y: 1D, no Y axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      m, 1, 1,
      xl, "", "Signal per bin",
      xvar, "(I,Ierr)", "I",
      x1, x2, y1, y2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  }else {
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 2D data"),
      m, n, 1,
      xl, yl, "Signal per bin",
      xvar, yvar, "I",
      x1, x2, y1, y2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  }

  if (!detector.p1 || !detector.m) return(detector);

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    return(mcdetector_out_2D_nexus(detector));
  else
#endif
    return(mcdetector_out_2D_ascii(detector));

} /* mcdetector_out_2D */

/*******************************************************************************
* mcdetector_out_2D_list: List mode 2D including forwarding "options" from
* Monitor_nD
*
*   Special case for list: master creates file first, then slaves append their
*   blocks without header-
*
*   t:    title
*   xl:   x-label
*   yl:   y-label
*   x1:   x axus min
*   x2:   x axis max
*   y1:   y axis min
*   y2:   y axis max
*   m:    dim 1 (x) size
*   n:    dim 2 (y) size
*   p0:   pntr to start of data block#0
*   p1:   pntr to start of data block#1
*   p2:   pntr to start of data block#2
*   f:    filename
*
*   Not included in the macro, and here forwarded to detector_import:
*   c:    ?
*   posa: ?
*   rota: ?
*******************************************************************************/
MCDETECTOR mcdetector_out_2D_list(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2,
                  long m, long n,
                  double *p0, double *p1, double *p2, char *f,
		  char *c, Coords posa, Rotation rota, char* options, int index)
{
  char xvar[CHAR_BUF_LENGTH];
  char yvar[CHAR_BUF_LENGTH];

  /* create short axes labels */
  if (xl && strlen(xl)) { strncpy(xvar, xl, CHAR_BUF_LENGTH); xvar[2]='\0'; }
  else strcpy(xvar, "x");
  if (yl && strlen(yl)) { strncpy(yvar, yl, CHAR_BUF_LENGTH); yvar[2]='\0'; }
  else strcpy(yvar, "y");

  MCDETECTOR detector;

  /* import and perform basic detector analysis (and handle MPI_Reduce) */
  if (labs(m) == 1) {/* n>1 on Y, m==1 on X: 1D, no X axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      n, 1, 1,
      yl, "", "Signal per bin",
      yvar, "(I,Ierr)", "I",
      y1, y2, x1, x2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  } else if (labs(n)==1) {/* m>1 on X, n==1 on Y: 1D, no Y axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      m, 1, 1,
      xl, "", "Signal per bin",
      xvar, "(I,Ierr)", "I",
      x1, x2, y1, y2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  }else {
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 2D data"),
      m, n, 1,
      xl, yl, "Signal per bin",
      xvar, yvar, "I",
      x1, x2, y1, y2, 0, 0, f,
     p0, p1, p2, posa, rota, index); /* write Detector: line */
  }

  MPI_MASTER(
  if (strlen(options)) {
    strcpy(detector.options,options);
  } else {
    strcpy(detector.options,"None");
  }
  );

  if (!detector.p1 || !detector.m) return(detector);

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    return(mcdetector_out_2D_nexus(detector));
  else
#endif
    return(mcdetector_out_2D_ascii(detector));

} /* mcdetector_out_2D_list */

/*******************************************************************************
* mcdetector_out_list: wrapper for list output (calls out_2D with mcformat+"list").
*   m=number of events, n=size of each event
*******************************************************************************/
MCDETECTOR mcdetector_out_list(char *t, char *xl, char *yl,
                  long m, long n,
                  double *p1, char *f,
			       char *c, Coords posa, Rotation rota, char* options, int index)
{
  char       format_new[CHAR_BUF_LENGTH];
  char      *format_org;
  MCDETECTOR detector;

  format_org = mcformat;
  strcpy(format_new, mcformat);
  strcat(format_new, " list");
  mcformat = format_new;
  detector = mcdetector_out_2D_list(t, xl, yl,
                  1,labs(m),1,labs(n),
                  m,n,
                  NULL, p1, NULL, f,
		  c, posa,rota,options, index);

  mcformat = format_org;
  return(detector);
}

/*******************************************************************************
 * mcuse_dir: set data/sim storage directory and create it,
 * or exit with error if exists
 ******************************************************************************/
static void
mcuse_dir(char *dir)
{
  if (!dir || !strlen(dir)) return;
#ifdef MC_PORTABLE
  fprintf(stderr, "Error: "
          "Directory output cannot be used with portable simulation (mcuse_dir)\n");
  exit(1);
#else  /* !MC_PORTABLE */
  /* handle file://directory URL type */
  if (strncmp(dir, "file://", strlen("file://")))
    dirname = dir;
  else
    dirname = dir+strlen("file://");


#ifdef USE_MPI
  if(mpi_node_rank == mpi_node_root) {
#endif
    int exists=0;
    DIR* handle = opendir(dirname);
    if (handle) {
      /* Directory exists. */
      closedir(handle);
      exists=1;
    }
    if(mkdir(dirname, 0777)) {
#ifndef DANSE
      if(!mcappend) {
	fprintf(stderr, "Error: unable to create directory '%s' (mcuse_dir)\n", dir);
	fprintf(stderr, "(Maybe the directory already exists?)\n");
#endif
#ifdef USE_MPI
	MPI_Abort(MPI_COMM_WORLD, -1);
#endif
	exit(-1);
      }
    }
#ifdef USE_MPI
    }
#endif

  /* remove trailing PATHSEP (if any) */
  while (strlen(dirname) && dirname[strlen(dirname) - 1] == MC_PATHSEP_C)
    dirname[strlen(dirname) - 1]='\0';
#endif /* !MC_PORTABLE */
} /* mcuse_dir */

/*******************************************************************************
* mcinfo: display instrument simulation info to stdout and exit
*******************************************************************************/
static void
mcinfo(void)
{
  fprintf(stdout, "begin instrument: %s\n", instrument_name);
  mcinfo_out("  ", stdout);
  fprintf(stdout, "end instrument\n");
  fprintf(stdout, "begin simulation: %s\n", dirname ? dirname : ".");
  mcruninfo_out("  ", stdout);
  fprintf(stdout, "end simulation\n");
  exit(0); /* includes MPI_Finalize in MPI mode */
} /* mcinfo */

/*******************************************************************************
* mcparameterinfo: display instrument parameter info to stdout and exit
*******************************************************************************/
static void
mcparameterinfo(void)
{
  mcparameterinfo_out("  ", stdout);
  exit(0); /* includes MPI_Finalize in MPI mode */
} /* mcparameterinfo */



#endif /* ndef MCCODE_R_IO_C */

/* end of the I/O section =================================================== */







/*******************************************************************************
* mcset_ncount: set total number of rays to generate
*******************************************************************************/
void mcset_ncount(unsigned long long int count)
{
  mcncount = count;
}

/* mcget_ncount: get total number of rays to generate */
unsigned long long int mcget_ncount(void)
{
  return mcncount;
}

/* mcget_run_num: get curent number of rays */
/* Within the TRACE scope we are now using _particle->uid directly */
unsigned long long int mcget_run_num() // shuld be (_class_particle* _particle) somehow
{
  /* This function only remains for the few cases outside TRACE where we need to know
     the number of simulated particles */
  return mcrun_num;
}

/* mcsetn_arg: get ncount from a string argument */
static void
mcsetn_arg(char *arg)
{
  mcset_ncount((long long int) strtod(arg, NULL));
}

/* mcsetseed: set the random generator seed from a string argument */
static void
mcsetseed(char *arg)
{
  mcseed = atol(arg);
  if(!mcseed) {
  //  srandom(mcseed);
  //} else {
    fprintf(stderr, "Error: seed must not be zero (mcsetseed)\n");
    exit(1);
  }
}

/* Following part is only embedded when not redundent with mccode-r.h ========= */

#ifndef MCCODE_H

/* SECTION: MCDISPLAY support. =============================================== */

/*******************************************************************************
* Just output MCDISPLAY keywords to be caught by an external plotter client.
*******************************************************************************/

void mcdis_magnify(char *what){
  // Do nothing here, better use interactive zoom from the tools
}

void mcdis_line(double x1, double y1, double z1,
                double x2, double y2, double z2){
  printf("MCDISPLAY: multiline(2,%g,%g,%g,%g,%g,%g)\n",
         x1,y1,z1,x2,y2,z2);
}

void mcdis_dashed_line(double x1, double y1, double z1,
		       double x2, double y2, double z2, int n){
  int i;
  const double dx = (x2-x1)/(2*n+1);
  const double dy = (y2-y1)/(2*n+1);
  const double dz = (z2-z1)/(2*n+1);

  for(i = 0; i < n+1; i++)
    mcdis_line(x1 + 2*i*dx,     y1 + 2*i*dy,     z1 + 2*i*dz,
	       x1 + (2*i+1)*dx, y1 + (2*i+1)*dy, z1 + (2*i+1)*dz);
}

void mcdis_multiline(int count, ...){
  va_list ap;
  double x,y,z;

  printf("MCDISPLAY: multiline(%d", count);
  va_start(ap, count);
  while(count--)
    {
    x = va_arg(ap, double);
    y = va_arg(ap, double);
    z = va_arg(ap, double);
    printf(",%g,%g,%g", x, y, z);
    }
  va_end(ap);
  printf(")\n");
}

void mcdis_rectangle(char* plane, double x, double y, double z,
		     double width, double height){
  /* draws a rectangle in the plane           */
  /* x is ALWAYS width and y is ALWAYS height */
  if (strcmp("xy", plane)==0) {
    mcdis_multiline(5,
		    x - width/2, y - height/2, z,
		    x + width/2, y - height/2, z,
		    x + width/2, y + height/2, z,
		    x - width/2, y + height/2, z,
		    x - width/2, y - height/2, z);
  } else if (strcmp("xz", plane)==0) {
    mcdis_multiline(5,
		    x - width/2, y, z - height/2,
		    x + width/2, y, z - height/2,
		    x + width/2, y, z + height/2,
		    x - width/2, y, z + height/2,
		    x - width/2, y, z - height/2);
  } else if (strcmp("yz", plane)==0) {
    mcdis_multiline(5,
		    x, y - height/2, z - width/2,
		    x, y - height/2, z + width/2,
		    x, y + height/2, z + width/2,
		    x, y + height/2, z - width/2,
		    x, y - height/2, z - width/2);
  } else {

    fprintf(stderr, "Error: Definition of plane %s unknown\n", plane);
    exit(1);
  }
}

void mcdis_circle(char *plane, double x, double y, double z, double r){
  printf("MCDISPLAY: circle('%s',%g,%g,%g,%g)\n", plane, x, y, z, r);
}

void mcdis_new_circle(double x, double y, double z, double r, double nx, double ny, double nz){
  printf("MCDISPLAY: new_circle(%g,%g,%g,%g,%g,%g,%g)\n", x, y, z, r, nx, ny, nz);
}


/* Draws a circle with center (x,y,z), radius (r), and in the plane
 * with normal (nx,ny,nz)*/
void mcdis_Circle(double x, double y, double z, double r, double nx, double ny, double nz){
    int i;
    if(nx==0 && ny && nz==0){
        for (i=0;i<24; i++){
            mcdis_line(x+r*sin(i*2*PI/24),y,z+r*cos(i*2*PI/24),
                    x+r*sin((i+1)*2*PI/24),y,z+r*cos((i+1)*2*PI/24));
        }
    }else{
        double mx,my,mz;
        /*generate perpendicular vector using (nx,ny,nz) and (0,1,0)*/
        vec_prod(mx,my,mz, 0,1,0, nx,ny,nz);
        NORM(mx,my,mz);
        /*draw circle*/
        for (i=0;i<24; i++){
            double ux,uy,uz;
            double wx,wy,wz;
            rotate(ux,uy,uz, mx,my,mz, i*2*PI/24, nx,ny,nz);
            rotate(wx,wy,wz, mx,my,mz, (i+1)*2*PI/24, nx,ny,nz);
            mcdis_line(x+ux*r,y+uy*r,z+uz*r,
                    x+wx*r,y+wy*r,z+wz*r);
        }
    }
}


/*  OLD IMPLEMENTATION
    draws a box with center at (x, y, z) and
    width (deltax), height (deltay), length (deltaz) */
void mcdis_legacy_box(double x, double y, double z,
	       double width, double height, double length){

  mcdis_rectangle("xy", x, y, z-length/2, width, height);
  mcdis_rectangle("xy", x, y, z+length/2, width, height);
  mcdis_line(x-width/2, y-height/2, z-length/2,
	     x-width/2, y-height/2, z+length/2);
  mcdis_line(x-width/2, y+height/2, z-length/2,
	     x-width/2, y+height/2, z+length/2);
  mcdis_line(x+width/2, y-height/2, z-length/2,
	     x+width/2, y-height/2, z+length/2);
  mcdis_line(x+width/2, y+height/2, z-length/2,
	     x+width/2, y+height/2, z+length/2);
}

/*  NEW 3D IMPLEMENTATION OF BOX SUPPORTS HOLLOW ALSO
    draws a box with center at (x, y, z) and
    width (deltax), height (deltay), length (deltaz) */
void mcdis_box(double x, double y, double z,
	       double width, double height, double length, double thickness, double nx, double ny, double nz){
  if (mcdotrace==2) {
    printf("MCDISPLAY: box(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g)\n", x, y, z, width, height, length, thickness, nx, ny, nz);
  } else {
    mcdis_legacy_box(x, y, z, width, height, length);
    if (thickness)
      mcdis_legacy_box(x, y, z, width-thickness, height-thickness, length);
  }
}


/* OLD IMPLEMENTATION
Draws a cylinder with center at (x,y,z) with extent (r,height).
 * The cylinder axis is along the vector nx,ny,nz. */
void mcdis_legacy_cylinder( double x, double y, double z,
        double r, double height, int N, double nx, double ny, double nz){
    int i;
    /*no lines make little sense - so trigger the default*/
    if(N<=0) N=5;

    NORM(nx,ny,nz);
    double h_2=height/2.0;
    mcdis_Circle(x+nx*h_2,y+ny*h_2,z+nz*h_2,r,nx,ny,nz);
    mcdis_Circle(x-nx*h_2,y-ny*h_2,z-nz*h_2,r,nx,ny,nz);

    double mx,my,mz;
    /*generate perpendicular vector using (nx,ny,nz) and (0,1,0)*/
    if(nx==0 && ny && nz==0){
        mx=my=0;mz=1;
    }else{
        vec_prod(mx,my,mz, 0,1,0, nx,ny,nz);
        NORM(mx,my,mz);
    }
    /*draw circle*/
    for (i=0; i<24; i++){
        double ux,uy,uz;
        rotate(ux,uy,uz, mx,my,mz, i*2*PI/24, nx,ny,nz);
        mcdis_line(x+nx*h_2+ux*r, y+ny*h_2+uy*r, z+nz*h_2+uz*r,
                 x-nx*h_2+ux*r, y-ny*h_2+uy*r, z-nz*h_2+uz*r);
    }
}

/* NEW 3D IMPLEMENTATION ALSO SUPPORTING HOLLOW
Draws a cylinder with center at (x,y,z) with extent (r,height).
 * The cylinder axis is along the vector nx,ny,nz.*/
void mcdis_cylinder( double x, double y, double z,
        double r, double height, double thickness, double nx, double ny, double nz){
  if (mcdotrace==2) {
      printf("MCDISPLAY: cylinder(%g, %g, %g, %g, %g, %g, %g, %g, %g)\n",
         x, y, z, r, height, thickness, nx, ny, nz);
  } else {
    mcdis_legacy_cylinder(x, y, z,
			  r, height, 12, nx, ny, nz);
  }
}

/* Draws a cone with center at (x,y,z) with extent (r,height).
 * The cone axis is along the vector nx,ny,nz.*/
void mcdis_cone( double x, double y, double z,
        double r, double height, double nx, double ny, double nz){
  if (mcdotrace==2) {
    printf("MCDISPLAY: cone(%g, %g, %g, %g, %g, %g, %g, %g)\n",
       x, y, z, r, height, nx, ny, nz);
  } else {
    mcdis_Circle(x, y, z, r, nx, ny, nz);
    mcdis_Circle(x+0.25*height*nx, y+0.25*height*ny, z+0.25*height*nz, 0.75*r, nx, ny, nz);
    mcdis_Circle(x+0.5*height*nx, y+0.5*height*ny, z+0.5*height*nz, 0.5*r, nx, ny, nz);
    mcdis_Circle(x+0.75*height*nx, y+0.75*height*ny, z+0.75*height*nz, 0.25*r, nx, ny, nz);
    mcdis_line(x, y, z, x+height*nx, y+height*ny, z+height*nz);
  }
}

/* Draws a disc with center at (x,y,z) with extent (r).
 * The disc axis is along the vector nx,ny,nz.*/
void mcdis_disc( double x, double y, double z,
        double r, double nx, double ny, double nz){
  printf("MCDISPLAY: disc(%g, %g, %g, %g, %g, %g, %g)\n",
     x, y, z, r, nx, ny, nz);
}

/* Draws a annulus with center at (x,y,z) with extent (outer_radius) and remove inner_radius.
 * The annulus axis is along the vector nx,ny,nz.*/
void mcdis_annulus( double x, double y, double z,
        double outer_radius, double inner_radius, double nx, double ny, double nz){
  printf("MCDISPLAY: annulus(%g, %g, %g, %g, %g, %g, %g, %g)\n",
     x, y, z, outer_radius, inner_radius, nx, ny, nz);
}

/* draws a sphere with center at (x,y,z) with extent (r)*/
void mcdis_sphere(double x, double y, double z, double r){
  if (mcdotrace==2) {
    printf("MCDISPLAY: sphere(%g,%g,%g,%g)\n", x, y, z, r);
  } else {
    double nx,ny,nz;
    int i;
    int N=12;

    nx=0;ny=0;nz=1;
    mcdis_Circle(x,y,z,r,nx,ny,nz);
    for (i=1;i<N;i++){
        rotate(nx,ny,nz, nx,ny,nz, PI/N, 0,1,0);
        mcdis_Circle(x,y,z,r,nx,ny,nz);
    }
    /*lastly draw a great circle perpendicular to all N circles*/
    //mcdis_Circle(x,y,z,radius,1,0,0);

    for (i=1;i<=N;i++){
        double yy=-r+ 2*r*((double)i/(N+1));
        mcdis_Circle(x,y+yy ,z,  sqrt(r*r-yy*yy) ,0,1,0);
    }
  }
}
/* POLYHEDRON IMPLEMENTATION*/

void mcdis_polyhedron(char *vertices_faces){
  printf("MCDISPLAY: polyhedron %s\n", vertices_faces);
}

/* POLYGON IMPLEMENTATION */
void mcdis_polygon(int count, ...){
  va_list ap;
  double *x,*y,*z;

  double x0=0,y0=0,z0=0; /* Used for centre-of-mass in trace==2 */

  x=malloc(count*sizeof(double));
  y=malloc(count*sizeof(double));
  z=malloc(count*sizeof(double));
  if (!x || !y || !z) {
    fprintf(stderr,"Error initializing polygon set size %i\n",count);
    exit(-1);
  }
  va_start(ap, count);
  // Fallback for trace==1 is multiline, one rank higher
  if (mcdotrace==1) {
    printf("MCDISPLAY: multiline(%i,",count+1);
  }
  
  int j;
  for (j=0; j<count; j++) {
    x[j] = va_arg(ap, double);
    y[j] = va_arg(ap, double);
    z[j] = va_arg(ap, double);
    if (mcdotrace==1) {
      printf("%g,%g,%g,",x[j],y[j],z[j]);
    } else {
      // Calculation of polygon centre of mass
      x0 += x[j]; y0 += y[j]; z0 += z[j];
    }
  }
  va_end(ap);

  /* Patch data for multiline(count+1, ... use 0th point*/
  if (mcdotrace==1) {
    printf("%g,%g,%g)\n",x[0],y[0],z[0]);
  } else {
    x0 /= count; y0 /= count; z0 /= count;
    /* Build up a json string for a "polyhedron" */
    // Estimate size of the JSON string
    const int VERTEX_OVERHEAD = 30;
    const int FACE_OVERHEAD_BASE = 20;
    const int FACE_INDEX_OVERHEAD = 15;
    int estimated_size = 256; // Base size
    estimated_size += count * VERTEX_OVERHEAD;

    int faceSize;
    int vtxSize;
    if (count > 3) {
      /* Split in triangles - as many as polygon rank */
      faceSize=count;
      vtxSize=count+1;
    } else {
      faceSize=1;
      vtxSize=count;
    }
    
    for (int i = 0; i < faceSize;) {
        int num_indices = 3;
        estimated_size += FACE_OVERHEAD_BASE + num_indices * FACE_INDEX_OVERHEAD;
        i += num_indices + 1;
    }

    char *json_string = malloc(estimated_size);
    if (json_string == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    char *ptr = json_string;
    ptr += sprintf(ptr, "{ \"vertices\": [");

    if (count==3) { // Single, basic triangle
      ptr += sprintf(ptr, "[%g, %g, %g], [%g, %g, %g], [%g, %g, %g]", x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2]);
    } else {
      for (int i = 0; i < vtxSize-1; i++) {
        ptr += sprintf(ptr, "[%g, %g, %g]", x[i], y[i], z[i]);
        if (i < vtxSize - 2) {
	  ptr += sprintf(ptr, ", ");
        } else {
	  ptr += sprintf(ptr, ", [%g, %g, %g]", x0, y0, z0);
	}
      }
    }
    ptr += sprintf(ptr, "], \"faces\": [");
    if (count==3) { // Single, basic triangle, 1 face...
      ptr += sprintf(ptr, "{ \"face\": [");
      ptr += sprintf(ptr, "0, 1, 2");
      ptr += sprintf(ptr, "]}");
    } else {
      for (int i = 0; i < faceSize; i++) {
        int num = 3;
        ptr += sprintf(ptr, "{ \"face\": [");
	if (i < faceSize - 1) {
	  ptr += sprintf(ptr, "%d, %d, %d",i,i+1,count);
	} else {
	  ptr += sprintf(ptr, "%d, %d, %d",i,count,0);
	}
	ptr += sprintf(ptr, "]}");
	if (i < faceSize-1) {
	  ptr += sprintf(ptr, ", ");
	}
      }
    }
    ptr += sprintf(ptr, "]}");
    mcdis_polyhedron(json_string);

    free(json_string);
  }
  free(x);free(y);free(z);
}
/* END NEW POLYGON IMPLEMENTATION*/

/*
void mcdis_polygon(double x1, double y1, double z1,
                double x2, double y2, double z2){
  printf("MCDISPLAY: polygon(2,%g,%g,%g,%g,%g,%g)\n",
         x1,y1,z1,x2,y2,z2);
}
*/

/* SECTION: coordinates handling ============================================ */

/*******************************************************************************
* Since we use a lot of geometric calculations using Cartesian coordinates,
* we collect some useful routines here. However, it is also permissible to
* work directly on the underlying struct coords whenever that is most
* convenient (that is, the type Coords is not abstract).
*
* Coordinates are also used to store rotation angles around x/y/z axis.
*
* Since coordinates are used much like a basic type (such as double), the
* structure itself is passed and returned, rather than a pointer.
*
* At compile-time, the values of the coordinates may be unknown (for example
* a motor position). Hence coordinates are general expressions and not simple
* numbers. For this we used the type Coords_exp which has three CExp
* fields. For runtime (or calculations possible at compile time), we use
* Coords which contains three double fields.
*******************************************************************************/

/* coords_set: Assign coordinates. */
Coords coords_set(MCNUM x, MCNUM y, MCNUM z)
{
  Coords a;

  a.x = x;
  a.y = y;
  a.z = z;
  return a;
}

/* coords_get: get coordinates. Required when 'x','y','z' are #defined as ray pars */
Coords coords_get(Coords a, MCNUM *x, MCNUM *y, MCNUM *z)
{
  *x = a.x;
  *y = a.y;
  *z = a.z;
  return a;
}

/* coords_add: Add two coordinates. */
Coords coords_add(Coords a, Coords b)
{
  Coords c;

  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.z = a.z + b.z;
  if (fabs(c.z) < 1e-14) c.z=0.0;
  return c;
}

/* coords_sub: Subtract two coordinates. */
Coords coords_sub(Coords a, Coords b)
{
  Coords c;

  c.x = a.x - b.x;
  c.y = a.y - b.y;
  c.z = a.z - b.z;
  if (fabs(c.z) < 1e-14) c.z=0.0;
  return c;
}

/* coords_neg: Negate coordinates. */
Coords coords_neg(Coords a)
{
  Coords b;

  b.x = -a.x;
  b.y = -a.y;
  b.z = -a.z;
  return b;
}

/* coords_scale: Scale a vector. */
Coords coords_scale(Coords b, double scale) {
  Coords a;

  a.x = b.x*scale;
  a.y = b.y*scale;
  a.z = b.z*scale;
  return a;
}

/* coords_sp: Scalar product: a . b */
double coords_sp(Coords a, Coords b) {
  double value;

  value = a.x*b.x + a.y*b.y + a.z*b.z;
  return value;
}

/* coords_xp: Cross product: a = b x c. */
Coords coords_xp(Coords b, Coords c) {
  Coords a;

  a.x = b.y*c.z - c.y*b.z;
  a.y = b.z*c.x - c.z*b.x;
  a.z = b.x*c.y - c.x*b.y;
  return a;
}

/* coords_len: Gives length of coords set. */
double coords_len(Coords a) {
  return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

/* coords_mirror: Mirror a in plane (through the origin) defined by normal n*/
Coords coords_mirror(Coords a, Coords n) {
  double t = scalar_prod(n.x, n.y, n.z, n.x, n.y, n.z);
  Coords b;
  if (t!=1) {
    t = sqrt(t);
    n.x /= t;
    n.y /= t;
    n.z /= t;
  }
  t=scalar_prod(a.x, a.y, a.z, n.x, n.y, n.z);
  b.x = a.x-2*t*n.x;
  b.y = a.y-2*t*n.y;
  b.z = a.z-2*t*n.z;
  return b;
}

/* coords_print: Print out vector values. */
void coords_print(Coords a) {
  #ifndef OPENACC
  fprintf(stdout, "(%f, %f, %f)\n", a.x, a.y, a.z);
  #endif
  return;
}

mcstatic void coords_norm(Coords* c) {
	double temp = coords_sp(*c,*c);

	// Skip if we will end dividing by zero
	if (temp == 0) return;

	temp = sqrt(temp);

	c->x /= temp;
	c->y /= temp;
	c->z /= temp;
}

/* coords_test_zero: check if zero vector*/
int coords_test_zero(Coords a){
  return ( a.x==0 && a.y==0 && a.z==0 );
}

/*******************************************************************************
* The Rotation type implements a rotation transformation of a coordinate
* system in the form of a double[3][3] matrix.
*
* Contrary to the Coords type in coords.c, rotations are passed by
* reference. Functions that yield new rotations do so by writing to an
* explicit result parameter; rotations are not returned from functions. The
* reason for this is that arrays cannot by returned from functions (though
* structures can; thus an alternative would have been to wrap the
* double[3][3] array up in a struct). Such are the ways of C programming.
*
* A rotation represents the tranformation of the coordinates of a vector when
* changing between coordinate systems that are rotated with respect to each
* other. For example, suppose that coordinate system Q is rotated 45 degrees
* around the Z axis with respect to coordinate system P. Let T be the
* rotation transformation representing a 45 degree rotation around Z. Then to
* get the coordinates of a vector r in system Q, apply T to the coordinates
* of r in P. If r=(1,0,0) in P, it will be (sqrt(1/2),-sqrt(1/2),0) in
* Q. Thus we should be careful when interpreting the sign of rotation angles:
* they represent the rotation of the coordinate systems, not of the
* coordinates (which has opposite sign).
*******************************************************************************/

/*******************************************************************************
* rot_set_rotation: Get transformation for rotation first phx around x axis,
* then phy around y, then phz around z.
*******************************************************************************/
void rot_set_rotation(Rotation t, double phx, double phy, double phz)
{
  if ((phx == 0) && (phy == 0) && (phz == 0)) {
    t[0][0] = 1.0;
    t[0][1] = 0.0;
    t[0][2] = 0.0;
    t[1][0] = 0.0;
    t[1][1] = 1.0;
    t[1][2] = 0.0;
    t[2][0] = 0.0;
    t[2][1] = 0.0;
    t[2][2] = 1.0;
  } else {
    double cx = cos(phx);
    double sx = sin(phx);
    double cy = cos(phy);
    double sy = sin(phy);
    double cz = cos(phz);
    double sz = sin(phz);

    t[0][0] = cy*cz;
    t[0][1] = sx*sy*cz + cx*sz;
    t[0][2] = sx*sz - cx*sy*cz;
    t[1][0] = -cy*sz;
    t[1][1] = cx*cz - sx*sy*sz;
    t[1][2] = sx*cz + cx*sy*sz;
    t[2][0] = sy;
    t[2][1] = -sx*cy;
    t[2][2] = cx*cy;
  }
}

/*******************************************************************************
* rot_test_identity: Test if rotation is identity
*******************************************************************************/
int rot_test_identity(Rotation t)
{
  return (t[0][0] + t[1][1] + t[2][2] == 3);
}

/*******************************************************************************
* rot_mul: Matrix multiplication of transformations (this corresponds to
* combining transformations). After rot_mul(T1, T2, T3), doing T3 is
* equal to doing first T2, then T1.
* Note that T3 must not alias (use the same array as) T1 or T2.
*******************************************************************************/
void rot_mul(Rotation t1, Rotation t2, Rotation t3)
{
  if (rot_test_identity(t1)) {
    rot_copy(t3, t2);
  } else if (rot_test_identity(t2)) {
    rot_copy(t3, t1);
  } else {
    int i,j;
    for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++)
	t3[i][j] = t1[i][0]*t2[0][j] + t1[i][1]*t2[1][j] + t1[i][2]*t2[2][j];
  }
}

/*******************************************************************************
* rot_copy: Copy a rotation transformation (arrays cannot be assigned in C).
*******************************************************************************/
void rot_copy(Rotation dest, Rotation src)
{
  int i,j;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      dest[i][j] = src[i][j];
}

/*******************************************************************************
* rot_transpose: Matrix transposition, which is inversion for Rotation matrices
*******************************************************************************/
void rot_transpose(Rotation src, Rotation dst)
{
  dst[0][0] = src[0][0];
  dst[0][1] = src[1][0];
  dst[0][2] = src[2][0];
  dst[1][0] = src[0][1];
  dst[1][1] = src[1][1];
  dst[1][2] = src[2][1];
  dst[2][0] = src[0][2];
  dst[2][1] = src[1][2];
  dst[2][2] = src[2][2];
}

/*******************************************************************************
* rot_apply: returns t*a
*******************************************************************************/
Coords rot_apply(Rotation t, Coords a)
{
  Coords b;
  if (rot_test_identity(t)) {
    return a;
  } else {
    b.x = t[0][0]*a.x + t[0][1]*a.y + t[0][2]*a.z;
    b.y = t[1][0]*a.x + t[1][1]*a.y + t[1][2]*a.z;
    b.z = t[2][0]*a.x + t[2][1]*a.y + t[2][2]*a.z;
    return b;
  }
}

/**
 * Pretty-printing of rotation matrices.
 */
void rot_print(Rotation rot) {
	printf("[ %4.2f %4.2f %4.2f ]\n",
			rot[0][0], rot[0][1], rot[0][2]);
	printf("[ %4.2f %4.2f %4.2f ]\n",
			rot[1][0], rot[1][1], rot[1][2]);
	printf("[ %4.2f %4.2f %4.2f ]\n\n",
			rot[2][0], rot[2][1], rot[2][2]);
}

/**
 * Vector product: used by vec_prod (mccode-r.h). Use coords_xp for Coords.
 */
void vec_prod_func(double *x, double *y, double *z,
		double x1, double y1, double z1,
		double x2, double y2, double z2) {
    *x = (y1)*(z2) - (y2)*(z1);
    *y = (z1)*(x2) - (z2)*(x1);
    *z = (x1)*(y2) - (x2)*(y1);
}

/**
 * Scalar product: use coords_sp for Coords.
 */
double scalar_prod(
		double x1, double y1, double z1,
		double x2, double y2, double z2) {
	return ((x1 * x2) + (y1 * y2) + (z1 * z2));
}

mcstatic void norm_func(double *x, double *y, double *z) {
	double temp = (*x * *x) + (*y * *y) + (*z * *z);
	if (temp != 0) {
		temp = sqrt(temp);
		*x /= temp;
		*y /= temp;
		*z /= temp;
	}
}


/* SECTION: GPU algorithms ================================================== */


/*
*  Divide-and-conquer strategy for parallelizing this task: Sort absorbed
*  particles last.
*
*   particles:  the particle array, required to checking _absorbed
*   pbuffer:    same-size particle buffer array required for parallel sort
*   len:        sorting area-of-interest size (e.g. from previous calls)
*   buffer_len: total array size
*   flag_split: if set, multiply live particles into absorbed slots, up to buffer_len
*   multiplier: output arg, becomes the  SPLIT multiplier if flag_split is set
*/
#ifdef FUNNEL
long sort_absorb_last(_class_particle* particles, _class_particle* pbuffer, long len, long buffer_len, long flag_split, long* multiplier) {
  #define SAL_THREADS 1024 // num parallel sections
  if (len<SAL_THREADS) return sort_absorb_last_serial(particles, len);

  if (multiplier != NULL) *multiplier = -1; // set default out value for multiplier
  long newlen = 0;
  long los[SAL_THREADS]; // target array startidxs
  long lens[SAL_THREADS]; // target array sublens
  long l = floor(len/(SAL_THREADS-1)); // subproblem_len
  long ll = len - l*(SAL_THREADS-1); // last_subproblem_len

  // TODO: The l vs ll is too simplistic, since ll can become much larger
  // than l, resulting in idling. We should distribute lengths more evenly.

  // step 1: sort sub-arrays
  #pragma acc parallel loop present(particles[0:buffer_len], pbuffer[0:buffer_len])
  for (unsigned long tidx=0; tidx<SAL_THREADS; tidx++) {
    long lo = l*tidx;
    long loclen = l;
    if (tidx==(SAL_THREADS-1)) loclen = ll; // last sub-problem special case
    long i = lo;
    long j = lo + loclen - 1;

    // write into pbuffer at i and j
    #pragma acc loop seq
    while (i < j) {
      #pragma acc loop seq
      while (!particles[i]._absorbed && i<j) {
        pbuffer[i] = particles[i];
        i++;
      }
      #pragma acc loop seq
      while (particles[j]._absorbed && i<j) {
        pbuffer[j] = particles[j];
        j--;
      }
      if (i < j) {
        pbuffer[j] = particles[i];
        pbuffer[i] = particles[j];
        i++;
        j--;
      }
    }
    // transfer edge case
    if (i==j)
      pbuffer[i] = particles[i];

    lens[tidx] = i - lo;
    if (i==j && !particles[i]._absorbed) lens[tidx]++;
  }

  // determine lo's
  long accumlen = 0;
  #pragma acc loop seq
  for (long idx=0; idx<SAL_THREADS; idx++) {
    los[idx] = accumlen;
    accumlen = accumlen + lens[idx];
  }

  // step 2: write non-absorbed sub-arrays to psorted/output from the left
  #pragma acc parallel loop present(pbuffer[0:buffer_len])
  for (unsigned long tidx=0; tidx<SAL_THREADS; tidx++) {
    long j, k;
    #pragma acc loop seq
    for (long i=0; i<lens[tidx]; i++) {
      j = i + l*tidx;
      k = i + los[tidx];
      particles[k] = pbuffer[j];
    }
  }
  //for (int ii=0;ii<accumlen;ii++) printf("%ld ", (psorted[ii]->_absorbed));

  // return (no SPLIT)
  if (flag_split != 1)
    return accumlen;

  // SPLIT - repeat the non-absorbed block N-1 times, where len % accumlen = N + R
  int mult = buffer_len / accumlen; // TODO: possibly use a new arg, bufferlen, rather than len

  // not enough space for full-block split, return
  if (mult <= 1)
    return accumlen;

  // copy non-absorbed block
  #pragma acc parallel loop present(particles[0:buffer_len])
  for (long tidx = 0; tidx < accumlen; tidx++) { // tidx: thread index
    randstate_t randstate[7];
    _class_particle sourcebuffer;
    _class_particle targetbuffer;
    // assign reduced weight to all particles
    particles[tidx].p=particles[tidx].p/mult;
    #pragma acc loop seq
    for (long bidx = 1; bidx < mult; bidx++) { // bidx: block index
      // preserve absorbed particle (for randstate)
      sourcebuffer = particles[bidx*accumlen + tidx];
      // buffer full particle struct
      targetbuffer = particles[tidx];
      // reassign previous randstate
      targetbuffer.randstate[0] = sourcebuffer.randstate[0];
      targetbuffer.randstate[1] = sourcebuffer.randstate[1];
      targetbuffer.randstate[2] = sourcebuffer.randstate[2];
      targetbuffer.randstate[3] = sourcebuffer.randstate[3];
      targetbuffer.randstate[4] = sourcebuffer.randstate[4];
      targetbuffer.randstate[5] = sourcebuffer.randstate[5];
      targetbuffer.randstate[6] = sourcebuffer.randstate[6];
      // apply
      particles[bidx*accumlen + tidx] = targetbuffer;
    }
  }

  // set out split multiplier value
  *multiplier = mult;

  // return expanded array size
  return accumlen * mult;
}

#endif

/*
*  Fallback serial version of the one above.
*/
long sort_absorb_last_serial(_class_particle* particles, long len) {
  long i = 0;
  long j = len - 1;
  _class_particle pbuffer;

  // bubble
  while (i < j) {
    while (!particles[i]._absorbed && i<j) i++;
    while (particles[j]._absorbed && i<j) j--;
    if (i < j) {
      pbuffer = particles[j];
      particles[j] = particles[i];
      particles[i] = pbuffer;
      i++;
      j--;
    }
  }

  // return new length
  if (i==j && !particles[i]._absorbed)
    return i + 1;
  else
    return i;
}

/*******************************************************************************
* mccoordschange: applies rotation to (x y z) and (vx vy vz) and Spin (sx,sy,sz)
*******************************************************************************/
void mccoordschange(Coords a, Rotation t, _class_particle *particle)
{
  Coords b, c;

  b.x = particle->x;
  b.y = particle->y;
  b.z = particle->z;
  c = rot_apply(t, b);
  b = coords_add(c, a);
  particle->x = b.x;
  particle->y = b.y;
  particle->z = b.z;

#if MCCODE_PARTICLE_CODE == 2112
    if (particle->vz != 0.0 || particle->vx != 0.0 || particle->vy != 0.0)
      mccoordschange_polarisation(t, &(particle->vx), &(particle->vy), &(particle->vz));

    if (particle->sz != 0.0 || particle->sx != 0.0 || particle->sy != 0.0)
      mccoordschange_polarisation(t, &(particle->sx), &(particle->sy), &(particle->sz));
#elif MCCODE_PARTICLE_CODE == 22
    if (particle->kz != 0.0 || particle->kx != 0.0 || particle->ky != 0.0)
      mccoordschange_polarisation(t, &(particle->kx), &(particle->ky), &(particle->kz));

    if (particle->Ez != 0.0 || particle->Ex != 0.0 || particle->Ey != 0.0)
      mccoordschange_polarisation(t, &(particle->Ex), &(particle->Ey), &(particle->Ez));
#endif
}

/*******************************************************************************
* mccoordschange_polarisation: applies rotation to vector (sx sy sz)
*******************************************************************************/
void mccoordschange_polarisation(Rotation t, double *sx, double *sy, double *sz)
{
  Coords b, c;

  b.x = *sx;
  b.y = *sy;
  b.z = *sz;
  c = rot_apply(t, b);
  *sx = c.x;
  *sy = c.y;
  *sz = c.z;
}

/* SECTION: vector math  ==================================================== */

/* normal_vec_func: Compute normal vector to (x,y,z). */
void normal_vec(double *nx, double *ny, double *nz,
                double x, double y, double z)
{
  double ax = fabs(x);
  double ay = fabs(y);
  double az = fabs(z);
  double l;
  if(x == 0 && y == 0 && z == 0)
  {
    *nx = 0;
    *ny = 0;
    *nz = 0;
    return;
  }
  if(ax < ay)
  {
    if(ax < az)
    {                           /* Use X axis */
      l = sqrt(z*z + y*y);
      *nx = 0;
      *ny = z/l;
      *nz = -y/l;
      return;
    }
  }
  else
  {
    if(ay < az)
    {                           /* Use Y axis */
      l = sqrt(z*z + x*x);
      *nx = z/l;
      *ny = 0;
      *nz = -x/l;
      return;
    }
  }
  /* Use Z axis */
  l = sqrt(y*y + x*x);
  *nx = y/l;
  *ny = -x/l;
  *nz = 0;
} /* normal_vec */

/*******************************************************************************
 * solve_2nd_order: second order equation solve: A*t^2 + B*t + C = 0
 * solve_2nd_order(&t1, NULL, A,B,C)
 *   returns 0 if no solution was found, or set 't1' to the smallest positive
 *   solution.
 * solve_2nd_order(&t1, &t2, A,B,C)
 *   same as with &t2=NULL, but also returns the second solution.
 * EXAMPLE usage for intersection of a trajectory with a plane in gravitation
 * field (gx,gy,gz):
 * The neutron starts at point r=(x,y,z) with velocityv=(vx vy vz). The plane
 * has a normal vector n=(nx,ny,nz) and contains the point W=(wx,wy,wz).
 * The problem consists in solving the 2nd order equation:
 *      1/2.n.g.t^2 + n.v.t + n.(r-W) = 0
 * so that A = 0.5 n.g; B = n.v; C = n.(r-W);
 * Without acceleration, t=-n.(r-W)/n.v
 ******************************************************************************/
int solve_2nd_order_old(double *t1, double *t2,
                  double A,  double B,  double C)
{
  int ret=0;

  if (!t1) return 0;
  *t1 = 0;
  if (t2) *t2=0;

  if (fabs(A) < 1E-10) /* approximate to linear equation: A ~ 0 */
  {
    if (B) {  *t1 = -C/B; ret=1; if (t2) *t2=*t1; }
    /* else no intersection: A=B=0 ret=0 */
  }
  else
  {
    double D;
    D = B*B - 4*A*C;
    if (D >= 0) /* Delta > 0: two solutions */
    {
      double sD, dt1, dt2;
      sD = sqrt(D);
      dt1 = (-B + sD)/2/A;
      dt2 = (-B - sD)/2/A;
      /* we identify very small values with zero */
      if (fabs(dt1) < 1e-10) dt1=0.0;
      if (fabs(dt2) < 1e-10) dt2=0.0;

      /* now we choose the smallest positive solution */
      if      (dt1<=0.0 && dt2>0.0) ret=2; /* dt2 positive */
      else if (dt2<=0.0 && dt1>0.0) ret=1; /* dt1 positive */
      else if (dt1> 0.0 && dt2>0.0)
      {  if (dt1 < dt2) ret=1; else ret=2; } /* all positive: min(dt1,dt2) */
      /* else two solutions are negative. ret=-1 */
      if (ret==1) { *t1 = dt1;  if (t2) *t2=dt2; }
      else        { *t1 = dt2;  if (t2) *t2=dt1; }
      ret=2;  /* found 2 solutions and t1 is the positive one */
    } /* else Delta <0: no intersection. ret=0 */
  }
  return(ret);
} /* solve_2nd_order */

int solve_2nd_order(double *t0, double *t1, double A, double B, double C){
  int retval=0;
  double sign=copysign(1.0,B);
  double dt0,dt1;

  dt0=0;
  dt1=0;
  if(t1){ *t1=0;}

  /*protect against rounding errors by locally equating DBL_EPSILON with 0*/
  if (fabs(A)<DBL_EPSILON){
    A=0;
  }
  if (fabs(B)<DBL_EPSILON){
    B=0;
  }
  if (fabs(C)<DBL_EPSILON){
    C=0;
  }

  /*check if coefficient are sane*/
  if( A==0  && B==0){
    retval=0;
  }else{
    if(A==0){
      /*equation is linear*/
      dt0=-C/B;
      retval=1;
    }else if (C==0){
      /*one root is 0*/
      if(sign<0){
        dt0=0;dt1=-B/A;
      }else{
        dt0=-B/A;dt1=0;
      }
      retval=2;
    }else{
      /*a regular 2nd order eq. Also works out fine for B==0.*/
      double D;
      D=B*B-4*A*C;
      if (D>=0){
        dt0=(-B - sign*sqrt(B*B-4*A*C))/(2*A);
        dt1=C/(A*dt0);
        retval=2;
      }else{
        /*no real roots*/
        retval=0;
      }
    }
    /*sort the solutions*/
    if (retval==1){
      /*put both solutions in t0 and t1*/
      *t0=dt0;
      if(t1) *t1=dt1;
    }else{
      /*we have two solutions*/
      /*swap if both are positive and t1 smaller than t0 or t1 the only positive*/
      int swap=0;
      if(dt1>0 && ( dt1<dt0 || dt0<=0) ){
        swap=1;
      }
      if (swap){
        *t0=dt1;
        if(t1) *t1=dt0;
      }else{
        *t0=dt0;
        if(t1) *t1=dt0;
      }
    }

  }
  return retval;

} /*solve_2nd_order_improved*/


/*******************************************************************************
 * randvec_target_circle: Choose random direction towards target at (x,y,z)
 * with given radius.
 * If radius is zero, choose random direction in full 4PI, no target.
 ******************************************************************************/
void _randvec_target_circle(double *xo, double *yo, double *zo, double *solid_angle,
        double xi, double yi, double zi, double radius,
        _class_particle* _particle)
{
  double l2, phi, theta, nx, ny, nz, xt, yt, zt, xu, yu, zu;

  if(radius == 0.0)
  {
    /* No target, choose uniformly a direction in full 4PI solid angle. */
    theta = acos(1 - rand0max(2));
    phi = rand0max(2 * PI);
    if(solid_angle)
      *solid_angle = 4*PI;
    nx = 1;
    ny = 0;
    nz = 0;
    yi = sqrt(xi*xi+yi*yi+zi*zi);
    zi = 0;
    xi = 0;
  }
  else
  {
    double costheta0;
    l2 = xi*xi + yi*yi + zi*zi; /* sqr Distance to target. */
    costheta0 = sqrt(l2/(radius*radius+l2));
    if (radius < 0) costheta0 *= -1;
    if(solid_angle)
    {
      /* Compute solid angle of target as seen from origin. */
        *solid_angle = 2*PI*(1 - costheta0);
    }

    /* Now choose point uniformly on circle surface within angle theta0 */
    theta = acos (1 - rand0max(1 - costheta0)); /* radius on circle */
    phi = rand0max(2 * PI); /* rotation on circle at given radius */
    /* Now, to obtain the desired vector rotate (xi,yi,zi) angle theta around a
       perpendicular axis u=i x n and then angle phi around i. */
    if(xi == 0 && zi == 0)
    {
      nx = 1;
      ny = 0;
      nz = 0;
    }
    else
    {
      nx = -zi;
      nz = xi;
      ny = 0;
    }
  }

  /* [xyz]u = [xyz]i x n[xyz] (usually vertical) */
  vec_prod(xu,  yu,  zu, xi, yi, zi,        nx, ny, nz);
  /* [xyz]t = [xyz]i rotated theta around [xyz]u */
  rotate  (xt,  yt,  zt, xi, yi, zi, theta, xu, yu, zu);
  /* [xyz]o = [xyz]t rotated phi around n[xyz] */
  rotate (*xo, *yo, *zo, xt, yt, zt, phi, xi, yi, zi);
}
/* randvec_target_circle */

/*******************************************************************************
 * randvec_target_rect_angular: Choose random direction towards target at
 * (xi,yi,zi) with given ANGULAR dimension height x width. height=phi_x=[0,PI],
 * width=phi_y=[0,2*PI] (radians)
 * If height or width is zero, choose random direction in full 4PI, no target.
 *******************************************************************************/
void _randvec_target_rect_angular(double *xo, double *yo, double *zo, double *solid_angle,
        double xi, double yi, double zi, double width, double height, Rotation A,
        _class_particle* _particle)
{
  double theta, phi, nx, ny, nz, xt, yt, zt, xu, yu, zu;
  Coords tmp;
  Rotation Ainverse;

  rot_transpose(A, Ainverse);

  if(height == 0.0 || width == 0.0)
  {
    randvec_target_circle(xo, yo, zo, solid_angle, xi, yi, zi, 0);
    return;
  }
  else
  {
    if(solid_angle)
    {
      /* Compute solid angle of target as seen from origin. */
      *solid_angle = 2*fabs(width*sin(height/2));
    }

    /* Go to global coordinate system */

    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(Ainverse, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    /* Now choose point uniformly on the unit sphere segment with angle theta/phi */
    phi   = width*randpm1()/2.0;
    theta = asin(randpm1()*sin(height/2.0));
    /* Now, to obtain the desired vector rotate (xi,yi,zi) angle theta around
       n, and then phi around u. */
    if(xi == 0 && zi == 0)
    {
      nx = 1;
      ny = 0;
      nz = 0;
    }
    else
    {
      nx = -zi;
      nz = xi;
      ny = 0;
    }
  }

  /* [xyz]u = [xyz]i x n[xyz] (usually vertical) */
  vec_prod(xu,  yu,  zu, xi, yi, zi,        nx, ny, nz);
  /* [xyz]t = [xyz]i rotated theta around [xyz]u */
  rotate  (xt,  yt,  zt, xi, yi, zi, theta, nx, ny, nz);
  /* [xyz]o = [xyz]t rotated phi around n[xyz] */
  rotate (*xo, *yo, *zo, xt, yt, zt, phi, xu,  yu,  zu);

  /* Go back to local coordinate system */
  tmp = coords_set(*xo, *yo, *zo);
  tmp = rot_apply(A, tmp);
  coords_get(tmp, &*xo, &*yo, &*zo);
}
/* randvec_target_rect_angular */

/*******************************************************************************
 * randvec_target_rect_real: Choose random direction towards target at (xi,yi,zi)
 * with given dimension height x width (in meters !).
 *
 * Local emission coordinate is taken into account and corrected for 'order' times.
 * (See remarks posted to mcstas-users by George Apostolopoulus <gapost@ipta.demokritos.gr>)
 *
 * If height or width is zero, choose random direction in full 4PI, no target.
 *
 * Traditionally, this routine had the name randvec_target_rect - this is now a
 * a define (see mcstas-r.h) pointing here. If you use the old rouine, you are NOT
 * taking the local emmission coordinate into account.
*******************************************************************************/
void _randvec_target_rect_real(double *xo, double *yo, double *zo, double *solid_angle,
        double xi, double yi, double zi,
        double width, double height, Rotation A,
        double lx, double ly, double lz, int order,
        _class_particle* _particle)
{
  double dx, dy, dist, dist_p, nx, ny, nz, mx, my, mz, n_norm, m_norm;
  double cos_theta;
  Coords tmp;
  Rotation Ainverse;

  rot_transpose(A, Ainverse);

  if(height == 0.0 || width == 0.0)
  {
    randvec_target_circle(xo, yo, zo, solid_angle,
               xi, yi, zi, 0);
    return;
  }
  else
  {
    /* Now choose point uniformly on rectangle within width x height */
    dx = width*randpm1()/2.0;
    dy = height*randpm1()/2.0;

    /* Determine distance to target plane*/
    dist = sqrt(xi*xi + yi*yi + zi*zi);
    /* Go to global coordinate system */

    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(Ainverse, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    /* Determine vector normal to trajectory axis (z) and gravity [0 1 0] */
    vec_prod(nx, ny, nz, xi, yi, zi, 0, 1, 0);

    /* This now defines the x-axis, normalize: */
    n_norm=sqrt(nx*nx + ny*ny + nz*nz);
    nx = nx/n_norm;
    ny = ny/n_norm;
    nz = nz/n_norm;

    /* Now, determine our y-axis (vertical in many cases...) */
    vec_prod(mx, my, mz, xi, yi, zi, nx, ny, nz);
    m_norm=sqrt(mx*mx + my*my + mz*mz);
    mx = mx/m_norm;
    my = my/m_norm;
    mz = mz/m_norm;

    /* Our output, random vector can now be defined by linear combination: */

    *xo = xi + dx * nx + dy * mx;
    *yo = yi + dx * ny + dy * my;
    *zo = zi + dx * nz + dy * mz;

    /* Go back to local coordinate system */
    tmp = coords_set(*xo, *yo, *zo);
    tmp = rot_apply(A, tmp);
    coords_get(tmp, &*xo, &*yo, &*zo);

    /* Go back to local coordinate system */
    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(A, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    if (solid_angle) {
      /* Calculate vector from local point to remote random point */
      lx = *xo - lx;
      ly = *yo - ly;
      lz = *zo - lz;
      dist_p = sqrt(lx*lx + ly*ly + lz*lz);

      /* Adjust the 'solid angle' */
      /* 1/r^2 to the chosen point times cos(\theta) between the normal */
      /* vector of the target rectangle and direction vector of the chosen point. */
      cos_theta = (xi * lx + yi * ly + zi * lz) / (dist * dist_p);
      *solid_angle = width * height / (dist_p * dist_p);
      int counter;
      for (counter = 0; counter < order; counter++) {
        *solid_angle = *solid_angle * cos_theta;
      }
    }
  }
}
/* randvec_target_rect_real */


/* SECTION: random numbers ==================================================

  How to add a new RNG:

  - Use an rng with a manegable state vector, e.g. of lengt 4 or 7. The state
  will sit on the particle struct as a "randstate_t state[RANDSTATE_LEN]"
  - If the rng has a long state (as MT), set an empty "srandom" and initialize
  it explicitly using the appropriate define (RNG_ALG)
  - Add a seed and a random function (the transforms will be reused)
  - Write the proper defines in mccode-r.h, e.g. randstate_t and RANDSTATE_LEN,
  srandom and random.
  - Compile using -DRNG_ALG=<selector int value>

============================================================================= */


/* "Mersenne Twister", by Makoto Matsumoto and Takuji Nishimura. */
/* See http://www.math.keio.ac.jp/~matumoto/emt.html for original source. */
/*
   A C-program for MT19937, with initialization improved 2002/1/26.
   Coded by Takuji Nishimura and Makoto Matsumoto.

   Before using, initialize the state by using mt_srandom(seed)
   or init_by_array(init_key, key_length).

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote
        products derived from this software without specific prior written
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   http://www.math.keio.ac.jp/matumoto/emt.html
   email: matumoto@math.keio.ac.jp
*/
#include <stdio.h>
#include <stdint.h>   // for uint32_t
#include <stddef.h>   // for size_t

/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfU   /* constant vector a */
#define UPPER_MASK 0x80000000U /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffU /* least significant r bits */

static uint32_t mt[N]; /* the array for the state vector  */
static int mti = N + 1; /* mti==N+1 means mt[N] is not initialized */

// Required for compatibility with common RNG interface (e.g., kiss/mt polymorphism)
void mt_srandom_empty(void) {}

// Initializes mt[N] with a seed
void mt_srandom(uint32_t seed) {
    mt[0] = seed;
    for (mti = 1; mti < N; mti++) {
        mt[mti] = 1812433253U * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti;
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        mt[mti] &= 0xffffffffU;
        /* for >32 bit machines */
    }
}
/* Initialize by an array with array-length.
   Init_key is the array for initializing keys.
   key_length is its length. */
void init_by_array(uint32_t init_key[], size_t key_length) {
    size_t i = 1, j = 0, k;
    mt_srandom(19650218U);
    k = (N > key_length ? N : key_length);
    for (; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525U))
              + init_key[j] + (uint32_t)j;
        mt[i] &= 0xffffffffU;
        i++; j++;
        if (i >= N) { mt[0] = mt[N - 1]; i = 1; }
        if (j >= key_length) j = 0;
    }
    for (k = N - 1; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941U))
              - (uint32_t)i;
        mt[i] &= 0xffffffffU;
        i++;
        if (i >= N) { mt[0] = mt[N - 1]; i = 1; }
    }
    mt[0] = 0x80000000U; /* MSB is 1; ensuring non-zero initial array */
}

// Generates a random number on [0, 0xffffffff]-interval
uint32_t mt_random(void) {
    uint32_t y;
    static const uint32_t mag01[2] = { 0x0U, MATRIX_A };
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= N) { /* generate N words at one time */
        int kk;

        if (mti == N + 1)   /* if mt_srandom() has not been called, */ 
            mt_srandom(5489U);  /* a default initial seed is used */

        for (kk = 0; kk < N - M; kk++) {
            y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
            mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1U];
        }
        for (; kk < N - 1; kk++) {
            y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
            mt[kk] = mt[kk + (M - N)] ^ (y >> 1) ^ mag01[y & 0x1U];
        }
        y = (mt[N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
        mt[N - 1] = mt[M - 1] ^ (y >> 1) ^ mag01[y & 0x1U];

        mti = 0;
    }

    y = mt[mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680U;
    y ^= (y << 15) & 0xefc60000U;
    y ^= (y >> 18);

    return y;
}
#undef N
#undef M
#undef MATRIX_A
#undef UPPER_MASK
#undef LOWER_MASK
/* End of "Mersenne Twister". */


/*
KISS

 From: http://www.helsbreth.org/random/rng_kiss.html
 Scott Nelson 1999

 Based on Marsaglia's KISS or (KISS+SWB) <http://www.cs.yorku.ca/~oz/marsaglia-
rng.html>

 KISS - Keep it Simple Stupid PRNG

 the idea is to use simple, fast, individually promising
 generators to get a composite that will be fast, easy to code
 have a very long period and pass all the tests put to it.
 The three components of KISS are
        x(n)=a*x(n-1)+1 mod 2^32
        y(n)=y(n-1)(I+L^13)(I+R^17)(I+L^5),
        z(n)=2*z(n-1)+z(n-2) +carry mod 2^32
 The y's are a shift register sequence on 32bit binary vectors
 period 2^32-1;
 The z's are a simple multiply-with-carry sequence with period
 2^63+2^32-1.  The period of KISS is thus
      2^32*(2^32-1)*(2^63+2^32-1) > 2^127

 In 2025 adapted for consistent 64-bit behavior across platforms.
*/

/* the KISS state is stored as a vector of 7 uint64_t        */
/*   0  1  2  3  4      5  6   */
/* [ x, y, z, w, carry, k, m ] */

uint64_t *kiss_srandom(uint64_t state[7], uint64_t seed) {
    if (seed == 0) seed = 1ull;
    state[0] = seed | 1ull; // x
    state[1] = seed | 2ull; // y
    state[2] = seed | 4ull; // z
    state[3] = seed | 8ull; // w
    state[4] = 0ull;        // carry
    state[5] = 0ull;        // k
    state[6] = 0ull;        // m
    return state;
}

uint64_t kiss_random(uint64_t state[7]) {
    // Linear congruential generator
    state[0] = state[0] * 69069ull + 1ull;

    // Xorshift
    state[1] ^= state[1] << 13ull;
    state[1] ^= state[1] >> 17ull;
    state[1] ^= state[1] << 5ull;

    // Multiply-with-carry
    state[5] = (state[2] >> 2ull) + (state[3] >> 3ull) + (state[4] >> 2ull);
    state[6] = state[3] + state[3] + state[2] + state[4];
    state[2] = state[3];
    state[3] = state[6];
    state[4] = state[5] >> 62ull;  // Top bit of carry (adjusted for 64-bit)

    return state[0] + state[1] + state[3];
}
/* end of "KISS" rng */


/* FAST KISS in another implementation (Hundt) */

//////////////////////////////////////////////////////////////////////////////
// fast keep it simple stupid generator
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Thomas Mueller hash for initialization of rngs
// http://stackoverflow.com/questions/664014/
//        what-integer-hash-function-are-good-that-accepts-an-integer-hash-key
//////////////////////////////////////////////////////////////////////////////
randstate_t _hash(randstate_t x) {
  x = ((x >> 16) ^ x) * (randstate_t)0x45d9f3b;
  x = ((x >> 16) ^ x) * (randstate_t)0x45d9f3b;
  x = ((x >> 16) ^ x);
  return x;
}


// SECTION: random number transforms ==========================================



// generate a random number from normal law
double _randnorm(randstate_t* state)
{
  static double v1, v2, s; /* removing static breaks comparison with McStas <= 2.5 */
  static int phase = 0;
  double X, u1, u2;

  if(phase == 0)
  {
    do
    {
      u1 = _rand01(state);
      u2 = _rand01(state);
      v1 = 2*u1 - 1;
      v2 = 2*u2 - 1;
      s = v1*v1 + v2*v2;
    } while(s >= 1 || s == 0);

    X = v1*sqrt(-2*log(s)/s);
  }
  else
  {
    X = v2*sqrt(-2*log(s)/s);
  }

  phase = 1 - phase;
  return X;
}
// another one
double _randnorm2(randstate_t* state) {
  double x, y, r;
  do {
      x = 2.0 * _rand01(state) - 1.0;
      y = 2.0 * _rand01(state) - 1.0;
      r = x*x + y*y;
  } while (r == 0.0 || r >= 1.0);
  return x * sqrt((-2.0 * log(r)) / r);
}

// Generate a random number from -1 to 1 with triangle distribution
double _randtriangle(randstate_t* state) {
	double randnum = _rand01(state);
	if (randnum>0.5) return(1-sqrt(2*(randnum-0.5)));
	else return(sqrt(2*randnum)-1);
}
double _rand01(randstate_t* state) {
	double randnum;
	randnum = (double) _random();
  // TODO: can we mult instead of div?
	randnum /= (double) MC_RAND_MAX + 1;
	return randnum;
}
// Return a random number between 1 and -1
double _randpm1(randstate_t* state) {
	double randnum;
	randnum = (double) _random();
	randnum /= ((double) MC_RAND_MAX + 1) / 2;
	randnum -= 1;
	return randnum;
}
// Return a random number between 0 and max.
double _rand0max(double max, randstate_t* state) {
	double randnum;
	randnum = (double) _random();
	randnum /= ((double) MC_RAND_MAX + 1) / max;
	return randnum;
}
// Return a random number between min and max.
double _randminmax(double min, double max, randstate_t* state) {
	return _rand0max(max - min, state) + max;
}


/* SECTION: main and signal handlers ======================================== */

/*******************************************************************************
* mchelp: displays instrument executable help with possible options
*******************************************************************************/
static void
mchelp(char *pgmname)
{
  int i;

  fprintf(stderr, "%s (%s) instrument simulation, generated with " MCCODE_STRING " (" MCCODE_DATE ")\n", instrument_name, instrument_source);
  fprintf(stderr, "Usage: %s [options] [parm=value ...]\n", pgmname);
  fprintf(stderr,
"Options are:\n"
"  -s SEED   --seed=SEED      Set random seed (must be != 0)\n"
"  -n COUNT  --ncount=COUNT   Set number of particles to simulate.\n"
"  -d DIR    --dir=DIR        Put all data files in directory DIR.\n"
"  -a        --append         Append data files to those in directory DIR.\n"	  
"  -t        --trace          Enable trace of " MCCODE_PARTICLE "s through instrument.\n"
"                             (Use -t=2 or --trace=2 for modernised mcdisplay rendering)\n"
"  -g        --gravitation    Enable gravitation for all trajectories.\n"
"  --no-output-files          Do not write any data files.\n"
"  -h        --help           Show this help message.\n"
"  -i        --info           Detailed instrument information.\n"
"  --list-parameters          Print the instrument parameters to standard out\n"
"  -y        --yes            Assume default values for all parameters with a default\n"
"  --meta-list                Print names of components which defined metadata\n"
"  --meta-defined COMP[:NAME] Print component defined metadata names, or (0,1) if NAME provided\n"
"  --meta-type COMP:NAME      Print metadata format type specified in definition\n"
"  --meta-data COMP:NAME      Print the metadata text\n"
"  --source                   Show the instrument code which was compiled.\n"
#ifdef OPENACC
"\n"
"  --vecsize                  OpenACC vector-size (default: 128)\n"
"  --numgangs                 Number of OpenACC gangs (default: 7813)\n"
"  --gpu_innerloop            Maximum rays to process pr. OpenACC \n"
"                             kernel run (default: 2147483647)\n"
"\n"
#endif
"\n"
"  --bufsiz                   Monitor_nD list/buffer-size (default: 1000000)\n"
"  --format=FORMAT            Output data files using FORMAT="
   FLAVOR_UPPER
#ifdef USE_NEXUS
   " NEXUS\n"
"  --IDF                      Embed an xml-formatted IDF instrument definition\n"
"                             in the NeXus file (if existent in .)\n\n"
#else
"\n\n"
#endif
);
#ifdef USE_MPI
  fprintf(stderr,
  "This instrument has been compiled with MPI support.\n  Use 'mpirun %s [options] [parm=value ...]'.\n", pgmname);
#endif
#ifdef OPENACC
  fprintf(stderr,
  "This instrument has been compiled with NVIDIA GPU support through OpenACC.\n  Running on systems without such devices will lead to segfaults.\nFurter, fprintf, sprintf and printf have been removed from any component TRACE.\n");
#endif

  if(numipar > 0)
  {
    fprintf(stderr, "Instrument parameters are:\n");
    for(i = 0; i < numipar; i++)
      if (mcinputtable[i].val && strlen(mcinputtable[i].val))
        fprintf(stderr, "  %-16s(%s) [default='%s']\n", mcinputtable[i].name,
        (*mcinputtypes[mcinputtable[i].type].parminfo)(mcinputtable[i].name),
        mcinputtable[i].val);
      else
        fprintf(stderr, "  %-16s(%s)\n", mcinputtable[i].name,
        (*mcinputtypes[mcinputtable[i].type].parminfo)(mcinputtable[i].name));
  }

#ifndef NOSIGNALS
  fprintf(stderr, "Known signals are: "
#ifdef SIGUSR1
  "USR1 (status) "
#endif
#ifdef SIGUSR2
  "USR2 (save) "
#endif
#ifdef SIGBREAK
  "BREAK (save) "
#endif
#ifdef SIGTERM
  "TERM (save and exit)"
#endif
  "\n");
#endif /* !NOSIGNALS */
} /* mchelp */


/* mcshowhelp: show help and exit with 0 */
static void
mcshowhelp(char *pgmname)
{
  mchelp(pgmname);
  exit(0);
}

/* mcusage: display usage when error in input arguments and exit with 1 */
static void
mcusage(char *pgmname)
{
  fprintf(stderr, "Error: incorrect command line arguments\n");
  mchelp(pgmname);
  exit(1);
}

/* mcenabletrace: enable trace/mcdisplay or error if requires recompile */
static void
mcenabletrace(int mode)
{
 if(traceenabled) {
  mcdotrace = mode;
  #pragma acc update device ( mcdotrace )
 } else {
   if (mode>0) {
     fprintf(stderr,
	     "Error: trace not enabled (mcenabletrace)\n"
	     "Please re-run the " MCCODE_NAME " compiler "
	     "with the --trace option, or rerun the\n"
	     "C compiler with the MC_TRACE_ENABLED macro defined.\n");
     exit(1);
   }
 }
}

/*******************************************************************************
* mcreadparams: request parameters from the prompt (or use default)
*******************************************************************************/
void
mcreadparams(void)
{
  int i,j,status;
  static char buf[CHAR_BUF_LENGTH];
  char *p;
  int len;

  MPI_MASTER(printf("Instrument parameters for %s (%s)\n",
                    instrument_name, instrument_source));

  for(i = 0; mcinputtable[i].name != 0; i++)
  {
    do
    {
      MPI_MASTER(
                 if (mcinputtable[i].val && strlen(mcinputtable[i].val))
                   printf("Set value of instrument parameter %s (%s) [default='%s']:\n",
                          mcinputtable[i].name,
                          (*mcinputtypes[mcinputtable[i].type].parminfo)
                          (mcinputtable[i].name), mcinputtable[i].val);
                 else
                   printf("Set value of instrument parameter %s (%s):\n",
                          mcinputtable[i].name,
                          (*mcinputtypes[mcinputtable[i].type].parminfo)
                          (mcinputtable[i].name));
                 fflush(stdout);
                 );
#ifdef USE_MPI
      if(mpi_node_rank == mpi_node_root)
        {
          p = fgets(buf, CHAR_BUF_LENGTH, stdin);
          if(p == NULL)
            {
              fprintf(stderr, "Error: empty input for paramater %s (mcreadparams)\n", mcinputtable[i].name);
              exit(1);
            }
        }
      else
        p = buf;
      MPI_Bcast(buf, CHAR_BUF_LENGTH, MPI_CHAR, mpi_node_root, MPI_COMM_WORLD);
#else /* !USE_MPI */
      p = fgets(buf, CHAR_BUF_LENGTH, stdin);
      if(p == NULL)
        {
          fprintf(stderr, "Error: empty input for paramater %s (mcreadparams)\n", mcinputtable[i].name);
          exit(1);
        }
#endif /* USE_MPI */
      len = strlen(buf);
      if (!len || (len == 1 && (buf[0] == '\n' || buf[0] == '\r')))
      {
        if (mcinputtable[i].val && strlen(mcinputtable[i].val)) {
          strncpy(buf, mcinputtable[i].val, CHAR_BUF_LENGTH);  /* use default value */
          len = strlen(buf);
        }
      }
      for(j = 0; j < 2; j++)
      {
        if(len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r'))
        {
          len--;
          buf[len] = '\0';
        }
      }

      status = (*mcinputtypes[mcinputtable[i].type].getparm)
                   (buf, mcinputtable[i].par);
      if(!status)
      {
        (*mcinputtypes[mcinputtable[i].type].error)(mcinputtable[i].name, buf);
        if (!mcinputtable[i].val || strlen(mcinputtable[i].val)) {
          fprintf(stderr, "       Change %s default value in instrument definition.\n", mcinputtable[i].name);
          exit(1);
        }
      }
    } while(!status);
  }
} /* mcreadparams */

/*******************************************************************************
* mcparseoptions: parse command line arguments (options, parameters)
*******************************************************************************/
void
mcparseoptions(int argc, char *argv[])
{
  int i, j;
  char *p;
  int paramset = 0, *paramsetarray;
  char *usedir=NULL;

  /* Add one to numipar to avoid allocating zero size memory block. */
  paramsetarray = (int*)malloc((numipar + 1)*sizeof(*paramsetarray));
  if(paramsetarray == NULL)
  {
    fprintf(stderr, "Error: insufficient memory (mcparseoptions)\n");
    exit(1);
  }
  for(j = 0; j < numipar; j++)
    {
      paramsetarray[j] = 0;
      if (mcinputtable[j].val != NULL && strlen(mcinputtable[j].val))
      {
        int  status;
        char buf[CHAR_BUF_LENGTH];
        strncpy(buf, mcinputtable[j].val, CHAR_BUF_LENGTH);
        status = (*mcinputtypes[mcinputtable[j].type].getparm)
                   (buf, mcinputtable[j].par);
        if(!status) fprintf(stderr, "Invalid '%s' default value %s in instrument definition (mcparseoptions)\n", mcinputtable[j].name, buf);
        else paramsetarray[j] = 1;
      } else {
        (*mcinputtypes[mcinputtable[j].type].getparm)
          (NULL, mcinputtable[j].par);
        paramsetarray[j] = 0;
      }
    }
  for(i = 1; i < argc; i++)
  {
    if(!strcmp("-s", argv[i]) && (i + 1) < argc)
      mcsetseed(argv[++i]);
    else if(!strncmp("-s", argv[i], 2))
      mcsetseed(&argv[i][2]);
    else if(!strcmp("--seed", argv[i]) && (i + 1) < argc)
      mcsetseed(argv[++i]);
    else if(!strncmp("--seed=", argv[i], 7))
      mcsetseed(&argv[i][7]);
    else if(!strcmp("-n", argv[i]) && (i + 1) < argc)
      mcsetn_arg(argv[++i]);
    else if(!strncmp("-n", argv[i], 2))
      mcsetn_arg(&argv[i][2]);
    else if(!strcmp("--ncount", argv[i]) && (i + 1) < argc)
      mcsetn_arg(argv[++i]);
    else if(!strncmp("--ncount=", argv[i], 9))
      mcsetn_arg(&argv[i][9]);
    else if(!strcmp("-d", argv[i]) && (i + 1) < argc)
      usedir=argv[++i];  /* will create directory after parsing all arguments (end of this function) */
    else if(!strncmp("-d", argv[i], 2))
      usedir=&argv[i][2];
    else if(!strcmp("--dir", argv[i]) && (i + 1) < argc)
      usedir=argv[++i];
    else if(!strncmp("-a", argv[i], 2))
      mcappend = 1;
    else if(!strcmp("--append", argv[i]))
      mcappend = 1;
    else if(!strncmp("--dir=", argv[i], 6))
      usedir=&argv[i][6];
    else if(!strcmp("-h", argv[i]))
      mcshowhelp(argv[0]);
    else if(!strcmp("--help", argv[i]) || !strcmp("--version", argv[i]))
      mcshowhelp(argv[0]);
    else if(!strcmp("-i", argv[i])) {
      mcformat=FLAVOR_UPPER;
      mcinfo();
    }
    else if(!strcmp("--info", argv[i]))
      mcinfo();
    else if (!strcmp("--list-parameters", argv[i]))
      mcparameterinfo();
    else if (!strcmp("--meta-list", argv[i]) && ((i+1) >= argc || argv[i+1][0] == '-')){
      //printf("Components with metadata defined:\n");
      exit(metadata_table_print_all_components(num_metadata, metadata_table) == 0);
    }
    else if (!strcmp("--meta-defined", argv[i]) && (i+1) < argc){
      exit(metadata_table_print_component_keys(num_metadata, metadata_table, argv[i+1]) == 0);
    }
    else if (!strcmp("--meta-type", argv[i]) && (i+1) < argc){
      char * literal_type = metadata_table_type(num_metadata, metadata_table, argv[i+1]);
      if (literal_type == NULL) exit(1);
      printf("%s\n", literal_type);
      exit(0);
    }
    else if (!strcmp("--meta-data", argv[i]) && (i+1) < argc){
      char * literal = metadata_table_literal(num_metadata, metadata_table, argv[i+1]);
      if (literal == NULL) exit(1);
      printf("%s\n", literal);
      exit(0);
    }
    else if(!strncmp("--trace=", argv[i], 8)) {
      mcenabletrace(atoi(&argv[i][8]));
    } else if(!strncmp("-t=", argv[i], 3) || !strcmp("--verbose", argv[i])) {
      mcenabletrace(atoi(&argv[i][3]));
    } else if(!strcmp("-t", argv[i]))
      mcenabletrace(1);
    else if(!strcmp("--trace", argv[i]) || !strcmp("--verbose", argv[i]))
      mcenabletrace(1);
    else if(!strcmp("--gravitation", argv[i]))
      mcgravitation = 1;
    else if(!strcmp("-g", argv[i]))
      mcgravitation = 1;
    else if(!strcmp("--yes", argv[i]))
      mcusedefaults = 1;
    else if(!strcmp("-y", argv[i]))
      mcusedefaults = 1;
    else if(!strncmp("--format=", argv[i], 9)) {
      mcformat=&argv[i][9];
    }
    else if(!strcmp("--format", argv[i]) && (i + 1) < argc) {
      mcformat=argv[++i];
    }
#ifdef USE_NEXUS
    else if(!strcmp("--IDF", argv[i])) {
      mcnexus_embed_idf = 1;
    }
#endif
    else if(!strncmp("--vecsize=", argv[i], 10)) {
      vecsize=atoi(&argv[i][10]);
    }    
    else if(!strcmp("--vecsize", argv[i]) && (i + 1) < argc) {
      vecsize=atoi(argv[++i]);
    }
    else if(!strncmp("--bufsiz=", argv[i], 9)) {
      MONND_BUFSIZ=atoi(&argv[i][9]);
    }
    else if(!strcmp("--bufsiz", argv[i]) && (i + 1) < argc) {
      MONND_BUFSIZ=atoi(argv[++i]);
    }
    else if(!strncmp("--numgangs=", argv[i], 11)) {
      numgangs=atoi(&argv[i][11]);
    }
    else if(!strcmp("--numgangs", argv[i]) && (i + 1) < argc) {
      numgangs=atoi(argv[++i]);
    }
    else if(!strncmp("--gpu_innerloop=", argv[i], 16)) {
      gpu_innerloop=(long)strtod(&argv[i][16], NULL);
    }
    else if(!strcmp("--gpu_innerloop", argv[i]) && (i + 1) < argc) {
      gpu_innerloop=(long)strtod(argv[++i], NULL);
    }

    else if(!strcmp("--no-output-files", argv[i]))
      mcdisable_output_files = 1;
    else if(!strcmp("--source", argv[i])) {
      printf("/* Source code %s from %s: */\n"
        "/******************************************************************************/\n"
        "%s\n"
        "/******************************************************************************/\n"
        "/* End of source code %s from %s */\n",
        instrument_name, instrument_source, instrument_code,
        instrument_name, instrument_source);
      exit(1);
    }
    else if(argv[i][0] != '-' && (p = strchr(argv[i], '=')) != NULL)
    {
      *p++ = '\0';

      for(j = 0; j < numipar; j++)
        if(!strcmp(mcinputtable[j].name, argv[i]))
        {
          int status;
          status = (*mcinputtypes[mcinputtable[j].type].getparm)(p,
                        mcinputtable[j].par);
          if(!status || !strlen(p))
          {
            (*mcinputtypes[mcinputtable[j].type].error)
              (mcinputtable[j].name, p);
            exit(1);
          }
          paramsetarray[j] = 1;
          paramset = 1;
          break;
        }
      if(j == numipar)
      {                                /* Unrecognized parameter name */
        fprintf(stderr, "Error: unrecognized parameter %s (mcparseoptions)\n", argv[i]);
        exit(1);
      }
    }
    else if(argv[i][0] == '-') {
      fprintf(stderr, "Error: unrecognized option argument %s (mcparseoptions). Ignored.\n", argv[i++]);
    }
    else {
      fprintf(stderr, "Error: unrecognized argument %s (mcparseoptions). Aborting.\n", argv[i]);
      mcusage(argv[0]);
    }
  }
  if (mcusedefaults) {
    MPI_MASTER(
     printf("Using all default parameter values\n");
    );
    for(j = 0; j < numipar; j++) {
      int status;
      if(mcinputtable[j].val && strlen(mcinputtable[j].val)){
	status = (*mcinputtypes[mcinputtable[j].type].getparm)(mcinputtable[j].val,
                        mcinputtable[j].par);
	paramsetarray[j] = 1;
	paramset = 1;
      }
    }
  }
  if(!paramset)
    mcreadparams();                /* Prompt for parameters if not specified. */
  else
  {
    for(j = 0; j < numipar; j++)
      if(!paramsetarray[j])
      {
        fprintf(stderr, "Error: Instrument parameter %s left unset (mcparseoptions)\n",
                mcinputtable[j].name);
        exit(1);
      }
  }
  free(paramsetarray);
#ifdef USE_MPI
  if (mcdotrace) mpi_node_count=1; /* disable threading when in trace mode */
#endif
  if (usedir && strlen(usedir) && !mcdisable_output_files) mcuse_dir(usedir);
} /* mcparseoptions */

#ifndef NOSIGNALS
/*******************************************************************************
* sighandler: signal handler that makes simulation stop, and save results
*******************************************************************************/
void sighandler(int sig)
{
  /* MOD: E. Farhi, Sep 20th 2001: give more info */
  time_t t1, t0;
#define SIG_SAVE 0
#define SIG_TERM 1
#define SIG_STAT 2
#define SIG_ABRT 3

  printf("\n# " MCCODE_STRING ": [pid %i] Signal %i detected", getpid(), sig);
#ifdef USE_MPI
  printf(" [proc %i]", mpi_node_rank);
#endif
#if defined(SIGUSR1) && defined(SIGUSR2) && defined(SIGKILL)
  if (!strcmp(mcsig_message, "sighandler") && (sig != SIGUSR1) && (sig != SIGUSR2))
  {
    printf("\n# Fatal : unrecoverable loop ! Suicide (naughty boy).\n");
    kill(0, SIGKILL); /* kill myself if error occurs within sighandler: loops */
  }
#endif
  switch (sig) {
#ifdef SIGINT
    case SIGINT : printf(" SIGINT (interrupt from terminal, Ctrl-C)"); sig = SIG_TERM; break;
#endif
#ifdef SIGILL
    case SIGILL  : printf(" SIGILL (Illegal instruction)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGFPE
    case SIGFPE  : printf(" SIGFPE (Math Error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGSEGV
    case SIGSEGV : printf(" SIGSEGV (Mem Error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGTERM
    case SIGTERM : printf(" SIGTERM (Termination)"); sig = SIG_TERM; break;
#endif
#ifdef SIGABRT
    case SIGABRT : printf(" SIGABRT (Abort)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGQUIT
    case SIGQUIT : printf(" SIGQUIT (Quit from terminal)"); sig = SIG_TERM; break;
#endif
#ifdef SIGTRAP
    case SIGTRAP : printf(" SIGTRAP (Trace trap)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGPIPE
    case SIGPIPE : printf(" SIGPIPE (Broken pipe)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGUSR1
    case SIGUSR1 : printf(" SIGUSR1 (Display info)"); sig = SIG_STAT; break;
#endif
#ifdef SIGUSR2
    case SIGUSR2 : printf(" SIGUSR2 (Save simulation)"); sig = SIG_SAVE; break;
#endif
#ifdef SIGHUP
    case SIGHUP  : printf(" SIGHUP (Hangup/update)"); sig = SIG_SAVE; break;
#endif
#ifdef SIGBUS
    case SIGBUS  : printf(" SIGBUS (Bus error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGURG
    case SIGURG  : printf(" SIGURG (Urgent socket condition)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGBREAK
    case SIGBREAK: printf(" SIGBREAK (Break signal, Ctrl-Break)"); sig = SIG_SAVE; break;
#endif
    default : printf(" (look at signal list for signification)"); sig = SIG_ABRT; break;
  }
  printf("\n");
  printf("# Simulation: %s (%s) \n", instrument_name, instrument_source);
  printf("# Breakpoint: %s ", mcsig_message);
  if (strstr(mcsig_message, "Save") && (sig == SIG_SAVE))
    sig = SIG_STAT;
  SIG_MESSAGE("sighandler");
  if (mcget_ncount() == 0)
    printf("(0 %%)\n" );
  else
  {
    printf("%.2f %% (%10.1f/%10.1f)\n", 100.0*mcget_run_num()/mcget_ncount(), 1.0*mcget_run_num(), 1.0*mcget_ncount());
  }
  t0 = (time_t)mcstartdate;
  t1 = time(NULL);
  printf("# Date:      %s", ctime(&t1));
  printf("# Started:   %s", ctime(&t0));

  if (sig == SIG_STAT)
  {
    printf("# " MCCODE_STRING ": Resuming simulation (continue)\n");
    fflush(stdout);
    return;
  }
  else
  if (sig == SIG_SAVE)
  {
    printf("# " MCCODE_STRING ": Saving data and resume simulation (continue)\n");
    save(NULL);
    fflush(stdout);
    return;
  }
  else
  if (sig == SIG_TERM)
  {
    printf("# " MCCODE_STRING ": Finishing simulation (save results and exit)\n");
    finally();
    exit(0);
  }
  else
  {
    fflush(stdout);
    perror("# Last I/O Error");
    printf("# " MCCODE_STRING ": Simulation stop (abort).\n");
// This portion of the signal handling only works on UNIX
#if defined(__unix__) || defined(__APPLE__)
    signal(sig, SIG_DFL); /* force to use default sighandler now */
    kill(getpid(), sig);  /* and trigger it with the current signal */
#endif
    exit(-1);
  }
#undef SIG_SAVE
#undef SIG_TERM
#undef SIG_STAT
#undef SIG_ABRT

} /* sighandler */
#endif /* !NOSIGNALS */

#ifdef NEUTRONICS
/*Main neutronics function steers the McStas calls, initializes parameters etc */
/* Only called in case NEUTRONICS = TRUE */
void neutronics_main_(float *inx, float *iny, float *inz, float *invx, float *invy, float *invz, float *intime, float *insx, float *insy, float *insz, float *inw, float *outx, float *outy, float *outz, float *outvx, float *outvy, float *outvz, float *outtime, float *outsx, float *outsy, float *outsz, float *outwgt)
{

  extern double mcnx, mcny, mcnz, mcnvx, mcnvy, mcnvz;
  extern double mcnt, mcnsx, mcnsy, mcnsz, mcnp;

  /* External code governs iteration - McStas is iterated once per call to neutronics_main. I.e. below counter must be initiancated for each call to neutronics_main*/
  mcrun_num=0;

  time_t t;
  t = (time_t)mcstartdate;
  mcstartdate = t;  /* set start date before parsing options and creating sim file */
  init();

  /* *** parse options *** */
  SIG_MESSAGE("[" __FILE__ "] main START");
  mcformat=getenv(FLAVOR_UPPER "_FORMAT") ?
           getenv(FLAVOR_UPPER "_FORMAT") : FLAVOR_UPPER;

  /* Set neutron state based on input from neutronics code */
  mcsetstate(*inx,*iny,*inz,*invx,*invy,*invz,*intime,*insx,*insy,*insz,*inw);

  /* main neutron event loop - runs only one iteration */

  //mcstas_raytrace(&mcncount); /* prior to McStas 1.12 */

  mcallowbackprop = 1; //avoid absorbtion from negative dt
  int argc=1;
  char *argv[0];
  int dummy = mccode_main(argc, argv);

  *outx =  mcnx;
  *outy =  mcny;
  *outz =  mcnz;
  *outvx =  mcnvx;
  *outvy =  mcnvy;
  *outvz =  mcnvz;
  *outtime =  mcnt;
  *outsx =  mcnsx;
  *outsy =  mcnsy;
  *outsz =  mcnsz;
  *outwgt =  mcnp;

  return;
} /* neutronics_main */

#endif /*NEUTRONICS*/

#endif /* !MCCODE_H */
/* End of file "mccode-r.c". */
/* End of file "mccode-r.c". */

/* embedding file "mcstas-r.c" */

/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mcstas-r.c
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McStas X.Y
* Version: $Revision$
*
* Runtime system for McStas.
* Embedded within instrument in runtime mode.
*
* Usage: Automatically embbeded in the c code whenever required.
*
* $Id$
*
*******************************************************************************/

#ifndef MCSTAS_R_H
#include "mcstas-r.h"
#endif
#ifdef DANSE
#include "mcstas-globals.h"
#endif

/*******************************************************************************
* The I/O format definitions and functions
*******************************************************************************/

/*the magnet stack*/
#ifdef MC_POL_COMPAT
void (*mcMagnetPrecession) (double, double, double, double, double, double,
    double, double*, double*, double*, double, Coords, Rotation)=NULL;
Coords   mcMagnetPos;
Rotation mcMagnetRot;
double*  mcMagnetData                = NULL;
/* mcMagneticField(x, y, z, t, Bx, By, Bz) */
int (*mcMagneticField) (double, double, double, double,
    double*, double*, double*, void *) = NULL;
#endif

#ifndef MCSTAS_H

/*******************************************************************************
* mcsetstate: transfer parameters into global McStas variables
*******************************************************************************/
_class_particle mcsetstate(double x, double y, double z, double vx, double vy, double vz,
			   double t, double sx, double sy, double sz, double p, int mcgravitation, void *mcMagnet, int mcallowbackprop)
{
  _class_particle mcneutron;

  mcneutron.x  = x;
  mcneutron.y  = y;
  mcneutron.z  = z;
  mcneutron.vx = vx;
  mcneutron.vy = vy;
  mcneutron.vz = vz;
  mcneutron.t  = t;
  mcneutron.sx = sx;
  mcneutron.sy = sy;
  mcneutron.sz = sz;
  mcneutron.p  = p;
  mcneutron.mcgravitation = mcgravitation;
  mcneutron.mcMagnet = mcMagnet;
  mcneutron.allow_backprop = mcallowbackprop;
  mcneutron._uid       = 0;
  mcneutron._index     = 1;
  mcneutron._absorbed  = 0;
  mcneutron._restore   = 0;
  mcneutron._scattered = 0;
  mcneutron.flag_nocoordschange = 0;
  
  /* init tmp-vars - FIXME are they used? */
  mcneutron._mctmp_a = mcneutron._mctmp_b =  mcneutron._mctmp_c = 0;
  // what about mcneutron._logic ?
  mcneutron._logic.dummy=1;
  // init uservars via cogen'd-function
  particle_uservar_init(&mcneutron);

  return(mcneutron);
} /* mcsetstate */

/*******************************************************************************
* mcgetstate: get neutron parameters from particle structure
*******************************************************************************/
_class_particle mcgetstate(_class_particle mcneutron, double *x, double *y, double *z,
               double *vx, double *vy, double *vz, double *t,
               double *sx, double *sy, double *sz, double *p)
{
  *x  =  mcneutron.x;
  *y  =  mcneutron.y;
  *z  =  mcneutron.z;
  *vx =  mcneutron.vx;
  *vy =  mcneutron.vy;
  *vz =  mcneutron.vz;
  *t  =  mcneutron.t;
  *sx =  mcneutron.sx;
  *sy =  mcneutron.sy;
  *sz =  mcneutron.sz;
  *p  =  mcneutron.p;

  return(mcneutron);
} /* mcgetstate */


/*******************************************************************************
* mcgenstate: set default neutron parameters
*******************************************************************************/
// Moved to generated code
/* #pragma acc routine seq */
/* _class_particle mcgenstate(void) */
/* { */
/*   return(mcsetstate(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, mcgravitation, mcMagnet, mcallowbackprop)); */
/* } */

/*******************************************************************************
* mccoordschanges: old style rotation routine rot -> (x y z) ,(vx vy vz),(sx,sy,sz)
*******************************************************************************/
void
mccoordschanges(Coords a, Rotation t, double *x, double *y, double *z,
               double *vx, double *vy, double *vz, double *sx, double *sy, double *sz)
{
  Coords b, c;

  b.x = *x;
  b.y = *y;
  b.z = *z;
  c = rot_apply(t, b);
  b = coords_add(c, a);
  *x = b.x;
  *y = b.y;
  *z = b.z;

  if ( (vz && vy  && vx) && (*vz != 0.0 || *vx != 0.0 || *vy != 0.0) )
    mccoordschange_polarisation(t, vx, vy, vz);

  if ( (sz && sy  && sx) && (*sz != 0.0 || *sx != 0.0 || *sy != 0.0) )
    mccoordschange_polarisation(t, sx, sy, sz);

}

/* intersection routines ==================================================== */

/*******************************************************************************
* inside_rectangle: Check if (x,y) is inside rectangle (xwidth, yheight)
* return 0 if outside and 1 if inside
*******************************************************************************/
int inside_rectangle(double x, double y, double xwidth, double yheight)
{
  if (x>-xwidth/2 && x<xwidth/2 && y>-yheight/2 && y<yheight/2)
    return 1;
  else
    return 0;
}

/*******************************************************************************
 * box_intersect: compute time intersection with a box
 * returns 0 when no intersection is found
 *      or 1 in case of intersection with resulting times dt_in and dt_out
 * This function written by Stine Nyborg, 1999.
 *******************************************************************************/
int box_intersect(double *dt_in, double *dt_out,
                  double x, double y, double z,
                  double vx, double vy, double vz,
                  double dx, double dy, double dz)
{
  double x_in, y_in, z_in, tt, t[6], a, b;
  int i, count, s;

      /* Calculate intersection time for each of the six box surface planes
       *  If the box surface plane is not hit, the result is zero.*/

  if(vx != 0)
   {
    tt = -(dx/2 + x)/vx;
    y_in = y + tt*vy;
    z_in = z + tt*vz;
    if( y_in > -dy/2 && y_in < dy/2 && z_in > -dz/2 && z_in < dz/2)
      t[0] = tt;
    else
      t[0] = 0;

    tt = (dx/2 - x)/vx;
    y_in = y + tt*vy;
    z_in = z + tt*vz;
    if( y_in > -dy/2 && y_in < dy/2 && z_in > -dz/2 && z_in < dz/2)
      t[1] = tt;
    else
      t[1] = 0;
   }
  else
    t[0] = t[1] = 0;

  if(vy != 0)
   {
    tt = -(dy/2 + y)/vy;
    x_in = x + tt*vx;
    z_in = z + tt*vz;
    if( x_in > -dx/2 && x_in < dx/2 && z_in > -dz/2 && z_in < dz/2)
      t[2] = tt;
    else
      t[2] = 0;

    tt = (dy/2 - y)/vy;
    x_in = x + tt*vx;
    z_in = z + tt*vz;
    if( x_in > -dx/2 && x_in < dx/2 && z_in > -dz/2 && z_in < dz/2)
      t[3] = tt;
    else
      t[3] = 0;
   }
  else
    t[2] = t[3] = 0;

  if(vz != 0)
   {
    tt = -(dz/2 + z)/vz;
    x_in = x + tt*vx;
    y_in = y + tt*vy;
    if( x_in > -dx/2 && x_in < dx/2 && y_in > -dy/2 && y_in < dy/2)
      t[4] = tt;
    else
      t[4] = 0;

    tt = (dz/2 - z)/vz;
    x_in = x + tt*vx;
    y_in = y + tt*vy;
    if( x_in > -dx/2 && x_in < dx/2 && y_in > -dy/2 && y_in < dy/2)
      t[5] = tt;
    else
      t[5] = 0;
   }
  else
    t[4] = t[5] = 0;

  /* The intersection is evaluated and *dt_in and *dt_out are assigned */

  a = b = s = 0;
  count = 0;

  for( i = 0; i < 6; i = i + 1 )
    if( t[i] == 0 )
      s = s+1;
    else if( count == 0 )
    {
      a = t[i];
      count = 1;
    }
    else
    {
      b = t[i];
      count = 2;
    }

  if ( a == 0 && b == 0 )
    return 0;
  else if( a < b )
  {
    *dt_in = a;
    *dt_out = b;
    return 1;
  }
  else
  {
    *dt_in = b;
    *dt_out = a;
    return 1;
  }

} /* box_intersect */

/*******************************************************************************
 * cylinder_intersect: compute intersection with a cylinder
 * returns 0 when no intersection is found
 *      or 2/4/8/16 bits depending on intersection,
 *     and resulting times t0 and t1
 * Written by: EM,NB,ABA 4.2.98
  *******************************************************************************/
int cylinder_intersect(double *t0, double *t1, double x, double y, double z,
                   double vx, double vy, double vz, double r, double h)
{
  double D, t_in, t_out, y_in, y_out;
  int ret=1;

  D = (2*vx*x + 2*vz*z)*(2*vx*x + 2*vz*z)
    - 4*(vx*vx + vz*vz)*(x*x + z*z - r*r);

  if (D>=0)
  {
    if (vz*vz + vx*vx) {
      t_in  = (-(2*vz*z + 2*vx*x) - sqrt(D))/(2*(vz*vz + vx*vx));
      t_out = (-(2*vz*z + 2*vx*x) + sqrt(D))/(2*(vz*vz + vx*vx));
    } else if (vy) { /* trajectory parallel to cylinder axis */
      t_in = (-h/2-y)/vy;
      t_out = (h/2-y)/vy;
      if (t_in>t_out){
        double tmp=t_in;
        t_in=t_out;t_out=tmp;
      }
    } else return 0;
    y_in = vy*t_in + y;
    y_out =vy*t_out + y;

    if ( (y_in > h/2 && y_out > h/2) || (y_in < -h/2 && y_out < -h/2) )
      return 0;
    else
    {
      if (y_in > h/2)
        { t_in = ((h/2)-y)/vy; ret += 2; }
      else if (y_in < -h/2)
        { t_in = ((-h/2)-y)/vy; ret += 4; }
      if (y_out > h/2)
        { t_out = ((h/2)-y)/vy; ret += 8; }
      else if (y_out < -h/2)
        { t_out = ((-h/2)-y)/vy; ret += 16; }
    }
    *t0 = t_in;
    *t1 = t_out;
    return ret;
  }
  else
  {
    *t0 = *t1 = 0;
    return 0;
  }
} /* cylinder_intersect */


/*******************************************************************************
 * sphere_intersect: Calculate intersection between a line and a sphere.
 * returns 0 when no intersection is found
 *      or 1 in case of intersection with resulting times t0 and t1
 *******************************************************************************/
int sphere_intersect(double *t0, double *t1, double x, double y, double z,
                 double vx, double vy, double vz, double r)
{
  double A, B, C, D, v;

  v = sqrt(vx*vx + vy*vy + vz*vz);
  A = v*v;
  B = 2*(x*vx + y*vy + z*vz);
  C = x*x + y*y + z*z - r*r;
  D = B*B - 4*A*C;
  if(D < 0)
    return 0;
  D = sqrt(D);
  *t0 = (-B - D) / (2*A);
  *t1 = (-B + D) / (2*A);
  return 1;
} /* sphere_intersect */

/*******************************************************************************
 * plane_intersect: Calculate intersection between a plane and a line.
 * returns 0 when no intersection is found (i.e. line is parallel to the plane)
 * returns 1 or -1 when intersection time is positive and negative respectively
 *******************************************************************************/
int plane_intersect(double *t, double x, double y, double z,
                 double vx, double vy, double vz, double nx, double ny, double nz, double wx, double wy, double wz)
{
  double s;
  if (fabs(s=scalar_prod(nx,ny,nz,vx,vy,vz))<FLT_EPSILON) return 0;
  *t = - scalar_prod(nx,ny,nz,x-wx,y-wy,z-wz)/s;
  if (*t<0) return -1;
  else return 1;
} /* plane_intersect */

#endif /* !MCSTAS_H */
/* End of file "mcstas-r.c". */


/* *****************************************************************************
* Start of instrument 'PSI_CAMEA' generated code
***************************************************************************** */

#ifdef MC_TRACE_ENABLED
int traceenabled = 1;
#else
int traceenabled = 0;
#endif
#define MCSTAS "/opt/homebrew/Caskroom/miniconda/base/envs/mcstas_3614/share/mcstas/resources/"
int   defaultmain         = 1;
char  instrument_name[]   = "PSI_CAMEA";
char  instrument_source[] = "FullInstrument_v5_working.instr";
char *instrument_exe      = NULL; /* will be set to argv[0] in main */
char  instrument_code[]   = "Instrument PSI_CAMEA source code FullInstrument_v5_working.instr is not embedded in this executable.\n  Use --source option when running mcstas.\n";

int main(int argc, char *argv[]){return mccode_main(argc, argv);}

/* *****************************************************************************
* instrument 'PSI_CAMEA' and components DECLARE
***************************************************************************** */

/* Instrument parameters: structure and a table for the initialisation
   (Used in e.g. inputparse and I/O function (e.g. detector_out) */

struct _struct_instrument_parameters {
  MCNUM SourceE;
  MCNUM DeltaSourceE;
  MCNUM EI;
  MCNUM A3;
  MCNUM A4;
  MCNUM SAMPLE;
  MCNUM RV_mono_Bool;
  MCNUM RH_mono_Bool;
  MCNUM Lv;
  MCNUM Lh;
  MCNUM monoShieldingWidth;
  MCNUM monoShieldingHeight;
  MCNUM monoShieldingDistance;
  MCNUM MonoShielding;
  MCNUM Be_filter;
  MCNUM sampleHeight;
  MCNUM sampleRadius;
  MCNUM sampleThickness;
  MCNUM samplePosY;
  MCNUM sampleFluxDiagnosticXWidth;
  MCNUM sampleFluxDiagnosticYHeight;
};
typedef struct _struct_instrument_parameters _class_instrument_parameters;

/* instrument SPLIT and GROUP control logic */
struct instrument_logic_struct {
  long Split_sample_scatter_state_reset; /* this is the SPLIT counter decremented down to 0 */
  _class_particle Split_sample_scatter_state_reset_particle; /* this is the particle to duplicate */
};

struct _instrument_struct {
  char   _name[256]; /* the name of this instrument e.g. 'PSI_CAMEA' */
/* Counters per component instance */
  double counter_AbsorbProp[48]; /* absorbed events in PROP routines */
  double counter_N[48], counter_P[48], counter_P2[48]; /* event counters after each component instance */
  _class_particle _trajectory[48]; /* current trajectory for STORE/RESTORE */
/* Components position table (absolute and relative coords) */
  Coords _position_relative[48]; /* positions of all components */
  Coords _position_absolute[48];
  _class_instrument_parameters _parameters; /* instrument parameters */
  struct instrument_logic_struct logic; /* instrument logic */
} _instrument_var;
struct _instrument_struct *instrument = & _instrument_var;
#pragma acc declare create ( _instrument_var )
#pragma acc declare create ( instrument )

int numipar = 21;
struct mcinputtable_struct mcinputtable[] = {
  "SourceE", &(_instrument_var._parameters.SourceE), instr_type_double, "5", "",
  "DeltaSourceE", &(_instrument_var._parameters.DeltaSourceE), instr_type_double, "0.5", "",
  "EI", &(_instrument_var._parameters.EI), instr_type_double, "5", "",
  "A3", &(_instrument_var._parameters.A3), instr_type_double, "0", "",
  "A4", &(_instrument_var._parameters.A4), instr_type_double, "-45", "",
  "SAMPLE", &(_instrument_var._parameters.SAMPLE), instr_type_double, "0", "",
  "RV_mono_Bool", &(_instrument_var._parameters.RV_mono_Bool), instr_type_double, "1", "",
  "RH_mono_Bool", &(_instrument_var._parameters.RH_mono_Bool), instr_type_double, "1", "",
  "Lv", &(_instrument_var._parameters.Lv), instr_type_double, "1.872", "",
  "Lh", &(_instrument_var._parameters.Lh), instr_type_double, "1.340", "",
  "monoShieldingWidth", &(_instrument_var._parameters.monoShieldingWidth), instr_type_double, "0.062", "",
  "monoShieldingHeight", &(_instrument_var._parameters.monoShieldingHeight), instr_type_double, "0.14", "",
  "monoShieldingDistance", &(_instrument_var._parameters.monoShieldingDistance), instr_type_double, "0.235", "",
  "MonoShielding", &(_instrument_var._parameters.MonoShielding), instr_type_double, "1", "",
  "Be_filter", &(_instrument_var._parameters.Be_filter), instr_type_double, "1", "",
  "sampleHeight", &(_instrument_var._parameters.sampleHeight), instr_type_double, "0.01", "",
  "sampleRadius", &(_instrument_var._parameters.sampleRadius), instr_type_double, "0.01", "",
  "sampleThickness", &(_instrument_var._parameters.sampleThickness), instr_type_double, "0.0026", "",
  "samplePosY", &(_instrument_var._parameters.samplePosY), instr_type_double, "0.00", "",
  "sampleFluxDiagnosticXWidth", &(_instrument_var._parameters.sampleFluxDiagnosticXWidth), instr_type_double, "0.08", "",
  "sampleFluxDiagnosticYHeight", &(_instrument_var._parameters.sampleFluxDiagnosticYHeight), instr_type_double, "0.08", "",
  NULL, NULL, instr_type_double, ""
};

struct metadata_table_struct metadata_table[] = {
  "", "", "", ""
};
int num_metadata = 0;

/* ************************************************************************** */
/*             SHARE user declarations for all components                     */
/* ************************************************************************** */

/* Shared user declarations for all components types 'Source_gen4'. */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright 1997-2002, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/read_table-lib.h
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Release: McStas 1.6
* Version: $Revision$
*
* This file is to be imported by components that may read data from table files
* It handles some shared functions.
*
* This library may be used directly as an external library. It has no dependency
*
* Usage: within SHARE
* %include "read_table-lib"
*
*******************************************************************************/

#ifndef READ_TABLE_LIB_H
#define READ_TABLE_LIB_H "$Revision$"

#define READ_TABLE_STEPTOL  0.04 /* tolerancy for constant step approx */

#ifndef MC_PATHSEP_C
#ifdef WIN32
#define MC_PATHSEP_C '\\'
#define MC_PATHSEP_S "\\"
#else  /* !WIN32 */
#ifdef MAC
#define MC_PATHSEP_C ':'
#define MC_PATHSEP_S ":"
#else  /* !MAC */
#define MC_PATHSEP_C '/'
#define MC_PATHSEP_S "/"
#endif /* !MAC */
#endif /* !WIN32 */
#endif /* !MC_PATHSEP_C */

#ifndef MCSTAS
#ifdef WIN32
#define MCSTAS "C:\\mcstas\\lib"
#else  /* !WIN32 */
#ifdef MAC
#define MCSTAS ":mcstas:lib" /* ToDo: What to put here? */
#else  /* !MAC */
#define MCSTAS "/usr/local/lib/mcstas"
#endif /* !MAC */
#endif /* !WIN32 */
#endif /* !MCSTAS */

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef _MSC_EXTENSIONS
#include <strings.h>
#else
#  include <string.h>
#  define strcasecmp _stricmp
#  define strncasecmp _strnicmp
#endif

  typedef struct struct_table
  {
    char    filename[1024];
    long    filesize;
    char   *header;  /* text header, e.g. comments */
    double *data;    /* vector { x[0], y[0], ... x[n-1], y[n-1]... } */
    double  min_x;   /* min value of first column */
    double  max_x;   /* max value of first column */
    double  step_x;  /* minimal step value of first column */
    long    rows;    /* number of rows in matrix block */
    long    columns; /* number of columns in matrix block */

    long    begin;   /* start fseek index of block */
    long    end;     /* stop  fseek index of block */
    long    block_number;  /* block index. 0 is catenation of all */
    long    array_length;  /* number of elements in the t_Table array */
    char    monotonic;     /* true when 1st column/vector data is monotonic */
    char    constantstep;  /* true when 1st column/vector data has constant step */
    char    method[32];    /* interpolation method: nearest, linear */
    char    quiet;   /*output level for messages to the console 0: print all messages, 1:only print some/including errors, 2: never print anything.*/
  } t_Table;

/*maximum number of rows to rebin a table = 1M*/
enum { mcread_table_rebin_maxsize = 1000000 };

typedef struct t_Read_table_file_item {
    int ref_count;
    t_Table *table_ref;
} t_Read_table_file_item;

typedef enum enum_Read_table_file_actions {STORE,FIND,GC}  t_Read_table_file_actions;

/* read_table-lib function prototypes */
/* ========================================================================= */

/* 'public' functions */
long     Table_Read              (t_Table *Table, char *File, long block_number);
long     Table_Read_Offset       (t_Table *Table, char *File, long block_number,
                                  long *offset, long max_lines);
long     Table_Read_Offset_Binary(t_Table *Table, char *File, char *Type,
                                  long *Offset, long Rows, long Columns);
long     Table_Rebin(t_Table *Table); /* rebin table with regular 1st column and interpolate all columns 2:end */
long     Table_Info (t_Table Table);
#pragma acc routine
double   Table_Index(t_Table Table,   long i, long j); /* get indexed value */
#pragma acc routine
double   Table_Value(t_Table Table, double X, long j); /* search X in 1st column and return interpolated value in j-column */
t_Table *Table_Read_Array(char *File, long *blocks);
void     Table_Free_Array(t_Table *Table);
long     Table_Info_Array(t_Table *Table);
int      Table_SetElement(t_Table *Table, long i, long j, double value);
long     Table_Init(t_Table *Table, long rows, long columns); /* create a Table */
#pragma acc routine
double   Table_Value2d(t_Table Table, double X, double Y);    /* same as Table_Index with non-integer indices and 2d interpolation */
MCDETECTOR Table_Write(t_Table Table, char*file, char*xl, char*yl, 
           double x1, double x2, double y1, double y2); /* write Table to disk */
void * Table_File_List_Handler(t_Read_table_file_actions action, void *item, void *item_modifier);
t_Table *Table_File_List_find(char *name, int block, int offset);
int Table_File_List_gc(t_Table *tab);
void *Table_File_List_store(t_Table *tab);

#define Table_ParseHeader(header, ...) \
  Table_ParseHeader_backend(header,__VA_ARGS__,NULL);

char **Table_ParseHeader_backend(char *header, ...);
FILE *Open_File(char *name, const char *Mode, char *path);


/* private functions */
void Table_Free(t_Table *Table);
long Table_Read_Handle(t_Table *Table, FILE *fid, long block_number, long max_lines, char *name);
static void Table_Stat(t_Table *Table);
#pragma acc routine
double Table_Interp1d(double x, double x1, double y1, double x2, double y2);
#pragma acc routine
double Table_Interp1d_nearest(double x, double x1, double y1, double x2, double y2);
#pragma acc routine
double Table_Interp2d(double x, double y, double x1, double y1, double x2, double y2,
double z11, double z12, double z21, double z22);


#endif

/* end of read_table-lib.h */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/read_table-lib.c
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Release: McStas CVS_090504
* Version: $Revision$
*
* This file is to be imported by components that may read data from table files
* It handles some shared functions. Embedded within instrument in runtime mode.
*
* Usage: within SHARE
* %include "read_table-lib"
*
*******************************************************************************/

#ifndef READ_TABLE_LIB_H
#include "read_table-lib.h"
#endif

#ifndef READ_TABLE_LIB_C
#define READ_TABLE_LIB_C "$Revision$"


/*******************************************************************************
 * void *Table_File_List_Handler(action, item, item_modifier)
 *   ACTION: handle file entries in the read_table-lib file list. If a file is read - it is supposed to be
 *   stored in a list such that we can avoid reading the same file many times.
 *   input  action: FIND, STORE, GC. check if file exists in the list, store an item in the list, or check if it can be garbage collected.
 *   input item: depends on the action.
 *    FIND)  item is a filename, and item_modifier is the block number
 *    STORE) item is the Table to store - item_modifier is ignored
 *    GC)    item is the Table to check. If it has a ref_count >1 then this is simply decremented.
 *   return  depends on the action
 *    FIND)  return a reference to a table+ref_count item if found - NULL otherwise. I.e. NULL means the file has not been read before and must be read again.
 *    STORE) return NULL always
 *    GC)    return NULL if no garbage collection is needed, return an adress to the t_Table which should be garbage collected. 0x1 is returned if
 *           the item is not found in the list
*******************************************************************************/
void * Table_File_List_Handler(t_Read_table_file_actions action, void *item, void *item_modifier){

    /* logic here is Read_Table should include a call to FIND. If found the return value should just be used as
     * if the table had been read from disk. If not found then read the table and STORE.
     * Table_Free should include a call to GC. If this returns non-NULL then we should proceed with freeing the memory
     * associated with the table item - otherwise only decrement the reference counter since there are more references
     * that may need it.*/

    static t_Read_table_file_item read_table_file_list[1024];  
    static int read_table_file_count=0;

    t_Read_table_file_item *tr;
    switch(action){
        case FIND:
            /*interpret data item as a filename, if it is found return a pointer to the table and increment refcount.
             * if not found return the item itself*/
            tr=read_table_file_list;
            while ( tr->table_ref!=NULL ){
                int i=*((int*) item_modifier);
                int j=*( ((int*) item_modifier)+1);
                if ( !strcmp(tr->table_ref->filename,(char *) item) &&
                        tr->table_ref->block_number==i && tr->table_ref->begin==j ){
                    tr->ref_count++;
                    return (void *) tr;
                }
                tr++;
            }
            return NULL;
        case STORE:
            /*find an available slot and store references to table there*/
            tr=&(read_table_file_list[read_table_file_count++]);
            tr->table_ref = ((t_Table *) item);
            tr->ref_count++;
            return NULL;
        case GC:
            /* Should this item be garbage collected (freed) - if so scratch the entry and return the address of the item - 
             * else decrement ref_count and return NULL.
             * A non-NULL return expects the item to actually be freed afterwards.*/
            tr=read_table_file_list;
            while ( tr->table_ref!=NULL ){
                if ( tr->table_ref->data ==((t_Table *)item)->data && 
                        tr->table_ref->block_number == ((t_Table *)item)->block_number){
                    /*matching item found*/
                    if (tr->ref_count>1){
                        /*the item is found and no garbage collection needed*/
                        tr->ref_count--;
                        return NULL;
                    }else{
                        /* The item is found and the reference counter is 1.
                         * This means we should garbage collect. Move remaining list items up one slot,
                         * and return the table for garbage collection by caller*/
                        while (tr->table_ref!=NULL){
                            *tr=*(tr+1);
                            tr++;
                        }
                        read_table_file_count--;
                        return (t_Table *) item;
                    }
                }
                tr++;
            }
            /* item not found, and so should be garbage collected. This could be the case if freeing a
             * Table that has been constructed from code - not read from file. Return 0x1 to flag it for
             * collection.*/
            return (void *) 0x1 ;
    }
    /* If we arrive here, nothing worked, return NULL */
    return NULL;
}

/* Access functions to the handler*/

/********************************************
 * t_Table *Table_File_List_find(char *name, int block, int offset)
 * input name: filename to search for in the file list
 * input block: data block in the file as each file may contain more than 1 data block.
 * return a ref. to a table if it is found (you may use this pointer and skip reading the file), NULL otherwise (i.e. go ahead and read the file)
*********************************************/
t_Table *Table_File_List_find(char *name, int block, int offset){
    int vars[2]={block,offset};
    t_Read_table_file_item *item = Table_File_List_Handler(FIND,name, vars);
    if (item == NULL){
        return NULL;
    }else{
        return item->table_ref;
    }
}
/********************************************
 * int Table_File_List_gc(t_Table *tab)
 * input tab: the table to check for references.
 * return 0: no garbage collection needed
 *        1: Table's data and header (at least) should be freed.
*********************************************/
int Table_File_List_gc(t_Table *tab){
    void *rval=Table_File_List_Handler(GC,tab,0);
    if (rval==NULL) return 0;
    else return 1;
}


/*****************************************************************************
 * void *Table_File_List_store(t_Table *tab)
 * input tab: pointer to table to store.
 * return None. 
*******************************************************************************/
void *Table_File_List_store(t_Table *tab){
    return Table_File_List_Handler(STORE,tab,0);
}


/*******************************************************************************
* FILE *Open_File(char *name, char *Mode, char *path)
*   ACTION: search for a file and open it. Optionally return the opened path.
*   input   name:  file name from which table should be extracted
*           mode: "r", "w", "a" or any valid fopen mode
*           path:  NULL or a pointer to at least 1024 allocated chars
*   return  initialized file handle or NULL in case of error
*******************************************************************************/

  FILE *Open_File(char *File, const char *Mode, char *Path)
  {
    char path[1024];
    FILE *hfile = NULL;
    
    if (!File || File[0]=='\0')                     return(NULL);
    if (!strcmp(File,"NULL") || !strcmp(File,"0"))  return(NULL);
    
    /* search in current or full path */
    strncpy(path, File, 1024);
    hfile = fopen(path, Mode);
    if(!hfile)
    {
      char dir[1024];

      if (!hfile && instrument_source[0] != '\0' && strlen(instrument_source)) /* search in instrument source location */
      {
        char *path_pos   = NULL;
        /* extract path: searches for last file separator */
        path_pos    = strrchr(instrument_source, MC_PATHSEP_C);  /* last PATHSEP */
        if (path_pos) {
          long path_length = path_pos +1 - instrument_source;  /* from start to path+sep */
          if (path_length) {
            strncpy(dir, instrument_source, path_length);
            dir[path_length] = '\0';
            snprintf(path, 1024, "%s%c%s", dir, MC_PATHSEP_C, File);
            hfile = fopen(path, Mode);
          }
        }
      }
      if (!hfile && instrument_exe[0] != '\0' && strlen(instrument_exe)) /* search in PWD instrument executable location */
      {
        char *path_pos   = NULL;
        /* extract path: searches for last file separator */
        path_pos    = strrchr(instrument_exe, MC_PATHSEP_C);  /* last PATHSEP */
        if (path_pos) {
          long path_length = path_pos +1 - instrument_exe;  /* from start to path+sep */
          if (path_length) {
            strncpy(dir, instrument_exe, path_length);
            dir[path_length] = '\0';
            snprintf(path, 1024, "%s%c%s", dir, MC_PATHSEP_C, File);
            hfile = fopen(path, Mode);
          }
        }
      }
      if (!hfile) /* search in HOME or . */
      {
        strcpy(dir, getenv("HOME") ? getenv("HOME") : ".");
        snprintf(path, 1024, "%s%c%s", dir, MC_PATHSEP_C, File);
        hfile = fopen(path, Mode);
      }
      if (!hfile) /* search in MCSTAS/data */
      {
        strcpy(dir, getenv(FLAVOR_UPPER) ? getenv(FLAVOR_UPPER) : MCSTAS);
        snprintf(path, 1024, "%s%c%s%c%s", dir, MC_PATHSEP_C, "data", MC_PATHSEP_C, File);
        hfile = fopen(path, Mode);
      }
      if (!hfile) /* search in MVCSTAS/contrib */
      {
        strcpy(dir, getenv(FLAVOR_UPPER) ? getenv(FLAVOR_UPPER) : MCSTAS);
        snprintf(path, 1024, "%s%c%s%c%s", dir, MC_PATHSEP_C, "contrib", MC_PATHSEP_C, File);
        hfile = fopen(path, Mode);
      }
      if(!hfile)
      {
        // fprintf(stderr, "Warning: Could not open input file '%s' (Open_File)\n", File);
        return (NULL);
      }
    }
    if (Path) strncpy(Path, path, 1024);
    return(hfile);
  } /* end Open_File */

/*******************************************************************************
* long Read_Table(t_Table *Table, char *name, int block_number)
*   ACTION: read a single Table from a text file
*   input   Table: pointer to a t_Table structure
*           name:  file name from which table should be extracted
*           block_number: if the file does contain more than one
*                 data block, then indicates which one to get (from index 1)
*                 a 0 value means append/catenate all
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
* The routine stores any line starting with '#', '%' and ';' into the header
* File is opened, read and closed
* Other lines are interpreted as numerical data, and stored.
* Data block should be a rectangular matrix or vector.
* Data block may be rebinned with Table_Rebin (also sort in ascending order)
*******************************************************************************/
  long Table_Read(t_Table *Table, char *File, long block_number)
  { /* reads all or a single data block from 'file' and returns a Table structure  */
    return(Table_Read_Offset(Table, File, block_number, NULL, 0));
  } /* end Table_Read */

/*******************************************************************************
* long Table_Read_Offset(t_Table *Table, char *name, int block_number, long *offset
*                        long max_rows)
*   ACTION: read a single Table from a text file, starting at offset
*     Same as Table_Read(..) except:
*   input   offset:    pointer to an offset (*offset should be 0 at start)
*           max_rows: max number of data rows to read from file (0 means all)
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
*           updated *offset position (where end of reading occured)
*******************************************************************************/
  long Table_Read_Offset(t_Table *Table, char *File,
                         long block_number, long *offset,
                         long max_rows)
  { /* reads all/a data block in 'file' and returns a Table structure  */
    FILE *hfile;
    long  nelements=0;
    long  begin=0;
    long  filesize=0;
    char  name[1024];
    char  path[1024];
    struct stat stfile;

    /*Need to be able to store the pointer*/
    if (!Table) return(-1);

    /*TK: Valgrind flags it as usage of uninitialised variable: */
    Table->quiet = 0;

    //if (offset && *offset) snprintf(name, 1024, "%s@%li", File, *offset);
    //else                   
    strncpy(name, File, 1024);
    if(offset && *offset){
        begin=*offset;
    }
    /* Check if the table has already been read from file.
     * If so just reuse the table, if not (this is flagged by returning NULL
     * set up a new table and read the data into it */
    t_Table *tab_p= Table_File_List_find(name,block_number,begin);
    if ( tab_p!=NULL ){
        /*table was found in the Table_File_List*/
        *Table=*tab_p;
        MPI_MASTER(
            if(Table->quiet<1)
              printf("Reusing input file '%s' (Table_Read_Offset)\n", name);
            );
        return Table->rows*Table->columns;
    }

    /* open the file */
    hfile = Open_File(File, "r", path);
    if (!hfile) return(-1);
    else {
      MPI_MASTER(
          if(Table->quiet<1)
            printf("Opening input file '%s' (Table_Read_Offset)\n", path);
          );
    }
    
    /* read file state */
    stat(path,&stfile); filesize = stfile.st_size;
    if (offset && *offset) fseek(hfile, *offset, SEEK_SET);
    begin     = ftell(hfile);
    
    Table_Init(Table, 0, 0);

    /* read file content and set the Table */
    nelements = Table_Read_Handle(Table, hfile, block_number, max_rows, name);
    Table->begin = begin;
    Table->end   = ftell(hfile);
    Table->filesize = (filesize>0 ? filesize : 0);
    Table_Stat(Table);
    
    Table_File_List_store(Table);

    if (offset) *offset=Table->end;
    fclose(hfile);
    return(nelements);

  } /* end Table_Read_Offset */

/*******************************************************************************
* long Table_Read_Offset_Binary(t_Table *Table, char *File, char *type,
*                               long *offset, long rows, long columns)
*   ACTION: read a single Table from a binary file, starting at offset
*     Same as Table_Read_Offset(..) except that it handles binary files.
*   input   type: may be "float"/NULL or "double"
*           offset: pointer to an offset (*offset should be 0 at start)
*           rows   : number of rows (0 means read all)
*           columns: number of columns
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
*           updated *offset position (where end of reading occured)
*******************************************************************************/
  long Table_Read_Offset_Binary(t_Table *Table, char *File, char *type,
                                long *offset, long rows, long columns)
  { /* reads all/a data block in binary 'file' and returns a Table structure  */
    long    nelements, sizeofelement;
    long    filesize;
    FILE   *hfile;
    char    path[1024];
    struct stat stfile;
    double *data    = NULL;
    double *datatmp = NULL;
    long    i;
    long    begin;

    if (!Table) return(-1);

    Table_Init(Table, 0, 0);
    
    /* open the file */
    hfile = Open_File(File, "r", path);
    if (!hfile) return(-1);
    else {
      MPI_MASTER(
          if(Table->quiet<1)
            printf("Opening input file '%s' (Table_Read, Binary)\n", path);
      );
    }
    
    /* read file state */
    stat(File,&stfile);
    filesize = stfile.st_size;
    Table->filesize=filesize;
    
    /* read file content */
    if (type && !strcmp(type,"double")) sizeofelement = sizeof(double);
    else  sizeofelement = sizeof(float);
    if (offset && *offset) fseek(hfile, *offset, SEEK_SET);
    begin     = ftell(hfile);
    if (rows && filesize > sizeofelement*columns*rows)
      nelements = columns*rows;
    else nelements = (long)(filesize/sizeofelement);
    if (!nelements || filesize <= *offset) return(0);
    data    = (double*)malloc(nelements*sizeofelement);
    if (!data) {
      if(!(Table->quiet>1))
        fprintf(stderr,"Error: allocating %ld elements for %s file '%s'. Too big (Table_Read_Offset_Binary).\n", nelements, type, File);
      exit(-1);
    }
    nelements = fread(data, sizeofelement, nelements, hfile);

    if (!data || !nelements)
    {
      if(!(Table->quiet>1))
        fprintf(stderr,"Error: reading %ld elements from %s file '%s' (Table_Read_Offset_Binary)\n", nelements, type, File);
      exit(-1);
    }
    Table->begin   = begin;
    Table->end     = ftell(hfile);
    if (offset) *offset=Table->end;
    fclose(hfile);

    datatmp = (double*)realloc(data, (double)nelements*sizeofelement);
    if (!datatmp) {
      free(data);
      fprintf(stderr,"Error: reallocating %ld elements for %s file '%s'. Too big (Table_Read_Offset_Binary).\n", nelements, type, File);
      exit(-1);
    } else {
      data = datatmp;
    }
    /* copy file data into Table */
    if (type && !strcmp(type,"double")) Table->data = data;
    else {
      float  *s;
      double *dataf;
      s     = (float*)data;
      dataf = (double*)malloc(sizeof(double)*nelements);
      if (!dataf) {
	fprintf(stderr, "Could not allocate data block of size %ld\n", nelements);
	exit(-1);
      }
      for (i=0; i<nelements; i++)
        dataf[i]=s[i];
      free(data);
      Table->data = dataf;
    }
    strncpy(Table->filename, File, 1024);
    Table->rows    = nelements/columns;
    Table->columns = columns;
    Table->array_length = 1;
    Table->block_number = 1;

    Table_Stat(Table);

    return(nelements);
  } /* end Table_Read_Offset_Binary */

/*******************************************************************************
* long Table_Read_Handle(t_Table *Table, FILE *fid, int block_number, long max_rows, char *name)
*   ACTION: read a single Table from a text file handle (private)
*   input   Table:pointer to a t_Table structure
*           fid:  pointer to FILE handle
*           block_number: if the file does contain more than one
*                 data block, then indicates which one to get (from index 1)
*                 a 0 value means append/catenate all
*           max_rows: if non 0, only reads that number of lines
*   return  initialized single Table t_Table structure containing data, header, ...
*           modified Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
* The routine stores any line starting with '#', '%' and ';' into the header
* Other lines are interpreted as numerical data, and stored.
* Data block should be a rectangular matrix or vector.
* Data block may be rebined with Table_Rebin (also sort in ascending order)
*******************************************************************************/
  long Table_Read_Handle(t_Table *Table, FILE *hfile,
                         long block_number, long max_rows, char *name)
  { /* reads all/a data block from 'file' handle and returns a Table structure  */
    double *Data              = NULL;
    double *Datatmp           = NULL;
    char *Header              = NULL;
    char *Headertmp           = NULL;
    long  malloc_size         = CHAR_BUF_LENGTH;
    long  malloc_size_h       = 4096;
    long  Rows = 0,   Columns = 0;
    long  count_in_array      = 0;
    long  count_in_header     = 0;
    long  count_invalid       = 0;
    long  block_Current_index = 0;
    char  flag_End_row_loop   = 0;

    if (!Table) return(-1);
    Table_Init(Table, 0, 0);
    if (name && name[0]!='\0') strncpy(Table->filename, name, 1024);

    if(!hfile) {
       fprintf(stderr, "Error: File handle is NULL (Table_Read_Handle).\n");
       return (-1);
    }
    Header = (char*)  calloc(malloc_size_h, sizeof(char));
    Data   = (double*)calloc(malloc_size,   sizeof(double));
    if ((Header == NULL) || (Data == NULL)) {
       fprintf(stderr, "Error: Could not allocate Table and Header (Table_Read_Handle).\n");
       return (-1);
    }

    int flag_In_array = 0;
    do { /* while (!flag_End_row_loop) */
      char  *line=malloc(1024*CHAR_BUF_LENGTH*sizeof(char));
      long  back_pos=0;   /* ftell start of line */

      if (!line) {
	fprintf(stderr,"Could not allocate line buffer\n");
	exit(-1);
      }
      back_pos = ftell(hfile);
      if (fgets(line, 1024*CHAR_BUF_LENGTH, hfile) != NULL) { /* analyse line */
        /* first skip blank and tabulation characters */
        int i = strspn(line, " \t");

        /* handle comments: stored in header */
        if (NULL != strchr("#%;/", line[i]))
        { /* line is a comment */
          count_in_header += strlen(line);
          if (count_in_header >= malloc_size_h) {
            /* if succeed and in array : add (and realloc if necessary) */
            malloc_size_h = count_in_header+4096;
            char *Headertmp = (char*)realloc(Header, malloc_size_h*sizeof(char));
	    if(!Headertmp) {
	      free(Header);
	             fprintf(stderr, "Error: Could not reallocate Header (Table_Read_Handle).\n");
		     free(Header);
		     return (-1);
	    } else {
	      Header = Headertmp;
	    }
          }
          strncat(Header, line, 4096);
          flag_In_array=0;
          /* exit line and file if passed desired block */
          if (block_number > 0 && block_number == block_Current_index) {
            flag_End_row_loop = 1;
          }

          /* Continue with next line */
          continue;
        }
        if (strstr(line, "***"))
        {
          count_invalid++;
          /* Continue with next line */
          continue;
        }

        /* get the number of columns splitting line with strtok */
        char  *lexeme;
        char  flag_End_Line = 0;
        long  block_Num_Columns = 0;
        const char seps[] = " ,;\t\n\r";

        lexeme = strtok(line, seps);
        while (!flag_End_Line) {
          if ((lexeme != NULL) && (lexeme[0] != '\0')) {
            /* reading line: the token is not empty */
            double X;
            int    count=1;
            /* test if we have 'NaN','Inf' */
            if (!strncasecmp(lexeme,"NaN",3))
              X = 0;
            else if (!strncasecmp(lexeme,"Inf",3) || !strncasecmp(lexeme,"+Inf",4))
              X = FLT_MAX;
            else if (!strncasecmp(lexeme,"-Inf",4))
              X = -FLT_MAX;
            else
              count = sscanf(lexeme,"%lg",&X);
            if (count == 1) {
              /* reading line: the token is a number in the line */
              if (!flag_In_array) {
                /* reading num: not already in a block: starts a new data block */
                block_Current_index++;
                flag_In_array    = 1;
                block_Num_Columns= 0;
                if (block_number > 0) {
                  /* initialise a new data block */
                  Rows = 0;
                  count_in_array = 0;
                } /* else append */
              }
              /* reading num: all blocks or selected block */
              if (flag_In_array && (block_number == 0 ||
                  block_number == block_Current_index)) {
                /* starting block: already the desired number of rows ? */
                if (block_Num_Columns == 0 &&
                    max_rows > 0 && Rows >= max_rows) {
                  flag_End_Line      = 1;
                  flag_End_row_loop  = 1;
                  flag_In_array      = 0;
                  /* reposition to begining of line (ignore line) */
                  fseek(hfile, back_pos, SEEK_SET);
                } else { /* store into data array */
                  if (count_in_array >= malloc_size) {
                    /* realloc data buffer if necessary */
                    malloc_size = count_in_array*1.5;
                    Datatmp = (double*) realloc(Data, malloc_size*sizeof(double));
                    if (Datatmp == NULL) {
                      fprintf(stderr, "Error: Can not re-allocate memory %zi (Table_Read_Handle).\n",
                              malloc_size*sizeof(double));
		      free(Data);
                      return (-1);
                    } else {
                      Data=Datatmp;
                    }
                  }
                  if (0 == block_Num_Columns) Rows++;
                  Data[count_in_array] = X;
                  count_in_array++;
                  block_Num_Columns++;
                }
              } /* reading num: end if flag_In_array */
            } /* end reading num: end if sscanf lexeme -> numerical */
            else {
              /* reading line: the token is not numerical in that line. end block */
              if (block_Current_index == block_number) {
                flag_End_Line = 1;
                flag_End_row_loop = 1;
              } else {
                flag_In_array = 0;
                flag_End_Line = 1;
              }
            }
          }
          else {
            /* no more tokens in line */
            flag_End_Line = 1;
            if (block_Num_Columns > 0) Columns = block_Num_Columns;
          }

          // parse next token
          lexeme = strtok(NULL, seps);

        } /* while (!flag_End_Line) */
      } /* end: if fgets */
      else flag_End_row_loop = 1; /* else fgets : end of file */
      free(line);
    } while (!flag_End_row_loop); /* end while flag_End_row_loop */

    Table->block_number = block_number;
    Table->array_length = 1;

    // shrink header to actual size (plus terminating 0-byte)
    if (count_in_header) {
      Headertmp = (char*)realloc(Header, count_in_header*sizeof(char) + 1);
      if(!Headertmp) {
	fprintf(stderr, "Error: Could not shrink Header (Table_Read_Handle).\n");
	free(Header);
	return (-1);
      } else {
        Header = Headertmp;
      }
    }
    Table->header = Header;

    if (count_in_array*Rows*Columns == 0)
    {
      Table->rows         = 0;
      Table->columns      = 0;
      free(Data);
      return (0);
    }
    if (Rows * Columns != count_in_array)
    {
      fprintf(stderr, "Warning: Read_Table :%s %s Data has %li values that should be %li x %li\n",
        (Table->filename[0] != '\0' ? Table->filename : ""),
        (!block_number ? " catenated" : ""),
        count_in_array, Rows, Columns);
      Columns = count_in_array; Rows = 1;
    }
    if (count_invalid)
    {
      fprintf(stderr,"Warning: Read_Table :%s %s Data has %li invalid lines (*****). Ignored.\n",
      (Table->filename[0] != '\0' ? Table->filename : ""),
        (!block_number ? " catenated" : ""),
        count_invalid);
    }
    Datatmp     = (double*)realloc(Data, count_in_array*sizeof(double));
    if(!Datatmp) {
      fprintf(stderr, "Error: Could reallocate Data block to %li doubles (Table_Read_Handle).\n", count_in_array);
      free(Data);
      return (-1);
    } else {
      Data = Datatmp;
    }
    Table->data         = Data;
    Table->rows         = Rows;
    Table->columns      = Columns;

    return (count_in_array);

  } /* end Table_Read_Handle */

/*******************************************************************************
* long Table_Rebin(t_Table *Table)
*   ACTION: rebin a single Table, sorting 1st column in ascending order
*   input   Table: single table containing data.
*                  The data block is reallocated in this process
*   return  updated Table with increasing, evenly spaced first column (index 0)
*           number of data elements (-1: error, 0:empty data)
*******************************************************************************/
  long Table_Rebin(t_Table *Table)
  {
    double new_step=0;
    long   i;
    /* performs linear interpolation on X axis (0-th column) */

    if (!Table) return(-1);
    if (!Table->data 
    || Table->rows*Table->columns == 0 || !Table->step_x)
      return(0);
    Table_Stat(Table); /* recompute statitstics and minimal step */
    new_step = Table->step_x; /* minimal step in 1st column */

    if (!(Table->constantstep)) /* not already evenly spaced */
    {
      long Length_Table;
      double *New_Table;

      Length_Table = ceil(fabs(Table->max_x - Table->min_x)/new_step)+1;
      /*return early if the rebinned table will become too large*/
      if (Length_Table > mcread_table_rebin_maxsize){
        fprintf(stderr,"WARNING: (Table_Rebin): Rebinning table from %s would exceed 1M rows. Skipping.\n", Table->filename); 
        return(Table->rows*Table->columns);
      }
      New_Table    = (double*)malloc(Length_Table*Table->columns*sizeof(double));
      if (!New_Table) {
	fprintf(stderr,"Could not allocate New_Table of size %ld x %ld\n", Length_Table, Table->columns);
	exit(-1);
      }
      for (i=0; i < Length_Table; i++)
      {
        long   j;
        double X;
        X = Table->min_x + i*new_step;
        New_Table[i*Table->columns] = X;
        for (j=1; j < Table->columns; j++)
          New_Table[i*Table->columns+j]
                = Table_Value(*Table, X, j);
      } /* end for i */

      Table->rows = Length_Table;
      Table->step_x = new_step;
      Table->max_x = Table->min_x + (Length_Table-1)*new_step; 
      /*max might not be the same anymore
       * Use Length_Table -1 since the first and laset rows are the limits of the defined interval.*/
      free(Table->data);
      Table->data = New_Table;
      Table->constantstep=1;
    } /* end else (!constantstep) */
    return (Table->rows*Table->columns);
  } /* end Table_Rebin */

/*******************************************************************************
* double Table_Index(t_Table Table, long i, long j)
*   ACTION: read an element [i,j] of a single Table
*   input   Table: table containing data
*           i : index of row      (0:Rows-1)
*           j : index of column   (0:Columns-1)
*   return  Value = data[i][j]
* Returns Value from the i-th row, j-th column of Table
* Tests are performed on indexes i,j to avoid errors
*******************************************************************************/

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif

double Table_Index(t_Table Table, long i, long j)
{
  long AbsIndex;

  if (Table.rows == 1 || Table.columns == 1) {
    /* vector */
    j = MIN(MAX(0, i+j), Table.columns*Table.rows - 1);
    i = 0;
  } else {
    /* matrix */
    i = MIN(MAX(0, i), Table.rows - 1);
    j = MIN(MAX(0, j), Table.columns - 1);
  }

  /* handle vectors specifically */
  AbsIndex = i*(Table.columns)+j;

  if (Table.data != NULL)
    return (Table.data[AbsIndex]);
  else
    return 0;
} /* end Table_Index */

/*******************************************************************************
* void Table_SetElement(t_Table *Table, long i, long j, double value)
*   ACTION: set an element [i,j] of a single Table
*   input   Table: table containing data
*           i : index of row      (0:Rows-1)
*           j : index of column   (0:Columns-1)
*           value = data[i][j]
* Returns 0 in case of error
* Tests are performed on indexes i,j to avoid errors
*******************************************************************************/
int Table_SetElement(t_Table *Table, long i, long j,
                     double value)
{
  long AbsIndex;

  if (Table->rows == 1 || Table->columns == 1) {
    /* vector */
    j = MIN(MAX(0, i+j), Table->columns*Table->rows - 1); i=0;
  } else {
    /* matrix */
    i = MIN(MAX(0, i), Table->rows - 1);
    j = MIN(MAX(0, j), Table->columns - 1);
  }

  AbsIndex = i*(Table->columns)+j;
  if (Table->data != NULL) {
    Table->data[AbsIndex] = value;
    return 1;
  }

  return 0;
} /* end Table_SetElement */

/*******************************************************************************
* double Table_Value(t_Table Table, double X, long j)
*   ACTION: read column [j] of a single Table at row which 1st column is X
*   input   Table: table containing data.
*           X : data value in the first column (index 0)
*           j : index of column from which is extracted the Value (0:Columns-1)
*   return  Value = data[index for X][j] with linear interpolation
* Returns Value from the j-th column of Table corresponding to the
* X value for the 1st column (index 0)
* Tests are performed (within Table_Index) on indexes i,j to avoid errors
* NOTE: data should rather be monotonic, and evenly sampled.
*******************************************************************************/
double Table_Value(t_Table Table, double X, long j)
{
  long   Index = -1;
  double X1=0, Y1=0, X2=0, Y2=0;
  double ret=0;

  if (X > Table.max_x) return Table_Index(Table,Table.rows-1  ,j);
  if (X < Table.min_x) return Table_Index(Table,0  ,j);

  // Use constant-time lookup when possible
  if(Table.constantstep) {
    Index = (long)floor(
              (X - Table.min_x) / (Table.max_x - Table.min_x) * (Table.rows-1));
    X1 = Table_Index(Table,Index-1,0);
    X2 = Table_Index(Table,Index  ,0);
  }
  // Use binary search on large, monotonic tables
  else if(Table.monotonic && Table.rows > 100) {
    long left = Table.min_x;
    long right = Table.max_x;

    while (!((X1 <= X) && (X < X2)) && (right - left > 1)) {
      Index = (left + right) / 2;

      X1 = Table_Index(Table, Index-1, 0);
      X2 = Table_Index(Table, Index,   0);

      if (X < X1) {
        right = Index;
      } else {
        left  = Index;
      }
    }
  }

  // Fall back to linear search, if no-one else has set X1, X2 correctly
  if (!((X1 <= X) && (X < X2))) {
    /* look for index surrounding X in the table -> Index */
    for (Index=1; Index <= Table.rows-1; Index++) {
        X1 = Table_Index(Table, Index-1,0);
        X2 = Table_Index(Table, Index  ,0);
        if ((X1 <= X) && (X < X2)) break;
      } /* end for Index */
  }

  Y1 = Table_Index(Table,Index-1, j);
  Y2 = Table_Index(Table,Index  , j);

#ifdef OPENACC
#define strcmp(a,b) str_comp(a,b)
#endif

  if (!strcmp(Table.method,"linear")) {
    ret = Table_Interp1d(X, X1,Y1, X2,Y2);
  }
  else if (!strcmp(Table.method,"nearest")) {
    ret = Table_Interp1d_nearest(X, X1,Y1, X2,Y2);
  }

#ifdef OPENACC
#ifdef strcmp
#undef strcmp
#endif
#endif

  return ret;
} /* end Table_Value */

/*******************************************************************************
* double Table_Value2d(t_Table Table, double X, double Y)
*   ACTION: read element [X,Y] of a matrix Table
*   input   Table: table containing data.
*           X : row index, may be non integer
*           Y : column index, may be non integer
*   return  Value = data[index X][index Y] with bi-linear interpolation
* Returns Value for the indices [X,Y]
* Tests are performed (within Table_Index) on indexes i,j to avoid errors
* NOTE: data should rather be monotonic, and evenly sampled.
*******************************************************************************/
double Table_Value2d(t_Table Table, double X, double Y)
  {
    long   x1,x2,y1,y2;
    double z11,z12,z21,z22;
    double ret=0;

    x1 = (long)floor(X);
    y1 = (long)floor(Y);

    if (x1 > Table.rows-1 || x1 < 0) {
      x2 = x1;
    } else {
      x2 = x1 + 1;
    }

    if (y1 > Table.columns-1 || y1 < 0) {
      y2 = y1;
    } else {
      y2 = y1 + 1;
    }

    z11 = Table_Index(Table, x1, y1);

    if (y2 != y1) z12=Table_Index(Table, x1, y2); else z12 = z11;
    if (x2 != x1) z21=Table_Index(Table, x2, y1); else z21 = z11;
    if (y2 != y1) z22=Table_Index(Table, x2, y2); else z22 = z21;

#ifdef OPENACC
#define strcmp(a,b) str_comp(a,b)
#endif

    if (!strcmp(Table.method,"linear"))
      ret = Table_Interp2d(X,Y, x1,y1,x2,y2, z11,z12,z21,z22);
#ifdef OPENACC
#ifdef strcmp
#undef strcmp
#endif
#endif
    else {
      if (fabs(X-x1) < fabs(X-x2)) {
        if (fabs(Y-y1) < fabs(Y-y2)) ret = z11; else ret = z12;
      } else {
        if (fabs(Y-y1) < fabs(Y-y2)) ret = z21; else ret = z22;
      }
    }
    return ret;
  } /* end Table_Value2d */


/*******************************************************************************
* void Table_Free(t_Table *Table)
*   ACTION: free a single Table. First Call Table_File_list_gc. If this returns
*   non-zero it means there are more refernces to the table, and so the table
*   should not bee freed.
*   return: empty Table
*******************************************************************************/
  void Table_Free(t_Table *Table)
  {
    if( !Table_File_List_gc(Table) ){
       return;
    } 
    if (!Table) return;
    if (Table->data   != NULL) free(Table->data);
    if (Table->header != NULL) free(Table->header);
    Table->data   = NULL;
    Table->header = NULL;
  } /* end Table_Free */

/******************************************************************************
* void Table_Info(t_Table Table)
*    ACTION: print informations about a single Table
*******************************************************************************/
  long Table_Info(t_Table Table)
  {
    char buffer[256];
    long ret=0;

    if (!Table.block_number) strcpy(buffer, "catenated");
    else sprintf(buffer, "block %li", Table.block_number);
    printf("Table from file '%s' (%s)",
        Table.filename[0] != '\0' ? Table.filename : "", buffer);
    if ((Table.data != NULL) && (Table.rows*Table.columns))
    {
      printf(" is %li x %li ", Table.rows, Table.columns);
      if (Table.rows*Table.columns > 1)
        printf("(x=%g:%g)", Table.min_x, Table.max_x);
      else printf("(x=%g) ", Table.min_x);
      ret = Table.rows*Table.columns;
      if (Table.monotonic)    printf(", monotonic");
      if (Table.constantstep) printf(", constant step");
      printf(". interpolation: %s\n", Table.method);
    }
    else printf(" is empty.\n");

    if (Table.header && strlen(Table.header)) {
      char *header;
      int  i;
      header = malloc(80);
      if (!header) return(ret);
      for (i=0; i<80; header[i++]=0);
      strncpy(header, Table.header, 75);
      if (strlen(Table.header) > 75) {
        strcat( header, " ...");
      }
      for (i=0; i<strlen(header); i++)
        if (header[i] == '\n' || header[i] == '\r') header[i] = ';';
      printf("  '%s'\n", header);
      free(header);
    }

    return(ret);
  } /* end Table_Info */

/******************************************************************************
* long Table_Init(t_Table *Table, m, n)
*   ACTION: initialise a Table to empty m by n table
*   return: empty Table
******************************************************************************/
long Table_Init(t_Table *Table, long rows, long columns)
{
  double *data=NULL;
  long   i;

  if (!Table) return(0);

  Table->header  = NULL;
  Table->filename[0]= '\0';
  Table->filesize= 0;
  Table->min_x   = 0;
  Table->max_x   = 0;
  Table->step_x  = 0;
  Table->block_number = 0;
  Table->array_length = 0;
  Table->monotonic    = 0;
  Table->constantstep = 0;
  Table->begin   = 0;
  Table->end     = 0;
  strcpy(Table->method,"linear");

  if (rows*columns >= 1) {
    data    = (double*)malloc(rows*columns*sizeof(double));
    if (data) for (i=0; i < rows*columns; data[i++]=0);
    else {
      if(Table->quiet<2)
        fprintf(stderr,"Error: allocating %ld double elements."
            "Too big (Table_Init).\n", rows*columns);
      rows = columns = 0;
    }
  }
  Table->rows    = (rows >= 1 ? rows : 0);
  Table->columns = (columns >= 1 ? columns : 0);
  Table->data    = data;
  return(Table->rows*Table->columns);
} /* end Table_Init */

/******************************************************************************
* long Table_Write(t_Table Table, char *file, x1,x2, y1,y2)
*   ACTION: write a Table to disk (ascii).
*     when x1=x2=0 or y1=y2=0, the table default limits are used.
*   return: 0=all is fine, non-0: error
*******************************************************************************/
MCDETECTOR Table_Write(t_Table Table, char *file, char *xl, char *yl, 
  double x1, double x2, double y1, double y2)
{
  MCDETECTOR detector;

  if ((Table.data == NULL) && (Table.rows*Table.columns)) {
    detector.m = 0;
    detector.xmin = 0;
    detector.xmax = 0;
    detector.ymin = 0;
    detector.ymax = 0;
    detector.zmin = 0;
    detector.zmax = 0; 
    detector.intensity = 0;
    detector.error = 0;
    detector.events = 0;
    detector.min = 0;
    detector.max = 0;
    detector.mean = 0;
    detector.centerX = 0;
    detector.halfwidthX = 0;
    detector.centerY = 0;
    detector.halfwidthY = 0;
    detector.rank = 0;
    detector.istransposed = 0;
    detector.n = 0;
    detector.p = 0;
    detector.date_l = 0;
    detector.p0 = NULL;
    detector.p1 = NULL;
    detector.p2 = NULL;
    return(detector); /* Table is empty - nothing to do */
  }
  if (!x1 && !x2) {
    x1 = Table.min_x;
    x2 = Table.max_x;
  }
  if (!y1 && !y2) {
    y1 = 1;
    y2 = Table.columns;
  }

  /* transfer content of the Table into a 2D detector */
  Coords coords = { 0, 0, 0};
  Rotation rot;
  rot_set_rotation(rot, 0, 0, 0);
  
  if (Table.rows == 1 || Table.columns == 1) {
    detector = mcdetector_out_1D(Table.filename,
                      xl ? xl : "", yl ? yl : "",
                      "x", x1, x2,
                      Table.rows * Table.columns,
                      NULL, Table.data, NULL,
		      file, file, coords, rot,9999);
  } else {
    detector = mcdetector_out_2D(Table.filename,
                      xl ? xl : "", yl ? yl : "",
                      x1, x2, y1, y2,
                      Table.rows, Table.columns,
                      NULL, Table.data, NULL,
		      file, file, coords, rot,9999);
  }
  return(detector);
}

/******************************************************************************
* void Table_Stat(t_Table *Table)
*   ACTION: computes min/max/mean step of 1st column for a single table (private)
*   return: updated Table
*******************************************************************************/
  static void Table_Stat(t_Table *Table)
  {
    long   i;
    double max_x, min_x;
    double row=1;
    char   monotonic=1;
    char   constantstep=1;
    double step=0;
    long n;

    if (!Table) return;
    if (!Table->rows || !Table->columns) return;
    if (Table->rows == 1) row=0; // single row
    max_x = -FLT_MAX;
    min_x =  FLT_MAX;
    n     = (row ? Table->rows : Table->columns);
    /* get min and max of first column/vector */
    for (i=0; i < n; i++)
    {
      double X;
      X = (row ? Table_Index(*Table,i  ,0)
                               : Table_Index(*Table,0, i));
      if (X < min_x) min_x = X;
      if (X > max_x) max_x = X;
    } /* for */
    
    /* test for monotonicity and constant step if the table is an XY or single vector */
    if (n > 1) {
      /* mean step */
      step = (max_x - min_x)/(n-1);
      /* now test if table is monotonic on first column, and get minimal step size */
      for (i=0; i < n-1; i++) {
        double X, diff;;
        X    = (row ? Table_Index(*Table,i  ,0)
                    : Table_Index(*Table,0,  i));
        diff = (row ? Table_Index(*Table,i+1,0)
                    : Table_Index(*Table,0,  i+1)) - X;
        if (diff && fabs(diff) < fabs(step)) step = diff;
        /* change sign ? */
        if ((max_x - min_x)*diff < 0 && monotonic)
          monotonic = 0;
      } /* end for */
      
      /* now test if steps are constant within READ_TABLE_STEPTOL */
      if(!step){
        /*means there's a disconitnuity -> not constantstep*/
        constantstep=0;
      }else if (monotonic) {
        for (i=0; i < n-1; i++) {
          double X, diff;
          X    = (row ? Table_Index(*Table,i  ,0)
              : Table_Index(*Table,0,  i));
          diff = (row ? Table_Index(*Table,i+1,0)
              : Table_Index(*Table,0,  i+1)) - X;
          if ( fabs(step)*(1+READ_TABLE_STEPTOL) < fabs(diff) ||
                fabs(diff) < fabs(step)*(1-READ_TABLE_STEPTOL) )
          { constantstep = 0; break; }
        }
      }

    }
    Table->step_x= step;
    Table->max_x = max_x;
    Table->min_x = min_x;
    Table->monotonic = monotonic;
    Table->constantstep = constantstep;
  } /* end Table_Stat */

/******************************************************************************
* t_Table *Table_Read_Array(char *File, long *blocks)
*   ACTION: read as many data blocks as available, iteratively from file
*   return: initialized t_Table array, last element is an empty Table.
*           the number of extracted blocks in non NULL pointer *blocks
*******************************************************************************/
  t_Table *Table_Read_Array(char *File, long *blocks)
  {
    t_Table *Table_Array    = NULL;
    t_Table *Table_Arraytmp = NULL;
    long offset=0;
    long block_number=0;
    long allocated=256;
    long nelements=1;

    /* first allocate an initial empty t_Table array */
    Table_Array = (t_Table *)malloc(allocated*sizeof(t_Table));
    if (!Table_Array) {
      fprintf(stderr, "Error: Can not allocate memory %zi (Table_Read_Array).\n",
         allocated*sizeof(t_Table));
      *blocks = 0;
      return (NULL);
    }

    while (nelements > 0)
    {
      t_Table Table;

      /* if ok, set t_Table block number else exit loop */
      block_number++;
      Table.block_number = block_number;
      
      /* access file at offset and get following block. Block number is from the set offset
       * hence the hardcoded 1 - i.e. the next block counted from offset.*/
      nelements = Table_Read_Offset(&Table, File, 1, &offset,0);
      /*if the block is empty - don't store it*/
      if (nelements>0){
          /* if t_Table array is not long enough, expand and realocate */
          if (block_number >= allocated-1) {
              allocated += 256;
              Table_Arraytmp = (t_Table *)realloc(Table_Array,
                      allocated*sizeof(t_Table));
              if (!Table_Arraytmp) {
                  fprintf(stderr, "Error: Can not re-allocate memory %zi (Table_Read_Array).\n",
                          allocated*sizeof(t_Table));
                  free(Table_Array);
                  *blocks = 0;
                  return (NULL);
              } else {
                Table_Array = Table_Arraytmp;
              }
          }
          /* store it into t_Table array */
          //snprintf(Table.filename, 1024, "%s#%li", File, block_number-1);
          Table_Array[block_number-1] = Table;
      }
      /* continues until we find an empty block */
    }
    /* send back number of extracted blocks */
    if (blocks) *blocks = block_number-1;

    /* now store total number of elements in Table array */
    for (offset=0; offset < block_number;
      Table_Array[offset++].array_length = block_number-1);

    return(Table_Array);
  } /* end Table_Read_Array */
/*******************************************************************************
* void Table_Free_Array(t_Table *Table)
*   ACTION: free a Table array
*******************************************************************************/
  void Table_Free_Array(t_Table *Table)
  {
    long index;
    if (!Table) return;
    for (index=0;index < Table[0].array_length; index++){
            Table_Free(&Table[index]);
    }
    free(Table);
  } /* end Table_Free_Array */

/******************************************************************************
* long Table_Info_Array(t_Table *Table)
*    ACTION: print informations about a Table array
*    return: number of elements in the Table array
*******************************************************************************/
  long Table_Info_Array(t_Table *Table)
  {
    long index=0;

    if (!Table) return(-1);
    while (index < Table[index].array_length
       && (Table[index].data || Table[index].header)
       && (Table[index].rows*Table[index].columns) ) {
      Table_Info(Table[index]);
      index++;
    }
    printf("This Table array contains %li elements\n", index);
    return(index);
  } /* end Table_Info_Array */

/******************************************************************************
* char **Table_ParseHeader(char *header, symbol1, symbol2, ..., NULL)
*    ACTION: search for char* symbols in header and return their value or NULL
*            the search is not case sensitive.
*            Last argument MUST be NULL
*    return: array of char* with line following each symbol, or NULL if not found
*******************************************************************************/
#ifndef MyNL_ARGMAX
#define MyNL_ARGMAX 50
#endif

char **Table_ParseHeader_backend(char *header, ...){
  va_list ap;
  char exit_flag=0;
  int counter   =0;
  char **ret    =NULL;
  if (!header || header[0]=='\0') return(NULL);

  ret = (char**)calloc(MyNL_ARGMAX, sizeof(char*));
  if (!ret) {
    printf("Table_ParseHeader: Cannot allocate %i values array for Parser (Table_ParseHeader).\n",
      MyNL_ARGMAX);
    return(NULL);
  }
  for (counter=0; counter < MyNL_ARGMAX; ret[counter++] = NULL);
  counter=0;

  va_start(ap, header);
  while(!exit_flag && counter < MyNL_ARGMAX-1)
  {
    char *arg_char=NULL;
    char *pos     =NULL;
    /* get variable argument value as a char */
    arg_char = va_arg(ap, char *);
    if (!arg_char || arg_char[0]=='\0'){
      exit_flag = 1; break;
    }
    /* search for the symbol in the header */
    pos = (char*)strcasestr(header, arg_char);
    if (pos) {
      char *eol_pos;
      eol_pos = strchr(pos+strlen(arg_char), '\n');
      if (!eol_pos)
        eol_pos = strchr(pos+strlen(arg_char), '\r');
      if (!eol_pos)
        eol_pos = pos+strlen(pos)-1;
      ret[counter] = (char*)malloc(eol_pos - pos);
      if (!ret[counter]) {
        printf("Table_ParseHeader: Cannot allocate value[%i] array for Parser searching for %s (Table_ParseHeader).\n",
          counter, arg_char);
        exit_flag = 1; break;
      }
      strncpy(ret[counter], pos+strlen(arg_char), eol_pos - pos - strlen(arg_char));
      ret[counter][eol_pos - pos - strlen(arg_char)]='\0';
    }
    counter++;
  }
  va_end(ap);
  return(ret);
} /* Table_ParseHeader */

/******************************************************************************
* double Table_Interp1d(x, x1, y1, x2, y2)
*    ACTION: interpolates linearly at x between y1=f(x1) and y2=f(x2)
*    return: y=f(x) value
*******************************************************************************/
double Table_Interp1d(double x,
  double x1, double y1,
  double x2, double y2)
{
  double slope;
  if (x2 == x1) return (y1+y2)/2;
  if (y1 == y2) return  y1;
  slope = (y2 - y1)/(x2 - x1);
  return y1+slope*(x - x1);
} /* Table_Interp1d */

/******************************************************************************
* double Table_Interp1d_nearest(x, x1, y1, x2, y2)
*    ACTION: table lookup with nearest method at x between y1=f(x1) and y2=f(x2)
*    return: y=f(x) value
*******************************************************************************/
double Table_Interp1d_nearest(double x,
  double x1, double y1,
  double x2, double y2)
{
  if (fabs(x-x1) < fabs(x-x2)) return (y1);
  else return(y2);
} /* Table_Interp1d_nearest */

/******************************************************************************
* double Table_Interp2d(x,y, x1,y1, x2,y2, z11,z12,z21,z22)
*    ACTION: interpolates bi-linearly at (x,y) between z1=f(x1,y1) and z2=f(x2,y2)
*    return: z=f(x,y) value
*    x,y |   x1   x2
*    ----------------
*     y1 |   z11  z21
*     y2 |   z12  z22
*******************************************************************************/
double Table_Interp2d(double x, double y,
  double x1, double y1,
  double x2, double y2,
  double z11, double z12, double z21, double z22)
{
  double ratio_x, ratio_y;
  if (x2 == x1) return Table_Interp1d(y, y1,z11, y2,z12);
  if (y1 == y2) return Table_Interp1d(x, x1,z11, x2,z21);

  ratio_y = (y - y1)/(y2 - y1);
  ratio_x = (x - x1)/(x2 - x1);
  return (1-ratio_x)*(1-ratio_y)*z11 + ratio_x*(1-ratio_y)*z21
    + ratio_x*ratio_y*z22         + (1-ratio_x)*ratio_y*z12;
} /* Table_Interp2d */

/* end of read_table-lib.c */
#endif // READ_TABLE_LIB_C


  #ifndef SOURCE_GEN_DEF
  #define SOURCE_GEN_DEF
  /*******************************************************************************
   * str_dup_numeric: makes a clean copy of a string and allocate as numeric
   *******************************************************************************/
  char*
  str_dup_numeric (char* orig) {
    long i;
    char* valid;

    if (!orig || !strlen (orig))
      return (NULL);

    for (i = 0; i < strlen (orig); i++) {
      if ((orig[i] > 122) || (orig[i] < 32) || (strchr ("!\"#$%&'()*,:;<=>?@[\\]^`/ ", orig[i]) != NULL)) {
        orig[i] = ' ';
      }
    }
    orig[i] = '\0';
    /* now skip spaces */
    for (i = 0; i < strlen (orig); i++) {
      if (*orig == ' ')
        orig++;
      else
        break;
    }

    return (orig);
  } /* str_dup_numeric */
  #endif

/* Shared user declarations for all components types 'Elliptic_guide_gravity'. */
/*****************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright 1997-2006, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/ref-lib.h
*
* %Identification
* Written by: Peter Christiansen
* Date: August, 2006
* Origin: RISOE
* Release: McStas 1.10
* Version: $Revision$
*
* Add StdDoubleReflecFunc, ExtendedReflecFunc
* Date: October, 2022
* Locale: ESS
* Release: McStas 2.7x, 3.1x
*
* Commonly used reflection functions are declared in this file which
* are used by some guide and mirror components.
*
* Depends on read_table-lib
*
* Usage: within SHARE
* %include "ref-lib"
*
****************************************************************************/


#ifndef REF_LIB_H
#define REF_LIB_H "$Revision$"

void StdReflecFunc(double, double*, double*);
void TableReflecFunc(double, t_Table*, double*);
void StdDoubleReflecFunc(double, double*, double*);
void ExtendedReflecFunc(double, double*, double*);

#endif

/* end of ref-lib.h */
/****************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright 1997-2006, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/ref-lib.c
*
* %Identification
* Written by: Peter Christiansen
* Date: August, 2006
* Origin: RISOE
* Release: McStas 1.10
* Version: $Revision$
*
* Add StdDoubleReflecFunc, ExtendedReflecFunc
* Date: October, 2022
* Locale: ESS
* Release: McStas 2.7.x, 3.x
*
* Commonly used reflection functions are declared in this file which
* are used by some guide and mirror components.
*
* Variable names have prefix 'mc_ref_' for 'McStas Reflection'
* to avoid conflicts
*
* Usage: within SHARE
* %include "ref-lib"
*
****************************************************************************/

#ifndef REF_LIB_H
#include "ref-lib.h"
#endif

#ifndef READ_TABLE_LIB_H
#include "read_table-lib.h"
#include "read_table-lib.c"
#endif

/****************************************************************************
* void StdReflecFunc(double q, double *par, double *r)
*
* The McStas standard analytic parametrization of the reflectivity.
* The parameters are:
* R0:      [1]    Low-angle reflectivity
* Qc:      [AA-1] Critical scattering vector
* alpha:   [AA]   Slope of reflectivity
* m:       [1]    m-value of material. Zero means completely absorbing.
* W:       [AA-1] Width of supermirror cut-off
*****************************************************************************/
#pragma acc routine seq
void StdReflecFunc(double mc_pol_q, double *mc_pol_par, double *mc_pol_r) {
    double R0    = mc_pol_par[0];
    double Qc    = mc_pol_par[1];
    double alpha = mc_pol_par[2];
    double m     = mc_pol_par[3];
    double W     = mc_pol_par[4];
    double beta  = 0;
    mc_pol_q     = fabs(mc_pol_q);
    double arg;
    double m_corr;

    /* Simpler parametrization from Henrik Jacobsen uses these values that depend on m only.
       double m_value=m*0.9853+0.1978;
       double W=-0.0002*m_value+0.0022;
       double alpha=0.2304*m_value+5.0944;
       double beta=-7.6251*m_value+68.1137;
       If W and alpha are set to 0, use Henrik's approach for estimating these parameters
       and apply the formulation:
       arg = R0*0.5*(1-tanh(arg))*(1-alpha*(q-Qc)+beta*(q-Qc)*(q-Qc));
    */
    if (W==0 && alpha==0) {
      m = m * 0.9853 + 0.1978;
      m_corr = m * 0.9853 - 0.7875;
      W = -0.0002 * m_corr + 0.0022;
      alpha = 0.2304 * m_corr + 5.0944;
      beta = -7.6251 * m_corr + 68.1137;
      if (m==3) {
	alpha = m_corr;
	beta = 0;
      }
      arg = (mc_pol_q - m*Qc)/W; // <--- here m, not m_corr!!
    }

    arg = W > 0 ? (mc_pol_q - m*Qc)/W : 11;

    if (arg > 10 || m <= 0 || Qc <=0 || R0 <= 0) {
      *mc_pol_r = 0;
      return;
    }

    if (m < 1) { Qc *= m; m=1; }

    if(mc_pol_q <= Qc) {
      *mc_pol_r = R0;
      return;
    }


    *mc_pol_r = R0*0.5*(1 - tanh(arg))*(1 - alpha*(mc_pol_q - Qc) + beta*(mc_pol_q - Qc)*(mc_pol_q - Qc));

    return;
  }

/****************************************************************************
* void TableReflecFunc(double q, t_Table *par, double *r) {
*
* Looks up the reflectivity in a table using the routines in read_table-lib.
*****************************************************************************/
#pragma acc routine seq
void TableReflecFunc(double mc_pol_q, t_Table *mc_pol_par, double *mc_pol_r) {

  *mc_pol_r = Table_Value(*mc_pol_par, mc_pol_q, 1);
  if(*mc_pol_r>1)
    *mc_pol_r = 1;
  return;
}


/****************************************************************************
* void StdDoubleReflecFunc(double q, double *par, double *r)
* 
* The McStas standard analytic parametrization of the reflectivity for 
* double-side coated supermirror.
* The parameters are:
* R0:      [1]    Low-angle reflectivity
* Qc:      [AA-1] Critical scattering vector
* alpha:   [AA]   Slope of reflectivity
* m:       [1]    m-value of material. Zero means completely absorbing.
* W:       [AA-1] Width of supermirror cut-off
*****************************************************************************/
void StdDoubleReflecFunc(double mc_pol_q, double *mc_pol_par, double *mc_pol_r) {
    double R0    = mc_pol_par[0];
    double Qc    = mc_pol_par[1];
    double alpha = mc_pol_par[2];
    double m     = mc_pol_par[3];
    double W     = mc_pol_par[4];
    double beta  = 0;
    mc_pol_q     = fabs(mc_pol_q);
    double arg;
        
    /* Simpler parametrization from Henrik Jacobsen uses these values that depend on m only.
       double m_value=m*0.9853+0.1978;
       double W=-0.0002*m_value+0.0022;
       double alpha=0.2304*m_value+5.0944;
       double beta=-7.6251*m_value+68.1137; 
       If W and alpha are set to 0, use Henrik's approach for estimating these parameters
       and apply the formulation:
       arg = R0*0.5*(1-tanh(arg))*(1-alpha*(q-Qc)+beta*(q-Qc)*(q-Qc));
    */  
    if (W==0 && alpha==0) {
      m=m*0.9853+0.1978;
      W=-0.0002*m+0.0022;
      alpha=0.2304*m+5.0944;
      beta=-7.6251*m+68.1137;
      if (m<=3) {
	alpha=m;
	beta=0;
      }
    }
    
    arg = W > 0 ? (mc_pol_q - m*Qc)/W : 11;

    if (arg > 10 || m <= 0 || Qc <=0 || R0 <= 0) {
      *mc_pol_r = 0;
      return;
    }
    
    if (m < 1) { Qc *= m; m=1; }
    
	/*
		Reflectivity R0 = single-side coated supermirror reflectivity
		double-side coated supermirror reflectivity = 1- (1-R0)^2
	*/
	
    if(mc_pol_q <= Qc) {      
      *mc_pol_r = 1- (1-R0)*(1-R0);
      return;
    }
    
    
    R0 = R0*0.5*(1 - tanh(arg))*(1 - alpha*(mc_pol_q - Qc) + beta*(mc_pol_q - Qc)*(mc_pol_q - Qc));
    *mc_pol_r = 1- (1-R0)*(1-R0);
   
    return;
  }

void ExtendedReflecFunc(double mc_pol_q, double *mc_pol_par, double *mc_pol_r) {
    double R0    = mc_pol_par[0];
    double Qc    = mc_pol_par[1];
    double alpha = mc_pol_par[2];
    double m     = mc_pol_par[3];
    double W     = mc_pol_par[4];
    double beta  = mc_pol_par[5];
    mc_pol_q     = fabs(mc_pol_q);
    double arg;

    /* Simpler parametrization from Henrik Jacobsen uses these values that depend on m only.
       double m_value=m*0.9853+0.1978;
       double W=-0.0002*m_value+0.0022;
       double alpha=0.2304*m_value+5.0944;
       double beta=-7.6251*m_value+68.1137;
       If W and alpha are set to 0, use Henrik's approach for estimating these parameters
       and apply the formulation:
       arg = R0*0.5*(1-tanh(arg))*(1-alpha*(q-Qc)+beta*(q-Qc)*(q-Qc));
    */
    if (W==0 && alpha==0) {
      m=m*0.9853+0.1978;
      W=-0.0002*m+0.0022;
      alpha=0.2304*m+5.0944;
      beta=-7.6251*m+68.1137;
      if (m<=3) {
	alpha=m;
	beta=0;
      }
    }

    arg = W > 0 ? (mc_pol_q - m*Qc)/W : 11;

    if (arg > 10 || m <= 0 || Qc <=0 || R0 <= 0) {
      *mc_pol_r = 0;
      return;
    }

    if (m < 1) { Qc *= m; m=1; }

    if(mc_pol_q <= Qc) {
      *mc_pol_r = R0;
      return;
    }


    *mc_pol_r = R0*0.5*(1 - tanh(arg))*(1 - alpha*(mc_pol_q - Qc) + beta*(mc_pol_q - Qc)*(mc_pol_q - Qc));

    return;
  }

/* end of ref-lib.c */


  ///////////////////////////////////////////////////////////////////////////
  /////////////// local structs and enums
  ///////////////////////////////////////////////////////////////////////////

  /**
  Sides of the guide
  */
  enum Side { RightSide, TopSide, LeftSide, BottomSide, None };

  /**
  The type of the collision is set in the collision function
  and decide the functions called in trace()
          Reflex (TODO change this name) calls the reflection function
          Absorb calls the built in ABSORB funtion.
          LeaveGuide calls break and end the calculations in this component
          EnterGuide does nothing
  */
  enum CollisionType { Reflex, Absorb, LeaveGuide, EnterGuide };

  /**
          The Mirror type sets the CollisionType of particles colliding on the mirror
  */
  enum MirrorType { MirrorTypeReflection, MirrorTypeTransparent, MirrorTypeabsorption };

  // enum IntersectionType {Reflex,Absorb,Transparent,Leave,Enter};

  /**
          Collision between guide and the particle
          contain infomation on the time to the next collision,
          which side of the guide it is on and whether this part of the guide
          is a perfect or approximated ellipse.
  */
  struct Intersection {
    double delta_time_to_next_collision;
    enum Side side; // A number from 0 to 4 (4 being an error warning)
    int ApproxOn;
    enum CollisionType collisionType;
  };

  /**
          Static Guide information (SGI)
          contain information on the guide, the ellipses and the mirrors on all sides
  */
  struct SGI {
    // guide infomation
    double Length;
    double entranceHorizontalWidth, entranceVerticalWidth;
    double exitHorizontalWidth, exitVerticalWidth;

    // ellipses infomation
    double ellipseMajorAxis[4], ellipseMinorAxis[4];
    double ellipseMajorOffset[4], ellipseMinorOffset[4];

    // mirror infomation
    double R0Arr[4];
    double QcArr[4];
    double alphaArr[4];
    double mArr[4];
    double WArr[4];

    // mirror type
    enum MirrorType InnerSide[4];
    enum MirrorType OuterSide[4];

    // selene
    int EnclosingBoxOn;
    double xArray[8];
    double yArray[8];
    double zArray[8];

    // segmentation
    int numberOfSegments;
    int enableSegments;
    double* mValuesright;
    double* mValuesleft;
    double* mValuestop;
    double* mValuesbottom;
    double* segLength;

    int verboseSetting;
  };

  ///////////////////////////////////////////////////////////////////////////
  /////////////// Error Handling Functions
  ///////////////////////////////////////////////////////////////////////////

  /**
          If a user input is less than zero and hence doesn't allow for a well
          define geomtric of the guide or physical values for mirrors
          @param var is the input varible there the error occurred [text]
  */
  int
  guide_elliptical_illegalInputLessThanZero (char* var, int verbose) {
    if (verbose)
      printf ("The user defined variable %s in %s has an illegal value"
              " less than zero\n",
              var, "Elliptic_guide_gravity");
    return 1;
  }

  /**
          The first focal point is in and the second is out.
          If -in-out > L then they would change position as the
          first and second focal points. This is
          @param in,out is the input varible there the error occurred [text]
  */
  int
  guide_elliptical_illegalInputFocalPointsHyperbola (char* in, char* out, double inValue, double outValue, int verbose) {
    if (verbose) {
      printf ("The user defined length of the guide, length \
  				and the focal points %s and %s does not result \
  				in an well defined ellipse. swap the focal points \
  				or increase L, %s or %s to fix this problem\n",
              in, out, in, out);
      printf ("The mininum length of the should be around %e\n", inValue + outValue + 0.000001);
    }
    return 1;
  }

  /**
          Gives a warning if a part of the code is called that
          should not be accessible if the algoritmes are working correctly
          Most likely errors are floating points and ill-defined cases
  */
  void
  guide_elliptical_callCriticalWarning (char* func, int verbose) {
    if (verbose)
      printf ("A CRITICAL WARNING has been called inside %s by function %s."
              "This is most likely due to a programming error \
  			inside the component. \n",
              "Elliptic_guide_gravity", func);
  }

  ///////////////////////////////////////////////////////////////////////////
  /////////////// Collision handling functions
  ///////////////////////////////////////////////////////////////////////////

  int
  guide_elliptical_getMirrorTypeFromInput (char* input, int verbose) {
    int type = -1;
    char* r1 = "reflection";
    char* r2 = "reflect";
    char* r3 = "r";
    char* a1 = "absorption";
    char* a2 = "absorb";
    char* a3 = "a";
    char* t1 = "transparant";
    char* t2 = "trans";
    char* t3 = "t";
    if (strcmp (input, r1) == 0 || strcmp (input, r2) == 0 || strcmp (input, r3) == 0)
      type = MirrorTypeReflection;
    if (strcmp (input, a1) == 0 || strcmp (input, a2) == 0 || strcmp (input, a3) == 0)
      type = MirrorTypeabsorption;
    if (strcmp (input, t1) == 0 || strcmp (input, t2) == 0 || strcmp (input, t3) == 0)
      type = MirrorTypeTransparent;
    if (type == -1 && verbose)
      printf ("Following string is not a valid type of a mirror: %s,"
              "use reflection,absorption or transparant. \n",
              input);

    return type;
  }

  ///////////////////////////////////////////////////////////////////////////
  /////////////// Collision functions
  ///////////////////////////////////////////////////////////////////////////

  /**
          Find the intersection between the neutron and the ellipse using newton method.
          As there is up to 4 solution to this problem, and only the
          smallest positive root is the physical solution. Using the tuning points
          it is possible to look the only the potential roots to speed up calculations.

          @param coef; A pointer to the array holding the coeffecients
                          for the 4th order polynomial.
          @param startPosition, The default starting point for newton method. [s]
          @param limit; A point after all the roots of the polynial. [s]
          @param solution A pointer which will hold the physical solution
                          if this function return true.
          @return; return 1 if the physical solution is found. [boolean]
  */
  #pragma acc routine seq
  double
  guide_elliptical_foverdf (double* coefficients, double currentPoint) {
    double numerator = coefficients[0] * currentPoint * currentPoint * currentPoint * currentPoint + coefficients[1] * currentPoint * currentPoint * currentPoint
                       + coefficients[2] * currentPoint * currentPoint + coefficients[3] * currentPoint + coefficients[4];
    double denominator = 4 * coefficients[0] * currentPoint * currentPoint * currentPoint + 3 * coefficients[1] * currentPoint * currentPoint
                         + 2 * coefficients[2] * currentPoint + coefficients[3];
    return numerator / denominator;
  }
  #pragma acc routine seq
  int
  guide_elliptical_newtonRapsonsMethod4thOrder (double* coefficients, double* solution, double startingPoint, double tolerance, double max_iterations) {

    double numerator;
    double denominator;
    double t_previous;
    double t = startingPoint;
    int iteration = 0;

    do {
      t_previous = t;
      t = t_previous - guide_elliptical_foverdf (coefficients, t);
      iteration++;
    } while (fabs (t - t_previous) > tolerance && iteration < max_iterations);
    if (iteration == max_iterations) {
      return 0;
    } else {
      *solution = t;
      return 1;
    }
  }

  #pragma acc routine seq
  int
  guide_elliptical_findNeutronEllipseIntersection (double* coef, double startPosition, double limit, double* solution) {

    // in the case of no gravity
    if (coef[0] == 0 & coef[1] == 0) {
      double t1 = 0;
      double t2 = 0;
      int boolean = solve_2nd_order (&t1, &t2, coef[2], coef[3], coef[4]);

      if (t1 > startPosition) {
        *solution = t1;
      }
      if (t2 > startPosition) {
        *solution = t2;
      }
      return boolean;
    }

    double tol = 1e-15;
    double max_iter = 1e3;
    double turningP1, turningP2;

    double sp = startPosition;
    int inside;
    if (coef[0] * sp * sp * sp * sp + coef[1] * sp * sp * sp + coef[2] * sp * sp + coef[3] * sp + coef[4] < 0)
      inside = 1;
    else
      inside = 0;

    int boolean = solve_2nd_order (&turningP1, &turningP2, 12 * coef[0], 6 * coef[1], 2 * coef[2]);

    double t1 = 0, t2 = 0;
    double ss = 100;

    if (inside) {
      if (boolean)
        guide_elliptical_newtonRapsonsMethod4thOrder (coef, &t1, turningP1, tol, max_iter);
      guide_elliptical_newtonRapsonsMethod4thOrder (coef, &t2, limit, tol, max_iter);
    } else {
      if (boolean)
        guide_elliptical_newtonRapsonsMethod4thOrder (coef, &t1, turningP2, tol, max_iter);
      guide_elliptical_newtonRapsonsMethod4thOrder (coef, &t2, startPosition, tol, max_iter);
    }

    if (ss > t1 && t1 > 1e-15)
      ss = t1;
    if (ss > t2 && t2 > 1e-15)
      ss = t2;
    *solution = ss;

    return 1;
  }

  #pragma acc routine seq
  int
  guide_elliptical_handleGuideIntersection (double x, double y, double z, double vx, double vy, double vz, double Gx, double Gy, double Gz, struct SGI* guideInfo,
                                            struct Intersection* currentCollision) {
    //
    double horExS = 1 / (guideInfo->ellipseMinorAxis[RightSide] * guideInfo->ellipseMinorAxis[RightSide]);
    double horEzS = 1 / (guideInfo->ellipseMajorAxis[RightSide] * guideInfo->ellipseMajorAxis[RightSide]);
    double hordiffx = x - guideInfo->ellipseMinorOffset[RightSide];
    double hordiffz = z - guideInfo->ellipseMajorOffset[RightSide];

    double horAlpha = (Gx * Gx * horExS + Gz * Gz * horEzS) / 4;
    double horBeta = (Gx * vx * horExS + Gz * vz * horEzS);
    double horGamma = horExS * vx * vx + horEzS * vz * vz + horExS * Gx * hordiffx + horEzS * Gz * hordiffz;
    double horDelta = 2 * horExS * vx * hordiffx + 2 * horEzS * vz * hordiffz;
    double horEpsilon = horExS * hordiffx * hordiffx + horEzS * hordiffz * hordiffz - 1;

    double horCoefficients[5] = { horAlpha, horBeta, horGamma, horDelta, horEpsilon };

    double verEyS = 1 / (guideInfo->ellipseMinorAxis[TopSide] * guideInfo->ellipseMinorAxis[TopSide]);
    double verEzS = 1 / (guideInfo->ellipseMajorAxis[TopSide] * guideInfo->ellipseMajorAxis[TopSide]);
    double verdiffy = y - guideInfo->ellipseMinorOffset[TopSide];
    double verdiffz = z - guideInfo->ellipseMajorOffset[TopSide];

    double verAlpha = (Gy * Gy * verEyS + Gz * Gz * verEzS) / 4;
    double verBeta = (Gy * vy * verEyS + Gz * vz * verEzS);
    double verGamma = verEyS * vy * vy + verEzS * vz * vz + verEyS * Gy * verdiffy + verEzS * Gz * verdiffz;
    double verDelta = 2 * verEyS * vy * verdiffy + 2 * verEzS * vz * verdiffz;
    double verEpsilon = verEyS * verdiffy * verdiffy + verEzS * verdiffz * verdiffz - 1;

    double verCoefficients[5] = { verAlpha, verBeta, verGamma, verDelta, verEpsilon };

    double upperlimit;
    double startingPoint = 1e-15;

    int boolean = -1;
    // Horizontal
    double solutionH = 0;
    solve_2nd_order (&upperlimit, NULL, -0.5 * Gz, -vz, 2 * guideInfo->ellipseMajorAxis[RightSide] - z);
    int booleanH = guide_elliptical_findNeutronEllipseIntersection (horCoefficients, startingPoint, upperlimit, &solutionH);
    // Vertical
    double solutionV = 0;
    solve_2nd_order (&upperlimit, NULL, -0.5 * Gz, -vz, 2 * guideInfo->ellipseMajorAxis[TopSide] - z);
    int booleanV = guide_elliptical_findNeutronEllipseIntersection (verCoefficients, startingPoint, upperlimit, &solutionV);

    if (solutionH <= 0)
      currentCollision->delta_time_to_next_collision = solutionV;
    else if (solutionV <= 0)
      currentCollision->delta_time_to_next_collision = solutionH;
    else if (fabs (solutionH - solutionV) < 1e-12)
      return 0;
    else if (solutionH < solutionV) {
      currentCollision->delta_time_to_next_collision = solutionH;
      boolean = booleanH;
    } else {
      currentCollision->delta_time_to_next_collision = solutionV;
      boolean = booleanV;
    }

    double tside = currentCollision->delta_time_to_next_collision;
    double xside = x + vx * tside + 0.5 * Gx * tside * tside;
    double yside = y + vy * tside + 0.5 * Gy * tside * tside;
    double zside = z + vz * tside + 0.5 * Gz * tside * tside;

    double xfactor = 2
                     * sqrt (1
                             - ((zside - guideInfo->ellipseMajorOffset[RightSide]) * (zside - guideInfo->ellipseMajorOffset[RightSide]))
                                   / (guideInfo->ellipseMajorAxis[RightSide] * guideInfo->ellipseMajorAxis[RightSide]))
                     * guideInfo->ellipseMinorAxis[RightSide];

    double yfactor = 2
                     * sqrt (1
                             - ((zside - guideInfo->ellipseMajorOffset[BottomSide]) * (zside - guideInfo->ellipseMajorOffset[BottomSide]))
                                   / (guideInfo->ellipseMajorAxis[BottomSide] * guideInfo->ellipseMajorAxis[BottomSide]))
                     * guideInfo->ellipseMinorAxis[BottomSide];

    xside = xside / xfactor;
    yside = yside / yfactor;
    if (fabs (yside) >= fabs (xside)) {
      if (y > 0)
        currentCollision->side = TopSide;
      else
        currentCollision->side = BottomSide;
    } else {
      if (x < 0)
        currentCollision->side = RightSide;
      else
        currentCollision->side = LeftSide;
    }
    if (tside < 1e-15)
      printf ("low time is: %e\n", tside);

    return boolean;
  }

  ///////////////////////////////////////////////////////////////////////////
  /////////////// reflection functions
  ///////////////////////////////////////////////////////////////////////////

  /**
          Calculate the new velocity vector for the particle colliding on
          the inner side of the elliptic mirror and returns the loss-factor (TODO)

          @param pos_V0,pos_W0 Is the 2d position vector of the particle,
                          assumed to be a point on the ellipse. [m]
          @param pvel_V0,pvel_W0 Is the 2d velocity vector of the particle. [m/s]
          @param ellipse_V_axis_squared,ellipse_W_axis_squared
                          are the axes of the ellipse. [m]
          @param ellipse_V_offset,ellipse_W_offset Is the 2d vector difference
                          between the ellipse coordinate system (center of the ellipse)
                          and the guide coordinate system [m]
          @param R0, Mvalue, Qc, W, Alpha #TODO
                  slaa beskrivelse af disse variabler i andre dokumenter
                  og hold dig til standarden.
          @return the new wieght of the package
  */
  #pragma acc routine seq
  double
  guide_elliptical_ReflectionOnEllipticSurface (double pos_V, double pos_W, double* pvel_V, double* pvel_W, double ellipse_V_axis, double ellipse_W_axis,
                                                double ellipse_V_offset, double ellipse_W_offset, double R0, double Qc, double alpha, double Mvalue, double W) {

    // Turns the velocity vector (vel_V0,vel_W0) into a local value
    double vel_V = *pvel_V;
    double vel_W = *pvel_W;

    // Galilean transformation of the particles start position
    // to the ellipse coordinate system
    pos_V = pos_V - ellipse_V_offset;
    pos_W = pos_W - ellipse_W_offset;

    /*
     *   If we reflect the velocity vector in the normal
     *	to the ellipse in the point of intersection
     *   The resulting vector will be -f2, do to conservation of momentum.
     *   this result in the following equation
     *   f2 = -f1 + 2(f1 dot nhat)nhat
     *   which is equal to f2 = f1 - 2(f1 dot n)n/nlength^2
     */

    // The normal vector to the point of intersection
    double normVec_V = -pos_W * ellipse_V_axis / ellipse_W_axis;
    double normVec_W = pos_V * ellipse_W_axis / ellipse_V_axis;

    double normVec_length_squared = normVec_V * normVec_V + normVec_W * normVec_W;

    // Dot product of (vel_V0,vel_W0) and the normal vector
    double Vel_dot_NV = vel_V * normVec_V + vel_W * normVec_W;

    // Calculate f2
    double vel_V_2 = -vel_V + 2 * Vel_dot_NV * normVec_V / normVec_length_squared;
    double vel_W_2 = -vel_W + 2 * Vel_dot_NV * normVec_W / normVec_length_squared;

    // Apply the new velocity vector to the particle globally
    *pvel_V = vel_V_2;
    *pvel_W = vel_W_2;

    // Calculate q and the weighting of the neutron package
    // q=f1-f2
    double delta_vel_V = vel_V - vel_V_2;
    double delta_vel_W = vel_W - vel_W_2;
    double q = V2Q * sqrt (delta_vel_V * delta_vel_V + delta_vel_W * delta_vel_W);

    // Calculate the loss of neutrons due to the reflection
    double mirrorPar[] = { R0, Qc, alpha, Mvalue, W };
    double weight = 1.0;
    StdReflecFunc (q, mirrorPar, &weight);

    return weight;
  }

  /**
          Use the found side of Intersection to call guide_elliptical_ReflectionOnEllipticSurface with
          the parameters of that side.
  */
  #pragma acc routine seq
  double
  guide_elliptical_handleReflection (double x0, double y0, double z0, double* vx_p, double* vy_p, double* vz_p, struct SGI* sgi, struct Intersection* cc) {

    if (!sgi->enableSegments) {
      if (cc->side == RightSide || cc->side == LeftSide)
        return guide_elliptical_ReflectionOnEllipticSurface (x0, z0, vx_p, vz_p, sgi->ellipseMinorAxis[cc->side], sgi->ellipseMajorAxis[cc->side],
                                                             sgi->ellipseMinorOffset[cc->side], sgi->ellipseMajorOffset[cc->side], sgi->R0Arr[cc->side],
                                                             sgi->QcArr[cc->side], sgi->alphaArr[cc->side], sgi->mArr[cc->side], sgi->WArr[cc->side]);
      if (cc->side == TopSide || cc->side == BottomSide)
        return guide_elliptical_ReflectionOnEllipticSurface (y0, z0, vy_p, vz_p, sgi->ellipseMinorAxis[cc->side], sgi->ellipseMajorAxis[cc->side],
                                                             sgi->ellipseMinorOffset[cc->side], sgi->ellipseMajorOffset[cc->side], sgi->R0Arr[cc->side],
                                                             sgi->QcArr[cc->side], sgi->alphaArr[cc->side], sgi->mArr[cc->side], sgi->WArr[cc->side]);
    } else {
      int currentSegment = -1;
      double combinedLength = 0;
      int i;
      for (i = 0; i < sgi->numberOfSegments; i++) {
        combinedLength = combinedLength + sgi->segLength[i];
        if (z0 < combinedLength) {
          currentSegment = i;
          break;
        }
      }
      if (currentSegment < 0) {
        printf ("Elliptic_guide_gravity: Error indexing guide segment\n");
        return 0;
      }

      if (cc->side == RightSide)
        return guide_elliptical_ReflectionOnEllipticSurface (x0, z0, vx_p, vz_p, sgi->ellipseMinorAxis[cc->side], sgi->ellipseMajorAxis[cc->side],
                                                             sgi->ellipseMinorOffset[cc->side], sgi->ellipseMajorOffset[cc->side], sgi->R0Arr[cc->side],
                                                             sgi->QcArr[cc->side], sgi->alphaArr[cc->side], sgi->mValuesright[currentSegment],
                                                             sgi->WArr[cc->side]);
      if (cc->side == LeftSide)
        return guide_elliptical_ReflectionOnEllipticSurface (x0, z0, vx_p, vz_p, sgi->ellipseMinorAxis[cc->side], sgi->ellipseMajorAxis[cc->side],
                                                             sgi->ellipseMinorOffset[cc->side], sgi->ellipseMajorOffset[cc->side], sgi->R0Arr[cc->side],
                                                             sgi->QcArr[cc->side], sgi->alphaArr[cc->side], sgi->mValuesleft[currentSegment],
                                                             sgi->WArr[cc->side]);
      if (cc->side == TopSide)
        return guide_elliptical_ReflectionOnEllipticSurface (y0, z0, vy_p, vz_p, sgi->ellipseMinorAxis[cc->side], sgi->ellipseMajorAxis[cc->side],
                                                             sgi->ellipseMinorOffset[cc->side], sgi->ellipseMajorOffset[cc->side], sgi->R0Arr[cc->side],
                                                             sgi->QcArr[cc->side], sgi->alphaArr[cc->side], sgi->mValuestop[currentSegment], sgi->WArr[cc->side]);
      if (cc->side == BottomSide)
        return guide_elliptical_ReflectionOnEllipticSurface (y0, z0, vy_p, vz_p, sgi->ellipseMinorAxis[cc->side], sgi->ellipseMajorAxis[cc->side],
                                                             sgi->ellipseMinorOffset[cc->side], sgi->ellipseMajorOffset[cc->side], sgi->R0Arr[cc->side],
                                                             sgi->QcArr[cc->side], sgi->alphaArr[cc->side], sgi->mValuesbottom[currentSegment],
                                                             sgi->WArr[cc->side]);
    }
    return 0;
  }

  ///////////////////////////////////////////////////////////////////////////
  /////////////// End of functions
  ///////////////////////////////////////////////////////////////////////////

/* Shared user declarations for all components types 'Bender'. */


/* Shared user declarations for all components types 'Slit'. */
  void
  slit_print_if (int condition, char* level, char* message, char* component) {
    if (condition)
      fprintf (stderr, "Slit: %s: %s: %s\n", component, level, message);
  }
  void
  slit_error_if (int condition, char* message, char* component) {
    slit_print_if (condition, "Error", message, component);
    if (condition)
      exit (-1);
  }
  void
  slit_warning_if (int condition, char* message, char* component) {
    slit_print_if (condition, "Warning", message, component);
  }

/* Shared user declarations for all components types 'Monochromator_curved'. */
  #pragma acc routine
  double
  GAUSS_monocurved (double x, double mean, double rms) {
    return (exp (-((x) - (mean)) * ((x) - (mean)) / (2 * (rms) * (rms))) / (sqrt (2 * PI) * (rms)));
  }



/* Shared user declarations for all components types 'Incoherent'. */

/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2008, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/interoff.h
*
* %Identification
* Written by: Reynald Arnerin
* Date:    Jun 12, 2008
* Release:
* Version:
*
* Object File Format intersection header for McStas. Requires the qsort function.
*
* Such files may be obtained with e.g.
*   qhull < points.xyz Qx Qv Tv o > points.off
* where points.xyz has format:
*   3
*   <nb_points>
*   <x> <y> <z>
*   ...
* The resulting file should have its first line being changed from '3' into 'OFF'.
* It can then be displayed with geomview.
* A similar, but somewhat older solution is to use 'powercrust' with e.g.
*   powercrust -i points.xyz
* which will generate a 'pc.off' file to be renamed as suited.
*
*******************************************************************************/

#ifndef INTEROFF_LIB_H
#define INTEROFF_LIB_H "$Revision$"

#ifndef OFF_EPSILON
#define OFF_EPSILON 1e-13
#endif

#ifndef OFF_INTERSECT_MAX
#ifdef OPENACC
#define OFF_INTERSECT_MAX 100
#else
#define OFF_INTERSECT_MAX 1024
#endif
#endif

//#include <float.h>

#define N_VERTEX_DISPLAYED    200000

typedef struct intersection {
	MCNUM time;  	  //time of the intersection
	Coords v;	      //intersection point
	Coords normal;  //normal vector of the surface intersected
	short in_out;	  //1 if the ray enters the volume, -1 otherwise
	short edge;	    //1 if the intersection is on the boundary of the polygon, and error is possible
	unsigned long index; // index of the face
} intersection;

typedef struct polygon {
  MCNUM* p;       //vertices of the polygon in adjacent order, this way : x1 | y1 | z1 | x2 | y2 | z2 ...
  int npol;       //number of vertices
  #pragma acc shape(p[0:npol]) init_needed(npol)
  Coords normal;
  double D;
} polygon;

typedef struct off_struct {
    long vtxSize;
    long polySize;
    long faceSize;
    Coords* vtxArray;
    #pragma acc shape(vtxArray[0:vtxSize]) init_needed(vtxSize)
    Coords* normalArray;
    #pragma acc shape(vtxArray[0:faceSize]) init_needed(faceSize)
    unsigned long* faceArray;
    #pragma acc shape(vtxArray[0:faceSize][0:polySize]) init_needed(faceSize,polySize)
    double* DArray;
    #pragma acc shape(vtxArray[0:polySize]) init_needed(polySize)
    char *filename;
    int mantidflag;
    long mantidoffset;
    intersection intersects[OFF_INTERSECT_MAX]; // After a call to off_intersect_all contains the list of intersections.
    int nextintersect;                 // 'Next' intersection (first t>0) solution after call to off_intersect_all
    int numintersect;               // Number of intersections after call to off_intersect_all
} off_struct;

/*******************************************************************************
* long off_init(  char *offfile, double xwidth, double yheight, double zdepth, off_struct* data)
* ACTION: read an OFF file, optionally center object and rescale, initialize OFF data structure
* INPUT: 'offfile' OFF file to read
*        'xwidth,yheight,zdepth' if given as non-zero, apply bounding box.
*           Specifying only one of these will also use the same ratio on all axes
*        'notcenter' center the object to the (0,0,0) position in local frame when set to zero
* RETURN: number of polyhedra and 'data' OFF structure
*******************************************************************************/
long off_init(  char *offfile, double xwidth, double yheight, double zdepth,
                int notcenter, off_struct* data);

/*******************************************************************************
* int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         ax, ay, az are the local acceleration vector
*         data points to the OFF data structure
* RETURN: the number of polyhedral which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*         data is the full OFF structure, including a list intersection type
*******************************************************************************/
#pragma acc routine
int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data );

/*******************************************************************************
* int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         ax, ay, az are the local acceleration vector
*         data points to the OFF data structure
* RETURN: the number of polyhedral which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
#pragma acc routine
int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct data );

/*****************************************************************************
* int off_intersectx(double* l0, double* l3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double kx, double ky, double kz,
     off_struct data )
* ACTION: computes intersection of an xray trajectory with an object.
* INPUT:  x,y,z and kx,ky,kz, are spatial coordinates and wavevector of the x-ray
*         respectively. data points to the OFF data structure.
* RETURN: the number of polyhedral the trajectory intersects
*         l0 and l3 are the smallest incoming and outgoing intersection lengths
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
#pragma acc routine
int off_x_intersect(double *l0,double *l3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double kx, double ky, double kz,
     off_struct data );

/*******************************************************************************
* void off_display(off_struct data)
* ACTION: display up to N_VERTEX_DISPLAYED points from the object
*******************************************************************************/
void off_display(off_struct);

/*******************************************************************************
void p_to_quadratic(double eq[], Coords acc,
                    Coords pos, Coords vel,
                    double* teq)
* ACTION: define the quadratic for the intersection of a parabola with a plane
* INPUT: 'eq' plane equation
*        'acc' acceleration vector
*        'vel' velocity of the particle
*        'pos' position of the particle
*         equation of plane A * x + B * y + C * z - D = 0
*         eq[0] = (C*az)/2+(B*ay)/2+(A*ax)/2
*         eq[1] = C*vz+B*vy+A*vx
*         eq[2] = C*z0+B*y0+A*x0-D
* RETURN: equation of parabola: teq(0) * t^2 + teq(1) * t + teq(2)
*******************************************************************************/
void p_to_quadratic(Coords norm, MCNUM d, Coords acc, Coords pos, Coords vel,
		    double* teq);

/*******************************************************************************
int quadraticSolve(double eq[], double* x1, double* x2);
* ACTION: solves the quadratic for the roots x1 and x2 
*         eq[0] * t^2 + eq[1] * t + eq[2] = 0
* INPUT: 'eq' the coefficients of the parabola
* RETURN: roots x1 and x2 and the number of solutions
*******************************************************************************/
int quadraticSolve(double* eq, double* x1, double* x2);

#endif

/* end of interoff-lib.h */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2008, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/interoff-lib.c
*
* %Identification
* Written by: Reynald Arnerin
* Date:    Jun 12, 2008
* Origin: ILL
* Release: $Revision$
* Version: McStas X.Y
*
* Object File Format intersection library for McStas. Requires the qsort function.
*
* Such files may be obtained with e.g.
*   qhull < points.xyz Qx Qv Tv o > points.off
* where points.xyz has format (it supports comments):
*   3
*   <nb_points>
*   <x> <y> <z>
*   ...
* The resulting file should have its first line being changed from '3' into 'OFF'.
* It can then be displayed with geomview.
* A similar, but somewhat older solution is to use 'powercrust' with e.g.
*   powercrust -i points.xyz
* which will generate a 'pc.off' file to be renamed as suited.
*
*******************************************************************************/

#ifndef INTEROFF_LIB_H
#include "interoff-lib.h"
#endif

#ifndef INTEROFF_LIB_C
#define INTEROFF_LIB_C "$Revision$"

#ifdef OPENACC // If on GPU map fprintf to printf
#define fprintf(stderr,...) printf(__VA_ARGS__)
#endif

#pragma acc routine
double off_F(double x, double y,double z,double A,double B,double C,double D) {
  return ( A*x + B*y + C*z + D );
}

#pragma acc routine
char off_sign(double a) {
  if (a<0)       return(-1);
  else if (a==0) return(0);
  else           return(1);
}

// off_normal ******************************************************************
//gives the normal vector of p
#pragma acc routine
void off_normal(Coords* n, polygon p)
{
  //using Newell method
  int i=0,j=0;
  n->x=0;n->y=0;n->z=0;
  for (i = 0, j = p.npol-1; i < p.npol; j = i++)
  {
    MCNUM x1=p.p[3*i],
          y1=p.p[3*i+1],
          z1=p.p[3*i+2];
    MCNUM x2=p.p[3*j],
          y2=p.p[3*j+1],
          z2=p.p[3*j+2];
    // n is the cross product of v1*v2
    n->x += (y1 - y2) * (z1 + z2);
    n->y += (z1 - z2) * (x1 + x2);
    n->z += (x1 - x2) * (y1 + y2);
  }
} /* off_normal */

// off_pnpoly ******************************************************************
//based on http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html
//return 0 if the vertex is out
//    1 if it is in
//   -1 if on the boundary
#pragma acc routine
int off_pnpoly(polygon p, Coords v)
{
  int i=0, c = 0;
  MCNUM minx=FLT_MAX,maxx=-FLT_MAX,miny=FLT_MAX,maxy=-FLT_MAX,minz=FLT_MAX,maxz=-FLT_MAX;
  MCNUM areax=0,areay=0,areaz=0;

  int pol2dx=0,pol2dy=1;          //2d restriction of the poly
  MCNUM x=v.x,y=v.y;

  /*areax: projected area with x-scratched = |v1_yz x v2_yz|, where v1=(x1-x0,0,z1-z0) & v2=(x2-x0,0,z2-z0).*/
  /* In principle, if polygon is triangle area should be scaled by 1/2, but this is irrelevant for finding the maximum area.*/
  /* Similarly for y and z scratched.*/
  areax=coords_len(coords_xp(
        coords_set(0,p.p[3*1+1]-p.p[0+1],p.p[3*1+2]-p.p[0+2]),
        coords_set(0,p.p[3*2+1]-p.p[0+1],p.p[3*2+2]-p.p[0+2])));
  areay=coords_len(coords_xp(
        coords_set(p.p[3*1+0]-p.p[0+0],0,p.p[3*1+2]-p.p[0+2]),
        coords_set(p.p[3*2+0]-p.p[0+0],0,p.p[3*2+2]-p.p[0+2])));
  areaz=coords_len(coords_xp(
        coords_set(p.p[3*1+0]-p.p[0+0],p.p[3*1+1]-p.p[0+1],0),
        coords_set(p.p[3*2+0]-p.p[0+0],p.p[3*2+1]-p.p[0+1],0)));

  if(areaz<areax){
    if(areax<areay){
      /*pick areay - i.e. scratch y*/
      pol2dy=2;
      y=v.z;
    }else{
      /*scratch x*/
      pol2dx=2;
      x=v.z;
    }
  }else if (areaz<areay){
    pol2dy=2;
    y=v.z;
  }

  //trace rays and test number of intersection
  int j;
  for (i = 0, j = p.npol-1; i < p.npol; j = i++) {
    if (((((p.p[3*i+pol2dy])<=y) && (y<(p.p[3*j+pol2dy]))) ||
         (((p.p[3*j+pol2dy])<=y) && (y<(p.p[3*i+pol2dy])))) &&
        (x < ( (p.p[3*j+pol2dx] - p.p[3*i+pol2dx]) * (y - p.p[3*i+pol2dy])
             / (p.p[3*j+pol2dy] - p.p[3*i+pol2dy]) + p.p[3*i+pol2dx]) ))
      c = !c;

    if (((fabs(p.p[3*i+pol2dy]-y)<=OFF_EPSILON) || ((fabs(p.p[3*j+pol2dy]-y)<=OFF_EPSILON))) &&
        fabs(x -((p.p[3*j+pol2dx] - p.p[3*i+pol2dx]) * (y - p.p[3*i+pol2dy])
          / (p.p[3*j+pol2dy] - p.p[3*i+pol2dy]) + p.p[3*i+pol2dx])) < OFF_EPSILON)
    {
      //the point lies on the edge
      c=-1;
      break;
    }
  }

  return c;
} /* off_pnpoly */

// off_intersectPoly ***********************************************************
//gives the intersection vertex between ray [a,b) and polygon p and its parametric value on (a b)
//based on http://geometryalgorithms.com/Archive/algorithm_0105/algorithm_0105.htm
#pragma acc routine
int off_intersectPoly(intersection *inter, Coords a, Coords b, polygon p)
{
  //direction vector of [a,b]
  Coords dir = {b.x-a.x, b.y-a.y, b.z-a.z};

  //the normal vector to the polygon
  Coords normale=p.normal;
  //off_normal(&normale, p); done at the init stage

  //direction vector from a to a vertex of the polygon
  Coords w0 = {a.x-p.p[0], a.y-p.p[1], a.z-p.p[2]};

  //scalar product
  MCNUM nw0  =-scalar_prod(normale.x,normale.y,normale.z,w0.x,w0.y,w0.z);
  MCNUM ndir = scalar_prod(normale.x,normale.y,normale.z,dir.x,dir.y,dir.z);
  inter->time = inter->edge = inter->in_out=0;
  inter->v = inter->normal = coords_set(0,0,1);

  if (fabs(ndir) < OFF_EPSILON)    // ray is parallel to polygon plane
  {
    if (nw0 == 0)              // ray lies in polygon plane (infinite number of solution)
      return 0;
    else return 0;             // ray disjoint from plane (no solution)
  }

  // get intersect point of ray with polygon plane
  inter->time = nw0 / ndir;            //parametric value the point on line (a,b)

  inter->v = coords_set(a.x + inter->time * dir.x,// intersect point of ray and plane
    a.y + inter->time * dir.y,
    a.z + inter->time * dir.z);

  int res=off_pnpoly(p,inter->v);

  inter->edge=(res==-1);
  if (ndir<0)
    inter->in_out=1;  //the negative dot product means we enter the surface
  else
    inter->in_out=-1;

  inter->normal=p.normal;

  return res;         //true if the intersection point lies inside the poly
} /* off_intersectPoly */


// off_getBlocksIndex **********************************************************
/*reads the indexes at the beginning of the off file as this :
line 1  OFF
line 2  nbVertex nbFaces nbEdges
*/
FILE *off_getBlocksIndex(char* filename, long* vtxSize, long* polySize )
{
  FILE* f = Open_File(filename,"r", NULL); /* from read_table-lib: FILE *Open_File(char *name, char *Mode, char *path) */
  if (!f) return (f);

  char line[CHAR_BUF_LENGTH];
  char *ret=0;
  *vtxSize = *polySize = 0;

  /* **************** start to read the file header */
  /* OFF file:
     'OFF' or '3'
   */

  ret=fgets(line,CHAR_BUF_LENGTH , f);// line 1 = "OFF"
  if (ret == NULL)
  {
    fprintf(stderr, "Error: Can not read 1st line in file %s (interoff/off_getBlocksIndex)\n", filename);
    exit(1);
  }
  if (strlen(line)>5)
  {
      fprintf(stderr,"Error: First line in %s is too long (=%lu). Possibly the line is not terminated by '\\n'.\n"
              "       The first line is required to be exactly 'OFF', '3' or 'ply'.\n",
              filename,(long unsigned)strlen(line));
      fclose(f);
      return(NULL);
  }

  if (strncmp(line,"OFF",3) && strncmp(line,"3",1) && strncmp(line,"ply",1))
  {
    fprintf(stderr, "Error: %s is probably not an OFF, NOFF or PLY file (interoff/off_getBlocksIndex).\n"
                    "       Requires first line to be 'OFF', '3' or 'ply'.\n",filename);
    fclose(f);
    return(NULL);
  }

  if (!strncmp(line,"OFF",3) || !strncmp(line,"3",1)) {
    do  /* OFF file: skip # comments which may be there */
    {
      ret=fgets(line,CHAR_BUF_LENGTH , f);
      if (ret == NULL)
      {
        fprintf(stderr, "Error: Can not read line in file %s (interoff/off_getBlocksIndex)\n", filename);
        exit(1);
      }
    } while (line[0]=='#');
    //line = nblines of vertex,faces and edges arrays
    sscanf(line,"%lu %lu",vtxSize,polySize);
  } else {
    do  /* PLY file: read all lines until find 'end_header'
           and locate 'element faces' and 'element vertex' */
    {
      ret=fgets(line,CHAR_BUF_LENGTH , f);
      if (ret == NULL)
      {
        fprintf(stderr, "Error: Can not read line in file %s (interoff/off_getBlocksIndex)\n", filename);
        exit(1);
      }
      if (!strncmp(line,"element face",12))
        sscanf(line,"element face %lu",polySize);
      else if (!strncmp(line,"element vertex",14))
        sscanf(line,"element vertex %lu",vtxSize);
      else if (!strncmp(line,"format binary",13))
        exit(fprintf(stderr,
          "Error: Can not read binary PLY file %s, only 'format ascii' (interoff/off_getBlocksIndex)\n%s\n",
          filename, line));
    } while (strncmp(line,"end_header",10));
  }

  /* The FILE is left opened ready to read 'vtxSize' vertices (vtxSize *3 numbers)
     and then polySize polygons (rows) */

  return(f);
} /* off_getBlocksIndex */

// off_init_planes *************************************************************
//gives the equations of 2 perpandicular planes of [ab]
#pragma acc routine
void off_init_planes(Coords a, Coords b,
  MCNUM* A1, MCNUM* C1, MCNUM* D1, MCNUM *A2, MCNUM* B2, MCNUM* C2, MCNUM* D2)
{
  //direction vector of [a b]
  Coords dir={b.x-a.x, b.y-a.y, b.z-a.z};

  //the plane parallel to the 'y' is computed with the normal vector of the projection of [ab] on plane 'xz'
  *A1= dir.z;
  *C1=-dir.x;
  if(*A1!=0 || *C1!=0)
    *D1=-(a.x)*(*A1)-(a.z)*(*C1);
  else
  {
    //the plane does not support the vector, take the one parallel to 'z''
    *A1=1;
    //B1=dir.x=0
    *D1=-(a.x);
  }
  //the plane parallel to the 'x' is computed with the normal vector of the projection of [ab] on plane 'yz'
  *B2= dir.z;
  *C2=-dir.y;
  *A2= 0;
  if (*B2==0 && *C2==0)
  {
    //the plane does not support the vector, take the one parallel to 'z'
    *B2=1;
    //B1=dir.x=0
    *D2=-(a.y);
  }
  else {
    if (dir.z==0)
    {
      //the planes are the same, take the one parallel to 'z'
      *A2= dir.y;
      *B2=-dir.x;
      *D2=-(a.x)*(*A2)-(a.y)*(*B2);
    }
    else
      *D2=-(a.y)**B2-(a.z)**C2;
  }
} /* off_init_planes */

// off_clip_3D_mod *************************************************************
#pragma acc routine
int off_clip_3D_mod(intersection* t, Coords a, Coords b,
  Coords* vtxArray, unsigned long vtxSize, unsigned long* faceArray,
  unsigned long faceSize, Coords* normalArray)
{
  MCNUM A1=0, C1=0, D1=0, A2=0, B2=0, C2=0, D2=0;      //perpendicular plane equations to [a,b]
  off_init_planes(a, b, &A1, &C1, &D1, &A2, &B2, &C2, &D2);

  int t_size=0;
  MCNUM popol[3*4]; /*3 dimensions and max 4 vertices to form a polygon*/
  unsigned long i=0,indPoly=0;

  //exploring the polygons :
  i=indPoly=0;
  while (i<faceSize)
  {
    polygon pol;
    pol.npol  = faceArray[i];                //nb vertex of polygon
    pol.p     = popol;
    pol.normal= coords_set(0,0,1);
    pol.D     = 1;
    unsigned long indVertP1=faceArray[++i];  //polygon's first vertex index in vtxTable
    int j=1;
    /*check whether vertex is left or right of plane*/
    char sg0=off_sign(off_F(vtxArray[indVertP1].x,vtxArray[indVertP1].y,vtxArray[indVertP1].z,A1,0,C1,D1));
    while (j<pol.npol)
    {
      //polygon's j-th vertex index in vtxTable
      unsigned long indVertP2=faceArray[i+j];
      /*check whether vertex is left or right of plane*/
      char sg1=off_sign(off_F(vtxArray[indVertP2].x,vtxArray[indVertP2].y,vtxArray[indVertP2].z,A1,0,C1,D1));
      if (sg0!=sg1) //if the plane intersect the polygon
        break;

      ++j;
    }

    if (j<pol.npol)          //ok, let's test with the second plane
    {
      char sg1=off_sign(off_F(vtxArray[indVertP1].x,vtxArray[indVertP1].y,vtxArray[indVertP1].z,A2,B2,C2,D2));//tells if vertex is left or right of the plane

      j=1;
      while (j<pol.npol)
      {
        //unsigned long indVertPi=faceArray[i+j];  //polyg's j-th vertex index in vtxTable
        Coords vertPi=vtxArray[faceArray[i+j]];
        if (sg1!=off_sign(off_F(vertPi.x,vertPi.y,vertPi.z,A2,B2,C2,D2)))//if the plane intersect the polygon
          break;
        ++j;
      }
      if (j<pol.npol)
      {
#ifdef OFF_LEGACY
        if (t_size>OFF_INTERSECT_MAX)
        {
          fprintf(stderr, "Warning: number of intersection exceeded (%d) (interoff-lib/off_clip_3D_mod)\n", OFF_INTERSECT_MAX);
            return (t_size);
        }
#endif
        //both planes intersect the polygon, let's find the intersection point
        //our polygon :
        int k;
        for (k=0; k<pol.npol; ++k)
        {
          Coords vertPk=vtxArray[faceArray[i+k]];
          pol.p[3*k]  =vertPk.x;
          pol.p[3*k+1]=vertPk.y;
          pol.p[3*k+2]=vertPk.z;
        }
        pol.normal=normalArray[indPoly];
        intersection x;
        if (off_intersectPoly(&x, a, b, pol))
        {
          x.index = indPoly;
#ifdef OFF_LEGACY
          t[t_size++]=x;
#else
	  /* Check against our 4 existing times, starting from [-FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX] */
	  /* Case 1, negative time? */
	  if (t_size < 4) t_size++;	  
	  if (x.time < 0) {
	    if (x.time > t[0].time) {
	      t[0]=x;
	    }
	  } else {
	    /* Case 2, positive time */
	    intersection xtmp;
	    if (x.time < t[3].time) {
	      t[3]=x;
	      if (t[3].time < t[2].time) {
		xtmp = t[2];
		t[2] = t[3];
		t[3] = xtmp;
	      }
	      if (t[2].time < t[1].time) {
		xtmp = t[1];
		t[1] = t[2];
		t[2] = xtmp;
	      }
	    } 
	  }
#endif
	}
      } /* if (j<pol.npol) */
    } /* if (j<pol.npol) */
    i += pol.npol;
    indPoly++;
  } /* while i<faceSize */
  return t_size;
} /* off_clip_3D_mod */

// off_clip_3D_mod_grav *************************************************************
/*******************************************************************************
version of off_clip_3D_mod_grav
*******************************************************************************/
#pragma acc routine seq
int off_clip_3D_mod_grav(intersection* t, Coords pos, Coords vel, Coords acc,
  Coords* vtxArray, unsigned long vtxSize, unsigned long* faceArray,
  unsigned long faceSize, Coords* normalArray, double* DArray)
{
  int t_size=0;
  MCNUM popol[3*CHAR_BUF_LENGTH];
  double plane_Eq [4];
  double quadratic [3];
  unsigned long i=0,indPoly=0;
  //exploring the polygons :
  i=indPoly=0;
  while (i<faceSize)
  {
    polygon pol;
    pol.npol  = faceArray[i];                //nb vertex of polygon
    pol.p     = popol;
    pol.normal= coords_set(0,0,1);
    unsigned long indVertP1=faceArray[++i];  //polygon's first vertex index in vtxTable
    
    if (t_size>CHAR_BUF_LENGTH)
      {
	fprintf(stderr, "Warning: number of intersection exceeded (%d) (interoff-lib/off_clip_3D_mod)\n", CHAR_BUF_LENGTH);
	return (t_size);
      }
    //both planes intersect the polygon, let's find the intersection point
    //our polygon :
    int k;
    for (k=0; k<pol.npol; ++k)
      {
	Coords vertPk=vtxArray[faceArray[i+k]];
	pol.p[3*k]  =vertPk.x;
	pol.p[3*k+1]=vertPk.y;
	pol.p[3*k+2]=vertPk.z;
      }
    pol.normal=normalArray[indPoly];
    pol.D=DArray[indPoly];
    p_to_quadratic(pol.normal, pol.D, acc, pos, vel, quadratic);
    double x1, x2;
    int nsol = quadraticSolve(quadratic, &x1, &x2);

    if (nsol >= 1) {
      double time = 1.0e36;
      if (x1 < time && x1 > 0.0) {
	time = x1;
      }
      if (nsol == 2 && x2 < time && x2 > 0.0) {
	time = x2;
      }
      if (time != 1.0e36) {
	intersection inters;
	double t2 = time * time * 0.5;
	double tx = pos.x + time * vel.x;
	if (acc.x != 0.0) {
	  tx = tx + t2 * acc.x;
	}
	double ty = pos.y + time * vel.y;
	if (acc.y != 0.0) {
	  ty = ty + t2 * acc.y;
	}
	double tz = pos.z + time * vel.z;
	if (acc.z != 0.0) {
	  tz = tz + t2 * acc.z;
	}
	inters.v = coords_set(tx, ty, tz);
	Coords tvel = coords_set(vel.x + time * acc.x,
				 vel.y + time * acc.y,
				 vel.z + time * acc.z);
	inters.time = time;
	inters.normal = pol.normal;
	inters.index = indPoly;
	int res=off_pnpoly(pol,inters.v);
	if (res != 0) {
	  inters.edge=(res==-1);
	  MCNUM ndir = scalar_prod(pol.normal.x,pol.normal.y,pol.normal.z,tvel.x,tvel.y,tvel.z);
	  if (ndir<0) {
	    inters.in_out=1;  //the negative dot product means we enter the surface
	  } else {
	    inters.in_out=-1;
	  }
#ifdef OFF_LEGACY
          t[t_size++]=inters;
#else
    /* Check against our 4 existing times, starting from [-FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX] */
    /* Case 1, negative time? */
    if (t_size < 4) t_size++;
    if (inters.time < 0) {
      if (inters.time > t[0].time) {
        t[0]=inters;
      }
    } else {
      /* Case 2, positive time */
      intersection xtmp;
      if (inters.time < t[3].time) {
      t[3]=inters;
        if (t[3].time < t[2].time) {
    xtmp = t[2];
    t[2] = t[3];
    t[3] = xtmp;
        }
        if (t[2].time < t[1].time) {
    xtmp = t[1];
    t[1] = t[2];
    t[2] = xtmp;
        }
      }
    }
#endif
	}
      }
    }
    i += pol.npol;
    indPoly++;
  } /* while i<faceSize */
  return t_size;
} /* off_clip_3D_mod_grav */

// off_compare *****************************************************************
#pragma acc routine
int off_compare (void const *a, void const *b)
{
   intersection const *pa = a;
   intersection const *pb = b;

   return off_sign(pa->time - pb->time);
} /* off_compare */

// off_cleanDouble *************************************************************
//given an array of intersections throw those which appear several times
//returns 1 if there is a possibility of error
#pragma acc routine
int off_cleanDouble(intersection* t, int* t_size)
{
  int i=1;
  intersection prev=t[0];
  while (i<*t_size)
  {
    int j=i;
    //for each intersection with the same time
    while (j<*t_size && fabs(prev.time-t[j].time)<OFF_EPSILON)
    {
      //if the intersection is the exact same erase it
      if (prev.in_out==t[j].in_out)
      {
        int k;
        for (k=j+1; k<*t_size; ++k)
        {
          t[k-1]=t[k];
        }
        *t_size-=1;
      }
      else
        ++j;
    }
    prev=t[i];
    ++i;

  }
  return 1;
} /* off_cleanDouble */

// off_cleanInOut **************************************************************
//given an array of intesections throw those which enter and exit in the same time
//Meaning the ray passes very close to the volume
//returns 1 if there is a possibility of error
#pragma acc routine
int off_cleanInOut(intersection* t, int* t_size)
{
  int i=1;
  intersection prev=t[0];
  while (i<*t_size)
  {
    //if two intersection have the same time but one enters and the other exits erase both
    //(such intersections must be adjacent in the array : run off_cleanDouble before)
    if (fabs(prev.time-t[i].time)<OFF_EPSILON && prev.in_out!=t[i].in_out)
    {
      int j=0;
      for (j=i+1; j<*t_size; ++j)
      {
        t[j-2]=t[j];
      }
      *t_size-=2;
      prev=t[i-1];
    }
    else
    {
      prev=t[i];
      ++i;
    }
  }
  return (*t_size);
} /* off_cleanInOut */

/* PUBLIC functions ******************************************************** */

/*******************************************************************************
* long off_init(  char *offfile, double xwidth, double yheight, double zdepth, off_struct* data)
* ACTION: read an OFF file, optionally center object and rescale, initialize OFF data structure
* INPUT: 'offfile' OFF file to read
*        'xwidth,yheight,zdepth' if given as non-zero, apply bounding box.
*           Specifying only one of these will also use the same ratio on all axes
*        'notcenter' center the object to the (0,0,0) position in local frame when set to zero
* RETURN: number of polyhedra and 'data' OFF structure
*******************************************************************************/
long off_init(  char *offfile, double xwidth, double yheight, double zdepth,
                int notcenter, off_struct* data)
{
  // data to be initialized
  long    vtxSize =0, polySize=0, i=0, ret=0, faceSize=0;
  Coords* vtxArray        =NULL;
  Coords* normalArray     =NULL;
  double* DArray          =NULL;
  unsigned long* faceArray=NULL;
  FILE*   f               =NULL; /* the FILE with vertices and polygons */
  double minx=FLT_MAX,maxx=-FLT_MAX,miny=FLT_MAX,maxy=-FLT_MAX,minz=FLT_MAX,maxz=-FLT_MAX;

  // get the indexes
  if (!data) return(0);

  MPI_MASTER(
  printf("Loading geometry file (OFF/PLY): %s\n", offfile);
  );

  f=off_getBlocksIndex(offfile,&vtxSize,&polySize);
  if (!f) return(0);

  // read vertex table = [x y z | x y z | ...] =================================
  // now we read the vertices as 'vtxSize*3' numbers and store it in vtxArray
  MPI_MASTER(
  printf("  Number of vertices: %ld\n", vtxSize);
  );
  vtxArray   = malloc(vtxSize*sizeof(Coords));
  if (!vtxArray) return(0);
  i=0;
  while (i<vtxSize && ~feof(f))
  {
    double x,y,z;
    ret=fscanf(f, "%lg%lg%lg", &x,&y,&z);
    if (!ret) {
      // invalid line: we skip it (probably a comment)
      char line[CHAR_BUF_LENGTH];
      char *s=fgets(line, CHAR_BUF_LENGTH, f);
      continue;
    }
    if (ret != 3) {
      fprintf(stderr, "Error: can not read [xyz] coordinates for vertex %li in file %s (interoff/off_init). Read %li values.\n",
        i, offfile, ret);
      exit(2);
    }
    vtxArray[i].x=x;
    vtxArray[i].y=y;
    vtxArray[i].z=z;

    //bounding box
    if (vtxArray[i].x<minx) minx=vtxArray[i].x;
    if (vtxArray[i].x>maxx) maxx=vtxArray[i].x;
    if (vtxArray[i].y<miny) miny=vtxArray[i].y;
    if (vtxArray[i].y>maxy) maxy=vtxArray[i].y;
    if (vtxArray[i].z<minz) minz=vtxArray[i].z;
    if (vtxArray[i].z>maxz) maxz=vtxArray[i].z;
    i++; // inquire next vertex
  }

  // resizing and repositioning params
  double centerx=0, centery=0, centerz=0;
  if (!notcenter) {
    centerx=(minx+maxx)*0.5;
    centery=(miny+maxy)*0.5;
    centerz=(minz+maxz)*0.5;
  }

  double rangex=-minx+maxx,
         rangey=-miny+maxy,
         rangez=-minz+maxz;

  double ratiox=1,ratioy=1,ratioz=1;

  if (xwidth && rangex)
  {
    ratiox=xwidth/rangex;
    ratioy=ratiox;
    ratioz=ratiox;
  }

  if (yheight && rangey)
  {
    ratioy=yheight/rangey;
    if(!xwidth)  ratiox=ratioy;
    ratioz=ratioy;
  }

  if (zdepth && rangez)
  {
    ratioz=zdepth/rangez;
    if(!xwidth)  ratiox=ratioz;
    if(!yheight) ratioy=ratioz;
  }

  rangex *= ratiox;
  rangey *= ratioy;
  rangez *= ratioz;

  //center and resize the object
  for (i=0; i<vtxSize; ++i)
  {
    vtxArray[i].x=(vtxArray[i].x-centerx)*ratiox+(!notcenter ? 0 : centerx);
    vtxArray[i].y=(vtxArray[i].y-centery)*ratioy+(!notcenter ? 0 : centery);
    vtxArray[i].z=(vtxArray[i].z-centerz)*ratioz+(!notcenter ? 0 : centerz);
  }

  // read face table = [nbvertex v1 v2 vn | nbvertex v1 v2 vn ...] =============
  MPI_MASTER(
  printf("  Number of polygons: %ld\n", polySize);
  );
  normalArray= malloc(polySize*sizeof(Coords));
  faceArray  = malloc(polySize*10*sizeof(unsigned long)); // we assume polygons have less than 9 vertices
  DArray     = malloc(polySize*sizeof(double));
  if (!normalArray || !faceArray || !DArray) return(0);

  // fill faces
  faceSize=0;
  i=0;
  while (i<polySize && ~feof(f)) {
    int  nbVertex=0, j=0;
    // read the length of this polygon
    ret=fscanf(f, "%d", &nbVertex);
    if (!ret) {
      // invalid line: we skip it (probably a comment)
      char line[CHAR_BUF_LENGTH];
      char *s=fgets(line, CHAR_BUF_LENGTH, f);
      continue;
    }
    if (ret != 1) {
      fprintf(stderr, "Error: can not read polygon %li length in file %s (interoff/off_init)\n",
        i, offfile);
      exit(3);
    }
    if (faceSize > polySize*10) {
      fprintf(stderr, "Error: %li exceeded allocated polygon array[%li] in file %s (interoff/off_init)\n",
        faceSize, polySize*10, offfile);
    }
    faceArray[faceSize++] = nbVertex; // length of the polygon/face
    // then read the vertex ID's
    for (j=0; j<nbVertex; j++) {
      double vtx=0;
      ret=fscanf(f, "%lg", &vtx);
      faceArray[faceSize++] = vtx;   // add vertices index after length of polygon
    }
    i++;
  }

  // precomputes normals
  long indNormal=0;//index in polyArray
  i=0;    //index in faceArray
  while (i<faceSize)
  {
    int    nbVertex=faceArray[i];//nb of vertices of this polygon
    double *vertices=malloc(3*nbVertex*sizeof(double));
    if (!vertices) {
      fprintf(stderr,"Error allocating vertex array sized %i\n",nbVertex);
      exit(-1);
    }
    int j;

    for (j=0; j<nbVertex; ++j)
    {
      unsigned long indVertPj=faceArray[i+j+1];
      vertices[3*j]  =vtxArray[indVertPj].x;
      vertices[3*j+1]=vtxArray[indVertPj].y;
      vertices[3*j+2]=vtxArray[indVertPj].z;
    }

    polygon p;
    p.p   =vertices;
    p.npol=nbVertex;
    p.D=1;
    off_normal(&(p.normal),p);

    normalArray[indNormal]=p.normal;
    p.D = scalar_prod(p.normal.x,p.normal.y,p.normal.z,
		      vertices[0],vertices[1],vertices[2]);
    DArray[indNormal]=p.D;

    i += nbVertex+1;
    indNormal++;
    free(vertices);
  }

  MPI_MASTER(
  if (ratiox!=ratioy || ratiox!=ratioz || ratioy!=ratioz)
    printf("Warning: Aspect ratio of the geometry %s was modified.\n"
           "         If you want to keep the original proportions, specifiy only one of the dimensions.\n",
           offfile);
  if ( xwidth==0 && yheight==0 && zdepth==0 ) {
    printf("Warning: Neither xwidth, yheight or zdepth are defined.\n"
	   "           The file-defined (non-scaled) geometry the OFF geometry %s will be applied!\n",
           offfile);
  }
  printf("  Bounding box dimensions for geometry %s:\n", offfile);
  printf("    Length=%f (%.3f%%)\n", rangex, ratiox*100);
  printf("    Width= %f (%.3f%%)\n", rangey, ratioy*100);
  printf("    Depth= %f (%.3f%%)\n", rangez, ratioz*100);
  );

  data->vtxArray   = vtxArray;
  data->normalArray= normalArray;
  data->DArray     = DArray;
  data->faceArray  = faceArray;
  data->vtxSize    = vtxSize;
  data->polySize   = polySize;
  data->faceSize   = faceSize;
  data->filename   = offfile;
  #ifdef OPENACC
  acc_attach((void *)&vtxArray);
  acc_attach((void *)&normalArray);
  acc_attach((void *)&faceArray);
  #endif

  return(polySize);
} /* off_init */

#pragma acc routine
int Min_int(int x, int y) {
  return (x<y)? x :y;
}

 
#pragma acc routine
void merge(intersection *arr, int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 =  r - m;

/* create temp arrays */
intersection *L, *R;
 L = (intersection *)malloc(sizeof(intersection) * n1);
 R = (intersection *)malloc(sizeof(intersection) * n2);
 if (!L||!R) {
   fprintf(stderr,"Error allocating intersection arrays\n");
   exit(-1);
 }
/* Copy data to temp arrays L[] and R[] */
 #pragma acc loop independent
for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
 #pragma acc loop independent
for (j = 0; j < n2; j++)
    R[j] = arr[m + 1+ j];

/* Merge the temp arrays back into arr[l..r]*/
i = 0;
j = 0;
k = l;

while (i < n1 && j < n2)
{
    if (L[i].time <= R[j].time)
    {
        arr[k] = L[i];
        i++;
    }
    else
    {
        arr[k] = R[j];
        j++;
    }
    k++;
}

/* Copy the remaining elements of L[], if there are any */

while (i < n1)
{
    arr[k] = L[i];
    i++;
    k++;
}

/* Copy the remaining elements of R[], if there are any */
while (j < n2)
{
    arr[k] = R[j];
    j++;
    k++;
}
free(L);
free(R);
}


#ifdef USE_OFF
#pragma acc routine
void gpusort(intersection *arr, int size)
{
  int curr_size;  // For current size of subarrays to be merged
  // curr_size varies from 1 to n/2
  int left_start; // For picking starting index of left subarray
  // to be merged
  // pcopying (R[0:n2])
  {
    for (curr_size=1; curr_size<=size-1; curr_size = 2*curr_size)
      {
	// Pick starting point of different subarrays of current size
	for (left_start=0; left_start<size-1; left_start += 2*curr_size)
	  {
	    // Find ending point of left subarray. mid+1 is starting
	    // point of right
	    int mid = left_start + curr_size - 1;

	    int right_end = Min_int(left_start + 2*curr_size - 1, size-1);

	    // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
	    if (mid < right_end) merge(arr, left_start, mid, right_end);
	  }
      }
  }
}
#endif

/*******************************************************************************
void p_to_quadratic(double eq[], Coords acc,
                    Coords pos, Coords vel,
                    double* teq)
* ACTION: define the quadratic for the intersection of a parabola with a plane
* INPUT: 'eq' plane equation
*        'acc' acceleration vector
*        'vel' velocity of the particle
*        'pos' position of the particle
*         equation of plane A * x + B * y + C * z - D = 0
*         eq[0] = (C*az)/2+(B*ay)/2+(A*ax)/2
*         eq[1] = C*vz+B*vy+A*vx
*         eq[2] = C*z0+B*y0+A*x0-D
* RETURN: equation of parabola: teq(0) * t^2 + teq(1) * t + teq(2)
*******************************************************************************/
void p_to_quadratic(Coords norm, MCNUM d, Coords acc, Coords pos, Coords vel,
		    double* teq)
{
  teq[0] = scalar_prod(norm.x, norm.y, norm.z, acc.x, acc.y, acc.z) * 0.5;
  teq[1] = scalar_prod(norm.x, norm.y, norm.z, vel.x, vel.y, vel.z);
  teq[2] = scalar_prod(norm.x, norm.y, norm.z, pos.x, pos.y, pos.z) - d;
  return;
}

/*******************************************************************************
int quadraticSolve(double eq[], double* x1, double* x2);
* ACTION: solves the quadratic for the roots x1 and x2 
*         eq[0] * t^2 + eq[1] * t + eq[2] = 0
* INPUT: 'eq' the coefficients of the parabola
* RETURN: roots x1 and x2 and the number of solutions
*******************************************************************************/
int quadraticSolve(double* eq, double* x1, double* x2)
{
  if (eq[0] == 0.0) { // This is a linear equation
    if (eq[1] != 0.0) { // one solution
      *x1 = -eq[2]/eq[1];
      *x2 = 1.0e36;
      return 1;
    }else { // no solutions, 1.0e36 will be ignored.
      *x1 = 1.0e36;
      *x2 = 1.0e36;
      return 0;
    }
  }
  double delta = eq[1]*eq[1]-4.0*eq[0]*eq[2];
  if (delta < 0.0) { // no solutions, both are imaginary
    *x1 = 1.0e36;
    *x2 = 1.0e36;
    return 0;
  }
  double s = 1.0;
  if (eq[1] < 0) {
    s = -1.0;
  }
  *x1 = (-eq[1] - s * sqrt(delta))/(2.0*eq[0]);
  if (eq[0] != 0.0) { //two solutions
    *x2 = eq[2]/(eq[0]*(*x1));
    return 2;
  } else { //one solution
    *x2 = 1.0e36;
    return 1;
  }
}

/*******************************************************************************
* int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         ax, ay, az are the local acceleration vector
*         data points to the OFF data structure
* RETURN: the number of polyhedral which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*         data is the full OFF structure, including a list intersection type
*******************************************************************************/
int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data )
{

    int t_size = 0;
#ifdef OFF_LEGACY

    if(mcgravitation) {
      Coords pos={ x,  y,  z};
      Coords vel={vx, vy, vz};
      Coords acc={ax, ay, az};
      t_size=off_clip_3D_mod_grav(data->intersects, pos, vel, acc,
				  data->vtxArray, data->vtxSize, data->faceArray,
				  data->faceSize, data->normalArray, data->DArray );
    } else {
    ///////////////////////////////////
    // non-grav
      Coords A={x, y, z};
      Coords B={x+vx, y+vy, z+vz};
      t_size=off_clip_3D_mod(data->intersects, A, B,
			     data->vtxArray, data->vtxSize, data->faceArray,
			     data->faceSize, data->normalArray );
    }
    #ifndef OPENACC
    qsort(data->intersects, t_size, sizeof(intersection),  off_compare);
    #else
    #ifdef USE_OFF
    gpusort(data->intersects, t_size);
    #endif
    #endif
    off_cleanDouble(data->intersects, &t_size);
    off_cleanInOut(data->intersects,  &t_size);

    /*find intersections "closest" to 0 (favouring positive ones)*/
    if(t_size>0){
      int i=0;
      if(t_size>1) {
        for (i=1; i < t_size-1; i++){
          if (data->intersects[i-1].time > 0 && data->intersects[i].time > 0)
            break;
        }

	data->nextintersect=i-1;
	data->numintersect=t_size;

        if (t0) *t0 = data->intersects[i-1].time;
        if (n0) *n0 = data->intersects[i-1].normal;
        if (t3) *t3 = data->intersects[i].time;
        if (n3) *n3 = data->intersects[i].normal;
      } else {
        if (t0) *t0 = data->intersects[0].time;
	      if (n0) *n0 = data->intersects[0].normal;
      }
      /* should also return t[0].index and t[i].index as polygon ID */
      data->nextintersect=(data->intersects[data->nextintersect]).index;
      return t_size;
    }
#else
    intersection intersect4[4];
    intersect4[0].time=-FLT_MAX;
    intersect4[1].time=FLT_MAX;
    intersect4[2].time=FLT_MAX;
    intersect4[3].time=FLT_MAX;
    if(mcgravitation) {
      Coords pos={ x,  y,  z};
      Coords vel={vx, vy, vz};
      Coords acc={ax, ay, az};
      t_size=off_clip_3D_mod_grav(intersect4, pos, vel, acc,
				  data->vtxArray, data->vtxSize, data->faceArray,
				  data->faceSize, data->normalArray, data->DArray);
    } else {
    ///////////////////////////////////
    // non-grav
      Coords A={x, y, z};
      Coords B={x+vx, y+vy, z+vz};
      t_size=off_clip_3D_mod(intersect4, A, B,
	  data->vtxArray, data->vtxSize, data->faceArray, data->faceSize, data->normalArray );
    }
    if(t_size>0){
      int i=0;
      if (intersect4[0].time == -FLT_MAX) i=1;
      data->numintersect=t_size;
      if (t0) *t0 = intersect4[i].time;
      if (n0) *n0 = intersect4[i].normal;
      if (t3) *t3 = intersect4[i+1].time;
      if (n3) *n3 = intersect4[i+1].normal;

      if (intersect4[1].time == FLT_MAX)
      {
        if (t3) *t3 = 0.0;
      }

      /* should also return t[0].index and t[i].index as polygon ID */
      data->nextintersect=(int)intersect4[i].index;
      return t_size;
    }
#endif
    return 0;
} /* off_intersect */

/*******************************************************************************
* int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     off_struct data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         data points to the OFF data structure
* RETURN: the number of polyhedral which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct data )
{
  return off_intersect_all(t0, t3, n0, n3, x, y, z, vx, vy, vz, ax, ay, az, &data );
} /* off_intersect */

/*****************************************************************************
* int off_x_intersect(double* l0, double* l3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double kx, double ky, double kz,
     off_struct data )
* ACTION: computes intersection of an xray trajectory with an object.
* INPUT:  x,y,z and kx,ky,kz, are spatial coordinates and wavevector of the x-ray
*         respectively. data points to the OFF data structure.
* RETURN: the number of polyhedral the trajectory intersects
*         l0 and l3 are the smallest incoming and outgoing intersection lengths
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
int off_x_intersect(double *l0,double *l3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double kx, double ky, double kz,
     off_struct data )
{
  /*This function simply reformats and calls off_intersect (as for neutrons)
   *by normalizing the wavevector - this will yield the intersection lengths
   *in m*/
  double jx,jy,jz,invk;
  int n;
  invk=1/sqrt(scalar_prod(kx,ky,kz,kx,ky,kz));
  jx=kx*invk;jy=ky*invk;jz=kz*invk;
  n=off_intersect(l0,l3,n0,n3,x,y,z,jx,jy,jz,0.0,0.0,0.0,data);
  return n;
}


/*******************************************************************************
* void off_display(off_struct data)
* ACTION: display up to N_VERTEX_DISPLAYED polygons from the object
*******************************************************************************/
void off_display(off_struct data)
{
    if(mcdotrace==2){
    // Estimate size of the JSON string
    const int VERTEX_OVERHEAD = 30;
    const int FACE_OVERHEAD_BASE = 20;
    const int FACE_INDEX_OVERHEAD = 15;
    int estimated_size = 256; // Base size
    estimated_size += data.vtxSize * VERTEX_OVERHEAD;

    for (int i = 0; i < data.faceSize;) {
        int num_indices = data.faceArray[i];
        estimated_size += FACE_OVERHEAD_BASE + num_indices * FACE_INDEX_OVERHEAD;
        i += num_indices + 1;
    }

    char *json_string = malloc(estimated_size);
    if (json_string == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    char *ptr = json_string;
    ptr += sprintf(ptr, "{ \"vertices\": [");

    for (int i = 0; i < data.vtxSize; i++) {
        ptr += sprintf(ptr, "[%g, %g, %g]", data.vtxArray[i].x, data.vtxArray[i].y, data.vtxArray[i].z);
        if (i < data.vtxSize - 1) {
            ptr += sprintf(ptr, ", ");
        }
    }

    ptr += sprintf(ptr, "], \"faces\": [");

    for (int i = 0; i < data.faceSize;) {
        int num = data.faceArray[i];
        ptr += sprintf(ptr, "{ \"face\": [");
        for (int j = 1; j <= num; j++) {
            ptr += sprintf(ptr, "%lu", data.faceArray[i + j]);
            if (j < num) {
                ptr += sprintf(ptr, ", ");
            }
        }
        ptr += sprintf(ptr, "]}");
        i += num + 1;
        if(i<data.faceSize){
          ptr += sprintf(ptr, ", ");
        }
    }

    ptr += sprintf(ptr, "]}");
    mcdis_polyhedron(json_string);

    free(json_string);
    }
    else {
      unsigned int i;
      double ratio=(double)(N_VERTEX_DISPLAYED)/(double)data.faceSize;
      unsigned int pixel=0;
      for (i=0; i<data.faceSize-1; i++) {
        int j;
        int nbVertex = data.faceArray[i];
        double x0,y0,z0;
        x0 = data.vtxArray[data.faceArray[i+1]].x;
        y0 = data.vtxArray[data.faceArray[i+1]].y;
        z0 = data.vtxArray[data.faceArray[i+1]].z;
        double x1=x0,y1=y0,z1=z0;
        double cmx=0,cmy=0,cmz=0;

        int drawthis = rand01() < ratio;
        // First pass, calculate center of mass location...
        for (j=1; j<=nbVertex; j++) {
          cmx = cmx+data.vtxArray[data.faceArray[i+j]].x;
          cmy = cmy+data.vtxArray[data.faceArray[i+j]].y;
          cmz = cmz+data.vtxArray[data.faceArray[i+j]].z;
        }
        cmx /= nbVertex;
        cmy /= nbVertex;
        cmz /= nbVertex;

        char pixelinfo[1024];
	char pixelinfotmp[1024];
        sprintf(pixelinfo, "%li,%li,%li,%i,%g,%g,%g,%g,%g,%g", data.mantidoffset+pixel, data.mantidoffset, data.mantidoffset+data.polySize-1, nbVertex, cmx, cmy, cmz, x1-cmx, y1-cmy, z1-cmz);
        for (j=2; j<=nbVertex; j++) {
          double x2,y2,z2;
          x2 = data.vtxArray[data.faceArray[i+j]].x;
          y2 = data.vtxArray[data.faceArray[i+j]].y;
          z2 = data.vtxArray[data.faceArray[i+j]].z;
          sprintf(pixelinfotmp, "%s,%g,%g,%g", pixelinfo, x2-cmx, y2-cmy, z2-cmz);
	  sprintf(pixelinfo,"%s",pixelinfotmp);
          if (ratio > 1 || drawthis) {
	    mcdis_line(x1,y1,z1,x2,y2,z2);
          }
          x1 = x2; y1 = y2; z1 = z2;
        }
        if (ratio > 1 || drawthis) {
	    mcdis_line(x1,y1,z1,x0,y0,z0);
          }
        if (data.mantidflag) {
          printf("MANTID_PIXEL: %s\n", pixelinfo);
          pixel++;
        }
        i += nbVertex;
      }
    }
} /* off_display */

/* end of interoff-lib.c */
#endif // INTEROFF_LIB_C

  struct StructVarsInc {
    double sigma_a; /* Absorption cross section per atom (barns) */
    double sigma_i; /* Incoherent scattering cross section per atom (barns) */
    double rho;     /* Density of atoms (AA-3) */
    double my_s;
    double my_a_v;
    int shape;         /* 0 cylinder, 1 box, 2 sphere, 3 OFF file */
    double aw, ah;     /* rectangular angular dimensions */
    double xw, yh;     /* rectangular metrical dimensions */
    double tx, ty, tz; /* target coords */
  };

/* Shared user declarations for all components types 'Phonon_simple'. */
  #ifndef PHONON_SIMPLE
  #define PHONON_SIMPLE $Revision$
  #define T2E (1/11.605)   /* Kelvin to meV */

  struct phonon_params {
    double a_;   // d spacing of the cubic lattice
    double c_;   // Speed of sound in the material
    double gap_; // optional spin gap
    double ah;   // Half of a
    int e_steps_high_;
    int e_steps_low_;
  };
  struct neutron_params {
    // Statically allocate vectors that are always 3
    double vf;   // Final velocity size
    double vi;   // Initial velocity size
    double vv_x; // vv is the unit vector of the final velocity vector
    double vv_y;
    double vv_z;
    double vi_x; // vi is the initial velocity vector
    double vi_y;
    double vi_z;
  };

  #pragma acc routine
  double
  nbose (double omega, double T) /* Other name ?? */
  {
    double nb;

    nb = (omega > 0) ? 1 + 1 / (exp (omega / (T * T2E)) - 1) : 1 / (exp (-omega / (T * T2E)) - 1);
    return nb;
  }
  #undef T2E
  /* Routine types from Numerical Recipies book */
  #define UNUSED (-1.11e30)
  #define MAXRIDD 60

  void
  fatalerror_cpu (char* s) {
    fprintf (stderr, "%s \n", s);
    exit (1);
  }

  #pragma acc routine
  void
  fatalerror (char* s) {
    #ifndef OPENACC
    fatalerror_cpu (s);
    #endif
  }

  #pragma acc routine
  double
  omega_q (struct neutron_params* neutron, struct phonon_params* phonon) {
    /* dispersion in units of meV  */
    double vi, vf, vv_x, vv_y, vv_z, vi_x, vi_y, vi_z;
    double q, qx, qy, qz, Jq, res_phonon, res_neutron;
    double ah, a, c;
    double gap;

    vf = neutron->vf;
    vi = neutron->vi;
    vv_x = neutron->vv_x;
    vv_y = neutron->vv_y;
    vv_z = neutron->vv_z;
    vi_x = neutron->vi_x;
    vi_y = neutron->vi_y;
    vi_z = neutron->vi_z;
    a = phonon->a_;
    c = phonon->c_;
    gap = phonon->gap_;
    ah = phonon->ah;

    qx = V2K * (vi_x - vf * vv_x);
    qy = V2K * (vi_y - vf * vv_y);
    qz = V2K * (vi_z - vf * vv_z);
    q = sqrt (qx * qx + qy * qy + qz * qz);
    Jq = 2 * (cos (ah * (qx + qy)) + cos (ah * (qx - qy)) + cos (ah * (qx + qz)) + cos (ah * (qx - qz)) + cos (ah * (qy + qz)) + cos (ah * (qy - qz)));
    if (gap > 0) {
      res_phonon = sqrt (gap * gap + (12 - Jq) * (c * c) / (a * a));
    } else {
      res_phonon = c / a * sqrt (12 - Jq);
    }
    res_neutron = fabs (VS2E * (vi * vi - vf * vf));

    return (res_phonon - res_neutron);
  }

  double
  zridd (double (*func) (struct neutron_params*, struct phonon_params*), double x1, double x2, struct neutron_params* neutron, struct phonon_params* phonon,
         double xacc) {
    int j;
    double ans, fh, fl, fm, fnew, s, xh, xl, xm, xnew;

    neutron->vf = x1;
    fl = func (neutron, phonon);
    neutron->vf = x2;
    fh = func (neutron, phonon);
    if (fl * fh >= 0) {
      if (fl == 0)
        return x1;
      if (fh == 0)
        return x2;
      return UNUSED;
    } else {
      xl = x1;
      xh = x2;
      ans = UNUSED;
      for (j = 1; j < MAXRIDD; j++) {
        xm = 0.5 * (xl + xh);
        neutron->vf = xm;
        fm = func (neutron, phonon);
        s = sqrt (fm * fm - fl * fh);
        if (s == 0.0)
          return ans;
        xnew = xm + (xm - xl) * ((fl >= fh ? 1.0 : -1.0) * fm / s);
        if (fabs (xnew - ans) <= xacc)
          return ans;
        ans = xnew;
        neutron->vf = ans;
        fnew = func (neutron, phonon);
        if (fnew == 0.0)
          return ans;
        if (fabs (fm) * SIGN (fnew) != fm) {
          xl = xm;
          fl = fm;
          xh = ans;
          fh = fnew;
        } else if (fabs (fl) * SIGN (fnew) != fl) {
          xh = ans;
          fh = fnew;
        } else if (fabs (fh) * SIGN (fnew) != fh) {
          xl = ans;
          fl = fnew;
        } else
          fatalerror ("never get here in zridd");
        if (fabs (xh - xl) <= xacc)
          return ans;
      }
      fatalerror ("zridd exceeded maximum iterations");
    }
    return 0.0; /* Never get here */
  }

  #pragma acc routine
  double
  zridd_gpu (double x1, double x2, struct neutron_params* neutron, struct phonon_params* phonon, double xacc) {
    int j;
    double ans, fh, fl, fm, fnew, s, xh, xl, xm, xnew;

    neutron->vf = x1;
    fl = omega_q (neutron, phonon);
    neutron->vf = x2;
    fh = omega_q (neutron, phonon);
    if (fl * fh >= 0) {
      if (fl == 0)
        return x1;
      if (fh == 0)
        return x2;
      return UNUSED;
    } else {
      xl = x1;
      xh = x2;
      ans = UNUSED;
      for (j = 1; j < MAXRIDD; j++) {
        xm = 0.5 * (xl + xh);
        neutron->vf = xm;
        fm = omega_q (neutron, phonon);
        s = sqrt (fm * fm - fl * fh);
        if (s == 0.0)
          return ans;
        xnew = xm + (xm - xl) * ((fl >= fh ? 1.0 : -1.0) * fm / s);
        if (fabs (xnew - ans) <= xacc)
          return ans;
        ans = xnew;
        neutron->vf = ans;
        fnew = omega_q (neutron, phonon);
        if (fnew == 0.0)
          return ans;
        if (fabs (fm) * SIGN (fnew) != fm) {
          xl = xm;
          fl = fm;
          xh = ans;
          fh = fnew;
        } else if (fabs (fl) * SIGN (fnew) != fl) {
          xh = ans;
          fh = fnew;
        } else if (fabs (fh) * SIGN (fnew) != fh) {
          xl = ans;
          fl = fnew;
        } else
          fatalerror ("never get here in zridd");
        if (fabs (xh - xl) <= xacc)
          return ans;
      }
      fatalerror ("zridd exceeded maximum iterations");
    }
    return 0.0; /* Never get here */
  }

  #define ROOTACC 1e-8

  void
  findroots (double brack_low, double brack_mid, double brack_high, double* list, int* index, double (*f) (struct neutron_params*, struct phonon_params*),
             struct neutron_params* neutron, struct phonon_params* phonon) {
    double root;
    // Energy gain and energy loss spaces are not equally big. We check uniformly
    // So we use two different ranges
    double range_low = brack_mid - brack_low;
    double range_high = brack_high - brack_mid;
    // First in energy loss for the neutron
    for (int i = 0; i < phonon->e_steps_low_; i++) {
      root = zridd (f, brack_low + range_low * i / phonon->e_steps_low_, brack_low + range_low * (i + 1) / phonon->e_steps_low_, neutron, phonon, ROOTACC);
      if (root != UNUSED) {
        list[(*index)++] = root;
      }
    }

    // Then in energy gain for the neutron
    for (int i = 0; i < phonon->e_steps_high_; i++) {
      root = zridd (f, brack_mid + range_high * i / phonon->e_steps_high_, brack_mid + range_high * (i + 1) / phonon->e_steps_high_, neutron, phonon, ROOTACC);
      if (root != UNUSED) {
        list[(*index)++] = root;
      }
    }
  }

  #pragma acc routine
  void
  findroots_gpu (double brack_low, double brack_mid, double brack_high, double* list, int* index, struct neutron_params* neutron, struct phonon_params* phonon) {
    double root;
    // Energy gain and energy loss spaces are not equally big. We check uniformly
    // So we use two different ranges
    double range_low = brack_mid - brack_low;
    double range_high = brack_high - brack_mid;
    // First in energy loss for the neutron
    for (int i = 0; i < phonon->e_steps_low_; i++) {
      root = zridd_gpu (brack_low + range_low * i / phonon->e_steps_low_, brack_low + range_low * (i + 1) / phonon->e_steps_low_, neutron, phonon, ROOTACC);
      if (root != UNUSED) {
        list[(*index)++] = root;
      }
    }

    // Then in energy gain for the neutron
    for (int i = 0; i < phonon->e_steps_high_; i++) {
      root = zridd_gpu (brack_mid + range_high * i / phonon->e_steps_high_, brack_mid + range_high * (i + 1) / phonon->e_steps_high_, neutron, phonon, ROOTACC);
      if (root != UNUSED) {
        list[(*index)++] = root;
      }
    }
  }

  #undef UNUSED
  #undef MAXRIDD
  #endif

/* Shared user declarations for all components types 'Res_sample'. */
  struct res_sample_vars {
    char   isrect;                     /* true when sample is a box */
    double awdim, ahdim;               /* rectangular angular dimensions */
    double xwdim, yhdim;               /* rectangular metrical dimensions */
    double targetx, targety, targetz;  /* target coords */
  };

/* Shared user declarations for all components types 'Filter_gen'. */
  #ifndef FILTER_GEN
  #define FILTER_GEN $Revision$
  #define UNKNOWN_TABLE    0
  #define ENERGY_TABLE     1
  #define WAVEVECTOR_TABLE 2
  #define WAVELENGTH_TABLE 3
  #define FLUX_ADAPT_SET   0
  #define FLUX_ADAPT_MULT  1
  #define FLUX_ADAPT_ADD   2

  char
  FilterGen_Mode (char* str, char* Mode, char* Type, double* verbose) {
    long i;
    char* c;
    if (!str || !strlen (str))
      return (0);
    c = malloc (strlen (str));
    if (!c) {
      fprintf (stderr, "Filter_Gen: malloc error in FilterGen_Mode. Exit!\n");
      exit (-1);
    }
    for (i = 0; i < strlen (str); i++)
      c[i] = tolower (str[i]);
    /* setup options */
    if (strstr (str, " k ") || strstr (str, " q ") || strstr (str, "wavevector"))
      *Type = WAVEVECTOR_TABLE;
    if (strstr (str, "omega") || strstr (str, " e ") || strstr (str, "energy"))
      *Type = ENERGY_TABLE;
    if (strstr (str, "lambda") || strstr (str, "wavelength") || strstr (str, " L "))
      *Type = WAVELENGTH_TABLE;
    if (strstr (str, "set"))
      *Mode = FLUX_ADAPT_SET;
    if (strstr (str, "add"))
      *Mode = FLUX_ADAPT_ADD;
    if (strstr (str, "multiply"))
      *Mode = FLUX_ADAPT_MULT;
    if (strstr (str, "verbose"))
      *verbose = 1;

    return (*Mode);
  }

  #endif

/* Shared user declarations for all components types 'PowderN'. */
  /* used for reading data table from file */


  /* Declare structures and functions only once in each instrument. */
  #ifndef POWDERN_DECL
  #define POWDERN_DECL

  struct line_data {
    double F2;       /* Value of structure factor */
    double q;        /* Qvector */
    int j;           /* Multiplicity */
    double DWfactor; /* Debye-Waller factor */
    double w;        /* Intrinsic line width */
    double Epsilon;  /* Strain=delta_d_d/d shift in ppm */
  };

  struct line_info_struct {
    struct line_data* list; /* Reflection array */
    int count;              /* Number of reflections */
    double Dd;
    double DWfactor;
    double V_0;
    double rho;
    double at_weight;
    double at_nb;
    double sigma_a;
    double sigma_i;
    char compname[256];
    double flag_barns;
    int shape;           /* 0 cylinder, 1 box, 2 sphere, 3 OFF file */
    int column_order[9]; /* column signification */
    int flag_warning;
    double dq;      /* wavevector transfer [Angs-1] */
    double Epsilon; /* global strain in ppm */
    double XsectionFactor;
    double my_s_v2_sum;
    double my_a_v;
    double my_inc;
    double lfree; // store mean free path for the last event;
    double *w_v, *q_v, *my_s_v2;
    double radius_i, xwidth_i, yheight_i, zdepth_i;
    double v; /* last velocity (cached) */
    double Nq;
    int nb_reuses, nb_refl, nb_refl_count;
    double v_min, v_max;
    double xs_Nq[CHAR_BUF_LENGTH];
    double xs_sum[CHAR_BUF_LENGTH];
    double neutron_passed;
    long xs_compute, xs_reuse, xs_calls;
  };

  // PN_list_compare *****************************************************************

  int
  PN_list_compare (const void* a, const void* b) {
    const struct line_data* pa = a;
    const struct line_data* pb = b;

    /* Sort by q */
    if (pa->q < pb->q)
      return -1;
    if (pa->q > pb->q)
      return 1;

    /* In case of tie, sort by F2 also */
    if (pa->F2 < pb->F2)
      return -1;
    if (pa->F2 > pb->F2)
      return 1;

    /* In case of tie, sort by j also */
    if (pa->j < pb->j)
      return -1;
    if (pa->j > pb->j)
      return 1;

    return 0;
  } /* PN_list_compare */

  #ifndef CIF2HKL
  #define CIF2HKL
  // hkl_filename = cif2hkl(file, options)
  //   used to convert CIF/CFL/INS file into F2(hkl)
  //   the CIF2HKL env var can point to a cif2hkl executable
  //   else the McCode binary is attempted, then the system.
  char*
  cif2hkl (char* infile, char* options) {
    char cmd[1024];
    int ret = 0;
    int found = 0;
    char* OUTFILE;
    char* inpath;

    // get filename extension
    char* ext = strrchr (infile, '.');
    if (!ext || ext == infile)
      return infile;
    else
      ext++;

    // return input when no extension or not a CIF/FullProf/ShelX file
    if (strcasecmp (ext, "cif") && strcasecmp (ext, "pcr") && strcasecmp (ext, "cfl") && strcasecmp (ext, "shx") && strcasecmp (ext, "ins")
        && strcasecmp (ext, "res"))
      return infile;

    OUTFILE = malloc (1024);
    if (!OUTFILE) {
      free (OUTFILE);
      return infile;
    }
    inpath = malloc (1024);
    if (!inpath) {
      free (OUTFILE);
      free (inpath);
      return infile;
    }

    // get input file path from read-table:Open_File
    FILE* f_infile = Open_File (infile, "r", inpath);
    if (!f_infile) {
      free (OUTFILE);
      free (inpath);
      free (f_infile);
      return infile;
    }
    fclose (f_infile);

    strncpy (OUTFILE, tmpnam (NULL), 1024); // create an output temporary file name

    // try in order the CIF2HKL env var, then the system cif2hkl, then the McCode one
    if (!found && getenv ("CIF2HKL")) {
      snprintf (cmd, 1024, "%s -o %s %s %s", getenv ("CIF2HKL"), OUTFILE, options, inpath);
      ret = system (cmd);
      if (ret != -1 && ret != 127)
        found = 1;
    }
    if (!found) {
      // try with cif2hkl command from the system PATH
      snprintf (cmd, 1024, "%s -o %s %s %s", "cif2hkl", OUTFILE, options, infile);
      ret = system (cmd);
      if (ret != -1 && ret != 127)
        found = 1;
    }
    if (!found) {
      // As a last resort, attempt with cif2hkl from $MCSTAS/bin
      snprintf (cmd, 1024, "%s%c%s%c%s -o %s %s %s", getenv (FLAVOR_UPPER) ? getenv (FLAVOR_UPPER) : MCSTAS, MC_PATHSEP_C, "bin", MC_PATHSEP_C, "cif2hkl",
                OUTFILE, options, inpath);
      ret = system (cmd);
    }
    // ret = -1:  child process could not be created
    // ret = 127: shell could not be executed in the child process
    if (ret == -1 || ret == 127) {
      free (OUTFILE);
      return (NULL);
    }

    // test if the result file has been created
    FILE* file = fopen (OUTFILE, "r");
    if (!file) {
      free (OUTFILE);
      return (NULL);
    }
    MPI_MASTER (printf ("%s: INFO: Converting %s into F2(HKL) list %s\n", __FILE__, inpath, OUTFILE); printf ("%s\n", cmd););
    fflush (NULL);
    fclose (file);
    return (OUTFILE);
  } // cif2hkl
  #endif

  int
  read_line_data (char* SC_file, struct line_info_struct* info) {
    struct line_data* list = NULL;
    int size = 0;
    t_Table sTable; /* sample data table structure from SC_file */
    int i = 0;
    int mult_count = 0;
    char flag = 0;
    double q_count = 0, j_count = 0, F2_count = 0;
    char** parsing;
    int list_count = 0;
    char* filename = NULL;

    if (!SC_file || !strlen (SC_file) || !strcmp (SC_file, "NULL")) {
      MPI_MASTER (printf ("PowderN: %s: Using incoherent elastic scattering only.\n", info->compname););
      info->count = 0;
      return (0);
    }
    filename = cif2hkl (SC_file, "--mode NUC");
    if (filename != SC_file)
      info->flag_barns = 1;                          // cif2hkl returns barns
    long retval = Table_Read (&sTable, filename, 1); /* read 1st block data from SC_file into sTable*/
    if (retval < 0) {
      fprintf (stderr, "PowderN: Could not open file %s - exiting!\n", SC_file);
      exit (-1);
    }

    /* parsing of header */
    parsing = Table_ParseHeader (sTable.header, "Vc", "V_0", "sigma_abs", "sigma_a ", "sigma_inc", "sigma_i ", "column_j", "column_d", "column_F2", "column_DW",
                                 "column_Dd", "column_inv2d", "column_1/2d", "column_sintheta/lambda", "column_q",                           /* 14 */
                                 "DW", "Debye_Waller", "delta_d_d/d", "column_F ", "V_rho", "density", "weight", "nb_atoms", "multiplicity", /* 23 */
                                 "column_ppm", "column_strain", NULL);

    if (parsing) {
      if (parsing[0] && !info->V_0)
        info->V_0 = atof (parsing[0]);
      if (parsing[1] && !info->V_0)
        info->V_0 = atof (parsing[1]);
      if (parsing[2] && !info->sigma_a)
        info->sigma_a = atof (parsing[2]);
      if (parsing[3] && !info->sigma_a)
        info->sigma_a = atof (parsing[3]);
      if (parsing[4] && !info->sigma_i)
        info->sigma_i = atof (parsing[4]);
      if (parsing[5] && !info->sigma_i)
        info->sigma_i = atof (parsing[5]);
      if (parsing[6])
        info->column_order[0] = atoi (parsing[6]);
      if (parsing[7])
        info->column_order[1] = atoi (parsing[7]);
      if (parsing[8])
        info->column_order[2] = atoi (parsing[8]);
      if (parsing[9])
        info->column_order[3] = atoi (parsing[9]);
      if (parsing[10])
        info->column_order[4] = atoi (parsing[10]);
      if (parsing[11])
        info->column_order[5] = atoi (parsing[11]);
      if (parsing[12])
        info->column_order[5] = atoi (parsing[12]);
      if (parsing[13])
        info->column_order[5] = atoi (parsing[13]);
      if (parsing[14])
        info->column_order[6] = atoi (parsing[14]);
      if (parsing[15] && info->DWfactor <= 0)
        info->DWfactor = atof (parsing[15]);
      if (parsing[16] && info->DWfactor <= 0)
        info->DWfactor = atof (parsing[16]);
      if (parsing[17] && info->Dd < 0)
        info->Dd = atof (parsing[17]);
      if (parsing[18])
        info->column_order[7] = atoi (parsing[18]);
      if (parsing[19] && !info->V_0)
        info->V_0 = 1 / atof (parsing[19]);
      if (parsing[20] && !info->rho)
        info->rho = atof (parsing[20]);
      if (parsing[21] && !info->at_weight)
        info->at_weight = atof (parsing[21]);
      if (parsing[22] && info->at_nb <= 1)
        info->at_nb = atof (parsing[22]);
      if (parsing[23] && info->at_nb <= 1)
        info->at_nb = atof (parsing[23]);
      if (parsing[24])
        info->column_order[8] = atoi (parsing[24]);
      if (parsing[25])
        info->column_order[8] = atoi (parsing[25]);
      for (i = 0; i <= 25; i++)
        if (parsing[i])
          free (parsing[i]);
      free (parsing);
    }

    if (!sTable.rows)
      exit (fprintf (stderr,
                     "PowderN: %s: Error: The number of rows in %s "
                     "should be at least %d\n",
                     info->compname, SC_file, 1));
    else
      size = sTable.rows;

    MPI_MASTER (Table_Info (sTable); printf ("PowderN: %s: Reading %d rows from %s\n", info->compname, size, SC_file););

    if (filename == SC_file) { // only when not from cif2hkl
      if (info->column_order[0] == 4 && info->flag_barns != 0)
        MPI_MASTER (printf ("PowderN: %s: Powder file probably of type Crystallographica/Fullprof (lau)\n"
                            "WARNING: but F2 unit is set to barns=1 (barns). Intensity might be 100 times too high.\n",
                            info->compname););
      if (info->column_order[0] == 17 && info->flag_barns == 0)
        MPI_MASTER (printf ("PowderN: %s: Powder file probably of type Lazy Pulver (laz)\n"
                            "WARNING: but F2 unit is set to barns=0 (fm^2). Intensity might be 100 times too low.\n",
                            info->compname););
    }
    /* allocate line_data array */
    list = (struct line_data*)malloc (size * sizeof (struct line_data));

    for (i = 0; i < size; i++) {
      /*      printf("Reading in line %i\n",i);*/
      double j = 0, d = 0, w = 0, q = 0, DWfactor = 0, F2 = 0, Epsilon = 0;
      int index;

      if (info->Dd >= 0)
        w = info->Dd;
      if (info->DWfactor > 0)
        DWfactor = info->DWfactor;
      if (info->Epsilon)
        Epsilon = info->Epsilon * 1e-6;

      /* get data from table using columns {j d F2 DW Dd inv2d q F} */
      /* column indexes start at 1, thus need to substract 1 */
      if (info->column_order[0] > 0)
        j = Table_Index (sTable, i, info->column_order[0] - 1);
      if (info->column_order[1] > 0)
        d = Table_Index (sTable, i, info->column_order[1] - 1);
      if (info->column_order[2] > 0)
        F2 = Table_Index (sTable, i, info->column_order[2] - 1);
      if (info->column_order[3] > 0)
        DWfactor = Table_Index (sTable, i, info->column_order[3] - 1);
      if (info->column_order[4] > 0)
        w = Table_Index (sTable, i, info->column_order[4] - 1);
      if (info->column_order[5] > 0 && !(info->column_order[1] > 0)) // Only use if d not read already
      {
        d = Table_Index (sTable, i, info->column_order[5] - 1);
        d = (d > 0 ? 1 / d / 2 : 0);
      }
      if (info->column_order[6] > 0 && !(info->column_order[1] > 0)) // Only use if d not read already
      {
        q = Table_Index (sTable, i, info->column_order[6] - 1);
        d = (q > 0 ? 2 * PI / q : 0);
      }
      if (info->column_order[7] > 0 && !F2) {
        F2 = Table_Index (sTable, i, info->column_order[7] - 1);
        F2 *= F2;
      }
      if (info->column_order[8] > 0 && !Epsilon) {
        Epsilon = Table_Index (sTable, i, info->column_order[8] - 1) * 1e-6;
      }

      /* assign and check values */
      j = (j > 0 ? j : 0);
      q = (d > 0 ? 2 * PI / d : 0); /* this is q */
      if (Epsilon && fabs (Epsilon) < 1e6) {
        q -= Epsilon * q; /* dq/q = -delta_d_d/d = -Epsilon */
      }
      DWfactor = (DWfactor > 0 ? DWfactor : 1);
      w = (w > 0 ? w : 0); /* this is q and d relative spreading */
      F2 = (F2 >= 0 ? F2 : 0);
      if (j == 0 || q == 0) {
        MPI_MASTER (printf ("PowderN: %s: line %i has invalid definition\n"
                            "         (mult=0 or q=0 or d=0)\n",
                            info->compname, i););
        continue;
      }
      list[list_count].j = j;
      list[list_count].q = q;
      list[list_count].DWfactor = DWfactor;
      list[list_count].w = w;
      list[list_count].F2 = F2;
      list[list_count].Epsilon = Epsilon;

      /* adjust multiplicity if j-column + multiple d-spacing lines */
      /* if  d = previous d, increase line duplication index */
      if (!q_count)
        q_count = q;
      if (!j_count)
        j_count = j;
      if (!F2_count)
        F2_count = F2;
      if (fabs (q_count - q) < 0.0001 * fabs (q) && fabs (F2_count - F2) < 0.0001 * fabs (F2) && j_count == j) {
        mult_count++;
        flag = 0;
      } else
        flag = 1;
      if (i == size - 1)
        flag = 1;
      /* else if d != previous d : just passed equivalent lines */
      if (flag) {
        if (i == size - 1)
          list_count++;
        /*   if duplication index == previous multiplicity */
        /*      set back multiplicity of previous lines to 1 */
        if ((mult_count && list_count > 0)
            && (mult_count == list[list_count - 1].j || ((list_count < size) && (i == size - 1) && (mult_count == list[list_count].j)))) {
          MPI_MASTER (printf ("PowderN: %s: Set multiplicity to 1 for lines [%i:%i]\n"
                              "         (d-spacing %g is duplicated %i times)\n",
                              info->compname, list_count - mult_count, list_count - 1, list[list_count - 1].q, mult_count););
          for (index = list_count - mult_count; index < list_count; list[index++].j = 1)
            ;
          mult_count = 1;
          q_count = q;
          j_count = j;
          F2_count = F2;
        }
        if (i == size - 1)
          list_count--;
        flag = 0;
      }
      list_count++;
    } /* end for */

    Table_Free (&sTable);

    /* sort the list with increasing q */
    qsort (list, list_count, sizeof (struct line_data), PN_list_compare);

    MPI_MASTER (printf ("PowderN: %s: Read %i reflections from file '%s'\n", info->compname, list_count, SC_file););

    // remove temporary F2(hkl) file when giving CFL/CIF/ShelX file
    if (filename != SC_file)
      unlink (filename);

    info->list = list;
    info->count = list_count;

    return (list_count);
  } /* read_line_data */

  /* computes the number of possible reflections (return value), and the total xsection 'sum' */
  /* this routine looks for a pre-computed value in the Nq and sum cache tables               */
  /* when found, the earch starts from the corresponding lower element in the table           */
  #pragma acc routine seq
  int
  calc_xsect (double v, double* qv, double* my_sv2, int count, double* sum, struct line_info_struct* line_info) {
    int Nq = 0, line = 0, line0 = 0;
    *sum = 0;

    /* check if a line_info element has been recorded already - not on OpenACC */
    #ifndef OPENACC
    if (v >= line_info->v_min && v <= line_info->v_max && line_info->neutron_passed >= CHAR_BUF_LENGTH) {
      line = (int)floor (v - line_info->v_min) * CHAR_BUF_LENGTH / (line_info->v_max - line_info->v_min);
      Nq = line_info->xs_Nq[line];
      *sum = line_info->xs_sum[line];
      if (!Nq && *sum == 0) {
        /* not yet set: we compute the sum up to the corresponding speed in the table cache */
        double line_v = line_info->v_min + line * (line_info->v_max - line_info->v_min) / CHAR_BUF_LENGTH;
        for (line0 = 0; line0 < count; line0++) {
          if (qv[line0] <= 2 * line_v) { /* q < 2*kf: restrict structural range */
            *sum += my_sv2[line0];
            if (Nq < line0 + 1)
              Nq = line0 + 1; /* determine maximum line index which can scatter */
          } else
            break;
        }
        line_info->xs_Nq[line] = Nq;
        line_info->xs_sum[line] = *sum;
        line_info->xs_compute++;
      } else
        line_info->xs_reuse++;
      line0 = Nq;
    }

    line_info->xs_calls++;
    #endif

    for (line = line0; line < count; line++) {
      if (qv[line] <= 2 * v) { /* q < 2*kf: restrict structural range */
        *sum += my_sv2[line];
        if (Nq < line + 1)
          Nq = line + 1; /* determine maximum line index which can scatter */
      } else
        break;
    }

    return (Nq);
  } /* calc_xsect */

  #endif /* !POWDERN_DECL */



/* ************************************************************************** */
/*             End of SHARE user declarations for all components              */
/* ************************************************************************** */


/* ********************** component definition declarations. **************** */

/* component Origin=Progress_bar() [1] DECLARE */
/* Parameter definition for component type 'Progress_bar' */
struct _struct_Progress_bar_parameters {
  /* Component type 'Progress_bar' setting parameters */
  char profile[16384];
  MCNUM percent;
  MCNUM flag_save;
  MCNUM minutes;
  /* Component type 'Progress_bar' private parameters */
  double  IntermediateCnts;
  time_t  StartTime;
  time_t  EndTime;
  time_t  CurrentTime;
  char  infostring[64];
}; /* _struct_Progress_bar_parameters */
typedef struct _struct_Progress_bar_parameters _class_Progress_bar_parameters;

/* Parameters for component type 'Progress_bar' */
struct _struct_Progress_bar {
  char     _name[256]; /* e.g. Origin */
  char     _type[256]; /* Progress_bar */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Progress_bar_parameters _parameters;
};
typedef struct _struct_Progress_bar _class_Progress_bar;
_class_Progress_bar _Origin_var;
#pragma acc declare create ( _Origin_var )

/* component source=Source_gen4() [2] DECLARE */
/* Parameter definition for component type 'Source_gen4' */
struct _struct_Source_gen4_parameters {
  /* Component type 'Source_gen4' setting parameters */
  char flux_file[16384];
  char xdiv_file[16384];
  char ydiv_file[16384];
  MCNUM radius;
  MCNUM dist;
  MCNUM xw;
  MCNUM yh;
  MCNUM E0;
  MCNUM dE;
  MCNUM Lambda0;
  MCNUM dLambda;
  MCNUM I1;
  MCNUM h;
  MCNUM w;
  MCNUM gaussian;
  MCNUM verbose;
  MCNUM T1;
  MCNUM flux_file_perAA;
  MCNUM flux_file_log;
  MCNUM Lmin;
  MCNUM Lmax;
  MCNUM Emin;
  MCNUM Emax;
  MCNUM T2;
  MCNUM I2;
  MCNUM T3;
  MCNUM I3;
  MCNUM length;
  MCNUM phi_init;
  MCNUM theta_init;
  MCNUM HEtailA;
  MCNUM HEtailL0;
  /* Component type 'Source_gen4' private parameters */
  t_Table  pTable;
  t_Table  pTable_x;
  t_Table  pTable_y;
  double  p_in;
  double  lambda0;
  double  lambda02;
  double  lambda0b;
  double  lambda02b;
  double  lambda0c;
  double  lambda02c;
  double  L2P;
  double  L2Pb;
  double  L2Pc;
  double  pTable_xmin;
  double  pTable_ymin;
  double  pTable_xmax;
  double  pTable_ymax;
  double  pTable_xsum;
  double  pTable_ysum;
  double  pTable_dxmin;
  double  pTable_dxmax;
  double  pTable_dymin;
  double  pTable_dymax;
}; /* _struct_Source_gen4_parameters */
typedef struct _struct_Source_gen4_parameters _class_Source_gen4_parameters;

/* Parameters for component type 'Source_gen4' */
struct _struct_Source_gen4 {
  char     _name[256]; /* e.g. source */
  char     _type[256]; /* Source_gen4 */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Source_gen4_parameters _parameters;
};
typedef struct _struct_Source_gen4 _class_Source_gen4;
_class_Source_gen4 _source_var;
#pragma acc declare create ( _source_var )

/* component StartOfGuideMonitor=PSD_monitor() [3] DECLARE */
/* Parameter definition for component type 'PSD_monitor' */
struct _struct_PSD_monitor_parameters {
  /* Component type 'PSD_monitor' setting parameters */
  int nx;
  int ny;
  char filename[16384];
  MCNUM xmin;
  MCNUM xmax;
  MCNUM ymin;
  MCNUM ymax;
  MCNUM xwidth;
  MCNUM yheight;
  int restore_neutron;
  int nowritefile;
  /* Component type 'PSD_monitor' private parameters */
  DArray2d  PSD_N;
  DArray2d  PSD_p;
  DArray2d  PSD_p2;
}; /* _struct_PSD_monitor_parameters */
typedef struct _struct_PSD_monitor_parameters _class_PSD_monitor_parameters;

/* Parameters for component type 'PSD_monitor' */
struct _struct_PSD_monitor {
  char     _name[256]; /* e.g. StartOfGuideMonitor */
  char     _type[256]; /* PSD_monitor */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_PSD_monitor_parameters _parameters;
};
typedef struct _struct_PSD_monitor _class_PSD_monitor;
_class_PSD_monitor _StartOfGuideMonitor_var;
#pragma acc declare create ( _StartOfGuideMonitor_var )

/* component StartOfGuide=Arm() [4] DECLARE */
/* Parameter definition for component type 'Arm' */
struct _struct_Arm_parameters {
  char Arm_has_no_parameters;
}; /* _struct_Arm_parameters */
typedef struct _struct_Arm_parameters _class_Arm_parameters;

/* Parameters for component type 'Arm' */
struct _struct_Arm {
  char     _name[256]; /* e.g. StartOfGuide */
  char     _type[256]; /* Arm */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Arm_parameters _parameters;
};
typedef struct _struct_Arm _class_Arm;
_class_Arm _StartOfGuide_var;
#pragma acc declare create ( _StartOfGuide_var )

/* component Insert=Elliptic_guide_gravity() [5] DECLARE */
/* Parameter definition for component type 'Elliptic_guide_gravity' */
struct _struct_Elliptic_guide_gravity_parameters {
  /* Component type 'Elliptic_guide_gravity' setting parameters */
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM l;
  MCNUM linxw;
  MCNUM loutxw;
  MCNUM linyh;
  MCNUM loutyh;
  MCNUM majorAxisxw;
  MCNUM minorAxisxw;
  MCNUM majorAxisyh;
  MCNUM minorAxisyh;
  MCNUM majorAxisoffsetxw;
  MCNUM majorAxisoffsetyh;
  char dimensionsAt[16384];
  char option[16384];
  MCNUM R0;
  MCNUM Qc;
  MCNUM alpha;
  MCNUM m;
  MCNUM W;
  MCNUM alpharight;
  MCNUM mright;
  MCNUM alphaleft;
  MCNUM mleft;
  MCNUM alphatop;
  MCNUM mtop;
  MCNUM alphabottom;
  MCNUM mbottom;
  char verbose[16384];
  MCNUM enableGravity;
  MCNUM curvature;
  int nSegments;
  MCNUM* mvaluesright;
  MCNUM* mvaluesleft;
  MCNUM* mvaluestop;
  MCNUM* mvaluesbottom;
  MCNUM* seglength;
  /* Component type 'Elliptic_guide_gravity' private parameters */
  struct SGI  guideInfo;
  double  Gx0;
  double  Gy0;
  double  Gz0;
  double  Circ;
  double*  dynamicalSegLength;
}; /* _struct_Elliptic_guide_gravity_parameters */
typedef struct _struct_Elliptic_guide_gravity_parameters _class_Elliptic_guide_gravity_parameters;

/* Parameters for component type 'Elliptic_guide_gravity' */
struct _struct_Elliptic_guide_gravity {
  char     _name[256]; /* e.g. Insert */
  char     _type[256]; /* Elliptic_guide_gravity */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Elliptic_guide_gravity_parameters _parameters;
};
typedef struct _struct_Elliptic_guide_gravity _class_Elliptic_guide_gravity;
_class_Elliptic_guide_gravity _Insert_var;
#pragma acc declare create ( _Insert_var )

_class_PSD_monitor _EndOfInsertPSD_var;
#pragma acc declare create ( _EndOfInsertPSD_var )

_class_Elliptic_guide_gravity _E2_var;
#pragma acc declare create ( _E2_var )

_class_Arm _EndOfelement_5_var;
#pragma acc declare create ( _EndOfelement_5_var )

_class_PSD_monitor _E2PSD_var;
#pragma acc declare create ( _E2PSD_var )

_class_Arm _EndOfelement_4_var;
#pragma acc declare create ( _EndOfelement_4_var )

/* component C1=Bender() [11] DECLARE */
/* Parameter definition for component type 'Bender' */
struct _struct_Bender_parameters {
  /* Component type 'Bender' setting parameters */
  MCNUM w;
  MCNUM h;
  MCNUM r;
  MCNUM Win;
  MCNUM k;
  MCNUM d;
  MCNUM l;
  MCNUM R0a;
  MCNUM Qca;
  MCNUM alphaa;
  MCNUM ma;
  MCNUM Wa;
  MCNUM R0i;
  MCNUM Qci;
  MCNUM alphai;
  MCNUM mi;
  MCNUM Wi;
  MCNUM R0s;
  MCNUM Qcs;
  MCNUM alphas;
  MCNUM ms;
  MCNUM Ws;
  /* Component type 'Bender' private parameters */
  double  bk;
  double  mWin;
}; /* _struct_Bender_parameters */
typedef struct _struct_Bender_parameters _class_Bender_parameters;

/* Parameters for component type 'Bender' */
struct _struct_Bender {
  char     _name[256]; /* e.g. C1 */
  char     _type[256]; /* Bender */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Bender_parameters _parameters;
};
typedef struct _struct_Bender _class_Bender;
_class_Bender _C1_var;
#pragma acc declare create ( _C1_var )

_class_Arm _EndOfelement_2_var;
#pragma acc declare create ( _EndOfelement_2_var )

_class_PSD_monitor _C1End_var;
#pragma acc declare create ( _C1End_var )

_class_Elliptic_guide_gravity _E3a_var;
#pragma acc declare create ( _E3a_var )

_class_PSD_monitor _E3aEnd_var;
#pragma acc declare create ( _E3aEnd_var )

_class_Elliptic_guide_gravity _E3b_var;
#pragma acc declare create ( _E3b_var )

_class_PSD_monitor _E3bEnd_var;
#pragma acc declare create ( _E3bEnd_var )

/* component SlitGuideEnd=Slit() [18] DECLARE */
/* Parameter definition for component type 'Slit' */
struct _struct_Slit_parameters {
  /* Component type 'Slit' setting parameters */
  MCNUM xmin;
  MCNUM xmax;
  MCNUM ymin;
  MCNUM ymax;
  MCNUM radius;
  MCNUM xwidth;
  MCNUM yheight;
  /* Component type 'Slit' private parameters */
  char  isradial;
}; /* _struct_Slit_parameters */
typedef struct _struct_Slit_parameters _class_Slit_parameters;

/* Parameters for component type 'Slit' */
struct _struct_Slit {
  char     _name[256]; /* e.g. SlitGuideEnd */
  char     _type[256]; /* Slit */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Slit_parameters _parameters;
};
typedef struct _struct_Slit _class_Slit;
_class_Slit _SlitGuideEnd_var;
#pragma acc declare create ( _SlitGuideEnd_var )

/* component Mono=Monochromator_curved() [19] DECLARE */
/* Parameter definition for component type 'Monochromator_curved' */
struct _struct_Monochromator_curved_parameters {
  /* Component type 'Monochromator_curved' setting parameters */
  char reflect[16384];
  char transmit[16384];
  MCNUM zwidth;
  MCNUM yheight;
  MCNUM gap;
  int NH;
  int NV;
  MCNUM mosaich;
  MCNUM mosaicv;
  MCNUM r0;
  MCNUM t0;
  MCNUM Q;
  MCNUM RV;
  MCNUM RH;
  MCNUM DM;
  MCNUM mosaic;
  MCNUM width;
  MCNUM height;
  MCNUM verbose;
  MCNUM order;
  /* Component type 'Monochromator_curved' private parameters */
  double  mos_rms_y;
  double  mos_rms_z;
  double  mos_rms_max;
  double  mono_Q;
  double  SlabWidth;
  double  SlabHeight;
  t_Table  rTable;
  t_Table  tTable;
  int  rTableFlag;
  int  tTableFlag;
  double*  tiltH;
  double*  tiltV;
  char  ncol_var[128];
  char  nrow_var[128];
}; /* _struct_Monochromator_curved_parameters */
typedef struct _struct_Monochromator_curved_parameters _class_Monochromator_curved_parameters;

/* Parameters for component type 'Monochromator_curved' */
struct _struct_Monochromator_curved {
  char     _name[256]; /* e.g. Mono */
  char     _type[256]; /* Monochromator_curved */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Monochromator_curved_parameters _parameters;
};
typedef struct _struct_Monochromator_curved _class_Monochromator_curved;
_class_Monochromator_curved _Mono_var;
#pragma acc declare create ( _Mono_var )

_class_Arm _A2_var;
#pragma acc declare create ( _A2_var )

_class_Slit _monochromatorShielding_var;
#pragma acc declare create ( _monochromatorShielding_var )

_class_Slit _slit_var;
#pragma acc declare create ( _slit_var )

_class_PSD_monitor _SlitMonitor_var;
#pragma acc declare create ( _SlitMonitor_var )

_class_Arm _SamplePos_var;
#pragma acc declare create ( _SamplePos_var )

_class_Arm _AMidt_var;
#pragma acc declare create ( _AMidt_var )

_class_Arm _a41_var;
#pragma acc declare create ( _a41_var )

_class_Arm _a42_var;
#pragma acc declare create ( _a42_var )

_class_Arm _a43_var;
#pragma acc declare create ( _a43_var )

_class_Arm _a44_var;
#pragma acc declare create ( _a44_var )

_class_Arm _a45_var;
#pragma acc declare create ( _a45_var )

_class_Arm _a46_var;
#pragma acc declare create ( _a46_var )

_class_Arm _a47_var;
#pragma acc declare create ( _a47_var )

_class_Arm _a48_var;
#pragma acc declare create ( _a48_var )

_class_PSD_monitor _sample_flux_before_var;
#pragma acc declare create ( _sample_flux_before_var )

_class_Arm _sample_scatter_state_reset_var;
#pragma acc declare create ( _sample_scatter_state_reset_var )

/* component VanSample=Incoherent() [36] DECLARE */
/* Parameter definition for component type 'Incoherent' */
struct _struct_Incoherent_parameters {
  /* Component type 'Incoherent' setting parameters */
  char geometry[16384];
  MCNUM radius;
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM zdepth;
  MCNUM thickness;
  MCNUM target_x;
  MCNUM target_y;
  MCNUM target_z;
  MCNUM focus_r;
  MCNUM focus_xw;
  MCNUM focus_yh;
  MCNUM focus_aw;
  MCNUM focus_ah;
  int target_index;
  MCNUM pack;
  MCNUM p_interact;
  MCNUM f_QE;
  MCNUM gamma;
  MCNUM Etrans;
  MCNUM deltaE;
  MCNUM sigma_abs;
  MCNUM sigma_inc;
  MCNUM Vc;
  MCNUM concentric;
  MCNUM order;
  /* Component type 'Incoherent' private parameters */
  struct StructVarsInc  VarsInc;
  off_struct  offdata;
}; /* _struct_Incoherent_parameters */
typedef struct _struct_Incoherent_parameters _class_Incoherent_parameters;

/* Parameters for component type 'Incoherent' */
struct _struct_Incoherent {
  char     _name[256]; /* e.g. VanSample */
  char     _type[256]; /* Incoherent */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Incoherent_parameters _parameters;
};
typedef struct _struct_Incoherent _class_Incoherent;
_class_Incoherent _VanSample_var;
#pragma acc declare create ( _VanSample_var )

/* component sample=Phonon_simple() [37] DECLARE */
/* Parameter definition for component type 'Phonon_simple' */
struct _struct_Phonon_simple_parameters {
  /* Component type 'Phonon_simple' setting parameters */
  MCNUM radius;
  MCNUM yheight;
  MCNUM sigma_abs;
  MCNUM sigma_inc;
  MCNUM a;
  MCNUM b;
  MCNUM M;
  MCNUM c;
  MCNUM DW;
  MCNUM T;
  MCNUM target_x;
  MCNUM target_y;
  MCNUM target_z;
  int target_index;
  MCNUM focus_r;
  MCNUM focus_xw;
  MCNUM focus_yh;
  MCNUM focus_aw;
  MCNUM focus_ah;
  MCNUM gap;
  int e_steps_low;
  int e_steps_high;
  /* Component type 'Phonon_simple' private parameters */
  double  V_rho;
  double  V_my_s;
  double  V_my_a_v;
  double  DV;
  struct phonon_params  phonon;
}; /* _struct_Phonon_simple_parameters */
typedef struct _struct_Phonon_simple_parameters _class_Phonon_simple_parameters;

/* Parameters for component type 'Phonon_simple' */
struct _struct_Phonon_simple {
  char     _name[256]; /* e.g. sample */
  char     _type[256]; /* Phonon_simple */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Phonon_simple_parameters _parameters;
};
typedef struct _struct_Phonon_simple _class_Phonon_simple;
_class_Phonon_simple _sample_var;
#pragma acc declare create ( _sample_var )

/* component powder1=Powder1() [38] DECLARE */
/* Parameter definition for component type 'Powder1' */
struct _struct_Powder1_parameters {
  /* Component type 'Powder1' setting parameters */
  MCNUM radius;
  MCNUM yheight;
  MCNUM xwidth;
  MCNUM zdepth;
  MCNUM q;
  MCNUM d;
  MCNUM d_phi;
  MCNUM pack;
  MCNUM j;
  MCNUM DW;
  MCNUM F2;
  MCNUM Vc;
  MCNUM sigma_abs;
  /* Component type 'Powder1' private parameters */
  double  my_s_v2;
  double  my_a_v;
  double  q_v;
  char  isrect;
}; /* _struct_Powder1_parameters */
typedef struct _struct_Powder1_parameters _class_Powder1_parameters;

/* Parameters for component type 'Powder1' */
struct _struct_Powder1 {
  char     _name[256]; /* e.g. powder1 */
  char     _type[256]; /* Powder1 */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Powder1_parameters _parameters;
};
typedef struct _struct_Powder1 _class_Powder1;
_class_Powder1 _powder1_var;
#pragma acc declare create ( _powder1_var )

/* component res_sample=Res_sample() [39] DECLARE */
/* Parameter definition for component type 'Res_sample' */
struct _struct_Res_sample_parameters {
  /* Component type 'Res_sample' setting parameters */
  MCNUM thickness;
  MCNUM radius;
  MCNUM focus_r;
  MCNUM E0;
  MCNUM dE;
  MCNUM target_x;
  MCNUM target_y;
  MCNUM target_z;
  MCNUM focus_xw;
  MCNUM focus_yh;
  MCNUM focus_aw;
  MCNUM focus_ah;
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM zdepth;
  int target_index;
  /* Component type 'Res_sample' private parameters */
  struct res_sample_vars  vars;
  char  res_pi_var[20];
  char  res_ki_x_var[20];
  char  res_ki_y_var[20];
  char  res_ki_z_var[20];
  char  res_kf_x_var[20];
  char  res_kf_y_var[20];
  char  res_kf_z_var[20];
  char  res_rx_var[20];
  char  res_ry_var[20];
  char  res_rz_var[20];
  int  compindex;
}; /* _struct_Res_sample_parameters */
typedef struct _struct_Res_sample_parameters _class_Res_sample_parameters;

/* Parameters for component type 'Res_sample' */
struct _struct_Res_sample {
  char     _name[256]; /* e.g. res_sample */
  char     _type[256]; /* Res_sample */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Res_sample_parameters _parameters;
};
typedef struct _struct_Res_sample _class_Res_sample;
_class_Res_sample _res_sample_var;
#pragma acc declare create ( _res_sample_var )

_class_PSD_monitor _sample_flux_after_unscattered_var;
#pragma acc declare create ( _sample_flux_after_unscattered_var )

/* component sample_cylinder_monitor=Cyl_monitor_PSD() [41] DECLARE */
/* Parameter definition for component type 'Cyl_monitor_PSD' */
struct _struct_Cyl_monitor_PSD_parameters {
  /* Component type 'Cyl_monitor_PSD' setting parameters */
  int nr;
  char filename[16384];
  MCNUM yheight;
  MCNUM radius;
  int restore_neutron;
  MCNUM thmin;
  MCNUM thmax;
  MCNUM ny;
  int nowritefile;
  /* Component type 'Cyl_monitor_PSD' private parameters */
  DArray2d  PSD_N;
  DArray2d  PSD_p;
  DArray2d  PSD_p2;
}; /* _struct_Cyl_monitor_PSD_parameters */
typedef struct _struct_Cyl_monitor_PSD_parameters _class_Cyl_monitor_PSD_parameters;

/* Parameters for component type 'Cyl_monitor_PSD' */
struct _struct_Cyl_monitor_PSD {
  char     _name[256]; /* e.g. sample_cylinder_monitor */
  char     _type[256]; /* Cyl_monitor_PSD */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Cyl_monitor_PSD_parameters _parameters;
};
typedef struct _struct_Cyl_monitor_PSD _class_Cyl_monitor_PSD;
_class_Cyl_monitor_PSD _sample_cylinder_monitor_var;
#pragma acc declare create ( _sample_cylinder_monitor_var )

/* component sample_spherical_monitor=PSD_monitor_4PI() [42] DECLARE */
/* Parameter definition for component type 'PSD_monitor_4PI' */
struct _struct_PSD_monitor_4PI_parameters {
  /* Component type 'PSD_monitor_4PI' setting parameters */
  int nx;
  int ny;
  char filename[16384];
  int nowritefile;
  MCNUM radius;
  int restore_neutron;
  /* Component type 'PSD_monitor_4PI' private parameters */
  DArray2d  PSD_N;
  DArray2d  PSD_p;
  DArray2d  PSD_p2;
}; /* _struct_PSD_monitor_4PI_parameters */
typedef struct _struct_PSD_monitor_4PI_parameters _class_PSD_monitor_4PI_parameters;

/* Parameters for component type 'PSD_monitor_4PI' */
struct _struct_PSD_monitor_4PI {
  char     _name[256]; /* e.g. sample_spherical_monitor */
  char     _type[256]; /* PSD_monitor_4PI */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_PSD_monitor_4PI_parameters _parameters;
};
typedef struct _struct_PSD_monitor_4PI _class_PSD_monitor_4PI;
_class_PSD_monitor_4PI _sample_spherical_monitor_var;
#pragma acc declare create ( _sample_spherical_monitor_var )

_class_PSD_monitor _BackEndMonitor_var;
#pragma acc declare create ( _BackEndMonitor_var )

_class_Slit _slitBackEnd_var;
#pragma acc declare create ( _slitBackEnd_var )

/* component filter_gen=Filter_gen() [45] DECLARE */
/* Parameter definition for component type 'Filter_gen' */
struct _struct_Filter_gen_parameters {
  /* Component type 'Filter_gen' setting parameters */
  char filename[16384];
  char options[16384];
  MCNUM xmin;
  MCNUM xmax;
  MCNUM ymin;
  MCNUM ymax;
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM thickness;
  MCNUM scaling;
  MCNUM verbose;
  /* Component type 'Filter_gen' private parameters */
  char  Mode_Table;
  char  Type_Table;
  t_Table  pTable;
}; /* _struct_Filter_gen_parameters */
typedef struct _struct_Filter_gen_parameters _class_Filter_gen_parameters;

/* Parameters for component type 'Filter_gen' */
struct _struct_Filter_gen {
  char     _name[256]; /* e.g. filter_gen */
  char     _type[256]; /* Filter_gen */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Filter_gen_parameters _parameters;
};
typedef struct _struct_Filter_gen _class_Filter_gen;
_class_Filter_gen _filter_gen_var;
#pragma acc declare create ( _filter_gen_var )

/* component BeFilter=PowderN() [46] DECLARE */
/* Parameter definition for component type 'PowderN' */
struct _struct_PowderN_parameters {
  /* Component type 'PowderN' setting parameters */
  char reflections[16384];
  char geometry[16384];
  MCNUM format[9];
  MCNUM radius;
  MCNUM yheight;
  MCNUM xwidth;
  MCNUM zdepth;
  MCNUM thickness;
  MCNUM pack;
  MCNUM Vc;
  MCNUM sigma_abs;
  MCNUM sigma_inc;
  MCNUM delta_d_d;
  MCNUM p_inc;
  MCNUM p_transmit;
  MCNUM DW;
  MCNUM nb_atoms;
  MCNUM d_omega;
  MCNUM d_phi;
  MCNUM tth_sign;
  MCNUM p_interact;
  MCNUM concentric;
  MCNUM density;
  MCNUM weight;
  MCNUM barns;
  MCNUM Strain;
  MCNUM focus_flip;
  int target_index;
  int order;
  /* Component type 'PowderN' private parameters */
  struct line_info_struct  line_info;
  double*  columns;
  off_struct  offdata;
  double  tgt_x;
  double  tgt_y;
  double  tgt_z;
}; /* _struct_PowderN_parameters */
typedef struct _struct_PowderN_parameters _class_PowderN_parameters;

/* Parameters for component type 'PowderN' */
struct _struct_PowderN {
  char     _name[256]; /* e.g. BeFilter */
  char     _type[256]; /* PowderN */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_PowderN_parameters _parameters;
};
typedef struct _struct_PowderN _class_PowderN;
_class_PowderN _BeFilter_var;
#pragma acc declare create ( _BeFilter_var )

int mcNUMCOMP = 46;

/* User declarations from instrument definition. Can define functions. */
int raw_scattered;
double slitwidth=0.3;
double slitheight=0.5;
double guide_start=1.5411;
double smallaxis_x_factor5=0.001019;
double smallaxis_y_factor5=0.00193;
double startx5=0.034973;
double starty5=0.11782;
double smallaxis_x_factor3=0.0012272;
double smallaxis_y_factor3=0.11055;
double startx3=0.070026;
double starty3=0.14691;
double lengthfrac2=0.35765;
double smallaxis_x_factor1=0.16453;
double smallaxis_y_factor1=0.093264;
double startx1=0.051571;
double starty1=0.14841;
double length1=13.2556;
double sizeX=0.03;
double sizeY=0.05;
double divreq_x=2;
double divreq_y=2;
double sample_dist=0.03;
double mod_x=0.08;
double mod_y=0.135;
double minimalist_factor=1;
double Mod_sample=35.6;
double closest_element=1.5;
double length4=0.13;
double length5=4.6;
double minlength1=6;
double minlength3=1;
double minlength5=1;
double R05=0.99;
double Qc5=0.0217;
double alpha5=6.07;
double m5=3.5;
double W5=0.003;
double max_smallaxis_x5=0.25;
double max_smallaxis_y5=0.25;
double R03=0.99;
double Qc3=0.0217;
double alpha3=6.07;
double m3=3.5;
double W3=0.003;
double max_smallaxis_x3=0.25;
double max_smallaxis_y3=0.25;
double R02=0.99;
double Qc2=0.0217;
double alpha2=6.07;
double m2=6;
double W2=0.003;
double channels2=1;
double R01=0.99;
double Qc1=0.0217;
double alpha1=6.07;
double m1=3.5;
double W1=0.003;
double max_smallaxis_x1=0.25;
double max_smallaxis_y1=0.25;
double WaveMin=1;
double WaveMax=10;
/********************************************************************************************/
double thetaA1;
double thetaA2;
double R_mono;
double lmin;
double lmax;
/********************************************************************************************/
double u;
double Lambda0;
double dLambda;
double var_divreq_x;
double var_divreq_y;
double x_div;
double y_div;
double startxpoint[8][3][3];
double startypoint[8][3][3];
double startXdirec[8][3];
double startYdirec[8][3];
double startXposition[8][3];
double startYposition[8][3];
double dist;
double position;
double focus_e;
double elength;
double width;
double height;
double curve_small_radius2;
double curveXcenter2[3];
double DeltaA2;
double DeltaB2;
double sinrot3;
double cosrot3;
double rot_factor_g2;
double X1[5];
double X2[5];
double Z1[5];
double Z2[5];
double a[5];
double b[5];
double tmp_double;
double dx_circ;
double dy_circ;
double dr_circ;
double D_circ;
double x1_circ;
double x2_circ;
double y1_circ;
double y2_circ;
double sign_dy;
double k_circ;
double x_solution[2];
double y_solution[2];
double smallaxis_x5;
double smallaxis_y5;
double Linx5;
double Liny5;
double Loutx5;
double Louty5;
double tmp_k;
double tmp_L1;
double tmp_L2;
double tmp_c;
double tmp_b;
double tmp_w1;
double tmp_w2;
double tmp_L;
double endx5;
double endy5;
double endPoint5;
double startx4;
double starty4;
double endx4;
double endy4;
double endPoint4;
double smallaxis_x3;
double smallaxis_y3;
double Linx3;
double Liny3;
double Loutx3;
double Louty3;
double endx3;
double endy3;
double length3;
double minlengthneeded;
double tmp_length;
double endPoint3;
double startx2;
double starty2;
double endx2;
double endy2;
double curve_radius2;
double rot2;
double var_divreq_x_protected;
double var_divreq_y_protected;
double length2;
double endPoint2;
double smallaxis_x1;
double smallaxis_y1;
double Linx1;
double Liny1;
double Loutx1;
double Louty1;
double endx1;
double endy1;
double endPoint1;
double rot_factor_g2;
int flag;
int i;
int part;
int n_check;
int los_logic;
int n1;
int n2;
int line;
int los_tmp[5];
int n_check;
int los_logic;
int los_check;
int ii;
int los_logic_single[7][8];
FILE *fp;
int scat = 0;
// Filter parameters 
double OUTFILTER_THICK;

// Analyser material parameters
double ana_mosaic_h;
double ana_mosaic_v;
double ana_q = 1.87325;
double ana_r0 = 0.8; 
double DA;    // d-spacing analyser
//Analyser geometrical parameters 
double ana_l[9];
//double ana_w=0.01;

// Declarations for 'Coarse Collimator' at the PSD detector surface 
int EntrySlit;
int ExitSlit;
int AnaBlade;
double BladeThickness = 0.0001;// detector coll after 2006, from drawings
double WindowSize = 0.025;
double BladeLength = 0.179;// detector coll after 2006, from drawings
double BladeHeight = 0.272;// detector coll after 2006, from drawings
double FirstWindowSizeL;
double FirstWindowSizeR;
double deltaL;
int coarse;

// Analyzer positions
double z_an1[8];
double y_an1[8];
double thet_an1[8];
int Ana1=0;
double z_an2[8];
double y_an2[8];
double thet_an2[8];
int Ana2=0;
double z_an3[8];
double y_an3[8];
double thet_an3[8];
int Ana3=0;

double z_an4[8];
double y_an4[8];
double thet_an4[8];
int Ana4=0;

double z_an5[8];
double y_an5[8];
double thet_an5[8];
int Ana5=0;

double z_an6[8];
double y_an6[8];
double thet_an6[8];
int Ana6=0;

double z_an7[8];
double y_an7[8];
double thet_an7[8];
int Ana7=0;

double z_an8[8];
double y_an8[8];
double thet_an8[8];
int Ana8=0;

// Detector parameters 
double ang_1[8];
double ang_2[8];
double detx_1[8];
double detz_1[8];
double detx_2[8];
double detz_2[8];
double dety_1;
double dety_2;
double det_cen;
int i;

double A3_val;
double A4_val;
double sourceDivergence;

double ANA_MOS_H=60;
double ANA_MOS_V=60;
double AW1=0.012;
double AW2=0.012;
double AW3=0.0125;
double AW4=0.013;
double AW5=0.0135;
double AW6=0.014;
double AW7=0.015;
double AW8=0.016;
double RADCOL_height=0.2;
double RADCOL_length=0.3;
double RADCOL_chan=20;
double RADCOL_radius=0.55;
double RADCOL_foilthick=0.0003;
double RADCOL_thetamin=-5;
double RADCOL_thetamax=5;
int RADCOL_flag=1;
int OUTFILTER=1;

double DET_cen=1.2;
double DET_rad=0.0063;
double DET_len=1;
double ana_l_add=0;

int REP=1;
int VIRTUALOUT=0;
int VIRTUALIN=0;
int verbose=0;

double mvle2[22]; // m values ellipse 2 left
double mvre2[22]; // right
double mvte2[22]; // top
double mvbe2[22]; // bottom
double sle2[22];


double mvlre3a[7]; // m values ellipse 3 left+r
double mvlre3b[20]; // m values ellipse 3 left+r
double mvtbe3a[7]; // t + b
double mvtbe3b[20]; // t + b
double sle3a[7];
double sle3b[20];

double mvinsertlr[5];
double mvinserttb[5];
double slinsert[5];

double RV_mono;
double RH_mono;


#undef compcurname
#undef compcurtype
#undef compcurindex
/* end of instrument 'PSI_CAMEA' and components DECLARE */

/* *****************************************************************************
* instrument 'PSI_CAMEA' and components INITIALISE
***************************************************************************** */

double index_getdistance(int first_index, int second_index)
/* Calculate the distance two components from their indexes*/
{
  return coords_len(coords_sub(POS_A_COMP_INDEX(first_index), POS_A_COMP_INDEX(second_index)));
}

double getdistance(char* first_component, char* second_component)
/* Calculate the distance between two named components */
{
  int first_index = _getcomp_index(first_component);
  int second_index = _getcomp_index(second_component);
  return index_getdistance(first_index, second_index);
}

double checked_setpos_getdistance(int current_index, char* first_component, char* second_component)
/* Calculate the distance between two named components at *_setpos() time, with component index checking */
{
  int first_index = _getcomp_index(first_component);
  int second_index = _getcomp_index(second_component);
  if (first_index >= current_index || second_index >= current_index) {
    printf("setpos_getdistance can only be used with the names of components before the current one!\n");
    return 0;
  }
  return index_getdistance(first_index, second_index);
}
#define setpos_getdistance(first, second) checked_setpos_getdistance(current_setpos_index, first, second)

/* component Origin=Progress_bar() SETTING, POSITION/ROTATION */
int _Origin_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_Origin_setpos] component Origin=Progress_bar() SETTING [Progress_bar:0]");
  stracpy(_Origin_var._name, "Origin", 16384);
  stracpy(_Origin_var._type, "Progress_bar", 16384);
  _Origin_var._index=1;
  int current_setpos_index = 1;
  if("NULL" && strlen("NULL"))
    stracpy(_Origin_var._parameters.profile, "NULL" ? "NULL" : "", 16384);
  else 
  _Origin_var._parameters.profile[0]='\0';
  _Origin_var._parameters.percent = 10;
  _Origin_var._parameters.flag_save = 0;
  _Origin_var._parameters.minutes = 0;


  /* component Origin=Progress_bar() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(_Origin_var._rotation_absolute,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_copy(_Origin_var._rotation_relative, _Origin_var._rotation_absolute);
    _Origin_var._rotation_is_identity =  rot_test_identity(_Origin_var._rotation_relative);
    _Origin_var._position_absolute = coords_set(
      0, 0, 0);
    tc1 = coords_neg(_Origin_var._position_absolute);
    _Origin_var._position_relative = rot_apply(_Origin_var._rotation_absolute, tc1);
  } /* Origin=Progress_bar() AT ROTATED */
  DEBUG_COMPONENT("Origin", _Origin_var._position_absolute, _Origin_var._rotation_absolute);
  instrument->_position_absolute[1] = _Origin_var._position_absolute;
  instrument->_position_relative[1] = _Origin_var._position_relative;
    _Origin_var._position_relative_is_zero =  coords_test_zero(_Origin_var._position_relative);
  instrument->counter_N[1]  = instrument->counter_P[1] = instrument->counter_P2[1] = 0;
  instrument->counter_AbsorbProp[1]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0000_Origin", _Origin_var._position_absolute, _Origin_var._rotation_absolute, "Progress_bar");
        mccomp_param_nexus(nxhandle,"0000_Origin", "profile", "NULL", "NULL", "char*");
        mccomp_param_nexus(nxhandle,"0000_Origin", "percent", "10", "10","MCNUM");
        mccomp_param_nexus(nxhandle,"0000_Origin", "flag_save", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0000_Origin", "minutes", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _Origin_setpos */

/* component source=Source_gen4() SETTING, POSITION/ROTATION */
int _source_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_source_setpos] component source=Source_gen4() SETTING [Source_gen4:0]");
  stracpy(_source_var._name, "source", 16384);
  stracpy(_source_var._type, "Source_gen4", 16384);
  _source_var._index=2;
  int current_setpos_index = 2;
  _source_var._parameters.flux_file[0]='\0';
  _source_var._parameters.xdiv_file[0]='\0';
  _source_var._parameters.ydiv_file[0]='\0';
  _source_var._parameters.radius = 0.0;
  _source_var._parameters.dist = guide_start;
  _source_var._parameters.xw = 0.036;
  _source_var._parameters.yh = 0.1186;
  _source_var._parameters.E0 = 0;
  _source_var._parameters.dE = 0;
  _source_var._parameters.Lambda0 = 0;
  _source_var._parameters.dLambda = 0;
  _source_var._parameters.I1 = ( 1.27e13 / 4 / PI );
  _source_var._parameters.h = 0.135;
  _source_var._parameters.w = 0.08;
  _source_var._parameters.gaussian = 0;
  _source_var._parameters.verbose = 0;
  _source_var._parameters.T1 = 301.287;
  _source_var._parameters.flux_file_perAA = 0;
  _source_var._parameters.flux_file_log = 0;
  _source_var._parameters.Lmin = lmin;
  _source_var._parameters.Lmax = lmax;
  _source_var._parameters.Emin = 0;
  _source_var._parameters.Emax = 0;
  _source_var._parameters.T2 = 105.655;
  _source_var._parameters.I2 = ( 3.818e12 / 4 / PI );
  _source_var._parameters.T3 = 25.379;
  _source_var._parameters.I3 = ( 2.331e12 / 4 / PI );
  _source_var._parameters.length = 0;
  _source_var._parameters.phi_init = 0;
  _source_var._parameters.theta_init = 0;
  _source_var._parameters.HEtailA = 8.306e11 / 4 / PI;
  _source_var._parameters.HEtailL0 = -0.398;


  /* component source=Source_gen4() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _source_var._rotation_absolute);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    rot_mul(_source_var._rotation_absolute, tr1, _source_var._rotation_relative);
    _source_var._rotation_is_identity =  rot_test_identity(_source_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _source_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_Origin_var._position_absolute, _source_var._position_absolute);
    _source_var._position_relative = rot_apply(_source_var._rotation_absolute, tc1);
  } /* source=Source_gen4() AT ROTATED */
  DEBUG_COMPONENT("source", _source_var._position_absolute, _source_var._rotation_absolute);
  instrument->_position_absolute[2] = _source_var._position_absolute;
  instrument->_position_relative[2] = _source_var._position_relative;
    _source_var._position_relative_is_zero =  coords_test_zero(_source_var._position_relative);
  instrument->counter_N[2]  = instrument->counter_P[2] = instrument->counter_P2[2] = 0;
  instrument->counter_AbsorbProp[2]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0001_source", _source_var._position_absolute, _source_var._rotation_absolute, "Source_gen4");
        mccomp_param_nexus(nxhandle,"0001_source", "flux_file", 0, 0, "char*");
        mccomp_param_nexus(nxhandle,"0001_source", "xdiv_file", 0, 0, "char*");
        mccomp_param_nexus(nxhandle,"0001_source", "ydiv_file", 0, 0, "char*");
        mccomp_param_nexus(nxhandle,"0001_source", "radius", "0.0", "0.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "dist", "0", "guide_start","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "xw", "0", "0.036","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "yh", "0", "0.1186","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "E0", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "dE", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "Lambda0", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "dLambda", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "I1", "0", "( 1.27e13 / 4 / PI )","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "h", "0", "0.135","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "w", "0", "0.08","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "gaussian", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "verbose", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "T1", "0", "301.287","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "flux_file_perAA", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "flux_file_log", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "Lmin", "0", "lmin","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "Lmax", "0", "lmax","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "Emin", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "Emax", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "T2", "0", "105.655","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "I2", "0", "( 3.818e12 / 4 / PI )","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "T3", "0", "25.379","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "I3", "0", "( 2.331e12 / 4 / PI )","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "length", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "phi_init", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "theta_init", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "HEtailA", "0", "8.306e11 / 4 / PI","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "HEtailL0", "0", "-0.398","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _source_setpos */

/* component StartOfGuideMonitor=PSD_monitor() SETTING, POSITION/ROTATION */
int _StartOfGuideMonitor_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_StartOfGuideMonitor_setpos] component StartOfGuideMonitor=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_StartOfGuideMonitor_var._name, "StartOfGuideMonitor", 16384);
  stracpy(_StartOfGuideMonitor_var._type, "PSD_monitor", 16384);
  _StartOfGuideMonitor_var._index=3;
  int current_setpos_index = 3;
  _StartOfGuideMonitor_var._parameters.nx = 100;
  _StartOfGuideMonitor_var._parameters.ny = 100;
  if("startOfGuide.dat" && strlen("startOfGuide.dat"))
    stracpy(_StartOfGuideMonitor_var._parameters.filename, "startOfGuide.dat" ? "startOfGuide.dat" : "", 16384);
  else 
  _StartOfGuideMonitor_var._parameters.filename[0]='\0';
  _StartOfGuideMonitor_var._parameters.xmin = -0.05;
  _StartOfGuideMonitor_var._parameters.xmax = 0.05;
  _StartOfGuideMonitor_var._parameters.ymin = -0.05;
  _StartOfGuideMonitor_var._parameters.ymax = 0.05;
  _StartOfGuideMonitor_var._parameters.xwidth = 0.2;
  _StartOfGuideMonitor_var._parameters.yheight = 0.2;
  _StartOfGuideMonitor_var._parameters.restore_neutron = 0;
  _StartOfGuideMonitor_var._parameters.nowritefile = 0;


  /* component StartOfGuideMonitor=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _source_var._rotation_absolute, _StartOfGuideMonitor_var._rotation_absolute);
    rot_transpose(_source_var._rotation_absolute, tr1);
    rot_mul(_StartOfGuideMonitor_var._rotation_absolute, tr1, _StartOfGuideMonitor_var._rotation_relative);
    _StartOfGuideMonitor_var._rotation_is_identity =  rot_test_identity(_StartOfGuideMonitor_var._rotation_relative);
    tc1 = coords_set(
      0, 0, u);
    rot_transpose(_source_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _StartOfGuideMonitor_var._position_absolute = coords_add(_source_var._position_absolute, tc2);
    tc1 = coords_sub(_source_var._position_absolute, _StartOfGuideMonitor_var._position_absolute);
    _StartOfGuideMonitor_var._position_relative = rot_apply(_StartOfGuideMonitor_var._rotation_absolute, tc1);
  } /* StartOfGuideMonitor=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("StartOfGuideMonitor", _StartOfGuideMonitor_var._position_absolute, _StartOfGuideMonitor_var._rotation_absolute);
  instrument->_position_absolute[3] = _StartOfGuideMonitor_var._position_absolute;
  instrument->_position_relative[3] = _StartOfGuideMonitor_var._position_relative;
    _StartOfGuideMonitor_var._position_relative_is_zero =  coords_test_zero(_StartOfGuideMonitor_var._position_relative);
  instrument->counter_N[3]  = instrument->counter_P[3] = instrument->counter_P2[3] = 0;
  instrument->counter_AbsorbProp[3]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0002_StartOfGuideMonitor", _StartOfGuideMonitor_var._position_absolute, _StartOfGuideMonitor_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0002_StartOfGuideMonitor", "nx", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0002_StartOfGuideMonitor", "ny", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0002_StartOfGuideMonitor", "filename", 0, "startOfGuide.dat", "char*");
        mccomp_param_nexus(nxhandle,"0002_StartOfGuideMonitor", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_StartOfGuideMonitor", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_StartOfGuideMonitor", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_StartOfGuideMonitor", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_StartOfGuideMonitor", "xwidth", "0", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_StartOfGuideMonitor", "yheight", "0", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_StartOfGuideMonitor", "restore_neutron", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0002_StartOfGuideMonitor", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _StartOfGuideMonitor_setpos */

/* component StartOfGuide=Arm() SETTING, POSITION/ROTATION */
int _StartOfGuide_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_StartOfGuide_setpos] component StartOfGuide=Arm() SETTING [Arm:0]");
  stracpy(_StartOfGuide_var._name, "StartOfGuide", 16384);
  stracpy(_StartOfGuide_var._type, "Arm", 16384);
  _StartOfGuide_var._index=4;
  int current_setpos_index = 4;
  /* component StartOfGuide=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _source_var._rotation_absolute, _StartOfGuide_var._rotation_absolute);
    rot_transpose(_StartOfGuideMonitor_var._rotation_absolute, tr1);
    rot_mul(_StartOfGuide_var._rotation_absolute, tr1, _StartOfGuide_var._rotation_relative);
    _StartOfGuide_var._rotation_is_identity =  rot_test_identity(_StartOfGuide_var._rotation_relative);
    tc1 = coords_set(
      0, 0, guide_start);
    rot_transpose(_source_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _StartOfGuide_var._position_absolute = coords_add(_source_var._position_absolute, tc2);
    tc1 = coords_sub(_StartOfGuideMonitor_var._position_absolute, _StartOfGuide_var._position_absolute);
    _StartOfGuide_var._position_relative = rot_apply(_StartOfGuide_var._rotation_absolute, tc1);
  } /* StartOfGuide=Arm() AT ROTATED */
  DEBUG_COMPONENT("StartOfGuide", _StartOfGuide_var._position_absolute, _StartOfGuide_var._rotation_absolute);
  instrument->_position_absolute[4] = _StartOfGuide_var._position_absolute;
  instrument->_position_relative[4] = _StartOfGuide_var._position_relative;
    _StartOfGuide_var._position_relative_is_zero =  coords_test_zero(_StartOfGuide_var._position_relative);
  instrument->counter_N[4]  = instrument->counter_P[4] = instrument->counter_P2[4] = 0;
  instrument->counter_AbsorbProp[4]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0003_StartOfGuide", _StartOfGuide_var._position_absolute, _StartOfGuide_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _StartOfGuide_setpos */

/* component Insert=Elliptic_guide_gravity() SETTING, POSITION/ROTATION */
int _Insert_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_Insert_setpos] component Insert=Elliptic_guide_gravity() SETTING [Elliptic_guide_gravity:0]");
  stracpy(_Insert_var._name, "Insert", 16384);
  stracpy(_Insert_var._type, "Elliptic_guide_gravity", 16384);
  _Insert_var._index=5;
  int current_setpos_index = 5;
  _Insert_var._parameters.xwidth = 0.036;
  _Insert_var._parameters.yheight = 0.1186;
  _Insert_var._parameters.l = 4.6348 - u;
  _Insert_var._parameters.linxw = 0.6699389077311009;
  _Insert_var._parameters.loutxw = 5.3047389;
  _Insert_var._parameters.linyh = 2.92407228;
  _Insert_var._parameters.loutyh = 7.5588722867;
  _Insert_var._parameters.majorAxisxw = 0;
  _Insert_var._parameters.minorAxisxw = 0;
  _Insert_var._parameters.majorAxisyh = 0;
  _Insert_var._parameters.minorAxisyh = 0;
  _Insert_var._parameters.majorAxisoffsetxw = 0;
  _Insert_var._parameters.majorAxisoffsetyh = 0;
  if("entrance" && strlen("entrance"))
    stracpy(_Insert_var._parameters.dimensionsAt, "entrance" ? "entrance" : "", 16384);
  else 
  _Insert_var._parameters.dimensionsAt[0]='\0';
  if("ellipse" && strlen("ellipse"))
    stracpy(_Insert_var._parameters.option, "ellipse" ? "ellipse" : "", 16384);
  else 
  _Insert_var._parameters.option[0]='\0';
  _Insert_var._parameters.R0 = 0.99;
  _Insert_var._parameters.Qc = 0.0218;
  _Insert_var._parameters.alpha = 6.07;
  _Insert_var._parameters.m = 2;
  _Insert_var._parameters.W = 0.003;
  _Insert_var._parameters.alpharight = -1;
  _Insert_var._parameters.mright = -1;
  _Insert_var._parameters.alphaleft = -1;
  _Insert_var._parameters.mleft = -1;
  _Insert_var._parameters.alphatop = -1;
  _Insert_var._parameters.mtop = -1;
  _Insert_var._parameters.alphabottom = -1;
  _Insert_var._parameters.mbottom = -1;
  if("on" && strlen("on"))
    stracpy(_Insert_var._parameters.verbose, "on" ? "on" : "", 16384);
  else 
  _Insert_var._parameters.verbose[0]='\0';
  _Insert_var._parameters.enableGravity = 1.0;
  _Insert_var._parameters.curvature = 0;
  _Insert_var._parameters.nSegments = 5;
  _Insert_var._parameters.mvaluesright = mvinsertlr; // default pointer allocation
  _Insert_var._parameters.mvaluesleft = mvinsertlr; // default pointer allocation
  _Insert_var._parameters.mvaluestop = mvinserttb; // default pointer allocation
  _Insert_var._parameters.mvaluesbottom = mvinserttb; // default pointer allocation
  _Insert_var._parameters.seglength = slinsert; // default pointer allocation


  /* component Insert=Elliptic_guide_gravity() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _Insert_var._rotation_absolute);
    rot_transpose(_StartOfGuideMonitor_var._rotation_absolute, tr1);
    rot_mul(_Insert_var._rotation_absolute, tr1, _Insert_var._rotation_relative);
    _Insert_var._rotation_is_identity =  rot_test_identity(_Insert_var._rotation_relative);
    tc1 = coords_set(
      0, 0, guide_start);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _Insert_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_StartOfGuideMonitor_var._position_absolute, _Insert_var._position_absolute);
    _Insert_var._position_relative = rot_apply(_Insert_var._rotation_absolute, tc1);
  } /* Insert=Elliptic_guide_gravity() AT ROTATED */
  DEBUG_COMPONENT("Insert", _Insert_var._position_absolute, _Insert_var._rotation_absolute);
  instrument->_position_absolute[5] = _Insert_var._position_absolute;
  instrument->_position_relative[5] = _Insert_var._position_relative;
    _Insert_var._position_relative_is_zero =  coords_test_zero(_Insert_var._position_relative);
  instrument->counter_N[5]  = instrument->counter_P[5] = instrument->counter_P2[5] = 0;
  instrument->counter_AbsorbProp[5]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0004_Insert", _Insert_var._position_absolute, _Insert_var._rotation_absolute, "Elliptic_guide_gravity");
        mccomp_param_nexus(nxhandle,"0004_Insert", "xwidth", "0", "0.036","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "yheight", "0", "0.1186","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "l", "NONE", "4.6348 - u","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "linxw", "0", "0.6699389077311009","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "loutxw", "0", "5.3047389","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "linyh", "0", "2.92407228","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "loutyh", "0", "7.5588722867","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "majorAxisxw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "minorAxisxw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "majorAxisyh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "minorAxisyh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "majorAxisoffsetxw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "majorAxisoffsetyh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "dimensionsAt", "entrance", "entrance", "char*");
        mccomp_param_nexus(nxhandle,"0004_Insert", "option", "ellipse", "ellipse", "char*");
        mccomp_param_nexus(nxhandle,"0004_Insert", "R0", "0.99", "0.99","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "Qc", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "alpha", "6.07", "6.07","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "m", "2", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "W", "0.003", "0.003","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "alpharight", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "mright", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "alphaleft", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "mleft", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "alphatop", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "mtop", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "alphabottom", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "mbottom", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "verbose", "on", "on", "char*");
        mccomp_param_nexus(nxhandle,"0004_Insert", "enableGravity", "1.0", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "curvature", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "nSegments", "-1", "5","int");
        mccomp_param_nexus(nxhandle,"0004_Insert", "mvaluesright", "NULL", "mvinsertlr","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "mvaluesleft", "NULL", "mvinsertlr","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "mvaluestop", "NULL", "mvinserttb","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "mvaluesbottom", "NULL", "mvinserttb","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_Insert", "seglength", "NULL", "slinsert","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _Insert_setpos */

/* component EndOfInsertPSD=PSD_monitor() SETTING, POSITION/ROTATION */
int _EndOfInsertPSD_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_EndOfInsertPSD_setpos] component EndOfInsertPSD=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_EndOfInsertPSD_var._name, "EndOfInsertPSD", 16384);
  stracpy(_EndOfInsertPSD_var._type, "PSD_monitor", 16384);
  _EndOfInsertPSD_var._index=6;
  int current_setpos_index = 6;
  _EndOfInsertPSD_var._parameters.nx = 100;
  _EndOfInsertPSD_var._parameters.ny = 100;
  if("EndOfInsertPSD.dat" && strlen("EndOfInsertPSD.dat"))
    stracpy(_EndOfInsertPSD_var._parameters.filename, "EndOfInsertPSD.dat" ? "EndOfInsertPSD.dat" : "", 16384);
  else 
  _EndOfInsertPSD_var._parameters.filename[0]='\0';
  _EndOfInsertPSD_var._parameters.xmin = -0.05;
  _EndOfInsertPSD_var._parameters.xmax = 0.05;
  _EndOfInsertPSD_var._parameters.ymin = -0.05;
  _EndOfInsertPSD_var._parameters.ymax = 0.05;
  _EndOfInsertPSD_var._parameters.xwidth = 0.2;
  _EndOfInsertPSD_var._parameters.yheight = 0.2;
  _EndOfInsertPSD_var._parameters.restore_neutron = 0;
  _EndOfInsertPSD_var._parameters.nowritefile = 0;


  /* component EndOfInsertPSD=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Insert_var._rotation_absolute, _EndOfInsertPSD_var._rotation_absolute);
    rot_transpose(_Insert_var._rotation_absolute, tr1);
    rot_mul(_EndOfInsertPSD_var._rotation_absolute, tr1, _EndOfInsertPSD_var._rotation_relative);
    _EndOfInsertPSD_var._rotation_is_identity =  rot_test_identity(_EndOfInsertPSD_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 4.6348 + u);
    rot_transpose(_Insert_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _EndOfInsertPSD_var._position_absolute = coords_add(_Insert_var._position_absolute, tc2);
    tc1 = coords_sub(_Insert_var._position_absolute, _EndOfInsertPSD_var._position_absolute);
    _EndOfInsertPSD_var._position_relative = rot_apply(_EndOfInsertPSD_var._rotation_absolute, tc1);
  } /* EndOfInsertPSD=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("EndOfInsertPSD", _EndOfInsertPSD_var._position_absolute, _EndOfInsertPSD_var._rotation_absolute);
  instrument->_position_absolute[6] = _EndOfInsertPSD_var._position_absolute;
  instrument->_position_relative[6] = _EndOfInsertPSD_var._position_relative;
    _EndOfInsertPSD_var._position_relative_is_zero =  coords_test_zero(_EndOfInsertPSD_var._position_relative);
  instrument->counter_N[6]  = instrument->counter_P[6] = instrument->counter_P2[6] = 0;
  instrument->counter_AbsorbProp[6]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0005_EndOfInsertPSD", _EndOfInsertPSD_var._position_absolute, _EndOfInsertPSD_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0005_EndOfInsertPSD", "nx", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0005_EndOfInsertPSD", "ny", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0005_EndOfInsertPSD", "filename", 0, "EndOfInsertPSD.dat", "char*");
        mccomp_param_nexus(nxhandle,"0005_EndOfInsertPSD", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_EndOfInsertPSD", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_EndOfInsertPSD", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_EndOfInsertPSD", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_EndOfInsertPSD", "xwidth", "0", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_EndOfInsertPSD", "yheight", "0", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_EndOfInsertPSD", "restore_neutron", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0005_EndOfInsertPSD", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _EndOfInsertPSD_setpos */

/* component E2=Elliptic_guide_gravity() SETTING, POSITION/ROTATION */
int _E2_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_E2_setpos] component E2=Elliptic_guide_gravity() SETTING [Elliptic_guide_gravity:0]");
  stracpy(_E2_var._name, "E2", 16384);
  stracpy(_E2_var._type, "Elliptic_guide_gravity", 16384);
  _E2_var._index=7;
  int current_setpos_index = 7;
  _E2_var._parameters.xwidth = 0.074;
  _E2_var._parameters.yheight = 0.15013;
  _E2_var._parameters.l = 11.1155;
  _E2_var._parameters.linxw = 14.660035;
  _E2_var._parameters.loutxw = 4.242297;
  _E2_var._parameters.linyh = 24.8055792;
  _E2_var._parameters.loutyh = 35.9211793;
  _E2_var._parameters.majorAxisxw = 0;
  _E2_var._parameters.minorAxisxw = 0;
  _E2_var._parameters.majorAxisyh = 0;
  _E2_var._parameters.minorAxisyh = 0;
  _E2_var._parameters.majorAxisoffsetxw = 0;
  _E2_var._parameters.majorAxisoffsetyh = 0;
  if("entrance" && strlen("entrance"))
    stracpy(_E2_var._parameters.dimensionsAt, "entrance" ? "entrance" : "", 16384);
  else 
  _E2_var._parameters.dimensionsAt[0]='\0';
  if("ellipse" && strlen("ellipse"))
    stracpy(_E2_var._parameters.option, "ellipse" ? "ellipse" : "", 16384);
  else 
  _E2_var._parameters.option[0]='\0';
  _E2_var._parameters.R0 = 0.99;
  _E2_var._parameters.Qc = 0.0218;
  _E2_var._parameters.alpha = 6.07;
  _E2_var._parameters.m = 2;
  _E2_var._parameters.W = 0.003;
  _E2_var._parameters.alpharight = -1;
  _E2_var._parameters.mright = -1;
  _E2_var._parameters.alphaleft = -1;
  _E2_var._parameters.mleft = -1;
  _E2_var._parameters.alphatop = -1;
  _E2_var._parameters.mtop = -1;
  _E2_var._parameters.alphabottom = -1;
  _E2_var._parameters.mbottom = -1;
  if("on" && strlen("on"))
    stracpy(_E2_var._parameters.verbose, "on" ? "on" : "", 16384);
  else 
  _E2_var._parameters.verbose[0]='\0';
  _E2_var._parameters.enableGravity = 1.0;
  _E2_var._parameters.curvature = 0;
  _E2_var._parameters.nSegments = 22;
  _E2_var._parameters.mvaluesright = mvre2; // default pointer allocation
  _E2_var._parameters.mvaluesleft = mvle2; // default pointer allocation
  _E2_var._parameters.mvaluestop = mvte2; // default pointer allocation
  _E2_var._parameters.mvaluesbottom = mvbe2; // default pointer allocation
  _E2_var._parameters.seglength = sle2; // default pointer allocation


  /* component E2=Elliptic_guide_gravity() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _E2_var._rotation_absolute);
    rot_transpose(_EndOfInsertPSD_var._rotation_absolute, tr1);
    rot_mul(_E2_var._rotation_absolute, tr1, _E2_var._rotation_relative);
    _E2_var._rotation_is_identity =  rot_test_identity(_E2_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 6.1759 + u);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _E2_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_EndOfInsertPSD_var._position_absolute, _E2_var._position_absolute);
    _E2_var._position_relative = rot_apply(_E2_var._rotation_absolute, tc1);
  } /* E2=Elliptic_guide_gravity() AT ROTATED */
  DEBUG_COMPONENT("E2", _E2_var._position_absolute, _E2_var._rotation_absolute);
  instrument->_position_absolute[7] = _E2_var._position_absolute;
  instrument->_position_relative[7] = _E2_var._position_relative;
    _E2_var._position_relative_is_zero =  coords_test_zero(_E2_var._position_relative);
  instrument->counter_N[7]  = instrument->counter_P[7] = instrument->counter_P2[7] = 0;
  instrument->counter_AbsorbProp[7]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0006_E2", _E2_var._position_absolute, _E2_var._rotation_absolute, "Elliptic_guide_gravity");
        mccomp_param_nexus(nxhandle,"0006_E2", "xwidth", "0", "0.074","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "yheight", "0", "0.15013","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "l", "NONE", "11.1155","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "linxw", "0", "14.660035","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "loutxw", "0", "4.242297","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "linyh", "0", "24.8055792","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "loutyh", "0", "35.9211793","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "majorAxisxw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "minorAxisxw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "majorAxisyh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "minorAxisyh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "majorAxisoffsetxw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "majorAxisoffsetyh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "dimensionsAt", "entrance", "entrance", "char*");
        mccomp_param_nexus(nxhandle,"0006_E2", "option", "ellipse", "ellipse", "char*");
        mccomp_param_nexus(nxhandle,"0006_E2", "R0", "0.99", "0.99","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "Qc", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "alpha", "6.07", "6.07","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "m", "2", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "W", "0.003", "0.003","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "alpharight", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "mright", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "alphaleft", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "mleft", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "alphatop", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "mtop", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "alphabottom", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "mbottom", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "verbose", "on", "on", "char*");
        mccomp_param_nexus(nxhandle,"0006_E2", "enableGravity", "1.0", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "curvature", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "nSegments", "-1", "22","int");
        mccomp_param_nexus(nxhandle,"0006_E2", "mvaluesright", "NULL", "mvre2","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "mvaluesleft", "NULL", "mvle2","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "mvaluestop", "NULL", "mvte2","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "mvaluesbottom", "NULL", "mvbe2","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_E2", "seglength", "NULL", "sle2","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _E2_setpos */

/* component EndOfelement_5=Arm() SETTING, POSITION/ROTATION */
int _EndOfelement_5_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_EndOfelement_5_setpos] component EndOfelement_5=Arm() SETTING [Arm:0]");
  stracpy(_EndOfelement_5_var._name, "EndOfelement_5", 16384);
  stracpy(_EndOfelement_5_var._type, "Arm", 16384);
  _EndOfelement_5_var._index=8;
  int current_setpos_index = 8;
  /* component EndOfelement_5=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _E2_var._rotation_absolute, _EndOfelement_5_var._rotation_absolute);
    rot_transpose(_E2_var._rotation_absolute, tr1);
    rot_mul(_EndOfelement_5_var._rotation_absolute, tr1, _EndOfelement_5_var._rotation_relative);
    _EndOfelement_5_var._rotation_is_identity =  rot_test_identity(_EndOfelement_5_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 11.1155 + u);
    rot_transpose(_E2_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _EndOfelement_5_var._position_absolute = coords_add(_E2_var._position_absolute, tc2);
    tc1 = coords_sub(_E2_var._position_absolute, _EndOfelement_5_var._position_absolute);
    _EndOfelement_5_var._position_relative = rot_apply(_EndOfelement_5_var._rotation_absolute, tc1);
  } /* EndOfelement_5=Arm() AT ROTATED */
  DEBUG_COMPONENT("EndOfelement_5", _EndOfelement_5_var._position_absolute, _EndOfelement_5_var._rotation_absolute);
  instrument->_position_absolute[8] = _EndOfelement_5_var._position_absolute;
  instrument->_position_relative[8] = _EndOfelement_5_var._position_relative;
    _EndOfelement_5_var._position_relative_is_zero =  coords_test_zero(_EndOfelement_5_var._position_relative);
  instrument->counter_N[8]  = instrument->counter_P[8] = instrument->counter_P2[8] = 0;
  instrument->counter_AbsorbProp[8]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0007_EndOfelement_5", _EndOfelement_5_var._position_absolute, _EndOfelement_5_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _EndOfelement_5_setpos */

/* component E2PSD=PSD_monitor() SETTING, POSITION/ROTATION */
int _E2PSD_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_E2PSD_setpos] component E2PSD=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_E2PSD_var._name, "E2PSD", 16384);
  stracpy(_E2PSD_var._type, "PSD_monitor", 16384);
  _E2PSD_var._index=9;
  int current_setpos_index = 9;
  _E2PSD_var._parameters.nx = 100;
  _E2PSD_var._parameters.ny = 100;
  if("ExitE2.dat" && strlen("ExitE2.dat"))
    stracpy(_E2PSD_var._parameters.filename, "ExitE2.dat" ? "ExitE2.dat" : "", 16384);
  else 
  _E2PSD_var._parameters.filename[0]='\0';
  _E2PSD_var._parameters.xmin = -0.05;
  _E2PSD_var._parameters.xmax = 0.05;
  _E2PSD_var._parameters.ymin = -0.05;
  _E2PSD_var._parameters.ymax = 0.05;
  _E2PSD_var._parameters.xwidth = 0.2;
  _E2PSD_var._parameters.yheight = 0.2;
  _E2PSD_var._parameters.restore_neutron = 0;
  _E2PSD_var._parameters.nowritefile = 0;


  /* component E2PSD=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _EndOfelement_5_var._rotation_absolute, _E2PSD_var._rotation_absolute);
    rot_transpose(_E2_var._rotation_absolute, tr1);
    rot_mul(_E2PSD_var._rotation_absolute, tr1, _E2PSD_var._rotation_relative);
    _E2PSD_var._rotation_is_identity =  rot_test_identity(_E2PSD_var._rotation_relative);
    tc1 = coords_set(
      0, 0, u);
    rot_transpose(_EndOfelement_5_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _E2PSD_var._position_absolute = coords_add(_EndOfelement_5_var._position_absolute, tc2);
    tc1 = coords_sub(_E2_var._position_absolute, _E2PSD_var._position_absolute);
    _E2PSD_var._position_relative = rot_apply(_E2PSD_var._rotation_absolute, tc1);
  } /* E2PSD=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("E2PSD", _E2PSD_var._position_absolute, _E2PSD_var._rotation_absolute);
  instrument->_position_absolute[9] = _E2PSD_var._position_absolute;
  instrument->_position_relative[9] = _E2PSD_var._position_relative;
    _E2PSD_var._position_relative_is_zero =  coords_test_zero(_E2PSD_var._position_relative);
  instrument->counter_N[9]  = instrument->counter_P[9] = instrument->counter_P2[9] = 0;
  instrument->counter_AbsorbProp[9]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0008_E2PSD", _E2PSD_var._position_absolute, _E2PSD_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0008_E2PSD", "nx", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0008_E2PSD", "ny", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0008_E2PSD", "filename", 0, "ExitE2.dat", "char*");
        mccomp_param_nexus(nxhandle,"0008_E2PSD", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_E2PSD", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_E2PSD", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_E2PSD", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_E2PSD", "xwidth", "0", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_E2PSD", "yheight", "0", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_E2PSD", "restore_neutron", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0008_E2PSD", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _E2PSD_setpos */

/* component EndOfelement_4=Arm() SETTING, POSITION/ROTATION */
int _EndOfelement_4_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_EndOfelement_4_setpos] component EndOfelement_4=Arm() SETTING [Arm:0]");
  stracpy(_EndOfelement_4_var._name, "EndOfelement_4", 16384);
  stracpy(_EndOfelement_4_var._type, "Arm", 16384);
  _EndOfelement_4_var._index=10;
  int current_setpos_index = 10;
  /* component EndOfelement_4=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _E2PSD_var._rotation_absolute, _EndOfelement_4_var._rotation_absolute);
    rot_transpose(_E2PSD_var._rotation_absolute, tr1);
    rot_mul(_EndOfelement_4_var._rotation_absolute, tr1, _EndOfelement_4_var._rotation_relative);
    _EndOfelement_4_var._rotation_is_identity =  rot_test_identity(_EndOfelement_4_var._rotation_relative);
    tc1 = coords_set(
      0, 0, u);
    rot_transpose(_E2PSD_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _EndOfelement_4_var._position_absolute = coords_add(_E2PSD_var._position_absolute, tc2);
    tc1 = coords_sub(_E2PSD_var._position_absolute, _EndOfelement_4_var._position_absolute);
    _EndOfelement_4_var._position_relative = rot_apply(_EndOfelement_4_var._rotation_absolute, tc1);
  } /* EndOfelement_4=Arm() AT ROTATED */
  DEBUG_COMPONENT("EndOfelement_4", _EndOfelement_4_var._position_absolute, _EndOfelement_4_var._rotation_absolute);
  instrument->_position_absolute[10] = _EndOfelement_4_var._position_absolute;
  instrument->_position_relative[10] = _EndOfelement_4_var._position_relative;
    _EndOfelement_4_var._position_relative_is_zero =  coords_test_zero(_EndOfelement_4_var._position_relative);
  instrument->counter_N[10]  = instrument->counter_P[10] = instrument->counter_P2[10] = 0;
  instrument->counter_AbsorbProp[10]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0009_EndOfelement_4", _EndOfelement_4_var._position_absolute, _EndOfelement_4_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _EndOfelement_4_setpos */

/* component C1=Bender() SETTING, POSITION/ROTATION */
int _C1_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_C1_setpos] component C1=Bender() SETTING [Bender:0]");
  stracpy(_C1_var._name, "C1", 16384);
  stracpy(_C1_var._type, "Bender", 16384);
  _C1_var._index=11;
  int current_setpos_index = 11;
  _C1_var._parameters.w = 0.05157;
  _C1_var._parameters.h = 0.157884;
  _C1_var._parameters.r = 500.123297;
  _C1_var._parameters.Win = 0.04;
  _C1_var._parameters.k = 1;
  _C1_var._parameters.d = 0.001;
  _C1_var._parameters.l = 5.022207;
  _C1_var._parameters.R0a = 0.99;
  _C1_var._parameters.Qca = 0.021;
  _C1_var._parameters.alphaa = 6.07;
  _C1_var._parameters.ma = 2;
  _C1_var._parameters.Wa = 0.003;
  _C1_var._parameters.R0i = 0.99;
  _C1_var._parameters.Qci = 0.021;
  _C1_var._parameters.alphai = 6.07;
  _C1_var._parameters.mi = 4.5;
  _C1_var._parameters.Wi = 0.003;
  _C1_var._parameters.R0s = 0.99;
  _C1_var._parameters.Qcs = 0.021;
  _C1_var._parameters.alphas = 6.07;
  _C1_var._parameters.ms = 2.5;
  _C1_var._parameters.Ws = 0.003;


  /* component C1=Bender() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _EndOfelement_4_var._rotation_absolute, _C1_var._rotation_absolute);
    rot_transpose(_E2PSD_var._rotation_absolute, tr1);
    rot_mul(_C1_var._rotation_absolute, tr1, _C1_var._rotation_relative);
    _C1_var._rotation_is_identity =  rot_test_identity(_C1_var._rotation_relative);
    tc1 = coords_set(
      0, 0, u);
    rot_transpose(_EndOfelement_4_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _C1_var._position_absolute = coords_add(_EndOfelement_4_var._position_absolute, tc2);
    tc1 = coords_sub(_E2PSD_var._position_absolute, _C1_var._position_absolute);
    _C1_var._position_relative = rot_apply(_C1_var._rotation_absolute, tc1);
  } /* C1=Bender() AT ROTATED */
  DEBUG_COMPONENT("C1", _C1_var._position_absolute, _C1_var._rotation_absolute);
  instrument->_position_absolute[11] = _C1_var._position_absolute;
  instrument->_position_relative[11] = _C1_var._position_relative;
    _C1_var._position_relative_is_zero =  coords_test_zero(_C1_var._position_relative);
  instrument->counter_N[11]  = instrument->counter_P[11] = instrument->counter_P2[11] = 0;
  instrument->counter_AbsorbProp[11]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0010_C1", _C1_var._position_absolute, _C1_var._rotation_absolute, "Bender");
        mccomp_param_nexus(nxhandle,"0010_C1", "w", "NONE", "0.05157","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "h", "NONE", "0.157884","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "r", "NONE", "500.123297","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "Win", "0.04", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "k", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "d", "0.001", "0.001","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "l", "0", "5.022207","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "R0a", "0.99", "0.99","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "Qca", "0.021", "0.021","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "alphaa", "6.07", "6.07","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "ma", "2", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "Wa", "0.003", "0.003","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "R0i", "0.99", "0.99","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "Qci", "0.021", "0.021","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "alphai", "6.07", "6.07","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "mi", "2", "4.5","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "Wi", "0.003", "0.003","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "R0s", "0.99", "0.99","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "Qcs", "0.021", "0.021","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "alphas", "6.07", "6.07","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "ms", "2", "2.5","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_C1", "Ws", "0.003", "0.003","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _C1_setpos */

/* component EndOfelement_2=Arm() SETTING, POSITION/ROTATION */
int _EndOfelement_2_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_EndOfelement_2_setpos] component EndOfelement_2=Arm() SETTING [Arm:0]");
  stracpy(_EndOfelement_2_var._name, "EndOfelement_2", 16384);
  stracpy(_EndOfelement_2_var._type, "Arm", 16384);
  _EndOfelement_2_var._index=12;
  int current_setpos_index = 12;
  /* component EndOfelement_2=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _C1_var._rotation_absolute, _EndOfelement_2_var._rotation_absolute);
    rot_transpose(_C1_var._rotation_absolute, tr1);
    rot_mul(_EndOfelement_2_var._rotation_absolute, tr1, _EndOfelement_2_var._rotation_relative);
    _EndOfelement_2_var._rotation_is_identity =  rot_test_identity(_EndOfelement_2_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 5.022207 + u);
    rot_transpose(_C1_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _EndOfelement_2_var._position_absolute = coords_add(_C1_var._position_absolute, tc2);
    tc1 = coords_sub(_C1_var._position_absolute, _EndOfelement_2_var._position_absolute);
    _EndOfelement_2_var._position_relative = rot_apply(_EndOfelement_2_var._rotation_absolute, tc1);
  } /* EndOfelement_2=Arm() AT ROTATED */
  DEBUG_COMPONENT("EndOfelement_2", _EndOfelement_2_var._position_absolute, _EndOfelement_2_var._rotation_absolute);
  instrument->_position_absolute[12] = _EndOfelement_2_var._position_absolute;
  instrument->_position_relative[12] = _EndOfelement_2_var._position_relative;
    _EndOfelement_2_var._position_relative_is_zero =  coords_test_zero(_EndOfelement_2_var._position_relative);
  instrument->counter_N[12]  = instrument->counter_P[12] = instrument->counter_P2[12] = 0;
  instrument->counter_AbsorbProp[12]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0011_EndOfelement_2", _EndOfelement_2_var._position_absolute, _EndOfelement_2_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _EndOfelement_2_setpos */

/* component C1End=PSD_monitor() SETTING, POSITION/ROTATION */
int _C1End_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_C1End_setpos] component C1End=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_C1End_var._name, "C1End", 16384);
  stracpy(_C1End_var._type, "PSD_monitor", 16384);
  _C1End_var._index=13;
  int current_setpos_index = 13;
  _C1End_var._parameters.nx = 100;
  _C1End_var._parameters.ny = 100;
  if("ExitC1.dat" && strlen("ExitC1.dat"))
    stracpy(_C1End_var._parameters.filename, "ExitC1.dat" ? "ExitC1.dat" : "", 16384);
  else 
  _C1End_var._parameters.filename[0]='\0';
  _C1End_var._parameters.xmin = -0.05;
  _C1End_var._parameters.xmax = 0.05;
  _C1End_var._parameters.ymin = -0.05;
  _C1End_var._parameters.ymax = 0.05;
  _C1End_var._parameters.xwidth = 0.2;
  _C1End_var._parameters.yheight = 0.2;
  _C1End_var._parameters.restore_neutron = 0;
  _C1End_var._parameters.nowritefile = 0;


  /* component C1End=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _EndOfelement_2_var._rotation_absolute, _C1End_var._rotation_absolute);
    rot_transpose(_C1_var._rotation_absolute, tr1);
    rot_mul(_C1End_var._rotation_absolute, tr1, _C1End_var._rotation_relative);
    _C1End_var._rotation_is_identity =  rot_test_identity(_C1End_var._rotation_relative);
    tc1 = coords_set(
      0, 0, u);
    rot_transpose(_EndOfelement_2_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _C1End_var._position_absolute = coords_add(_EndOfelement_2_var._position_absolute, tc2);
    tc1 = coords_sub(_C1_var._position_absolute, _C1End_var._position_absolute);
    _C1End_var._position_relative = rot_apply(_C1End_var._rotation_absolute, tc1);
  } /* C1End=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("C1End", _C1End_var._position_absolute, _C1End_var._rotation_absolute);
  instrument->_position_absolute[13] = _C1End_var._position_absolute;
  instrument->_position_relative[13] = _C1End_var._position_relative;
    _C1End_var._position_relative_is_zero =  coords_test_zero(_C1End_var._position_relative);
  instrument->counter_N[13]  = instrument->counter_P[13] = instrument->counter_P2[13] = 0;
  instrument->counter_AbsorbProp[13]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0012_C1End", _C1End_var._position_absolute, _C1End_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0012_C1End", "nx", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0012_C1End", "ny", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0012_C1End", "filename", 0, "ExitC1.dat", "char*");
        mccomp_param_nexus(nxhandle,"0012_C1End", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_C1End", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_C1End", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_C1End", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_C1End", "xwidth", "0", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_C1End", "yheight", "0", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_C1End", "restore_neutron", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0012_C1End", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _C1End_setpos */

/* component E3a=Elliptic_guide_gravity() SETTING, POSITION/ROTATION */
int _E3a_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_E3a_setpos] component E3a=Elliptic_guide_gravity() SETTING [Elliptic_guide_gravity:0]");
  stracpy(_E3a_var._name, "E3a", 16384);
  stracpy(_E3a_var._type, "Elliptic_guide_gravity", 16384);
  _E3a_var._index=14;
  int current_setpos_index = 14;
  _E3a_var._parameters.xwidth = 0.051569;
  _E3a_var._parameters.yheight = 0.157884;
  _E3a_var._parameters.l = 3.5196154567641345;
  _E3a_var._parameters.linxw = 1.618094;
  _E3a_var._parameters.loutxw = 10.31937061296228;
  _E3a_var._parameters.linyh = 2000;
  _E3a_var._parameters.loutyh = 2000;
  _E3a_var._parameters.majorAxisxw = 0;
  _E3a_var._parameters.minorAxisxw = 0;
  _E3a_var._parameters.majorAxisyh = 0;
  _E3a_var._parameters.minorAxisyh = 0;
  _E3a_var._parameters.majorAxisoffsetxw = 0;
  _E3a_var._parameters.majorAxisoffsetyh = 0;
  if("entrance" && strlen("entrance"))
    stracpy(_E3a_var._parameters.dimensionsAt, "entrance" ? "entrance" : "", 16384);
  else 
  _E3a_var._parameters.dimensionsAt[0]='\0';
  if("ellipse" && strlen("ellipse"))
    stracpy(_E3a_var._parameters.option, "ellipse" ? "ellipse" : "", 16384);
  else 
  _E3a_var._parameters.option[0]='\0';
  _E3a_var._parameters.R0 = 0.99;
  _E3a_var._parameters.Qc = 0.0218;
  _E3a_var._parameters.alpha = 6.07;
  _E3a_var._parameters.m = 2;
  _E3a_var._parameters.W = 0.003;
  _E3a_var._parameters.alpharight = -1;
  _E3a_var._parameters.mright = -1;
  _E3a_var._parameters.alphaleft = -1;
  _E3a_var._parameters.mleft = -1;
  _E3a_var._parameters.alphatop = -1;
  _E3a_var._parameters.mtop = -1;
  _E3a_var._parameters.alphabottom = -1;
  _E3a_var._parameters.mbottom = -1;
  if("on" && strlen("on"))
    stracpy(_E3a_var._parameters.verbose, "on" ? "on" : "", 16384);
  else 
  _E3a_var._parameters.verbose[0]='\0';
  _E3a_var._parameters.enableGravity = 1.0;
  _E3a_var._parameters.curvature = 0;
  _E3a_var._parameters.nSegments = 7;
  _E3a_var._parameters.mvaluesright = mvlre3a; // default pointer allocation
  _E3a_var._parameters.mvaluesleft = mvlre3a; // default pointer allocation
  _E3a_var._parameters.mvaluestop = mvtbe3a; // default pointer allocation
  _E3a_var._parameters.mvaluesbottom = mvtbe3a; // default pointer allocation
  _E3a_var._parameters.seglength = sle3a; // default pointer allocation


  /* component E3a=Elliptic_guide_gravity() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _C1End_var._rotation_absolute, _E3a_var._rotation_absolute);
    rot_transpose(_C1End_var._rotation_absolute, tr1);
    rot_mul(_E3a_var._rotation_absolute, tr1, _E3a_var._rotation_relative);
    _E3a_var._rotation_is_identity =  rot_test_identity(_E3a_var._rotation_relative);
    tc1 = coords_set(
      0, 0, u);
    rot_transpose(_C1End_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _E3a_var._position_absolute = coords_add(_C1End_var._position_absolute, tc2);
    tc1 = coords_sub(_C1End_var._position_absolute, _E3a_var._position_absolute);
    _E3a_var._position_relative = rot_apply(_E3a_var._rotation_absolute, tc1);
  } /* E3a=Elliptic_guide_gravity() AT ROTATED */
  DEBUG_COMPONENT("E3a", _E3a_var._position_absolute, _E3a_var._rotation_absolute);
  instrument->_position_absolute[14] = _E3a_var._position_absolute;
  instrument->_position_relative[14] = _E3a_var._position_relative;
    _E3a_var._position_relative_is_zero =  coords_test_zero(_E3a_var._position_relative);
  instrument->counter_N[14]  = instrument->counter_P[14] = instrument->counter_P2[14] = 0;
  instrument->counter_AbsorbProp[14]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0013_E3a", _E3a_var._position_absolute, _E3a_var._rotation_absolute, "Elliptic_guide_gravity");
        mccomp_param_nexus(nxhandle,"0013_E3a", "xwidth", "0", "0.051569","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "yheight", "0", "0.157884","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "l", "NONE", "3.5196154567641345","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "linxw", "0", "1.618094","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "loutxw", "0", "10.31937061296228","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "linyh", "0", "2000","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "loutyh", "0", "2000","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "majorAxisxw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "minorAxisxw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "majorAxisyh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "minorAxisyh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "majorAxisoffsetxw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "majorAxisoffsetyh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "dimensionsAt", "entrance", "entrance", "char*");
        mccomp_param_nexus(nxhandle,"0013_E3a", "option", "ellipse", "ellipse", "char*");
        mccomp_param_nexus(nxhandle,"0013_E3a", "R0", "0.99", "0.99","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "Qc", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "alpha", "6.07", "6.07","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "m", "2", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "W", "0.003", "0.003","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "alpharight", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "mright", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "alphaleft", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "mleft", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "alphatop", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "mtop", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "alphabottom", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "mbottom", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "verbose", "on", "on", "char*");
        mccomp_param_nexus(nxhandle,"0013_E3a", "enableGravity", "1.0", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "curvature", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "nSegments", "-1", "7","int");
        mccomp_param_nexus(nxhandle,"0013_E3a", "mvaluesright", "NULL", "mvlre3a","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "mvaluesleft", "NULL", "mvlre3a","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "mvaluestop", "NULL", "mvtbe3a","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "mvaluesbottom", "NULL", "mvtbe3a","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_E3a", "seglength", "NULL", "sle3a","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _E3a_setpos */

/* component E3aEnd=PSD_monitor() SETTING, POSITION/ROTATION */
int _E3aEnd_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_E3aEnd_setpos] component E3aEnd=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_E3aEnd_var._name, "E3aEnd", 16384);
  stracpy(_E3aEnd_var._type, "PSD_monitor", 16384);
  _E3aEnd_var._index=15;
  int current_setpos_index = 15;
  _E3aEnd_var._parameters.nx = 100;
  _E3aEnd_var._parameters.ny = 100;
  if("ExitE3a.dat" && strlen("ExitE3a.dat"))
    stracpy(_E3aEnd_var._parameters.filename, "ExitE3a.dat" ? "ExitE3a.dat" : "", 16384);
  else 
  _E3aEnd_var._parameters.filename[0]='\0';
  _E3aEnd_var._parameters.xmin = -0.05;
  _E3aEnd_var._parameters.xmax = 0.05;
  _E3aEnd_var._parameters.ymin = -0.05;
  _E3aEnd_var._parameters.ymax = 0.05;
  _E3aEnd_var._parameters.xwidth = 0.2;
  _E3aEnd_var._parameters.yheight = 0.2;
  _E3aEnd_var._parameters.restore_neutron = 0;
  _E3aEnd_var._parameters.nowritefile = 0;


  /* component E3aEnd=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _E3a_var._rotation_absolute, _E3aEnd_var._rotation_absolute);
    rot_transpose(_E3a_var._rotation_absolute, tr1);
    rot_mul(_E3aEnd_var._rotation_absolute, tr1, _E3aEnd_var._rotation_relative);
    _E3aEnd_var._rotation_is_identity =  rot_test_identity(_E3aEnd_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 3.5196154567641345 + u);
    rot_transpose(_E3a_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _E3aEnd_var._position_absolute = coords_add(_E3a_var._position_absolute, tc2);
    tc1 = coords_sub(_E3a_var._position_absolute, _E3aEnd_var._position_absolute);
    _E3aEnd_var._position_relative = rot_apply(_E3aEnd_var._rotation_absolute, tc1);
  } /* E3aEnd=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("E3aEnd", _E3aEnd_var._position_absolute, _E3aEnd_var._rotation_absolute);
  instrument->_position_absolute[15] = _E3aEnd_var._position_absolute;
  instrument->_position_relative[15] = _E3aEnd_var._position_relative;
    _E3aEnd_var._position_relative_is_zero =  coords_test_zero(_E3aEnd_var._position_relative);
  instrument->counter_N[15]  = instrument->counter_P[15] = instrument->counter_P2[15] = 0;
  instrument->counter_AbsorbProp[15]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0014_E3aEnd", _E3aEnd_var._position_absolute, _E3aEnd_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0014_E3aEnd", "nx", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0014_E3aEnd", "ny", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0014_E3aEnd", "filename", 0, "ExitE3a.dat", "char*");
        mccomp_param_nexus(nxhandle,"0014_E3aEnd", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_E3aEnd", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_E3aEnd", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_E3aEnd", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_E3aEnd", "xwidth", "0", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_E3aEnd", "yheight", "0", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_E3aEnd", "restore_neutron", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0014_E3aEnd", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _E3aEnd_setpos */

/* component E3b=Elliptic_guide_gravity() SETTING, POSITION/ROTATION */
int _E3b_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_E3b_setpos] component E3b=Elliptic_guide_gravity() SETTING [Elliptic_guide_gravity:0]");
  stracpy(_E3b_var._name, "E3b", 16384);
  stracpy(_E3b_var._type, "Elliptic_guide_gravity", 16384);
  _E3b_var._index=16;
  int current_setpos_index = 16;
  _E3b_var._parameters.xwidth = 0.079349;
  _E3b_var._parameters.yheight = 0.157884;
  _E3b_var._parameters.l = 9.736082;
  _E3b_var._parameters.linxw = 5.137709375005;
  _E3b_var._parameters.loutxw = 0.58328863;
  _E3b_var._parameters.linyh = 10.313748;
  _E3b_var._parameters.loutyh = 0.578157891;
  _E3b_var._parameters.majorAxisxw = 0;
  _E3b_var._parameters.minorAxisxw = 0;
  _E3b_var._parameters.majorAxisyh = 0;
  _E3b_var._parameters.minorAxisyh = 0;
  _E3b_var._parameters.majorAxisoffsetxw = 0;
  _E3b_var._parameters.majorAxisoffsetyh = 0;
  if("entrance" && strlen("entrance"))
    stracpy(_E3b_var._parameters.dimensionsAt, "entrance" ? "entrance" : "", 16384);
  else 
  _E3b_var._parameters.dimensionsAt[0]='\0';
  if("ellipse" && strlen("ellipse"))
    stracpy(_E3b_var._parameters.option, "ellipse" ? "ellipse" : "", 16384);
  else 
  _E3b_var._parameters.option[0]='\0';
  _E3b_var._parameters.R0 = 0.99;
  _E3b_var._parameters.Qc = 0.0218;
  _E3b_var._parameters.alpha = 6.07;
  _E3b_var._parameters.m = 2;
  _E3b_var._parameters.W = 0.003;
  _E3b_var._parameters.alpharight = -1;
  _E3b_var._parameters.mright = -1;
  _E3b_var._parameters.alphaleft = -1;
  _E3b_var._parameters.mleft = -1;
  _E3b_var._parameters.alphatop = -1;
  _E3b_var._parameters.mtop = -1;
  _E3b_var._parameters.alphabottom = -1;
  _E3b_var._parameters.mbottom = -1;
  if("on" && strlen("on"))
    stracpy(_E3b_var._parameters.verbose, "on" ? "on" : "", 16384);
  else 
  _E3b_var._parameters.verbose[0]='\0';
  _E3b_var._parameters.enableGravity = 1.0;
  _E3b_var._parameters.curvature = 0;
  _E3b_var._parameters.nSegments = 20;
  _E3b_var._parameters.mvaluesright = mvlre3b; // default pointer allocation
  _E3b_var._parameters.mvaluesleft = mvlre3b; // default pointer allocation
  _E3b_var._parameters.mvaluestop = mvtbe3b; // default pointer allocation
  _E3b_var._parameters.mvaluesbottom = mvtbe3b; // default pointer allocation
  _E3b_var._parameters.seglength = sle3b; // default pointer allocation


  /* component E3b=Elliptic_guide_gravity() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _E3aEnd_var._rotation_absolute, _E3b_var._rotation_absolute);
    rot_transpose(_E3aEnd_var._rotation_absolute, tr1);
    rot_mul(_E3b_var._rotation_absolute, tr1, _E3b_var._rotation_relative);
    _E3b_var._rotation_is_identity =  rot_test_identity(_E3b_var._rotation_relative);
    tc1 = coords_set(
      0, 0, u);
    rot_transpose(_E3aEnd_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _E3b_var._position_absolute = coords_add(_E3aEnd_var._position_absolute, tc2);
    tc1 = coords_sub(_E3aEnd_var._position_absolute, _E3b_var._position_absolute);
    _E3b_var._position_relative = rot_apply(_E3b_var._rotation_absolute, tc1);
  } /* E3b=Elliptic_guide_gravity() AT ROTATED */
  DEBUG_COMPONENT("E3b", _E3b_var._position_absolute, _E3b_var._rotation_absolute);
  instrument->_position_absolute[16] = _E3b_var._position_absolute;
  instrument->_position_relative[16] = _E3b_var._position_relative;
    _E3b_var._position_relative_is_zero =  coords_test_zero(_E3b_var._position_relative);
  instrument->counter_N[16]  = instrument->counter_P[16] = instrument->counter_P2[16] = 0;
  instrument->counter_AbsorbProp[16]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0015_E3b", _E3b_var._position_absolute, _E3b_var._rotation_absolute, "Elliptic_guide_gravity");
        mccomp_param_nexus(nxhandle,"0015_E3b", "xwidth", "0", "0.079349","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "yheight", "0", "0.157884","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "l", "NONE", "9.736082","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "linxw", "0", "5.137709375005","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "loutxw", "0", "0.58328863","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "linyh", "0", "10.313748","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "loutyh", "0", "0.578157891","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "majorAxisxw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "minorAxisxw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "majorAxisyh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "minorAxisyh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "majorAxisoffsetxw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "majorAxisoffsetyh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "dimensionsAt", "entrance", "entrance", "char*");
        mccomp_param_nexus(nxhandle,"0015_E3b", "option", "ellipse", "ellipse", "char*");
        mccomp_param_nexus(nxhandle,"0015_E3b", "R0", "0.99", "0.99","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "Qc", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "alpha", "6.07", "6.07","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "m", "2", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "W", "0.003", "0.003","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "alpharight", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "mright", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "alphaleft", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "mleft", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "alphatop", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "mtop", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "alphabottom", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "mbottom", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "verbose", "on", "on", "char*");
        mccomp_param_nexus(nxhandle,"0015_E3b", "enableGravity", "1.0", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "curvature", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "nSegments", "-1", "20","int");
        mccomp_param_nexus(nxhandle,"0015_E3b", "mvaluesright", "NULL", "mvlre3b","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "mvaluesleft", "NULL", "mvlre3b","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "mvaluestop", "NULL", "mvtbe3b","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "mvaluesbottom", "NULL", "mvtbe3b","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_E3b", "seglength", "NULL", "sle3b","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _E3b_setpos */

/* component E3bEnd=PSD_monitor() SETTING, POSITION/ROTATION */
int _E3bEnd_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_E3bEnd_setpos] component E3bEnd=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_E3bEnd_var._name, "E3bEnd", 16384);
  stracpy(_E3bEnd_var._type, "PSD_monitor", 16384);
  _E3bEnd_var._index=17;
  int current_setpos_index = 17;
  _E3bEnd_var._parameters.nx = 100;
  _E3bEnd_var._parameters.ny = 100;
  if("ExitE3b.dat" && strlen("ExitE3b.dat"))
    stracpy(_E3bEnd_var._parameters.filename, "ExitE3b.dat" ? "ExitE3b.dat" : "", 16384);
  else 
  _E3bEnd_var._parameters.filename[0]='\0';
  _E3bEnd_var._parameters.xmin = -0.05;
  _E3bEnd_var._parameters.xmax = 0.05;
  _E3bEnd_var._parameters.ymin = -0.05;
  _E3bEnd_var._parameters.ymax = 0.05;
  _E3bEnd_var._parameters.xwidth = 0.2;
  _E3bEnd_var._parameters.yheight = 0.2;
  _E3bEnd_var._parameters.restore_neutron = 0;
  _E3bEnd_var._parameters.nowritefile = 0;


  /* component E3bEnd=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _E3b_var._rotation_absolute, _E3bEnd_var._rotation_absolute);
    rot_transpose(_E3b_var._rotation_absolute, tr1);
    rot_mul(_E3bEnd_var._rotation_absolute, tr1, _E3bEnd_var._rotation_relative);
    _E3bEnd_var._rotation_is_identity =  rot_test_identity(_E3bEnd_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 9.736081977133152 + u);
    rot_transpose(_E3b_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _E3bEnd_var._position_absolute = coords_add(_E3b_var._position_absolute, tc2);
    tc1 = coords_sub(_E3b_var._position_absolute, _E3bEnd_var._position_absolute);
    _E3bEnd_var._position_relative = rot_apply(_E3bEnd_var._rotation_absolute, tc1);
  } /* E3bEnd=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("E3bEnd", _E3bEnd_var._position_absolute, _E3bEnd_var._rotation_absolute);
  instrument->_position_absolute[17] = _E3bEnd_var._position_absolute;
  instrument->_position_relative[17] = _E3bEnd_var._position_relative;
    _E3bEnd_var._position_relative_is_zero =  coords_test_zero(_E3bEnd_var._position_relative);
  instrument->counter_N[17]  = instrument->counter_P[17] = instrument->counter_P2[17] = 0;
  instrument->counter_AbsorbProp[17]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0016_E3bEnd", _E3bEnd_var._position_absolute, _E3bEnd_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0016_E3bEnd", "nx", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0016_E3bEnd", "ny", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0016_E3bEnd", "filename", 0, "ExitE3b.dat", "char*");
        mccomp_param_nexus(nxhandle,"0016_E3bEnd", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_E3bEnd", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_E3bEnd", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_E3bEnd", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_E3bEnd", "xwidth", "0", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_E3bEnd", "yheight", "0", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_E3bEnd", "restore_neutron", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0016_E3bEnd", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _E3bEnd_setpos */

/* component SlitGuideEnd=Slit() SETTING, POSITION/ROTATION */
int _SlitGuideEnd_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_SlitGuideEnd_setpos] component SlitGuideEnd=Slit() SETTING [Slit:0]");
  stracpy(_SlitGuideEnd_var._name, "SlitGuideEnd", 16384);
  stracpy(_SlitGuideEnd_var._type, "Slit", 16384);
  _SlitGuideEnd_var._index=18;
  int current_setpos_index = 18;
  _SlitGuideEnd_var._parameters.xmin = UNSET;
  _SlitGuideEnd_var._parameters.xmax = UNSET;
  _SlitGuideEnd_var._parameters.ymin = UNSET;
  _SlitGuideEnd_var._parameters.ymax = UNSET;
  _SlitGuideEnd_var._parameters.radius = UNSET;
  _SlitGuideEnd_var._parameters.xwidth = slitwidth;
  _SlitGuideEnd_var._parameters.yheight = slitheight;


  /* component SlitGuideEnd=Slit() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _E3bEnd_var._rotation_absolute, _SlitGuideEnd_var._rotation_absolute);
    rot_transpose(_E3bEnd_var._rotation_absolute, tr1);
    rot_mul(_SlitGuideEnd_var._rotation_absolute, tr1, _SlitGuideEnd_var._rotation_relative);
    _SlitGuideEnd_var._rotation_is_identity =  rot_test_identity(_SlitGuideEnd_var._rotation_relative);
    tc1 = coords_set(
      0, 0, u);
    rot_transpose(_E3bEnd_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _SlitGuideEnd_var._position_absolute = coords_add(_E3bEnd_var._position_absolute, tc2);
    tc1 = coords_sub(_E3bEnd_var._position_absolute, _SlitGuideEnd_var._position_absolute);
    _SlitGuideEnd_var._position_relative = rot_apply(_SlitGuideEnd_var._rotation_absolute, tc1);
  } /* SlitGuideEnd=Slit() AT ROTATED */
  DEBUG_COMPONENT("SlitGuideEnd", _SlitGuideEnd_var._position_absolute, _SlitGuideEnd_var._rotation_absolute);
  instrument->_position_absolute[18] = _SlitGuideEnd_var._position_absolute;
  instrument->_position_relative[18] = _SlitGuideEnd_var._position_relative;
    _SlitGuideEnd_var._position_relative_is_zero =  coords_test_zero(_SlitGuideEnd_var._position_relative);
  instrument->counter_N[18]  = instrument->counter_P[18] = instrument->counter_P2[18] = 0;
  instrument->counter_AbsorbProp[18]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0017_SlitGuideEnd", _SlitGuideEnd_var._position_absolute, _SlitGuideEnd_var._rotation_absolute, "Slit");
        mccomp_param_nexus(nxhandle,"0017_SlitGuideEnd", "xmin", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_SlitGuideEnd", "xmax", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_SlitGuideEnd", "ymin", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_SlitGuideEnd", "ymax", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_SlitGuideEnd", "radius", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_SlitGuideEnd", "xwidth", "UNSET", "slitwidth","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_SlitGuideEnd", "yheight", "UNSET", "slitheight","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _SlitGuideEnd_setpos */

/* component Mono=Monochromator_curved() SETTING, POSITION/ROTATION */
int _Mono_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_Mono_setpos] component Mono=Monochromator_curved() SETTING [Monochromator_curved:0]");
  stracpy(_Mono_var._name, "Mono", 16384);
  stracpy(_Mono_var._type, "Monochromator_curved", 16384);
  _Mono_var._index=19;
  int current_setpos_index = 19;
  if("NULL" && strlen("NULL"))
    stracpy(_Mono_var._parameters.reflect, "NULL" ? "NULL" : "", 16384);
  else 
  _Mono_var._parameters.reflect[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_Mono_var._parameters.transmit, "NULL" ? "NULL" : "", 16384);
  else 
  _Mono_var._parameters.transmit[0]='\0';
  _Mono_var._parameters.zwidth = 0.015;
  _Mono_var._parameters.yheight = 0.015;
  _Mono_var._parameters.gap = 0.0001;
  _Mono_var._parameters.NH = 17;
  _Mono_var._parameters.NV = 11;
  _Mono_var._parameters.mosaich = 42;
  _Mono_var._parameters.mosaicv = 42;
  _Mono_var._parameters.r0 = 1;
  _Mono_var._parameters.t0 = 1.0;
  _Mono_var._parameters.Q = 1.8734;
  _Mono_var._parameters.RV = RV_mono;
  _Mono_var._parameters.RH = RH_mono;
  _Mono_var._parameters.DM = 3.355;
  _Mono_var._parameters.mosaic = 0;
  _Mono_var._parameters.width = 0;
  _Mono_var._parameters.height = 0;
  _Mono_var._parameters.verbose = 0;
  _Mono_var._parameters.order = 0;


  /* component Mono=Monochromator_curved() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (thetaA1)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _SlitGuideEnd_var._rotation_absolute, _Mono_var._rotation_absolute);
    rot_transpose(_SlitGuideEnd_var._rotation_absolute, tr1);
    rot_mul(_Mono_var._rotation_absolute, tr1, _Mono_var._rotation_relative);
    _Mono_var._rotation_is_identity =  rot_test_identity(_Mono_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 1.6);
    rot_transpose(_SlitGuideEnd_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _Mono_var._position_absolute = coords_add(_SlitGuideEnd_var._position_absolute, tc2);
    tc1 = coords_sub(_SlitGuideEnd_var._position_absolute, _Mono_var._position_absolute);
    _Mono_var._position_relative = rot_apply(_Mono_var._rotation_absolute, tc1);
  } /* Mono=Monochromator_curved() AT ROTATED */
  DEBUG_COMPONENT("Mono", _Mono_var._position_absolute, _Mono_var._rotation_absolute);
  instrument->_position_absolute[19] = _Mono_var._position_absolute;
  instrument->_position_relative[19] = _Mono_var._position_relative;
    _Mono_var._position_relative_is_zero =  coords_test_zero(_Mono_var._position_relative);
  instrument->counter_N[19]  = instrument->counter_P[19] = instrument->counter_P2[19] = 0;
  instrument->counter_AbsorbProp[19]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0018_Mono", _Mono_var._position_absolute, _Mono_var._rotation_absolute, "Monochromator_curved");
        mccomp_param_nexus(nxhandle,"0018_Mono", "reflect", "NULL", "NULL", "char*");
        mccomp_param_nexus(nxhandle,"0018_Mono", "transmit", "NULL", "NULL", "char*");
        mccomp_param_nexus(nxhandle,"0018_Mono", "zwidth", "0.01", "0.015","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "yheight", "0.01", "0.015","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "gap", "0.0005", "0.0001","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "NH", "11", "17","int");
        mccomp_param_nexus(nxhandle,"0018_Mono", "NV", "11", "11","int");
        mccomp_param_nexus(nxhandle,"0018_Mono", "mosaich", "30.0", "42","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "mosaicv", "30.0", "42","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "r0", "0.7", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "t0", "1.0", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "Q", "1.8734", "1.8734","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "RV", "0", "RV_mono","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "RH", "0", "RH_mono","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "DM", "0", "3.355","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "mosaic", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "width", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "height", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "verbose", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_Mono", "order", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _Mono_setpos */

/* component A2=Arm() SETTING, POSITION/ROTATION */
int _A2_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_A2_setpos] component A2=Arm() SETTING [Arm:0]");
  stracpy(_A2_var._name, "A2", 16384);
  stracpy(_A2_var._type, "Arm", 16384);
  _A2_var._index=20;
  int current_setpos_index = 20;
  /* component A2=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (thetaA2)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _SlitGuideEnd_var._rotation_absolute, _A2_var._rotation_absolute);
    rot_transpose(_Mono_var._rotation_absolute, tr1);
    rot_mul(_A2_var._rotation_absolute, tr1, _A2_var._rotation_relative);
    _A2_var._rotation_is_identity =  rot_test_identity(_A2_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_Mono_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _A2_var._position_absolute = coords_add(_Mono_var._position_absolute, tc2);
    tc1 = coords_sub(_Mono_var._position_absolute, _A2_var._position_absolute);
    _A2_var._position_relative = rot_apply(_A2_var._rotation_absolute, tc1);
  } /* A2=Arm() AT ROTATED */
  DEBUG_COMPONENT("A2", _A2_var._position_absolute, _A2_var._rotation_absolute);
  instrument->_position_absolute[20] = _A2_var._position_absolute;
  instrument->_position_relative[20] = _A2_var._position_relative;
    _A2_var._position_relative_is_zero =  coords_test_zero(_A2_var._position_relative);
  instrument->counter_N[20]  = instrument->counter_P[20] = instrument->counter_P2[20] = 0;
  instrument->counter_AbsorbProp[20]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0019_A2", _A2_var._position_absolute, _A2_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _A2_setpos */

/* component monochromatorShielding=Slit() SETTING, POSITION/ROTATION */
int _monochromatorShielding_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_monochromatorShielding_setpos] component monochromatorShielding=Slit() SETTING [Slit:0]");
  stracpy(_monochromatorShielding_var._name, "monochromatorShielding", 16384);
  stracpy(_monochromatorShielding_var._type, "Slit", 16384);
  _monochromatorShielding_var._index=21;
  int current_setpos_index = 21;
  _monochromatorShielding_var._parameters.xmin = UNSET;
  _monochromatorShielding_var._parameters.xmax = UNSET;
  _monochromatorShielding_var._parameters.ymin = UNSET;
  _monochromatorShielding_var._parameters.ymax = UNSET;
  _monochromatorShielding_var._parameters.radius = UNSET;
  _monochromatorShielding_var._parameters.xwidth = _instrument_var._parameters.monoShieldingWidth;
  _monochromatorShielding_var._parameters.yheight = _instrument_var._parameters.monoShieldingHeight;


  /* component monochromatorShielding=Slit() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _A2_var._rotation_absolute, _monochromatorShielding_var._rotation_absolute);
    rot_transpose(_Mono_var._rotation_absolute, tr1);
    rot_mul(_monochromatorShielding_var._rotation_absolute, tr1, _monochromatorShielding_var._rotation_relative);
    _monochromatorShielding_var._rotation_is_identity =  rot_test_identity(_monochromatorShielding_var._rotation_relative);
    tc1 = coords_set(
      0, 0, _instrument_var._parameters.monoShieldingDistance);
    rot_transpose(_A2_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _monochromatorShielding_var._position_absolute = coords_add(_A2_var._position_absolute, tc2);
    tc1 = coords_sub(_Mono_var._position_absolute, _monochromatorShielding_var._position_absolute);
    _monochromatorShielding_var._position_relative = rot_apply(_monochromatorShielding_var._rotation_absolute, tc1);
  } /* monochromatorShielding=Slit() AT ROTATED */
  DEBUG_COMPONENT("monochromatorShielding", _monochromatorShielding_var._position_absolute, _monochromatorShielding_var._rotation_absolute);
  instrument->_position_absolute[21] = _monochromatorShielding_var._position_absolute;
  instrument->_position_relative[21] = _monochromatorShielding_var._position_relative;
    _monochromatorShielding_var._position_relative_is_zero =  coords_test_zero(_monochromatorShielding_var._position_relative);
  instrument->counter_N[21]  = instrument->counter_P[21] = instrument->counter_P2[21] = 0;
  instrument->counter_AbsorbProp[21]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0020_monochromatorShielding", _monochromatorShielding_var._position_absolute, _monochromatorShielding_var._rotation_absolute, "Slit");
        mccomp_param_nexus(nxhandle,"0020_monochromatorShielding", "xmin", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_monochromatorShielding", "xmax", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_monochromatorShielding", "ymin", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_monochromatorShielding", "ymax", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_monochromatorShielding", "radius", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_monochromatorShielding", "xwidth", "UNSET", "_instrument_var._parameters.monoShieldingWidth","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_monochromatorShielding", "yheight", "UNSET", "_instrument_var._parameters.monoShieldingHeight","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _monochromatorShielding_setpos */

/* component slit=Slit() SETTING, POSITION/ROTATION */
int _slit_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_slit_setpos] component slit=Slit() SETTING [Slit:0]");
  stracpy(_slit_var._name, "slit", 16384);
  stracpy(_slit_var._type, "Slit", 16384);
  _slit_var._index=22;
  int current_setpos_index = 22;
  _slit_var._parameters.xmin = -0.015;
  _slit_var._parameters.xmax = 0.015;
  _slit_var._parameters.ymin = -0.015;
  _slit_var._parameters.ymax = 0.015;
  _slit_var._parameters.radius = UNSET;
  _slit_var._parameters.xwidth = UNSET;
  _slit_var._parameters.yheight = UNSET;


  /* component slit=Slit() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _A2_var._rotation_absolute, _slit_var._rotation_absolute);
    rot_transpose(_monochromatorShielding_var._rotation_absolute, tr1);
    rot_mul(_slit_var._rotation_absolute, tr1, _slit_var._rotation_relative);
    _slit_var._rotation_is_identity =  rot_test_identity(_slit_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 1.5);
    rot_transpose(_A2_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _slit_var._position_absolute = coords_add(_A2_var._position_absolute, tc2);
    tc1 = coords_sub(_monochromatorShielding_var._position_absolute, _slit_var._position_absolute);
    _slit_var._position_relative = rot_apply(_slit_var._rotation_absolute, tc1);
  } /* slit=Slit() AT ROTATED */
  DEBUG_COMPONENT("slit", _slit_var._position_absolute, _slit_var._rotation_absolute);
  instrument->_position_absolute[22] = _slit_var._position_absolute;
  instrument->_position_relative[22] = _slit_var._position_relative;
    _slit_var._position_relative_is_zero =  coords_test_zero(_slit_var._position_relative);
  instrument->counter_N[22]  = instrument->counter_P[22] = instrument->counter_P2[22] = 0;
  instrument->counter_AbsorbProp[22]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0021_slit", _slit_var._position_absolute, _slit_var._rotation_absolute, "Slit");
        mccomp_param_nexus(nxhandle,"0021_slit", "xmin", "UNSET", "-0.015","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_slit", "xmax", "UNSET", "0.015","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_slit", "ymin", "UNSET", "-0.015","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_slit", "ymax", "UNSET", "0.015","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_slit", "radius", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_slit", "xwidth", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_slit", "yheight", "UNSET", "UNSET","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _slit_setpos */

/* component SlitMonitor=PSD_monitor() SETTING, POSITION/ROTATION */
int _SlitMonitor_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_SlitMonitor_setpos] component SlitMonitor=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_SlitMonitor_var._name, "SlitMonitor", 16384);
  stracpy(_SlitMonitor_var._type, "PSD_monitor", 16384);
  _SlitMonitor_var._index=23;
  int current_setpos_index = 23;
  _SlitMonitor_var._parameters.nx = 100;
  _SlitMonitor_var._parameters.ny = 100;
  if("SlitMonitor.dat" && strlen("SlitMonitor.dat"))
    stracpy(_SlitMonitor_var._parameters.filename, "SlitMonitor.dat" ? "SlitMonitor.dat" : "", 16384);
  else 
  _SlitMonitor_var._parameters.filename[0]='\0';
  _SlitMonitor_var._parameters.xmin = -0.02;
  _SlitMonitor_var._parameters.xmax = 0.02;
  _SlitMonitor_var._parameters.ymin = -0.02;
  _SlitMonitor_var._parameters.ymax = 0.02;
  _SlitMonitor_var._parameters.xwidth = 0;
  _SlitMonitor_var._parameters.yheight = 0;
  _SlitMonitor_var._parameters.restore_neutron = 1;
  _SlitMonitor_var._parameters.nowritefile = 0;


  /* component SlitMonitor=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _slit_var._rotation_absolute, _SlitMonitor_var._rotation_absolute);
    rot_transpose(_slit_var._rotation_absolute, tr1);
    rot_mul(_SlitMonitor_var._rotation_absolute, tr1, _SlitMonitor_var._rotation_relative);
    _SlitMonitor_var._rotation_is_identity =  rot_test_identity(_SlitMonitor_var._rotation_relative);
    tc1 = coords_set(
      0, 0, u);
    rot_transpose(_slit_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _SlitMonitor_var._position_absolute = coords_add(_slit_var._position_absolute, tc2);
    tc1 = coords_sub(_slit_var._position_absolute, _SlitMonitor_var._position_absolute);
    _SlitMonitor_var._position_relative = rot_apply(_SlitMonitor_var._rotation_absolute, tc1);
  } /* SlitMonitor=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("SlitMonitor", _SlitMonitor_var._position_absolute, _SlitMonitor_var._rotation_absolute);
  instrument->_position_absolute[23] = _SlitMonitor_var._position_absolute;
  instrument->_position_relative[23] = _SlitMonitor_var._position_relative;
    _SlitMonitor_var._position_relative_is_zero =  coords_test_zero(_SlitMonitor_var._position_relative);
  instrument->counter_N[23]  = instrument->counter_P[23] = instrument->counter_P2[23] = 0;
  instrument->counter_AbsorbProp[23]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0022_SlitMonitor", _SlitMonitor_var._position_absolute, _SlitMonitor_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0022_SlitMonitor", "nx", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0022_SlitMonitor", "ny", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0022_SlitMonitor", "filename", 0, "SlitMonitor.dat", "char*");
        mccomp_param_nexus(nxhandle,"0022_SlitMonitor", "xmin", "-0.05", "-0.02","MCNUM");
        mccomp_param_nexus(nxhandle,"0022_SlitMonitor", "xmax", "0.05", "0.02","MCNUM");
        mccomp_param_nexus(nxhandle,"0022_SlitMonitor", "ymin", "-0.05", "-0.02","MCNUM");
        mccomp_param_nexus(nxhandle,"0022_SlitMonitor", "ymax", "0.05", "0.02","MCNUM");
        mccomp_param_nexus(nxhandle,"0022_SlitMonitor", "xwidth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0022_SlitMonitor", "yheight", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0022_SlitMonitor", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0022_SlitMonitor", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _SlitMonitor_setpos */

/* component SamplePos=Arm() SETTING, POSITION/ROTATION */
int _SamplePos_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_SamplePos_setpos] component SamplePos=Arm() SETTING [Arm:0]");
  stracpy(_SamplePos_var._name, "SamplePos", 16384);
  stracpy(_SamplePos_var._type, "Arm", 16384);
  _SamplePos_var._index=24;
  int current_setpos_index = 24;
  /* component SamplePos=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _A2_var._rotation_absolute, _SamplePos_var._rotation_absolute);
    rot_transpose(_SlitMonitor_var._rotation_absolute, tr1);
    rot_mul(_SamplePos_var._rotation_absolute, tr1, _SamplePos_var._rotation_relative);
    _SamplePos_var._rotation_is_identity =  rot_test_identity(_SamplePos_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 1.6);
    rot_transpose(_A2_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _SamplePos_var._position_absolute = coords_add(_A2_var._position_absolute, tc2);
    tc1 = coords_sub(_SlitMonitor_var._position_absolute, _SamplePos_var._position_absolute);
    _SamplePos_var._position_relative = rot_apply(_SamplePos_var._rotation_absolute, tc1);
  } /* SamplePos=Arm() AT ROTATED */
  DEBUG_COMPONENT("SamplePos", _SamplePos_var._position_absolute, _SamplePos_var._rotation_absolute);
  instrument->_position_absolute[24] = _SamplePos_var._position_absolute;
  instrument->_position_relative[24] = _SamplePos_var._position_relative;
    _SamplePos_var._position_relative_is_zero =  coords_test_zero(_SamplePos_var._position_relative);
  instrument->counter_N[24]  = instrument->counter_P[24] = instrument->counter_P2[24] = 0;
  instrument->counter_AbsorbProp[24]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0023_SamplePos", _SamplePos_var._position_absolute, _SamplePos_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _SamplePos_setpos */

/* component AMidt=Arm() SETTING, POSITION/ROTATION */
int _AMidt_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_AMidt_setpos] component AMidt=Arm() SETTING [Arm:0]");
  stracpy(_AMidt_var._name, "AMidt", 16384);
  stracpy(_AMidt_var._type, "Arm", 16384);
  _AMidt_var._index=25;
  int current_setpos_index = 25;
  /* component AMidt=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (A4_val)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _SamplePos_var._rotation_absolute, _AMidt_var._rotation_absolute);
    rot_transpose(_SlitMonitor_var._rotation_absolute, tr1);
    rot_mul(_AMidt_var._rotation_absolute, tr1, _AMidt_var._rotation_relative);
    _AMidt_var._rotation_is_identity =  rot_test_identity(_AMidt_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_SamplePos_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _AMidt_var._position_absolute = coords_add(_SamplePos_var._position_absolute, tc2);
    tc1 = coords_sub(_SlitMonitor_var._position_absolute, _AMidt_var._position_absolute);
    _AMidt_var._position_relative = rot_apply(_AMidt_var._rotation_absolute, tc1);
  } /* AMidt=Arm() AT ROTATED */
  DEBUG_COMPONENT("AMidt", _AMidt_var._position_absolute, _AMidt_var._rotation_absolute);
  instrument->_position_absolute[25] = _AMidt_var._position_absolute;
  instrument->_position_relative[25] = _AMidt_var._position_relative;
    _AMidt_var._position_relative_is_zero =  coords_test_zero(_AMidt_var._position_relative);
  instrument->counter_N[25]  = instrument->counter_P[25] = instrument->counter_P2[25] = 0;
  instrument->counter_AbsorbProp[25]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0024_AMidt", _AMidt_var._position_absolute, _AMidt_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _AMidt_setpos */

/* component a41=Arm() SETTING, POSITION/ROTATION */
int _a41_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_a41_setpos] component a41=Arm() SETTING [Arm:0]");
  stracpy(_a41_var._name, "a41", 16384);
  stracpy(_a41_var._type, "Arm", 16384);
  _a41_var._index=26;
  int current_setpos_index = 26;
  /* component a41=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (28)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _AMidt_var._rotation_absolute, _a41_var._rotation_absolute);
    rot_transpose(_SlitMonitor_var._rotation_absolute, tr1);
    rot_mul(_a41_var._rotation_absolute, tr1, _a41_var._rotation_relative);
    _a41_var._rotation_is_identity =  rot_test_identity(_a41_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_AMidt_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _a41_var._position_absolute = coords_add(_AMidt_var._position_absolute, tc2);
    tc1 = coords_sub(_SlitMonitor_var._position_absolute, _a41_var._position_absolute);
    _a41_var._position_relative = rot_apply(_a41_var._rotation_absolute, tc1);
  } /* a41=Arm() AT ROTATED */
  DEBUG_COMPONENT("a41", _a41_var._position_absolute, _a41_var._rotation_absolute);
  instrument->_position_absolute[26] = _a41_var._position_absolute;
  instrument->_position_relative[26] = _a41_var._position_relative;
    _a41_var._position_relative_is_zero =  coords_test_zero(_a41_var._position_relative);
  instrument->counter_N[26]  = instrument->counter_P[26] = instrument->counter_P2[26] = 0;
  instrument->counter_AbsorbProp[26]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0025_a41", _a41_var._position_absolute, _a41_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _a41_setpos */

/* component a42=Arm() SETTING, POSITION/ROTATION */
int _a42_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_a42_setpos] component a42=Arm() SETTING [Arm:0]");
  stracpy(_a42_var._name, "a42", 16384);
  stracpy(_a42_var._type, "Arm", 16384);
  _a42_var._index=27;
  int current_setpos_index = 27;
  /* component a42=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (20)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _AMidt_var._rotation_absolute, _a42_var._rotation_absolute);
    rot_transpose(_SlitMonitor_var._rotation_absolute, tr1);
    rot_mul(_a42_var._rotation_absolute, tr1, _a42_var._rotation_relative);
    _a42_var._rotation_is_identity =  rot_test_identity(_a42_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_AMidt_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _a42_var._position_absolute = coords_add(_AMidt_var._position_absolute, tc2);
    tc1 = coords_sub(_SlitMonitor_var._position_absolute, _a42_var._position_absolute);
    _a42_var._position_relative = rot_apply(_a42_var._rotation_absolute, tc1);
  } /* a42=Arm() AT ROTATED */
  DEBUG_COMPONENT("a42", _a42_var._position_absolute, _a42_var._rotation_absolute);
  instrument->_position_absolute[27] = _a42_var._position_absolute;
  instrument->_position_relative[27] = _a42_var._position_relative;
    _a42_var._position_relative_is_zero =  coords_test_zero(_a42_var._position_relative);
  instrument->counter_N[27]  = instrument->counter_P[27] = instrument->counter_P2[27] = 0;
  instrument->counter_AbsorbProp[27]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0026_a42", _a42_var._position_absolute, _a42_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _a42_setpos */

/* component a43=Arm() SETTING, POSITION/ROTATION */
int _a43_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_a43_setpos] component a43=Arm() SETTING [Arm:0]");
  stracpy(_a43_var._name, "a43", 16384);
  stracpy(_a43_var._type, "Arm", 16384);
  _a43_var._index=28;
  int current_setpos_index = 28;
  /* component a43=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (12)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _AMidt_var._rotation_absolute, _a43_var._rotation_absolute);
    rot_transpose(_SlitMonitor_var._rotation_absolute, tr1);
    rot_mul(_a43_var._rotation_absolute, tr1, _a43_var._rotation_relative);
    _a43_var._rotation_is_identity =  rot_test_identity(_a43_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_AMidt_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _a43_var._position_absolute = coords_add(_AMidt_var._position_absolute, tc2);
    tc1 = coords_sub(_SlitMonitor_var._position_absolute, _a43_var._position_absolute);
    _a43_var._position_relative = rot_apply(_a43_var._rotation_absolute, tc1);
  } /* a43=Arm() AT ROTATED */
  DEBUG_COMPONENT("a43", _a43_var._position_absolute, _a43_var._rotation_absolute);
  instrument->_position_absolute[28] = _a43_var._position_absolute;
  instrument->_position_relative[28] = _a43_var._position_relative;
    _a43_var._position_relative_is_zero =  coords_test_zero(_a43_var._position_relative);
  instrument->counter_N[28]  = instrument->counter_P[28] = instrument->counter_P2[28] = 0;
  instrument->counter_AbsorbProp[28]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0027_a43", _a43_var._position_absolute, _a43_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _a43_setpos */

/* component a44=Arm() SETTING, POSITION/ROTATION */
int _a44_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_a44_setpos] component a44=Arm() SETTING [Arm:0]");
  stracpy(_a44_var._name, "a44", 16384);
  stracpy(_a44_var._type, "Arm", 16384);
  _a44_var._index=29;
  int current_setpos_index = 29;
  /* component a44=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (4)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _AMidt_var._rotation_absolute, _a44_var._rotation_absolute);
    rot_transpose(_SlitMonitor_var._rotation_absolute, tr1);
    rot_mul(_a44_var._rotation_absolute, tr1, _a44_var._rotation_relative);
    _a44_var._rotation_is_identity =  rot_test_identity(_a44_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_AMidt_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _a44_var._position_absolute = coords_add(_AMidt_var._position_absolute, tc2);
    tc1 = coords_sub(_SlitMonitor_var._position_absolute, _a44_var._position_absolute);
    _a44_var._position_relative = rot_apply(_a44_var._rotation_absolute, tc1);
  } /* a44=Arm() AT ROTATED */
  DEBUG_COMPONENT("a44", _a44_var._position_absolute, _a44_var._rotation_absolute);
  instrument->_position_absolute[29] = _a44_var._position_absolute;
  instrument->_position_relative[29] = _a44_var._position_relative;
    _a44_var._position_relative_is_zero =  coords_test_zero(_a44_var._position_relative);
  instrument->counter_N[29]  = instrument->counter_P[29] = instrument->counter_P2[29] = 0;
  instrument->counter_AbsorbProp[29]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0028_a44", _a44_var._position_absolute, _a44_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _a44_setpos */

/* component a45=Arm() SETTING, POSITION/ROTATION */
int _a45_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_a45_setpos] component a45=Arm() SETTING [Arm:0]");
  stracpy(_a45_var._name, "a45", 16384);
  stracpy(_a45_var._type, "Arm", 16384);
  _a45_var._index=30;
  int current_setpos_index = 30;
  /* component a45=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (-4)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _AMidt_var._rotation_absolute, _a45_var._rotation_absolute);
    rot_transpose(_SlitMonitor_var._rotation_absolute, tr1);
    rot_mul(_a45_var._rotation_absolute, tr1, _a45_var._rotation_relative);
    _a45_var._rotation_is_identity =  rot_test_identity(_a45_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_AMidt_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _a45_var._position_absolute = coords_add(_AMidt_var._position_absolute, tc2);
    tc1 = coords_sub(_SlitMonitor_var._position_absolute, _a45_var._position_absolute);
    _a45_var._position_relative = rot_apply(_a45_var._rotation_absolute, tc1);
  } /* a45=Arm() AT ROTATED */
  DEBUG_COMPONENT("a45", _a45_var._position_absolute, _a45_var._rotation_absolute);
  instrument->_position_absolute[30] = _a45_var._position_absolute;
  instrument->_position_relative[30] = _a45_var._position_relative;
    _a45_var._position_relative_is_zero =  coords_test_zero(_a45_var._position_relative);
  instrument->counter_N[30]  = instrument->counter_P[30] = instrument->counter_P2[30] = 0;
  instrument->counter_AbsorbProp[30]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0029_a45", _a45_var._position_absolute, _a45_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _a45_setpos */

/* component a46=Arm() SETTING, POSITION/ROTATION */
int _a46_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_a46_setpos] component a46=Arm() SETTING [Arm:0]");
  stracpy(_a46_var._name, "a46", 16384);
  stracpy(_a46_var._type, "Arm", 16384);
  _a46_var._index=31;
  int current_setpos_index = 31;
  /* component a46=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (-12)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _AMidt_var._rotation_absolute, _a46_var._rotation_absolute);
    rot_transpose(_SlitMonitor_var._rotation_absolute, tr1);
    rot_mul(_a46_var._rotation_absolute, tr1, _a46_var._rotation_relative);
    _a46_var._rotation_is_identity =  rot_test_identity(_a46_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_AMidt_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _a46_var._position_absolute = coords_add(_AMidt_var._position_absolute, tc2);
    tc1 = coords_sub(_SlitMonitor_var._position_absolute, _a46_var._position_absolute);
    _a46_var._position_relative = rot_apply(_a46_var._rotation_absolute, tc1);
  } /* a46=Arm() AT ROTATED */
  DEBUG_COMPONENT("a46", _a46_var._position_absolute, _a46_var._rotation_absolute);
  instrument->_position_absolute[31] = _a46_var._position_absolute;
  instrument->_position_relative[31] = _a46_var._position_relative;
    _a46_var._position_relative_is_zero =  coords_test_zero(_a46_var._position_relative);
  instrument->counter_N[31]  = instrument->counter_P[31] = instrument->counter_P2[31] = 0;
  instrument->counter_AbsorbProp[31]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0030_a46", _a46_var._position_absolute, _a46_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _a46_setpos */

/* component a47=Arm() SETTING, POSITION/ROTATION */
int _a47_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_a47_setpos] component a47=Arm() SETTING [Arm:0]");
  stracpy(_a47_var._name, "a47", 16384);
  stracpy(_a47_var._type, "Arm", 16384);
  _a47_var._index=32;
  int current_setpos_index = 32;
  /* component a47=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (-20)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _AMidt_var._rotation_absolute, _a47_var._rotation_absolute);
    rot_transpose(_SlitMonitor_var._rotation_absolute, tr1);
    rot_mul(_a47_var._rotation_absolute, tr1, _a47_var._rotation_relative);
    _a47_var._rotation_is_identity =  rot_test_identity(_a47_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_AMidt_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _a47_var._position_absolute = coords_add(_AMidt_var._position_absolute, tc2);
    tc1 = coords_sub(_SlitMonitor_var._position_absolute, _a47_var._position_absolute);
    _a47_var._position_relative = rot_apply(_a47_var._rotation_absolute, tc1);
  } /* a47=Arm() AT ROTATED */
  DEBUG_COMPONENT("a47", _a47_var._position_absolute, _a47_var._rotation_absolute);
  instrument->_position_absolute[32] = _a47_var._position_absolute;
  instrument->_position_relative[32] = _a47_var._position_relative;
    _a47_var._position_relative_is_zero =  coords_test_zero(_a47_var._position_relative);
  instrument->counter_N[32]  = instrument->counter_P[32] = instrument->counter_P2[32] = 0;
  instrument->counter_AbsorbProp[32]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0031_a47", _a47_var._position_absolute, _a47_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _a47_setpos */

/* component a48=Arm() SETTING, POSITION/ROTATION */
int _a48_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_a48_setpos] component a48=Arm() SETTING [Arm:0]");
  stracpy(_a48_var._name, "a48", 16384);
  stracpy(_a48_var._type, "Arm", 16384);
  _a48_var._index=33;
  int current_setpos_index = 33;
  /* component a48=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (-28)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _AMidt_var._rotation_absolute, _a48_var._rotation_absolute);
    rot_transpose(_SlitMonitor_var._rotation_absolute, tr1);
    rot_mul(_a48_var._rotation_absolute, tr1, _a48_var._rotation_relative);
    _a48_var._rotation_is_identity =  rot_test_identity(_a48_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_AMidt_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _a48_var._position_absolute = coords_add(_AMidt_var._position_absolute, tc2);
    tc1 = coords_sub(_SlitMonitor_var._position_absolute, _a48_var._position_absolute);
    _a48_var._position_relative = rot_apply(_a48_var._rotation_absolute, tc1);
  } /* a48=Arm() AT ROTATED */
  DEBUG_COMPONENT("a48", _a48_var._position_absolute, _a48_var._rotation_absolute);
  instrument->_position_absolute[33] = _a48_var._position_absolute;
  instrument->_position_relative[33] = _a48_var._position_relative;
    _a48_var._position_relative_is_zero =  coords_test_zero(_a48_var._position_relative);
  instrument->counter_N[33]  = instrument->counter_P[33] = instrument->counter_P2[33] = 0;
  instrument->counter_AbsorbProp[33]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0032_a48", _a48_var._position_absolute, _a48_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _a48_setpos */

/* component sample_flux_before=PSD_monitor() SETTING, POSITION/ROTATION */
int _sample_flux_before_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_flux_before_setpos] component sample_flux_before=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_sample_flux_before_var._name, "sample_flux_before", 16384);
  stracpy(_sample_flux_before_var._type, "PSD_monitor", 16384);
  _sample_flux_before_var._index=34;
  int current_setpos_index = 34;
  _sample_flux_before_var._parameters.nx = 100;
  _sample_flux_before_var._parameters.ny = 100;
  if("sample_flux_before.dat" && strlen("sample_flux_before.dat"))
    stracpy(_sample_flux_before_var._parameters.filename, "sample_flux_before.dat" ? "sample_flux_before.dat" : "", 16384);
  else 
  _sample_flux_before_var._parameters.filename[0]='\0';
  _sample_flux_before_var._parameters.xmin = -3.0 * _instrument_var._parameters.sampleRadius;
  _sample_flux_before_var._parameters.xmax = 3.0 * _instrument_var._parameters.sampleRadius;
  _sample_flux_before_var._parameters.ymin = -3.0 * _instrument_var._parameters.sampleHeight;
  _sample_flux_before_var._parameters.ymax = 3.0 * _instrument_var._parameters.sampleHeight;
  _sample_flux_before_var._parameters.xwidth = 0;
  _sample_flux_before_var._parameters.yheight = 0;
  _sample_flux_before_var._parameters.restore_neutron = 1;
  _sample_flux_before_var._parameters.nowritefile = 0;


  /* component sample_flux_before=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _SamplePos_var._rotation_absolute, _sample_flux_before_var._rotation_absolute);
    rot_transpose(_SlitMonitor_var._rotation_absolute, tr1);
    rot_mul(_sample_flux_before_var._rotation_absolute, tr1, _sample_flux_before_var._rotation_relative);
    _sample_flux_before_var._rotation_is_identity =  rot_test_identity(_sample_flux_before_var._rotation_relative);
    tc1 = coords_set(
      0, _instrument_var._parameters.samplePosY, - _instrument_var._parameters.sampleRadius - u);
    rot_transpose(_SamplePos_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_flux_before_var._position_absolute = coords_add(_SamplePos_var._position_absolute, tc2);
    tc1 = coords_sub(_SlitMonitor_var._position_absolute, _sample_flux_before_var._position_absolute);
    _sample_flux_before_var._position_relative = rot_apply(_sample_flux_before_var._rotation_absolute, tc1);
  } /* sample_flux_before=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("sample_flux_before", _sample_flux_before_var._position_absolute, _sample_flux_before_var._rotation_absolute);
  instrument->_position_absolute[34] = _sample_flux_before_var._position_absolute;
  instrument->_position_relative[34] = _sample_flux_before_var._position_relative;
    _sample_flux_before_var._position_relative_is_zero =  coords_test_zero(_sample_flux_before_var._position_relative);
  instrument->counter_N[34]  = instrument->counter_P[34] = instrument->counter_P2[34] = 0;
  instrument->counter_AbsorbProp[34]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0033_sample_flux_before", _sample_flux_before_var._position_absolute, _sample_flux_before_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0033_sample_flux_before", "nx", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0033_sample_flux_before", "ny", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0033_sample_flux_before", "filename", 0, "sample_flux_before.dat", "char*");
        mccomp_param_nexus(nxhandle,"0033_sample_flux_before", "xmin", "-0.05", "-3.0 * _instrument_var._parameters.sampleRadius","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_flux_before", "xmax", "0.05", "3.0 * _instrument_var._parameters.sampleRadius","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_flux_before", "ymin", "-0.05", "-3.0 * _instrument_var._parameters.sampleHeight","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_flux_before", "ymax", "0.05", "3.0 * _instrument_var._parameters.sampleHeight","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_flux_before", "xwidth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_flux_before", "yheight", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_flux_before", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0033_sample_flux_before", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _sample_flux_before_setpos */

/* component sample_scatter_state_reset=Arm() SETTING, POSITION/ROTATION */
int _sample_scatter_state_reset_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_scatter_state_reset_setpos] component sample_scatter_state_reset=Arm() SETTING [Arm:0]");
  stracpy(_sample_scatter_state_reset_var._name, "sample_scatter_state_reset", 16384);
  stracpy(_sample_scatter_state_reset_var._type, "Arm", 16384);
  _sample_scatter_state_reset_var._index=35;
  int current_setpos_index = 35;
  /* component sample_scatter_state_reset=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _SamplePos_var._rotation_absolute, _sample_scatter_state_reset_var._rotation_absolute);
    rot_transpose(_sample_flux_before_var._rotation_absolute, tr1);
    rot_mul(_sample_scatter_state_reset_var._rotation_absolute, tr1, _sample_scatter_state_reset_var._rotation_relative);
    _sample_scatter_state_reset_var._rotation_is_identity =  rot_test_identity(_sample_scatter_state_reset_var._rotation_relative);
    tc1 = coords_set(
      0, _instrument_var._parameters.samplePosY, 0);
    rot_transpose(_SamplePos_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_scatter_state_reset_var._position_absolute = coords_add(_SamplePos_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_flux_before_var._position_absolute, _sample_scatter_state_reset_var._position_absolute);
    _sample_scatter_state_reset_var._position_relative = rot_apply(_sample_scatter_state_reset_var._rotation_absolute, tc1);
  } /* sample_scatter_state_reset=Arm() AT ROTATED */
  DEBUG_COMPONENT("sample_scatter_state_reset", _sample_scatter_state_reset_var._position_absolute, _sample_scatter_state_reset_var._rotation_absolute);
  instrument->_position_absolute[35] = _sample_scatter_state_reset_var._position_absolute;
  instrument->_position_relative[35] = _sample_scatter_state_reset_var._position_relative;
    _sample_scatter_state_reset_var._position_relative_is_zero =  coords_test_zero(_sample_scatter_state_reset_var._position_relative);
  instrument->counter_N[35]  = instrument->counter_P[35] = instrument->counter_P2[35] = 0;
  instrument->counter_AbsorbProp[35]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0034_sample_scatter_state_reset", _sample_scatter_state_reset_var._position_absolute, _sample_scatter_state_reset_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _sample_scatter_state_reset_setpos */

/* component VanSample=Incoherent() SETTING, POSITION/ROTATION */
int _VanSample_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_VanSample_setpos] component VanSample=Incoherent() SETTING [Incoherent:0]");
  stracpy(_VanSample_var._name, "VanSample", 16384);
  stracpy(_VanSample_var._type, "Incoherent", 16384);
  _VanSample_var._index=36;
  int current_setpos_index = 36;
  _VanSample_var._parameters.geometry[0]='\0';
  _VanSample_var._parameters.radius = _instrument_var._parameters.sampleRadius;
  _VanSample_var._parameters.xwidth = 0;
  _VanSample_var._parameters.yheight = _instrument_var._parameters.sampleHeight;
  _VanSample_var._parameters.zdepth = 0;
  _VanSample_var._parameters.thickness = _instrument_var._parameters.sampleThickness;
  _VanSample_var._parameters.target_x = 0;
  _VanSample_var._parameters.target_y = 0;
  _VanSample_var._parameters.target_z = 0;
  _VanSample_var._parameters.focus_r = 0;
  _VanSample_var._parameters.focus_xw = 0;
  _VanSample_var._parameters.focus_yh = 0;
  _VanSample_var._parameters.focus_aw = 0;
  _VanSample_var._parameters.focus_ah = 0;
  _VanSample_var._parameters.target_index = 0;
  _VanSample_var._parameters.pack = 1;
  _VanSample_var._parameters.p_interact = 1;
  _VanSample_var._parameters.f_QE = 0;
  _VanSample_var._parameters.gamma = 0;
  _VanSample_var._parameters.Etrans = 0;
  _VanSample_var._parameters.deltaE = 0;
  _VanSample_var._parameters.sigma_abs = 5.08;
  _VanSample_var._parameters.sigma_inc = 5.08;
  _VanSample_var._parameters.Vc = 13.827;
  _VanSample_var._parameters.concentric = 0;
  _VanSample_var._parameters.order = 0;


  /* component VanSample=Incoherent() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (_instrument_var._parameters.A3)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _SamplePos_var._rotation_absolute, _VanSample_var._rotation_absolute);
    rot_transpose(_sample_scatter_state_reset_var._rotation_absolute, tr1);
    rot_mul(_VanSample_var._rotation_absolute, tr1, _VanSample_var._rotation_relative);
    _VanSample_var._rotation_is_identity =  rot_test_identity(_VanSample_var._rotation_relative);
    tc1 = coords_set(
      0, _instrument_var._parameters.samplePosY, 0);
    rot_transpose(_SamplePos_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _VanSample_var._position_absolute = coords_add(_SamplePos_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_scatter_state_reset_var._position_absolute, _VanSample_var._position_absolute);
    _VanSample_var._position_relative = rot_apply(_VanSample_var._rotation_absolute, tc1);
  } /* VanSample=Incoherent() AT ROTATED */
  DEBUG_COMPONENT("VanSample", _VanSample_var._position_absolute, _VanSample_var._rotation_absolute);
  instrument->_position_absolute[36] = _VanSample_var._position_absolute;
  instrument->_position_relative[36] = _VanSample_var._position_relative;
    _VanSample_var._position_relative_is_zero =  coords_test_zero(_VanSample_var._position_relative);
  instrument->counter_N[36]  = instrument->counter_P[36] = instrument->counter_P2[36] = 0;
  instrument->counter_AbsorbProp[36]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0035_VanSample", _VanSample_var._position_absolute, _VanSample_var._rotation_absolute, "Incoherent");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "geometry", 0, 0, "char*");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "radius", "0", "_instrument_var._parameters.sampleRadius","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "xwidth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "yheight", "0", "_instrument_var._parameters.sampleHeight","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "zdepth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "thickness", "0", "_instrument_var._parameters.sampleThickness","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "target_x", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "target_y", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "target_z", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "focus_r", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "focus_xw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "focus_yh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "focus_aw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "focus_ah", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "target_index", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "pack", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "p_interact", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "f_QE", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "gamma", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "Etrans", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "deltaE", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "sigma_abs", "5.08", "5.08","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "sigma_inc", "5.08", "5.08","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "Vc", "13.827", "13.827","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "concentric", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_VanSample", "order", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _VanSample_setpos */

/* component sample=Phonon_simple() SETTING, POSITION/ROTATION */
int _sample_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_setpos] component sample=Phonon_simple() SETTING [Phonon_simple:0]");
  stracpy(_sample_var._name, "sample", 16384);
  stracpy(_sample_var._type, "Phonon_simple", 16384);
  _sample_var._index=37;
  int current_setpos_index = 37;
  _sample_var._parameters.radius = _instrument_var._parameters.sampleRadius;
  _sample_var._parameters.yheight = _instrument_var._parameters.sampleHeight;
  _sample_var._parameters.sigma_abs = 0.17;
  _sample_var._parameters.sigma_inc = 0.003;
  _sample_var._parameters.a = 4.95;
  _sample_var._parameters.b = 0.90;
  _sample_var._parameters.M = 208;
  _sample_var._parameters.c = 8;
  _sample_var._parameters.DW = 1.00;
  _sample_var._parameters.T = 300;
  _sample_var._parameters.target_x = 0;
  _sample_var._parameters.target_y = 0;
  _sample_var._parameters.target_z = 0;
  _sample_var._parameters.target_index = + 4;
  _sample_var._parameters.focus_r = 0;
  _sample_var._parameters.focus_xw = 1;
  _sample_var._parameters.focus_yh = 0.10;
  _sample_var._parameters.focus_aw = 0;
  _sample_var._parameters.focus_ah = 0;
  _sample_var._parameters.gap = 0;
  _sample_var._parameters.e_steps_low = 50;
  _sample_var._parameters.e_steps_high = 50;


  /* component sample=Phonon_simple() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (_instrument_var._parameters.A3)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _SamplePos_var._rotation_absolute, _sample_var._rotation_absolute);
    rot_transpose(_VanSample_var._rotation_absolute, tr1);
    rot_mul(_sample_var._rotation_absolute, tr1, _sample_var._rotation_relative);
    _sample_var._rotation_is_identity =  rot_test_identity(_sample_var._rotation_relative);
    tc1 = coords_set(
      0, _instrument_var._parameters.samplePosY, 0);
    rot_transpose(_SamplePos_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_var._position_absolute = coords_add(_SamplePos_var._position_absolute, tc2);
    tc1 = coords_sub(_VanSample_var._position_absolute, _sample_var._position_absolute);
    _sample_var._position_relative = rot_apply(_sample_var._rotation_absolute, tc1);
  } /* sample=Phonon_simple() AT ROTATED */
  DEBUG_COMPONENT("sample", _sample_var._position_absolute, _sample_var._rotation_absolute);
  instrument->_position_absolute[37] = _sample_var._position_absolute;
  instrument->_position_relative[37] = _sample_var._position_relative;
    _sample_var._position_relative_is_zero =  coords_test_zero(_sample_var._position_relative);
  instrument->counter_N[37]  = instrument->counter_P[37] = instrument->counter_P2[37] = 0;
  instrument->counter_AbsorbProp[37]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0036_sample", _sample_var._position_absolute, _sample_var._rotation_absolute, "Phonon_simple");
        mccomp_param_nexus(nxhandle,"0036_sample", "radius", "NONE", "_instrument_var._parameters.sampleRadius","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "yheight", "NONE", "_instrument_var._parameters.sampleHeight","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "sigma_abs", "NONE", "0.17","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "sigma_inc", "NONE", "0.003","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "a", "NONE", "4.95","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "b", "NONE", "0.90","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "M", "NONE", "208","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "c", "NONE", "8","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "DW", "NONE", "1.00","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "T", "NONE", "300","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "target_x", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "target_y", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "target_z", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "target_index", "0", "+ 4","int");
        mccomp_param_nexus(nxhandle,"0036_sample", "focus_r", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "focus_xw", "0", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "focus_yh", "0", "0.10","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "focus_aw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "focus_ah", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "gap", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0036_sample", "e_steps_low", "50", "50","int");
        mccomp_param_nexus(nxhandle,"0036_sample", "e_steps_high", "50", "50","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _sample_setpos */

/* component powder1=Powder1() SETTING, POSITION/ROTATION */
int _powder1_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_powder1_setpos] component powder1=Powder1() SETTING [Powder1:0]");
  stracpy(_powder1_var._name, "powder1", 16384);
  stracpy(_powder1_var._type, "Powder1", 16384);
  _powder1_var._index=38;
  int current_setpos_index = 38;
  _powder1_var._parameters.radius = _instrument_var._parameters.sampleRadius;
  _powder1_var._parameters.yheight = _instrument_var._parameters.sampleHeight;
  _powder1_var._parameters.xwidth = 0;
  _powder1_var._parameters.zdepth = 0;
  _powder1_var._parameters.q = 1.8049;
  _powder1_var._parameters.d = 0;
  _powder1_var._parameters.d_phi = 9;
  _powder1_var._parameters.pack = 1;
  _powder1_var._parameters.j = 6;
  _powder1_var._parameters.DW = 1;
  _powder1_var._parameters.F2 = 56.8;
  _powder1_var._parameters.Vc = 85.0054;
  _powder1_var._parameters.sigma_abs = 0.463;


  /* component powder1=Powder1() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (_instrument_var._parameters.A3)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _SamplePos_var._rotation_absolute, _powder1_var._rotation_absolute);
    rot_transpose(_sample_var._rotation_absolute, tr1);
    rot_mul(_powder1_var._rotation_absolute, tr1, _powder1_var._rotation_relative);
    _powder1_var._rotation_is_identity =  rot_test_identity(_powder1_var._rotation_relative);
    tc1 = coords_set(
      0, _instrument_var._parameters.samplePosY, 0);
    rot_transpose(_SamplePos_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _powder1_var._position_absolute = coords_add(_SamplePos_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_var._position_absolute, _powder1_var._position_absolute);
    _powder1_var._position_relative = rot_apply(_powder1_var._rotation_absolute, tc1);
  } /* powder1=Powder1() AT ROTATED */
  DEBUG_COMPONENT("powder1", _powder1_var._position_absolute, _powder1_var._rotation_absolute);
  instrument->_position_absolute[38] = _powder1_var._position_absolute;
  instrument->_position_relative[38] = _powder1_var._position_relative;
    _powder1_var._position_relative_is_zero =  coords_test_zero(_powder1_var._position_relative);
  instrument->counter_N[38]  = instrument->counter_P[38] = instrument->counter_P2[38] = 0;
  instrument->counter_AbsorbProp[38]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0037_powder1", _powder1_var._position_absolute, _powder1_var._rotation_absolute, "Powder1");
        mccomp_param_nexus(nxhandle,"0037_powder1", "radius", "0.01", "_instrument_var._parameters.sampleRadius","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_powder1", "yheight", "0.05", "_instrument_var._parameters.sampleHeight","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_powder1", "xwidth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_powder1", "zdepth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_powder1", "q", "1.8049", "1.8049","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_powder1", "d", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_powder1", "d_phi", "0", "9","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_powder1", "pack", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_powder1", "j", "6", "6","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_powder1", "DW", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_powder1", "F2", "56.8", "56.8","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_powder1", "Vc", "85.0054", "85.0054","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_powder1", "sigma_abs", "0.463", "0.463","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _powder1_setpos */

/* component res_sample=Res_sample() SETTING, POSITION/ROTATION */
int _res_sample_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_res_sample_setpos] component res_sample=Res_sample() SETTING [Res_sample:0]");
  stracpy(_res_sample_var._name, "res_sample", 16384);
  stracpy(_res_sample_var._type, "Res_sample", 16384);
  _res_sample_var._index=39;
  int current_setpos_index = 39;
  _res_sample_var._parameters.thickness = 0;
  _res_sample_var._parameters.radius = _instrument_var._parameters.sampleRadius;
  _res_sample_var._parameters.focus_r = 0.05;
  _res_sample_var._parameters.E0 = 4.1;
  _res_sample_var._parameters.dE = 1;
  _res_sample_var._parameters.target_x = 0;
  _res_sample_var._parameters.target_y = 0;
  _res_sample_var._parameters.target_z = .5;
  _res_sample_var._parameters.focus_xw = 1;
  _res_sample_var._parameters.focus_yh = 0.1;
  _res_sample_var._parameters.focus_aw = 0;
  _res_sample_var._parameters.focus_ah = 0;
  _res_sample_var._parameters.xwidth = 0;
  _res_sample_var._parameters.yheight = _instrument_var._parameters.sampleHeight;
  _res_sample_var._parameters.zdepth = 0;
  _res_sample_var._parameters.target_index = + 2;


  /* component res_sample=Res_sample() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (_instrument_var._parameters.A3)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _SamplePos_var._rotation_absolute, _res_sample_var._rotation_absolute);
    rot_transpose(_powder1_var._rotation_absolute, tr1);
    rot_mul(_res_sample_var._rotation_absolute, tr1, _res_sample_var._rotation_relative);
    _res_sample_var._rotation_is_identity =  rot_test_identity(_res_sample_var._rotation_relative);
    tc1 = coords_set(
      0, _instrument_var._parameters.samplePosY, 0);
    rot_transpose(_SamplePos_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _res_sample_var._position_absolute = coords_add(_SamplePos_var._position_absolute, tc2);
    tc1 = coords_sub(_powder1_var._position_absolute, _res_sample_var._position_absolute);
    _res_sample_var._position_relative = rot_apply(_res_sample_var._rotation_absolute, tc1);
  } /* res_sample=Res_sample() AT ROTATED */
  DEBUG_COMPONENT("res_sample", _res_sample_var._position_absolute, _res_sample_var._rotation_absolute);
  instrument->_position_absolute[39] = _res_sample_var._position_absolute;
  instrument->_position_relative[39] = _res_sample_var._position_relative;
    _res_sample_var._position_relative_is_zero =  coords_test_zero(_res_sample_var._position_relative);
  instrument->counter_N[39]  = instrument->counter_P[39] = instrument->counter_P2[39] = 0;
  instrument->counter_AbsorbProp[39]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0038_res_sample", _res_sample_var._position_absolute, _res_sample_var._rotation_absolute, "Res_sample");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "thickness", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "radius", "0.01", "_instrument_var._parameters.sampleRadius","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "focus_r", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "E0", "14", "4.1","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "dE", "2", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "target_x", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "target_y", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "target_z", ".5", ".5","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "focus_xw", "0", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "focus_yh", "0", "0.1","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "focus_aw", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "focus_ah", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "xwidth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "yheight", "0.05", "_instrument_var._parameters.sampleHeight","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "zdepth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0038_res_sample", "target_index", "0", "+ 2","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _res_sample_setpos */

/* component sample_flux_after_unscattered=PSD_monitor() SETTING, POSITION/ROTATION */
int _sample_flux_after_unscattered_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_flux_after_unscattered_setpos] component sample_flux_after_unscattered=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_sample_flux_after_unscattered_var._name, "sample_flux_after_unscattered", 16384);
  stracpy(_sample_flux_after_unscattered_var._type, "PSD_monitor", 16384);
  _sample_flux_after_unscattered_var._index=40;
  int current_setpos_index = 40;
  _sample_flux_after_unscattered_var._parameters.nx = 100;
  _sample_flux_after_unscattered_var._parameters.ny = 100;
  if("sample_flux_after_unscattered.dat" && strlen("sample_flux_after_unscattered.dat"))
    stracpy(_sample_flux_after_unscattered_var._parameters.filename, "sample_flux_after_unscattered.dat" ? "sample_flux_after_unscattered.dat" : "", 16384);
  else 
  _sample_flux_after_unscattered_var._parameters.filename[0]='\0';
  _sample_flux_after_unscattered_var._parameters.xmin = -3.0 * _instrument_var._parameters.sampleRadius;
  _sample_flux_after_unscattered_var._parameters.xmax = 3.0 * _instrument_var._parameters.sampleRadius;
  _sample_flux_after_unscattered_var._parameters.ymin = -3.0 * _instrument_var._parameters.sampleHeight;
  _sample_flux_after_unscattered_var._parameters.ymax = 3.0 * _instrument_var._parameters.sampleHeight;
  _sample_flux_after_unscattered_var._parameters.xwidth = 0;
  _sample_flux_after_unscattered_var._parameters.yheight = 0;
  _sample_flux_after_unscattered_var._parameters.restore_neutron = 1;
  _sample_flux_after_unscattered_var._parameters.nowritefile = 0;


  /* component sample_flux_after_unscattered=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _SamplePos_var._rotation_absolute, _sample_flux_after_unscattered_var._rotation_absolute);
    rot_transpose(_res_sample_var._rotation_absolute, tr1);
    rot_mul(_sample_flux_after_unscattered_var._rotation_absolute, tr1, _sample_flux_after_unscattered_var._rotation_relative);
    _sample_flux_after_unscattered_var._rotation_is_identity =  rot_test_identity(_sample_flux_after_unscattered_var._rotation_relative);
    tc1 = coords_set(
      0, _instrument_var._parameters.samplePosY, _instrument_var._parameters.sampleRadius + u);
    rot_transpose(_SamplePos_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_flux_after_unscattered_var._position_absolute = coords_add(_SamplePos_var._position_absolute, tc2);
    tc1 = coords_sub(_res_sample_var._position_absolute, _sample_flux_after_unscattered_var._position_absolute);
    _sample_flux_after_unscattered_var._position_relative = rot_apply(_sample_flux_after_unscattered_var._rotation_absolute, tc1);
  } /* sample_flux_after_unscattered=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("sample_flux_after_unscattered", _sample_flux_after_unscattered_var._position_absolute, _sample_flux_after_unscattered_var._rotation_absolute);
  instrument->_position_absolute[40] = _sample_flux_after_unscattered_var._position_absolute;
  instrument->_position_relative[40] = _sample_flux_after_unscattered_var._position_relative;
    _sample_flux_after_unscattered_var._position_relative_is_zero =  coords_test_zero(_sample_flux_after_unscattered_var._position_relative);
  instrument->counter_N[40]  = instrument->counter_P[40] = instrument->counter_P2[40] = 0;
  instrument->counter_AbsorbProp[40]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0039_sample_flux_after_unscattered", _sample_flux_after_unscattered_var._position_absolute, _sample_flux_after_unscattered_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0039_sample_flux_after_unscattered", "nx", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0039_sample_flux_after_unscattered", "ny", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0039_sample_flux_after_unscattered", "filename", 0, "sample_flux_after_unscattered.dat", "char*");
        mccomp_param_nexus(nxhandle,"0039_sample_flux_after_unscattered", "xmin", "-0.05", "-3.0 * _instrument_var._parameters.sampleRadius","MCNUM");
        mccomp_param_nexus(nxhandle,"0039_sample_flux_after_unscattered", "xmax", "0.05", "3.0 * _instrument_var._parameters.sampleRadius","MCNUM");
        mccomp_param_nexus(nxhandle,"0039_sample_flux_after_unscattered", "ymin", "-0.05", "-3.0 * _instrument_var._parameters.sampleHeight","MCNUM");
        mccomp_param_nexus(nxhandle,"0039_sample_flux_after_unscattered", "ymax", "0.05", "3.0 * _instrument_var._parameters.sampleHeight","MCNUM");
        mccomp_param_nexus(nxhandle,"0039_sample_flux_after_unscattered", "xwidth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0039_sample_flux_after_unscattered", "yheight", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0039_sample_flux_after_unscattered", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0039_sample_flux_after_unscattered", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _sample_flux_after_unscattered_setpos */

/* component sample_cylinder_monitor=Cyl_monitor_PSD() SETTING, POSITION/ROTATION */
int _sample_cylinder_monitor_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_cylinder_monitor_setpos] component sample_cylinder_monitor=Cyl_monitor_PSD() SETTING [Cyl_monitor_PSD:0]");
  stracpy(_sample_cylinder_monitor_var._name, "sample_cylinder_monitor", 16384);
  stracpy(_sample_cylinder_monitor_var._type, "Cyl_monitor_PSD", 16384);
  _sample_cylinder_monitor_var._index=41;
  int current_setpos_index = 41;
  _sample_cylinder_monitor_var._parameters.nr = 180;
  if("sample_cylinder_monitor.dat" && strlen("sample_cylinder_monitor.dat"))
    stracpy(_sample_cylinder_monitor_var._parameters.filename, "sample_cylinder_monitor.dat" ? "sample_cylinder_monitor.dat" : "", 16384);
  else 
  _sample_cylinder_monitor_var._parameters.filename[0]='\0';
  _sample_cylinder_monitor_var._parameters.yheight = 10.0;
  _sample_cylinder_monitor_var._parameters.radius = 1.0;
  _sample_cylinder_monitor_var._parameters.restore_neutron = 1;
  _sample_cylinder_monitor_var._parameters.thmin = -180;
  _sample_cylinder_monitor_var._parameters.thmax = 180;
  _sample_cylinder_monitor_var._parameters.ny = 90;
  _sample_cylinder_monitor_var._parameters.nowritefile = 0;


  /* component sample_cylinder_monitor=Cyl_monitor_PSD() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (_instrument_var._parameters.A3)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _SamplePos_var._rotation_absolute, _sample_cylinder_monitor_var._rotation_absolute);
    rot_transpose(_sample_flux_after_unscattered_var._rotation_absolute, tr1);
    rot_mul(_sample_cylinder_monitor_var._rotation_absolute, tr1, _sample_cylinder_monitor_var._rotation_relative);
    _sample_cylinder_monitor_var._rotation_is_identity =  rot_test_identity(_sample_cylinder_monitor_var._rotation_relative);
    tc1 = coords_set(
      0, _instrument_var._parameters.samplePosY, 0);
    rot_transpose(_SamplePos_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_cylinder_monitor_var._position_absolute = coords_add(_SamplePos_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_flux_after_unscattered_var._position_absolute, _sample_cylinder_monitor_var._position_absolute);
    _sample_cylinder_monitor_var._position_relative = rot_apply(_sample_cylinder_monitor_var._rotation_absolute, tc1);
  } /* sample_cylinder_monitor=Cyl_monitor_PSD() AT ROTATED */
  DEBUG_COMPONENT("sample_cylinder_monitor", _sample_cylinder_monitor_var._position_absolute, _sample_cylinder_monitor_var._rotation_absolute);
  instrument->_position_absolute[41] = _sample_cylinder_monitor_var._position_absolute;
  instrument->_position_relative[41] = _sample_cylinder_monitor_var._position_relative;
    _sample_cylinder_monitor_var._position_relative_is_zero =  coords_test_zero(_sample_cylinder_monitor_var._position_relative);
  instrument->counter_N[41]  = instrument->counter_P[41] = instrument->counter_P2[41] = 0;
  instrument->counter_AbsorbProp[41]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0040_sample_cylinder_monitor", _sample_cylinder_monitor_var._position_absolute, _sample_cylinder_monitor_var._rotation_absolute, "Cyl_monitor_PSD");
        mccomp_param_nexus(nxhandle,"0040_sample_cylinder_monitor", "nr", "20", "180","int");
        mccomp_param_nexus(nxhandle,"0040_sample_cylinder_monitor", "filename", 0, "sample_cylinder_monitor.dat", "char*");
        mccomp_param_nexus(nxhandle,"0040_sample_cylinder_monitor", "yheight", "10", "10.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0040_sample_cylinder_monitor", "radius", "1", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0040_sample_cylinder_monitor", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0040_sample_cylinder_monitor", "thmin", "-180", "-180","MCNUM");
        mccomp_param_nexus(nxhandle,"0040_sample_cylinder_monitor", "thmax", "180", "180","MCNUM");
        mccomp_param_nexus(nxhandle,"0040_sample_cylinder_monitor", "ny", "100", "90","MCNUM");
        mccomp_param_nexus(nxhandle,"0040_sample_cylinder_monitor", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _sample_cylinder_monitor_setpos */

/* component sample_spherical_monitor=PSD_monitor_4PI() SETTING, POSITION/ROTATION */
int _sample_spherical_monitor_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_spherical_monitor_setpos] component sample_spherical_monitor=PSD_monitor_4PI() SETTING [PSD_monitor_4PI:0]");
  stracpy(_sample_spherical_monitor_var._name, "sample_spherical_monitor", 16384);
  stracpy(_sample_spherical_monitor_var._type, "PSD_monitor_4PI", 16384);
  _sample_spherical_monitor_var._index=42;
  int current_setpos_index = 42;
  _sample_spherical_monitor_var._parameters.nx = 180;
  _sample_spherical_monitor_var._parameters.ny = 90;
  if("sample_spherical_monitor.dat" && strlen("sample_spherical_monitor.dat"))
    stracpy(_sample_spherical_monitor_var._parameters.filename, "sample_spherical_monitor.dat" ? "sample_spherical_monitor.dat" : "", 16384);
  else 
  _sample_spherical_monitor_var._parameters.filename[0]='\0';
  _sample_spherical_monitor_var._parameters.nowritefile = 0;
  _sample_spherical_monitor_var._parameters.radius = 1.0;
  _sample_spherical_monitor_var._parameters.restore_neutron = 1;


  /* component sample_spherical_monitor=PSD_monitor_4PI() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (_instrument_var._parameters.A3)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _SamplePos_var._rotation_absolute, _sample_spherical_monitor_var._rotation_absolute);
    rot_transpose(_sample_cylinder_monitor_var._rotation_absolute, tr1);
    rot_mul(_sample_spherical_monitor_var._rotation_absolute, tr1, _sample_spherical_monitor_var._rotation_relative);
    _sample_spherical_monitor_var._rotation_is_identity =  rot_test_identity(_sample_spherical_monitor_var._rotation_relative);
    tc1 = coords_set(
      0, _instrument_var._parameters.samplePosY, 0);
    rot_transpose(_SamplePos_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_spherical_monitor_var._position_absolute = coords_add(_SamplePos_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_cylinder_monitor_var._position_absolute, _sample_spherical_monitor_var._position_absolute);
    _sample_spherical_monitor_var._position_relative = rot_apply(_sample_spherical_monitor_var._rotation_absolute, tc1);
  } /* sample_spherical_monitor=PSD_monitor_4PI() AT ROTATED */
  DEBUG_COMPONENT("sample_spherical_monitor", _sample_spherical_monitor_var._position_absolute, _sample_spherical_monitor_var._rotation_absolute);
  instrument->_position_absolute[42] = _sample_spherical_monitor_var._position_absolute;
  instrument->_position_relative[42] = _sample_spherical_monitor_var._position_relative;
    _sample_spherical_monitor_var._position_relative_is_zero =  coords_test_zero(_sample_spherical_monitor_var._position_relative);
  instrument->counter_N[42]  = instrument->counter_P[42] = instrument->counter_P2[42] = 0;
  instrument->counter_AbsorbProp[42]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0041_sample_spherical_monitor", _sample_spherical_monitor_var._position_absolute, _sample_spherical_monitor_var._rotation_absolute, "PSD_monitor_4PI");
        mccomp_param_nexus(nxhandle,"0041_sample_spherical_monitor", "nx", "90", "180","int");
        mccomp_param_nexus(nxhandle,"0041_sample_spherical_monitor", "ny", "90", "90","int");
        mccomp_param_nexus(nxhandle,"0041_sample_spherical_monitor", "filename", 0, "sample_spherical_monitor.dat", "char*");
        mccomp_param_nexus(nxhandle,"0041_sample_spherical_monitor", "nowritefile", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0041_sample_spherical_monitor", "radius", "1", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0041_sample_spherical_monitor", "restore_neutron", "0", "1","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _sample_spherical_monitor_setpos */

/* component BackEndMonitor=PSD_monitor() SETTING, POSITION/ROTATION */
int _BackEndMonitor_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_BackEndMonitor_setpos] component BackEndMonitor=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_BackEndMonitor_var._name, "BackEndMonitor", 16384);
  stracpy(_BackEndMonitor_var._type, "PSD_monitor", 16384);
  _BackEndMonitor_var._index=43;
  int current_setpos_index = 43;
  _BackEndMonitor_var._parameters.nx = 100;
  _BackEndMonitor_var._parameters.ny = 100;
  if("BackEndMonitor.dat" && strlen("BackEndMonitor.dat"))
    stracpy(_BackEndMonitor_var._parameters.filename, "BackEndMonitor.dat" ? "BackEndMonitor.dat" : "", 16384);
  else 
  _BackEndMonitor_var._parameters.filename[0]='\0';
  _BackEndMonitor_var._parameters.xmin = -0.4;
  _BackEndMonitor_var._parameters.xmax = 0.4;
  _BackEndMonitor_var._parameters.ymin = -0.05;
  _BackEndMonitor_var._parameters.ymax = 0.05;
  _BackEndMonitor_var._parameters.xwidth = 0;
  _BackEndMonitor_var._parameters.yheight = 0;
  _BackEndMonitor_var._parameters.restore_neutron = 1;
  _BackEndMonitor_var._parameters.nowritefile = 0;


  /* component BackEndMonitor=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _AMidt_var._rotation_absolute, _BackEndMonitor_var._rotation_absolute);
    rot_transpose(_sample_spherical_monitor_var._rotation_absolute, tr1);
    rot_mul(_BackEndMonitor_var._rotation_absolute, tr1, _BackEndMonitor_var._rotation_relative);
    _BackEndMonitor_var._rotation_is_identity =  rot_test_identity(_BackEndMonitor_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0.50);
    rot_transpose(_AMidt_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _BackEndMonitor_var._position_absolute = coords_add(_AMidt_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_spherical_monitor_var._position_absolute, _BackEndMonitor_var._position_absolute);
    _BackEndMonitor_var._position_relative = rot_apply(_BackEndMonitor_var._rotation_absolute, tc1);
  } /* BackEndMonitor=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("BackEndMonitor", _BackEndMonitor_var._position_absolute, _BackEndMonitor_var._rotation_absolute);
  instrument->_position_absolute[43] = _BackEndMonitor_var._position_absolute;
  instrument->_position_relative[43] = _BackEndMonitor_var._position_relative;
    _BackEndMonitor_var._position_relative_is_zero =  coords_test_zero(_BackEndMonitor_var._position_relative);
  instrument->counter_N[43]  = instrument->counter_P[43] = instrument->counter_P2[43] = 0;
  instrument->counter_AbsorbProp[43]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0042_BackEndMonitor", _BackEndMonitor_var._position_absolute, _BackEndMonitor_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0042_BackEndMonitor", "nx", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0042_BackEndMonitor", "ny", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0042_BackEndMonitor", "filename", 0, "BackEndMonitor.dat", "char*");
        mccomp_param_nexus(nxhandle,"0042_BackEndMonitor", "xmin", "-0.05", "-0.4","MCNUM");
        mccomp_param_nexus(nxhandle,"0042_BackEndMonitor", "xmax", "0.05", "0.4","MCNUM");
        mccomp_param_nexus(nxhandle,"0042_BackEndMonitor", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0042_BackEndMonitor", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0042_BackEndMonitor", "xwidth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0042_BackEndMonitor", "yheight", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0042_BackEndMonitor", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0042_BackEndMonitor", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _BackEndMonitor_setpos */

/* component slitBackEnd=Slit() SETTING, POSITION/ROTATION */
int _slitBackEnd_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_slitBackEnd_setpos] component slitBackEnd=Slit() SETTING [Slit:0]");
  stracpy(_slitBackEnd_var._name, "slitBackEnd", 16384);
  stracpy(_slitBackEnd_var._type, "Slit", 16384);
  _slitBackEnd_var._index=44;
  int current_setpos_index = 44;
  _slitBackEnd_var._parameters.xmin = -0.4;
  _slitBackEnd_var._parameters.xmax = 0.4;
  _slitBackEnd_var._parameters.ymin = -0.05;
  _slitBackEnd_var._parameters.ymax = 0.05;
  _slitBackEnd_var._parameters.radius = UNSET;
  _slitBackEnd_var._parameters.xwidth = UNSET;
  _slitBackEnd_var._parameters.yheight = UNSET;


  /* component slitBackEnd=Slit() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _AMidt_var._rotation_absolute, _slitBackEnd_var._rotation_absolute);
    rot_transpose(_BackEndMonitor_var._rotation_absolute, tr1);
    rot_mul(_slitBackEnd_var._rotation_absolute, tr1, _slitBackEnd_var._rotation_relative);
    _slitBackEnd_var._rotation_is_identity =  rot_test_identity(_slitBackEnd_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0.50 + u);
    rot_transpose(_AMidt_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _slitBackEnd_var._position_absolute = coords_add(_AMidt_var._position_absolute, tc2);
    tc1 = coords_sub(_BackEndMonitor_var._position_absolute, _slitBackEnd_var._position_absolute);
    _slitBackEnd_var._position_relative = rot_apply(_slitBackEnd_var._rotation_absolute, tc1);
  } /* slitBackEnd=Slit() AT ROTATED */
  DEBUG_COMPONENT("slitBackEnd", _slitBackEnd_var._position_absolute, _slitBackEnd_var._rotation_absolute);
  instrument->_position_absolute[44] = _slitBackEnd_var._position_absolute;
  instrument->_position_relative[44] = _slitBackEnd_var._position_relative;
    _slitBackEnd_var._position_relative_is_zero =  coords_test_zero(_slitBackEnd_var._position_relative);
  instrument->counter_N[44]  = instrument->counter_P[44] = instrument->counter_P2[44] = 0;
  instrument->counter_AbsorbProp[44]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0043_slitBackEnd", _slitBackEnd_var._position_absolute, _slitBackEnd_var._rotation_absolute, "Slit");
        mccomp_param_nexus(nxhandle,"0043_slitBackEnd", "xmin", "UNSET", "-0.4","MCNUM");
        mccomp_param_nexus(nxhandle,"0043_slitBackEnd", "xmax", "UNSET", "0.4","MCNUM");
        mccomp_param_nexus(nxhandle,"0043_slitBackEnd", "ymin", "UNSET", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0043_slitBackEnd", "ymax", "UNSET", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0043_slitBackEnd", "radius", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0043_slitBackEnd", "xwidth", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0043_slitBackEnd", "yheight", "UNSET", "UNSET","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _slitBackEnd_setpos */

/* component filter_gen=Filter_gen() SETTING, POSITION/ROTATION */
int _filter_gen_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_filter_gen_setpos] component filter_gen=Filter_gen() SETTING [Filter_gen:0]");
  stracpy(_filter_gen_var._name, "filter_gen", 16384);
  stracpy(_filter_gen_var._type, "Filter_gen", 16384);
  _filter_gen_var._index=45;
  int current_setpos_index = 45;
  if("Be.trm" && strlen("Be.trm"))
    stracpy(_filter_gen_var._parameters.filename, "Be.trm" ? "Be.trm" : "", 16384);
  else 
  _filter_gen_var._parameters.filename[0]='\0';
  _filter_gen_var._parameters.options[0]='\0';
  _filter_gen_var._parameters.xmin = -0.5;
  _filter_gen_var._parameters.xmax = 0.5;
  _filter_gen_var._parameters.ymin = -0.05;
  _filter_gen_var._parameters.ymax = 0.05;
  _filter_gen_var._parameters.xwidth = 0;
  _filter_gen_var._parameters.yheight = 0;
  _filter_gen_var._parameters.thickness = 1;
  _filter_gen_var._parameters.scaling = 1;
  _filter_gen_var._parameters.verbose = 0;


  /* component filter_gen=Filter_gen() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _AMidt_var._rotation_absolute, _filter_gen_var._rotation_absolute);
    rot_transpose(_slitBackEnd_var._rotation_absolute, tr1);
    rot_mul(_filter_gen_var._rotation_absolute, tr1, _filter_gen_var._rotation_relative);
    _filter_gen_var._rotation_is_identity =  rot_test_identity(_filter_gen_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0.60);
    rot_transpose(_AMidt_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _filter_gen_var._position_absolute = coords_add(_AMidt_var._position_absolute, tc2);
    tc1 = coords_sub(_slitBackEnd_var._position_absolute, _filter_gen_var._position_absolute);
    _filter_gen_var._position_relative = rot_apply(_filter_gen_var._rotation_absolute, tc1);
  } /* filter_gen=Filter_gen() AT ROTATED */
  DEBUG_COMPONENT("filter_gen", _filter_gen_var._position_absolute, _filter_gen_var._rotation_absolute);
  instrument->_position_absolute[45] = _filter_gen_var._position_absolute;
  instrument->_position_relative[45] = _filter_gen_var._position_relative;
    _filter_gen_var._position_relative_is_zero =  coords_test_zero(_filter_gen_var._position_relative);
  instrument->counter_N[45]  = instrument->counter_P[45] = instrument->counter_P2[45] = 0;
  instrument->counter_AbsorbProp[45]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0044_filter_gen", _filter_gen_var._position_absolute, _filter_gen_var._rotation_absolute, "Filter_gen");
        mccomp_param_nexus(nxhandle,"0044_filter_gen", "filename", 0, "Be.trm", "char*");
        mccomp_param_nexus(nxhandle,"0044_filter_gen", "options", 0, 0, "char*");
        mccomp_param_nexus(nxhandle,"0044_filter_gen", "xmin", "-0.05", "-0.5","MCNUM");
        mccomp_param_nexus(nxhandle,"0044_filter_gen", "xmax", "0.05", "0.5","MCNUM");
        mccomp_param_nexus(nxhandle,"0044_filter_gen", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0044_filter_gen", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0044_filter_gen", "xwidth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0044_filter_gen", "yheight", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0044_filter_gen", "thickness", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0044_filter_gen", "scaling", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0044_filter_gen", "verbose", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _filter_gen_setpos */

/* component BeFilter=PowderN() SETTING, POSITION/ROTATION */
int _BeFilter_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_BeFilter_setpos] component BeFilter=PowderN() SETTING [PowderN:0]");
  stracpy(_BeFilter_var._name, "BeFilter", 16384);
  stracpy(_BeFilter_var._type, "PowderN", 16384);
  _BeFilter_var._index=46;
  int current_setpos_index = 46;
  if("Be.laz" && strlen("Be.laz"))
    stracpy(_BeFilter_var._parameters.reflections, "Be.laz" ? "Be.laz" : "", 16384);
  else 
  _BeFilter_var._parameters.reflections[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_BeFilter_var._parameters.geometry, "NULL" ? "NULL" : "", 16384);
  else 
  _BeFilter_var._parameters.geometry[0]='\0';
  _BeFilter_var._parameters.format[0] = 0;
  _BeFilter_var._parameters.format[1] = 0;
  _BeFilter_var._parameters.format[2] = 0;
  _BeFilter_var._parameters.format[3] = 0;
  _BeFilter_var._parameters.format[4] = 0;
  _BeFilter_var._parameters.format[5] = 0;
  _BeFilter_var._parameters.format[6] = 0;
  _BeFilter_var._parameters.format[7] = 0;
  _BeFilter_var._parameters.format[8] = 0;
  _BeFilter_var._parameters.radius = 0;
  _BeFilter_var._parameters.yheight = 0.1;
  _BeFilter_var._parameters.xwidth = 0.1;
  _BeFilter_var._parameters.zdepth = 0.1;
  _BeFilter_var._parameters.thickness = 0;
  _BeFilter_var._parameters.pack = 1;
  _BeFilter_var._parameters.Vc = 0;
  _BeFilter_var._parameters.sigma_abs = 0;
  _BeFilter_var._parameters.sigma_inc = 0;
  _BeFilter_var._parameters.delta_d_d = 0;
  _BeFilter_var._parameters.p_inc = 1e-4;
  _BeFilter_var._parameters.p_transmit = 0.1;
  _BeFilter_var._parameters.DW = 0;
  _BeFilter_var._parameters.nb_atoms = 1;
  _BeFilter_var._parameters.d_omega = 0;
  _BeFilter_var._parameters.d_phi = 0;
  _BeFilter_var._parameters.tth_sign = 0;
  _BeFilter_var._parameters.p_interact = 0.8;
  _BeFilter_var._parameters.concentric = 0;
  _BeFilter_var._parameters.density = 0;
  _BeFilter_var._parameters.weight = 0;
  _BeFilter_var._parameters.barns = 1;
  _BeFilter_var._parameters.Strain = 0;
  _BeFilter_var._parameters.focus_flip = 0;
  _BeFilter_var._parameters.target_index = 0;
  _BeFilter_var._parameters.order = 1;


  /* component BeFilter=PowderN() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _AMidt_var._rotation_absolute, _BeFilter_var._rotation_absolute);
    rot_transpose(_filter_gen_var._rotation_absolute, tr1);
    rot_mul(_BeFilter_var._rotation_absolute, tr1, _BeFilter_var._rotation_relative);
    _BeFilter_var._rotation_is_identity =  rot_test_identity(_BeFilter_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0.51);
    rot_transpose(_AMidt_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _BeFilter_var._position_absolute = coords_add(_AMidt_var._position_absolute, tc2);
    tc1 = coords_sub(_filter_gen_var._position_absolute, _BeFilter_var._position_absolute);
    _BeFilter_var._position_relative = rot_apply(_BeFilter_var._rotation_absolute, tc1);
  } /* BeFilter=PowderN() AT ROTATED */
  DEBUG_COMPONENT("BeFilter", _BeFilter_var._position_absolute, _BeFilter_var._rotation_absolute);
  instrument->_position_absolute[46] = _BeFilter_var._position_absolute;
  instrument->_position_relative[46] = _BeFilter_var._position_relative;
    _BeFilter_var._position_relative_is_zero =  coords_test_zero(_BeFilter_var._position_relative);
  instrument->counter_N[46]  = instrument->counter_P[46] = instrument->counter_P2[46] = 0;
  instrument->counter_AbsorbProp[46]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0045_BeFilter", _BeFilter_var._position_absolute, _BeFilter_var._rotation_absolute, "PowderN");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "reflections", "NULL", "Be.laz", "char*");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "geometry", "NULL", "NULL", "char*");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "format", "{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }", "{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "radius", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "yheight", "0", "0.1","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "xwidth", "0", "0.1","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "zdepth", "0", "0.1","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "thickness", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "pack", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "Vc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "sigma_abs", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "sigma_inc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "delta_d_d", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "p_inc", "0.1", "1e-4","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "p_transmit", "0.1", "0.1","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "DW", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "nb_atoms", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "d_omega", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "d_phi", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "tth_sign", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "p_interact", "0.8", "0.8","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "concentric", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "density", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "weight", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "barns", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "Strain", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "focus_flip", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "target_index", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0045_BeFilter", "order", "1", "1","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _BeFilter_setpos */

_class_Progress_bar *class_Progress_bar_init(_class_Progress_bar *_comp
) {
  #define profile (_comp->_parameters.profile)
  #define percent (_comp->_parameters.percent)
  #define flag_save (_comp->_parameters.flag_save)
  #define minutes (_comp->_parameters.minutes)
  #define IntermediateCnts (_comp->_parameters.IntermediateCnts)
  #define StartTime (_comp->_parameters.StartTime)
  #define EndTime (_comp->_parameters.EndTime)
  #define CurrentTime (_comp->_parameters.CurrentTime)
  #define infostring (_comp->_parameters.infostring)
  SIG_MESSAGE("[_Origin_init] component Origin=Progress_bar() INITIALISE [Progress_bar:0]");

  IntermediateCnts = 0;
  StartTime = 0;
  EndTime = 0;
  CurrentTime = 0;

  fprintf (stdout, "[%s] Initialize\n", instrument_name);
  if (percent * mcget_ncount () / 100 < 1e5) {
    percent = 1e5 * 100.0 / mcget_ncount ();
  }
  #ifdef OPENACC
  time (&StartTime);
  #endif

  #ifdef USE_MPI
  sprintf (infostring, "(%i MPI processes) ", mpi_node_count);
  #else
  sprintf (infostring, "(single process) ");
  #endif
  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  #undef infostring
  return(_comp);
} /* class_Progress_bar_init */

_class_Source_gen4 *class_Source_gen4_init(_class_Source_gen4 *_comp
) {
  #define flux_file (_comp->_parameters.flux_file)
  #define xdiv_file (_comp->_parameters.xdiv_file)
  #define ydiv_file (_comp->_parameters.ydiv_file)
  #define radius (_comp->_parameters.radius)
  #define dist (_comp->_parameters.dist)
  #define xw (_comp->_parameters.xw)
  #define yh (_comp->_parameters.yh)
  #define E0 (_comp->_parameters.E0)
  #define dE (_comp->_parameters.dE)
  #define Lambda0 (_comp->_parameters.Lambda0)
  #define dLambda (_comp->_parameters.dLambda)
  #define I1 (_comp->_parameters.I1)
  #define h (_comp->_parameters.h)
  #define w (_comp->_parameters.w)
  #define gaussian (_comp->_parameters.gaussian)
  #define verbose (_comp->_parameters.verbose)
  #define T1 (_comp->_parameters.T1)
  #define flux_file_perAA (_comp->_parameters.flux_file_perAA)
  #define flux_file_log (_comp->_parameters.flux_file_log)
  #define Lmin (_comp->_parameters.Lmin)
  #define Lmax (_comp->_parameters.Lmax)
  #define Emin (_comp->_parameters.Emin)
  #define Emax (_comp->_parameters.Emax)
  #define T2 (_comp->_parameters.T2)
  #define I2 (_comp->_parameters.I2)
  #define T3 (_comp->_parameters.T3)
  #define I3 (_comp->_parameters.I3)
  #define length (_comp->_parameters.length)
  #define phi_init (_comp->_parameters.phi_init)
  #define theta_init (_comp->_parameters.theta_init)
  #define HEtailA (_comp->_parameters.HEtailA)
  #define HEtailL0 (_comp->_parameters.HEtailL0)
  #define pTable (_comp->_parameters.pTable)
  #define pTable_x (_comp->_parameters.pTable_x)
  #define pTable_y (_comp->_parameters.pTable_y)
  #define p_in (_comp->_parameters.p_in)
  #define lambda0 (_comp->_parameters.lambda0)
  #define lambda02 (_comp->_parameters.lambda02)
  #define lambda0b (_comp->_parameters.lambda0b)
  #define lambda02b (_comp->_parameters.lambda02b)
  #define lambda0c (_comp->_parameters.lambda0c)
  #define lambda02c (_comp->_parameters.lambda02c)
  #define L2P (_comp->_parameters.L2P)
  #define L2Pb (_comp->_parameters.L2Pb)
  #define L2Pc (_comp->_parameters.L2Pc)
  #define pTable_xmin (_comp->_parameters.pTable_xmin)
  #define pTable_ymin (_comp->_parameters.pTable_ymin)
  #define pTable_xmax (_comp->_parameters.pTable_xmax)
  #define pTable_ymax (_comp->_parameters.pTable_ymax)
  #define pTable_xsum (_comp->_parameters.pTable_xsum)
  #define pTable_ysum (_comp->_parameters.pTable_ysum)
  #define pTable_dxmin (_comp->_parameters.pTable_dxmin)
  #define pTable_dxmax (_comp->_parameters.pTable_dxmax)
  #define pTable_dymin (_comp->_parameters.pTable_dymin)
  #define pTable_dymax (_comp->_parameters.pTable_dymax)
  SIG_MESSAGE("[_source_init] component source=Source_gen4() INITIALISE [Source_gen4:0]");

  double source_area, k;
  pTable_xsum = pTable_ysum = 0;

  /* spectrum characteristics */
  if (flux_file && strlen (flux_file) > 0) {
    if (Table_Read (&pTable, flux_file, 1) <= 0) /* read 1st block data from file into pTable */
      exit (fprintf (stderr, "Source_gen: %s: can not read file %s\n", NAME_CURRENT_COMP, flux_file));
    /* put table in Log scale */
    int i;
    if (pTable.columns < 2)
      exit (fprintf (stderr, "Source_gen: %s: Flux file %s should contain at least 2 columns\n", NAME_CURRENT_COMP, flux_file));
    double table_lmin = FLT_MAX, table_lmax = -FLT_MAX;
    double tmin = FLT_MAX, tmax = -FLT_MAX;
    for (i = 0; i < pTable.rows; i++) {
      double val = Table_Index (pTable, i, 1);
      val = Table_Index (pTable, i, 0); /* lambda */
      if (val > tmax)
        tmax = val;
      if (val < tmin)
        tmin = val;
    }
    for (i = 0; i < pTable.rows; i++) {
      double val = Table_Index (pTable, i, 1);
      if (val < 0)
        fprintf (stderr, "Source_gen: %s: File %s has negative flux at row %i\n", NAME_CURRENT_COMP, flux_file, i + 1);
      if (flux_file_log)
        val = log (val > 0 ? val : tmin / 10);
      Table_SetElement (&pTable, i, 1, val);
      val = Table_Index (pTable, i, 0); /* lambda */
      if (val > table_lmax)
        table_lmax = val;
      if (val < table_lmin)
        table_lmin = val;
    }
    if (!Lmin && !Lmax && !Lambda0 && !dLambda && !E0 && !dE && !Emin && !Emax) {
      Lmin = table_lmin;
      Lmax = table_lmax;
    }
    if (Lmax > table_lmax) {
      if (verbose)
        fprintf (stderr, "Source_gen: %s: Maximum wavelength %g is beyond table range upper limit %g. Constraining.\n", NAME_CURRENT_COMP, Lmax, table_lmax);
      Lmax = table_lmax;
    }
    if (Lmin < table_lmin) {
      if (verbose)
        fprintf (stderr, "Source_gen: %s: Minimum wavelength %g is below table range lower limit %g. Constraining.\n", NAME_CURRENT_COMP, Lmin, table_lmin);
      Lmin = table_lmin;
    }
  } else {
    k = 1.38066e-23; /* k_B */
    if (T1 > 0) {
      lambda0 = 1.0e10 * sqrt (HBAR * HBAR * 4.0 * PI * PI / 2.0 / MNEUTRON / k / T1);
      lambda02 = lambda0 * lambda0;
      L2P = 2 * lambda02 * lambda02;
    } else {
      lambda0 = Lambda0;
    }

    if (T2 > 0) {
      lambda0b = 1.0e10 * sqrt (HBAR * HBAR * 4.0 * PI * PI / 2.0 / MNEUTRON / k / T2);
      lambda02b = lambda0b * lambda0b;
      L2Pb = 2 * lambda02b * lambda02b;
    } else {
      lambda0b = Lambda0;
    }

    if (T3 > 0) {
      lambda0c = 1.0e10 * sqrt (HBAR * HBAR * 4.0 * PI * PI / 2.0 / MNEUTRON / k / T3);
      lambda02c = lambda0c * lambda0c;
      L2Pc = 2 * lambda02c * lambda02c;
    } else {
      lambda0c = Lambda0;
    }
  }

  /* now read position-divergence files, if any */
  if (xdiv_file && strlen (xdiv_file) > 0) {
    int i, j;
    if (Table_Read (&pTable_x, xdiv_file, 1) <= 0) /* read 1st block data from file into pTable */
      exit (fprintf (stderr, "Source_gen: %s: can not read file %s\n", NAME_CURRENT_COMP, xdiv_file));
    pTable_xsum = 0;
    for (i = 0; i < pTable_x.rows; i++)
      for (j = 0; j < pTable_x.columns; j++)
        pTable_xsum += Table_Index (pTable_x, i, j);

    /* now extract limits */
    char** parsing;
    char xylimits[1024];
    strcpy (xylimits, "");
    parsing = Table_ParseHeader (pTable_x.header, "xlimits", "xylimits", NULL);

    if (parsing) {
      if (parsing[0])
        strcpy (xylimits, str_dup_numeric (parsing[0]));
      if (parsing[1] && !strlen (xylimits))
        strcpy (xylimits, str_dup_numeric (parsing[1]));
      for (i = 0; i <= 1; i++) {
        if (parsing[i])
          free (parsing[i]);
      }
      free (parsing);
    }
    i = sscanf (xylimits, "%lg %lg %lg %lg", &(pTable_xmin), &(pTable_xmax), &(pTable_dxmin), &(pTable_dxmax));
    if (i != 2 && i != 4 && verbose)
      fprintf (stderr, "Source_gen: %s: invalid xylimits '%s' from file %s. extracted %i values\n", NAME_CURRENT_COMP, xylimits, xdiv_file, i);

    if (!w)
      w = pTable_xmax - pTable_xmin;
    if (!xw && !dist)
      xw = fabs (pTable_dxmax - pTable_dxmin);
  }

  if (ydiv_file && strlen (ydiv_file) > 0) {
    int i, j;
    if (Table_Read (&pTable_y, ydiv_file, 1) <= 0) /* read 1st block data from file into pTable */
      exit (fprintf (stderr, "Source_gen: %s: can not read file %s\n", NAME_CURRENT_COMP, ydiv_file));
    pTable_ysum = 0;
    for (i = 0; i < pTable_y.rows; i++)
      for (j = 0; j < pTable_y.columns; j++)
        pTable_ysum += Table_Index (pTable_y, i, j);

    /* now extract limits */
    char** parsing;
    char xylimits[1024];
    strcpy (xylimits, "");
    parsing = Table_ParseHeader (pTable_y.header, "xlimits", "xylimits", NULL);

    if (parsing) {
      if (parsing[0])
        strcpy (xylimits, str_dup_numeric (parsing[0]));
      if (parsing[1] && !strlen (xylimits))
        strcpy (xylimits, str_dup_numeric (parsing[1]));
      for (i = 0; i <= 1; i++) {
        if (parsing[i])
          free (parsing[i]);
      }
      free (parsing);
    }
    i = sscanf (xylimits, "%lg %lg %lg %lg", &(pTable_ymin), &(pTable_ymax), &(pTable_dymin), &(pTable_dymax));
    if (i != 2 && i != 4 && verbose)
      fprintf (stderr, "Source_gen: %s: invalid xylimits '%s' from file %s. extracted %i values\n", NAME_CURRENT_COMP, xylimits, ydiv_file, i);
    if (!h)
      h = pTable_ymax - pTable_ymin;
    if (!yh && !dist)
      yh = fabs (pTable_dymax - pTable_dymin);
  }

  /* tests for parameter values */
  if (Emin < 0 || Emax < 0 || Lmin < 0 || Lmax < 0 || E0 < 0 || dE < 0 || Lambda0 < 0 || dLambda < 0) {
    fprintf (stderr,
             "Source_gen: %s: Error: Negative average\n"
             "            or range values for wavelength or energy encountered\n",
             NAME_CURRENT_COMP);
    exit (-1);
  }
  if ((Emin == 0 && Emax > 0) || (dE > 0 && dE >= E0)) {
    fprintf (stderr, "Source_gen: %s: Error: minimal energy cannot be less or equal zero\n", NAME_CURRENT_COMP);
    exit (-1);
  }
  if ((Emax >= Emin) && (Emin > 0)) {
    E0 = (Emax + Emin) / 2;
    dE = (Emax - Emin) / 2;
  }
  if ((E0 > dE) && (dE >= 0)) {
    Lmin = sqrt (81.81 / (E0 + dE)); /* Angstroem */
    Lmax = sqrt (81.81 / (E0 - dE));
  }
  if (Lmax > 0) {
    Lambda0 = (Lmax + Lmin) / 2;
    dLambda = (Lmax - Lmin) / 2;
  }
  if ((Lambda0 < dLambda) || (dLambda < 0)) {
    fprintf (stderr, "Source_gen: %s: Error: Wavelength range %.3f +/- %.3f AA calculated \n", NAME_CURRENT_COMP, Lambda0, dLambda);
    fprintf (stderr, "- whole wavelength range must be >= 0 \n");
    fprintf (stderr, "- range must be > 0; otherwise intensity gets zero, use other sources in this case \n\n");
    exit (-1);
  }

  radius = fabs (radius);
  w = fabs (w);
  h = fabs (h);
  I1 = fabs (I1);
  Lambda0 = fabs (Lambda0);
  dLambda = fabs (dLambda);
  xw = fabs (xw);
  yh = fabs (yh);
  dist = fabs (dist);

  if (dist == 0) {
    fprintf (stderr,
             "Source_gen: %s: warning: focusing distance is null.\n"
             "            xw and yh interpreted as full divergence in [deg]\n",
             NAME_CURRENT_COMP);
  }
  Lmin = Lambda0 - dLambda; /* Angstroem */
  Lmax = Lambda0 + dLambda;

  /* compute initial weight factor p_in to get [n/s] */
  if ((I1 > 0 && T1 >= 0) || (flux_file && strlen (flux_file) > 0)) { /* the I1,2,3 are usually in [n/s/cm2/st/AA] */
    if (radius)
      source_area = radius * radius * PI * 1e4; /* circular cm^2 */
    else
      source_area = h * w * 1e4; /* square cm^2 */
    p_in = source_area;          /* cm2 */
    p_in *= (Lmax - Lmin);       /* AA. 1 bin=AA/n */
    if (flux_file && strlen (flux_file) && !flux_file_perAA)
      p_in *= pTable.rows / (Lmax - Lmin);
  } else
    p_in = (I1 > 0 ? I1 : 1) / 4 / PI; /* Small angle approx. */
  p_in /= mcget_ncount ();
  if (!T1 && I1)
    p_in *= I1;

  if (radius == 0 && h == 0 && w == 0) {
    fprintf (stderr, "Source_gen: %s: Error: Please specify source geometry (radius, h, w)\n", NAME_CURRENT_COMP);
    exit (-1);
  }
  if (xw * yh == 0) {
    fprintf (stderr, "Source_gen: %s: Error: Please specify source target (xw, yh)\n", NAME_CURRENT_COMP);
    exit (-1);
  }

  if (verbose) {
    printf ("Source_gen: component %s ", NAME_CURRENT_COMP);
    if ((h == 0) || (w == 0))
      printf ("(disk, radius=%g)", radius);
    else
      printf ("(square %g x %g)", h, w);
    printf ("\n            spectra ");
    printf ("%.3f to %.3f AA (%.3f to %.3f meV)", Lmin, Lmax, 81.81 / Lmax / Lmax, 81.81 / Lmin / Lmin);
    if (gaussian)
      printf (", gaussian divergence beam");
    printf ("\n");
    if (flux_file && strlen (flux_file) > 0) {
      printf ("  File %s for flux distribution used. Flux is dPhi/dLambda in [n/s/AA]. \n", flux_file);
      Table_Info (pTable);
    } else if (T1 >= 0 && I1) {
      if (T1 != 0)
        printf ("            T1=%.1f K (%.3f AA)", T1, lambda0);
      if (T2 * I2 != 0)
        printf (", T2=%.1f K (%.3f AA)", T2, lambda0b);
      if (T3 * I3 != 0)
        printf (", T3=%.1f K (%.3f AA)", T3, lambda0c);
      if (T1)
        printf ("\n");
      printf ("  Flux is dPhi/dLambda in [n/s/cm2].\n");
    } else {
      printf ("  Flux is Phi in [n/s].\n");
    }
    if (xdiv_file && strlen (xdiv_file) > 0)
      printf ("  File %s x=[%g:%g] [m] xdiv=[%g:%g] [deg] used as horizontal phase space distribution.\n", xdiv_file, pTable_xmin, pTable_xmax, pTable_dxmin,
              pTable_dxmax);
    if (ydiv_file && strlen (ydiv_file) > 0)
      printf ("  File %s y=[%g:%g] [m] ydiv=[%g:%g] [deg] used as vertical phase space distribution.\n", ydiv_file, pTable_ymin, pTable_ymax, pTable_dymin,
              pTable_dymax);
  } else if (verbose == -1)
    printf ("Source_gen: component %s inactivated", NAME_CURRENT_COMP);
  #undef flux_file
  #undef xdiv_file
  #undef ydiv_file
  #undef radius
  #undef dist
  #undef xw
  #undef yh
  #undef E0
  #undef dE
  #undef Lambda0
  #undef dLambda
  #undef I1
  #undef h
  #undef w
  #undef gaussian
  #undef verbose
  #undef T1
  #undef flux_file_perAA
  #undef flux_file_log
  #undef Lmin
  #undef Lmax
  #undef Emin
  #undef Emax
  #undef T2
  #undef I2
  #undef T3
  #undef I3
  #undef length
  #undef phi_init
  #undef theta_init
  #undef HEtailA
  #undef HEtailL0
  #undef pTable
  #undef pTable_x
  #undef pTable_y
  #undef p_in
  #undef lambda0
  #undef lambda02
  #undef lambda0b
  #undef lambda02b
  #undef lambda0c
  #undef lambda02c
  #undef L2P
  #undef L2Pb
  #undef L2Pc
  #undef pTable_xmin
  #undef pTable_ymin
  #undef pTable_xmax
  #undef pTable_ymax
  #undef pTable_xsum
  #undef pTable_ysum
  #undef pTable_dxmin
  #undef pTable_dxmax
  #undef pTable_dymin
  #undef pTable_dymax
  return(_comp);
} /* class_Source_gen4_init */

_class_PSD_monitor *class_PSD_monitor_init(_class_PSD_monitor *_comp
) {
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_StartOfGuideMonitor_init] component StartOfGuideMonitor=PSD_monitor() INITIALISE [PSD_monitor:0]");

  if (xwidth > 0) {
    xmax = xwidth / 2;
    xmin = -xmax;
  }
  if (yheight > 0) {
    ymax = yheight / 2;
    ymin = -ymax;
  }

  if ((xmin >= xmax) || (ymin >= ymax)) {
    printf ("PSD_monitor: %s: Null detection area !\n"
            "ERROR        (xwidth,yheight,xmin,xmax,ymin,ymax). Exiting",
            NAME_CURRENT_COMP);
    exit (0);
  }

  PSD_N = create_darr2d (nx, ny);
  PSD_p = create_darr2d (nx, ny);
  PSD_p2 = create_darr2d (nx, ny);

  // Use instance name for monitor output if no input was given
  if (!strcmp (filename, "\0"))
    sprintf (filename, "%s", NAME_CURRENT_COMP);
  #undef nx
  #undef ny
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef restore_neutron
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_init */

_class_Elliptic_guide_gravity *class_Elliptic_guide_gravity_init(_class_Elliptic_guide_gravity *_comp
) {
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define l (_comp->_parameters.l)
  #define linxw (_comp->_parameters.linxw)
  #define loutxw (_comp->_parameters.loutxw)
  #define linyh (_comp->_parameters.linyh)
  #define loutyh (_comp->_parameters.loutyh)
  #define majorAxisxw (_comp->_parameters.majorAxisxw)
  #define minorAxisxw (_comp->_parameters.minorAxisxw)
  #define majorAxisyh (_comp->_parameters.majorAxisyh)
  #define minorAxisyh (_comp->_parameters.minorAxisyh)
  #define majorAxisoffsetxw (_comp->_parameters.majorAxisoffsetxw)
  #define majorAxisoffsetyh (_comp->_parameters.majorAxisoffsetyh)
  #define dimensionsAt (_comp->_parameters.dimensionsAt)
  #define option (_comp->_parameters.option)
  #define R0 (_comp->_parameters.R0)
  #define Qc (_comp->_parameters.Qc)
  #define alpha (_comp->_parameters.alpha)
  #define m (_comp->_parameters.m)
  #define W (_comp->_parameters.W)
  #define alpharight (_comp->_parameters.alpharight)
  #define mright (_comp->_parameters.mright)
  #define alphaleft (_comp->_parameters.alphaleft)
  #define mleft (_comp->_parameters.mleft)
  #define alphatop (_comp->_parameters.alphatop)
  #define mtop (_comp->_parameters.mtop)
  #define alphabottom (_comp->_parameters.alphabottom)
  #define mbottom (_comp->_parameters.mbottom)
  #define verbose (_comp->_parameters.verbose)
  #define enableGravity (_comp->_parameters.enableGravity)
  #define curvature (_comp->_parameters.curvature)
  #define nSegments (_comp->_parameters.nSegments)
  #define mvaluesright (_comp->_parameters.mvaluesright)
  #define mvaluesleft (_comp->_parameters.mvaluesleft)
  #define mvaluestop (_comp->_parameters.mvaluestop)
  #define mvaluesbottom (_comp->_parameters.mvaluesbottom)
  #define seglength (_comp->_parameters.seglength)
  #define guideInfo (_comp->_parameters.guideInfo)
  #define Gx0 (_comp->_parameters.Gx0)
  #define Gy0 (_comp->_parameters.Gy0)
  #define Gz0 (_comp->_parameters.Gz0)
  #define Circ (_comp->_parameters.Circ)
  #define dynamicalSegLength (_comp->_parameters.dynamicalSegLength)
  SIG_MESSAGE("[_Insert_init] component Insert=Elliptic_guide_gravity() INITIALISE [Elliptic_guide_gravity:0]");

  ///////////////////////////////////////////////////////////////////////////
  /////////////// Test user input
  ///////////////////////////////////////////////////////////////////////////

  if (strcmp (verbose, "on") == 0)
    guideInfo.verboseSetting = 1;
  else
    guideInfo.verboseSetting = 0;

  guideInfo.R0Arr[RightSide] = R0;
  guideInfo.QcArr[RightSide] = Qc;
  guideInfo.alphaArr[RightSide] = alpharight;
  guideInfo.mArr[RightSide] = mright;
  guideInfo.WArr[RightSide] = W;

  guideInfo.R0Arr[TopSide] = R0;
  guideInfo.QcArr[TopSide] = Qc;
  guideInfo.alphaArr[TopSide] = alphatop;
  guideInfo.mArr[TopSide] = mtop;
  guideInfo.WArr[TopSide] = W;

  guideInfo.R0Arr[LeftSide] = R0;
  guideInfo.QcArr[LeftSide] = Qc;
  guideInfo.alphaArr[LeftSide] = alphaleft;
  guideInfo.mArr[LeftSide] = mleft;
  guideInfo.WArr[LeftSide] = W;

  guideInfo.R0Arr[BottomSide] = R0;
  guideInfo.QcArr[BottomSide] = Qc;
  guideInfo.alphaArr[BottomSide] = alphabottom;
  guideInfo.mArr[BottomSide] = mbottom;
  guideInfo.WArr[BottomSide] = W;

  int sides;
  for (sides = RightSide; sides <= BottomSide; sides++) {
    if (guideInfo.alphaArr[sides] == -1)
      guideInfo.alphaArr[sides] = alpha;
    if (guideInfo.mArr[sides] == -1)
      guideInfo.mArr[sides] = m;
  }

  // Test user input for illegal values
  int inputErrors = 0;
  // Lower or equal to zero
  if (l <= 0)
    inputErrors += guide_elliptical_illegalInputLessThanZero ("length", guideInfo.verboseSetting);
  if (guideInfo.alphaArr[TopSide] < 0)
    inputErrors += guide_elliptical_illegalInputLessThanZero ("alphatop", guideInfo.verboseSetting);
  if (guideInfo.mArr[TopSide] < 0)
    inputErrors += guide_elliptical_illegalInputLessThanZero ("mtop", guideInfo.verboseSetting);

  if (guideInfo.alphaArr[BottomSide] < 0)
    inputErrors += guide_elliptical_illegalInputLessThanZero ("alphabottom", guideInfo.verboseSetting);
  if (guideInfo.mArr[BottomSide] < 0)
    inputErrors += guide_elliptical_illegalInputLessThanZero ("mbottom", guideInfo.verboseSetting);

  if (guideInfo.alphaArr[RightSide] < 0)
    inputErrors += guide_elliptical_illegalInputLessThanZero ("alpharight", guideInfo.verboseSetting);
  if (guideInfo.mArr[RightSide] < 0)
    inputErrors += guide_elliptical_illegalInputLessThanZero ("mright", guideInfo.verboseSetting);

  if (guideInfo.alphaArr[LeftSide] < 0)
    inputErrors += guide_elliptical_illegalInputLessThanZero ("alphaleft", guideInfo.verboseSetting);
  if (guideInfo.mArr[LeftSide] < 0)
    inputErrors += guide_elliptical_illegalInputLessThanZero ("mleft", guideInfo.verboseSetting);

  // Focal points result in hyperbola instead of an ellipse
  if (l <= -linxw - loutxw)
    inputErrors += guide_elliptical_illegalInputFocalPointsHyperbola ("linw", "loutw", linxw, loutxw, guideInfo.verboseSetting);
  if (l <= -linyh - loutyh)
    inputErrors += guide_elliptical_illegalInputFocalPointsHyperbola ("linh", "louth", linyh, loutyh, guideInfo.verboseSetting);

  if (strcmp (dimensionsAt, "entrance") != 0 && strcmp (dimensionsAt, "mid") != 0 && strcmp (dimensionsAt, "exit") != 0) {
    inputErrors += 1;
    printf ("dimensionsAt were given an incorrect input."
            "Input must be string containing \"entrance\",\"mid\" or \"exit\" \n");
  }

  // Terminate program if any input errors occurred
  if (inputErrors != 0) {
    exit (printf ("\nCRITICAL ERROR(S) IN COMPONENT %s"
                  " CONSIDER CHECKING USER INPUT AS %d INPUT ERRORS WAS FOUND.\n",
                  NAME_CURRENT_COMP, inputErrors));
  }

  ///////////////////////////////////////////////////////////////////////////
  /////////////// Calculate intern guide values from user input
  ///////////////////////////////////////////////////////////////////////////

  /*  Calculate the foci line for the ellipses.
          These can be used to calculate the axes of the ellipses
          using pyth and defination of the ellipse that says distance
          between the foci and every point on the ellipse is constant.
  */
  int directDefination = 0;

  if (majorAxisyh != 0 || minorAxisyh != 0 || majorAxisxw != 0 || minorAxisxw != 0) {
    directDefination = 1;
    guideInfo.Length = l;

    guideInfo.ellipseMajorAxis[RightSide] = majorAxisxw;
    guideInfo.ellipseMinorAxis[RightSide] = minorAxisxw;
    guideInfo.ellipseMajorOffset[RightSide] = majorAxisoffsetxw;
    guideInfo.ellipseMinorOffset[RightSide] = 0;

    guideInfo.ellipseMajorAxis[TopSide] = majorAxisyh;
    guideInfo.ellipseMinorAxis[TopSide] = minorAxisyh;
    guideInfo.ellipseMajorOffset[TopSide] = majorAxisoffsetyh;
    guideInfo.ellipseMinorOffset[TopSide] = 0;

    guideInfo.ellipseMajorAxis[LeftSide] = majorAxisxw;
    guideInfo.ellipseMinorAxis[LeftSide] = minorAxisxw;
    guideInfo.ellipseMajorOffset[LeftSide] = majorAxisoffsetxw;
    guideInfo.ellipseMinorOffset[LeftSide] = 0;

    guideInfo.ellipseMajorAxis[BottomSide] = majorAxisyh;
    guideInfo.ellipseMinorAxis[BottomSide] = minorAxisyh;
    guideInfo.ellipseMajorOffset[BottomSide] = majorAxisoffsetyh;
    guideInfo.ellipseMinorOffset[BottomSide] = 0;

    guideInfo.entranceHorizontalWidth = 2 * sqrt (1 - (majorAxisoffsetyh * majorAxisoffsetyh) / (majorAxisyh * majorAxisyh)) * minorAxisyh;
    guideInfo.entranceVerticalWidth = 2 * sqrt (1 - (majorAxisoffsetxw * majorAxisoffsetxw) / (majorAxisxw * majorAxisxw)) * minorAxisxw;
  }

  if (strcmp (option, "ellipse") == 0 && directDefination == 0) {
    if (strcmp (dimensionsAt, "entrance") == 0) {
      double lofbs_horizontal = sqrt (linxw * linxw + xwidth * xwidth * 0.25) + sqrt ((l + loutxw) * (l + loutxw) + xwidth * xwidth * 0.25);

      double lofbs_vertical = sqrt (linyh * linyh + yheight * yheight * 0.25) + sqrt ((l + loutyh) * (l + loutyh) + yheight * yheight * 0.25);

      guideInfo.Length = l;

      guideInfo.ellipseMajorAxis[RightSide] = lofbs_horizontal / 2;
      guideInfo.ellipseMinorAxis[RightSide] = sqrt (0.25 * lofbs_horizontal * lofbs_horizontal - 0.25 * (l + linxw + loutxw) * (l + linxw + loutxw));

      guideInfo.ellipseMajorOffset[RightSide] = (l + linxw + loutxw) / 2 - linxw;
      guideInfo.ellipseMinorOffset[RightSide] = 0;

      guideInfo.ellipseMajorAxis[LeftSide] = guideInfo.ellipseMajorAxis[RightSide];
      guideInfo.ellipseMinorAxis[LeftSide] = guideInfo.ellipseMinorAxis[RightSide];
      guideInfo.ellipseMajorOffset[LeftSide] = guideInfo.ellipseMajorOffset[RightSide];
      guideInfo.ellipseMinorOffset[LeftSide] = guideInfo.ellipseMinorOffset[RightSide];

      guideInfo.ellipseMajorAxis[TopSide] = lofbs_vertical / 2;

      guideInfo.ellipseMinorAxis[TopSide] = sqrt (0.25 * lofbs_vertical * lofbs_vertical - 0.25 * (l + linyh + loutyh) * (l + linyh + loutyh));

      guideInfo.ellipseMajorOffset[TopSide] = (l + linyh + loutyh) / 2 - linyh;
      guideInfo.ellipseMinorOffset[TopSide] = 0;

      guideInfo.ellipseMajorAxis[BottomSide] = guideInfo.ellipseMajorAxis[TopSide];
      guideInfo.ellipseMinorAxis[BottomSide] = guideInfo.ellipseMinorAxis[TopSide];
      guideInfo.ellipseMajorOffset[BottomSide] = guideInfo.ellipseMajorOffset[TopSide];
      guideInfo.ellipseMinorOffset[BottomSide] = guideInfo.ellipseMinorOffset[TopSide];
    }
    if (strcmp (dimensionsAt, "exit") == 0) {
      double lofbs_horizontal = sqrt (loutxw * loutxw + xwidth * xwidth * 0.25) + sqrt ((l + linxw) * (l + linxw) + xwidth * xwidth * 0.25);

      double lofbs_vertical = sqrt (loutyh * loutyh + yheight * yheight * 0.25) + sqrt ((l + linyh) * (l + linyh) + yheight * yheight * 0.25);

      guideInfo.Length = l;

      guideInfo.ellipseMajorAxis[RightSide] = lofbs_horizontal / 2;
      guideInfo.ellipseMinorAxis[RightSide] = sqrt (0.25 * lofbs_horizontal * lofbs_horizontal - 0.25 * (l + linxw + loutxw) * (l + linxw + loutxw));

      guideInfo.ellipseMajorOffset[RightSide] = (l + linxw + loutxw) / 2 - linxw;
      guideInfo.ellipseMinorOffset[RightSide] = 0;

      guideInfo.ellipseMajorAxis[LeftSide] = guideInfo.ellipseMajorAxis[RightSide];
      guideInfo.ellipseMinorAxis[LeftSide] = guideInfo.ellipseMinorAxis[RightSide];
      guideInfo.ellipseMajorOffset[LeftSide] = guideInfo.ellipseMajorOffset[RightSide];
      guideInfo.ellipseMinorOffset[LeftSide] = guideInfo.ellipseMinorOffset[RightSide];

      guideInfo.ellipseMajorAxis[TopSide] = lofbs_vertical / 2;

      guideInfo.ellipseMinorAxis[TopSide] = sqrt (0.25 * lofbs_vertical * lofbs_vertical - 0.25 * (l + linyh + loutyh) * (l + linyh + loutyh));

      guideInfo.ellipseMajorOffset[TopSide] = (l + linyh + loutyh) / 2 - linyh;
      guideInfo.ellipseMinorOffset[TopSide] = 0;

      guideInfo.ellipseMajorAxis[BottomSide] = guideInfo.ellipseMajorAxis[TopSide];
      guideInfo.ellipseMinorAxis[BottomSide] = guideInfo.ellipseMinorAxis[TopSide];
      guideInfo.ellipseMajorOffset[BottomSide] = guideInfo.ellipseMajorOffset[TopSide];
      guideInfo.ellipseMinorOffset[BottomSide] = guideInfo.ellipseMinorOffset[TopSide];
    }
    if (strcmp (dimensionsAt, "mid") == 0) {

      guideInfo.Length = l;

      guideInfo.ellipseMajorAxis[RightSide] = sqrt ((linxw + l + loutxw) * (linxw + l + loutxw) / 4 + xwidth * xwidth / 4);
      guideInfo.ellipseMinorAxis[RightSide] = xwidth / 2;

      guideInfo.ellipseMajorOffset[RightSide] = (l + linxw + loutxw) / 2 - linxw;
      guideInfo.ellipseMinorOffset[RightSide] = 0;

      guideInfo.ellipseMajorAxis[LeftSide] = guideInfo.ellipseMajorAxis[RightSide];
      guideInfo.ellipseMinorAxis[LeftSide] = guideInfo.ellipseMinorAxis[RightSide];
      guideInfo.ellipseMajorOffset[LeftSide] = guideInfo.ellipseMajorOffset[RightSide];
      guideInfo.ellipseMinorOffset[LeftSide] = guideInfo.ellipseMinorOffset[RightSide];

      guideInfo.ellipseMajorAxis[TopSide] = sqrt ((linyh + l + loutyh) * (linyh + l + loutyh) / 4 + yheight * yheight / 4);
      guideInfo.ellipseMinorAxis[TopSide] = yheight / 2;

      guideInfo.ellipseMajorOffset[TopSide] = (l + linyh + loutyh) / 2 - linyh;
      guideInfo.ellipseMinorOffset[TopSide] = 0;

      guideInfo.ellipseMajorAxis[BottomSide] = guideInfo.ellipseMajorAxis[TopSide];
      guideInfo.ellipseMinorAxis[BottomSide] = guideInfo.ellipseMinorAxis[TopSide];
      guideInfo.ellipseMajorOffset[BottomSide] = guideInfo.ellipseMajorOffset[TopSide];
      guideInfo.ellipseMinorOffset[BottomSide] = guideInfo.ellipseMinorOffset[TopSide];
    }
  }

  guideInfo.entranceHorizontalWidth = 2
                                      * sqrt (1
                                              - guideInfo.ellipseMajorOffset[RightSide] * guideInfo.ellipseMajorOffset[RightSide]
                                                    / (guideInfo.ellipseMajorAxis[RightSide] * guideInfo.ellipseMajorAxis[RightSide]))
                                      * guideInfo.ellipseMinorAxis[RightSide];
  guideInfo.entranceVerticalWidth = 2
                                    * sqrt (1
                                            - guideInfo.ellipseMajorOffset[TopSide] * guideInfo.ellipseMajorOffset[TopSide]
                                                  / (guideInfo.ellipseMajorAxis[TopSide] * guideInfo.ellipseMajorAxis[TopSide]))
                                    * guideInfo.ellipseMinorAxis[TopSide];

  if (strcmp (option, "halfellipse") == 0 && directDefination == 0) {
    exit (printf ("Critical error in %s; the option for option = halfellipse is currently disabled.", NAME_CURRENT_COMP));

    double used_focal_vertical;
    double used_focal_horizontal;
    double major_offset_horizontal = 0;
    double major_offset_vertical = 0;

    if (strcmp (dimensionsAt, "entrance") == 0) {
      used_focal_vertical = sqrt ((yheight * yheight) / 4 + (l + linyh) * (l + linyh));
      used_focal_horizontal = sqrt ((xwidth * xwidth) / 4 + (l + linxw) * (l + linxw));
      major_offset_vertical = l;
      major_offset_horizontal = l;
    } else {
      used_focal_vertical = sqrt ((yheight * yheight) / 4 + (l + loutyh) * (l + loutyh));
      used_focal_horizontal = sqrt ((xwidth * xwidth) / 4 + (l + loutxw) * (l + loutxw));
    }

    guideInfo.Length = l;

    guideInfo.ellipseMajorAxis[RightSide] = used_focal_horizontal;
    guideInfo.ellipseMinorAxis[RightSide] = xwidth / 2;

    guideInfo.ellipseMajorOffset[RightSide] = major_offset_horizontal;
    guideInfo.ellipseMinorOffset[RightSide] = 0;

    guideInfo.ellipseMajorAxis[LeftSide] = guideInfo.ellipseMajorAxis[RightSide];
    guideInfo.ellipseMinorAxis[LeftSide] = guideInfo.ellipseMinorAxis[RightSide];
    guideInfo.ellipseMajorOffset[LeftSide] = guideInfo.ellipseMajorOffset[RightSide];
    guideInfo.ellipseMinorOffset[LeftSide] = guideInfo.ellipseMinorOffset[RightSide];

    guideInfo.ellipseMajorAxis[TopSide] = used_focal_vertical;
    guideInfo.ellipseMinorAxis[TopSide] = yheight / 2;

    guideInfo.ellipseMajorOffset[TopSide] = major_offset_vertical;
    guideInfo.ellipseMinorOffset[TopSide] = 0;

    guideInfo.ellipseMajorAxis[BottomSide] = guideInfo.ellipseMajorAxis[TopSide];
    guideInfo.ellipseMinorAxis[BottomSide] = guideInfo.ellipseMinorAxis[TopSide];
    guideInfo.ellipseMajorOffset[BottomSide] = guideInfo.ellipseMajorOffset[TopSide];
    guideInfo.ellipseMinorOffset[BottomSide] = guideInfo.ellipseMinorOffset[TopSide];
  }

  // Applies the properties of the mirrors in the guide given by the user.
  // These variables are used in the reflection functions.

  // Give a warning if all side of the guide is turned off,
  // as the guide is essentially turned off
  if (guideInfo.OuterSide[RightSide] == 1 && guideInfo.OuterSide[TopSide] == 1 && guideInfo.OuterSide[LeftSide] == 1 && guideInfo.OuterSide[BottomSide] == 1
      && guideInfo.InnerSide[RightSide] == 1 && guideInfo.InnerSide[TopSide] == 1 && guideInfo.InnerSide[LeftSide] == 1 && guideInfo.InnerSide[BottomSide] == 1)
    printf ("Warning: In %s all the sides of the guide has been disabled,"
            " so it not possible for any particle"
            " to collide with the guide, consider"
            " disabling this component",
            NAME_CURRENT_COMP);

  if (guideInfo.mArr[RightSide] <= 0)
    guideInfo.InnerSide[RightSide] = MirrorTypeabsorption;
  if (guideInfo.mArr[TopSide] <= 0)
    guideInfo.InnerSide[TopSide] = MirrorTypeabsorption;
  if (guideInfo.mArr[LeftSide] <= 0)
    guideInfo.InnerSide[LeftSide] = MirrorTypeabsorption;
  if (guideInfo.mArr[BottomSide] <= 0)
    guideInfo.InnerSide[BottomSide] = MirrorTypeabsorption;

  if (strcmp (option, "halfellipse") == 0 && directDefination == 0) {
    guideInfo.entranceHorizontalWidth = (guideInfo.ellipseMinorAxis[RightSide]
                                             * sqrt (1
                                                     - (guideInfo.ellipseMajorOffset[RightSide] * guideInfo.ellipseMajorOffset[RightSide])
                                                           / (guideInfo.ellipseMajorAxis[RightSide] * guideInfo.ellipseMajorAxis[RightSide]))
                                         + guideInfo.ellipseMinorOffset[RightSide])
                                        * 2;
    guideInfo.entranceVerticalWidth = (guideInfo.ellipseMinorAxis[TopSide]
                                           * sqrt (1
                                                   - (guideInfo.ellipseMajorOffset[TopSide] * guideInfo.ellipseMajorOffset[TopSide])
                                                         / (guideInfo.ellipseMajorAxis[TopSide] * guideInfo.ellipseMajorAxis[TopSide]))
                                       + guideInfo.ellipseMinorOffset[TopSide])
                                      * 2;
  }

  guideInfo.EnclosingBoxOn = 0;

  guideInfo.exitVerticalWidth
      = 2
        * sqrt (1
                - ((guideInfo.Length - guideInfo.ellipseMajorOffset[BottomSide]) * (guideInfo.Length - guideInfo.ellipseMajorOffset[BottomSide]))
                      / (guideInfo.ellipseMajorAxis[BottomSide] * guideInfo.ellipseMajorAxis[BottomSide]))
        * guideInfo.ellipseMinorAxis[BottomSide];

  guideInfo.exitHorizontalWidth
      = 2
        * sqrt (1
                - ((guideInfo.Length - guideInfo.ellipseMajorOffset[RightSide]) * (guideInfo.Length - guideInfo.ellipseMajorOffset[RightSide]))
                      / (guideInfo.ellipseMajorAxis[RightSide] * guideInfo.ellipseMajorAxis[RightSide]))
        * guideInfo.ellipseMinorAxis[RightSide];

  //////////////////segmentation of m values

  // Are the arrays empty?
  if (mvaluesright != NULL || mvaluesleft != NULL || mvaluestop != NULL || mvaluesbottom != NULL) {
    guideInfo.enableSegments = 1;

    if (nSegments == -1) {
      printf ("\nError (%s): vector-specifcation of coating used, but nSegments=%i.\n  Please give provide nSegments = length of coating segment-arrays!\n",
              _comp->_name, nSegments);
      exit (-1);
    } else {
      guideInfo.numberOfSegments = (int)nSegments;
    }

    // printf("Length is %i\n",guideInfo.numberOfSegments);
    guideInfo.mValuesright = mvaluesright;
    guideInfo.mValuesleft = mvaluesleft;
    guideInfo.mValuestop = mvaluestop;
    guideInfo.mValuesbottom = mvaluesbottom;
    // printf("Seglength ... %f %f %f\n",seglength[0],seglength[1],seglength[2]);

    // Are the arrays of equal length?
    if (seglength == NULL) {
      dynamicalSegLength = realloc (dynamicalSegLength, guideInfo.numberOfSegments * sizeof (double));
      int i;
      for (i = 0; i < guideInfo.numberOfSegments; ++i) {
        dynamicalSegLength[i] = guideInfo.Length / guideInfo.numberOfSegments;
      }
      guideInfo.segLength = dynamicalSegLength;
    } else
      guideInfo.segLength = seglength;

    double sumOfelements = 0;
    int i;
    for (i = 0; i < guideInfo.numberOfSegments; i++) {
      sumOfelements += guideInfo.segLength[i];
    }
    if (guideInfo.verboseSetting && fabs (sumOfelements - guideInfo.Length) > 1e-9)
      printf ("Error in userinput inside %s, the difference between"
              " guidelength and elements of the seglength array is:"
              "%e consider changes the parameters l or seglength \n",
              NAME_CURRENT_COMP, sumOfelements - guideInfo.Length);
  } else
    guideInfo.enableSegments = 0;

  ///////////////////////////////////////////////////////////////////////////
  /////////////// Calculate gravity vector in the guides coordinatesystem
  ///////////////////////////////////////////////////////////////////////////

  /*
          Sets the local gravity vector equal to the global gravity vector (0,-g,0)
          and when apply the same rotation matrix as applied to guide.
  */
  if (enableGravity != 0) {
    Gx0 = 0, Gy0 = -GRAVITY * enableGravity, Gz0 = 0;
    Coords mcLocG;
    mcLocG = rot_apply (ROT_A_CURRENT_COMP, coords_set (0, Gy0, 0));
    coords_get (mcLocG, &Gx0, &Gy0, &Gz0);
  }
  Circ = 2 * PI * curvature;
  #undef xwidth
  #undef yheight
  #undef l
  #undef linxw
  #undef loutxw
  #undef linyh
  #undef loutyh
  #undef majorAxisxw
  #undef minorAxisxw
  #undef majorAxisyh
  #undef minorAxisyh
  #undef majorAxisoffsetxw
  #undef majorAxisoffsetyh
  #undef dimensionsAt
  #undef option
  #undef R0
  #undef Qc
  #undef alpha
  #undef m
  #undef W
  #undef alpharight
  #undef mright
  #undef alphaleft
  #undef mleft
  #undef alphatop
  #undef mtop
  #undef alphabottom
  #undef mbottom
  #undef verbose
  #undef enableGravity
  #undef curvature
  #undef nSegments
  #undef mvaluesright
  #undef mvaluesleft
  #undef mvaluestop
  #undef mvaluesbottom
  #undef seglength
  #undef guideInfo
  #undef Gx0
  #undef Gy0
  #undef Gz0
  #undef Circ
  #undef dynamicalSegLength
  return(_comp);
} /* class_Elliptic_guide_gravity_init */

_class_Bender *class_Bender_init(_class_Bender *_comp
) {
  #define w (_comp->_parameters.w)
  #define h (_comp->_parameters.h)
  #define r (_comp->_parameters.r)
  #define Win (_comp->_parameters.Win)
  #define k (_comp->_parameters.k)
  #define d (_comp->_parameters.d)
  #define l (_comp->_parameters.l)
  #define R0a (_comp->_parameters.R0a)
  #define Qca (_comp->_parameters.Qca)
  #define alphaa (_comp->_parameters.alphaa)
  #define ma (_comp->_parameters.ma)
  #define Wa (_comp->_parameters.Wa)
  #define R0i (_comp->_parameters.R0i)
  #define Qci (_comp->_parameters.Qci)
  #define alphai (_comp->_parameters.alphai)
  #define mi (_comp->_parameters.mi)
  #define Wi (_comp->_parameters.Wi)
  #define R0s (_comp->_parameters.R0s)
  #define Qcs (_comp->_parameters.Qcs)
  #define alphas (_comp->_parameters.alphas)
  #define ms (_comp->_parameters.ms)
  #define Ws (_comp->_parameters.Ws)
  #define bk (_comp->_parameters.bk)
  #define mWin (_comp->_parameters.mWin)
  SIG_MESSAGE("[_C1_init] component C1=Bender() INITIALISE [Bender:0]");

  if (r < 0) {
    fprintf (stderr, "Bender: error: %s: to bend in the other direction\n", NAME_CURRENT_COMP);
    fprintf (stderr, "        rotate comp on z-axis by 180 deg.\n");
    exit (-1);
  }

  if (k * d > w) {
    fprintf (stderr, "Bender: error: %s has (k*d > w).\n", NAME_CURRENT_COMP);
    exit (-1);
  }
  if (w * h * r * Win * k == 0) {
    fprintf (stderr, "Bender: error: %s has one of w,h,r,Win,k null.\n", NAME_CURRENT_COMP);
    exit (-1);
  }
  /* width of one channel + thickness d of partition */
  mWin = Win;
  if (l != 0 && r != 0)
    mWin = (double)l / (double)r;
  bk = (w + d) / k;
  if (mcgravitation)
    fprintf (stderr,
             "WARNING: Bender: %s: "
             "This component produces wrong results with gravitation !\n",
             NAME_CURRENT_COMP);
  #undef w
  #undef h
  #undef r
  #undef Win
  #undef k
  #undef d
  #undef l
  #undef R0a
  #undef Qca
  #undef alphaa
  #undef ma
  #undef Wa
  #undef R0i
  #undef Qci
  #undef alphai
  #undef mi
  #undef Wi
  #undef R0s
  #undef Qcs
  #undef alphas
  #undef ms
  #undef Ws
  #undef bk
  #undef mWin
  return(_comp);
} /* class_Bender_init */

_class_Slit *class_Slit_init(_class_Slit *_comp
) {
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define radius (_comp->_parameters.radius)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define isradial (_comp->_parameters.isradial)
  SIG_MESSAGE("[_SlitGuideEnd_init] component SlitGuideEnd=Slit() INITIALISE [Slit:0]");

  if (is_unset (radius)) {
    isradial = 0;
    if (all_set (3, xwidth, xmin, xmax)) {
      slit_error_if (xwidth != xmax - xmin, "specifying xwidth, xmin and xmax requires consistent parameters", NAME_CURRENT_COMP);
    } else {
      slit_error_if (is_unset (xwidth) && any_unset (2, xmin, xmax), "specify either xwidth or xmin & xmax", NAME_CURRENT_COMP);
    }
    if (all_set (3, yheight, ymin, ymax)) {
      slit_error_if (yheight != ymax - ymin, "specifying yheight, ymin and ymax requires consistent parameters", NAME_CURRENT_COMP);
    } else {
      slit_error_if (is_unset (yheight) && any_unset (2, ymin, ymax), "specify either yheight or ymin & ymax", NAME_CURRENT_COMP);
    }
    if (is_unset (xmin)) { // xmax also unset but xwidth *is* set
      xmax = xwidth / 2;
      xmin = -xmax;
    }
    if (is_unset (ymin)) { // ymax also unset but yheight *is* set
      ymax = yheight / 2;
      ymin = -ymax;
    }
    slit_warning_if (xmin == xmax || ymin == ymax, "Running with CLOSED rectangular slit - is this intentional?", NAME_CURRENT_COMP);
  } else {
    isradial = 1;
    slit_error_if (any_set (6, xwidth, xmin, xmax, yheight, ymin, ymax), "specify radius OR width and height parameters", NAME_CURRENT_COMP);
    slit_warning_if (radius == 0., "Running with CLOSED radial slit - is this intentional?", NAME_CURRENT_COMP);
  }
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef radius
  #undef xwidth
  #undef yheight
  #undef isradial
  return(_comp);
} /* class_Slit_init */

_class_Monochromator_curved *class_Monochromator_curved_init(_class_Monochromator_curved *_comp
) {
  #define reflect (_comp->_parameters.reflect)
  #define transmit (_comp->_parameters.transmit)
  #define zwidth (_comp->_parameters.zwidth)
  #define yheight (_comp->_parameters.yheight)
  #define gap (_comp->_parameters.gap)
  #define NH (_comp->_parameters.NH)
  #define NV (_comp->_parameters.NV)
  #define mosaich (_comp->_parameters.mosaich)
  #define mosaicv (_comp->_parameters.mosaicv)
  #define r0 (_comp->_parameters.r0)
  #define t0 (_comp->_parameters.t0)
  #define Q (_comp->_parameters.Q)
  #define RV (_comp->_parameters.RV)
  #define RH (_comp->_parameters.RH)
  #define DM (_comp->_parameters.DM)
  #define mosaic (_comp->_parameters.mosaic)
  #define width (_comp->_parameters.width)
  #define height (_comp->_parameters.height)
  #define verbose (_comp->_parameters.verbose)
  #define order (_comp->_parameters.order)
  #define mos_rms_y (_comp->_parameters.mos_rms_y)
  #define mos_rms_z (_comp->_parameters.mos_rms_z)
  #define mos_rms_max (_comp->_parameters.mos_rms_max)
  #define mono_Q (_comp->_parameters.mono_Q)
  #define SlabWidth (_comp->_parameters.SlabWidth)
  #define SlabHeight (_comp->_parameters.SlabHeight)
  #define rTable (_comp->_parameters.rTable)
  #define tTable (_comp->_parameters.tTable)
  #define rTableFlag (_comp->_parameters.rTableFlag)
  #define tTableFlag (_comp->_parameters.tTableFlag)
  #define tiltH (_comp->_parameters.tiltH)
  #define tiltV (_comp->_parameters.tiltV)
  #define ncol_var (_comp->_parameters.ncol_var)
  #define nrow_var (_comp->_parameters.nrow_var)
  SIG_MESSAGE("[_Mono_init] component Mono=Monochromator_curved() INITIALISE [Monochromator_curved:0]");

  int i;

  if (mosaic != 0) {
    mos_rms_y = MIN2RAD * mosaic / sqrt (8 * log (2));
    mos_rms_z = mos_rms_y;
  } else {
    mos_rms_y = MIN2RAD * mosaich / sqrt (8 * log (2));
    mos_rms_z = MIN2RAD * mosaicv / sqrt (8 * log (2));
  }
  mos_rms_max = mos_rms_y > mos_rms_z ? mos_rms_y : mos_rms_z;

  mono_Q = Q;
  if (DM != 0)
    mono_Q = 2 * PI / DM;

  if (mono_Q <= 0) {
    fprintf (stderr, "Monochromator_curved: %s: Error scattering vector Q = 0\n", NAME_CURRENT_COMP);
    exit (-1);
  }
  if (r0 < 0) {
    fprintf (stderr, "Monochromator_curved: %s: Error reflectivity r0 is negative\n", NAME_CURRENT_COMP);
    exit (-1);
  }
  if (r0 == 0) {
    fprintf (stderr, "Monochromator_curved: %s: Reflectivity r0 is null. Ignoring component.\n", NAME_CURRENT_COMP);
  }
  if (NH * NV == 0) {
    fprintf (stderr, "Monochromator_curved: %s: no slabs ??? (NH or NV=0)\n", NAME_CURRENT_COMP);
    exit (-1);
  }

  if (verbose && r0) {
    printf ("Monochromator_curved: component %s Q=%.3g Angs-1 (DM=%.4g Angs)\n", NAME_CURRENT_COMP, mono_Q, 2 * PI / mono_Q);
    if (NH * NV == 1)
      printf ("            flat.\n");
    else {
      if (NH > 1) {
        printf ("            horizontal: %i blades", (int)NH);
        if (RH != 0)
          printf (" focusing with RH=%.3g [m]", RH);
        printf ("\n");
      }
      if (NV > 1) {
        printf ("            vertical:   %i blades", (int)NV);
        if (RV != 0)
          printf (" focusing with RV=%.3g [m]", RV);
        printf ("\n");
      }
    }
  }

  if (reflect != NULL && r0 && strlen (reflect) && strcmp (reflect, "NULL") && strcmp (reflect, "0")) {
    if (verbose)
      fprintf (stdout, "Monochromator_curved: %s: Reflectivity data (k, R) from %s\n", NAME_CURRENT_COMP, reflect);
    Table_Read (&rTable, reflect, 1); /* read 1st block data from file into rTable */
    Table_Rebin (&rTable);            /* rebin as evenly, increasing array */
    if (rTable.rows < 2)
      Table_Free (&rTable);
    if (verbose)
      Table_Info (rTable);
    rTableFlag = 1;
  } else {
    rTableFlag = 0;
  }
  if (transmit != NULL && strlen (transmit) && strcmp (transmit, "NULL") && strcmp (transmit, "0")) {
    if (verbose)
      fprintf (stdout, "Monochromator_curved: %s: Transmission data (k, T) from %s\n", NAME_CURRENT_COMP, transmit);
    Table_Read (&tTable, transmit, 1); /* read 1st block data from file into rTable */
    Table_Rebin (&tTable);             /* rebin as evenly, increasing array */
    if (tTable.rows < 2)
      Table_Free (&tTable);
    if (verbose)
      Table_Info (tTable);
    tTableFlag = 1;
  } else {
    tTableFlag = 0;
  }

  if (width == 0)
    SlabWidth = zwidth;
  else
    SlabWidth = (width + gap) / NH - gap;
  if (height == 0)
    SlabHeight = yheight;
  else
    SlabHeight = (height + gap) / NV - gap;

  tiltH = calloc ((int)2 * (NH + 1), sizeof (double));
  tiltV = calloc ((int)2 * (NV + 1), sizeof (double));

  if (!tiltH)
    printf ("Monochromator_curved: %s: Warning: not enough memory to allocate tilts (NH=%i).\n", NAME_CURRENT_COMP, NH);
  else if (RH) { /* pre-compute tilts */
    for (i = 0; i <= NH; i++) {
      tiltH[i] = asin ((i - (NH + 1) / 2.0) * (SlabWidth + gap) / RH);
    }
  }
  if (!tiltV)
    printf ("Monochromator_curved: %s: Warning: not enough memory to allocate tilts (NV=%i).\n", NAME_CURRENT_COMP, NV);
  else if (RV) {
    for (i = 0; i <= NV; i++) {
      tiltV[i] = -asin ((i - (NV + 1) / 2.0) * (SlabHeight + gap) / RV);
    }
  }
  sprintf (ncol_var, "ncol_%ld", _comp->_index);
  sprintf (nrow_var, "nrow_%ld", _comp->_index);
  #undef reflect
  #undef transmit
  #undef zwidth
  #undef yheight
  #undef gap
  #undef NH
  #undef NV
  #undef mosaich
  #undef mosaicv
  #undef r0
  #undef t0
  #undef Q
  #undef RV
  #undef RH
  #undef DM
  #undef mosaic
  #undef width
  #undef height
  #undef verbose
  #undef order
  #undef mos_rms_y
  #undef mos_rms_z
  #undef mos_rms_max
  #undef mono_Q
  #undef SlabWidth
  #undef SlabHeight
  #undef rTable
  #undef tTable
  #undef rTableFlag
  #undef tTableFlag
  #undef tiltH
  #undef tiltV
  #undef ncol_var
  #undef nrow_var
  return(_comp);
} /* class_Monochromator_curved_init */

_class_Incoherent *class_Incoherent_init(_class_Incoherent *_comp
) {
  #define geometry (_comp->_parameters.geometry)
  #define radius (_comp->_parameters.radius)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define thickness (_comp->_parameters.thickness)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define focus_r (_comp->_parameters.focus_r)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define target_index (_comp->_parameters.target_index)
  #define pack (_comp->_parameters.pack)
  #define p_interact (_comp->_parameters.p_interact)
  #define f_QE (_comp->_parameters.f_QE)
  #define gamma (_comp->_parameters.gamma)
  #define Etrans (_comp->_parameters.Etrans)
  #define deltaE (_comp->_parameters.deltaE)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define Vc (_comp->_parameters.Vc)
  #define concentric (_comp->_parameters.concentric)
  #define order (_comp->_parameters.order)
  #define VarsInc (_comp->_parameters.VarsInc)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_VanSample_init] component VanSample=Incoherent() INITIALISE [Incoherent:0]");

  VarsInc.shape = -1; /* -1:no shape, 0:cyl, 1:box, 2:sphere, 3:any-shape  */
  if (geometry && strlen (geometry) && strcmp (geometry, "NULL") && strcmp (geometry, "0")) {
    #ifndef USE_OFF
    fprintf (stderr, "Error: You are attempting to use an OFF geometry without -DUSE_OFF. You will need to recompile with that define set!\n");
    exit (-1);
    #else
    if (off_init (geometry, xwidth, yheight, zdepth, 0, &offdata)) {
      VarsInc.shape = 3;
      thickness = 0;
      concentric = 0;
    }
    #endif
  } else if (xwidth && yheight && zdepth)
    VarsInc.shape = 1; /* box */
  else if (radius > 0 && yheight)
    VarsInc.shape = 0; /* cylinder */
  else if (radius > 0 && !yheight)
    VarsInc.shape = 2; /* sphere */

  if (VarsInc.shape < 0)
    exit (fprintf (stderr,
                   "Incoherent: %s: sample has invalid dimensions.\n"
                   "ERROR       Please check parameter values (xwidth, yheight, zdepth, radius).\n",
                   NAME_CURRENT_COMP));
  if (thickness) {
    if (radius && (radius < thickness || (yheight && (yheight < 2 * thickness)))) {
      fprintf (stderr,
               "Incoherent: %s: hollow sample thickness is larger than its volume (sphere/cylinder).\n"
               "WARNING     Please check parameter values. Using bulk sample (thickness=0).\n",
               NAME_CURRENT_COMP);
      thickness = 0;
    } else if (!radius && (xwidth < 2 * thickness || yheight < 2 * thickness || zdepth < 2 * thickness)) {
      fprintf (stderr,
               "Incoherent: %s: hollow sample thickness is larger than its volume (box).\n"
               "WARNING     Please check parameter values. Using bulk sample (thickness=0).\n",
               NAME_CURRENT_COMP);
      thickness = 0;
    }
  }

  if (concentric && thickness <= 0) {
    printf ("Incoherent: %s:Can not use concentric mode\n"
            "WARNING     on non hollow shape. Ignoring.\n",
            NAME_CURRENT_COMP);
    concentric = 0;
  }

  VarsInc.sigma_a = sigma_abs;
  VarsInc.sigma_i = sigma_inc;
  VarsInc.rho = (pack / Vc);
  VarsInc.my_s = (VarsInc.rho * 100 * VarsInc.sigma_i);
  VarsInc.my_a_v = (VarsInc.rho * 100 * VarsInc.sigma_a);

  /* now compute target coords if a component index is supplied */
  VarsInc.tx = VarsInc.ty = VarsInc.tz = 0;
  if (!target_index && !target_x && !target_y && !target_z)
    target_index = 1;
  if (target_index) {
    Coords ToTarget;
    ToTarget = coords_sub (POS_A_COMP_INDEX (INDEX_CURRENT_COMP + target_index), POS_A_CURRENT_COMP);
    ToTarget = rot_apply (ROT_A_CURRENT_COMP, ToTarget);
    coords_get (ToTarget, &VarsInc.tx, &VarsInc.ty, &VarsInc.tz);
  } else {
    VarsInc.tx = target_x;
    VarsInc.ty = target_y;
    VarsInc.tz = target_z;
  }

  if (!(VarsInc.tx || VarsInc.ty || VarsInc.tz)) {
    MPI_MASTER (printf ("Incoherent: %s: The target is not defined. Using direct beam (Z-axis).\n", NAME_CURRENT_COMP););
    VarsInc.tz = 1;
  }

  /* different ways of setting rectangular area */
  VarsInc.aw = VarsInc.ah = 0;
  if (focus_xw) {
    VarsInc.xw = focus_xw;
  }
  if (focus_yh) {
    VarsInc.yh = focus_yh;
  }
  if (focus_aw) {
    VarsInc.aw = DEG2RAD * focus_aw;
  }
  if (focus_ah) {
    VarsInc.ah = DEG2RAD * focus_ah;
  }

  MPI_MASTER (printf ("Incoherent: %s: Vc=%g [Angs] sigma_abs=%g [barn] sigma_inc=%g [barn]\n", NAME_CURRENT_COMP, Vc, VarsInc.sigma_a, VarsInc.sigma_i););
  #undef geometry
  #undef radius
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef thickness
  #undef target_x
  #undef target_y
  #undef target_z
  #undef focus_r
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef target_index
  #undef pack
  #undef p_interact
  #undef f_QE
  #undef gamma
  #undef Etrans
  #undef deltaE
  #undef sigma_abs
  #undef sigma_inc
  #undef Vc
  #undef concentric
  #undef order
  #undef VarsInc
  #undef offdata
  return(_comp);
} /* class_Incoherent_init */

_class_Phonon_simple *class_Phonon_simple_init(_class_Phonon_simple *_comp
) {
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define a (_comp->_parameters.a)
  #define b (_comp->_parameters.b)
  #define M (_comp->_parameters.M)
  #define c (_comp->_parameters.c)
  #define DW (_comp->_parameters.DW)
  #define T (_comp->_parameters.T)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define target_index (_comp->_parameters.target_index)
  #define focus_r (_comp->_parameters.focus_r)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define gap (_comp->_parameters.gap)
  #define e_steps_low (_comp->_parameters.e_steps_low)
  #define e_steps_high (_comp->_parameters.e_steps_high)
  #define V_rho (_comp->_parameters.V_rho)
  #define V_my_s (_comp->_parameters.V_my_s)
  #define V_my_a_v (_comp->_parameters.V_my_a_v)
  #define DV (_comp->_parameters.DV)
  #define phonon (_comp->_parameters.phonon)
  SIG_MESSAGE("[_sample_init] component sample=Phonon_simple() INITIALISE [Phonon_simple:0]");


  V_rho = 4 / (a * a * a);
  V_my_s = (V_rho * 100 * sigma_inc);
  V_my_a_v = (V_rho * 100 * sigma_abs * 2200);
  DV = 0.001; /* Velocity change used for numerical derivative */
  if (focus_aw)
    focus_aw *= DEG2RAD;
  if (focus_ah)
    focus_ah *= DEG2RAD;

  // Set constant parameters for parms object
  phonon.a_ = a;
  phonon.c_ = c;
  phonon.gap_ = gap;
  phonon.ah = a / 2.0;
  phonon.e_steps_high_ = e_steps_high;
  phonon.e_steps_low_ = e_steps_low;

  /* now compute target coords if a component index is supplied */
  if (!target_index && !target_x && !target_y && !target_z)
    target_index = 1;
  if (target_index) {
    Coords ToTarget;
    ToTarget = coords_sub (POS_A_COMP_INDEX (INDEX_CURRENT_COMP + target_index), POS_A_CURRENT_COMP);
    ToTarget = rot_apply (ROT_A_CURRENT_COMP, ToTarget);
    coords_get (ToTarget, &target_x, &target_y, &target_z);
  }
  if (!(target_x || target_y || target_z)) {
    printf ("Phonon_simple: %s: The target is not defined. Using direct beam (Z-axis).\n", NAME_CURRENT_COMP);
    target_z = 1;
  }
  #undef radius
  #undef yheight
  #undef sigma_abs
  #undef sigma_inc
  #undef a
  #undef b
  #undef M
  #undef c
  #undef DW
  #undef T
  #undef target_x
  #undef target_y
  #undef target_z
  #undef target_index
  #undef focus_r
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef gap
  #undef e_steps_low
  #undef e_steps_high
  #undef V_rho
  #undef V_my_s
  #undef V_my_a_v
  #undef DV
  #undef phonon
  return(_comp);
} /* class_Phonon_simple_init */

_class_Powder1 *class_Powder1_init(_class_Powder1 *_comp
) {
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define xwidth (_comp->_parameters.xwidth)
  #define zdepth (_comp->_parameters.zdepth)
  #define q (_comp->_parameters.q)
  #define d (_comp->_parameters.d)
  #define d_phi (_comp->_parameters.d_phi)
  #define pack (_comp->_parameters.pack)
  #define j (_comp->_parameters.j)
  #define DW (_comp->_parameters.DW)
  #define F2 (_comp->_parameters.F2)
  #define Vc (_comp->_parameters.Vc)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define my_s_v2 (_comp->_parameters.my_s_v2)
  #define my_a_v (_comp->_parameters.my_a_v)
  #define q_v (_comp->_parameters.q_v)
  #define isrect (_comp->_parameters.isrect)
  SIG_MESSAGE("[_powder1_init] component powder1=Powder1() INITIALISE [Powder1:0]");

  isrect = 0;

  if (yheight)
    yheight = yheight;
  if (!radius || !yheight) {
    if (!xwidth || !yheight || !zdepth)
      exit (fprintf (stderr, "Powder1: %s: sample has no volume (zero dimensions)\n", NAME_CURRENT_COMP));
    else
      isrect = 1;
  }

  my_a_v = pack * sigma_abs / Vc * 2200 * 100; /* Is not yet divided by v */
  my_s_v2 = 4 * PI * PI * PI * pack * j * F2 * DW / (Vc * Vc * V2K * V2K * q) * 100;
  /* Is not yet divided by v^2. 100: convert from barns to fm^2 */
  /* Squires [3.103] */
  if (d)
    q = 2 * PI / d;
  q_v = q * K2V;
  #undef radius
  #undef yheight
  #undef xwidth
  #undef zdepth
  #undef q
  #undef d
  #undef d_phi
  #undef pack
  #undef j
  #undef DW
  #undef F2
  #undef Vc
  #undef sigma_abs
  #undef my_s_v2
  #undef my_a_v
  #undef q_v
  #undef isrect
  return(_comp);
} /* class_Powder1_init */

_class_Res_sample *class_Res_sample_init(_class_Res_sample *_comp
) {
  #define thickness (_comp->_parameters.thickness)
  #define radius (_comp->_parameters.radius)
  #define focus_r (_comp->_parameters.focus_r)
  #define E0 (_comp->_parameters.E0)
  #define dE (_comp->_parameters.dE)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define target_index (_comp->_parameters.target_index)
  #define vars (_comp->_parameters.vars)
  #define res_pi_var (_comp->_parameters.res_pi_var)
  #define res_ki_x_var (_comp->_parameters.res_ki_x_var)
  #define res_ki_y_var (_comp->_parameters.res_ki_y_var)
  #define res_ki_z_var (_comp->_parameters.res_ki_z_var)
  #define res_kf_x_var (_comp->_parameters.res_kf_x_var)
  #define res_kf_y_var (_comp->_parameters.res_kf_y_var)
  #define res_kf_z_var (_comp->_parameters.res_kf_z_var)
  #define res_rx_var (_comp->_parameters.res_rx_var)
  #define res_ry_var (_comp->_parameters.res_ry_var)
  #define res_rz_var (_comp->_parameters.res_rz_var)
  #define compindex (_comp->_parameters.compindex)
  SIG_MESSAGE("[_res_sample_init] component res_sample=Res_sample() INITIALISE [Res_sample:0]");

  if (!radius || !yheight) {
    if (!xwidth || !yheight || !zdepth)
      exit(fprintf(stderr,"Res_sample: %s: sample has no volume (zero dimensions)\n", NAME_CURRENT_COMP));
    else
      vars.isrect = 1;
  }
  else {
    vars.isrect = 0;
  }

  /* now compute target coords if a component index is supplied */
  if (!target_index && !target_x && !target_y && !target_z)
    target_index = 1;
  if (target_index) {
    Coords ToTarget;
    ToTarget = coords_sub(POS_A_COMP_INDEX(INDEX_CURRENT_COMP+target_index),POS_A_CURRENT_COMP);
    ToTarget = rot_apply(ROT_A_CURRENT_COMP, ToTarget);
    coords_get(ToTarget, &vars.targetx, &vars.targety, &vars.targetz);
  }
  else {
    vars.targetx = target_x;
    vars.targety = target_y;
    vars.targetz = target_z;
  }

  if (!(vars.targetx || vars.targety || vars.targetz)) {
    printf("Res_sample: %s: The target is not defined. Using direct beam (Z-axis).\n",
      NAME_CURRENT_COMP);
    vars.targetz = 1;
  }

  /* different ways of setting rectangular area */
  vars.awdim = vars.ahdim = 0;
  if (focus_xw) vars.xwdim = focus_xw;
  if (focus_yh) vars.yhdim = focus_yh;
  if (focus_aw) vars.awdim = DEG2RAD*focus_aw;
  if (focus_ah) vars.ahdim = DEG2RAD*focus_ah;

  /* Initialize uservar strings */
  sprintf(res_pi_var,"res_pi_%i",_comp->_index);
  sprintf(res_ki_x_var,"res_ki_x_%i",_comp->_index);
  sprintf(res_ki_y_var,"res_ki_y_%i",_comp->_index);
  sprintf(res_ki_z_var,"res_ki_z_%i",_comp->_index);
  sprintf(res_kf_x_var,"res_kf_x_%i",_comp->_index);
  sprintf(res_kf_y_var,"res_kf_y_%i",_comp->_index);
  sprintf(res_kf_z_var,"res_kf_z_%i",_comp->_index);
  sprintf(res_rx_var,"res_rx_%i",_comp->_index);
  sprintf(res_ry_var,"res_ry_%i",_comp->_index);
  sprintf(res_rz_var,"res_rz_%i",_comp->_index);
  compindex=_comp->_index;
  #undef thickness
  #undef radius
  #undef focus_r
  #undef E0
  #undef dE
  #undef target_x
  #undef target_y
  #undef target_z
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef target_index
  #undef vars
  #undef res_pi_var
  #undef res_ki_x_var
  #undef res_ki_y_var
  #undef res_ki_z_var
  #undef res_kf_x_var
  #undef res_kf_y_var
  #undef res_kf_z_var
  #undef res_rx_var
  #undef res_ry_var
  #undef res_rz_var
  #undef compindex
  return(_comp);
} /* class_Res_sample_init */

_class_Cyl_monitor_PSD *class_Cyl_monitor_PSD_init(_class_Cyl_monitor_PSD *_comp
) {
  #define nr (_comp->_parameters.nr)
  #define filename (_comp->_parameters.filename)
  #define yheight (_comp->_parameters.yheight)
  #define radius (_comp->_parameters.radius)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define thmin (_comp->_parameters.thmin)
  #define thmax (_comp->_parameters.thmax)
  #define ny (_comp->_parameters.ny)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_sample_cylinder_monitor_init] component sample_cylinder_monitor=Cyl_monitor_PSD() INITIALISE [Cyl_monitor_PSD:0]");

  PSD_N = create_darr2d (nr, ny);
  PSD_p = create_darr2d (nr, ny);
  PSD_p2 = create_darr2d (nr, ny);

  // Use instance name for monitor output if no input was given
  if (!strcmp (filename, "\0"))
    sprintf (filename, "%s", NAME_CURRENT_COMP);
  #undef nr
  #undef filename
  #undef yheight
  #undef radius
  #undef restore_neutron
  #undef thmin
  #undef thmax
  #undef ny
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_Cyl_monitor_PSD_init */

_class_PSD_monitor_4PI *class_PSD_monitor_4PI_init(_class_PSD_monitor_4PI *_comp
) {
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define radius (_comp->_parameters.radius)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_sample_spherical_monitor_init] component sample_spherical_monitor=PSD_monitor_4PI() INITIALISE [PSD_monitor_4PI:0]");

  PSD_N = create_darr2d (nx, ny);
  PSD_p = create_darr2d (nx, ny);
  PSD_p2 = create_darr2d (nx, ny);

  // Use instance name for monitor output if no input was given
  if (!strcmp (filename, "\0"))
    sprintf (filename, "%s", NAME_CURRENT_COMP);
  #undef nx
  #undef ny
  #undef filename
  #undef nowritefile
  #undef radius
  #undef restore_neutron
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_4PI_init */

_class_Filter_gen *class_Filter_gen_init(_class_Filter_gen *_comp
) {
  #define filename (_comp->_parameters.filename)
  #define options (_comp->_parameters.options)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define thickness (_comp->_parameters.thickness)
  #define scaling (_comp->_parameters.scaling)
  #define verbose (_comp->_parameters.verbose)
  #define Mode_Table (_comp->_parameters.Mode_Table)
  #define Type_Table (_comp->_parameters.Type_Table)
  #define pTable (_comp->_parameters.pTable)
  SIG_MESSAGE("[_filter_gen_init] component filter_gen=Filter_gen() INITIALISE [Filter_gen:0]");

  Mode_Table = FLUX_ADAPT_MULT;
  Type_Table = UNKNOWN_TABLE;

  if (xwidth > 0) {
    xmax = xwidth / 2;
    xmin = -xmax;
  }
  if (yheight > 0) {
    ymax = yheight / 2;
    ymin = -ymax;
  }

  FilterGen_Mode (options, &Mode_Table, &Type_Table, &verbose);

  if (filename != NULL && strlen (filename) && strcmp (filename, "NULL") && strcmp (filename, "0")) {
    if (Table_Read (&pTable, filename, 1) <= 0) /* read 1st block data from filename into pTable */
      exit (fprintf (stderr, "Filter_gen: %s: can not read filename %s\n", NAME_CURRENT_COMP, filename));

    Table_Rebin (&pTable); /* rebin as evenly, increasing array */
    if (pTable.rows < 2 || !pTable.step_x) {
      Table_Free (&pTable);
    }
    if (pTable.data) {
      FilterGen_Mode (pTable.header, &Mode_Table, &Type_Table, &verbose);
      if (verbose) {
        Table_Info (pTable);
        printf ("Filter_gen: %s: Filter data [", NAME_CURRENT_COMP);
        if (Type_Table == ENERGY_TABLE)
          printf ("Energy");
        if (Type_Table == WAVEVECTOR_TABLE)
          printf ("Wavevector");
        if (Type_Table == WAVELENGTH_TABLE)
          printf ("Wavelength");
        if (Type_Table == UNKNOWN_TABLE)
          printf ("UNKNOWN (not used)");
        printf (", Flux] in ");
        if (Mode_Table == FLUX_ADAPT_MULT)
          printf ("multiply");
        else if (Mode_Table == FLUX_ADAPT_ADD)
          printf ("add");
        else
          printf ("set");
        printf (" mode\n");
      }
    } else
      fprintf (stderr, "Filter_gen: %s: file %s contains no data.\n", NAME_CURRENT_COMP, filename);

  } else
    pTable.data = NULL;
  #undef filename
  #undef options
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef thickness
  #undef scaling
  #undef verbose
  #undef Mode_Table
  #undef Type_Table
  #undef pTable
  return(_comp);
} /* class_Filter_gen_init */

_class_PowderN *class_PowderN_init(_class_PowderN *_comp
) {
  #define reflections (_comp->_parameters.reflections)
  #define geometry (_comp->_parameters.geometry)
  #define format (_comp->_parameters.format)
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define xwidth (_comp->_parameters.xwidth)
  #define zdepth (_comp->_parameters.zdepth)
  #define thickness (_comp->_parameters.thickness)
  #define pack (_comp->_parameters.pack)
  #define Vc (_comp->_parameters.Vc)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define delta_d_d (_comp->_parameters.delta_d_d)
  #define p_inc (_comp->_parameters.p_inc)
  #define p_transmit (_comp->_parameters.p_transmit)
  #define DW (_comp->_parameters.DW)
  #define nb_atoms (_comp->_parameters.nb_atoms)
  #define d_omega (_comp->_parameters.d_omega)
  #define d_phi (_comp->_parameters.d_phi)
  #define tth_sign (_comp->_parameters.tth_sign)
  #define p_interact (_comp->_parameters.p_interact)
  #define concentric (_comp->_parameters.concentric)
  #define density (_comp->_parameters.density)
  #define weight (_comp->_parameters.weight)
  #define barns (_comp->_parameters.barns)
  #define Strain (_comp->_parameters.Strain)
  #define focus_flip (_comp->_parameters.focus_flip)
  #define target_index (_comp->_parameters.target_index)
  #define order (_comp->_parameters.order)
  #define line_info (_comp->_parameters.line_info)
  #define columns (_comp->_parameters.columns)
  #define offdata (_comp->_parameters.offdata)
  #define tgt_x (_comp->_parameters.tgt_x)
  #define tgt_y (_comp->_parameters.tgt_y)
  #define tgt_z (_comp->_parameters.tgt_z)
  SIG_MESSAGE("[_BeFilter_init] component BeFilter=PowderN() INITIALISE [PowderN:0]");

  /* We ought to clean up the columns variable as format is now a proper vector/array */
  columns = format;

  int i = 0;
  struct line_data* L;
  line_info.Dd = delta_d_d;
  line_info.DWfactor = DW;
  line_info.V_0 = Vc;
  line_info.rho = density;
  line_info.at_weight = weight;
  line_info.at_nb = nb_atoms;
  line_info.sigma_a = sigma_abs;
  line_info.sigma_i = sigma_inc;
  line_info.flag_barns = barns;
  line_info.shape = 0;
  line_info.flag_warning = 0;
  line_info.Epsilon = Strain;
  line_info.radius_i = line_info.xwidth_i = line_info.yheight_i = line_info.zdepth_i = 0;
  line_info.v = 0;
  line_info.Nq = 0;
  line_info.v_min = FLT_MAX;
  line_info.v_max = 0;
  line_info.neutron_passed = 0;
  line_info.nb_reuses = line_info.nb_refl = line_info.nb_refl_count = 0;
  line_info.xs_compute = line_info.xs_reuse = line_info.xs_calls = 0;
  for (i = 0; i < 9; i++) {
    line_info.column_order[i] = (int)columns[i];
  }
  strncpy (line_info.compname, NAME_CURRENT_COMP, 256);

  line_info.shape = -1; /* -1:no shape, 0:cyl, 1:box, 2:sphere, 3:any-shape  */
  if (geometry && strlen (geometry) && strcmp (geometry, "NULL") && strcmp (geometry, "0")) {
    #ifndef USE_OFF
    fprintf (stderr, "Error: You are attempting to use an OFF geometry without -DUSE_OFF. You will need to recompile with that define set!\n");
    exit (-1);
    #else
    if (off_init (geometry, xwidth, yheight, zdepth, 0, &offdata)) {
      line_info.shape = 3;
      thickness = 0;
      concentric = 0;
    }
    #endif
  } else if (xwidth && yheight && zdepth)
    line_info.shape = 1; /* box */
  else if (radius > 0 && yheight)
    line_info.shape = 0; /* cylinder */
  else if (radius > 0 && !yheight)
    line_info.shape = 2; /* sphere */

  if (line_info.shape < 0)
    exit (fprintf (stderr,
                   "PowderN: %s: sample has invalid dimensions.\n"
                   "ERROR    Please check parameter values (xwidth, yheight, zdepth, radius).\n",
                   NAME_CURRENT_COMP));
  if (thickness) {
    if (radius && (radius < fabs (thickness))) {
      MPI_MASTER (printf ("PowderN: %s: hollow sample thickness is larger than its volume (sphere/cylinder).\n"
                          "WARNING  Please check parameter values. Using bulk sample (thickness=0).\n",
                          NAME_CURRENT_COMP););
      thickness = 0;
    } else if (!radius && (xwidth < 2 * fabs (thickness) || yheight < 2 * fabs (thickness) || zdepth < 2 * fabs (thickness))) {
      MPI_MASTER (printf ("PowderN: %s: hollow sample thickness is larger than its volume (box).\n"
                          "WARNING  Please check parameter values.\n",
                          NAME_CURRENT_COMP););
    }
  }

  if (concentric && thickness == 0) {
    MPI_MASTER (printf ("PowderN: %s:Can not use concentric mode\n"
                        "WARNING     on non hollow shape. Ignoring.\n",
                        NAME_CURRENT_COMP););
    concentric = 0;
  }

  if (thickness > 0) {
    if (radius > thickness) {
      line_info.radius_i = radius - thickness;
    } else {
      if (xwidth > 2 * thickness)
        line_info.xwidth_i = xwidth - 2 * thickness;
      if (yheight > 2 * thickness)
        line_info.yheight_i = yheight - 2 * thickness;
      if (zdepth > 2 * thickness)
        line_info.zdepth_i = zdepth - 2 * thickness;
    }
  } else if (thickness < 0) {
    thickness = fabs (thickness);
    if (radius) {
      line_info.radius_i = radius;
      radius = line_info.radius_i + thickness;
    } else {
      line_info.xwidth_i = xwidth;
      line_info.yheight_i = yheight;
      line_info.zdepth_i = zdepth;
      xwidth = xwidth + 2 * thickness;
      yheight = yheight + 2 * thickness;
      zdepth = zdepth + 2 * thickness;
    }
  }

  if (!line_info.yheight_i) {
    line_info.yheight_i = yheight;
  }

  if (!p_interact) {
    fprintf (stderr, "WARNING(%s): p_interact=0, adjusting to 0.01, to avoid algorithm instability\n", NAME_CURRENT_COMP);
    p_interact = 1e-2;
  }
  if (!p_inc) {
    fprintf (stderr, "WARNING(%s): p_inc=0, adjusting to 0.01, to avoid algorithm instability\n", NAME_CURRENT_COMP);
    p_inc = 1e-2;
  }
  if (!p_transmit) {
    fprintf (stderr, "WARNING(%s): p_transmit=0, adjusting to 0.01, to avoid algorithm instability\n", NAME_CURRENT_COMP);
    p_transmit = 1e-2;
  }
  double p_sum = p_interact + p_inc + p_transmit;
  p_interact = p_interact / p_sum;
  p_inc = p_inc / p_sum;
  p_transmit = p_transmit / p_sum;

  if (concentric) {
    MPI_MASTER (printf ("PowderN: %s: Concentric mode - remember to include the 'opposite' copy of this component !\n"
                        "WARNING  The equivalent, 'opposite' comp should have concentric=0\n",
                        NAME_CURRENT_COMP););
    if (p_transmit < 0.1) {
      MPI_MASTER (printf ("PowderN: %s: Concentric mode and p_transmit<0.1 !\n"
                          "WARNING  Consider increasing p_transmit as few particles will reach the inner hollow.\n",
                          NAME_CURRENT_COMP););
    }
  }

  if (reflections && strlen (reflections) && strcmp (reflections, "NULL") && strcmp (reflections, "0")) {
    i = read_line_data (reflections, &line_info);
    if (i == 0)
      exit (fprintf (stderr,
                     "PowderN: %s: reflection file %s is not valid.\n"
                     "ERROR    Please check file format (laz or lau).\n",
                     NAME_CURRENT_COMP, reflections));
  }

  /* compute the scattering unit density from material weight and density */
  /* the weight of the scattering element is the chemical formula molecular weight
   * times the nb of chemical formulae in the scattering element (nb_atoms) */
  if (!line_info.V_0 && line_info.at_nb > 0 && line_info.at_weight > 0 && line_info.rho > 0) {
    /* molar volume [cm^3/mol] = weight [g/mol] / density [g/cm^3] */
    /* atom density per Angs^3 = [mol/cm^3] * N_Avogadro *(1e-8)^3 */
    line_info.V_0 = line_info.at_nb / (line_info.rho / line_info.at_weight / 1e24 * 6.02214199e23);
  }

  /* the scattering unit cross sections are the chemical formula onces
   * times the nb of chemical formulae in the scattering element */
  if (line_info.at_nb > 0) {
    line_info.sigma_a *= line_info.at_nb;
    line_info.sigma_i *= line_info.at_nb;
  }

  if (line_info.sigma_a < 0)
    line_info.sigma_a = 0;
  if (line_info.sigma_i < 0)
    line_info.sigma_i = 0;

  if (line_info.V_0 <= 0)
    MPI_MASTER (printf ("PowderN: %s: density/unit cell volume is NULL (Vc). Unactivating component.\n", NAME_CURRENT_COMP););

  if (line_info.V_0 > 0 && p_inc && !line_info.sigma_i) {
    MPI_MASTER (printf ("PowderN: %s: WARNING: You have requested statistics for incoherent scattering but not defined sigma_inc!\n", NAME_CURRENT_COMP););
  }

  if (line_info.flag_barns) { /* Factor 100 to convert from barns to fm^2 */
    line_info.XsectionFactor = 100;
  } else {
    line_info.XsectionFactor = 1;
  }

  if (line_info.V_0 > 0 && i) {
    L = line_info.list;

    line_info.q_v = malloc (line_info.count * sizeof (double));
    line_info.w_v = malloc (line_info.count * sizeof (double));
    line_info.my_s_v2 = malloc (line_info.count * sizeof (double));
    if (!line_info.q_v || !line_info.w_v || !line_info.my_s_v2)
      exit (fprintf (stderr, "PowderN: %s: ERROR allocating memory (init)\n", NAME_CURRENT_COMP));
    for (i = 0; i < line_info.count; i++) {
      line_info.my_s_v2[i] = 4 * PI * PI * PI * pack * (L[i].DWfactor ? L[i].DWfactor : 1) / (line_info.V_0 * line_info.V_0 * V2K * V2K)
                             * (L[i].j * L[i].F2 / L[i].q) * line_info.XsectionFactor;
      /* Is not yet divided by v^2 */
      /* Squires [3.103] */
      line_info.q_v[i] = L[i].q * K2V;
      line_info.w_v[i] = L[i].w;
    }
  }
  if (line_info.V_0 > 0) {
    /* Is not yet divided by v */
    line_info.my_a_v = pack * line_info.sigma_a / line_info.V_0 * 2200 * 100; // Factor 100 to convert from barns to fm^2
    line_info.my_inc = pack * line_info.sigma_i / line_info.V_0 * 100;        // Factor 100 to convert from barns to fm^2
    MPI_MASTER (printf ("PowderN: %s: Vc=%g [Angs] sigma_abs=%g [barn] sigma_inc=%g [barn] reflections=%s\n", NAME_CURRENT_COMP, line_info.V_0, line_info.sigma_a,
                        line_info.sigma_i, reflections && strlen (reflections) ? reflections : "NULL"););
  }

  /* update JS, 1/7/2017
    Get target coordinates relative to the local reference frame.
  */
  if (target_index) {
    Coords ToTarget;
    ToTarget = coords_sub (POS_A_COMP_INDEX (INDEX_CURRENT_COMP + target_index), POS_A_CURRENT_COMP);
    ToTarget = rot_apply (ROT_A_CURRENT_COMP, ToTarget);
    coords_get (ToTarget, &tgt_x, &tgt_y, &tgt_z);
    NORM (tgt_x, tgt_y, tgt_z);
    printf ("PowderN: Target direction = (%g %g %g)\n", tgt_x, tgt_y, tgt_z);
  } else {
    tgt_x = 0.0;
    tgt_y = 0.0;
    tgt_z = 1.0;
  }
  #undef reflections
  #undef geometry
  #undef format
  #undef radius
  #undef yheight
  #undef xwidth
  #undef zdepth
  #undef thickness
  #undef pack
  #undef Vc
  #undef sigma_abs
  #undef sigma_inc
  #undef delta_d_d
  #undef p_inc
  #undef p_transmit
  #undef DW
  #undef nb_atoms
  #undef d_omega
  #undef d_phi
  #undef tth_sign
  #undef p_interact
  #undef concentric
  #undef density
  #undef weight
  #undef barns
  #undef Strain
  #undef focus_flip
  #undef target_index
  #undef order
  #undef line_info
  #undef columns
  #undef offdata
  #undef tgt_x
  #undef tgt_y
  #undef tgt_z
  return(_comp);
} /* class_PowderN_init */



int init(void) { /* called by mccode_main for PSI_CAMEA:INITIALISE */
  DEBUG_INSTR();
  // Initialise rng
  srandom(_hash(mcseed-1));

  /* code_main/parseoptions/readparams sets instrument parameters value */
  stracpy(instrument->_name, "PSI_CAMEA", 256);

  /* Instrument 'PSI_CAMEA' INITIALISE */
  SIG_MESSAGE("[PSI_CAMEA] INITIALISE [(null):-1]");
  #define SourceE (instrument->_parameters.SourceE)
  #define DeltaSourceE (instrument->_parameters.DeltaSourceE)
  #define EI (instrument->_parameters.EI)
  #define A3 (instrument->_parameters.A3)
  #define A4 (instrument->_parameters.A4)
  #define SAMPLE (instrument->_parameters.SAMPLE)
  #define RV_mono_Bool (instrument->_parameters.RV_mono_Bool)
  #define RH_mono_Bool (instrument->_parameters.RH_mono_Bool)
  #define Lv (instrument->_parameters.Lv)
  #define Lh (instrument->_parameters.Lh)
  #define monoShieldingWidth (instrument->_parameters.monoShieldingWidth)
  #define monoShieldingHeight (instrument->_parameters.monoShieldingHeight)
  #define monoShieldingDistance (instrument->_parameters.monoShieldingDistance)
  #define MonoShielding (instrument->_parameters.MonoShielding)
  #define Be_filter (instrument->_parameters.Be_filter)
  #define sampleHeight (instrument->_parameters.sampleHeight)
  #define sampleRadius (instrument->_parameters.sampleRadius)
  #define sampleThickness (instrument->_parameters.sampleThickness)
  #define samplePosY (instrument->_parameters.samplePosY)
  #define sampleFluxDiagnosticXWidth (instrument->_parameters.sampleFluxDiagnosticXWidth)
  #define sampleFluxDiagnosticYHeight (instrument->_parameters.sampleFluxDiagnosticYHeight)
{
/********************************************************************************************/
thetaA1= asin(1.0/(0.1106*sqrt(EI)*2.0*3.355));
thetaA2=2.0*thetaA1;
R_mono=sqrt( ( 2.0*1.6*1.6+2.0*1.6*1.6*cos(thetaA2)) )/2.0/sqrt(sin(thetaA2)*sin(thetaA2))*2;
thetaA2=thetaA2*RAD2DEG;
thetaA1=thetaA1*RAD2DEG;
lmin=1.0/0.1106/sqrt(SourceE+DeltaSourceE/2.0);
lmax=1.0/0.1106/sqrt(SourceE-DeltaSourceE/2.0);
printf("\n lmin: %f      lmax: %f \n",lmin,lmax);
printf("\n E0: %f      E0max: %f E0min %f \n",SourceE,SourceE+DeltaSourceE/2.0,SourceE-DeltaSourceE/2.0);
/********************************************************************************************/

dLambda = 0.5*(WaveMax - WaveMin);
Lambda0 = dLambda+WaveMin;

var_divreq_x = divreq_x;
var_divreq_y = divreq_y;

u=1e-4;



double BE_THICK = 0.12; // Originally from Secondary Spectrometer
int COARSE = 1;
// Filter length*/
OUTFILTER_THICK = BE_THICK/0.05;


// Coarse collimator 
if (COARSE) {coarse = 1;}
else {coarse = 0;}

// Analyzer positions
z_an1[1]=0.9115;
z_an1[2]=0.9209;
z_an1[3]=0.9300;
z_an1[4]=0.9388;
z_an1[5]=0.9474;
y_an1[1]=-0.0275;
y_an1[2]=-0.0140;
y_an1[3]=0.0000;
y_an1[4]=0.0145;
y_an1[5]=0.0297;
thet_an1[1]=47.17;
thet_an1[2]=48.03;
thet_an1[3]=48.90;
thet_an1[4]=49.79;
thet_an1[5]=50.69;
ana_l[1]=0.0720;
Ana1=0;

z_an2[1]=0.9744;
z_an2[2]=0.9843;
z_an2[3]=0.9939;
z_an2[4]=1.0033;
z_an2[5]=1.0123;
y_an2[1]=-0.0290;
y_an2[2]=-0.0148;
y_an2[3]=0.0000;
y_an2[4]=0.0153;
y_an2[5]=0.0312;
thet_an2[1]=45.51;
thet_an2[2]=46.35;
thet_an2[3]=47.21;
thet_an2[4]=48.09;
thet_an2[5]=48.98;
ana_l[2]=0.082;
Ana2=0;

z_an3[1]=1.0354;
z_an3[2]=1.0462;
z_an3[3]=1.0569;
z_an3[4]=1.0671;
z_an3[5]=1.0771;
y_an3[1]=-0.0311;
y_an3[2]=-0.0160;
y_an3[3]=0.0000;
y_an3[4]=0.0165;
y_an3[5]=0.0338;
thet_an3[1]=43.81;
thet_an3[2]=44.65;
thet_an3[3]=45.53;
thet_an3[4]=46.41;
thet_an3[5]=47.32;
ana_l[3]=0.092;
Ana3=0;

z_an4[1]=1.0959;
z_an4[2]=1.1078;
z_an4[3]=1.1195;
z_an4[4]=1.1309;
z_an4[5]=1.1420;
y_an4[1]=-0.0332;
y_an4[2]=-0.0170;
y_an4[3]=0.0000;
y_an4[4]=0.0177;
y_an4[5]=0.0362;
thet_an4[1]=42.11;
thet_an4[2]=42.96;
thet_an4[3]=43.84;
thet_an4[4]=44.74;
thet_an4[5]=45.66;
ana_l[4]=0.103;
Ana4=0;

z_an5[1]=1.1567;
z_an5[2]=1.1697;
z_an5[3]=1.1827;
z_an5[4]=1.1953;
z_an5[5]=1.2076;
y_an5[1]=-0.0350;
y_an5[2]=-0.0180;
y_an5[3]=0.0000;
y_an5[4]=0.0187;
y_an5[5]=0.0382;
thet_an5[1]=40.42;
thet_an5[2]=41.27;
thet_an5[3]=42.16;
thet_an5[4]=43.05;
thet_an5[5]=43.97;
ana_l[5]=0.113;
Ana5=0;

z_an6[1]=1.2170;
z_an6[2]=1.2313;
z_an6[3]=1.2456;
z_an6[4]=1.2595;
z_an6[5]=1.2732;
y_an6[1]=-0.0365;
y_an6[2]=-0.0188;
y_an6[3]=0.0000;
y_an6[4]=0.0195;
y_an6[5]=0.0402;
thet_an6[1]=38.75;
thet_an6[2]=39.60;
thet_an6[3]=40.47;
thet_an6[4]=41.36;
thet_an6[5]=42.28;
ana_l[6]=0.120;
Ana6=0;

z_an7[1]=1.2775;
z_an7[2]=1.2936;
z_an7[3]=1.3098;
z_an7[4]=1.3256;
z_an7[5]=1.3413;
y_an7[1]=-0.0389;
y_an7[2]=-0.0201;
y_an7[3]=0.0000;
y_an7[4]=0.0209;
y_an7[5]=0.0431;
thet_an7[1]=37.04;
thet_an7[2]=37.90;
thet_an7[3]=38.79;
thet_an7[4]=39.69;
thet_an7[5]=40.63;
ana_l[7]=0.129;
Ana7=0;

z_an8[1]=1.3385;
z_an8[2]=1.3565;
z_an8[3]=1.3747;
z_an8[4]=1.3925;
z_an8[5]=1.4102;
y_an8[1]=-0.0409;
y_an8[2]=-0.0212;
y_an8[3]=0.0000;
y_an8[4]=0.0221;
y_an8[5]=0.0456;
thet_an8[1]=35.35;
thet_an8[2]=36.21;
thet_an8[3]=37.10;
thet_an8[4]=38.01;
thet_an8[5]=38.95;
ana_l[8]=0.140;
Ana8=0;

ana_l[1]=ana_l[1]+ana_l_add;
ana_l[2]=ana_l[2]+ana_l_add;
ana_l[3]=ana_l[3]+ana_l_add;
ana_l[4]=ana_l[4]+ana_l_add;
ana_l[5]=ana_l[5]+ana_l_add;
ana_l[6]=ana_l[6]+ana_l_add;
ana_l[7]=ana_l[7]+ana_l_add;
ana_l[8]=ana_l[8]+ana_l_add;


// Detector positions rotation given in degrees

ang_1[1]=-3.3;
ang_1[2]=-2.2;
ang_1[3]=-1.1;
ang_1[4]=0;
ang_1[5]=1.1;
ang_1[6]=2.2;
ang_1[7]=3.3;

ang_2[1]=-2.75;
ang_2[2]=-1.65;
ang_2[3]=-0.55;
ang_2[4]=0.55;
ang_2[5]=1.65;
ang_2[6]=2.75;

dety_1=0.71; //
dety_2=0.70; //
det_cen=DET_cen;

A3_val = A3;//*3.141592/180.0;

A4_val = A4;//*3.141592/180.0;
//sourceDivergence = source_DivH;

for (i=1; i<8; i++){
	detx_1[i] = -sin(ang_1[i]*PI/180)*det_cen;
	detz_1[i] = cos(ang_1[i]*PI/180)*det_cen;
}

for (i=1; i<7; i++){
	detx_2[i] = -sin(ang_2[i]*PI/180)*det_cen;
	detz_2[i] = cos(ang_2[i]*PI/180)*det_cen;
}


RV_mono = Lv*sin(DEG2RAD*thetaA1)*(double)RV_mono_Bool;
RH_mono = Lh/sin(DEG2RAD*thetaA1)*(double)RH_mono_Bool;
printf("\n RV_mono: %f      RH_mono: %f \n",RV_mono,RH_mono);


mvinsertlr[0] = 4.5; // -> 1.6
mvinsertlr[1] = 4.5; // -> 1.6
mvinsertlr[2] = 4.0; // -> 2.6
mvinsertlr[3] = 4.0; // -> 2.6
mvinsertlr[4] = 3.5; // -> 4.6

mvinserttb[0] = 4.5; // -> 1.0
mvinserttb[1] = 3.5; // -> 2.0
mvinserttb[2] = 3.5; // -> 2.0
mvinserttb[3] = 3.0; // -> 4.6
mvinserttb[4] = 3.0; // -> 4.6


slinsert[0] = 1.0;
slinsert[1] = 0.6;
slinsert[2] = 0.4;
slinsert[3] = 0.6;
slinsert[4] = 2.0348-u;

mvle2[0]   = 2.0;
mvle2[1]   = 2.0;
mvle2[2]   = 2.5;
mvle2[3]   = 2.5;
mvle2[4]   = 2.5;
mvle2[5]   = 2.5;
mvle2[6]   = 2.5;
mvle2[7]   = 2.5;
mvle2[8]   = 2.5;
mvle2[9]   = 2.5;
mvle2[10] = 2.5;
mvle2[11] = 2.5;
mvle2[12] = 2.5;
mvle2[13] = 2.5;
mvle2[14] = 2.5;
mvle2[15] = 2.5;
mvle2[16] = 2.5;
mvle2[17] = 3.0;
mvle2[18] = 3.0;
mvle2[19] = 3.0;
mvle2[20] = 3.5;
mvle2[21] = 4.0;

mvre2[0]   = 2.0;
mvre2[1]   = 2.0;
mvre2[2]   = 2.5;
mvre2[3]   = 2.5;
mvre2[4]   = 2.5;
mvre2[5]   = 2.5;
mvre2[6]   = 2.5;
mvre2[7]   = 2.5;
mvre2[8]   = 2.5;
mvre2[9]   = 2.5;
mvre2[10] = 2.5;
mvre2[11] = 2.5;
mvre2[12] = 2.5;
mvre2[13] = 2.5;
mvre2[14] = 2.5;
mvre2[15] = 2.5;
mvre2[16] = 2.5;
mvre2[17] = 3.0;
mvre2[18] = 3.0;
mvre2[19] = 3.0;
mvre2[20] = 3.5;
mvre2[21] = 4.0;

mvte2[0]   = 2.5;
mvte2[1]   = 2.5;
mvte2[2]   = 2.5;
mvte2[3]   = 2.5;
mvte2[4]   = 2.5;
mvte2[5]   = 2.5;
mvte2[6]   = 2.5;
mvte2[7]   = 2.5;
mvte2[8]   = 2.5;
mvte2[9]   = 2.5;
mvte2[10] = 3.0;
mvte2[11] = 3.0;
mvte2[12] = 3.0;
mvte2[13] = 3.0;
mvte2[14] = 3.0;
mvte2[15] = 3.0;
mvte2[16] = 3.0;
mvte2[17] = 3.0;
mvte2[18] = 3.0;
mvte2[19] = 3.0;
mvte2[20] = 3.0;
mvte2[21] = 3.0;

mvbe2[0]   = 2.5;
mvbe2[1]   = 2.5;
mvbe2[2]   = 2.5;
mvbe2[3]   = 2.5;
mvbe2[4]   = 2.5;
mvbe2[5]   = 2.5;
mvbe2[6]   = 2.5;
mvbe2[7]   = 2.5;
mvbe2[8]   = 2.5;
mvbe2[9]   = 2.5;
mvbe2[10] = 3.0;
mvbe2[11] = 3.0;
mvbe2[12] = 3.0;
mvbe2[13] = 3.0;
mvbe2[14] = 3.0;
mvbe2[15] = 3.0;
mvbe2[16] = 3.0;
mvbe2[17] = 3.0;
mvbe2[18] = 3.0;
mvbe2[19] = 3.0;
mvbe2[20] = 3.0;
mvbe2[21] = 3.0;

for (i=0; i<21; i++){
	sle2[i] = 0.5;
}
sle2[21] = 0.6155;




mvlre3a[0]   = 2.5;
mvlre3a[1]   = 2.5;
mvlre3a[2]   = 2.5;
mvlre3a[3]   = 2.5;
mvlre3a[4]   = 2.5;
mvlre3a[5]   = 2.5;
mvlre3a[6]   = 2.5;

mvlre3b[0]   = 2.5;
mvlre3b[1]   = 2.5;
mvlre3b[2]   = 2.5;
mvlre3b[3] = 2.5;
mvlre3b[4] = 2.5;
mvlre3b[5] = 3.0;
mvlre3b[6] = 3.0;
mvlre3b[7] = 3.0;
mvlre3b[8] = 3.0;
mvlre3b[9] = 3.0;
mvlre3b[10] = 3.0;
mvlre3b[11] = 3.5;
mvlre3b[12] = 3.5;
mvlre3b[13] = 3.5;
mvlre3b[14] = 4.0;
mvlre3b[15] = 4.0;
mvlre3b[16] = 4.5;
mvlre3b[17] = 4.5;
mvlre3b[18] = 4.5;
mvlre3b[19] = 4.5;

mvtbe3a[0]   = 3.0;
mvtbe3a[1]   = 3.0;
mvtbe3a[2]   = 3.0;
mvtbe3a[3]   = 3.0;
mvtbe3a[4]   = 3.0;
mvtbe3a[5]   = 3.0;
mvtbe3a[6]   = 3.0;

mvtbe3b[0]   = 3.0;
mvtbe3b[1]   = 3.0;
mvtbe3b[2]   = 3.0;
mvtbe3b[3] = 3.0;
mvtbe3b[4] = 3.0;
mvtbe3b[5] = 3.0;
mvtbe3b[6] = 3.0;
mvtbe3b[7] = 3.0;
mvtbe3b[8] = 3.0;
mvtbe3b[9] = 3.5;
mvtbe3b[10] = 3.5;
mvtbe3b[11] = 3.5;
mvtbe3b[12] = 3.5;
mvtbe3b[13] = 3.5;
mvtbe3b[14] = 4.0;
mvtbe3b[15] = 4.0;
mvtbe3b[16] = 4.5;
mvtbe3b[17] = 4.5;
mvtbe3b[18] = 4.5;
mvtbe3b[19] = 4.5;

for (i=0; i<6; i++){
	sle3a[i] = 0.49;
}
sle3a[6] = 0.5796154567641345;

for (i=0; i<19; i++){
	sle3b[i] = 0.49;
}
sle3b[19] = 0.426082;


}
  #undef SourceE
  #undef DeltaSourceE
  #undef EI
  #undef A3
  #undef A4
  #undef SAMPLE
  #undef RV_mono_Bool
  #undef RH_mono_Bool
  #undef Lv
  #undef Lh
  #undef monoShieldingWidth
  #undef monoShieldingHeight
  #undef monoShieldingDistance
  #undef MonoShielding
  #undef Be_filter
  #undef sampleHeight
  #undef sampleRadius
  #undef sampleThickness
  #undef samplePosY
  #undef sampleFluxDiagnosticXWidth
  #undef sampleFluxDiagnosticYHeight
  _Origin_setpos(); /* type Progress_bar */
  _source_setpos(); /* type Source_gen4 */
  _StartOfGuideMonitor_setpos(); /* type PSD_monitor */
  _StartOfGuide_setpos(); /* type Arm */
  _Insert_setpos(); /* type Elliptic_guide_gravity */
  _EndOfInsertPSD_setpos(); /* type PSD_monitor */
  _E2_setpos(); /* type Elliptic_guide_gravity */
  _EndOfelement_5_setpos(); /* type Arm */
  _E2PSD_setpos(); /* type PSD_monitor */
  _EndOfelement_4_setpos(); /* type Arm */
  _C1_setpos(); /* type Bender */
  _EndOfelement_2_setpos(); /* type Arm */
  _C1End_setpos(); /* type PSD_monitor */
  _E3a_setpos(); /* type Elliptic_guide_gravity */
  _E3aEnd_setpos(); /* type PSD_monitor */
  _E3b_setpos(); /* type Elliptic_guide_gravity */
  _E3bEnd_setpos(); /* type PSD_monitor */
  _SlitGuideEnd_setpos(); /* type Slit */
  _Mono_setpos(); /* type Monochromator_curved */
  _A2_setpos(); /* type Arm */
  _monochromatorShielding_setpos(); /* type Slit */
  _slit_setpos(); /* type Slit */
  _SlitMonitor_setpos(); /* type PSD_monitor */
  _SamplePos_setpos(); /* type Arm */
  _AMidt_setpos(); /* type Arm */
  _a41_setpos(); /* type Arm */
  _a42_setpos(); /* type Arm */
  _a43_setpos(); /* type Arm */
  _a44_setpos(); /* type Arm */
  _a45_setpos(); /* type Arm */
  _a46_setpos(); /* type Arm */
  _a47_setpos(); /* type Arm */
  _a48_setpos(); /* type Arm */
  _sample_flux_before_setpos(); /* type PSD_monitor */
  _sample_scatter_state_reset_setpos(); /* type Arm */
  _VanSample_setpos(); /* type Incoherent */
  _sample_setpos(); /* type Phonon_simple */
  _powder1_setpos(); /* type Powder1 */
  _res_sample_setpos(); /* type Res_sample */
  _sample_flux_after_unscattered_setpos(); /* type PSD_monitor */
  _sample_cylinder_monitor_setpos(); /* type Cyl_monitor_PSD */
  _sample_spherical_monitor_setpos(); /* type PSD_monitor_4PI */
  _BackEndMonitor_setpos(); /* type PSD_monitor */
  _slitBackEnd_setpos(); /* type Slit */
  _filter_gen_setpos(); /* type Filter_gen */
  _BeFilter_setpos(); /* type PowderN */

  /* call iteratively all components INITIALISE */
  class_Progress_bar_init(&_Origin_var);

  class_Source_gen4_init(&_source_var);

  class_PSD_monitor_init(&_StartOfGuideMonitor_var);


  class_Elliptic_guide_gravity_init(&_Insert_var);

  class_PSD_monitor_init(&_EndOfInsertPSD_var);

  class_Elliptic_guide_gravity_init(&_E2_var);


  class_PSD_monitor_init(&_E2PSD_var);


  class_Bender_init(&_C1_var);


  class_PSD_monitor_init(&_C1End_var);

  class_Elliptic_guide_gravity_init(&_E3a_var);

  class_PSD_monitor_init(&_E3aEnd_var);

  class_Elliptic_guide_gravity_init(&_E3b_var);

  class_PSD_monitor_init(&_E3bEnd_var);

  class_Slit_init(&_SlitGuideEnd_var);

  class_Monochromator_curved_init(&_Mono_var);


  class_Slit_init(&_monochromatorShielding_var);

  class_Slit_init(&_slit_var);

  class_PSD_monitor_init(&_SlitMonitor_var);











  class_PSD_monitor_init(&_sample_flux_before_var);


  class_Incoherent_init(&_VanSample_var);

  class_Phonon_simple_init(&_sample_var);

  class_Powder1_init(&_powder1_var);

  class_Res_sample_init(&_res_sample_var);

  class_PSD_monitor_init(&_sample_flux_after_unscattered_var);

  class_Cyl_monitor_PSD_init(&_sample_cylinder_monitor_var);

  class_PSD_monitor_4PI_init(&_sample_spherical_monitor_var);

  class_PSD_monitor_init(&_BackEndMonitor_var);

  class_Slit_init(&_slitBackEnd_var);

  class_Filter_gen_init(&_filter_gen_var);

  class_PowderN_init(&_BeFilter_var);

  if (mcdotrace) display();
  DEBUG_INSTR_END();

#ifdef OPENACC
#include <openacc.h>
#pragma acc update device(_Origin_var)
#pragma acc update device(_source_var)
#pragma acc update device(_StartOfGuideMonitor_var)
#pragma acc update device(_StartOfGuide_var)
#pragma acc update device(_Insert_var)
#pragma acc update device(_EndOfInsertPSD_var)
#pragma acc update device(_E2_var)
#pragma acc update device(_EndOfelement_5_var)
#pragma acc update device(_E2PSD_var)
#pragma acc update device(_EndOfelement_4_var)
#pragma acc update device(_C1_var)
#pragma acc update device(_EndOfelement_2_var)
#pragma acc update device(_C1End_var)
#pragma acc update device(_E3a_var)
#pragma acc update device(_E3aEnd_var)
#pragma acc update device(_E3b_var)
#pragma acc update device(_E3bEnd_var)
#pragma acc update device(_SlitGuideEnd_var)
#pragma acc update device(_Mono_var)
#pragma acc update device(_A2_var)
#pragma acc update device(_monochromatorShielding_var)
#pragma acc update device(_slit_var)
#pragma acc update device(_SlitMonitor_var)
#pragma acc update device(_SamplePos_var)
#pragma acc update device(_AMidt_var)
#pragma acc update device(_a41_var)
#pragma acc update device(_a42_var)
#pragma acc update device(_a43_var)
#pragma acc update device(_a44_var)
#pragma acc update device(_a45_var)
#pragma acc update device(_a46_var)
#pragma acc update device(_a47_var)
#pragma acc update device(_a48_var)
#pragma acc update device(_sample_flux_before_var)
#pragma acc update device(_sample_scatter_state_reset_var)
#pragma acc update device(_VanSample_var)
#pragma acc update device(_sample_var)
#pragma acc update device(_powder1_var)
#pragma acc update device(_res_sample_var)
#pragma acc update device(_sample_flux_after_unscattered_var)
#pragma acc update device(_sample_cylinder_monitor_var)
#pragma acc update device(_sample_spherical_monitor_var)
#pragma acc update device(_BackEndMonitor_var)
#pragma acc update device(_slitBackEnd_var)
#pragma acc update device(_filter_gen_var)
#pragma acc update device(_BeFilter_var)
#pragma acc update device(_instrument_var)
#endif

  return(0);
} /* init */

/*******************************************************************************
* components TRACE
*******************************************************************************/

#define x (_particle->x)
#define y (_particle->y)
#define z (_particle->z)
#define vx (_particle->vx)
#define vy (_particle->vy)
#define vz (_particle->vz)
#define t (_particle->t)
#define sx (_particle->sx)
#define sy (_particle->sy)
#define sz (_particle->sz)
#define p (_particle->p)
#define mcgravitation (_particle->mcgravitation)
#define mcMagnet (_particle->mcMagnet)
#define allow_backprop (_particle->allow_backprop)
#define _mctmp_a (_particle->_mctmp_a)
#define _mctmp_b (_particle->_mctmp_b)
#define _mctmp_c (_particle->_mctmp_c)
/* if on GPU, globally nullify sprintf,fprintf,printfs   */
/* (Similar defines are available in each comp trace but */
/*  those are not enough to handle external libs etc. )  */
#ifdef OPENACC
#define fprintf(stderr,...) printf(__VA_ARGS__)
#define sprintf(string,...) printf(__VA_ARGS__)
#define exit(...) noprintf()
#define strcmp(a,b) str_comp(a,b)
#define strlen(a) str_len(a)
#endif
#define SCATTERED (_particle->_scattered)
#define RESTORE (_particle->_restore)
#define RESTORE_NEUTRON(_index, ...) _particle->_restore = _index;
#define ABSORB0 do { DEBUG_STATE(); DEBUG_ABSORB(); MAGNET_OFF; ABSORBED++; return; } while(0)
#define ABSORBED (_particle->_absorbed)
#define mcget_run_num() _particle->_uid
#define ABSORB ABSORB0
#pragma acc routine
void class_Progress_bar_trace(_class_Progress_bar *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define profile (_comp->_parameters.profile)
  #define percent (_comp->_parameters.percent)
  #define flag_save (_comp->_parameters.flag_save)
  #define minutes (_comp->_parameters.minutes)
  #define IntermediateCnts (_comp->_parameters.IntermediateCnts)
  #define StartTime (_comp->_parameters.StartTime)
  #define EndTime (_comp->_parameters.EndTime)
  #define CurrentTime (_comp->_parameters.CurrentTime)
  #define infostring (_comp->_parameters.infostring)
  SIG_MESSAGE("[_Origin_trace] component Origin=Progress_bar() TRACE [Progress_bar:0]");

  #ifndef OPENACC
  double ncount;
  ncount = mcget_run_num ();
  if (!StartTime) {
    time (&StartTime); /* compute starting time */
    IntermediateCnts = 1e3;
  }
  time_t NowTime;
  time (&NowTime);
  /* compute initial estimate of computation duration */
  if (!EndTime && ncount >= IntermediateCnts) {
    CurrentTime = NowTime;
    if (difftime (NowTime, StartTime) > 10 && ncount) { /* wait 10 sec before writing ETA */
      EndTime = StartTime + (time_t)(difftime (NowTime, StartTime) * (double)mcget_ncount () / ncount);
      IntermediateCnts = 0;
      MPI_MASTER (fprintf (stdout, "\nTrace ETA "); fprintf (stdout, "%s", infostring);
                  if (difftime (EndTime, StartTime) < 60.0) fprintf (stdout, "%g [s] ", difftime (EndTime, StartTime));
                  else if (difftime (EndTime, StartTime) > 3600.0) fprintf (stdout, "%g [h] ", difftime (EndTime, StartTime) / 3600.0);
                  else fprintf (stdout, "%g [min] ", difftime (EndTime, StartTime) / 60.0); fprintf (stdout, "\n"););
    } else
      IntermediateCnts += 1e3;
    fflush (stdout);
  }

  /* display percentage when percent or minutes have reached step */
  if (EndTime && mcget_ncount () && ((minutes && difftime (NowTime, CurrentTime) > minutes * 60) || (percent && !minutes && ncount >= IntermediateCnts))) {
    MPI_MASTER (fprintf (stdout, "%llu %%\n", (unsigned long long)(ncount * 100.0 / mcget_ncount ())); fflush (stdout););
    CurrentTime = NowTime;

    IntermediateCnts = ncount + percent * mcget_ncount () / 100;
    /* check that next intermediate ncount check is a multiple of the desired percentage */
    IntermediateCnts = floor (IntermediateCnts * 100 / percent / mcget_ncount ()) * percent * mcget_ncount () / 100;
    /* raise flag to indicate that we did something */
    SCATTER;
    if (flag_save)
      save (NULL);
  }
  #endif
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  #undef infostring
  return;
} /* class_Progress_bar_trace */

#pragma acc routine
void class_Source_gen4_trace(_class_Source_gen4 *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define flux_file (_comp->_parameters.flux_file)
  #define xdiv_file (_comp->_parameters.xdiv_file)
  #define ydiv_file (_comp->_parameters.ydiv_file)
  #define radius (_comp->_parameters.radius)
  #define dist (_comp->_parameters.dist)
  #define xw (_comp->_parameters.xw)
  #define yh (_comp->_parameters.yh)
  #define E0 (_comp->_parameters.E0)
  #define dE (_comp->_parameters.dE)
  #define Lambda0 (_comp->_parameters.Lambda0)
  #define dLambda (_comp->_parameters.dLambda)
  #define I1 (_comp->_parameters.I1)
  #define h (_comp->_parameters.h)
  #define w (_comp->_parameters.w)
  #define gaussian (_comp->_parameters.gaussian)
  #define verbose (_comp->_parameters.verbose)
  #define T1 (_comp->_parameters.T1)
  #define flux_file_perAA (_comp->_parameters.flux_file_perAA)
  #define flux_file_log (_comp->_parameters.flux_file_log)
  #define Lmin (_comp->_parameters.Lmin)
  #define Lmax (_comp->_parameters.Lmax)
  #define Emin (_comp->_parameters.Emin)
  #define Emax (_comp->_parameters.Emax)
  #define T2 (_comp->_parameters.T2)
  #define I2 (_comp->_parameters.I2)
  #define T3 (_comp->_parameters.T3)
  #define I3 (_comp->_parameters.I3)
  #define length (_comp->_parameters.length)
  #define phi_init (_comp->_parameters.phi_init)
  #define theta_init (_comp->_parameters.theta_init)
  #define HEtailA (_comp->_parameters.HEtailA)
  #define HEtailL0 (_comp->_parameters.HEtailL0)
  #define pTable (_comp->_parameters.pTable)
  #define pTable_x (_comp->_parameters.pTable_x)
  #define pTable_y (_comp->_parameters.pTable_y)
  #define p_in (_comp->_parameters.p_in)
  #define lambda0 (_comp->_parameters.lambda0)
  #define lambda02 (_comp->_parameters.lambda02)
  #define lambda0b (_comp->_parameters.lambda0b)
  #define lambda02b (_comp->_parameters.lambda02b)
  #define lambda0c (_comp->_parameters.lambda0c)
  #define lambda02c (_comp->_parameters.lambda02c)
  #define L2P (_comp->_parameters.L2P)
  #define L2Pb (_comp->_parameters.L2Pb)
  #define L2Pc (_comp->_parameters.L2Pc)
  #define pTable_xmin (_comp->_parameters.pTable_xmin)
  #define pTable_ymin (_comp->_parameters.pTable_ymin)
  #define pTable_xmax (_comp->_parameters.pTable_xmax)
  #define pTable_ymax (_comp->_parameters.pTable_ymax)
  #define pTable_xsum (_comp->_parameters.pTable_xsum)
  #define pTable_ysum (_comp->_parameters.pTable_ysum)
  #define pTable_dxmin (_comp->_parameters.pTable_dxmin)
  #define pTable_dxmax (_comp->_parameters.pTable_dxmax)
  #define pTable_dymin (_comp->_parameters.pTable_dymin)
  #define pTable_dymax (_comp->_parameters.pTable_dymax)
  SIG_MESSAGE("[_source_trace] component source=Source_gen4() TRACE [Source_gen4:0]");

  double theta0, phi0, theta1, phi1, chi, theta, phi, v, r, lambda;
  double tan_h, tan_v, Maxwell, lambda2, lambda5;

  if (verbose >= 0) {

    z = 0;

    if ((h == 0) || (w == 0)) {
      chi = 2 * PI * rand01 ();      /* Choose point on source */
      r = sqrt (rand01 ()) * radius; /* with uniform distribution. */
      x = r * cos (chi);
      y = r * sin (chi);
    } else {
      x = w * randpm1 () / 2; /* select point on source (uniform) */
      y = h * randpm1 () / 2;
    }
    if (length != 0)
      z = length * randpm1 () / 2;

    if (dist == 0) {
      theta0 = DEG2RAD * xw / 2;
      phi0 = DEG2RAD * yh / 2;
      theta1 = -DEG2RAD * xw / 2;
      phi1 = -DEG2RAD * yh / 2;
    } else {
      theta0 = -atan ((x - xw / 2.0) / dist) + theta_init / 180 * 3.1415; /* Angles to aim at target */
      phi0 = -atan ((y - yh / 2.0) / dist) + phi_init / 180 * 3.1415;
      theta1 = -atan ((x + xw / 2.0) / dist) + theta_init / 180 * 3.1415;
      phi1 = -atan ((y + yh / 2.0) / dist) + phi_init / 180 * 3.1415;
    }

    /* shot towards target : flat distribution */

    if (gaussian) {
      theta = theta0 + (theta1 - theta0) * (randnorm () * FWHM2RMS + 0.5);
      phi = phi0 + (phi1 - phi0) * (randnorm () * FWHM2RMS + 0.5);
    } else {
      theta = theta0 + (theta1 - theta0) * rand01 ();
      phi = phi0 + (phi1 - phi0) * rand01 ();
    }
    /* Assume linear distribution */
    lambda = Lambda0 + dLambda * randpm1 ();
    if (lambda <= 0)
      ABSORB;

    v = K2V * (2 * PI / lambda);
    p = p_in;
    if (!flux_file || !strlen (flux_file))
      p *= 2 * fabs ((theta1 - theta0) * sin ((phi1 - phi0) / 2)); /* solid angle */
    p *= cos (phi) * cos (theta);
    if (flux_file && strlen (flux_file) > 0) {
      double W = Table_Value (pTable, lambda, 1);
      if (flux_file_log)
        W = exp (W);
      p *= W;
    } else if (T1 > 0 && I1 > 0) {
      lambda2 = lambda * lambda;
      lambda5 = lambda2 * lambda2 * lambda;
      Maxwell = I1 * L2P / lambda5 * exp (-lambda02 / lambda2); /* 1/AA */

      if ((T2 > 0) && (I2 > 0)) {
        Maxwell += I2 * L2Pb / lambda5 * exp (-lambda02b / lambda2);
      }
      if ((T3 > 0) && (I3 > 0)) {
        Maxwell += I3 * L2Pc / lambda5 * exp (-lambda02c / lambda2);
      }
      if (HEtailA > 0) {
        Maxwell += HEtailA / (lambda - HEtailL0) / (lambda - HEtailL0);
      }
      p *= Maxwell;
    }

    /* Perform the correct treatment - no small angle approx. here! */
    tan_h = tan (theta);
    tan_v = tan (phi);
    vz = v / sqrt (1 + tan_v * tan_v + tan_h * tan_h);
    vy = tan_v * vz;
    vx = tan_h * vz;
    /* optional x-xdiv and y-ydiv weightening: position=along columns, div=along rows */
    if (xdiv_file && strlen (xdiv_file) > 0 && pTable_xsum > 0) {
      double i, j;
      j = (x - pTable_xmin) / (pTable_xmax - pTable_xmin) * pTable_x.columns;
      i = (theta * RAD2DEG - pTable_dxmin) / (pTable_dxmax - pTable_dxmin) * pTable_x.rows;
      r = Table_Value2d (pTable_x, i, j); /* row, column */
      p *= r / pTable_xsum;
    }
    if (ydiv_file && strlen (ydiv_file) > 0 && pTable_ysum > 0) {
      double i, j;
      j = (y - pTable_ymin) / (pTable_ymax - pTable_ymin) * pTable_y.columns;
      i = (phi * RAD2DEG - pTable_dymin) / (pTable_dymax - pTable_dymin) * pTable_y.rows;
      r = Table_Value2d (pTable_y, i, j);
      p *= r / pTable_ysum;
    }
    SCATTER;
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef flux_file
  #undef xdiv_file
  #undef ydiv_file
  #undef radius
  #undef dist
  #undef xw
  #undef yh
  #undef E0
  #undef dE
  #undef Lambda0
  #undef dLambda
  #undef I1
  #undef h
  #undef w
  #undef gaussian
  #undef verbose
  #undef T1
  #undef flux_file_perAA
  #undef flux_file_log
  #undef Lmin
  #undef Lmax
  #undef Emin
  #undef Emax
  #undef T2
  #undef I2
  #undef T3
  #undef I3
  #undef length
  #undef phi_init
  #undef theta_init
  #undef HEtailA
  #undef HEtailL0
  #undef pTable
  #undef pTable_x
  #undef pTable_y
  #undef p_in
  #undef lambda0
  #undef lambda02
  #undef lambda0b
  #undef lambda02b
  #undef lambda0c
  #undef lambda02c
  #undef L2P
  #undef L2Pb
  #undef L2Pc
  #undef pTable_xmin
  #undef pTable_ymin
  #undef pTable_xmax
  #undef pTable_ymax
  #undef pTable_xsum
  #undef pTable_ysum
  #undef pTable_dxmin
  #undef pTable_dxmax
  #undef pTable_dymin
  #undef pTable_dymax
  return;
} /* class_Source_gen4_trace */

#pragma acc routine
void class_PSD_monitor_trace(_class_PSD_monitor *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_StartOfGuideMonitor_trace] component StartOfGuideMonitor=PSD_monitor() TRACE [PSD_monitor:0]");

  PROP_Z0;
  if (x > xmin && x < xmax && y > ymin && y < ymax) {
    int i = floor ((x - xmin) * nx / (xmax - xmin));
    int j = floor ((y - ymin) * ny / (ymax - ymin));

    double p2 = p * p;
    #pragma acc atomic
    PSD_N[i][j] = PSD_N[i][j] + 1;

    #pragma acc atomic
    PSD_p[i][j] = PSD_p[i][j] + p;

    #pragma acc atomic
    PSD_p2[i][j] = PSD_p2[i][j] + p2;

    SCATTER;
  }
  if (restore_neutron) {
    RESTORE_NEUTRON (INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef nx
  #undef ny
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef restore_neutron
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return;
} /* class_PSD_monitor_trace */

#pragma acc routine
void class_Arm_trace(_class_Arm *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  SIG_MESSAGE("[_StartOfGuide_trace] component StartOfGuide=Arm() TRACE [Arm:0]");

#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif

  #define ncol_19 (_particle->ncol_19)
  #define nrow_19 (_particle->nrow_19)
  #define res_pi_39 (_particle->res_pi_39)
  #define res_ki_x_39 (_particle->res_ki_x_39)
  #define res_ki_y_39 (_particle->res_ki_y_39)
  #define res_ki_z_39 (_particle->res_ki_z_39)
  #define res_kf_x_39 (_particle->res_kf_x_39)
  #define res_kf_y_39 (_particle->res_kf_y_39)
  #define res_kf_z_39 (_particle->res_kf_z_39)
  #define res_rx_39 (_particle->res_rx_39)
  #define res_ry_39 (_particle->res_ry_39)
  #define res_rz_39 (_particle->res_rz_39)
if (_comp->_index == 35) { // EXTEND 'sample_scatter_state_reset'
  raw_scattered = 0;
}
  #undef ncol_19
  #undef nrow_19
  #undef res_pi_39
  #undef res_ki_x_39
  #undef res_ki_y_39
  #undef res_ki_z_39
  #undef res_kf_x_39
  #undef res_kf_y_39
  #undef res_kf_z_39
  #undef res_rx_39
  #undef res_ry_39
  #undef res_rz_39

  return;
} /* class_Arm_trace */

#pragma acc routine
void class_Elliptic_guide_gravity_trace(_class_Elliptic_guide_gravity *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define l (_comp->_parameters.l)
  #define linxw (_comp->_parameters.linxw)
  #define loutxw (_comp->_parameters.loutxw)
  #define linyh (_comp->_parameters.linyh)
  #define loutyh (_comp->_parameters.loutyh)
  #define majorAxisxw (_comp->_parameters.majorAxisxw)
  #define minorAxisxw (_comp->_parameters.minorAxisxw)
  #define majorAxisyh (_comp->_parameters.majorAxisyh)
  #define minorAxisyh (_comp->_parameters.minorAxisyh)
  #define majorAxisoffsetxw (_comp->_parameters.majorAxisoffsetxw)
  #define majorAxisoffsetyh (_comp->_parameters.majorAxisoffsetyh)
  #define dimensionsAt (_comp->_parameters.dimensionsAt)
  #define option (_comp->_parameters.option)
  #define R0 (_comp->_parameters.R0)
  #define Qc (_comp->_parameters.Qc)
  #define alpha (_comp->_parameters.alpha)
  #define m (_comp->_parameters.m)
  #define W (_comp->_parameters.W)
  #define alpharight (_comp->_parameters.alpharight)
  #define mright (_comp->_parameters.mright)
  #define alphaleft (_comp->_parameters.alphaleft)
  #define mleft (_comp->_parameters.mleft)
  #define alphatop (_comp->_parameters.alphatop)
  #define mtop (_comp->_parameters.mtop)
  #define alphabottom (_comp->_parameters.alphabottom)
  #define mbottom (_comp->_parameters.mbottom)
  #define verbose (_comp->_parameters.verbose)
  #define enableGravity (_comp->_parameters.enableGravity)
  #define curvature (_comp->_parameters.curvature)
  #define nSegments (_comp->_parameters.nSegments)
  #define mvaluesright (_comp->_parameters.mvaluesright)
  #define mvaluesleft (_comp->_parameters.mvaluesleft)
  #define mvaluestop (_comp->_parameters.mvaluestop)
  #define mvaluesbottom (_comp->_parameters.mvaluesbottom)
  #define seglength (_comp->_parameters.seglength)
  #define guideInfo (_comp->_parameters.guideInfo)
  #define Gx0 (_comp->_parameters.Gx0)
  #define Gy0 (_comp->_parameters.Gy0)
  #define Gz0 (_comp->_parameters.Gz0)
  #define Circ (_comp->_parameters.Circ)
  #define dynamicalSegLength (_comp->_parameters.dynamicalSegLength)
  SIG_MESSAGE("[_Insert_trace] component Insert=Elliptic_guide_gravity() TRACE [Elliptic_guide_gravity:0]");

  struct Intersection latestParticleCollision;
  latestParticleCollision.delta_time_to_next_collision = 0;
  latestParticleCollision.side = 0;
  latestParticleCollision.ApproxOn = 0;
  latestParticleCollision.collisionType = 0;

  PROP_Z0;

  double Gloc;
  double Gx, Gy, Gz;
  if (curvature) {
    Gloc = (vx * vx + vy * vy + vz * vz) / curvature;
  } else {
    Gloc = 0;
  }

  if (!guideInfo.EnclosingBoxOn)
    if (fabs (x) > guideInfo.entranceHorizontalWidth / 2.0 || fabs (y) > guideInfo.entranceVerticalWidth / 2.0)
      ABSORB;

  SCATTER;

  int bounces = 0;
  for (bounces = 0; bounces <= 1000; bounces++) {

    Gx = Gx0;
    Gy = Gy0;
    Gz = Gz0;
    if (curvature) {
      // Add velocity-dependent, location-dependent approximation to centripetal force for curvature...
      Gx = Gx0 + Gloc * cos (2 * PI * z / Circ);
      Gz = Gz0 + Gloc * sin (2 * PI * z / Circ);
    }

    // Find the next intersection between the guide and the neutron.
    int boolean = guide_elliptical_handleGuideIntersection (x, y, z, vx, vy, vz, Gx, Gy, Gz, &guideInfo, &latestParticleCollision);

    double timeToCollision = latestParticleCollision.delta_time_to_next_collision;

    // Handle special cases.
    if (boolean == 0)
      ABSORB;
    if (timeToCollision < 1e-15)
      ABSORB;

    // If the neutron reach the end of the guide, when move
    // the neutron to the end of guide and leave this component.
    if (z + vz * timeToCollision + 0.5 * Gz * timeToCollision * timeToCollision >= guideInfo.Length) {
      double timeToExit = 0;
      solve_2nd_order (&timeToExit, NULL, -0.5 * Gz, -vz, guideInfo.Length - z - 1e-9);
      PROP_GRAV_DT (timeToExit, Gx, Gy, Gz);
      SCATTER;
      break;
    }

    // Move the neutron and handle the reflection.
    PROP_GRAV_DT (timeToCollision, Gx, Gy, Gz);
    if (latestParticleCollision.collisionType == Absorb) {
      ABSORB;
    }
    if (latestParticleCollision.collisionType == Reflex) {
      p *= guide_elliptical_handleReflection (x, y, z, &vx, &vy, &vz, &guideInfo, &latestParticleCollision);
      SCATTER;
      if (p == 0)
        ABSORB;
    }
  }

  if (fabs (x) > guideInfo.exitHorizontalWidth / 2 || fabs (y) > guideInfo.exitVerticalWidth / 2)
    ABSORB;
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef xwidth
  #undef yheight
  #undef l
  #undef linxw
  #undef loutxw
  #undef linyh
  #undef loutyh
  #undef majorAxisxw
  #undef minorAxisxw
  #undef majorAxisyh
  #undef minorAxisyh
  #undef majorAxisoffsetxw
  #undef majorAxisoffsetyh
  #undef dimensionsAt
  #undef option
  #undef R0
  #undef Qc
  #undef alpha
  #undef m
  #undef W
  #undef alpharight
  #undef mright
  #undef alphaleft
  #undef mleft
  #undef alphatop
  #undef mtop
  #undef alphabottom
  #undef mbottom
  #undef verbose
  #undef enableGravity
  #undef curvature
  #undef nSegments
  #undef mvaluesright
  #undef mvaluesleft
  #undef mvaluestop
  #undef mvaluesbottom
  #undef seglength
  #undef guideInfo
  #undef Gx0
  #undef Gy0
  #undef Gz0
  #undef Circ
  #undef dynamicalSegLength
  return;
} /* class_Elliptic_guide_gravity_trace */

#pragma acc routine
void class_Bender_trace(_class_Bender *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define w (_comp->_parameters.w)
  #define h (_comp->_parameters.h)
  #define r (_comp->_parameters.r)
  #define Win (_comp->_parameters.Win)
  #define k (_comp->_parameters.k)
  #define d (_comp->_parameters.d)
  #define l (_comp->_parameters.l)
  #define R0a (_comp->_parameters.R0a)
  #define Qca (_comp->_parameters.Qca)
  #define alphaa (_comp->_parameters.alphaa)
  #define ma (_comp->_parameters.ma)
  #define Wa (_comp->_parameters.Wa)
  #define R0i (_comp->_parameters.R0i)
  #define Qci (_comp->_parameters.Qci)
  #define alphai (_comp->_parameters.alphai)
  #define mi (_comp->_parameters.mi)
  #define Wi (_comp->_parameters.Wi)
  #define R0s (_comp->_parameters.R0s)
  #define Qcs (_comp->_parameters.Qcs)
  #define alphas (_comp->_parameters.alphas)
  #define ms (_comp->_parameters.ms)
  #define Ws (_comp->_parameters.Ws)
  #define bk (_comp->_parameters.bk)
  #define mWin (_comp->_parameters.mWin)
  SIG_MESSAGE("[_C1_trace] component C1=Bender() TRACE [Bender:0]");

  int i, num, numa, numi;
  double dru, ab, dab, R, Q, Ta, vpl;
  double einmWin, ausmWin, zykmWin, aeumWin, innmWin, ref, innref, aeuref;
  double einzei, auszei, zykzei;

  /* does the neutron hit the bender at the entrance? */
  PROP_Z0;
  if ((fabs (x) < w / 2) && (fabs (y) < h / 2)) {
    /*** reflections in the XZ-plane ***/

    /* distance between neutron and concave side of the channel at the entrance */
    dru = floor ((w / 2 - x) / bk) * bk;
    ab = w / 2.0 - x - dru;

    /* radius of the channel */
    R = r - dru;

    /* does the neutron hit the partition at the entrance? */
    if (ab < bk - d) {
      double aeu[] = { R0a, Qca, alphaa, ma, Wa };
      /* velocity in the XZ-plane */
      vpl = sqrt (vx * vx + vz * vz);

      /* divergence of the neutron at the entrance */
      einmWin = atan (vx / vz);

      /* maximal distance between neutron and concave side of the channel */
      dab = R - cos (einmWin) * (R - ab);

      /* reflection angle at the concave side */
      aeumWin = acos ((R - dab) / R);

      /* reflection coefficient at the concave side */
      Q = 2.0 * V2K * vpl * sin (aeumWin);
      StdReflecFunc (Q, aeu, &aeuref);

      /* does the neutron hit the convex side of the channel? */
      innmWin = 0.0;
      innref = 1.0;
      if (dab > bk - d) {
        double inn[] = { R0i, Qci, alphai, mi, Wi };
        /* reflection coefficient at the convex side */
        innmWin = acos ((R - dab) / (R - bk + d));
        Q = 2.0 * V2K * vpl * sin (innmWin);
        StdReflecFunc (Q, inn, &innref);
      }

      /* divergence of the neutron at the exit */
      zykmWin = 2.0 * (aeumWin - innmWin);
      ausmWin = fmod (mWin + einmWin + aeumWin - innmWin * (1.0 + SIGN (einmWin)), zykmWin) - zykmWin / 2.0;
      ausmWin += innmWin * SIGN (ausmWin);

      /* number of reflections at the concave side */
      numa = (mWin + einmWin + aeumWin - innmWin * (1.0 + SIGN (einmWin))) / zykmWin;

      /* number of reflections at the convex side */
      numi = numa;
      if (ausmWin * einmWin < 0) {
        if (ausmWin - einmWin > 0)
          numi++;
        else
          numi--;
      }

      /* is the reflection coefficient too small? */
      if (((numa > 0) && (aeuref <= 0)) || ((numi > 0) && (innref <= 0)))
        ABSORB;

      /* calculation of the neutron probability weight p */
      for (i = 1; i <= numa; i++)
        p *= aeuref;
      for (i = 1; i <= numi; i++)
        p *= innref;

      /* time to cross the bender */
      Ta = (2 * numa * (tan (aeumWin) - tan (innmWin)) + tan (ausmWin) - tan (einmWin) - tan (innmWin) * (SIGN (ausmWin) - SIGN (einmWin))) * (R - dab) / vpl;
      t += Ta;

      /* distance between neutron and concave side of channel at the exit */
      ab = R - (R - dab) / cos (ausmWin);

      /* calculation of the exit coordinates in the XZ-plane */
      x = w / 2.0 - ab - dru;
      z = r * mWin;
      vx = sin (ausmWin) * vpl;
      vz = cos (ausmWin) * vpl;

      /*** reflections at top and bottom side (Y axis) ***/

      if (vy != 0.0) {
        double s[] = { R0s, Qcs, alphas, ms, Ws };
        /* reflection coefficent at the top and bottom side */
        Q = 2.0 * V2K * fabs (vy);
        StdReflecFunc (Q, s, &ref);

        /* number of reflections at top and bottom */
        einzei = h / 2.0 / fabs (vy) + y / vy;
        zykzei = h / fabs (vy);
        num = (Ta + einzei) / zykzei;

        /* time between the last reflection and the exit */
        auszei = fmod (Ta + einzei, zykzei);

        /* is the reflection coefficient too small? */
        if ((num > 0) && (ref <= 0))
          ABSORB;

        /* calculation of the probability weight p */
        for (i = 1; i <= num; i++) {
          p *= ref;
          vy *= -1.0;
        }

        /* calculation of the exit coordinate */
        y = auszei * vy - vy * h / fabs (vy) / 2.0;
      } /* if (vy!=0.0) */
      SCATTER;
    } /* if (dab>bk-d)  */
    else
      ABSORB; /* hit separating walls */
  } else      /* if ((fabs(x)<w/2) && (fabs(y)<h/2))   */
    ABSORB;   /* miss entry window */
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef w
  #undef h
  #undef r
  #undef Win
  #undef k
  #undef d
  #undef l
  #undef R0a
  #undef Qca
  #undef alphaa
  #undef ma
  #undef Wa
  #undef R0i
  #undef Qci
  #undef alphai
  #undef mi
  #undef Wi
  #undef R0s
  #undef Qcs
  #undef alphas
  #undef ms
  #undef Ws
  #undef bk
  #undef mWin
  return;
} /* class_Bender_trace */

#pragma acc routine
void class_Slit_trace(_class_Slit *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define radius (_comp->_parameters.radius)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define isradial (_comp->_parameters.isradial)
  SIG_MESSAGE("[_SlitGuideEnd_trace] component SlitGuideEnd=Slit() TRACE [Slit:0]");

  PROP_Z0;
  if (!isradial ? (x < xmin || x > xmax || y < ymin || y > ymax) : (x * x + y * y > radius * radius))
    ABSORB;
  else
    SCATTER;
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef radius
  #undef xwidth
  #undef yheight
  #undef isradial
  return;
} /* class_Slit_trace */

#pragma acc routine
void class_Monochromator_curved_trace(_class_Monochromator_curved *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define reflect (_comp->_parameters.reflect)
  #define transmit (_comp->_parameters.transmit)
  #define zwidth (_comp->_parameters.zwidth)
  #define yheight (_comp->_parameters.yheight)
  #define gap (_comp->_parameters.gap)
  #define NH (_comp->_parameters.NH)
  #define NV (_comp->_parameters.NV)
  #define mosaich (_comp->_parameters.mosaich)
  #define mosaicv (_comp->_parameters.mosaicv)
  #define r0 (_comp->_parameters.r0)
  #define t0 (_comp->_parameters.t0)
  #define Q (_comp->_parameters.Q)
  #define RV (_comp->_parameters.RV)
  #define RH (_comp->_parameters.RH)
  #define DM (_comp->_parameters.DM)
  #define mosaic (_comp->_parameters.mosaic)
  #define width (_comp->_parameters.width)
  #define height (_comp->_parameters.height)
  #define verbose (_comp->_parameters.verbose)
  #define order (_comp->_parameters.order)
  #define mos_rms_y (_comp->_parameters.mos_rms_y)
  #define mos_rms_z (_comp->_parameters.mos_rms_z)
  #define mos_rms_max (_comp->_parameters.mos_rms_max)
  #define mono_Q (_comp->_parameters.mono_Q)
  #define SlabWidth (_comp->_parameters.SlabWidth)
  #define SlabHeight (_comp->_parameters.SlabHeight)
  #define rTable (_comp->_parameters.rTable)
  #define tTable (_comp->_parameters.tTable)
  #define rTableFlag (_comp->_parameters.rTableFlag)
  #define tTableFlag (_comp->_parameters.tTableFlag)
  #define tiltH (_comp->_parameters.tiltH)
  #define tiltV (_comp->_parameters.tiltV)
  #define ncol_var (_comp->_parameters.ncol_var)
  #define nrow_var (_comp->_parameters.nrow_var)
  SIG_MESSAGE("[_Mono_trace] component Mono=Monochromator_curved() TRACE [Monochromator_curved:0]");

  double dt;
  double Gauss_X[]
      = { -0.987992518020485, -0.937273392400706, -0.848206583410427, -0.724417731360170, -0.570972172608539, -0.394151347077563, -0.201194093997435, 0,
          0.201194093997435,  0.394151347077563,  0.570972172608539,  0.724417731360170,  0.848206583410427,  0.937273392400706,  0.987992518020485 };
  double Gauss_W[]
      = { 0.030753241996117, 0.070366047488108, 0.107159220467172, 0.139570677926154, 0.166269205816994, 0.186161000115562, 0.198431485327111, 0.202578241925561,
          0.198431485327111, 0.186161000115562, 0.166269205816994, 0.139570677926154, 0.107159220467172, 0.070366047488108, 0.030753241996117 };

  if (vx != 0.0 && (dt = -x / vx) >= 0.0 && r0) { /* Moving towards crystal? */
    double zmin, zmax, ymin, ymax;
    double yy, zz;

    zmax = ((NH * (SlabWidth + gap)) - gap) / 2;
    zmin = -zmax;
    ymax = ((NV * (SlabHeight + gap)) - gap) / 2;
    ymin = -ymax;

    /* Test-propagate to crystal plane */
    zz = z + vz * dt;
    yy = y + vy * dt;
    if (zz > zmin && zz < zmax && yy > ymin && yy < ymax) { /* Intersect the crystal? */
      double tilth, tiltv;                                  /* used to calculate tilt angle of slab */
      double ratio, Q_order, k, kux, kuy, kuz;
      double kix, kiy, kiz;
      int do_transmit = 0;
      int row, col;

      col = ceil ((zz - zmin) / (SlabWidth + gap)); /* which slab hit ? */
      row = ceil ((yy - ymin) / (SlabHeight + gap));

      particle_setvar_void (_particle, ncol_var, &col);
      particle_setvar_void (_particle, nrow_var, &row);

      if (RH != 0) {
        tilth = tiltH ? tiltH[(int)col] : asin ((col - (NH + 1) / 2.0) * (SlabWidth + gap) / RH);
      } else {
        tilth = 0;
      }
      if (RV != 0) {
        tiltv = tiltV ? tiltV[(int)row] : -asin ((row - (NV + 1) / 2.0) * (SlabHeight + gap) / RV);
      } else {
        tiltv = 0;
      }

      /* rotate with tilth (around Y) and tiltv (around Z), center on plate */
      double center_z = zmin + (col - 0.5) * (SlabWidth + gap) - gap / 2;
      double center_y = ymin + (row - 0.5) * (SlabHeight + gap) - gap / 2;

      Rotation T;
      rot_set_rotation (T, 0, tilth, tiltv);
      /* now make the coordinate system change */
      mccoordschange_polarisation (T, &vx, &vy, &vz);
      y = y - center_y;
      z = z - center_z;
      coords_get (rot_apply (T, coords_set (x, y, z)), &x, &y, &z);

      /* this is where polarisation should be handled, plus further down */
      /* mccoordschange_polarisation(t, &sx, &sy, &sz); */

      /* now propagate to slab plane */
      PROP_X0;

      /* Hit a slab or a gap ?*/
      int inside = inside_rectangle (z, y, SlabWidth, SlabHeight);
      if (inside) {     /* not in gap ? */
        kix = V2K * vx; /* Initial wave vector */
        kiy = V2K * vy;
        kiz = V2K * vz;
        /* Get reflection order and corresponding nominal scattering vector q0
          of correct length and direction. Only the order with the closest
          scattering vector is considered */
        ratio = -2 * kix / mono_Q;
        Q_order = floor (ratio + .5);
        if (Q_order == 0.0)
          Q_order = ratio < 0 ? -1 : 1;
        /* Order will be negative when the neutron enters from the back, in
          which case the direction of Q0 is flipped. */
        if (Q_order < 0)
          Q_order = -Q_order;
        /* Make sure the order is small enough to allow Bragg scattering at the
          given neutron wavelength */
        k = sqrt (kix * kix + kiy * kiy + kiz * kiz);
        kux = kix / k; /* Unit vector along ki */
        kuy = kiy / k;
        kuz = kiz / k;
        if (Q_order > 2 * k / mono_Q)
          Q_order--;
        if ((!order && Q_order > 0) || (Q_order == fabs (order) && order)) { /* Bragg scattering possible? */
          double q0, q0x, theta, delta, p_reflect, my_r0;

          q0 = Q_order * mono_Q;
          q0x = ratio < 0 ? -q0 : q0;
          theta = asin (q0 / (2 * k)); /* Actual bragg angle */
          /* Make MC choice: reflect or transmit? */
          delta = asin (fabs (kux)) - theta;

          if (rTableFlag) {
            my_r0 = r0 * Table_Value (rTable, k, 1); /* 2nd column */
          } else
            my_r0 = r0;
          if (my_r0 > 1) {
            if (my_r0 > 1.01 && verbose)
              fprintf (stdout, "Warning: Monochromator_curved : lowered reflectivity from %f to 1 (k=%f)\n", my_r0, k);
            my_r0 = 0.999;
          }
          if (my_r0 < 0) {
            if (verbose)
              fprintf (stdout, "Warning: Monochromator_curved : raised reflectivity from %f to 0 (k=%f)\n", my_r0, k);
            my_r0 = 0;
          }

          p_reflect = fabs (my_r0) * exp (-kiz * kiz / (kiy * kiy + kiz * kiz) * (delta * delta) / (2 * mos_rms_y * mos_rms_y))
                      * exp (-kiy * kiy / (kiy * kiy + kiz * kiz) * (delta * delta) / (2 * mos_rms_z * mos_rms_z));

          double rr = rand01 ();
          if (rr <= p_reflect) { /* Reflect */
            double bx, by, bz, ax, ay, az, phi;
            double cos_2theta, k_sin_2theta, cos_phi, sin_phi, q_x, q_y, q_z;
            double total, c1x, c1y, c1z, w, mos_sample;
            int i = 0;

            cos_2theta = cos (2 * theta);
            k_sin_2theta = k * sin (2 * theta);
            /* Get unit normal to plane containing ki and most probable kf */
            vec_prod (bx, by, bz, kix, kiy, kiz, q0x, 0, 0);
            NORM (bx, by, bz);
            bx = bx * k_sin_2theta;
            by = by * k_sin_2theta;
            bz = bz * k_sin_2theta;
            /* Get unit vector normal to ki and b */
            vec_prod (ax, ay, az, bx, by, bz, kux, kuy, kuz);
            /* Compute the total scattering probability at this ki */
            total = 0;
            /* Choose width of Gaussian distribution to sample the angle
             * phi on the Debye-Scherrer cone for the scattered neutron.
             * The radius of the Debye-Scherrer cone is smaller by a
             * factor 1/cos(theta) than the radius of the (partial) sphere
             * describing the possible orientations of Q due to mosaicity, so we
             * start with a width 1/cos(theta) greater than the largest of
             * the two mosaics. */
            mos_sample = mos_rms_max / cos (theta);
            c1x = kix * (cos_2theta - 1);
            c1y = kiy * (cos_2theta - 1);
            c1z = kiz * (cos_2theta - 1);
            /* Loop, repeatedly reducing the sample width until it is small
             * enough to avoid sampling scattering directions with
             * ridiculously low scattering probability.
             * Use a cut-off at 5 times the gauss width for considering
             * scattering probability as well as for integration limits
             * when integrating the sampled distribution below. */
            for (i = 0; i < 100; i++) {
              w = 5 * mos_sample;
              cos_phi = cos (w);
              sin_phi = sin (w);
              q_x = c1x + cos_phi * ax + sin_phi * bx;
              q_y = (c1y + cos_phi * ay + sin_phi * by) / mos_rms_z;
              q_z = (c1z + cos_phi * az + sin_phi * bz) / mos_rms_y;
              /* Stop when we get near a factor of 25=5^2. */
              if (q_z * q_z + q_y * q_y < (25 / (2.0 / 3.0)) * (q_x * q_x))
                break;
              mos_sample *= (2.0 / 3.0);
            }
            /* Now integrate the chosen sampling distribution, using a
             * cut-off at five times sigma. */
            for (i = 0; i < (sizeof (Gauss_X) / sizeof (double)); i++) {
              phi = w * Gauss_X[i];
              cos_phi = cos (phi);
              sin_phi = sin (phi);
              q_x = c1x + cos_phi * ax + sin_phi * bx;
              q_y = c1y + cos_phi * ay + sin_phi * by;
              q_z = c1z + cos_phi * az + sin_phi * bz;
              p_reflect = GAUSS_monocurved ((q_z / q_x), 0, mos_rms_y) * GAUSS_monocurved ((q_y / q_x), 0, mos_rms_z);
              total += Gauss_W[i] * p_reflect;
            }
            total *= w;
            /* Choose point on Debye-Scherrer cone. Sample from a Gaussian of
             * width 1/cos(theta) greater than the mosaic and correct for any
             * error by adjusting the neutron weight later. */
            phi = mos_sample * randnorm ();
            /* Compute final wave vector kf and scattering vector q = ki - kf */
            cos_phi = cos (phi);
            sin_phi = sin (phi);
            q_x = c1x + cos_phi * ax + sin_phi * bx;
            q_y = c1y + cos_phi * ay + sin_phi * by;
            q_z = c1z + cos_phi * az + sin_phi * bz;
            p_reflect = GAUSS_monocurved ((q_z / q_x), 0, mos_rms_y) * GAUSS_monocurved ((q_y / q_x), 0, mos_rms_z);

            vx = K2V * (kix + q_x);
            vy = K2V * (kiy + q_y);
            vz = K2V * (kiz + q_z);
            p_reflect /= total * GAUSS_monocurved (phi, 0, mos_sample);
            if (p_reflect <= 0)
              ABSORB;
            if (p_reflect > 1)
              p_reflect = 1;
            p = p * p_reflect;

          } /* End MC choice to reflect or transmit neutron (if tmp<p_reflect) */
          else {
            do_transmit = 1;
          }
          /* else transmit neutron */
        } /* End bragg scattering possible (if order) */
        else {
          do_transmit = 1;
        }
        if (do_transmit) {
          double my_t0;
          if (tTableFlag != 0) {
            my_t0 = t0 * Table_Value (tTable, k, 1); /* 2nd column */
          } else
            my_t0 = t0;
          /* do not SCATTER, else GROUP does not work */
          if (my_t0 > 1) {
            if (my_t0 > 1.01 && verbose)
              fprintf (stdout, "Warning: Monochromator_curved : lowered transmission from %f to 1 (k=%f)\n", my_t0, k);
            my_t0 = 0.999;
          }
          if (my_t0 > 0)
            p = p * my_t0;
          else
            ABSORB;
        }
      } /* end if not in gap */
      /* rotate back in component frame */
      Rotation TT;
      rot_transpose (T, TT);
      /* now make the coordinate system change */
      mccoordschange_polarisation (TT, &vx, &vy, &vz);
      coords_get (rot_apply (TT, coords_set (x, y, z)), &x, &y, &z);
      y = y + center_y;
      z = z + center_z;
      /* Visualise scattering point in proper, component frame
         - but only if the neutron is reflected, that is none of:
         * transmitted
         * falling outside the slab material */
      if (!do_transmit)
        SCATTER;

      /* mccoordschange_polarisation(tt, &sx, &sy, &sz); */
    } /* End intersect the crystal (if z) */
    else {
      /* restore neutron state when no interaction */
      RESTORE_NEUTRON (INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
    }
  } /* End neutron moving towards crystal (if vx)*/
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef reflect
  #undef transmit
  #undef zwidth
  #undef yheight
  #undef gap
  #undef NH
  #undef NV
  #undef mosaich
  #undef mosaicv
  #undef r0
  #undef t0
  #undef Q
  #undef RV
  #undef RH
  #undef DM
  #undef mosaic
  #undef width
  #undef height
  #undef verbose
  #undef order
  #undef mos_rms_y
  #undef mos_rms_z
  #undef mos_rms_max
  #undef mono_Q
  #undef SlabWidth
  #undef SlabHeight
  #undef rTable
  #undef tTable
  #undef rTableFlag
  #undef tTableFlag
  #undef tiltH
  #undef tiltV
  #undef ncol_var
  #undef nrow_var
  return;
} /* class_Monochromator_curved_trace */

#pragma acc routine
void class_Incoherent_trace(_class_Incoherent *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define geometry (_comp->_parameters.geometry)
  #define radius (_comp->_parameters.radius)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define thickness (_comp->_parameters.thickness)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define focus_r (_comp->_parameters.focus_r)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define target_index (_comp->_parameters.target_index)
  #define pack (_comp->_parameters.pack)
  #define p_interact (_comp->_parameters.p_interact)
  #define f_QE (_comp->_parameters.f_QE)
  #define gamma (_comp->_parameters.gamma)
  #define Etrans (_comp->_parameters.Etrans)
  #define deltaE (_comp->_parameters.deltaE)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define Vc (_comp->_parameters.Vc)
  #define concentric (_comp->_parameters.concentric)
  #define order (_comp->_parameters.order)
  #define VarsInc (_comp->_parameters.VarsInc)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_VanSample_trace] component VanSample=Incoherent() TRACE [Incoherent:0]");

  double t0, t3;                          /* Entry/exit time for outer surface */
  double t1, t2;                          /* Entry/exit time for inner surface */
  double dt0, dt1, dt2, dt;               /* Flight times through sample */
  double v = 0;                           /* Neutron velocity */
  double d_path;                          /* Flight path length for non-scattered neutron */
  double l_i, l_o = 0;                    /* Flight path lenght in/out for scattered neutron */
  double my_a = 0, my_t = 0;              /* Velocity-dependent attenuation factor and total Xsec */
  double solid_angle = 0;                 /* Solid angle of target as seen from scattering point */
  double aim_x = 0, aim_y = 0, aim_z = 1; /* Position of target relative to scattering point */
  double v_i, v_f, E_i, E_f;              /* initial and final energies and velocities */
  double dE;                              /* Energy transfer */
  int intersect = 0;
  int flag_concentric = 0;
  int flag = 0;
  double mc_trans, p_trans, mc_scatt, p_scatt, ws;
  double p_mult = 1;

  #ifdef OPENACC
  #ifdef USE_OFF
  off_struct thread_offdata = offdata;
  #endif
  #else
  #define thread_offdata offdata
  #endif

  do { /* Main interaction loop. Ends with intersect=0 */

    /* Intersection neutron trajectory / sample (sample surface) */
    if (VarsInc.shape == 0)
      intersect = cylinder_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius, yheight);
    else if (VarsInc.shape == 1)
      intersect = box_intersect (&t0, &t3, x, y, z, vx, vy, vz, xwidth, yheight, zdepth);
    else if (VarsInc.shape == 2)
      intersect = sphere_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius);
    #ifdef USE_OFF
    else if (VarsInc.shape == 3)
      intersect = off_intersect (&t0, &t3, NULL, NULL, x, y, z, vx, vy, vz, 0, 0, 0, thread_offdata);
    #endif

    if (intersect) {
      int flag_ishollow = 0;
      if (thickness > 0) {
        if (VarsInc.shape == 0 && cylinder_intersect (&t1, &t2, x, y, z, vx, vy, vz, radius - thickness, yheight - 2 * thickness))
          flag_ishollow = 1;
        else if (VarsInc.shape == 2 && sphere_intersect (&t1, &t2, x, y, z, vx, vy, vz, radius - thickness))
          flag_ishollow = 1;
        else if (VarsInc.shape == 1 && box_intersect (&t1, &t2, x, y, z, vx, vy, vz, xwidth - 2 * thickness, yheight - 2 * thickness, zdepth - 2 * thickness))
          flag_ishollow = 1;
      }
      if (!flag_ishollow)
        t1 = t2 = t3; /* no empty space inside */

      dt0 = t1 - t0; /* Time in sample, ingoing */
      dt1 = t2 - t1; /* Time in hole */
      dt2 = t3 - t2; /* Time in sample, outgoing */

      if (t0 > 0) {                   /* we are before the sample */
        PROP_DT (t0);                 /* propagates neutron to the entry of the sample */
      } else if (t1 > 0 && t1 > t0) { /* we are inside first part of the sample */
        /* no propagation, stay inside */
      } else if (t2 > 0 && t2 > t1) { /* we are in the hole */
        PROP_DT (t2);                 /* propagate to inner surface of 2nd part of sample */
      } else if (t3 > 0 && t3 > t2) { /* we are in the 2nd part of sample */
        /* no propagation, stay inside */
      }

      dt0 = t1 - (t0 > 0 ? t0 : 0); /* Time in first part of hollow/cylinder/box */
      dt1 = t2 - (t1 > 0 ? t1 : 0); /* Time in hole */
      dt2 = t3 - (t2 > 0 ? t2 : 0); /* Time in 2nd part of hollow cylinder */

      if (dt0 < 0)
        dt0 = 0;
      if (dt1 < 0)
        dt1 = 0;
      if (dt2 < 0)
        dt2 = 0;

      /* initialize concentric mode */
      if (concentric && !flag_concentric && t0 >= 0 && VarsInc.shape == 0 && thickness > 0) {
        flag_concentric = 1;
      }

      if (flag_concentric == 1) {
        dt1 = dt2 = 0; /* force exit when reaching hole/2nd part */
      }

      if (!dt0 && !dt2) {
        intersect = 0; /* the sample was passed entirely */
        break;
      }

      p_mult = 1;
      if (!v)
        v = sqrt (vx * vx + vy * vy + vz * vz);
      if (v)
        my_a = VarsInc.my_a_v * (2200 / v);
      else {
        printf ("Incoherent: %s: ERROR: Null velocity\n", NAME_CURRENT_COMP);
        ABSORB; /* should never occur */
      }

      my_t = my_a + VarsInc.my_s; /* total scattering Xsect (tmp var) */
      if (my_t <= 0) {
        printf ("Incoherent: %s: ERROR: Null total cross section %g. Removing event.\n", NAME_CURRENT_COMP, my_t);
        ABSORB; /* should never occur */
      }
      d_path = v * (dt0 + dt2); /* Length of full path through sample */

      /* Proba of scattering vs absorption (integrating along the whole trajectory) */
      ws = VarsInc.my_s / my_t; /* (inc+coh)/(inc+coh+abs) */
      /* Proba of transmission along length d_path */
      p_trans = exp (-my_t * d_path);
      p_scatt = 1 - p_trans; /* portion of beam which scatters */
      flag = 0;              /* flag used for propagation to exit point before ending */
      /* are we next to the exit ? probably no scattering (avoid rounding errors) */
      if (VarsInc.my_s * d_path <= 4e-7) {
        flag = 1; /* No interaction before the exit */
      }
      /* force a given fraction of the beam to scatter */
      if (p_interact > 0 && p_interact <= 1) {
        /* we force a portion of the beam to interact */
        /* This is used to improve statistics on single scattering (and multiple) */
        if (!SCATTERED)
          mc_trans = 1 - p_interact;
        else
          mc_trans = 1 - p_interact / (4 * SCATTERED + 1); /* reduce effect on multi scatt */
      } else {
        mc_trans = p_trans; /* 1 - p_scatt */
      }
      mc_scatt = 1 - mc_trans; /* portion of beam to scatter (or force to) */
      if (mc_scatt <= 0 || mc_scatt > 1)
        flag = 1;
      /* MC choice: Interaction or transmission ? */
      if (!flag && mc_scatt > 0 && (mc_scatt >= 1 || (rand01 ()) < mc_scatt)) { /* Interaction neutron/sample */
        p_mult *= ws;                                                           /* Update weight ; account for absorption and retain scattered fraction */
        if (!mc_scatt)
          ABSORB;
        /* we have chosen portion mc_scatt of beam instead of p_scatt, so we compensate */
        p_mult *= fabs (p_scatt / mc_scatt); /* lower than 1 */
      } else {
        flag = 1; /* Transmission : no interaction neutron/sample */
        if (!mc_trans)
          ABSORB;
        p_mult *= fabs (p_trans / mc_trans); /* attenuate beam by portion which is scattered (and left along) */
      }

      if (flag) { /* propagate to exit of sample and finish */
        intersect = 0;
        p *= p_mult; /* apply absorption correction */
        PROP_DT (dt0 + dt2);
        break; /* exit main multi scatt while loop */
      }
      if (my_t * d_path < 1e-6)
        /* For very weak scattering, use simple uniform sampling of scattering
           point to avoid rounding errors. */
        dt = rand0max (d_path); /* length */
      else
        dt = -log (1 - rand0max ((1 - exp (-my_t * d_path)))) / my_t; /* length */
      l_i = dt;                                                       /* Penetration in sample: scattering+abs */
      dt /= v;                                                        /* Time from present position to scattering point */

      /* If t0 is in hole, propagate to next part of the hollow cylinder */
      if (dt1 > 0 && dt0 > 0 && dt > dt0)
        dt += dt1;
      PROP_DT (dt); /* Point of scattering */

      if ((VarsInc.tx || VarsInc.ty || VarsInc.tz)) {
        aim_x = VarsInc.tx - x; /* Vector pointing at target (anal./det.) */
        aim_y = VarsInc.ty - y;
        aim_z = VarsInc.tz - z;
      }
      if (VarsInc.aw && VarsInc.ah) {
        randvec_target_rect_angular (&vx, &vy, &vz, &solid_angle, aim_x, aim_y, aim_z, VarsInc.aw, VarsInc.ah, ROT_A_CURRENT_COMP);
      } else if (VarsInc.xw && VarsInc.yh) {
        randvec_target_rect (&vx, &vy, &vz, &solid_angle, aim_x, aim_y, aim_z, VarsInc.xw, VarsInc.yh, ROT_A_CURRENT_COMP);
      } else {
        randvec_target_circle (&vx, &vy, &vz, &solid_angle, aim_x, aim_y, aim_z, focus_r);
      }
      NORM (vx, vy, vz);

      v_i = v; /* Store initial velocity in case of quasielastic */
      E_i = VS2E * v_i * v_i;
      if (deltaE == 0) {
        if (rand01 () < f_QE) /* Quasielastic contribution */
        {
          dE = gamma * tan (PI / 2 * randpm1 ());
          E_f = E_i + dE;
          if (E_f <= 0)
            ABSORB;
          v_f = SE2V * sqrt (E_f);
          v = v_f;
          /*          printf("vi: %g Ei: %g dE: %g Ef %g vf: %g v: %g \n",
                      v_i,E_i,dE,E_f,v_f,v); */
        }
      } else {
        E_f = E_i - Etrans + deltaE * randpm1 (); // E_f=E0;
        v_f = SE2V * sqrt (E_f);
        v = v_f;
      }

      vx *= v;
      vy *= v;
      vz *= v;

      /* We do not consider scattering from 2nd part (outgoing) */
      p_mult *= solid_angle / 4 / PI;
      p *= p_mult;

      /* Polarisation part (1/3 NSF, 2/3 SF) */
      sx *= -1.0 / 3.0;
      sy *= -1.0 / 3.0;
      sz *= -1.0 / 3.0;

      SCATTER;

      /* test for a given multiple order */
      if (order && SCATTERED >= order) {
        intersect = 0; /* reached required number of SCATTERing */
        break;         /* finish multiple scattering loop */
      }
    } /* end if intersect */
  } while (intersect); /* end do (intersect) (multiple scattering loop) */

  // Add attenuation of exit flight path for non-multiple scattering
  if (order && SCATTERED) {
    if (VarsInc.shape == 0)
      intersect = cylinder_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius, yheight);
    else if (VarsInc.shape == 1)
      intersect = box_intersect (&t0, &t3, x, y, z, vx, vy, vz, xwidth, yheight, zdepth);
    else if (VarsInc.shape == 2)
      intersect = sphere_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius);
    #ifdef USE_OFF
    else if (VarsInc.shape == 3)
      intersect = off_intersect (&t0, &t3, NULL, NULL, x, y, z, vx, vy, vz, 0, 0, 0, thread_offdata);
    #endif

    d_path = v * t3; /* Length of full path through sample */

    p_trans = exp (-my_t * d_path);
    p *= p_trans;
    PROP_DT (t3);
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif

  #define ncol_19 (_particle->ncol_19)
  #define nrow_19 (_particle->nrow_19)
  #define res_pi_39 (_particle->res_pi_39)
  #define res_ki_x_39 (_particle->res_ki_x_39)
  #define res_ki_y_39 (_particle->res_ki_y_39)
  #define res_ki_z_39 (_particle->res_ki_z_39)
  #define res_kf_x_39 (_particle->res_kf_x_39)
  #define res_kf_y_39 (_particle->res_kf_y_39)
  #define res_kf_z_39 (_particle->res_kf_z_39)
  #define res_rx_39 (_particle->res_rx_39)
  #define res_ry_39 (_particle->res_ry_39)
  #define res_rz_39 (_particle->res_rz_39)
if (_comp->_index == 36) { // EXTEND 'VanSample'
  raw_scattered = SCATTERED;
}
  #undef ncol_19
  #undef nrow_19
  #undef res_pi_39
  #undef res_ki_x_39
  #undef res_ki_y_39
  #undef res_ki_z_39
  #undef res_kf_x_39
  #undef res_kf_y_39
  #undef res_kf_z_39
  #undef res_rx_39
  #undef res_ry_39
  #undef res_rz_39

  #undef geometry
  #undef radius
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef thickness
  #undef target_x
  #undef target_y
  #undef target_z
  #undef focus_r
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef target_index
  #undef pack
  #undef p_interact
  #undef f_QE
  #undef gamma
  #undef Etrans
  #undef deltaE
  #undef sigma_abs
  #undef sigma_inc
  #undef Vc
  #undef concentric
  #undef order
  #undef VarsInc
  #undef offdata
  return;
} /* class_Incoherent_trace */

#pragma acc routine
void class_Phonon_simple_trace(_class_Phonon_simple *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define a (_comp->_parameters.a)
  #define b (_comp->_parameters.b)
  #define M (_comp->_parameters.M)
  #define c (_comp->_parameters.c)
  #define DW (_comp->_parameters.DW)
  #define T (_comp->_parameters.T)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define target_index (_comp->_parameters.target_index)
  #define focus_r (_comp->_parameters.focus_r)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define gap (_comp->_parameters.gap)
  #define e_steps_low (_comp->_parameters.e_steps_low)
  #define e_steps_high (_comp->_parameters.e_steps_high)
  #define V_rho (_comp->_parameters.V_rho)
  #define V_my_s (_comp->_parameters.V_my_s)
  #define V_my_a_v (_comp->_parameters.V_my_a_v)
  #define DV (_comp->_parameters.DV)
  #define phonon (_comp->_parameters.phonon)
  SIG_MESSAGE("[_sample_trace] component sample=Phonon_simple() TRACE [Phonon_simple:0]");

  double* vf_list;
  #ifdef OPENACC
  vf_list = (double*)malloc ((e_steps_low + e_steps_high) * sizeof (double)); // List of allowed final velocities. Has length of scan_steps
  #else
  vf_list = (double*)calloc (e_steps_low + e_steps_high, sizeof (double)); // List of allowed final velocities. Has length of scan_steps
  #endif
  if (!vf_list) {
    printf ("Memory allocation failed, fatal error!\n");
    exit (-1);
  }
  #ifdef OPENACC
  for (int ii = 0; ii < e_steps_low + e_steps_high; ii++) {
    vf_list[ii] = 0;
  }
  #endif

  struct neutron_params neutron;
  double t0, t1;                          /* Entry/exit time for cylinder */
  double v_i, v_f;                        /* Neutron velocities: initial, final */
  double vx_i, vy_i, vz_i;                /* Neutron initial velocity vector */
  double dt0, dt;                         /* Flight times through sample */
  double l_full;                          /* Flight path length for non-scattered neutron */
  double l_i, l_o;                        /* Flight path lenght in/out for scattered neutron */
  double my_a_i;                          /* Initial attenuation factor */
  double my_a_f;                          /* Final attenuation factor */
  double solid_angle;                     /* Solid angle of target as seen from scattering point */
  double aim_x = 0, aim_y = 0, aim_z = 1; /* Position of target relative to scattering point */
  double kappa_x, kappa_y, kappa_z;       /* Scattering vector */
  double kappa2;                          /* Square of the scattering vector */
  double bose_factor;                     /* Calculated value of the Bose factor */
  double omega;                           /* energy transfer */
  int nf, index;                          /* Number of allowed final velocities */
  double J_factor;                        /* Jacobian from delta fnc.s in cross section */
  double f1, f2;                          /* probed values of omega_q minus omega */
  double p1, p2, p3, p4, p5;              /* temporary multipliers */

  if (cylinder_intersect (&t0, &t1, x, y, z, vx, vy, vz, radius, yheight)) {
    if (t0 < 0)
      ABSORB; /* Neutron came from the sample or begins inside */

    /* Neutron enters at t=t0. */
    dt0 = t1 - t0; /* Time in sample */
    v_i = sqrt (vx * vx + vy * vy + vz * vz);
    l_full = v_i * dt0;   /* Length of path through sample if not scattered */
    dt = rand01 () * dt0; /* Time of scattering (relative to t0) */
    l_i = v_i * dt;       /* Penetration in sample at scattering */
    vx_i = vx;
    vy_i = vy;
    vz_i = vz;
    PROP_DT (dt + t0); /* Point of scattering */

    aim_x = target_x - x; /* Vector pointing at target (e.g. analyzer) */
    aim_y = target_y - y;
    aim_z = target_z - z;

    if (focus_aw && focus_ah) {
      randvec_target_rect_angular (&vx, &vy, &vz, &solid_angle, aim_x, aim_y, aim_z, focus_aw, focus_ah, ROT_A_CURRENT_COMP);
    } else if (focus_xw && focus_yh) {
      randvec_target_rect (&vx, &vy, &vz, &solid_angle, aim_x, aim_y, aim_z, focus_xw, focus_yh, ROT_A_CURRENT_COMP);
    } else {
      randvec_target_sphere (&vx, &vy, &vz, &solid_angle, aim_x, aim_y, aim_z, focus_r);
    }
    NORM (vx, vy, vz);
    nf = 0;
    neutron.vf = -1;
    neutron.vi = v_i;
    neutron.vv_x = vx;
    neutron.vv_y = vy;
    neutron.vv_z = vz;
    neutron.vi_x = vx_i;
    neutron.vi_y = vy_i;
    neutron.vi_z = vz_i;

    #ifndef OPENACC
    findroots (0, v_i, v_i + 2 * c * V2K / VS2E, vf_list, &nf, omega_q, &neutron, &phonon);
    #else
    findroots_gpu (0, v_i, v_i + 2 * c * V2K / VS2E, vf_list, &nf, &neutron, &phonon);
    #endif
    index = (int)floor (rand01 () * nf);

    v_f = vf_list[index];
    neutron.vf = v_f - DV;
    f1 = omega_q (&neutron, &phonon);
    neutron.vf = v_f + DV;
    f2 = omega_q (&neutron, &phonon);
    J_factor = fabs (f2 - f1) / (2 * DV);
    omega = VS2E * (v_i * v_i - v_f * v_f);
    vx *= v_f;
    vy *= v_f;
    vz *= v_f;
    kappa_x = V2K * (vx_i - vx);
    kappa_y = V2K * (vy_i - vy);
    kappa_z = V2K * (vz_i - vz);
    kappa2 = kappa_z * kappa_z + kappa_y * kappa_y + kappa_x * kappa_x;

    if (!cylinder_intersect (&t0, &t1, x, y, z, vx, vy, vz, radius, yheight)) {
      /* ??? did not hit cylinder */
      printf ("FATAL ERROR: Did not hit cylinder from inside.\n");
      exit (1);
    }
    dt = t1;
    l_o = v_f * dt;

    my_a_i = V_my_a_v / v_i;
    my_a_f = V_my_a_v / v_f;
    bose_factor = nbose (omega, T);
    p1 = exp (-(V_my_s * (l_i + l_o) + my_a_i * l_i + my_a_f * l_o));                 /* Absorption factor */
    p2 = nf * solid_angle * l_full * V_rho / (4 * PI);                                /* Focusing factors; assume random choice of n_f possibilities */
    p3 = (v_f / v_i) * DW * (kappa2 * K2V * K2V * VS2E) / fabs (omega) * bose_factor; /* Cross section factor 1 */
    p4 = 2 * VS2E * v_f / J_factor;                                                   /* Jacobian of delta functions in cross section */
    p5 = b * b / M;                                                                   /* Cross section factor 2 */
    p *= p1 * p2 * p3 * p4 * p5;
  } /* else transmit: Neutron did not hit the sample */
  free (vf_list);
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif

  #define ncol_19 (_particle->ncol_19)
  #define nrow_19 (_particle->nrow_19)
  #define res_pi_39 (_particle->res_pi_39)
  #define res_ki_x_39 (_particle->res_ki_x_39)
  #define res_ki_y_39 (_particle->res_ki_y_39)
  #define res_ki_z_39 (_particle->res_ki_z_39)
  #define res_kf_x_39 (_particle->res_kf_x_39)
  #define res_kf_y_39 (_particle->res_kf_y_39)
  #define res_kf_z_39 (_particle->res_kf_z_39)
  #define res_rx_39 (_particle->res_rx_39)
  #define res_ry_39 (_particle->res_ry_39)
  #define res_rz_39 (_particle->res_rz_39)
if (_comp->_index == 37) { // EXTEND 'sample'
  raw_scattered = SCATTERED;
}
  #undef ncol_19
  #undef nrow_19
  #undef res_pi_39
  #undef res_ki_x_39
  #undef res_ki_y_39
  #undef res_ki_z_39
  #undef res_kf_x_39
  #undef res_kf_y_39
  #undef res_kf_z_39
  #undef res_rx_39
  #undef res_ry_39
  #undef res_rz_39

  #undef radius
  #undef yheight
  #undef sigma_abs
  #undef sigma_inc
  #undef a
  #undef b
  #undef M
  #undef c
  #undef DW
  #undef T
  #undef target_x
  #undef target_y
  #undef target_z
  #undef target_index
  #undef focus_r
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef gap
  #undef e_steps_low
  #undef e_steps_high
  #undef V_rho
  #undef V_my_s
  #undef V_my_a_v
  #undef DV
  #undef phonon
  return;
} /* class_Phonon_simple_trace */

#pragma acc routine
void class_Powder1_trace(_class_Powder1 *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define xwidth (_comp->_parameters.xwidth)
  #define zdepth (_comp->_parameters.zdepth)
  #define q (_comp->_parameters.q)
  #define d (_comp->_parameters.d)
  #define d_phi (_comp->_parameters.d_phi)
  #define pack (_comp->_parameters.pack)
  #define j (_comp->_parameters.j)
  #define DW (_comp->_parameters.DW)
  #define F2 (_comp->_parameters.F2)
  #define Vc (_comp->_parameters.Vc)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define my_s_v2 (_comp->_parameters.my_s_v2)
  #define my_a_v (_comp->_parameters.my_a_v)
  #define q_v (_comp->_parameters.q_v)
  #define isrect (_comp->_parameters.isrect)
  SIG_MESSAGE("[_powder1_trace] component powder1=Powder1() TRACE [Powder1:0]");

  double t0, t1, v, l_full, l, l_1, dt, dphi_in, d_phi0, theta, my_s;
  double arg, tmp_vx, tmp_vy, tmp_vz, vout_x, vout_y, vout_z;
  char intersect = 0;

  dphi_in = d_phi;
  if (isrect)
    intersect = box_intersect (&t0, &t1, x, y, z, vx, vy, vz, xwidth, yheight, zdepth);
  else
    intersect = cylinder_intersect (&t0, &t1, x, y, z, vx, vy, vz, radius, yheight);
  if (intersect) {
    if (t0 < 0)
      ABSORB;
    /* Neutron enters at t=t0. */
    v = sqrt (vx * vx + vy * vy + vz * vz);
    l_full = v * (t1 - t0);     /* Length of full path through sample */
    dt = rand01 () * (t1 - t0); /* Time of scattering */
    PROP_DT (dt + t0);          /* Point of scattering */
    l = v * dt;                 /* Penetration in sample */

    /* choose line theta */
    arg = q_v / (2.0 * v);
    if (arg > 1)
      ABSORB;           /* No bragg scattering possible*/
    theta = asin (arg); /* Bragg scattering law */

    /* Choose point on Debye-Scherrer cone */
    if (dphi_in) { /* relate height of detector to the height on DS cone */
      arg = sin (dphi_in * DEG2RAD / 2) / sin (2 * theta);
      if (arg < -1 || arg > 1)
        dphi_in = 0;
      else
        dphi_in = 2 * asin (arg);
    }
    if (dphi_in) {
      dphi_in = fabs (dphi_in);
      d_phi0 = 2 * rand01 () * dphi_in;
      if (d_phi0 > dphi_in)
        arg = 1;
      else
        arg = 0;
      if (arg) {
        d_phi0 = PI + (d_phi0 - 1.5 * dphi_in);
      } else {
        d_phi0 = d_phi0 - 0.5 * dphi_in;
      }
      p *= dphi_in / PI;
    } else
      d_phi0 = PI * randpm1 ();

    /* now find a nearly vertical rotation axis:
     *  (v along Z) x (X axis) -> nearly Y axis
     */
    vec_prod (tmp_vx, tmp_vy, tmp_vz, vx, vy, vz, 1, 0, 0);

    /* handle case where v and aim are parallel */
    if (!tmp_vx && !tmp_vy && !tmp_vz) {
      tmp_vx = tmp_vz = 0;
      tmp_vy = 1;
    }

    /* v_out = rotate 'v' by 2*theta around tmp_v: Bragg angle */
    rotate (vout_x, vout_y, vout_z, vx, vy, vz, 2 * theta, tmp_vx, tmp_vy, tmp_vz);

    /* tmp_v = rotate v_out by d_phi0 around 'v' (Debye-Scherrer cone) */
    rotate (tmp_vx, tmp_vy, tmp_vz, vout_x, vout_y, vout_z, d_phi0, vx, vy, vz);
    vx = tmp_vx;
    vy = tmp_vy;
    vz = tmp_vz;

    arg = 0;
    if (isrect && !box_intersect (&t0, &t1, x, y, z, vx, vy, vz, xwidth, yheight, zdepth))
      arg = 1;
    else if (!isrect && !cylinder_intersect (&t0, &t1, x, y, z, vx, vy, vz, radius, yheight))
      arg = 1;

    if (arg) {
      /* Strange error: did not hit cylinder */
      fprintf (stderr, "PowderN: FATAL ERROR: Did not hit sample from inside.\n");
      ABSORB;
    }
    l_1 = v * t1; /* go to exit */

    my_s = my_s_v2 / (v * v);
    p *= l_full * my_s * exp (-(my_a_v / v + my_s) * (l + l_1));
    SCATTER;
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif

  #define ncol_19 (_particle->ncol_19)
  #define nrow_19 (_particle->nrow_19)
  #define res_pi_39 (_particle->res_pi_39)
  #define res_ki_x_39 (_particle->res_ki_x_39)
  #define res_ki_y_39 (_particle->res_ki_y_39)
  #define res_ki_z_39 (_particle->res_ki_z_39)
  #define res_kf_x_39 (_particle->res_kf_x_39)
  #define res_kf_y_39 (_particle->res_kf_y_39)
  #define res_kf_z_39 (_particle->res_kf_z_39)
  #define res_rx_39 (_particle->res_rx_39)
  #define res_ry_39 (_particle->res_ry_39)
  #define res_rz_39 (_particle->res_rz_39)
if (_comp->_index == 38) { // EXTEND 'powder1'
  raw_scattered = SCATTERED;
}
  #undef ncol_19
  #undef nrow_19
  #undef res_pi_39
  #undef res_ki_x_39
  #undef res_ki_y_39
  #undef res_ki_z_39
  #undef res_kf_x_39
  #undef res_kf_y_39
  #undef res_kf_z_39
  #undef res_rx_39
  #undef res_ry_39
  #undef res_rz_39

  #undef radius
  #undef yheight
  #undef xwidth
  #undef zdepth
  #undef q
  #undef d
  #undef d_phi
  #undef pack
  #undef j
  #undef DW
  #undef F2
  #undef Vc
  #undef sigma_abs
  #undef my_s_v2
  #undef my_a_v
  #undef q_v
  #undef isrect
  return;
} /* class_Powder1_trace */

#pragma acc routine
void class_Res_sample_trace(_class_Res_sample *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define thickness (_comp->_parameters.thickness)
  #define radius (_comp->_parameters.radius)
  #define focus_r (_comp->_parameters.focus_r)
  #define E0 (_comp->_parameters.E0)
  #define dE (_comp->_parameters.dE)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define target_index (_comp->_parameters.target_index)
  #define vars (_comp->_parameters.vars)
  #define res_pi_var (_comp->_parameters.res_pi_var)
  #define res_ki_x_var (_comp->_parameters.res_ki_x_var)
  #define res_ki_y_var (_comp->_parameters.res_ki_y_var)
  #define res_ki_z_var (_comp->_parameters.res_ki_z_var)
  #define res_kf_x_var (_comp->_parameters.res_kf_x_var)
  #define res_kf_y_var (_comp->_parameters.res_kf_y_var)
  #define res_kf_z_var (_comp->_parameters.res_kf_z_var)
  #define res_rx_var (_comp->_parameters.res_rx_var)
  #define res_ry_var (_comp->_parameters.res_ry_var)
  #define res_rz_var (_comp->_parameters.res_rz_var)
  #define compindex (_comp->_parameters.compindex)
  SIG_MESSAGE("[_res_sample_trace] component res_sample=Res_sample() TRACE [Res_sample:0]");

  double t0, t3;                /* Entry/exit time for outer cylinder */
  double t1, t2;                /* Entry/exit time for inner cylinder */
  double v;                     /* Neutron velocity */
  double E;
  double l_full;                /* Flight path length for non-scattered neutron */
  double dt0, dt1, dt2, dt;     /* Flight times through sample */
  double solid_angle=0;         /* Solid angle of target as seen from scattering point */
  double aim_x, aim_y, aim_z;   /* Position of target relative to scattering point */
  double scat_factor;           /* Simple cross-section model */
  int intersect = 0;
  double kix,kiy,kiz;
  double kfx,kfy,kfz;

  if(vars.isrect)
    intersect = box_intersect(&t0, &t3, x, y, z, vx, vy, vz, xwidth, yheight, zdepth);
  else
    intersect = cylinder_intersect(&t0, &t3, x, y, z, vx, vy, vz, radius, yheight);

  if(intersect) {
    if(t0 < 0) ABSORB;
    if(vars.isrect) {
      t1 = t2 = t3;
      scat_factor = 2*zdepth;
    } /* box sample */
    else {  /* Hollow cylinder sample */
      /* Neutron enters at t=t0. */
      if(!thickness || !cylinder_intersect(&t1, &t2, x, y, z, vx, vy, vz, radius-thickness, yheight))
        t1 = t2 = t3;
      scat_factor = 2*radius;
    }

    dt0 = t1-t0;                  /* Time in sample, ingoing */
    dt1 = t2-t1;                  /* Time in hole */
    dt2 = t3-t2;                  /* Time in sample, outgoing */

    v = sqrt(vx*vx + vy*vy + vz*vz);
    l_full = v * (dt0 + dt2);     /* Length of full path through sample */
    p *= l_full/scat_factor;      /* Scattering probability */
    dt = rand01()*(dt0+dt2);      /* Time of scattering (relative to t0) */
    if (dt > dt0)
      dt += dt1;

    PROP_DT(dt+t0);             /* Point of scattering */

    /* Store initial neutron state. */
    if(p == 0) ABSORB;
    kix=V2K*vx; kiy=V2K*vy; kiz=V2K*vz;
    particle_setvar_void(_particle, res_pi_var, &p);
    particle_setvar_void(_particle, res_ki_x_var, &(kix));
    particle_setvar_void(_particle, res_ki_y_var, &(kiy));
    particle_setvar_void(_particle, res_ki_z_var, &(kiz));
    particle_setvar_void(_particle, res_rx_var, &x);
    particle_setvar_void(_particle, res_ry_var, &y);
    particle_setvar_void(_particle, res_rz_var, &z);

    aim_x = vars.targetx - x;         /* Vector pointing at target (anal./det.) */
    aim_y = vars.targety - y;
    aim_z = vars.targetz - z;
 
   if(vars.awdim && vars.ahdim) {
      randvec_target_rect_angular(&vx, &vy, &vz, &solid_angle,
        aim_x, aim_y, aim_z, vars.awdim, vars.ahdim, ROT_A_CURRENT_COMP);
    } else if(vars.xwdim && vars.yhdim) {
      randvec_target_rect(&vx, &vy, &vz, &solid_angle,
        aim_x, aim_y, aim_z, vars.xwdim, vars.yhdim, ROT_A_CURRENT_COMP);
    } else {
      randvec_target_circle(&vx, &vy, &vz, &solid_angle,
        aim_x, aim_y, aim_z, focus_r);
    }

    NORM(vx, vy, vz);
    E = E0 + dE*randpm1();
    v = sqrt(E)*SE2V;
    vx *= v;
    vy *= v;
    vz *= v;
    SCATTER;

     /* Store final neutron state. */
    kfx=V2K*vx; kfy=V2K*vy; kfz=V2K*vz;
    particle_setvar_void(_particle, res_kf_x_var, &(kfx));
    particle_setvar_void(_particle, res_kf_y_var, &(kfy));
    particle_setvar_void(_particle, res_kf_z_var, &(kfz));
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif

  #define ncol_19 (_particle->ncol_19)
  #define nrow_19 (_particle->nrow_19)
  #define res_pi_39 (_particle->res_pi_39)
  #define res_ki_x_39 (_particle->res_ki_x_39)
  #define res_ki_y_39 (_particle->res_ki_y_39)
  #define res_ki_z_39 (_particle->res_ki_z_39)
  #define res_kf_x_39 (_particle->res_kf_x_39)
  #define res_kf_y_39 (_particle->res_kf_y_39)
  #define res_kf_z_39 (_particle->res_kf_z_39)
  #define res_rx_39 (_particle->res_rx_39)
  #define res_ry_39 (_particle->res_ry_39)
  #define res_rz_39 (_particle->res_rz_39)
if (_comp->_index == 39) { // EXTEND 'res_sample'
  raw_scattered = SCATTERED;
}
  #undef ncol_19
  #undef nrow_19
  #undef res_pi_39
  #undef res_ki_x_39
  #undef res_ki_y_39
  #undef res_ki_z_39
  #undef res_kf_x_39
  #undef res_kf_y_39
  #undef res_kf_z_39
  #undef res_rx_39
  #undef res_ry_39
  #undef res_rz_39

  #undef thickness
  #undef radius
  #undef focus_r
  #undef E0
  #undef dE
  #undef target_x
  #undef target_y
  #undef target_z
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef target_index
  #undef vars
  #undef res_pi_var
  #undef res_ki_x_var
  #undef res_ki_y_var
  #undef res_ki_z_var
  #undef res_kf_x_var
  #undef res_kf_y_var
  #undef res_kf_z_var
  #undef res_rx_var
  #undef res_ry_var
  #undef res_rz_var
  #undef compindex
  return;
} /* class_Res_sample_trace */

#pragma acc routine
void class_Cyl_monitor_PSD_trace(_class_Cyl_monitor_PSD *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define nr (_comp->_parameters.nr)
  #define filename (_comp->_parameters.filename)
  #define yheight (_comp->_parameters.yheight)
  #define radius (_comp->_parameters.radius)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define thmin (_comp->_parameters.thmin)
  #define thmax (_comp->_parameters.thmax)
  #define ny (_comp->_parameters.ny)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_sample_cylinder_monitor_trace] component sample_cylinder_monitor=Cyl_monitor_PSD() TRACE [Cyl_monitor_PSD:0]");

  int i, j;
  double t0, t1, phi;

  if (cylinder_intersect (&t0, &t1, x, y, z, vx, vy, vz, radius, yheight) == 1) {
    if (t0 < 0) {
      if (t1 > 0) {
        PROP_DT (t1);
        /* Calculate pixel */
        if (fabs (y) <= yheight / 2.0) {
          phi = atan2 (x, z) * RAD2DEG;

          if (phi >= thmin && phi <= thmax) {
            i = floor ((nr) * (phi - thmin) / (thmax - thmin));
            j = floor ((ny) * (y - yheight / 2.0) / (yheight));
            double p2 = p * p;

            #pragma acc atomic
            PSD_N[i][j] = PSD_N[i][j] + 1;

            #pragma acc atomic
            PSD_p[i][j] = PSD_p[i][j] + p;

            #pragma acc atomic
            PSD_p2[i][j] = PSD_p2[i][j] + p2;
          }
        }
      }
    }
  }
  if (restore_neutron) {
    RESTORE_NEUTRON (INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef nr
  #undef filename
  #undef yheight
  #undef radius
  #undef restore_neutron
  #undef thmin
  #undef thmax
  #undef ny
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return;
} /* class_Cyl_monitor_PSD_trace */

#pragma acc routine
void class_PSD_monitor_4PI_trace(_class_PSD_monitor_4PI *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define radius (_comp->_parameters.radius)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_sample_spherical_monitor_trace] component sample_spherical_monitor=PSD_monitor_4PI() TRACE [PSD_monitor_4PI:0]");

  double t0, t1, phi, theta;
  int i, j;

  if (sphere_intersect (&t0, &t1, x, y, z, vx, vy, vz, radius) && t1 > 0) {
    if (t0 < 0)
      t0 = t1;
    /* t0 is now time of intersection with the sphere. */
    mcPROP_DT (t0);
    phi = atan2 (x, z);
    i = floor (nx * (phi / (2 * PI) + 0.5));
    if (i >= nx)
      i = nx - 1; /* Special case for phi = PI. */
    else if (i < 0)
      i = 0;
    theta = asin (y / radius);
    j = floor (ny * (theta + PI / 2) / PI + 0.5);
    if (j >= ny)
      j = ny - 1; /* Special case for y = radius. */
    else if (j < 0)
      j = 0;

    double p2 = p * p;
    #pragma acc atomic
    PSD_N[i][j] = PSD_N[i][j] + 1;

    #pragma acc atomic
    PSD_p[i][j] = PSD_p[i][j] + p;

    #pragma acc atomic
    PSD_p2[i][j] = PSD_p2[i][j] + p2;

    SCATTER;
  }
  if (restore_neutron) {
    RESTORE_NEUTRON (INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef nx
  #undef ny
  #undef filename
  #undef nowritefile
  #undef radius
  #undef restore_neutron
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return;
} /* class_PSD_monitor_4PI_trace */

#pragma acc routine
void class_Filter_gen_trace(_class_Filter_gen *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define filename (_comp->_parameters.filename)
  #define options (_comp->_parameters.options)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define thickness (_comp->_parameters.thickness)
  #define scaling (_comp->_parameters.scaling)
  #define verbose (_comp->_parameters.verbose)
  #define Mode_Table (_comp->_parameters.Mode_Table)
  #define Type_Table (_comp->_parameters.Type_Table)
  #define pTable (_comp->_parameters.pTable)
  SIG_MESSAGE("[_filter_gen_trace] component filter_gen=Filter_gen() TRACE [Filter_gen:0]");

  double v2, K, L, E, X, new_p;

  PROP_Z0;
  if (Type_Table && (x > xmin && x < xmax && y > ymin && y < ymax)) {
    v2 = (vx * vx + vy * vy + vz * vz);
    K = V2K * sqrt (v2); /* k */
    L = (2 * PI / K);    /* lambda */
    E = VS2E * v2;       /* energy */
    if (Type_Table == ENERGY_TABLE)
      X = E;
    if (Type_Table == WAVEVECTOR_TABLE)
      X = K;
    if (Type_Table == WAVELENGTH_TABLE)
      X = L;
    /* table look up */
    if (pTable.data != NULL) {
      double y1, y2, x1;
      long Index;
      Index = floor ((X - pTable.min_x) / pTable.step_x);
      y1 = Table_Index (pTable, Index, 1);                           /* 2nd column */
      x1 = Table_Index (pTable, Index, 0);                           /* 1st column */
      y2 = Table_Index (pTable, Index + 1, 1);                       /* 2nd column */
      new_p = scaling * (y1 + (X - x1) * (y2 - y1) / pTable.step_x); /* 2nd column */
      if (thickness != 1)
        new_p = pow (new_p, thickness);
    } else
      new_p = 1;

    if (Mode_Table == FLUX_ADAPT_MULT)
      p *= new_p;
    else
      p = new_p;
    SCATTER;
  } else if (Type_Table)
    ABSORB;
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef filename
  #undef options
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef thickness
  #undef scaling
  #undef verbose
  #undef Mode_Table
  #undef Type_Table
  #undef pTable
  return;
} /* class_Filter_gen_trace */

#pragma acc routine
void class_PowderN_trace(_class_PowderN *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define reflections (_comp->_parameters.reflections)
  #define geometry (_comp->_parameters.geometry)
  #define format (_comp->_parameters.format)
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define xwidth (_comp->_parameters.xwidth)
  #define zdepth (_comp->_parameters.zdepth)
  #define thickness (_comp->_parameters.thickness)
  #define pack (_comp->_parameters.pack)
  #define Vc (_comp->_parameters.Vc)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define delta_d_d (_comp->_parameters.delta_d_d)
  #define p_inc (_comp->_parameters.p_inc)
  #define p_transmit (_comp->_parameters.p_transmit)
  #define DW (_comp->_parameters.DW)
  #define nb_atoms (_comp->_parameters.nb_atoms)
  #define d_omega (_comp->_parameters.d_omega)
  #define d_phi (_comp->_parameters.d_phi)
  #define tth_sign (_comp->_parameters.tth_sign)
  #define p_interact (_comp->_parameters.p_interact)
  #define concentric (_comp->_parameters.concentric)
  #define density (_comp->_parameters.density)
  #define weight (_comp->_parameters.weight)
  #define barns (_comp->_parameters.barns)
  #define Strain (_comp->_parameters.Strain)
  #define focus_flip (_comp->_parameters.focus_flip)
  #define target_index (_comp->_parameters.target_index)
  #define order (_comp->_parameters.order)
  #define line_info (_comp->_parameters.line_info)
  #define columns (_comp->_parameters.columns)
  #define offdata (_comp->_parameters.offdata)
  #define tgt_x (_comp->_parameters.tgt_x)
  #define tgt_y (_comp->_parameters.tgt_y)
  #define tgt_z (_comp->_parameters.tgt_z)
  SIG_MESSAGE("[_BeFilter_trace] component BeFilter=PowderN() TRACE [PowderN:0]");

  double t0, t1, t2, t3, v, v1, l_full, l, l_1, dt, alpha0, alpha, theta, my_s, my_s_n, sg;
  double solid_angle;
  double neutrontype = 0;
  double ntype = 0;
  double arg, tmp_vx, tmp_vy, tmp_vz, vout_x, vout_y, vout_z, nx, ny, nz, pmul = 1;
  int line;
  char intersect = 0;
  char intersecti = 0;

  // Variables calculated within thread for thread purpose only
  char type = '\0';
  int itype = 0;
  double d_phi_thread = d_phi;
  // These ones are injected back to struct at the end of TRACE in non-OpenACC case
  int nb_reuses = line_info.nb_reuses;
  int nb_refl = line_info.nb_refl;
  int nb_refl_count = line_info.nb_refl_count;
  double vcache = line_info.v;
  double Nq = line_info.Nq;
  double v_min = line_info.v_min;
  double v_max = line_info.v_max;
  double lfree = line_info.lfree;
  long xs_compute = line_info.xs_compute;
  long xs_reuse = line_info.xs_reuse;
  long xs_calls = line_info.xs_calls;
  double dq = line_info.dq;

  #ifdef OPENACC
  #ifdef USE_OFF
  off_struct thread_offdata = offdata;
  #endif
  #else
  #define thread_offdata offdata
  #endif

  if (line_info.V_0 > 0 && (line_info.count || line_info.my_inc)) {
    if (line_info.shape == 1) {
      intersect = box_intersect (&t0, &t3, x, y, z, vx, vy, vz, xwidth, yheight, zdepth);
      intersecti = box_intersect (&t1, &t2, x, y, z, vx, vy, vz, line_info.xwidth_i, line_info.yheight_i, line_info.zdepth_i);
    } else if (line_info.shape == 0) {
      intersect = cylinder_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius, yheight);
      intersecti = cylinder_intersect (&t1, &t2, x, y, z, vx, vy, vz, line_info.radius_i, line_info.yheight_i);
    } else if (line_info.shape == 2) {
      intersect = sphere_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius);
      intersecti = sphere_intersect (&t1, &t2, x, y, z, vx, vy, vz, line_info.radius_i);
    }
    #ifdef USE_OFF
    else if (line_info.shape == 3) {
      intersect = off_intersect (&t0, &t3, NULL, NULL, x, y, z, vx, vy, vz, 0, 0, 0, thread_offdata);
      intersecti = 0;
    }
    #endif
  }

  if (intersect && t3 > 0) {

    if (concentric) {
      /* Set up for concentric case */
      /* 'Remove' the backside of this comp */
      if (!intersecti) {
        t1 = (t3 + t0) / 2;
      }
      t2 = t1;
      t3 = t1;
      dt = -1.0 * rand01 (); /* In case of scattering we will scatter on 'forward' part of sample */
    } else {
      if (!intersecti) {
        t1 = (t3 + t0) / 2;
        t2 = t1;
      }
      dt = randpm1 (); /* Possibility to scatter at all points in line of sight */
    }

    /* Neutron enters at t=t0. */
    if (t0 < 0)
      t0 = 0; /* already in sample */
    if (t1 < 0)
      t1 = 0; /* already in inner hollow */
    if (t2 < 0)
      t2 = 0; /* already past inner hollow */
    v = sqrt (vx * vx + vy * vy + vz * vz);
    l_full = v * (t3 - t2 + t1 - t0);

    if (line_info.neutron_passed < CHAR_BUF_LENGTH) {
      if (v < v_min)
        v_min = v;
      if (v > v_max)
        v_max = v;
      line_info.neutron_passed++;
    }

    /* Calculate total scattering cross section at relevant velocity - but not on GPU*/
    #ifndef OPENACC
    if (fabs (v - vcache) < 1e-6) {
      nb_reuses++;
    } else {
      #endif
      Nq = calc_xsect (v, line_info.q_v, line_info.my_s_v2, line_info.count, &line_info.my_s_v2_sum, &line_info);
      vcache = v;
      nb_refl += Nq;
      nb_refl_count++;
      #ifndef OPENACC
    }
    #endif

    if (t3 < 0) {
      t3 = 0; /* Already past sample?! */
      if (line_info.flag_warning < 10)
        printf ("PowderN: %s: Warning: Neutron has already passed us? (Skipped).\n"
                "         In concentric geometry, this may be caused by a missing concentric=0 option in 2nd enclosing instance.\n",
                NAME_CURRENT_COMP);
      line_info.flag_warning++;
    } else {
      if (dt < 0) {                 /* Calculate scattering point position */
        dt = fabs (dt) * (t1 - t0); /* 'Forward' part */
      } else {
        dt = dt * (t3 - t2) + (t2 - t0); /* Possibly also 'backside' part */
      }
      if (order) {
        my_s = line_info.my_s_v2_sum / (v * v) + line_info.my_inc;
      } else {
        my_s = line_info.my_inc;
      }
      /* Total attenuation from scattering */
      lfree = 0;
      ntype = rand01 ();
      /* How to handle this one? Transmit (1) / Incoherent (2) / Coherent (3) ? */
      if (ntype < p_transmit) {
        neutrontype = 1;
        l = l_full; /* Passing through, full length */
        PROP_DT (t3);
      } else if (ntype >= p_transmit && ntype < (p_transmit + p_inc)) {
        neutrontype = 2;
        l = v * dt;        /* Penetration in sample */
        PROP_DT (dt + t0); /* Point of scattering */
        SCATTER;
      } else if (ntype >= p_transmit + p_inc) {
        neutrontype = 3;
        l = v * dt;        /* Penetration in sample */
        PROP_DT (dt + t0); /* Point of scattering */
        SCATTER;
      } else {
        exit (fprintf (stderr, "PowderN %s: DEAD - this shouldn't happen!\n", NAME_CURRENT_COMP));
      }

      if (neutrontype == 3) { /* Make coherent scattering event */
        if (line_info.count > 0) {
          /* choose line */
          if (Nq > 1)
            line = floor (Nq * rand01 ()); /* Select between Nq powder lines */
          else
            line = 0;
          if (line_info.w_v[line])
            arg = line_info.q_v[line] * (1 + line_info.w_v[line] * randnorm ()) / (2.0 * v);
          else
            arg = line_info.q_v[line] / (2.0 * v);
          my_s_n = line_info.my_s_v2[line] / (v * v);
          if (fabs (arg) > 1)
            ABSORB; /* No bragg scattering possible*/
          if (tth_sign == 0) {
            sg = randpm1 ();
            if (sg > 0)
              sg = 1;
            else
              sg = -1;
          } else {
            sg = tth_sign / fabs (tth_sign);
          }
          theta = asin (arg); /* Bragg scattering law */
          /* Choose point on Debye-Scherrer cone */
          if (d_phi_thread) { /* relate height of detector to the height on DS cone */
            arg = sin (d_phi_thread * DEG2RAD / 2) / sin (2 * theta);
            /* If full Debye-Scherrer cone is within d_phi, don't focus */
            if (arg < -1 || arg > 1)
              d_phi_thread = 0;
            /* Otherwise, determine alpha to rotate from scattering plane
               into d_phi focusing area*/
            else
              alpha = 2 * asin (arg);
          }
          if (d_phi_thread) {
            /* Focusing */
            alpha = fabs (alpha);
            alpha0 = 0.5 * randpm1 () * alpha;
            if (focus_flip) {
              alpha0 += M_PI_2;
            }
          } else
            alpha0 = PI * randpm1 ();

          /* now find a nearly vertical rotation axis:
           * Either
           *  (v along Z) x (X axis) -> nearly Y axis
           * Or
           *  (v along X) x (Z axis) -> nearly Y axis
           */

          /* update JS, 1/7/2017
            If a target is defined, try to define vertical axis as a normal to the plane
                defined by the incident neutron velocity and target position.
                Check that v is not ~ parallel to the target direction.
          */
          double vnorm = 0.0;
          if (target_index) {
            vec_prod (tmp_vx, tmp_vy, tmp_vz, vx, vy, vz, tgt_x, tgt_y, tgt_z);
            vnorm = sqrt (tmp_vx * tmp_vx + tmp_vy * tmp_vy + tmp_vz * tmp_vz) / v;
          }
          // no target or direction is nearly parallel to v:
          if (vnorm < 0.01) {
            if (fabs (vx / v) < fabs (vz / v)) {
              nx = 1;
              ny = 0;
              nz = 0;
            } else {
              nx = 0;
              ny = 0;
              nz = 1;
            }
            vec_prod (tmp_vx, tmp_vy, tmp_vz, vx, vy, vz, nx, ny, nz);
          }

          /* v_out = rotate 'v' by 2*theta around tmp_v: Bragg angle */
          rotate (vout_x, vout_y, vout_z, vx, vy, vz, 2 * sg * theta, tmp_vx, tmp_vy, tmp_vz);

          /* tmp_v = rotate v_out by alpha0 around 'v' (Debye-Scherrer cone) */
          rotate (tmp_vx, tmp_vy, tmp_vz, vout_x, vout_y, vout_z, alpha0, vx, vy, vz);
          vx = tmp_vx;
          vy = tmp_vy;
          vz = tmp_vz;

          /* Since now scattered and new direction given, calculate path to exit */
          if (line_info.shape == 1) {
            intersect = box_intersect (&t0, &t3, x, y, z, vx, vy, vz, xwidth, yheight, zdepth);
            intersecti = box_intersect (&t1, &t2, x, y, z, vx, vy, vz, line_info.xwidth_i, line_info.yheight_i, line_info.zdepth_i);
          } else if (line_info.shape == 0) {
            intersect = cylinder_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius, yheight);
            intersecti = cylinder_intersect (&t1, &t2, x, y, z, vx, vy, vz, line_info.radius_i, line_info.yheight_i);
          } else if (line_info.shape == 2) {
            intersect = sphere_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius);
            intersecti = sphere_intersect (&t1, &t2, x, y, z, vx, vy, vz, line_info.radius_i);
          }
          #ifdef USE_OFF
          else if (line_info.shape == 3) {
            intersect = off_intersect (&t0, &t3, NULL, NULL, x, y, z, vx, vy, vz, 0, 0, 0, thread_offdata);
            intersecti = 0;
          }
          #endif

          if (!intersect) {
            /* Strange error: did not hit cylinder */
            if (line_info.flag_warning < 10)
              printf ("PowderN: %s: WARNING: Did not hit sample from inside (coh). ABSORB.\n", NAME_CURRENT_COMP);
            line_info.flag_warning++;
            ABSORB;
          }

          if (!intersecti) {
            t1 = (t3 + t0) / 2;
            t2 = t1;
          }

          if (concentric && intersecti) {
            /* In case of concentricity, 'remove' backward wall of sample */
            t2 = t1;
            t3 = t1;
          }

          if (t0 < 0)
            t0 = 0; /* already in sample */
          if (t1 < 0)
            t1 = 0; /* already in inner hollow */
          if (t2 < 0)
            t2 = 0; /* already past inner hollow */

          l_1 = v * (t3 - t2 + t1 - t0); /* Length to exit */

          pmul *= Nq * l_full * my_s_n * exp (-(line_info.my_a_v / v + my_s) * (l + l_1)) / (1 - (p_inc + p_transmit));

          /* Correction in case of d_phi focusing - BUT only when d_phi != 0 */
          if (d_phi_thread) {
            pmul *= alpha / PI;
            if (tth_sign)
              pmul *= 0.5;
          }

          type = 'c';
          itype = 1;
          dq = line_info.q_v[line] * V2K;
          lfree = 1 / (line_info.my_a_v / v + my_s);
        } /* else transmit <-- No powder lines in file */
      } /* Coherent scattering event */
      else if (neutrontype == 2) { /* Make incoherent scattering event */
        if (d_omega && d_phi_thread) {
          randvec_target_rect_angular (&vx, &vy, &vz, &solid_angle, tgt_x, tgt_y, tgt_z, d_omega * DEG2RAD, d_phi_thread * DEG2RAD, ROT_A_CURRENT_COMP);
        } else if (d_phi_thread) {
          randvec_target_rect_angular (&vx, &vy, &vz, &solid_angle, tgt_x, tgt_y, tgt_z, 2 * PI, d_phi_thread * DEG2RAD, ROT_A_CURRENT_COMP);
        } else {
          randvec_target_circle (&vx, &vy, &vz, &solid_angle, 0, 0, 1, 0);
        }
        v1 = sqrt (vx * vx + vy * vy + vz * vz);
        vx *= v / v1;
        vy *= v / v1;
        vz *= v / v1;

        /* Since now scattered and new direction given, calculate path to exit */
        if (line_info.shape == 1) {
          intersect = box_intersect (&t0, &t3, x, y, z, vx, vy, vz, xwidth, yheight, zdepth);
          intersecti = box_intersect (&t1, &t2, x, y, z, vx, vy, vz, line_info.xwidth_i, line_info.yheight_i, line_info.zdepth_i);
        } else if (line_info.shape == 0) {
          intersect = cylinder_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius, yheight);
          intersecti = cylinder_intersect (&t1, &t2, x, y, z, vx, vy, vz, line_info.radius_i, line_info.yheight_i);
        } else if (line_info.shape == 2) {
          intersect = sphere_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius);
          intersecti = sphere_intersect (&t1, &t2, x, y, z, vx, vy, vz, line_info.radius_i);
        }
        #ifdef USE_OFF
        else if (line_info.shape == 3) {
          intersect = off_intersect (&t0, &t3, NULL, NULL, x, y, z, vx, vy, vz, 0, 0, 0, thread_offdata);
          intersecti = 0;
        }
        #endif

        if (!intersect) {
          /* Strange error: did not hit cylinder */
          if (line_info.flag_warning < 10)
            printf ("PowderN: %s: WARNING: Did not hit sample from inside (inc). ABSORB.\n", NAME_CURRENT_COMP);
          line_info.flag_warning++;
          ABSORB;
        }

        if (!intersecti) {
          t1 = (t3 + t0) / 2;
          t2 = t1;
        }

        if (concentric && intersecti) {
          /* In case of concentricity, 'remove' backward wall of sample */
          t2 = t1;
          t3 = t1;
        }

        if (t0 < 0)
          t0 = 0; /* already in sample */
        if (t1 < 0)
          t1 = 0; /* already in inner hollow */
        if (t2 < 0)
          t2 = 0; /* already past inner hollow */

        l_1 = v * (t3 - t2 + t1 - t0); /* Length to exit */

        pmul *= l_full * line_info.my_inc * exp (-(line_info.my_a_v / v + my_s) * (l + l_1)) / (p_inc);
        pmul *= solid_angle / (4 * PI);
        lfree = 1 / (line_info.my_a_v / v + my_s);
        type = 'i';
        itype = 2;

      } /* Incoherent scattering event */
      else if (neutrontype == 1) {
        /* Make transmitted (absorption-corrected) event */
        /* No coordinate changes here, simply change neutron weight */
        pmul *= exp (-(line_info.my_a_v / v + my_s) * (l)) / (p_transmit);
        lfree = 1 / (line_info.my_a_v / v + my_s);
        type = 't';
        itype = 3;
      }
      p *= pmul;
    } /* Neutron leaving since it has passed already */
  } /* else transmit non interacting neutrons */

  // Inject these back to global struct in non-OpenACC case
  #ifndef OPENACC
  line_info.nb_reuses = nb_reuses;
  line_info.nb_refl = nb_refl;
  line_info.nb_refl_count = nb_refl_count;
  line_info.v = vcache;
  line_info.Nq = Nq;
  line_info.v_min = v_min;
  line_info.v_max = v_max;
  line_info.lfree = lfree;
  line_info.xs_compute = xs_compute;
  line_info.xs_reuse = xs_reuse;
  line_info.xs_calls = xs_calls;
  line_info.dq = dq;
  #endif
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef reflections
  #undef geometry
  #undef format
  #undef radius
  #undef yheight
  #undef xwidth
  #undef zdepth
  #undef thickness
  #undef pack
  #undef Vc
  #undef sigma_abs
  #undef sigma_inc
  #undef delta_d_d
  #undef p_inc
  #undef p_transmit
  #undef DW
  #undef nb_atoms
  #undef d_omega
  #undef d_phi
  #undef tth_sign
  #undef p_interact
  #undef concentric
  #undef density
  #undef weight
  #undef barns
  #undef Strain
  #undef focus_flip
  #undef target_index
  #undef order
  #undef line_info
  #undef columns
  #undef offdata
  #undef tgt_x
  #undef tgt_y
  #undef tgt_z
  return;
} /* class_PowderN_trace */

#define ncol_19 (_particle->ncol_19)
#define nrow_19 (_particle->nrow_19)
#define res_pi_39 (_particle->res_pi_39)
#define res_ki_x_39 (_particle->res_ki_x_39)
#define res_ki_y_39 (_particle->res_ki_y_39)
#define res_ki_z_39 (_particle->res_ki_z_39)
#define res_kf_x_39 (_particle->res_kf_x_39)
#define res_kf_y_39 (_particle->res_kf_y_39)
#define res_kf_z_39 (_particle->res_kf_z_39)
#define res_rx_39 (_particle->res_rx_39)
#define res_ry_39 (_particle->res_ry_39)
#define res_rz_39 (_particle->res_rz_39)
/* *****************************************************************************
* instrument 'PSI_CAMEA' TRACE
***************************************************************************** */

#ifndef FUNNEL
#pragma acc routine
int raytrace(_class_particle* _particle) { /* single event propagation, called by mccode_main for PSI_CAMEA:TRACE */

  /* init variables and counters for TRACE */
  #undef ABSORB0
  #undef ABSORB
  #define ABSORB0 do { DEBUG_ABSORB(); MAGNET_OFF; ABSORBED++;} while(0)
  #define ABSORB ABSORB0
  DEBUG_ENTER();
  DEBUG_STATE();
  _particle->flag_nocoordschange=0; /* Init */
  _class_particle _particle_save=*_particle;
  /* the main iteration loop for one incoming event */
  while (!ABSORBED) { /* iterate event until absorbed */
    /* send particle event to component instance, one after the other */
    /* begin component Origin=Progress_bar() [1] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_Origin_var._rotation_is_identity) {
        if(!_Origin_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _Origin_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_Origin_var._position_relative, _Origin_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 1) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_Origin_var._name);
      DEBUG_STATE();
      class_Progress_bar_trace(&_Origin_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component Origin [1] */
    /* begin component source=Source_gen4() [2] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_source_var._rotation_is_identity) {
        if(!_source_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _source_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_source_var._position_relative, _source_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 2) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_source_var._name);
      DEBUG_STATE();
      class_Source_gen4_trace(&_source_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component source [2] */
    /* begin component StartOfGuideMonitor=PSD_monitor() [3] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_StartOfGuideMonitor_var._rotation_is_identity) {
        if(!_StartOfGuideMonitor_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _StartOfGuideMonitor_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_StartOfGuideMonitor_var._position_relative, _StartOfGuideMonitor_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 3) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_StartOfGuideMonitor_var._name);
      DEBUG_STATE();
      class_PSD_monitor_trace(&_StartOfGuideMonitor_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component StartOfGuideMonitor [3] */
    /* begin component StartOfGuide=Arm() [4] */
    if (!ABSORBED && _particle->_index == 4) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component StartOfGuide [4] */
    /* begin component Insert=Elliptic_guide_gravity() [5] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_Insert_var._rotation_is_identity) {
        if(!_Insert_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _Insert_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_Insert_var._position_relative, _Insert_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 5) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_Insert_var._name);
      DEBUG_STATE();
      class_Elliptic_guide_gravity_trace(&_Insert_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component Insert [5] */
    /* begin component EndOfInsertPSD=PSD_monitor() [6] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_EndOfInsertPSD_var._rotation_is_identity) {
        if(!_EndOfInsertPSD_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _EndOfInsertPSD_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_EndOfInsertPSD_var._position_relative, _EndOfInsertPSD_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 6) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_EndOfInsertPSD_var._name);
      DEBUG_STATE();
      class_PSD_monitor_trace(&_EndOfInsertPSD_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component EndOfInsertPSD [6] */
    /* begin component E2=Elliptic_guide_gravity() [7] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_E2_var._rotation_is_identity) {
        if(!_E2_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _E2_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_E2_var._position_relative, _E2_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 7) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_E2_var._name);
      DEBUG_STATE();
      class_Elliptic_guide_gravity_trace(&_E2_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component E2 [7] */
    /* begin component EndOfelement_5=Arm() [8] */
    if (!ABSORBED && _particle->_index == 8) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component EndOfelement_5 [8] */
    /* begin component E2PSD=PSD_monitor() [9] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_E2PSD_var._rotation_is_identity) {
        if(!_E2PSD_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _E2PSD_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_E2PSD_var._position_relative, _E2PSD_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 9) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_E2PSD_var._name);
      DEBUG_STATE();
      class_PSD_monitor_trace(&_E2PSD_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component E2PSD [9] */
    /* begin component EndOfelement_4=Arm() [10] */
    if (!ABSORBED && _particle->_index == 10) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component EndOfelement_4 [10] */
    /* begin component C1=Bender() [11] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_C1_var._rotation_is_identity) {
        if(!_C1_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _C1_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_C1_var._position_relative, _C1_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 11) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_C1_var._name);
      DEBUG_STATE();
      class_Bender_trace(&_C1_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component C1 [11] */
    /* begin component EndOfelement_2=Arm() [12] */
    if (!ABSORBED && _particle->_index == 12) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component EndOfelement_2 [12] */
    /* begin component C1End=PSD_monitor() [13] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_C1End_var._rotation_is_identity) {
        if(!_C1End_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _C1End_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_C1End_var._position_relative, _C1End_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 13) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_C1End_var._name);
      DEBUG_STATE();
      class_PSD_monitor_trace(&_C1End_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component C1End [13] */
    /* begin component E3a=Elliptic_guide_gravity() [14] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_E3a_var._rotation_is_identity) {
        if(!_E3a_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _E3a_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_E3a_var._position_relative, _E3a_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 14) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_E3a_var._name);
      DEBUG_STATE();
      class_Elliptic_guide_gravity_trace(&_E3a_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component E3a [14] */
    /* begin component E3aEnd=PSD_monitor() [15] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_E3aEnd_var._rotation_is_identity) {
        if(!_E3aEnd_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _E3aEnd_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_E3aEnd_var._position_relative, _E3aEnd_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 15) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_E3aEnd_var._name);
      DEBUG_STATE();
      class_PSD_monitor_trace(&_E3aEnd_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component E3aEnd [15] */
    /* begin component E3b=Elliptic_guide_gravity() [16] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_E3b_var._rotation_is_identity) {
        if(!_E3b_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _E3b_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_E3b_var._position_relative, _E3b_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 16) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_E3b_var._name);
      DEBUG_STATE();
      class_Elliptic_guide_gravity_trace(&_E3b_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component E3b [16] */
    /* begin component E3bEnd=PSD_monitor() [17] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_E3bEnd_var._rotation_is_identity) {
        if(!_E3bEnd_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _E3bEnd_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_E3bEnd_var._position_relative, _E3bEnd_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 17) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_E3bEnd_var._name);
      DEBUG_STATE();
      class_PSD_monitor_trace(&_E3bEnd_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component E3bEnd [17] */
    /* begin component SlitGuideEnd=Slit() [18] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_SlitGuideEnd_var._rotation_is_identity) {
        if(!_SlitGuideEnd_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _SlitGuideEnd_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_SlitGuideEnd_var._position_relative, _SlitGuideEnd_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 18) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_SlitGuideEnd_var._name);
      DEBUG_STATE();
      class_Slit_trace(&_SlitGuideEnd_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component SlitGuideEnd [18] */
    /* begin component Mono=Monochromator_curved() [19] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_Mono_var._rotation_is_identity) {
        if(!_Mono_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _Mono_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_Mono_var._position_relative, _Mono_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 19) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_Mono_var._name);
      DEBUG_STATE();
      class_Monochromator_curved_trace(&_Mono_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component Mono [19] */
    /* begin component A2=Arm() [20] */
    if (!ABSORBED && _particle->_index == 20) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component A2 [20] */
    /* begin component monochromatorShielding=Slit() [21] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_monochromatorShielding_var._rotation_is_identity) {
        if(!_monochromatorShielding_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _monochromatorShielding_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_monochromatorShielding_var._position_relative, _monochromatorShielding_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 21) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_monochromatorShielding_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.MonoShielding ))) // conditional WHEN execution
      class_Slit_trace(&_monochromatorShielding_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component monochromatorShielding [21] */
    /* begin component slit=Slit() [22] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_slit_var._rotation_is_identity) {
        if(!_slit_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _slit_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_slit_var._position_relative, _slit_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 22) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_slit_var._name);
      DEBUG_STATE();
      class_Slit_trace(&_slit_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component slit [22] */
    /* begin component SlitMonitor=PSD_monitor() [23] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_SlitMonitor_var._rotation_is_identity) {
        if(!_SlitMonitor_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _SlitMonitor_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_SlitMonitor_var._position_relative, _SlitMonitor_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 23) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_SlitMonitor_var._name);
      DEBUG_STATE();
      class_PSD_monitor_trace(&_SlitMonitor_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component SlitMonitor [23] */
    /* begin component SamplePos=Arm() [24] */
    if (!ABSORBED && _particle->_index == 24) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component SamplePos [24] */
    /* begin component AMidt=Arm() [25] */
    if (!ABSORBED && _particle->_index == 25) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component AMidt [25] */
    /* begin component a41=Arm() [26] */
    if (!ABSORBED && _particle->_index == 26) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component a41 [26] */
    /* begin component a42=Arm() [27] */
    if (!ABSORBED && _particle->_index == 27) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component a42 [27] */
    /* begin component a43=Arm() [28] */
    if (!ABSORBED && _particle->_index == 28) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component a43 [28] */
    /* begin component a44=Arm() [29] */
    if (!ABSORBED && _particle->_index == 29) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component a44 [29] */
    /* begin component a45=Arm() [30] */
    if (!ABSORBED && _particle->_index == 30) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component a45 [30] */
    /* begin component a46=Arm() [31] */
    if (!ABSORBED && _particle->_index == 31) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component a46 [31] */
    /* begin component a47=Arm() [32] */
    if (!ABSORBED && _particle->_index == 32) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component a47 [32] */
    /* begin component a48=Arm() [33] */
    if (!ABSORBED && _particle->_index == 33) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component a48 [33] */
    /* begin component sample_flux_before=PSD_monitor() [34] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_sample_flux_before_var._rotation_is_identity) {
        if(!_sample_flux_before_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _sample_flux_before_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_sample_flux_before_var._position_relative, _sample_flux_before_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 34) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_sample_flux_before_var._name);
      DEBUG_STATE();
      class_PSD_monitor_trace(&_sample_flux_before_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component sample_flux_before [34] */
#ifndef NOSPLIT
    /* start SPLIT at sample_scatter_state_reset */
    if (!ABSORBED) {
    _class_particle Split_sample_scatter_state_reset_particle=*_particle;
    int Split_sample_scatter_state_reset_counter;
    int SplitS_sample_scatter_state_reset = 100;
    #pragma acc loop independent
    for (Split_sample_scatter_state_reset_counter = 0; Split_sample_scatter_state_reset_counter< SplitS_sample_scatter_state_reset; Split_sample_scatter_state_reset_counter++) {
      randstate_t randbackup = *_particle->randstate;
      *_particle=Split_sample_scatter_state_reset_particle;
      *_particle->randstate = randbackup;
      p /= SplitS_sample_scatter_state_reset > 0 ? SplitS_sample_scatter_state_reset : 1;
#endif
    /* begin component sample_scatter_state_reset=Arm() [35] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_sample_scatter_state_reset_var._rotation_is_identity) {
        if(!_sample_scatter_state_reset_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _sample_scatter_state_reset_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_sample_scatter_state_reset_var._position_relative, _sample_scatter_state_reset_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 35) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_sample_scatter_state_reset_var._name);
      DEBUG_STATE();
      class_Arm_trace(&_sample_scatter_state_reset_var, _particle); /* contains EXTEND code */
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component sample_scatter_state_reset [35] */
    /* begin component VanSample=Incoherent() [36] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_VanSample_var._rotation_is_identity) {
        if(!_VanSample_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _VanSample_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_VanSample_var._position_relative, _VanSample_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 36) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_VanSample_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.SAMPLE == 0 ))) // conditional WHEN execution
      class_Incoherent_trace(&_VanSample_var, _particle); /* contains EXTEND code */
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component VanSample [36] */
    /* begin component sample=Phonon_simple() [37] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_sample_var._rotation_is_identity) {
        if(!_sample_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _sample_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_sample_var._position_relative, _sample_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 37) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_sample_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.SAMPLE == 1 ))) // conditional WHEN execution
      class_Phonon_simple_trace(&_sample_var, _particle); /* contains EXTEND code */
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component sample [37] */
    /* begin component powder1=Powder1() [38] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_powder1_var._rotation_is_identity) {
        if(!_powder1_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _powder1_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_powder1_var._position_relative, _powder1_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 38) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_powder1_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.SAMPLE == 2 ))) // conditional WHEN execution
      class_Powder1_trace(&_powder1_var, _particle); /* contains EXTEND code */
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component powder1 [38] */
    /* begin component res_sample=Res_sample() [39] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_res_sample_var._rotation_is_identity) {
        if(!_res_sample_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _res_sample_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_res_sample_var._position_relative, _res_sample_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 39) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_res_sample_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.SAMPLE == 3 ))) // conditional WHEN execution
      class_Res_sample_trace(&_res_sample_var, _particle); /* contains EXTEND code */
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component res_sample [39] */
    /* begin component sample_flux_after_unscattered=PSD_monitor() [40] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_sample_flux_after_unscattered_var._rotation_is_identity) {
        if(!_sample_flux_after_unscattered_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _sample_flux_after_unscattered_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_sample_flux_after_unscattered_var._position_relative, _sample_flux_after_unscattered_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 40) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_sample_flux_after_unscattered_var._name);
      DEBUG_STATE();
      if ((( raw_scattered == 0 ))) // conditional WHEN execution
      class_PSD_monitor_trace(&_sample_flux_after_unscattered_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component sample_flux_after_unscattered [40] */
    /* begin component sample_cylinder_monitor=Cyl_monitor_PSD() [41] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_sample_cylinder_monitor_var._rotation_is_identity) {
        if(!_sample_cylinder_monitor_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _sample_cylinder_monitor_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_sample_cylinder_monitor_var._position_relative, _sample_cylinder_monitor_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 41) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_sample_cylinder_monitor_var._name);
      DEBUG_STATE();
      class_Cyl_monitor_PSD_trace(&_sample_cylinder_monitor_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component sample_cylinder_monitor [41] */
    /* begin component sample_spherical_monitor=PSD_monitor_4PI() [42] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_sample_spherical_monitor_var._rotation_is_identity) {
        if(!_sample_spherical_monitor_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _sample_spherical_monitor_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_sample_spherical_monitor_var._position_relative, _sample_spherical_monitor_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 42) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_sample_spherical_monitor_var._name);
      DEBUG_STATE();
      class_PSD_monitor_4PI_trace(&_sample_spherical_monitor_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component sample_spherical_monitor [42] */
    /* begin component BackEndMonitor=PSD_monitor() [43] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_BackEndMonitor_var._rotation_is_identity) {
        if(!_BackEndMonitor_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _BackEndMonitor_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_BackEndMonitor_var._position_relative, _BackEndMonitor_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 43) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_BackEndMonitor_var._name);
      DEBUG_STATE();
      class_PSD_monitor_trace(&_BackEndMonitor_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component BackEndMonitor [43] */
    /* begin component slitBackEnd=Slit() [44] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_slitBackEnd_var._rotation_is_identity) {
        if(!_slitBackEnd_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _slitBackEnd_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_slitBackEnd_var._position_relative, _slitBackEnd_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 44) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_slitBackEnd_var._name);
      DEBUG_STATE();
      class_Slit_trace(&_slitBackEnd_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component slitBackEnd [44] */
    /* begin component filter_gen=Filter_gen() [45] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_filter_gen_var._rotation_is_identity) {
        if(!_filter_gen_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _filter_gen_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_filter_gen_var._position_relative, _filter_gen_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 45) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_filter_gen_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.Be_filter == 1 ))) // conditional WHEN execution
      class_Filter_gen_trace(&_filter_gen_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component filter_gen [45] */
    /* begin component BeFilter=PowderN() [46] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_BeFilter_var._rotation_is_identity) {
        if(!_BeFilter_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _BeFilter_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_BeFilter_var._position_relative, _BeFilter_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 46) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_BeFilter_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.Be_filter == 1 ))) // conditional WHEN execution
      class_PowderN_trace(&_BeFilter_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component BeFilter [46] */
#ifndef NOSPLIT
    } /* end SPLIT at sample_scatter_state_reset */
    } /* if (!ABSORBED) relating to SPLIT at sample_scatter_state_reset */
#endif
    if (_particle->_index > 46)
      ABSORBED++; /* absorbed when passed all components */
  } /* while !ABSORBED */

  DEBUG_LEAVE()
  particle_restore(_particle, &_particle_save);
  DEBUG_STATE()

  return(_particle->_index);
} /* raytrace */

/* loop to generate events and call raytrace() propagate them */
void raytrace_all(unsigned long long ncount, unsigned long seed) {

  /* CPU-loop */
  unsigned long long loops;
  loops = ceil((double)ncount/gpu_innerloop);
  /* if on GPU, printf has been globally nullified, re-enable here */
  #ifdef OPENACC
  #undef strlen
  #undef strcmp
  #undef exit
  #undef printf
  #undef sprintf
  #undef fprintf
  #endif

  #ifdef OPENACC
  if (ncount>gpu_innerloop) {
    printf("Defining %llu CPU loops around GPU kernel and adjusting ncount\n",loops);
    mcset_ncount(loops*gpu_innerloop);
  } else {
    #endif
    loops=1;
    gpu_innerloop = ncount;
    #ifdef OPENACC
  }
    #endif

  for (unsigned long long cloop=0; cloop<loops; cloop++) {
    #ifdef OPENACC
    if (loops>1) fprintf(stdout, "%d..", (int)cloop); fflush(stdout);
    #endif

    /* if on GPU, re-nullify printf */
     #ifdef OPENACC
     #undef strlen
     #undef strcmp
     #undef exit
     #undef printf
     #undef sprintf
     #undef fprintf
     #endif

    #pragma acc parallel loop num_gangs(numgangs) vector_length(vecsize)
    for (unsigned long pidx=0 ; pidx < gpu_innerloop ; pidx++) {
      _class_particle particleN = mcgenstate(); // initial particle
      _class_particle* _particle = &particleN;
      particleN._uid = pidx;
      #ifdef USE_MPI
      particleN._uid += mpi_node_rank * ncount; 
      #endif

      srandom(_hash((pidx+1)*(seed+1)));

      raytrace(_particle);
    } /* inner for */
    seed = seed+gpu_innerloop;
  } /* CPU for */
  /* if on GPU, printf has been globally nullified, re-enable here */
     #ifdef OPENACC
     #undef strlen
     #undef strcmp
     #undef exit
     #undef printf
     #undef sprintf
     #undef fprintf
     #endif
  MPI_MASTER(
  printf("*** TRACE end *** \n");
  );
} /* raytrace_all */

#endif //no-FUNNEL

#ifdef FUNNEL
// Alternative raytrace algorithm which iterates all particles through
// one component at the time, can remove absorbs from the next loop and
// switch between cpu/gpu.
void raytrace_all_funnel(unsigned long long ncount, unsigned long seed) {

  // set up outer (CPU) loop / particle batches
  unsigned long long loops;

  /* if on GPU, printf has been globally nullified, re-enable here */
   #ifdef OPENACC
   #undef strlen
   #undef strcmp
   #undef exit
   #undef printf
   #undef sprintf
   #undef fprintf
   #endif
  #ifdef OPENACC
  loops = ceil((double)ncount/gpu_innerloop);
  if (ncount>gpu_innerloop) {
    printf("Defining %llu CPU loops around kernel and adjusting ncount\n",loops);
    mcset_ncount(loops*gpu_innerloop);
  } else {
  #endif
    loops=1;
    gpu_innerloop = ncount;
  #ifdef OPENACC
  }
  #endif

  // create particles struct and pointer arrays (same memory used by all batches)
  _class_particle* particles = malloc(gpu_innerloop*sizeof(_class_particle));
  _class_particle* pbuffer = malloc(gpu_innerloop*sizeof(_class_particle));
  long livebatchsize = gpu_innerloop;

  #undef ABSORB0
  #undef ABSORB
  #define ABSORB0 do { DEBUG_ABSORB(); MAGNET_OFF; ABSORBED++; } while(0)
  #define ABSORB ABSORB0
  // outer loop / particle batches
  for (unsigned long long cloop=0; cloop<loops; cloop++) {
    if (loops>1) fprintf(stdout, "%d..", (int)cloop); fflush(stdout);

    // init particles
    #pragma acc parallel loop present(particles[0:livebatchsize])
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      // generate particle state, set loop index and seed
      particles[pidx] = mcgenstate();
      _class_particle* _particle = particles + pidx;
      _particle->_uid = pidx;
      #ifdef USE_MPI
      _particle->_uid += mpi_node_rank * ncount; 
      #endif
      srandom(_hash((pidx+1)*(seed+1))); // _particle->state usage built into srandom macro
    }

    // iterate components

    #pragma acc parallel loop present(particles[0:livebatchsize])
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      _class_particle* _particle = &particles[pidx];
      _class_particle _particle_save;

      // Origin
    if (!ABSORBED && _particle->_index == 1) {
#ifndef MULTICORE
        if (_Origin_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _Origin_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_Origin_var._position_relative, _Origin_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Progress_bar_trace(&_Origin_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // source
    if (!ABSORBED && _particle->_index == 2) {
#ifndef MULTICORE
        if (_source_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _source_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_source_var._position_relative, _source_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Source_gen4_trace(&_source_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // StartOfGuideMonitor
    if (!ABSORBED && _particle->_index == 3) {
#ifndef MULTICORE
        if (_StartOfGuideMonitor_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _StartOfGuideMonitor_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_StartOfGuideMonitor_var._position_relative, _StartOfGuideMonitor_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_PSD_monitor_trace(&_StartOfGuideMonitor_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // StartOfGuide
    if (!ABSORBED && _particle->_index == 4) {
        _particle->_index++;
      }

      // Insert
    if (!ABSORBED && _particle->_index == 5) {
#ifndef MULTICORE
        if (_Insert_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _Insert_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_Insert_var._position_relative, _Insert_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Elliptic_guide_gravity_trace(&_Insert_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // EndOfInsertPSD
    if (!ABSORBED && _particle->_index == 6) {
#ifndef MULTICORE
        if (_EndOfInsertPSD_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _EndOfInsertPSD_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_EndOfInsertPSD_var._position_relative, _EndOfInsertPSD_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_PSD_monitor_trace(&_EndOfInsertPSD_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // E2
    if (!ABSORBED && _particle->_index == 7) {
#ifndef MULTICORE
        if (_E2_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _E2_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_E2_var._position_relative, _E2_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Elliptic_guide_gravity_trace(&_E2_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // EndOfelement_5
    if (!ABSORBED && _particle->_index == 8) {
        _particle->_index++;
      }

      // E2PSD
    if (!ABSORBED && _particle->_index == 9) {
#ifndef MULTICORE
        if (_E2PSD_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _E2PSD_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_E2PSD_var._position_relative, _E2PSD_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_PSD_monitor_trace(&_E2PSD_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // EndOfelement_4
    if (!ABSORBED && _particle->_index == 10) {
        _particle->_index++;
      }

      // C1
    if (!ABSORBED && _particle->_index == 11) {
#ifndef MULTICORE
        if (_C1_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _C1_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_C1_var._position_relative, _C1_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Bender_trace(&_C1_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // EndOfelement_2
    if (!ABSORBED && _particle->_index == 12) {
        _particle->_index++;
      }

      // C1End
    if (!ABSORBED && _particle->_index == 13) {
#ifndef MULTICORE
        if (_C1End_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _C1End_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_C1End_var._position_relative, _C1End_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_PSD_monitor_trace(&_C1End_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // E3a
    if (!ABSORBED && _particle->_index == 14) {
#ifndef MULTICORE
        if (_E3a_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _E3a_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_E3a_var._position_relative, _E3a_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Elliptic_guide_gravity_trace(&_E3a_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // E3aEnd
    if (!ABSORBED && _particle->_index == 15) {
#ifndef MULTICORE
        if (_E3aEnd_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _E3aEnd_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_E3aEnd_var._position_relative, _E3aEnd_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_PSD_monitor_trace(&_E3aEnd_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // E3b
    if (!ABSORBED && _particle->_index == 16) {
#ifndef MULTICORE
        if (_E3b_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _E3b_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_E3b_var._position_relative, _E3b_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Elliptic_guide_gravity_trace(&_E3b_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // E3bEnd
    if (!ABSORBED && _particle->_index == 17) {
#ifndef MULTICORE
        if (_E3bEnd_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _E3bEnd_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_E3bEnd_var._position_relative, _E3bEnd_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_PSD_monitor_trace(&_E3bEnd_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // SlitGuideEnd
    if (!ABSORBED && _particle->_index == 18) {
#ifndef MULTICORE
        if (_SlitGuideEnd_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _SlitGuideEnd_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_SlitGuideEnd_var._position_relative, _SlitGuideEnd_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Slit_trace(&_SlitGuideEnd_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // Mono
    if (!ABSORBED && _particle->_index == 19) {
#ifndef MULTICORE
        if (_Mono_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _Mono_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_Mono_var._position_relative, _Mono_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Monochromator_curved_trace(&_Mono_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // A2
    if (!ABSORBED && _particle->_index == 20) {
        _particle->_index++;
      }

      // monochromatorShielding
    if (!ABSORBED && _particle->_index == 21) {
#ifndef MULTICORE
        if (_monochromatorShielding_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _monochromatorShielding_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_monochromatorShielding_var._position_relative, _monochromatorShielding_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.MonoShielding ))) // conditional WHEN
        class_Slit_trace(&_monochromatorShielding_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // slit
    if (!ABSORBED && _particle->_index == 22) {
#ifndef MULTICORE
        if (_slit_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _slit_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_slit_var._position_relative, _slit_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Slit_trace(&_slit_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // SlitMonitor
    if (!ABSORBED && _particle->_index == 23) {
#ifndef MULTICORE
        if (_SlitMonitor_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _SlitMonitor_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_SlitMonitor_var._position_relative, _SlitMonitor_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_PSD_monitor_trace(&_SlitMonitor_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // SamplePos
    if (!ABSORBED && _particle->_index == 24) {
        _particle->_index++;
      }

      // AMidt
    if (!ABSORBED && _particle->_index == 25) {
        _particle->_index++;
      }

      // a41
    if (!ABSORBED && _particle->_index == 26) {
        _particle->_index++;
      }

      // a42
    if (!ABSORBED && _particle->_index == 27) {
        _particle->_index++;
      }

      // a43
    if (!ABSORBED && _particle->_index == 28) {
        _particle->_index++;
      }

      // a44
    if (!ABSORBED && _particle->_index == 29) {
        _particle->_index++;
      }

      // a45
    if (!ABSORBED && _particle->_index == 30) {
        _particle->_index++;
      }

      // a46
    if (!ABSORBED && _particle->_index == 31) {
        _particle->_index++;
      }

      // a47
    if (!ABSORBED && _particle->_index == 32) {
        _particle->_index++;
      }

      // a48
    if (!ABSORBED && _particle->_index == 33) {
        _particle->_index++;
      }

      // sample_flux_before
    if (!ABSORBED && _particle->_index == 34) {
#ifndef MULTICORE
        if (_sample_flux_before_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _sample_flux_before_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_sample_flux_before_var._position_relative, _sample_flux_before_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_PSD_monitor_trace(&_sample_flux_before_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }
    }

    // SPLIT with available livebatchsize 
    long mult_sample_scatter_state_reset;
    livebatchsize = sort_absorb_last(particles, pbuffer, livebatchsize, gpu_innerloop, 1, &mult_sample_scatter_state_reset);
    //printf("livebatchsize: %ld, split: %ld\n",  livebatchsize, mult);

    #pragma acc parallel loop present(particles[0:livebatchsize])
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      _class_particle* _particle = &particles[pidx];
      _class_particle _particle_save;

      // sample_scatter_state_reset
    if (!ABSORBED && _particle->_index == 35) {
#ifndef MULTICORE
        if (_sample_scatter_state_reset_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _sample_scatter_state_reset_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_sample_scatter_state_reset_var._position_relative, _sample_scatter_state_reset_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Arm_trace(&_sample_scatter_state_reset_var, _particle); /* contains EXTEND code */
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // VanSample
    if (!ABSORBED && _particle->_index == 36) {
#ifndef MULTICORE
        if (_VanSample_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _VanSample_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_VanSample_var._position_relative, _VanSample_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.SAMPLE == 0 ))) // conditional WHEN
        class_Incoherent_trace(&_VanSample_var, _particle); /* contains EXTEND code */
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // sample
    if (!ABSORBED && _particle->_index == 37) {
#ifndef MULTICORE
        if (_sample_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _sample_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_sample_var._position_relative, _sample_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.SAMPLE == 1 ))) // conditional WHEN
        class_Phonon_simple_trace(&_sample_var, _particle); /* contains EXTEND code */
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // powder1
    if (!ABSORBED && _particle->_index == 38) {
#ifndef MULTICORE
        if (_powder1_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _powder1_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_powder1_var._position_relative, _powder1_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.SAMPLE == 2 ))) // conditional WHEN
        class_Powder1_trace(&_powder1_var, _particle); /* contains EXTEND code */
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // res_sample
    if (!ABSORBED && _particle->_index == 39) {
#ifndef MULTICORE
        if (_res_sample_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _res_sample_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_res_sample_var._position_relative, _res_sample_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.SAMPLE == 3 ))) // conditional WHEN
        class_Res_sample_trace(&_res_sample_var, _particle); /* contains EXTEND code */
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // sample_flux_after_unscattered
    if (!ABSORBED && _particle->_index == 40) {
#ifndef MULTICORE
        if (_sample_flux_after_unscattered_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _sample_flux_after_unscattered_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_sample_flux_after_unscattered_var._position_relative, _sample_flux_after_unscattered_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( raw_scattered == 0 ))) // conditional WHEN
        class_PSD_monitor_trace(&_sample_flux_after_unscattered_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // sample_cylinder_monitor
    if (!ABSORBED && _particle->_index == 41) {
#ifndef MULTICORE
        if (_sample_cylinder_monitor_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _sample_cylinder_monitor_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_sample_cylinder_monitor_var._position_relative, _sample_cylinder_monitor_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Cyl_monitor_PSD_trace(&_sample_cylinder_monitor_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // sample_spherical_monitor
    if (!ABSORBED && _particle->_index == 42) {
#ifndef MULTICORE
        if (_sample_spherical_monitor_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _sample_spherical_monitor_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_sample_spherical_monitor_var._position_relative, _sample_spherical_monitor_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_PSD_monitor_4PI_trace(&_sample_spherical_monitor_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // BackEndMonitor
    if (!ABSORBED && _particle->_index == 43) {
#ifndef MULTICORE
        if (_BackEndMonitor_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _BackEndMonitor_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_BackEndMonitor_var._position_relative, _BackEndMonitor_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_PSD_monitor_trace(&_BackEndMonitor_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // slitBackEnd
    if (!ABSORBED && _particle->_index == 44) {
#ifndef MULTICORE
        if (_slitBackEnd_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _slitBackEnd_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_slitBackEnd_var._position_relative, _slitBackEnd_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Slit_trace(&_slitBackEnd_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // filter_gen
    if (!ABSORBED && _particle->_index == 45) {
#ifndef MULTICORE
        if (_filter_gen_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _filter_gen_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_filter_gen_var._position_relative, _filter_gen_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.Be_filter == 1 ))) // conditional WHEN
        class_Filter_gen_trace(&_filter_gen_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // BeFilter
    if (!ABSORBED && _particle->_index == 46) {
#ifndef MULTICORE
        if (_BeFilter_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _BeFilter_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_BeFilter_var._position_relative, _BeFilter_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.Be_filter == 1 ))) // conditional WHEN
        class_PowderN_trace(&_BeFilter_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

    }

    // jump to next viable seed
    seed = seed + gpu_innerloop;
  } // outer loop / particle batches

  free(particles);
  free(pbuffer);

  printf("\n");
} /* raytrace_all_funnel */
#endif // FUNNEL

#undef ncol_19
#undef nrow_19
#undef res_pi_39
#undef res_ki_x_39
#undef res_ki_y_39
#undef res_ki_z_39
#undef res_kf_x_39
#undef res_kf_y_39
#undef res_kf_z_39
#undef res_rx_39
#undef res_ry_39
#undef res_rz_39
#undef x
#undef y
#undef z
#undef vx
#undef vy
#undef vz
#undef t
#undef sx
#undef sy
#undef sz
#undef p
#undef mcgravitation
#undef mcMagnet
#undef allow_backprop
#undef _mctmp_a
#undef _mctmp_b
#undef _mctmp_c
#ifdef OPENACC
#undef strlen
#undef strcmp
#undef exit
#undef printf
#undef sprintf
#undef fprintf
#endif
#undef SCATTERED
#undef RESTORE
#undef RESTORE_NEUTRON
#undef STORE_NEUTRON
#undef ABSORBED
#undef ABSORB
#undef ABSORB0
/* *****************************************************************************
* instrument 'PSI_CAMEA' and components SAVE
***************************************************************************** */

_class_Progress_bar *class_Progress_bar_save(_class_Progress_bar *_comp
) {
  #define profile (_comp->_parameters.profile)
  #define percent (_comp->_parameters.percent)
  #define flag_save (_comp->_parameters.flag_save)
  #define minutes (_comp->_parameters.minutes)
  #define IntermediateCnts (_comp->_parameters.IntermediateCnts)
  #define StartTime (_comp->_parameters.StartTime)
  #define EndTime (_comp->_parameters.EndTime)
  #define CurrentTime (_comp->_parameters.CurrentTime)
  #define infostring (_comp->_parameters.infostring)
  SIG_MESSAGE("[_Origin_save] component Origin=Progress_bar() SAVE [Progress_bar:0]");

  MPI_MASTER (fprintf (stdout, "\nSave [%s]\n", instrument_name););
  if (profile && strlen (profile) && strcmp (profile, "NULL") && strcmp (profile, "0")) {
    char filename[256];
    if (!strlen (profile) || !strcmp (profile, "NULL") || !strcmp (profile, "0"))
      strcpy (filename, instrument_name);
    else
      strcpy (filename, profile);
    DETECTOR_OUT_1D ("Intensity profiler", "Component index [1]", "Intensity", "prof", 1, mcNUMCOMP, mcNUMCOMP - 1, &(instrument->counter_N[1]),
                     &(instrument->counter_P[1]), &(instrument->counter_P2[1]), filename);
  }
  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  #undef infostring
  return(_comp);
} /* class_Progress_bar_save */

_class_PSD_monitor *class_PSD_monitor_save(_class_PSD_monitor *_comp
) {
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_StartOfGuideMonitor_save] component StartOfGuideMonitor=PSD_monitor() SAVE [PSD_monitor:0]");

  if (!nowritefile) {
    DETECTOR_OUT_2D ("PSD monitor", "X position [cm]", "Y position [cm]", xmin * 100.0, xmax * 100.0, ymin * 100.0, ymax * 100.0, nx, ny, &PSD_N[0][0],
                     &PSD_p[0][0], &PSD_p2[0][0], filename);
  }
  #undef nx
  #undef ny
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef restore_neutron
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_save */

_class_Cyl_monitor_PSD *class_Cyl_monitor_PSD_save(_class_Cyl_monitor_PSD *_comp
) {
  #define nr (_comp->_parameters.nr)
  #define filename (_comp->_parameters.filename)
  #define yheight (_comp->_parameters.yheight)
  #define radius (_comp->_parameters.radius)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define thmin (_comp->_parameters.thmin)
  #define thmax (_comp->_parameters.thmax)
  #define ny (_comp->_parameters.ny)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_sample_cylinder_monitor_save] component sample_cylinder_monitor=Cyl_monitor_PSD() SAVE [Cyl_monitor_PSD:0]");

  if (!nowritefile) {
    DETECTOR_OUT_2D ("Cylindrical PSD monitor", "radial position [deg]", "y [m]", thmin, thmax, -yheight / 2.0, yheight / 2.0, nr, ny, &PSD_N[0][0], &PSD_p[0][0],
                     &PSD_p2[0][0], filename);
  }
  #undef nr
  #undef filename
  #undef yheight
  #undef radius
  #undef restore_neutron
  #undef thmin
  #undef thmax
  #undef ny
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_Cyl_monitor_PSD_save */

_class_PSD_monitor_4PI *class_PSD_monitor_4PI_save(_class_PSD_monitor_4PI *_comp
) {
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define radius (_comp->_parameters.radius)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_sample_spherical_monitor_save] component sample_spherical_monitor=PSD_monitor_4PI() SAVE [PSD_monitor_4PI:0]");

  if (!nowritefile) {
    DETECTOR_OUT_2D ("4PI PSD monitor", "Longitude [deg]", "Latitude [deg]", -180, 180, -90, 90, nx, ny, &PSD_N[0][0], &PSD_p[0][0], &PSD_p2[0][0], filename);
  }
  #undef nx
  #undef ny
  #undef filename
  #undef nowritefile
  #undef radius
  #undef restore_neutron
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_4PI_save */



int save(FILE *handle) { /* called by mccode_main for PSI_CAMEA:SAVE */
  if (!handle) siminfo_init(NULL);

  /* call iteratively all components SAVE */
  class_Progress_bar_save(&_Origin_var);


  class_PSD_monitor_save(&_StartOfGuideMonitor_var);



  class_PSD_monitor_save(&_EndOfInsertPSD_var);



  class_PSD_monitor_save(&_E2PSD_var);




  class_PSD_monitor_save(&_C1End_var);


  class_PSD_monitor_save(&_E3aEnd_var);


  class_PSD_monitor_save(&_E3bEnd_var);






  class_PSD_monitor_save(&_SlitMonitor_var);











  class_PSD_monitor_save(&_sample_flux_before_var);






  class_PSD_monitor_save(&_sample_flux_after_unscattered_var);

  class_Cyl_monitor_PSD_save(&_sample_cylinder_monitor_var);

  class_PSD_monitor_4PI_save(&_sample_spherical_monitor_var);

  class_PSD_monitor_save(&_BackEndMonitor_var);




  if (!handle) siminfo_close(); 

  return(0);
} /* save */

/* *****************************************************************************
* instrument 'PSI_CAMEA' and components FINALLY
***************************************************************************** */

_class_Progress_bar *class_Progress_bar_finally(_class_Progress_bar *_comp
) {
  #define profile (_comp->_parameters.profile)
  #define percent (_comp->_parameters.percent)
  #define flag_save (_comp->_parameters.flag_save)
  #define minutes (_comp->_parameters.minutes)
  #define IntermediateCnts (_comp->_parameters.IntermediateCnts)
  #define StartTime (_comp->_parameters.StartTime)
  #define EndTime (_comp->_parameters.EndTime)
  #define CurrentTime (_comp->_parameters.CurrentTime)
  #define infostring (_comp->_parameters.infostring)
  SIG_MESSAGE("[_Origin_finally] component Origin=Progress_bar() FINALLY [Progress_bar:0]");

  time_t NowTime;
  time (&NowTime);
  fprintf (stdout, "\nFinally [%s: %s]. Time: ", instrument_name, dirname ? dirname : ".");
  if (difftime (NowTime, StartTime) < 60.0)
    fprintf (stdout, "%g [s] ", difftime (NowTime, StartTime));
  else if (difftime (NowTime, StartTime) > 3600.0)
    fprintf (stdout, "%g [h] ", difftime (NowTime, StartTime) / 3600.0);
  else
    fprintf (stdout, "%g [min] ", difftime (NowTime, StartTime) / 60.0);
  fprintf (stdout, "\n");
  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  #undef infostring
  return(_comp);
} /* class_Progress_bar_finally */

_class_Source_gen4 *class_Source_gen4_finally(_class_Source_gen4 *_comp
) {
  #define flux_file (_comp->_parameters.flux_file)
  #define xdiv_file (_comp->_parameters.xdiv_file)
  #define ydiv_file (_comp->_parameters.ydiv_file)
  #define radius (_comp->_parameters.radius)
  #define dist (_comp->_parameters.dist)
  #define xw (_comp->_parameters.xw)
  #define yh (_comp->_parameters.yh)
  #define E0 (_comp->_parameters.E0)
  #define dE (_comp->_parameters.dE)
  #define Lambda0 (_comp->_parameters.Lambda0)
  #define dLambda (_comp->_parameters.dLambda)
  #define I1 (_comp->_parameters.I1)
  #define h (_comp->_parameters.h)
  #define w (_comp->_parameters.w)
  #define gaussian (_comp->_parameters.gaussian)
  #define verbose (_comp->_parameters.verbose)
  #define T1 (_comp->_parameters.T1)
  #define flux_file_perAA (_comp->_parameters.flux_file_perAA)
  #define flux_file_log (_comp->_parameters.flux_file_log)
  #define Lmin (_comp->_parameters.Lmin)
  #define Lmax (_comp->_parameters.Lmax)
  #define Emin (_comp->_parameters.Emin)
  #define Emax (_comp->_parameters.Emax)
  #define T2 (_comp->_parameters.T2)
  #define I2 (_comp->_parameters.I2)
  #define T3 (_comp->_parameters.T3)
  #define I3 (_comp->_parameters.I3)
  #define length (_comp->_parameters.length)
  #define phi_init (_comp->_parameters.phi_init)
  #define theta_init (_comp->_parameters.theta_init)
  #define HEtailA (_comp->_parameters.HEtailA)
  #define HEtailL0 (_comp->_parameters.HEtailL0)
  #define pTable (_comp->_parameters.pTable)
  #define pTable_x (_comp->_parameters.pTable_x)
  #define pTable_y (_comp->_parameters.pTable_y)
  #define p_in (_comp->_parameters.p_in)
  #define lambda0 (_comp->_parameters.lambda0)
  #define lambda02 (_comp->_parameters.lambda02)
  #define lambda0b (_comp->_parameters.lambda0b)
  #define lambda02b (_comp->_parameters.lambda02b)
  #define lambda0c (_comp->_parameters.lambda0c)
  #define lambda02c (_comp->_parameters.lambda02c)
  #define L2P (_comp->_parameters.L2P)
  #define L2Pb (_comp->_parameters.L2Pb)
  #define L2Pc (_comp->_parameters.L2Pc)
  #define pTable_xmin (_comp->_parameters.pTable_xmin)
  #define pTable_ymin (_comp->_parameters.pTable_ymin)
  #define pTable_xmax (_comp->_parameters.pTable_xmax)
  #define pTable_ymax (_comp->_parameters.pTable_ymax)
  #define pTable_xsum (_comp->_parameters.pTable_xsum)
  #define pTable_ysum (_comp->_parameters.pTable_ysum)
  #define pTable_dxmin (_comp->_parameters.pTable_dxmin)
  #define pTable_dxmax (_comp->_parameters.pTable_dxmax)
  #define pTable_dymin (_comp->_parameters.pTable_dymin)
  #define pTable_dymax (_comp->_parameters.pTable_dymax)
  SIG_MESSAGE("[_source_finally] component source=Source_gen4() FINALLY [Source_gen4:0]");

  Table_Free (&pTable);
  Table_Free (&pTable_x);
  Table_Free (&pTable_y);
  #undef flux_file
  #undef xdiv_file
  #undef ydiv_file
  #undef radius
  #undef dist
  #undef xw
  #undef yh
  #undef E0
  #undef dE
  #undef Lambda0
  #undef dLambda
  #undef I1
  #undef h
  #undef w
  #undef gaussian
  #undef verbose
  #undef T1
  #undef flux_file_perAA
  #undef flux_file_log
  #undef Lmin
  #undef Lmax
  #undef Emin
  #undef Emax
  #undef T2
  #undef I2
  #undef T3
  #undef I3
  #undef length
  #undef phi_init
  #undef theta_init
  #undef HEtailA
  #undef HEtailL0
  #undef pTable
  #undef pTable_x
  #undef pTable_y
  #undef p_in
  #undef lambda0
  #undef lambda02
  #undef lambda0b
  #undef lambda02b
  #undef lambda0c
  #undef lambda02c
  #undef L2P
  #undef L2Pb
  #undef L2Pc
  #undef pTable_xmin
  #undef pTable_ymin
  #undef pTable_xmax
  #undef pTable_ymax
  #undef pTable_xsum
  #undef pTable_ysum
  #undef pTable_dxmin
  #undef pTable_dxmax
  #undef pTable_dymin
  #undef pTable_dymax
  return(_comp);
} /* class_Source_gen4_finally */

_class_PSD_monitor *class_PSD_monitor_finally(_class_PSD_monitor *_comp
) {
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_StartOfGuideMonitor_finally] component StartOfGuideMonitor=PSD_monitor() FINALLY [PSD_monitor:0]");

  destroy_darr2d(PSD_N);
  destroy_darr2d(PSD_p);
  destroy_darr2d(PSD_p2);
  #undef nx
  #undef ny
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef restore_neutron
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_finally */

_class_Monochromator_curved *class_Monochromator_curved_finally(_class_Monochromator_curved *_comp
) {
  #define reflect (_comp->_parameters.reflect)
  #define transmit (_comp->_parameters.transmit)
  #define zwidth (_comp->_parameters.zwidth)
  #define yheight (_comp->_parameters.yheight)
  #define gap (_comp->_parameters.gap)
  #define NH (_comp->_parameters.NH)
  #define NV (_comp->_parameters.NV)
  #define mosaich (_comp->_parameters.mosaich)
  #define mosaicv (_comp->_parameters.mosaicv)
  #define r0 (_comp->_parameters.r0)
  #define t0 (_comp->_parameters.t0)
  #define Q (_comp->_parameters.Q)
  #define RV (_comp->_parameters.RV)
  #define RH (_comp->_parameters.RH)
  #define DM (_comp->_parameters.DM)
  #define mosaic (_comp->_parameters.mosaic)
  #define width (_comp->_parameters.width)
  #define height (_comp->_parameters.height)
  #define verbose (_comp->_parameters.verbose)
  #define order (_comp->_parameters.order)
  #define mos_rms_y (_comp->_parameters.mos_rms_y)
  #define mos_rms_z (_comp->_parameters.mos_rms_z)
  #define mos_rms_max (_comp->_parameters.mos_rms_max)
  #define mono_Q (_comp->_parameters.mono_Q)
  #define SlabWidth (_comp->_parameters.SlabWidth)
  #define SlabHeight (_comp->_parameters.SlabHeight)
  #define rTable (_comp->_parameters.rTable)
  #define tTable (_comp->_parameters.tTable)
  #define rTableFlag (_comp->_parameters.rTableFlag)
  #define tTableFlag (_comp->_parameters.tTableFlag)
  #define tiltH (_comp->_parameters.tiltH)
  #define tiltV (_comp->_parameters.tiltV)
  #define ncol_var (_comp->_parameters.ncol_var)
  #define nrow_var (_comp->_parameters.nrow_var)
  SIG_MESSAGE("[_Mono_finally] component Mono=Monochromator_curved() FINALLY [Monochromator_curved:0]");

  if (rTableFlag) {
    Table_Free (&rTable);
  }
  if (tTableFlag) {
    Table_Free (&tTable);
  }
  if (tiltH)
    free (tiltH);
  if (tiltV)
    free (tiltV);
  #undef reflect
  #undef transmit
  #undef zwidth
  #undef yheight
  #undef gap
  #undef NH
  #undef NV
  #undef mosaich
  #undef mosaicv
  #undef r0
  #undef t0
  #undef Q
  #undef RV
  #undef RH
  #undef DM
  #undef mosaic
  #undef width
  #undef height
  #undef verbose
  #undef order
  #undef mos_rms_y
  #undef mos_rms_z
  #undef mos_rms_max
  #undef mono_Q
  #undef SlabWidth
  #undef SlabHeight
  #undef rTable
  #undef tTable
  #undef rTableFlag
  #undef tTableFlag
  #undef tiltH
  #undef tiltV
  #undef ncol_var
  #undef nrow_var
  return(_comp);
} /* class_Monochromator_curved_finally */

_class_Phonon_simple *class_Phonon_simple_finally(_class_Phonon_simple *_comp
) {
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define a (_comp->_parameters.a)
  #define b (_comp->_parameters.b)
  #define M (_comp->_parameters.M)
  #define c (_comp->_parameters.c)
  #define DW (_comp->_parameters.DW)
  #define T (_comp->_parameters.T)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define target_index (_comp->_parameters.target_index)
  #define focus_r (_comp->_parameters.focus_r)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define gap (_comp->_parameters.gap)
  #define e_steps_low (_comp->_parameters.e_steps_low)
  #define e_steps_high (_comp->_parameters.e_steps_high)
  #define V_rho (_comp->_parameters.V_rho)
  #define V_my_s (_comp->_parameters.V_my_s)
  #define V_my_a_v (_comp->_parameters.V_my_a_v)
  #define DV (_comp->_parameters.DV)
  #define phonon (_comp->_parameters.phonon)
  SIG_MESSAGE("[_sample_finally] component sample=Phonon_simple() FINALLY [Phonon_simple:0]");



  #undef radius
  #undef yheight
  #undef sigma_abs
  #undef sigma_inc
  #undef a
  #undef b
  #undef M
  #undef c
  #undef DW
  #undef T
  #undef target_x
  #undef target_y
  #undef target_z
  #undef target_index
  #undef focus_r
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef gap
  #undef e_steps_low
  #undef e_steps_high
  #undef V_rho
  #undef V_my_s
  #undef V_my_a_v
  #undef DV
  #undef phonon
  return(_comp);
} /* class_Phonon_simple_finally */

_class_Cyl_monitor_PSD *class_Cyl_monitor_PSD_finally(_class_Cyl_monitor_PSD *_comp
) {
  #define nr (_comp->_parameters.nr)
  #define filename (_comp->_parameters.filename)
  #define yheight (_comp->_parameters.yheight)
  #define radius (_comp->_parameters.radius)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define thmin (_comp->_parameters.thmin)
  #define thmax (_comp->_parameters.thmax)
  #define ny (_comp->_parameters.ny)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_sample_cylinder_monitor_finally] component sample_cylinder_monitor=Cyl_monitor_PSD() FINALLY [Cyl_monitor_PSD:0]");

  destroy_darr2d (PSD_N);
  destroy_darr2d (PSD_p);
  destroy_darr2d (PSD_p2);
  #undef nr
  #undef filename
  #undef yheight
  #undef radius
  #undef restore_neutron
  #undef thmin
  #undef thmax
  #undef ny
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_Cyl_monitor_PSD_finally */

_class_PSD_monitor_4PI *class_PSD_monitor_4PI_finally(_class_PSD_monitor_4PI *_comp
) {
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define radius (_comp->_parameters.radius)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_sample_spherical_monitor_finally] component sample_spherical_monitor=PSD_monitor_4PI() FINALLY [PSD_monitor_4PI:0]");

  destroy_darr2d (PSD_N);
  destroy_darr2d (PSD_p);
  destroy_darr2d (PSD_p2);
  #undef nx
  #undef ny
  #undef filename
  #undef nowritefile
  #undef radius
  #undef restore_neutron
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_4PI_finally */

_class_Filter_gen *class_Filter_gen_finally(_class_Filter_gen *_comp
) {
  #define filename (_comp->_parameters.filename)
  #define options (_comp->_parameters.options)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define thickness (_comp->_parameters.thickness)
  #define scaling (_comp->_parameters.scaling)
  #define verbose (_comp->_parameters.verbose)
  #define Mode_Table (_comp->_parameters.Mode_Table)
  #define Type_Table (_comp->_parameters.Type_Table)
  #define pTable (_comp->_parameters.pTable)
  SIG_MESSAGE("[_filter_gen_finally] component filter_gen=Filter_gen() FINALLY [Filter_gen:0]");

  Table_Free (&pTable);
  #undef filename
  #undef options
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef thickness
  #undef scaling
  #undef verbose
  #undef Mode_Table
  #undef Type_Table
  #undef pTable
  return(_comp);
} /* class_Filter_gen_finally */

_class_PowderN *class_PowderN_finally(_class_PowderN *_comp
) {
  #define reflections (_comp->_parameters.reflections)
  #define geometry (_comp->_parameters.geometry)
  #define format (_comp->_parameters.format)
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define xwidth (_comp->_parameters.xwidth)
  #define zdepth (_comp->_parameters.zdepth)
  #define thickness (_comp->_parameters.thickness)
  #define pack (_comp->_parameters.pack)
  #define Vc (_comp->_parameters.Vc)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define delta_d_d (_comp->_parameters.delta_d_d)
  #define p_inc (_comp->_parameters.p_inc)
  #define p_transmit (_comp->_parameters.p_transmit)
  #define DW (_comp->_parameters.DW)
  #define nb_atoms (_comp->_parameters.nb_atoms)
  #define d_omega (_comp->_parameters.d_omega)
  #define d_phi (_comp->_parameters.d_phi)
  #define tth_sign (_comp->_parameters.tth_sign)
  #define p_interact (_comp->_parameters.p_interact)
  #define concentric (_comp->_parameters.concentric)
  #define density (_comp->_parameters.density)
  #define weight (_comp->_parameters.weight)
  #define barns (_comp->_parameters.barns)
  #define Strain (_comp->_parameters.Strain)
  #define focus_flip (_comp->_parameters.focus_flip)
  #define target_index (_comp->_parameters.target_index)
  #define order (_comp->_parameters.order)
  #define line_info (_comp->_parameters.line_info)
  #define columns (_comp->_parameters.columns)
  #define offdata (_comp->_parameters.offdata)
  #define tgt_x (_comp->_parameters.tgt_x)
  #define tgt_y (_comp->_parameters.tgt_y)
  #define tgt_z (_comp->_parameters.tgt_z)
  SIG_MESSAGE("[_BeFilter_finally] component BeFilter=PowderN() FINALLY [PowderN:0]");

  free (line_info.list);
  free (line_info.q_v);
  free (line_info.w_v);
  free (line_info.my_s_v2);
  MPI_MASTER (if (line_info.flag_warning)
                  printf ("PowderN: %s: Error messages were repeated %i times with absorbed neutrons.\n", NAME_CURRENT_COMP, line_info.flag_warning);

              /* in case this instance is used in a SPLIT, we can recommend the
                 optimal iteration value */
              if (line_info.nb_refl_count) {
                double split_iterations = (double)line_info.nb_reuses / line_info.nb_refl_count + 1;
                double split_optimal = (double)line_info.nb_refl / line_info.nb_refl_count;
                if (split_optimal > split_iterations + 5)
                  printf ("PowderN: %s: Info: you may highly improve the computation efficiency by using\n"
                          "    SPLIT %i COMPONENT %s=PowderN(...)\n"
                          "  in the instrument description %s.\n",
                          NAME_CURRENT_COMP, (int)split_optimal, NAME_CURRENT_COMP, instrument_source);
              });
  #undef reflections
  #undef geometry
  #undef format
  #undef radius
  #undef yheight
  #undef xwidth
  #undef zdepth
  #undef thickness
  #undef pack
  #undef Vc
  #undef sigma_abs
  #undef sigma_inc
  #undef delta_d_d
  #undef p_inc
  #undef p_transmit
  #undef DW
  #undef nb_atoms
  #undef d_omega
  #undef d_phi
  #undef tth_sign
  #undef p_interact
  #undef concentric
  #undef density
  #undef weight
  #undef barns
  #undef Strain
  #undef focus_flip
  #undef target_index
  #undef order
  #undef line_info
  #undef columns
  #undef offdata
  #undef tgt_x
  #undef tgt_y
  #undef tgt_z
  return(_comp);
} /* class_PowderN_finally */



int finally(void) { /* called by mccode_main for PSI_CAMEA:FINALLY */
#pragma acc update host(_Origin_var)
#pragma acc update host(_source_var)
#pragma acc update host(_StartOfGuideMonitor_var)
#pragma acc update host(_StartOfGuide_var)
#pragma acc update host(_Insert_var)
#pragma acc update host(_EndOfInsertPSD_var)
#pragma acc update host(_E2_var)
#pragma acc update host(_EndOfelement_5_var)
#pragma acc update host(_E2PSD_var)
#pragma acc update host(_EndOfelement_4_var)
#pragma acc update host(_C1_var)
#pragma acc update host(_EndOfelement_2_var)
#pragma acc update host(_C1End_var)
#pragma acc update host(_E3a_var)
#pragma acc update host(_E3aEnd_var)
#pragma acc update host(_E3b_var)
#pragma acc update host(_E3bEnd_var)
#pragma acc update host(_SlitGuideEnd_var)
#pragma acc update host(_Mono_var)
#pragma acc update host(_A2_var)
#pragma acc update host(_monochromatorShielding_var)
#pragma acc update host(_slit_var)
#pragma acc update host(_SlitMonitor_var)
#pragma acc update host(_SamplePos_var)
#pragma acc update host(_AMidt_var)
#pragma acc update host(_a41_var)
#pragma acc update host(_a42_var)
#pragma acc update host(_a43_var)
#pragma acc update host(_a44_var)
#pragma acc update host(_a45_var)
#pragma acc update host(_a46_var)
#pragma acc update host(_a47_var)
#pragma acc update host(_a48_var)
#pragma acc update host(_sample_flux_before_var)
#pragma acc update host(_sample_scatter_state_reset_var)
#pragma acc update host(_VanSample_var)
#pragma acc update host(_sample_var)
#pragma acc update host(_powder1_var)
#pragma acc update host(_res_sample_var)
#pragma acc update host(_sample_flux_after_unscattered_var)
#pragma acc update host(_sample_cylinder_monitor_var)
#pragma acc update host(_sample_spherical_monitor_var)
#pragma acc update host(_BackEndMonitor_var)
#pragma acc update host(_slitBackEnd_var)
#pragma acc update host(_filter_gen_var)
#pragma acc update host(_BeFilter_var)
#pragma acc update host(_instrument_var)

  siminfo_init(NULL);
  save(siminfo_file); /* save data when simulation ends */

  /* call iteratively all components FINALLY */
  class_Progress_bar_finally(&_Origin_var);

  class_Source_gen4_finally(&_source_var);

  class_PSD_monitor_finally(&_StartOfGuideMonitor_var);



  class_PSD_monitor_finally(&_EndOfInsertPSD_var);



  class_PSD_monitor_finally(&_E2PSD_var);




  class_PSD_monitor_finally(&_C1End_var);


  class_PSD_monitor_finally(&_E3aEnd_var);


  class_PSD_monitor_finally(&_E3bEnd_var);


  class_Monochromator_curved_finally(&_Mono_var);




  class_PSD_monitor_finally(&_SlitMonitor_var);











  class_PSD_monitor_finally(&_sample_flux_before_var);



  class_Phonon_simple_finally(&_sample_var);



  class_PSD_monitor_finally(&_sample_flux_after_unscattered_var);

  class_Cyl_monitor_PSD_finally(&_sample_cylinder_monitor_var);

  class_PSD_monitor_4PI_finally(&_sample_spherical_monitor_var);

  class_PSD_monitor_finally(&_BackEndMonitor_var);


  class_Filter_gen_finally(&_filter_gen_var);

  class_PowderN_finally(&_BeFilter_var);

  siminfo_close(); 

  return(0);
} /* finally */

/* *****************************************************************************
* instrument 'PSI_CAMEA' and components DISPLAY
***************************************************************************** */

  #define magnify     mcdis_magnify
  #define line        mcdis_line
  #define dashed_line mcdis_dashed_line
  #define multiline   mcdis_multiline
  #define rectangle   mcdis_rectangle
  #define box         mcdis_box
  #define circle      mcdis_circle
  #define cylinder    mcdis_cylinder
  #define sphere      mcdis_sphere
  #define cone        mcdis_cone
  #define polygon     mcdis_polygon
  #define polyhedron  mcdis_polyhedron
_class_Progress_bar *class_Progress_bar_display(_class_Progress_bar *_comp
) {
  #define profile (_comp->_parameters.profile)
  #define percent (_comp->_parameters.percent)
  #define flag_save (_comp->_parameters.flag_save)
  #define minutes (_comp->_parameters.minutes)
  #define IntermediateCnts (_comp->_parameters.IntermediateCnts)
  #define StartTime (_comp->_parameters.StartTime)
  #define EndTime (_comp->_parameters.EndTime)
  #define CurrentTime (_comp->_parameters.CurrentTime)
  #define infostring (_comp->_parameters.infostring)
  SIG_MESSAGE("[_Origin_display] component Origin=Progress_bar() DISPLAY [Progress_bar:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  #undef infostring
  return(_comp);
} /* class_Progress_bar_display */

_class_Source_gen4 *class_Source_gen4_display(_class_Source_gen4 *_comp
) {
  #define flux_file (_comp->_parameters.flux_file)
  #define xdiv_file (_comp->_parameters.xdiv_file)
  #define ydiv_file (_comp->_parameters.ydiv_file)
  #define radius (_comp->_parameters.radius)
  #define dist (_comp->_parameters.dist)
  #define xw (_comp->_parameters.xw)
  #define yh (_comp->_parameters.yh)
  #define E0 (_comp->_parameters.E0)
  #define dE (_comp->_parameters.dE)
  #define Lambda0 (_comp->_parameters.Lambda0)
  #define dLambda (_comp->_parameters.dLambda)
  #define I1 (_comp->_parameters.I1)
  #define h (_comp->_parameters.h)
  #define w (_comp->_parameters.w)
  #define gaussian (_comp->_parameters.gaussian)
  #define verbose (_comp->_parameters.verbose)
  #define T1 (_comp->_parameters.T1)
  #define flux_file_perAA (_comp->_parameters.flux_file_perAA)
  #define flux_file_log (_comp->_parameters.flux_file_log)
  #define Lmin (_comp->_parameters.Lmin)
  #define Lmax (_comp->_parameters.Lmax)
  #define Emin (_comp->_parameters.Emin)
  #define Emax (_comp->_parameters.Emax)
  #define T2 (_comp->_parameters.T2)
  #define I2 (_comp->_parameters.I2)
  #define T3 (_comp->_parameters.T3)
  #define I3 (_comp->_parameters.I3)
  #define length (_comp->_parameters.length)
  #define phi_init (_comp->_parameters.phi_init)
  #define theta_init (_comp->_parameters.theta_init)
  #define HEtailA (_comp->_parameters.HEtailA)
  #define HEtailL0 (_comp->_parameters.HEtailL0)
  #define pTable (_comp->_parameters.pTable)
  #define pTable_x (_comp->_parameters.pTable_x)
  #define pTable_y (_comp->_parameters.pTable_y)
  #define p_in (_comp->_parameters.p_in)
  #define lambda0 (_comp->_parameters.lambda0)
  #define lambda02 (_comp->_parameters.lambda02)
  #define lambda0b (_comp->_parameters.lambda0b)
  #define lambda02b (_comp->_parameters.lambda02b)
  #define lambda0c (_comp->_parameters.lambda0c)
  #define lambda02c (_comp->_parameters.lambda02c)
  #define L2P (_comp->_parameters.L2P)
  #define L2Pb (_comp->_parameters.L2Pb)
  #define L2Pc (_comp->_parameters.L2Pc)
  #define pTable_xmin (_comp->_parameters.pTable_xmin)
  #define pTable_ymin (_comp->_parameters.pTable_ymin)
  #define pTable_xmax (_comp->_parameters.pTable_xmax)
  #define pTable_ymax (_comp->_parameters.pTable_ymax)
  #define pTable_xsum (_comp->_parameters.pTable_xsum)
  #define pTable_ysum (_comp->_parameters.pTable_ysum)
  #define pTable_dxmin (_comp->_parameters.pTable_dxmin)
  #define pTable_dxmax (_comp->_parameters.pTable_dxmax)
  #define pTable_dymin (_comp->_parameters.pTable_dymin)
  #define pTable_dymax (_comp->_parameters.pTable_dymax)
  SIG_MESSAGE("[_source_display] component source=Source_gen4() DISPLAY [Source_gen4:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  double xmin;
  double xmax;
  double ymin;
  double ymax;

  if ((h == 0) || (w == 0)) {

    circle ("xy", 0, 0, 0, radius);
    if (gaussian)
      circle ("xy", 0, 0, 0, radius / 2);
  } else {
    xmin = -w / 2;
    xmax = w / 2;
    ymin = -h / 2;
    ymax = h / 2;

    multiline (5, (double)xmin, (double)ymin, 0.0, (double)xmax, (double)ymin, 0.0, (double)xmax, (double)ymax, 0.0, (double)xmin, (double)ymax, 0.0,
               (double)xmin, (double)ymin, 0.0);
    if (gaussian)
      circle ("xy", 0, 0, 0, sqrt (w * w + h * h) / 4);
  }
  #undef flux_file
  #undef xdiv_file
  #undef ydiv_file
  #undef radius
  #undef dist
  #undef xw
  #undef yh
  #undef E0
  #undef dE
  #undef Lambda0
  #undef dLambda
  #undef I1
  #undef h
  #undef w
  #undef gaussian
  #undef verbose
  #undef T1
  #undef flux_file_perAA
  #undef flux_file_log
  #undef Lmin
  #undef Lmax
  #undef Emin
  #undef Emax
  #undef T2
  #undef I2
  #undef T3
  #undef I3
  #undef length
  #undef phi_init
  #undef theta_init
  #undef HEtailA
  #undef HEtailL0
  #undef pTable
  #undef pTable_x
  #undef pTable_y
  #undef p_in
  #undef lambda0
  #undef lambda02
  #undef lambda0b
  #undef lambda02b
  #undef lambda0c
  #undef lambda02c
  #undef L2P
  #undef L2Pb
  #undef L2Pc
  #undef pTable_xmin
  #undef pTable_ymin
  #undef pTable_xmax
  #undef pTable_ymax
  #undef pTable_xsum
  #undef pTable_ysum
  #undef pTable_dxmin
  #undef pTable_dxmax
  #undef pTable_dymin
  #undef pTable_dymax
  return(_comp);
} /* class_Source_gen4_display */

_class_PSD_monitor *class_PSD_monitor_display(_class_PSD_monitor *_comp
) {
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_StartOfGuideMonitor_display] component StartOfGuideMonitor=PSD_monitor() DISPLAY [PSD_monitor:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  multiline (5, (double)xmin, (double)ymin, 0.0, (double)xmax, (double)ymin, 0.0, (double)xmax, (double)ymax, 0.0, (double)xmin, (double)ymax, 0.0, (double)xmin,
             (double)ymin, 0.0);
  #undef nx
  #undef ny
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef restore_neutron
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_display */

_class_Arm *class_Arm_display(_class_Arm *_comp
) {
  SIG_MESSAGE("[_StartOfGuide_display] component StartOfGuide=Arm() DISPLAY [Arm:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  /* A bit ugly; hard-coded dimensions. */

  line (0, 0, 0, 0.2, 0, 0);
  line (0, 0, 0, 0, 0.2, 0);
  line (0, 0, 0, 0, 0, 0.2);

  cone (0.2, 0, 0, 0.01, 0.02, 1, 0, 0);
  cone (0, 0.2, 0, 0.01, 0.02, 0, 1, 0);
  cone (0, 0, 0.2, 0.01, 0.02, 0, 0, 1);
  return(_comp);
} /* class_Arm_display */

_class_Elliptic_guide_gravity *class_Elliptic_guide_gravity_display(_class_Elliptic_guide_gravity *_comp
) {
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define l (_comp->_parameters.l)
  #define linxw (_comp->_parameters.linxw)
  #define loutxw (_comp->_parameters.loutxw)
  #define linyh (_comp->_parameters.linyh)
  #define loutyh (_comp->_parameters.loutyh)
  #define majorAxisxw (_comp->_parameters.majorAxisxw)
  #define minorAxisxw (_comp->_parameters.minorAxisxw)
  #define majorAxisyh (_comp->_parameters.majorAxisyh)
  #define minorAxisyh (_comp->_parameters.minorAxisyh)
  #define majorAxisoffsetxw (_comp->_parameters.majorAxisoffsetxw)
  #define majorAxisoffsetyh (_comp->_parameters.majorAxisoffsetyh)
  #define dimensionsAt (_comp->_parameters.dimensionsAt)
  #define option (_comp->_parameters.option)
  #define R0 (_comp->_parameters.R0)
  #define Qc (_comp->_parameters.Qc)
  #define alpha (_comp->_parameters.alpha)
  #define m (_comp->_parameters.m)
  #define W (_comp->_parameters.W)
  #define alpharight (_comp->_parameters.alpharight)
  #define mright (_comp->_parameters.mright)
  #define alphaleft (_comp->_parameters.alphaleft)
  #define mleft (_comp->_parameters.mleft)
  #define alphatop (_comp->_parameters.alphatop)
  #define mtop (_comp->_parameters.mtop)
  #define alphabottom (_comp->_parameters.alphabottom)
  #define mbottom (_comp->_parameters.mbottom)
  #define verbose (_comp->_parameters.verbose)
  #define enableGravity (_comp->_parameters.enableGravity)
  #define curvature (_comp->_parameters.curvature)
  #define nSegments (_comp->_parameters.nSegments)
  #define mvaluesright (_comp->_parameters.mvaluesright)
  #define mvaluesleft (_comp->_parameters.mvaluesleft)
  #define mvaluestop (_comp->_parameters.mvaluestop)
  #define mvaluesbottom (_comp->_parameters.mvaluesbottom)
  #define seglength (_comp->_parameters.seglength)
  #define guideInfo (_comp->_parameters.guideInfo)
  #define Gx0 (_comp->_parameters.Gx0)
  #define Gy0 (_comp->_parameters.Gy0)
  #define Gz0 (_comp->_parameters.Gz0)
  #define Circ (_comp->_parameters.Circ)
  #define dynamicalSegLength (_comp->_parameters.dynamicalSegLength)
  SIG_MESSAGE("[_Insert_display] component Insert=Elliptic_guide_gravity() DISPLAY [Elliptic_guide_gravity:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);


  // Calculate the points need to draw approximation of the ellipses
  // defining the guide

  // the number of lines used to draw one side of the guide
  int ApproximationMirrors = 500;

  // The start of the guide
  double zvalue = 0;

  // The the different in z between point used to draw the ellipse
  double zdelta = guideInfo.Length / (1.0 * ApproximationMirrors);

  // The vector used to store the points defining the lines
  double* xplus = malloc ((ApproximationMirrors + 1) * sizeof (double));
  double* xminus = malloc ((ApproximationMirrors + 1) * sizeof (double));
  double* yplus = malloc ((ApproximationMirrors + 1) * sizeof (double));
  double* yminus = malloc ((ApproximationMirrors + 1) * sizeof (double));

  if (!xplus || !xminus || !yplus || !yminus) {
    fprintf (stderr, "Elliptic_guide_gravity %s: ERROR allocating visualisation arrays. Exit!\n", NAME_CURRENT_COMP);
    exit (-1);
  }

  // Temperary values for the loop
  double tempx;
  double tempy;

  /*
          Calculate the second coordinates to the points on the ellipse with z_i
          as the first coordinate. We transform the point to the coordinate system
          there the ellipse is a unit circle. And use the defination of this circle
          to find second coordinate (x^2+z^2 = 1)
  */

  /////////////////////////////////////////////////////////
  double Length;
  double entranceHorizontalWidth;
  double entranceVerticalWidth;

  // ellipses infomation
  double ellipseMajorAxis[4], ellipseMinorAxis[4];
  double ellipseMajorOffset[4], ellipseMinorOffset[4];

  enum Side { RightSide, TopSide, LeftSide, BottomSide, None };
  /////////////////////////////////////////////////////////

  int i = 0;
  double tempz = 0;
  for (i = 0; i < ApproximationMirrors + 1; i++) {

    tempx = sqrt (guideInfo.ellipseMinorAxis[RightSide] * guideInfo.ellipseMinorAxis[RightSide]
                  - (guideInfo.ellipseMinorAxis[RightSide] * guideInfo.ellipseMinorAxis[RightSide])
                        / (guideInfo.ellipseMajorAxis[RightSide] * guideInfo.ellipseMajorAxis[RightSide])
                        * (zvalue + zdelta * i - guideInfo.ellipseMajorOffset[RightSide]) * (zvalue + zdelta * i - guideInfo.ellipseMajorOffset[RightSide]));

    xplus[i] = tempx + guideInfo.ellipseMinorOffset[RightSide];
    xminus[i] = -tempx + guideInfo.ellipseMinorOffset[RightSide];

    tempy = sqrt (guideInfo.ellipseMinorAxis[TopSide] * guideInfo.ellipseMinorAxis[TopSide]
                  - (guideInfo.ellipseMinorAxis[TopSide] * guideInfo.ellipseMinorAxis[TopSide])
                        / (guideInfo.ellipseMajorAxis[TopSide] * guideInfo.ellipseMajorAxis[TopSide])
                        * (zvalue + zdelta * i - guideInfo.ellipseMajorOffset[TopSide]) * (zvalue + zdelta * i - guideInfo.ellipseMajorOffset[TopSide]));

    yplus[i] = tempy + guideInfo.ellipseMinorOffset[TopSide];
    yminus[i] = -tempy + guideInfo.ellipseMinorOffset[TopSide];
  }

  ///// Draw lines

  // Drawing lines orthogonal with the z direction.
  // at both ends of the guide and at the boardest place at the guide

  // These may not give correct result if one of the ends are closed

  int j = 0;

  line (xplus[j], yplus[j], zvalue + j * zdelta, 0, yplus[j], zvalue + j * zdelta);
  line (0, yplus[j], zvalue + j * zdelta, xminus[j], yplus[j], zvalue + j * zdelta);
  line (xminus[j], yminus[j], zvalue + j * zdelta, 0, yminus[j], zvalue + j * zdelta);
  line (0, yminus[j], zvalue + j * zdelta, xplus[j], yminus[j], zvalue + j * zdelta);
  line (xminus[j], yplus[j], zvalue + j * zdelta, xminus[j], 0, zvalue + j * zdelta);
  line (xminus[j], 0, zvalue + j * zdelta, xminus[j], yminus[j], zvalue + j * zdelta);
  line (xplus[j], 0, zvalue + j * zdelta, xplus[j], yplus[j], zvalue + j * zdelta);
  line (xplus[j], yminus[j], zvalue + j * zdelta, xplus[j], 0, zvalue + j * zdelta);

  j = ApproximationMirrors;

  line (xplus[j], yplus[j], zvalue + j * zdelta, 0, yplus[j], zvalue + j * zdelta);
  line (0, yplus[j], zvalue + j * zdelta, xminus[j], yplus[j], zvalue + j * zdelta);
  line (xminus[j], yminus[j], zvalue + j * zdelta, 0, yminus[j], zvalue + j * zdelta);
  line (0, yminus[j], zvalue + j * zdelta, xplus[j], yminus[j], zvalue + j * zdelta);
  line (xminus[j], yplus[j], zvalue + j * zdelta, xminus[j], 0, zvalue + j * zdelta);
  line (xminus[j], 0, zvalue + j * zdelta, xminus[j], yminus[j], zvalue + j * zdelta);
  line (xplus[j], 0, zvalue + j * zdelta, xplus[j], yplus[j], zvalue + j * zdelta);
  line (xplus[j], yminus[j], zvalue + j * zdelta, xplus[j], 0, zvalue + j * zdelta);

  // find boardest place on the guide and draw a band around the guide
  int m0;
  double boardestPlace = 0;
  int boardestPlaceNumber = 0;
  for (m0 = 0; m0 < ApproximationMirrors; m0++) {
    if (boardestPlace <= fabs (yplus[m0])) {
      boardestPlace = fabs (yplus[m0]);
      boardestPlaceNumber = m0;
    }
  }
  j = boardestPlaceNumber;

  line (xplus[j], yplus[j], zvalue + j * zdelta, 0, yplus[j], zvalue + j * zdelta);
  line (0, yplus[j], zvalue + j * zdelta, xminus[j], yplus[j], zvalue + j * zdelta);
  line (xminus[j], yminus[j], zvalue + j * zdelta, 0, yminus[j], zvalue + j * zdelta);
  line (0, yminus[j], zvalue + j * zdelta, xplus[j], yminus[j], zvalue + j * zdelta);
  line (xminus[j], yplus[j], zvalue + j * zdelta, xminus[j], 0, zvalue + j * zdelta);
  line (xminus[j], 0, zvalue + j * zdelta, xminus[j], yminus[j], zvalue + j * zdelta);
  line (xplus[j], 0, zvalue + j * zdelta, xplus[j], yplus[j], zvalue + j * zdelta);
  line (xplus[j], yminus[j], zvalue + j * zdelta, xplus[j], 0, zvalue + j * zdelta);

  // Drawing lines parallel with the z direction

  int k = 0;
  for (k = 0; k < ApproximationMirrors; k++) {

    line (xplus[k], yplus[k], zvalue + k * zdelta, xplus[k + 1], yplus[k + 1], zvalue + (k + 1) * zdelta);
    line (xminus[k], yplus[k], zvalue + k * zdelta, xminus[k + 1], yplus[k + 1], zvalue + (k + 1) * zdelta);

    line (xplus[k], yminus[k], zvalue + k * zdelta, xplus[k + 1], yminus[k + 1], zvalue + (k + 1) * zdelta);

    line (xminus[k], yminus[k], zvalue + k * zdelta, xminus[k + 1], yminus[k + 1], zvalue + (k + 1) * zdelta);

    line (xminus[k], 0, zvalue + k * zdelta, xminus[k + 1], 0, zvalue + (k + 1) * zdelta);
    line (xplus[k], 0, zvalue + k * zdelta, xplus[k + 1], 0, zvalue + (k + 1) * zdelta);

    line (0, yminus[k], zvalue + k * zdelta, 0, yminus[k + 1], zvalue + (k + 1) * zdelta);
    line (0, yplus[k], zvalue + k * zdelta, 0, yplus[k], zvalue + (k + 1) * zdelta);
  }

  if (guideInfo.EnclosingBoxOn) {
    dashed_line (guideInfo.xArray[0], guideInfo.yArray[0], guideInfo.zArray[0], guideInfo.xArray[1], guideInfo.yArray[1], guideInfo.zArray[1], 10);
    dashed_line (guideInfo.xArray[1], guideInfo.yArray[1], guideInfo.zArray[1], guideInfo.xArray[2], guideInfo.yArray[2], guideInfo.zArray[2], 10);
    dashed_line (guideInfo.xArray[2], guideInfo.yArray[2], guideInfo.zArray[2], guideInfo.xArray[3], guideInfo.yArray[3], guideInfo.zArray[3], 10);
    dashed_line (guideInfo.xArray[3], guideInfo.yArray[3], guideInfo.zArray[3], guideInfo.xArray[0], guideInfo.yArray[0], guideInfo.zArray[0], 10);

    dashed_line (guideInfo.xArray[4], guideInfo.yArray[4], guideInfo.zArray[4], guideInfo.xArray[5], guideInfo.yArray[5], guideInfo.zArray[5], 10);
    dashed_line (guideInfo.xArray[5], guideInfo.yArray[5], guideInfo.zArray[5], guideInfo.xArray[6], guideInfo.yArray[6], guideInfo.zArray[6], 10);
    dashed_line (guideInfo.xArray[6], guideInfo.yArray[6], guideInfo.zArray[6], guideInfo.xArray[7], guideInfo.yArray[7], guideInfo.zArray[7], 10);
    dashed_line (guideInfo.xArray[7], guideInfo.yArray[7], guideInfo.zArray[7], guideInfo.xArray[4], guideInfo.yArray[4], guideInfo.zArray[4], 10);

    dashed_line (guideInfo.xArray[0], guideInfo.yArray[0], guideInfo.zArray[0], guideInfo.xArray[4], guideInfo.yArray[4], guideInfo.zArray[4], 10);
    dashed_line (guideInfo.xArray[4], guideInfo.yArray[4], guideInfo.zArray[4], guideInfo.xArray[7], guideInfo.yArray[7], guideInfo.zArray[7], 10);
    dashed_line (guideInfo.xArray[7], guideInfo.yArray[7], guideInfo.zArray[7], guideInfo.xArray[3], guideInfo.yArray[3], guideInfo.zArray[3], 10);
    dashed_line (guideInfo.xArray[3], guideInfo.yArray[3], guideInfo.zArray[3], guideInfo.xArray[0], guideInfo.yArray[0], guideInfo.zArray[0], 10);

    dashed_line (guideInfo.xArray[1], guideInfo.yArray[1], guideInfo.zArray[1], guideInfo.xArray[5], guideInfo.yArray[5], guideInfo.zArray[5], 10);
    dashed_line (guideInfo.xArray[5], guideInfo.yArray[5], guideInfo.zArray[5], guideInfo.xArray[6], guideInfo.yArray[6], guideInfo.zArray[6], 10);
    dashed_line (guideInfo.xArray[6], guideInfo.yArray[6], guideInfo.zArray[6], guideInfo.xArray[2], guideInfo.yArray[2], guideInfo.zArray[2], 10);
    dashed_line (guideInfo.xArray[2], guideInfo.yArray[2], guideInfo.zArray[2], guideInfo.xArray[1], guideInfo.yArray[1], guideInfo.zArray[1], 10);
  }
  free (xminus);
  free (yminus);
  free (xplus);
  free (yplus);
  #undef xwidth
  #undef yheight
  #undef l
  #undef linxw
  #undef loutxw
  #undef linyh
  #undef loutyh
  #undef majorAxisxw
  #undef minorAxisxw
  #undef majorAxisyh
  #undef minorAxisyh
  #undef majorAxisoffsetxw
  #undef majorAxisoffsetyh
  #undef dimensionsAt
  #undef option
  #undef R0
  #undef Qc
  #undef alpha
  #undef m
  #undef W
  #undef alpharight
  #undef mright
  #undef alphaleft
  #undef mleft
  #undef alphatop
  #undef mtop
  #undef alphabottom
  #undef mbottom
  #undef verbose
  #undef enableGravity
  #undef curvature
  #undef nSegments
  #undef mvaluesright
  #undef mvaluesleft
  #undef mvaluestop
  #undef mvaluesbottom
  #undef seglength
  #undef guideInfo
  #undef Gx0
  #undef Gy0
  #undef Gz0
  #undef Circ
  #undef dynamicalSegLength
  return(_comp);
} /* class_Elliptic_guide_gravity_display */

_class_Bender *class_Bender_display(_class_Bender *_comp
) {
  #define w (_comp->_parameters.w)
  #define h (_comp->_parameters.h)
  #define r (_comp->_parameters.r)
  #define Win (_comp->_parameters.Win)
  #define k (_comp->_parameters.k)
  #define d (_comp->_parameters.d)
  #define l (_comp->_parameters.l)
  #define R0a (_comp->_parameters.R0a)
  #define Qca (_comp->_parameters.Qca)
  #define alphaa (_comp->_parameters.alphaa)
  #define ma (_comp->_parameters.ma)
  #define Wa (_comp->_parameters.Wa)
  #define R0i (_comp->_parameters.R0i)
  #define Qci (_comp->_parameters.Qci)
  #define alphai (_comp->_parameters.alphai)
  #define mi (_comp->_parameters.mi)
  #define Wi (_comp->_parameters.Wi)
  #define R0s (_comp->_parameters.R0s)
  #define Qcs (_comp->_parameters.Qcs)
  #define alphas (_comp->_parameters.alphas)
  #define ms (_comp->_parameters.ms)
  #define Ws (_comp->_parameters.Ws)
  #define bk (_comp->_parameters.bk)
  #define mWin (_comp->_parameters.mWin)
  SIG_MESSAGE("[_C1_display] component C1=Bender() DISPLAY [Bender:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  int i;
  double w1c, w2c, h1, h2, L, w1, w2;

  w1c = (w + d) / (double)k;
  w2c = w1c;
  h1 = h;
  h2 = h;
  L = r * mWin;
  w1 = w;
  w2 = w;

  for (i = 0; i < k; i++) {
    multiline (5, i * w1c - w1 / 2.0, -h1 / 2.0, 0.0, i * w2c - w2 / 2.0, -h2 / 2.0, (double)L, i * w2c - w2 / 2.0, h2 / 2.0, (double)L, i * w1c - w1 / 2.0,
               h1 / 2.0, 0.0, i * w1c - w1 / 2.0, -h1 / 2.0, 0.0);
    multiline (5, (i + 1) * w1c - d - w1 / 2.0, -h1 / 2.0, 0.0, (i + 1) * w2c - d - w2 / 2.0, -h2 / 2.0, (double)L, (i + 1) * w2c - d - w2 / 2.0, h2 / 2.0,
               (double)L, (i + 1) * w1c - d - w1 / 2.0, h1 / 2.0, 0.0, (i + 1) * w1c - d - w1 / 2.0, -h1 / 2.0, 0.0);
  }
  line (-w1 / 2.0, -h1 / 2.0, 0.0, w1 / 2.0, -h1 / 2.0, 0.0);
  line (-w2 / 2.0, -h2 / 2.0, (double)L, w2 / 2.0, -h2 / 2.0, (double)L);
  #undef w
  #undef h
  #undef r
  #undef Win
  #undef k
  #undef d
  #undef l
  #undef R0a
  #undef Qca
  #undef alphaa
  #undef ma
  #undef Wa
  #undef R0i
  #undef Qci
  #undef alphai
  #undef mi
  #undef Wi
  #undef R0s
  #undef Qcs
  #undef alphas
  #undef ms
  #undef Ws
  #undef bk
  #undef mWin
  return(_comp);
} /* class_Bender_display */

_class_Slit *class_Slit_display(_class_Slit *_comp
) {
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define radius (_comp->_parameters.radius)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define isradial (_comp->_parameters.isradial)
  SIG_MESSAGE("[_SlitGuideEnd_display] component SlitGuideEnd=Slit() DISPLAY [Slit:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  if (is_unset (radius)) {
    double xw, yh;
    xw = (xmax - xmin) / 2.0;
    yh = (ymax - ymin) / 2.0;
    multiline (3, xmin - xw, (double)ymax, 0.0, (double)xmin, (double)ymax, 0.0, (double)xmin, ymax + yh, 0.0);
    multiline (3, xmax + xw, (double)ymax, 0.0, (double)xmax, (double)ymax, 0.0, (double)xmax, ymax + yh, 0.0);
    multiline (3, xmin - xw, (double)ymin, 0.0, (double)xmin, (double)ymin, 0.0, (double)xmin, ymin - yh, 0.0);
    multiline (3, xmax + xw, (double)ymin, 0.0, (double)xmax, (double)ymin, 0.0, (double)xmax, ymin - yh, 0.0);
  } else {
    circle ("xy", 0, 0, 0, radius);
  }
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef radius
  #undef xwidth
  #undef yheight
  #undef isradial
  return(_comp);
} /* class_Slit_display */

_class_Monochromator_curved *class_Monochromator_curved_display(_class_Monochromator_curved *_comp
) {
  #define reflect (_comp->_parameters.reflect)
  #define transmit (_comp->_parameters.transmit)
  #define zwidth (_comp->_parameters.zwidth)
  #define yheight (_comp->_parameters.yheight)
  #define gap (_comp->_parameters.gap)
  #define NH (_comp->_parameters.NH)
  #define NV (_comp->_parameters.NV)
  #define mosaich (_comp->_parameters.mosaich)
  #define mosaicv (_comp->_parameters.mosaicv)
  #define r0 (_comp->_parameters.r0)
  #define t0 (_comp->_parameters.t0)
  #define Q (_comp->_parameters.Q)
  #define RV (_comp->_parameters.RV)
  #define RH (_comp->_parameters.RH)
  #define DM (_comp->_parameters.DM)
  #define mosaic (_comp->_parameters.mosaic)
  #define width (_comp->_parameters.width)
  #define height (_comp->_parameters.height)
  #define verbose (_comp->_parameters.verbose)
  #define order (_comp->_parameters.order)
  #define mos_rms_y (_comp->_parameters.mos_rms_y)
  #define mos_rms_z (_comp->_parameters.mos_rms_z)
  #define mos_rms_max (_comp->_parameters.mos_rms_max)
  #define mono_Q (_comp->_parameters.mono_Q)
  #define SlabWidth (_comp->_parameters.SlabWidth)
  #define SlabHeight (_comp->_parameters.SlabHeight)
  #define rTable (_comp->_parameters.rTable)
  #define tTable (_comp->_parameters.tTable)
  #define rTableFlag (_comp->_parameters.rTableFlag)
  #define tTableFlag (_comp->_parameters.tTableFlag)
  #define tiltH (_comp->_parameters.tiltH)
  #define tiltV (_comp->_parameters.tiltV)
  #define ncol_var (_comp->_parameters.ncol_var)
  #define nrow_var (_comp->_parameters.nrow_var)
  SIG_MESSAGE("[_Mono_display] component Mono=Monochromator_curved() DISPLAY [Monochromator_curved:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  int ih;

  for (ih = 0; ih < NH; ih++) {
    int iv;
    for (iv = 0; iv < NV; iv++) {
      double zmin, zmax, ymin, ymax;
      double xt, yt;

      zmin = (SlabWidth + gap) * (ih - NH / 2.0) + gap / 2;
      zmax = zmin + SlabWidth;
      ymin = (SlabHeight + gap) * (iv - NV / 2.0) + gap / 2;
      ymax = ymin + SlabHeight;

      if (RH)
        xt = -(zmax * zmax - zmin * zmin) / RH / 2;
      else
        xt = 0;

      if (RV)
        yt = -(ymax * ymax - ymin * ymin) / RV / 2;
      else
        yt = 0;
      multiline (5, xt + yt, (double)ymin, (double)zmin, xt - yt, (double)ymax, (double)zmin, -xt - yt, (double)ymax, (double)zmax, -xt + yt, (double)ymin,
                 (double)zmax, xt + yt, (double)ymin, (double)zmin);
    }
  }
  #undef reflect
  #undef transmit
  #undef zwidth
  #undef yheight
  #undef gap
  #undef NH
  #undef NV
  #undef mosaich
  #undef mosaicv
  #undef r0
  #undef t0
  #undef Q
  #undef RV
  #undef RH
  #undef DM
  #undef mosaic
  #undef width
  #undef height
  #undef verbose
  #undef order
  #undef mos_rms_y
  #undef mos_rms_z
  #undef mos_rms_max
  #undef mono_Q
  #undef SlabWidth
  #undef SlabHeight
  #undef rTable
  #undef tTable
  #undef rTableFlag
  #undef tTableFlag
  #undef tiltH
  #undef tiltV
  #undef ncol_var
  #undef nrow_var
  return(_comp);
} /* class_Monochromator_curved_display */

_class_Incoherent *class_Incoherent_display(_class_Incoherent *_comp
) {
  #define geometry (_comp->_parameters.geometry)
  #define radius (_comp->_parameters.radius)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define thickness (_comp->_parameters.thickness)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define focus_r (_comp->_parameters.focus_r)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define target_index (_comp->_parameters.target_index)
  #define pack (_comp->_parameters.pack)
  #define p_interact (_comp->_parameters.p_interact)
  #define f_QE (_comp->_parameters.f_QE)
  #define gamma (_comp->_parameters.gamma)
  #define Etrans (_comp->_parameters.Etrans)
  #define deltaE (_comp->_parameters.deltaE)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define Vc (_comp->_parameters.Vc)
  #define concentric (_comp->_parameters.concentric)
  #define order (_comp->_parameters.order)
  #define VarsInc (_comp->_parameters.VarsInc)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_VanSample_display] component VanSample=Incoherent() DISPLAY [Incoherent:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  if (geometry && strlen (geometry) && strcmp (geometry, "NULL") && strcmp (geometry, "0")) { /* OFF file */
    off_display (offdata);
  } else if (radius > 0 && yheight) { /* cylinder along y*/
    cylinder (0, 0, 0, radius, yheight, thickness, 0, 1, 0);
  } else if (xwidth && yheight) { /* box/rectangle */
    box (0, 0, 0, xwidth, yheight, zdepth, thickness, 0, 1, 0);
  } else if (radius > 0 && !yheight) { /* sphere */
    sphere (0, 0, 0, radius);
  }
  #undef geometry
  #undef radius
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef thickness
  #undef target_x
  #undef target_y
  #undef target_z
  #undef focus_r
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef target_index
  #undef pack
  #undef p_interact
  #undef f_QE
  #undef gamma
  #undef Etrans
  #undef deltaE
  #undef sigma_abs
  #undef sigma_inc
  #undef Vc
  #undef concentric
  #undef order
  #undef VarsInc
  #undef offdata
  return(_comp);
} /* class_Incoherent_display */

_class_Phonon_simple *class_Phonon_simple_display(_class_Phonon_simple *_comp
) {
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define a (_comp->_parameters.a)
  #define b (_comp->_parameters.b)
  #define M (_comp->_parameters.M)
  #define c (_comp->_parameters.c)
  #define DW (_comp->_parameters.DW)
  #define T (_comp->_parameters.T)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define target_index (_comp->_parameters.target_index)
  #define focus_r (_comp->_parameters.focus_r)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define gap (_comp->_parameters.gap)
  #define e_steps_low (_comp->_parameters.e_steps_low)
  #define e_steps_high (_comp->_parameters.e_steps_high)
  #define V_rho (_comp->_parameters.V_rho)
  #define V_my_s (_comp->_parameters.V_my_s)
  #define V_my_a_v (_comp->_parameters.V_my_a_v)
  #define DV (_comp->_parameters.DV)
  #define phonon (_comp->_parameters.phonon)
  SIG_MESSAGE("[_sample_display] component sample=Phonon_simple() DISPLAY [Phonon_simple:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  circle ("xz", 0, yheight / 2.0, 0, radius);
  circle ("xz", 0, -yheight / 2.0, 0, radius);
  line (-radius, -yheight / 2.0, 0, -radius, +yheight / 2.0, 0);
  line (+radius, -yheight / 2.0, 0, +radius, +yheight / 2.0, 0);
  line (0, -yheight / 2.0, -radius, 0, +yheight / 2.0, -radius);
  line (0, -yheight / 2.0, +radius, 0, +yheight / 2.0, +radius);
  #undef radius
  #undef yheight
  #undef sigma_abs
  #undef sigma_inc
  #undef a
  #undef b
  #undef M
  #undef c
  #undef DW
  #undef T
  #undef target_x
  #undef target_y
  #undef target_z
  #undef target_index
  #undef focus_r
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef gap
  #undef e_steps_low
  #undef e_steps_high
  #undef V_rho
  #undef V_my_s
  #undef V_my_a_v
  #undef DV
  #undef phonon
  return(_comp);
} /* class_Phonon_simple_display */

_class_Powder1 *class_Powder1_display(_class_Powder1 *_comp
) {
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define xwidth (_comp->_parameters.xwidth)
  #define zdepth (_comp->_parameters.zdepth)
  #define q (_comp->_parameters.q)
  #define d (_comp->_parameters.d)
  #define d_phi (_comp->_parameters.d_phi)
  #define pack (_comp->_parameters.pack)
  #define j (_comp->_parameters.j)
  #define DW (_comp->_parameters.DW)
  #define F2 (_comp->_parameters.F2)
  #define Vc (_comp->_parameters.Vc)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define my_s_v2 (_comp->_parameters.my_s_v2)
  #define my_a_v (_comp->_parameters.my_a_v)
  #define q_v (_comp->_parameters.q_v)
  #define isrect (_comp->_parameters.isrect)
  SIG_MESSAGE("[_powder1_display] component powder1=Powder1() DISPLAY [Powder1:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  if (!isrect) {
    circle ("xz", 0, yheight / 2.0, 0, radius);
    circle ("xz", 0, -yheight / 2.0, 0, radius);
    line (-radius, -yheight / 2.0, 0, -radius, +yheight / 2.0, 0);
    line (+radius, -yheight / 2.0, 0, +radius, +yheight / 2.0, 0);
    line (0, -yheight / 2.0, -radius, 0, +yheight / 2.0, -radius);
    line (0, -yheight / 2.0, +radius, 0, +yheight / 2.0, +radius);
  } else {
    double xmin = -0.5 * xwidth;
    double xmax = 0.5 * xwidth;
    double ymin = -0.5 * yheight;
    double ymax = 0.5 * yheight;
    double zmin = -0.5 * zdepth;
    double zmax = 0.5 * zdepth;
    multiline (5, xmin, ymin, zmin, xmax, ymin, zmin, xmax, ymax, zmin, xmin, ymax, zmin, xmin, ymin, zmin);
    multiline (5, xmin, ymin, zmax, xmax, ymin, zmax, xmax, ymax, zmax, xmin, ymax, zmax, xmin, ymin, zmax);
    line (xmin, ymin, zmin, xmin, ymin, zmax);
    line (xmax, ymin, zmin, xmax, ymin, zmax);
    line (xmin, ymax, zmin, xmin, ymax, zmax);
    line (xmax, ymax, zmin, xmax, ymax, zmax);
  }
  #undef radius
  #undef yheight
  #undef xwidth
  #undef zdepth
  #undef q
  #undef d
  #undef d_phi
  #undef pack
  #undef j
  #undef DW
  #undef F2
  #undef Vc
  #undef sigma_abs
  #undef my_s_v2
  #undef my_a_v
  #undef q_v
  #undef isrect
  return(_comp);
} /* class_Powder1_display */

_class_Res_sample *class_Res_sample_display(_class_Res_sample *_comp
) {
  #define thickness (_comp->_parameters.thickness)
  #define radius (_comp->_parameters.radius)
  #define focus_r (_comp->_parameters.focus_r)
  #define E0 (_comp->_parameters.E0)
  #define dE (_comp->_parameters.dE)
  #define target_x (_comp->_parameters.target_x)
  #define target_y (_comp->_parameters.target_y)
  #define target_z (_comp->_parameters.target_z)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  #define focus_aw (_comp->_parameters.focus_aw)
  #define focus_ah (_comp->_parameters.focus_ah)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define target_index (_comp->_parameters.target_index)
  #define vars (_comp->_parameters.vars)
  #define res_pi_var (_comp->_parameters.res_pi_var)
  #define res_ki_x_var (_comp->_parameters.res_ki_x_var)
  #define res_ki_y_var (_comp->_parameters.res_ki_y_var)
  #define res_ki_z_var (_comp->_parameters.res_ki_z_var)
  #define res_kf_x_var (_comp->_parameters.res_kf_x_var)
  #define res_kf_y_var (_comp->_parameters.res_kf_y_var)
  #define res_kf_z_var (_comp->_parameters.res_kf_z_var)
  #define res_rx_var (_comp->_parameters.res_rx_var)
  #define res_ry_var (_comp->_parameters.res_ry_var)
  #define res_rz_var (_comp->_parameters.res_rz_var)
  #define compindex (_comp->_parameters.compindex)
  SIG_MESSAGE("[_res_sample_display] component res_sample=Res_sample() DISPLAY [Res_sample:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  if(vars.isrect) { /* Flat sample. */
    double xmin = -0.5*xwidth;
    double xmax =  0.5*xwidth;
    double ymin = -0.5*yheight;
    double ymax =  0.5*yheight;
    double len = zdepth/2;
    multiline(5, xmin, ymin, -len,
                 xmax, ymin, -len,
                 xmax, ymax, -len,
                 xmin, ymax, -len,
                 xmin, ymin, -len);
    multiline(5, xmin, ymin, len,
                 xmax, ymin, len,
                 xmax, ymax, len,
                 xmin, ymax, len,
                 xmin, ymin, len);
    line(xmin, ymin, -len, xmin, ymin, len);
    line(xmax, ymin, -len, xmax, ymin, len);
    line(xmin, ymax, -len, xmin, ymax, len);
    line(xmax, ymax, -len, xmax, ymax, len);
  }
  else {
    circle("xz", 0,  yheight/2.0, 0, radius);
    circle("xz", 0, -yheight/2.0, 0, radius);
    line(-radius, -yheight/2.0, 0, -radius, +yheight/2.0, 0);
    line(+radius, -yheight/2.0, 0, +radius, +yheight/2.0, 0);
    line(0, -yheight/2.0, -radius, 0, +yheight/2.0, -radius);
    line(0, -yheight/2.0, +radius, 0, +yheight/2.0, +radius);
    if (thickness) {
      double radius_i=radius-thickness;
      circle("xz", 0,  yheight/2.0, 0, radius_i);
      circle("xz", 0, -yheight/2.0, 0, radius_i);
      line(-radius_i, -yheight/2.0, 0, -radius_i, +yheight/2.0, 0);
      line(+radius_i, -yheight/2.0, 0, +radius_i, +yheight/2.0, 0);
      line(0, -yheight/2.0, -radius_i, 0, +yheight/2.0, -radius_i);
      line(0, -yheight/2.0, +radius_i, 0, +yheight/2.0, +radius_i);
    }
  }
  #undef thickness
  #undef radius
  #undef focus_r
  #undef E0
  #undef dE
  #undef target_x
  #undef target_y
  #undef target_z
  #undef focus_xw
  #undef focus_yh
  #undef focus_aw
  #undef focus_ah
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef target_index
  #undef vars
  #undef res_pi_var
  #undef res_ki_x_var
  #undef res_ki_y_var
  #undef res_ki_z_var
  #undef res_kf_x_var
  #undef res_kf_y_var
  #undef res_kf_z_var
  #undef res_rx_var
  #undef res_ry_var
  #undef res_rz_var
  #undef compindex
  return(_comp);
} /* class_Res_sample_display */

_class_Cyl_monitor_PSD *class_Cyl_monitor_PSD_display(_class_Cyl_monitor_PSD *_comp
) {
  #define nr (_comp->_parameters.nr)
  #define filename (_comp->_parameters.filename)
  #define yheight (_comp->_parameters.yheight)
  #define radius (_comp->_parameters.radius)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define thmin (_comp->_parameters.thmin)
  #define thmax (_comp->_parameters.thmax)
  #define ny (_comp->_parameters.ny)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_sample_cylinder_monitor_display] component sample_cylinder_monitor=Cyl_monitor_PSD() DISPLAY [Cyl_monitor_PSD:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  circle ("xz", 0, 0, 0, radius);
  #undef nr
  #undef filename
  #undef yheight
  #undef radius
  #undef restore_neutron
  #undef thmin
  #undef thmax
  #undef ny
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_Cyl_monitor_PSD_display */

_class_PSD_monitor_4PI *class_PSD_monitor_4PI_display(_class_PSD_monitor_4PI *_comp
) {
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define radius (_comp->_parameters.radius)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_sample_spherical_monitor_display] component sample_spherical_monitor=PSD_monitor_4PI() DISPLAY [PSD_monitor_4PI:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  circle ("xy", 0, 0, 0, radius);
  circle ("xz", 0, 0, 0, radius);
  circle ("yz", 0, 0, 0, radius);
  #undef nx
  #undef ny
  #undef filename
  #undef nowritefile
  #undef radius
  #undef restore_neutron
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_4PI_display */

_class_Filter_gen *class_Filter_gen_display(_class_Filter_gen *_comp
) {
  #define filename (_comp->_parameters.filename)
  #define options (_comp->_parameters.options)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define thickness (_comp->_parameters.thickness)
  #define scaling (_comp->_parameters.scaling)
  #define verbose (_comp->_parameters.verbose)
  #define Mode_Table (_comp->_parameters.Mode_Table)
  #define Type_Table (_comp->_parameters.Type_Table)
  #define pTable (_comp->_parameters.pTable)
  SIG_MESSAGE("[_filter_gen_display] component filter_gen=Filter_gen() DISPLAY [Filter_gen:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  multiline (5, (double)xmin, (double)ymin, 0.0, (double)xmax, (double)ymin, 0.0, (double)xmax, (double)ymax, 0.0, (double)xmin, (double)ymax, 0.0, (double)xmin,
             (double)ymin, 0.0);
  #undef filename
  #undef options
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef thickness
  #undef scaling
  #undef verbose
  #undef Mode_Table
  #undef Type_Table
  #undef pTable
  return(_comp);
} /* class_Filter_gen_display */

_class_PowderN *class_PowderN_display(_class_PowderN *_comp
) {
  #define reflections (_comp->_parameters.reflections)
  #define geometry (_comp->_parameters.geometry)
  #define format (_comp->_parameters.format)
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define xwidth (_comp->_parameters.xwidth)
  #define zdepth (_comp->_parameters.zdepth)
  #define thickness (_comp->_parameters.thickness)
  #define pack (_comp->_parameters.pack)
  #define Vc (_comp->_parameters.Vc)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define delta_d_d (_comp->_parameters.delta_d_d)
  #define p_inc (_comp->_parameters.p_inc)
  #define p_transmit (_comp->_parameters.p_transmit)
  #define DW (_comp->_parameters.DW)
  #define nb_atoms (_comp->_parameters.nb_atoms)
  #define d_omega (_comp->_parameters.d_omega)
  #define d_phi (_comp->_parameters.d_phi)
  #define tth_sign (_comp->_parameters.tth_sign)
  #define p_interact (_comp->_parameters.p_interact)
  #define concentric (_comp->_parameters.concentric)
  #define density (_comp->_parameters.density)
  #define weight (_comp->_parameters.weight)
  #define barns (_comp->_parameters.barns)
  #define Strain (_comp->_parameters.Strain)
  #define focus_flip (_comp->_parameters.focus_flip)
  #define target_index (_comp->_parameters.target_index)
  #define order (_comp->_parameters.order)
  #define line_info (_comp->_parameters.line_info)
  #define columns (_comp->_parameters.columns)
  #define offdata (_comp->_parameters.offdata)
  #define tgt_x (_comp->_parameters.tgt_x)
  #define tgt_y (_comp->_parameters.tgt_y)
  #define tgt_z (_comp->_parameters.tgt_z)
  SIG_MESSAGE("[_BeFilter_display] component BeFilter=PowderN() DISPLAY [PowderN:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  if (line_info.V_0) {

    if (line_info.shape == 0) { /* cyl */
      circle ("xz", 0, yheight / 2.0, 0, radius);
      circle ("xz", 0, -yheight / 2.0, 0, radius);
      line (-radius, -yheight / 2.0, 0, -radius, +yheight / 2.0, 0);
      line (+radius, -yheight / 2.0, 0, +radius, +yheight / 2.0, 0);
      line (0, -yheight / 2.0, -radius, 0, +yheight / 2.0, -radius);
      line (0, -yheight / 2.0, +radius, 0, +yheight / 2.0, +radius);
      if (thickness) {
        double radius_i = radius - thickness;
        circle ("xz", 0, yheight / 2.0, 0, radius_i);
        circle ("xz", 0, -yheight / 2.0, 0, radius_i);
        line (-radius_i, -yheight / 2.0, 0, -radius_i, +yheight / 2.0, 0);
        line (+radius_i, -yheight / 2.0, 0, +radius_i, +yheight / 2.0, 0);
        line (0, -yheight / 2.0, -radius_i, 0, +yheight / 2.0, -radius_i);
        line (0, -yheight / 2.0, +radius_i, 0, +yheight / 2.0, +radius_i);
      }
    } else if (line_info.shape == 1) { /* box */
      double xmin = -0.5 * xwidth;
      double xmax = 0.5 * xwidth;
      double ymin = -0.5 * yheight;
      double ymax = 0.5 * yheight;
      double zmin = -0.5 * zdepth;
      double zmax = 0.5 * zdepth;
      multiline (5, xmin, ymin, zmin, xmax, ymin, zmin, xmax, ymax, zmin, xmin, ymax, zmin, xmin, ymin, zmin);
      multiline (5, xmin, ymin, zmax, xmax, ymin, zmax, xmax, ymax, zmax, xmin, ymax, zmax, xmin, ymin, zmax);
      line (xmin, ymin, zmin, xmin, ymin, zmax);
      line (xmax, ymin, zmin, xmax, ymin, zmax);
      line (xmin, ymax, zmin, xmin, ymax, zmax);
      line (xmax, ymax, zmin, xmax, ymax, zmax);
      if (line_info.zdepth_i) {
        xmin = -0.5 * line_info.xwidth_i;
        xmax = 0.5 * line_info.xwidth_i;
        ymin = -0.5 * line_info.yheight_i;
        ymax = 0.5 * line_info.yheight_i;
        zmin = -0.5 * line_info.zdepth_i;
        zmax = 0.5 * line_info.zdepth_i;
        multiline (5, xmin, ymin, zmin, xmax, ymin, zmin, xmax, ymax, zmin, xmin, ymax, zmin, xmin, ymin, zmin);
        multiline (5, xmin, ymin, zmax, xmax, ymin, zmax, xmax, ymax, zmax, xmin, ymax, zmax, xmin, ymin, zmax);
        line (xmin, ymin, zmin, xmin, ymin, zmax);
        line (xmax, ymin, zmin, xmax, ymin, zmax);
        line (xmin, ymax, zmin, xmin, ymax, zmax);
        line (xmax, ymax, zmin, xmax, ymax, zmax);
      }
    }
    if (line_info.shape == 2) { /* sphere */
      if (line_info.radius_i) {
        circle ("xy", 0, 0, 0, line_info.radius_i);
        circle ("xz", 0, 0, 0, line_info.radius_i);
        circle ("yz", 0, 0, 0, line_info.radius_i);
      }
      circle ("xy", 0, 0, 0, radius);
      circle ("xz", 0, 0, 0, radius);
      circle ("yz", 0, 0, 0, radius);
    } else if (line_info.shape == 3) { /* OFF file */
      off_display (offdata);
    }
  }
  #undef reflections
  #undef geometry
  #undef format
  #undef radius
  #undef yheight
  #undef xwidth
  #undef zdepth
  #undef thickness
  #undef pack
  #undef Vc
  #undef sigma_abs
  #undef sigma_inc
  #undef delta_d_d
  #undef p_inc
  #undef p_transmit
  #undef DW
  #undef nb_atoms
  #undef d_omega
  #undef d_phi
  #undef tth_sign
  #undef p_interact
  #undef concentric
  #undef density
  #undef weight
  #undef barns
  #undef Strain
  #undef focus_flip
  #undef target_index
  #undef order
  #undef line_info
  #undef columns
  #undef offdata
  #undef tgt_x
  #undef tgt_y
  #undef tgt_z
  return(_comp);
} /* class_PowderN_display */


  #undef magnify
  #undef line
  #undef dashed_line
  #undef multiline
  #undef rectangle
  #undef box
  #undef circle
  #undef cylinder
  #undef sphere

int display(void) { /* called by mccode_main for PSI_CAMEA:DISPLAY */
  printf("MCDISPLAY: start\n");

  /* call iteratively all components DISPLAY */
  class_Progress_bar_display(&_Origin_var);

  class_Source_gen4_display(&_source_var);

  class_PSD_monitor_display(&_StartOfGuideMonitor_var);

  class_Arm_display(&_StartOfGuide_var);

  class_Elliptic_guide_gravity_display(&_Insert_var);

  class_PSD_monitor_display(&_EndOfInsertPSD_var);

  class_Elliptic_guide_gravity_display(&_E2_var);

  class_Arm_display(&_EndOfelement_5_var);

  class_PSD_monitor_display(&_E2PSD_var);

  class_Arm_display(&_EndOfelement_4_var);

  class_Bender_display(&_C1_var);

  class_Arm_display(&_EndOfelement_2_var);

  class_PSD_monitor_display(&_C1End_var);

  class_Elliptic_guide_gravity_display(&_E3a_var);

  class_PSD_monitor_display(&_E3aEnd_var);

  class_Elliptic_guide_gravity_display(&_E3b_var);

  class_PSD_monitor_display(&_E3bEnd_var);

  class_Slit_display(&_SlitGuideEnd_var);

  class_Monochromator_curved_display(&_Mono_var);

  class_Arm_display(&_A2_var);

  class_Slit_display(&_monochromatorShielding_var);

  class_Slit_display(&_slit_var);

  class_PSD_monitor_display(&_SlitMonitor_var);

  class_Arm_display(&_SamplePos_var);

  class_Arm_display(&_AMidt_var);

  class_Arm_display(&_a41_var);

  class_Arm_display(&_a42_var);

  class_Arm_display(&_a43_var);

  class_Arm_display(&_a44_var);

  class_Arm_display(&_a45_var);

  class_Arm_display(&_a46_var);

  class_Arm_display(&_a47_var);

  class_Arm_display(&_a48_var);

  class_PSD_monitor_display(&_sample_flux_before_var);

  class_Arm_display(&_sample_scatter_state_reset_var);

  class_Incoherent_display(&_VanSample_var);

  class_Phonon_simple_display(&_sample_var);

  class_Powder1_display(&_powder1_var);

  class_Res_sample_display(&_res_sample_var);

  class_PSD_monitor_display(&_sample_flux_after_unscattered_var);

  class_Cyl_monitor_PSD_display(&_sample_cylinder_monitor_var);

  class_PSD_monitor_4PI_display(&_sample_spherical_monitor_var);

  class_PSD_monitor_display(&_BackEndMonitor_var);

  class_Slit_display(&_slitBackEnd_var);

  class_Filter_gen_display(&_filter_gen_var);

  class_PowderN_display(&_BeFilter_var);

  printf("MCDISPLAY: end\n");

  return(0);
} /* display */

void* _getvar_parameters(char* compname)
/* enables settings parameters based use of the GETPAR macro */
{
  #ifdef OPENACC
    #define strcmp(a,b) str_comp(a,b)
  #endif
  if (!strcmp(compname, "Origin")) return (void *) &(_Origin_var._parameters);
  if (!strcmp(compname, "source")) return (void *) &(_source_var._parameters);
  if (!strcmp(compname, "StartOfGuideMonitor")) return (void *) &(_StartOfGuideMonitor_var._parameters);
  if (!strcmp(compname, "StartOfGuide")) return (void *) &(_StartOfGuide_var._parameters);
  if (!strcmp(compname, "Insert")) return (void *) &(_Insert_var._parameters);
  if (!strcmp(compname, "EndOfInsertPSD")) return (void *) &(_EndOfInsertPSD_var._parameters);
  if (!strcmp(compname, "E2")) return (void *) &(_E2_var._parameters);
  if (!strcmp(compname, "EndOfelement_5")) return (void *) &(_EndOfelement_5_var._parameters);
  if (!strcmp(compname, "E2PSD")) return (void *) &(_E2PSD_var._parameters);
  if (!strcmp(compname, "EndOfelement_4")) return (void *) &(_EndOfelement_4_var._parameters);
  if (!strcmp(compname, "C1")) return (void *) &(_C1_var._parameters);
  if (!strcmp(compname, "EndOfelement_2")) return (void *) &(_EndOfelement_2_var._parameters);
  if (!strcmp(compname, "C1End")) return (void *) &(_C1End_var._parameters);
  if (!strcmp(compname, "E3a")) return (void *) &(_E3a_var._parameters);
  if (!strcmp(compname, "E3aEnd")) return (void *) &(_E3aEnd_var._parameters);
  if (!strcmp(compname, "E3b")) return (void *) &(_E3b_var._parameters);
  if (!strcmp(compname, "E3bEnd")) return (void *) &(_E3bEnd_var._parameters);
  if (!strcmp(compname, "SlitGuideEnd")) return (void *) &(_SlitGuideEnd_var._parameters);
  if (!strcmp(compname, "Mono")) return (void *) &(_Mono_var._parameters);
  if (!strcmp(compname, "A2")) return (void *) &(_A2_var._parameters);
  if (!strcmp(compname, "monochromatorShielding")) return (void *) &(_monochromatorShielding_var._parameters);
  if (!strcmp(compname, "slit")) return (void *) &(_slit_var._parameters);
  if (!strcmp(compname, "SlitMonitor")) return (void *) &(_SlitMonitor_var._parameters);
  if (!strcmp(compname, "SamplePos")) return (void *) &(_SamplePos_var._parameters);
  if (!strcmp(compname, "AMidt")) return (void *) &(_AMidt_var._parameters);
  if (!strcmp(compname, "a41")) return (void *) &(_a41_var._parameters);
  if (!strcmp(compname, "a42")) return (void *) &(_a42_var._parameters);
  if (!strcmp(compname, "a43")) return (void *) &(_a43_var._parameters);
  if (!strcmp(compname, "a44")) return (void *) &(_a44_var._parameters);
  if (!strcmp(compname, "a45")) return (void *) &(_a45_var._parameters);
  if (!strcmp(compname, "a46")) return (void *) &(_a46_var._parameters);
  if (!strcmp(compname, "a47")) return (void *) &(_a47_var._parameters);
  if (!strcmp(compname, "a48")) return (void *) &(_a48_var._parameters);
  if (!strcmp(compname, "sample_flux_before")) return (void *) &(_sample_flux_before_var._parameters);
  if (!strcmp(compname, "sample_scatter_state_reset")) return (void *) &(_sample_scatter_state_reset_var._parameters);
  if (!strcmp(compname, "VanSample")) return (void *) &(_VanSample_var._parameters);
  if (!strcmp(compname, "sample")) return (void *) &(_sample_var._parameters);
  if (!strcmp(compname, "powder1")) return (void *) &(_powder1_var._parameters);
  if (!strcmp(compname, "res_sample")) return (void *) &(_res_sample_var._parameters);
  if (!strcmp(compname, "sample_flux_after_unscattered")) return (void *) &(_sample_flux_after_unscattered_var._parameters);
  if (!strcmp(compname, "sample_cylinder_monitor")) return (void *) &(_sample_cylinder_monitor_var._parameters);
  if (!strcmp(compname, "sample_spherical_monitor")) return (void *) &(_sample_spherical_monitor_var._parameters);
  if (!strcmp(compname, "BackEndMonitor")) return (void *) &(_BackEndMonitor_var._parameters);
  if (!strcmp(compname, "slitBackEnd")) return (void *) &(_slitBackEnd_var._parameters);
  if (!strcmp(compname, "filter_gen")) return (void *) &(_filter_gen_var._parameters);
  if (!strcmp(compname, "BeFilter")) return (void *) &(_BeFilter_var._parameters);
  return 0;
}

void* _get_particle_var(char *token, _class_particle *p)
/* enables setpars based use of GET_PARTICLE_DVAR macro and similar */
{
  if (!strcmp(token, "ncol_19")) return (void *) &(p->ncol_19);
  if (!strcmp(token, "nrow_19")) return (void *) &(p->nrow_19);
  if (!strcmp(token, "res_pi_39")) return (void *) &(p->res_pi_39);
  if (!strcmp(token, "res_ki_x_39")) return (void *) &(p->res_ki_x_39);
  if (!strcmp(token, "res_ki_y_39")) return (void *) &(p->res_ki_y_39);
  if (!strcmp(token, "res_ki_z_39")) return (void *) &(p->res_ki_z_39);
  if (!strcmp(token, "res_kf_x_39")) return (void *) &(p->res_kf_x_39);
  if (!strcmp(token, "res_kf_y_39")) return (void *) &(p->res_kf_y_39);
  if (!strcmp(token, "res_kf_z_39")) return (void *) &(p->res_kf_z_39);
  if (!strcmp(token, "res_rx_39")) return (void *) &(p->res_rx_39);
  if (!strcmp(token, "res_ry_39")) return (void *) &(p->res_ry_39);
  if (!strcmp(token, "res_rz_39")) return (void *) &(p->res_rz_39);
  return 0;
}

int _getcomp_index(char* compname)
/* Enables retrieving the component position & rotation when the index is not known.
 * Component indexing into MACROS, e.g., POS_A_COMP_INDEX, are 1-based! */
{
  if (!strcmp(compname, "Origin")) return 1;
  if (!strcmp(compname, "source")) return 2;
  if (!strcmp(compname, "StartOfGuideMonitor")) return 3;
  if (!strcmp(compname, "StartOfGuide")) return 4;
  if (!strcmp(compname, "Insert")) return 5;
  if (!strcmp(compname, "EndOfInsertPSD")) return 6;
  if (!strcmp(compname, "E2")) return 7;
  if (!strcmp(compname, "EndOfelement_5")) return 8;
  if (!strcmp(compname, "E2PSD")) return 9;
  if (!strcmp(compname, "EndOfelement_4")) return 10;
  if (!strcmp(compname, "C1")) return 11;
  if (!strcmp(compname, "EndOfelement_2")) return 12;
  if (!strcmp(compname, "C1End")) return 13;
  if (!strcmp(compname, "E3a")) return 14;
  if (!strcmp(compname, "E3aEnd")) return 15;
  if (!strcmp(compname, "E3b")) return 16;
  if (!strcmp(compname, "E3bEnd")) return 17;
  if (!strcmp(compname, "SlitGuideEnd")) return 18;
  if (!strcmp(compname, "Mono")) return 19;
  if (!strcmp(compname, "A2")) return 20;
  if (!strcmp(compname, "monochromatorShielding")) return 21;
  if (!strcmp(compname, "slit")) return 22;
  if (!strcmp(compname, "SlitMonitor")) return 23;
  if (!strcmp(compname, "SamplePos")) return 24;
  if (!strcmp(compname, "AMidt")) return 25;
  if (!strcmp(compname, "a41")) return 26;
  if (!strcmp(compname, "a42")) return 27;
  if (!strcmp(compname, "a43")) return 28;
  if (!strcmp(compname, "a44")) return 29;
  if (!strcmp(compname, "a45")) return 30;
  if (!strcmp(compname, "a46")) return 31;
  if (!strcmp(compname, "a47")) return 32;
  if (!strcmp(compname, "a48")) return 33;
  if (!strcmp(compname, "sample_flux_before")) return 34;
  if (!strcmp(compname, "sample_scatter_state_reset")) return 35;
  if (!strcmp(compname, "VanSample")) return 36;
  if (!strcmp(compname, "sample")) return 37;
  if (!strcmp(compname, "powder1")) return 38;
  if (!strcmp(compname, "res_sample")) return 39;
  if (!strcmp(compname, "sample_flux_after_unscattered")) return 40;
  if (!strcmp(compname, "sample_cylinder_monitor")) return 41;
  if (!strcmp(compname, "sample_spherical_monitor")) return 42;
  if (!strcmp(compname, "BackEndMonitor")) return 43;
  if (!strcmp(compname, "slitBackEnd")) return 44;
  if (!strcmp(compname, "filter_gen")) return 45;
  if (!strcmp(compname, "BeFilter")) return 46;
  return -1;
}

/* embedding file "metadata-r.c" */

/** --- Contents of  metadata-r.c ---------------------------------------------------------------------------------- */
// Created by Gregory Tucker, Data Management Software Centre, European Spallation Source ERIC on 07/07/23.
#ifndef MCCODE_NAME
#include "metadata-r.h"
#endif

char * metadata_table_key_component(char* key){
  if (strlen(key) == 0) return NULL;
  char sep[2] = ":\0"; // matches any number of repeated colons
  // look for the separator in the provided key; strtok is allowed to modify the string, so copy it
  char * tok = malloc((strlen(key) + 1) * sizeof(char));
  if (!tok) {
    fprintf(stderr,"Error allocating token\n");
    exit(-1);
  }
  strcpy(tok, key);
  char * pch = strtok(tok, sep); // this *is* the component name (if provided) -- but we need to move the pointer
  char * comp = malloc((1 + strlen(pch)) * sizeof(char));
  if (!comp) {
    fprintf(stderr,"Error allocating comp\n");
    exit(-1);
  }
  strcpy(comp, pch);
  if (tok) free(tok);
  return comp;
}
char * metadata_table_key_literal(char * key){
  if (strlen(key) == 0) return NULL;
  char sep[3] = ":\0";
  char * tok = malloc((strlen(key) + 1 ) * sizeof(char));
  if (!tok) {
    fprintf(stderr,"Error allocating token\n");
    exit(-1);
  }
  strcpy(tok, key);
  char * pch = strtok(tok, sep); // this *is* the component name (if provided)
  if (pch) pch = strtok(NULL, sep); // either NULL or the literal name
  char * name = NULL;
  if (pch) {
    name = malloc((1 + strlen(pch)) * sizeof(char));
    if (!name) {
      fprintf(stderr,"Error allocating name\n");
	exit(-1);
    }
    strcpy(name, pch);
  }
  if (tok) free(tok);
  return name;
}
int metadata_table_defined(int no, metadata_table_t * tab, char * key){
  if (strlen(key) == 0){
    /* This is 0 instead of `no` independent of any wildcard-matching logic
     * because a caller _already_ knows `no` and can verify
     * that `key` is not "" at call-time. So returning `no` is useless.
     */
    return 0;
  }
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  // look through the table for the matching component and literal names
  int number = 0;
  for (int i=0; i<no; ++i){
    if (!strcmp(comp, tab[i].source)){
      if (name == NULL || !strcmp(name, tab[i].name)) ++number;
    }
  }
  if (comp) free(comp);
  if (name) free(name);
  return number;
}

char * metadata_table_name(int no, metadata_table_t * tab, char *key){
    if (strlen(key) == 0){
        return NULL;
    }
    char * comp = metadata_table_key_component(key);
    char * name = metadata_table_key_literal(key);
    if (name == NULL) {
        for (int i=0; i<no; ++i){
            if (!strcmp(comp, tab[i].source)){
                name = malloc((strlen(tab[i].name) + 1) * sizeof(char));
		if (!name) {
		  fprintf(stderr,"Error allocating metadata_table_name\n");
		  exit(-1);
		}
                strcpy(name, tab[i].name);
                break;
            }
        }
    } else {
        int found=0;
        for (int i=0; i<no; ++i){
            if (!strcmp(comp, tab[i].source) && !strcmp(name, tab[i].name)) {
                found = 1;
                break;
            }
        }
        if (!found) free(name);
    }
    free(comp);
    return name;
}

char * metadata_table_type(int no, metadata_table_t * tab, char * key){
  if (strlen(key) == 0) {
    fprintf(stderr, "Unable to check type of non-existent key\n");
    exit(1);
  }
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  if (name == NULL){
    fprintf(stderr, "Unable to check type of literal for component %s without its name\n", comp);
    free(comp);
    exit(1);
  }
  char * type = NULL;
  for (int i=0; i<no; ++i){
    if (!strcmp(comp, tab[i].source) && !strcmp(name, tab[i].name)) type = tab[i].type;
  }
  if (comp) free(comp);
  if (name) free(name);
  return type;
}

char * metadata_table_literal(int no, metadata_table_t * tab, char * key){
  if (strlen(key) == 0) {
    fprintf(stderr, "Unable to retrieve literal for non-existent key\n");
    exit(1);
  }
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  if (name == NULL){
    fprintf(stderr, "Unable to retrieve literal for component %s without its name\n", comp);
    free(comp);
    exit(1);
  }
  char * type = NULL;
  for (int i=0; i<no; ++i){
    if (!strcmp(comp, tab[i].source) && !strcmp(name, tab[i].name)) type = tab[i].value;
  }
  if (comp) free(comp);
  if (name) free(name);
  return type;
}
void metadata_table_print_all_keys(int no, metadata_table_t * tab){
  for (int i=0; i<no; ++i){
    printf("%s::%s ", tab[i].source, tab[i].name);
  }
  printf("\n");
}
int metadata_table_print_all_components(int no, metadata_table_t * tab){
  int count = 0;
  char ** known = malloc(no * sizeof(char*));
  if (!known) {
    fprintf(stderr,"Error allocating table of known metadata\n");
    exit(-1);
  }
  for (int i=0; i<no; ++i){
    int unknown = 1;
    for (int j=0; j<count; ++j) if (!strcmp(tab[i].source, known[j])) unknown = 0;
    if (unknown) known[count++] = tab[i].source;
  }
  size_t nchar = 0;
  for (int i=0; i<count; ++i) nchar += strlen(known[i]) + 1;
  char * line = malloc((nchar + 1) * sizeof(char));
  char * linetmp = malloc((nchar + 1) * sizeof(char));
  if (!line || !linetmp) {
    fprintf(stderr,"Error allocating metadata print arrays\n");
    exit(-1);
  }
  line[0] = '\0';
  for (int i=0; i<count; ++i) sprintf(linetmp, "%s%s ", line, known[i]);
  line=linetmp;
  line[strlen(line)] = '\0'; // eat the trailing space
  printf("%s\n", line);
  free(line);
  free(linetmp);
  free(known);
  return count;
}
int metadata_table_print_component_keys(int no, metadata_table_t * tab, char * key){
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  int count = 0;
  for (int i=0; i<no; ++i) if (!strcmp(tab[i].source, comp) && (name == NULL || !strcmp(tab[i].name, name))) {
    if (name == NULL) printf("%s ", tab[i].name);
    ++count;
  }
  if (name != NULL) printf("%d", count); // replace count by strlen(tab[i].value)?
  printf("\n");
  return count;
}
/* -------------------------------------------------------------------------------------Contents of  metadata-r.c --- */
/* End of file "metadata-r.c". */

/* embedding file "mccode_main.c" */

/*******************************************************************************
* mccode_main: McCode main() function.
*******************************************************************************/
int mccode_main(int argc, char *argv[])
{
  /*  double run_num = 0; */
  time_t  t;
  clock_t ct;

#ifdef USE_MPI
  char mpi_node_name[MPI_MAX_PROCESSOR_NAME];
  int  mpi_node_name_len;
#endif /* USE_MPI */

#ifdef MAC
  argc = ccommand(&argv);
#endif

#ifdef USE_MPI
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &mpi_node_count); /* get number of nodes */
  MPI_Comm_rank(MPI_COMM_WORLD, &mpi_node_rank);
  MPI_Comm_set_name(MPI_COMM_WORLD, instrument_name);
  MPI_Get_processor_name(mpi_node_name, &mpi_node_name_len);
#endif /* USE_MPI */

  ct = clock();

  // device and host functional RNG seed
  struct timeval tm;
  gettimeofday(&tm, NULL);
  mcseed = (long) tm.tv_sec*1000000 + tm.tv_usec;
  mcstartdate = (long)tm.tv_sec;  /* set start date before parsing options and creating sim file */
  // init global _particle.randstate for random number use
  // during init(), finally() and display(). NOTE: during trace, a local
  // "_particle" variable is present and thus used instead.
  //
  // PW: srandom deferred until init() since we did not read seed input from commandline
  //srandom(_hash(mcseed-1));

#ifdef USE_MPI
  /* *** print number of nodes *********************************************** */
  if (mpi_node_count > 1) {
    MPI_MASTER(
    printf("Simulation '%s' (%s): running on %i nodes (master is '%s', MPI version %i.%i).\n",
      instrument_name, instrument_source, mpi_node_count, mpi_node_name, MPI_VERSION, MPI_SUBVERSION);
    );
    /* share the same seed, then adapt random seed for each node */
    MPI_Bcast(&mcseed, 1, MPI_LONG, 0, MPI_COMM_WORLD); /* root sends its seed to slaves */
    mcseed += mpi_node_rank; /* make sure we use different seeds per noe */
  }
#endif /* USE_MPI */

#ifdef OPENACC
#ifdef USE_MPI
  int num_devices = acc_get_num_devices(acc_device_nvidia);
  if(num_devices>0){
    int my_device = mpi_node_rank % num_devices;
    acc_set_device_num( my_device, acc_device_nvidia );
    printf("Have found %d GPU devices on rank %d. Will use device %d.\n", num_devices, mpi_node_rank, my_device);
  }else{
    printf("There was an issue probing acc_get_num_devices, fallback to host\n");
    acc_set_device_type( acc_device_host );
  }
#endif
#endif

  /* *** parse options ******************************************************* */
  SIG_MESSAGE("[" __FILE__ "] main START");
  mcformat = getenv(FLAVOR_UPPER "_FORMAT") ?
             getenv(FLAVOR_UPPER "_FORMAT") : FLAVOR_UPPER;
  instrument_exe = argv[0]; /* store the executable path */
  /* read simulation parameters and options */
  mcparseoptions(argc, argv); /* sets output dir and format */


#ifdef USE_MPI
  if (mpi_node_count > 1) {
    /* share the same seed, then adapt random seed for each node */
    MPI_Bcast(&mcseed, 1, MPI_LONG, 0, MPI_COMM_WORLD); /* root sends its seed to slaves */
    mcseed += mpi_node_rank; /* make sure we use different seeds per node */
  }
#endif


/* *** install sig handler, but only once !! after parameters parsing ******* */
#ifndef NOSIGNALS
#ifdef SIGQUIT
  if (signal( SIGQUIT ,sighandler) == SIG_IGN)
    signal( SIGQUIT,SIG_IGN);   /* quit (ASCII FS) */
#endif
#ifdef SIGABRT
  if (signal( SIGABRT ,sighandler) == SIG_IGN)
    signal( SIGABRT,SIG_IGN);   /* used by abort, replace SIGIOT in the future */
#endif
#ifdef SIGTERM
  if (signal( SIGTERM ,sighandler) == SIG_IGN)
    signal( SIGTERM,SIG_IGN);   /* software termination signal from kill */
#endif
#ifdef SIGUSR1
  if (signal( SIGUSR1 ,sighandler) == SIG_IGN)
    signal( SIGUSR1,SIG_IGN);   /* display simulation status */
#endif
#ifdef SIGUSR2
  if (signal( SIGUSR2 ,sighandler) == SIG_IGN)
    signal( SIGUSR2,SIG_IGN);
#endif
#ifdef SIGHUP
  if (signal( SIGHUP ,sighandler) == SIG_IGN)
    signal( SIGHUP,SIG_IGN);
#endif
#ifdef SIGILL
  if (signal( SIGILL ,sighandler) == SIG_IGN)
    signal( SIGILL,SIG_IGN);    /* illegal instruction (not reset when caught) */
#endif
#ifdef SIGFPE
  if (signal( SIGFPE ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);    /* floating point exception */
#endif
#ifdef SIGBUS
  if (signal( SIGBUS ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);    /* bus error */
#endif
#ifdef SIGSEGV
  if (signal( SIGSEGV ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);   /* segmentation violation */
#endif
#endif /* !NOSIGNALS */


  // init executed by master/host
  siminfo_init(NULL); /* open SIM */
  SIG_MESSAGE("[" __FILE__ "] main INITIALISE");
  init();


#ifndef NOSIGNALS
#ifdef SIGINT
  if (signal( SIGINT ,sighandler) == SIG_IGN)
    signal( SIGINT,SIG_IGN);    /* interrupt (rubout) only after INIT */
#endif
#endif /* !NOSIGNALS */

/* ================ main particle generation/propagation loop ================ */
#ifdef USE_MPI
  /* sliced Ncount on each MPI node */
  mcncount = mpi_node_count > 1 ?
    floor(mcncount / mpi_node_count) :
    mcncount; /* number of rays per node */
#endif

// MT specific init, note that per-ray init is empty
#if RNG_ALG == 2
  mt_srandom(mcseed);
#endif


// main raytrace work loop
#ifndef FUNNEL
  // legacy version
  raytrace_all(mcncount, mcseed);
#else
  MPI_MASTER(
  // "funneled" version in which propagation is more parallelizable
  printf("\nNOTE: CPU COMPONENT grammar activated:\n 1) \"FUNNEL\" raytrace algorithm enabled.\n 2) Any SPLIT's are dynamically allocated based on available buffer size. \n");
	     );
  raytrace_all_funnel(mcncount, mcseed);
#endif


#ifdef USE_MPI
 /* merge run_num from MPI nodes */
  if (mpi_node_count > 1) {
  double mcrun_num_double = (double)mcrun_num;
  mc_MPI_Sum(&mcrun_num_double, 1);
  mcrun_num = (unsigned long long)mcrun_num_double;
  }
#endif


  // save/finally executed by master node/thread/host
  finally();


#ifdef USE_MPI
  MPI_Finalize();
#endif /* USE_MPI */


  return 0;
} /* mccode_main */
/* End of file "mccode_main.c". */

/* end of generated C code ./FullInstrument_v5_working.c */
