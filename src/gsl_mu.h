/*
 * Copyright (c) 2014 David Zaslavsky <diazona@ellipsix.net>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * Wraps GSL functions and constants for inclusion in MuParser.
 */

#include <muParser.h>

// All the loading functions: one per "section" of GSL
void mu_load_gsl_math(mu::Parser& parser);
void mu_load_gsl_sf(mu::Parser& parser);
// and a general one
void mu_load_gsl(mu::Parser& parser);

// All the functions that wrap GSL functions
mu::value_type mu_bessel_J(const mu::value_type n, const mu::value_type x);
mu::value_type mu_psi(const mu::value_type x);
