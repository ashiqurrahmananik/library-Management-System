#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int com,l,temp,te,t=0,f,k=0,p,day,month,year,day1,month1,year1,fi,gi,v,go=0,in=0,li[100];
string ch;
ofstream outl;

class book
{
protected:
    int id_book[1000],number_of_books[1000],d;
    string book_name[1000],author_name[1000];
public:
    void updatebook()
    {
        ofstream outfile;
        outfile.open("input00.dat",ios::app);
        outl.open("input5.dat");
        cout<<"How Many Book You Want To Entry:"<<endl;
        cin>>d;
        for(int i=1; i<=d; i++)
        {
            cout<<"Enter book id number: ";
            cin>>id_book[i];
            cin.ignore();
            outfile<<id_book[i]<<endl;
            cout<<"Enter Books name: ";
            cin>>book_name[i];
            cin.ignore();
            outfile<<book_name[i]<<endl;
            cout<<"Enter author name of the book: ";
            cin>>author_name[i];
            cin.ignore();
            outfile<<author_name[i]<<endl;
            cout<<"Enter Number of books: ";
            cin>>number_of_books[i];
            cin.ignore();
            if(go==1 && l==i)
            {
                number_of_books[i]--;
            }
            outfile<<number_of_books[i]<<endl;

        }
        outfile.close();
        outl.close();
    }
    void showbook()
    {
        ifstream infile,inl;
        infile.open("input00.dat",ios::app);
        cout<<"\n"<<"                          "<<"*******Book List*******"<<endl<<endl;
        cout<<"How Many Book You Want To See:"<<endl;
        cin>>d;
        for(int i=1; i<=d; i++)
        {
            cout<<"Book id number : ";
            infile >>id_book[i] ;
            cout << id_book[i] << endl<<endl ;
            cout<<"Books name     : ";
            infile >>book_name[i];
            cout << book_name[i]<< endl<<endl ;
            cout<<"Author name    : ";
            infile >> author_name[i];
            cout << author_name[i]<< endl<<endl ;
            cout<<"Number of books: ";
            infile >> number_of_books[i] ;
            inl.open("input5.dat");
            inl>>l;
            //inl>>go;
            if(go==1 && l==i)
            {
                number_of_books[i]--;
            }
            cout << number_of_books[i] << endl<<endl<<endl<<endl  ;

        }
        inl.close();
        infile.close();
    }

