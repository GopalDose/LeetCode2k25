class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int white = 0;
        for(int i =0; i < k; i++){
            if(blocks[i] == 'W') white++;
        }
        int ans = white;
        for(int i = 1; k < n; i++,k++){
            if(blocks[i-1] == 'W') white--;
            if(blocks[k] == 'W') white++;
            ans = min(ans, white);
        }
        return ans < 0 ? 0 : ans;
    }
};