/*
 * Copyright (C) 2007-2015, the BAT core developer team
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 * For documentation see http://mpp.mpg.de/bat
 */

#include "BCPositiveDefinitePrior.h"

// ---------------------------------------------------------
BCPositiveDefinitePrior::BCPositiveDefinitePrior(BCPrior * prior)
    : BCPrior(),
      fPrior(prior)
{
}

// ---------------------------------------------------------
BCPositiveDefinitePrior::BCPositiveDefinitePrior(const BCPositiveDefinitePrior& other)
    : BCPrior(other),
      fPrior(other.fPrior->Clone())
{
}

// ---------------------------------------------------------
BCPositiveDefinitePrior::~BCPositiveDefinitePrior()
{
    delete fPrior;
}

// ---------------------------------------------------------
double BCPositiveDefinitePrior::GetRandomValue(double xmin, double xmax, TRandom* const R) const
{
    xmin = std::max<double>(xmin,0);
    xmax = std::max<double>(xmax,0);
    if (xmin == xmax)
        return std::numeric_limits<double>::quiet_NaN();
    return fPrior->GetRandomValue(xmin,xmax,R);
}
