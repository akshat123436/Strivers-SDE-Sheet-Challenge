#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<bool> row(n, 0), col(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!matrix[i][j])
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (row[i])
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (col[i])
        {
            for (int j = 0; j < n; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
}