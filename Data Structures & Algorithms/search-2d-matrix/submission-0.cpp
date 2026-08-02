class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int top=0;
        int bottom=matrix.size()-1;

        while(top<=bottom)
        {
            int row_mid=top+(bottom-top)/2;

            if(matrix[row_mid][0]<=target)
            {
                //this mean the target may be present in the current row
                int left=0;
                int right=matrix[0].size()-1;

                while(left<=right)
                {
                    int col_mid=left+(right-left)/2;
                    if(matrix[row_mid][col_mid]==target)
                        return true;
                    if(target<matrix[row_mid][col_mid])
                    {
                        right=col_mid-1;
                    }
                    else
                    {
                        left=col_mid+1;
                    }
                }

                //if the element is not in the current row then it may be present
                //in the next and rest of rows
                top=row_mid+1;
            }
            else
            {
                bottom=row_mid-1;
            }
        }

        return false;
    }
};
