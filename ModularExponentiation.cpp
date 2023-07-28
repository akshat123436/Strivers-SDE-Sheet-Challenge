#include <bits/stdc++.h>
// int exp(int x, int n, int m){
// 	if(n == 0) return 1%m;
// 	long long val = exp(x,n/2,m);
// 	if(n%2 == 0){
// 		return (val * val)%m;
// 	}
// 	else{
// 		return (x * (val * val)%m) % m;
// 	}
// }
int exp(long long x, int n, int m)
{
    long long ans = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = ((ans % m) * (x % m)) % m;
        }
        x = ((x % m) * (x % m)) % m;
        n >>= 1;
    }

    return ans;
}
int modularExponentiation(int x, int n, int m)
{
    return exp(x, n, m);
}
