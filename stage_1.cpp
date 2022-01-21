#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

#define length 60 
#define text_data 200 

string username;

int show_data(){
      char ch;

    ifstream file(username + "_deepak_property.txt",ios::in);
   cout << "\n//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;     
   

    string un,pw;

   getline(file,un);
   getline(file,pw);

    while(!file.eof()){
        file.get(ch);
        cout << ch;
    } 
    file.close();
    cout << "\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;  
}

int enter_data()
{     char data[1000];
    cout<<"\nEnter the data you want to enter ...   : ";
        ofstream file;
        file.open(username+"_deepak_property.txt");
        gotoline(file,3);
        cin.getline(data,1000,'.');
        file << data;

        file.close();

        cout<<"\n Data has been saved successfully...";

    return 0;
}


int exist(string){
    
    ifstream fname(username + "_deepak_property.txt",ios::in);

    if(fname){
        fname.close();
        return 1;
    }
   return 0;
}

bool IsloggedIN()
{
    string password, un, pw;
    namer :
    cout<< "Enter username :";
    cin>>username;
    //gets(username,83,'.');
    if(!exist(username)){
        cout<<" username does'nt exist.. "<< endl << endl ;
        cout<<"renter user name "<<endl<<endl;
        goto namer;
    }
    cout<< "Enter password:"; cin >> password;
     ifstream read;
    read.open(username + "_deepak_property.txt",ios::app | ios::out);
    getline(read, un);  // This reads a single line from the text file which generally contains the username only
    getline(read, pw);  // this reads a next line from the text file which contains generally the password of the user

    if(un == username && pw == password)
    {
        return true;
    }
    else{
        return false;
    }

}

int main(){

int choice;

cycle: 

cout<<"   MENU\n1: Register\n2: Login\n3. Exit \nYour choice :"; cin>>choice;

if(choice == 1)
{    rename :
    string password;
    cout<<"select a username: "; cin>>username;
    cout<<endl;
    label:
    cout<<"select a password: "; cin>>password;
    cout<<endl;
    
    

    if(exist(username))
    {
        cout<<"\nThis user name already exists try with another name " << endl <<endl;

        goto rename;
    }


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

    file.open(username + "_deepak_property.txt");
 
    file << username << endl <<password;

    file.close();

    cout<<"\nUser registered successfully..."<< endl;
    cout<<"\nNow you can try to log in.... "<< endl << endl;

    main();

}

else if (choice == 2)
{   menu :
    bool status = IsloggedIN();

    if (!status)
    {
        cout<<"False login! "<< endl;
        system("PAUSE");

        cout<<"Try again with correct credentials "<< endl << endl;
        goto menu;
        return 0;
    }

    else 
    {   // int opt;
        cout << "Logged in successfully..." << endl<<endl;
        int num;
        sub_loc :
        cout<<"   Sub-Menu\n1.Show data\n2.Enter data\n3.Logout"<<endl;
        cout<<"Enter your option :";
        cin>>num;

        if(num == 1){
            
            cout<<"\nredirecting you to the data..."<<endl;
            show_data();


        }
        else if(num == 2){
            
          enter_data();
          goto sub_loc;

        }
        else if(num == 3){
            cout<<"logging you out ..."<<endl<<endl;
            system("pause");
            cout<<"logged out successfully.."<<endl;
            goto cycle;
        }
        else{
            cout<<"You have entered wrong input try again ..."<<endl;
            goto sub_loc;
        }
        return 1;
    }
}

else if(choice == 3)
{
}

return 0;
}