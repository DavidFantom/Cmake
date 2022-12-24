# CMakeList.txt: проект CMake для CMakeProject; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
project(Matrix)

set(SOURCES
        main.cpp
        Matrix.cpp
        )

set(HEADERS
        Matrix.h
        )

# Добавьте источник в исполняемый файл этого проекта.
#add_executable (Matrix "Matrix.cpp" "Matrix.h")
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
