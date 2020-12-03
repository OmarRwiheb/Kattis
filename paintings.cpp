#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vll vector<long long>
#define all(v) ((v).begin()), ((v).end())

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int n, m;
int cnt = 0;
vector<int> ans;
vector<int>temp;
vector<bool>vis;
vector< vector<bool> > good;

void backTracking() {
    if (temp.size() == n) {
        if (ans.size() == 0) {
            for (auto i : temp) {
                ans.push_back(i);
            }
        }
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (temp.size() > 0 && !good[temp.back()][i]) {
                continue;
            }

            vis[i] = true;
            temp.push_back(i);

            backTracking();

            temp.pop_back();
            vis[i] = false;
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#pragma warning(disable : 4996)
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int tc;
    cin>>tc;
    while (tc--) {

        cin >> n;

        vis.clear();
        vis.resize(n,false);

        map<string,int> color;
        vector<string> colors;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            color[s] = i;
            colors.push_back(s);
        }

        good.clear();
        good.resize(n,vector<bool>(n,true));
        int t;
        cin >> t;
        for(int i = 0; i < t; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            int n1 = color[s1];
            int n2 = color[s2];
            good[n1][n2] = false;
            good[n2][n1] = false;
        }

        backTracking();

        cout << cnt << endl;
        for(auto i : ans) {
            cout << colors[i] << " ";
        }
        cout << endl;

        cnt = 0;
        ans.clear();

    }
    return 0;
}
