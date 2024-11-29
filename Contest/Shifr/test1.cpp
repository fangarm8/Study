
 
#include <stdio.h>
#include <string.h>
 
int main(int argc,char** argv)
{
   char  pszAscii [256];
   char  pszPhrase[256];
 
   memset(pszAscii,0,sizeof(pszAscii));
 
   printf("vvedite slovo: ");
 
   fflush(stdin);
   scanf("%s",pszPhrase);
 
   int   iUnic = 0;
 
   int   iLen = strlen(pszPhrase);
 
   for (int ii = 0; ii < iLen; ++ii)
   {
      ++pszAscii[(unsigned char)pszPhrase[ii]];
   }
 
   for (int jj = 0; jj < sizeof(pszAscii); ++jj)
   {
      if (pszAscii[jj])
      {
         ++iUnic;
      }
   }
 
   printf("%d\n",iUnic);
 
   return 0;
}