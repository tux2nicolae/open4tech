#include<iostream> 
#include<iterator>
#include<vector>
#include<list>
#include<fstream>
#include<algorithm>

// #include "CountSort.h";
// #include "BinarySearch.h";
// #include "Tree.h"

using namespace std;

int Search(const string& str, const string& substr)
{
  return -1;
}

int main()
{
  string str = "You'll #neversea algorithms like these";
  string substr = "neversea";

  int pos = Search(str, substr);
  if (pos != -1)
  {
    cout << "Subsirul a fost gasit pe pozitia : " << pos << endl;
  }
  else
  {
    cout << "Subsirul nu a fost gasit" << endl;
  }
}
