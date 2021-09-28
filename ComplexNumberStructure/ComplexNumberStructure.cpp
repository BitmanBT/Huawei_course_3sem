#include "Header.hpp"

ComplexNumber::ComplexNumber() : real_part_(0), imaginary_part_(0) {}

ComplexNumber::ComplexNumber(double real_part, double imaginary_part) {
    real_part_ = real_part;
    imaginary_part_ = imaginary_part;
}

ComplexNumber::ComplexNumber(const ComplexNumber& another) :
    real_part_(another.real_part_), imaginary_part_(another.imaginary_part_) {}

ComplexNumber ComplexNumber::operator+ (const ComplexNumber &other) const {
    ComplexNumber z;

    z.real_part_ = real_part_ + other.real_part_;
    z.imaginary_part_ = imaginary_part_ + other.imaginary_part_;

    return z;
}

ComplexNumber ComplexNumber::operator- (const ComplexNumber &other) const {
    ComplexNumber z;

    z.real_part_ = real_part_ - other.real_part_;
    z.imaginary_part_ = imaginary_part_ - other.imaginary_part_;

    return z;
}

ComplexNumber ComplexNumber::operator* (const ComplexNumber &other) const {
    ComplexNumber z;

    z.real_part_ = real_part_ * other.real_part_ - imaginary_part_ * other.imaginary_part_;
    z.imaginary_part_ = real_part_ * other.imaginary_part_ + imaginary_part_ * other.real_part_;

    return z;
}

ComplexNumber ComplexNumber::operator/ (const ComplexNumber &other) const {
    ComplexNumber z;
    double denominator = other.real_part_ * other.real_part_ + other.imaginary_part_ * other.imaginary_part_;

    assert(denominator != 0);

    z.real_part_ = (real_part_ * other.real_part_ + imaginary_part_ * other.imaginary_part_) / denominator;
    z.imaginary_part_ = (imaginary_part_ * other.real_part_ - real_part_ * other.imaginary_part_) / denominator;

    return z;
}

ComplexNumber ComplexNumber::operator= (const ComplexNumber &other) {
    this -> real_part_ = other.real_part_;
    this -> imaginary_part_ = other.imaginary_part_;

    return *this;
}

ComplexNumber ComplexNumber::operator+= (const ComplexNumber &other) {
    this -> real_part_ += other.real_part_;
    this -> imaginary_part_ += other.imaginary_part_;

    return *this;
}

ComplexNumber ComplexNumber::operator-= (const ComplexNumber &other) {
    this -> real_part_ -= other.real_part_;
    this -> imaginary_part_ -= other.imaginary_part_;

    return *this;
}

bool ComplexNumber::operator== (const ComplexNumber &other) {
    if ((real_part_ == other.real_part_) && (imaginary_part_ == other.imaginary_part_)) {
        return true;
    } else {
        return false;
    }
}

ComplexNumber ComplexNumber::operator+ (const double &other) const {
    ComplexNumber z;

    z.real_part_ = real_part_ + other;
    z.imaginary_part_ = imaginary_part_;

    return z;
}

ComplexNumber ComplexNumber::operator- (const double &other) const {
    ComplexNumber z;

    z.real_part_ = real_part_ - other;
    z.imaginary_part_ = imaginary_part_;

    return z;
}

ComplexNumber ComplexNumber::operator* (const double &other) const {
    ComplexNumber z;

    z.real_part_ = real_part_ * other;
    z.imaginary_part_ = imaginary_part_ * other;

    return z;
}

ComplexNumber ComplexNumber::operator/ (const double &other) const {
    ComplexNumber z;

    assert(other != 0);

    z.real_part_ = real_part_ / other;
    z.imaginary_part_ = imaginary_part_ / other;

    return z;
}

ComplexNumber ComplexNumber::operator= (const double &other) {
    this -> real_part_ = other;
    this -> imaginary_part_ = 0;

    return *this;
}

ComplexNumber ComplexNumber::operator+= (const double &other) {
    this -> real_part_ += other;

    return *this;
}

