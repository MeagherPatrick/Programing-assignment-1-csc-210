#include <iostream>
#include <fstream>
#include <string>
using namespace std;



struct student_Type {
  string first_Name;
  string middle_Name;
  string last_Name;
  int id;
  int num_classes;
  double gpa;
};
int file_Open(ifstream& fin);
void file_Read(ifstream& fin, student_Type[]);