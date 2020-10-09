#include <bits/stdc++.h>
using namespace std;

void solve(char *ch, int i)
{

   if (ch[i] == '\0' || ch[i + 1] == '\0')
   {
      return;
   }

   if (ch[i] == ch[i + 1])
   {
      int j = i + 1;
      while (ch[j] != '\0')
      {
         ch[j - 1] = ch[j];
         j++;
      }
      ch[j - 1] = '\0';
      solve(ch, i);
   }else{
    solve(ch, i + 1);
   }
   return;
}

// void solve(char *ch, int i)
// {

//    if (ch[i] == '\0' or ch[i + 1] == '\0')
//    {
//       return;
//    }

//    //Check current and next char
//    if (ch[i] == ch[i + 1])
//    {

//       int j = i + 2;

//       while (ch[j] != '\0')
//       {
//          j++;
//       }

//       while (j >= i + 1)
//       {
//          //Move characters to the right
//          ch[j + 1] = ch[j];
//          j--;
//       }
//       //Put * in i+1 ith position
//       ch[j + 1] = '*';
//       solve(ch, i + 2);
//    }
//    else
//    {
//       solve(ch, i + 1);
//    }
//    return;
// }

int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   char ch[10000];
   cin.getline(ch, 10000);
   solve(ch, 0);
   for (int i = 0; ch[i] != '\0'; i++)
   {
      cout << ch[i];
   }
   return 0;
}