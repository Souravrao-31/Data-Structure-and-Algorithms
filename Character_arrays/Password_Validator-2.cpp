#include <iostream>
using namespace std;

bool printStrongNess(string& input) {
   int n = input.length();
   // Checking lower alphabet in string

    if(input[0]=='@'  || input[0]=='#' || input[0]=='$' || input[0]=='%' || input[0]=='&' || input[0]=='?' ){
	    return false;
      }

   bool hasLower = false, hasUpper = false;
   bool hasDigit = false, specialChar = false;
   string normalChars = "abcdefghijklmnopqrstu" "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
   for (int i = 0; i < n; i++) {
      if (islower(input[i]))
         hasLower = true;
      if (isupper(input[i]))
         hasUpper = true;
      if (isdigit(input[i]))
         hasDigit = true;
      size_t special = input.find_first_not_of(normalChars);
      if (special != string::npos)
         specialChar = true;
   }
   // Strength of password
  
   if (hasLower && hasUpper && hasDigit &&
      specialChar && (n >= 10))
       return true;
   else
      return false;
}
int main() {

  int t;cin>>t;

     while(t--){
         string s;
         cin>>s;

         if(printStrongNess(s)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
         
     } 



   return 0;
}