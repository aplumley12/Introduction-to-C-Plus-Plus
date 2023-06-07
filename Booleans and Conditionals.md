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
std::cout << (5 < 10) << std::endl;
```
will print 1 to the terminal because 5 is smaller than 10. Conversly, the expression
```
std::cout << (5 > 10) << std::endl; 
```
will print 0 to the terminal because 5 is not greater than 10.

## Logical AND and OR Operators
Often a program needs to combine multiple boolean values into a single result. C++ supports two logical operators specifically designed to handle such cases. 

The `&&` (AND) operator examines the adjacent boolean expressions from left to right and returns `true` if BOTH evaluate to `true`. If at least one expression evaluates to `false`, the entire expression returns `false`. For example, the following code returns `true` because both expressions are `true`. 
```
(5 < 10) && (6 <= 10)
``` 
On the other hand, this code returns `false` because the first expression evaluates to `false`. 
```
(3 % 2 == 0) && (7 > 0)
``` 

The `||` (OR) operator examines the adjacent boolean expressions and returns `true` if AT LEAST ONE evaluates to `true`. In other words, this operator will only return `false` if both expressions are `false`. For example, the following code returns `true` because the first expression evaluates to `true`.
```
(6 % 3 == 0) || (9 > 12)
```
However, this line of code returns `false` because both expressions evaluate to `false`.
```
(7 < 6) || (10 > 12)
```

The results of compound boolean expressions are summarized in the following truth table.
| P | Q | P and Q | P or Q |
|:----------:|:------:|:---------:|:---------:|
| true | true | true | true |
| true | false | false | true |
| false | true | false | true |
| false | false | false | false |

## Conditional Statements
Many programming languages support conditional statements, which make use of boolean expressions to determine whether the compiler should execute a block of code. C++ has four common conditional statements.

#### The `if` Statement
An `if` statement allows the compiler to run a block of code if its associated boolean expression yields `true`.
The basic syntax for a single `if` statement is as follows:
```
if (condition) {
  // this code is executed if the condition is true 
}
```
Note the `if` keyword is in all lowercase, the condition is enclosed in parentheses, and the code block is wrapped in curly braces.

Using the boolean expression from before (with a slight change), we can now include it as the condition for an `if` statement like so:
```
int x = 5;
if (x < 10) {
  std::cout << x << " is less than 10" << std::endl;
}
```
In this example, the code executes because 5 is larger than 4. We can also include a logical operator in the expression to produce a multi-condition `if` statement:
```
if (x < 0 && x < 10) {
  std::cout << x << " is a single positive, single-digit integer."
}
```
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
Note the `else` keyword is also in all lowercase, and the second code block is wrapped in curly braces. Additionally, an `else` statment must be associated with an `if` statement.
Unlike Python, C++ does not enforce indentation; however, it is a recommended convention to avoid losing track of which conditionals are associated with each other. Indentation improves readability by avoiding this **dangling else** problem.

Adding to the previous example, we can now include an additional branch of code:
```
x = 12; // reassign x to 12
if (x < 10) {
  std::cout << x << " is less than 10" << std::endl;
} else {
    std::cout << x << " is greater than 10" << std::endl;
}
```
In this example, the first condition evaluates to `false` because 12 is greater than 10. This prompts the compiler to run the second block of code 
associated with the `else` statement. Again, we can also modify this code to include a multi-condition `if` statement:
```
if (x > 0 && x < 10) {
  std::cout << x << " is a positive, single-digit" << std::endl;
} else {
    std::cout << x << " is not between 0 and 10" << std::endl;
}
```

#### The `else if` Statement
An `else if` statement allows the user to add additional conditions for the compiler to evaluate if the boolean expression associated with the associated `if` statement is `false`.
The basic syntax for an `else if` statement is as follows:
```
if (condition_1) {
  // this code is executed if condition_1 is true
} else if (condition_2) {
    // this code is executed if condition_1 is false and condition_2 is true
} else {
    // this code is executed if all previous conditions are false
```
Notice the `else if` keyword is again, in all lowercase, and the second code block is wrapped in curly braces. 
C++ has no limits on the number of `else if` statements included in a conditional; however, they must follow an `if` statement.

We can now apply this to the previous example like so:
```
x = 10; // reassign x to 10
if (x < 10) {
  std::cout << x << " is less than 10" << endl;
} else if (x == 10) {
    std::cout << x << " is equal to 10" << endl;
} else {
    std::cout << x << " is greater than 10" << std::endl;
```
In this case, the second condition will execute because x was assigned the integer value 10.
Here is an example using multi-conditions:
```
if (x > 0 && x < 10) {
  std::cout << x << " is a positive, single-digit integer" << std::endl;
} else if (x < 0 && x > -10) {
    std::cout << x << " is a negative, single-digit integer" << std::endl;
} else {
    std::cout << x << " is not a single-digit integer" << std::endl;
}
```

#### Chaining and Nesting Conditional Statements
Sometimes, programmers want the compiler to test additional conditions regardless whether one already evaluated to true. Other times, they may want other expression to evaluate ONLY if a conditional is true. 
In these situations, multiple `if` / `else if` statements can be appened one after the other (chained) or nested inside each other respectively. 
The basic syntax for chained conditionals is as follows:
```
if (condition_1) {
  // block of code executes if condition_1 is true
} if (condition_2) {
    // block of code executes if condition_2 is true
}
```
Note that the second `if` statement is NOT within the curly braces of the first conditional--it is independent and whether the code block executes or not is solely based on the second condition. The following code contains a simple example of this concept.

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
The basic syntax for nested conditionals is as follows:
```
if (condition_1) {
  // optional block of code executes if the first condition_1 is true
  if (condition_2) {
    // block of code executes if both conditions are true
  }
}
```
Note that the second `if` statement is inside the curly braces of the first conditional--it is part of the code block that executes if the first condition is `true`. The following code contains a simple example of this concept.
```
// nested if statements
x = 8;
if (x > 0) {
  std::cout << x << " is a positive integer ";
  if (x%2 == 0) { 
    std::cout << "and even. Dividing by 2..." << std::endl;
    std::cout << "result: " << x/2 << std::endl;
  } 
}      
```
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

#### A Note on Short Circuiting
In C++, short-circuit logic is applied while evaluating logical `&&` and `||` operators. As previously discused, the `&&` operator yields `false` if at least one condition is false. Therefore, if the left boolean expression evaluates to `false`, the compiler skips the right expression and automatically returns `false` for the entire condition. Similarly, the `||` operator yields `true` if, at most, one condition is true. Therefore, if the left boolean expression returns `true`, the compiler skips the right condition and evaluates the entire condition as true. The following code includes examples of short-circuit logic:
```
int i = 0

// short-circuiting with a logical OR operator
if (i < 1 || i++) {
  std::cout << i << " has not been incremented because of short-circuit logic!" << std::endl;
}

// short-circuiting with a logical AND operator
if (i > 0 && i++) {
  std::cout << i << " has not been incremented because of short-circuit logic!" << std::endl;
}
```


