/////// IMPORTS ///////
#include <iostream>
#include <istream>
#include <string>
#include <cstring>

using namespace std;

/////// MAIN FUNCTION ///////
main() {
  // Example (1): simple for loop countdown //
  for (int i = 10; i > 0; i--) {
    cout << i << endl;
  }
  cout << "LIFT OFF!" << endl;
  
  // Example (2): taking the average via a for-each loop //
  float sum = 0;
  int numbers[5] = {3, 9, 17, 12, 6};
  for (int i : numbers) {
    sum = sum + i;
  }
  cout << "the average is: " << sum/5 << endl;
  
  // Example (3): calculating the factorial with a while loop //
  int factorial = 5
  int product = 1;
  while (factorial > 0) {
    product = product * factorial;
    factorial--; 
  }
  cout << product << endl;
  
  // Example (4): simple while loop countdown //
  int i = 10;
  while (i > 0) {
    cout << i << endl;
    i--;
  }
  cout << "LIFT OFF!" << endl;
  
  // Example (5): calculating the factorial with a for loop //
  factorial = 5;
  product = 1;
  for (int i = factorial, i > 0, i--) {
    product = product * i;
  }
  cout << product << endl;
  
  // Example (6): using a do-while loop to ask for the correct password (interactive) //
  string password = "12ab";
  string input;
  do {
    cout << "Enter the password: ";
    cin >> input;
  } while (input != password);
  cout << "Correct!" << endl;
}
