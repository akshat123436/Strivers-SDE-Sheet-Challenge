int direction(int first, vector<int> &row1, vector<int> &row2, int m, int n, int second)
{
    if (first > m)
        return -1;
    if (second > n)
        return 1;
    if (first && second)
    {
        if (second == n || first == m)
        {
            if (second == n && first == m)
            {
                return 0;
            }
            if (second == n)
            {
                if (row2[second - 1] <= row1[first])
                    return 0;
                return 1;
            }
            else
            {
                if (row1[first - 1] <= row2[second])
                    return 0;
                return -1;
            }
        }
        if (row1[first - 1] <= row2[second] && row2[second - 1] <= row1[first])
            return 0;
        else if (row1[first - 1] > row2[second])
            return -1;
        return 1;
    }
    else
    {
        if (first)
        {
            if (row1[first - 1] > row2[second])
                return -1;
            return 0;
        }
        else
        {
            if (row1[first] < row2[second - 1])
                return 1;
            return 0;
        }
    }
}
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    // Write your code here.
    // vector<int> comb(n+m);
    // int i = 0;
    // int first = 0, second = 0;

    // while(first < m && second < n){
    //     if(row1[first] < row2[second]){
    //         comb[i] = row1[first];
    //         first++;
    //     }
    //     else{
    //         comb[i] = row2[second];
    //         second++;
    //     }
    //     i++;
    // }

    // while(first < m){
    //     comb[i] = row1[first];
    //     i++;
    //     first++;
    // }

    // while(second < n){
    //     comb[i] = row2[second];
    //     i++;
    //     second++;
    // }

    // return comb[k-1];

    int low = 0;
    int high = min(m, k);
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int d = direction(mid, row1, row2, m, n, k - mid);
        if (!d)
        {
            ans = mid;
            break;
        }
        else if (d == -1)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return max(row1[ans - 1], row2[k - ans - 1]);
}