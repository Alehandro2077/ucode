void mx_sort_arr_int(int *arr, int size) {
    if(!arr) {
        return;
    }
    if(size < 1) {
        return;
    }

    int sorted = 1;

    while(sorted) {
        sorted = 0;

        for(int i = 0; i< size - 1; i++) {
            if(arr[i] > arr[i+1]) {
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                sorted = 1;
            }
        }
    }
}


