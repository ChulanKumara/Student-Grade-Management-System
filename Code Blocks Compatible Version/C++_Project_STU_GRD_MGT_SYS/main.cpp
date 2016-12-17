#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>

#include <windows.h> //To Change Colors ( 0xA-green 0xB-blue 0xC-red 0xE-yellow )
#include <dos.h> //Sleep Function ( Which waits the system some seconds )

//Below header files convert username input to simple case letter because of security purposes.
#include <algorithm>   // transform()
#include <cctype>      // toupper(), tolower()
#include <functional>  // ptr_fun()

///____________________________STUDENT GRADE MANAGEMENT SYSTEM______________________________///

using namespace std;



class RegisterUser{

private:

    string password;
    string uname;
    string pwd;

public:

    bool IsLoggedIN(string usertype, string username)
    {

        cout << "Enter Password: "; cin >> password;

        transform( username.begin(), username.end(), username.begin(), ptr_fun <int, int> ( tolower ) );

        string reader = usertype+"\\";
        reader += username;
        reader += ".dat";

        ifstream read(reader.c_str());
        getline(read, uname);
        getline(read, pwd);
        read.close();

        if(uname == username && pwd == password)
        {
            return true;
        }
        else
        {
            return false;
        }

    }



    bool IfExistsUser(string username, string usertype)
    {

        string readerIFE = usertype+"\\";
        readerIFE += username;
        readerIFE += ".dat";

        ifstream readIFE(readerIFE.c_str());
        getline(readIFE, uname);
        readIFE.close();

        if(uname == username)
        {
            return false;
        }
        else
        {
            return true;
        }

    }


    string change_user_password(string username, string usertype)
    {
        string adminNo, old_pw, new_pw, cnf_pw;

        string readerCUP = usertype+"\\";
        readerCUP += username;
        readerCUP += ".dat";

        ifstream readCUP(readerCUP.c_str());
        getline(readCUP, uname);
        getline(readCUP, pwd);
        getline(readCUP, adminNo);
        readCUP.close();

        cout << "\n" << "Enter Old Password   : "; cin >> old_pw;

        if (old_pw == pwd)
        {
            cout << "Enter New Password   : "; cin >> new_pw;
            cout << "Confirm New Password : "; cin >> cnf_pw;

            if (cnf_pw == new_pw)
            {
                ofstream writeCUP(readerCUP.c_str(), ios::out);
                writeCUP << username << endl << new_pw << endl << adminNo;
                writeCUP.close();
                return "Password Changed Successfully";
            }

            else
                return "Couldn't Confirm the Password";

        }
        else
            return "Old Password is Incorrect";
    }

};


class Student
{

private:

    int stuno;
    char index[20];
    char fname[20];
    char lname[20];
    char nic[20];
    char gender[20];
    char dob[20];
    char batch[20];
    char joined[20];
    char national[20];
    char module_1[20];
    char module_2[20];
    char module_3[20];

    int M1Assi,M1Final;
    int M2Assi,M2Final;
    int M3Assi,M3Final;

public:
    void setData()
    {
        cout << "\nEnter Student No                : "; cin >> stuno;
        cout << "Index No. of the Student        : "; cin >> index;
        cout << "First Name of the Student       : "; cin >> fname;
        cout << "Last Name of the Student        : "; cin >> lname;
        cout << "National Identification Card No : "; cin >> nic;
        cout << "Gender [M/F]                    : "; cin >> gender;
        cout << "Date of Birth [YYYY-MM-DD]      : "; cin >> dob;
        cout << "Batch                           : "; cin >> batch;
        cout << "Joined Date [YYYY-MM-DD]        : "; cin >> joined;
        cout << "Nationality                     : "; cin >> national;
        cout << "Module 1                        : "; cin >> module_1;
        cout << "Module 2                        : "; cin >> module_2;
        cout << "Module 3                        : "; cin >> module_3;
    }

    void showData()
    {
        cout << "\nStudent No            : " << stuno;
        cout << "\nIndex Number          : " << index;
        cout << "\nFirst Name            : " << fname;
        cout << "\nLast Name             : " << lname;
        cout << "\nNIC                   : " << nic;
        cout << "\nGender [M/F]          : " << gender;
        cout << "\nDate of Birth         : " << dob;
        cout << "\nBatch                 : " << batch;
        cout << "\nJoined Date           : " << joined;
        cout << "\nNationality           : " << national;
        cout << "\nModule 1              : " << module_1;
        cout << "\nModule 2              : " << module_2;
        cout << "\nModule 3              : " << module_3;
        cout << "\n\n" << endl;
    }

        void showData_inline()
    {

        cout << " "<<stuno  <<"\t"<< index <<"\t"<< fname <<" "<< lname <<"\t\t"<< nic <<"\t\t"<< gender <<"\t\t"<< dob <<"\t"<< batch <<"\t"<< joined <<"\t"<< national <<"\t"<< module_1 <<"\t"<< module_2 <<"\t"<< module_3<<"\n\n" << endl;

    }

    void setmarks()
    {
        cout << "\n" << "Enter Student No                  : "; cin >> stuno;
        cout << "\n" << "Module 1 Assignment Marks (%)     : "; cin >> M1Assi;
        cout         << "Module 1 Final Marks (%)          : "; cin >> M1Final;
        cout << "\n" << "Module 2 Assignment Marks (%)     : "; cin >> M2Assi;
        cout         << "Module 2 Final Marks (%)          : "; cin >> M2Final;
        cout << "\n" << "Module 3 Assignment Marks (%)     : "; cin >> M3Assi;
        cout         << "Module 3 Final Marks (%)          : "; cin >> M3Final;
    }

    void showmarks()
    {
        cout << "\n\nStudent No            : " << stuno;
        cout << "\nModule 1 Assignment   : " << M1Assi << "%";
        cout << "\nModule 1 Final        : " << M1Final << "%";
        cout << "\nModule 2 Assignment   : " << M2Assi << "%";
        cout << "\nModule 2 Final        : " << M2Final << "%";
        cout << "\nModule 3 Assignment   : " << M3Assi << "%";
        cout << "\nModule 3 Final        : " << M3Final << "%";

    }

    int retAdmno()
    {
        return stuno;
    }

    char* retFname()
    {
        return fname;
    }

    char* retLname()
    {
        return lname;
    }

    char* retNIC()
    {
        return nic;
    }

    char* retM1()
    {
        return module_1;
    }

    char* retM2()
    {
        return module_2;
    }

    char* retM3()
    {
        return module_3;
    }

    char* retBatch()
    {
        return batch;
    }

    char* retDateJ()
    {
        return joined;
    }

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void write_record()
{
    ofstream outFile;
    outFile.open("users/students.dat", ios::binary | ios::app);

    Student obj;
    obj.setData();

    outFile.write((char*)&obj, sizeof(obj));

    outFile.close();
}


//Display records of file



void display()
{
    ifstream inFile;
    inFile.open("users/students.dat", ios::binary);

    Student obj;
    cout << "\n\n___________________________________________________________________________\n"<<endl;
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.showData();
    }
    cout << "\n___________________________________________________________________________\n\n"<<endl;

    inFile.close();
}

void display_inline()
{
    ifstream inFile;
    inFile.open("users/students.dat", ios::binary);

    Student obj;

    cout << "\n\n_____________________________________________________________________________________________________________________________________________________________________________________________\n"<<endl;
    cout << "\n SN\tIndex Number\t\tName\t\t\t\tNIC\t\t\tGender\t\t\tDOB\t\tBatch\tJoined Date\tNationality\tM 1\tM 2\tM 3\n" << endl;
    cout << "_____________________________________________________________________________________________________________________________________________________________________________________________\n\n"<<endl;
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.showData_inline();
    }
    cout << "\n_____________________________________________________________________________________________________________________________________________________________________________________________"<<endl;
    cout << "NOTE: If you cannot see properly, you may adjust the window Width(Screen Buffer Size) to 200, from Window Properties.\n\n";
    inFile.close();
}


