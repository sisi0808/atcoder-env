#include <bits/stdc++.h>
/* ACLのライブラリを追加*/
#include<atcoder/all>
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
//using mint = modint1000000007;
/*
まずはN角形の1辺の角度を求める
更に、x2,y2からどっち向きに回せばいいかを判断する
２つの座標から、線分の長さを求めることが可能
平面の時の座標を求めて、そこから回転させる？

1. 線分の長さを求める
2. 対角線状にその頂点があると仮定して、座標を計算
角度と線分の長さが分かれば、座標がわかるはず
3. その後、その座標を角度/2分回転させる
*/

int main(void){
    fio();
    int n; cin >> n;
    double x,y;
    complex<double> p0, p1;
    cin >> x >> y; p0 = {x,y};
    cin >> x >> y; p1 = {x,y};

    /* 対角線の中心座標 */
    auto m = (p0 + p1) / 2.0;

    /* 答えの算出 */
    auto res = m + (p0 - m) * polar(1.0, M_PI*2.0/n);

    cout << setprecision(9) << res.real() << " " << res.imag() << endl;
}
