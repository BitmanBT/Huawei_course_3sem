#include "ComplexNumberStructure.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

#define _USE_MATH_DEFINES

void TestDefaultConstructor();

void TestConstructor();

void TestCopyConstructor();

void TestOperatorPlus();

void TestOperatorMinus();

void TestOperatorStar();

void TestOperatorSlash();

void TestOperatorEqual();

void TestOperatorIncrease();

void TestOperatorDecrease();

void TestOperatorStarIncrease();

void TestOperatorSlashDecrease();

void TestOperatorCheckEqual();

void TestOperatorStarDouble();

void TestOperatorSlashDouble();

void TestOperatorStarIncreaseDouble();

void TestOperatorSlashDecreaseDouble();

void TestOperatorBeginningMinus();

void TestAbs();

void TestArgument();

void TestDefaultConstructor() {
    ComplexNumber z;

    if ((z.real_part == 0) && (z.imaginary_part == 0)) {
        std::cout << "Default Constructor Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Default Constructor Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestConstructor() {
    ComplexNumber z(1, 2);

    if ((z.real_part == 1) && (z.imaginary_part == 2)) {
        std::cout << "Constructor Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Constructor Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestCopyConstructor() {
    ComplexNumber z_1;

    ComplexNumber z_new_first_test(z_1);

    bool flag = false;

    if (!((z_new_first_test.real_part == z_1.real_part) && (z_new_first_test.imaginary_part == z_1.imaginary_part))) {
        flag = true;
    }

    ComplexNumber z_2(1, 2);

    ComplexNumber z_new_second_test(z_2);

    if (!((z_new_second_test.real_part == z_2.real_part) && (z_new_second_test.imaginary_part == z_2.imaginary_part))) {
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

    if ((z.real_part == 3) && (z.imaginary_part == 5)) {
        std::cout << "Operator+ Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator+ Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorMinus() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    ComplexNumber z = z1 - z2;

    if ((z.real_part == -1) && (z.imaginary_part == -1)) {
        std::cout << "Operator- Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator- Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorStar() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    ComplexNumber z = z1 * z2;

    if ((z.real_part == -4) && (z.imaginary_part == 7)) {
        std::cout << "Operator* Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator* Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorSlash() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(1, 1);

    ComplexNumber z = z1 / z2;

    if ((z.real_part == 1.5) && (z.imaginary_part == 0.5)) {
        std::cout << "Operator/ Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator/ Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorEqual() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    z1 = z2;

    if ((z1.real_part == 2) && (z1.imaginary_part == 3)) {
        std::cout << "Operator= Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator= Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorIncrease() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    z1 += z2;

    if ((z1.real_part == 3) && (z1.imaginary_part == 5)) {
        std::cout << "Operator+= Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator+= Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorDecrease() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    z1 -= z2;

    if ((z1.real_part == -1) && (z1.imaginary_part == -1)) {
        std::cout << "Operator-= Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator-= Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorStarIncrease() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    z1 *= z2;

    if ((z1.real_part == -4) && (z1.imaginary_part == 7)) {
        std::cout << "Operator*= Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator*= Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorSlashDecrease() {
    ComplexNumber z1(1, 2);
    ComplexNumber z2(2, 3);

    z1 /= z2;

    if ((z1.real_part == 8/13) && (z1.imaginary_part == 1/13)) {
        std::cout << "Operator/= Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator/= Test on line " << __LINE__ << " failed!" << std::endl;
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

void TestOperatorStarDouble() {
    ComplexNumber z1(1, 2);
    double x = 2;

    ComplexNumber z2 = z1 * x;

    if ((z2.real_part == 2) && (z2.imaginary_part == 4)) {
        std::cout << "Operator*double Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator*double Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorSlashDouble() {
    ComplexNumber z1(1, 2);
    double x = 2;

    ComplexNumber z2 = z1 / x;

    if ((z2.real_part == 0.5) && (z2.imaginary_part == 1)) {
        std::cout << "Operator/double Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator/double Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorStarIncreaseDouble() {
    ComplexNumber z1(1, 2);
    double x = 2;

    z1 *= x;

    if ((z1.real_part == 2) && (z1.imaginary_part == 4)) {
        std::cout << "Operator*=double Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator*=double Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorSlashDecreaseDouble() {
    ComplexNumber z1(1, 2);
    double x = 2;

    z1 /= x;

    if ((z1.real_part == 0.5) && (z1.imaginary_part == 1)) {
        std::cout << "Operator/=double Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "Operator/=double Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

void TestOperatorBeginningMinus() {
    ComplexNumber z(1, -1);

    z = -z;

    if ((z.real_part == -1) && (z.imaginary_part == 1)) {
        std::cout << "OperatorBeginning- Test on line " << __LINE__ << " is OK." << std::endl;
    } else {
        std::cout << "OperatorBeginning- Test on line " << __LINE__ << " failed!" << std::endl;
    }
}

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
