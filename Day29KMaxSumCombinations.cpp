// #include <bits/stdc++.h>
// vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
// 	// Write your code here.
// 	int count =0;
// 	vector<int> ans;
// 	sort(a.begin(), a.end());
// 	sort(b.begin(), b.end());
// 	set<pair<int,int>> isObtained;
// 	isObtained.insert({n-1, n-1});

// 	priority_queue<vector<int>> pq;
// 	pq.push({a[n-1] + b[n-1], n-1, n-1});

// 	while(count<k){
// 		auto e = pq.top();
// 		int sum = e[0];
// 		int first = e[1];
// 		int second = e[2];
// 		pq.pop();
// 		if(first-1 >= 0){
// 			if(isObtained.find({first-1, second}) == isObtained.end()){
// 				pq.push({a[first-1] + b[second], first-1, second});
// 				isObtained.insert({first-1, second});
// 			}
// 		}
// 		if(second-1 >= 0){
// 			if(isObtained.find({first, second-1}) == isObtained.end()){
// 				pq.push({a[first] + b[second-1], first, second-1});
// 				isObtained.insert({first, second-1});
// 			}
// 		}
// 		ans.push_back(sum);
// 		count++;
// 	}
// 	return ans;
// }
#include <bits/stdc++.h>

#include <queue>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{

    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            pq.push(a[i] + b[j]);
        }
    }

    vector<int> ans;

    while (k--)
    {

        ans.push_back(pq.top());

        pq.pop();
    }

    return ans;
}