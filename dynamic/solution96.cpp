#include <iostream>
#include <vector>
using namespace std;
/**
 * 剑指 Odpdper II 096. 字符串交织
 * 给定三个字符串 s1、s2、s3，请判断 s3 能不能由 s1 和 s2 交织（交错） 组成。
 * 两个字符串 s 和 t 交织 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
 * - s = s1 + s2 + ... + sn
 * - t = t1 + t2 + ... + tm
 * - |n - m| <= 1
 * - 交织 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
 */
class Solution {
public:
    /**
     * dp[i][j], dp[s1的前i个元素][s2的前j个元素]=能否交织为s3的前i+j个元素
     * i>0, dp[i][j]=dp[i][j]||s1.charAt(i-1)==s3.charAt(i+j-1)&&dp[i-1][j]
     * j>0, dp[i][j]=dp[i][j]||s1.charAt(j-1)==s3.charAt(i+j-1)&&dp[i][j-1]
     */
    bool isInterleave2(string s1, string s2, string s3) {
        //特殊情况
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        if(n1+n2!=n3){
            return false;
        }

        //初始状态, 字符个数
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1));
        dp[0][0]=true;

        //状态转移
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i>0){//dp[i-1][j] s1[0~i-1]和s2[0~j]交织组成 s3
                    dp[i][j]=dp[i][j]||dp[i-1][j]&&s1.at(i-1)==s3.at(i+j-1);
                }
                if(j>0){
                    dp[i][j]=dp[i][j]||dp[i][j-1]&&s2.at(j-1)==s3.at(i+j-1);
                }
            }
        }

        //
        return dp[n1][n2];
    }

    /**
     * 滚动数组优化
     * - 数组dp的第i行只和第i−1行相关,去掉i这一维度,使用滚动方式代替行
     * - 滚动，第i行取决于第i-1行，等式右侧的dp[j]是代表dp[s1的前i-1个元素][s2的前j个元素]，左侧dp[j]代表dp[s1的前i个元素][s2的前j个元素]
     */
    bool isInterleave(string s1, string s2, string s3) {
        //特殊情况
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        if(n1+n2!=n3){
            return false;
        }

        //初始状态, 字符个数
        vector<int> dp(n2+1);
        dp[0]=true;

        //状态转移
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i>0){//dp[i-1][j] s1[0~i-1]和s2[0~j]交织组成 s3
                    // dp[i][j]=dp[i][j]||dp[i-1][j]&&s1.at(i-1)==s3.at(i+j-1);
                    dp[j]=dp[j]&&(s1.at(i-1)==s3.at(i+j-1));
                }
                if(j>0){
                    // dp[i][j]=dp[i][j]||dp[i][j-1]&&s2.at(j-1)==s3.at(i+j-1);
                    dp[j]=dp[j]||dp[j-1]&&(s2.at(j-1)==s3.at(i+j-1));
                }
            }
        }

        //
        return dp[n2];
    }
};