int mx_factorial_iter(int n) {
    if(n < 0 || n > 2147483647) return 0;

    int res = 1;
    for(int i = 2; i <= n; i++){
        res *= i;

        if(res > 2147483647 - res){
            return 0;
        }
    }

    return res;
}

