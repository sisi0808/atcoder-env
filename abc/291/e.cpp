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

ll n, m;
vector<set<int>> g;
vector<set<int>> in;
vector<set<int>> out;

vector<int> ans;

int main(void) {
    fio();
    cin >> n >> m;

    g.resize(n);
    in.resize(n);
    out.resize(n);
    ans.resize(n);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].insert(b); // 小さい方から大きい方への有向グラフ
        in[b].insert(a);
        out[a].insert(b);
    }

    set<int> st;
    rep(i, n) st.insert(i);
    ll cnt = 0;
    while(st.size() > 1) {
        ll in_cnt = 0, out_cnt = 0;
        ll in_num = 0, out_num = 0;
        for(auto i : st) {
            if(out[i].size() == 0) in_cnt++, in_num = i;
            if(in[i].size() == 0) out_cnt++, out_num = i;
        }
        if(in_cnt == 1 && out_cnt == 1) {
            // 削除
            st.erase(in_num);
            st.erase(out_num);
            for(auto it : in[in_num]) out[it].erase(in_num);
            for(auto it : out[out_num]) in[it].erase(out_num);
            ans[in_num] = n - cnt;
            ans[out_num] = cnt + 1;
        } else {
            no();
            return 0;
        }
        cnt++;
    }
    if(st.size() == 1) {
        for(auto i : st) ans[i] = cnt + 1;
    }
    yes();
    rep(i, n) cout << ans[i] << " ";
    cout << endl;
}
