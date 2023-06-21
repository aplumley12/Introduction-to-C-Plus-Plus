# Classes and Inheritance in C++
C++ is an object-oriented programming (OOP) language built on the concept of classes. A **class** is a
user-defined data type with its own methods and attributes. These **class members** are accessed by 
creating an object or class instance. 

## Defining a Class and its Attributes

In C++, the ```class``` keyword defines a class. Consider the syntax of the following example.

##### Example (1)
```c++
class Cat {
  public:
    string name;
    int age;
};
```
In this case, the ```class``` keyword defines a class with the name ```Cat```. Notice that the class name is
written in camel case. Within the curly brackets, the **access specifier**, ```public```, indicates that any attributes 
and methods defined within ```Cat``` are accessible outside the class definition. This exmaple includes two **attributes**,
a string object and an integer. In C++ and other OOP languages, attributes describe variables declared withiin a class definition. 
Finally, the class definition is closed using a semicolon.

In C++, objects are created by including the class name. This syntax is similar to declaring variables of primitive data types:
##### Example (1.1)
```c++
main() {
  Cat myCat;
}
```
However, the Cat class defined in Example (1) includes two attributes--one that stores a name and another that stores an age.
To access these attributes and set their values for a given object, use dot notation like so:
##### Example (1.2)
```c++
myCat.name = "Mittens";
myCat.age = 5;
```
Note that a class can have many instances, each with its own stored values. For example, a second `Cat` object can be initialized like so:
##### Example (1.3)
```c++
main() {
  // initialize another Cat object
  Cat myCat2;
  // set attributes
  myCat2.name = "Snowshoe";
  myCat2.age = 7;
}
```
## Class Methods 
A **method** describes any function declared within a class. In C++, methods can be defined either inside or outside the 
class they belong to. For example, consider a ```Cat``` class method named ```speak```. To define the ```speak``` method
inside its class, we can use to following syntax:
##### Example (2)
```c++
class Cat {
  public:
    string name;
    int age;
  
  // speak method defined inside the Cat class
  void speak() {
    cout << name << " says 'Meow!'" << endl;
  }
};
```
On the other hand, to define this method outside the ```Cat``` class, first include a declaration inside the class. When 
writing the actual definition, specify the class name followed by the scope resolution ```::``` operator and the method's name.
##### Example (2.1)
```c++
class Cat {
  public:
    string name;
    int age;
  
  // declare speak method inside the Cat class
  void speak();
};

// define speak method outside the Cat class
void Cat::speak() {
  cout << name << " says 'Meow!'" << endl;
}
```
Like attributes, we can access and call methods on a class instance using dot notation. For example, the following code calls the 
```speak``` method on ```myCat```.
##### Example (2.2)
```c++
main() {
  myCat.speak();
}
```
This prints the value stored in ```myCat.name``` followed by the string " says 'Meow!'" to the terminal.

