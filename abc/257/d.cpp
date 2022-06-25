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
const int inf = 1 << 31;
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

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

int main(void) {
    fio();
    ll n, m;
    cin >> n;
    m = n * (n - 1);
    lvec x(n), y(n), p(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> p[i];
    }

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    /* okが最小値でも、最大値でも同じ書き方 */
    ll left = -1;
    ll right = INF;
    while(right - left > 1) {
        ll mid = left + (right - left) / 2;
        if(f(mid)) right = mid;
        else left = mid;
    }
    double dist[201][201];

    // 直接つながっているものはその辺のコストで初期化
    //、開始と終了の点が同じ場合、コストは0
    // それ以外はinfに設定
    rep(i, n) rep(j, n) dist[i][j] = inf;
    rep(i, n) dist[i][i] = 0;
    rep(i, n) {
        rep(j, n) {
            if(i == j) continue;
            dist[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) / p[i];
        }
    }

    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    double ans = 1000000000;
    rep(i, n) {
        double _ans = 0;
        rep(j, n) {
            if(i == j) continue;
            if(_ans < dist[i][j]) _ans = dist[i][j];
        }
        if(ans > _ans) ans = _ans;
    }
    pri(ceil(ans));
}
