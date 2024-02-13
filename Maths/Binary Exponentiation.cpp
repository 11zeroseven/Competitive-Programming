long long power(long long x, long long y) {
    long long result = 1;
    while (y > 0) {
        if (y & 1) {
            result = result * x;
        }
        x = x * x;
        y >>= 1;
    }
    return result;
}
