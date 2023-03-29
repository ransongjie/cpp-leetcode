#include <iostream>
#include <vector>
using namespace std;

/**
 * 剑指 Offer II 094. 最少回文分割
 */
class Solution {
public:
    /**
     * fss[i][j]=i~j是否回文串
     * fss[i][j]=s.charAt(i)==s.charAt(j)&&fss[i+1][j-1]
     * i和j两个字符是否相等&&i+1~j-1是否回文串
     * 
     * gs[i]=0~i最少分割次数
     * gs[i]=min(gs[i],gs[j]+1)
     * 0,...,j,...,i
     * @param s
     * @return
     */  
    int minCut(string s) {
        //初始状态
        int n =s.size();
        vector<vector<bool>> fss(n,vector<bool>(n,true));//cpp 二维向量创建并初始化

        //状态转移
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                fss[i][j]=fss[i+1][j-1]&&s[i]==s[j];
            }
        }

        //初始状态
        vector<int> gs(n,INT_MAX);//cpp INT_MAX

        //状态转移. 0~i之间切割. 0~j,j+1~i
        for(int i=0;i<n;i++){
            //0~i是回文串 分割次数为0
            if(fss[0][i]){
                gs[i]=0;
            }else{
                //0~i不是回文. 0~j,j+1~i
                for(int j=0;j<i;j++){
                    if(fss[j+1][i]){
                        gs[i]=min(gs[i],gs[j]+1);
                    }
                }
            }
        }

        //
        return gs[n-1];
    }
};