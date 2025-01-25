class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int mid) {
        int sum = 0;
        for (auto i : weights) {
            if (sum + i <= mid) {
                sum += i;
            } else {
                days--;
                sum = i;
                if (days <= 0) {
                    return false;
                }
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int e = accumulate(weights.begin(), weights.end(), 0);
        int s = *max_element(weights.begin(), weights.end());

        int mid = 0;
        while(s < e){
            mid = (s+e)/2;
            if(isPossible(weights, days, mid)){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};