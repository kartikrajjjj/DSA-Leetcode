//building recurssion basics curretly. Will solve by DP later
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;
        else if(n==2) return 1;
        return fib(n-1) + fib(n-2);
    } 
};