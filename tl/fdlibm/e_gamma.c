
/* @(#)e_gamma.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 */

/* _ieee754_gamma(x)
 * Return the logarithm of the Gamma function of x.
 *
 * Method: call _ieee754_gamma_r
 */

#include "fdlibm.h"
#include "fdlibm_intern.h"
