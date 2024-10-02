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
void mergeTwoArrays(int low, int high, int mid,int arr[], vector<int> &freq, vector<pair<int,int>> &vp){
    vector<pair<int, int>> tempVp;
    int left = low;
    int right = mid + 1;

    while(left<=mid && right<=high){
        if(vp[left].second > vp[right].second){
            freq[vp[left].first]+=high-right+1;
            tempVp.push_back(vp[left]);
            left++;
        } else {
            // freq[vp[right].first]++;
            tempVp.push_back(vp[right]);
            right++;
        }
    }

    while(left<=mid){
            tempVp.push_back(vp[left]);
            left++;
    } 

    while(right<=high){
            tempVp.push_back(vp[right]);
            right++;
    }

    for (int i = low; i <= high; i++) {
        vp[i] = tempVp[i - low];
    }

}

void mergeSort(int low, int high, int arr[], vector<int> &freq, vector<pair<int,int>> &vp)
{
    if(low==high){
        // vector<int> v;
        // v.push_back(arr[low]);
        return;
        // return arr[low];
    }
    int mid = (low + high) >> 1;
    mergeSort(low, mid, arr,freq,vp);
    mergeSort(mid + 1, high, arr,freq,vp);
    mergeTwoArrays(low,high,mid, arr,freq,vp);
    for (int i = 0; i < freq.size();i++){
        cout << freq[i] << "  ";
    }
    cout << endl;
    // return answer;
}

void solve(int arr[], int len){
    pair<int, int> p;
    vector<pair<int, int>> vp;
    for (int i = 0; i < len; i++)
    {
        vp.push_back(make_pair(i, arr[i]));
    }
    vector<int> freq(len, 0);
    mergeSort(0, len - 1, arr,freq,vp);
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
    int n;
    cin >> n;
    int arr[n+1];
    for (int i = 0;i<n;i++){ 
        cin >> arr[i];
    }
    solve(arr,n);
}

// PROBLEM LINK - https://codeforces.com/problemset/problem/339/D q