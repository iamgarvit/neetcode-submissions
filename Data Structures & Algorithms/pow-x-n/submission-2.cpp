class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1)    return 1/x;

        if (n > 0) {
            if (n % 2 == 0) {
                return myPow(x, n/2) * myPow(x, n/2);
            }
            return x * myPow(x, n/2) * myPow(x, n/2);
        }
        if (n % 2 == 0) {
            return myPow(x, n/2) * myPow(x, n/2);
        }
        return (1/x) * myPow(x, n/2) * myPow(x, n/2);
    }
};