enable_testing()
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(GTest REQUIRED)
file(GLOB SOURCES "*.cpp")

add_executable(FormulaEvaluationTestexec ${SOURCES})

target_link_libraries(FormulaEvaluationTestexec Evaluator GTest::GTest GTest::Main)

add_test(FormulaEvaluationTest FormulaEvaluationTestexec)
