double power(double num, int p)
{
    if (p == 1)
        return num;
    if (p == 0)
        return 1;

    double n = power(num, p / 2);

    if (p & 1)
    {
        return num * n * n;
    }
    else
    {
        return n * n;
    }
}

int NthRoot(int n, int m)
{
    // Write your code here.

    int low = 1;
    int high = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        double val = power(mid, n);
        if (val == m)
        {
            return mid;
        }
        else if (val > m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}