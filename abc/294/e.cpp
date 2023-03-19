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
    ll l, n, m;
    cin >> l >> n >> m;
    // vector<vector<ll>> v(2, vector<ll>(max(n, m)));
    // vector<vector<ll>> b(2, vector<ll>(max(n, m)));
    // rep(i, n) cin >> v[0][i] >> b[0][i];
    // rep(i, m) cin >> v[1][i] >> b[1][i];
    vector<vector<P>> v(2);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        v[0].pb({a, b});
    }
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        v[1].pb({a, b});
    }

    // しゃくとりベース
    // findで
    ll n_idx = 0; // 0~n
    ll n_l = 0;   // 0~L
    ll m_idx = 0; // 0~m
    ll m_l = 0;   // 0~L

    ll ans = 0;
    ll aa = 0;
    ll bb = 0;
    while(n_l < l || m_l < l) {
        if(n_l < m_l) {
            while(n_idx < n) {
                n_l += v[0][n_idx].second;
                if(v[0][n_idx].first == v[1][m_idx].first) ans += min(m_l, n_l) - aa;
                aa = n_l;
                if(m_l < n_l) break;
                n_idx++;
            }
            m_idx++;
        } else if(n_l > m_l) {
            while(m_idx < m) {
                m_l += v[1][m_idx].second;
                if(v[0][n_idx].first == v[1][m_idx].first) ans += min(m_l, n_l) - bb;
                bb = m_l;
                if(n_l < m_l) break;
                m_idx++;
            }
            n_idx++;
        } else { // ==
            n_l += v[0][n_idx].second;
            aa = n_l;
            while(m_idx < m) {
                m_l += v[1][m_idx].second;
                if(v[0][n_idx].first == v[1][m_idx].first) ans += min(m_l, n_l) - bb;
                bb = m_l;
                if(n_l < m_l) break;
                m_idx++;
            }
            n_idx++;
        }
    }
    cout << ans << endl;
}
