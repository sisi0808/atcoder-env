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

// alias g++='g++ -I/mnt/c/Users/Owner/Desktop/ac-library'
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
const int SIZE = 100005;
const int inf = 1000000000;
const int modi = 1000000007;
const long long INF = 1000000000000000;
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
    int n;
    cin >> n;
    ll A = (1 << n);
    vector<ll> a(A);
    rep(i, A) cin >> a[i];

    /* 解2 */
    /* 準優勝は優勝する選手と反対のブロックで一番レートが高い選手という性質を利用 */

    auto itr = max_element(ALL(a)) - a.begin();
    // cout << itr << endl;
    if(itr + 1 > A / 2) {
        auto itr2 = max_element(a.begin(), a.begin() + A / 2) - a.begin();
        cout << itr2 + 1 << endl;
    } else {
        auto itr2 = max_element(a.begin() + A / 2, a.end()) - a.begin();
        cout << itr2 + 1 << endl;
    }
    /* 解1 */
    /* トーナメントをすべてシュミレートする */

    /*
    ll wl = A;
    rep(i, n - 1) {
        rep(j, wl) {
            if(a[j] != 0) {
                ll ij = j + 1;
                while(a[ij] == 0) {
                    ij++;
                }
                if(a[j] < a[ij])
                    a[j] = 0;
                else
                    a[ij] = 0;
                j = ij;
            }
        }
    }
    ll max_n = *max_element(ALL(a));
    rep(i, wl) {
        if(a[i] != 0 && a[i] != max_n)
            cout << i + 1 << endl;
    }
    */
}
