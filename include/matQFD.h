/*
 * MATLAB Compiler: 6.2 (R2016a)
 * Date: Fri May 03 16:24:52 2019
 * Arguments: "-B" "macro_default" "-W" "lib:matQFD" "-T" "link:lib" "-d"
 * "D:\Program Files\MATLAB\R2016a\bin\matQFD\for_testing" "-v" "D:\Program
 * Files\MATLAB\R2016a\bin\matFahp.m" "D:\Program
 * Files\MATLAB\R2016a\bin\matStep10.m" "D:\Program
 * Files\MATLAB\R2016a\bin\matStep3.m" "D:\Program
 * Files\MATLAB\R2016a\bin\matStep6.m" "D:\Program
 * Files\MATLAB\R2016a\bin\matStep7.m" "D:\Program
 * Files\MATLAB\R2016a\bin\matStep8.m" 
 */

#ifndef __matQFD_h
#define __matQFD_h 1

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

#ifdef EXPORTING_matQFD
#define PUBLIC_matQFD_C_API __global
#else
#define PUBLIC_matQFD_C_API /* No import statement needed. */
#endif

#define LIB_matQFD_C_API PUBLIC_matQFD_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_matQFD
#define PUBLIC_matQFD_C_API __declspec(dllexport)
#else
#define PUBLIC_matQFD_C_API __declspec(dllimport)
#endif

#define LIB_matQFD_C_API PUBLIC_matQFD_C_API


#else

#define LIB_matQFD_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_matQFD_C_API 
#define LIB_matQFD_C_API /* No special import/export declaration */
#endif

extern LIB_matQFD_C_API 
bool MW_CALL_CONV matQFDInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_matQFD_C_API 
bool MW_CALL_CONV matQFDInitialize(void);

extern LIB_matQFD_C_API 
void MW_CALL_CONV matQFDTerminate(void);



extern LIB_matQFD_C_API 
void MW_CALL_CONV matQFDPrintStackTrace(void);

extern LIB_matQFD_C_API 
bool MW_CALL_CONV mlxMatFahp(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_matQFD_C_API 
bool MW_CALL_CONV mlxMatStep10(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_matQFD_C_API 
bool MW_CALL_CONV mlxMatStep3(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_matQFD_C_API 
bool MW_CALL_CONV mlxMatStep6(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_matQFD_C_API 
bool MW_CALL_CONV mlxMatStep7(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_matQFD_C_API 
bool MW_CALL_CONV mlxMatStep8(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);



extern LIB_matQFD_C_API bool MW_CALL_CONV mlfMatFahp(int nargout, mxArray** C, mxArray* A);

extern LIB_matQFD_C_API bool MW_CALL_CONV mlfMatStep10(int nargout, mxArray** Q, mxArray* step11, mxArray* step3out, mxArray* step51, mxArray* step52, mxArray* step621, mxArray* step622, mxArray* step6out, mxArray* step7out, mxArray* step721, mxArray* step722);

extern LIB_matQFD_C_API bool MW_CALL_CONV mlfMatStep3(int nargout, mxArray** Q, mxArray* A3, mxArray* B3, mxArray* C3, mxArray* D3);

extern LIB_matQFD_C_API bool MW_CALL_CONV mlfMatStep6(int nargout, mxArray** Q, mxArray* step51, mxArray* step61, mxArray* step621, mxArray* step622);

extern LIB_matQFD_C_API bool MW_CALL_CONV mlfMatStep7(int nargout, mxArray** Q, mxArray* step51, mxArray* step61, mxArray* step711, mxArray* step712, mxArray* step721, mxArray* step722);

extern LIB_matQFD_C_API bool MW_CALL_CONV mlfMatStep8(int nargout, mxArray** Q, mxArray* step3out, mxArray* step7out);

#ifdef __cplusplus
}
#endif
#endif