ComplexNumber ComplexNumber::operator-= (const double &other) {
    this -> real_part_ -= other;

    return *this;
}

bool ComplexNumber::operator== (const double &other) {
    if ((real_part_ == other) && (imaginary_part_ == 0)) {
        return true;
    } else {
        return false;
    }
}

/*double operator+ (const ComplexNumber &other) const {
    ComplexNumber z;

    z.real_part_ = this + other.real_part_;
    z.imaginary_part_ = other.imaginary_part_;

    return z;
}*/

void ComplexNumber::print() const {
    std::cout << "z = {" << real_part_ << ", " << imaginary_part_ << "}" << std::endl;
}

double ComplexNumber::abs() const {
    double abs = sqrt(real_part_ * real_part_ + imaginary_part_ * imaginary_part_);

    return abs;
}

double ComplexNumber::argument() const {
    double argument;

    if (real_part_ > 0)
    {
        argument = atan(imaginary_part_/real_part_);
    } else if (imaginary_part_ > 0) {
        argument = M_PI + atan(imaginary_part_/real_part_);
    } else {
        argument = -M_PI + atan(imaginary_part_/real_part_);
    }
}

int main() {
    TestDefaultConstructor();
    TestConstructor();
    TestCopyConstructor();
    TestOperatorPlus();
    TestOperatorMinus();
    TestOperatorStar();
    TestOperatorSlash();
    TestOperatorEqual();
    TestOperatorIncrease();
    TestOperatorDecrease();
    TestOperatorCheckEqual();
    TestOperatorPlusDouble();
    TestOperatorMinusDouble();
    TestOperatorStarDouble();
    TestOperatorSlashDouble();
    TestOperatorEqualDouble();
    TestOperatorIncreaseDouble();
    TestOperatorDecreaseDouble();
    TestOperatorCheckEqualDouble();
    //TestOperatorPlusDoubleReversed();
    TestAbs();
    TestArgument();

    ComplexNumber z(1, 2);
    z.print();

    return 0;
}

