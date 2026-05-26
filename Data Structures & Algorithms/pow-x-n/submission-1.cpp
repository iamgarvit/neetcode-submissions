class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1)    return 1/x;

        if (n > 0) {
            if (n % 2 == 0) {
                return pow(x, n/2) * pow(x, n/2);
            }
            return x * pow(x, n/2) * pow(x, n/2);
        }
        if (n % 2 == 0) {
            return pow(x, n/2) * pow(x, n/2);
        }
        return (1/x) * pow(x, n/2) * pow(x, n/2);
    }
};
