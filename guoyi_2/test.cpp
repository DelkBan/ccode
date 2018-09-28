#include <stdio.h>
  int main(int argc, char *argv[])
  {
      int x,y,z;
      int xyz,zyx;//7进制数和9进制数对应的十进制数 
      for(x=1;x<7;x++)
      {
          for(y=0;y<7;y++)
          {
             for(z=1;z<7;z++)
             {
                 xyz=x*7*7+y*7+z;
                 zyx=z*9*9+y*9+x;
                 if(xyz==zyx)
                 {
                     printf("%d\n%d%d%d\n%d%d%d\n",xyz,x,y,z,z,y,x);
                 }
             }
         }
     }
     return 0;
 }
