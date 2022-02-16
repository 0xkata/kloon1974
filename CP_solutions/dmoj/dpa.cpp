#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//---typedef--------------------------------------------------------------------
typedef long long ll;
typedef long long unsigned llu;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
//---alias----------------------------------------------------------------------
#define endl "\n"
#define inf 0x3f3f3f3f
#define pb(a) push_back(a)
//---macros------------------------------------------ --------------------------
template <typename T> T gcd(T a, T b) { return a == 0 ? b : gcd((b % a), a); }
template <typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }
//------------------------------------------------------------------------------

void solve() {
    int n; cin >> n; 
    int arr[n];
    int dp[n];
    fill (dp, dp + n, inf);

    for (int i = 0; i < n; ++i) cin >> arr[i];

    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);
    for (int i = 2; i < n; ++i) {
        int dis1 = abs(arr[i - 1] - arr[i]) + dp[i - 1];
        int dis2 = abs(arr[i - 2] - arr[i]) + dp[i - 2];
        dp[i] = min(dp[i], dis1);
        dp[i] = min(dp[i], dis2);
    }

    cout << dp[n - 1] << endl;
}

int main() {
    fastio();
    solve();
}
