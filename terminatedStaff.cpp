//terminated staff
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
  
  void backToMenu(void);

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