void modify_record(int n)
{
    fstream file;
    file.open("users/students.dat",ios::in | ios::out);

    Student obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
            cout << "\nEnter the New Details of Student";
            obj.setData();

            int pos = -1 * sizeof(obj);
            file.seekp(pos, ios::cur);

            file.write((char*)&obj, sizeof(obj));
        }
    }

    file.close();
}



 //Delete a record


void delete_record(int n)
{
    Student obj;
    ifstream inFile;
    inFile.open("users/students.dat", ios::binary);

    ofstream outFile;
    outFile.open("users/stutemp.dat", ios::out | ios::binary);

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() != n)
        {
            outFile.write((char*)&obj, sizeof(obj));
        }
    }

    inFile.close();
    outFile.close();

    remove("users/students.dat");
    rename("users/stutemp.dat", "users/students.dat");
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void write_marks()
{
    ofstream outFile;
    outFile.open("users/students_marks.dat", ios::binary | ios::app);

    Student objmarks;
    objmarks.setmarks();

    outFile.write((char*)&objmarks, sizeof(objmarks));

    outFile.close();
}

void display_marks()
{
    ifstream inMFile;
    inMFile.open("users/students_marks.dat", ios::binary);

    Student objmarks;
    cout << "\n\n___________________________________________________________________________\n"<<endl;
    while(inMFile.read((char*)&objmarks, sizeof(objmarks)))
    {
        objmarks.showmarks();
    }
    cout << "\n\n\n___________________________________________________________________________\n\n"<<endl;

    inMFile.close();
}

void modify_marks(int n)
{
    fstream Mfile;
    Mfile.open("users/students_marks.dat",ios::in | ios::out);

    Student objmarks;

    while(Mfile.read((char*)&objmarks, sizeof(objmarks)))
    {
        if(objmarks.retAdmno() == n)
        {
            cout << "\nEnter the new marks of student";
            objmarks.setmarks();

            int pos = -1 * sizeof(objmarks);
            Mfile.seekp(pos, ios::cur);

            Mfile.write((char*)&objmarks, sizeof(objmarks));
        }
    }

    Mfile.close();
}

void delete_record_marks(int n)
{
    Student objmarks;
    ifstream inMFile;
    inMFile.open("users/students_marks.dat", ios::binary);

    ofstream outMFile;
    outMFile.open("users/stu_markstemp.dat", ios::out | ios::binary);

    while(inMFile.read((char*)&objmarks, sizeof(objmarks)))
    {
        if(objmarks.retAdmno() != n)
        {
            outMFile.write((char*)&objmarks, sizeof(objmarks));
        }
    }

    inMFile.close();
    outMFile.close();

    remove("users/students_marks.dat");
    rename("users/stu_markstemp.dat", "users/students_marks.dat");
}



///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///+++++++++++++++++++++++++++++++++SEARCH+++++++++++++++++++++++++++++++++++
///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


///Search by Student Number
void search_SN(int srch)
{
    ifstream inFile;
    inFile.open("users/students.dat", ios::binary);

    Student obj_sn_srch;


    cout << "\n\nSEARCH RESULTS FOR STUDENT NUMBER \"" << srch << "\"" << endl;
    cout << "\n_____________________________________________________________________________________________________________________________________________________________________________________________\n"<<endl;
    cout << "\n SN\tIndex Number\t\tName\t\t\t\tNIC\t\t\tGender\t\t\tDOB\t\tBatch\tJoined Date\tNationality\tM 1\tM 2\tM 3\n" << endl;
    cout << "_____________________________________________________________________________________________________________________________________________________________________________________________\n\n"<<endl;

    while(inFile.read((char*)&obj_sn_srch, sizeof(obj_sn_srch)))
    {
        if(obj_sn_srch.retAdmno() == srch)
        {
            obj_sn_srch.showData_inline();
        }
    }

    cout << "\n_____________________________________________________________________________________________________________________________________________________________________________________________"<<endl;
    cout << "NOTE: If you cannot see properly, you may adjust the window Width(Screen Buffer Size) to 200, from Window Properties.\n\n";

    inFile.close();
}



///Searching by First Name,Last Name, NIC, Module 1, Module 2, Module 3 and Batch.
void search_FN(char* fn_srch, int srch_keyword)
{
    ifstream inFile;
    inFile.open("users/students.dat", ios::binary);

    Student obj_fn_srch;

    char* to_srch_keyword;
    //This will search for the keyword
    if (srch_keyword == 2)
    to_srch_keyword = obj_fn_srch.retFname();
    else if (srch_keyword == 3)
    to_srch_keyword = obj_fn_srch.retLname();
    else if (srch_keyword == 4)
    to_srch_keyword = obj_fn_srch.retNIC();
    else if (srch_keyword == 5)
    to_srch_keyword = obj_fn_srch.retM1();
    else if (srch_keyword == 6)
    to_srch_keyword = obj_fn_srch.retM2();
    else if (srch_keyword == 7)
    to_srch_keyword = obj_fn_srch.retM3();
    else if (srch_keyword == 8)
    to_srch_keyword = obj_fn_srch.retBatch();
    else if (srch_keyword == 9)
    to_srch_keyword = obj_fn_srch.retDateJ();

    cout << "\n\nSEARCH RESULTS FOR \"" << fn_srch << "\"" << endl;
    cout << "\n_____________________________________________________________________________________________________________________________________________________________________________________________\n"<<endl;
    cout << "\n SN\tIndex Number\t\tName\t\t\t\tNIC\t\t\tGender\t\t\tDOB\t\tBatch\tJoined Date\tNationality\tM 1\tM 2\tM 3\n" << endl;
    cout << "_____________________________________________________________________________________________________________________________________________________________________________________________\n\n"<<endl;

    while(inFile.read((char*)&obj_fn_srch, sizeof(obj_fn_srch)))
    {
        if((strcmp(to_srch_keyword,fn_srch))==0)
        {
            obj_fn_srch.showData_inline();
        }

    }

    cout << "\n_____________________________________________________________________________________________________________________________________________________________________________________________"<<endl;
    cout << "NOTE: If you cannot see properly, you may adjust the window Width(Screen Buffer Size) to 200, from Window Properties.\n";
    cout << "      If the search result returned \"Empty Set\" that means program couldn't find your keyword.\n\n";

    inFile.close();
}


