// Author : rs258
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

#define RB rb_tree_tag
#define TSNU tree_order_statistics_node_update
template <typename T>
using oset = tree<T,null_type,less<T>,RB,TSNU>;
template <typename T>
using omultiset = tree<T,null_type,less_equal<T>,RB,TSNU>; 

#define ll         long long
#define ld         long double
#define endl       "\n"
#define pb         push_back
#define vll        vector<ll>
#define vvll       vector<vll>
#define pll        pair<ll,ll>
#define vbool      vector<bool>
#define vpair      vector<pll>
#define F          first
#define S          second
#define mp(x,y)    make_pair(x,y)
#define all(a)     a.begin(),a.end()
#define rall(a)    a.rbegin(),a.rend()
#define mx(a)      *max_element(all(a))
#define mn(a)      *min_element(all(a))
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
const ll N    =    1005;

ll n, m;
char A[N][N];
bool vis[N][N];
ll previousStep[N][N];

ll dx[4] = { -1, 0, 1, 0 };
ll dy[4] = { 0, 1, 0, -1 };
string stepDir = "URDL";

void solve() {
    cin >> n >> m;
    queue<pll> q;
    pll begin, end;
    fr (i, 0, n) {
        fr (j, 0, m) {
            cin >> A[i][j];
            if (A[i][j] == 'A') {
                begin = mp(i, j);
            } else if (A[i][j] == 'B') {
                end = mp(i, j);
            }
        }
    }

    q.push(begin);
    vis[begin.F][begin.S] = true;

    while (!q.empty()) {
        pll u = q.front(); q.pop();
        fr(i, 0, 4) {
            pll v = mp(u.F + dx[i], u.S + dy[i]);
            if (v.F < 0 || v.F >= n || v.S < 0 || v.S >= m) continue;
            if (A[v.F][v.S] == '#') continue;
            if (vis[v.F][v.S]) continue;
            vis[v.F][v.S] = true;
            previousStep[v.F][v.S] = i;
            q.push(v);
        }
    }

    if (vis[end.F][end.S]) {
        yes();
        vll steps;
        while (end != begin) {
            ll p = previousStep[end.F][end.S];
            steps.pb(p);
            end = mp(end.F - dx[p], end.S - dy[p]);
        }
        rev(steps);
        cout << steps.size() << endl;
        for (ll c : steps) {
            cout << stepDir[c];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
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

