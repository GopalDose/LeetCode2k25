class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> ans;
        int sum = 0;

        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j < i; j++){
                int p = nums[i]* nums[j];
                sum += ans[p]*8;
                ans[p]++;
            }
        }

        return sum;
    }
};