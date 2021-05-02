/*!   This is example01.100beams source file for
!       https://github.com/LiuGangKingston/C++-CSV-TIKZ.git
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
!   This file is formed by adding new lines at the
!   "Specific calculation to generate CSV files" area in the
!   functin "void MyComputing() {...}" at the end of the
!   template file.
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

    int i, startingline, totallines;
    double  refractiveindex, bigradius , a ,b , z, anglez, c, anglea, incidentangle;
    double  refractiveangle, anglede, dx, ee, et, ex, ey, anglece, angleced, outangle;

    totallines = 100;
    startingline = 1;

    refractiveindex=1.5e0;
    bigradius=8.0e0;
    a=3.0e0;
    b=3.0e0;
    z=sqrt(bigradius * bigradius- b * b);
    anglez=asin(b/bigradius)*Rad2Deg;
    c=-sqrt(bigradius * bigradius - (a+b) * (a+b));
    anglea=acos(c/bigradius)*Rad2Deg;

    ofstream afile;
    afile.open("setup.scalars.csv");
    if(!(afile.is_open())) {
       cout << "In the function MyComputing()" <<endl;
       cout << "File open for setup.scalars.csv failed, then stopped." <<endl;
       Finalize();
       exit(0);
    }
    afile <<"totallines,refractiveindex,bigradius,a,b,z,anglez,c,anglea" <<endl;
    afile <<totallines << ',' << refractiveindex << ',' << bigradius << ','
          << a << ',' << b << ',' << z << ',' << anglez << ',' << c << ',' << anglea <<endl;
    afile.close();

    afile.open("iterated.alldata.csv");
    if(!(afile.is_open())) {
       cout << "In the function MyComputing()" <<endl;
       cout << "File open for iterated.alldata.csv failed, then stopped." <<endl;
       Finalize();
       exit(0);
    }
    afile << "totallines,i,refractiveindex,bigradius,a,b,z,anglez,c,"
             "anglea,incidentangle,refractiveangle,anglede,dx,ee,et,ex,ey,"
             "anglece,angleced,outangle,mycolor" << endl;

    for(i=startingline; i<=totallines; i++) {
       incidentangle=3.0e0 + 0.50e0*i;
       refractiveangle=asin(sin(incidentangle*Deg2Rad)/refractiveindex)*Rad2Deg;
       anglede=180-refractiveangle-anglea;
       // x component of D position
       dx=a/tan(anglede*Deg2Rad) + c;

       //! To find E position by solving equations, with t and et as DE length:
       //!  (t sin(anglede) + \b)^2 + (t cos(anglede) + \dx )^2 = 64
       //!  t^2 + 2 (\b sin + \dx cos ) + (\b sin + \dx cos )^2
       //!  = 64 - \b^2 - \dx^2 + (\b sin +  \dx cos  )^2
       //!  t = sqrt ((\b sin + \dx cos )^2 +  64 - \b^2 - \dx^2 )  - (\b sin + \dx cos )

       ee=b*sin(anglede*Deg2Rad) + dx*cos(anglede*Deg2Rad);
       et=sqrt(ee * ee + bigradius * bigradius -b * b - dx * dx) - ee;

       //! x and y components of E position
       ex=et*cos(anglede*Deg2Rad) + dx;
       ey=et*sin(anglede*Deg2Rad) + b;
       anglece=acos(ex/sqrt(ex * ex+ey * ey))*Rad2Deg;
       angleced=anglece-anglede;
       outangle=asin(sin(angleced*Deg2Rad) * refractiveindex)*Rad2Deg;

       afile      << totallines<< ',' << i<< ',' << refractiveindex<< ',' << bigradius<< ','
                  << a<< ',' << b << ',' << z<< ',' << anglez<< ',' << c << ',' << anglea << ','
                  << incidentangle << ',' << refractiveangle << ',' << anglede << ',' << dx << ','
                  << ee<< ',' << et << ',' << ex << ',' << ey << ',' << anglece << ',' << angleced << ','
                  << outangle << ',' << PickTypicalColor(i) << endl;
    }
    afile.close();

}


