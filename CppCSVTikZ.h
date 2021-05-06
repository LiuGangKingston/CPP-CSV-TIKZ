/*!   This is the supporting source file for
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
! */

#ifndef _CppCSVTikZ
#define _CppCSVTikZ


void Initialize();
void Finalize();


#include <cstdarg>
#include <fstream>
#include <iostream>
using namespace std;


    const double  PI             = 3.14159265358979323846e0;
    const double  Rad2Deg        = 57.29577951308232e0     ;  // 180/pi;
    const double  Deg2Rad        = 0.017453292519943296e0  ;  // pi/180;
    const double  NapierConstant = 2.71828182845904523536e0;
    const double  EulerNumber    = 2.71828182845904523536e0;

    const double  AccelerationDueToEarthGravity  = 9.80e0               ;// "m/s$^2$"
    const double  AtomicMassConstant             = 1.66053906660e-27    ;// kg
    const double  AvogadroNumber                 = 6.02214076e23        ;// "mol$^{-1}$"
    const double  BohrMagneton                   = 9.2740100783e-24     ;// "J/T"
    const double  BohrRadius                     = 5.29177210903e-11    ;// m
    const double  BoltzmannConstant              = 1.380649e-23         ;// "J/K"
    const double  ClassicalElectronRadius        = 2.8179403262e-15     ;// m
    const double  CoulombConstant                = 8.9875517923e9       ;// "N$\cdot $m$^2$/C$^2$"
    const double  ElementaryCharge               = 1.602176634e-19      ;// "C"
    const double  FaradayConstant                = 9.648533212e4        ;// C/mol
    const double  FineStructureConstant          = 7.2973525693e-3      ;//
    const double  FirstRadiationConstant         = 3.741771852e-16      ;// W$\dot m^2$
    const double  MassOfElectron                 = 9.1093837015e-31     ;// "kg"
    const double  MassOfNeutron                  = 1.67492749804e-27    ;// "kg"
    const double  MassOfProton                   = 1.67262192369e-27    ;// "kg"
    const double  NuclearMagneton                =  5.0507837461e-27    ;// "J/T"
    const double  PlanckConstant                 = 6.62607015e-34       ;// "J$\cdot $s"
    const double  RydbergConstant                = 1.0973731568160e7    ;// 1/m
    const double  SecondRadiationConstant        = 1.438776877e-2       ;// m$\dot K$
    const double  SpeedoFlightInVacuum           = 2.99792458e+8        ;// "m/s"
    const double  ThomsonCrossSection            = 6.6524587321e-29     ;//  $m^2$
    const double  UniversalGasConstant           = 8.314462618e0        ;// "J/(mol$\cdot $K)"
    const double  UniversalGravitationalConstant = 6.67430e-11          ;// "N$\cdot $m$^2$/kg$^2$"
    const double  VacuumElectricPermittivity     = 8.8541878128e-12     ;// "F/m"
    const double  VacuumMagneticPermeability     = 1.25663706212e-6     ;// "N/$A^2$"

    static const size_t NumberOfTypicalColors = 5;
    static const size_t LengthOfTypicalColors = 16;
    std::string  TypicalColors[NumberOfTypicalColors] = {
                 "red\0            ","orange\0         ","yellow\0         ","green\0          ",
                 "blue\0           " };

    static const size_t NumberOfTikZColors = 19;
    static const size_t LengthOfTikZColors = 16;
    std::string  TikZColors[NumberOfTikZColors] = {
                 "red\0            ","purple\0         ","magenta\0        ","pink\0           ",
                 "violet\0         ","white\0          ","orange\0         ","yellow\0         ",
                 "green\0          ","lime\0           ","brown\0          ","olive\0          ",
                 "blue\0           ","cyan\0           ","teal\0           ","lightgray \0     ",
                 "gray\0           ","darkgray\0       ","black\0          " };

    static const size_t NumberOfColors = 68;
    static const size_t LengthOfColors = 16;
    std::string  Colors[NumberOfColors] = {
                 "Apricot\0        ","Aquamarine\0     ","Bittersweet\0    ","Black\0          ",
                 "Blue\0           ","BlueGreen\0      ","BlueViolet\0     ","BrickRed\0       ",
                 "Brown\0          ","BurntOrange\0    ","CadetBlue\0      ","CarnationPink\0  ",
                 "Cerulean\0       ","CornflowerBlue\0 ","Cyan\0           ","Dandelion\0      ",
                 "DarkOrchid\0     ","Emerald\0        ","ForestGreen\0    ","Fuchsia\0        ",
                 "Goldenrod\0      ","Gray\0           ","Green\0          ","GreenYellow\0    ",
                 "JungleGreen\0    ","Lavender\0       ","LimeGreen\0      ","Magenta\0        ",
                 "Mahogany\0       ","Maroon\0         ","Melon\0          ","MidnightBlue\0   ",
                 "Mulberry\0       ","NavyBlue\0       ","OliveGreen\0     ","Orange\0         ",
                 "OrangeRed\0      ","Orchid\0         ","Peach\0          ","Periwinkle\0     ",
                 "PineGreen\0      ","Plum\0           ","ProcessBlue\0    ","Purple\0         ",
                 "RawSienna\0      ","Red\0            ","RedOrange\0      ","RedViolet\0      ",
                 "Rhodamine\0      ","RoyalBlue\0      ","RoyalPurple\0    ","RubineRed\0      ",
                 "Salmon\0         ","SeaGreen\0       ","Sepia\0          ","SkyBlue\0        ",
                 "SpringGreen\0    ","Tan\0            ","TealBlue\0       ","Thistle\0        ",
                 "Turquoise\0      ","Violet\0         ","VioletRed\0      ","White\0          ",
                 "WildStrawberry\0 ","Yellow\0         ","YellowGreen\0    ","YellowOrange\0   " };


    std::string   PickTypicalColor(int i);
    std::string   PickTikZColor(int i);
    std::string   PickColor(int i);

    std::string   PickTypicalColor(int i) {return TypicalColors[abs(i)%NumberOfTypicalColors];}

    std::string   PickTikZColor(int i)    {return TikZColors[abs(i)%NumberOfTikZColors];}

    std::string   PickColor(int i)        {return Colors[abs(i)%NumberOfColors];}


  struct CppCSVTikZFilesAndNamePrefixes {
         std::string TheNamePrefix;
         int         ItsGroupNumber;
         ofstream *  GroupFiles;
         struct CppCSVTikZFilesAndNamePrefixes * NextPrefixes;
  };
  static int TotalCppCSVTikZFilesAndNamePrefixes;
  static struct CppCSVTikZFilesAndNamePrefixes * HeadOfCppCSVTikZFilesAndNamePrefixes;
  static struct CppCSVTikZFilesAndNamePrefixes *       CppCSVTikZFilesAndNamePrefixTemp1;
  static struct CppCSVTikZFilesAndNamePrefixes *       CppCSVTikZFilesAndNamePrefixTemp2;




