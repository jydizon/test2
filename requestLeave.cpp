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
