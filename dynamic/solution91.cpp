#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 剑指 Offer II 091. 粉刷房子
 * cost[i][j] j in [0,2] 三种不同颜色
 * 相邻房子的颜色不能一样
 */
class Solution {
public:
    /**
     * 最后一间房每种颜色都考虑了，最后一间房被刷成什么颜色总成本最低
     * dpnew[j]=costs[i][j]+Math.min(dp[(j+1)%3],dp[(j+2)%3]);
     * 第i间房刷成0色的成本+min(第i-1间房刷成1色的最小总成本+第i-1间房刷成2色的最小总成本)
     */
    int minCost(vector<vector<int>>& costs) {//引用传递
        //初始状态
        vector<int> dp(3);//当前房刷成什么颜色的最小成本
        for(int i=0;i<3;i++){
            dp[i]=costs[0][i];
        }

        //状态转移
        int n =costs.size();
        for(int i=1;i<n;i++){
            vector<int> dpnew(3);
            for(int j=0;j<3;j++){
                dpnew[j]=min(dp[(j+1)%3],dp[(j+2)%3])+costs[i][j];
            }
            dp=dpnew;
        }

        //
        return *min_element(dp.begin(),dp.end());//<algorithm>   
    }
};