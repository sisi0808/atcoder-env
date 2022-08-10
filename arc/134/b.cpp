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

/*
先頭を選ぶ際は、なるべくidxが小さいもの(理想は、先頭がa)
後ろを選ぶ際は、なるべくidxが大きいもの(理想は、末尾が)

入れ替え対象の文字と前回の入れ替えの末尾の範囲で最小の文字を探す

入れ替えに掛かる計算量はほぼ無視できる
* 既定範囲内の最小自助順の文字を求める

* 自分より小さいidxで、自分より辞書順が早い文字をメモ？
* a-zは26字しかないので、計算量を減らしやすい？

入れ替える者同士を線で結ぶと、それらの線は交じり合わない
*/

int main(void) {
    fio();
    int n;
    cin >> n;
    string s;
    cin >> s;

    /* どのアルファベットが何文字目に出てきたかをメモ */
    map<char, vector<int>> mp;

    int mn = 0;
    rep(i, n) {
        mp[s[i]].pb(i);
        chmin(mn, s[i] - 'a');
    }

    int l = n;
    rep(i, n) {
        if(i >= l) break;
        // 自分より辞書順で早い文字が、自分より後のidxにあるか捜索
        repp(j, s[i] - 'a', mn) {
            if(!mp[j + 'a'].empty()) {
                auto it = lower_bound(ALL(mp[j + 'a']), l);
                if(it == mp[j + 'a'].begin()) continue;
                it--;
                if(i < *it && *it < l) {
                    swap(s[*it], s[i]);
                    l = *it;
                    break;
                }
            }
        }
        // cout << s << ":" << l << endl;
    }

    cout << s << endl;
}
