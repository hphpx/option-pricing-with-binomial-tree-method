#include"binomial.h"
#include<cmath>
#include<algorithm>
#include<iostream>
#include<iomanip>

using namespace std;

Binomial::Binomial(){}

void Binomial::setspace()
{ 
   node=new Price[Num+1]; 
  
}

void Binomial::calpara()
{
    ht=time/Num;
    double a=exp(r*ht);
    up=exp(sigma*sqrt(ht));
    down=1/up;
    p=(a-down)/(up-down);
};

void Binomial::initialprice()
{
    double temp=up*up, factor=pow(up,Num);
    int i;
    for(i=0;i<=Num;i++)
      { 
         node[i].stockp=startp*factor;
         node[i].callp=max(0.0,node[i].stockp-strike);
         node[i].putp=max(0.0,strike-node[i].stockp);
         factor/=temp;
      }
 
}

void Binomial::calculate1(int end)
{
    double ac,ap,c=1-p;
    double x=exp(-r*ht);
    int i;
    for(i=0;i<=end;i++)  node[i].stockp/=up;
    
    if(type=='E')
     {
        for(i=0;i<=end;i++)
          {  
             ac=p*node[i].callp+c*node[i+1].callp;
             ap=p*node[i].putp+c*node[i+1].putp;
             ac*=x; ap*=x;
             
             node[i].callp=ac;
             node[i].putp=ap;
          }
     }

   else {
         for(i=0;i<=end;i++)
          {  
             ac=p*node[i].callp+c*node[i+1].callp;
             ap=p*node[i].putp+c*node[i+1].putp;
             ac*=x; ap*=x;
             
             node[i].callp=max(node[i].stockp-strike,ac);
             node[i].putp=max(strike-node[i].stockp,ap);
          }
        }
 }

void Binomial::calculate()
{
   int i;
   for(i=Num-1;i>=0;i--)
     calculate1(i);
}

void Binomial::showprice()
{
   cout<<setw(8)<<startp<<" "<<setw(8)<<node[0].callp<<" "<<setw(8)<<node[0].putp<<endl;
}

void Binomial::calprice()
{
     calpara();  
     initialprice();  
     calculate(); 
}
