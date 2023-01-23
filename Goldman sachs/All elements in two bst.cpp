// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/

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
    void inorder(TreeNode* root,vector<int>& vec){
        if(root == NULL) return;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        inorder(root1,tree1);
        inorder(root2,tree2);

        int i=0;
        int j=0;
        vector<int> ans;
        while(i<tree1.size() && j<tree2.size()){
            if(tree1[i] <= tree2[j]){
               ans.push_back(tree1[i]);
               i++;
            }
            else{
                ans.push_back(tree2[j]);
                j++;
            }
        }
        while(i<tree1.size()){
            ans.push_back(tree1[i]);
            i++;
        }
        while(j<tree2.size()){
            ans.push_back(tree2[j]);
            j++;
        }
        return ans;
    }
};