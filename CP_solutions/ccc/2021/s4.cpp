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

const int N = 200000 + 5;
vi graph[N];
int p[N], s[N];
bool vis[N];
multiset<int> sum;

void bfs(int n) {
    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int o = q.front(); q.pop();
        for (auto i : graph[o]) {
            if (vis[i]) continue;
            vis[i] = 1;
            p[i] = p[o] + 1;
            q.push(i);
        }
    }
}

void solve() {
    int n, w, d; cin >> n >> w >> d;
    
    for (int i = 0, a, b; i < w; ++i) {
        cin >> a >> b;
        graph[b].pb(a);
    }

    fill(p, p + n, inf);
    p[n] = 0;

    memset(vis, 0, sizeof(vis));
    vis[n] = 1;

    bfs(n);

    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        sum.insert(i - 1 + p[s[i]]);
    }

    for (int i = 0; i < d; ++i) {
        int s1, s2; cin >> s1 >> s2;

        int s1PrevDist = s1 - 1 + p[s[s1]];
        int s2PrevDist = s2 - 1 + p[s[s2]];

        sum.erase(sum.find(s1PrevDist));
        sum.erase(sum.find(s2PrevDist));

        swap(s[s1], s[s2]);

        sum.insert(s1 - 1 + p[s[s1]]);
        sum.insert(s2 - 1 + p[s[s2]]);

        cout << *sum.begin() << endl;
    }
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
