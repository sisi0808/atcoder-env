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
using vs = vector<ll>;
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

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

ll N, Q;
ll X[100], Y[100], Z[100], W[100];
ll x[100], y[100], z[100], w[100];

long long bit_zentansaku() {
    long long ways = 0;
    for(int i = 0; i < (1 << N); i++) {
        long long bit[15];
        for(int j = 0; j < N; j++) bit[j + 1] = (i / (1 << j)) % 2;

        bool flag = true;
        for(int j = 1; j <= Q; j++) {
            if(((bit[x[j]] | bit[y[j]]) | bit[z[j]]) != w[j]) flag = false;
        }
        if(flag == true) ways++;
    }
    return ways;
}

int main() {
    // Step #1. Input
    cin >> N >> Q;
    for(int i = 1; i <= Q; i++) cin >> X[i] >> Y[i] >> Z[i] >> W[i];

    // Step #2. Brute Force
    // 全てのビットについてそれぞれ探索
    mint ans = 1;
    for(int i = 0; i < 60; i++) {
        for(int j = 1; j <= Q; j++) {
            x[j] = X[j];
            y[j] = Y[j];
            z[j] = Z[j];
            w[j] = (W[j] / (1LL << i)) % 2LL;
        }
        /* そのビットにおいて、w[j].equal()が成り立つn個の数列の組み合わせの数 */
        ll ret = bit_zentansaku();
        ans *= ret;
    }
    cout << ans.val() << endl;
    return 0;
}