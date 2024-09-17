#include <iostream>
using namespace std;
int main()
{
int a;
int b;
int *ptrA;
int *ptrB;
cout<<"enter the value of a :"<<endl;
cin>>a;
cout<<"enter the value of b :"<<endl;
cin>>b;
ptrA=&a;
ptrB=&b;
cout<<"enter the value of a :"<< *ptrA<<endl;
cout<<"enter the value of a :"<<*ptrB<<endl;
return 0;
}
