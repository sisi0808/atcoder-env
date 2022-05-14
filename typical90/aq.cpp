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

int h, w;
int yy1, xx1, yy2, xx2;
vector<string> s;
vector<vector<vector<int>>> dist;

bool judge_root(int y, int x) {
    if(y < 0 || x < 0 || y >= h || x >= w) return false;
    if(s[y][x] == '#') return false;
    return true;
}

/* (現在の位置、現在の位置)*/
void bfs(int y, int x) {
    rep(i, 4) dist[y][x][i] = 0;

    queue<pair<int, P>> q;
    rep(i, 4) q.push({i, {y, x}});

    while(!q.empty()) {
        auto st = q.front();
        q.pop();
        int dd = st.first;
        int yy, xx;
        tie(yy, xx) = st.second;

        rep(i, 4) {
            if(judge_root(yy + dy[i], xx + dx[i])) {
                if(dd == i && dist[yy + dy[i]][xx + dx[i]][i] > dist[yy][xx][dd]) {
                    dist[yy + dy[i]][xx + dx[i]][i] = dist[yy][xx][dd];
                    q.push({i, {yy + dy[i], xx + dx[i]}});
                } else if(dist[yy + dy[i]][xx + dx[i]][i] > dist[yy][xx][dd] + 1) {
                    dist[yy + dy[i]][xx + dx[i]][i] = dist[yy][xx][dd] + 1;
                    q.push({i, {yy + dy[i], xx + dx[i]}});
                }
            }
        }
    }
}

int main(void) {
    fio();
    cin >> h >> w;
    cin >> yy1 >> xx1 >> yy2 >> xx2;
    yy1--;
    xx1--;
    yy2--;
    xx2--;
    s.resize(h);
    dist.resize(h, vector<vector<int>>(w, vector<int>(4, inf)));
    rep(i, h) cin >> s[i];

    bfs(yy1, xx1);

    ll ans = INF;
    rep(i, 4) {
        chmin(ans, dist[yy2][xx2][i]);
    }
    pri(ans);
}
