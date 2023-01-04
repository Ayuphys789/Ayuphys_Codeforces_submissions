
// 1749_D Counting Arrays
// #187929250

/*
diff:1900
解法:
数列aがambiguousでない必要十分条件は,a_iがi以下の素数で割り切れないこと
not_ambiguousな数列についてa_iの取りうる値の種類b_iはMをi以下の素数で割ったもの
各iについて素数判定をO(logN)を行うことでb_iを全て得られ,
b_1~b_K総積が,長さがKのnot_ambiguousな数列の数
長さがKの数列の総数はM^Kなので,これから引くことでambiguousな数列の総数を得られる
各KについてK-1の結果を用いて貪欲に求められるので,
O(NlogN)で解が得られる
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
 
bool isPrime(long long n)
{
    if (n <= 1)
        return false;
    for (long long p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
            return false;
    }
    return true;
}
 
int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    ll F1 = M % MOD, F2 = M, F3 = M % MOD;
    ll sum = 0;
    FOR(i, 2, N)
    {
        F3 = F3 * (M % MOD) % MOD;
        if (isPrime(i))
            F2 /= i;
        F1 = F1 * (F2 % MOD) % MOD;
        sum = (sum + F3 - F1 + MOD) % MOD;
    }
    cout << sum << endl;
    return 0;
}
