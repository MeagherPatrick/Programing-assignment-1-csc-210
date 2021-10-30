#include "Head.h"


int main()
{
  ifstream fin_1,fin_2;
  ofstream fout,lout;
  student_Type student_Info[MAX_NUM_STUDENTS];
  credit_Hours credits[MAX_NUM_CLASSES];
  int I = 0;

  file_Open(fin_1, fin_2,fout , lout);  
  file_Read(I, fin_1, fin_2, fout, lout, student_Info, credits);
  file_Close(fin_1, fin_2, fout, lout);
  return 0;
}
void file_Open(ifstream& fin_1,ifstream& fin_2, ofstream& fout, ofstream& lout)
{
  bool fState = 0;
  string fName;
    if (fState == 0) 
    {
      cout << "Program logs files will be stored in logFile.txt \n";      
      lout.open("logFile.txt");
      lout << "Function file_Open has started \n logFile.txt has been opened \n Entering outFile_State \n";
      fState = outFile_State(lout, fName);
      lout << "Exited function outFile_State reutrning to calling function file_Open"
      << '\n';
    }
    fState = 0;
      
    while (fState == 0) 
    {
      cout << "Please enter a student file to open: \n";
      cin >> fName;
      fin_1.open(fName);
      fState = file_State(fin_1,fName,lout);
      lout << "Exited function file_State reutrning to calling function file_Open" << '\n';
    }
    fState = 0;
    while (fState == 0) 
    {
      cout
        << "Please enter a file with class and number of cedits to open: \n";
      cin >> fName;
      fin_2.open(fName);
      fState = file_State(fin_2, fName, lout);
      lout
        << "Exited function file_State reutrning to calling function file_Open"
        << '\n';
    }
    fState = 0;
    while (fState == 0) {
      cout
        << "Please enter a name for your output file: \n";
      cin >> fName;
      fout.open(fName);
      lout << "Entering outFile_State " << '\n';
      fState = outFile_State(fout, fName);
      lout
        << "Exited function outFile_State reutrning to calling function file_Open"
        << '\n';
    }
    lout << "Exiting function file_Open" << '\n';
    }
