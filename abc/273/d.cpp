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

int main(void) {
    fio();
    ll h, w;
    cin >> h >> w;
    ll y, x;
    cin >> y >> x;
    y--;
    x--;
    int n;
    cin >> n;

    map<ll, set<ll>> mp_x;
    map<ll, set<ll>> mp_y;
    rep(i, n) {
        ll r, c;
        cin >> r >> c;
        r--;
        c--;
        // mp[r].pb(c);
        mp_x[r].insert(c);
        mp_y[c].insert(r);
    }

    int q;
    cin >> q;
    while(q--) {
        char d;
        cin >> d;
        ll l;
        cin >> l;

        if(d == 'L') {
            /* 壁が無い場合 */
            if(!mp_x.count(y)) x = max(0LL, x - l);
            else if(mp_x[y].begin() == mp_x[y].lower_bound(x)) x = max(0LL, x - l);
            /* 壁がある場合 */
            else x = max(*prev(mp_x[y].lower_bound(x)) + 1, x - l);
        }
        if(d == 'R') {
            /* 壁が無い場合 */
            if(!mp_x.count(y)) x = min(w - 1, x + l);
            else if(mp_x[y].end() == mp_x[y].lower_bound(x)) x = min(w - 1, x + l);
            /* 壁がある場合 */
            else x = min(*mp_x[y].lower_bound(x) - 1, x + l);
        }
        if(d == 'U') {
            /* 壁が無い場合 */
            if(!mp_y.count(x)) y = max(0LL, y - l);
            else if(mp_y[x].begin() == mp_y[x].lower_bound(y)) y = max(0LL, y - l);
            /* 壁がある場合 */
            else y = max(*prev(mp_y[x].lower_bound(y)) + 1, y - l);
        }
        if(d == 'D') {
            /* 壁が無い場合 */
            if(!mp_y.count(x)) y = min(h - 1, y + l);
            else if(mp_y[x].end() == mp_y[x].lower_bound(y)) y = min(h - 1, y + l);
            /* 壁がある場合 */
            else y = min(*mp_y[x].lower_bound(y) - 1, y + l);
        }
        cout << y + 1 << " " << x + 1 << endl;
    }
}
