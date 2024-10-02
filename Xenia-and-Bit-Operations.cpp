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

void no()
{
    cout << "-1"
         << "\n";
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

void update(int indx,int low, int high, int i, int val, int seg[], int orr){
    if(low==high){
        seg[indx] = val;
        return;
    }
    int mid = (low + high) >> 1;
    if (i <= mid)
        update(2 * indx + 1, low, mid, i, val, seg, !orr);
    else update(2 * indx + 2, mid+1, high, i, val, seg, !orr);
    if(orr)
        seg[indx] = seg[2 * indx + 1] | seg[2 * indx + 2];
    else     
        seg[indx] = seg[2 * indx + 1] ^ seg[2 * indx + 2];
}

void build(int indx, int low, int high, int arr[], int seg[], int orr)
{
    if(low==high){
        seg[indx] = arr[low];
        return;
    }
    int mid = (low + high) >> 1;
    build(2 * indx + 1, low, mid, arr, seg, !orr);
    build(2 * indx + 2, mid + 1, high, arr, seg, !orr);
    if(orr)
        seg[indx] = seg[2 * indx + 1] | seg[2 * indx + 2];
    else     
        seg[indx] = seg[2 * indx + 1] ^ seg[2 * indx + 2];
}

void solve(int n, int arr[], int segsize,int m, int indx, int val) {
    int seg[segsize*4];
    int p,b;
    if (n % 2 == 0) build(0, 0, segsize - 1, arr, seg, 0);
        else build(0, 0, segsize - 1, arr, seg, 1);
    while (m--)
    {
        cin >> p >> b;
        p--;
        if (n % 2 == 0)
            update(0, 0, segsize - 1, p, b, seg, 0);
        else
            update(0, 0, segsize - 1, p, b, seg, 1);
        cout << seg[0] << endl;
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
    int n,m,p,b;
    cin >> n >> m;
    int poww = pow(2, n);
    int arr[poww];
    for (int i = 0;i<poww;i++){ 
        cin >> arr[i];
    }
    solve(n, arr, poww,m, p,b);
}


// PROBLEM LINK - https://codeforces.com/problemset/problem/339/D 