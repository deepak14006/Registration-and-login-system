
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

#define length 60
#define text_data 83

string username;


int main(){

int choice;

cycle:

cout<<"\t\t\t\t\t   MENU\n\t\t\t\t\t1: Register\n\t\t\t\t\t2: Login\n\t\t\t\t\t3. Exit \n\n\t\t\tYour choice :"; cin>>choice;

if(choice == 1)
{    rename :
    string password;
    cout<<"\t\t\t\t\tselect a username: "; cin>>username;
    cout<<endl;
    label:
    

    cout<<"\t\t\t\t\tselect a password: "; cin>>password;
    cout<<endl;


    int size=0;

    int i=0;

    while(password[i] != '\0')
    { size++; i++; }

    if(size < 8)
    {
        cout<<"Renter the password (minimum  8 char) " <<endl;
        goto label;
    }

    ofstream file;

    file.open(username + "_doc.dat", ios::binary | ios::out);
     char space = ' ';
   //file << username << endl <<password<< endl <<"";
   file.write((char *) &username, sizeof(username));
    file.write((char *) &space, sizeof(space));
    file.write((char *) &password, sizeof(password));
    
    file.close();

    cout<<"\n\t\t\t\t\t ******** User registered successfully... ******** "<< endl;
    cout<<"\n\t\t\t\t\t######### Now you can try to log in.... #########"<< endl << endl;

    main();

}

return 0;
}

/*
 #include<iostream>
#include<fstream>
using namespace std;
struct Student {
   int roll_no;
   string name;
};
int main() {
   ofstream wf("student.dat", ios::out | ios::binary);
   if(!wf) {
      cout << "Cannot open file!" << endl;
      return 1;
   }
   Student wstu[3];
   wstu[0].roll_no = 1;
   wstu[0].name = "Ram";
   wstu[1].roll_no = 2;
   wstu[1].name = "Shyam";
   wstu[2].roll_no = 3;
   wstu[2].name = "Madhu";
   for(int i = 0; i < 3; i++)
      wf.write((char *) &wstu[i], sizeof(Student));
   wf.close();
   if(!wf.good()) {
      cout << "Error occurred at writing time!" << endl;
      return 1;
   }
   ifstream rf("student.dat", ios::out | ios::binary);
   if(!rf) {
      cout << "Cannot open file!" << endl;
      return 1;
   }
   Student rstu[3];
   for(int i = 0; i < 3; i++)
      rf.read((char *) &rstu[i], sizeof(Student));
   rf.close();
   if(!rf.good()) {
      cout << "Error occurred at reading time!" << endl;
      return 1;
   }
   cout<<"Student's Details:"<<endl;
   for(int i=0; i < 3; i++) {
      cout << "Roll No: " << wstu[i].roll_no << endl;
      cout << "Name: " << wstu[i].name << endl;
      cout << endl;
   }
   return 0;
}

*/