#include "Head.h"


int main()
{
  ifstream fin_1,fin_2;
  ofstream lout;
  student_Type student_Info[MAX_NUM_STUDENTS];
  credit_Hours credits[MAX_NUM_CLASSES];
  
  int I = 0;

  file_Open(fin_1, fin_2, lout);
  file_Read(I, fin_1,student_Info,credits);
}
void file_Open(ifstream& fin_1,ifstream& fin_2, ofstream& lout)
{
  int fState = 0;
      string fName;
  while (fState = 0) {
    while (fState = 0) {

      cout << "Please enter a student file to open : \n";
      cin >> fName;
      fin_1.open(fName);
      fState = file_State(fin_1,fName);
    }

    cout << "Please enter a file with class and number of cedits to open : \n";
    cin >> fName;
    fin_2.open(fName);
  }
}

void file_Read(int I, ifstream& fin_1, student_Type student_Info[], credit_Hours credits[MAX_NUM_CLASSES])
{
  int test_grade;
  read_Credit_Hours(I, credits);
  while (fin_1) 
  {
    int i = 0;
    fin_1 >> student_Info[i].first_Name 
        >> student_Info[i].last_Name 
        >> student_Info[i].id 
        >> student_Info[i].num_Classes;
    
    for (int x = 0; x < student_Info[i].num_Classes; x++)
    {
      fin_1 >> student_Info[i].class_Name[x] 
          >> student_Info[i].grades[x];
      //cout << student_Info[i].grades[x] << '\n';
    }
      student_Info[i].gpa = grade_clac(i, credits, student_Info);  
  cout << student_Info[i].first_Name 
      << showpoint 
      << student_Info[i].gpa << '\n';
   
    i++;
    
  }
}
void read_Credit_Hours(int I, credit_Hours credits[MAX_NUM_CLASSES])
{
  ifstream fin_12;
  fin_12.open("classHours.txt");
  for (int i = 0; i < MAX_NUM_CLASSES; i++) {
    fin_12 >> credits[i].course[i] >> credits[i].credits[i];
  } 
}

double grade_clac(int I, credit_Hours credit[MAX_NUM_CLASSES], student_Type student[MAX_NUM_STUDENTS])
{
  int total_credits = 0;
  int possible_Credits = 0;
  double gpa = 0;
  for (int i=0; i < student[I].num_Classes; i++) 
  {      
         
    for (int x = 0; x < MAX_NUM_CLASSES; x++) {
      if (student[I].class_Name[i] == credit[x].course[x]) {
        possible_Credits += credit[x].credits[x];
    

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
        gpa = (double)total_credits /possible_Credits;
        
      }
      
    }
    }
  return gpa;
}
int file_State(ifstream & fin_, string fname)
{
  if (!fin_.is_open()) {
    cout << "The last input file you entered did not open" << '\n';
    return 0;
  } 
  return 1;

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