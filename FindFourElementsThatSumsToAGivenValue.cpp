#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n)
{
    // Write your code here.
    // unordered_map<int,int> count;
    // for(int i =0;i<n;i++) count[arr[i]]++;

    // for(int i = 0;i<n;i++){
    //     count[arr[i]]--;
    //     for(int j = n-1;j>i;j--){
    //         count[arr[j]]--;
    //         for(int k = i+1;k<j;k++){
    //             count[arr[k]]--;
    //             int num = target-arr[i] -arr[j]-arr[k];
    //             if(count[num]) return "Yes";
    //             // count[arr[k]]++;
    //         }
    //         // count[arr[j]]++;
    //     }
    //     // count[arr[i]]++;
    // }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum == target)
                    return "Yes";
                if (sum > target)
                    l--;
                else
                    k++;
            }
        }
    }
    return "No";
}
