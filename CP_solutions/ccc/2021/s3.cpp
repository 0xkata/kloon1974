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
#define MX 100010
#define pb(a) push_back(a)
//---macros------------------------------------------ --------------------------
template <typename T> T gcd(T a, T b) { return a == 0 ? b : gcd((b % a), a); }
template <typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }
//------------------------------------------------------------------------------

int n;
vi p, w, d;

ll move(int pos) { // Takes pos of concert and return walking time for friends
    ll time = 0;
    for (int i = 0; i < n; ++i) { // each friend
        int ls = p[i] - d[i]; // left and right hearing range
        int rs = p[i] + d[i];

        // Check base cases (if friends can already hear it)
        if (pos >= ls && pos <= rs) {
            continue;
        }

        int close = rs;
        if (abs(pos - ls) < abs(pos - rs)) {
            close = ls;
        }

        time += (ll) w[i] * abs(pos - close);
    }
    return time;
}

void solve() {
    cin >> n;
    p.resize(n); w.resize(n); d.resize(n);
    int l = INT_MAX, r = INT_MIN;

    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> w[i] >> d[i];
        l = min(l, p[i]);
        r = max(r, p[i]);
    }

    // ternary search
    // algorithm to find the min of a function without using derivatives
    ll best = 1e18;
    for (int i = 0; i < 60; ++i) {
        int delta = (r - l) / 3;
        int m1 = l + delta;
        int m2 = r - delta;
        ll t1 = move(m1);
        ll t2 = move(m2);
        best = min(t1, best);
        best = min(t2, best);
        if (t1 > t2) {
            l = m1;
        }
        else {
            r = m2;
        }
    }
    cout << best << endl;
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
