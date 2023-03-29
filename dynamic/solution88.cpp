#include <iostream>
#include <vector>
using namespace std;
/**
 * 剑指 Offer II 088. 爬楼梯的最少成本
 * 你可以选择从下标为 0 或 1 的元素作为初始阶梯。
 */
class Solution{
public:
    /**
     * dp[i]=min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);
     */
    int minCostClimbingStairs2(vector<int>& cost){//cpp 引用传递
        //初始状态
        int n =cost.size();
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=0;

        //状态转移
        for(int i=2;i<=n;i++){
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }

        //
        return dp[n];        
    }

    /**
     * 滚动数组优化
     * @param cost
     * @return
     */
    int minCostClimbingStairs(vector<int>& cost){
        //初始状态
        int pre=0;
        int cur=0;

        //状态转移
        int n = cost.size();
        for(int i=2;i<=n;i++){
            int nxt=min(cur+cost[i-1],pre+cost[i-2]);
            pre=cur;
            cur=nxt;
        }

        //
        return cur;
    }
};