class CppCSVTikZFileGroup
{ private:
         int TotalLinesInEachFile;
         int TotalFiles;
         int StartingLineNumber;
         int EndingLineNumber;
         int LineNumberDirection;
         int AbsoluteLineRange;
         //std::string CppCSVTikZFileExtension = ".csv\0";
         ofstream * FileGroupInClass;
         static constexpr const char* CppCSVTikZFileExtension = ".csv\0";
         void Initialize();
  public:
    ~CppCSVTikZFileGroup();
    CppCSVTikZFileGroup();
    CppCSVTikZFileGroup(std::string FileNamePrefix, int StartingLine, int EndingLine, int LinesInEachFile);
    void   SetupAndOpen(std::string FileNamePrefix, int StartingLine, int EndingLine, int LinesInEachFile);
    void   FillFirstLine(std::string FirstLineWords);
    ofstream * OutputLine(int LineNumber);
    void   OutputVariablesToLine(int LineNumber, const char* fmt...);
    void   GroupClose();
    void   Finalize();
    int    GetTotalLinesInEachFile()          { return TotalLinesInEachFile;};
    int    GetTotalFiles()                    { return TotalFiles;};
    int    GetStartingLineNumber()            { return StartingLineNumber;};
    int    GetEndingLineNumber()              { return EndingLineNumber;};
    int    GetLineNumberDirection()           { return LineNumberDirection;};
    int    GetAbsoluteLineRange()             { return AbsoluteLineRange;};
    const char * GetCppCSVTikZFileExtension() { return CppCSVTikZFileExtension;};
};


