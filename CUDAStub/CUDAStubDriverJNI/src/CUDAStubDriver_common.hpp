
#ifndef CUDASTUB_COMMON
#define CUDASTUB_COMMON

#ifdef _WIN32
#  define WINDOWS_LEAN_AND_MEAN
#  define NOMINMAX
#  include <windows.h>
#endif

#include <stdlib.h>
#include <jni.h>
#include <cuda_runtime.h>
#include <cuda.h>
#include <cudaProfiler.h>

#if defined (__APPLE__) || defined(MACOSX)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <cudaGL.h>

#define CUDA_INTERNAL_ERROR 0x80000001

#include "Logger.hpp"
#include "PointerUtils.hpp"
#include "JNIUtils.hpp"
#include "CallbackUtils.hpp"

// The JVM, used for attaching threads in callbacks, and initialized
// in JNI_OnLoad
JavaVM *globalJvm;


/**
 * A structure containing all information necessary for maintaining
 * the CUDA_MEMCPY2D parameters
 */
typedef struct Memcpy2DData
{
    /** The actual CUDA_MEMCPY2D */
    CUDA_MEMCPY2D memcpy2d;

    /** The host source pointer */
    jobject srcHost;

    /** The data for the host source pointer */
    PointerData *srcHostPointerData;

    /** The host destination pointer */
    jobject dstHost;

    /** The data for the host destination pointer */
    PointerData *dstHostPointerData;

} Memcpy2DData;




/**
 * A structure containing all information necessary for maintaining
 * the CUDA_MEMCPY3D parameters
 */
typedef struct Memcpy3DData
{
    /** The actual CUDA_MEMCPY3D */
    CUDA_MEMCPY3D memcpy3d;

    /** The host source pointer */
    jobject srcHost;

    /** The data for the host source pointer */
    PointerData *srcHostPointerData;

    /** The host destination pointer */
    jobject dstHost;

    /** The data for the host destination pointer */
    PointerData *dstHostPointerData;

} Memcpy3DData;


/**
 * A structure containing all information necessary for maintaining
 * the CUDA_MEMCPY3D_PEER parameters
 */
typedef struct Memcpy3DPeerData
{
    /** The actual CUDA_MEMCPY3D_PEER */
    CUDA_MEMCPY3D_PEER memcpy3d;

    /** The host source pointer */
    jobject srcHost;

    /** The data for the host source pointer */
    PointerData *srcHostPointerData;

    /** The host destination pointer */
    jobject dstHost;

    /** The data for the host destination pointer */
    PointerData *dstHostPointerData;

} Memcpy3DPeerData;

/**
 * A structure storing the native representation of a java
 * JITOptions object
 */
typedef struct JITOptionsData
{
    int numOptions;
    CUjit_option *options;
    void **optionValues;
} JITOptionsData;

#endif