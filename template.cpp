/*!   This is the template source file for
!       https://github.com/LiuGangKingston/CPP-CSV-TIKZ.git
!            Version 1.0
!   free for non-commercial use.
!   Please send us emails for any problems/suggestions/comments.
!   Please be advised that none of us accept any responsibility
!   for any consequences arising out of the usage of this
!   software, especially for damage.
!   For usage, please refer to the README file.
!   This code was written by
!        Gang Liu (gl.cell@outlook)
!                 (http://orcid.org/0000-0003-1575-9290)
!          and
!        Shiwei Huang (huang937@gmail.com)
!   Copyright (c) 2021
!
!   To use this, you can add your code at the
!   "Specific calculation to generate CSV files" area in the
!   functin "void MyComputing() {...}" at the end of this file.
! */


#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
#include <CppCSVTikZ.h>


void Initialize(){
     CppCSVTikZFileGroupInitialize();
}


void Finalize(){
     CppCSVTikZFileGroupFinalize();
}


void MyComputing();


int main() {
    Initialize();
    MyComputing();
    Finalize();
    return 0;
}


void MyComputing() {
// Specific calculation to generate CSV files
// Specific calculation to generate CSV files

    /*
    int i, j, k, totallines=500, datalinesineachfile=50, startingline=1;
    double  morevariables;

    ...

    ofstream afile;
    afile.open("setup.scalars.csv");
    if(!(afile.is_open())) {
       cout << "In the function MyComputing()" <<endl;
       cout << "File open for setup.scalars.csv failed, then stopped." <<endl;
       Finalize();
       exit(0);
    }
    afile <<"variablenamesseperatebycommaswithoutanythingelse" <<endl;
    afile <<thevariables <<endl;
    afile.close();;

    CppCSVTikZFileGroup bigfile("iterated.alldata.",startingline,totallines,datalinesineachfile);

    bigfile.FillFirstLine("variablenamesseperatebycommaswithoutanythingelse");


    for(i=startingline; i<=totallines; i++) {
        ...

      //The next function OutputVariablesToLine has three groups of arguments.
      //The first is a single integer, which is the LineNumber.
      //    It must be from "startingline" to "totallines", as used when the object was created.
      //The second is a const string of indicators for the data types of all later arguments.
      //    d: integer
      //    c: single char
      //    f: float, double
      //    s: std::string
      //    Otherwise, the routine will stop.
      //    Related webpage: https://en.cppreference.com/w/cpp/language/variadic_arguments
      //All the rest arguments will be outputted to the file based on the LineNumber, 
      //where a comma will be inserted between any two and the end-of-line "endl" will be 
      //added at the end.
      //HOWEVER, TESTS SHOW THAT ALL std::string TYPE VARIABLES MUST BE THE LAST ONES.
   
      bigfile.OutputVariablesToLine(i,"ddfffffffffffffffffffs",
                                    totallines,i,refractiveindex,bigradius,a,b,z,anglez,c,anglea,
                                    incidentangle,refractiveangle,anglede,dx,ee,et,ex,ey,anglece,
                                    angleced,outangle, PickTikZColor(i));

      //   The following is an alternative to do the same, which should always work:
      *(bigfile.OutputLine(i))<< totallines<< ',' << i<< ',' << refractiveindex<< ',' << bigradius<< ','
              << a<< ',' << b << ',' << z<< ',' << anglez<< ',' << c << ',' << anglea << ','
              << incidentangle << ',' << refractiveangle << ',' << anglede << ',' << dx << ','
              << ee<< ',' << et << ',' << ex << ',' << ey << ',' << anglece << ',' << angleced << ','
              << outangle << ',' << PickTikZColor(i) << endl; */
}    */
     
}



