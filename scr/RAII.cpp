#include <iostream>
#include <vector>

class Book {
public:
    Book() { std::cout << "Add new book\n"; }
    ~Book() { std::cout << "Remove book\n"; }
};

int main() {
    int count = 10;
    std::vector<Book> books;
    
    for (int i = 0; i < count; ++i) {
        books.emplace_back();
    }
    
    return 0;
}
