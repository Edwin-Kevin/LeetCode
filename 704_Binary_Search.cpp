#include <vector>
#include <iostream>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        while(left <= right){
            middle = left + ((right - left) >> 1);
            if(nums[middle] > target){
                right = middle - 1;
            }
            else if(nums[middle] < target){
                left = middle + 1;
            }
            else{
                return middle;
            }
        }
        return -1;
    }
};