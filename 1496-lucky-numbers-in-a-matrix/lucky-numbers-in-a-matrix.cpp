class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;

        for(int i = 0; i < m; i++){
            int rowMin = matrix[i][0];
            int colIndex = 0;

            // find minimum in row i
            for(int j = 1; j < n; j++){
                if(matrix[i][j] < rowMin){
                    rowMin = matrix[i][j];
                    colIndex = j;
                }
            }

            // check if it's maximum in its column
            bool isLucky = true;
            for(int k = 0; k < m; k++){
                if(matrix[k][colIndex] > rowMin){
                    isLucky = false;
                    break;
                }
            }

            if(isLucky)
                result.push_back(rowMin);
        }

        return result;
    }
};
