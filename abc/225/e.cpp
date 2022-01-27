#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include<atcoder/all>
using namespace atcoder;

#define fio()         \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define rrep(i, n) for(int i = n; i > 0; --i)
#define repp(i, n, m) for(int i = m; i < int(n); ++i)
#define fore(i_in, a) for(auto &i_in : a)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = vector<ll, ll>;
const int SIZE = 100005;
const int inf = INT_MAX;
const int modi = 1000000007;
const long long INF = LLONG_MAX;
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

graph G;
using mint = modint998244353;


struct frac{
    /* (p,q) = (y,x) */
    ll p,q;
    /* x/yを昇順に並び替えた時、最も小さくなる数で初期化 */
    frac(ll P=1, ll Q=0): p(P), q(Q){}

    /* 傾きが大きいほど(x/yが小さいほど)、座標の左側に位置する！ */
    bool operator<(const frac &other) const{
        /* x1/y1 < x2/y2 の式変形 */
        return q*other.p < p*other.q;
    }
    bool operator<=(const frac &other) const{
        /* x1/y1 <= x2/y2 の式変形 */
        return q*other.p <= p*other.q;
    }
};

int main(void){
    fio();
    int n; cin >> n;
    vector<pair<frac, frac>> p;
    vector<ll> x(n),y(n);

    rep(i,n){
        cin >> x[i] >> y[i];
    }

    rep(i,n) p.push_back({frac(y[i], x[i]-1), frac(y[i]-1, x[i])});
    /* p[i].second を基準にソート */
    sort(ALL(p), [&](pair<frac,frac> a, pair<frac,frac> b) {return a.second < b.second; });

    int ans = 0;
    frac r;
    rep(i,n){
        if(r <= p[i].first){
            r = p[i].second;
            ans++;
        }
    }

    cout << ans << endl;
}
