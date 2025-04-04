#include <iostream>
class Cat{
public:
  Cat() {};
  ~Cat() {};
};
class Dog{
public:
  Dog() {};
  ~Dog() {};
};
class Animals {
public:
    Animals() {
        a = new Cat();
        b = new Dog();
    }
    
    ~Animals() {}
    
private:
    Cat* a;
    Dog* b;
};
int main() {
Animals vet;
return 0;
}
