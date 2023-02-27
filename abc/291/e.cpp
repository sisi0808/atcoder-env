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
* 一意に特定するための条件
1. 全ての頂点が連結であること
2. 最大の数は出次数0
3. 最小の数は入次数0
4. 2,3に当てはまる数が一つずつ存在
5. 4を取り除いた後の形は4
6. 5を繰り返して頂点数が1か0になったら終了
*/

int N, M;              // 頂点と辺の数
vector<vector<int>> G; // グラフ
vector<int> h;         // 入次数
vector<int> ans;       // 答えを格納
ll cnt = 0;

void topoBFS() {
    // queue<int> unchecked;
    priority_queue<int, vector<int>, greater<int>> unchecked;
    for(int i = 0; i < N; i++) {
        if(h[i] == 0) {
            unchecked.push(i); // 入次数が0の頂点をキューに入れる
        }
    }
    while(!unchecked.empty()) {
        if(unchecked.size() != 1) {
            no();
            exit(0);
        }
        int current = unchecked.top();
        unchecked.pop();
        ans[current] = cnt++;

        for(int next : G[current]) { // 「行ける」頂点について
            h[next]--;               // 入次数を減らす
            if(h[next] == 0) {       // 入次数0になったらキューに追加
                unchecked.push(next);
            }
        }
    }

    yes();
    for(int x : ans) {
        cout << x + 1 << " "; // 1始まりで出力するときはx+1とする
    }
    cout << endl;
}

int main(void) {
    fio();
    cin >> N >> M;
    G.resize(N);
    h.resize(N, 0); // 入次数0初期化
    ans.resize(N);
    int f, t;
    for(int i = 0; i < M; i++) {
        cin >> f >> t;
        f--;
        t--;               // 1始まりで辺の情報を入れるならデクリメントする
        G[f].push_back(t); // fからtに行ける
        h[t]++;            // tの入次数を増やす
    }

    topoBFS();
}
