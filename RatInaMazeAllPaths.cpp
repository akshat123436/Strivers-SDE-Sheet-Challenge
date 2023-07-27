#include <bits/stdc++.h>

void setPaths(vector<vector<int>> &ans, vector<int> &path, vector<vector<int>> &maze, int n, int i, int j, int *delr, int *delc)
{
    if (i >= n || j >= n || i < 0 || j < 0)
        return;
    if (path[i * n + j])
        return;
    if (!maze[i][j])
        return;
    path[i * n + j] = 1;
    if (i == n - 1 && j == n - 1)
    {
        // cout << 1 << endl;
        ans.push_back(path);
        path[i * n + j] = 0;
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        setPaths(ans, path, maze, n, i + delr[k], j + delc[k], delr, delc);
    }
    path[i * n + j] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    // Write your code here.
    vector<int> path(n * n);
    vector<vector<int>> ans;
    int delr[] = {-1, 1, 0, 0};
    int delc[] = {0, 0, 1, -1};
    setPaths(ans, path, maze, n, 0, 0, delr, delc);
    return ans;
}