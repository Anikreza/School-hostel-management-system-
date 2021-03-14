#include<iostream>
#include <fstream>
#include<cstring>
#include<windows.h>
#include<time.h>
#define SEAT 20   //to assume the total seat available in hostel.
int TOTALSTUDENT=17; //we suppose to have 17 students currently in the hostel.
using namespace std;

class student
{
    string name;
    string id;
    string gender;
    string room;
    string father;
    string mother;
    string date_of_birth;
    string department;
    string semester;
public:
    void set_name(string n)
    {
        name=n;
    }
    void set_id(string i)
    {
        id=i;
    }
    void set_gender(string g)
    {
        gender=g;
    }
    void set_room(string r)
    {
        room=r;
    }
    void set_father(string f)
    {
        father=f;
    }
    void set_mother(string m)
    {
        mother=m;
    }
    void set_birthday(string b)
    {
        date_of_birth=b;
    }
    void set_department(string d)
    {
        department=d;
    }
    void set_semester(string s)
    {
        semester=s;
    }

    string get_name()
    {
        return name;
    }
    string get_id()
    {
        return id;
    }
    string get_gender()
    {
        return gender;
    }
    string get_room()
    {
        return room;
    }
    string get_father()
    {
        return father;
    }
    string get_mother()
    {
        return mother;
    }
    string get_birthday()
    {
        return date_of_birth;
    }
    string get_department()
    {
        return department;
    }
    string get_semester()
    {
        return semester;
    }

};  ///end of student class


void get_time()
{
    Sleep(1000);
    time_t currentTime;
    time(&currentTime);
    cout<<endl<<endl<<"         Database has being accessed at "<<(ctime(&currentTime))<<endl;
}
void get_endtime()
{
    Sleep(100);
    time_t currentTime;
    time(&currentTime);
    cout<<endl<<"         Database has being closed at "<<(ctime(&currentTime))<<endl;
} ///end of get time functions


void semester()
{
    int month;
    time_t currentTime;
    time(&currentTime);
    class tm *myTime = localtime(&currentTime);
    if(myTime->tm_mon+1==4 || myTime->tm_mon+1==3 ||myTime->tm_mon+1==2 ||myTime->tm_mon+1==1)
    {
        cout<<"                              SPRING "<<(myTime->tm_year+1900)<<endl<<endl;
    }
    else if(myTime->tm_mon+1==5 ||myTime->tm_mon+1==6 ||myTime->tm_mon+1==7 ||myTime->tm_mon+1==8)
    {
        cout<<"                              SUMMER "<<(myTime->tm_year+1900)<<endl<<endl;
    }
    else if(myTime->tm_mon+1==9 ||myTime->tm_mon+1==10 ||myTime->tm_mon+1==11 ||myTime->tm_mon+1==12)
    {
        cout<<"                              FALL "<<(myTime->tm_year+1900)<<endl<<endl;
    }
} ///End of function semester

void maxroom(student sr[],int r)
{
    int i;
    string Maxroom=sr[0].get_room();
    for(i=0; i<r; i++)
    {
        if(sr[i].get_room()>Maxroom)
            Maxroom=sr[i].get_room();
    }
    cout<<"Try a number bigger than: "<<Maxroom<<" to 200: ";
}


void greetings()
{
    Sleep(600);
    cout<<endl<<endl<<"                   Welcome to the database of EWU Hostel"<<endl<<endl;
    Sleep (600);
    cout<<"                   Created by: "<<endl<<endl;
    Sleep (600);
    cout<<"                   __________________"<<endl<<endl;
    cout<<"                   Tanvir Reza Anik &"<<endl<<endl;
    Sleep(600);
    cout<<"                   Jahidul Houque"<<endl;
    cout<<"                   __________________"<<endl;
    Sleep(600);
    cout<<endl<<endl;
} ///End of greetings function


void show_menu()
{
    Sleep(100);
    cout<<"                 _________________MAIN MENU_________________"<<endl;
    cout<<endl;
    Sleep(100);
    cout<<"                   : Option 1: Show all students data      :"<<endl;
    cout<<"                                "<<endl;
    Sleep(100);
    cout<<"                   : Option 2: Search for a students entry :"<<endl;
    cout<<"                                 "<<endl;
    Sleep(100);
    cout<<"                   : Option 3: Delete a students entry     :"<<endl;
    cout<<"                                 "<<endl;
    Sleep(100);
    cout<<"                   : Option 4: Admit a new student         :"<<endl;
    cout<<"                                 "<<endl;
    Sleep(100);
    cout<<"                   : Option 5: Edit a student's entry      :"<<endl;
    cout<<"                                 "<<endl;
    Sleep(100);
    cout<<"                   : Option 6: Exit the database           :"<<endl;
    cout<<"                                 "<<endl;
    Sleep(100);
    cout<<"                 ____________________________________________"<<endl;
    cout<<"                                 "<<endl;
    Sleep(100);
    cout<<"                   Option: ";
    Sleep(100);
} ///end of show menu function


