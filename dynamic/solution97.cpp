#include <iostream>
#include <vector>
using namespace std;
/**
 * 剑指 Offer II 097. 子序列的数目
 * t在s中出现的次数，t可不连续
 */
class Solution {
public:
    /**
     * s中t出现的次数，s的子串中t的子串出现的次数
     * dp[i][j]=s[i:]中t[j:]出现的次数
     * - s[i]==s[j]: dp[i][j]=dp[i+1][j+1]+dp[i+1][j]
     * - s[i]!=s[j]: dp[i][j]=dp[i+1][j]
     */
    int numDistinct(string s, string t) {
        //特殊情况
        int n1=s.size();
        int n2=t.size();
        if(n2>n1){
            return 0;
        }

        //初始状态 s的任意子串都包含t的空子串
        //字串 字符数量 所以 +1
        vector<vector<unsigned long int>> dp(n1+1,vector<unsigned long int>(n2+1));
        for(int i=0;i<n1+1;i++){
            dp[i][n2]=1;
        }

        //状态转移
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                if(s.at(i)==t.at(j)){
                    //取相等的字符，不取相等的字符
                    dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
                }else{
                    dp[i][j]=dp[i+1][j];
                }
            }
        }

        //
        return dp[0][0];
    }
};