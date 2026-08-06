class Solution {
public:
    int solve(int n) {
        int a=1;
        while(n>0) {
            a=a*(n%10);
            n=n/10;
            // n--;
        }
        return a;
    }

    int smallestNumber(int n, int t) {
        while(true) {
            if(solve(n)%t==0) {
                return n;
            }
            n++;
        }
    }
};