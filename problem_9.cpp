// # find pyth triplet such that a + b + c = 1000
#include <bits/stdc++.h>
using namespace std;


int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      int b , c;
      bool flag = true;

      for(int i = 1 ; i <= 1000 && flag; ++i){ // b
            for(int j = 1 ; j <= 1000 && flag ; ++j){ // c
                  int val = int(1e6) + (2*i*i) + (2*i*j) - (2000 * (i + j));
                  if (val == 0){
                        b = i ;
                        c = j ;
                        cout<<(1000 - (b + c))<<" "<<b<<" "<<c<<endl;
                  }
            }
      }

      cout<<(1000 - (b + c))<<" "<<b<<" "<<c<<endl;
      cout << (1000 - (b + c)) * b * c << endl;

      return 0;
}