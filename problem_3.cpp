// //  finding largest prime factor of a number

// #include <bits/stdc++.h>
// using namespace std;
// #include<chrono>

// bool isprime(int num ){
//       if (num == 2) return true;
//       if(num  == 1 || num % 2 == 0)return false;

//       for(int i = 2 ; i <= sqrt(num) ; ++i){
//             if(num % i == 0) return false;
//       }
//       return true;
// }

// int nextPrime(int num){
//       num++;
//       while(!isprime(num)) num++;
//       return num;
// }


// int main(){
//       // ios::sync_with_stdio(0);
//       // cin.tie(0);
//       // cout.tie(0);

//       long long n ; 
//       cout << "enter your number : ";
//       cin >> n;

//       // Start measuring time
//       auto start = std::chrono::high_resolution_clock::now();
      
//       // Your code here , add 
//       long long maxi = 0LL;
//       long long curr_prime = 2;
//       while(n != 1){
//             if(n % curr_prime == 0) maxi = curr_prime;
//             while(n % curr_prime == 0) n /= curr_prime;
//             curr_prime = nextPrime(curr_prime);
//       }

//       cout<<"ans -> "<< maxi << endl;
      
//       // Stop measuring time and calculate the elapsed time
//       auto end = std::chrono::high_resolution_clock::now();
//       auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
      
//       // Output the elapsed time
//       std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

//       return 0;
// }














// optimized method : 
#include <bits/stdc++.h>
using namespace std;

int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      long long n ; cin >> n;
      long long n1 = sqrt(n);
      long long maxi = 0 ;

      if(n % 2 == 0) maxi = 2;
      while(n % 2 == 0) n /= 2;

      for(int i = 3;  i  <= n1 ; i += 2){
            while(n % i == 0){
                  n /= i;
                  maxi = i;
            }
      }

      cout<<max(maxi, n)<<endl;

      return 0;
}