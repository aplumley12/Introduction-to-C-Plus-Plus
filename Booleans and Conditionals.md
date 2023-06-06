# C++ Booleans and Conditional Statements
## Boolean Values
A boolean is a logical, binary variable that stores only one of two values. In C++, the boolean data type
can hold either `true` (1) or  `false` (0) in all lower case. To declare a boolean variable, use the `bool` keyword
and set it to one of these values. For example:
```
bool b_1 = true;
bool b_0 = false;
```
When printing a boolean variable, the terminal will display `1` for a `true` value and `0` for a `false` value.

## Boolean Expressions
In C++, boolean expressions return either 1 or 0 and typically use one of the following comparison operators.
| Operator | Name | Example |
|:----------:|:------:|:---------:|
| == | equal | `x == y` |
| != | not equal | `x != y` |
| > | greater than | `x > y` |
| < | less than | `x < y` |
| >= | greater than or equal to | `x >= y` |
| <= | less than or equal to | `x <= y` |

For example, the expression 
```
std::cout << (5 > 4) << std::endl;
```
will print 1 to the terminal because 5 is larger than 4. Similarly, the expression
```
std::cout << (5 < 4) << std::endl; 
```
will print 0 to the terminal because 5 is not smaller than 4.

## Conditional Statements
Many programming languages support conditional statements, which make use of boolean expressions to determine whether the compiler
should execute a block of code. C++ has four common conditional statements.

#### The `if` Statement
An `if` statement allows the compiler to run a block of code if its associated boolean expression yields `true`.
The basic syntax for a single `if` statement is as follows:
```
if (condition) {
  // this code is executed if the condition is true 
}
```
Note the `if` keyword is in all lowercase, the condition is enclosed in parentheses, and the code block is wrapped in curly braces.
Unlike Python, C++ does not enforce indentation; however, it is a recommended convention to keep code organized and readable.

Using the boolean expression above (with a slight change), we can now include it as the condition for an `if` statement like so:
```
int x = 5;
if (x > 4) {
  std::cout << x << " is greater than 4" << std::endl;
}
```
In this example, the code executes because 5 is larger than 4.

#### The `else` Statement 
An `else` statement allows the compiler to run a block of code if the previous condition is `false`.
The basic syntax for an `else` statement is as follows:
```
if (condition) {
  // this code is executed if the condition is true
} else {
  // this code is executed if the condition is false
}
```
Note the `else` keyword is also in all lowercase, and the second code block is wrapped in curly braces. Additionally, an
`else` statment must be associated with an `if` statement.

Adding to the previous example, we can now include an additional branch of code:
```
x = 3;
if (x > 4) {
  std::cout << x << " is greater than 4" << std::endl;
} else {
  std::cout << x << " is less than 4" << std::endl;
}
```
In this example, the first condition evaluates to `false` because 3 is smaller than 4. This prompts the compiler to run the second block of code 
associated with the `else` statement.

#### The `else if` Statement
An `else if` statement allows the user to add additional conditions for the compiler to evaluate if the boolean expression associated with the associated `if` statement is 
`false`.
The basic syntax for an `else if` statement is as follows:
```
if (condition_1) {
  // this code is executed if condition_1 is true
} else if (condition_2) {
  // this code is executed if condition_1 is false and condition_2 is true
} else {
  // this code is executed if all previous conditions are false
```
Note the `else if` keyword is again, in all lowercase, and the second code block is wrapped in curly braces. Additionally, an
`else if` statment must be associated with an `if` statement.

We can now apply this to the previous example like so:
```
x = 4;
if (x > 4) {
  std::cout << x << " is greater than 4" << endl;
} else if (x == 4) {
   std::cout << x << " is equal to 4" << endl;
} else {
   std::cout << x << " is less than 4" << std::endl;
```
In this case, the second condition will execute because x was assigned the integer value 4. 

#### Chaining and Nesting Conditional Statements
Sometimes, programmers want the compiler to test additional conditions regardless whether one already evaluated to true. Other times, they may want other expression to evaluate ONLY if a conditional is true. 
In these situations, multiple `if` / `else if` statements can be appened one after the other (chained) or nested inside each other respectively. The following code contains some simple examples of this concept.
```
// nested if statements
x = 8;
if (x%2 == 0) {
  std::cout << x << " is even. ";
  if (x%4 == 0) { 
    std::cout << "It is divisible by 4." << std::endl;
  } 
}      
```
In case, the compiler will only evaluate the inner `if` statement if the condition associated with the outer conditional is `true`.

```
// chianed if statements
x = 7;
// chained if statements
if (x%2 == 0) {
  std::cout << x << " is even. ";
} if (x < 10) {
  std::cout << x << " is a single digit integer." << std::endl;
}
```
Notice that the second `if` statement is not inside the curly braces of the first `if` statement. Even if the first conditional evaluates to `false`,
the second will still be tested. Furthermore, unlike an `if else` statement, the second `if` will still be evaluated even if the first returns `true`.

#### Switch Statements
In C++, a `swtich` statement can be used to run one of many code blocks. 
The basic syntax for this type of conditional is as follows:
```
switch(expression) {
  case a:
    // code block executed if case a is true
    break;
  case b:
    // code block executed if case b is true
    break;
  case c:
    // code block executed if case c is true
    break;
  default:
    // code block executed if all previous cases are false
}
```
Note the `break` keyword at the end of each code block. This tells the compiler to stop evaluating after a case returns to `true`. Additionally, if all cases 
evaluate to `false`, the code associated with `default` will execute.
The following switch statement converts the number of a month to its English name.
```
int m = 9;
switch(m) {
    case 1: 
        std::cout << "January";
    case 2:
        std::cout << "February";
    case 3: 
        std::cout << "March";
    case 4:
        std::cout << "April";
    case 5:
        std::cout << "May";
    case 6:
        std::cout << "June";
    case 7: 
        std::cout << "July";
    case 8:
        std::cout << "August";
    case 9:
        std::cout << "September";
    case 10:
        std::cout << "October";
    case 11:
        std::cout << "November";
    case 12:
        std::cout << "December";
    default:
        std::cout << "There are only 12 months in a year!";
}
```
In this example, case 9 will evaluate to true and "September" will print to the terminal. 

#### Multi-Conditionals: Logical AND/OR Operators

#### The Dangling `else` Problem

#### A Note on Short Circuiting


