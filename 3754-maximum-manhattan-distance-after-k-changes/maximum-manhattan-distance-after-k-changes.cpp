class Solution {
public:
    int maxDistance(string s, int k) {
        int maxDist = 0;
        int northMoves = 0, southMoves = 0, eastMoves = 0, westMoves = 0;

        for (char move : s) {
            if (move == 'N') northMoves++;
            else if (move == 'S') southMoves++;
            else if (move == 'E') eastMoves++;
            else westMoves++;

            int oppositeCancels = min(northMoves, southMoves) + min(eastMoves, westMoves);
            maxDist = max(maxDist, northMoves + southMoves + eastMoves + westMoves - max(0, 2 * (oppositeCancels - k)));
        }
        
        return maxDist;
    }
};
