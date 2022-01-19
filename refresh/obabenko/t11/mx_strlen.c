int mx_strlen(const char *s) {
    if(!s) {
        return 0;
    }

    int sz = 0;
    for(int i = 0; s[i]; i++)
    {
        sz++;
    }
    return sz;
}

