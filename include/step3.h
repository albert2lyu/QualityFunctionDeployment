/*
 * MATLAB Compiler: 6.2 (R2016a)
 * Date: Mon Apr 15 13:53:09 2019
 * Arguments: "-B" "macro_default" "-W" "lib:step3" "-T" "link:lib" "-d"
 * "C:\Users\Administrator\Desktop\step3\for_testing" "-v" "D:\Program
 * Files\MATLAB\R2016a\bin\step3.m" 
 */

#ifndef __step3_h
#define __step3_h 1

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

#ifdef EXPORTING_step3
#define PUBLIC_step3_C_API __global
#else
#define PUBLIC_step3_C_API /* No import statement needed. */
#endif

#define LIB_step3_C_API PUBLIC_step3_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_step3
#define PUBLIC_step3_C_API __declspec(dllexport)
#else
#define PUBLIC_step3_C_API __declspec(dllimport)
#endif

#define LIB_step3_C_API PUBLIC_step3_C_API


#else

#define LIB_step3_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_step3_C_API 
#define LIB_step3_C_API /* No special import/export declaration */
#endif

extern LIB_step3_C_API 
bool MW_CALL_CONV step3InitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_step3_C_API 
bool MW_CALL_CONV step3Initialize(void);

extern LIB_step3_C_API 
void MW_CALL_CONV step3Terminate(void);



extern LIB_step3_C_API 
void MW_CALL_CONV step3PrintStackTrace(void);

extern LIB_step3_C_API 
bool MW_CALL_CONV mlxStep3(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);



extern LIB_step3_C_API bool MW_CALL_CONV mlfStep3(int nargout, mxArray** Q, mxArray* A3, mxArray* B3, mxArray* C3, mxArray* D3);

#ifdef __cplusplus
}
#endif
#endif
