cmake_minimum_required(VERSION 3.10)
project(OrderMatchEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for headers
include_directories(include)

# Main source files
set(SOURCES
        src/main.cpp
        src/Order.cpp
        src/Orderbook.cpp
        src/OrderFactory.cpp
        src/OrderHistoryObserver.cpp
        src/OrderMatchingStrategy.cpp
)

# Add headers (optional, helps IDEs recognize header files in the project)
set(HEADERS
        include/Order.h
        include/Orderbook.h
        include/OrderFactory.h
        include/OrderHistoryObserver.h
        include/OrderMatchingStrategy.h
)

# Create main application executable
add_executable(OrderMatchEngine ${SOURCES} ${HEADERS})

# Google Test setup with conditional download
find_package(GTest)

if(NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
    )
    FetchContent_MakeAvailable(googletest)
    set(GTEST_LIBRARIES GTest::gtest GTest::gtest_main)
    set(GTEST_INCLUDE_DIRS ${gtest_SOURCE_DIR}/include)
else()
    set(GTEST_LIBRARIES GTest::GTest GTest::Main)
endif()

# Include directories for GTest
include_directories(${GTEST_INCLUDE_DIRS})

# Test source files
set(TEST_SOURCES
        test/OrderMatchingStrategyTest.cpp
        src/Order.cpp
        src/Orderbook.cpp
        src/OrderFactory.cpp
        src/OrderHistoryObserver.cpp
        src/OrderMatchingStrategy.cpp
)

# Create test executable
add_executable(OrderMatchEngine_tests ${TEST_SOURCES} ${HEADERS})
target_link_libraries(OrderMatchEngine_tests ${GTEST_LIBRARIES})

# Enable testing and register tests
enable_testing()
add_test(NAME OrderMatchEngine_tests COMMAND OrderMatchEngine_tests)