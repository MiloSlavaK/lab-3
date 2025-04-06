#include <iostream>
#include <memory>
#include <vector>

// Класс изображения
class Image {
public:
    Image(const std::string& name) : name(name) {
        std::cout << "Add image: " << name << std::endl;
    }

    ~Image() {
        std::cout << "Delete image: " << name << std::endl;
    }

    void display() const {
        std::cout << name << std::endl;
    }

private:
    std::string name;
};

// Класс окна, которое открывает изображение
class Window {
public:
    Window(std::shared_ptr<Image> img) : image(img) {
        std::cout << "Open window\n";
    }
    ~Window() {
        std::cout << "Close window\n";
    }

private:
    std::shared_ptr<Image> image;
};

int main() {
    // Создаем изображение
    auto Photo = std::make_shared<Image>("image.jpg");

    std::cout << "Counter: " << Photo.use_count() << std::endl;

    // Создаем окна, использующие это изображение
    Window window1(Photo);
    Window window2(Photo);


    std::cout << "Counter: " << Photo.use_count() << std::endl;

    return 0;
}


