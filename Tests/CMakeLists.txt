# CMakeList.txt: проект CMake для CMakeProject; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
project(Tests)

set (gtest_force_shared_crt on cache bool "" force)
include(GoogleTest)


set (TESTS
        Test.h
        )


include_directories(${PROJECT_NAME} PUBLIC ../Matrix)

set (EXT_HEADERS

        ../Matrix/Matrix.h
        )

set (EXT_SOURCES
        ../Matrix/Matrix.cpp
        )

# Добавьте источник в исполняемый файл этого проекта.

add_definitions(-DINPUTDIR="${PROJECT_SOURCE_DIR}/input")

#add_library (gtest STATIC IMPORTED)

add_executable(${PROJECT_NAME} Main.cpp ${TESTS} ${EXT_SOURCES} ${EXT_HEADERS})


target_link_libraries(${PROJECT_NAME} gtest gtest_main gmock gmock_main)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

# оценка покрытия кода тестами
#target_link_libraries(${PROJECT_NAME} gcov)

gtest_add_tests(TARGET      ${PROJECT_NAME}
        TEST_SUFFIX .noArgs
        TEST_LIST   noArgsTests
        )
gtest_add_tests(TARGET      ${PROJECT_NAME}
        EXTRA_ARGS  --someArg someValue
        TEST_SUFFIX .withArgs
        TEST_LIST   withArgsTests
        )
