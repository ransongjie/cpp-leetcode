#include <iostream>
#include <vector>
using namespace std;
/**
 * 剑指 Offer II 099. 机器人行走最小路径之和
 * 注意，机器人只能往下或右走
 * 输入，grid[i][j]=权重
 * 输出，从左上角 到 右下角 的最小路径权重和
 */
class Solution {
public:
    /**
     * dp[i][j]=从(0,0)走到(i,j)的最小路径和
     * dp[0][0]=grid[0][0];
     * dp[0][j]=dp[0][j-1]+grid[0][j];//往下走
     * dp[i][0]=dp[i-1][0]+grid[i][0];//往右走
     * dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];//从上走到(i,j) 从左走到(i,j)的最小值
     */
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int m=grid.size();
        int n=grid[0].size();
        if(m==0){
            return 0;
        }
        if(n==0){
            return 0;
        }

        //初始状态
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=grid[0][0];//起点
        for(int i=1;i<m;i++){//一直往下走
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int j=1;j<n;j++){//一直往右走
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }

        //状态转移
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }

        //
        return dp[m-1][n-1];
    }
};