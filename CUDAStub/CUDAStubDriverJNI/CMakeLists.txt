cmake_minimum_required(VERSION 3.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../CUDAStub-common/CUDAStubCommon_CMake_flags.txt)

project(CUDAStubDriver)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../CUDAStub-common/CUDAStubCommon_CMake.txt)

if (NOT TARGET CUDAStubCommonJNI)
    add_subdirectory(
        ${CMAKE_CURRENT_SOURCE_DIR}/../../CUDAStub-common/CUDAStubCommonJNI
        ${CMAKE_CURRENT_BINARY_DIR}/bin)
endif() 

set (BUILD_SHARED_LIBS ON)

include_directories (
    src/
    ${CUDAStubCommonJNI_INCLUDE_DIRS}
    ${JNI_INCLUDE_DIRS}
    ${CUDA_INCLUDE_DIRS}
)
  
cuda_add_library(${PROJECT_NAME}
    src/CUDAStubDriver.cpp
)






target_link_libraries(${PROJECT_NAME}
    CUDAStubCommonJNI
    ${CUDA_CUDA_LIBRARY}
)

set_target_properties(${PROJECT_NAME} 
    PROPERTIES OUTPUT_NAME ${PROJECT_NAME}-${CUDAStub_VERSION}-${CUDAStub_OS}-${CUDAStub_ARCH})
