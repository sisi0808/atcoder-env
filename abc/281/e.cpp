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

/*
* i番目まで見た時に、大きい方からj番目だった数は、i+1を見た時に、大きい方からj+1,j,j-1番目にいる

* 追加 or 削除される数が
    * 番人v[k]より大きい場合: 影響なし
    * 番人v[k]より小さい場合: 合計が変化
    *
    *
* 番人と同じ数が何個あるかだけ管理する必要がある
*/

int main(void) {
    fio();
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b;
    rep(i, n) cin >> a[i];

    // bに先頭k個をコピー
    copy(a.begin(), a.begin() + m, back_inserter(b));
    sort(ALL(b));

    vector<ll> ans(n - m + 1);
    multiset<ll> st_k; // 先頭k個
    multiset<ll> st_l; // 先頭k個以降
    rep(i, b.size()) {
        if(i < k) {
            st_k.insert(b[i]);
            ans[0] += b[i];
        } else st_l.insert(b[i]);
    }
    // m=k=1対策
    st_k.insert(0);
    st_l.insert(INF);

    // iが消えて、i+mが増える
    rep(i, n - m) {
        ans[i + 1] = ans[i];
        // 削除
        // 先頭k個に含まれている時
        if(st_k.find(a[i]) != st_k.end()) {
            st_k.erase(st_k.find(a[i]));
            st_k.insert(*st_l.begin());
            st_l.erase(st_l.begin());
            ans[i + 1] = ans[i + 1] - a[i] + *st_k.rbegin();
        } else { // k個以降に含まれている時
            st_l.erase(st_l.find(a[i]));
        }

        // 追加
        // 先頭k個にはいる場合
        if(a[i + m] < *st_k.rbegin()) {
            // cout << *st_k.rbegin() << endl;
            st_l.insert(*st_k.rbegin());
            st_k.erase(prev(st_k.end()));
            st_k.insert(a[i + m]);
            ans[i + 1] = ans[i + 1] + a[i + m] - *st_l.begin();
        } else { // k個以降に入る場合
            st_l.insert(a[i + m]);
        }
    }

    rep(i, n - m + 1) cout << ans[i] << " ";
    cout << endl;
}
