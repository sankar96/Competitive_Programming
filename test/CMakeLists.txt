enable_testing()
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest REQUIRED)
file(GLOB SOURCES "*.cpp")

add_executable(testingsourcesexec ${SOURCES})

target_link_libraries(testingsourcesexec Competitive_Programming GTest::GTest GTest::Main)

add_test(TestingSources testingsourcesexec)


