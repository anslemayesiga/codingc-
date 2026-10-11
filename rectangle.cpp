#include <iostream>
#include <stdexcept>

class Rectangle {
    double width = 1.0;
    double length = 1.0;

public:
    Rectangle() = default;

    Rectangle(double w, double l) {
        setWidth(w);
        setLength(l);
    }

    void setWidth(double value) {
        if (value <= 0) throw std::invalid_argument("Width must be positive.");
        width = value;
    }

    void setLength(double value) {
        if (value <= 0) throw std::invalid_argument("Length must be positive.");
        length = value;
    }

    double area() const { return width * length; }
    double perimeter() const { return 2 * (width + length); }
};

int main() {
    double width, length;
    std::cout << "Enter width: ";
    if (!(std::cin >> width)) {
        std::cerr << "Error: Please enter a valid width.\n";
        return 1;
    }

    std::cout << "Enter length: ";
    if (!(std::cin >> length)) {
        std::cerr << "Error: Please enter valid numbers.\n";
        return 1;
    }

    try {
        Rectangle rectangle(width, length);
        std::cout << "Area: " << rectangle.area()
                  << "\nPerimeter: " << rectangle.perimeter() << '\n';
    } catch (const std::invalid_argument& error) {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
