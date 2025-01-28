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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0,0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* temp = p.first;

            int x = p.second.first;
            int y = p.second.second;
            mp[x][y].insert(temp->val);

            if(temp->left){
                q.push({temp->left, {x-1, y+1}});
            }
            if(temp->right){
                q.push({temp->right, {x+1, y+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto p:mp){
            vector<int> n;
            for(auto i:p.second){
                n.insert(n.end(), i.second.begin(), i.second.end());
            }
            ans.push_back(n);
        }
        return ans;
    }
};