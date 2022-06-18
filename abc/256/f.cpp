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

using mint = modint998244353;
// using mint = modint1000000007;
// cout << fixed << setprecision(12);

int main(void) {
    fio();
    int n, Q;
    cin >> n >> Q;
    lvec a(n);
    vector<mint> b(n), c(n), d(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        if(i == 0) b[i] = a[i];
        else b[i] = a[i] + b[i - 1];
    }
    rep(i, n) {
        if(i == 0) c[i] = b[i];
        else c[i] = b[i] + c[i - 1];
    }
    rep(i, n) {
        if(i == 0) d[i] = c[i];
        else d[i] = c[i] + d[i - 1];
    }

    multiset<P> y;
    while(Q--) {
        int q;
        cin >> q;
        if(q == 1) {
            ll x, v;
            cin >> x >> v;
            x--;
            y.insert({x, v - a[x]});
            // cout << x << v - a[x] << endl;
        } else {
            ll x2;
            cin >> x2;
            x2--;
            mint ans = d[x2];
            for(auto it : y) {
                int x3 = x2 - it.first;
                if(x3 < 0) {
                    break;
                }
                // cout << ans.val() << ":" << it.first << ":" << it.second << ":" << x3 << endl;
                ans = ans + (x3 + 1) * (x3 + 2) / 2 * it.second;
            }
            cout << ans.val() << endl;
        }
    }
}
