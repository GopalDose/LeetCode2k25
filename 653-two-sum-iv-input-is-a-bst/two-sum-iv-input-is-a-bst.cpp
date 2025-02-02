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
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i<size;i++){
                TreeNode* t = q.front();
                q.pop();
                ans.push_back(t->val);

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }

        int start = 0;
        int end = ans.size()-1;
        sort(ans.begin(), ans.end());
        while(start < end){
            if(ans[start]+ans[end] == k && start != end) return true;
            if(ans[start]+ans[end] > k) end--;
            else{
                start++;
            }
        }

        return false;
    }
};