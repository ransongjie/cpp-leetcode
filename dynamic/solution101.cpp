#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
/**
 * 剑指 Offer II 101. 分割等和子集，选取数字和=数组和一半
  * 这道题与传统的「0−1背包问题」的区别：
 * - weight sum <= bag availabe weight:传统的「0−1背包问题」要求选取的物品的重量之和“不超过”背包的总容量，
 * - weight sum = bag availabe weight/2:这道题则要求选取的数字的和“恰好等于”整个数组的元素和的一半
 */
class Solution {
public:
    /**
     * 从数组中选取的数之和=数组和的一半=目标值。从数组的子序列中选取的数之和=目标值的子值
     * dp[i][j]= nums[0]~nums[i]选取的数=j
     * dp[i][0]=true;//从数组子序列中1个都不选择之和=0
     * dp[0][nums[0]]=true;//nums[0:0]选择了之和=nums[0]
     * dp[i][j]
     * - j<nums[i]: 不能选nums[i], dp[i][j]=dp[i-1][j]
     * - j>=nums[i]: 可选可不选nums[i], dp[i][j]=dp[i-1][j-nums[i]]|dp[i-1][j]
     */
    bool canPartition(vector<int>& nums) {
        //特殊情况
        if(nums.empty()) return false;
        int m=nums.size();
        if(m<2) return false;
        int sum=accumulate(nums.begin(),nums.end(),0);//cpp sum
        if(sum%2==1) return false;
        int max=*max_element(nums.begin(),nums.end());
        if(max>sum/2) return false;

        //初始状态
        int n=sum/2+1;
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++){
            dp[i][0]=true;
        }
        dp[0][nums[0]]=true;

        //状态转移
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(j<nums[i]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j-nums[i]]||dp[i-1][j];
            }
        }

        //
        return dp[m-1][n-1];
    }
};