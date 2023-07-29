#include <set>
#include <math.h>
// void findPermutation(int n, int &k, string &ans, set<char> &s, string &ds){
//     if(s.empty()) {
//         k--;
//         if(!k) ans = ds;
//         return;
//     }

//     for(auto &a : s){
//         char c = a;
//         s.erase(c);
//         ds.push_back(c);
//         findPermutation(n,k,ans,s,ds);
//         ds.pop_back();
//         s.insert(c);
//     }
// }

int factorial(int num)
{
    if (!num)
        return 1;
    for (int i = num - 1; i >= 1; i--)
    {
        num *= i;
    }

    return num;
}

void creator(string &ans, set<char> &s, int n, int k)
{
    if (!n)
        return;

    int fact = factorial(n - 1);

    int num = ceil(double(k) / fact);

    auto it = next(s.begin(), num - 1);
    s.erase(it);
    ans.push_back(*it);

    k = k - (num - 1) * (fact);

    creator(ans, s, n - 1, k);
}

string kthPermutation(int n, int k)
{
    // Write your code here.
    // set <char> s;
    // for(int i ='1';i<='0' + n;i++) s.insert(i);

    // string ans;
    // string ds;
    // findPermutation(n, k, ans, s, ds);
    // return ans;
    set<char> s;
    for (char i = '1'; i <= '0' + n; i++)
        s.insert(i);

    string ans;

    creator(ans, s, n, k);
    return ans;
}
