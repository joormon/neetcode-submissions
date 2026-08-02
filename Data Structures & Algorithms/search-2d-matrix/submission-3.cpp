class Solution {
   public:
    // O(log(m * n))
    //Here we have transformed the 2d matrix into a flattened 1D array virtually 
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int mid_element = matrix[mid / n][mid % n];
            if (mid_element == target) 
                return true;
            if(mid_element<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
    }


    // This solution takes O(logM * logN)
    //  bool searchMatrix(vector<vector<int>>& matrix, int target)
    //  {
    //      int top=0;
    //      int bottom=matrix.size()-1;

    //     while(top<=bottom)
    //     {
    //         int row_mid=top+(bottom-top)/2;

    //         if(matrix[row_mid][0]<=target)
    //         {
    //             //this mean the target may be present in the current row
    //             int left=0;
    //             int right=matrix[0].size()-1;

    //             while(left<=right)
    //             {
    //                 int col_mid=left+(right-left)/2;
    //                 if(matrix[row_mid][col_mid]==target)
    //                     return true;
    //                 if(target<matrix[row_mid][col_mid])
    //                 {
    //                     right=col_mid-1;
    //                 }
    //                 else
    //                 {
    //                     left=col_mid+1;
    //                 }
    //             }

    //             //if the element is not in the current row then it may be present
    //             //in the next and rest of rows
    //             top=row_mid+1;
    //         }
    //         else//if target is less than the first element of the row then it is present
    //         //in the previous rows
    //         {
    //             bottom=row_mid-1;
    //         }
    //     }

    //     return false;
    // }
};
