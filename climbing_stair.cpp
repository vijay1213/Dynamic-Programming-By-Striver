class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) {
            return 1;
        }
        
        int left = climbStairs(n-1);
        int right = climbStairs(n-2);
        
        return left + right;
        
        
    }
};

// using DP
class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp(n+1);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
        
    }
};
