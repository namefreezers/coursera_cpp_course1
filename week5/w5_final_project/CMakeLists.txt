# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("w5_final_project")

set(CMAKE_CXX_STANDARD 17)

# Включите подпроекты.
add_executable (w5_final_project src/w5_final_project.cpp)
