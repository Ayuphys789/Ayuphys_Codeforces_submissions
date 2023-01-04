
// 1779_D Boris and His Amazing Haircut
// submission #187947445

/*
diff:-
解法:
各iについて,iを切るときにレーザーを使う範囲の右端をstackを用いて求める
上の結果を用いてそれぞれのレーザーの必要個数を求める(a_i=b_iの時必要でないので除く)
必要個数が用意されたレーザーの個数以下ならばYES
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <functional>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <array>
#include <random>
#include <cstdlib>
#include <cassert>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REP(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define rFOR(i, a, b) for (ll i = a; i >= b; i--)
#define all(x) x.begin(), x.end()
#define Graph vector<vector<ll>>
#define fcout cout << fixed << setprecision(15)
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078160628620899
const ll INF = 1000000000000000000;
const ll NIL = -1;
const ll MOD = 998244353;
// const ll MOD = 1000000007;
const ll dx[4] = {0, 1, 0, -1};
const ll dy[4] = {1, 0, -1, 0};

void solve(void)
{
    ll N, M;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    cin >> M;
    vector<ll> C(M);
    rep(i, M) cin >> C[i];
    map<ll, ll> CAN, END, NEED;
    rep(i, N)
    {
        if (B[i] > A[i])
        {
            cout << "NO\n";
            return;
        }
    }
    stack<ll> S;
    vector<ll> V(N);
    rep(i, N)
    {
        while (!S.empty() && B[S.top()] < B[i])
        {
            ll val = S.top();
            V[val] = i;
            S.pop();
        }
        S.push(i);
    }
    while (!S.empty())
    {
        ll val = S.top();
        V[val] = N;
        S.pop();
    }
    rep(i, M)
    {
        CAN[C[i]]++;
    }
    rep(i, N)
    {
        if (i >= END[B[i]] && B[i] != A[i])
        {
            END[B[i]] = V[i];
            NEED[B[i]]++;
        }
    }
    for (auto &it : NEED)
    {
        if (CAN[it.first] < it.second)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
