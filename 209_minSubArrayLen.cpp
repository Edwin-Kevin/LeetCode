#include<vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0; // 头部指针
        int result = INT32_MAX;  // 子数组长度
        int subLength = 0;    // 滑动窗口长度
        int sum = 0;    // 滑动窗口数值之和
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum >= target){
                subLength = (j - i + 1);
                result = min(result, subLength);
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};