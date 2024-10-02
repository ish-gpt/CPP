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

struct info {
    int open, close, full;
    info() {
        open = 0;
        close = 0;
        full = 0;
    }
    info(int _open, int _close, int _full) {
        open = _open;
        close = _close;
        full = _full;
    }
};



info merge(info &left, info &right) {
    info mergedAns;
    mergedAns.full = left.full + right.full + min(left.open,right.close);
    mergedAns.open = left.open + right.open - min(left.open, right.close);
    mergedAns.close = left.close + right.close - min(left.open, right.close);
    return mergedAns;
}


info query(int indx, int low, int high, int l, int r, info seg[]){
    info emptyAns;
    if (r < low || high < l)
        return emptyAns;
    if(low>=l && high<=r)
        return seg[indx];
    int mid = (low + high) / 2;
    info left = query(2 * indx + 1, low, mid,l,r, seg);
    info right = query(2 * indx + 2, mid+1, high, l,r, seg);
    return merge(left, right);
}

void build(int indx, int low, int high,string &s, info seg[])  // If not passing string as a reference than codeforces is giving TLE.
{
    if(high==low){
        if(s[high]=='(') seg[indx] = info(1, 0, 0);
        else seg[indx] = info(0, 1, 0);
        return;
    }
    int mid = (low + high) >> 1;
    build(2 * indx + 1, low, mid, s, seg);
    build(2 * indx + 2, mid+1, high, s, seg);
    seg[indx] = merge(seg[2*indx+1],seg[2*indx+2]);
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
    string s;
    cin >> s;
    int n = s.size();
    info seg[n * 4];
    build(0, 0, n - 1,s, seg);
    // cout<<seg[0].full;
    // cout<<seg[0].open;
    // cout<<seg[0].close;
    int m;
    cin >> m;
    int l, r;
    while (m--)
    {
        cin >> l >> r;
        l--, r--;
        info ans = query(0, 0, n - 1, l, r, seg);
        cout << query(0, 0, n - 1, l, r, seg).full * 2 << endl;
    }
}

// PROBLEM LINK - https://codeforces.com/problemset/problem/380/C