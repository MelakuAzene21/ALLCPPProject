
#include <string.h>
#include <iostream>
#include <stdlib.h> //for exit function
#include<iomanip>
using namespace std;
struct student
{
    string first_name;
    string last_name;
    string course_id;
    string adm_password;
    int st_years;
    char gender;
    int roll_number;
    int counter = 0;
    string st_id;

    int elec_mark, alg_mark, ari_mark, adb_mark, net_mark, anet_mark, ore_mark,
        dis_mark, cbr_mark;
    /*
       elec_mark...> electronics  subject mark
       alg_mark.....>algorithm  subject mark
       adb_mark...>advanced database mark
       ore_mark....>object oruented mark
     */
} admin, F_students[110], S_students[110], T_students[110], Fo_students[110];
/*F_students[110],....>first  year student
   T_students[110]...>third  year student
 */

int F_number_of_students = 0;
int S_number_of_students = 0;
int T_number_of_students = 0;
int Fo_number_of_students = 0;
/*
   F_number_of_students....>number of first year student
 */
// function    declaration
void record_data();
void main_page();
void st_year();
void show_data();
void access_page();

// function definition to store student data
void addStudentDetails()
{
    int choice;
    system("color 9");
option:
    while (choice != 7)
    {
        system("cls");
        st_year();
        cout << "\n\t5.back to record page" << endl;
        cout << "\n\t6.back to main page" << endl;
        cout << "\n\t7.exit" << endl;
        cout << "\n\nEnter  your choice\n";

        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\n\tEnter the Roll Number of the student :";
            int F_roll_no; // first year student roll number
        first:
            cin >> F_roll_no;

            for (int i = 0; i < F_number_of_students; i++)
            {
                if (F_students[i].roll_number == F_roll_no)
                {
                    cout << " Student with the given roll number already exists in the database\n";
                    return;
                }
            }
            cout << "\n\t enter the years of student               :";
            cin >> F_students[F_number_of_students].st_years;
            cout << "\n\tEnter the first name of the student      :";
            cin >> F_students[F_number_of_students].first_name;
            cout << "\n\tEnter the last name of the student       :";
            cin >> F_students[F_number_of_students].last_name;
            cout << "\n\tenter  your id                           :";
            cin >> F_students[F_number_of_students].st_id;
            cout << "\n\tenter gender                               :";
            cin >> F_students[F_number_of_students].gender;
            cout << "\n\tenter  netrworking result out of 100     : ";
            cin >> F_students[F_number_of_students].net_mark;
            cout << "\n\tenter  electronics result out of 100      :";
            cin >> F_students[F_number_of_students].elec_mark;
            F_students[F_number_of_students].roll_number = F_roll_no;
            F_number_of_students++;
            break;
        }
        case 2:
        {
            cout << "\n\tEnter the Roll Number of the student :";
            int S_roll_no;
        again:
            cin >> S_roll_no;

            for (int i = 0; i < S_number_of_students; i++)
            {
                if (S_students[i].roll_number == S_roll_no)
                {
                    cout << " Student with the given roll number already exists in the database\n";
                    return;
                }
            }
            cout << "\n\tenter the years of student             :";
            cin >> F_students[S_number_of_students].st_years;
            cout << "\n\tEnter the first name of the student    :";
            cin >> S_students[S_number_of_students].first_name;
            cout << "\n\tEnter the last name of the student     :";
            cin >> S_students[S_number_of_students].last_name;
            cout << "\n\tenter gender                           :";
            cin >> S_students[F_number_of_students].gender;
            cout << "\n\tenter  your id                         :";
            cin >> S_students[S_number_of_students].st_id;
            cout << "\n\tenter  algorithm result out of 100     : ";
            cin >> S_students[S_number_of_students].alg_mark;
            cout << "\n\tenter object oriented result out of 100 :";
            cin >> S_students[S_number_of_students].ore_mark;
            S_students[F_number_of_students].roll_number = S_roll_no;
            S_number_of_students++;
            break;
        }
        case 3:
        {
            int T_roll_no;
            cout << "\n\tEnter the Roll Number of the student :";
        third:
            cin >> T_roll_no;

            for (int i = 0; i < T_number_of_students; i++)
            {
                if (T_students[i].roll_number == T_roll_no)
                {
                    cout << " Student with the given roll number already exists in the database\n";
                    return;
                }
            }
            cout << "\n\tenter the years of student             :";
            cin >> T_students[T_number_of_students].st_years;
            cout << "\n\tEnter the first name of the student    :";
            cin >> T_students[T_number_of_students].first_name;
            cout << "\n\tEnter the last name of the student     :";
            cin >> T_students[T_number_of_students].last_name;
            cout << "\n\tenter gender                           :";
            cin >> T_students[F_number_of_students].gender;
            cout << "\n\tenter  your id                         :";
            cin >> T_students[T_number_of_students].st_id;
            cout << "\n\tenter  discrete result out of 100      : ";
            cin >> T_students[T_number_of_students].dis_mark;
            cout << "\n\tenter  database result out of 100      :";
            cin >> T_students[T_number_of_students].adb_mark;
            T_students[S_number_of_students].roll_number = T_roll_no;
            T_number_of_students++;
            break;
        }
        case 4:
        {
            cout << "\n\tEnter the Roll Number of the student :";
            int Fo_roll_no;
        four:
            cin >> Fo_roll_no;

            for (int i = 0; i < Fo_number_of_students; i++)
            {
                if (Fo_students[i].roll_number == Fo_roll_no)
                {
                    cout << " Student with the given roll number already exists in the database\n";
                    return;
                }
            }
            cout << "\n\tenter the years of student              :";
            cin >> Fo_students[Fo_number_of_students].st_years;
            cout << "\n\tEnter the first name of the student     :";
            cin >> Fo_students[Fo_number_of_students].first_name;
            cout << "\n\tEnter the last name of the student      :";
            cin >> Fo_students[Fo_number_of_students].last_name;
            cout << "\n\tenter gender    (M/F)                   :";
            cin >> Fo_students[F_number_of_students].gender;
            cout << "\n\tenter  your id                          :";
            cin >> Fo_students[Fo_number_of_students].st_id;
            cout << "\n\tenter  advanced netrworking result out of 100 : ";
            cin >> Fo_students[Fo_number_of_students].anet_mark;
            cout << "\n\tenter artificial intelligence result out of 100 :";
            cin >> Fo_students[Fo_number_of_students].ari_mark;
            cout << "\n\tcyber security result out of 100        :";
            cin >> Fo_students[Fo_number_of_students].cbr_mark;
            Fo_students[Fo_number_of_students].roll_number = Fo_roll_no;
            Fo_number_of_students++;
            break;
        }
        case 5:
            record_data();
            break;
        case 6:
            main_page();
            break;
        case 7:
            exit(0);
        default:
            cout << "\n\t\tinvalid  option ,ty again(1_7)" << endl;
            goto option;
        }
    }
}
// defining function to  accesscc student  by their roll number
void findStudentByRollNumber()
{
    int choice;
    string s_id; // s_id....>student id
option:
while(true)
{
    st_year(); // function call
    cout << "====enter  your choice===" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int F_roll_no; // first year roll number
        cout << "Enter the Roll Number of the student\n";
        cin >> F_roll_no;
        bool correct = false;
        for (int i = 0; i < F_number_of_students; i++)
        {
            if (F_roll_no == F_students[i].roll_number)
            {
                cout << "enter  your passwor or id   : ";
                cin >> s_id;
                if (F_students[i].st_id == s_id)
                {
                    cout << "\n\n\taccess authorized \n\n" << endl;
                }
                else
                    break;
                correct = true;
                cout << " Student roll no.    : " << F_roll_no << "  data\n\n";
                cout << "\n\t First name          :" << F_students[i].first_name << "\n";
                cout << "\n\tLast name            : " << F_students[i].last_name << "\n";
                cout << "\n\tstudent year         :" << F_students[i].st_years << endl;
                cout << "\n\tgender               :" << F_students[i].gender << "\n";
                cout << "\n\tstudent id           :" << F_students[i].st_id << "\n";
                cout << "\n\tnetworking  result   :" << F_students[i].net_mark << "\n";
                cout << "\n\telectronics  result  :" << F_students[i].elec_mark << "\n";
                break;
            }
            if (!correct)
              {  cout << "no such student with the   given roll number\n";
                show_data();
              }
        }
        break;
    }
    case 2:
    {
        int S_roll_no;
        cout << "Enter the Roll Number of the student\n";
        cin >> S_roll_no;
        bool correct = false;
        for (int i = 0; i < S_number_of_students; i++)
        {
            if (S_roll_no == S_students[i].roll_number)
            {
                cout << "enter password or id  :";
                cin >> s_id;
                if (S_students[i].st_id == s_id)
                {
                    cout << "\n\n\taccess authorized \n"
                         << endl;
                }
                else
                {
                    break;
                }

                correct = true;
                cout << " Student roll no   : " << S_roll_no << "  data\n\n";
                cout << "\n\tThe First name        :" << S_students[i].first_name << "\n";
                cout << "\n\tThe Last name         :" << S_students[i].last_name << "\n";
                cout << "\n\tstudent year          :" << S_students[i].st_years << endl;
                cout << "\n\tgender                :" << S_students[i].gender << "\n";
                cout << "\n\tstudent id            :" << S_students[i].st_id << "\n";
                cout << "\n\talgorithm  result     :" << S_students[i].alg_mark << "\n";
                cout << "\n\tobject oriented result:" << S_students[i].ore_mark << "\n";
                break;
            }
            if (!correct)
               { cout << "no such student with the   given roll number\n";
                 show_data();
               }
        }
    }
    case 3:
    {
        int T_roll_no;
        cout << "Enter the Roll Number of the student\n";
        cin >> T_roll_no;
        bool correct = false;
        for (int i = 0; i < T_number_of_students; i++)
        {
            if (T_roll_no == T_students[i].roll_number)
            {
                cin >> s_id;
                if (T_students[i].st_id == s_id)
                {
                    cout << "\n\n\taccess authorized \n"
                         << endl;
                }
                else
                    break;

                correct = true;
                cout << " Student roll no. " << T_roll_no << " data\n";

                cout << "\n\tFirst name    :" << T_students[i].first_name << endl;
                cout << "\n\tLast name     :" << T_students[i].last_name << endl;
                cout << "\n\tstudent year  :" << T_students[i].st_years << endl;
                cout << "\n\tgender        :" << T_students[i].gender << "\n";
                cout << "\n\tstudent id    :" << T_students[i].st_id << endl;
                cout << "\n\tdiscrete      :" << T_students[i].dis_mark << endl;
                cout << "\n\tdatabase      :" << T_students[i].adb_mark << endl;
                break;
            }
            if (!correct)
               { cout << "no such student with the  given roll number\n";
                 show_data();
               }
        }
    }
    case 4:
    {
        int Fo_roll_no;
        cout << "Enter the Roll Number of the student\n";
        cin >> Fo_roll_no;
        bool correct = false;
        for (int i = 0; i < Fo_number_of_students; i++)
        {
            if (Fo_roll_no == Fo_students[i].roll_number)
            {
                cout << "Enter your password or ID  :";
                cin >> s_id;
                if (Fo_students[i].st_id == s_id)
                {
                    cout << "\n\n\taccess authorized \n"
                         << endl;
                }
                else
                    break;
                correct = true;
                cout << " Student roll no. " << Fo_roll_no << "  data\n";

                cout << "\n\tFirst name       :" << Fo_students[i].first_name << "\n";
                cout << "\n\t Last name       :" << Fo_students[i].last_name << "\n";
                cout << "\n\tstudent year     :" << Fo_students[i].st_years << "\n";
                cout << "\n\tgender           :" << Fo_students[i].gender << "\n";
                cout << "\n\tstudent id       :" << Fo_students[i].st_id << "\n";
                cout << "\n\tintelligence     :" << Fo_students[i].ari_mark << "\n";
                cout << "\n\tetworking        :" << Fo_students[i].anet_mark << "\n";
                cout << "\n\tcybersecurity    :" << Fo_students[i].cbr_mark << "\n";
                break;
            }
            if (!correct)
               { cout << "no such student with the given roll number\n";
                   show_data();
               }
        }
    }
    case 5:
        record_data();
        break;
    case 6:
        main_page();
    default:
        cout << "no such year's student";
        goto option;
        break;
    }
  }
}
// function definituon to access student  by ftheir first name
void findStudentByFirstName()
{
    int select;
    string firstName;
    st_year();
    cin >> select;
    switch (select)
    {
    case 1:
    {
        cout << "Enter the first name of the student\n";
        cin >> firstName;
        bool found = false;

        for (int i = 0; i < F_number_of_students; i++)
        {
            if (firstName == F_students[i].first_name)
            {
                found = true;

                cout << "\tThe Students Details are\n";
                cout << "\n\t First name          :" << F_students[i].first_name << "\n";
                cout << "\n\tLast name            : " << F_students[i].last_name << "\n";
                cout << "\n\tstudent year         :" << F_students[i].st_years << endl;
                cout << "\n\tgender               :" << F_students[i].gender << "\n";
                cout << "\n\t student id          :" << F_students[i].st_id << "\n";
                cout << "\n\tnetworking  result   :" << F_students[i].net_mark << "\n";
                cout << "\n\telectronics  result  :" << F_students[i].elec_mark << "\n";
            }
        }

        if (!found)
            cout << "no such student with the given first name\n";
    }
    case 2:
    {
        cout << "Enter the first name of the student\n";
        cin >> firstName;
        bool found = false;
        for (int i = 0; i < S_number_of_students; i++)
        {
            if (firstName == S_students[i].first_name)
            {
                found = true;
                cout << "\tThe Students Details are\n";

                cout << "\n\tThe First name        :" << S_students[i].first_name << "\n";
                cout << "\n\tThe Last name         :" << S_students[i].last_name << "\n";
                cout << "\n\tstudent year          :" << S_students[i].st_years << endl;
                cout << "\n\tgender                :" << S_students[i].gender << "\n";
                cout << "\n\tstudent id            :" << S_students[i].st_id << "\n";
                cout << "\n\talgorithm  result     :" << S_students[i].alg_mark << "\n";
                cout << "\n\tobject oriented result:" << S_students[i].ore_mark << "\n";
            }
        }

        if (!found)
            cout << "no such student with the given first name\n";
    }
    case 3:
    {
        cout << "Enter the first name of the student\n";
        cin >> firstName;

        bool found = false;

        for (int i = 0; i < T_number_of_students; i++)
        {
            if (firstName == T_students[i].first_name)
            {
                found = true;
                cout << "The Students Details are\n";

                cout << "\n\tFirst name    :" << T_students[i].first_name << endl;
                cout << "\n\tLast name     :" << T_students[i].last_name << endl;
                cout << "\n\tstudent year  :" << T_students[i].st_years << endl;
                cout << "\n\tgender        :" << T_students[i].gender << endl;
                cout << "\n\tstudent id    :" << T_students[i].st_id << endl;
                cout << "\n\tdiscrete      :" << T_students[i].dis_mark << endl;
                cout << "\n\tdatabase      :" << T_students[i].adb_mark << endl;
            }
        }
        if (!found)
            cout << "no such student with the given first name\n";
    }
    case 4:
    {
        cout << "Enter the first name of the student\n";
        cin >> firstName;

        bool found = false;

        for (int i = 0; i < Fo_number_of_students; i++)
        {
            if (firstName == Fo_students[i].first_name)
            {
                found = true;
                cout << "The Students Details are\n";

                cout << "\nFirst name       :" << Fo_students[i].first_name << "\n";
                cout << "\n Last name       :" << Fo_students[i].last_name << "\n";
                cout << "\n\tstudent year   :" << Fo_students[i].st_years << "\n";
                cout << "\n\tgender         :" << Fo_students[i].gender << "\n";
                cout << "\n\tstudent id     :" << Fo_students[i].st_id << "\n";
                cout << "\n\aintelligence   :" << Fo_students[i].ari_mark << "\n";
                cout << "\n\networking      :" << Fo_students[i].anet_mark << "\n";
                cout << "\n\tcybersecurity  :" << Fo_students[i].cbr_mark << "\n";
            }
        }
        if (!found)
            cout << "no such student with the given first name\n";
    }
    case 5:
        show_data();
        break;
    case 6:
        main_page();
        break;
    }
}
// function definition to display total  number of student in  each year
void findTotalStudents()
{
    int select;
    while (true)
    {
        st_year(); // function call
        cout << "\n\t5. back to show page \n";
        cout << "\n\t6.back  to main page\n";
        cin >> select;
        switch (select)
        {
        case 1:
            cout << "The total number Students are " << F_number_of_students << "\n";
            break;
        case 2:
            cout << "The total number Students are " << S_number_of_students << "\n";
            break;
        case 3:
            cout << "The total number Students are " << T_number_of_students << "\n";
            break;
        case 4:
            cout << "The total number Students are " << Fo_number_of_students << "\n";
            break;
        case 5:
            show_data();
            break;
        case 6:
            main_page();
            break;
        }
    }
}

