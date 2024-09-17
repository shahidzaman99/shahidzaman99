#include <iostream>
using namespace std;
int main()
{
int largest;
int smallest;
int array[10];
cout<<"enter the value of array :"<<endl;
for(int i=0;i<10;i++)
{
cin>>array[i];
}
for(int i=0;i<10;i++)
{
if(array[i]>largest)
{
largest=array[i];
}
if(array[i]<smallest)
{
smallest=array[i];
}
}
cout<<"the largest value of this array is :"<< largest<<endl;
cout<<"the smallest value of this array is :"<< smallest<<endl;
return 0;
}
