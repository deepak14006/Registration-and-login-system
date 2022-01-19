#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
//char ch[100];
string ch;
cout<<"\nEnter the name of the condidat :";
//cin.getline(ch,83,'\n');
// we can either use the upper getline() or lower gets() functions to store the complete string
gets(ch);
cout<<"\nThe name is :"<<ch;


return 0;
}