/*Memoization approach

Steps to convert Recursive code to memoization solution:

Create a dp[n] array initialized to -1.
Whenever we want to find the answer of a particular value (say n), we first check whether the answer is already calculated using the dp array(i.e dp[n] != -1 ). 
  If yes, simply return the value from the dp array.
If not, then we are finding the answer for the given value for the first time, 
we will use the recursive relation as usual but before returning from the function, we will set dp[n] to the solution we get.*/
#include <bits/stdc++.h>

using namespace std;

int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int mmSteps = INT_MAX;
        
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
      int jump = solveUtil(ind-j, height, dp, k)+ abs(height[ind]- height[ind-j]);
            mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind]= mmSteps;
    
}

int solve(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return solveUtil(n-1, height, dp, k);
}

int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  int k=2;
  vector<int> dp(n,-1);
  cout<<solve(n,height,k);
}
/*Tabulation approach

Declare a dp[] array of size n.
First initialize the base condition values, i.e dp[0] as 0.
Set an iterative loop which traverses the array( from index 1 to n-1) and for every index calculate jumpOne and jumpTwo and set dp[i] = min(jumpOne, jumpTwo).*/
#include <bits/stdc++.h>

using namespace std;

int solveUtil(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}

int solve(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return solveUtil(n, height, dp, k);
}

int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  int k=2;
  vector<int> dp(n,-1);
  cout<<solve(n,height,k);
}
