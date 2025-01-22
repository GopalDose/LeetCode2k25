class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        int j = 2;
        int i = 2;
        int n = nums.size();
        while(j<n){
            if(nums[i-2] != nums[j]){
                nums[i++] = nums[j];
            }
            j++;
        }
        return min(n, i);
    }
};