#include <bits/stdc++.h>
using namespace std;

int sum_divisors(int n ){

      int sum = 0 ; 

      for(int i = 1 ; i <= sqrt(n); i++){
            if(n % i == 0){
                  sum += i ;
                  if(i * i != n && i != 1) sum += (n/i); // 2nd factor in pair 
            }
      }

      return sum; 
}

pair<int,int> find_pair(int a ){
      int sumofdiv_a  = sum_divisors(a);
      int b = sumofdiv_a;
      int sumofdiv_b = sum_divisors(b);

      if(sumofdiv_b == a){
            // valid pairs : 
            return {a , b};
      }
      else{
            return {-1, -1};
      }

}

int main(){
      // ios::sync_with_stdio(0);
      // cin.tie(0);
      // cout.tie(0);

      int n ;
      cout << "enter value of n : " ; cin >> n ;

      vector<bool>used(n , false);
      int sum = 0 ;

      for(int i = 1 ; i <= n ; i++){
            if(used[i]) continue;
            pair<int,int>pair = find_pair(i);

            if(pair.first != pair.second && pair.second > 0 ) {
                  cout << " a pair : "<<pair.first << "  -  "<<pair.second << endl;

                  // a valid pair : 
                  sum += pair.first ; 
                  used[pair.first] = true;

                  if(pair.second <= n){
                        sum += pair.second; 
                        used[pair.second] = true;
                  } 
                  
            }
      }

      cout << sum << endl;

      return 0;
}