int studentData(student ST[],int k)
{
    int in;
    string n,i,g,r,f,m,b,d,s;
    ifstream infile;
    infile.open("projectsfile.txt", ios::in);

    while(infile.eof()==false)
    {
        for(in=0; in<k; in++)
        {
            getline(infile, n);
            getline(infile, i);
            getline(infile, g);
            getline(infile, r);
            getline(infile, f);
            getline(infile, m);
            getline(infile, b);
            getline(infile, d);
            getline(infile, s);

            ST[in].set_name(n);
            ST[in].set_id(i);
            ST[in].set_gender(g);
            ST[in].set_room(r);
            ST[in].set_father(f);
            ST[in].set_mother(m);
            ST[in].set_birthday(b);
            ST[in].set_department(d);
            ST[in].set_semester(s);
        }
    }
    infile.close();
} ///End of student data load from file function



void  showdata(student sT[],int m)
{
    int i;
    for(i=0; i<m; i++)
    {
        cout<<"info of student "<<i+1<<"is below: "<<endl<<endl<<endl;
        cout<<"                   Name: "<<sT[i].get_name()<<endl;
        cout<<"                   ID: "<<sT[i].get_id()<<endl;
        cout<<"                   Gender: "<<sT[i].get_gender()<<endl;
        cout<<"                   Room: "<<sT[i].get_room()<<endl;
        cout<<"                   Father: "<<sT[i].get_father()<<endl;
        cout<<"                   Mother: "<<sT[i].get_mother()<<endl;
        cout<<"                   Birthday: "<<sT[i].get_birthday()<<endl;
        //cout<<"age age is: "<<(myTime->tm_year+1900)-(sT[i].get_birthday())<<" years";
        cout<<"                   Department: "<<sT[i].get_department()<<endl;
        cout<<"                   Semester: "<<sT[i].get_semester()<<endl<<endl;
    }
    cout<<"Number of student in hostel is currently: "<<TOTALSTUDENT<<endl;

} ///End of show data function


void Search(student st[],int x)
{
    int choice;
    string room,id;
    Sleep(100);
    cout<<"By which info do you want to search?"<<endl;
    Sleep(100);
    cout<<"___________________________________"<<endl<<endl;
    Sleep(100);
    cout<<"                         1:ROOM :  "<<endl;
    Sleep(100);
    cout<<"                         2:ID   :  "<<endl;
    Sleep(100);
    cout<<"___________________________________"<<endl;
    Sleep(100);
    cout<<endl<<"ENTER your choice: ";
    Sleep(100);
    cin>>choice;
    cout<<endl;
    if(choice==1)
    {
        int i,flag=0;

        cout<<"ENTER the room number you want to search by: ";
        cin>>room;
        for(i=0; i<x; i++)
        {
            if(st[i].get_room()==room)
            {
                flag=1;
                cout<<"Entry found in index: "<<i<<endl;
                cout<<"There might be some personal informations!do you really want to see it now?"<<endl<<"If you are,then type: YES"<<endl;
                string c;
                cin>>c;
                if(c=="YES")
                {
                    if(st[i].get_gender()=="male"&&"MALE"&&"man"&&"MAN")
                    {
                        cout<<"Thank you,here is his informations: "<<endl<<endl;
                    }
                    else if(st[i].get_gender()=="female"&&"FEMALE"&&"woman"&&"WOMAN")
                    {
                        cout<<"Thank you,here is her information: "<<endl<<endl;
                    }
                    cout<<"                   Name: "<<st[i].get_name()<<"  "<<endl;
                    cout<<"                   Id: "<<st[i].get_id()<<" "<<endl;
                    cout<<"                   Birth year: "<<st[i].get_birthday()<<" "<<endl;
                    cout<<"                   Gender: "<<st[i].get_gender()<<" "<<endl;
                    cout<<"                   Fathers name: "<<st[i].get_father()<<" "<<endl;
                    cout<<"                   Mothers name: "<<st[i].get_mother()<<" "<<endl;
                    cout<<"                   Room: "<<st[i].get_room()<<" "<<endl;
                    cout<<"                   Department: "<<st[i].get_department()<<" "<<endl;
                    cout<<"                   Semester: "<<st[i].get_semester()<<" "<<endl;

                    cout<<endl<<endl;
                }//End of if for privacy checking of student.
                else
                    cout<<"type: YES"<<endl;

            }//End of if for matching input for search.
        }//End of for loop for searching a member.

        if(flag==0)
            cout<<"Sorry!"<<endl<<endl<<"The student you are looking for does not stay here!"<<endl;
    }///End of if for search option of id or name.
    else if (choice==2)
    {
        cout<<"ENTER the ID you want to search: ";
        cin>>id;
        int i,flag=0;
        for(i=0; i<x; i++)
        {
            if(st[i].get_id()==id)
            {
                flag=1;
                cout<<"Entry found in index: "<<i<<endl;
                cout<<endl<<"There might be some personal informations!do you really want to see it now?"<<endl<<"If you are,then type-YES: ";
                string c;
                cin>>c;
                if(c=="YES")
                {
                    if(st[i].get_gender()=="male"&&"MALE"&&"man"&&"MAN")
                    {
                        cout<<endl<<"Thank you,here is his informations: "<<endl<<endl;
                    }
                    else if(st[i].get_gender()=="female"&&"FEMALE"&&"woman"&&"WOMAN")
                    {
                        cout<<endl<<"Thank you,here is her information: "<<endl<<endl;
                    }
                    cout<<"                   Name: "<<st[i].get_name()<<"  "<<endl;
                    cout<<"                   Id: "<<st[i].get_id()<<" "<<endl;
                    cout<<"                   Birth year: "<<st[i].get_birthday()<<" "<<endl;
                    cout<<"                   Gender: "<<st[i].get_gender()<<" "<<endl;
                    cout<<"                   Fathers name: "<<st[i].get_father()<<" "<<endl;
                    cout<<"                   Mothers name: "<<st[i].get_mother()<<" "<<endl;
                    cout<<"                   Room: "<<st[i].get_room()<<" "<<endl;
                    cout<<"                   Department: "<<st[i].get_department()<<" "<<endl;
                    cout<<"                   Semester: "<<st[i].get_semester()<<" "<<endl;

                    cout<<endl<<endl;
                }//End of if for privacy checking of student.
                else
                    cout<<"type: YES"<<endl;

            }//End of else if for matching input for search.
        }//End of for loop for searching a member.
        if(flag==0)
            cout<<"Sorry!"<<endl<<"The student you are looking for does not stay here!"<<endl;
    }//End of else if for search option of id or name.
}///End of search function.


