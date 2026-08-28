/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node*
_bottomRight) { val = _val; isLeaf = _isLeaf; topLeft = _topLeft; topRight = _topRight; bottomLeft =
_bottomLeft; bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* createNode(vector<vector<int>>& grid, int row_begin, int row_end, int col_begin,
                         int col_end) {
        Node* root;
        int first_ele = grid[row_begin][col_begin];
        bool isSame = true;
        for (int i = row_begin; i < row_end; i++) {
            for (int j = col_begin; j < col_end; j++) {
                if (first_ele != grid[i][j]) {
                    isSame = false;
                    break;
                }
            }
            if (!isSame) {
                break;
            }
        }

        // create node based on same elements or not;
        if (isSame) {
            root = new Node(first_ele, 1);
            return root;
        }

        root = new Node(first_ele, 0);
        int mid_row = row_begin + (row_end - row_begin) / 2;
        int mid_col = col_begin + (col_end - col_begin) / 2;
        root->topLeft = createNode(grid, row_begin, mid_row, col_begin, mid_col);
        root->topRight = createNode(grid, row_begin, mid_row, mid_col, col_end);
        root->bottomLeft = createNode(grid, mid_row, row_end, col_begin, mid_col);
        root->bottomRight = createNode(grid, mid_row, row_end, mid_col, col_end);

        return root;
    }

   public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid[0].size();
        // Create Node
        return createNode(grid, 0, n, 0, n);
    }
};