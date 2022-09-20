#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {

  // declare variables
  string FirstName;
  string date;
  int TestResult;
  int count = 0;
  int cumulative_cases = 0;

  // declare stream variables
  ifstream inFile;  // need to access the file we want to load
  ofstream outFile; // needed to sace the results of the analysis

  // open the input file
  inFile.open("TestResultsData.dat");

  // reaad in the data - first line of the file
  inFile >> date;
  cout << date << endl;

  // read in the 2 pieces of info on the second line
  inFile >> FirstName;
  cout << FirstName << ' ';
  inFile >> TestResult;
  cout << TestResult << endl;
}