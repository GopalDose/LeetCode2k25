class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;

        for (char c : s) {
            if (c == 'N') north++;
            else if (c == 'S') south++;
            else if (c == 'E') east++;
            else west++;

            int req = min(north, south) + min(east, west);
            ans = max(ans, north + south + east + west - max(0, 2 * (req - k)));
        }
        
        return ans;
    }
};
