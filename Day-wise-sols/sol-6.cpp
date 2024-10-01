using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#define INT_min -999999
#define ll long long int
#define MAXSIZE 200
#define ff first
#define ss second

#ifndef ONLINE_JUDGE
#define debug(x)        \
    cerr << #x << "  "; \
    _print(x);          \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(char n)
{
    cerr << n;
}
void _print(int n) { cerr << n; }
void _print(bool n) { cerr << n; }
void _print(string n) { cerr << n; }
void _print(long long int n) { cerr << n; }
void _print(double n) { cerr << n; }

int MOD = 1e9 + 7;

ll add(ll x, ll y)
{
    ll res = x + y;
    return (res >= MOD ? res - MOD : res);
}
ll mul(ll x, ll y)
{
    ll res = x * y;
    return (res >= MOD ? res % MOD : res);
}
ll sub(ll x, ll y)
{
    ll res = x - y;
    return (res < 0 ? res + MOD : res);
}

// TO CALC MODULAR INVERSE (c=MOD)
ll modRecc(ll a, ll b, ll c)
{
    // TC->O(log(b))
    // SC->O(log(b))->recursion stack
    if (b == 0)
    {
        return 1;
    }
    if (b % 2 == 0)
    {
        ll temp = modRecc(a, b / 2, c);
        return ((temp % c) * (temp % c)) % c;
    }
    else
    {
        ll temp = modRecc(a, b / 2, c);
        return ((a % c) * (temp % c) * (temp % c)) % c;
    }
}
// BOTH ABOVE AND BELOW ARE SAME BUT DIFF METHOD
ll modIter(ll a, ll b, ll c)
{
    // TC->O(log(b))
    // SC->O(1) MORE OPTIMIZED
    ll ans = 1;
    while (b != 0)
    {
        if (b & 1)
        {
            ans = ((ans % c) * (a % c)) % c;
        }
        a = ((a % c) * (a % c)) % c;
        b = b >> 1;
    }
    return ans;
}

// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        cerr << "(";
        _print(i.ff);
        cerr << ",";
        _print(i.ss);
        cerr << ")";
        cerr << " ";
    }
    cerr << "]";
}

const int N = 1e7 + 7;
vector<int> prime(N);

// or use inbuilt __gcd() function
int gcd(int n, int m)
{
    if (n % m == 0 && n >= m)
        return m;
    else
        return gcd(m, n % m);
}

int prime_till[N];

void seive()
{
    for (int i = 2; i < N; i++)
    {
        if (prime[i] == 0)
        {
            int j = 2;
            while (i * j <= N)
            {
                prime[i * j] = 1;
                j++;
            }
        }
    }
}

void prime_t()
{
    for (int i = 2; i < N; i++)
    {
        if (prime[i] == 0)
        {
            prime_till[i] = prime_till[i - 1] + 1;
        }
        else
        {
            prime_till[i] = prime_till[i - 1];
        }
    }
}

void no()
{
    cout << "-1"
         << "\n";
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
long long int sumOfSq(vector<int> v){
    long long int res=0;
    for (int i = 0; i < v.size();i++){
        res += (v[i] * v[i]);
    }
    return res;
}

long long int sumOfArrEle(vector<int> v){
    long long int res=0;
    for (int i = 0; i < v.size();i++){
        res += (v[i]);
    }
    return res;
}

void solve()
{
    //petr and comb locks - codeforces
    int n;
    cin>>n;

    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
// 0 -> anticlockwise
// 1 -> clockwise
    string isZero = "NO";
    for (int i = 0; i < (1 << n); i++)
    {
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            if(i&(1<<j)){
                ans += a[j];
            }else{
                ans -= a[j];
            }
        }
        
        if(ans==0 || (abs(ans)%360==0)){
            isZero = "YES";
        }
    }
    cout << isZero;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output_.txt", "w", stdout);
#endif

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    // cin>>t;
    // prime_till[1]=0;
    // seive();
    // prime_t();
    t = 1;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}
