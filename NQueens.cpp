void f(vector<bool> &capturedCol, vector<bool> &capturedDiagonal, vector<bool> &capturedRightDiagonal, vector<int> &board, int n, int qnumber, vector<vector<int>> &ans, int i)
{

    if (qnumber == n + 1)
    {
        ans.push_back(board);
        return;
    }
    if (i == n + 1)
        return;
    int row = i;
    for (int col = 0; col < n; col++)
    {
        if (!capturedCol[col] && !capturedDiagonal[n - 1 + (col - row)] && !capturedRightDiagonal[col + row])
        {
            capturedCol[col] = true;
            capturedRightDiagonal[col + row] = true;
            capturedDiagonal[n - 1 + (col - row)] = true;
            board[n * row + col] = 1;
            f(capturedCol, capturedDiagonal, capturedRightDiagonal, board, n, qnumber + 1, ans, row + 1);

            capturedCol[col] = false;
            capturedDiagonal[n - 1 + (col - row)] = false;
            capturedRightDiagonal[col + row] = false;
            board[n * row + col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<bool> capturedCol(n, 0), capturedDiagonal(2 * n - 1, 0), capturedRightDiagonal(2 * n - 1, 0);
    vector<int> board(n * n, 0);
    vector<vector<int>> ans;
    f(capturedCol, capturedDiagonal, capturedRightDiagonal, board, n, 1, ans, 0);
    return ans;
}