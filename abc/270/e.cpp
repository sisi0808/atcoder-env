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
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*

二分探索か？
周回する回数を二分探索で求めればいけるかも

*/

ll n, k;
lvec a;
lvec b;
lvec csa;

/* m週回った時、リンゴはK個数食べられるか */
bool f(ll m) {
    int it = lower_bound(ALL(b), m) - b.begin();
    return csa[it] + (n - it) * m >= k;
}

int main(void) {
    fio();
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    csa.resize(n + 1);
    rep(i, n) cin >> a[i];
    rep(i, n) b[i] = a[i];
    sort(ALL(b));
    rep(i, n) csa[i + 1] = csa[i] + b[i];

    /* 回ることのできる原回数を記録 */
    /* この後に一周に満たない分の処理を行う */
    ll left = 0;
    ll right = 1e12 + 2;
    while(right - left > 1) {
        ll mid = left + (right - left) / 2;
        if(f(mid)) right = mid;
        else left = mid;
    }

    /* leftが周回数 */
    rep(i, n) {
        k -= min(a[i], left);
        a[i] -= min(a[i], left);
    }
    rep(i, n) {
        if(k > 0 && a[i] > 0) {
            k--;
            a[i]--;
        }
    }
    rep(i, n) cout << a[i] << " ";
    cout << endl;
}
