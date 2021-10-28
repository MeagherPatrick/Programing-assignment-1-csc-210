#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_NUM_CLASSES = 4;
const int MAX_NUM_STUDENTS = 5;

struct student_Type {
  string first_Name;
  string middle_Name;
  string last_Name;
  int id;
  int num_Classes;
  string class_Name[MAX_NUM_CLASSES];
  char grades[3];
  double gpa;
};
int file_Open(ifstream& fin);
void file_Read(ifstream& fin, student_Type[]);