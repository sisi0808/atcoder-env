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

/*
全通り試せるかも？
とりあえず試してみる！
*/

int main(void) {
    fio();
    int n, m, Q;
    cin >> n >> m >> Q;
    vector<int> a(Q), b(Q), c(Q), d(Q);
    rep(i, Q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }

    vector<vector<int>> t;

    queue<vector<int>> q;
    rep(i, m) {
        q.push({i + 1});
    }

    while(!q.empty()) {
        auto r = q.front();
        q.pop();
        for(int i = r[r.size() - 1]; i <= m; i++) {
            vector<int> qq = {ALL(r)};
            qq.pb(i);
            if(r.size() + 1 == n) t.pb(qq);
            else q.push(qq);
        }
    }

    ll ans = 0;
    /* eは選んだ数列 */
    for(auto e : t) {
        ll _ans = 0;
        rep(i, Q) {
            if(e[b[i]] - e[a[i]] == c[i]) _ans += d[i];
        }
        chmax(ans, _ans);
    }

    cout << ans << endl;
}
