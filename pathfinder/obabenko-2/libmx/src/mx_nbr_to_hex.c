#include "../inc/libmx.h"

char  *mx_nbr_to_hex(unsigned long nbr)
{
    if(nbr == 0)
    {
        return "0";
    }

    unsigned long tmp = nbr;
    int len = 0;
    char c[] = "0123456789abcdef";

    while(tmp > 0)
    {
        len++;
        tmp /= 16;
    }

    char *res = mx_strnew(len);
    int ct = len - 1;

    while(nbr > 0)
    {
        res[ct] = c[nbr % 16];
        nbr /= 16;
        ct--;
    } 

    return res;

}


