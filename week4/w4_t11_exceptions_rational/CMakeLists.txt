# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("w4_t11_exceptions_rational")

# Включите подпроекты.
add_executable (w4_t11_exceptions_rational src/w4_t11_exceptions_rational.cpp)
