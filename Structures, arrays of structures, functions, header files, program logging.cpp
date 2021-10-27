#include "Head.h"


int main()
{
  ifstream fin;
  
  file_Open(fin);
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
    
    int i=0;
    fin >> student_Info[i].first_Name >> student_Info[i].last_Name >>
      student_Info[i].
    i++;
  }
}