CppCSVTikZFileGroup::~CppCSVTikZFileGroup()
{    Finalize();
}


void CppCSVTikZFileGroup::Finalize(){
     int i;
     for(i=0; i < TotalFiles; i++) {
         (FileGroupInClass[i]).close();
     }
     TotalFiles = 0;
}


CppCSVTikZFileGroup::CppCSVTikZFileGroup()
{         Initialize();
}


void CppCSVTikZFileGroup::Initialize()
{         TotalLinesInEachFile = 1;
          TotalFiles = 0;
          StartingLineNumber = 0;
          EndingLineNumber = 0;
          LineNumberDirection = 1;
          AbsoluteLineRange = 0;
          FileGroupInClass = NULL;
}


CppCSVTikZFileGroup::CppCSVTikZFileGroup(std::string FileNamePrefix, int StartingLine,
                                                    int EndingLine, int LinesInEachFile)
{    SetupAndOpen(FileNamePrefix, StartingLine, EndingLine, LinesInEachFile);
}


void CppCSVTikZFileGroup::SetupAndOpen(std::string FileNamePrefix, int StartingLine,
                                                int EndingLine, int LinesInEachFile)
{    int i, j, k, prelen, existlen, tfiles;
     std::string existingname;
     std::string fullfilename;

     Initialize();

     i = 0;
     j = 0;
     while (FileNamePrefix.c_str()[i] != '\0') {
        if((FileNamePrefix.c_str()[i] != ' ') && ( FileNamePrefix.c_str()[i] != '\t')) j = 1;
        i++;
     }
     if(j == 0) {
        cout <<"In the CppCSVTikZFileGroup::CppCSVTikZFileGroup(...)/SetupAndOpen(...) " <<endl;
        cout <<"Since the FileNamePrefix is empty, this code run stopped." <<endl;
        Finalize();
        exit(0);
     }

     prelen = FileNamePrefix.length();
     CppCSVTikZFilesAndNamePrefixTemp1= HeadOfCppCSVTikZFilesAndNamePrefixes;
     CppCSVTikZFilesAndNamePrefixTemp2 = NULL;

     for(i=0; i < TotalCppCSVTikZFilesAndNamePrefixes; i++) {
         CppCSVTikZFilesAndNamePrefixTemp2 = CppCSVTikZFilesAndNamePrefixTemp1->NextPrefixes;
         existingname = CppCSVTikZFilesAndNamePrefixTemp2->TheNamePrefix;
         existlen = existingname.length();
         if(prelen == existlen) {
            if (FileNamePrefix.compare(existingname) == 0) {
               cout <<"In the CppCSVTikZFileGroup::CppCSVTikZFileGroup(...)/SetupAndOpen(...) " <<endl;
               cout << "The FileNamePrefix "<<FileNamePrefix<< " was used previously."  << endl;
               cout << "Although just a WARNING, maybe you are trying to overwrite exsisting file(s). "<< endl;
               cout << "Although just a WARNING, maybe you are trying to overwrite exsisting file(s). "<< endl;
               cout << "Although just a WARNING, maybe you are trying to overwrite exsisting file(s). "<< endl;
               //Finalize();
               //exit(0);
            }
         }
         CppCSVTikZFilesAndNamePrefixTemp1 = CppCSVTikZFilesAndNamePrefixTemp2;
     }

     CppCSVTikZFilesAndNamePrefixTemp2 = (struct CppCSVTikZFilesAndNamePrefixes*)
                      malloc(sizeof(struct CppCSVTikZFilesAndNamePrefixes));
     if(CppCSVTikZFilesAndNamePrefixTemp2 == NULL){
        cout <<"In the CppCSVTikZFileGroup::CppCSVTikZFileGroup(...)/SetupAndOpen(...) " <<endl;
        cout <<"memory allocation for CppCSVTikZFilesAndNamePrefixTemp2 failed, then stopped. " <<endl;
        Finalize();
        exit(0);
     }

     CppCSVTikZFilesAndNamePrefixTemp2->TheNamePrefix = FileNamePrefix;
     CppCSVTikZFilesAndNamePrefixTemp2->GroupFiles = NULL;
     CppCSVTikZFilesAndNamePrefixTemp2->NextPrefixes = NULL;
     CppCSVTikZFilesAndNamePrefixTemp1->NextPrefixes = CppCSVTikZFilesAndNamePrefixTemp2;
     TotalCppCSVTikZFilesAndNamePrefixes++;

     if(LinesInEachFile < 0) {
        cout <<"In the CppCSVTikZFileGroup::CppCSVTikZFileGroup(...)/SetupAndOpen(...) " <<endl;
        cout <<"the value of LinesInEachFile "<< LinesInEachFile << " is negative." <<endl;
        cout <<"Not reasonable. Then stopped." <<endl;
        Finalize();
        exit(0);
     }

     StartingLineNumber = StartingLine;
     EndingLineNumber = EndingLine;
     TotalLinesInEachFile  = LinesInEachFile;
     TotalFiles = abs(StartingLine - EndingLine) / LinesInEachFile + 1;
     LineNumberDirection = 1;
     if((EndingLine-StartingLine) < 0)
     LineNumberDirection = -1;
     AbsoluteLineRange = abs(EndingLine-StartingLine);

     FileGroupInClass = new ofstream[TotalFiles];
     for(i=0; i < TotalFiles; i++) {
         fullfilename = FileNamePrefix + to_string(i+1) + CppCSVTikZFileExtension;
         (FileGroupInClass[i]).open (fullfilename);
         if (!((FileGroupInClass[i]).is_open())) {
            cout <<"In the CppCSVTikZFileGroup::CppCSVTikZFileGroup(...)/SetupAndOpen(...) " <<endl;
            cout <<"File open for " << fullfilename <<" failed, then stopped. " <<endl;
            Finalize();
            exit(0);
         }
         cout << "File " << fullfilename << " is opened as number " << i+1 <<" . " << endl;
     }

}


