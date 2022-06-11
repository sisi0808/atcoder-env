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
/*
i番目のアイテムを使う前に、AiとBiのアイテムのどちらかを使っていない
*/

int main(void) {
    fio();
    int n;
    cin >> n;
    vs a(n + 1), b(n + 1);
    vector<bool> used(n + 1, false);
    graph g(n + 1);
    queue<int> q;

    repp(i, n + 1, 1) {
        cin >> a[i] >> b[i];
        g[a[i]].push_back(i);
        g[b[i]].push_back(i);
        if(a[i] == i || b[i] == i) {
            used[i] = true;
            q.push(i);
        }
    }

    /* 後ろからシミュレーション */
    vs ans;
    while(!q.empty()) {
        int pos = q.front();
        q.pop();
        ans.push_back(pos);
        for(int i : g[pos]) {
            if(used[i]) continue;
            used[i] = true;
            q.push(i);
        }
    }

    reverse(ALL(ans));
    if(ans.size() != n) pri(-1);
    else {
        for(auto _ans : ans) pri(_ans);
    }
}