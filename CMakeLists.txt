cmake_minimum_required(VERSION 3.5)
message(STATUS "start")

find_package(GMP QUIET)
set(GMP_SOURCE_DIR "deps/gmp-6.2.1")
set(GMP_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${GMP_SOURCE_DIR}/libs)

if(GMP_FOUND)
  message(STATUS "entrato")

else()
  message(STATUS "nell'else")
  #execute_process(
    #COMMAND ${GMP_SOURCE_DIR}/configure --prefix=${GMP_LIB_DIR} #--disable-static
    #COMMAND ${GMP_SOURCE_DIR}/configure --help
    #COMMAND make
    #COMMAND make check
    #WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}${GMP_SOURCE_DIR}
    #)
endif()

project(quad-precision-test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(quad-precision-test
  main.cpp
)

add_subdirectory("deps/math-boost-1.79.0")
add_subdirectory("deps/multiprecision-1.79")

find_library(GMP_LIB libgmp)

#add_library(lib-gmp SHARED IMPORTED)
#set_property(TARGET lib-gmp PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/deps/gmp-6.2.1/lib/libgmp.so")


target_link_libraries(quad-precision-test
  PRIVATE
  Boost::math
  Boost::multiprecision
  quadmath
  "/usr/local/lib/libgmp.so"

)

