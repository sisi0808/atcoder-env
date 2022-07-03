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

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
* w_iのじゃがいもから始まった時、何個詰められるか記録
*


* ループ！

*/

int main(void) {
    fio();
    int n, q;
    cin >> n >> q;
    ll x;
    cin >> x;
    lvec w(n);
    lvec a(2 * n + 1);
    rep(i, n) cin >> w[i];
    rep(i, 2 * n) {
        a[i + 1] = a[i] + w[i % n];
    }

    ll weight_cnt = (x / a[n]) * n;
    x %= a[n];

    // ループ地点を求める
    int st = 0;
    // i番目開始の時、y個取れる
    vector<pair<int, ll>> box;
    /* 何番目のidxがループの何番目に出てくるか*/
    map<int, int> mp;
    while(!mp.count(st)) {
        mp[st] = box.size();
        ll cnt = weight_cnt;
        int idx = lower_bound(a.begin() + st, a.end(), x + a[st]) - a.begin();
        cnt += idx - st;   //何個野じゃがいもを手に入れられるか
        box.pb({st, cnt}); // st個目のジャガイモから見始めた時、何個ジャガイモが入るか
        st = idx % n;      // 何個目のジャガイモまで見終わったか
    }

    int non_loop_length = mp[st];
    int loop_length = (int)box.size() - non_loop_length;

    rep(i, q) {
        ll k;
        cin >> k;
        k--;
        if(k <= non_loop_length) {
            cout << box[k].second << endl;
        } else {
            k = (k - non_loop_length) % loop_length;
            cout << box[non_loop_length + k].second << endl;
        }
    }
}
