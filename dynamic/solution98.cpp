#include <iostream>
#include <vector>
using namespace std;

/**
 * 剑指 Offer II 098. 机器人行走路径的数目
 * 注意，机器人只能往下或右走
 * 输入，方格大小m,n
 * 输出，从方格左上角走到方格右下角的路径数量
 */
class Solution {
public:
    /**
     * dp[i][j], 从(0,0)走到(i,j)的路径数目
     * dp[i][0]=1;//往下走
     * dp[0][j]=1;//往右走
     * dp[i][j]=dp[i-1][j]+dp[i][j-1];//从上走到(i,j) 从左走到(i,j)
     */
    int uniquePaths(int m, int n) {
        //初始状态
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++){//一直往下走
            dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }

        //状态转移
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        //
        return dp[m-1][n-1];
    }
};