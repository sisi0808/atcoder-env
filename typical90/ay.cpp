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
const long long INF = 1000000000000000;
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

int main(void) {
    fio();
    ll n, k, p;
    cin >> n >> k >> p;
    vs a(n);
    rep(i, n) cin >> a[i];

    int f_half = n / 2;
    int s_half = n - n / 2;
    Graph fh(f_half + 1), sh(s_half + 1);

    /* 前半に分ける */
    rep(i, (1 << f_half)) {
        ll total_fee = 0;
        int cou = 0;
        rep(j, f_half) {
            if(i & (1 << j)) {
                total_fee += a[j];
                cou++;
            }
        }
        fh[cou].push_back(total_fee);
    }
    rep(i, f_half + 1) sort(ALL(fh[i]));

    /* 後半に分ける */
    rep(i, (1 << s_half)) {
        ll total_fee = 0;
        int cou = 0;
        rep(j, s_half) {
            if(i & (1 << j)) {
                total_fee += a[f_half + j];
                cou++;
            }
        }
        sh[cou].push_back(total_fee);
    }
    rep(i, s_half + 1) sort(ALL(sh[i]));

    ll ans = 0;
    rep(i, k + 1) {
        if(i > f_half || k - i > s_half) continue;
        for(auto f_fee : fh[i]) {
            ans += upper_bound(ALL(sh[k - i]), p - f_fee) - sh[k - i].begin();
        }
    }
    pri(ans);
}
