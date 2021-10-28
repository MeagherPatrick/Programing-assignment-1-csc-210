#include "Head.h"


int main()
{
  ifstream fin;
  student_Type student_Info[MAX_NUM_STUDENTS];

  file_Open(fin);
  file_Read(fin,student_Info);
}
int file_Open(ifstream& fin)
{
  string infile_Name;
  cout << " Please enter the file name to open : \n";
  cin >> infile_Name;
  cout << " '\n' You entered: " << infile_Name << '\n';

  fin.open(infile_Name);
  if (!fin.is_open()) {
    cout << "error could not open file. \n program will now shut down. \n";
    return -1;
  } else
    return 1;
}
void file_Read(ifstream& fin, student_Type student_Info[])
{
  while (fin) {

    int i = 0;
    fin >> student_Info[i].first_Name 
        >> student_Info[i].last_Name 
        >> student_Info[i].id 
        >> student_Info[i].num_Classes;
// cout << student_Info[i].first_Name << " " << student_Info[i].last_Name << " " << student_Info[i].id << " " << student_Info[i].num_Classes;
    
    for (int x = 0; x < student_Info[i].num_Classes; x++) {
      fin >> student_Info[i].class_Name[x] 
          >> student_Info[i].grades[x];
// cout << student_Info[i].class_Name[x] << " "  << student_Info[i].grades[x];
    }
    i++;
//cout << '\n';
      
  }
}