/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <string>
#include <vector>

using namespace std;
class Solution {
private:
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    
public:
    void traversal(TreeNode* node, vector<int> &paths, vector<string> &results){
        paths.push_back(node->val);
        if(node->left == NULL && node->right == NULL){
            string result;
            for(int i = 0; i < paths.size() - 1; i++){
                result += to_string(paths[i]);
                result += "->";
            }
            result += to_string(paths[paths.size() - 1]);
            results.push_back(result);
            return;
        }
        if(node->left){
            traversal(node->left, paths, results);
            paths.pop_back();
        }
        if(node->right){
            traversal(node->right, paths, results);
            paths.pop_back();
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> paths;
        vector<string> results;
        traversal(root, paths, results);
        return results;
    }
};