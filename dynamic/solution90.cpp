#include <iostream>
#include <vector>
using namespace std;
/**
 * 剑指 Offer II 089. 环形房屋偷盗最高金额
 * 相邻的房间都被偷盗，会触发报警
 */
class Solution {
public:
    /**
     * max(0~len-2, 0~len-1)都分开考虑了
     * dp[i]=max(dp[i-2]+nums[i],dp[i-1])
     * 偷第i-2间房和第i间房，偷第i-1间房
     * @param nums
     * @return
     */
    int rob(vector<int>& nums) {
        //特殊情况
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        //
        int n =nums.size();
        return max(robRange(nums,0,n-2),robRange(nums,1,n-1));
    }

    //引用传递
    int robRange(vector<int>& nums, int start, int end) {
        //初始状态
        int pre=nums[start];
        int cur=max(nums[start],nums[start+1]);

        //状态转移
        for(int i=start+2;i<=end;i++){
            int nxt=max(pre+nums[i],cur);
            pre=cur;
            cur=nxt;
        }

        //
        return cur;
    }
};