void deleteStudentByRollNumber()
{
    int select;
    st_year();
    cin >> select;
    switch (select)
    {
    case 1:
    {
        int F_roll_no;
        cout << "Enter the Roll Number that you want to delete\n";
        cin >> F_roll_no;

        bool found = false;
        for (int i = 0; i < F_number_of_students; i++)
        {
            if (F_roll_no == F_students[i].roll_number)
            {
                found = true;
                for (int j = i; j < 109; j++)
                    F_students[j] = F_students[j + 1];
                F_number_of_students--;
            }
        }
        if (found)
        {
            cout << "The Roll Number is removed Successfully\n";
            record_data();
        }
        else
        {
            cout << "Roll number not found in the database ,try again\n";
            record_data();
        }
    }
    case 2:
    {
        int S_roll_no;
        cout << "Enter the Roll Number that you want to delete\n";
        cin >> S_roll_no;
        bool found = false;
        for (int i = 0; i < F_number_of_students; i++)
        {
            if (S_roll_no == S_students[i].roll_number)
            {
                found = true;
                for (int j = i; j < 109; j++)
                    S_students[j] = S_students[j + 1];
                S_number_of_students--;
            }
        }

        if (found)
        {
            cout << "The Roll Number is removed Successfully\n";
            record_data();
        }
        else
        {
            cout << "Roll number not found in the database ,try again\n";
            record_data();
        }
    }
    case 3:
    {
        int T_roll_no;
        cout << "Enter the Roll Number that you want to delete\n";
        cin >> T_roll_no;

        bool found = false;
        for (int i = 0; i < T_number_of_students; i++)
        {
            if (T_roll_no == T_students[i].roll_number)
            {
                found = true;
                for (int j = i; j < 109; j++)
                    T_students[j] = T_students[j + 1];
                T_number_of_students--;
            }
        }

        if (found)
        {
            cout << "The Roll Number is removed Successfully\n";
            record_data();
        }
        else
        {
            cout << "Roll number not found in the database,  try again\n";
            record_data();
        }
    }
    case 4:
    {
        int Fo_roll_no;
        cout << "Enter the Roll Number that you want to delete\n";
        cin >> Fo_roll_no;

        bool found = false;
        for (int i = 0; i < Fo_number_of_students; i++)
        {
            if (Fo_roll_no == Fo_students[i].roll_number)
            {
                found = true;
                for (int j = i; j < 109; j++)
                    Fo_students[j] = Fo_students[j + 1];
                Fo_number_of_students--;
            }
        }
        if (found)
        {
            cout << "The Roll Number is removed Successfully\n";
            record_data();
        }
        else
        {
            cout << "Roll number not found in the database, try again\n";
            record_data();
        }
    }
    }
}
void update_optiin()
{
    cout << "1.  first name\n"
            "2. last name\n"
            "3. roll number  and gender\n"
            "4.password or id  \n"
            "5. each subject  result \n";
}

