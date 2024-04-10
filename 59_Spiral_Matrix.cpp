#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> resultMatrix(n, vector<int>(n, 0));
        int upper_Bound = 0, left_Bound = 0;
        int lower_Bound = n - 1, right_Bound = n - 1;
        int num = 1;

        while(num <= n * n){
            if(upper_Bound <= lower_Bound){
                // 顶部遍历
                for(int i = left_Bound; i <= right_Bound; i++){
                    resultMatrix[upper_Bound][i] = num++;
                }
                upper_Bound++;
            }
            if(right_Bound >= left_Bound){
                // 右侧遍历
                for(int i = upper_Bound; i <= lower_Bound; i++){
                    resultMatrix[i][right_Bound] = num++;
                }
                right_Bound--;
            }
            if(lower_Bound >= upper_Bound){
                // 底部遍历
                for(int i = right_Bound; i >= left_Bound; i--){
                    resultMatrix[lower_Bound][i] = num++;
                }
                lower_Bound--;
            }
            if(left_Bound <= right_Bound){
                // 左侧遍历
                for(int i = lower_Bound; i >= upper_Bound; i--){
                    resultMatrix[i][left_Bound] = num++;
                }
                left_Bound++;
            }
        }
        return resultMatrix;
    }
};