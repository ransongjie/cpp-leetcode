#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/**
 * 剑指 Offer II 102. 加减的目标值方案数目
 * 输入：nums[] target
 * 操作：向数组中的每个整数前添加 '+' 或 '-' 构造一个 表达式
 * 输出：正数和+负数和= target 的不同表达式的数目
 * 类似于Solution101 分割等和子集 目标值是 数组和的一半
 *      Solution102 加减的目标值 目标值是 (sum-target)/2 数组中被添加负号的子序列之和
 */
class Solution {
public:
    /**
     * 初始阶段: 从子数组中含有0个元素 开始求 方案数
     * dp[i][j]: i个元素 sum(nums[0]~nums[i-1])=j 的方案数
     * dp[0][0]=1, 子数组中0个元素不选择任何数值等于0的方案数=1
     * dp[0][j]=0, 子数组中0个元素无法选择任何数值等于j的方案数=0
     * dp[i][j]
     * - j<nums[i], 不能选择nums[i], 往前看, dp[i][j]=dp[i-1][j]
     * - j>=nums[i], 可选可不选nums[i], dp[i][j]=dp[i-1][j-nums[i]]+dp[i-1][j]
     */
    int findTargetSumWays(vector<int>& nums, int target) {
        //特殊情况
        if(nums.empty()) return 0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<target) return 0;
        if((sum-target)%2==1) return 0;

        //初始状态
        int neg=(sum-target)/2;
        int m=nums.size()+1;
        int n=neg+1;
        vector<vector<int>> dp(m,vector<int>(n));
        for(int j=0;j<n;j++){
            dp[0][j]=0;
        }
        dp[0][0]=1;

        //状态转移
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                //dp[i]是个数 nums[i-1]是索引
                if(j<nums[i-1]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
            }
        }

        //
        return dp[m-1][n-1];
    }
};