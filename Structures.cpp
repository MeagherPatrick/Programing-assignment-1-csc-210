#include "Head.h"


int main()
{
  ifstream fin;
  student_Type student_Info[MAX_NUM_STUDENTS];
  credit_Hours credits[MAX_NUM_CLASSES];
  int *I;

  file_Open(fin);
  file_Read(I, fin,student_Info,credits);
}
void file_Open(ifstream& fin)
{
  string infile_Name;
  cout << " Please enter the file name to open : \n";
  cin  >> infile_Name;
  cout << " '\n' You entered: " 
       << infile_Name << '\n';

  fin.open(infile_Name);
  if (!fin.is_open()) 
    cout << "error could not open file. \n program will now shut down. \n";
    exit;
  }
void file_Read(int *I, ifstream& fin, student_Type student_Info[], credit_Hours credits[MAX_NUM_CLASSES])
{
  int test_grade;
  while (fin) 
  {
    int i = 0;
    fin >> student_Info[i].first_Name 
        >> student_Info[i].last_Name 
        >> student_Info[i].id 
        >> student_Info[i].num_Classes;
// cout << student_Info[i].first_Name << " " << student_Info[i].last_Name << " " << student_Info[i].id << " " << student_Info[i].num_Classes;
    
  read_Credit_Hours(I, credits);
    for (int x = 0; x < student_Info[i].num_Classes; x++)
    {
      fin >> student_Info[i].class_Name[x] 
          >> student_Info[i].grades[x];
      
    I = &i;
      
    }
    i++;
    cout << I << '\n';
  }
}
     /* cout << " this is the credit for " 
           << student_Info[i].class_Name 
           << " "
           << student_Info[i].grades[x];*/
    // cout << student_Info[i].class_Name[x] << " "  << student_Info[i].grades[x];
void read_Credit_Hours(int *I, credit_Hours credits[MAX_NUM_CLASSES])
{
   /* cout << credits[i].course[i] << " " << credits[i].credits[i] << '\n';*/
  ifstream fin2;
  fin2.open("classHours.txt");
  for (int i = 0; i < MAX_NUM_CLASSES; i++) {
    fin2 >> credits[i].course[i] >> credits[i].credits[i];
  } 
  
}

int grade_clac(int* I, credit_Hours[], student_Type[])
{
  return 0;
}