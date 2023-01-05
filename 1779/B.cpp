
// 1779_B MKnez's ConstructiveForces Task
// submission #187785790

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
 
ll T;
 
int main(void)
{
    cin >> T;
    while (T--)
    {
        ll N;
        cin >> N;
        if (N == 3)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if (N % 2)
        {
            ll M = N / 2;
            rep(i, M) cout << -(M - 1) << " " << M << " ";
            cout << -(M - 1);
            cout << endl;
            continue;
        }
        rep(i, N / 2) cout << 1 << " " << -1 << " ";
        cout << endl;
    }
    return 0;
}
