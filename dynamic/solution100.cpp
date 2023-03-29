#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 剑指 Offer II 100. 三角形行走最小路径之和
 * 三角形形状
 * [2]
 * [3,4]
 * [6,5,7]
 * [4,1,8,3]
 * 分析：
 * - 第1行有1个元素，第2行2个元素，...，第n行n个元素
 * - 移动，往下 或 往右下
 * 注意：
 * - Solution99是正方形，到达同一个终点
 * - Solution100是三角形，到达底边，有多个终点
 */
class Solution {
public:
    /**
     * 从(0,0)到底边的最小路径和
     * dp[0][0]=triangle[0][0]
     * dp[i][0]=dp[i-1][0]+triangle[i][j]
     * dp[i][i]=dp[i-1][i-1]+triangle[i][i]
     * dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j]
     */
    int minimumTotal(vector<vector<int>>& triangle) {
        //初始状态
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n));
        dp[0][0]=triangle[0][0];

        //状态转移
        for(int i=1;i<triangle.size();i++){
            //往下走
            dp[i][0]=dp[i-1][0]+triangle[i][0];
            //
            for(int j=1;j<i;j++){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
            }
            //走斜边
            dp[i][i]=dp[i-1][i-1]+triangle[i][i];
        }

        //
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};