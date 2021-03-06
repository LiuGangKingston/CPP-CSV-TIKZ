# CPP-CSV-TIKZ
To use C++ computing and Tikz drawing powers together.

     Gang Liu (gl.cell@outlook, http://orcid.org/0000-0003-1575-9290)
          and
     Shiwei Huang (huang937@gmail.com)
     
It is absolutely a good idea to combine FORTRAN or C or C++ or Python or Java or Kotlin computing functionality and Tikz drawing powers. To do this, we may use one of these popular languages to perform all key computations, then output all needed results into CSV files. Since Latex/Tikz can read CSV data files, it can use the data to draw figures accordingly. For the six languages, we have separate specific repositories: 

     https://github.com/LiuGangKingston/FORTRAN-CSV-TIKZ.git
     https://github.com/LiuGangKingston/C-CSV-TIKZ.git
     https://github.com/LiuGangKingston/CPP-CSV-TIKZ.git
     https://github.com/LiuGangKingston/PYTHON-CSV-TIKZ.git
     https://github.com/LiuGangKingston/JAVA-CSV-TIKZ.git
     https://github.com/LiuGangKingston/KOTLIN-CSV-TIKZ.git

While all of them are equivalent to each other, this is the C++ version. 

By using the template file or any example, users only need to code the part source code for their specific computing work. Our source code not only offers all the rest necessary part to build the complete code, but also provides additional facilities. For example, the function "PickTikZColor(i)" returns a TikZ color for any input integer "i", which can be used to add various colors to iteratively calculated drawings. 

In Latex/TikZ, we will use the "CSVSIMPLE" package. Since it supports the option "[head to column names]" in the command "\csvreader", the CSV files are better generated with all names for the data columns as the first line. As "CSVSIMPLE" documented, any pair of neighbor names must be separated by the comma ",", with no other character (even a space) being permitted, in the first line. Once it is generated properly, the command

     \csvreader[head to column names] {THE CSV FILE} {}  
     {
      ... DRAW ANYTHING HERE ...
     }

in a tex file can read it, and automatically get macros in form of "\COLUMNNAME" set for all comlumn data. Another caution is to avoid "," at the end of any line of the CSV files. In fact, the above command also invokes an iteration: to apply data line by line to perform the corresponding work of "{... DRAW ANYTHING HERE ...}". 

As in our example01, two CSV files are generated: 

    "setup.scalars.csv"
    "iterated.alldata.csv"

The first contains data computed only one-time for figure setup. The second one contains all itereated data for drawing more than one similar things in the example. To avoid problems, all data needed for "DRAW ANYTHING HERE" in the command

    \csvreader[head to column names]{iterated.alldata.csv}  {}  {... DRAW ANYTHING HERE ...}

are outputted to the "iterated.alldata.csv" file, including those which were already outputted into previous CSV files. 

In the head file CppCSVTikZ.h, coded "Class CppCSVTikZFileGroup" can make it easy to split a large amount of data then output them into a group of CSV files, and another large amount of data into another group of CSV files, and another another, unlimited. Hope this is helpful to reduce hardware memory requirement, supposing data can be used part by part during Latex file being processed. As an example, it may be done as:

    int  i, startingline=1, totallines=500, datalinesineachfile=50;
    double  morevariables;
    ...
    
    // In the next object creation, the files "iterated.alldata.1.csv", 
    //                                        "iterated.alldata.2.csv", 
    //                                        "iterated.alldata.3.csv", 
    //                                        ..., 
    //                                        till the last needed one
    // will also be opened:
    CppCSVTikZFileGroup bigfile("iterated.alldata.",startingline,totallines,datalinesineachfile);

    // The next routine call will output the long string into all the above files as the top line:
    bigfile.FillFirstLine("variablenamesseperatebycommaswithoutanythingelse");

    for(i=startingline; i<=totallines; i++) {
        ...

    /*    The next function OutputVariablesToLine has three groups of arguments.
          The first is a single integer, which is the LineNumber.
              It must be from "startingline" to "totallines", as used when the object was created.
          The second is a const string of indicators for the data types of all later arguments.
              d: integer
              c: single char
              f: float, double
              s: std::string
              Otherwise, the routine will stop.
              Related webpage: https://en.cppreference.com/w/cpp/language/variadic_arguments
          All the rest arguments will be outputted to the file based on the LineNumber, 
          where a comma will be inserted between any two and the end-of-line "endl" will be 
          added at the end.
          HOWEVER, TESTS SHOW THAT ALL std::string TYPE VARIABLES MUST BE THE LAST ONES.
          For example, 
    */
       
    bigfile.OutputVariablesToLine(i,"ddfffffffffffffffffffs",
                                     totallines,i,refractiveindex,bigradius,a,b,z,anglez,c,anglea,
                                     incidentangle,refractiveangle,anglede,dx,ee,et,ex,ey,anglece,
                                     angleced,outangle, PickTikZColor(i));

    /*   The following is an alternative to do the same, which should always work:
    *(bigfile.OutputLine(i))<< totallines<< ',' << i<< ',' << refractiveindex<< ',' << bigradius<< ','
                  << a<< ',' << b << ',' << z<< ',' << anglez<< ',' << c << ',' << anglea << ','
                  << incidentangle << ',' << refractiveangle << ',' << anglede << ',' << dx << ','
                  << ee<< ',' << et << ',' << ex << ',' << ey << ',' << anglece << ',' << angleced << ','
                  << outangle << ',' << PickTikZColor(i) << endl; */
    }
    
    
    
It is used in example01.500beams.data.split and example02.ellipsoidal. 



