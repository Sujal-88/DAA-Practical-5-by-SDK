#include <iostream>
#include <vector>
#include <string> 
#include <algorithm> 
using namespace std;


int findLrs(const string& s, int i, int j, vector<vector<int>>& dp){

    if(i == s.length() || j == s.length()){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int result;

    if(s[i] == s[j] && i!=j){
        
        result = 1 + findLrs(s, i + 1, j + 1, dp);
    }else{
        
        int excluding_i = findLrs(s, i + 1, j, dp);
        int excluding_j = findLrs(s, i, j + 1, dp);
        result = max(excluding_i, excluding_j);
    }
    
    
    return dp[i][j] = result;
}


int getLRSans(const string &s1){
    int n = s1.length();
    
    vector<vector<int>> dp(n, vector<int>(n, -1)); 
    return findLrs(s1, 0, 0, dp);
}

int main(){
    string s1 = "ABASDAEFWEAFADGHHSDRJHD";
    
    int ans = getLRSans(s1); 
    cout << ans << endl; 
    return 0;
}