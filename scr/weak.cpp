#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Image {
public:
    explicit Image(const std::string& name) : name(name) {
        std::cout << "Add image: " << name << std::endl;
    }

    ~Image() {
        std::cout << "Delete image: " << name << std::endl;
    }

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
};

class ImageCache {
public:
    void addImage(const std::shared_ptr<Image>& image) {
        images.push_back(image);
    }

    void displayImages() {
        for (const auto& weakImage : images) {
            if (auto img = weakImage.lock()) {
                std::cout << "Image: " << img->getName() << std::endl;
            }
            else {
                std::cout << "Delete image from cache" << std::endl;
            }
        }
    }

private:
    std::vector<std::weak_ptr<Image>> images;
};

int main() {
    ImageCache cache;

    {
        auto image1 = std::make_shared<Image>("image1.jpg");
        auto image2 = std::make_shared<Image>("image2.png");

        cache.addImage(image1);
        cache.addImage(image2);

        // Отображаем изображения
        cache.displayImages();
    } // Выйдем из области видимости, изображения будут уничтожены

    // Попробуем отобразить изображения снова
    cache.displayImages();

    return 0;
}
