#include <iostream>
#include <vector>
using namespace std;

/**
 * 剑指 Offer II 095. 最长公共子序列
 */
class Solution {
public:
    /**
     * 两字符串的最长公共子序列，两字符串的子串的最长公共子序列
     * dp[i][j], 子串长度为i, 子串长度为j, 两子串的最长公共子序列
     * i=0或j=0, 空串和任何字符串的最长公共子序列都是0
     * i>0或j>0, 
     * - s1[i-1]=s2[j-1], dp[i][j]=dp[i−1][j−1]+1
     * - s1[i-1]!=s2[j-1], dp[i][j]=max(dp[i−1][j],dp[i][j−1])
     */
    int longestCommonSubsequence(string text1, string text2) {
        //初始状态, 当i=0或j=0时, dp[0][j]=0, dp[i][0]=0
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));//字符串的长度

        //状态转移 i和j代表子串长度
        for(int i=1;i<n1+1;i++){
            char ci=text1[i-1];
            for(int j=1;j<n2+1;j++){
                char cj=text2[j-1];
                if(ci==cj){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        //
        return dp[n1][n2];
    }
};