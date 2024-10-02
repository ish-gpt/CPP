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


void update(int indx, int low, int high, int i, int val, int seg[]){
    if(low==high){
        seg[indx] += val;
        return;
    }
    int mid = (low + high) >> 1;
    if(i<=mid) {
    update(2 * indx + 1, low, mid, i, val, seg);
    } else {
    update(2 * indx + 2, mid+1, high, i, val, seg);
    }
    seg[indx] = seg[indx * 2 + 1] + seg[indx * 2 + 2];
}

int query(int indx, int low, int high, int l, int r, int seg[]){
    // info emptyAns;
    if (r < low || high < l)
        return 0;
    if(low>=l && high<=r)
        return seg[indx];
    int mid = (low + high) >> 1;
    int left = query(2 * indx + 1, low, mid,l,r, seg);
    int right = query(2 * indx + 2, mid+1, high, l,r, seg);
    return left + right;
}

void build(int indx, int low, int high, int arr[], int seg[])  
{
    if(high==low){
        seg[indx] = arr[low];
        return;
    }
    int mid = (low + high) >> 1;
    build(2 * indx + 1, low, mid, arr, seg);
    build(2 * indx + 2, mid+1, high, arr, seg);
    seg[indx] = seg[indx * 2 + 1] + seg[indx * 2 + 2];
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
    cin >> t;
    while(t--){
            int n;
            cin >> n;
            int arr[n];
            int mx = -1;
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
                // cout << arr[i] << " ";
                mx = max(mx, arr[i]);
        }
        mx += 1;
        int freq[mx];
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
        }
        int seg[4 * mx];
        build(0, 0, mx - 1, freq, seg);

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]--;
            update(0, 0, mx - 1, arr[i], -1, seg);
            cnt += query(0, 0, mx - 1, 0, arr[i]-1,seg);
        }
        cout << cnt<<endl;
    }
}

// PROBLEM LINK - https://www.spoj.com/problems/INVCNT/