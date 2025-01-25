class Solution {
public:
    int Row(vector<vector<int>>& mat, int col){
        int maxi = 0;
        int ind = -1;

        for(int i = 0; i<mat.size(); i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int start = 0;
        int end = mat[0].size()-1;
        int mid = 0;

        while(start <= end){
            mid = (start+end)/2;
            int row = Row(mat, mid);
            int left = mid-1 < 0 ? -1 : mat[row][mid-1];
            int right = mid+1 > mat[0].size()-1 ? -1 : mat[row][mid+1];
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }
            else if(mat[row][mid] < left){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        return {-1, -1};
    }
};