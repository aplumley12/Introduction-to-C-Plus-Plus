/////// IMPORTS ///////
#include <iostream>
#include <istream>
#include <string>
#include <cstring>

using namespace std;

/////// FUNCTION DEFINITIONS ///////

// Example (1): using a function to greet the user
void greeting(string name) {
  /*
  Takes in the user's name as a parameter and prints a greeting to the terminal
  */
  cout << "Hello, " << name << endl;
}

// Example (2): converting a base 10 integer to its equivalent in another base system
int baseConversion(int num, int base) {
  /*
  Takes in a base 10 integer and returns its equivalent in the specified base system
  */
  int r; 
  int q;
  string ans;
  while (q != 0) {
    q = num / base;
    r = num % base;
    num = q;
    ans.insert(0, to_string(r));
  }
  return (stoi(ans));
}

// Example (3): Calculating the factorial using recursion
int factorial(int n) {
  /*
  Takes in an integer n, and uses recursion to calculate n!
  */
  if (n > 1) {
    return n * factorial(n - 1);
  } else {
    return 1;
  }
}

// Example (4): pass-by value DOES NOT change the original stored data
void swapVal(int x, int y) {
  /*
  Uses pass-by value to swap the values of its parameters within the scope of the function only
  */
  int temp = x;
  x = y;
  y = temp;
}

// Example (5): pass-by reference DOES change the original stored data
void swapRef(int &x, int &y) {
  /*
  Uses pass-by reference to swap the original values of the arguments
  */
  int temp = x;
  x = y;
  y = temp;
}

// Example (6): using pass-by reference to "return" more than one value
void split(string s, char del, string &substr_1, string &substr_2) {
  /*
  Uses pass-by reference two split a string on a specified delimeter and produce two substrings
  */
  // declare empty character array
  char char_array[s.length() + 1];
  // strcpy() and .c_str() used to convert passed string to chars and insert them into empty character array
  strcpy(char_array, s.c_str());
  
  char c;
  int i = 0;
  
  // build first substring
  while (c != del && i <= s.length()) {
    c = char_array[i];
    // push_back() appends the char to the end of the string
    substr_1.push_back(c);
    i++;
  }
  
  while (i <= s.length()) {
    c = char_array[i];
    substr_2.push_back(c);
    i++;
  }
}

/////// MAIN FUNCTION ///////
int main() {
  /*
  This is the main function; it calls all the user-defined functions in this file
  */
  
  // call to greeting() function
  greeting("Mary Sue");
  
  // call to baseConversion() function
  cout << baseConversion(47, 2) << endl;
  
  // call to factorial() function
  cout << factorial(5) << endl;
  
  // call to swapVal() function (note that the values of the original variables DO NOT change)
  int x = 5;
  int y = 10;
  swapVal(x, y);
  cout << "pass-by value...         x: " << x << " y: " << y << endl;
  
  // call to swapRef() function (note that the values of the original variable DO change)
  swapRef(x, y);
  cout << "pass-by reference...     x: " << x << " y: " << y << endl;
  
  // call to split() function (first, initialize substring variables to empty strings to be manipulated later in the function)
  string substr_1 = "";
  string substr_2 = "";
  
  split("Hello World", ' ', substr_1, substr_2);
  cout << substr_1 << "\n" << substr_2 << endl;
  
  return 0; 
}
  
