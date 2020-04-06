# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("w4_t07_table")

# Включите подпроекты.
add_executable(w4_t07_table src/w4_t07_table.cpp)

