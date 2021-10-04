#include "ComplexNumberStructure.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

#define _USE_MATH_DEFINES

ComplexNumber::~ComplexNumber() {
    real_part = std::nan("");
    imaginary_part = std::nan("");
}

ComplexNumber::ComplexNumber() : real_part(0), imaginary_part(0) {}

ComplexNumber::ComplexNumber(double real_part_new, double imaginary_part_new) {
    real_part = real_part_new;
    imaginary_part = imaginary_part_new;
}

ComplexNumber::ComplexNumber(const ComplexNumber& another) :
    real_part(another.real_part), imaginary_part(another.imaginary_part) {}

ComplexNumber ComplexNumber::operator+ (const ComplexNumber &other) const {
    ComplexNumber z;

    z.real_part = real_part + other.real_part;
    z.imaginary_part = imaginary_part + other.imaginary_part;

    return z;
}

ComplexNumber ComplexNumber::operator- (const ComplexNumber &other) const {
    ComplexNumber z;

    z.real_part = real_part - other.real_part;
    z.imaginary_part = imaginary_part - other.imaginary_part;

    return z;
}

ComplexNumber ComplexNumber::operator* (const ComplexNumber &other) const {
    ComplexNumber z;

    z.real_part = real_part * other.real_part - imaginary_part * other.imaginary_part;
    z.imaginary_part = real_part * other.imaginary_part + imaginary_part * other.real_part;

    return z;
}

ComplexNumber ComplexNumber::operator/ (const ComplexNumber &other) const {
    ComplexNumber z;
    double denominator = other.real_part * other.real_part + other.imaginary_part * other.imaginary_part;

    assert(denominator != 0);

    z.real_part = (real_part * other.real_part + imaginary_part * other.imaginary_part) / denominator;
    z.imaginary_part = (imaginary_part * other.real_part - real_part * other.imaginary_part) / denominator;

    return z;
}

ComplexNumber& ComplexNumber::operator= (const ComplexNumber &other) {
    real_part = other.real_part;
    imaginary_part = other.imaginary_part;

    return *this;
}

ComplexNumber& ComplexNumber::operator+= (const ComplexNumber &other) {
    real_part += other.real_part;
    imaginary_part += other.imaginary_part;

    return *this;
}

ComplexNumber& ComplexNumber::operator-= (const ComplexNumber &other) {
    real_part -= other.real_part;
    imaginary_part -= other.imaginary_part;

    return *this;
}

ComplexNumber& ComplexNumber::operator*= (const ComplexNumber &other) {
    double copy_real = real_part;
    real_part = real_part * other.real_part - imaginary_part * other.imaginary_part;
    imaginary_part = copy_real * other.imaginary_part + imaginary_part * other.real_part;

    return *this;
}

ComplexNumber& ComplexNumber::operator/= (const ComplexNumber &other) {
    double copy_real = real_part;
    double denominator = (other.real_part)^2 + (other.imaginary_part)^2;
    real_part = (real_part * other.real_part + imaginary_part * other.imaginary_part) / denominator;
    imaginary_part = (imaginary_part * other.real_part - copy_real * other.imaginary_part) / denominator;

    return *this;
}

bool ComplexNumber::operator== (const ComplexNumber &other) const {
    if ((real_part == other.real_part) && (imaginary_part == other.imaginary_part)) {
        return true;
    } else {
        return false;
    }
}

ComplexNumber ComplexNumber::operator* (double &other) const {
    ComplexNumber z;

    z.real_part = real_part * other;
    z.imaginary_part = imaginary_part * other;

    return z;
}

ComplexNumber ComplexNumber::operator/ (double &other) const {
    ComplexNumber z;

    assert(other != 0);

    z.real_part = real_part / other;
    z.imaginary_part = imaginary_part / other;

    return z;
}

ComplexNumber& ComplexNumber::operator*= (double &other) {
    real_part *= other;
    imaginary_part *= other;

    return *this;
}

ComplexNumber& ComplexNumber::operator/= (double &other) {
    real_part /= other;
    imaginary_part /= other;

    return *this;
}

ComplexNumber& ComplexNumber::operator- () const {
    real_part *= (-1);
    imaginary_part *= (-1);

    return *this;
}

void ComplexNumber::print() const {
    std::cout << "z = {" << real_part << ", " << imaginary_part << "}" << std::endl;
}

double ComplexNumber::abs() const {
    double abs = sqrt(real_part * real_part + imaginary_part * imaginary_part);

    return abs;
}

double ComplexNumber::argument() const {
    double argument;

    if (real_part > 0)
    {
        argument = atan(imaginary_part/real_part);
    } else if (imaginary_part > 0) {
        argument = M_PI + atan(imaginary_part/real_part);
    } else {
        argument = -M_PI + atan(imaginary_part/real_part);
    }
}
