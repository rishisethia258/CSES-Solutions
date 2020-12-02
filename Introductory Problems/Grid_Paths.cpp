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
#define fi         first
#define se         second
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
const ll n    =    7;
bool v[n][n];
vll res(49);
ll ans = 0, steps = 0;

void move(ll r, ll c)
{
    if (r == n - 1 && c == 0)
    {
        ans += (steps == n * n - 1);
        return;
    }

    bool t = (((r + 1 == n || (v[r - 1][c] && v[r + 1][c])) && c - 1 >= 0 && c + 1 < n && !v[r][c - 1] && !v[r][c + 1]) ||
              ((c + 1 == n || (v[r][c - 1] && v[r][c + 1])) && r - 1 >= 0 && r + 1 < n && !v[r - 1][c] && !v[r + 1][c]) ||
              ((r == 0 || (v[r + 1][c] && v[r - 1][c])) && c - 1 >= 0 && c + 1 < n && !v[r][c - 1] && !v[r][c + 1]) ||
              ((c == 0 || (v[r][c + 1] && v[r][c - 1])) && r - 1 >= 0 && r + 1 < n && !v[r - 1][c] && !v[r + 1][c]));

    if(t) return;

    v[r][c] = true;

    if (res[steps] != -1)
    {
        switch (res[steps])
        {
        case 0:
            if (r - 1 >= 0)
            {
                if (!v[r - 1][c])
                {
                    steps++;
                    move(r - 1, c);
                    steps--;
                }
            }
            break;

        case 1:
            if (c + 1 < n)
            {
                if (!v[r][c + 1])
                {
                    steps++;
                    move(r, c + 1);
                    steps--;
                }
            }
            break;

        case 2:
            if (r + 1 < n)
            {
                if (!v[r + 1][c])
                {
                    steps++;
                    move(r + 1, c);
                    steps--;
                }
            }
            break;

        case 3:
            if (c - 1 >= 0)
            {
                if (!v[r][c - 1])
                {
                    steps++;
                    move(r, c - 1);
                    steps--;
                }
            }
            break;
        }
        v[r][c] = false;
        return;
    }
    if (r + 1 < n)
    {
        if (!v[r + 1][c])
        {
            steps++;
            move(r + 1, c);
            steps--;
        }
    }
    if (c + 1 < n)
    {
        if (!v[r][c + 1])
        {
            steps++;
            move(r, c + 1);
            steps--;
        }
    }
    if (r - 1 >= 0)
    {
        if (!v[r - 1][c])
        {
            steps++;
            move(r - 1, c);
            steps--;
        }
    }
    if (c - 1 >= 0)
    {
        if (!v[r][c - 1])
        {
            steps++;
            move(r, c - 1);
            steps--;
        }
    }
    v[r][c] = false;
}

void solve() {
    string path;
    cin >> path;
    for (ll i = 0; i < (ll)path.size(); i++)
    {
        if (path[i] == '?')
            res[i] = -1;
        else if (path[i] == 'U')
            res[i] = 0;
        else if (path[i] == 'R')
            res[i] = 1;
        else if (path[i] == 'D')
            res[i] = 2;
        else if (path[i] == 'L')
            res[i] = 3;
    }
    ans = 0; steps = 0;
    move(0, 0);
    cout << ans;
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