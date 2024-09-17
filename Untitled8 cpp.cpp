#include<iostream>
#include<cmath>
using namespace std;
void menu(){
cout<<"additions"<<endl;
cout<<endl;
cout<<"subtraction"<<endl;
cout<<endl;
cout<<"multiplaction"<<endl;
cout<<endl;
cout<<"power"<<endl;
cout<<endl;
cout<<"division"<<endl;
cout<<endl;
}
int Additions(int a,int b){
return a+b;
}
int subtraction (int a,int b){
return a-b;
}
int multiplication (int a,int b){
return a*b;
}
int power(int num ,int pow)
{
return pow ==0 ? 1:num* power(num ,pow-1);
}
int division (int a,int b){
if(b !=0)
return a/b;
else
cout<<"cannot be divided by 0"<<endl;
return 0;
}
int main()
{
int choice;
int a;
int b;
menu();
cout<<"enter choose option "<<endl;
cin>>choice;
cout<<"enter the value of a"<<endl;
cin>>a;
cout<<"enter the value of b"<<endl;
cin>>b;
switch(choice){
case 1:
cout<<"result:"<<Additions(a,b)<<endl;
break;
case 2:
cout<<"result of subtraction"<<subtraction(a,b)<<endl;
break;
case 3:
cout<<"result of multiplication"<<multiplication(a,b)<<endl;
case 4:
cout<<"result of division"<<division<<endl;
case 5:
cout<<"result of power:"<<power<<endl;
break;
}
}
