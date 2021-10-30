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
  
    while (fState == 0) 
    {
      cout << "Please enter a student file to open: \n";
      cin >> fName;
      fin_1.open(fName);
      fState = file_State(fin_1,fName);
    }
    fState = 0;
    while (fState == 0) 
    {
      cout
        << "Please enter a file with class and number of cedits to open: \n";
      cin >> fName;
      fin_2.open(fName);
      fState = file_State(fin_2, fName);
    }
    fState = 0;
    while (fState == 0) {
      cout
        << "Please enter a name for your output file: \n";
      cin >> fName;
      fout.open(fName);
      fState = outFile_State(fout, fName);
    }
    fState = 0;
    while (fState == 0) {
      cout << "Program logs files will be stored in logFile.txt \n";
      
      lout.open("logFile.txt");
      fState = file_State(fin_2, fName);
    }
}
void file_Read(int I, ifstream& fin_1, ifstream& fin_2, ofstream& fout, ofstream& lout,
    student_Type student_Info[], credit_Hours credits[])
{
  string s;
  int test_grade;
  read_Credit_Hours(I, credits,fin_2 );
  ///*int i = 0;
  //
  //I = i;
  //fin_1 >> student_Info[i].first_Name >> student_Info[i].last_Name >>
  //  student_Info[i].id >> student_Info[i].num_Classes;

  //for (int x=0; x < student_Info[i].num_Classes; x++) {
  //  fin_1 >> student_Info[i].class_Name[x] >> student_Info[i].grades[x];
  //}*/
  //grade_clac(I, credits, student_Info);
  //output(I, fout, lout, student_Info);
  int i = 0;
   cout << '\n' << s;
  while (getline(fin_1,s)) 
  {
   I = i;
    cout << '\n' << i << '\n';
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
    output(I, fout, lout,student_Info);
    i++;
    /*cout << '\n';
    cout << student_Info[I].first_Name << ", " << student_Info[I].last_Name << ", "
        << student_Info[I].id << ", " << showpoint << student_Info[I].gpa << '\n';*/
  }
}
void read_Credit_Hours(int I, credit_Hours credits[MAX_NUM_CLASSES], ifstream & fin_2)
{
   for (int i = 0; i < MAX_NUM_CLASSES; i++)
        fin_2 >> credits[i].course[i] >> credits[i].credits[i];
}
void grade_clac(int I, credit_Hours credit[MAX_NUM_CLASSES], student_Type student[MAX_NUM_STUDENTS])
{
  int total_Credits = 0;
  int possible_Credits = 0;
  double gpa = 0;
  for (int i=0; i < student[I].num_Classes; i++) 
  {      
    for (int x = 0; x < MAX_NUM_CLASSES; x++) {
      if (student[I].class_Name[i] == credit[x].course[x]) {
        possible_Credits += credit[x].credits[x];

        switch (student[I].grades[i]) {
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
        gpa_calc(I, total_Credits, possible_Credits, student);
        
      }
    }
  }
  
}
bool file_State(ifstream & fin_, string fname)
{
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
void file_Close(ifstream& fin_1, ifstream& fin_2, ofstream& fout,
                ofstream& lout)
{
  string placeHolder = "oh no";
  bool fState;
  fin_1.close();
  fin_2.close();
  fout.close();
  lout.close();
  //fState = file_State(fin_1, placeHolder);
  //if (fState == 1)
  //  cout << "A file did not close \n";

}
void gpa_calc(int I, int total_Credits, int possible_Credits, student_Type student[MAX_NUM_STUDENTS])
{
  student[I].gpa = (double)total_Credits / possible_Credits;

}
void output(int I, ofstream& fout, ofstream& lout, student_Type student[MAX_NUM_STUDENTS])
{
  cout << student[I].first_Name << ", " << student[I].last_Name << ", "
       << student[I].id << ", " << showpoint << student[I].gpa << '\n';
}
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