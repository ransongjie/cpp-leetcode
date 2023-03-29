#include <iostream>
#include <vector>
using namespace std;
/**
 * 剑指 Offer II 089. 房屋偷盗最高金额
 * 相邻的房间都被偷盗，会触发报警
 */
class Solution {
public:
    /**
     * dp[i]=偷盗0~i间房能获取的最大收益
     * dp[i]=Math.max(dp[i-2]+nums[i],dp[i-1]);
     * 偷第i-2间房和第i间房
     * 偷第i-1间房
     * @param nums
     * @return
     */
    int rob2(vector<int>& nums) {
        //特殊情况
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        //初始状态
        int n = nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        //状态转移
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }

        //
        return dp[n-1];
    }

    /**
     * 动态规划优化
     * @param nums
     * @return
     */
    int rob(vector<int>& nums) {
        //特殊情况
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        //初始状态
        int n = nums.size();
        int pre=nums[0];
        int cur=max(nums[0],nums[1]);

        //状态转移
        for(int i=2;i<n;i++){
            int nxt=max(pre+nums[i],cur);
            pre=cur;
            cur=nxt;
        }

        //
        return cur;
    }
};