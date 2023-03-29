#include <iostream>
#include <vector>
using namespace std;
/**
 * 剑指 Offer II 107. 矩阵中的距离, 癌细胞感染。
 * 给定一个由 0 和 1 组成的矩阵 mat，请输出一个大小相同的矩阵。
 * 其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
 */
class Solution {
public:
    /**
     * f[i][j]：(i,j)到最近的0的距离
     * 分阶段：从四周的方向到0的最短距离 》f[i][j]到0的最短距离
     * 从左上角开始移动
     * - 往后：f[i][j] = Math.min(f[i][j], f[i - 1][j] + 1);
     * - 往左：f[i][j] = Math.min(f[i][j], f[i][j - 1] + 1);
     * 从左下角开始移动
     * - 往下：f[i][j] = Math.min(f[i][j], f[i + 1][j] + 1);
     * - 往左：f[i][j] = Math.min(f[i][j], f[i][j - 1] + 1);
     * 从右上角开始移动
     * - 往后：f[i][j] = Math.min(f[i][j], f[i - 1][j] + 1);
     * - 往右：f[i][j] = Math.min(f[i][j], f[i][j + 1] + 1);
     * 从右下角开始移动
     * - 往下：f[i][j] = Math.min(f[i][j], f[i + 1][j] + 1);
     * - 往右：f[i][j] = Math.min(f[i][j], f[i][j + 1] + 1);
     * @param mat
     * @return
     */
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        //初始状态
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX/2));//不能初始化为INT_MAX 后面有+法 防止越界
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                }
            }
        }        

        //状态转移
        //从左上角到f[i][j]
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0)dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                if(j>0)dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            }
        }

        //从左下角到f[i][j]
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                if(i>0)dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                if(j<n-1)dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
            }
        }

        //从右下角到f[i][j]
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i<m-1)dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
                if(j<n-1)dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
            }
        }

        //从右上角到f[i][j]
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i<m-1)dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
                if(j>0)dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            }
        }

        //
        return dp;
    }
};