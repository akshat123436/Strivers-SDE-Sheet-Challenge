void f(vector<int> &arr, int n, int i, int k, int sum, vector<int> &ds, vector<vector<int>> &ans)
{
    if (i == n)
    {
        if (sum == k)
        {
            ans.push_back(ds);
        }
        return;
    }

    // pick
    ds.push_back(arr[i]);
    f(arr, n, i + 1, k, sum + arr[i], ds, ans);
    ds.pop_back();
    // notPick
    f(arr, n, i + 1, k, sum, ds, ans);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int> ds;
    vector<vector<int>> ans;
    f(arr, n, 0, k, 0, ds, ans);
    return ans;
}