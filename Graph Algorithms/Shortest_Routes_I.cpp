// Author : rs258
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, 
tree_order_statistics_node_update>;
template <typename T>
using omultiset = tree<T, null_type, less_equal<T>, rb_tree_tag, 
tree_order_statistics_node_update>; 

#define ll         long long
#define ld         long double
#define endl       "\n"
#define pb         push_back
#define vll        vector<ll>
#define vvll       vector<vll>
#define pll        pair<ll,ll>
#define vbool      vector<bool>
#define vvbool     vector<vbool>
#define vstr       vector<string>
#define vpair      vector<pll>
#define F          first
#define S          second
#define mp(x,y)    make_pair(x,y)
#define all(a)     a.begin(),a.end()
#define rall(a)    a.rbegin(),a.rend()
#define rev(a)     reverse(all(a))
#define unq(a)     a.erase(std::unique(all(a)),a.end());
#define fr(i,a,b)  for(ll i=a;i<b;i++)
#define rf(i,a,b)  for(ll i=a;i>=b;i--)
#define yes()      cout<<"YES"<<endl
#define no()       cout<<"NO"<<endl
#define err()      cout<<"===========\n";
#define errA(A)    for(auto i:A) cout<<i<<" ";cout<<"\n";
#define err1(a)    cout<<#a<<" "<<a<<"\n"
#define err2(a,b)  cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n"

const ll mod1 =    1000000007;
const ll mod2 =    998244353;
const ll infi =    1e18;
const ld eps  =    1e-9;

ll test_case = 0;
void google() {
    test_case++;
    cout << "Case #" << test_case << ": ";
}

ll pwr(ll a, ll b) {
    ll res = 1;
    while (b > 0) { 
        if (b & 1) res = (res * a);   
        a = (a * a); b >>= 1;
    }
    return res;
}

ll modpwr(ll a, ll b, ll x = mod1) {
    ll res = 1; 
    while (b > 0) { 
        if (b & 1) res = (res * a) % x;
        a = (a * a) % x; b >>= 1;
    } 
    return res;
}

ll modInverse(ll n, ll p = mod1) { 
    return modpwr(n, p - 2, p); 
}

template <typename T>
struct graph {
    struct edge {
        ll from, to;
        T cost;
    };
    ll n;
    bool directed;
    vector<edge> edges;
    vector<vector<ll>> g;
    graph(ll _n, bool d = false) {
        n = _n;
        directed = d;
        g.resize(n);
    }
    ll add(ll u, ll v, T c = 1) {
        ll id = (ll)edges.size();
        g[u].pb(id);
        if(!directed) {
            g[v].pb(id);
        }
        edges.push_back({u, v, c});
        return id;
    }
};

template <typename T>
vector<T> dijkstra(const graph<T> &g, ll src) {
    assert(0 <= src && src < g.n);
    vector<T> dist(g.n, numeric_limits<T>::max());
    priority_queue<pair<T, ll>, vector<pair<T, ll>>, greater<pair<T, ll>>> s;
    dist[src] = 0;
    s.emplace(dist[src], src);
    while (!s.empty()) {
        T expected = s.top().first;
        ll i = s.top().second;
        s.pop();
        if (dist[i] != expected) {
            continue;
        }
        for (ll id : g.g[i]) {
            auto &e = g.edges[id];
            ll to = e.from ^ e.to ^ i;
            if (dist[i] + e.cost < dist[to]) {
                dist[to] = dist[i] + e.cost;
                s.emplace(dist[to], to);
            }
        }
    }
    return dist;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    graph<ll> g(n, true);
    fr(i, 0, m) {
    	ll a, b, c;
    	cin >> a >> b >> c;
    	g.add(a - 1, b - 1, c);
    } 
    vll ans = dijkstra<ll>(g, 0);
    errA(ans);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t = 1; 
    while(t--) solve();
    return 0;
}
