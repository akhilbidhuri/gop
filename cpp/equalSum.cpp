//Equal sum subsets Dp
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> t;

//Memoize
bool subsum(vector<int> arr, int sum, int n){
    if(n<0 && sum!=0)
        return 0;
    if(sum == 0)
        return 1;
    if(t[n][sum]!=-1){
        return t[n][sum];
    }
    else if(arr[n]<=sum){
        return (t[n][sum] = subsum(arr, sum-arr[n], n-1)||subsum(arr, sum, n-1));    
    } else {
        return (t[n][sum] = subsum(arr, sum, n-1));
    }
}

//Top Down Approach
bool subsum(vector<int> arr,  int sum){
    int n = arr.size();
    vector<vector<bool>> t(n+1, vector<bool>(sum+1, false));
    for(int i = 0;i<n+1;i++){
        t[i][0] = true;    
    }
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            } else {
                t[i][j] = t[i-1][j]; 
            }    
        }
    }
    return t[n][sum];
}

bool equalSum(vector<int> arr) {
    int sum = 0;
    for(int a : arr) {
        sum += a;    
    }
    if(sum==0)
        return true;
    if(sum%2!=0) {
        return false;
    } else {
        return subsum(arr, sum/2);    
    }
}

int main()
{
    vector<int> arr = {4, 4, 8, 5, 3};
    //t.assign(arr.size(), vector<int>(sum+1, -1));
    cout<<equalSum(arr);
}
