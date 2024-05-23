#include<iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;
int main()
{
    int hrs,min,sec,hrs1,min1,sec1;
    cout<<"Enter the hour\n";
    cin>>hrs;
     cout<<"Enter the minuets\n";
     cin>>min;
      cout<<"Enter the Second\n";
      cin>>sec;
      cout<<"SET YOUR ALARM IN TIME FORMAT OF HH:MM:SS \n\n";
      cin>>hrs1>>min1>>sec1;

if(hrs<24&&min<60&&sec<60){
      while(1)//while(true)
     {
         system("cls");//ths will clear the existing screen data
    if(sec>59)
      {  min++;
         sec=0;
        }
     if(min>59)
      {
        hrs++;
        min=0;
      }
    if(hrs>23)
        hrs=0;
    {
    cout<<hrs<<":"<<min<<":"<<sec<<" ";
    sec++;
    if(hrs>12){
        cout<<"AM";
    }
    else
        cout<<"PM";
    if(hrs==hrs1&&min==min1&&sec==sec1)
        cout<<"\a\a\a\a\a\a\a\a\a\a";
    Sleep(1000);
    }}}
    else
        cout<<"Please insert the correct time range \n";
    return 0;
}