void Delete(student St[],int n)
{
    int index=0,i;
    string id;
    cout<<"Enter the ID of student's entry you want to delete: ";
    cin>>id;
    for(i=0; i<n; i++)
    {
        if(id==St[i].get_id())
        {
            index=i;
            break;
        }
        else
        {
            cout<<endl<<"Sorry! There is no student in here with the ID you entered!"<<endl<<endl;
            return;
        }
    }
    cout<<endl<<"Are you sure you are going to delete entry of student "<<index<<" ?"<<endl;
    cout<<"Tf you are,type-YES: ";
    string ans;
    cin>>ans;
    if(ans=="YES")
    {
        for(i=index; i<n; i++)
        {
            St[i].set_name(St[i+1].get_name());
            St[i].set_id(St[i+1].get_id());
            St[i].set_gender(St[i+1].get_gender());
            St[i].set_room(St[i+1].get_room());
            St[i].set_father(St[i+1].get_father());
            St[i].set_mother(St[i+1].get_mother());
            St[i].set_birthday(St[i+1].get_birthday());
            St[i].set_department(St[i+1].get_department());
            St[i].set_semester(St[i+1].get_semester());
        }//End of for loop to delete every data of the index which to be deleted.
        cout<<"Deletion complete"<<endl;
    }//End of are you sure to delete if.
    else
        cout<<"You did not type YES ";
        TOTALSTUDENT--;
        cout<<"The number of student in hostel is currently: "<<TOTALSTUDENT<<endl;
}///End of delete function.


