bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int rows = mat.size(), cols = mat[0].size();

    int low = 0;
    int high = rows - 1;

    while (high - low > 1)
    {
        int mid = (low + high) / 2;
        if (mat[mid][0] > target)
            high = mid - 1;
        else
            low = mid;
    }
    int rowNo = 0;
    if (mat[high][0] <= target)
        rowNo = high;
    else
        rowNo = low;

    low = 0;
    high = cols - 1;

    while (high - low > 1)
    {
        int mid = (low + high) / 2;
        if (mat[rowNo][mid] > target)
            high = mid - 1;
        else
            low = mid;
    }

    if (mat[rowNo][low] == target)
        return true;
    else if (mat[rowNo][high] == target)
        return true;
    return false;
}