int search_student()
{
    search_label: //Label

    //COLOR CHANGE EFFECTS
	HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    // Remember how things were when started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );
    //COLOR CHANGE EFFECTS


                cout << "\n\nSelect Category to Search Student\n" << endl;
                cout << " 1.Search by Student Number" << endl;
                cout << " 2.Search by First Name " << endl;
                cout << " 3.Search by Last Name " << endl;
                cout << " 4.Search by NIC Number " << endl;
                cout << " 5.Search by Module 1" << endl;
                cout << " 6.Search by Module 2" << endl;
                cout << " 7.Search by Module 3" << endl;
                cout << " 8.Search by Batch " << endl;
                cout << " 9.Search by Date Joined " << endl;
                cout << "10.Edit/Delete Records" << endl;
                cout << " 0.Done" << endl;


                int srch;
                char srch_fn[20];
                cout << "\nYour Choice : "; cin >> srch;

                switch (srch)
                {
                case 0:
                    return 1;
                    break;

                case 1:
                    int srch_sn;
                    cout << "\nEnter Student Number : "; cin >> srch_sn;


                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    search_SN(srch_sn);

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto search_label;
                    break;

                case 2:

                    cout << "\nEnter Student First Name : "; cin >> srch_fn;


                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    search_FN(srch_fn, 2);

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto search_label;
                    break;

               case 3:

                    cout << "\nEnter Student Last Name : "; cin >> srch_fn;


                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    search_FN(srch_fn, 3);

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto search_label;
                    break;

               case 4:

                    cout << "\nEnter Student NIC : "; cin >> srch_fn;


                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    search_FN(srch_fn, 4);

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto search_label;
                    break;

               case 5:

                    cout << "\nEnter Module 1 : "; cin >> srch_fn;


                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    search_FN(srch_fn, 5);

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto search_label;
                    break;

               case 6:

                    cout << "\nEnter Module 2 : "; cin >> srch_fn;


                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    search_FN(srch_fn, 6);

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto search_label;
                    break;

               case 7:

                    cout << "\nEnter Module 3 : "; cin >> srch_fn;


                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    search_FN(srch_fn, 7);

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto search_label;
                    break;

               case 8:

                    cout << "\nEnter Student Batch : "; cin >> srch_fn;


                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    search_FN(srch_fn, 8);

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto search_label;
                    break;

                case 9:

                    cout << "\nEnter Student Batch : "; cin >> srch_fn;


                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    search_FN(srch_fn, 9);

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto search_label;
                    break;

                case 10:
                    return 2;
                    break;

                default:
                    cout << "Error Input" << endl;
                    Sleep(2000);
                    system("CLS");
                    goto search_label;
                    break;

                }
}




///./////////////////////////////////////////////////////////////////////////
///./////////////////////////////////////////////////////////////////////////
///.//////////////////////////////STAFF//////////////////////////////////////
///./////////////////////////////////////////////////////////////////////////
///./////////////////////////////////////////////////////////////////////////



class Staff
{

private:

    char fname[20];
    char lname[20];
    char nic[20];
    char gender[20];
    char designation[20];
    char department[20];

public:

    char staff_no[3];
    int staff_no_int;
    int staff_no_after;

    void set_staff_count()
    {
        ifstream readstaffcount("users/staff_count.dat");
        readstaffcount >> staff_no;
        readstaffcount.close();

        staff_no_int = atoi(staff_no); //converting chat to an integer
        staff_no_after = staff_no_int+1;
        ofstream writestaffcount("users/staff_count.dat", ios::out);
        writestaffcount << staff_no_after;
        writestaffcount.close();

    }

    void setData_staff()
    {
        set_staff_count();

        cout << "First Name of the Staff Member         : "; cin >> fname;
        cout << "Last Name of the Staff Member          : "; cin >> lname;
        cout << "National Identification Card No        : "; cin >> nic;
        cout << "Gender [M/F]                           : "; cin >> gender;
        cout << "Designation [Lecturer/Administrative]  : "; cin >> designation;
        cout << "Department                             : "; cin >> department;

    }

    void showData_staff()
    {
        cout << "\nStaff No              : " << staff_no;
        cout << "\nFirst Name            : " << fname;
        cout << "\nLast Name             : " << lname;
        cout << "\nNIC                   : " << nic;
        cout << "\nGender [M/F]          : " << gender;
        cout << "\nDesignation           : " << designation;
        cout << "\nDepartment            : " << department;
        cout << "\n\n" << endl;
    }

        void showData_inline_staff()
    {

        cout << " " <<staff_no  << "\t" << fname << " " << lname << "\t\t\t" << nic << "\t\t" << gender << "\t\t\t"<< designation << "\t\t\t"<< department << "\n\n" << endl;

    }


    int retAdmno()
    {
        return staff_no_int;
    }
};

void write_record_staff()
{
    ofstream outFile_staff;
    outFile_staff.open("users/staff.dat", ios::binary | ios::app);

    Staff obj_staff;


    obj_staff.setData_staff();


    outFile_staff.write((char*)&obj_staff, sizeof(obj_staff));

    outFile_staff.close();
}

/*
* function to display records of file
*/


void display_staff()
{
    ifstream inFile_staff;
    inFile_staff.open("users/staff.dat", ios::binary);

    Staff obj_staff;
    cout << "\n\n___________________________________________________________________________\n"<<endl;
    while(inFile_staff.read((char*)&obj_staff, sizeof(obj_staff)))
    {
        obj_staff.showData_staff();
    }
    cout << "\n___________________________________________________________________________\n\n"<<endl;

    inFile_staff.close();
}

void display_inline_staff()
{
    ifstream inFile_staff;
    inFile_staff.open("users/staff.dat", ios::binary);

    Staff obj_staff;

    cout << "\n\n_____________________________________________________________________________________________________________________________________________\n"<<endl;
    cout << "\n SN\tName\t\t\t\t\tNIC\t\t\tGender\t\t\tDesignation\t\t\t\tDepartment\n" << endl;
    cout << "_____________________________________________________________________________________________________________________________________________\n\n"<<endl;
    while(inFile_staff.read((char*)&obj_staff, sizeof(obj_staff)))
    {
        obj_staff.showData_inline_staff();
    }
    cout << "_____________________________________________________________________________________________________________________________________________"<<endl;
    cout << "NOTE: If you cannot see properly, you may adjust the window Width(Screen Buffer Size) to 200, from Window Properties.\n\n";
    inFile_staff.close();
}


void modify_record_staff(int n)
{
    fstream file_staff;
    file_staff.open("users/staff.dat",ios::in | ios::out);

    Staff obj_staff;

    while(file_staff.read((char*)&obj_staff, sizeof(obj_staff)))
    {
        if(obj_staff.retAdmno() == n)
        {
            cout << "\nEnter the new details of student";
            obj_staff.setData_staff();

            int pos = -1 * sizeof(obj_staff);
            file_staff.seekp(pos, ios::cur);

            file_staff.write((char*)&obj_staff, sizeof(obj_staff));
        }
    }

    file_staff.close();
}


/*
* function to delete a record
*/

