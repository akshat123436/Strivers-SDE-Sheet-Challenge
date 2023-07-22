#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    int n = arr.size();
    vector<int> ans;
    unordered_map<int,int> count;
    for(int i = 0;i<k;i++){
        count[arr[i]]++;
    }
    ans.push_back(count.size());
    int temp = ans[0];
	for(int i = 0;i<n-k;i++){
        int inserted = count[arr[i+k]]++;
        if(!inserted) temp++;
        int exited = --count[arr[i]];
        if(!exited) temp--;

        ans.push_back(temp);
    }

    return ans;
}
