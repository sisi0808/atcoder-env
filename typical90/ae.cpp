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

int N;
int A[1 << 18], B[1 << 18];

int grundy[55][1555];

void init() {
    for(int i = 0; i <= 50; i++) {
        for(int j = 0; j <= 1500; j++) {
            /* 初期化 */
            int mex[1555];
            for(int k = 0; k < 1555; k++) mex[k] = 0;

            if(i >= 1) {
                mex[grundy[i - 1][j + i]] = 1;
            }
            if(j >= 2) {
                for(int k = 1; k <= (j / 2); k++) mex[grundy[i][j - k]] = 1;
            }
            for(int k = 0; k < 1555; k++) {
                if(mex[k] == 0) {
                    grundy[i][j] = k;
                    break;
                }
            }
        }
    }
}

int main() {
    // Step #1. Input
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N; i++) cin >> B[i];

    // Step #2. Initialize
    init();

    // Step #3. Get Answer
    int sum_xor = 0;
    for(int i = 1; i <= N; i++) {
        sum_xor ^= grundy[A[i]][B[i]];
    }

    // Step #4. Output
    if(sum_xor != 0) cout << "First" << endl;
    if(sum_xor == 0) cout << "Second" << endl;
    return 0;
}