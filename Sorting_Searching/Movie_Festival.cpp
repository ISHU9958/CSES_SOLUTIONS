#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define flush cout << flush;

/* -----------------------------------------integer ranges----------------------------------*/
#define imax INT_MAX
#define imin INT_MIN
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define mod (int)(1e9 + 7)
#define ll long long
#define int ll
#define pb push_back

// data structures methods
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define Sort(arr) sort(arr.begin(), arr.end())
#define Dsort(arr) sort(arr.begin(), arr.end(), greater<int>())
#define rev(arr) reverse(arr.begin(), arr.end())
#define all(cont) cont.begin(), cont.end()
#define Sum(v, initial_sum) accumulate(v.begin(), v.end(), initial_sum)

// data structures
#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define vv(a) vector<vector<a>>
#define ump(a, b) unordered_map<a, b>
#define omp(a, b) map<a, b>
#define ust(a) unordered_set<a>
#define ost(a) set<a>
#define maxheap(a) priority_queue<a>
#define minheap(a) priority_queue<a, vector<a>, greater<a>>

// take inputs and debug
#define debug(i) cout << i << endl;
#define input(arr)                       \
    for (int i = 0; i < arr.size(); i++) \
        cin >> arr[i];
#define print(arr)                       \
    for (auto &it:arr) \
        cout << it << " ";
#define nline cout << endl
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

/*-------------------some specific functions---------------*/
class PascalTriangle {
private:
    vector<vector<ll>> pascal;
    int row, col;
    ll MOD;

public:
    PascalTriangle(int maxN, int maxR, int Mod) {
        row = maxN;
        col = maxR;
        MOD = Mod;
        pascal.resize(maxN + 1, vector<ll>(maxR + 1, 0));
        create();
    }

    void create() {
        pascal[0][0] = 1;
        for (int n = 1; n <= row; n++) {
            pascal[n][0] = 1;
            for (int r = 1; r <= col; r++) {
                pascal[n][r] = (pascal[n - 1][r - 1] + pascal[n - 1][r]) % MOD;
            }
        }
    }

    vector<vector<ll>> getPascal() {
        return pascal;
    }
};

#define iseven(n) ((n % 2) == 0)
#define isodd(n) ((n % 2) != 0)
#define LCM(a, b) ((a / (__gcd(a, b))) * b)

ll exp(int a, int b) { if (b == 0) { return 1;}if (b == 1) return a;ll res = exp(a, b / 2);if (b & 1)return res * res * a;return res * res;}

ll expMod(ll a, ll b, ll Mod) {ll res = 1;while (b > 0) {if (b & 1) res = (res * a) % Mod;a = ((a % Mod) * (a % Mod)) % Mod;b = b >> 1;}return res;}

ll MMI(ll b, ll m) { return expMod(b, m - 2, m); }
ll mod_add(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m) { return ((a % m) * (MMI(b, m) % m)) % m; }
ll nCr(ll n, ll r, ll m, vector<ll> &fact) { ll num = fact[n];ll deno = fact[r] * fact[n - r];return mod_div(num, deno, m);}

/*------------------------ main code-----------------------*/
void testcases(int testcase) {
    int n;
    cin>>n;
    v(p(int,int))arr(n);
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        arr[i]={x,y};
    }

    sort(all(arr),[&](p(int,int)&a,p(int,int)&b){
        if(a.ss!=b.ss) return a.ss<b.ss;
        return a.ff<b.ff;
    });


    int end=imin;
    int ct=0;

    for(int i=0;i<n;i++){
        int l=arr[i].ff,r=arr[i].ss;

        if(end<=l){
            ct++;
            end=r;
        }
    }

    cout<<ct<<endl;

}

signed main() {
    fastio();
    testcases(0);
    return 0;
}