void updateStudentDetails()
{
    int select;
    st_year();
    cout << "enter your choice :";
    cin >> select;
    switch (select)
    {
    case 1:
    {
        cout << "Enter the roll number whose details you want to update\n";
        int F_roll_no;
        cin >> F_roll_no;
        bool found = false;
        for (int i = 0; i < F_number_of_students; i++)
        {
            if (F_students[i].roll_number == F_roll_no)
            {
                found = true;
                update_optiin();
                int choice;
                cin >> choice;
                switch (choice)
                {
                case 1:
                    cout << "\nEnter the new first name   :";
                    cin >> F_students[i].first_name;
                    break;
                case 2:
                    cout << "\nEnter the new last name    :";
                    cin >> F_students[i].last_name;
                    break;
                case 3:
                    cout << "\nEnter the new roll number   :";
                    cin >> F_students[i].roll_number;
                    cout << "\nenter  new gender           :";
                    cin >> F_students[i].gender;
                    break;
                case 4:
                    cout << "\n enter new password or id     :";
                    cin >> F_students[i].st_id;
                    break;
                case 5:
                    cout << "\nEnter the new economics   :";
                    cin >> F_students[i].net_mark;
                    cout << "\nEnter the new electronics result :";
                    cin >> F_students[i].elec_mark;
                    break;
                }
            }
        }

        if (found)
        {
            cout << "Details updated successfully.\n";
            record_data();
        }
        else
        {
            cout << "Student not found in the record, try again\n";
            record_data();
        }
    }
    case 2:
    {
        cout << "Enter the roll number whose details you want to update\n";
        int S_roll_no;
        cin >> S_roll_no;

        bool found = false;
        for (int i = 0; i < S_number_of_students; i++)
        {
            if (S_students[i].roll_number == S_roll_no)
            {

                found = true;
                update_optiin();
                int choice;
                cin >> choice;
                switch (choice)
                {
                case 1:
                    cout << "\nEnter the new first name   :";
                    cin >> S_students[i].first_name;
                    break;
                case 2:
                    cout << "\nEnter the new last name   :";
                    cin >> S_students[i].last_name;
                    break;
                case 3:
                    cout << "\nEnter the new roll number   :";
                    cin >> S_students[i].roll_number;
                    cout << "\n enter new gender             :";
                    cin >> S_students[i].gender;
                    break;
                case 4:
                    cout << "\nenter new password or id      :";
                    cin >> S_students[i].st_id;
                    break;
                case 5:
                    cout << "\nEnter the new algorithm     :";
                    cin >> S_students[i].alg_mark;
                    cout << "\nEnter the new object oriented :";
                    cin >> S_students[i].ore_mark;
                    break;
                }
            }
        }

        if (found)
        {
            cout << "Details updated successfully.\n";
            record_data();
        }
        else
        {
            cout << "Student not found in the record, try again\n";
            record_data();
        }
    }
    case 3:
    {
        cout << "Enter the roll number whose details you want to update\n";
        int T_roll_no;
        cin >> T_roll_no;
        bool found = false;
        for (int i = 0; i < T_number_of_students; i++)
        {
            if (T_students[i].roll_number == T_roll_no)
            {

                found = true;
                update_optiin();
                // update_optiin.....>option list function
                int choice;
                cin >> choice;
                switch (choice)
                {
                case 1:
                    cout << "\nEnter the new first name    :";
                    cin >> T_students[i].first_name;
                    break;

                case 2:
                    cout << "\nEnter the new last name     :";
                    cin >> T_students[i].last_name;
                    break;
                case 3:
                    cout << "\nEnter the new roll number    :";
                    cin >> T_students[i].roll_number;
                    cout << "\nenter new gender               :";
                    cin >> T_students[i].gender;
                    break;
                case 4:
                    cout << "\nenter new password or id           :";
                    cin >> T_students[i].st_id;
                    break;
                case 5:
                    cout << "Enter new discrete result  :";
                    cin >> T_students[i].dis_mark;
                    cout << "Enter the new database     :";
                    cin >> T_students[i].adb_mark;
                    break;
                }
            }
        }

        if (found)
        {
            cout << "Details updated successfully.\n";
            record_data();
        }
        else
        {
            cout << "Student not found in the record,  try again\n";
            record_data();
        }
        break;
    }
    case 4:
    {
        cout << "Enter the roll number whose details you want to update\n";
        int Fo_roll_no;
        cin >> Fo_roll_no;

        bool found = false;
        for (int i = 0; i < Fo_number_of_students; i++)
        {
            if (Fo_students[i].roll_number == Fo_roll_no)
            {

                found = true;
                update_optiin();
                int choice;
                cin >> choice;
                switch (choice)
                {
                case 1:
                    cout << "\nEnter the new first name   :";
                    cin >> Fo_students[i].first_name;
                    break;

                case 2:
                    cout << "\nEnter the new last name     :";
                    cin >> Fo_students[i].last_name;
                    break;

                case 3:
                    cout << "\nEnter the new roll number    :";
                    cin >> Fo_students[i].roll_number;
                    cout << "\nenter new gender               :";
                    cin >> Fo_students[i].gender;
                    break;
                case 4:
                    cout << "\nenter new password or id    :";
                    cin >> Fo_students[i].st_id;
                    break;
                case 5:
                    cout << "\nEnter the new advanced net result number  :";
                    cin >> Fo_students[i].anet_mark;
                    cout << "\nEnter the new cyber result                :";
                    cin >> Fo_students[i].cbr_mark;
                    cout << "\nEnter the new artificial  result          :";
                    cin >> Fo_students[i].ari_mark;
                    break;
                }
            }
        }

        if (found)
        {
            cout << "Details updated successfully.\n";
            record_data();
        }
        else
        {
            cout << "Student not found in the record,try again\n";
            record_data();
        }
        break;
    }
    case 5:
        record_data();
        break;
    case 6:
        exit(0);
    default:
        cout << "no  such year's  student" << endl;
    }
}

