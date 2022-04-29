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

using mint = modint998244353;
// using mint = modint1000000007;
// cout << fixed << setprecision(12);
int n;
graph g(1001, vector<int>(1001, 0));

int main(void) {
    fio();
    cin >> n;
    int lx[n], ly[n], rx[n], ry[n];
    rep(i, n) cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
    rep(i, n) {
        g[lx[i]][ly[i]] += 1;
        g[lx[i]][ry[i]] -= 1;
        g[rx[i]][ly[i]] -= 1;
        g[rx[i]][ry[i]] += 1;
    }
    rep(i, 1001) {
        repp(j, 1001, 1) {
            g[i][j] += g[i][j - 1];
        }
    }
    repp(i, 1001, 1) {
        rep(j, 1001) {
            g[i][j] += g[i - 1][j];
        }
    }

    map<int, int> mp;
    rep(i, 1000) rep(j, 1000) mp[g[i][j]]++;

    repp(k, n + 1, 1) {
        cout << mp[k] << endl;
    }
}
