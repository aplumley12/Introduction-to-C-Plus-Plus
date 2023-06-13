# C++ Naming Conventions and Data Types
## Naming Conventions: Keeping Your Code Clean and Easy to Read
All programing languages have some form of naming conventions--a set of rules outlining how to choose valid
variable, function, and class names. Some of these rules are enforced by the language itself while others act more as guidlines
to keep code consistent and accessible for other programmers. Following the naming conventions of a language mitigates ambiguity,
provides consistency, improves readability, and helps programmers avoid naming conflicts. 
Common C++ naming conventions include:
* Class names should use start case, that is, every word should begin with a capital letter. For example, `ThisIsAClass`.
* Class names should not contain underscores.
* Functions and methods should use camel case such that the first word begins with a lower case letter and all following words begin with an upper case letter.
  For example, `thisIsAFunction`.
* Variable names should begin with a letter character.
* Variable names containing multiple words should use the underscore `_` as a separator. For example, `this_is_a_variable`
* Keywords cannot be used as variable names.

## Common C++ Data Types
Most programming languages support various data types, which refer to the category of value stored in a variable.
Like Java, C++ is statistically- and strongly-typed, meaning it provides a data integrity 'safety net' and enforces strict typing rules at compile time.
Therefore, when declaring a variable in C++, the programmer must include an identifier preceeding its name to indicate the stored value's data type.

### Primative Data Types
Primative data types are the building blocks from which all other types are constructed. 

#### Integers
An integer stores a whole numerical value. To declare an integer variable, use the `int` identifier. 
For example: 
```
int i = 12;
```
#### Floating-point Numbers
A floating-point or float stores a fractional numerical value. To declare a float-point variable, use the `float` identifier.
For example: 
```
float f = 3.14;
```
#### Booleans
A boolean refers to a `true` or `false` value, often represented by 1 or 0 respectively. To declare a boolean variable, use the `bool` identifier.
For example: 
```
bool b = true;
```
#### Characters
A character stores a single character value (letter, punctuation mark, mathematical operator, etc) wrapped in single quotes. To declare a character variable, use the `char` identifier.
For example: 
```
char c = 'a';
```

### Non-primative Data Types
Non-primative data types refer to class objects.

#### Strings
A string object is a sequence of characters enclosed in double quotes. To declare a string variable, first use the import statement `#include <string>`, then use the `string` identifier. 
For example:
```
#include <string>
std::string s = "Hello World!";
```
The `std::` refers to the standard library where the string class is stored.

#### Arrays
An array is a data structure used to store multiple values of the same data type. To declare an empty array, indicate the data type of the stored values, the array name, and the 
number of elements enclosed in square brackets. There are two ways to fill an empty array:  
(1) Inserting elements after initialization:
```
// initialize empty integer array of 3 elements
int numbers[3];

// fill array with values
numbers[0] = 10;
numbers[1] = 20;
numbers[2] = 30;
```
(2) Inserting elements during initialization using curly brackets:
```
char fruit[5] = {'a', 'p', 'p', 'l', 'e'};
```
### Maps
A map is a data structure used to store key-value pairs. To declare an empty map, first import the map class from the standard library using the statement `#include <map>`.
Proceeding the map identifier, enclose the data types of the key and value respectively in angle brackets and indicate the map name. To add key-value pairs, include the map name followed by a key name in square brackets.
Set this equal to the associated value.
For example:
```
// imports
#include <map>
#include <string>

// initialize empty map
std::map<std::string, std::string> capitals;

// insert key-value pairs
capitals["Spain"] = "Madrid";
capitals["France"] = "Paris";
capitals["Italy"] = "Rome";
capitals["England"] = "London";
capitals["Denmark"] = "Copenhagen";
```

## Data Type Conversion
C++ supports data type conversion. For example, an integer can be converted to a floating-point by setting a new float variable equal to an existing integer variable.
```
int i = 7;
float f = i;
```
Additionally, whole numbers represented as strings can be converted to integers using the `stoi()` function.
```
// imports
# include <string>

// declare string variable
std::string s = "7";

// conversion to an integer
int i = stoi(s);
```
## Arithmetic Operations
C++ supports the use of arithmetic operations on numerical data types such as integers and floating-points.
For example, the `+` operator is used to add two values or variables:
```
// addition of two values
int i = 7 + 3;

// addition of two variables
int sum_1 = 7 + 3;
int sum_2 = sum_1 + 10;
int sum_3 = sum_1 + sum_2;
```
Some common C++ operators are listed in the table below.
| Operator | Name | Example |
|:----------:|:------:|:---------:|
| + | addition | `x + y` |
| - | subtraction | `x - y` |
| * | multiplication | `x * y` |
| / | division | `x / y` |
| % | modulus | `x % y` |
| ++ | incrementation | `++x` |
| -- | decrementation | `--x` | 

C++ supports "widening", that is, performing an arithmetic operation between a lower data type and a higher data type will always result in a higher data type.
For example, adding an integer and a floating-point results in a float. Additionally, note that in C++, non-numerical data types and numerical data types are not compatible via arithmetic operations.
For example, the code `x = "5" + 6` will not compile. In this situation, either `5` must be converted to an numerical data type, or `6` must be converted to a string.
