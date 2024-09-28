#include <bits/stdc++.h>
using namespace std;

inline string string_multiply_with_digit(string& s , int digit){
      string ans = "";
      int carry = 0 ;
      for(int i = s.length()-1 ; i >= 0 ; i--){
            int prod = (s[i] - '0') * digit + carry;
            carry = prod / 10;
            prod = prod % 10;

            ans = to_string(prod) + ans;
      }

      if(carry != 0){
            ans = to_string(carry) + ans;
      }

      return ans;
}

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


string multiply_string_with_num(string s , int num){
      string ans = "";
      string interm_prod = "";
      int step = 0;

      while(num){
            int digit = num % 10;
            num = num / 10;
            
            interm_prod = string_multiply_with_digit(s , digit);
            for(int i = 1; i <= step ; i++) interm_prod += "0";

            ans = string_summation(ans , interm_prod);
            step++;
      }

      return ans;
}

string calc_factorial(int n){
      string ans = to_string(n);

      while(--n){
            ans = multiply_string_with_num(ans,  n);
      }

      return ans;
}

int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      int n; cin >> n; 
      string ans = calc_factorial(n);

      cout<<endl << ans << endl << endl;

      int sum = 0 ;
      for(char c : ans){
            sum += (c - '0');
      }

      cout << sum << endl;

      return 0;
}