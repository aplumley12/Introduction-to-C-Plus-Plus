# Classes and Inheritance in C++
C++ is an object-oriented programming (OOP) language built on the concept of classes. A **class** is a
user-defined data type with its own methods and attributes. These **class members** are accessed by 
creating an object or class instance. 

## Defining a Class and its Attributes

In C++, the ```class``` keyword defines a class. Consider the syntax of the following example.

##### Example (1.1)
```c++
class Cat {
  public:
    string name;
    int age;
};
```
In this case, the ```class``` keyword defines a class with the name ```Cat```. Notice that the class name is
written in camel case. Within the curly brackets, the **access specifier**, ```public```, indicates that any attributes 
and methods defined within ```Cat``` are accessible outside the class definition. For now, just know that C++ supports three types of access specifiers:
* `public`    members are _accessible_ outside their associated class
* `private`   members are _inaccessible_ from outside their associated class
* `protected` members are _inaccessible_ from outside their associated class, however, inherited classes may still use them. 

Example (1.1) includes two **attributes**,
a string object and an integer. In C++ and other OOP languages, attributes describe variables declared withiin a class definition. 
Finally, the class definition is closed using a semicolon.

In C++, objects are created by including the class name. This syntax is similar to declaring variables of primitive data types:
##### Example (1.2)
```c++
main() {
  Cat myCat;
}
```
However, the Cat class defined in Example (1.1) includes two attributes--one that stores a name and another that stores an age.
To access these attributes and set their values for a given object, use dot notation like so:
##### Example (1.3)
```c++
myCat.name = "Mittens";
myCat.age = 5;
```
Note that a class can have many instances, each with its own stored values. For example, a second `Cat` object can be initialized like so:
##### Example (1.4)
```c++
main() {
  // initialize another Cat object
  Cat myCat2;
  // set attributes
  myCat2.name = "Snowshoe";
  myCat2.age = 7;
}
```
## User-Defined Methods 
A **method** describes any function declared within a class. In C++, methods can be defined either inside or outside the 
class they belong to. For example, consider a ```Cat``` class method named ```speak```. To define the ```speak``` method
inside its class, we can use to following syntax:
##### Example (2.1)
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
##### Example (2.2)
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
##### Example (2.3)
```c++
main() {
  myCat.speak();
}
```
Running this code will print the value stored in ```myCat.name``` followed by the string " says 'Meow!'" to the terminal. 

## The Constructor Method
Along with support for user-defined methods, C++ has a built-in standard method for performing similar functions across all objects. This **constructor method** is automatically called when declaring a new object. In C++, a constructor should use the same name as the class it belongs to. For example, the constructor method of the `Cat` class in the previous examples should also have the name Cat followed by parentheses. A constructor method may also take parameters using the same syntax as ordinary functions. Generally, programmers use this feature to assign initial values to an object's attributes.
##### Example (3.1)
```c++
class Cat {
  // access specifier
  public:
    // declare attributes
    string name;
    int age;
  // constructor with parameters corresponding to the attributes
  Cat(string n, int a) {
    name = n;
    age = a;
  };
 
 main() {
   // create new cat object and pass arguments to the constructor method
   Cat myCat("Pompom", 2);
 }
```
And, just like user-defined methods, C++ allows us to write constructor definitions outside their class defintions like so:
##### Example (3.2)
```c++
class Cat {
  // access specifier
  public:
    // declare attributes
    string name;
    int age;
  // declare constructor with parameters corresponding to the attributes
  Cat(string n, int a);
  };

// define constructor outside of the Cat class
Cat::Cat(string n, int a) {
  name = n;
  age = a;
}

 main() {
   // create new cat object and pass arguments to the constructor method
   Cat myCat("Pompom", 2);
 }
```

## Inheritance in C++
Object-oriented programming languages generally allow classes to _inherit_ methods and attributes from other classes. In C++, **derived** (child) classes inherit from **base** (parent) classes. A derived class is denoted with the colon `:` character. For example, we can modify the `Cat` class so it inherits from a `Pet` base class.
##### Example (4.1)
```c++
// base class
class Pet {
  public:
    string name;
    int age;
  // constructor method
  Pet(string n, int a) {
    name = n;
    age = a;
  }
};

// derived class
class Cat: public Pet {
  public:
    string breed;
  // constructor method with inherited attributes
  Cat()
} 
```




