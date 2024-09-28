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
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      vector<string> vec(100);
      for(int i = 0 ;  i < 100 ; i ++){
            cin >> vec[i];
      }

      string sum = vec[0];

      for(int i = 1 ; i <  100 ; i++){
            sum = string_summation(sum , vec[i]);
      }

      cout << sum << endl;

      return 0;
}