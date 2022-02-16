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

const int N = 26;
vi adj[N + 2];
bool vis[N + 2];

void dfs(int n) {
    if (vis[n]) return;
    vis[n] = true;

    for (auto u : adj[n]) {
        dfs(u);
    }
}

void solve() {
    int n, a, b; cin >> n;
    string s;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
        cin >> s;
        a = s[0]-65, b = s[1]-65;
        adj[a].pb(b);
    }

    dfs(12);

    cout << (vis[3] ? "MAXJIANG-YES" : "MAXJIANG-NO") << endl;
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("Input.txt", "r", stdin);
//     freopen("Output.txt", "w", stdout);
//     freopen("Error.txt", "w", stderr);
// #endif
//  auto start = steady_clock::now();
    fastio();
    solve();
//  auto end = steady_clock::now();
// #ifndef TIMER
//     double elapsed_time = double (duration_cast <nanoseconds> (end-start).count());
//     cerr << "Time elapsed(s): " << elapsed_time / 1e9;
// #endif
}
