#include"binomial.h"
#include<iostream>

//this is a program pricing American/European option without dividend

using namespace std;
int main()
{
  Binomial option;
  option.Num=200;
  option.time=6.0/252;
  option.strike=160;
  option.r=0.04;
  option.sigma=0.25;
  option.type='A';
  option.setspace();
  
  double p;
  for(p=155;p<=160;p+=2.5)
   { 
     option.startp=p;
     option.calprice();
     option.showprice();
   }
 
   return 0;
}
