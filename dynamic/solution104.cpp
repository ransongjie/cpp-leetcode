#include <iostream>
#include <vector>
using namespace std;
/**
 * 剑指 Offer II 104. 排列的数目，和等于target的排列的数目
 */
class Solution {
public:
    /**
     * 和等于target的排列的数目，和等于0的排列的数目，和等于1的排列额数目
     * dp[target]=和等于target的排列的数目，方案数
     * dp[0]=1
     * i>=nums[j]: dp[i]+=dp[i-nums[j]]
     */
    int combinationSum4(vector<int>& nums, int target) {
        //初始状态
        int m=target+1;
        int n=nums.size();
        vector<unsigned long int> dp(m);
        dp[0]=1;

        //状态转移
        for(int i=0;i<m;i++){
            //使用nums中的值组成i
            for(int j=0;j<n;j++){
                if(i>=nums[j])dp[i]+=dp[i-nums[j]];
            }
        }

        //
        return dp[m-1];
    }
};