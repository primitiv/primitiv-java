cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(jprimitiv VERSION 0.4.0 LANGUAGES Java CXX)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror -fPIC")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror -fPIC")
else()
  message(WARNING "primitiv-java may not support the detected compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

find_package(Primitiv REQUIRED)
find_package(Java COMPONENTS Development)
find_package(JNI REQUIRED)

include_directories(
  ${JNI_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_BINARY_DIR}/src)

include(UseJava)

# core library
add_subdirectory(src)

# # tests
# if(PRIMITIV_JAVA_BUILD_TESTS)
#   enable_testing()
#   add_subdirectory(test)
# endif()
#
