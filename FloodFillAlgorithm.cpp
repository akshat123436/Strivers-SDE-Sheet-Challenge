#include <queue>
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int n = image.size();
    int m = image[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    int color = image[x][y];

    queue<pair<int, int>> q;
    q.push({x, y});
    vector<vector<int>> newImage = image;
    int delr[] = {-1, 0, 1, 0};
    int delc[] = {0, -1, 0, 1};
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        vis[i][j] = true;
        newImage[i][j] = newColor;
        for (int k = 0; k < 4; k++)
        {
            int row = i + delr[k];
            int col = j + delc[k];

            if (row >= 0 && col >= 0 && row < n && col < m && !vis[row][col] && image[row][col] == color)
            {
                vis[row][col] = true;
                q.push({row, col});
            }
        }
    }

    return newImage;
}