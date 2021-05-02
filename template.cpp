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

       *(bigfile.OutputLine(i))<< variables << PickTikZColor(i) << endl;
    }
    */
}