    void issue()
    {
        int l,k,n;
        int flag=0,i=1;
        outl.open("input5.dat");
        cout<<"Enter Book ID:";
        cin>>l;
        go=1;
        outl<<l<<endl;
        //outl<<go<<endl;

        cout<<"Enter Student ID:";
        cin>>k;
        cout<<"Enter Issue Day / Month /Year:";
        cin>>day>>month>>year;
        ifstream infile;
        infile.open("input00.dat",ios::app);
        while(flag!=1)
        {
            if(i==l)
            {

                cout<<"Previous Number Of Books: "<<number_of_books[i]<<endl;
                number_of_books[i]--;
                temp = number_of_books[i];
                te = i;
                cout<<"Current Number Of Books: "<<number_of_books[i]<<endl;
                flag=1;
            }
            i++;
        }
        outl.close();
        infile.close();




        ofstream outfile;
        outfile.open("input00.dat",ios::app);
        for (int i=1; i<=te; i++)
        {
            if(i==te)
            {
                number_of_books[i]=temp;
                cout<<"Current Number Of Books: "<<number_of_books[i]<<endl<<endl;
                cout<<"**********Book Issue Complete For 7 days*********"<<endl;
                outfile<<number_of_books[i]<<endl;
            }
        }
        outfile.close();


    }
    void book_back()
    {
        go=0;
        in=1;
        cout<<"Enter Book ID:";
        cin>>p;
        cout<<"Enter Student ID:";
        cin>>v;
        cout<<"Book back  Day / Month /Year:";
        cin>>day1>>month1>>year1;
        ifstream infile;
        infile.open("input00.dat",ios::app);
        number_of_books[p]++;
        cout<<"Current Number Of Books: "<<number_of_books[p]<<endl<<endl<<endl;
        infile.close();
        fi=day1-day;
        if(fi>7)
        {
            cout<<"He/She Is Backing Book After 7 Days.Fine is 25 Tk Per Day";
            gi=fi-7;
            cout<<"Now fine is:"<<gi*25<<endl;
        }
        else
            cout<<"Now fine is: 0";

    }
    void search_book()
    {
        cout<<"Enter Book id:";
        cin>>f;
        while(1)
        {
            t++;
            if(f==t)
            {
                cout<<"Book id number : ";
                cout << id_book[t] << endl<<endl ;
                cout<<"Books name     : ";
                cout << book_name[t]<< endl<<endl ;
                cout<<"Author name    : ";
                cout << author_name[t]<< endl<<endl ;
                cout<<"Number of books: ";
                cout << number_of_books[t] << endl<<endl<<endl<<endl  ;
                break;
            }
        }
    }
    void search_book_name()
    {
        cout<<"Enter Book Name:";
        cin>>ch;
        while(1)
        {
            k++;
            if(ch==book_name[k])
            {
                cout<<"Book id number : ";
                cout << id_book[k] << endl<<endl ;
                cout<<"Books name     : ";
                cout << book_name[k]<< endl<<endl ;
                cout<<"Author name    : ";
                cout << author_name[k]<< endl<<endl ;
                cout<<"Number of books: ";
                cout << number_of_books[k] << endl<<endl<<endl<<endl  ;
                break;
            }
        }
    }

};
class student:public book
{


protected:
    int id_student[100],student_number[100],p,q;
    string student_name[100],student_email[100];
public:
    void updatestudent()
    {
        ofstream outfile;
        outfile.open("input2.dat",ios::app);
        cout<<"How Many Student Details You Want To Entry:"<<endl;
        cin>>p;
        for(int j=1; j<=p; j++)
        {
            cout<<"Enter Student id : ";
            cin>>id_student[j];
            cin.ignore();
            outfile<<id_student[j]<<endl;
            cout<<"Enter Student name: ";
            cin>>student_name[j];
            outfile<<student_name[j]<<endl;
            cout<<"Enter Student Phone Number: ";
            cin>>student_number[j];
            outfile<<student_number[j]<<endl;
            cout<<"Enter Student Email Address: ";
            cin>>student_email[j];
            outfile<<student_email[j]<<endl;
        }
        outfile.close();
    }
    void showstudent()
    {
        ifstream infile;
        infile.open("input2.dat",ios::app);
        cout<<"                      "<<"Student Details"<<endl;
        cout<<"How Many Student Details You Want To See:"<<endl;
        cin>>q;
        for(int j=1; j<=q; j++)
        {
            cout<<"Student id : ";
            infile >>id_student[j] ;
            cout << id_student[j] << endl ;
            infile >> student_name[j];
            cout<<"Student name: ";
            cout <<student_name[j]<< endl ;
            infile >> student_number[j] ;
            cout<<"Student Phone Number: ";
            cout << student_number[j] << endl ;
            infile >> student_email[j];
            cout<<"Student Email Address: ";
            cout << student_email[j]<< endl ;
        }
        infile.close();
    }

};
class employee:public book
{

protected:
    int id,c,g;
    string data,data1;
public:
    void updateemployee()
    {
        ofstream outfile;
        outfile.open("input3.dat",ios::app);
        cout<<"Enter Employee id : ";
        cin>>id;
        cin.ignore();
        outfile<<id<<endl;
        cout<<"Enter Employee name: ";
        getline(cin,data);
        outfile<<data<<endl;
        cout<<"Enter Employee Phone Number: ";
        getline(cin,data1);
        outfile<<data1<<endl;
        cout<<"Enter Employee Email Address: ";
        cin>>c;
        outfile<<c<<endl;
        outfile.close();
    }
    void showemployee()
    {
        ifstream infile;
        infile.open("input3u.dat");
        cout<<"                      "<<"Employee Details"<<endl;
        infile >>id ;
        cout<<"Employee id : ";
        cout << id << endl ;
        infile >> data ;
        cout<<"Employee name: ";
        cout << data << endl ;
        infile >> data1 ;
        cout<<"Employee Phone Number: ";
        cout << data1 << endl ;
        infile >> c ;
        cout<<"Employee Email Address: ";
        cout << c << endl ;
        infile.close();
    }

};
int main()
{
    int n,pass,x,f,j,l,k,day,month,year,ok,h,a1;
    book b1;
    student s1;
    employee e1;
    system("Color 1A");
    cout<<"\n\n\n\n\n\n\n\n\n\n"<<"                     "<<"WELCOME TO LIBRARY MANAGEMENT SYSTEM";
    Sleep(1000);
    system("cls");

    while(1)
    {
        cout<<"                         "<<"library Management System"<<endl;
        cout<<endl;
        cout<<"*********MAIN MENU*********"<<endl;
        cout<<endl;
        cout<<"1.Admin"<<endl;
        cout<<endl;
        cout<<"2.Student"<<endl;
        cout<<endl;
        cout<<"3.Employee"<<endl;
        cout<<endl;
        cout<<"4.Exit"<<endl;
        cin>>x;
        if(x==1)
        {
            while(1)
            {
                if(n==13)
                {
                    n=0;
                    break;
                }
                cout<<"Enter Password:";
                cin>>pass;
                if(pass==123)
                {
                    while(1)
                    {
                        system("cls");
                        cout<<"                         "<<"library Management System"<<endl;
                        cout<<"*********ADMIN MAIN MENU*********"<<endl<<endl;
                        cout<<"Press 1 for update book details"<<endl<<endl;
                        cout<<"Press 2 for show book details"<<endl<<endl;
                        cout<<"Press 3 for update student details"<<endl<<endl;
                        cout<<"Press 4 for show student details"<<endl<<endl;
                        cout<<"Press 5 for update employee details"<<endl<<endl;
                        cout<<"Press 6 for show employee details"<<endl<<endl;
                        cout<<"Press 7 for Book Issue for student"<<endl<<endl;
                        cout<<"Press 8 for Book Back for employee"<<endl<<endl;
                        cout<<"Press 9 for Book Issue for employee"<<endl<<endl;
                        cout<<"Press 10 for Book Back for student"<<endl<<endl;
                        cout<<"Press 11 for Book Search With Id"<<endl<<endl;
                        cout<<"Press 12 for Book Search With Name"<<endl<<endl;
                        cout<<"Press 13 log out"<<endl;
                        cin>>n;
                        if(n==1)
                        {
                            system("cls");
                            cout<<"                         "<<"library Management System"<<endl;
                            b1.updatebook();
                            cout<<"                     "<<"Press 1 If You Want ADMIN MAIN MENU again"<<endl;
                            cin>>a1;
                        }
                        else if(n==2)
                        {
                            system("cls");
                            cout<<"                         "<<"library Management System"<<endl;
                            b1.showbook();
                            cout<<"                     "<<"Press 1 If You Want ADMIN MAIN MENU again"<<endl;
                            cin>>a1;
                        }
                        else if(n==3)
                        {
                            system("cls");
                            cout<<"                         "<<"library Management System"<<endl;
                            s1.updatestudent();
                            cout<<"                     "<<"Press 1 If You Want ADMIN MAIN MENU again"<<endl;
                            cin>>a1;
                        }
                        else if(n==4)
                        {
                            system("cls");
                            cout<<"                         "<<"library Management System"<<endl;
                            s1.showstudent();
                            cout<<"                     "<<"Press 1 If You Want ADMIN MAIN MENU again"<<endl;
                            cin>>a1;
                        }
                        else if(n==5)
                        {
                            system("cls");
                            cout<<"                         "<<"library Management System"<<endl;
                            e1.updateemployee();
                            cout<<"                     "<<"Press 1 If You Want ADMIN MAIN MENU again"<<endl;
                            cin>>a1;
                        }
                        else if(n==6)
                        {
                            system("cls");
                            cout<<"                         "<<"library Management System"<<endl;
                            e1.showemployee();
                            cout<<"                     "<<"Press 1 If You Want ADMIN MAIN MENU again"<<endl;
                            cin>>a1;
                        }
                        else if(n==7)
                        {
                            system("cls");
                            b1.issue();
                            cout<<"                     "<<"Press 1 If You Want ADMIN MAIN MENU again"<<endl;
                            cin>>a1;
                        }
                        else if(n==9)
                        {
                            system("cls");
                            b1.issue();
                            cout<<"                     "<<"Press 1 If You Want ADMIN MAIN MENU again"<<endl;
                            cin>>a1;
                        }
                        else if(n==10)
                        {
                            system("cls");
                            b1.book_back();
                            cout<<"                     "<<"Press 1 If You Want ADMIN MAIN MENU again"<<endl;
                            cin>>a1;
                        }
                        else if(n==11)
                        {
                            system("cls");
                            cout<<endl<<endl;
                            b1.search_book();
                            cout<<"                     "<<"Press 1 If You Want ADMIN MAIN MENU again"<<endl;
                            cin>>a1;
                        }
                        else if(n==12)
                        {
                            system("cls");
                            b1.search_book_name();
                            cout<<"                     "<<"Press 1 If You Want ADMIN MAIN MENU again"<<endl;
                            cin>>a1;
                        }
                        else if(n==8)
                        {
                            system("cls");
                            b1.book_back();
                            cout<<"                     "<<"Press 1 If You Want ADMIN MAIN MENU again"<<endl;
                            cin>>a1;
                        }
                        else if(n==13)
                        {
                            system("cls");
                            break;
                        }
                    }
                }
                else
                {
                    //system("cls");
                    //cout<<"                         "<<"library Management System"<<endl;
                    cout<<endl;
                    cout<<"Wrong Password!!!!"<<endl<<endl;
                    cout<<"Try Again"<<endl<<endl;
                }
            }
        }
        else if(x==2)
        {
            while(1)
            {
                system("cls");
                cout<<"                         "<<"library Management System"<<endl;
                cout<<"*********STUDENT MAIN MENU*********"<<endl<<endl;
                cout<<"Press 1 for show book details"<<endl<<endl;
                cout<<"Press 2 for Book Search With Id"<<endl<<endl;
                cout<<"Press 3 for Book Search With Name"<<endl<<endl;
                cout<<"Press 4 MAIN MENU"<<endl;
                cin>>f;
                if(f==1)
                {
                    system("cls");
                    cout<<"                         "<<"library Management System"<<endl;
                    b1.showbook();
                    cout<<"                     "<<"Press 1 If You Want STUDENT MAIN MENU again"<<endl;
                    cin>>a1;
                }
                else if(f==2)
                {
                    system("cls");
                    cout<<endl<<endl;
                    b1.search_book();
                    cout<<"                     "<<"Press 1 If You Want STUDENT MAIN MENU again"<<endl;
                    cin>>a1;
                }
                else if(f==3)
                {
                    system("cls");
                    b1.search_book_name();
                    cout<<"                     "<<"Press 1 If You Want STUDENT MAIN MENU again"<<endl;
                    cin>>a1;
                }
                else if(f==4)
                {
                    break;
                    system("cls");
                }
            }
            system("cls");
        }
        else if(x==3)
        {
            while(1)
            {
                system("cls");
                cout<<"                         "<<"library Management System"<<endl;
                cout<<"*********EMPLOYEE MAIN MENU*********"<<endl<<endl;
                cout<<"Press 1 for show book details"<<endl<<endl;
                cout<<"Press 2 for Book Search With Id"<<endl<<endl;
                cout<<"Press 3 for Book Search With Name"<<endl<<endl;
                cout<<"Press 4 MAIN MENU"<<endl;
                cin>>f;
                if(f==1)
                {
                    system("cls");
                    cout<<"                         "<<"library Management System"<<endl;
                    b1.showbook();
                    cout<<"                     "<<"Press 1 If You Want EMPLOYEE MAIN MENU again"<<endl;
                    cin>>a1;
                }
                else if(f==2)
                {
                    system("cls");
                    cout<<endl<<endl;
                    b1.search_book();
                    cout<<"                     "<<"Press 1 If You Want EMPLOYEE MAIN MENU again"<<endl;
                    cin>>a1;
                }
                else if(f==3)
                {
                    system("cls");
                    b1.search_book_name();
                    cout<<"                     "<<"Press 1 If You Want EMPLOYEE MAIN MENU again"<<endl;
                    cin>>a1;
                }
                else if(f==4)
                {
                    break;
                    system("cls");
                }
            }
            system("cls");
        }
        else if(x==4)
        {
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n"<<"                         "<<"Thank You For Using This :)"<<endl<<endl<<endl<<endl<<endl;
            return 0;
        }
        /*cout<<endl;
        cout<<"                     "<<"Press 1 If You Want MAIN MENU again"<<endl;
        cin>>ok;
        if(ok==1)
        {
            system("cls");
        }*/
    }
    return 0;
}
