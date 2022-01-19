#include "../inc/libmx.h"

char *mx_itoa(int number) {
    int tmp = number, ct = 0;

    if (number == 0) {
        return "0";
    }
    if (number == -2147483648){
        return "-2147483648";
    }

    if(tmp < 0) {
        ct++;
        tmp *= -1;
    }
    while(tmp != 0) {
        tmp /= 10;
        ct++;
    }

    char *res = mx_strnew(ct);
    if(number < 0) {
        res[0] = '-';
        number *= -1;
    }
    res[ct--] = '\0';
    for(int i = ct; number != 0 && i >= 0; i--) {
        res[i] = number % 10 + '0';
        number /= 10;
    }

    return res;
}


