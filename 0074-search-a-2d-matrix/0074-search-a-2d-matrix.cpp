class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(); //3
        int m=matrix[0].size(); //4

        int low=0;
        int high=(n*m)-1;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[mid/m][mid%m]==target){
                return true;
            }
            else if(matrix[mid/m][mid%m]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
};