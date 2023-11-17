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

void mergeArr(vector<int> &arr, int r, int l, int mid){
    int subArr1 = mid - l + 1;
    int subArr2 = r - mid;

    // vector<int> subVec1;
    // vector<int> subVec2;

    // int indexOfMergedArr = 0;
    // int indexOfSubbArr1 = 0;
    // int indexOfSubbArr2 = 0;

    // for (int i = 0; i < subArr1;i++){
    //     subVec1.push_back(arr[l + i]);
    // }

    // for (int i = 0; i < subArr2;i++){
    //     subVec2.push_back(arr[mid + 1 + i]);
    // }



    // while(indexOfSubbArr1<subArr1 && indexOfSubbArr2<subArr2){
    //     if(subVec1[indexOfSubbArr1]<=subVec2[indexOfSubbArr2]){
    //         arr[indexOfMergedArr] = subVec1[indexOfSubbArr1];
    //         indexOfSubbArr1++;
    //     }
    //     else
    //     {
    //         arr[indexOfMergedArr] = subVec2[indexOfSubbArr2];
    //         indexOfSubbArr2++;
    //     }
    //     indexOfMergedArr++;
    // }

    // while(indexOfSubbArr1<subArr1){
    //     arr[indexOfMergedArr] = subVec1[indexOfSubbArr1];
    //     indexOfMergedArr++;
    //     indexOfSubbArr1++;
    // }

    //  while(indexOfSubbArr2<subArr2){
    //     arr[indexOfMergedArr] = subVec2[indexOfSubbArr2];
    //     indexOfMergedArr++;
    //     indexOfSubbArr2++;
    // }

    vector<int> temp;
    int leftArrStart = l;
    int rightArrStart = mid+1;
// cout << mid << "   " << r << "  " << l <<"\n";
    while(leftArrStart<=mid && rightArrStart<=r ){
        
        if (arr[leftArrStart] <= arr[rightArrStart])
        {
            temp.push_back(arr[leftArrStart]);
            leftArrStart++;
        }
        else
        {
            temp.push_back(arr[rightArrStart]);
            rightArrStart++;
        }
    }

    while(leftArrStart<=mid){
        temp.push_back(arr[leftArrStart]);
            leftArrStart++;
    }

    while(rightArrStart<=r){
        temp.push_back(arr[rightArrStart]);
            rightArrStart++;
    }

// for (int i = s; i <= e; ++i)
// 		v[i] = temp[i - s];
    for (int i = l; i <= r ;i++){
            arr[i] = temp[i - l];
    }
}

void sortArr(int l, int r, vector<int> &arr){
    // cout << "Hello\n";
    if(l>=r){
        return;
    }
    int mid = (r+l)/ 2;
    sortArr(l, mid, arr);
    sortArr(mid + 1, r,arr);
    mergeArr(arr, r, l, mid);
    // for (int i = 0; i < arr.size();i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
}

void solve()
{
    //petr and comb locks - codeforces
    // int n;
    // cin>>n;

    vector<int> a = {41,1,21,3,34,52,11,10,56,23,0,43,66};
    sortArr(0, a.size() - 1, a);

    for (int i = 0; i < a.size();i++){
        cout << a[i] << " ";
    }
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
