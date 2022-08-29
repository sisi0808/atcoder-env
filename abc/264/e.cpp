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

グラフの問題

* 発電所同士の電線は意味を成さない
* union-find?
    * 道の削除が出来ないからそれはないか？
    *
* 電線から見て、それがなくなった時の影響力を記録しておく？
    * 強連結成分分解(無向グラフなので違う)
    * オイラーツアー（なんか違う気がする）
    *
* クエリをすべて処理した段階から道をつなげるでACが取れるはず!
* 発電所は纏める
*/

int main(void) {
    fio();
    ll n, m, e;
    cin >> n >> m >> e;
    vector<ll> u(e), v(e);
    rep(i, e) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        chmin(u[i], n);
        chmin(v[i], n);
    }

    int q;
    cin >> q;
    vector<int> x(q);
    set<int> st;
    rep(i, q) {
        cin >> x[i];
        x[i]--;
        st.insert(x[i]);
    }

    dsu d(n + 1);
    rep(i, e) if(!st.count(i)) d.merge(u[i], v[i]);

    vector<int> ans(q);
    rrep(i, q - 1) {
        // 答え
        ans[i] = d.size(n) - 1;
        d.merge(u[x[i]], v[x[i]]);
    }

    rep(i, q) cout << ans[i] << endl;
}
