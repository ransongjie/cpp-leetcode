#include <iostream>
using namespace std;
/**
 * 剑指 Offer II 092. 翻转字符，保持单调递增的最小翻转次数
 */
class Solution {
public:
    /**
     * 第i项目是1翻转为0的仍然递增的最小翻转次数：dp[i][0]=dp[i-1][0]+1
     * 第i项目是0翻转为1的仍然是递增的最小翻转次数：dp[i][1]=min(dp[i-1][0],dp[i-1][1])
     * @param s
     * @return
     */
    int minFlipsMonoIncr(string s) {
        //初始状态
        int dp0=0;//从-1项开始
        int dp1=0;//从-1项开始

        //状态转移
        int n = s.size();
        for(int i=0;i<n;i++){
            int dpnew0=dp0;
            int dpnew1=min(dp0,dp1);

            if(s[i]=='1'){//1翻成0 cpp string获取字符
                dpnew0=dp0+1;
            }else{//0翻成1
                dpnew1=min(dp0,dp1)+1;
            }

            dp0=dpnew0;
            dp1=dpnew1;
        }

        //
        return min(dp0,dp1);
    }
};