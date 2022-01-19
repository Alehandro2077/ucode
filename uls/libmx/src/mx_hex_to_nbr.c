#include <stdio.h>
#include "../inc/libmx.h"
unsigned long mx_hex_to_nbr(const char *hex)
{
    if(!hex)
    {
        return 0;
    }

    unsigned long res = 0;
    int len = 0;

    for(; hex[len]; len++)
    {
        unsigned long tmp = 0;
        if(mx_isalpha(hex[len]))
        {
            if((hex[len] >= 'a' && hex[len] <= 'f') || (hex[len] >= 'A' && hex[len] <= 'F'))
            {
                tmp = (unsigned long)hex[len] + 10;
                tmp -= (mx_isupper(hex[len]) ? 'A' : 'a');
            }
            else
            {
                return 0;
            }
        }
        else if(mx_isdigit(hex[len]))
        {
            tmp = (unsigned long)hex[len] -'0';
        }
        else
        {
            return 0;
        }

        res = res * 16 + tmp;
    }

    return res;
}


