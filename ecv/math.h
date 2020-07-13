/* File math.h supplied with Escher C Verifier.
 * Use this file only if you are using the eCv preprocessor.
 * If you wish to use a compiler to preprocess C/C++ source instead, then
 *  you should use the standard include files supplied with that compiler.
 */

#if !defined(__ecv_math_h_included__)
#define __ecv_math_h_included__

#pragma ECV noverify

#if defined(__ECV__)

# if (__ECV_DOUBLE_BITS__) == 64
#  define HUGE_VAL		(1.7976931348623157E+308)	/* same as DBL_MAX (could also be +ve infinity) */
# endif

# if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || (defined(__cplusplus) && (__cplusplus >= 201103L))

#  if (__ECV_FLOAT_BITS__) == 32
#   define HUGE_VALF	(3.40282347E+38F)	/* same as FLT_MAX (could also be +ve infinity) */
#  endif

#  if (__ECV_LONG_DOUBLE_BITS__) == 64
#   define HUGE_VALL	(1.7976931348623157E+308)	/* same as LDBL_MAX (could also be +ve infinity) */
#  endif

#  if (__ECV_LONG_DOUBLE_BITS__) == 80
#   define HUGE_VALL	(1.1897314953572317650213E+4932L)	/* same as LDBL_MAX (could also be +ve infinity) */
#  endif

#  define INFINITY		(HUGE_VALF * 2.0F)

#  define NAN			(1)		/* assume NaNs are available */

int _ecv_fpclassifyf(float x);
int _ecv_fpclassifyd(double x);
int _ecv_fpclassifyl(long double x);

#  define fpclassify(_x) (sizeof(_x) == sizeof(float) \
							? _ecv_fpclassifyf(_x) \
							: sizeof(_x) == sizeof(double) \
								? _ecv_fpclassifyd(_x) \
								: _ecv_fpclassifyl(_x))

#  define FP_ZERO		(0)
#  define FP_SUBNORMAL	(1)
#  define FP_NORMAL		(2)
#  define FP_INFINITE	(3)
#  define FP_NAN		(4)

#  define isfinite(_x)	(fpclassify(_x) <= FP_NORMAL)
#  define isinf(_x)		(fpclassify(_x) == FP_INFINITE)
#  define isnan(_x)		(fpclassify(_x) == FP_NAN)

# endif

double acos(double d) _ecv_pre(-1.0 <= d; d <= 1.0);
double asin(double d) _ecv_pre(-1.0 <= d; d <= 1.0);
double atan(double);
double atan2(double, double);
double cos(double);
double sin(double);
double tan(double);
double cosh(double);
double sinh(double);
double tanh(double);

double exp(double);
double frexp(double, int *_pexp) _ecv_writes(*_pexp);
double ldexp(double, int);
double log(double d) _ecv_pre(d > 0.0);
double log10(double d) _ecv_pre(d > 0.0);
double modf(double, double *_iptr) _ecv_writes(*_iptr);

double pow(double _arg1, double _arg2) _ecv_returns(_arg1 _ecv_pow _arg2);
double sqrt(double d) _ecv_pre(d >= 0.0);

double ceil(double);
double fabs(double _arg) _ecv_returns((_arg >= 0.0) ? _arg : -_arg);

double floor(double);
double fmod(double a, double b)
	_ecv_pre(b != 0.0)
	_ecv_post((a >= 0.0 && b >= 0.0) => (_ecv_result >= 0.0 && _ecv_result < b));

#ifdef __cplusplus
/* Additional overloads for C++ 2003 */
float abs (float _arg) _ecv_returns((_arg >= 0.0) ? _arg : -_arg);
float acos (float f) _ecv_pre(-1.0 <= f; f <= 1.0);
float asin (float f) _ecv_pre(-1.0 <= f; f <= 1.0);
float atan (float);
float atan2(float, float);
float ceil (float);
float cos (float);
float cosh (float);
float exp (float);
float fabs (float _arg) _ecv_returns((_arg >= 0.0) ? _arg : -_arg);
float floor(float);
float fmod (float a, float b) _ecv_pre(b != 0.0);
float frexp(float, int *_pexp) _ecv_writes(*_pexp);
float ldexp(float, int);
float log (float f) _ecv_pre(f > 0.0);
float log10(float f) _ecv_pre(f > 0.0);
float modf (float, float *_iptr) _ecv_writes(*_iptr);
float pow (float _arg1, float _arg2) _ecv_returns(_arg1 _ecv_pow _arg2);
float pow (float _arg1, int _arg2) _ecv_returns(_arg1 _ecv_pow _arg2);
float sin (float);
float sinh (float);
float sqrt (float f) _ecv_pre(f >= 0.0);
float tan (float);
float tanh (float);

double abs(double _arg) _ecv_returns((_arg >= 0.0) ? _arg : -_arg);
double pow(double _arg1, int _arg2) _ecv_returns(_arg1 _ecv_pow _arg2);

long double abs (long double _arg) _ecv_returns((_arg >= 0.0) ? _arg : -_arg);
long double acos (long double d) _ecv_pre(-1.0 <= d; d <= 1.0);
long double asin (long double d) _ecv_pre(-1.0 <= d; d <= 1.0);
long double atan (long double);
long double atan2(long double, long double);
long double ceil (long double);
long double cos (long double);
long double cosh (long double);
long double exp (long double);
long double fabs (long double _arg) _ecv_returns((_arg >= 0.0) ? _arg : -_arg);
long double floor(long double);
long double fmod (long double a, long double b) _ecv_pre(b != 0.0);
long double frexp(long double, int *_pexp) _ecv_writes(*_pexp);
long double ldexp(long double, int);
long double log (long double d) _ecv_pre(d > 0.0);
long double log10(long double d) _ecv_pre(d > 0.0);
long double modf (long double, long double *_iptr) _ecv_writes(*_iptr);
long double pow (long double _arg1, long double _arg2) _ecv_returns(_arg1 _ecv_pow _arg2);
long double pow (long double _arg1, int _arg2) _ecv_returns(_arg1 _ecv_pow _arg2);
long double sin (long double);
long double sinh (long double);
long double sqrt (long double d) _ecv_pre(d >= 0.0);
long double tan (long double);
long double tanh (long double);
#endif

#else
# error "Missing macro definitions! Use this include file only when running Escher C verifier."
#endif

#endif

/* End */
