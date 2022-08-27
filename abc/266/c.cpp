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

// using mint = modint998244353;
using mint = modint1000000007;
// cout << fixed << setprecision(12);

typedef struct edge {
    double x;
    double y;
};

int main(void) {
    fio();
    vector<vector<double>> a(4, vector<double>(2));
    rep(i, 4) rep(j, 2) cin >> a[i][j];

    bool ans = true;
    rep(i, 4) {
        double x1 = a[(i + 3) % 4][0];
        double y1 = a[(i + 3) % 4][1];
        double x2 = a[i][0];
        double y2 = a[i][1];
        double x3 = a[(i + 1) % 4][0];
        double y3 = a[(i + 1) % 4][1];

        edge v1, v2;
        v1.x = x1 - x2;
        v1.y = y1 - y2;
        v2.x = x3 - x2;
        v2.y = y3 - y2;
        double d1, d2, v12, cosd, deg, rad;

        // sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3))
        d1 = sqrt(v1.x * v1.x + v1.y * v1.y);
        d1 *= d1 < 0 ? -1 : 1;
        d2 = sqrt(v2.x * v2.x + v2.y * v2.y);
        d2 *= d2 < 0 ? -1 : 1;
        v12 = v1.x * v2.x + v1.y * v2.y;
        cosd = v12 / (d1 * d2);
        rad = acos(cosd);
        deg = rad / M_PI * 180;
        // cout << deg << endl;

        double p0x, p0y, p1x, p1y, p2x, p2y;
        double px, py;
        p0x = x1;
        p0y = y1;
        p1x = a[(i + 2) % 4][0];
        p1y = a[(i + 2) % 4][1];
        p2x = x3;
        p2y = y3;
        px = x2;
        py = y2;

        double Area = 0.5 * (-p1y * p2x + p0y * (-p1x + p2x) + p0x * (p1y - p2y) + p1x * p2y);
        double s = 1 / (2 * Area) * (p0y * p2x - p0x * p2y + (p2y - p0y) * px + (p0x - p2x) * py);
        double t = 1 / (2 * Area) * (p0x * p1y - p0y * p1x + (p0y - p1y) * px + (p1x - p0x) * py);
        // cout << s << ' ' << t << endl;
        if(0 < s && s < 1 && (0 < t && t < 1 && 0 < 1 - s - t && 1 - s - t < 1)) deg = 360 - deg;
        // cout << deg << endl;

        if(deg >= 180) ans = false;
    }
    yn(ans);
}
