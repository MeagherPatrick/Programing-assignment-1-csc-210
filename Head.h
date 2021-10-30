#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int MAX_NUM_CLASSES = 15;
const int MAX_NUM_STUDENTS = 20;

struct student_Type {
  string first_Name;
  string last_Name;
  int id;
  int num_Classes;
  string class_Name[MAX_NUM_CLASSES];
  char grades[12];
  double gpa;
};
struct credit_Hours
{
  string course[MAX_NUM_CLASSES];
  int credits[MAX_NUM_CLASSES];

};
void file_Open(ifstream &fin_1, ifstream& fin_2, ofstream& fout, ofstream& lout);
void file_Read(int, ifstream& fin_1, ifstream& fin_2, ofstream& fout, ofstream& lout, student_Type[], credit_Hours[]);
void read_Credit_Hours(int, credit_Hours[], ifstream & fin_2);
void grade_clac(int I, credit_Hours credit[], student_Type student[]);
bool file_State(ifstream & fin_, string fname);
bool outFile_State(ofstream& out_, string fname);
void file_Close(ifstream& fin_1, ifstream& fin_2, ofstream& fout,ofstream& lout);
void gpa_calc(int I, int total_Credits, int possible_Credits, student_Type student[]);
void output(int, ofstream& fout, ofstream& lout, student_Type student[]);