#include <iostream>
#include <vector>

class File {
public:
    File() { std::cout << "Add new file\n"; }
    ~File() { std::cout << "Delete file\n"; }
};

int main() {
    int count = 10;
    std::vector<File> folder;

    for (int i = 0; i < count; ++i) {
        folder.emplace_back();
    }

    return 0;
}
