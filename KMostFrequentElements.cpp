vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    priority_queue<pair<int, int>> frequency;
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (auto &a : count)
    {
        frequency.push({a.second, a.first});
    }

    vector<int> ans;

    while (k)
    {
        k--;
        ans.push_back(frequency.top().second);
        frequency.pop();
    }

    return ans;
}