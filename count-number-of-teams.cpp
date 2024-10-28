using namespace std;
#include <iostream>
#include <bits/stdc++.h>

// Approach used - Thought process is that since n is 10^3 means it should be solve in 
// N^2 or NlogN or N^2logN complexity. So for this I have used time complexity of N^2
// and it is still better than lot of other submissions.
// What I did is I looped on all the values and while looping, at certain index 'i' I thought
// of making two arrays - one on the right side of index i and other on left side of index i.
// so eventually array will be splitted like - 
// [12,5,3,9,7,1,6,13,10,17]
//           ^               -> suppose I am at value 7. 
// [12,5,3,9]   7   [1,6,13,10,17]
//  left arr  indx    right arr

// do a second loop on left and right array and make a count of all the values greater and smaller 
// than rating[i] i.e 7 in this case.

// [   12    , 5,3,    9       ]
//    llow=0        lhigh=i-1


// rating[i] - 7


//[    1    ,  6,13,10,    17    ]
//  rlow=i+1            rhigh=n-1   n is size of arr.

// cnt+=(llessThan*rgreaterThan)+(lgreaterThan*rlessThan); will give the count of all the pairs
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt=0;
        for( int i=0;i<rating.size();i++){
            int val = rating[i];
            int llow = 0;
            int lhigh = i-1;
            int rlow = i+1;
            int rhigh = rating.size()-1;
            int llessThan=0;
            int lgreaterThan=0;
            int rlessThan=0;
            int rgreaterThan=0;
            if(lhigh>=0){
                for(int j=llow;j<=lhigh;j++){
                    if(rating[j]<val){
                        llessThan++;
                    }
                    if(rating[j]>val){
                        lgreaterThan++;
                    }
                }
            }
            if(rlow<=rating.size()-1) {          
                for(int k=rlow;k<=rhigh;k++){
                    if(rating[k]<val){
                        rlessThan++;
                    }
                    if(rating[k]>val){
                        rgreaterThan++;
                    }
                }
            }

            cnt+=(llessThan*rgreaterThan)+(lgreaterThan*rlessThan);
        }
        return cnt;
    }
};