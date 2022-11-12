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

// struct edge {
//     int u, v;
//     ll cost;
// };

// bool comp(const edge &e1, const edge &e2) {
//     return e1.cost < e2.cost;
// }

// edge es[1000000];
// int n, m;

// // 最小全域木のコストを求める
// ll kruskal() {
//     sort(es, es + m, comp);
//     dsu d(n);
//     ll res = 0;
//     rep(i, m) {
//         edge e = es[i];
//         if(!d.same(e.u, e.v)) {
//             d.merge(e.u, e.v);
//             res += e.cost;
//         } else if(e.cost < 0) {
//             res += e.cost;
//         }
//     }
//     return res;
// }

// 深さ優先探索

// map<ll, ll> seen;
// void dfs(ll v) {
//     // seen[v] = true; // v を訪問済にする

//     // v から行ける各頂点 next_v について
//     for(auto next_v : g[v]) {
//         if(seen[next_v]) continue; // next_v が探索済だったらスルー
//         dfs(next_v);               // 再帰的に探索
//     }

//     seen[v] = ;
// }

int main(void) {
    fio();
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);

    rep(i, n) cin >> a[i];
    sort(ALL(a));

    vector<ll> ans;
    rep(i, n - 1) {
        ll _ans = a[i];
        // int j = 0;
        while(i < n) {
            if(a[i] == a[i + 1] || a[i] + 1 == a[i + 1]) {
                _ans += a[i + 1];
            } else break;
            i++;
        }
        ans.pb(_ans);
    }
    if(ans.size() == 0 || ans[0] == accumulate(ALL(a), 0ll)) {
        cout << 0 << endl;
        return 0;
    }
    if((a[n - 1] + 1) % m == a[0]) ans.pb(ans[0] + ans[ans.size() - 1]);

    ll mx = 0;
    for(auto aa : ans) chmax(mx, aa);

    cout << accumulate(ALL(a), 0LL) - mx << endl;
}