void file_Read(int I, ifstream& fin_1, ifstream& fin_2, ofstream& fout, ofstream& lout, student_Type student_Info[], credit_Hours credits[])
{
  string class_taken[MAX_NUM_CLASSES];
    char class_grade[MAX_NUM_CLASSES];
  lout << "Entered function file_Read." << '\n';
  int i = 0;
     I = i;
 read_Credit_Hours(I, credits,fin_2, lout);
     lout << "Exited function read_Credit_Hours. \n Returned to function file_Read" << '\n';
 string s;
 fin_1 >> student_Info[i].first_Name >> student_Info[i].last_Name >>
   student_Info[i].id >> student_Info[i].num_Classes;

 for (int x = 0; x < student_Info[i].num_Classes; x++) {
   fin_1 >> class_taken[x] >> class_grade[x];
 }
 header_output(i,fout,lout);
 lout << "Exited function header_output. \n Returned to function file_Read \n";
 do {
   grade_clac(I, credits, student_Info, lout, class_taken, class_grade);
   lout << "Exited function grade_clac. \n Returned to function file_Read \n";
     
 output(I, fout, lout, student_Info);
   lout
     << "Exited function output. \n Returned to function file_Read"
     << '\n';
   i++;
 I = i;
   lout << "reading line " << i + 1 << '\n';
    fin_1 >> student_Info[i].first_Name >> student_Info[i].last_Name >>
      student_Info[i].id >> student_Info[i].num_Classes;
    for (int x = 0; x < student_Info[i].num_Classes; x++) {
      fin_1 >> class_taken[x] >> class_grade[x];
    }
 } while (fin_1);
 lout << "Exited function file_Read" << '\n';
}
void read_Credit_Hours(int I, credit_Hours credits[MAX_NUM_CLASSES], ifstream & fin_2, ofstream& lout)
{
  lout << "Entering function read_Credit_Hours" << '\n';
  for (int i = 0; i < MAX_NUM_CLASSES; i++) {

    fin_2 >> credits[i].course[i] >> credits[i].credits[i];
    lout << "reading line " << i + 1 << '\n';
  }
   
}
void grade_clac(int I, credit_Hours credit[MAX_NUM_CLASSES],student_Type student[MAX_NUM_STUDENTS], ofstream& lout,
                string class_taken[MAX_NUM_CLASSES], char class_grade[MAX_NUM_CLASSES])
{
  lout << "Entered function grade_clac." << '\n';
  int total_Credits = 0;
  int possible_Credits = 0;
  double gpa = 0;
  for (int i=0; i < student[I].num_Classes; i++) 
  {      
    for (int x = 0; x < MAX_NUM_CLASSES; x++) {
      if (class_taken[i] == credit[x].course[x]) {
        possible_Credits += credit[x].credits[x];

        switch (class_grade[i]) {
          case 'A':
            total_Credits += 4 * credit[x].credits[x];
            break;
          case 'B':
            total_Credits += 3 * credit[x].credits[x];
            break;
          case 'C':
            total_Credits += 2 * credit[x].credits[x];
            break;
          case 'D':
            total_Credits += 1 * credit[x].credits[x];
            break;
          case 'F':
            total_Credits += 0;
            break;
        }
        
        gpa_calc(I, total_Credits, possible_Credits, student, lout);
        lout << " Exited function gpa_calc. \n Returned to function grade_calc \n";
        
      }
    }
  }
  
}
bool file_State(ifstream & fin_, string fname, ofstream& lout)
{
  lout << "Entered function file_State." << '\n';
  if (!fin_.is_open()) {
    cout << fname << "  is not open." << '\n';
    return 0;
  } 
  return 1;

}
bool outFile_State(ofstream& out_, string fname)
{
  
  if (!out_.is_open()) {
    cout << fname << "  is not open." << '\n';
    return 0;
  }
  return 1;  
}
void gpa_calc(int I, int total_Credits, int possible_Credits, student_Type student[MAX_NUM_STUDENTS], ofstream& lout)
{
  lout << "Entered function gpa_clac." << '\n';
  student[I].gpa = (double)total_Credits / possible_Credits;
}
void output(int I, ofstream& fout, ofstream& lout, student_Type student[MAX_NUM_STUDENTS])
{
  lout << "Entered function output." << '\n';
  cout << '\n';
  cout << left << setw(15) << student[I].first_Name << setw(15)
       << student[I].last_Name << setw(15) << student[I].id << setw(15)
       <<fixed << setprecision(2)
      << student[I].gpa << '\n';
  fout << '\n';
  fout << left << setw(15) << student[I].first_Name << setw(15)
       << student[I].last_Name << setw(15) << student[I].id << setw(15)
       << fixed << setprecision(2) << student[I].gpa << '\n';
}
void file_Close(ifstream& fin_1, ifstream& fin_2, ofstream& fout,ofstream& lout)
{
  lout << "Entered function file_Close. \n Log file will now be close with "
          "all other files.";
  fin_1.close();
  fin_2.close();
  fout.close();
  lout.close();

}
void header_output(int i, ofstream& fout, ofstream& lout)
{
  lout << "Entered function header_output." << '\n';
  lout << "reading line " << i + 1 << '\n';
  cout << '\n'
       << "------------------------------------------------------------- \n"
       << left << setw(15) << "First Name" << setw(15) << "last Name"
       << setw(15) << "ID" << setw(15) << "GPA ";
  cout << '\n'
       << "------------------------------------------------------------- \n";
  fout << '\n'
       << "------------------------------------------------------------- \n"
       << left << setw(15) << "First Name" << setw(15) << "last Name"
       << setw(15) << "ID" << setw(15) << "GPA ";
  fout << '\n'
       << "------------------------------------------------------------- \n";
}
//  cout << '\n' << I << '\n';
// cout << "this is i in the do: " << i << '\n';
   // grade_clac(I, credits, student_Info);
 // output(I, fout, lout, student_Info);
    /*cout << '\n';
    cout << student_Info[I].first_Name << ", " << student_Info[I].last_Name << ", "
        << student_Info[I].id << ", " << showpoint << student_Info[I].gpa << '\n';*/
//  }
 // cout << "this is I: " << I << '\n';
    /*       
    
    //I = &i;

       // cout << I << '\n';

    //cout << credits[i].course[i] << " " << credits[i].credits[i] << '\n';
    //<< " , ";
    //cout << "this is the number of classes"<< student[I].num_Classes << '\n';
       // cout << "this is I.... " << I << '\n';
  //cout << "this is I ----" << I << '\n';
       // cout << "this is credit[x].course[x]:  " << credit[x].course[x];
     // cout << "this is i.. " << i << '\n';
   // cout << "HERE" << credits[i].course[i] << '\n';
            
      */
  //fState = file_State(fin_1, placeHolder);
  //if (fState == 1)
  //  cout << "A file did not close \n";

/*{
    i++;
   I = i;
    fin_1 >> student_Info[i].first_Name
        >> student_Info[i].last_Name
        >> student_Info[i].id
        >> student_Info[i].num_Classes;

    for ( int x=0; x < student_Info[i].num_Classes; x++)
    {
      fin_1 >> student_Info[i].class_Name[x]
          >> student_Info[i].grades[x];
    }

    grade_clac(I, credits, student_Info);
    output(I, fout, lout,student_Info);*/