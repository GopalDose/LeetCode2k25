class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        // Inorder traversal using stack (iterative approach)
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }

        // Two-pointer approach on sorted 'ans' array
        int start = 0, end = ans.size() - 1;
        while (start < end) {
            int sum = ans[start] + ans[end];
            if (sum == k) return true;
            if (sum > k) end--;
            else start++;
        }

        return false;
    }
};