void Admit(student ns[],int nm)
{
    int i,flag=0;
    student newstd[SEAT];
    string n,id,g,r,f,m,d,s,b,rm;
    if(TOTALSTUDENT>SEAT)
    {
        cout<<"Hostel will be gone over it's capacity,cant add any student's"<<endl;
        cout<<"You can try adding less or equal "<<SEAT-TOTALSTUDENT<<" student's"<<endl;
        return;
    }
    else
    {
        cout<<endl<<"ENTER new student's name: ";
        cin>>n;
        cout<<endl;
        newstd[nm].set_name(n);
        cout<<" Student's id: ";
        cin>>id;
        cout<<endl;
        newstd[nm].set_id(id);
        cout<<" Student's gender: ";
        cin>>g;
        cout<<endl;
        newstd[nm].set_gender(g);
        cout<<" Students room number: ";
        maxroom(ns,nm);
        cin>>r;
        cout<<endl;
                for(i=0;i<nm;i++)
        {
            if(r==ns[i].get_room())
            {
                flag==1;
                cout<<"This room is already taken! "<<endl<<endl;
                maxroom(ns,nm);
                return;
            }
        }
        for(i=0;i<nm;i++)
        {
            if(flag==0)
            {
                newstd[i].set_room(r);
                break;
            }
            else
                cout<<"Try again!"<<endl;
                return;
        }
        newstd[nm].set_room(r);
        cout<<" Student's father name:";
        cin>>f;
        cout<<endl;
        newstd[nm].set_father(f);
        cout<<" Student's mother name:";
        cin>>m;
        cout<<endl;
        newstd[nm].set_mother(m);
        cout<<" Student's birthday:";
        cin>>b;
        cout<<endl;
        newstd[nm].set_birthday(b);
        cout<<" Student's department: ";
        cin>>d;
        cout<<endl;
        newstd[nm].set_department(d);
        cout<<" Student's semester:";
        cin>>s;
        cout<<endl;
        newstd[nm].set_semester(s);
    }  //end of else to check if seats are available

    ns[nm]=newstd[nm];//Saving student info in a new array.


    TOTALSTUDENT++;//UPDATING THE TOTAL NUMBER OF STUDENT'S.

    cout<<"Successfully completed admission of a new student"<<endl;
    cout<<"Number of student in hostel is currently: "<<TOTALSTUDENT<<endl;

} ///End of admit function


void Modify(student Std[],int z)
{
    int choice,i,flag=0;
    string room,semester,id,nr,dep,ID;
    cout<<"            __________________________"<<endl<<endl;
    Sleep(100);
    cout<<"             1: Change room number   :"<<endl;
    Sleep(100);
    cout<<"             2: update Department    :"<<endl;
    Sleep(100);
    cout<<"            __________________________"<<endl;
    Sleep(100);
    cout<<endl<<"Which data you want to modify?  Option: ";
    Sleep(100);
    cin>>choice;
    if(choice==1)
    {
        cout<<endl<<"ENTER the ID of the student you want to change room: ";
        cin>>id;
        cout<<endl<<"Provide with students new room number: ";
        cin>>nr;
        for(i=0; i<z; i++)
        {

            if(nr==Std[i].get_room())
            {
                flag=1;
                cout<<"This room is already booked for: "<<Std[i].get_name()<<endl;
                maxroom(Std,z);
                break;
            }

        }
        for(i=0; i<z; i++)
        {
            if(flag==0)
            {
                if(id==Std[i].get_id())
                {

                    Std[i].set_room(nr);
                    cout<<endl<<"DONE! Room number "<<nr<<" has been successfully booked to "<<Std[i].get_name()<<endl;
                    break;
                }
                else
                {
                    cout<<"Sorry! The student of whose ID you typed does not star here!"<<endl;
                    break;
                }
            }//end of if after making sure the room number is valid

        }//end of for loop to get access to all the students of database
    } //end of if to check the choice

    else if(choice==2)
    {
        cout<<endl<<"ENTER the ID of the student you want to change department: ";
        cin>>ID;
        cout<<endl<<"Provide with students new Department: ";
        cin>>dep;
        for(i=0; i<z; i++)
        {
            if(ID==Std[i].get_id())
            {
                Std[i].set_department(dep);
                cout<<"DONE! "<<Std[i].get_name()<<" has been successfully shifted to "<<dep<<" Department"<<endl;
            }
        } //end of for loop to get the specific student;
    } //end of else if for choice selection

} ///End of modify function



main()
{
    system("color 2f");
    get_time();
    Sleep(2200);
    semester();
    greetings();
    int choice;
    student Stud[SEAT];
    studentData(Stud,TOTALSTUDENT);//load STUDENT data from file
    Sleep(600);
    cout<<"                   Which data you wish to access?"<<endl<<endl;
    Sleep(600);
    while( 1 )
    {
        Sleep(700);
        cout<<endl<<"                   Choose an option and press enter:"<<endl<<endl;
        Sleep(800);
        show_menu();
        cin>>choice;
        if
        (choice==1)
        {
            showdata(Stud,SEAT);
        }
        else if
        (choice==2)
        {
            Search(Stud,TOTALSTUDENT);
        }
        else if
        (choice==3)
        {
            Delete(Stud,TOTALSTUDENT);
        }
        else if
        (choice==4)
        {
            Admit(Stud,TOTALSTUDENT);
        }
        else if
        (choice==5)
        {
            Modify(Stud,TOTALSTUDENT);
        }
        else if
        (choice==6)
        {
            get_endtime();
            break;

        }
    }
    return 0;
}

