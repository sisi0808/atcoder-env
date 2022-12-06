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
const int inf = 1000000000;
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

using mint = modint998244353;
// using mint = modint1000000007;

/*
* HW <= 16
* a <= 8
* b <= 16

* どの順番、どの向きに入れるかを全探索すればよい？
*/

ll h, w;
bool used[16][16];

// (x,y,a) = (今見ている列, 今見ている行, 残りの長方形のタイルの数)
int dfs(int x, int y, int a) {

    // 最後まで探索して、長方形のタイルを使い切っているなら、組合せを+1する
    if(h == y) return a == 0;

    // 横の端まで行ったら次の行へ
    if(w == x) return dfs(0, y + 1, a);

    // 既に置かれているなら何もできないので、次のマスへ
    if(used[y][x]) return dfs(x + 1, y, a);

    int res = 0;

    // 縦置き
    if(y + 1 < h && !used[y + 1][x] && 0 < a) {
        used[y][x] = used[y + 1][x] = true;
        res += dfs(x + 1, y, a - 1);
        used[y][x] = used[y + 1][x] = false;
    }

    // 横置き
    if(x + 1 < w && !used[y][x + 1] && 0 < a) {
        used[y][x] = used[y][x + 1] = true;
        res += dfs(x + 1, y, a - 1);
        used[y][x] = used[y][x + 1] = false;
    }

    // 何も置かない
    res += dfs(x + 1, y, a);

    return res;
}
int main(void) {
    fio();
    cin >> h >> w;
    ll a, b;
    cin >> a >> b;

    cout << dfs(0, 0, a) << endl;
}
