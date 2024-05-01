#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> t;

//Memoize
/*int ks(vector<int> val, vector<int> wt, int w, int n){
    if(n<0 || w==0)
        return 0;
    if(t[n][w]!=-1){
        return t[n][w];
    }
    else if(wt[n]<=w){
        return t[n][w] = max(ks(val, wt, w-wt[n], n-1)+val[n], ks(val, wt, w, n-1));    
    } else {
        return t[n][w] = ks(val, wt, w, n-1);
    }
}*/

//Top Down Approach
int ks(vector<int> val, vector<int> wt, int w){
    int n = val.size();
    vector<vector<int>> t(n+1, vector<int>(w+1, 0));
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<w+1;j++){
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
            } else {
                t[i][j] = t[i-1][j]; 
            }    
        }
    }
    return t[n][w];
}

int main()
{
    vector<int> val = {5, 20, 2, 7, 20};
    vector<int> wt = {1, 3, 1, 3, 5};
    int w = 10;
    t.assign(val.size(), vector<int>(w+1, -1));
    cout<<ks(val, wt, w);//, val.size()-1);
}
