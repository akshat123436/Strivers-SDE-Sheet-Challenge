#include <stack>
#include <vector>
#include <algorithm>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while ((!s.empty()) && (s.top() >= arr[i]))
        {
            // cout << "-" << s.top() << endl;
            s.pop();
        }
        // cout << arr[i] << endl;
        if (s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top());
        // cout << "last : " << ans[ans.size()-1] << endl;
        s.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}