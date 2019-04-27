#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class staff {
  private: //staff record details
  string staffName;
  string staffID;
  string staffRole;
  string birthday;
  string staffSalary;
  string staffCasualLeave;
  string slot1;
  string slot2;
  string slot3;
  string slot4;
  string leavesleft;
  string clID;
  int n;
  int salary;
  string attribute;


    // after choosing option and displaying results, user can go back to menu page
    void backToMenu(void) {
      int m;
      cout << "Enter 0 to go back to menu: ";
      cin >> m;
      if (m==0) {
        menu();
      }
    }

    // View all staff records
    void viewAllStaff(void) {
      ifstream fin;
      fin.open("staffrec.txt");
      if (fin.fail())
      {
          cout << "Error in file opening!" << endl;
          exit(1);
      }
      cout<<"\n\t                                                           =======================";
      cout<<"\n\t                                                            List of Staff Members";
      cout<<"\n\t                                                           =======================\n";


      string staffrecord[500][10];
      for (int i=0; i<500; i++){
        for (int j=0; j<10; j++){
          fin >> staffrecord[i][j];
        }
      }

      //outputting staff
      cout << "===================================================================================================================================================================================";
      for (int i=0; i<500; i++){
        if (staffrecord[i][0].length() > 0 )
        {
        cout << "\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
        cout << endl << endl;
        for (int j=0; j<10; j++){
          cout << setw(8) <<staffrecord[i][j] << "     |" << "    " ;
          }
        cout << "\n";
        }
        else {
          break;
        }
      }

      cout << endl;
      fin.close();
      backToMenu();
    }

    // Search for staff
    void searchStaff(void) {
      cout << "\n\t\t\t========================================================";
      cout << "\n\t\t\t   Please enter option to search by stated attribute: " ;
      cout << "\n\t\t\t========================================================";
      cout << "\n";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 1: Staff ID";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 2: Name";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 3: Birthday";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 4: Department";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n\n";

    //opening FILE
    ifstream fin;
    fin.open("staffrec.txt");
    if (fin.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    string staffrecord[500][10];
    for (int i=0; i<500; i++){
      for (int j=0; j<10; j++){
        fin >> staffrecord[i][j];
      }
    }

    int option;
    cout << "Your option: ";
    cin >> option;
    cout << "\n";

    if ( option == 1){
        cout << "Enter ID number: ";
        string idnum;
        cin >> idnum;
        cout << endl;
        bool found = false;

    // outputting attribute headers
    cout << "===================================================================================================================================================================================";
    cout << endl;
    for (int i=0; i<10; i++){
      cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
    }

    // output searched staff details
    for (int k=0; k<500; k++){
      if ( staffrecord[k][1] == idnum) {
        cout << "\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
        cout << endl << endl;
        for (int l=0; l<10; l++){
          cout << setw(8) <<staffrecord[k][l] << "     |" << "    " ;
        }
        found = true;
        cout << "\n";
      }
      else if ((k==499) && (found == false))
      {
        cout << "Employee not found!" << endl;
      }
    }
    cout << endl;
  }

    else if (option == 2){

        cout << "Enter employee's name: ";
        string name;
        cin >> name;
        cout << endl;
        bool found = false;

        // outputting attribute headers
        cout << "===================================================================================================================================================================================";
        cout << endl;
        for (int i=0; i<10; i++){
          cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
        }

        // output searched staff details
        for (int m=0; m<500; m++){
          if ( staffrecord[m][0] == name) {
            cout << "\n";
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout << endl << endl;
            for (int n=0; n<10; n++){
              cout << setw(8) <<staffrecord[m][n] << "     |" << "    " ;
            }
            found = true;
            cout << "\n";
          }
          else if ((m==499) && (found == false))
          {
            cout << "Employee not found!" << endl;
          }
        }
        cout << endl;
      }

      else if (option == 3){

          cout << "Enter birthday in this format (DD/MM/YYYY): ";
          string bday;
          cin >> bday;
          cout<< endl;
          bool found = false;

          // outputting attribute headers
          cout << "===================================================================================================================================================================================";
          cout << endl;
          for (int i=0; i<10; i++){
            cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
          }

          // output searched staff details
          for (int p=0; p<500; p++){
            if ( staffrecord[p][3] == bday) {
              cout << "\n";
              cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
              cout << endl << endl;
              for (int q=0; q<10; q++){
                cout << setw(8) << staffrecord[p][q] << "     |" << "    " ;
              }
              found = true;
              cout << "\n";
            }
            else if ((p==499) && (found == false))
            {
              cout << "Employee not found!" << endl;
            }
          }
          cout << endl;
        }

        else if (option == 4){

            cout << "Enter employee's role: ";
            string role;
            cin >> role;
            cout << endl;
            bool found = false;

            // outputting attribute headers
            cout << "===================================================================================================================================================================================";
            cout << endl;
            for (int i=0; i<10; i++){
              cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
            }

            // output searched staff details
            for (int r=0; r<500; r++){
              if ( staffrecord[r][2] == role) {
                cout << "\n";
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
                cout << endl << endl;
                for (int s=0; s<10; s++){
                  cout << setw(8) << staffrecord[r][s] << "     |" << "    " ;
                }
                found = true;
                cout << "\n";
              }
              else if ((r==499) && (found == false))
              {
                cout << "Employee not found!" << endl;
              }
            }
            cout << endl;
          }

      fin.close();
      backToMenu();
    }

    // modify staff records
    void modifyStaff(void) {
      //opening FILE
      ifstream fin;
      fin.open("staffrec.txt");
      if (fin.fail())
      {
          cout << "Error in file opening!" << endl;
          exit(1);
      }

      string staffrecord[500][10];
      for (int i=0; i<500; i++){
        for (int j=0; j<10; j++){
          fin >> staffrecord[i][j];
        }
      }

      //choose option
      cout << "\n\t\t\t========================================================";
      cout << "\n\t\t\t   Please enter option to modify by stated attribute: " ;
      cout << "\n\t\t\t========================================================";
      cout << "\n";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 1: Staff ID";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 2: Name";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 3: Birthday";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 4: Department";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 5: Salary";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 6: " << staffrecord[0][6];
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 7: " << staffrecord[0][7];
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 8: " << staffrecord[0][8];
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 9: " << staffrecord[0][9];
      cout << "\n\t\t\t____________________________________________";
      cout << "\n\n";

      //input option
      int optionMod;
      cout << "Your option: ";
      cin >> optionMod;
      cout << "\n";

      //declaration
      string newstaffID;
      string newstaffName;
      string newstaffRole;
      string newbirthday;
      string newstaffSalary;
      string newslot1;
      string newslot2;
      string newslot3;
      string newslot4;

      ofstream fout;


      //execute option
      switch(optionMod) {
        default:
          cout << "This option is unavailable \n";
          break;
        case 1: //modify ID
          //input ID
          cout << "Enter ID number of staff you want to modify : ";
          cin >> staffID;
          cout <<endl;

          for (int k=0; k<500; k++)
          {
            if (staffrecord[k][1] == staffID)
            {
              //input new ID
              cout << "Enter new ID number : ";
              cin >> newstaffID;
              cout <<endl;

              // outputting attribute headers
              cout << "===================================================================================================================================================================================";
              cout << endl;
              for (int i=0; i<10; i++){
                cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
              }
              cout << endl;
              cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
              cout << endl;

              //modify file
              staffrecord[k][1] = newstaffID;
              for (int l=0; l<10; l++) {
                cout << setw(8) <<staffrecord[k][l] << "     |" << "    " ;
              }
              cout << "\n";
            }
            else
            {
              continue;
            }
          }

          //add into file
          fout.open("staffrec.txt");
          if (fout.fail()) {
            cout << "Error in file opening!"
                << endl;
              exit(1);
            }

          for (int l=0; l<500; l++){
            if (staffrecord[l][0].length() > 0 )
            {
              for (int m=0; m<10; m++){
                fout << staffrecord[l][m] << " " ;
              }
              fout << endl;
            }
            else {
              break;
            }
          }
          fin.close();
          fout.close();
          backToMenu();
          break;
        case 2: //modify name
        cout << "Enter ID number of staff you want to modify : ";
        cin >> staffID;
        cout <<endl;

          for (int k=0; k<500; k++)
          {
            if (staffrecord[k][1] == staffID)
            {
              //input new name
              cout << "Enter new name : ";
              cin >> newstaffName;
              cout <<endl;

              // outputting attribute headers
              cout << "===================================================================================================================================================================================";
              cout << endl;
              for (int i=0; i<10; i++){
                cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
              }
              cout << endl;
              cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
              cout << endl;

              //modify file
              staffrecord[k][0] = newstaffName;
              for (int l=0; l<10; l++) {
                cout << setw(8) <<staffrecord[k][l] << "     |" << "    " ;
              }
              cout << "\n";
            }
            else
            {
              continue;
            }
          }

          //add into file
          fout.open("staffrec.txt");
          if (fout.fail()) {
            cout << "Error in file opening!"
                << endl;
              exit(1);
            }

          for (int l=0; l<500; l++){
            if (staffrecord[l][0].length() > 0 )
            {
              for (int m=0; m<10; m++){
                fout << staffrecord[l][m] << " " ;
              }
              fout << endl;
            }
            else {
              break;
            }
          }
          fin.close();
          fout.close();
          backToMenu();
          break;
        case 3: //modify Birthday
        cout << "Enter ID number of staff you want to modify : ";
        cin >> staffID;
        cout <<endl;

        for (int k=0; k<500; k++)
        {
          if (staffrecord[k][1] == staffID)
          {
            //input new ID
            cout << "Enter new birthday : ";
            cin >> newbirthday;
            cout <<endl;

            // outputting attribute headers
            cout << "===================================================================================================================================================================================";
            cout << endl;
            for (int i=0; i<10; i++){
              cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
            }
            cout << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout << endl;

            //modify file
            staffrecord[k][3] = newbirthday;
            for (int l=0; l<10; l++) {
              cout << setw(8) <<staffrecord[k][l] << "     |" << "    " ;
            }
            cout << "\n";
          }
          else
          {
            continue;
          }
        }

        //add into file
        fout.open("staffrec.txt");
        if (fout.fail()) {
          cout << "Error in file opening!"
              << endl;
            exit(1);
          }

        for (int l=0; l<500; l++){
          if (staffrecord[l][0].length() > 0 )
          {
            for (int m=0; m<10; m++){
              fout << staffrecord[l][m] << " " ;
            }
            fout << endl;
          }
          else {
            break;
          }
        }
        fin.close();
        fout.close();
        backToMenu();
          break;
        case 4://modify department
        //input ID
        cout << "Enter ID number of staff you want to modify : ";
        cin >> staffID;
        cout <<endl;

        for (int k=0; k<500; k++)
        {
          if (staffrecord[k][1] == staffID)
          {
            //input new ID
            cout << "Enter new department : ";
            cin >> newstaffRole;
            cout <<endl;

            // outputting attribute headers
            cout << "===================================================================================================================================================================================";
            cout << endl;
            for (int i=0; i<10; i++){
              cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
            }
            cout << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout << endl;

            //modify file
            staffrecord[k][2] = newstaffRole;
            for (int l=0; l<10; l++) {
              cout << setw(8) <<staffrecord[k][l] << "     |" << "    " ;
            }
            cout << "\n";
          }
          else
          {
            continue;
          }
        }

        //add into file
        fout.open("staffrec.txt");
        if (fout.fail()) {
          cout << "Error in file opening!"
              << endl;
            exit(1);
          }

        for (int l=0; l<500; l++){
          if (staffrecord[l][0].length() > 0 )
          {
            for (int m=0; m<10; m++){
              fout << staffrecord[l][m] << " " ;
            }
            fout << endl;
          }
          else {
            break;
          }
        }
        fin.close();
        fout.close();
        backToMenu();
          break;
        case 5: //modify SALARY
        //input ID
        cout << "Enter ID number of staff you want to modify : ";
        cin >> staffID;
        cout <<endl;

        for (int k=0; k<500; k++)
        {
          if (staffrecord[k][1] == staffID)
          {
            //input new salary
            cout << "Enter new salary : ";
            cin >> newstaffSalary;
            cout <<endl;

            // outputting attribute headers
            cout << "===================================================================================================================================================================================";
            cout << endl;
            for (int i=0; i<10; i++){
              cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
            }
            cout << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout << endl;

            //modify file
            staffrecord[k][4] = newstaffSalary;
            for (int l=0; l<10; l++) {
              cout << setw(8) <<staffrecord[k][l] << "     |" << "    " ;
            }
            cout << "\n";
          }
          else
          {
            continue;
          }
        }

        //add into file
        fout.open("staffrec.txt");
        if (fout.fail()) {
          cout << "Error in file opening!"
              << endl;
            exit(1);
          }

        for (int l=0; l<500; l++){
          if (staffrecord[l][0].length() > 0 )
          {
            for (int m=0; m<10; m++){
              fout << staffrecord[l][m] << " " ;
            }
            fout << endl;
          }
          else {
            break;
          }
        }
        fin.close();
        fout.close();
        backToMenu();
          break;
        case 6: //modify slot 1
        //input ID
        cout << "Enter ID number of staff you want to modify : ";
        cin >> staffID;
        cout <<endl;

        for (int k=0; k<500; k++)
        {
          if (staffrecord[k][1] == staffID)
          {
            //input new slot 1
            cout << "Enter new " << staffrecord[0][6] << ": ";
            cin >> newslot1;
            cout <<endl;

            // outputting attribute headers
            cout << "===================================================================================================================================================================================";
            cout << endl;
            for (int i=0; i<10; i++){
              cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
            }
            cout << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout << endl;

            //modify file
            staffrecord[k][6] = newslot1;
            for (int l=0; l<10; l++) {
              cout << setw(8) <<staffrecord[k][l] << "     |" << "    " ;
            }
            cout << "\n";
          }
          else
          {
            continue;
          }
        }

        //add into file
        fout.open("staffrec.txt");
        if (fout.fail()) {
          cout << "Error in file opening!"
              << endl;
            exit(1);
          }

        for (int l=0; l<500; l++){
          if (staffrecord[l][0].length() > 0 )
          {
            for (int m=0; m<10; m++){
              fout << staffrecord[l][m] << " " ;
            }
            fout << endl;
          }
          else {
            break;
          }
        }
        fin.close();
        fout.close();
        backToMenu();
          break;
        case 7: //modify slot2
        //input ID
        cout << "Enter ID number of staff you want to modify : ";
        cin >> staffID;
        cout <<endl;

        for (int k=0; k<500; k++)
        {
          if (staffrecord[k][1] == staffID)
          {
            //input new slot 2
            cout << "Enter new " << staffrecord[0][7] << ": ";
            cin >> newslot2;
            cout <<endl;

            // outputting attribute headers
            cout << "===================================================================================================================================================================================";
            cout << endl;
            for (int i=0; i<10; i++){
              cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
            }
            cout << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout << endl;

            //modify file
            staffrecord[k][7] = newslot2;
            for (int l=0; l<10; l++) {
              cout << setw(8) <<staffrecord[k][l] << "     |" << "    " ;
            }
            cout << "\n";
          }
          else {
            break;
          }
        }
        fin.close();
        fout.close();
        backToMenu();
          break;
        case 8: //modify slot3
        //input ID
        cout << "Enter ID number of staff you want to modify : ";
        cin >> staffID;
        cout <<endl;

        for (int k=0; k<500; k++)
        {
          if (staffrecord[k][1] == staffID)
          {
            //input new slot 3
            cout << "Enter new " << staffrecord[0][8] << ": ";
            cin >> newslot3;
            cout <<endl;

            // outputting attribute headers
            cout << "===================================================================================================================================================================================";
            cout << endl;
            for (int i=0; i<10; i++){
              cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
            }
            cout << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout << endl;

            //modify file
            staffrecord[k][8] = newslot3;
            for (int l=0; l<10; l++) {
              cout << setw(8) <<staffrecord[k][l] << "     |" << "    " ;
            }
            cout << "\n";
          }
          else
          {
            continue;
          }
        }

        //add into file
        fout.open("staffrec.txt");
        if (fout.fail()) {
          cout << "Error in file opening!"
              << endl;
            exit(1);
          }

        for (int l=0; l<500; l++){
          if (staffrecord[l][0].length() > 0 )
          {
            for (int m=0; m<10; m++){
              fout << staffrecord[l][m] << " " ;
            }
            fout << endl;
          }
          else {
            break;
          }
        }
        fin.close();
        fout.close();
        backToMenu();
          break;
        case 9:
        //input ID
        cout << "Enter ID number of staff you want to modify : ";
        cin >> staffID;
        cout <<endl;

        for (int k=0; k<500; k++)
        {
          if (staffrecord[k][1] == staffID)
          {
            //input new slot 4
            cout << "Enter new " << staffrecord[0][9] << ": ";
            cin >> newslot4;
            cout <<endl;

            // outputting attribute headers
            cout << "===================================================================================================================================================================================";
            cout << endl;
            for (int i=0; i<10; i++){
              cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
            }
            cout << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout << endl;

            //modify file
            staffrecord[k][9] = newslot4;
            for (int l=0; l<10; l++) {
              cout << setw(8) <<staffrecord[k][l] << "     |" << "    " ;
            }
            cout << "\n";
          }
          else
          {
            continue;
          }
        }

        //add into file
        fout.open("staffrec.txt");
        if (fout.fail()) {
          cout << "Error in file opening!"
              << endl;
            exit(1);
          }

        for (int l=0; l<500; l++){
          if (staffrecord[l][0].length() > 0 )
          {
            for (int m=0; m<10; m++){
              fout << staffrecord[l][m] << " " ;
            }
            fout << endl;
          }
          else {
            break;
          }
        }
        fin.close();
        fout.close();
        backToMenu();
          break;
        }
    }

    // add staff records
    void addStaff(void) {
      ofstream fout;
      fout.open("staffrec.txt", ios::app);

      if (fout.fail()) {
         cout << "Error in file opening!"
              << endl;
           exit(1);
        }

        //opening FILE
        ifstream fin;
        fin.open("staffrec.txt");
        if (fin.fail())
        {
            cout << "Error in file opening!" << endl;
            exit(1);
        }

        string staffrecord[500][10];
        for (int i=0; i<500; i++){
          for (int j=0; j<10; j++){
            fin >> staffrecord[i][j];
          }
        }

        cout<<"\n\t                                       ======================";
        cout<<"\n\t                                        Add New Staff Record";
        cout<<"\n\t                                       ======================\n";


        cout << "Enter New Staff Name: ";
        cin >> staffName;
        cout << "\n";
        cout << "Enter New Staff ID: "; //error message?
        cin >> staffID;
        cout << "\n";
        cout << "Enter New Staff Department (e.g. HR-Human Resoruces, PR-Public Relations, MKTG-Marketing, ACCT-Accounting): ";
        cin >> staffRole;
        cout << "\n";
        cout << "Enter New Staff Date of Birth (i.e. DD/MM/YYYY): ";
        cin >> birthday;
        cout << "\n";
        cout << "Enter New Staff Salary: ";
        cin >> staffSalary;
        cout << "\n";
        cout << "Enter New Staff Casual Leaves Left: ";
        cin >> staffCasualLeave;
        cout << "\n";
        cout << "Enter " << staffrecord[0][6] << ", else input N/A: ";
        cin >> slot1;
        cout << "\n";
        cout << "Enter " << staffrecord[0][7] << ", else input N/A: ";
        cin >> slot2;
        cout << "\n";
        cout << "Enter " << staffrecord[0][8] << ", else input N/A: ";
        cin >> slot3;
        cout << "\n";
        cout << "Enter " << staffrecord[0][9] << ", else input N/A: ";
        cin >> slot4;
        cout << "\n";

        // storing entered data into the staff record array
        for (int i=0; i<500; i++){
          if (staffrecord[i][0].length() == 0 )
          {
            staffrecord[i][0] = staffName;
            staffrecord[i][1] = staffID;
            staffrecord[i][2] = staffRole;
            staffrecord[i][3] = birthday;
            staffrecord[i][4] = staffSalary;
            staffrecord[i][5] = staffCasualLeave;
            staffrecord[i][6] = slot1;
            staffrecord[i][7] = slot2;
            staffrecord[i][8] = slot3;
            staffrecord[i][9] = slot4;
            }
          else
          {
            break;
          }
        }

        fout << staffName << " " << staffID << " " << staffRole << " "
        << birthday << " " << staffSalary << " " << staffCasualLeave << " "
        << slot1 << " " << slot2 << " " << slot3 << " " << slot4 << endl;
        fout.close();

        viewAllStaff();
        fin.close();
        backToMenu();
    } //A

    // delete staff records
    void deleteStaff(void) {
      cout << "\n\t\t\t========================================================";
      cout << "\n\t\t\t   Please enter option to delete by stated attribute: " ;
      cout << "\n\t\t\t========================================================";
      cout << "\n";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 1: Staff ID";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 2: Name";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 3: Birthday";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n";
      cout << "\n\t\t\tOption 4: Department";
      cout << "\n\t\t\t____________________________________________";
      cout << "\n\n";

      //input option
      cout << "Your option: ";
      int optionDel;
      cin >> optionDel;
      cout <<endl;

      //declaration
      ifstream staffRecFile;
      ofstream tmp;
      string line;
      ofstream fout;


      //execute action for chosen options
      switch(optionDel) {
        default:
          cout << "This option is unavailable \n";
          break;
        case 1: //delete by ID
          //input ID
          cout << "Enter ID number: ";
          cin >> staffID;
          cout <<endl;

          //open read file & write file
          staffRecFile.open("staffrec.txt");
          tmp.open("temp.txt");
          if (staffRecFile.fail())
          {
              cout << "Error in file opening!" << endl;
              exit(1);
          }
          if (tmp.fail())
          {
            cout << "Error in file opening!" << endl;
            exit(1);
          }

          //open file to store in terminated file
          fout.open("terminatedStaff.txt", ios::app);
          if (fout.fail()) {
             cout << "Error in file opening!"
                  << endl;
               exit(1);
            }

          //delete employee
          while (getline(staffRecFile,line)) {
            if (line.find(staffID) == string::npos) {
              tmp << line << endl;
            }
            if (line.find(staffID) != string::npos) {
              fout << "\n" << line ;
            }
          }
          staffRecFile.close();
          tmp.close();
          fout.close();
          remove("staffrec.txt");
          rename("temp.txt", "staffrec.txt");
          viewAllStaff();
          break;
        case 2: //delete by name
          //input name
          cout << "Enter Staff Name: ";
          cin >> staffName;
          cout <<endl;

          //open read file & write file
          staffRecFile.open("staffrec.txt");
          tmp.open("temp.txt");
          if (staffRecFile.fail())
          {
            cout << "Error in file opening!" << endl;
            exit(1);
          }
          if (tmp.fail())
          {
            cout << "Error in file opening!" << endl;
            exit(1);
          }

          //open file to store in terminated file
          fout.open("terminatedStaff.txt", ios::app);
          if (fout.fail()) {
             cout << "Error in file opening!"
                  << endl;
               exit(1);
            }

          //delete employee
          while (getline(staffRecFile,line)) {
            if (line.find(staffName) == string::npos) {
              tmp << line << endl;
            }
            if (line.find(staffName) != string::npos) {
              fout << "\n" << line ;
            }
          }

          staffRecFile.close();
          tmp.close();
          fout.close();
          remove("staffrec.txt");
          rename("temp.txt", "staffrec.txt");
          viewAllStaff();
          break;
        case 3: //delete by bday
            //input bday
            cout << "Enter Staff Birthday (i.e. DD/MM/YYYY): ";
            cin >> birthday;
            cout << endl;

            //open read file & write file
            staffRecFile.open("staffrec.txt");
            tmp.open("temp.txt");
            if (staffRecFile.fail())
            {
              cout << "Error in file opening!" << endl;
              exit(1);
            }
            if (tmp.fail())
            {
              cout << "Error in file opening!" << endl;
              exit(1);
            }

            //open file to store in terminated file
            fout.open("terminatedStaff.txt", ios::app);
            if (fout.fail()) {
               cout << "Error in file opening!"
                    << endl;
                 exit(1);
              }

            //delete employee
            while (getline(staffRecFile,line)) {
              if (line.find(birthday) == string::npos) {
                tmp << line << endl;
              }
              if (line.find(birthday) != string::npos) {
                fout << "\n" << line ;
              }
            }

            staffRecFile.close();
            tmp.close();
            fout.close();
            remove("staffrec.txt");
            rename("temp.txt", "staffrec.txt");
            viewAllStaff();
            break;
        case 4: //delete by department
            //input bday
            cout << "Enter Staff's Department (e.g. HR-Human Resoruces, PR-Public Relations, MKTG-Marketing, ACCT-Accounting): ";
            cin >> staffRole;
            cout << endl;

            //open read file & write file
            staffRecFile.open("staffrec.txt");
            tmp.open("temp.txt");
            if (staffRecFile.fail())
            {
              cout << "Error in file opening!" << endl;
              exit(1);
            }
            if (tmp.fail())
            {
              cout << "Error in file opening!" << endl;
              exit(1);
            }

            //open file to store in terminated file
            fout.open("terminatedStaff.txt", ios::app);
            if (fout.fail()) {
               cout << "Error in file opening!"
                    << endl;
                 exit(1);
              }

            //delete employee
            while (getline(staffRecFile,line)) {
              if (line.find(staffRole) == string::npos) {
                tmp << line << endl;
              }
              if (line.find(staffRole) != string::npos) {
                fout << "\n" << line ;
              }
            }

            staffRecFile.close();
            tmp.close();
            fout.close();
            remove("staffrec.txt");
            rename("temp.txt", "staffrec.txt");
            viewAllStaff();
            break;
      }
    }

    // view list of terminated staff
    void terminatedStaff(void) {
      ifstream fin;
      fin.open("terminatedStaff.txt");
      if (fin.fail())
      {
          cout << "Error in file opening!" << endl;
          exit(1);
      }
      cout<<"\n\t                                                           ==================================";
      cout<<"\n\t                                                            List of Terminated Staff Members";
      cout<<"\n\t                                                           ==================================\n";


      string staffrecord[500][10];
      for (int i=0; i<500; i++){
        for (int j=0; j<10; j++){
          fin >> staffrecord[i][j];
        }
      }

      //outputting staff
      cout << "===================================================================================================================================================================================";
      for (int i=0; i<500; i++){
        if (staffrecord[i][0].length() > 0 )
        {
        cout << "\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
        cout << endl << endl;
        for (int j=0; j<10; j++){
          cout << setw(8) <<staffrecord[i][j] << "     |" << "    " ;
          }
        cout << "\n";
        }
        else {
          break;
        }
      }

      cout << endl;
      fin.close();

      backToMenu();
    }

    // request casual leave
    void requestLeave(void) {

        //opening FILE
        ifstream fin;
        fin.open("staffrec.txt");
        if (fin.fail())
        {
            cout << "Error in file opening!" << endl;
            exit(1);
        }

        string staffrecord[500][10];
        for (int i=0; i<500; i++){
          for (int j=0; j<10; j++){
            fin >> staffrecord[i][j];
          }
        }

      // approve/disapprove casual leave
      cout<<"\n\t                             ==========================";
      cout<<"\n\t                              Request For Casual Leave";
      cout<<"\n\t                             ==========================\n";
      cout << "\n";
      cout << "Enter Staff ID who requested for casual leave: ";
      cin >> clID;

      cout << "\n";
      cout<<"\n---------------------------------------------------------------";
      cout<<"\n        NAME        |     ID     |     CASUAL LEAVES LEFT    \n";
      cout<<"---------------------------------------------------------------" << endl;

      for (int k=0; k<500; k++)
      {
        if (staffrecord[k][1] == clID)
        {
          if ( std::stoi(staffrecord[k][5]) == 0 )
          {
            cout << setw(12) << staffrecord[k][0] << setw(20) << staffrecord[k][1] << setw(15) << staffrecord[k][5]  <<endl;
            cout << "\n";
            cout << "Request: DENIED" <<endl;
          }
          else
          {
            n = (std::stoi(staffrecord[k][5])) - 1;
            leavesleft = std::to_string(n);
            staffrecord[k][5] = leavesleft;
            cout << setw(12) << staffrecord[k][0] << setw(20) << staffrecord[k][1] << setw(15) << staffrecord[k][5]  <<endl;
            cout << "\n";
            cout << "Request: APPROVED" <<endl;
          }
        }
        else
        {
          continue;
        }
      }

      ofstream fout;
      fout.open("staffrec.txt");

      if (fout.fail()) {
         cout << "Error in file opening!"
              << endl;
           exit(1);
        }

      for (int l=0; l<500; l++){
        if (staffrecord[l][0].length() > 0 )
        {
        for (int m=0; m<10; m++){
          fout << staffrecord[l][m] << " " ;
          }
        fout << endl;
        }
        else {
          break;
        }
      }

      fin.close();
      fout.close();
      backToMenu();
    }

    // add a new attribute
    void addAttribute(void) {

      //opening FILE
      ifstream fin;
      fin.open("staffrec.txt");
      if (fin.fail())
      {
          cout << "Error in file opening!" << endl;
          exit(1);
      }

      string staffrecord[500][10];
      for (int i=0; i<500; i++){
        for (int j=0; j<10; j++){
          fin >> staffrecord[i][j];
        }
      }

      // outputting attribute headers
      cout << "===================================================================================================================================================================================";
      cout << endl;
      for (int i=0; i<10; i++){
        cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
      }
      cout << endl;
      cout << "===================================================================================================================================================================================";
      cout<< endl << endl;

      int slotchoice;
      cout << "Please choose empty slot to add attribute (1-4): ";
      cin >> slotchoice;
      cout<< endl;

      cout << "What attribute would you like to add?" << endl;
      cout << "Attribute name: ";
      cin >> attribute;
      cout << endl;

      //calling function based on option chosen
      switch (slotchoice) {
        case 1:
          staffrecord[0][6] = attribute;
          break;
        case 2:
          staffrecord[0][7] = attribute;
          break;
        case 3:
          staffrecord[0][8] = attribute;
          break;
        case 4:
          staffrecord[0][9] = attribute;
          break;
      }

      ofstream fout;
      fout.open("staffrec.txt");

      if (fout.fail()) {
         cout << "Error in file opening!"
              << endl;
           exit(1);
        }

        for (int l=0; l<500; l++){
          if (staffrecord[l][0].length() > 0 )
          {
          for (int m=0; m<10; m++){
            fout << staffrecord[l][m] << " " ;
            }
          fout << endl;
          }
          else {
            break;
          }
        }

      fin.close();
      fout.close();
      viewAllStaff();
      backToMenu();
    }

    // search by salary and compare
    void salarycheck(void) {

      //opening FILE
      ifstream fin;
      fin.open("staffrec.txt");
      if (fin.fail())
      {
          cout << "Error in file opening!" << endl;
          exit(1);
      }

      string staffrecord[500][10];
      for (int i=0; i<500; i++){
        for (int j=0; j<10; j++){
          fin >> staffrecord[i][j];
        }
      }
      //Asking for amount to compare
      cout << "Enter salary amount: ";
      cin >> salary;
      bool found = false;

      //user's option
      cout << "Please enter 1 to search for record with salary greater than or equal to $" << salary
      << " or 2 for less than or equal to $" << salary << "." << endl;
      cout << "Your option: ";
      int option;
      cin >> option;
      cout << "\n";

      //calling function based on option chosen
      switch (option) {
        case 1:
            cout<<"\n\t                                                           =======================";
            cout<<"\n\t                                                            List of Staff Members";
            cout<<"\n\t                                                           =======================\n";

            // outputting attribute headers
            cout << "===================================================================================================================================================================================";
            cout << endl;
            for (int i=0; i<10; i++){
              cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
            }
            cout<< endl;

            for (int i=1; i<500; i++)
            {
              if (staffrecord[i][0].length() > 0 )
              {
                if (std::stoi(staffrecord[i][4]) >= salary)
                {
                  cout << "\n";
                  cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
                  cout << endl << endl;
                  for (int j=0; j<10; j++)
                  {
                    cout << setw(8) << staffrecord[i][j] << "     |" << "    " ;
                    found = true;
                  }
                cout << endl << endl;
                }
              }
              else if (found == false)
              {
                cout << endl;
                cout << "No employee has the salary of >= $" << salary << ".";
                cout << endl << endl;
                break;
              }
              else
              {
                break;
              }
            }
            fin.close();
            backToMenu();
        case 2:
        cout<<"\n\t                                                           =======================";
        cout<<"\n\t                                                            List of Staff Members";
        cout<<"\n\t                                                           =======================\n";

        // outputting attribute headers
        cout << "===================================================================================================================================================================================";
        cout << endl;
        for (int i=0; i<10; i++){
          cout << setw(8) << staffrecord[0][i] << "     |" << "    " ;
        }
        cout<< endl;

        for (int i=1; i<500; i++)
        {
          if (staffrecord[i][0].length() > 0 )
          {
            if (std::stoi(staffrecord[i][4]) <= salary)
            {
              cout << "\n";
              cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
              cout << endl << endl;
              for (int j=0; j<10; j++)
              {
                cout << setw(8) << staffrecord[i][j] << "     |" << "    " ;
                found = true;
              }
            cout << endl << endl;
            }
          }
          else if (found == false)
          {
            cout << endl;
            cout << "No employee has the salary of <= $" << salary << ".";
            cout << endl << endl;
            break;
          }
          else
          {
            break;
          }
        }
        fin.close();
        backToMenu();
    }
  }

  public:
    void menu(void) { //the menu page
      while(true) {
        cout << "\n\t\t\t============================================";
        cout << "\n\t\t\t          Staff Management System " ;
        cout << "\n\t\t\t============================================";
        cout << "\n";
        cout << "\n\t\t\t____________________________________________";
        cout << "\n";
        cout << "\n\t\t\tOption 1: View List of Staff Members";
        cout << "\n\t\t\t____________________________________________";
        cout << "\n";
        cout << "\n\t\t\tOption 2: Search Staff Records";
        cout << "\n\t\t\t____________________________________________";
        cout << "\n";
        cout << "\n\t\t\tOption 3: Modify Staff Records";
        cout << "\n\t\t\t____________________________________________";
        cout << "\n";
        cout << "\n\t\t\tOption 4: Add New Staff Record";
        cout << "\n\t\t\t____________________________________________";
        cout << "\n";
        cout << "\n\t\t\tOption 5: Delete Existing Staff Record";
        cout << "\n\t\t\t____________________________________________";
        cout << "\n";
        cout << "\n\t\t\tOption 6: View List of Terminated Staff";
        cout << "\n\t\t\t____________________________________________";
        cout << "\n";
        cout << "\n\t\t\tOption 7: Request for Casual Leave";
        cout << "\n\t\t\t____________________________________________";
        cout << "\n";
        cout << "\n\t\t\tOption 8: Add New Atrribute";
        cout << "\n\t\t\t____________________________________________";
        cout << "\n";
        cout << "\n\t\t\tOption 9: Salary Check";
        cout << "\n\t\t\t____________________________________________";
        cout << "\n";
        cout << "\n\t\t\tOption 10: End Program";
        cout << "\n\t\t\t____________________________________________";
        cout << "\n";
        cout << "\n";
        cout << "Please Enter Your Option: ";

        //user's option
        int option;
        cin >> option;
        cout << "\n";

        //calling function based on option chosen
        switch (option) {
          case 1:
            viewAllStaff();
            break;
          case 2:
            searchStaff();
            break;
          case 3:
            modifyStaff();
            break;
          case 4:
            addStaff();
            break;
          case 5:
            deleteStaff();
            break;
          case 6:
            terminatedStaff();
            break;
          case 7:
            requestLeave();
            break;
          case 8:
            addAttribute();
            break;
          case 9:
            salarycheck();
            break;
          case 10:
            cout << "Goodbye! \n"<<endl;
            exit(1);
          default:
            cout << "This option is unavailable \n";
            break;
          }
        }
    }
};

int main() {
  staff s;
  s.menu();
  return 0;
}
