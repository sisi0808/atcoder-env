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
const string ALP = "ABCDEFGHIkkKLMNOPQRSTUVWXYZ";
const string alp = "abcdefghijklmnopqrstuvwxyz";

using mint = modint998244353;
// using mint = modint1000000007;
// cout << fixed << setprecision(12);

/*
n <= 250,000

条件１：その数が行の中で一番小さく、それ超過の数が列に存在する
条件２：その数が列の中で一番大きく、それ未満の数が列に存在する
条件３： １と２両方を満たす
条件４： １と２両方を満たさない
    行の中で一番大きく、列の中で一番小さい

1は必ず条件１を満たす
n^2は必ず条件２を満たす

dp?

逆に、満たさないのはどんな場合か
* ある行のすべての数が、ある列のすべての数より小さい

*/

int main(void) {
    fio();
    int n;
    cin >> n;

    mint n1 = 1;
    mint n2 = 1;
    mint n3 = 1;

    repp(i, n * n + 1, 1) {
        n1 *= i;
    }
    repp(i, n + 1, 1) {
        n2 *= i;
    }
    repp(i, 2 * n, 1) {
        n3 *= i;
    }
    mint ans = n1 - n1 * n2 * n2 / n3;
    cout << ans.val() << endl;
}