void CppCSVTikZFileGroup::FillFirstLine(std::string  FirstLineWords){
     int i;
     for(i=0; i < TotalFiles; i++) {
         (FileGroupInClass[i])<< FirstLineWords <<endl;
     }
}


ofstream * CppCSVTikZFileGroup::OutputLine(int LineNumber)
{    int i,j,k;
     i = LineNumber - StartingLineNumber;
     k = abs(i);
     if( ((i*LineNumberDirection) < 0) || (k>AbsoluteLineRange) )  {
        cout <<"In the CppCSVTikZFileGroup::OutputLine(int LineNumber)" <<endl;
        cout <<"The LineNumber " << LineNumber << " is not in the range " <<endl;
        cout <<"from " << StartingLineNumber << " to " << EndingLineNumber << " ." <<endl;
        cout <<"Then stopped. " <<endl;
        Finalize();
        exit(0);
     }
     j = k / TotalLinesInEachFile;
     return &(FileGroupInClass[j]);
}


/*   The next function OutputVariablesToLine has three groups of arguments.
          The first is a single integer, which is the LineNumber.
          The second is a const string of the data types of all later arguments.
              d: integer
              c: single char
              f: float, double
              s: std::string
              Otherwise, the routine will stop.
              https://en.cppreference.com/w/cpp/language/variadic_arguments
          All the rest arguments will be outputted to the file based on the LineNumber.
          A comma will be inserted between any two. The new line "endl" will be outputted at the end.
          For example, it may be called as
          anobject.OutputVariablesToLine(LineNumber,"ddffs",
                                         totallines,i,refractiveindex,bigradius,PickTikZColor(i));
       */
