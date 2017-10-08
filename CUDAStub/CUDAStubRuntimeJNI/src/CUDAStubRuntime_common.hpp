

#ifndef CUDA_COMMON
#define CUDA_COMMON

#ifdef _WIN32
#  define WINDOWS_LEAN_AND_MEAN
#  define NOMINMAX
#  include <windows.h>
#endif

#include <stdlib.h>
#include <jni.h>
#include <cuda_runtime.h>
#include <cuda_gl_interop.h>
#include <cuda_profiler_api.h>
#include <cuda.h>

#include "Logger.hpp"
#include "JNIUtils.hpp"
#include "PointerUtils.hpp"
#include "CallbackUtils.hpp"

// The JVM, used for attaching threads in callbacks, and initialized
// in JNI_OnLoad
JavaVM *globalJvm;

#define CUDA_INTERNAL_ERROR 0x80000001

#endif