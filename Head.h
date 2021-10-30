#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const int MAX_NUM_CLASSES = 15;
const int MAX_NUM_STUDENTS = 20;

struct student_Type {
  string first_Name;
  string last_Name;
  int id;
  int num_Classes;
  double gpa;
};
struct credit_Hours
{
  string course[MAX_NUM_CLASSES];
  int credits[MAX_NUM_CLASSES];

};
void file_Open(ifstream &fin_1, ifstream& fin_2, ofstream& fout, ofstream& lout);
// Function to open file
// 
// preconditions:fin_1, fin_2, fout, and lout  must be passed to function
// 
// Postcondition: fin_1, fin_2, fout, and lout must open;
//               
void file_Read(int, ifstream& fin_1, ifstream& fin_2, ofstream& fout,
               ofstream& lout, student_Type[], credit_Hours[]);
// Function to read input files and store data in student_type struct and credit_Hours struct.
//  
// preconditions: fin_1, fin_2, fout, and lout must open
//				stuct for student_Type and credit_Hours must be created	  	
// Postcondition: data from fin_1 has been written to struct of student_Type
//				 data from fin_2 has been written to struct of credit_Hours
void read_Credit_Hours(int, credit_Hours[], ifstream & fin_2, ofstream& lout);
// Function to read input from fin_2 and store in credit_Hours struct.
// 
// preconditions: int I must contain the value of the counter in function read_File
//				 fin_2,  and lout must open
//				stuct credit_Hours must be created
// Postcondition: data from fin+2 has been written to struct of credit hours

void grade_clac(int I, credit_Hours credit[], student_Type student[], ofstream& lout,
                string class_taken[MAX_NUM_CLASSES], char class_grade[MAX_NUM_CLASSES]);
// Function to clac total credits taken and received for each student in struct student
//
// preconditions: int I must contain the value of the counter in function read_File
//				lout must open
//				stuct credit_Hours and student type must have filled
// Postcondition: the counter I must be passed to function gpa_calc
//				  total_credits must contain all credit hours for each student to pass to gpa_calc
//				 possible_credit must contain all possible credit hours for each student to pass to gpa_calc
bool file_State(ifstream& fin_, string fname, ofstream& lout);
// Function to check input file state
//
// preconditions: pass the inout file for testing
//				 fname should contaion the name of the file
//				lout should be passed for logging
// Postcondition: fin_ must be open.

bool outFile_State(ofstream& out_, string fname);
// Function to check output file state
//
// preconditions: pass the ouput file for testing
//				 fname should contaion the name of the file
//				lout should  NOT be passed into this function
// Postcondition: out_ must be open.
void file_Close(ifstream& fin_1, ifstream& fin_2, ofstream& fout,ofstream& lout);
// Function to close file
//
// preconditions: must contain 2 input files and 2 output files
// Postcondition: all files muist be close.
void gpa_calc(int I, int total_Credits, int possible_Credits, student_Type student[], ofstream& lout);
// Function to clac gpa for each student in struct student_Type
//
// preconditions: int I must contain the value of the counter in function read_File
//				lout must open
//				student type must have filled
//			     total_credits must contain all credit hours for current student to pass to gpa_calc
//				 possible_credit must contain all possible credit hours for current student
//
// Postcondition: gpa will stored  in student struct
// 				 

void output(int, ofstream& fout, ofstream& lout, student_Type student[]);
// Function to output results
//
// preconditions: int I must contain the value of the counter in functionread_File
//				 fout  and lout must open
//				stuct credit_Hours must be filled
//
// Postcondition: datat will be outputed to the console, a text file.
void header_output(int,ofstream&fout, ofstream& lout);
