class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<n-i;j++){
                swap(matrix[i][j+i],matrix[j+i][i]);
            }
        }
        
    }
};
