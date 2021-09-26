#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cassert>

class ComplexNumber {
private:
    double m_real_part;
    double m_imaginary_part;

public:
    // Constructor

    ComplexNumber(double real_part = NAN, double imaginary_part = NAN) {
        m_real_part = real_part;
        m_imaginary_part = imaginary_part;
    }

    // Operator "+"

    friend ComplexNumber operator+(const ComplexNumber &z1, const ComplexNumber &z2);

    friend ComplexNumber operator+(const ComplexNumber &z1, double value);

    friend ComplexNumber operator+(double value, const ComplexNumber &z2);

    // Operator "-"

    friend ComplexNumber operator-(const ComplexNumber &z1, const ComplexNumber &z2);

    friend ComplexNumber operator-(const ComplexNumber &z1, double value);

    friend ComplexNumber operator-(double value, const ComplexNumber &z2);

    // Operator "*"

    friend ComplexNumber operator*(const ComplexNumber &z1, const ComplexNumber &z2);

    friend ComplexNumber operator*(const ComplexNumber &z1, double value);

    friend ComplexNumber operator*(double value, const ComplexNumber &z2);

    // Operator "/"

    friend ComplexNumber operator/(const ComplexNumber &z1, const ComplexNumber &z2);

    friend ComplexNumber operator/(const ComplexNumber &z1, double value);

    friend ComplexNumber operator/(double value, const ComplexNumber &z2);

    // Prints parts of the complex number

    void print(){
        std::cout << "The real part is " << m_real_part << ' ' << std::endl
            <<"The imaginary part is " << m_imaginary_part << '.' << std::endl;
    }

    // Asks user to enter the complex number

    void set() {
        std::cout << "Enter the real part: ";
        std::cin >> m_real_part;
        assert(m_real_part);

        std::cout << "Enter the imaginary part: ";
        std::cin >> m_imaginary_part;
        assert(m_imaginary_part);
    }

    // Those two functions gives you real or complex part of your complex number

    double getRealPart() const {return m_real_part;}

    double getComplexPart() const {return m_imaginary_part;}
};

// Operator "+"

ComplexNumber operator+(const ComplexNumber &z1, const ComplexNumber &z2) {
    return ComplexNumber(z1.m_real_part + z2.m_real_part, z1.m_imaginary_part + z2.m_imaginary_part);
}

ComplexNumber operator+(const ComplexNumber &z1, double value) {
    return ComplexNumber(z1.m_real_part + value, z1.m_imaginary_part);
}

ComplexNumber operator+(double value, const ComplexNumber &z2) {
    return ComplexNumber(z2.m_real_part + value, z2.m_imaginary_part);
}

// Operator "-"

ComplexNumber operator-(const ComplexNumber &z1, const ComplexNumber &z2) {
    return ComplexNumber(z1.m_real_part - z2.m_real_part, z1.m_imaginary_part - z2.m_imaginary_part);
}

ComplexNumber operator-(const ComplexNumber &z1, double value) {
    return ComplexNumber(z1.m_real_part - value, z1.m_imaginary_part);
}

ComplexNumber operator-(double value, const ComplexNumber &z2) {
    return ComplexNumber(value - z2.m_real_part, -z2.m_imaginary_part);
}

// Operator "*"

ComplexNumber operator*(const ComplexNumber &z1, const ComplexNumber &z2) {
    return ComplexNumber(z1.m_real_part * z2.m_real_part - z1.m_imaginary_part * z2.m_imaginary_part,
                         z1.m_real_part * z2.m_imaginary_part + z1.m_imaginary_part * z2.m_real_part);
}

ComplexNumber operator*(const ComplexNumber &z1, double value) {
    return ComplexNumber(z1.m_real_part * value, z1.m_imaginary_part * value);
}

ComplexNumber operator*(double value, const ComplexNumber &z2) {
    return ComplexNumber(z2.m_real_part * value, z2.m_imaginary_part * value);
}

// Operator "/"

ComplexNumber operator/(const ComplexNumber &z1, const ComplexNumber &z2) {
    return ComplexNumber((z1.m_real_part * z2.m_real_part + z1.m_imaginary_part * z2.m_imaginary_part) / (z2.m_real_part * z2.m_real_part + z2.m_imaginary_part * z2.m_imaginary_part),
                         (z1.m_imaginary_part * z2.m_real_part - z1.m_real_part * z2.m_imaginary_part) / (z2.m_real_part * z2.m_real_part + z2.m_imaginary_part * z2.m_imaginary_part));
}

ComplexNumber operator/(const ComplexNumber &z1, double value) {
    return ComplexNumber(z1.m_real_part / value, z1.m_imaginary_part / value);
}

ComplexNumber operator/(double value, const ComplexNumber &z2) {
    return ComplexNumber((z2.m_real_part * value) / (z2.m_real_part * z2.m_real_part + z2.m_imaginary_part * z2.m_imaginary_part),
                         (-z2.m_imaginary_part * value) / (z2.m_real_part * z2.m_real_part + z2.m_imaginary_part * z2.m_imaginary_part));
}

int main() {
    ComplexNumber a;

    a.set();
    a.print();

    std::cout << std::endl;

    ComplexNumber b(1, 1);
    std::cout << "Here is complex number b:" << std::endl;
    b.print();

    std::cout << std::endl;

    ComplexNumber c = a + b;
    std::cout << "c = a + b = {" << c.getRealPart() << ", " << c.getComplexPart() << "}" << std::endl;

    std::cout << std::endl;

    c = a - b;
    std::cout << "c = a - b = {" << c.getRealPart() << ", " << c.getComplexPart() << "}" << std::endl;

    std::cout << std::endl;

    c = a + 4;
    std::cout << "c = a + 4 = {" << c.getRealPart() << ", " << c.getComplexPart() << "}" << std::endl;

    std::cout << std::endl;

    c = 4 - b;
    std::cout << "c = 4 - b = {" << c.getRealPart() << ", " << c.getComplexPart() << "}" << std::endl;

    std::cout << std::endl;

    c = a * b;
    std::cout << "c = a * b = {" << c.getRealPart() << ", " << c.getComplexPart() << "}" << std::endl;

    std::cout << std::endl;

    c = 4 * a;
    std::cout << "c = 4 * a = {" << c.getRealPart() << ", " << c.getComplexPart() << "}" << std::endl;

    std::cout << std::endl;

    c = a / b;
    std::cout << "c = a / b = {" << c.getRealPart() << ", " << c.getComplexPart() << "}" << std::endl;

    std::cout << std::endl;

    c = a / 4;
    std::cout << "c = a / 4 = {" << c.getRealPart() << ", " << c.getComplexPart() << "}" << std::endl;

    std::cout << std::endl;

    c = 4 / a;
    std::cout << "c = 4 / a = {" << c.getRealPart() << ", " << c.getComplexPart() << "}" << std::endl;

    return 0;
}
