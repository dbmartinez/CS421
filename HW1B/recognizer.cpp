#include<iostream>
#include<string>
using namespace std;

//------------------------------------------------------ 
// CS421 HW1
// Write a recognizer in C++ for L = {x | x is any coombination of a's and b's}.
// Your name: Daniel B. Martinez
//------------------------------------------------------

//  The recognizer function should return TRUE or FALSE 
//  checking each character
//  to make sure it is a or b.
bool recognizer(string s)
{
  // Variables
  bool isTrue;
  int i = 0;

  // use while loop to check length
  while(i< s.length())
    {
      // if statement to check characters a and b
      if(s[i] == 'a' || s[i] == 'b')
	{
	  isTrue = true; // check condition and set to true  
	}

      else
	{
	  isTrue = false; // check condition and set to false
	  break;
	}

      i++; // increment
    }
  
  return isTrue;

}// end of recognizer

//main: Given a string (from E) cined from the user, pass it to
// the recognizer function.
// Cout "YES IN L" or "NO NOT IN L" depending on what was returned.
int main()
{
  // Variables
  string line;

  // Main statement for program
  cout << "\nTesting Recognizer";
  
  // Allow user to enter in characters a,b,c, etc.
  cout << "\nEnter in characters: ";

  // feel free to put it in a loop
    while(getline(cin, line))
      {
	// If/else statement to see if it's true or not
	if(recognizer(line))
	  {
	    cout << "YES IN L\n";
	  }
	
	else
	  {
	    cout << "NO NOT IN L\n";
	  }

	// Allow user to enter in characters a,b,c, etc.
	cout << "\nEnter in characters: ";
	
	if(line == "q")
	  {
	    break;
	  }

      }
           
} // end of main
