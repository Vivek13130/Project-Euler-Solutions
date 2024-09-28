#include <bits/stdc++.h>
using namespace std;

inline string string_multiply(string& s , int num){
      string ans = "";
      int carry = 0 ;

      for(int i = s.length()-1 ; i >= 0 ; i--){
            int prod = (s[i] - '0') * num + carry;
            carry = prod / 10;
            prod = prod % 10;

            ans = to_string(prod) + ans;
      }

      if(carry != 0){
            ans = to_string(carry) + ans;
      }

      return ans;
}

int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      string s = "1";
      int num = 2;

      for(int i = 1 ; i <= 1000 ; i++){
            s = string_multiply(s , num);
      }

      int ans = 0 ;
      for(char c : s){
            ans += (c - '0');
      }

      cout << s << endl;
      cout << s.length()<<endl;
      cout << ans << endl;

      return 0;
}