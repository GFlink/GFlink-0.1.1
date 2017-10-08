cmake_minimum_required(VERSION 3.1)


project(CUDAStubCommonJNI)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../CUDAStub-common/CUDAStubCommon_CMake.txt)

set (BUILD_SHARED_LIBS OFF)

include_directories (
    src/
    ${JNI_INCLUDE_DIRS}
)
  
add_library(${PROJECT_NAME}
    src/JNIUtils.cpp
    src/Logger.cpp
    src/PointerUtils.cpp
    src/CallbackUtils.cpp
)

if (UNIX AND NOT WIN32)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif(UNIX AND NOT WIN32)
