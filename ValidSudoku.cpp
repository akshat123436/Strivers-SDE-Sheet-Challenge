#include <vector>

bool isPossibleSudoku(vector<vector<bool>> &rowCheck, vector<vector<bool>> &colCheck, vector<vector<vector<bool>>> &boxCheck, int i, int j, vector<vector<int>> &matrix)
{
    if (j >= 9)
    {
        if (!i)
            return true;
        return false;
    }
    bool check = false;
    // cout << i << " " << j << endl;
    if (!matrix[i][j])
        for (int num = 1; num <= 9; num++)
        {
            if (check)
                return check;
            if (!rowCheck[i][num] && !colCheck[j][num] && !boxCheck[i / 3][j / 3][num])
            {
                rowCheck[i][num] = true;
                colCheck[j][num] = true;
                boxCheck[i / 3][j / 3][num] = true;
                if (i + 1 < 9)
                    check |= isPossibleSudoku(rowCheck, colCheck, boxCheck, i + 1, j, matrix);
                else
                    check |= isPossibleSudoku(rowCheck, colCheck, boxCheck, 0, j + 1, matrix);
                rowCheck[i][num] = false;
                colCheck[j][num] = false;
                boxCheck[i / 3][j / 3][num] = false;
            }
        }
    else
    {
        if (check)
            return check;
        if (i + 1 < 9)
            check |= isPossibleSudoku(rowCheck, colCheck, boxCheck, i + 1, j, matrix);
        else
            check |= isPossibleSudoku(rowCheck, colCheck, boxCheck, 0, j + 1, matrix);
    }

    return check;
}

bool isItSudoku(int matrix[9][9])
{
    // Write your code here.
    vector<vector<int>> mat(9, vector<int>(9, 0));
    vector<vector<bool>> rowCheck(9, vector<bool>(10, 0)), colCheck(9, vector<bool>(10, 0));
    vector<vector<vector<bool>>> boxCheck(3, vector<vector<bool>>(3, vector<bool>(10, 0)));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            mat[i][j] = matrix[i][j];
            if (matrix[i][j])
            {
                rowCheck[i][matrix[i][j]] = true;
                colCheck[j][matrix[i][j]] = true;
                boxCheck[i / 3][j / 3][matrix[i][j]] = true;
            }
        }
    }
    return isPossibleSudoku(rowCheck, colCheck, boxCheck, 0, 0, mat);
}
