#include <stack>
int largestRectangle(vector<int> &heights)
{
    // Write your code here.
    stack<pair<int, int>> s;

    int n = heights.size();
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top().first >= heights[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            left[i] = -1;
        }
        else
        {
            left[i] = s.top().second;
        }
        s.push({heights[i], i});
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top().first >= heights[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            right[i] = n;
        }
        else
        {
            right[i] = s.top().second;
        }
        s.push({heights[i], i});
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int size = -left[i] + right[i] - 1;
        //  cout << heights[i] << " " << size<< " " << left[i]<< " " << right[i] << endl;
        ans = max(ans, heights[i] * size);
    }

    return ans;
}