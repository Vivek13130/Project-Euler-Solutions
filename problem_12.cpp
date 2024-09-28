#include <bits/stdc++.h>
using namespace std;

inline long long get_triangle_number(long long n ){
      return (n * (n + 1) / 2);
}

inline int count_divisors(long long n){
      int count = 0 ;

      for(long long i = 1 ; i * i <= n; i++){
            if(n % i == 0){
                  count += 2;
            }
      }

      long long i = sqrt(n);
      if(i * i == n) count--; // since it will be counted twice above;

      return count;
}

int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      int i = 1;
      while(count_divisors(get_triangle_number(i)) < 500){
            i++;
      }

      cout << get_triangle_number(i) << endl;

      return 0;
}