cmake_minimum_required (VERSION 3.1)

project(Testing VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

set(ADD_TESTING ON)
set(ADD_SANITIZERS ON)

if (ADD_TESTING)
	include(FetchContent)
	FetchContent_Declare(
	  googletest
	  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
	)

	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(googletest)

	enable_testing()

	file(GLOB_RECURSE SOURCES *.cpp)
	set(TEST stack_test)

	include(GoogleTest)

	add_executable(${TEST} ${SOURCES})
	add_custom_target(run_${TEST}
						COMMENT "Running ${TEST}"
						COMMAND ./${TEST})
	add_dependencies(run_${TEST} ${TEST})

	gtest_discover_tests(${TEST})

	target_link_libraries(${TEST} gtest_main stack)

	if (ADD_SANITIZERS)
		message("Build with sanitizers")
		target_compile_options(${TEST} PUBLIC -fsanitize=address -g)
		set_target_properties(${TEST} PROPERTIES LINK_FLAGS "-fsanitize=address")
	endif()
endif()