void record_data()
{
    int choice;
    system("color E");
    system("cls");
    while (true)
    {
        cout << "\n\n\t***STUDENT RECORD MANAGEMENT***" << endl;
        cout << "\n\t1.Add new Student to the database\n"
             << endl;
        cout << "\n\t2. Delete the Student by Roll Number\n"
             << endl;
        cout << "\n\t3. Update Student Details by Roll Number\n"
             << endl;
        cout << "\n\t4.back to menu" << endl;
        cout << "\n\t5. Exit the program\n"
             << endl;
        cout << "Enter your choice\n"
             << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudentDetails();
            break;
        case 2:
            deleteStudentByRollNumber();
            break;
        case 3:
            updateStudentDetails();
            break;
        case 4:
            main_page();
            break;
        case 5:
            exit(0);
            break;
        }
    }
}

void all_in_tabular(){
        int choice;
        st_year();
        cout<<"5.exit"<<endl;
        cout<<"Enter your choice "<<endl;
        cin>>choice;
  switch(choice)
    {
        case 1:
    cout << left<< setw(10) << "f_name"<< left << setw(5)  << "l_name"  << left<< setw(5)<<"gender" << left<< setw(8)  <<" id "<< left<< setw(5)<< "Year"
      <<left<<setw(8)<<"network"<<left<<setw(8)<<"economics"<<endl;

   for (int i = 0; i < F_number_of_students; i++)
    {
        cout
            << left << setw(10) << F_students[i].first_name
            << left<< setw(5)<<F_students[i].last_name
            << left<< setw(5)<< F_students[i].gender
            <<left << setw(5)<<F_students[i].st_id
            <<left << setw(5)<<F_students[i].st_years
            <<left << setw(5)<<F_students[i].net_mark
            <<left<< setw(5)<<F_students[i].elec_mark
            << endl;

    }
    break;
    case 2:
cout << left<< setw(10) << "f_name"<< left << setw(5)  << "l_name"  << left<< setw(5)<<"gender" << left<< setw(8)  <<" id "<< left<< setw(5)<< "Year"<<
      left<<setw(8)<<"network"<<left<<setw(8)<<"economics"<<endl;

   for (int i = 0; i < S_number_of_students; i++)
    {
        cout
            << left << setw(10) << S_students[i].first_name
            << left<< setw(5)<<S_students[i].last_name
            << left<< setw(5)<<S_students[i].gender
            <<left << setw(5)<<S_students[i].st_id
            <<left << setw(5)<<S_students[i].st_years
            <<left << setw(5)<<S_students[i].net_mark
            <<left<< setw(5)<<S_students[i].elec_mark
            << endl;

    }
    break;
  case 3:
cout << left<< setw(10) << "f_name"<< left << setw(5)  << "l_name"  << left<< setw(5)<<"gender" << left<< setw(8)  <<" id "<< left<< setw(5)<< "Year"<<
      left<<setw(8)<<"network"<<left<<setw(8)<<"economics"<<endl;

   for (int i = 0; i < F_number_of_students; i++)
    {
        cout
            << left << setw(10)<< T_students[i].first_name
            << left<< setw(5)<<T_students[i].last_name
            << left<< setw(5)<<T_students[i].gender
            <<left << setw(5)<<T_students[i].st_id
            <<left << setw(5)<<T_students[i].st_years
            <<left << setw(5)<<T_students[i].net_mark
            <<left<< setw(5)<<T_students[i].elec_mark
            << endl;

    }
    break;
  case 4:
cout << left<< setw(10) << "f_name"<< left << setw(5)  << "l_name"  << left<< setw(5)<<"gender" << left<< setw(8)  <<" id "<< left<< setw(5)<< "Year"<<
      left<<setw(8)<<"network"<<left<<setw(8)<<"economics"<<endl;

   for (int i = 0; i < F_number_of_students; i++)
    {
        cout
            << left << setw(10)<<Fo_students[i].first_name
            << left<< setw(5)<<Fo_students[i].last_name
            << left<< setw(5)<< Fo_students[i].gender
            <<left << setw(5)<<Fo_students[i].st_id
            <<left << setw(5)<<Fo_students[i].st_years
            <<left << setw(5)<<Fo_students[i].net_mark
            <<left<< setw(5)<<Fo_students[i].elec_mark
            << endl;

    }
    break;
     default:exit(0);
    }
   }
