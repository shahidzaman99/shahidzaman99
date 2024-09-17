#include <iostream>
using namespace std;
int main()
{
int var;
cout<<"enter the value of variable :"<<endl;
cin>>var;
int *pvar=&var;
cout<<" the value of variable :"<< var <<endl;
cout<<"value of address variable :"<< pvar<<endl;
cout<<"value of pointer variable :"<<*pvar<<endl;
return 0;
}
