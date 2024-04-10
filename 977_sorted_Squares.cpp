#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int k = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        while(i <= j){
            if((nums[i] * nums[i]) < (nums[j] * nums[j])){
                result[k--] = nums[j] * nums[j--];
            }
            else{
                result[k--] = nums[i] * nums[i++];
            }
        }
        return result;
    }
};