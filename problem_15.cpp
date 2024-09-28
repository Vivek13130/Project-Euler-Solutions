#include <bits/stdc++.h>
using namespace std;

long long solve(long long ci , long long cj , vector<vector<long long>>& dp ){
      // base cases : 
      if(ci < 0 || cj < 0) return 0;
      if(dp[ci][cj] != -1) return dp[ci][cj];
      if(ci == 0 && cj == 0) return 1;

      // calls ;
      // either go up 
      long long paths_up = solve(ci -1 , cj , dp);

      // or go left 
      long long paths_left = solve(ci , cj - 1 , dp);

      return dp[ci][cj] = paths_left + paths_up;
}

int main(){

      cout << " enter grid size " ;
      long long n ; cin >> n;

      vector<vector<long long>>dp(n + 1 , vector<long long>(n + 1 , -1));
      solve( n , n , dp);

      cout << dp[n][n] << endl;

      return 0;
}