void show_data()
{
    int choice;
    while (choice != 7)
    {
        system("color 9");
        system("cls");
        cout << "\n\t\t****STUDENT DATA SEARCH****" << endl;
        system("color E");
        cout << "\n\t1. Search Student by Roll Number\n"
             << endl;
        cout << "\n\t2. Search Student by First Name\n"
             << endl;
        cout << "\n\t3. Count Total number of Students\n"
             << endl;
        cout << "\n\t4.all  student in tabular form" << endl;
        cout << "\n\t5. summary of student\n"
             << endl;
        cout << "\n\t6.back to menu" << endl;
        cout << "\n\t7.exit" << endl;
        system("color 9");
        cout << " enter your option  :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            findStudentByRollNumber();
            break;
        case 2:
            findStudentByFirstName();
            break;
        case 3:
            findTotalStudents();
            break;
        case 4: all_in_tabular();break;
        case 5:
            cout << "coming soon";
            break;
        case 6:
            main_page();
            break;
        case 7:
            exit(0);
            break;
        }
    }
}

void main_page()
{
    int choice;
    int count = 0;
    while (true)
    {
        system("cls");
        cout << "\n\t****MAIN MENU PAGE****" << endl;
        cout << "\n\t1.Record student data" << endl;
        cout << "\n\t2.show student data" << endl;
        cout << "\n\t3.access data" << endl;
        cout << "\n\t4.exit " << endl;
        cout << "please enter your choice(1-3)" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            record_data();
            break;
        case 2:
            show_data();
            break;
        case 3:
            access_page();
            break;
        case 4:
            exit(0);
            break;
        }
        count++;
        if (count > 3)
        {
            cout << "too many trial ,program stopped" << endl;
            return;
        }
    }
}

