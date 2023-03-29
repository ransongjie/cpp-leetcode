#include <iostream>
#include <vector>
using namespace std;
/**
 * 剑指 Offer II 103. 最少的硬币数目
 * 输入，coins[]硬币面值，硬币面值至少为1，amount 总金额，硬币数量无限
 * 输出，组成总金额的最少硬币个数; 没有任何一种硬币组合能组成总金额，返回 -1。
 */
class Solution {
public:
    /**
     * 组成amount所需最少硬币数量，组成子amount的最少硬币数量
     * dp[i]=组成i值的最小硬币数量
     * dp[0]=0
     * i>=coins[j]: dp[i]=min((dp[i-coints[j]])+1,dp[i]), 把每种币值都尝试下
     */
    int coinChange(vector<int>& coins, int amount) {
        //初始状态
        int m = coins.size();
        int n = amount+1;
        vector<int> dp(n,amount+1);//求最小值 所有元素初始化为amount+1
        dp[0]=0;

        //状态转移
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>=coins[j]) dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }

        //
        return dp[n-1]==amount+1?-1:dp[n-1];
    }
};