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
BFS
*/
ll n, m;
bool judge(int ii, int jj) {
    if(ii < 0 || jj < 0) return false;
    if(ii >= n || jj >= n) return false;
    return true;
}

int main(void) {
    fio();
    cin >> n >> m;

    /* m=i^2+j^2が成り立つijの組み合わせを探索 */
    vector<P> p;
    for(int i = 0; i * i <= m; i++) {
        int j = sqrt(m - i * i);
        if(j * j == m - i * i) p.pb({i, j});
    }

    Graph g(n, vector<ll>(n, -1));

    g[0][0] = 0;
    queue<P> pp;
    pp.push({0, 0});

    int d1[] = {1, -1, -1, 1};
    int d2[] = {1, 1, -1, -1};

    while(!pp.empty()) {
        int y = pp.front().first;
        int x = pp.front().second;
        pp.pop();

        /* 到達出来る頂点を探索 */
        rep(i, p.size()) {
            rep(j, 4) {
                int ii = y + p[i].first * d1[j];
                int jj = x + p[i].second * d2[j];
                if(judge(ii, jj) && g[ii][jj] == -1) {
                    g[ii][jj] = g[y][x] + 1;
                    pp.push({ii, jj});
                }
            }
        }
    }

    rep(i, n) {
        rep(j, n) {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
}
