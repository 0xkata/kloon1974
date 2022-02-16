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
    int n, a, b; cin >> n >> a >> b;
    vi v(n);
    for (int &x : v) {
        cin >> x;
    }

    int count = 0;
    while (a < b) {
        int j = -1;
        for (int i = 0; i < n; ++i) {
            if (v[i] > a) continue;
            if (j == -1) {
                j = i;
            }
        }
        if (j == -1) {
            cout << -1 << endl;
            return;
        }
        a += v[j];
        v[j] = inf;
        count++;
    }

    cout << count << endl;
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
