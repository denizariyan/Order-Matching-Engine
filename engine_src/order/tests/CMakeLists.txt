enable_testing()
find_package(GTest REQUIRED)

add_executable(order_object_test order_object_test.cpp ../Order.cpp)
target_link_libraries(order_object_test GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock)
target_include_directories(order_object_test PRIVATE ../)
gtest_add_tests(TARGET order_object_test)

add_executable(order_handler_test order_handler_test.cpp ../Order.cpp ../OrderHandler.cpp)
target_link_libraries(order_handler_test GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock)
target_include_directories(order_object_test PRIVATE ../)
gtest_add_tests(TARGET order_handler_test)
