list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)

add_executable(AMP_Tests test_db_utils.cpp)

target_link_libraries(AMP_Tests PRIVATE AMP_Core Catch2::Catch2WithMain)

catch_discover_tests(AMP_Tests)
