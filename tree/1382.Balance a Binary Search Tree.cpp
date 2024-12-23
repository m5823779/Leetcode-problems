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
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedArray;
        inorder(root, sortedArray);
        return construct(sortedArray, 0, sortedArray.size() - 1);
    }
private:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    TreeNode* construct(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        int m = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = construct(nums, start, m - 1);
        root->right = construct(nums, m + 1, end);
        return root;
    }
};