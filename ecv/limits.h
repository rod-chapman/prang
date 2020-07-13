/* File limits.h supplied with Escher C Verifier.
 * Use this file only if you are using the eCv preprocessor.
 * If you wish to use a compiler to preprocess C/C++ source instead, then
 *  you should use the standard include files supplied with that compiler.
 */

#if !defined(__ecv_limits_h_included__)
#define __ecv_limits_h_included__

#pragma ECV noverify

#if defined(__ECV__) && defined(__ECV_CHAR_UNSIGNED__) && defined(__ECV_WCHAR_UNSIGNED__) \
 && defined(__ECV_CHAR_BITS__) && defined(__ECV_WCHAR_BITS__) \
 && defined(__ECV_SHORT_BITS__) && defined(__ECV_INT_BITS__) && defined(__ECV_LONG_BITS__) \
 && defined(__ECV_LONG_LONG_BITS__) && defined(__ECV_POINTER_BITS__) \
 && defined(__ECV_FLOAT_BITS__) && defined(__ECV_DOUBLE_BITS__) && defined(__ECV_LONG_DOUBLE_BITS__)

# define CHAR_BIT	(__ECV_CHAR_BITS__)

/* C doesn't allow us to define SCHAR_MIN in terms of CHAR_BIT using shifting in a way that is legal in preprocessor expressions and is also MISRA compliant.
 * So we have to resort to supporting fixed bit widths only.
 * eCv assumes 2's complement representation.
 */

# define __ECV_S8_MIN__		(-128)
# define __ECV_S8_MAX__		(127)
# define __ECV_U8_MAX__		(255)

# define __ECV_S16_MIN__	(-32768)
# define __ECV_S16_MAX__	(32767)
# define __ECV_U16_MAX__	(65535)

# define __ECV_S32_MIN__	(-2147483648)
# define __ECV_S32_MAX__	(2147483647)
# define __ECV_U32_MAX__	(4294967295)

# define __ECV_S64_MIN__	(-9223372036854775808)
# define __ECV_S64_MAX__	(9223372036854775807)
# define __ECV_U64_MAX__	(18446744073709551615)

# if __ECV_CHAR_BITS__ == 8
#  define SCHAR_MIN			(__ECV_S8_MIN__)
#  define SCHAR_MAX			(__ECV_S8_MAX__)
#  define UCHAR_MAX			(__ECV_U8_MAX__)
# else
#  error Unsupported value of CHAR_BIT
# endif

# if __ECV_SHORT_BITS__ == 16
#  define SHRT_MIN			(__ECV_S16_MIN__)
#  define SHRT_MAX			(__ECV_S16_MAX__)
#  define USHRT_MAX			(__ECV_U16_MAX__)
# elif __ECV_SHORT_BITS__ == 32
#  define SHRT_MIN			(__ECV_S32_MIN__)
#  define SHRT_MAX			(__ECV_S32_MAX__)
#  define USHRT_MAX			(__ECV_U32_MAX__)
# else
#  error Unsupported value __ECV_SHORT_BITS__
# endif

# if __ECV_INT_BITS__ == 16
#  define INT_MIN			(__ECV_S16_MIN__)
#  define INT_MAX			(__ECV_S16_MAX__)
#  define UINT_MAX			(__ECV_U16_MAX__)
# elif __ECV_INT_BITS__ == 32
#  define INT_MIN			(__ECV_S32_MIN__)
#  define INT_MAX			(__ECV_S32_MAX__)
#  define UINT_MAX			(__ECV_U32_MAX__)
# else
#  error Unsupported value __ECV_INT_BITS__
# endif

# if __ECV_LONG_BITS__ == 32
#  define LONG_MIN			(__ECV_S32_MIN__)
#  define LONG_MAX			(__ECV_S32_MAX__)
#  define ULONG_MAX			(__ECV_U32_MAX__)
# elif __ECV_LONG_BITS__ == 64
#  define LONG_MIN			(__ECV_S64_MIN__)
#  define LONG_MAX			(__ECV_S64_MAX__)
#  define ULONG_MAX			(__ECV_U64_MAX__)
# else
#  error Unsupported value __ECV_LONG_BITS__
# endif

# if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || (defined(__cplusplus) && (__cplusplus >= 201103L))

# if __ECV_LONG_LONG_BITS__ == 32
#  define LLONG_MIN			(__ECV_S32_MIN__)
#  define LLONG_MAX			(__ECV_S32_MAX__)
#  define ULLONG_MAX		(__ECV_U32_MAX__)
# elif __ECV_LONG_LONG_BITS__ == 64
#  define LLONG_MIN			(__ECV_S64_MIN__)
#  define LLONG_MAX			(__ECV_S64_MAX__)
#  define ULLONG_MAX		(__ECV_U64_MAX__)
# else
#  error Unsupported value __ECV_LONG_LONG_BITS__
# endif

# endif

/* In defining MB_LEN_MAX we assume multibyte characters are encoded in UTF-8 form */
# define MB_LEN_MAX		(4)

#else
# error "Missing macro definitions!. Use this include file only when running Escher C Verifier."
#endif

#endif

/* End */
