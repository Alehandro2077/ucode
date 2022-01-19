#include "../inc/libmx.h"

static void sort(char **arr, int i, int j, int *count) {
    char *tmp = 0;
    tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;
    (*count)++;
}

int mx_quicksort(char **arr, int left, int right) {
    int middle = (left + right) / 2;
    int i = left;
    int j = right;
    int count = 0;

    if(!arr)
        return -1;
    if (i < j) {
        while (mx_strlen(arr[i]) < mx_strlen(arr[middle]))
            i++;
        while (mx_strlen(arr[j]) > mx_strlen(arr[middle]))
            j--;
        if (mx_strlen(arr[i]) != mx_strlen(arr[j])) 
            sort(arr, i, j, &count);
        if (++i < right)
            count += mx_quicksort(arr, i, right);
        if (--j > left)
            count += mx_quicksort(arr, left, j);
    }
    return count;
}


