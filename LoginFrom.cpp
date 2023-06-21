#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

void login();
void registration();
void forgot();
int main()
{
    int ch;
    cout<<"\t------------------------------------------------------------------------------------------------\n\n\n";
    cout<<"\t\t\t                                          Welcome                                               \n\n";
    cout<<"\t------------------------------------------------------------------------------------------------\n\n\n";
    cout<<"\t\t\t                                            Menu                                                \n\n";
    cout<<"|Press 1 for login:                   |"<<endl;
    cout<<"|Press 2 for Registration:            |"<<endl;
    cout<<"|Press 3 if you forgot password :     |"<<endl;
    cout<<"|Press 4 for exist                    |"<<endl;
    cout<<"\n\n";
    cout<<"Enter the choice:";
    cin>>ch;
    switch(ch)
    {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"                                         Thank YOU                                           "<<endl;
            break;
        default:
            cout<<"Please enter the valid choice"<<endl;
            main();
    }
    return 0;
}
void login()
{
    int count;
    string userid,password,id,pass;
    cout<<"\t\tEnter the UserName:";
    cin>>userid;
    cout<<"\t\tEnter the Password:";
    cin>>password;
    ifstream input("records.txt");
    while(input>>id>>pass)
    {
        if(id==userid && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {
        cout<<userid<<" "<<"Sucessfully login"<<endl;
        main();
    }
    else
    {
        cout<<"\t Loign Error | Please Recheck the username and password"<<endl;
        main();
    }
}
void registration()
{
    string ruserid,rpassword,ru,rp;
    system("cls");
    cout<<"Enter the UserName:";
    cin>>ruserid;
    cout<<"Enter the password:";
    cin>>rpassword;
    ofstream f1("records.txt", ios::app);
    f1<<ruserid<<' '<<rpassword<<endl;;
    system("cls");
    cout<<"Registration is Successfull"<<endl;
    main();
}
void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t            You forgot Password ! No worries  \n";
    cout<<"Press 1 to search your id by username  "<<endl;
    cout<<"Press 2 t go back to Menu"<<endl;
    cout<<"Enter the Choice:";
    cin>>option;
    switch(option)
    {
        case 1:
        {
            int n;
            string suserid,sid,spass;
            cout<<"Enter the UserName:";
            cin>>suserid;
            ifstream f2("records.txt");
            while(f2>>sid>>spass)
            {
                if(sid==suserid)
                {
                    n=1;
                }
            }
            if(n==1)
            {
                cout<<"Your Password is:"<<spass<<endl;
                main();
            }
            else{
                cout<<"Your Account Not found | Recheck the UserName"<<endl;
                main();
            }
            break;
        }
        case 2:
        {
            main();
        }
        default:
        {
            cout<<"Wrong choice ! Please try again"<<endl;
            forgot();
        }
    }
}