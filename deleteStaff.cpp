#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

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

void viewAllStaff(void);


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
