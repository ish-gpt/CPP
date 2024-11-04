using namespace std;
#include <iostream>
#include <bits/stdc++.h>

class ST{
    public: 
        vector<int> seg;
        vector<int> lazy;
        ST(int n){
            seg.resize(4 * n);
            lazy.resize(4 * n);
        }

        void build(int indx, int low, int high, int arr[]){
            if(low==high){
                seg[indx] = arr[low];
                return;
            }
            int mid = (low + high) >> 1;
            build(2 * indx + 1, low, mid, arr);
            build(2 * indx + 2, mid + 1, high, arr);
            seg[indx] = seg[2 * indx + 1] + seg[2 * indx + 2];
        }

        void update(int indx, int l, int r,int low, int high, int val){
            // update previous pending nodes if any.
            if(lazy[indx]!=0){
                seg[indx] += (high - low + 1) * lazy[indx];
                if(low!=high){
                    lazy[2 * indx + 1] = lazy[indx];
                    lazy[2 * indx + 2] = lazy[indx];
                }
                lazy[indx] = 0;
            }
            // complete overlap
            if(low>=l && high<=r){
                seg[indx] += (high-low+1)*val;
                if(high!=low){
                    lazy[2 * indx + 1] += val;
                    lazy[2 * indx + 2] += val;
                }
                return;
            }

            //no overlap
            if(high<l || r<low){
                return;
            }

            // partial overlap
            int mid = (low + high) >> 1;
            update(2 * indx + 1, l, r, low, mid, val);
            update(2*indx+2,l,r,mid+1,high,val);
            seg[indx] = seg[2 * indx + 1] + seg[2 * indx + 2];
        }

        int query(int indx, int l, int r, int low, int high){
            if(lazy[indx]!=0){
                seg[indx] += (high - low + 1) * lazy[indx];
                if(low!=high){
                    lazy[2 * indx + 1] = lazy[indx];
                    lazy[2 * indx + 2] = lazy[indx];
                }
                lazy[indx] = 0;
            }

            //complete overlap
            if(low>=l && high<=r){
                
                return seg[indx];
            }

            //no overlap
            if(high<l || r<low){
                return 0;
            }

            // partial overlap
            int mid = (low + high) >> 1;
            int left = query(2 * indx + 1, l, r, low, mid);
            int right = query(2*indx+2,l,r,mid+1,high);
            return left + right;
        }
};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output_.txt", "w", stdout);
#endif

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, arr[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    ST st(n);
    st.build(0, 0, n - 1, arr);
    while (q--)
    {
        int typ;
        int l, r, val;
        cin >> typ;
        if(typ==1) {
            cin >> l >> r >> val;
            st.update(0, l, r, 0, n - 1, val);
        }
        else {
            cin >> l >> r;
            cout<<st.query(0,l,r,0,n-1);
        }
    }
}