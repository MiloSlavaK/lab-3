#include <iostream>
class Book{
public:
  Book() { std::cout << "Add new book\n";};
  ~Book() {std::cout << "Remove book\n";};
};
int main() {
  int count = 10;
  for (int i = 0; i < count; ++i) {
    Book* new_book = new Book();
  }
  }
