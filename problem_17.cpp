#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> mp;

void insert_values_in_map()
{
      mp[1] = "one";
      mp[2] = "two";
      mp[3] = "three";
      mp[4] = "four";
      mp[5] = "five";
      mp[6] = "six";
      mp[7] = "seven";
      mp[8] = "eight";
      mp[9] = "nine";

      mp[10] = "ten";
      mp[11] = "eleven";
      mp[12] = "twelve";
      mp[13] = "thirteen";
      mp[14] = "fourteen";
      mp[15] = "fifteen";
      mp[16] = "sixteen";
      mp[17] = "seventeen";
      mp[18] = "eighteen";
      mp[19] = "nineteen";

      mp[20] = "twenty";
      mp[30] = "thirty";
      mp[40] = "forty";
      mp[50] = "fifty";
      mp[60] = "sixty";
      mp[70] = "seventy";
      mp[80] = "eighty";
      mp[90] = "ninety";
      mp[100] = "hundred";
      mp[1000] = "thousand";
}

inline string get_english_name(int num)
{
      string ans = "";
      int step = 0;
      int num1 = -1;
      if(num > 9) num1 = num % 100 ;
      if(num1 < 9 || num1 > 19) num1 = -1;

      if(num1 != -1){
            step++;
            num /= 10;
      }

      while (num)
      {
            int dig = num % 10;
            num /= 10;

            if (step == 2)
            {
                  int firstdig = dig ;
                  if(ans.length() == 0){
                        ans = mp[100] ;
                  }
                  else{
                        ans = mp[100] + "and" + ans;
                  }
                  ans = mp[firstdig] + ans;
            }
            else if(step == 1 && num1 != -1){
                  ans = mp[num1] + ans;
            }
            else
            {
                  dig = dig * pow(10, step);
                  ans = mp[dig] + ans;
            }

            step++;
      }

      return ans;
}

int main()
{
      insert_values_in_map();
      int ans = 0;

      for (int i = 1; i < 1000; i++)
      {
            string s = get_english_name(i);
            ans += s.length();
      }

      string finalstr = "onethousand";
      ans += finalstr.length();

      cout << ans << endl;

      return 0;
}