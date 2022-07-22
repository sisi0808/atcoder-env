#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include <atcoder/all>
using namespace atcoder;

#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define rrep(i, n) for(int i = n; i >= 0; --i)
#define repp(i, n, m) for(int i = m; i < int(n); ++i)
#define fore(i_in, a) for(auto &i_in : a)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define chmin(a, b) a = min((ll)a, (ll)b)
#define chmax(a, b) a = max((ll)a, (ll)b)

#define pb push_back
#define pf push_front

#define fi first
#define se second

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using ivec = vector<int>;
using lvec = vector<ll>;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
const int SIZE = 100005;
const int inf = 1 << 30;
const int _inf = 1000000000;
const int modi = 1000000007;
const long long INF = 1LL << 62;
const long long _INF = 1000000000000000000LL;
const long long modl = 1000000007LL;
const long long modll = 998244353LL;

void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }
void yn(bool t) {
    if(t)
        yes();
    else
        no();
}
void Yes() { cout << "YES" << endl; }
void No() { cout << "NO" << endl; }
void YN(bool t) {
    if(t)
        Yes();
    else
        No();
}

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

// int main(void) {
//     fio();
//     ll n;
//     string k;
//     cin >> n >> k;
//     string t = k;
//     reverse(ALL(t));

//     ll ans = 0;
//     map<string, bool> mp;

//     /* これで、最初から余計な0が付いている場合も消せる */
//     if(stoll(k) > stoll(t)) {
//         cout << 0 << endl;
//         return 0;
//     }
//     while(stoll(k) <= n && !mp[k]) {
//         ans++;
//         mp[k] = true;
//         k += '0';
//     }
//     while(stoll(t) <= n && !mp[t]) {
//         ans++;
//         mp[t] = true;
//         t += '0';
//     }

//     cout << ans << endl;
// }

ll ans = 0;
ll n;
map<string, bool> mp;
/* その数が条件に当てはまるかを返す */
void dfs(string k) {
    if(stoll(k) > n || mp[k]) return;
    mp[k] = true;
    ans++;
    dfs(k + '0');
}

int main(void) {
    fio();
    string k;
    cin >> n >> k;

    string t = k;
    reverse(ALL(t));
    if(stoll(k) <= stoll(t)) {
        dfs(k);
        dfs(t);
    }

    cout << ans << endl;
}
