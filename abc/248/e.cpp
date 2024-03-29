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
using vs = vector<ll>;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
const int SIZE = 100005;
// const int inf = 1000000000;
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

/*
直線自体は、2点があれば定まる
つまり、2点以上通る直線(定まった直線)を全探索して、k点以上通るか判定
*/

int main(void) {
    fio();
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vector<vector<bool>> flag(n + 1, vector<bool>(n + 1, true));
    // bool flag[300][300];
    // for(int i = 0; i < n; i++)
    //     for(int j = i + 1; j < n; j++) flag[i][j] = true;

    if(k == 1LL) {
        cout << "Infinity" << endl;
        return 0;
    }

    ll ans = 0;
    rep(i, n) {
        repp(j, n, i + 1) {
            if(flag[i][j]) {
                ll pnt_cnt = 2;
                vector<int> pv;
                pv.pb(i);
                pv.pb(j);
                repp(ii, n, j + 1) {
                    if((x[i] - x[j]) * (y[i] - y[ii]) == (x[i] - x[ii]) * (y[i] - y[j])) {
                        pnt_cnt++;
                        pv.pb(ii);
                    }
                }
                rep(ii, pv.size()) rep(jj, pv.size()) flag[pv[ii]][pv[jj]] = false;
                if(pnt_cnt >= k) ans++;
            }
        }
    }
    cout << ans << endl;
}
