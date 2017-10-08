

#ifndef CUDASTUB_COMMON
#define CUDASTUB_COMMON

#ifdef _WIN32
#  define WINDOWS_LEAN_AND_MEAN
#  define NOMINMAX
#  include <windows.h>
#endif

#include <stdlib.h>
#include <jni.h>
#include <nvrtc.h>
#include <stdint.h>

#include "Logger.hpp"
#include "PointerUtils.hpp"
#include "JNIUtils.hpp"

#define CUDA_INTERNAL_ERROR 0x80000001

#endif

