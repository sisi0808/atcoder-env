#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include <atcoder/all>
using namespace atcoder;

#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define rrep(i, n, m) for(int i = n; i >= m; --i)
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
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
* パティの枚数は、f(n) = 2*f(n-1) + 1;
* パティは3と1が交互に続く形

* 再帰を続けていくと、f(0)何個分課を求めることが出来る？
*/

vector<ll> b;

/* 何番目のバーガーの下から何枚を食べるか */
/* 返り血は、その中に何枚のパティが含まれているか */
ll dfs(ll n, ll x) {
    if(x <= 0LL) return 0;
    if(n == 0LL) return 1;
    if(x >= b[n]) return (b[n] + 1) / 2;

    ll ans = 0;
    ans = dfs(n - 1, x - (b[n] + 1) / 2) + min(1ll, max(0ll, x - b[n] / 2)) + dfs(n - 1, x - 1);

    return ans;
}

int main(void) {
    fio();
    ll n, x;
    cin >> n >> x;

    /* バーガーの総数とパティの数のペア*/
    b.pb(1);
    repp(i, 51, 1) b.pb(b[i - 1] * 2 + 3);

    /* 何番目のバーガーの下から何枚を食べるか */
    cout << dfs(n, x) << endl;
}
