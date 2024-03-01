cmake_minimum_required(VERSION 3.28)

project(tmpCppCanAlystII LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
	3rdparty/Chuangxin/include
)

add_executable(tmpCppCanAlystII main.cpp)

target_link_libraries(tmpCppCanAlystII PRIVATE
	-lControlCAN -LC:/projects/tmp/tmpCppCanAlystII/3rdparty/Chuangxin/lib
)

install(TARGETS tmpCppCanAlystII
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