void delete_record_staff(int m)
{
    Staff obj_staff;
    ifstream inFile_staff;
    inFile_staff.open("users/staff.dat", ios::binary);

    ofstream outFile_staff;
    outFile_staff.open("users/stafftemp.dat", ios::out | ios::binary);

    while(inFile_staff.read((char*)&obj_staff, sizeof(obj_staff)))
    {
        if(obj_staff.retAdmno() != m)
        {
            outFile_staff.write((char*)&obj_staff, sizeof(obj_staff));
        }
    }

    inFile_staff.close();
    outFile_staff.close();

    remove("users/staff.dat");
    rename("users/stafftemp.dat", "users/staff.dat");
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//SHOW AND EDIT MODULE DETAILS

void show_module_det()
{
    ifstream read_module("users/modules.txt");
    string str;
    while (getline(read_module, str))
    {
        cout << str << endl;
    }
}

void edit_module_det()
{
    fstream Module_file("users/modules.txt",ios::out);

    if(Module_file.fail())
    {
        cout<<"error opening file"<<endl;
    }

    cout << "\nNOTE  : If You Are Done Editing the Module Details, Press and Enter \"#\" to End.\n\n" << endl;
    char ch;
    while(1)
    {
            cin.get(ch);

            if (ch == '#')
                break;

            Module_file.put(ch);

    }

    Module_file.close();
}


int main()
{

    begininglabel:
    //COLOR CHANGE EFFECTS
	HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    // Remember how things were when started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );
    //COLOR CHANGE EFFECTS


    char whoareyou;

    SetConsoleTextAttribute( hstdout, 0xE0 ); //COLOR
    cout << "                                                                               "<<endl;
    cout << "                                                                               "<<endl;
    cout << "___________________________________WELCOME!____________________________________"<<endl;
    cout << "                                                                               "<<endl;
    cout << "                                                                               "<<endl;
    SetConsoleTextAttribute( hstdout, 0x5C ); //COLOR
    cout << "                                                                               "<<endl;
    cout << "_______________________STUDENT GRADE MANAGEMENT SYSTEM_________________________"<<endl;
    cout << "                                                                               \n"<<endl;

    //COLOR
    FlushConsoleInputBuffer( hstdin );
    // Back to normal color
    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
    //COLOR


    cout << "Who Are You?\n\n" << endl;
    cout << "1. A Student" << endl;
    cout << "2. A Lecturer" << endl;
    cout << "3. An Administrative Staff Member" << endl;
    cout << "4. Admin" << endl;
    cout << "\n\n0. Exit" << endl;

    cout << "\nYour Choice: "; cin >> whoareyou;

    if(whoareyou == '1')
    {

                RegisterUser regstudent;

                string username;
                cout << "Enter Username: "; cin >> username;

                transform( username.begin(), username.end(), username.begin(), ptr_fun <int, int> ( tolower ) );

                bool status = regstudent.IsLoggedIN("users/students", username);

                if(!status)
                {
                    system("CLS");

                    SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                    cout << "\nLogin Failed! Check Username and Password" << endl;

                    Sleep(2000);

                    system("CLS");
                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    main();
                }
                else
                {

                    system("CLS");
                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    cout << "\nLogged in Successfully." << endl;



                    Sleep(2000);
                    system("CLS");


                    studentlable: //LABLE
                    SetConsoleTextAttribute( hstdout, 0xA0 ); //COLOR
                    cout << "                                                                               " <<endl;
                    cout << "                           Welcome  |  Student's Page                          " <<endl;
                    cout << "                                                                               " <<endl;
                    SetConsoleTextAttribute( hstdout, 0xB ); //COLOR
                    cout << "You Are Logged In As \""<<username<<"\""<<endl;


                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    string uname, pwd, admission_num;


                    string readstudentfile = "users/students\\";
                    readstudentfile += username;
                    readstudentfile += ".dat";



                    ifstream read(readstudentfile.c_str());
                    getline(read, uname);
                    getline(read, pwd);
                    getline(read, admission_num);
                    read.close();

                    int admission_num_int = atoi(admission_num.c_str());



                    Student  objmarks;


                    //searching the student marks according to username
                    ifstream inMFile;
                    inMFile.open("users/students_marks.dat", ios::binary);



                    while(inMFile.read((char*)&objmarks, sizeof(objmarks)))
                    {
                        if(objmarks.retAdmno() == admission_num_int)
                        {
                            objmarks.showmarks();
                        }
                    }

                    inMFile.close();

                    stu_choice_label:
                    int stu_choice;
                    cout <<"\n\n 1.View My Details\n 2.Change Password\n 3.View Module Details\n\n 0.Logout \n99.Exit \n\nYour Choice : "; cin >> stu_choice;
                    if (stu_choice == 0)
                    {
                        system("CLS");
                        main();
                    }

                    else if(stu_choice == 1)
                    {
                        Student obj;

                        //searching the student details according to username
                        ifstream inFile;
                        inFile.open("users/students.dat", ios::binary);

                        SetConsoleTextAttribute( hstdout, 0xE ); //COLOR

                        while(inFile.read((char*)&obj, sizeof(obj)))
                        {
                            if(obj.retAdmno() == admission_num_int)
                            {
                                obj.showData();
                            }
                        }

                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR

                        inFile.close();
                        goto stu_choice_label;
                    }

                    else if(stu_choice == 2)
                    {
                        RegisterUser changePWobj;

                        string PWDchngStatus = changePWobj.change_user_password(username, "users/students");

                        cout << PWDchngStatus << endl;

                        Sleep(2000);
                        system("CLS");
                        goto studentlable;
                    }

                    else if (stu_choice == 3)
                    {
                        cout << "\n\n\n" << endl;
                        SetConsoleTextAttribute( hstdout, 0x5 ); //COLOR

                        show_module_det(); //Showing module details.

                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR

                        while (cin.get())
                        {
                            cout << "\n" << endl;
                            system("PAUSE");
                            system("CLS");
                            goto studentlable;
                        }
                    }

                    else if (stu_choice == 99)
                    {
                        return 0;
                    }

                    else
                    {
                        cout << "Invalid Input" << endl;
                        Sleep(2000);
                        system("CLS");
                        goto studentlable;
                    }


                }
    }

    else if(whoareyou == '2') //LOGGED IN AS LECTURER
    {

                RegisterUser reglec;

                string username;
                cout << "Enter Username: "; cin >> username;

                transform( username.begin(), username.end(), username.begin(), ptr_fun <int, int> ( tolower ) );

                bool status = reglec.IsLoggedIN("users/lecturers", username);

                if(!status)
                {
                    system("CLS");

                    SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                    cout << "\nLogin Failed! Check Username and Password" << endl;

                    Sleep(2000);

                    system("CLS");
                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    main();
                }
                else
                {

                    system("CLS");
                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    cout << "\nLogged in Successfully." << endl;



                    Sleep(2000);
                    system("CLS");

                    lecturerlable: //LABLE

                    SetConsoleTextAttribute( hstdout, 0xA0 ); //COLOR
                    cout << "                                                                               " <<endl;
                    cout << "                          Welcome  |  Lecturer's Page                          " <<endl;
                    cout << "                                                                               " <<endl;
                    SetConsoleTextAttribute( hstdout, 0xB ); //COLOR
                    cout << "You Are Logged In As \""<<username<<"\""<<endl;


                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    int choice;
                    cout <<"\n\n 1.View My Details \n 2.Student Marks and Details \n 3.Search Student \n 4.View Module Details \n\n 0.Logout\n99.Exit \n\nYour Choice : "; cin >> choice;
                    if (choice == 0)
                    {
                        system("CLS");
                        main();
                    }
                    else if (choice == 1) //VIEW LECTURER DETAILS
                    {

                        string uname, pwd, admission_num;


                        string readlecturersfile = "users/lecturers\\";
                        readlecturersfile += username;
                        readlecturersfile += ".dat";



                        ifstream read(readlecturersfile.c_str());
                        getline(read, uname);
                        getline(read, pwd);
                        getline(read, admission_num);
                        read.close();

                        int admission_num_int = atoi(admission_num.c_str());



                        Staff obj;

                        //searching the lecturer details according to username
                        ifstream inFile;
                        inFile.open("users/staff.dat", ios::binary);

                        SetConsoleTextAttribute( hstdout, 0xE ); //COLOR

                        while(inFile.read((char*)&obj, sizeof(obj)))
                        {
                            if(obj.retAdmno() == admission_num_int)
                            {
                                obj.showData_staff();
                            }
                        }

                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR

                        inFile.close();
                        int lec_choice;

                        cout << "\n1.Change Account Password\n0.Done"<<endl;
                        lecturer_myacc_label:
                        cout << "\nYour Choice : ";

                        cin >> lec_choice;

                        if (lec_choice == 0)
                        {
                            system("CLS");
                            goto lecturerlable;
                        }
                        else if (lec_choice == 1)
                        {
                            RegisterUser changePWobj;

                            string PWDchngStatus = changePWobj.change_user_password(username, "users/lecturers");

                            cout << PWDchngStatus << endl;

                            Sleep(2000);
                            system("CLS");
                            goto lecturerlable;

                        }
                        else
                        {
                            cout << "Error Input" << endl;
                            Sleep(2000);
                            goto lecturer_myacc_label;
                        }
                    }


                    else if (choice == 2) //ENTER/EDIT STUDENTS MARKS (AS LECTURER)
                    {
                       lecturer_mark_edit:

                        int swi2;
                        cout << "\n1.Enter Marks \n2.List All Students Marks  \n3.List All Student Details \n4.Modify Marks \n5.Delete Marks\n0.Done \n\nYour Choice: ";
                        cin >> swi2;
                        switch (swi2)
                        {
                        case 0:
                            system("CLS");
                            goto lecturerlable;
                            break;

                        case 1:
                            int jj;
                            cout << "\nHow Many Records You Want to Enter: "; cin >> jj;
                            for (int ii=0; ii<jj; ii++)
                            {
                              write_marks();
                            }

                            cout << "Records Entered Successfully"<<endl;
                            Sleep(2000);
                            system("CLS");
                            goto lecturerlable;
                            break;

                        case 2:
                            //Display all records
                            cout << "\nList of Marking Records";

                            SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                            display_marks();

                            //COLOR
                            FlushConsoleInputBuffer( hstdin );
                            // Back to normal color
                            SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                            //COLOR

                            goto lecturer_mark_edit;
                            break;

                        case 3:
                            //show students details
                            cout << "\nList of Students Details";

                            SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                            display_inline();

                            //COLOR
                            FlushConsoleInputBuffer( hstdin );
                            // Back to normal color
                            SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                            //COLOR

                            goto lecturer_mark_edit;
                            break;

                        case 4:
                            //Modify record
                            int xx;
                            cout << "\nModify Marks (Enter Student Number) : "; cin >> xx;
                            modify_marks(xx);
                            cout << "\nMarks Successfully Modified" << endl;
                            Sleep(2000);
                            system("CLS");
                            goto lecturerlable;
                            break;

                        case 5:
                            //Delete record
                            int yy;
                            cout << "\nDelete Marks (Enter Student Number) : "; cin >> yy;
                            delete_record_marks(yy);
                            cout << "\nMarks Record Deleted\n";
                            Sleep(2000);
                            system("CLS");
                            goto lecturerlable;
                            break;


                        default:

                            cout<<"Error Input\n";
                            Sleep(2000);
                            system("CLS");

                            goto lecturerlable;
                            break;
                        }



                    }

                    else if (choice == 3) //SEARCH STUDENTS (AS LECTURER)
                    {
                        int x = search_student();
                        if (x == 1)
                        {
                            system("CLS");
                            goto lecturerlable;
                        }
                        else if (x == 2)
                        {
                            cout << "\nYou Don't Have Permission!" << endl;
                            Sleep(2000);
                            system("CLS");
                            goto lecturerlable;
                        }
                    }

                    else if (choice == 4)
                    {
                        cout << "\n\n\n" << endl;
                        SetConsoleTextAttribute( hstdout, 0x5 ); //COLOR

                        show_module_det(); //Showing module details.

                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR

                        while (cin.get())
                        {
                            cout << "\n" << endl;
                            system("PAUSE");
                            system("CLS");
                            goto lecturerlable;
                        }
                    }

                    else if (choice == 99)
                    {
                        return 0;
                    }

                    else
                    {
                        cout << "Invalid Input" << endl;
                        Sleep(2000);
                        system("CLS");
                        goto lecturerlable;
                    }


                }
    }


    else if(whoareyou == '3') //LOGGED IN AS ADMINISTRATIVE STAFF MEMBER
    {

                RegisterUser regadminis;

                string username;
                cout << "Enter Username: "; cin >> username;

                transform( username.begin(), username.end(), username.begin(), ptr_fun <int, int> ( tolower ) );

                bool status = regadminis.IsLoggedIN("users/adminstaff", username);

                if(!status)
                {
                    system("CLS");

                    SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                    cout << "\nLogin Failed! Check Username and Password" << endl;

                    Sleep(2000);

                    system("CLS");
                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    main();
                }
                else
                {

                    system("CLS");
                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    cout << "\nLogged in Successfully." << endl;



                    Sleep(2000);
                    system("CLS");

                    adminstafflable: //LABLE

                    SetConsoleTextAttribute( hstdout, 0xA0 ); //COLOR
                    cout << "                                                                               " <<endl;
                    cout << "                 Welcome  |  Administrative Staff Member's Page                " <<endl;
                    cout << "                                                                               " <<endl;
                    SetConsoleTextAttribute( hstdout, 0xB ); //COLOR
                    cout << "You Are Logged In As \""<<username<<"\""<<endl;


                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    int choice;
                    cout <<"\n\n 1.View My Details\n 2.Student Marks and Details\n 3.Search Students\n 4.View Module Details\n\n 0.Logout\n99.Exit\n\nYour Choice : "; cin >> choice;
                    if (choice == 0)
                    {
                        system("CLS");
                        main();
                    }
                    else if (choice == 1) //VIEW AD STAFF DETAILS
                    {

                        string uname, pwd, admission_num;


                        string readadminstafffile = "users/adminstaff\\";
                        readadminstafffile += username;
                        readadminstafffile += ".dat";



                        ifstream read(readadminstafffile.c_str());
                        getline(read, uname);
                        getline(read, pwd);
                        getline(read, admission_num);
                        read.close();

                        int admission_num_int = atoi(admission_num.c_str());



                        Staff obj;

                        //searching the ad staff details according to username
                        ifstream inFile;
                        inFile.open("users/staff.dat", ios::binary);

                        SetConsoleTextAttribute( hstdout, 0xE ); //COLOR

                        while(inFile.read((char*)&obj, sizeof(obj)))
                        {
                            if(obj.retAdmno() == admission_num_int)
                            {
                                obj.showData_staff();
                            }
                        }

                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR

                        inFile.close();
                        int adstaff_choice;

                        cout << "\n1.Change Account Password\n0.Done"<<endl;
                        adminstaff_myacc_label:
                        cout << "\nYour Choice : ";
                        cin >> adstaff_choice;

                        if (adstaff_choice == 0)
                        {
                            system("CLS");
                            goto adminstafflable;
                        }
                        else if (adstaff_choice == 1)
                        {
                            RegisterUser changePWobj;

                            string PWDchngStatus = changePWobj.change_user_password(username, "users/adminstaff");

                            cout << PWDchngStatus << endl;

                            Sleep(2000);
                            system("CLS");
                            goto adminstafflable;

                        }
                        else
                        {
                            cout << "Error Input" << endl;
                            Sleep(2000);
                            goto adminstaff_myacc_label;
                        }
                    }


                    else if (choice == 2) //VIEW STUDENTS MARKS (AS AD STAFF)
                    {
                       adminstaff_mark_view:

                        int swi2;
                        cout << "\n1.List All Students Marks\n2.List All Student Details \n0.done \n\nYour Choice : ";
                        cin >> swi2;
                        switch (swi2)
                        {
                        case 0:
                            system("CLS");
                            goto adminstafflable;
                            break;

                        case 1:
                            //Display all records
                            cout << "\nList of marking records";

                            SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                            display_marks();

                            //COLOR
                            FlushConsoleInputBuffer( hstdin );
                            // Back to normal color
                            SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                            //COLOR

                            goto adminstaff_mark_view;
                            break;

                        case 2:
                            //show students details
                            cout << "\nList of Students Details";

                            SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                            display_inline();

                            //COLOR
                            FlushConsoleInputBuffer( hstdin );
                            // Back to normal color
                            SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                            //COLOR

                            goto adminstaff_mark_view;
                            break;


                        default:

                            cout<<"Invalid Input\n";
                            Sleep(2000);
                            system("CLS");

                            goto adminstafflable;
                            break;
                        }


                    }

                    else if (choice == 3)
                    {
                        int x = search_student();
                        if (x == 1)
                        {
                            system("CLS");
                            goto adminstafflable;
                        }
                        else if (x == 2)
                        {
                            cout << "\nYou Don't Have Permission!" << endl;
                            Sleep(2000);
                            system("CLS");
                            goto adminstafflable;
                        }
                    }

                    else if (choice == 4)
                    {
                        cout << "\n\n\n" << endl;
                        SetConsoleTextAttribute( hstdout, 0x5 ); //COLOR

                        show_module_det(); //Showing module details.

                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR

                        while (cin.get())
                        {
                            cout << "\n" << endl;
                            system("PAUSE");
                            system("CLS");
                            goto adminstafflable;
                        }
                    }

                    else if (choice == 99)
                    {
                        return 0;
                    }

                    else
                    {
                        cout << "Invalid Input" << endl;
                        Sleep(2000);
                        system("CLS");
                        goto adminstafflable;
                    }

                }
    }


    else if(whoareyou == '4')
    {
        string adminpass;
        cout << "Enter Password: "; cin >> adminpass;

        system("CLS");

        string adminpassword;
        ifstream adminpasswordfie("users/admin/admin.dat", ios::binary);
        adminpasswordfie >> adminpassword;

        if (adminpass == adminpassword)
        {
            adminlabel: //LABEL

            SetConsoleTextAttribute( hstdout, 0xA0 ); //COLOR
            cout << "                                                                               "<<endl;
            cout << "                                 Welcome ADMIN                                 " <<endl;
            cout << "                                                                               "<<endl;

            SetConsoleTextAttribute( hstdout, 0xB0 ); //COLOR
            cout << "Note:                                                                          " <<endl;
            cout << "Make Sure You Input Simple Letters When Entering \"Username\".                   "<<endl;
            //COLOR
            FlushConsoleInputBuffer( hstdin );
            // Back to normal color
            SetConsoleTextAttribute( hstdout, csbi.wAttributes );
            //COLOR

            cout << "\n\n" << endl;

            int choice;

            cout << " 1: Register Student" << endl;
            cout << " 2: Register Lecturer" << endl;
            cout << " 3: Register Administrative Staff Member" << endl;
            cout << " 4: View/Enter/Edit Student Details" << endl;
            cout << " 5: View/Enter/Edit Student Marks" << endl;
            cout << " 6: View/Enter/Edit Staff Members Details" << endl;
            cout << " 7: Unregister User" << endl;
            cout << " 8: Search Students" << endl;
            cout << " 9: View Module Details" << endl;
            cout << "10: Edit Module Details" << endl;
            cout << "11: Change ADMIN Password\n" << endl;
            cout << " 0: Logout" <<endl;
            cout << "99: Exit\n" << endl;
            cout << "Your Choice: "; cin >> choice;

            if (choice == 1) //REGISTERING STUDENTS
            {
                string username, password, confirmpassword, student_number;

                cout << "Enter a new username : "; cin >> username;

                transform( username.begin(), username.end(), username.begin(), ptr_fun <int, int> ( tolower ) ); //converting username to lowercasse.

                RegisterUser existstudent;
                bool status = existstudent.IfExistsUser(username, "users/students");

                if(!status)
                {
                    SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                    cout << "\nRegistration Failed! User Already Exists." << endl;



                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR
                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                }
                else
                {

                cout << "Enter a password : "; cin >> password;
                cout << "Confirm password : "; cin >> confirmpassword;


                if (password == confirmpassword)
                {
                        cout << "Enter Student Number : "; cin >> student_number;

                        string reader2 = "users/students\\";
                        reader2 += username;
                        reader2 += ".dat";

                        ofstream userfile(reader2.c_str());
                        userfile << username << endl << password << endl << student_number;
                        userfile.close();

                        system("CLS");

                        SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                        cout << "\nRegistered Successfully! Now User can Login." << endl;


                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR
                        Sleep(2000);
                        system("CLS");
                        goto adminlabel;
                }

                else
                {
                        system("CLS");
                        SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                        cout << "\nPassword Doesn't Match!" << endl;


                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR
                        Sleep(2000);
                        system("CLS");
                        goto adminlabel;
                }


                }
            }


            else if (choice == 2) //REGISTERING lECTURER
            {
                string username, password, confirmpassword, lecturer_number;

                cout << "Enter a new username : "; cin >> username;

                transform( username.begin(), username.end(), username.begin(), ptr_fun <int, int> ( tolower ) ); //converting username to lowercasse.

                RegisterUser existlec;
                bool status = existlec.IfExistsUser(username, "users/lecturers");

                if(!status)
                {
                    SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                    cout << "\nRegistration Failed! User Already Exists." << endl;



                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR
                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                }
                else
                {

                cout << "Enter a password : "; cin >> password;
                cout << "Confirm password : "; cin >> confirmpassword;

                if (password == confirmpassword)
                {
                        cout << "Enter Lecturer Number : "; cin >> lecturer_number;

                        string reader2 = "users/lecturers\\";
                        reader2 += username;
                        reader2 += ".dat";

                        ofstream userfile(reader2.c_str());
                        userfile << username << endl << password << endl << lecturer_number;
                        userfile.close();

                        system("CLS");

                        SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                        cout << "\nRegistered Successfully! Now User can Login." << endl;


                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR
                        Sleep(2000);
                        system("CLS");
                        goto adminlabel;
                }

                else
                {
                        system("CLS");
                        SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                        cout << "\nPassword Doesn't Match!" << endl;


                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR
                        Sleep(2000);
                        system("CLS");
                        goto adminlabel;
                }


                }
            }



            else if (choice == 3) //REGISTERING ADMINISTRATIVE STAFF
            {
                string username, password, confirmpassword, adminstaff_number;

                cout << "Enter a new username : "; cin >> username;

                transform( username.begin(), username.end(), username.begin(), ptr_fun <int, int> ( tolower ) ); //converting username to lowercasse.

                RegisterUser existadminstaff;
                bool status = existadminstaff.IfExistsUser(username, "users/adminstaff");

                if(!status)
                {
                    SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                    cout << "\nRegistration Failed! User Already Exists." << endl;



                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR
                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                }
                else
                {

                cout << "Enter a password : "; cin >> password;
                cout << "Confirm password : "; cin >> confirmpassword;

                if (password == confirmpassword)
                {
                        cout << "Enter Ad.Staff Member Number : "; cin >> adminstaff_number;


                        string reader2 = "users/adminstaff\\";
                        reader2 += username;
                        reader2 += ".dat";

                        ofstream userfile(reader2.c_str());
                        userfile << username << endl << password << endl << adminstaff_number;
                        userfile.close();

                        system("CLS");

                        SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                        cout << "\nRegistered Successfully! Now User can Login." << endl;


                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR
                        Sleep(2000);
                        system("CLS");
                        goto adminlabel;
                }

                else
                {
                        system("CLS");
                        SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                        cout << "\nPassword Doesn't Match!" << endl;


                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR
                        Sleep(2000);
                        system("CLS");
                        goto adminlabel;
                }


                }
            }


            else if (choice == 4) //ENTER/EDIT STUDENT DETAILS
            {
               adminlabel3:

                int swi;
                cout << "\n1.Enter Records \n2.Display Records \n3.Modify Records \n4.Delete Records \n0.Done \n\nYour Choice: ";
                cin >> swi;
                switch (swi)
                {
                case 0:
                    system("CLS");
                    goto adminlabel;
                    break;

                case 1:
                    int j;
                    cout << "\nHow Many Records You Want to Enter: "; cin >> j;
                    for (int i=0; i<j; i++)
                    {
                      write_record();
                    }

                    cout << "Records Entered Successfully" <<endl;
                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                    break;

                case 2:
                    //Display all records
                    cout << "\nList of Records";

                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    display_inline();

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto adminlabel3;
                    break;

                case 3:
                    //Modify record
                    int x;
                    cout << "\nModify Record (Enter Student Number) : "; cin >> x;
                    modify_record(x);
                    Sleep(1000);
                    system("CLS");
                    goto adminlabel;
                    break;

                case 4:
                    //Delete record
                    int y;
                    cout << "Enter Student Number You Want to Delete : "; cin >> y;
                    delete_record(y);
                    cout << "\nRecord Deleted\n";
                    Sleep(1000);
                    system("CLS");
                    goto adminlabel;
                    break;

                default:
                    cout<<"Invalid Input\n";
                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                    break;
                }



            }


            else if (choice == 5) //ENTER/EDIT/DELETE STUDENTS MARKS
            {
               adminlabel4:

                int swi2;
                cout << "\n1.Enter Marks\n2.Display All of the Students Marks\n3.Display All of the Students Details\n4.Modify Marks \n5.Delete Marks \n0.Done \n\nYour Choice: ";
                cin >> swi2;
                switch (swi2)
                {
                case 0:
                    system("CLS");
                    goto adminlabel;
                    break;

                case 1:
                    int jj;
                    cout << "\nHow Many Records You Want to Enter : "; cin >> jj;
                    for (int ii=0; ii<jj; ii++)
                    {
                      write_marks();
                    }

                    cout << "Records Entered Successfully"<<endl;
                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                    break;

                case 2:
                    //Display all records
                    cout << "\nList of Marking Records";

                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    display_marks();

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto adminlabel4;
                    break;

                case 3:
                    //show students details
                    cout << "\nList of Students Details";

                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    display_inline();

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto adminlabel4;
                    break;

                case 4:
                    //Modify record
                    int xx;
                    cout << "\nModify Marks (Enter Student Number) : "; cin >> xx;
                    modify_marks(xx);
                    cout << "\nMarks Modified Successfully" << endl;
                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                    break;

                case 5:
                    //Delete record
                    int yy;
                    cout << "\nDelete Marks (Enter Student Number) : "; cin >> yy;
                    delete_record_marks(yy);
                    cout << "\nMarks Record Deleted\n";
                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                    break;

                default:

                    cout<<"Invalid Input\n";
                    Sleep(2000);
                    system("CLS");

                    goto adminlabel;
                    break;
                }



            }

            else if (choice == 6) //VIEW/EDIT/DELETE STAFF MEMBER DETAILS
            {
               adminlabel_staff:

                int swi3;
                cout << "\n1.Enter Records \n2.View All Records \n3.Modify Records \n4.Delete Records \n0.Done \n\nYour Choice : ";
                cin >> swi3;
                switch (swi3)
                {
                case 0:
                    system("CLS");
                    goto adminlabel;
                    break;

                case 1:
                    int j;
                    cout << "\nHow Many Records You Want to Enter : "; cin >> j;



                    for (int i=0; i<j; i++)
                    {
                       write_record_staff();
                    }

                    cout << "Records Entered Successfully"<<endl;

                    //this will increase the count of staff_count.dat


                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                    break;

                case 2:
                    //Display all records
                    cout << "\nList of Records";

                    SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                    display_inline_staff();

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR

                    goto adminlabel_staff;
                    break;

                case 3:
                    //Modify record
                    int z;
                    cout << "\nModify Record (Enter Staff Member Number) : "; cin >> z;
                    modify_record_staff(z);
                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                    break;

                case 4:
                    //Delete record
                    int ys;
                    cout << "Enter Staff Number You Want to Delete : "; cin >> ys;
                    delete_record_staff(ys);
                    cout << "\nRecord Deleted\n";
                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                    break;

                default:

                    cout<<"Invalid Input\n";
                    Sleep(2000);
                    system("CLS");

                    goto adminlabel;
                    break;
                }



            }

            else if (choice == 7) //UNREGISTER USER
            {
                int del_swi;
                char yes_no;
                string student_uname, lecturer_uname, a_s_member_uname;


                cout << "1.Unregister Student\n2.Unregister Lecturer\n3.Unregister Administrative Staff Member\n0.Done\n\nYour Choice : " ; cin >> del_swi;
                if (del_swi == 0)
                {
                    system("CLS");
                    goto adminlabel;
                }

                else if (del_swi == 1) //unregister student
                {

                    cout << "Enter Username of the Student : "; cin >> student_uname;
                    cout << "Are You Sure You Want to Delete \"" << student_uname << "\" [Y/N] ? " ; cin >> yes_no;

                    transform( student_uname.begin(), student_uname.end(), student_uname.begin(), ptr_fun <int, int> ( tolower ) ); //converting student_uname to lowercasse


                    if (yes_no == 'Y' || yes_no == 'y')
                    {
                        RegisterUser exist_student_delete;
                        bool status_for_delete = exist_student_delete.IfExistsUser(student_uname, "users/students");

                        if(status_for_delete)
                        {
                            SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                            cout << "\nStudent Username Doesn't Exists." << endl;

                            //COLOR
                            FlushConsoleInputBuffer( hstdin );
                            // Back to normal color
                            SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                            //COLOR
                            Sleep(2000);
                            system("CLS");
                            goto adminlabel;
                        }

                        else
                        {
                            string deleteSTUfile = "users/students/";
                            deleteSTUfile += student_uname;
                            deleteSTUfile += ".dat";
                            remove(deleteSTUfile.c_str());

                            SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                            cout << "\nStudent Username Successfully Deleted." << endl;

                            //COLOR
                            FlushConsoleInputBuffer( hstdin );
                            // Back to normal color
                            SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                            //COLOR
                            Sleep(2000);
                            system("CLS");
                            goto adminlabel;
                        }


                    }
                    else if (yes_no == 'N' || yes_no == 'n')
                    {
                        system("CLS");
                        goto adminlabel;
                    }
                    else
                    {
                        cout << "Error Input" << endl;
                        Sleep(2000);
                        system("CLS");
                        goto adminlabel;
                    }

                }

                else if (del_swi == 2) //unregister lecturer
                {

                    cout << "Enter Username of the Lecturer : "; cin >> lecturer_uname;
                    cout << "Are You Sure You Want to Delete \"" << lecturer_uname << "\" [Y/N] ? "; cin >> yes_no;

                    transform( lecturer_uname.begin(), lecturer_uname.end(), lecturer_uname.begin(), ptr_fun <int, int> ( tolower ) ); //converting student_uname to lowercasse


                    if (yes_no == 'Y' || yes_no == 'y')
                    {
                        RegisterUser exist_lecturer_delete;
                        bool status_for_delete = exist_lecturer_delete.IfExistsUser(lecturer_uname, "users/lecturers");

                        if(status_for_delete)
                        {
                            SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                            cout << "\nLecturer Username Doesn't Exists." << endl;

                            //COLOR
                            FlushConsoleInputBuffer( hstdin );
                            // Back to normal color
                            SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                            //COLOR
                            Sleep(2000);
                            system("CLS");
                            goto adminlabel;
                        }

                        else
                        {
                            string deleteLECfile = "users/lecturers/";
                            deleteLECfile += lecturer_uname;
                            deleteLECfile += ".dat";
                            remove(deleteLECfile.c_str());

                            SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                            cout << "\nLecturer Username Successfully Deleted." << endl;

                            //COLOR
                            FlushConsoleInputBuffer( hstdin );
                            // Back to normal color
                            SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                            //COLOR
                            Sleep(2000);
                            system("CLS");
                            goto adminlabel;
                        }


                    }
                    else if (yes_no == 'N' || yes_no == 'n')
                    {
                        system("CLS");
                        goto adminlabel;
                    }
                    else
                    {
                        cout << "Error Input" << endl;
                        Sleep(2000);
                        system("CLS");
                        goto adminlabel;
                    }

                }

                else if (del_swi == 3) //unregister administrative staff
                {

                    cout << "Enter Username of the Administrative Staff Member : "; cin >> a_s_member_uname;
                    cout << "Are You Sure You Want to Delete \"" << a_s_member_uname << "\" [Y/N] ? "; cin >> yes_no;

                    transform( a_s_member_uname.begin(), a_s_member_uname.end(), a_s_member_uname.begin(), ptr_fun <int, int> ( tolower ) ); //converting student_uname to lowercasse


                    if (yes_no == 'Y' || yes_no == 'y')
                    {
                        RegisterUser exist_a_s_member_delete;
                        bool status_for_delete = exist_a_s_member_delete.IfExistsUser(a_s_member_uname, "users/adminstaff");

                        if(status_for_delete)
                        {
                            SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                            cout << "\nAdministrative Staff Member Username Doesn't Exists." << endl;

                            //COLOR
                            FlushConsoleInputBuffer( hstdin );
                            // Back to normal color
                            SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                            //COLOR
                            Sleep(2000);
                            system("CLS");
                            goto adminlabel;
                        }

                        else
                        {
                            string deleteASMfile = "users/adminstaff/";
                            deleteASMfile += a_s_member_uname;
                            deleteASMfile += ".dat";
                            remove(deleteASMfile.c_str());

                            SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                            cout << "\nAdministrative Staff Member Username Successfully Deleted." << endl;

                            //COLOR
                            FlushConsoleInputBuffer( hstdin );
                            // Back to normal color
                            SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                            //COLOR
                            Sleep(2000);
                            system("CLS");
                            goto adminlabel;
                        }


                    }
                    else if (yes_no == 'N' || yes_no == 'n')
                    {
                        system("CLS");
                        goto adminlabel;
                    }
                    else
                    {
                        cout << "Error Input" << endl;
                        Sleep(2000);
                        system("CLS");
                        goto adminlabel;
                    }

                }


                else
                {
                    cout << "Error Input" << endl;
                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                }


            }

            else if (choice == 8) //SEARCH STUDENTS
            {
                int x = search_student();

                if (x == 1)
                {
                    system("CLS");
                    goto adminlabel;
                }
                else if(x == 2)
                {

                    int swi;
                    cout << "\n1.Modify Records \n2.Delete Records \n0.Done \n\nYour Choice: ";
                    cin >> swi;
                    switch (swi)
                    {
                    case 0:
                        system("CLS");
                        goto adminlabel;
                        break;

                    case 1:
                        //Modify record
                        int x;
                        cout << "\nModify Record (Enter Student Number) : "; cin >> x;
                        modify_record(x);
                        Sleep(1000);
                        system("CLS");
                        goto adminlabel;
                        break;

                    case 2:
                        //Delete record
                        int y;
                        cout << "Enter Student Number to Delete : "; cin >> y;
                        delete_record(y);
                        cout << "\nRecord Deleted\n";
                        Sleep(1000);
                        system("CLS");
                        goto adminlabel;
                        break;

                    default:
                        cout<<"Invalid Input\n";
                        Sleep(2000);
                        system("CLS");
                        goto adminlabel;
                        break;
                    }
                }
            }

            else if (choice == 9) //VIEW MODULE DETAILS
            {
                cout << "\n\n\n" << endl;
                SetConsoleTextAttribute( hstdout, 0x5 ); //COLOR

                show_module_det(); //Showing module details.

                //COLOR
                FlushConsoleInputBuffer( hstdin );
                // Back to normal color
                SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                //COLOR

                while (cin.get())
                {
                    cout << "\n" << endl;
                    system("PAUSE");
                    system("CLS");
                    goto adminlabel;
                }
            }

            else if (choice == 10) //EDIT MODULE DETAILS
            {
                char edit;
                cout << "\nAre You Sure You Want to Edit Module Details [Y/N] ? "; cin >> edit;
                if (edit == 'Y' || edit == 'y')
                {
                    cout << "\n\n\n" << endl;
                    SetConsoleTextAttribute( hstdout, 0x5 ); //COLOR

                    edit_module_det(); //Editing module details.

                    //COLOR
                    FlushConsoleInputBuffer( hstdin );
                    // Back to normal color
                    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                    //COLOR


                    cout << "\nSuccessfully Changed the Content" << endl;
                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                }
                else if (edit == 'N' || edit == 'n')
                {
                    system("CLS");
                    goto adminlabel;
                }
                else
                {
                    cout << "\nInvalid Input" << endl;
                    Sleep(2000);
                    system("CLR");
                    goto adminlabel;
                }

            }

            else if (choice == 11) //CHANGE ADMIN PASSWORD
            {
                string oldadminpassword, oldadminpasswordfromfile, newadminpassword, confirmnewadminpassword;

                cout << "Enter old password : " ; cin >> oldadminpassword;
                ifstream oldadminpasswordfile("users/admin/admin.dat", ios::binary);
                oldadminpasswordfile >> oldadminpasswordfromfile;

                if (oldadminpassword == oldadminpasswordfromfile)
                {
                    cout << "Enter new password : " ; cin >> newadminpassword;
                    cout << "Confirm password : " ; cin >> confirmnewadminpassword;

                    if (newadminpassword == confirmnewadminpassword)
                    {
                        ofstream writenewadminpasswordfile("users/admin/admin.dat", ios::out | ios::binary);
                        writenewadminpasswordfile << newadminpassword;

                        system("CLS");
                        SetConsoleTextAttribute( hstdout, 0xA ); //COLOR

                        cout << "Password changed successfully!" << endl;

                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR
                        Sleep(2000);
                        system("CLS");
                        goto adminlabel;
                    }
                    else
                    {
                        system("CLS");
                        SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

                        cout << "Couldn't confirm the password." << endl;

                        //COLOR
                        FlushConsoleInputBuffer( hstdin );
                        // Back to normal color
                        SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                        //COLOR
                        Sleep(2000);
                        system("CLS");
                        goto adminlabel;
                    }
                }
                else
                {
                    system("CLS");
                    SetConsoleTextAttribute( hstdout, 0xC ); //COLOR
                    cout << "Incorrect Password!" << endl;

                     //COLOR
                     FlushConsoleInputBuffer( hstdin );
                     // Back to normal color
                     SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                     //COLOR

                    Sleep(2000);
                    system("CLS");
                    goto adminlabel;
                }


            }

            else if (choice == 99)
            {
                return 0;
            }

            else if (choice == 0)
            {
                system("CLS");
                goto begininglabel;
            }

            else
            {

                system("CLS");
                SetConsoleTextAttribute( hstdout, 0xC ); //COLOR
                cout << "ERROR!" << endl;

                 //COLOR
                 FlushConsoleInputBuffer( hstdin );
                 // Back to normal color
                 SetConsoleTextAttribute( hstdout, csbi.wAttributes );
                 //COLOR

                Sleep(2000);
                system("CLS");
                goto adminlabel;
            }

        }
        else
        {
        system("CLS");
        SetConsoleTextAttribute( hstdout, 0xC ); //COLOR
        cout << "\nPassword You Entered is Incorrect!" << endl;

         //COLOR
         FlushConsoleInputBuffer( hstdin );
         // Back to normal color
         SetConsoleTextAttribute( hstdout, csbi.wAttributes );
         //COLOR

        Sleep(2000);
        system("CLS");
        goto begininglabel;
        }

    }

    else if (whoareyou == '0')
    {
        return 0;
    }

    else
    {

        system("CLS");

        SetConsoleTextAttribute( hstdout, 0xC ); //COLOR

        cout << "\nError Input!" << endl;

         //COLOR
         FlushConsoleInputBuffer( hstdin );
         // Back to normal color
         SetConsoleTextAttribute( hstdout, csbi.wAttributes );
         //COLOR

        Sleep(2000);
        system("CLS");
        goto begininglabel;

    }

}
///____________________________________END OF THE PROGRAMME_____________________________________///

///SAMINTHA KAVEESH     BSC-UCD-CSC-15.1-088
///CHULAN KOTUDURAGE    BSC-UCD-CSC-15.1-063
///KALANA WIJESEKARA    BSC-UCD-CSC-15.1-091
///SANDUN NIMSARA       BSC-UGC-MIS-15.1-012