void CppCSVTikZFileGroup::OutputVariablesToLine(int LineNumber, const char* fmt...)
{    int i,j,k;
     va_list args;
     va_start(args, fmt);
     i = LineNumber - StartingLineNumber;
     k = abs(i);
     if( ((i*LineNumberDirection) < 0) || (k>AbsoluteLineRange) )  {
        cout <<"In the CppCSVTikZFileGroup::OutputVariablesToLine(int LineNumber)" <<endl;
        cout <<"The LineNumber " << LineNumber << " is not in the range " <<endl;
        cout <<"from " << StartingLineNumber << " to " << EndingLineNumber << " ." <<endl;
        cout <<"Then stopped. " <<endl;
        Finalize();
        exit(0);
     }
     j = k / TotalLinesInEachFile;

     k=0;
     while (*fmt != '\0') {
        if (k > 0) FileGroupInClass[j] << ',';
        if (*fmt == 'd') {
            int i = va_arg(args, int);
            FileGroupInClass[j] << i ;
        } else if (*fmt == 'c') {
            // note automatic conversion to integral type
            int c = va_arg(args, int);
            FileGroupInClass[j] << static_cast<char>(c) ;
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            FileGroupInClass[j] << d ;
        } else if (*fmt == 's') {
            std::string s = va_arg(args, std::string);
            FileGroupInClass[j] << s ;
        } else {
            cout << "In the CppCSVTikZFileGroup::OutputVariablesToLine(int LineNumber, ...)" <<    endl;
            cout << "Only int, (single) char, double, and std::string variables are supported." << endl;
            cout << "Since others are used, stopped." << endl;
            cout << "Since others are used, stopped." << endl;
            cout << "Since others are used, stopped." << endl;
            cout << "An alternative: " << endl;
            cout << "*(CppCSVTikZFileGroup::OutputLine(int LineNumber))<< aVariable <<',' " << endl;
            cout << "            << anotherVariable <<',' ... << anotherVariable << endl; " << endl;
            cout << "may work. " << endl;
            Finalize();
            exit(0);
        }
        ++k;
        ++fmt;
     }

     FileGroupInClass[j] << endl;
     va_end(args);
}


void CppCSVTikZFileGroupInitialize()
{
     HeadOfCppCSVTikZFilesAndNamePrefixes = (struct CppCSVTikZFilesAndNamePrefixes*)
                         malloc(sizeof(struct CppCSVTikZFilesAndNamePrefixes));
     if(HeadOfCppCSVTikZFilesAndNamePrefixes == NULL){
        cout <<"In CppCSVTikZFileGroupInitialize()  " <<endl;
        cout <<"memory allocation for HeadOfCppCSVTikZFilesAndNamePrefixes failed, then stopped. " <<endl;
        Finalize();
        exit(0);
     }
     HeadOfCppCSVTikZFilesAndNamePrefixes->GroupFiles = NULL;
     HeadOfCppCSVTikZFilesAndNamePrefixes->NextPrefixes = NULL;
}


void CppCSVTikZFileGroupFinalize()
{    int i, j;
     CppCSVTikZFilesAndNamePrefixTemp1= HeadOfCppCSVTikZFilesAndNamePrefixes;
     CppCSVTikZFilesAndNamePrefixTemp2 = NULL;
     for(i=0; i<=TotalCppCSVTikZFilesAndNamePrefixes; i++) {
         CppCSVTikZFilesAndNamePrefixTemp2 = CppCSVTikZFilesAndNamePrefixTemp1->NextPrefixes;
         free(CppCSVTikZFilesAndNamePrefixTemp1);
         CppCSVTikZFilesAndNamePrefixTemp1 = CppCSVTikZFilesAndNamePrefixTemp2;
     }
     TotalCppCSVTikZFilesAndNamePrefixes = 0;
}


#endif


