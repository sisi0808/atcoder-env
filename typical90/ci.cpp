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

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using vs = vector<ll>;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
const int SIZE = 100005;
const int inf = 1000000000;
const int modi = 1000000007;
const long long INF = 1000000000000000LL;
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

void pri(ll a) { cout << a << endl; }
void spri(string a) { cout << a << endl; }
void priV(vector<ll> &vec) {
    for(size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << ":";
    }
    cout << endl;
}

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

using mint = modint998244353;
// using mint = modint1000000007;
// cout << fixed << setprecision(12);
ll n, p, k;
Graph a;

ll f(ll mid) {
    ll dist[41][41];
    // 直接つながっているものはその辺のコストで初期化
    //、開始と終了の点が同じ場合、コストは0
    // それ以外はinfに設定

    rep(i, n) rep(j, n) dist[i][j] = a[i][j] == -1 ? mid : a[i][j];

    rep(h, n) rep(i, n) rep(j, n) chmin(dist[i][j], dist[i][h] + dist[h][j]);

    int cnt = 0;
    rep(i, n) repp(j, n, i + 1) if(dist[i][j] <= p) cnt++;

    return cnt;
}

ll get_border(ll cnt) {
    /* どんな二分探索でもここの書き方を変えずにできる！ */
    /* okが最小値でも、最大値でも同じ書き方 */
    ll left = 0;
    ll right = 5 * _INF;
    while(right - left > 1) {
        ll mid = left + (right - left) / 2;
        if(f(mid) <= cnt) {
            right = mid;
        } else left = mid;
    }
    // cout << left << " " << right << endl;
    return right;
}

int main(void) {
    fio();
    cin >> n >> p >> k;
    a.resize(n, vector<ll>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    ll l_border = get_border(k);
    ll r_border = get_border(k - 1);

    // cout << l_border << " " << r_border << endl;

    if(r_border - l_border >= 2 * _INF) cout << "Infinity" << endl;
    else cout << r_border - l_border << endl;
}
