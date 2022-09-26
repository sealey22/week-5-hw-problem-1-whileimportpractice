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

  // open the output file
  outFile.open("AnalyzeData.txt");

  // reaad in the data - first line of the file
  inFile >> date;
  cout << date << endl;
  
  // add date to the ouptu file as the first line
  outFile << date << endl;

  // read in the 2 pieces of info on the second line
  inFile >> FirstName;
  cout << FirstName << ' ';
  inFile >> TestResult;
  cout << TestResult << endl;

  while (inFile) {
    // update number of cases and persons tested
    cumulative_cases = cumulative_cases + TestResult;
    count++; // increment the number of patients

    // read in the next line
    inFile >> FirstName;
    inFile >> TestResult;
  }

  //cout << count << endl;
  //cout << cumulative_cases << endl;

  // report cases and tested persons 
  outFile << "Number of persons tested = " << count << " ";
  outFile << "\nTotal number of cases = " << cumulative_cases << " ";

  // report precalence as % with 2 decimals
  outFile << fixed << showpoint << setprecision(2);
  outFile << "The prevelence is ";
  outFile << ((static_cast<double>(cumulative_cases)) / count) * 100;
  outFile << " %" << endl;

  // close the input and output file
  inFile.close();
  outFile.close();
}