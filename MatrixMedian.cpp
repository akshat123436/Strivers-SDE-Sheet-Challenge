#include <queue>
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pq.push(matrix[i][j]);
        }
    }
    int total = m * n;
    int i = 0;
    while (i < total / 2)
    {
        pq.pop();
        i++;
    }
    return pq.top();
}