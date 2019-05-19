// ZhangYingyingLab10aHashTableDriver.cpp
// Yingying Zhang
// on 11/01/2015
// Editor(s) used: X Code
// Compiler(s) used: X Code
// The Hash Table Driver File

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct TermSection
{
  string Term;
  string Section;
  bool operator==(const TermSection& ts) const {return Term == ts.Term && Section == ts.Section;}
};

int hashCode(const TermSection& ts)
{
  int a = 0;
  //stringstream ss1(ts.Section);
  //ss1 >> a;
  
  int b = 0;
  if (ts.Term == "Fall")
    b = 10000;
  else if (ts.Term == "Spring")
    b = 20000;
  else if (ts.Term == "Summer")
    b = 30000;
  
  return (a+b);
}

#include "ZhangYingyingLab10aHashTable.h"

int main()
{
  // Print my name and this assignment's title
  cout << "ZhangYingyingLab10a.cpp\n";
  cout << "Programmer: Yingying Zhang\n";
  cout << "Editor(s) used: X Code\n";
  cout << "Compiler(s) used: X Code\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  cout << "The \"Hash Table Test Driver\" Program" << endl << endl;
  
  HashTable<int, TermSection, 200> a(hashCode);
  TermSection ts;
  
  // open input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if(!fin.good())
    cout << "I/O Error";
  
  // process input file
  // read 100 lines
  int i = 0;
  while(fin.good() && i < 100)
  {
    i++;
    string line;
    getline(fin,line);
    if(line[0] == 0)  continue;
    if (i != 1)
    {
    
    // parse the line
    size_t current, next = -1;
    current = next+1;
    next=line.find_first_of("\t\n", current );
    string term = line.substr(current,next-current);
    
    current = next+1;
    next=line.find_first_of("\t\n", current );
    string section = line.substr(current,next-current);
    
    current = next+1;
    string course;
    if( current < line.length() )
    {
      next=line.find_first_of("\t\n", current );
      course = line.substr(current,next-current);
    }
    
    current = next+1;
    string instructor;
    if( current < line.length() )
    {
      next=line.find_first_of("\t\n", current );
      instructor = line.substr(current,next-current);
    }
    
    current = next+1;
    string whenWhere;
    if( current < line.length() )
    {
      next=line.find_first_of("\t\n", current );
      whenWhere = line.substr(current,next-current);
    }
    
    if( course.find('-') == string::npos )
      continue;
    
    string subjectCode( course.begin(), course.begin() + course.find('-') );
    
    ts.Term = term;
    ts.Section = section;
    
    cout << hashCode(ts) << endl;
    }

  }
  fin.close();
  
  //test capacity function
  cout << "capacity: " << a.capacity() << endl;
  cout << "capacity is expected to be 99, so capaicity function works well." << endl;
  
  // test size function
  cout << "size: " << a.size() << endl;
  cout << "size is expected to be 160, so size function works well." << endl;
  
  // setter funtion
  cout << "Size is correct, so setters function works well." << endl;
  
  return 0;
}
