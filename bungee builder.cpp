#include<bits/stdc++.h>

using namespace std;

const int N = 1e7+7;

#define vi vector<int>
#define vll vector<long long>
#define all(v) ((v).begin()), ((v).end())

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

/*ll sieve_size;
bitset<10000010>bs;
vll p;

void sieve(ll upperbound){
    sieve_size=upperbound+1;
    bs.set();
    bs[0]=bs[1]=false;
    for(ll i = 2;i<sieve_size;i++) if(bs[i]){
            for(ll j = i*i;j<sieve_size;j+=i) bs[j]=false;
            p.push_back(i);
        }
}*/

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

bool isPrime(ll n) {
    if (!(n % 2))return false;
    for (int i = 3; i * i <= n; i += 2)
        if (!(n % i))return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> v;
    int n;
    cin >> n;

    int ans = 0;
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int first = -1;
    int mx = INT_MIN;

    for (int i = 0, u; i < n; i++) {
        cin >> u;
        v.push_back(u);
        mx = max(mx, v[i]);
        if (v[i] == mx) {
            maxi = INT_MIN;
            mini = INT_MAX;
            if (i - first > 1) {
                for (int k = first; k < i; k++) {
                    maxi = max(maxi, v[k]);
                    mini = min(mini, v[k]);
                }
                ans = max(ans, maxi - mini);
            }
            first = i;
        }
    }

    maxi = INT_MIN;
    mini = INT_MAX;
    if(first != n - 1) {
        for (int i = n - 1; i >= first; i--) {
            if(v[i] >= maxi){
                if(mini != INT_MAX)
                    ans = max(ans, maxi - mini);
                maxi = v[i];
                mini = INT_MAX;
            }
            else mini = min(mini, v[i]);
        }
    }
    if (ans < 0) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }


    return 0;
}
