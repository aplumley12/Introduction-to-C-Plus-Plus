# Loops in C++
In programming, loops allow a code block to repeatadly execute until a condition is met. This can save time, improve 
readability, and reduce syntax/logical errors. As a high-level language, C++ supports several types of loops, 
each with unique advantages. 

## The `for` Loop
A `for` loop allows the user to specify how many times a code block should execute. The basic C++ syntax is as
follows (Lenka):
```
for (counter, condition, increment) {
  // code block executed on each iteration
}
```
In C++, for loops require three statements: the declaration of a counter variable, a condition determining when the loop should stop, and 
an update of the counter on each loop iteration.

The example below prints a countdown from 10 to 1 in the terminal:
##### Example (1)
```c++
for (int i = 10; i > 0; i--) {
  cout << i << endl;
}
cout << "LIFT OFF!" << endl;
```
Note the three statements enclosed in parenthesis. The line `int i = 10` initializes the counter variable with a value of 10.
Next, the loop will continue until the condition `i > 0` becomes false, i.e., `i` reaches 0. Finally, `--i` decreases the counter by 1
on each iteration, moving the loop towards completion. 

## The For-Each Loop
The for-each loop is a variation of the for loop used exclusively to iterate over elements in an array or other
data structure. The basic C++ syntax is as follows (Lenka):
```
for (type variable_name : array_name) {
  // code block executed for each element in the array
}
```
On each iteration of a for-each loop, the variable is updated to store the next item in the array. The loop stops once each element has been traversed.

The example below takes the average of an integer array and prints it to the terminal:
##### Example (2)
```c++
float sum = 0;
int numbers[5] = {3, 9, 17, 12, 6};
for (int i : numbers) {
  sum = sum + i;
}
cout << "the average is: " << sum/5 << endl;
```
Each time this loop executes, i is assigned the next element in the `numbers` array and added to the rolling sum. Once the loop has passed through
every item, the sum is divided by the array's length and displayed in the terminal.

## The `while` Loop
A `while` loop will continue to execute a block of code until its conditional statement becomes false. This condition is always tetsted **before** each iteration. 
To avoid an infinite loop, a while loop should always include some form of update moving it towards completion. The basic C++ syntax is as follows (Lenka):
```
while (condition) {
  // code block executed on each iteration
}
```
The example below uses a while loop to calculate the factrorial of 5 (5!):
##### Example (3)
```c++
int factorial = 5;
int product = 1;
while (factorial > 0) {
  product = product * factorial;
  factorial--;
}
cout << product << endl;
```
Often times, while and for loops can be used interchangably. For example, we can use a while loop instead of a for loop to write the countdown code from example 1:
##### Example (4)
```c++
int i = 10;
while (i > 0) {
  cout << i << endl;
  i--;
}
cout << "LIFT OFF!" << endl;
```
We can also use a for loop instead of a while loop to calculate the factorial in example 3:
##### Example (5)
```c++
int factorial = 5;
int product = 1;
for(int i = factorial, i > 0, i--) {
  product = product * i;
}
cout << product << endl;
```
## The Do-While Loop
A do-while loop is a variation of the while loop that tests the conditional statement **after** each iteration. In other words, this type of loop always executes at least once! The basic C++ syntax is as follows (Gautam):
```
do{
  // code block executed on each iteration
} while (condition);
```
The example below uses a do-while loop to prompt the user for input until the correct password is given:
##### Example (6)
```c++
string password = "12ab";
string input;
do{
  cout << "Enter the passwowrd: ";
  cin >> input;
} while (input != password);
cout << "Correct!" << endl;

```


