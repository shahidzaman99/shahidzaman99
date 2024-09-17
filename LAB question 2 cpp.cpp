#include <iostream>
using namespace std;
int main()
{
int size;
cout<<"enter the size of array :"<<endl;
cin>>size;
int* arr1= new int[size];
cout<<"first arr :"<<endl;
for(int i=0;i<size;i++)
{
cout<<"enter the first arr value :"<<i+1<<"elements :";
cin>> arr1[i];
}
int* arr2= new int[size];
cout<<"second arr :"<<endl;
for(int i=0;i<size;i++)
{
cout<<"enter the second arr value :"<<i+1<<"elements :";
cin>> arr2[i];
}
int* arr3= new int[size];
cout<<"thrid arr :"<<endl;
for(int i=0;i<size;i++)
{
cout<<"enter the theid arr value :"<<i+1<<"elements :";
cin>> arr3[i];
}
int* array= new int[size];
for(int i=0;i<size;i++)
{
array[i] = arr1[i] + arr2[i] + arr3[i];
}
cout <<" after adding final array of all three arrays is :"<<endl;
for(int i=0;i<size;i++)
{
cout<<array[i];
}
return 0;
}
