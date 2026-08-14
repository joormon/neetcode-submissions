class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {

        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.')
                    continue;

                int num = board[r][c] - '1'; // Convert '1'-'9' to index 0-8
                int boxIdx = (r / 3) * 3 + (c / 3);

                if (rows[r][num] || cols[c][num] || boxes[boxIdx][num])
                    return false;

                rows[r][num] = true;
                cols[c][num] = true;
                boxes[boxIdx][num] = true;
            }
        }

        return true;
    }

    //     for (int count = 0; count < 9; count++) {
    //         // row check
    //         unordered_set<char> row;
    //         for (int i = 0; i < 9; i++) {
    //             if (board[count][i] == '.') continue;
    //             if (row.count(board[count][i])) return false;
    //             row.insert(board[count][i]);
    //         }
    //         // column check
    //         unordered_set<char> col;
    //         for (int i = 0; i < 9; i++) {
    //             if (board[i][count] == '.') continue;
    //             if (col.count(board[i][count])) return false;
    //             col.insert(board[i][count]);
    //         }
    //     }

    //     //check the 3x3 sub boxes
    //     for(int box=0;box<9;box++)
    //     {
    //         unordered_set<char> boxSet;
    //         for(int i=0;i<3;i++)
    //         {
    //             for(int j=0;j<3;j++)
    //             {
    //                 int row = 3*(box/3) + i;
    //                 int col = 3*(box%3) + j;

    //                 if(board[row][col]!='.')
    //                 {
    //                     if(boxSet.count(board[row][col]))
    //                         return false;
    //                     boxSet.insert(board[row][col]);
    //                 }
    //             }

    //         }
    //     }

    //     return true;
    // }
};
