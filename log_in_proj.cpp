#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

#define length 60
#define text_data 83

string username;


int enter_data(){
     fstream F;
    // opening a file in input and output mode
    F.open(username+"_deepak_property.txt",ios::app);

   F.seekp(83,ios::beg);
   F.seekp(83,ios::beg);

   string info;
   cout<<"\nEnter the data : ";
   cin.ignore();  // this most important because previously when the data wa
    getline(cin,info); //s stored  the curser remains into that file which causes breaking in input.
    F<<info<<endl;
    
    F.close();
     cout<<"\nData has been entered successfully......"<<endl;
    return 0;
}

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
    cout<< "\n\t\t\t\t\tEnter username :";
    cin>>username;
    //gets(username,83,'.');
    if(!exist(username)){
        cout<<" \t\t\t <<<<<<<<<  username does'nt exist..  >>>>>>>>>>"<< endl << endl ;
        cout<<"\t\t\t  ^^^^^^^^^^   Renter user name  ^^^^^^^^^^"<<endl<<endl;
        goto namer;
    }
    cout<< "\n\t\t\t\t\tEnter password:"; cin >> password;
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

cout<<"\t\t\t\t\t   MENU\n\t\t\t\t\t1: Register\n\t\t\t\t\t2: Login\n\t\t\t\t\t3. Exit \n\n\t\t\tYour choice :"; cin>>choice;

if(choice == 1)
{    rename :
    string password;
    cout<<"\t\t\t\t\tselect a username: "; cin>>username;
    cout<<endl;
    label:
    cout<<"\t\t\t\t\tselect a password: "; cin>>password;
    cout<<endl;



    if(exist(username))
    {
        cout<<"\n\t\t\t ***** This user name already exists try with another name *****" << endl <<endl;

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

    file << username << endl <<password<< endl <<"";

    file.close();

    cout<<"\n\t\t\t\t\t ******** User registered successfully... ******** "<< endl;
    cout<<"\n\t\t\t\t\t######### Now you can try to log in.... #########"<< endl << endl;

    main();

}

else if (choice == 2)
{   menu :
    bool status = IsloggedIN();

    if (!status)
    {
        cout<<"\n\t\t\t\t___________________________   False login!   ___________________________ "<< endl <<endl;
        cout<<"\t\t\t"<<system("PAUSE");

        cout<<"\n\t\t\t\t\t***Try again with correct credentials*** "<< endl << endl;
        goto menu;
        return 0;
    }

    else
    {   // int opt;
        cout << "\n\t\t\t------------------  Logged in successfully...  ------------------" << endl<<endl;
         cout<<"\n\n==============================================================================================================================================" << endl;
   
    
        int num;
        sub_loc :
        cout<<"\n\n\t\t\t\t\tSub-Menu\n\t\t\t\t\t1.Show data\n\t\t\t\t\t2.Enter data\n\t\t\t\t\t3.Logout"<<endl;
        cout<<"\n\t\t\t\t\tEnter your option :";
        cin >> num;

        if(num == 1){

            cout<<"\nredirecting you to the data..."<<endl;
            system("PAUSE");
             cout<<"\n";
             show_data();
            goto sub_loc;


        }
        else if(num == 2){

            enter_data();

            goto sub_loc ;
        }
        else if(num == 3){
            cout<<"logging you out ..."<<endl<<endl;
            system("PAUSE");
            cout<<"logged out successfully.."<<endl;
                cout<<"\n\n==============================================================================================================================================" << endl;
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
