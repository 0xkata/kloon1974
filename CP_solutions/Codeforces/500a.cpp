#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//---typedef--------------------------------------------------------------------
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
//---alias----------------------------------------------------------------------
#define endl "\n"
#define MX 100010
#define pb(a) push_back(a)g
//---macros------------------------------------------ --------------------------
template <typename T> T gcd(T a, T b) { return a == 0 ? b : gcd((b % a), a); }
template <typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }
//------------------------------------------------------------------------------

vi graph[MX];
bool vis[MX];

void dfs(int n) {
    vis[n] = 1;
    for (int i = 0; i < graph[n].size(); ++i) {
        int next = graph[n][i];
        if (vis[next] == 0) dfs(next);
    }
}

void solve() {
    int n, destiny;
    cin >> n >> destiny;
    for (int i = 1, temp; i < n; ++i) {
        cin >> temp;
        graph[i].pb(temp + i);
    }

    dfs(1);
    cout << (vis[destiny] ? "YES" : "NO") << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    auto start = steady_clock::now();
    fastio();
    solve();
    auto end = steady_clock::now();
#ifndef TIMER
    double elapsed_time = double (duration_cast <nanoseconds> (end-start).count());
    cerr << "Time elapsed(s): " << elapsed_time / 1e9;
#endif
}
