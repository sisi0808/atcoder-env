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
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = vector<ll, ll>;
const int SIZE = 100005;
const int inf = 100000000;
const int modi = 1000000007;
const long long INF = 10000000000;
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

// これも鳩ノ巣

int main(void) {
    fio();
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> box(n + 1);     // i番目の数
    vector<ll> pre(n + 1, -1); // 配列のそのidxを見たか && それは何番目か
    int loop_start;            // ループ開始地点
    int loop_end;              // ループの終わり

    box[0] = 0;
    pre[0] = 0;
    rep(i, n) {
        box[i + 1] = box[i] + a[box[i] % n];
        if(pre[box[i + 1] % n] != -1) { // 既にそのidxを見ていた場合
            loop_start = pre[box[i + 1] % n];
            loop_end = i + 1;
            break;
        }
        pre[box[i + 1] % n] = i + 1;
    }
    // rep(i, n + 1) cout << pre[i] << endl;

    ll ans = 0;
    if(k < loop_start) ans = box[k];
    else {
        int loop_length = loop_end - loop_start;
        int loop_plus = (k - loop_start - 1) % loop_length;
        ll loop_cnt = (k - loop_start - 1) / loop_length;
        ans += box[loop_start + loop_plus + 1];
        ans += (box[loop_end] - box[loop_start]) * loop_cnt;
    }
    cout << ans << endl;
}
