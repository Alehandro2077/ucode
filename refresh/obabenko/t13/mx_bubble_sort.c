int mx_strcmp(const char *s1, const char *s2);

int mx_bubble_sort(char **arr, int size) {
    if(!arr){
        return 0;
    }
    int sort = 1, ct = 0;

    while(sort) {
        sort = 0;
        for(int i = 0; i < size - 1; i++) {
            if(mx_strcmp(arr[i], arr[i+1]) > 0) {
                char *tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                sort = 1;
                ct++;
            }
        }
    }

    return ct;
}

