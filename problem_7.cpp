// finding nth prime number 

#include <bits/stdc++.h>
#include <chrono>
using namespace std;

inline bool is_prime(int& num){
      if(num == 1) return false;
      if(num == 2) return true;
      if(num % 2 == 0) return false;

      for(int i = 2 ; i <= sqrt(num) ; i++){
            if(num % i  == 0) return false;
      }
      return true;
}

int next_prime(int num){
      num++;
      while(! is_prime(num)){
            num++;
      }
      return num;
}


int main(){
      // ios::sync_with_stdio(0);
      // cin.tie(0);
      // cout.tie(0);


      int n ; 
      cout << "enter n : ";
      cin >> n;

      // Start measuring time
      auto start = chrono::high_resolution_clock::now();

      int count = 0 ; 
      int ans = 1;
      while (count < n)
      {
            ans = next_prime(ans);
            count++;
      }

      cout << " ans -> " <<  ans << endl;
      
      // Stop measuring time and calculate the elapsed time
      auto end = chrono::high_resolution_clock::now();
      auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
      
    // Output the elapsed time
      cout << "Time taken: " << duration.count() << " milliseconds" << endl;

      return 0;
}