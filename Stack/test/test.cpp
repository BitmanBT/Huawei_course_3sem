#include "test-impl.h"
#include <iostream>

int main()
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}