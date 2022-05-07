class Solution {
public:
    int digitSquareSum(int n) {
        int ans=0;
        while(n>=10) {
            ans+=(n%10)*(n%10);
            n=n/10;
        }
        ans+=n*n;
        return ans;
    }
    bool isHappy(int n) {
        if(digitSquareSum(n)==1)
            return true;
        
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while(slow != fast);
        if (slow == 1) return 1;
        else return 0;
    }
};