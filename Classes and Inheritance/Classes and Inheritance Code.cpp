/////// IMPORTS ///////
#include <iostream>
#include <string>

using namespace std;

/////// BASE CLASS DEFINITION ///////
class Pet {
  // access specifier //
  public:
    // attributes //
    string name;
    int age;
    
    // constructor method //
    Pet(string n, int a) {
      name = n;
      age = a;
    } 

    // get methods //
    string getName() {
      return name;
    }
    int getAge() {
      return age;
    }

    // set methods //
    void setName(string n) {
      name = n;
    }
    void setAge(int a) {
      age = a;
    }
};

/////// DERIVED CLASS DEFINITION ///////
class Cat : public Pet {
  // access specifier //
  public:
    // attributes // 
    string breed;

    // constructor method --> name and age are inherited from the Pet base class! //
    Cat(string n, int a, string b) : Pet(n, a) {
      breed = b;
    }

    // get methods //
    string getBreed() {
      return breed;
    }

    // set methods //
    void setBreed(string b) {
      breed = b;
    }

    // Cat speak method //
    void speak() {
      cout << name << " says 'Meow!'" << endl;
    }
};

/////// MAIN METHOD ///////
int main() {
  // create instance of the Cat class and pass values to its attributes //
  Cat myCat("Mittens", 5, "Birman");

  // print attributes to the terminal //
  cout << myCat.name << " the " << myCat.breed << " is " << myCat.age << " year(s) old." << endl;

  // call speak method //
  myCat.speak();

  // change attributes using the set methods //
  myCat.setName("Snowshoe");
  myCat.setAge(7);
  myCat.setBreed("Ragdoll");

  // access new attributes using the get methods //
  cout << "Name: " << myCat.getName() << endl;
  cout << "Age: " << myCat.getAge() << endl;
  cout << "Breed: " << myCat.getBreed() << endl;
}
