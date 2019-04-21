/*
 * MATLAB Compiler: 6.2 (R2016a)
 * Date: Wed Apr 17 14:14:54 2019
 * Arguments: "-B" "macro_default" "-W" "lib:matStep67810" "-T" "link:lib" "-d"
 * "C:\Users\Administrator\Desktop\matStep67810\for_testing" "-v" "D:\Program
 * Files\MATLAB\R2016a\bin\matStep10.m" "D:\Program
 * Files\MATLAB\R2016a\bin\matStep6.m" "D:\Program
 * Files\MATLAB\R2016a\bin\matStep7.m" "D:\Program
 * Files\MATLAB\R2016a\bin\matStep8.m" 
 */

#ifndef __matStep67810_h
#define __matStep67810_h 1

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

#ifdef EXPORTING_matStep67810
#define PUBLIC_matStep67810_C_API __global
#else
#define PUBLIC_matStep67810_C_API /* No import statement needed. */
#endif

#define LIB_matStep67810_C_API PUBLIC_matStep67810_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_matStep67810
#define PUBLIC_matStep67810_C_API __declspec(dllexport)
#else
#define PUBLIC_matStep67810_C_API __declspec(dllimport)
#endif

#define LIB_matStep67810_C_API PUBLIC_matStep67810_C_API


#else

#define LIB_matStep67810_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_matStep67810_C_API 
#define LIB_matStep67810_C_API /* No special import/export declaration */
#endif

extern LIB_matStep67810_C_API 
bool MW_CALL_CONV matStep67810InitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_matStep67810_C_API 
bool MW_CALL_CONV matStep67810Initialize(void);

extern LIB_matStep67810_C_API 
void MW_CALL_CONV matStep67810Terminate(void);



extern LIB_matStep67810_C_API 
void MW_CALL_CONV matStep67810PrintStackTrace(void);

extern LIB_matStep67810_C_API 
bool MW_CALL_CONV mlxMatStep10(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_matStep67810_C_API 
bool MW_CALL_CONV mlxMatStep6(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_matStep67810_C_API 
bool MW_CALL_CONV mlxMatStep7(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_matStep67810_C_API 
bool MW_CALL_CONV mlxMatStep8(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);



extern LIB_matStep67810_C_API bool MW_CALL_CONV mlfMatStep10(int nargout, mxArray** Q, mxArray* step11, mxArray* step3out, mxArray* step51, mxArray* step52, mxArray* step621, mxArray* step622, mxArray* step6out, mxArray* step7out, mxArray* step721, mxArray* step722);

extern LIB_matStep67810_C_API bool MW_CALL_CONV mlfMatStep6(int nargout, mxArray** Q, mxArray* step51, mxArray* step61, mxArray* step621, mxArray* step622);

extern LIB_matStep67810_C_API bool MW_CALL_CONV mlfMatStep7(int nargout, mxArray** Q, mxArray* step51, mxArray* step61, mxArray* step711, mxArray* step712, mxArray* step721, mxArray* step722);

extern LIB_matStep67810_C_API bool MW_CALL_CONV mlfMatStep8(int nargout, mxArray** Q, mxArray* step3out, mxArray* step7out);

#ifdef __cplusplus
}
#endif
#endif
