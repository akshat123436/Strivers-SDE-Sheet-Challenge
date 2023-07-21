int sortedBinarySearch(int low, int high, int *arr, int key)
{
    int ans = -1;

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (arr[low] == key)
        return low;
    return ans;
}
int search(int *arr, int n, int key)
{
    // Write your code here.
    int low = 0, high = n - 1;
    int ans = -1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            break;
        }
        if (arr[mid] > arr[low])
        {
            ans = sortedBinarySearch(low, mid, arr, key);
            if (ans != -1)
                break;
            else
            {
                low = mid + 1;
            }
        }
        else if (arr[mid] < arr[high])
        {
            ans = sortedBinarySearch(mid, high, arr, key);
            if (ans != -1)
                break;
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            ans = sortedBinarySearch(mid + 1, high, arr, key);
            if (ans != -1)
                break;
            else
            {
                high = mid - 1;
            }
        }
    }
    if (arr[low] == key)
        return low;
    return ans;
}