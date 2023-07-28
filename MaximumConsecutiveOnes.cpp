bool isPossible(int val, vector<int> &zeroes, int n, int k)
{
    for (int i = 1; i + val - 1 <= n; i++)
    {
        int count = zeroes[i + val - 1] - zeroes[i - 1];
        if (count <= k)
            return true;
    }

    return false;
}

int longestSubSeg(vector<int> &arr, int n, int k)
{
    // Write your code here.

    int low = k;
    int high = n;

    vector<int> zeroes(n + 1);

    for (int i = 0; i < n; i++)
    {
        if (!arr[i])
            zeroes[i + 1] = 1;
    }

    for (int i = 1; i <= n; i++)
        zeroes[i] += zeroes[i - 1];
    // int count = 0;
    int ans = 0;
    while (low <= high)
    {
        // cout << low << " " << high << endl;
        int mid = low + (high - low) / 2;
        if (isPossible(mid, zeroes, n, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        // count++;
    }

    return ans;
}
