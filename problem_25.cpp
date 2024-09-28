#include <bits/stdc++.h>
using namespace std;

inline string string_summation(string s1 , string s2){
      string ans = "";
      int s1j = s1.length()-1;
      int s2j = s2.length() - 1;

      int carry = 0;

      while(s1j >= 0 && s2j >= 0){
            int sum = (s1[s1j] - '0' ) + (s2[s2j] - '0') + carry;

            carry = sum / 10;
            sum %= 10;
            ans = to_string(sum) + ans;

            s1j--;
            s2j--;
      }

      while(s1j >= 0){
            int sum = (s1[s1j] - '0' ) + carry;
            carry = sum / 10;
            sum %= 10;
            ans = to_string(sum) + ans;
            s1j--;
      }
      while(s2j >= 0){
            int sum = (s2[s2j] - '0' ) + carry;
            carry = sum / 10;
            sum %= 10;
            ans = to_string(sum) + ans;
            s2j--;
      }
      if(carry != 0) ans = to_string(carry) + ans;

      return ans;
}

int main(){
      cout << "how many digits you want in fib number ? " ;
      int n ; cin >> n;

      string a = "1";
      string b = "1";
      string temp = "2";
      string count = "3";

      auto start = std::chrono::high_resolution_clock::now();

      while((int)temp.length() != n){
            a = b;
            b = temp; 
            temp = string_summation(a, b) ;
            count = string_summation(count , "1");
      }

      auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
      
      std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

      cout << "index of that number : "<<count << endl;
      return 0;
}