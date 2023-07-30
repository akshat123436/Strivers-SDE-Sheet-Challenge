bool isPossible(vector<vector<int>> &mat, int node, int m, vector<int> &colors, int n)
{
    if (colors[node])
        return true;

    for (int c = 1; c <= m; c++)
    {
        colors[node] = c;
        bool check = true;
        for (int i = 0; i < n; i++)
        {
            if (i != node && mat[node][i] && colors[i] == c)
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            for (int i = 0; i < n; i++)
            {
                if (i != node && mat[node][i] && !isPossible(mat, i, m, colors, n))
                {
                    check = false;
                    break;
                }
            }
            if (check)
                return true;
        }
    }
    return false;

    // return check;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    // Write your code here
    int n = mat.size();
    vector<int> colors(n);
    for (int i = 0; i < n; i++)
    {
        if (!isPossible(mat, i, m, colors, n))
            return "NO";
    }

    return "YES";
}