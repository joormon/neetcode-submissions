class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int count = 0; count < 9; count++) {
            // row check
            unordered_set<char> row;
            for (int i = 0; i < 9; i++) {
                if (board[count][i] == '.') continue;
                if (row.count(board[count][i])) return false;
                row.insert(board[count][i]);
            }
            // column check
            unordered_set<char> col;
            for (int i = 0; i < 9; i++) {
                if (board[i][count] == '.') continue;
                if (col.count(board[i][count])) return false;
                col.insert(board[i][count]);
            }
        }

        //check the 3x3 sub boxes
        for(int box=0;box<9;box++)
        {
            unordered_set<char> boxSet;
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    int row = 3*(box/3) + i;
                    int col = 3*(box%3) + j;

                    if(board[row][col]!='.')
                    {
                        if(boxSet.count(board[row][col]))
                            return false;
                        boxSet.insert(board[row][col]);
                    }
                }

            }
        }

        return true;
    }
};
