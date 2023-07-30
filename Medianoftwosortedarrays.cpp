int direction(vector<int> &a, vector<int> &b, int f, int s, int first, int second)
{
    if (f == first || s == second)
    {
        if (f == first && s == second)
            return 0;
        if (f == first)
        {
            if (a[f - 1] <= b[s])
                return 0;
            else
                return -1;
        }
        else
        {
            if (b[s - 1] <= a[f])
                return 0;
            return 1;
        }
    }
    else
    {
        if (a[f - 1] <= b[s] && b[s - 1] <= a[f])
            return 0;
        else if (a[f - 1] <= b[s])
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

double median(vector<int> &a, vector<int> &b)
{
    // Write your code here.
    int first = a.size(), second = b.size();
    int n = (first + second + 2) / 2;
    int ans;
    if (first < second)
    {
        int low = 0;
        int high = min(first, n);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int d = direction(a, b, mid, n - mid, first, second);
            if (d == 0)
            {
                ans = mid;
                break;
            }
            else if (d == 1)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    else
    {
        int low = 0;
        int high = min(second, n);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int d = direction(a, b, n - mid, mid, first, second);
            if (d == 0)
            {
                ans = mid;
                break;
            }
            else if (d == 1)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        ans = n - ans;
    }
    if ((first + second) & 1)
    {
        if (ans && n - ans)
            return max(a[ans - 1], b[n - ans - 1]);
        else if (ans)
        {
            return a[ans - 1];
        }
        else
        {
            return b[n - ans - 1];
        }
    }
    else if (ans && n - ans)
    {
        if (a[ans - 1] > b[n - ans - 1])
        {
            if (ans - 1)
            {
                return (a[ans - 1] + max(a[ans - 2], b[n - ans - 1])) / 2.0;
            }
            else
            {
                return (a[ans - 1] + b[n - ans - 1]) / 2.0;
            }
        }
        else
        {
            if (n - ans - 1)
            {
                return (b[n - ans - 1] + max(a[ans - 1], b[n - ans - 2])) / 2.0;
            }
            else
            {
                return (a[ans - 1] + b[n - ans - 1]) / 2.0;
            }
        }
    }
    else
    {
        if (ans)
            return (a[ans - 1] + a[ans - 2]) / 2.0;
        else
            return (b[n - ans - 1] + b[n - ans - 2]) / 2.0;
    }
}