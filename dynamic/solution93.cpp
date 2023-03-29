#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * 剑指 Offer II 093. 最长斐波那契数列
 * 找到 arr 中最长的斐波那契式的子序列的长度。如果一个不存在，返回  0 。
 * 斐波那契式子序列
 * - arr[i]>arr[j]>arr[k]且arr[k]+arr[j]=arr[i]
 */
class Solution {
public:
    /**
     * arr[k],arr[j],arr[i]
     * dp[j][i]: 以arr[j],arr[i]为最后两个数字的最长斐波拉契子序列
     * int k=map.getOrDefault(arr[i]-arr[j], -1);
     * - k>=0: dp[j][i]=Math.max(3,dp[k][j]+1);
     * - k<0: dp[j][i]=dp[j][i]
     * @param arr
     * @return
     */
    int lenLongestFibSubseq(vector<int>& arr) {
        //Map<arr[i]元素值,下标>
        unordered_map<int,int> num_idx;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            num_idx[arr[i]]=i;
        }

        // 初始状态
        vector<vector<int>> dp(n,vector<int>(n));//cpp 二维向量

        //状态转移, arr[k],arr[j],arr[i]
        int maxr=0;
        for(int i=0;i<n;i++){
            /**
             * 倒序寻找以i结尾的可能的斐波那契式子序列
             * - 当arr[j]×2>arr[i]时，才满足arr[k]<arr[j]，即可能存在arr[k]，遍历更小的j
             * - 当arr[j]×2≤arr[i]时，不满足arr[k]<arr[j]，即不可能存在arr[k]，不遍历更小的j
             */
            for(int j=i;j>=0&&2*arr[j]>arr[i];j--){
                int k=-1;
                if(num_idx.count(arr[i]-arr[j])){//cpp 存在=1, 不存在=0
                    k=num_idx[arr[i]-arr[j]];//cpp value=map[key]
                }
                if(k!=-1){
                    dp[j][i]=max(3,dp[k][j]+1);
                }
                maxr=max(maxr,dp[j][i]);
            }
        }

        //
        return maxr;
    }
};