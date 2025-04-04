class Book{
public:
  Book() { std::cout << "Add new book\n"; }
  ~Book() { std::cout << "Remove book\n"; }
};

int main() {
  int count = 10;
  
  // Создаем массив для хранения умных указателей
  std::vector<std::unique_ptr<Book>> books;
  
  for (int i = 0; i < count; ++i) {
    // Используем make_unique для безопасного создания объекта
    books.emplace_back(std::make_unique<Book>());
  }
  
  return 0;
}
