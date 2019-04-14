/*
 * MATLAB Compiler: 6.2 (R2016a)
 * Date: Sun Apr 14 12:14:52 2019
 * Arguments: "-B" "macro_default" "-W" "lib:matBasic" "-T" "link:lib" "-d"
 * "C:\Users\Administrator\Desktop\matBasic\for_testing" "-v" "D:\Program
 * Files\MATLAB\R2016a\bin\matFahp.m" 
 */

#ifndef __matBasic_h
#define __matBasic_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_matBasic
#define PUBLIC_matBasic_C_API __global
#else
#define PUBLIC_matBasic_C_API /* No import statement needed. */
#endif

#define LIB_matBasic_C_API PUBLIC_matBasic_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_matBasic
#define PUBLIC_matBasic_C_API __declspec(dllexport)
#else
#define PUBLIC_matBasic_C_API __declspec(dllimport)
#endif

#define LIB_matBasic_C_API PUBLIC_matBasic_C_API


#else

#define LIB_matBasic_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_matBasic_C_API 
#define LIB_matBasic_C_API /* No special import/export declaration */
#endif

extern LIB_matBasic_C_API 
bool MW_CALL_CONV matBasicInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_matBasic_C_API 
bool MW_CALL_CONV matBasicInitialize(void);

extern LIB_matBasic_C_API 
void MW_CALL_CONV matBasicTerminate(void);



extern LIB_matBasic_C_API 
void MW_CALL_CONV matBasicPrintStackTrace(void);

extern LIB_matBasic_C_API 
bool MW_CALL_CONV mlxMatFahp(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);



extern LIB_matBasic_C_API
bool MW_CALL_CONV mlfMatFahp(int nargout, mxArray** C, mxArray* A);

#ifdef __cplusplus
}
#endif
#endif
