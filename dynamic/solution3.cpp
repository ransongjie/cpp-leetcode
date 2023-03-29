#include<iostream>
#include <vector>
using namespace std;
/**
 * 剑指 Offer II 003. 前n个数字二进制中1的个数(0~n)
 */
class Solution{
public:
    /**
     * dp[i]=二进制表示中1的个数
     * dp[2k]=dp[k]=dp[k]+0
     * dp[2k+1]=dp[2k]+1=dp[k]+1
     * 
     * @param n
     * @return
     */
    vector<int> countBits2(int n){
        //初始状态
        //cpp 不需要new 跟基本类型用法一致
        vector<int> dp(n+1);//0~n
        dp[0]=0;

        //状态转移
        for(int i=1;i<=n;i++){
            if(i%2==0){
                dp[i]=dp[i>>1];
            }else{
                dp[i]=dp[i>>1]+1;
            }
        }

        //
        return dp;
    }

    /**
     * 统一奇偶判断
     * @param n
     * @return
     */
    vector<int> countBits(int n){
        //初始状态
        vector<int> dp(n+1);//0~n
        dp[0]=0;

        //状态转移
        for(int i=1;i<=n;i++){
            dp[i]=dp[i>>1]+(i&1);
        }

        //
        return dp;
    }
};