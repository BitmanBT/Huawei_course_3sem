#include "ComplexNumberStructure.hpp"
#include <iostream>
#include "test.hpp"

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
    TestOperatorStarIncrease();
    TestOperatorSlashDecrease();
    TestOperatorCheckEqual();
    TestOperatorStarDouble();
    TestOperatorSlashDouble();
    TestOperatorStarIncreaseDouble();
    TestOperatorSlashDecreaseDouble();
    TestOperatorBeginningMinus();
    TestAbs();
    TestArgument();

    ComplexNumber z(1, 2);
    z.print();

    return 0;
}
