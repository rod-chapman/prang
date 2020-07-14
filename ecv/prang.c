/*======================================================================================================================
 * SOURCE CODE FILE: WHprang.c - Wichmann-Hill 16-bit pseudorandom number generator test
*/

#include <ecv.h>
#undef result
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

static const int LIMIT = 80;

static const short M1	=	((short) 30269);	/* 1st 16-bit prime modulus					*/
static const short r1	=	((short)   171);	/* a primitive root mod M1					*/
static const short a1	=	((short)   177);	/* 1st auxiliary value used in calculation	*/
static const short b1	=	((short)	 2);	/* 2nd auxiliary value used in calculation	*/

static const short M2	=	((short) 30307);	/* 2nd 16-bit prime modulus					*/
static const short r2	=	((short)   172);	/* a primitive root mod M2					*/
static const short a2	=	((short)   176);	/* 1st auxiliary value used in calculation	*/
static const short b2	=	((short)    35);	/* 2nd auxiliary value used in calculation	*/

static const short M3	=	((short) 30323);	/* 3rd 16-bit prime modulus					*/
static const short r3	=	((short)   170);	/* a primitive root mod M3					*/
static const short a3	=	((short)   178);	/* 1st auxiliary value used in calculation	*/
static const short b3	=	((short)    63);	/* 2nd auxiliary value used in calculation	*/

static short p1 = (short) 1;					/* initialise 1st sequence value 			*/
static short p2 = (short) 2;					/* initialise 2nd sequence value 			*/
static short p3 = (short) 3;					/* initialise 3rd sequence value 			*/

ghost(
bool invariant1() returns(p1 > 0 && p1 < M1 && p2 > 0 && p2 < M2 && p3 > 0 && p3 < M3);
)

/*----------------------------------------------------------------------------------------------------------------------
 * Wichmann-Hill 16-bit pseudorandom number generator function                                                        */

double WHprang (void)
writes(p1; p2; p3)
pre(invariant1())
post(_ecv_result > 0.0; _ecv_result < 1.0; invariant1())
{
	/* first, get required quotients and remainders	*/

	div_t div1 = div((int)p1, (int)a1);									/*### PRECOND: (p1 > 0) and (p1 < M1)     :###*/
	assert(p1 < a1 => div1.rem == p1; p1 >= a1 => div1.quot != 0);		// help the prover to case-split
	assert(div1.rem != 0 || div1.quot != 0);

	div_t div2 = div((int)p2, (int)a2);									/*### PRECOND: (p2 > 0) and (p2 < M2)     :###*/
	assert(p2 < a2 => div2.rem == p2; p2 >= a2 => div2.quot != 0);		// help the prover to case-split
	assert(div2.rem != 0 || div2.quot != 0);

	div_t div3 = div((int)p3, (int)a3);									/*### PRECOND: (p3 > 0) and (p3 < M3)     :###*/
	assert(p3 < a3 => div3.rem == p3; p3 >= a3 => div3.quot != 0);		// help the prover to case-split
	assert(div3.rem != 0 || div3.quot != 0);

	/* now calculate next values for p1, p2, p3 using the auxiliary value method to avoid 16-bit overflow */

	p1 = r1 * (short)(div1.rem) - b1 * (short)(div1.quot);
	assert(p1 > -M1; p1 != 0; p1 < M1);
	p2 = r2 * (short)(div2.rem) - b2 * (short)(div2.quot);
	assert(p2 > -M2; p2 != 0; p2 < M2);
	p3 = r3 * (short)(div3.rem) - b3 * (short)(div3.quot);
	assert(p3 > -M3; p3 != 0; p3 < M3);

    p1 += (int)(p1 < 0) * M1;												/*### POSTCOND: (p1 > 0) and (p1 < m1)    :###*/
    p2 += (int)(p2 < 0) * M2;												/*### POSTCOND: (p2 > 0) and (p2 < M2)    :###*/
    p3 += (int)(p3 < 0) * M3;												/*### POSTCOND: (p3 > 0) and (p3 < M3)    :###*/

    /* note: the above 3 lines conditionally increment the values without
	 * branching; there is *exactly one simple path* through the function
	 */

	assert(invariant1());

	{	/* now calculate and return the fractional part of the sum of p1, p2, and p3	*/

		double raux1 = (double)p1/(double)M1;	/* compute intermediate term in p1	*/
		double raux2 = (double)p2/(double)M2;	/* compute intermediate term in p2	*/
		double raux3 = (double)p3/(double)M3;	/* compute intermediate term in p3	*/

		assert(raux1 > 0.0; raux2 > 0.0; raux3 > 0.0);

		assert(raux1 + raux2 + raux3 > 0.0);
		double result = fmod( raux1 + raux2 + raux3, 1.0);		/*### POSTCOND: (result > 0) and (result < 1.0)	  :###*/

		return result;	/* return final pseudorandom value	*/
	}

}
/* End of WHprang
 * -------------------------------------------------------------------------------------------------------------------*/


/* main routine to run call the function LIMIT times in sequence	*/

int main(void) writes(p1; p2; p3; _ecv_files)
{
	// Initialise p1, p2, p3 explicitly because eCv doesn't treat 'main' specially
	p1 = 1;
	p2 = 2;
	p3 = 3;

	const int limit = LIMIT;
	int       count = 0;

	printf ("\nUSHRT_MAX = %i\n\n", USHRT_MAX);

	while (count < limit)
	writes(p1; p2; p3; _ecv_files; count)		// this clause is optional, eCv will infer it anyway
	keep(invariant1())
	decrease(limit - count)
	{
		printf("%lf\n", WHprang());
		++count;
	}

	return 0;
}

/* END OF SOURCE CODE FILE: WHprang.c
 * =====================================================================================================================
 */
