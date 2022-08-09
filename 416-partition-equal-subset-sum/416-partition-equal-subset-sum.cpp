class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        //sum of array
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        //if the sum of all ements of array is not even then it cannot be divided to equal sum subsets. 
        if(sum%2!=0)
            return false;
        sum=sum/2; //we just look for the sum
        int dp[n+1][sum+1];
        //initialization
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0)
                    dp[i][j]=false;
                if(j==0)
                    dp[i][j]=true;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j]; //include it or leave it
                else
                    dp[i][j]=dp[i-1][j]; //leave it
            }
        }
        return dp[n][sum];
    }
};