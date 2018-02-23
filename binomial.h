#ifndef  BINOMIAL_H
#define  BINOMIAL_H

struct Price
{
   double stockp, callp,putp;
};

class Binomial
{
   public:
      Binomial();
      double strike,startp,sigma,r,time;
      int Num;        //number of time intervals
      char type;      //'A' means American option, 'E' means European option
      void setspace(); 
      void showprice();
      void calprice();
   private:
      Price *node;
      double ht,up,down,p;
      void calpara();
      void calculate();
      void calculate1(int);
      void initialprice();
};

#endif
