#include "../inc/libmx.h"

int mx_sqrt(int x) {

    if (x <= 0) return 0;

    double sqrt, to_cmpr;
    sqrt = x / 2;
    to_cmpr = 0;

    while (sqrt != to_cmpr) {

        to_cmpr = sqrt;
        sqrt = (x / to_cmpr + to_cmpr) / 2;

    }

    int intResult = (int)sqrt;
    if ((intResult != sqrt) || (sqrt <= 0)) {
        return 0;
    }

    return sqrt;

}


