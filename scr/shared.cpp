#include <iostream>
#include <memory>
#include <vector>

// Класс изображения
class Image {
public:
    Image(const std::string& name) : name(name), width(1920), height(1080) {
        std::cout << "Add image: " << name << std::endl;
    }

    ~Image() {
        std::cout << "Delete image: " << name << std::endl;
    }

    void display() const {
        std::cout << name << " (" << width << "x" << height << ")" << std::endl;
    }

private:
    std::string name;
    int width, height;
};

// Класс окна, которое отображает изображение
class Window {
public:
    Window(std::shared_ptr<Image> img) : image(img) {
        std::cout << "Open window\n";
    }

    void show() {
        if (image) {
            std::cout << "On display: ";
            image->display();
        }
    }

private:
    std::shared_ptr<Image> image;
};

int main() {
    // Создаем общее изображение
    auto sharedImage = std::make_shared<Image>("Im1.jpg");

    std::cout << "Counter: " << sharedImage.use_count() << std::endl;

    // Создаем окна, использующие общее изображение
    Window window1(sharedImage);
    Window window2(sharedImage);

    std::cout << "Counter: " << sharedImage.use_count() << std::endl;

    // Показываем изображения в окнах
    window1.show();
    window2.show();

    // Создаем вектор с дополнительными ссылками
    std::vector<std::shared_ptr<Image>> imageReferences;
    imageReferences.push_back(sharedImage);

    std::cout << "Counter: " << sharedImage.use_count() << std::endl;

    // Очищаем вектор
    imageReferences.clear();

    std::cout << "Counter: " << sharedImage.use_count() << std::endl;

    return 0;
}

