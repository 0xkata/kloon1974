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
#define pb(a) push_back(a)
//---macros------------------------------------------ --------------------------
template <typename T> T gcd(T a, T b) { return a == 0 ? b : gcd((b % a), a); }
template <typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }
//------------------------------------------------------------------------------

const int N = 2000;
vi graph[N + 2];
bool vis[N + 2];

void dfs(int n) {
    vis[n] = 1;
    for (auto i : graph[n]) if(!vis[i]) dfs(i);
}

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    memset(vis, false, sizeof(vis));
    for (int i = 1, a, b; i <= m; ++i) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(a);
    cout << (vis[b] ? "GO SHAHIR!" :  "NO SHAHIR!") << endl;
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
