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
 * Wraps GSL special functions for inclusion in MuParser.
 */

#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_sf_psi.h>
#include <muParser.h>
#include "gsl_mu.h"

using mu::Parser;
using mu::value_type;
using mu::valmap_type;

value_type mu_bessel_J(const value_type n, const value_type x) {
    if (n == 0) {
        return gsl_sf_bessel_J0(x);
    }
    else if (n == 1) {
        return gsl_sf_bessel_J1(x);
    }
    else {
        const int n_int = static_cast<int>(n);
        if (n_int != n) {
            throw mu::ParserError("first argument to Bessel function must be an integer");
        }
        return gsl_sf_bessel_Jn(n_int, x);
    }
}

value_type mu_psi(const value_type x) {
    const int x_int = static_cast<int>(x);
    if (x_int == x) {
        return gsl_sf_psi_int(x_int);
    }
    else {
        return gsl_sf_psi(x);
    }
}

void mu_load_gsl_sf(Parser& parser) {
    parser.DefineFun("J", mu_bessel_J);
    parser.DefineFun("psi", mu_psi);
}
