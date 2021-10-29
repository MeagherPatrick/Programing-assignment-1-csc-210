#include "Head.h"


int main()
{
  ifstream fin;
  student_Type student_Info[MAX_NUM_STUDENTS];
  credit_Hours credits[MAX_NUM_CLASSES];
  
  int I = 0;

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
void file_Read(int I, ifstream& fin, student_Type student_Info[], credit_Hours credits[MAX_NUM_CLASSES])
{
  int test_grade;
  read_Credit_Hours(I, credits);
  while (fin) 
  {
    int i = 0;
    fin >> student_Info[i].first_Name 
        >> student_Info[i].last_Name 
        >> student_Info[i].id 
        >> student_Info[i].num_Classes;
    
    for (int x = 0; x < student_Info[i].num_Classes; x++)
    {
      fin >> student_Info[i].class_Name[x] 
          >> student_Info[i].grades[x];
      //cout << student_Info[i].grades[x] << '\n';
    }
      int g = grade_clac(i, credits, student_Info);  
   
    i++;
    
  }
}
void read_Credit_Hours(int I, credit_Hours credits[MAX_NUM_CLASSES])
{
  ifstream fin2;
  fin2.open("classHours.txt");
  for (int i = 0; i < MAX_NUM_CLASSES; i++) {
    fin2 >> credits[i].course[i] >> credits[i].credits[i];
  } 
}

int grade_clac(int I, credit_Hours credit[MAX_NUM_CLASSES], student_Type student[MAX_NUM_STUDENTS])
{
  int total_credits=0;
  double gpa = 0;
  for (int i=0; i < student[I].num_Classes; i++) 
  {      
         
    for (int x = 0; x < MAX_NUM_CLASSES; x++) {
      if (student[I].class_Name[i] == credit[x].course[x]) {

        switch (student[I].grades[i]) {
          case 'A':
            total_credits += 4 * credit[x].credits[x];
            break;
          case 'B':
            total_credits += 3 * credit[x].credits[x];
            break;
          case 'C':
            total_credits += 2 * credit[x].credits[x];
            break;
          case 'D':
            total_credits += 1 * credit[x].credits[x];
            break;
          case 'F':
            total_credits += 0;
            break;
        }
        gpa = (double)total_credits / student[I].num_Classes;
        
      }
      
    }
    }
  cout << student[I].first_Name   
       << " ";
  cout << "gpa " << total_credits 
       << " / "
       << student[I].num_Classes  
       << " = " << showpoint << gpa << '\n';
  return gpa;
}
    /*       
    

    //I = &i;
// cout << student_Info[i].first_Name << " " << student_Info[i].last_Name << " " << student_Info[i].id << " " << student_Info[i].num_Classes;
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