# Defining and Using Functions in C++
A **function** is a block of code that only executes when called by name. The user may pass data as *arguments* into a 
function, where it is stored in variables known as *parameters*. Overall, functions allow programmers to run code multiple times
without needing to duplicate it. This improves suscinctness and readability while reducing errors. Note that, while the inclusion of a docstring is not
enforced, adding one after a function definition can help other programmers understand what the code does. The basic syntax for a C++ function with no return 
value is as follows:
```
void exampleFunction(datatype parameter_1, datatype parameter_2) {
   // code block executed when this function is called by name
}
```
Here, we can see that `exampleFunction()` is the function name and that the keyword `void` indicates that it has no return values.
Additionally, notice how the parameters are written just like variable declarations. Keep in mind that a function call in C++ must include an 
argument for each parameter, i.e., there are no optional parameters.

Below is an example function that takes in the user's name as a parameter and prints a greeting to the terminal.

##### Example (1)
```c++
void greeting(string name) {
/*
Takes in the user's name as a parameter and prints a greeting to the terminal
*/
  cout << "Hello, " << name << endl;
}
int main() {
/*
This is the main function; it calls the greeting() function
*/
  greeting("Mary Sue");
}
```
In this example, the `greeting()` function is called inside `main()`. Additionally, note that any user-defined functions such as
`greeting()` must be declared *before* the main fucntion to avoid a scope error.

When declaring a function _with_ a return value, we must replace the `void` keyword with the datatype of the return value.
For example, the following function converts an integer of base 10 to any other base and returns the value as an integer:
##### Example (2)
```c++
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

int main() {
  /*
  This is the main function; it calls the baseConversion() function
  */
  cout << baseConversion(47, 2) << endl;
  return 0;
}
```
## Recursion
A _recursive_ function calls itself in order to break complex problems into smaller ones.
Like while loops, functions of this nature repeatedly execute until a condition is met. This condition, commonly 
referred to as the _base case_, is the simplest form of a problem, which does not require recursion to solve.
For example, consider this recursive version of the factorial algorithm:
##### Example (3)
```c++
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

int main() {
  /*
  This is the main function; it calls the factorial() function
  */
  cout << factorial(5) << endl;
  return 0;
}
```
In this example, the base case is 0!, which, by definition, equals 1. Each recursive step moves towards this base case 
by taking the factorial of one less than `n`.

## Pass-by Reference or Value?
Programming languages are often referred to as either pass-by reference or pass-by value, but what is the difference? 
When passing a variable to a function by value, a copy of its stored data is made, leaving the original value 
unaffected. On the other hand, when passing by reference, the _original_ variable is passed as an argument, and therefore, any updates  
made within the funtion are reflected by the variable's stored value. In general, pass-by reference is more efficient because a program does 
not have to store duplicates of arguments; however, this behavior may also lead to unintended changes to the data. 
C++ supports BOTH pass-by reference and pass-by value via the _pointer_ datatype. For now, simply understand that pointers 'point' directly to a variable's
location in memory and, therefore, allow a function to directly manipulate the data stored in it. 
The following C++ function demonstrates pass-by value, in which, the original stored data is not manipulated by the function:
##### Example (4)
```c++
void swapVal(int x, int y) {
  /*
  Uses pass-by value to swap the values of its parameters within the scope of the function only
  */
  int temp = x;
  x = y;
  y = temp;
}
int main() {
  /*
  This is the main function; it calls the swapVal() function
  */
  int x = 5;
  int y = 10;
  swapVal(x, y);
  cout << "x: " << x << " y: " << y << endl;
}
```
In this case, the original values of `x` and `y` will not be swapped; only the copies of the arguments will be 
affected inside the body of the function. 
However, this C++ function uses pointers (denoted by the ampersand `&` symbol) to pass-by reference, in which the original memory addresses of the variables are sent to the function:
##### Example (5)
```c++
void swapRef(int &x, int &y) {
  /*
  Uses pass-by reference to swap the original values of the arguments
  */
  int temp = x;
  x = y;
  y = temp;
}
int main() {
  /*
  This is the main function; it calls the swapRef() function
  */
  int x = 5;
  int y = 10;
  swapRef(x, y);
  cout << "x: " << x << " y: " << y << endl;
}
```
In this example, the original value of `x` and `y` WILL be swapped and `x: 10 y: 5` will be displayed in the terminal.

Note: While C++ does not allow functions to directly return multiple values (something perfectly legal in some other languages such as Python), 
this pass-by reference method provides a decent work around! Simply pass pre-declared variables into a function as pointer parameters where they can be
manipulated without requiring a return statement.

Below is another example where pointers are used to emulate multiple return values:
##### Example (6)
```c++
void split(string s, char del, string &substr_1, string &substr_2) {
  /*
  Uses pass-by reference two split a string on a specified delimeter and produce two substrings
  */
  // create a new character array
  char char_array[s.length() + 1];
  // strcpy() function and .c_str() method used to convert the string to chars and store them in char_array
  // note that both strcpy() and .c_str() can be imported via '#include <cstring>'
  strcpy(char_array, s.c_str());
  
  char c;
  int i = 0;
  while (c != del && i <= s.length()) {
    c = char_array[i];
    // the push_back() method appends a char to the end of a string
    substr_1.push_back(c);
    i++;
  }
  
  while (i <= s.length()) {
    c = char_array[i];
    substr_2.push_back(c);
    i++;
  }
}

int main() {
  /*
  This is the main function; it declares the two empty substrings, calls the split() function, 
  and prints the new values of the substrings to the terminal
  */
  // initialize substring variables to empty strings
  string substr_1 = "";
  string substr_2 = "";
  
  split("Hello World", ' ', substr_1, substr_2);
  
  cout << substr_1 << "/n" << substr_2 << endl;
}
```
The `split()` function in Example (6) takes in a string, a delimeter, and two empty strings as parameters.
The original string is split on the delimeter into two substrings, which are then stored in the empty string parameters.
Because `split()` uses pass-by reference via pointers, the original values stored in both substring variables are directly 
manipulated, thus mimicking two return values.


