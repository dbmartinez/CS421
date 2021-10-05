#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------                                      
// CS421 File mat.cpp for HW2A Matrix Practice        
// Your name: Daniel B. Martinez  
//--------------------------------------                

// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VM = 3; // table entry (vector) length
vector<char>  T[R][C];  // 3 rows and 4 columns table for now

// ------------------ Functions -------------------------------
int convert(char x)
{
  // do a formula to convert a to 0, b to 1, c to 2 etc.
  //return(int)x - 97;
  return((int)x - 97)%C;
}

// read in the table from the file
int readTable()
{
  int row, col;  // row and col numbers
  char col_c;     // column indicator
  ifstream fin ("lines.txt", ios::in); // read in file

  // Read in the file into T 
  while (fin >> row) // next line of file
    {
      fin >> col_c; // fill col_c from contents of file
      col = convert(col_c);  // convert to a slot number 
      vector<char> v;  // a vector to fill              
      char c; // one char from the file

      // ** Fill v with chars from the file (there are VM chars)
      for(int i = 0; i < VM; i++)
	{
	  // fill in the letters into the vector
	  fin >> c;
	  v.push_back(c);
	  
	  /*cout << v[i] << ' ';    /
	  / test to see if letters  /
	  / are being inputed      */
	}

      // ** Put  v in T[row][col]
      T[row][col] = v;

    }//end of while
}

// display contents of the vector
void showVector(vector<char> v)
{
  if (v.size() == 0)  // empty entry
    {
      // display for empty entry
      for (int i = 1; i <= VM; i++)
	{
	  cout << "- ";
	}
    }

  else
    {
      // show the content of v separated by blanks (e.g. "a b c")
      // use for loop to show all letters in the vector v
      for(int i = 0; i < VM; i++)
	{
	  // display the letters from the vector v
	  cout << v[i] << ' ';
	}
    }
}

// Displays T as a table, separating entries with "|"
void displayTable()
{
  // ** display T nicely labeled with row numbers (col numbers not needed)
  // using a for loop inside another for loop to display the following contents
  // of the matrix
  for(int i = 0; i < R; ++i) 
    {
      // start displaying the letters from the vector
      cout << i;

      // Second for loop used for displaying of the matrix
      for(int j = 0; j < C; ++j) 
	{
	  // seperate the letters
	  cout << "| ";

	  // call function showVector() to display contents
	  showVector(T[i][j]);
	}
      
      // end new line
      cout << endl;
      }
}

// Main Driver
int main()
{
  // display contents if the matrix by calling 
  // the follwoing functions, readTable() & displayTable()
  cout << "Reading table from lines.txt..." << endl;
  readTable();
  displayTable();
}//the end
