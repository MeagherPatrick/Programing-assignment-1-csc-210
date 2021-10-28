#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_NUM_CLASSES = 15;
const int MAX_NUM_STUDENTS = 20;

struct student_Type {
  string first_Name;
  string middle_Name;
  string last_Name;
  int id;
  int num_Classes;
  string class_Name[MAX_NUM_CLASSES];
  int grades[12];
  double gpa;
};
struct credit_Hours
{
  string course[MAX_NUM_CLASSES];
  int credits[MAX_NUM_CLASSES];

};
void file_Open(ifstream& fin);
void file_Read(int*, ifstream& fin, student_Type[], credit_Hours[]);
void read_Credit_Hours(int*, credit_Hours[]);
int grade_clac(int*, credit_Hours[], student_Type[]);