void access_page()
{
    string ad_password, st_password;
    int choice, trial = 0;
    cout << "\n\t1.Admin access";
    cout << "\n\t2.student data view ";
    cout << "\nenter your choice  :";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        if (admin.counter == 0)
        {
            cout << " create password   :";
            cin >> admin.adm_password;
            admin.counter++;
        }
        if (admin.counter > 0)
        {
            cout << " enter  the password   :";
        pass:
            cin >> ad_password;
            if (admin.adm_password == ad_password)
            {
                main_page();
            }
            trial++;
            goto pass;
            if (trial > 3)
                cout << " the program  stopped for security purpose";
        }
        break;
    }
    case 2:
        show_data();
        break;
    default:
        cout << " wrong option and program halt " << endl;
        break;
    }
}

int main()
{
    int select;
    system("color A");
    cout << "\t *****STUDENT MANAGEMENT DATABASE***** " << endl;
    cout << "********************************************************" << endl;
    cout << " \t\tchoose  language " << endl;
    cout << "\t1.English\n\t2.amharic\n \t3.Geez\n\t4.oromia" << endl;
    cin >> select;
    switch (select)
    {
    case 1:
        access_page();
        break;
    case 2:
    case 3:
    case 4:
        cout << "this service  is  not avaliable now  coming soon";
        break;
    default :cout<<"wrong option";break;
    }
    return 0;
}
void st_year()
{
    cout << "\n\t1.first year student " << endl;
    cout << "\n\t2.second year student " << endl;
    cout << "\n\t3.third year student " << endl;
    cout << "\n\t4.fourth year student" << endl;
    return;
}