void TestDefaultConstructor() {
    ComplexNumber z;

    if ((z.real_part_ == 0) && (z.imaginary_part_ == 0)) {
        std::cout << "Default Constructor Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Default Constructor Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestConstructor() {
    ComplexNumber z(1, 2);

    if ((z.real_part_ == 1) && (z.imaginary_part_ == 2)) {
        std::cout << "Constructor Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Constructor Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestCopyConstructor() {
    ComplexNumber z_1;

    ComplexNumber z_new_first_test(z_1);

    bool flag = false;

    if (!((z_new_first_test.real_part_ == z_1.real_part_) && (z_new_first_test.imaginary_part_ == z_1.imaginary_part_))) {
        flag = true;
    }

    ComplexNumber z_2(1, 2);

    ComplexNumber z_new_second_test(z_2);

    if (!((z_new_second_test.real_part_ == z_2.real_part_) && (z_new_second_test.imaginary_part_ == z_2.imaginary_part_))) {
        flag = true;
    }

    if (flag == false) {
        std::cout << "Copy Constructor Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Copy Constructor Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorPlus() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    ComplexNumber z = z1 + z2;

    if ((z.real_part_ == 3) && (z.imaginary_part_ == 5)) {
        std::cout << "Operator+ Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator+ Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorMinus() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    ComplexNumber z = z1 - z2;

    if ((z.real_part_ == -1) && (z.imaginary_part_ == -1)) {
        std::cout << "Operator- Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator- Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorStar() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    ComplexNumber z = z1 * z2;

    if ((z.real_part_ == -4) && (z.imaginary_part_ == 7)) {
        std::cout << "Operator* Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator* Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorSlash() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(1, 1);

    ComplexNumber z = z1 / z2;

    if ((z.real_part_ == 1.5) && (z.imaginary_part_ == 0.5)) {
        std::cout << "Operator/ Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator/ Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorEqual() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    z1 = z2;

    if ((z1.real_part_ == 2) && (z1.imaginary_part_ == 3)) {
        std::cout << "Operator= Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator= Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorIncrease() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    z1 += z2;

    if ((z1.real_part_ == 3) && (z1.imaginary_part_ == 5)) {
        std::cout << "Operator+= Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator+= Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorDecrease() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    z1 -= z2;

    if ((z1.real_part_ == -1) && (z1.imaginary_part_ == -1)) {
        std::cout << "Operator-= Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator-= Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorCheckEqual() {
    ComplexNumber z1(1, 1);
    ComplexNumber z2(1, 1);

    bool check_1 = false;

    if (z1 == z2)
        check_1 = true;

    ComplexNumber z3(1, 1);
    ComplexNumber z4(2, 2);

    bool check_2 = false;

    if (z3 == z4)
        check_2 = true;

    if ((check_1 == true) && (check_2 == false)) {
        std::cout << "Operator== Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator== Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorPlusDouble() {
    ComplexNumber z1(1, 2);
    double x = 1;

    ComplexNumber z2 = z1 + x;

    if ((z2.real_part_ == 2) && (z2.imaginary_part_ == 2)) {
        std::cout << "Operator+double Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator+double Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorMinusDouble() {
    ComplexNumber z1(1, 2);
    double x = 1;

    ComplexNumber z2 = z1 - x;

    if ((z2.real_part_ == 0) && (z2.imaginary_part_ == 2)) {
        std::cout << "Operator-double Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator-double Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorStarDouble() {
    ComplexNumber z1(1, 2);
    double x = 2;

    ComplexNumber z2 = z1 * x;

    if ((z2.real_part_ == 2) && (z2.imaginary_part_ == 4)) {
        std::cout << "Operator*double Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator*double Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorSlashDouble() {
    ComplexNumber z1(1, 2);
    double x = 2;

    ComplexNumber z2 = z1 / x;

    if ((z2.real_part_ == 0.5) && (z2.imaginary_part_ == 1)) {
        std::cout << "Operator/double Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator/double Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorEqualDouble() {
    ComplexNumber z1(1, 2);
    double x = 2;;

    z1 = x;

    if ((z1.real_part_ == 2) && (z1.imaginary_part_ == 0)) {
        std::cout << "Operator=double Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator=double Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorIncreaseDouble() {
    ComplexNumber z1(1, 2);
    double x = 1;

    z1 += x;

    if ((z1.real_part_ == 2) && (z1.imaginary_part_ == 2)) {
        std::cout << "Operator+=double Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator+=double Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorDecreaseDouble() {
    ComplexNumber z1(1, 2);
    double x = 1;

    z1 -= x;

    if ((z1.real_part_ == 0) && (z1.imaginary_part_ == 2)) {
        std::cout << "Operator-=double Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator-=double Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorCheckEqualDouble() {
    ComplexNumber z1(1, 0);
    double x = 1;

    bool check_1 = false;

    if (z1 == x)
        check_1 = true;

    ComplexNumber z2(1, 1);

    bool check_2 = false;

    if (z2 == x)
        check_2 = true;

    if ((check_1 == true) && (check_2 == false)) {
        std::cout << "Operator==double Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator==double Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

/*void TestOperatorPlusDoubleReversed() {
    ComplexNumber z1(1, 2);
    double x = 1;

    ComplexNumber z2 = x + z1;

    if ((z2.real_part_ == 2) && (z2.imaginary_part_ == 2)) {
        std::cout << "Operator+double_reversed Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator+double_reversed Test on line " << __LINE__ << " failed!" << std::endl;
    }
}*/

void TestAbs() {
    ComplexNumber z(3, 4);

    double abs = z.abs();

    if (abs == 5)
    {
        std::cout << "Abs Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Abs Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestArgument() {
    ComplexNumber z1(1, 1);

    bool flag = false;

    double argument = z1.argument();

    if (argument != M_PI/4)
        flag = true;

    ComplexNumber z2(-1, 1);

    argument = z2.argument();

    if (argument != 3 * M_PI /4)
        flag = true;

    ComplexNumber z3(-1, -1);

    argument = z3.argument();

    if (argument != -3 * M_PI /4)
        flag = true;

    if (flag == false) {
        std::cout << "Argument Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Argument Test on line " << __LINE__ << " failed!" << std::endl;
    }
}
