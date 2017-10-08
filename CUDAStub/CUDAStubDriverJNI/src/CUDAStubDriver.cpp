/*
 * CUDAWrapper - Java bindings for NVIDIA CUDA driver and runtime API
 *
 * Copyright (c) 2009-2015 Marco Hutter - http://www.CUDAWrapper.org
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "CUDAStubDriver.hpp"
#include "CUDAStubDriver_common.hpp"
#include <cstring>
#include <string>

jfieldID CUdevprop_maxThreadsPerBlock; // int
jfieldID CUdevprop_maxThreadsDim; // int[3]
jfieldID CUdevprop_maxGridSize; // int[3]
jfieldID CUdevprop_sharedMemPerBlock; // int
jfieldID CUdevprop_totalConstantMemory; // int
jfieldID CUdevprop_SIMDWidth; // int
jfieldID CUdevprop_memPitch; // int
jfieldID CUdevprop_regsPerBlock; // int
jfieldID CUdevprop_clockRate; // int
jfieldID CUdevprop_textureAlign; // int

jfieldID CUDA_ARRAY_DESCRIPTOR_Width; // size_t
jfieldID CUDA_ARRAY_DESCRIPTOR_Height; // size_t
jfieldID CUDA_ARRAY_DESCRIPTOR_Format; // CUarray_format
jfieldID CUDA_ARRAY_DESCRIPTOR_NumChannels; // unsigned int

jfieldID CUDA_ARRAY3D_DESCRIPTOR_Width; // size_t
jfieldID CUDA_ARRAY3D_DESCRIPTOR_Height; // size_t
jfieldID CUDA_ARRAY3D_DESCRIPTOR_Depth; // size_t
jfieldID CUDA_ARRAY3D_DESCRIPTOR_Format; // CUarray_format
jfieldID CUDA_ARRAY3D_DESCRIPTOR_NumChannels; // unsigned int
jfieldID CUDA_ARRAY3D_DESCRIPTOR_Flags; // unsigned int

jfieldID CUDA_MEMCPY2D_srcXInBytes; // size_t
jfieldID CUDA_MEMCPY2D_srcY; // size_t
jfieldID CUDA_MEMCPY2D_srcMemoryType; // CUmemorytype
jfieldID CUDA_MEMCPY2D_srcHost; // Pointer
jfieldID CUDA_MEMCPY2D_srcDevice; // CUdeviceptr
jfieldID CUDA_MEMCPY2D_srcArray; // CUarray
jfieldID CUDA_MEMCPY2D_srcPitch; // size_t
jfieldID CUDA_MEMCPY2D_dstXInBytes; // size_t
jfieldID CUDA_MEMCPY2D_dstY; // size_t
jfieldID CUDA_MEMCPY2D_dstMemoryType; // CUmemorytype
jfieldID CUDA_MEMCPY2D_dstHost; // Pointer
jfieldID CUDA_MEMCPY2D_dstDevice; // CUdeviceptr
jfieldID CUDA_MEMCPY2D_dstArray; // CUarray
jfieldID CUDA_MEMCPY2D_dstPitch; // size_t
jfieldID CUDA_MEMCPY2D_WidthInBytes; // size_t
jfieldID CUDA_MEMCPY2D_Height; // size_t

jfieldID CUDA_MEMCPY3D_srcXInBytes; // size_t
jfieldID CUDA_MEMCPY3D_srcY; // size_t
jfieldID CUDA_MEMCPY3D_srcZ; // size_t
jfieldID CUDA_MEMCPY3D_srcLOD; // size_t
jfieldID CUDA_MEMCPY3D_srcMemoryType; // CUmemorytype
jfieldID CUDA_MEMCPY3D_srcHost; // Pointer
jfieldID CUDA_MEMCPY3D_srcDevice; // CUdeviceptr
jfieldID CUDA_MEMCPY3D_srcArray; // CUarray
jfieldID CUDA_MEMCPY3D_srcPitch; // size_t
jfieldID CUDA_MEMCPY3D_srcHeight; // size_t
jfieldID CUDA_MEMCPY3D_dstXInBytes; // size_t
jfieldID CUDA_MEMCPY3D_dstY; // size_t
jfieldID CUDA_MEMCPY3D_dstZ; // size_t
jfieldID CUDA_MEMCPY3D_dstLOD; // size_t
jfieldID CUDA_MEMCPY3D_dstMemoryType; // CUmemorytype
jfieldID CUDA_MEMCPY3D_dstHost; // Pointer
jfieldID CUDA_MEMCPY3D_dstDevice; // CUdeviceptr
jfieldID CUDA_MEMCPY3D_dstArray; // CUarray
jfieldID CUDA_MEMCPY3D_dstPitch; // size_t
jfieldID CUDA_MEMCPY3D_dstHeight; // size_t
jfieldID CUDA_MEMCPY3D_WidthInBytes; // size_t
jfieldID CUDA_MEMCPY3D_Height; // size_t
jfieldID CUDA_MEMCPY3D_Depth; // size_t

jfieldID CUDA_MEMCPY3D_PEER_srcXInBytes; // size_t
jfieldID CUDA_MEMCPY3D_PEER_srcY; // size_t
jfieldID CUDA_MEMCPY3D_PEER_srcZ; // size_t
jfieldID CUDA_MEMCPY3D_PEER_srcLOD; // size_t
jfieldID CUDA_MEMCPY3D_PEER_srcMemoryType; // CUmemorytype
jfieldID CUDA_MEMCPY3D_PEER_srcHost; // Pointer
jfieldID CUDA_MEMCPY3D_PEER_srcDevice; // CUdeviceptr
jfieldID CUDA_MEMCPY3D_PEER_srcArray; // CUarray
jfieldID CUDA_MEMCPY3D_PEER_srcContext; // CUcontext
jfieldID CUDA_MEMCPY3D_PEER_srcPitch; // size_t
jfieldID CUDA_MEMCPY3D_PEER_srcHeight; // size_t
jfieldID CUDA_MEMCPY3D_PEER_dstXInBytes; // size_t
jfieldID CUDA_MEMCPY3D_PEER_dstY; // size_t
jfieldID CUDA_MEMCPY3D_PEER_dstZ; // size_t
jfieldID CUDA_MEMCPY3D_PEER_dstLOD; // size_t
jfieldID CUDA_MEMCPY3D_PEER_dstMemoryType; // CUmemorytype
jfieldID CUDA_MEMCPY3D_PEER_dstHost; // Pointer
jfieldID CUDA_MEMCPY3D_PEER_dstDevice; // CUdeviceptr
jfieldID CUDA_MEMCPY3D_PEER_dstArray; // CUarray
jfieldID CUDA_MEMCPY3D_PEER_dstContext; // CUcontext
jfieldID CUDA_MEMCPY3D_PEER_dstPitch; // size_t
jfieldID CUDA_MEMCPY3D_PEER_dstHeight; // size_t
jfieldID CUDA_MEMCPY3D_PEER_WidthInBytes; // size_t
jfieldID CUDA_MEMCPY3D_PEER_Height; // size_t
jfieldID CUDA_MEMCPY3D_PEER_Depth; // size_t

jmethodID JITOptions_getKeys;
jmethodID JITOptions_getInt;
jmethodID JITOptions_getFloat;
jmethodID JITOptions_getBytes;
jmethodID JITOptions_putInt;
jmethodID JITOptions_putFloat;

jfieldID CUipcEventHandle_reserved; // byte[]
jfieldID CUipcMemHandle_reserved; // byte[]


jfieldID CUDA_RESOURCE_DESC_resType; // CUresourcetype
jfieldID CUDA_RESOURCE_DESC_array_hArray; // CUarray
jfieldID CUDA_RESOURCE_DESC_mipmap_hMipmappedArray; // CUmipmappedArray
jfieldID CUDA_RESOURCE_DESC_linear_devPtr; // CUdeviceptr
jfieldID CUDA_RESOURCE_DESC_linear_format; // CUarray_format
jfieldID CUDA_RESOURCE_DESC_linear_numChannels; // unsigned int
jfieldID CUDA_RESOURCE_DESC_linear_sizeInBytes; // size_t
jfieldID CUDA_RESOURCE_DESC_pitch2D_devPtr; // CUdeviceptr
jfieldID CUDA_RESOURCE_DESC_pitch2D_format; // CUarray_format
jfieldID CUDA_RESOURCE_DESC_pitch2D_numChannels; // unsigned int
jfieldID CUDA_RESOURCE_DESC_pitch2D_width; // size_t
jfieldID CUDA_RESOURCE_DESC_pitch2D_height; // size_t
jfieldID CUDA_RESOURCE_DESC_pitch2D_pitchInBytes; // size_t

jfieldID CUDA_RESOURCE_VIEW_DESC_format; // CUresourceViewFormat
jfieldID CUDA_RESOURCE_VIEW_DESC_width; // size_t
jfieldID CUDA_RESOURCE_VIEW_DESC_height; // size_t
jfieldID CUDA_RESOURCE_VIEW_DESC_depth; // size_t
jfieldID CUDA_RESOURCE_VIEW_DESC_firstMipmapLevel; // unsigned int
jfieldID CUDA_RESOURCE_VIEW_DESC_lastMipmapLevel; // unsigned int
jfieldID CUDA_RESOURCE_VIEW_DESC_firstLayer; // unsigned int
jfieldID CUDA_RESOURCE_VIEW_DESC_lastLayer; // unsigned int

jfieldID CUDA_TEXTURE_DESC_addressMode; // CUaddress_mode[3]
jfieldID CUDA_TEXTURE_DESC_filterMode; // CUfilter_mode
jfieldID CUDA_TEXTURE_DESC_flags; // unsigned int
jfieldID CUDA_TEXTURE_DESC_maxAnisotropy; // unsigned int
jfieldID CUDA_TEXTURE_DESC_mipmapFilterMode; // CUfilter_mode
jfieldID CUDA_TEXTURE_DESC_mipmapLevelBias; // float
jfieldID CUDA_TEXTURE_DESC_minMipmapLevelClamp; // float
jfieldID CUDA_TEXTURE_DESC_maxMipmapLevelClamp; // float
jfieldID CUDA_TEXTURE_DESC_borderColor; // float[4]

jclass CUdevice_class;
jmethodID CUdevice_constructor;

// Static method ID for the "function pointer" interface
jmethodID CUoccupancyB2DSize_call; // "(I)J"

// The current function pointer object and JNI environment.
// This is not so nice due to the global state. It should
// probably be converted to use a functor, similar to
// cudaOccupancyB2DHelper in cuda_runtime.h
jobject currentOccupancyCallback = NULL;
JNIEnv *currentOccupancyEnv = NULL;

// Static method ID for the CUstreamCallback#call function
static jmethodID CUstreamCallback_call; // (LCUDAWrapper/driver/CUstream;ILjava/lang/Object;)V



/**
 * Called when the library is loaded. Will initialize all
 * required field and method IDs
 */
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved)
{
    JNIEnv *env = NULL;
    if (jvm->GetEnv((void **)&env, JNI_VERSION_1_4))
    {
        return JNI_ERR;
    }

    Logger::log(LOG_TRACE, "Initializing CUDAWrapper\n");

    globalJvm = jvm;

    jclass cls = NULL;

    // Initialize the JNIUtils and PointerUtils
    if (initJNIUtils(env) == JNI_ERR) return JNI_ERR;
    if (initPointerUtils(env) == JNI_ERR) return JNI_ERR;

    // Obtain the fieldIDs of the CUdevprop class
    if (!init(env, cls, "CUDAWrapper/driver/CUdevprop")) return JNI_ERR;
    if (!init(env, cls, CUdevprop_maxThreadsPerBlock,  "maxThreadsPerBlock",  "I" )) return JNI_ERR; // int
    if (!init(env, cls, CUdevprop_maxThreadsDim,       "maxThreadsDim",       "[I")) return JNI_ERR; // int
    if (!init(env, cls, CUdevprop_maxGridSize,         "maxGridSize",         "[I")) return JNI_ERR; // int
    if (!init(env, cls, CUdevprop_sharedMemPerBlock,   "sharedMemPerBlock",   "I" )) return JNI_ERR; // int
    if (!init(env, cls, CUdevprop_totalConstantMemory, "totalConstantMemory", "I" )) return JNI_ERR; // int
    if (!init(env, cls, CUdevprop_SIMDWidth,           "SIMDWidth",           "I" )) return JNI_ERR; // int
    if (!init(env, cls, CUdevprop_regsPerBlock,        "regsPerBlock",        "I" )) return JNI_ERR; // int
    if (!init(env, cls, CUdevprop_memPitch,            "memPitch",            "I" )) return JNI_ERR; // int
    if (!init(env, cls, CUdevprop_clockRate,           "clockRate",           "I" )) return JNI_ERR; // int
    if (!init(env, cls, CUdevprop_textureAlign,        "textureAlign",        "I" )) return JNI_ERR; // int


    // Obtain the fieldIDs of the CUDA_ARRAY_DESCRIPTOR class
    if (!init(env, cls, "CUDAWrapper/driver/CUDA_ARRAY_DESCRIPTOR")) return JNI_ERR;
    if (!init(env, cls, CUDA_ARRAY_DESCRIPTOR_Width,       "Width",       "J")) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_ARRAY_DESCRIPTOR_Height,      "Height",      "J")) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_ARRAY_DESCRIPTOR_Format,      "Format",      "I")) return JNI_ERR; // CUarray_format
    if (!init(env, cls, CUDA_ARRAY_DESCRIPTOR_NumChannels, "NumChannels", "I")) return JNI_ERR; // size_t



    // Obtain the fieldIDs of the CUDA_ARRAY3D_DESCRIPTOR class
    if (!init(env, cls, "CUDAWrapper/driver/CUDA_ARRAY3D_DESCRIPTOR")) return JNI_ERR;
    if (!init(env, cls, CUDA_ARRAY3D_DESCRIPTOR_Width,       "Width",       "J")) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_ARRAY3D_DESCRIPTOR_Height,      "Height",      "J")) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_ARRAY3D_DESCRIPTOR_Depth,       "Depth",       "J")) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_ARRAY3D_DESCRIPTOR_Format,      "Format",      "I")) return JNI_ERR; // CUarray_format
    if (!init(env, cls, CUDA_ARRAY3D_DESCRIPTOR_NumChannels, "NumChannels", "I")) return JNI_ERR; // unsigned int
    if (!init(env, cls, CUDA_ARRAY3D_DESCRIPTOR_Flags,       "Flags",       "I")) return JNI_ERR; // unsigned int


    // Obtain the fieldIDs of the CUDA_MEMCPY2D class
    if (!init(env, cls, "CUDAWrapper/driver/CUDA_MEMCPY2D")) return JNI_ERR;
    if (!init(env, cls, CUDA_MEMCPY2D_srcXInBytes,   "srcXInBytes",   "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY2D_srcY,          "srcY",          "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY2D_srcMemoryType, "srcMemoryType", "I"                         )) return JNI_ERR; // int
    if (!init(env, cls, CUDA_MEMCPY2D_srcHost,       "srcHost",       "LCUDAWrapper/Pointer;"           )) return JNI_ERR; // Pointer
    if (!init(env, cls, CUDA_MEMCPY2D_srcDevice,     "srcDevice",     "LCUDAWrapper/driver/CUdeviceptr;")) return JNI_ERR; // CUdeviceptr
    if (!init(env, cls, CUDA_MEMCPY2D_srcArray,      "srcArray",      "LCUDAWrapper/driver/CUarray;"    )) return JNI_ERR; // CUarray
    if (!init(env, cls, CUDA_MEMCPY2D_srcPitch,      "srcPitch",      "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY2D_dstXInBytes,   "dstXInBytes",   "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY2D_dstY,          "dstY",          "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY2D_dstMemoryType, "dstMemoryType", "I"                         )) return JNI_ERR; // int
    if (!init(env, cls, CUDA_MEMCPY2D_dstHost,       "dstHost",       "LCUDAWrapper/Pointer;"           )) return JNI_ERR; // Pointer
    if (!init(env, cls, CUDA_MEMCPY2D_dstDevice,     "dstDevice",     "LCUDAWrapper/driver/CUdeviceptr;")) return JNI_ERR; // CUdeviceptr
    if (!init(env, cls, CUDA_MEMCPY2D_dstArray,      "dstArray",      "LCUDAWrapper/driver/CUarray;"    )) return JNI_ERR; // CUarray
    if (!init(env, cls, CUDA_MEMCPY2D_dstPitch,      "dstPitch",      "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY2D_WidthInBytes,  "WidthInBytes",  "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY2D_Height,        "Height",        "J"                         )) return JNI_ERR; // size_t

    // Obtain the fieldIDs of the CUDA_MEMCPY3D class
    if (!init(env, cls, "CUDAWrapper/driver/CUDA_MEMCPY3D")) return JNI_ERR;
    if (!init(env, cls, CUDA_MEMCPY3D_srcXInBytes,   "srcXInBytes",   "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_srcY,          "srcY",          "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_srcZ,          "srcZ",          "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_srcLOD,        "srcLOD",        "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_srcMemoryType, "srcMemoryType", "I"                         )) return JNI_ERR; // int
    if (!init(env, cls, CUDA_MEMCPY3D_srcHost,       "srcHost",       "LCUDAWrapper/Pointer;"           )) return JNI_ERR; // Pointer
    if (!init(env, cls, CUDA_MEMCPY3D_srcDevice,     "srcDevice",     "LCUDAWrapper/driver/CUdeviceptr;")) return JNI_ERR; // CUdeviceptr
    if (!init(env, cls, CUDA_MEMCPY3D_srcArray,      "srcArray",      "LCUDAWrapper/driver/CUarray;"    )) return JNI_ERR; // CUarray
    if (!init(env, cls, CUDA_MEMCPY3D_srcPitch,      "srcPitch",      "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_srcHeight,     "srcHeight",     "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_dstXInBytes,   "dstXInBytes",   "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_dstY,          "dstY",          "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_dstZ,          "dstZ",          "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_dstLOD,        "dstLOD",        "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_dstMemoryType, "dstMemoryType", "I"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_dstHost,       "dstHost",       "LCUDAWrapper/Pointer;"           )) return JNI_ERR; // Pointer
    if (!init(env, cls, CUDA_MEMCPY3D_dstDevice,     "dstDevice",     "LCUDAWrapper/driver/CUdeviceptr;")) return JNI_ERR; // CUdeviceptr
    if (!init(env, cls, CUDA_MEMCPY3D_dstArray,      "dstArray",      "LCUDAWrapper/driver/CUarray;"    )) return JNI_ERR; // CUarray
    if (!init(env, cls, CUDA_MEMCPY3D_dstPitch,      "dstPitch",      "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_dstHeight,     "dstHeight",     "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_WidthInBytes,  "WidthInBytes",  "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_Height,        "Height",        "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_Depth,         "Depth",         "J"                         )) return JNI_ERR; // size_t

    // Obtain the fieldIDs of the CUDA_MEMCPY3D_PEER class
    if (!init(env, cls, "CUDAWrapper/driver/CUDA_MEMCPY3D_PEER")) return JNI_ERR;
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_srcXInBytes,   "srcXInBytes",   "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_srcY,          "srcY",          "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_srcZ,          "srcZ",          "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_srcLOD,        "srcLOD",        "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_srcMemoryType, "srcMemoryType", "I"                         )) return JNI_ERR; // int
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_srcHost,       "srcHost",       "LCUDAWrapper/Pointer;"           )) return JNI_ERR; // Pointer
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_srcDevice,     "srcDevice",     "LCUDAWrapper/driver/CUdeviceptr;")) return JNI_ERR; // CUdeviceptr
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_srcArray,      "srcArray",      "LCUDAWrapper/driver/CUarray;"    )) return JNI_ERR; // CUarray
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_srcContext,    "srcContext",    "LCUDAWrapper/driver/CUcontext;"  )) return JNI_ERR; // CUcontext
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_srcPitch,      "srcPitch",      "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_srcHeight,     "srcHeight",     "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_dstXInBytes,   "dstXInBytes",   "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_dstY,          "dstY",          "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_dstZ,          "dstZ",          "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_dstLOD,        "dstLOD",        "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_dstMemoryType, "dstMemoryType", "I"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_dstHost,       "dstHost",       "LCUDAWrapper/Pointer;"           )) return JNI_ERR; // Pointer
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_dstDevice,     "dstDevice",     "LCUDAWrapper/driver/CUdeviceptr;")) return JNI_ERR; // CUdeviceptr
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_dstArray,      "dstArray",      "LCUDAWrapper/driver/CUarray;"    )) return JNI_ERR; // CUarray
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_dstContext,    "dstContext",    "LCUDAWrapper/driver/CUcontext;"  )) return JNI_ERR; // CUcontext
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_dstPitch,      "dstPitch",      "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_dstHeight,     "dstHeight",     "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_WidthInBytes,  "WidthInBytes",  "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_Height,        "Height",        "J"                         )) return JNI_ERR; // size_t
    if (!init(env, cls, CUDA_MEMCPY3D_PEER_Depth,         "Depth",         "J"                         )) return JNI_ERR; // size_t

    // Obtain the methodIDs for JITOptions
    if (!init(env, cls, "CUDAWrapper/driver/JITOptions")) return JNI_ERR;
    if (!init(env, cls, JITOptions_getKeys,  "getKeys",  "()[I" )) return JNI_ERR;
    if (!init(env, cls, JITOptions_getInt,   "getInt",   "(I)I" )) return JNI_ERR;
    if (!init(env, cls, JITOptions_getFloat, "getFloat", "(I)F" )) return JNI_ERR;
    if (!init(env, cls, JITOptions_getBytes, "getBytes", "(I)[B")) return JNI_ERR;
    if (!init(env, cls, JITOptions_putInt,   "putInt",   "(II)V")) return JNI_ERR;
    if (!init(env, cls, JITOptions_putFloat, "putFloat", "(IF)V")) return JNI_ERR;

    // Obtain the fieldIDs of the CUipcEventHandle class
    if (!init(env, cls, "CUDAWrapper/driver/CUipcEventHandle")) return JNI_ERR;
    if (!init(env, cls, CUipcEventHandle_reserved, "reserved", "[B")) return JNI_ERR;

    // Obtain the fieldIDs of the CUipcEventHandle class
    if (!init(env, cls, "CUDAWrapper/driver/CUipcMemHandle")) return JNI_ERR;
    if (!init(env, cls, CUipcMemHandle_reserved, "reserved", "[B")) return JNI_ERR;


    // Obtain the fieldIDs of the CUDA_RESOURCE_DESC class
    if (!init(env, cls, "CUDAWrapper/driver/CUDA_RESOURCE_DESC")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_resType,                "resType",                "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_array_hArray,           "array_hArray",           "LCUDAWrapper/driver/CUarray;")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_mipmap_hMipmappedArray, "mipmap_hMipmappedArray", "LCUDAWrapper/driver/CUmipmappedArray;")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_linear_devPtr,          "linear_devPtr",          "LCUDAWrapper/driver/CUdeviceptr;")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_linear_format,          "linear_format",          "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_linear_numChannels,     "linear_numChannels",     "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_linear_sizeInBytes,     "linear_sizeInBytes",     "J")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_pitch2D_devPtr,         "pitch2D_devPtr",         "LCUDAWrapper/driver/CUdeviceptr;")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_pitch2D_format,         "pitch2D_format",         "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_pitch2D_numChannels,    "pitch2D_numChannels",    "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_pitch2D_width,          "pitch2D_width",          "J")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_pitch2D_height,         "pitch2D_height",         "J")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_DESC_pitch2D_pitchInBytes,   "pitch2D_pitchInBytes",   "J")) return JNI_ERR;

    // Obtain the fieldIDs of the CUDA_RESOURCE_VIEW_DESC class
    if (!init(env, cls, "CUDAWrapper/driver/CUDA_RESOURCE_VIEW_DESC")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_VIEW_DESC_format,           "format",           "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_VIEW_DESC_width,            "width",            "J")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_VIEW_DESC_height,           "height",           "J")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_VIEW_DESC_depth,            "depth",            "J")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_VIEW_DESC_firstMipmapLevel, "firstMipmapLevel", "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_VIEW_DESC_lastMipmapLevel,  "lastMipmapLevel",  "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_VIEW_DESC_firstLayer,       "firstLayer",       "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_RESOURCE_VIEW_DESC_lastLayer,        "lastLayer",        "I")) return JNI_ERR;

    // Obtain the fieldIDs of the CUDA_TEXTURE_DESC class
    if (!init(env, cls, "CUDAWrapper/driver/CUDA_TEXTURE_DESC")) return JNI_ERR;
    if (!init(env, cls, CUDA_TEXTURE_DESC_addressMode,         "addressMode",         "[I")) return JNI_ERR;
    if (!init(env, cls, CUDA_TEXTURE_DESC_filterMode,          "filterMode",          "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_TEXTURE_DESC_flags,               "flags",               "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_TEXTURE_DESC_maxAnisotropy,       "maxAnisotropy",       "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_TEXTURE_DESC_mipmapFilterMode,    "mipmapFilterMode",    "I")) return JNI_ERR;
    if (!init(env, cls, CUDA_TEXTURE_DESC_mipmapLevelBias,     "mipmapLevelBias",     "F")) return JNI_ERR;
    if (!init(env, cls, CUDA_TEXTURE_DESC_minMipmapLevelClamp, "minMipmapLevelClamp", "F")) return JNI_ERR;
    if (!init(env, cls, CUDA_TEXTURE_DESC_maxMipmapLevelClamp, "maxMipmapLevelClamp", "F")) return JNI_ERR;
    if (!init(env, cls, CUDA_TEXTURE_DESC_borderColor,         "borderColor",         "[F")) return JNI_ERR;

    // Obtain the constructor of the CUdevice class
    if (!init(env, cls, "CUDAWrapper/driver/CUdevice")) return JNI_ERR;
    CUdevice_class = (jclass)env->NewGlobalRef(cls);
    if (CUdevice_class == NULL)
    {
        Logger::log(LOG_ERROR, "Failed to create reference to class CUdevice\n");
        return JNI_ERR;
    }
    if (!init(env, cls, CUdevice_constructor, "<init>", "()V")) return JNI_ERR;


    // Obtain the methodID for CUDAWrapper.driver.CUoccupancyB2DSize
    if (!init(env, cls, "CUDAWrapper/driver/CUoccupancyB2DSize")) return JNI_ERR;
    if (!init(env, cls, CUoccupancyB2DSize_call, "call", "(I)J")) return JNI_ERR;

    // Obtain the methodID for CUDAWrapper.driver.CUstreamCallback#call
    if (!init(env, cls, "CUDAWrapper/driver/CUstreamCallback")) return JNI_ERR;
    if (!init(env, cls, CUstreamCallback_call, "call", "(LCUDAWrapper/driver/CUstream;ILjava/lang/Object;)V")) return JNI_ERR;


    return JNI_VERSION_1_4;
}


JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved)
{
}


/**
 * A pointer to this function will be passed to the function
 * cuOccupancyMaxPotentialBlockSize
 */
size_t CUDA_CB CUoccupancyB2DSizeFunction(int blockSize)
{
    if (currentOccupancyCallback == NULL)
    {
        return -1;
    }
    if (currentOccupancyEnv == NULL)
    {
        return -1;
    }
    jlong memSize = currentOccupancyEnv->CallLongMethod(
        currentOccupancyCallback, CUoccupancyB2DSize_call, blockSize);
    return (size_t)memSize;
}


/**
* A pointer to this function will be passed to cuStreamAddCallback function.
* The given callbackInfoUserData will be a pointer to the CallbackInfo that was 
* created when the callback was established. The contents of this CallbackInfo
* will be extracted here, and the actual (Java) callback function will be called.
*/
void CUDA_CB cuStreamAddCallback_NativeCallback(CUstream hStream, CUresult status, void *callbackInfoUserData)
{
    Logger::log(LOG_DEBUGTRACE, "Executing cuStreamAddCallback_NativeCallback\n");

    CallbackInfo *callbackInfo = (CallbackInfo*)callbackInfoUserData;

    jobject javaStreamObject = callbackInfo->globalStream;
    jobject javaCallbackObject = callbackInfo->globalJavaCallbackObject;
    if (javaCallbackObject == NULL)
    {
        return;
    }
    jobject userData = callbackInfo->globalUserData;

    JNIEnv *env = NULL;
    jint attached = globalJvm->GetEnv((void**)&env, JNI_VERSION_1_4);
    if (attached != JNI_OK)
    {
        globalJvm->AttachCurrentThread((void**)&env, NULL);
    }

    Logger::log(LOG_DEBUGTRACE, "Calling Java callback method\n");
    env->CallVoidMethod(javaCallbackObject, CUstreamCallback_call, javaStreamObject, status, userData);
    Logger::log(LOG_DEBUGTRACE, "Calling Java callback method done\n");

    finishCallback(env);
    deleteCallbackInfo(env, callbackInfo);
    if (attached != JNI_OK)
    {
        globalJvm->DetachCurrentThread();
    }
}


/*
 * Set the log level
 *
 * Class:     CUDAWrapper_driver_CUDADriver
 * Method:    setLogLevel
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_setLogLevel
  (JNIEnv *env, jclass cla, jint logLevel)
{
    Logger::setLogLevel((LogLevel)logLevel);
}




/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCUdevprop(JNIEnv *env, jobject prop, CUdevprop nativeProp)
{
    env->SetIntField(prop, CUdevprop_maxThreadsPerBlock,  (jint)nativeProp.maxThreadsPerBlock);

    jintArray propMaxThreadsDim   = (jintArray)env->GetObjectField(prop, CUdevprop_maxThreadsDim);
    jint *nativePropMaxThreadsDim = (jint*)    env->GetPrimitiveArrayCritical(propMaxThreadsDim, NULL);
    for (int i=0; i<3; i++)
    {
        nativePropMaxThreadsDim[i] = (int)nativeProp.maxThreadsDim[i];
    }
    env->ReleasePrimitiveArrayCritical(propMaxThreadsDim, nativePropMaxThreadsDim, 0);

    jintArray propMaxGridSize     = (jintArray)env->GetObjectField(prop, CUdevprop_maxGridSize);

    jint *nativePropMaxGridSize   = (jint*)    env->GetPrimitiveArrayCritical(propMaxGridSize, NULL);
    for (int i=0; i<3; i++)
    {
        nativePropMaxGridSize[i] = (int)nativeProp.maxGridSize[i];
    }
    env->ReleasePrimitiveArrayCritical(propMaxGridSize, nativePropMaxGridSize, 0);

    env->SetIntField(prop, CUdevprop_sharedMemPerBlock,   (jint)nativeProp.sharedMemPerBlock);
    env->SetIntField(prop, CUdevprop_totalConstantMemory, (jint)nativeProp.totalConstantMemory);
    env->SetIntField(prop, CUdevprop_SIMDWidth,           (jint)nativeProp.SIMDWidth);
    env->SetIntField(prop, CUdevprop_memPitch,            (jint)nativeProp.memPitch);
    env->SetIntField(prop, CUdevprop_regsPerBlock,        (jint)nativeProp.regsPerBlock);
    env->SetIntField(prop, CUdevprop_clockRate,           (jint)nativeProp.clockRate);
    env->SetIntField(prop, CUdevprop_textureAlign,        (jint)nativeProp.textureAlign);
}




/**
 * Returns the native representation of the given Java object
 */
CUDA_ARRAY_DESCRIPTOR getCUDA_ARRAY_DESCRIPTOR(JNIEnv *env, jobject pAllocateArray)
{
    CUDA_ARRAY_DESCRIPTOR nativePAllocateArray;
    nativePAllocateArray.Width       = (size_t)        env->GetLongField(pAllocateArray, CUDA_ARRAY_DESCRIPTOR_Width);
    nativePAllocateArray.Height      = (size_t)        env->GetLongField(pAllocateArray, CUDA_ARRAY_DESCRIPTOR_Height);
    nativePAllocateArray.Format      = (CUarray_format)env->GetIntField( pAllocateArray, CUDA_ARRAY_DESCRIPTOR_Format);
    nativePAllocateArray.NumChannels = (unsigned int)  env->GetIntField( pAllocateArray, CUDA_ARRAY_DESCRIPTOR_NumChannels);
    return nativePAllocateArray;
}

/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCUDA_ARRAY_DESCRIPTOR(JNIEnv *env, jobject pArrayDescriptor, CUDA_ARRAY_DESCRIPTOR nativePArrayDescriptor)
{
    env->SetLongField(pArrayDescriptor, CUDA_ARRAY_DESCRIPTOR_Width,       (jlong)nativePArrayDescriptor.Width);
    env->SetLongField(pArrayDescriptor, CUDA_ARRAY_DESCRIPTOR_Height,      (jlong)nativePArrayDescriptor.Height);
    env->SetIntField( pArrayDescriptor, CUDA_ARRAY_DESCRIPTOR_Format,      (jint) nativePArrayDescriptor.Format);
    env->SetIntField( pArrayDescriptor, CUDA_ARRAY_DESCRIPTOR_NumChannels, (jint) nativePArrayDescriptor.NumChannels);
}



/**
 * Returns the native representation of the given Java object
 */
CUDA_ARRAY3D_DESCRIPTOR getCUDA_ARRAY3D_DESCRIPTOR(JNIEnv *env, jobject pAllocateArray)
{
    CUDA_ARRAY3D_DESCRIPTOR nativePAllocateArray;
    nativePAllocateArray.Width       = (size_t)        env->GetLongField(pAllocateArray, CUDA_ARRAY3D_DESCRIPTOR_Width);
    nativePAllocateArray.Height      = (size_t)        env->GetLongField(pAllocateArray, CUDA_ARRAY3D_DESCRIPTOR_Height);
    nativePAllocateArray.Depth       = (size_t)        env->GetLongField(pAllocateArray, CUDA_ARRAY3D_DESCRIPTOR_Depth);
    nativePAllocateArray.Format      = (CUarray_format)env->GetIntField( pAllocateArray, CUDA_ARRAY3D_DESCRIPTOR_Format);
    nativePAllocateArray.NumChannels = (unsigned int)  env->GetIntField( pAllocateArray, CUDA_ARRAY3D_DESCRIPTOR_NumChannels);
    nativePAllocateArray.Flags       = (unsigned int)  env->GetIntField( pAllocateArray, CUDA_ARRAY3D_DESCRIPTOR_Flags);
    return nativePAllocateArray;
}


/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCUDA_ARRAY3D_DESCRIPTOR(JNIEnv *env, jobject pArrayDescriptor, CUDA_ARRAY3D_DESCRIPTOR nativePArrayDescriptor)
{
    env->SetLongField(pArrayDescriptor, CUDA_ARRAY3D_DESCRIPTOR_Width,       (jlong)nativePArrayDescriptor.Width);
    env->SetLongField(pArrayDescriptor, CUDA_ARRAY3D_DESCRIPTOR_Height,      (jlong)nativePArrayDescriptor.Height);
    env->SetLongField(pArrayDescriptor, CUDA_ARRAY3D_DESCRIPTOR_Depth,       (jlong)nativePArrayDescriptor.Depth);
    env->SetIntField( pArrayDescriptor, CUDA_ARRAY3D_DESCRIPTOR_Format,      (jint) nativePArrayDescriptor.Format);
    env->SetIntField( pArrayDescriptor, CUDA_ARRAY3D_DESCRIPTOR_NumChannels, (jint) nativePArrayDescriptor.NumChannels);
    env->SetIntField( pArrayDescriptor, CUDA_ARRAY3D_DESCRIPTOR_Flags,       (jint) nativePArrayDescriptor.Flags);
}











/**
 * Creates a Memcpy2DData from the given CUDA_MEMCPY2D object.
 * Returns NULL if an error occurred.
 */
Memcpy2DData* initMemcpy2DData(JNIEnv *env, jobject pCopy)
{
    Memcpy2DData *memcpyData = new Memcpy2DData();
    if (memcpyData == NULL)
    {
        ThrowByName(env, "java/lang/OutOfMemoryError",
            "Out of memory during Memcpy2DData creation");
        return NULL;
    }

    CUDA_MEMCPY2D &mc = memcpyData->memcpy2d;

    mc.srcXInBytes   = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY2D_srcXInBytes);
    mc.srcY          = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY2D_srcY);
    mc.srcMemoryType = (CUmemorytype)env->GetIntField(pCopy, CUDA_MEMCPY2D_srcMemoryType);

    memcpyData->srcHost = env->GetObjectField(pCopy, CUDA_MEMCPY2D_srcHost);
    memcpyData->srcHostPointerData = initPointerData(env, memcpyData->srcHost);
    if (memcpyData->srcHostPointerData == NULL)
    {
        delete memcpyData;
        return NULL;
    }
    mc.srcHost = (void*)memcpyData->srcHostPointerData->getPointer(env);

    jobject srcDevice = env->GetObjectField(pCopy, CUDA_MEMCPY2D_srcDevice);
    mc.srcDevice = (CUdeviceptr)getPointer(env, srcDevice);

    jobject srcArray = env->GetObjectField(pCopy, CUDA_MEMCPY2D_srcArray);
    mc.srcArray = (CUarray)getNativePointerValue(env, srcArray);

    mc.srcPitch      = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY2D_srcPitch);
    mc.dstXInBytes   = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY2D_dstXInBytes);
    mc.dstY          = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY2D_dstY);
    mc.dstMemoryType = (CUmemorytype)env->GetIntField(pCopy, CUDA_MEMCPY2D_dstMemoryType);

    memcpyData->dstHost = env->GetObjectField(pCopy, CUDA_MEMCPY2D_dstHost);
    memcpyData->dstHostPointerData = initPointerData(env, memcpyData->dstHost);
    if (memcpyData->dstHostPointerData == NULL)
    {
        delete memcpyData;
        return NULL;
    }
    mc.dstHost = (void*)memcpyData->dstHostPointerData->getPointer(env);

    jobject dstDevice = env->GetObjectField(pCopy, CUDA_MEMCPY2D_dstDevice);
    mc.dstDevice = (CUdeviceptr)getPointer(env, dstDevice);

    jobject dstArray = env->GetObjectField(pCopy, CUDA_MEMCPY2D_dstArray);
    mc.dstArray = (CUarray)getNativePointerValue(env, dstArray);

    mc.dstPitch      = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY2D_dstPitch);
    mc.WidthInBytes  = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY2D_WidthInBytes);
    mc.Height        = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY2D_Height);

    return memcpyData;
}

/**
 * Release all pointers in the given memcpyData, delete it and
 * set it to NULL. Returns whether this operation succeeded.
 */
bool releaseMemcpy2DData(JNIEnv *env, Memcpy2DData* &memcpyData)
{
    if (!releasePointerData(env, memcpyData->srcHostPointerData, JNI_ABORT)) return false;
    if (!releasePointerData(env, memcpyData->dstHostPointerData)) return false;
    delete memcpyData;
    memcpyData = NULL;
    return true;
}





/**
 * Initializes the given memcpyData with the data from the given
 * CUDA_MEMCPY3D object
 */
Memcpy3DData* initMemcpy3DData(JNIEnv *env, jobject pCopy)
{
    Memcpy3DData *memcpyData = new Memcpy3DData();
    CUDA_MEMCPY3D &mc = memcpyData->memcpy3d;

    mc.srcXInBytes   = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_srcXInBytes);
    mc.srcY          = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_srcY);
    mc.srcZ          = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_srcZ);
    mc.srcLOD        = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_srcLOD);
    mc.srcMemoryType = (CUmemorytype)env->GetIntField(pCopy, CUDA_MEMCPY3D_srcMemoryType);

    memcpyData->srcHost = env->GetObjectField(pCopy, CUDA_MEMCPY3D_srcHost);
    memcpyData->srcHostPointerData = initPointerData(env, memcpyData->srcHost);
    if (memcpyData->srcHostPointerData == NULL)
    {
        delete memcpyData;
        return NULL;
    }
    mc.srcHost = (void*)memcpyData->srcHostPointerData->getPointer(env);

    jobject srcDevice = env->GetObjectField(pCopy, CUDA_MEMCPY3D_srcDevice);
    mc.srcDevice = (CUdeviceptr)getPointer(env, srcDevice);

    jobject srcArray = env->GetObjectField(pCopy, CUDA_MEMCPY3D_srcArray);
    mc.srcArray = (CUarray)getNativePointerValue(env, srcArray);

    mc.srcPitch      = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_srcPitch);
    mc.srcHeight     = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_srcHeight);
    mc.dstXInBytes   = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_dstXInBytes);
    mc.dstY          = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_dstY);
    mc.dstZ          = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_dstZ);
    mc.dstLOD        = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_dstLOD);
    mc.dstMemoryType = (CUmemorytype)env->GetIntField(pCopy, CUDA_MEMCPY3D_dstMemoryType);

    memcpyData->dstHost = env->GetObjectField(pCopy, CUDA_MEMCPY3D_dstHost);
    memcpyData->dstHostPointerData = initPointerData(env, memcpyData->dstHost);
    if (memcpyData->dstHostPointerData == NULL)
    {
        delete memcpyData;
        return NULL;
    }
    mc.dstHost = (void*)memcpyData->dstHostPointerData->getPointer(env);

    jobject dstDevice = env->GetObjectField(pCopy, CUDA_MEMCPY3D_dstDevice);
    mc.dstDevice = (CUdeviceptr)getPointer(env, dstDevice);

    jobject dstArray = env->GetObjectField(pCopy, CUDA_MEMCPY3D_dstArray);
    mc.dstArray = (CUarray)getNativePointerValue(env, dstArray);

    mc.dstPitch      = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_dstPitch);
    mc.dstHeight     = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_dstHeight);
    mc.WidthInBytes  = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_WidthInBytes);
    mc.Height        = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_Height);
    mc.Depth         = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_Depth);

    return memcpyData;
}


/**
 * Release all pointers in the given memcpyData, delete it and
 * set it to NULL. Returns whether this operation succeeded.
 */
bool releaseMemcpy3DData(JNIEnv *env, Memcpy3DData* &memcpyData)
{
    if (!releasePointerData(env, memcpyData->srcHostPointerData, JNI_ABORT)) return false;
    if (!releasePointerData(env, memcpyData->dstHostPointerData)) return false;
    delete memcpyData;
    memcpyData = NULL;
    return true;
}







/**
 * Initializes the given memcpyData with the data from the given
 * CUDA_MEMCPY3D_PEER object
 */
Memcpy3DPeerData* initMemcpy3DPeerData(JNIEnv *env, jobject pCopy)
{
    Memcpy3DPeerData *memcpyData = new Memcpy3DPeerData();
    CUDA_MEMCPY3D_PEER &mc = memcpyData->memcpy3d;

    mc.srcXInBytes   = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_srcXInBytes);
    mc.srcY          = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_srcY);
    mc.srcZ          = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_srcZ);
    mc.srcLOD        = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_srcLOD);
    mc.srcMemoryType = (CUmemorytype)env->GetIntField(pCopy, CUDA_MEMCPY3D_PEER_srcMemoryType);

    memcpyData->srcHost = env->GetObjectField(pCopy, CUDA_MEMCPY3D_PEER_srcHost);
    memcpyData->srcHostPointerData = initPointerData(env, memcpyData->srcHost);
    if (memcpyData->srcHostPointerData == NULL)
    {
        delete memcpyData;
        return NULL;
    }
    mc.srcHost = (void*)memcpyData->srcHostPointerData->getPointer(env);

    jobject srcDevice = env->GetObjectField(pCopy, CUDA_MEMCPY3D_PEER_srcDevice);
    mc.srcDevice = (CUdeviceptr)getPointer(env, srcDevice);

    jobject srcArray = env->GetObjectField(pCopy, CUDA_MEMCPY3D_PEER_srcArray);
    mc.srcArray = (CUarray)getNativePointerValue(env, srcArray);

    jobject srcContext = env->GetObjectField(pCopy, CUDA_MEMCPY3D_PEER_srcContext);
    mc.srcContext = (CUcontext)getNativePointerValue(env, srcContext);

    mc.srcPitch      = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_srcPitch);
    mc.srcHeight     = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_srcHeight);
    mc.dstXInBytes   = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_dstXInBytes);
    mc.dstY          = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_dstY);
    mc.dstZ          = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_dstZ);
    mc.dstLOD        = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_dstLOD);
    mc.dstMemoryType = (CUmemorytype)env->GetIntField(pCopy, CUDA_MEMCPY3D_PEER_dstMemoryType);

    memcpyData->dstHost = env->GetObjectField(pCopy, CUDA_MEMCPY3D_PEER_dstHost);
    memcpyData->dstHostPointerData = initPointerData(env, memcpyData->dstHost);
    if (memcpyData->dstHostPointerData == NULL)
    {
        delete memcpyData;
        return NULL;
    }
    mc.dstHost = (void*)memcpyData->dstHostPointerData->getPointer(env);

    jobject dstDevice = env->GetObjectField(pCopy, CUDA_MEMCPY3D_PEER_dstDevice);
    mc.dstDevice = (CUdeviceptr)getPointer(env, dstDevice);

    jobject dstArray = env->GetObjectField(pCopy, CUDA_MEMCPY3D_PEER_dstArray);
    mc.dstArray = (CUarray)getNativePointerValue(env, dstArray);

    jobject dstContext = env->GetObjectField(pCopy, CUDA_MEMCPY3D_PEER_dstContext);
    mc.dstContext = (CUcontext)getNativePointerValue(env, dstContext);

    mc.dstPitch      = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_dstPitch);
    mc.dstHeight     = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_dstHeight);
    mc.WidthInBytes  = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_WidthInBytes);
    mc.Height        = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_Height);
    mc.Depth         = (size_t)env->GetLongField(pCopy, CUDA_MEMCPY3D_PEER_Depth);

    return memcpyData;
}


/**
 * Release all pointers in the given memcpyData, delete it and
 * set it to NULL. Returns whether this operation succeeded.
 */
bool releaseMemcpy3DPeerData(JNIEnv *env, Memcpy3DPeerData* &memcpyData)
{
    if (!releasePointerData(env, memcpyData->srcHostPointerData, JNI_ABORT)) return false;
    if (!releasePointerData(env, memcpyData->dstHostPointerData)) return false;
    delete memcpyData;
    memcpyData = NULL;
    return true;
}




/**
 * Returns the native representation of the given Java object
 */
CUipcEventHandle getCUipcEventHandle(JNIEnv *env, jobject handle)
{
    CUipcEventHandle nativeHandle;

    jobject reservedObject = env->GetObjectField(handle, CUipcEventHandle_reserved);
    jbyteArray reserved = (jbyteArray)reservedObject;
    int len = env->GetArrayLength(reserved); // Should always be CU_IPC_HANDLE_SIZE
    char *reservedData = (char*)env->GetPrimitiveArrayCritical(reserved, NULL);
    for (int i=0; i<len; i++)
    {
        nativeHandle.reserved[i] = reservedData[i];
    }
    env->ReleasePrimitiveArrayCritical(reserved, reservedData, 0);
    return nativeHandle;
}


/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCUipcEventHandle(JNIEnv *env, jobject handle, CUipcEventHandle &nativeHandle)
{
    jobject reservedObject = env->GetObjectField(handle, CUipcEventHandle_reserved);
    jbyteArray reserved = (jbyteArray)reservedObject;
    int len = env->GetArrayLength(reserved); // Should always be CU_IPC_HANDLE_SIZE
    char *reservedData = (char*)env->GetPrimitiveArrayCritical(reserved, NULL);
    for (int i=0; i<len; i++)
    {
        reservedData[i] = nativeHandle.reserved[i];
    }
    env->ReleasePrimitiveArrayCritical(reserved, reservedData, 0);
}


/**
 * Returns the native representation of the given Java object
 */
CUipcMemHandle getCUipcMemHandle(JNIEnv *env, jobject handle)
{
    CUipcMemHandle nativeHandle;

    jobject reservedObject = env->GetObjectField(handle, CUipcMemHandle_reserved);
    jbyteArray reserved = (jbyteArray)reservedObject;
    int len = env->GetArrayLength(reserved); // Should always be CU_IPC_HANDLE_SIZE
    char *reservedData = (char*)env->GetPrimitiveArrayCritical(reserved, NULL);
    for (int i=0; i<len; i++)
    {
        nativeHandle.reserved[i] = reservedData[i];
    }
    env->ReleasePrimitiveArrayCritical(reserved, reservedData, 0);
    return nativeHandle;
}


/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCUipcMemHandle(JNIEnv *env, jobject handle, CUipcMemHandle &nativeHandle)
{
    jobject reservedObject = env->GetObjectField(handle, CUipcMemHandle_reserved);
    jbyteArray reserved = (jbyteArray)reservedObject;
    int len = env->GetArrayLength(reserved); // Should always be CU_IPC_HANDLE_SIZE
    char *reservedData = (char*)env->GetPrimitiveArrayCritical(reserved, NULL);
    for (int i=0; i<len; i++)
    {
        reservedData[i] = nativeHandle.reserved[i];
    }
    env->ReleasePrimitiveArrayCritical(reserved, reservedData, 0);
}




/**
 * Returns the native representation of the given Java object
 */
CUDA_RESOURCE_DESC getCUDA_RESOURCE_DESC(JNIEnv *env, jobject resourceDesc)
{
    CUDA_RESOURCE_DESC nativeResourceDesc;
    memset(&nativeResourceDesc,0,sizeof(CUDA_RESOURCE_DESC));

    nativeResourceDesc.resType = (CUresourcetype) env->GetIntField(resourceDesc, CUDA_RESOURCE_DESC_resType);

    jobject array_hArray = NULL;
    jobject mipmap_hMipmappedArray = NULL;
    jobject linear_devPtr = NULL;
    jobject pitch2D_devPtr = NULL;
    switch (nativeResourceDesc.resType)
    {
        case CU_RESOURCE_TYPE_ARRAY:
            array_hArray = env->GetObjectField(resourceDesc, CUDA_RESOURCE_DESC_array_hArray);
            nativeResourceDesc.res.array.hArray = (CUarray)getNativePointerValue(env, array_hArray);
            break;

        case CU_RESOURCE_TYPE_MIPMAPPED_ARRAY:
            mipmap_hMipmappedArray = env->GetObjectField(resourceDesc, CUDA_RESOURCE_DESC_mipmap_hMipmappedArray);
            nativeResourceDesc.res.mipmap.hMipmappedArray = (CUmipmappedArray)getNativePointerValue(env, mipmap_hMipmappedArray);
            break;

        case CU_RESOURCE_TYPE_LINEAR:
            linear_devPtr = env->GetObjectField(resourceDesc, CUDA_RESOURCE_DESC_linear_devPtr);
            nativeResourceDesc.res.linear.devPtr = (CUdeviceptr)getNativePointerValue(env, linear_devPtr);
            nativeResourceDesc.res.linear.format = (CUarray_format)env->GetIntField(resourceDesc, CUDA_RESOURCE_DESC_linear_format);
            nativeResourceDesc.res.linear.numChannels = (unsigned int)env->GetIntField(resourceDesc, CUDA_RESOURCE_DESC_linear_numChannels);
            nativeResourceDesc.res.linear.sizeInBytes = (size_t)env->GetLongField(resourceDesc, CUDA_RESOURCE_DESC_linear_sizeInBytes);
            break;

        case CU_RESOURCE_TYPE_PITCH2D:
            pitch2D_devPtr = env->GetObjectField(resourceDesc, CUDA_RESOURCE_DESC_pitch2D_devPtr);
            nativeResourceDesc.res.pitch2D.devPtr = (CUdeviceptr)getNativePointerValue(env, pitch2D_devPtr);
            nativeResourceDesc.res.pitch2D.format = (CUarray_format)env->GetIntField(resourceDesc, CUDA_RESOURCE_DESC_pitch2D_format);
            nativeResourceDesc.res.pitch2D.numChannels = (unsigned int)env->GetIntField(resourceDesc, CUDA_RESOURCE_DESC_pitch2D_numChannels);
            nativeResourceDesc.res.pitch2D.width = (size_t)env->GetLongField(resourceDesc, CUDA_RESOURCE_DESC_pitch2D_width);
            nativeResourceDesc.res.pitch2D.height = (size_t)env->GetLongField(resourceDesc, CUDA_RESOURCE_DESC_pitch2D_height);
            nativeResourceDesc.res.pitch2D.pitchInBytes = (size_t)env->GetLongField(resourceDesc, CUDA_RESOURCE_DESC_pitch2D_pitchInBytes);
            break;
    }

    return nativeResourceDesc;
}


/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCUDA_RESOURCE_DESC(JNIEnv *env, jobject resourceDesc, CUDA_RESOURCE_DESC &nativeResourceDesc)
{
    env->SetIntField(resourceDesc, CUDA_RESOURCE_DESC_resType, (jint)nativeResourceDesc.resType);

    jobject array_hArray = NULL;
    jobject mipmap_hMipmappedArray = NULL;
    jobject linear_devPtr = NULL;
    jobject pitch2D_devPtr = NULL;
    switch (nativeResourceDesc.resType)
    {
        case CU_RESOURCE_TYPE_ARRAY:
            array_hArray = env->GetObjectField(resourceDesc, CUDA_RESOURCE_DESC_array_hArray);
            setNativePointerValue(env, array_hArray, (jlong)nativeResourceDesc.res.array.hArray);
            break;

        case CU_RESOURCE_TYPE_MIPMAPPED_ARRAY:
            mipmap_hMipmappedArray = env->GetObjectField(resourceDesc, CUDA_RESOURCE_DESC_mipmap_hMipmappedArray);
            setNativePointerValue(env, mipmap_hMipmappedArray, (jlong)nativeResourceDesc.res.mipmap.hMipmappedArray);
            break;

        case CU_RESOURCE_TYPE_LINEAR:
            linear_devPtr = env->GetObjectField(resourceDesc, CUDA_RESOURCE_DESC_linear_devPtr);
            setNativePointerValue(env, linear_devPtr, (jlong)nativeResourceDesc.res.linear.devPtr);
            env->SetIntField(resourceDesc, CUDA_RESOURCE_DESC_linear_format, (jint)nativeResourceDesc.res.linear.format);
            env->SetIntField(resourceDesc, CUDA_RESOURCE_DESC_linear_numChannels, (jint)nativeResourceDesc.res.linear.numChannels);
            env->SetLongField(resourceDesc, CUDA_RESOURCE_DESC_linear_sizeInBytes, (jlong)nativeResourceDesc.res.linear.sizeInBytes);
            break;

        case CU_RESOURCE_TYPE_PITCH2D:
            pitch2D_devPtr = env->GetObjectField(resourceDesc, CUDA_RESOURCE_DESC_pitch2D_devPtr);
            setNativePointerValue(env, pitch2D_devPtr, (jlong)nativeResourceDesc.res.pitch2D.devPtr);
            env->SetIntField(resourceDesc, CUDA_RESOURCE_DESC_pitch2D_format, (jint)nativeResourceDesc.res.pitch2D.format);
            env->SetIntField(resourceDesc, CUDA_RESOURCE_DESC_pitch2D_numChannels, (jint)nativeResourceDesc.res.pitch2D.numChannels);
            env->SetLongField(resourceDesc, CUDA_RESOURCE_DESC_pitch2D_width, (jlong)nativeResourceDesc.res.pitch2D.width);
            env->SetLongField(resourceDesc, CUDA_RESOURCE_DESC_pitch2D_height, (jlong)nativeResourceDesc.res.pitch2D.height);
            env->SetLongField(resourceDesc, CUDA_RESOURCE_DESC_pitch2D_pitchInBytes, (jlong)nativeResourceDesc.res.pitch2D.pitchInBytes);
            break;
    }

}






/**
 * Returns the native representation of the given Java object
 */
CUDA_RESOURCE_VIEW_DESC getCUDA_RESOURCE_VIEW_DESC(JNIEnv *env, jobject resourceViewDesc)
{
    CUDA_RESOURCE_VIEW_DESC nativeResourceViewDesc;
    memset(&nativeResourceViewDesc,0,sizeof(CUDA_RESOURCE_VIEW_DESC));

    nativeResourceViewDesc.format = (CUresourceViewFormat) env->GetIntField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_format);
    nativeResourceViewDesc.width = (size_t)env->GetLongField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_width);
    nativeResourceViewDesc.height = (size_t)env->GetLongField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_height);
    nativeResourceViewDesc.depth = (size_t)env->GetLongField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_depth);
    nativeResourceViewDesc.firstMipmapLevel = (unsigned int)env->GetIntField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_firstMipmapLevel);
    nativeResourceViewDesc.lastMipmapLevel = (unsigned int)env->GetIntField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_lastMipmapLevel);
    nativeResourceViewDesc.firstLayer = (unsigned int)env->GetIntField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_firstLayer);
    nativeResourceViewDesc.lastLayer = (unsigned int)env->GetIntField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_lastLayer);

    return nativeResourceViewDesc;
}




/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCUDA_RESOURCE_VIEW_DESC(JNIEnv *env, jobject resourceViewDesc, CUDA_RESOURCE_VIEW_DESC &nativeResourceViewDesc)
{
    env->SetIntField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_format, (jint)nativeResourceViewDesc.format);
    env->SetLongField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_width, (jlong)nativeResourceViewDesc.width);
    env->SetLongField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_height, (jlong)nativeResourceViewDesc.height);
    env->SetLongField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_depth, (jlong)nativeResourceViewDesc.depth);
    env->SetIntField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_firstMipmapLevel, (jint)nativeResourceViewDesc.firstMipmapLevel);
    env->SetIntField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_lastMipmapLevel, (jint)nativeResourceViewDesc.lastMipmapLevel);
    env->SetIntField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_firstLayer, (jint)nativeResourceViewDesc.firstLayer);
    env->SetIntField(resourceViewDesc, CUDA_RESOURCE_VIEW_DESC_lastLayer, (jint)nativeResourceViewDesc.lastLayer);
}



/**
 * Returns the native representation of the given Java object
 */
CUDA_TEXTURE_DESC getCUDA_TEXTURE_DESC(JNIEnv *env, jobject texDesc)
{
    CUDA_TEXTURE_DESC nativeTexDesc;
    memset(&nativeTexDesc,0,sizeof(CUDA_TEXTURE_DESC));

    jintArray addressMode = (jintArray)env->GetObjectField(texDesc, CUDA_TEXTURE_DESC_addressMode);
    jint *nativeAddressMode = (jint*)env->GetPrimitiveArrayCritical(addressMode, NULL);
    for (int i=0; i<3; i++)
    {
        nativeTexDesc.addressMode[i] = (CUaddress_mode)nativeAddressMode[i];
    }
    env->ReleasePrimitiveArrayCritical(addressMode, nativeAddressMode, JNI_ABORT);

    nativeTexDesc.filterMode = (CUfilter_mode) env->GetIntField(texDesc, CUDA_TEXTURE_DESC_filterMode);
    nativeTexDesc.flags = (unsigned int) env->GetIntField(texDesc, CUDA_TEXTURE_DESC_flags);
    nativeTexDesc.maxAnisotropy = (unsigned int) env->GetIntField(texDesc, CUDA_TEXTURE_DESC_maxAnisotropy);
    nativeTexDesc.mipmapFilterMode = (CUfilter_mode) env->GetIntField(texDesc, CUDA_TEXTURE_DESC_mipmapFilterMode);
    nativeTexDesc.mipmapLevelBias = (float)env->GetFloatField(texDesc, CUDA_TEXTURE_DESC_mipmapLevelBias);
    nativeTexDesc.minMipmapLevelClamp = (float)env->GetFloatField(texDesc, CUDA_TEXTURE_DESC_minMipmapLevelClamp);
    nativeTexDesc.maxMipmapLevelClamp = (float)env->GetFloatField(texDesc, CUDA_TEXTURE_DESC_maxMipmapLevelClamp);

    jfloatArray borderColor = (jfloatArray)env->GetObjectField(texDesc, CUDA_TEXTURE_DESC_borderColor);
    jfloat *nativeBorderColor = (jfloat*)env->GetPrimitiveArrayCritical(borderColor, NULL);
    for (int i = 0; i<4; i++)
    {
        nativeTexDesc.borderColor[i] = (float)nativeBorderColor[i];
    }
    env->ReleasePrimitiveArrayCritical(borderColor, nativeBorderColor, JNI_ABORT);

    return nativeTexDesc;
}


/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCUDA_TEXTURE_DESC(JNIEnv *env, jobject texDesc, CUDA_TEXTURE_DESC &nativeTexDesc)
{
    jintArray addressMode = (jintArray)env->GetObjectField(texDesc, CUDA_TEXTURE_DESC_addressMode);
    jint *nativeAddressMode = (jint*)env->GetPrimitiveArrayCritical(addressMode, NULL);
    for (int i = 0; i<3; i++)
    {
        nativeAddressMode[i] = (jint)nativeTexDesc.addressMode[i];
    }
    env->ReleasePrimitiveArrayCritical(addressMode, nativeAddressMode, 0);

    env->SetIntField(texDesc, CUDA_TEXTURE_DESC_filterMode, (jint)nativeTexDesc.filterMode);
    env->SetIntField(texDesc, CUDA_TEXTURE_DESC_flags, (jint)nativeTexDesc.flags);
    env->SetIntField(texDesc, CUDA_TEXTURE_DESC_maxAnisotropy, (jint)nativeTexDesc.maxAnisotropy);
    env->SetIntField(texDesc, CUDA_TEXTURE_DESC_mipmapFilterMode, (jint)nativeTexDesc.mipmapFilterMode);
    env->SetFloatField(texDesc, CUDA_TEXTURE_DESC_mipmapLevelBias, (jfloat)nativeTexDesc.mipmapLevelBias);
    env->SetFloatField(texDesc, CUDA_TEXTURE_DESC_minMipmapLevelClamp, (jfloat)nativeTexDesc.minMipmapLevelClamp);
    env->SetFloatField(texDesc, CUDA_TEXTURE_DESC_maxMipmapLevelClamp, (jfloat)nativeTexDesc.maxMipmapLevelClamp);

    jfloatArray borderColor = (jfloatArray)env->GetObjectField(texDesc, CUDA_TEXTURE_DESC_borderColor);
    jfloat *nativeBorderColor = (jfloat*)env->GetPrimitiveArrayCritical(borderColor, NULL);
    for (int i = 0; i<4; i++)
    {
        nativeBorderColor[i] = (jfloat)nativeTexDesc.borderColor[i];
    }
    env->ReleasePrimitiveArrayCritical(borderColor, nativeBorderColor, 0);

}




/**
 * Stores in 'value' the specified option from the given JITOptions object
 * and returns whether this operation succeeded.
 */
bool getOptionValue(JNIEnv *env, jobject jitOptions, CUjit_option option, void* &value)
{
    switch (option)
    {
        case CU_JIT_MAX_REGISTERS:
        case CU_JIT_THREADS_PER_BLOCK:
        case CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES:
        case CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES:
        case CU_JIT_OPTIMIZATION_LEVEL:
        case CU_JIT_TARGET:
        case CU_JIT_FALLBACK_STRATEGY:
        case CU_JIT_GENERATE_DEBUG_INFO:
        case CU_JIT_LOG_VERBOSE:
        case CU_JIT_GENERATE_LINE_INFO:
        case CU_JIT_CACHE_MODE:
        {
            jint v = env->CallIntMethod(jitOptions, JITOptions_getInt, option);
            if (env->ExceptionCheck())
            {
                return false;
            }
            value = (void*)v;
            return true;
        }

        case CU_JIT_WALL_TIME:
        {
            jfloat v = env->CallFloatMethod(jitOptions, JITOptions_getFloat, option);
            if (env->ExceptionCheck())
            {
                return false;
            }
            int iv = *(int*)&v;
            value = (void*)iv;
            return true;
        }

        case CU_JIT_INFO_LOG_BUFFER:
        case CU_JIT_ERROR_LOG_BUFFER:
        {
            jbyteArray byteArray = (jbyteArray)env->CallObjectMethod(jitOptions, JITOptions_getBytes, option);
            if (env->ExceptionCheck())
            {
                return false;
            }
            char *v = getArrayContents(env, byteArray);
            value = (void*)v;
            return true;
        }

        case CU_JIT_TARGET_FROM_CUCONTEXT:
            return true;
    }
    return false;
}



/**
 * Stores the given 'value' in the given JITOptions object
 * and returns whether this operation succeeded.
 */
bool setOptionValue(JNIEnv *env, jobject jitOptions, CUjit_option option, void* value)
{
    switch (option)
    {
        case CU_JIT_MAX_REGISTERS:
        case CU_JIT_THREADS_PER_BLOCK:
        case CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES:
        case CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES:
        case CU_JIT_OPTIMIZATION_LEVEL:
        case CU_JIT_TARGET:
        case CU_JIT_FALLBACK_STRATEGY:
        case CU_JIT_GENERATE_DEBUG_INFO:
        case CU_JIT_LOG_VERBOSE:
        case CU_JIT_GENERATE_LINE_INFO:
        case CU_JIT_CACHE_MODE:
        {
            env->CallVoidMethod(jitOptions, JITOptions_putInt, option, (jint)(intptr_t)value);
            if (env->ExceptionCheck())
            {
                return false;
            }
            return true;
        }

        case CU_JIT_WALL_TIME:
        {
            env->CallVoidMethod(jitOptions, JITOptions_putFloat, option, (jfloat)(intptr_t)value);
            if (env->ExceptionCheck())
            {
                return false;
            }
            return true;
        }

        case CU_JIT_INFO_LOG_BUFFER:
        case CU_JIT_ERROR_LOG_BUFFER:
        {
            jbyteArray byteArray = (jbyteArray)env->CallObjectMethod(jitOptions, JITOptions_getBytes, option);
            if (env->ExceptionCheck())
            {
                return false;
            }
            jsize length = env->GetArrayLength(byteArray);
            jbyte *a = (jbyte*)env->GetPrimitiveArrayCritical(byteArray, NULL);
            if (a == NULL)
            {
                return NULL;
            }
            char *v = (char*)value;
            for (int i=0; i<length; i++)
            {
                a[i] = (jbyte)v[i];
            }
            env->ReleasePrimitiveArrayCritical(byteArray, a, 0);
            delete[] v;
            return true;
        }

        case CU_JIT_TARGET_FROM_CUCONTEXT:
            return true;
    }
    return false;
}


/**
 * Creates a JITOptionsData from the given JITOptions object.
 * Returns NULL if an error occurred.
 */
JITOptionsData* initJITOptionsData(JNIEnv *env, jobject jitOptions)
{
    JITOptionsData *jitOptionsData = new JITOptionsData();
    if (jitOptionsData == NULL)
    {
        ThrowByName(env, "java/lang/OutOfMemoryError",
            "Out of memory during JITOptionsData creation");
        return NULL;
    }


    if (jitOptions != NULL)
    {
        // Obtain the keys from the JITOptions. These will
        // be the 'options' passed to cuModuleLoadDataEx
        jintArray keys = (jintArray)env->CallObjectMethod(jitOptions, JITOptions_getKeys);
        if (env->ExceptionCheck())
        {
            delete jitOptionsData;
            return NULL;
        }
        jitOptionsData->numOptions = (int)env->GetArrayLength(keys);

        jint *keysElements = env->GetIntArrayElements(keys, NULL);
        if (keysElements == NULL)
        {
            delete jitOptionsData;
            return NULL;
        }
        jitOptionsData->options = new CUjit_option[jitOptionsData->numOptions];
        for (int i=0; i<jitOptionsData->numOptions; i++)
        {
            jitOptionsData->options[i] = (CUjit_option)keysElements[i];
        }
        env->ReleaseIntArrayElements(keys, keysElements, JNI_ABORT);

        // Initialize the native 'optionValues' which will be passed
        // to cuModuleLoadDataEx
        jitOptionsData->optionValues = new void*[jitOptionsData->numOptions];
        for (int i=0; i<jitOptionsData->numOptions; i++)
        {
            void *value = NULL;
            if (!getOptionValue(env, jitOptions, jitOptionsData->options[i], value))
            {
                delete jitOptionsData;
                return NULL;
            }
            jitOptionsData->optionValues[i] = value;
        }
    }
    return jitOptionsData;
}

/**
 * Write the values from the given JITOptionsData into the Java JITOptions
 * object, and release the JITOptionsData. Returns whether this operation
 * succeeded.
 */
bool releaseJITOptionsData(JNIEnv *env, JITOptionsData* &jitOptionsData, jobject jitOptions)
{
    for (int i=0; i<jitOptionsData->numOptions; i++)
    {
        if (!setOptionValue(env, jitOptions, jitOptionsData->options[i], jitOptionsData->optionValues[i]))
        {
            delete[] jitOptionsData->options;
            delete[] jitOptionsData->optionValues;
            delete jitOptionsData;
            return false;
        }
    }
    delete[] jitOptionsData->options;
    delete[] jitOptionsData->optionValues;
    delete jitOptionsData;
    return true;
}







//============================================================================


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGetErrorStringNative
 * Signature: (I[Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGetErrorStringNative
  (JNIEnv *env, jclass cls, jint error, jobjectArray pStr)
{
    if (pStr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pStr' is null for cuGetErrorString");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuGetErrorString\n");

    int length = env->GetArrayLength(pStr);
    if (length == 0)
    {
        ThrowByName(env, "java/lang/IllegalArgumentException",
            "String array must at least have length 1");
        return CUDA_INTERNAL_ERROR;
    }

    const char *nativePStr;
    int result = cuGetErrorString((CUresult)error, &nativePStr);

    jstring s = NULL;
    if (nativePStr != NULL)
    {
        s = env->NewStringUTF(nativePStr);
    }
    env->SetObjectArrayElement(pStr, 0, s);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGetErrorNameNative
 * Signature: (I[Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGetErrorNameNative
  (JNIEnv *env, jclass cls, jint error, jobjectArray pStr)
{
    if (pStr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pStr' is null for cuGetErrorName");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuGetErrorName\n");

    int length = env->GetArrayLength(pStr);
    if (length == 0)
    {
        ThrowByName(env, "java/lang/IllegalArgumentException",
            "String array must at least have length 1");
        return CUDA_INTERNAL_ERROR;
    }

    const char *nativePStr;
    int result = cuGetErrorName((CUresult)error, &nativePStr);

    jstring s = NULL;
    if (nativePStr != NULL)
    {
        s = env->NewStringUTF(nativePStr);
    }
    env->SetObjectArrayElement(pStr, 0, s);
    return result;

}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuInitNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuInitNative
  (JNIEnv *env, jclass cls, jint Flags)
{
    Logger::log(LOG_TRACE, "Executing cuInit\n");

    int result = cuInit((unsigned int)Flags);
    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuDeviceGetNative
 * Signature: (LCUDAWrapper/driver/CUdevice;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDeviceGetNative
  (JNIEnv *env, jclass cls, jobject device, jint ordinal)
{
    if (device == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'device' is null for cuDeviceGet");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuDeviceGet for device %ld\n", ordinal);

    CUdevice nativeDevice;
    int result = cuDeviceGet(&nativeDevice, ordinal);
    setNativePointerValue(env, device, (jlong)nativeDevice);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuDeviceGetCountNative
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDeviceGetCountNative
  (JNIEnv *env, jclass cls, jintArray count)
{
    if (count == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'count' is null for cuDeviceGetCount");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuDeviceGetCount\n");

    int nativeCount = 0;
    int result = cuDeviceGetCount(&nativeCount);
    if (!set(env, count, 0, nativeCount)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuDeviceGetNameNative
 * Signature: ([BILCUDAWrapper/driver/CUdevice;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDeviceGetNameNative
  (JNIEnv *env, jclass cls, jbyteArray name, jint len, jobject dev)
{
    if (name == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'name' is null for cuDeviceGetName");
        return CUDA_INTERNAL_ERROR;
    }
    if (dev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dev' is null for cuDeviceGetName");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuDeviceGetName\n");

    jboolean isCopy = JNI_FALSE;
    CUdevice nativeDev = (CUdevice)(intptr_t)getNativePointerValue(env, dev);
    char *nativeName = (char*)env->GetPrimitiveArrayCritical(name, &isCopy);
    if (nativeName == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuDeviceGetName(nativeName, len, nativeDev);
    env->ReleasePrimitiveArrayCritical(name, nativeName, (isCopy==JNI_TRUE)?0:JNI_ABORT);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuDeviceComputeCapabilityNative
 * Signature: ([I[ILCUDAWrapper/driver/CUdevice;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDeviceComputeCapabilityNative
  (JNIEnv *env, jclass cls, jintArray major, jintArray minor, jobject dev)
{
    if (major == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'major' is null for cuDeviceComputeCapability");
        return CUDA_INTERNAL_ERROR;
    }
    if (minor == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'minor' is null for cuDeviceComputeCapability");
        return CUDA_INTERNAL_ERROR;
    }
    if (dev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dev' is null for cuDeviceComputeCapability");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuDeviceComputeCapability\n");

    CUdevice nativeDev = (CUdevice)(intptr_t)getNativePointerValue(env, dev);
    int nativeMajor = 0;
    int nativeMinor = 0;
    int result = cuDeviceComputeCapability(&nativeMajor, &nativeMinor, nativeDev);
    if (!set(env, major, 0, nativeMajor)) return CUDA_INTERNAL_ERROR;
    if (!set(env, minor, 0, nativeMinor)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuDevicePrimaryCtxRetainNative
* Signature: (LCUDAWrapper/driver/CUcontext;LCUDAWrapper/driver/CUdevice;)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDevicePrimaryCtxRetainNative
  (JNIEnv *env, jclass cls, jobject pctx, jobject dev)
{
    if (pctx == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pctx' is null for cuDevicePrimaryCtxRetain");
        return CUDA_INTERNAL_ERROR;
    }
    if (dev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dev' is null for cuDevicePrimaryCtxRetain");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuDevicePrimaryCtxRetain\n");

    CUcontext nativePctx = (CUcontext)(intptr_t)getNativePointerValue(env, pctx);
    CUdevice nativeDev = (CUdevice)(intptr_t)getNativePointerValue(env, dev);

    int result = cuDevicePrimaryCtxRetain(&nativePctx, nativeDev);

    return result;
}


/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuDevicePrimaryCtxReleaseNative
* Signature: (LCUDAWrapper/driver/CUdevice;)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDevicePrimaryCtxReleaseNative
  (JNIEnv *env, jclass cls, jobject dev)
{
    if (dev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dev' is null for cuDevicePrimaryCtxRelease");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuDevicePrimaryCtxRelease\n");

    CUdevice nativeDev = (CUdevice)(intptr_t)getNativePointerValue(env, dev);

    int result = cuDevicePrimaryCtxRelease(nativeDev);

    return result;
}

/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuDevicePrimaryCtxSetFlagsNative
* Signature: (LCUDAWrapper/driver/CUdevice;I)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDevicePrimaryCtxSetFlagsNative
  (JNIEnv *env, jclass cls, jobject dev, jint flags)
{
    if (dev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dev' is null for cuDevicePrimaryCtxSetFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuDevicePrimaryCtxSetFlags\n");

    CUdevice nativeDev = (CUdevice)(intptr_t)getNativePointerValue(env, dev);

    int result = cuDevicePrimaryCtxSetFlags(nativeDev, (unsigned int)flags);

    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuDeviceTotalMemNative
 * Signature: ([JLCUDAWrapper/driver/CUdevice;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDeviceTotalMemNative
(JNIEnv *env, jclass cls, jlongArray bytes, jobject dev)
{
    if (bytes == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'bytes' is null for cuDeviceTotalMem");
        return CUDA_INTERNAL_ERROR;
    }
    if (dev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dev' is null for cuDeviceTotalMem");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuDeviceTotalMem\n");

    CUdevice nativeDev = (CUdevice)(intptr_t)getNativePointerValue(env, dev);
    size_t nativeBytes = 0;
    int result = cuDeviceTotalMem(&nativeBytes, nativeDev);
    if (!set(env, bytes, 0, nativeBytes)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuDeviceGetPropertiesNative
 * Signature: (LCUDAWrapper/driver/CUdevprop;LCUDAWrapper/driver/CUdevice;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDeviceGetPropertiesNative
  (JNIEnv *env, jclass cls, jobject prop, jobject dev)
{
    if (prop == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'prop' is null for cuDeviceGetProperties");
        return CUDA_INTERNAL_ERROR;
    }
    if (dev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dev' is null for cuDeviceGetProperties");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuDeviceGetProperties\n");

    CUdevice nativeDev = (CUdevice)(intptr_t)getNativePointerValue(env, dev);

    CUdevprop nativeProp;
    int result = cuDeviceGetProperties(&nativeProp, nativeDev);

    setCUdevprop(env, prop, nativeProp);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuDeviceGetAttributeNative
 * Signature: ([IILCUDAWrapper/driver/CUdevice;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDeviceGetAttributeNative
  (JNIEnv *env, jclass cls, jintArray pi, jint CUdevice_attribute_attrib, jobject dev)
{
    if (pi == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pi' is null for cuDeviceGetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    if (dev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dev' is null for cuDeviceGetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuDeviceGetAttribute\n");

    CUdevice nativeDev = (CUdevice)(intptr_t)getNativePointerValue(env, dev);
    int nativePi = 0;
    int result = cuDeviceGetAttribute(&nativePi, (CUdevice_attribute)CUdevice_attribute_attrib, nativeDev);
    if (!set(env, pi, 0, nativePi)) return CUDA_INTERNAL_ERROR;
    return result;
}







/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxCreateNative
 * Signature: (LCUDAWrapper/driver/CUcontext;ILCUDAWrapper/driver/CUdevice;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxCreateNative
  (JNIEnv *env, jclass cls, jobject pctx, jint flags, jobject dev)
{
    if (pctx == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pctx' is null for cuCtxCreate");
        return CUDA_INTERNAL_ERROR;
    }
    if (dev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dev' is null for cuCtxCreate");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxCreate\n");

    CUdevice nativeDev = (CUdevice)(intptr_t)getNativePointerValue(env, dev);
    CUcontext nativePctx;
    int result = cuCtxCreate(&nativePctx, (int)flags, nativeDev);
    setNativePointerValue(env, pctx, (jlong)nativePctx);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxDestroyNative
 * Signature: (LCUDAWrapper/driver/CUcontext;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxDestroyNative
  (JNIEnv *env, jclass cls, jobject ctx)
{
    if (ctx == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ctx' is null for cuCtxDestroy");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxDestroy\n");

    CUcontext nativeCtx = (CUcontext)getNativePointerValue(env, ctx);
    int result = cuCtxDestroy(nativeCtx);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxAttachNative
 * Signature: (LCUDAWrapper/driver/CUcontext;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxAttachNative
  (JNIEnv *env, jclass cls, jobject pctx, jint flags)
{
    if (pctx == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pctx' is null for cuCtxAttach");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxAttach\n");

    CUcontext nativePctx = (CUcontext)getNativePointerValue(env, pctx);
    int result = cuCtxAttach(&nativePctx, (unsigned int)flags);
    setNativePointerValue(env, pctx, (jlong)nativePctx);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxDetachNative
 * Signature: (LCUDAWrapper/driver/CUcontext;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxDetachNative
  (JNIEnv *env, jclass cls, jobject ctx)
{
    if (ctx == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ctx' is null for cuCtxDetach");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxDetach\n");

    CUcontext nativeCtx = (CUcontext)getNativePointerValue(env, ctx);
    int result = cuCtxDetach(nativeCtx);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxPushCurrentNative
 * Signature: (LCUDAWrapper/driver/CUcontext;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxPushCurrentNative
  (JNIEnv *env, jclass cls, jobject ctx)
{
    if (ctx == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ctx' is null for cuCtxPushCurrent");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxPushCurrent\n");

    CUcontext nativeCtx = (CUcontext)getNativePointerValue(env, ctx);
    int result = cuCtxPushCurrent(nativeCtx);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxPopCurrentNative
 * Signature: (LCUDAWrapper/driver/CUcontext;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxPopCurrentNative
  (JNIEnv *env, jclass cls, jobject pctx)
{
    if (pctx == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pctx' is null for cuCtxPopCurrent");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxPopCurrent\n");

    CUcontext nativePctx = (CUcontext)getNativePointerValue(env, pctx);
    int result = cuCtxPopCurrent(&nativePctx);
    setNativePointerValue(env, pctx, (jlong)nativePctx);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxSetCurrentNative
 * Signature: (LCUDAWrapper/driver/CUcontext;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxSetCurrentNative
  (JNIEnv *env, jclass cls, jobject ctx)
{
    if (ctx == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ctx' is null for cuCtxSetCurrent");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxSetCurrent\n");

    CUcontext nativeCtx = (CUcontext)getNativePointerValue(env, ctx);
    int result = cuCtxSetCurrent(nativeCtx);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxGetCurrentNative
 * Signature: (LCUDAWrapper/driver/CUcontext;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxGetCurrentNative
  (JNIEnv *env, jclass cls, jobject pctx)
{
    if (pctx == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pctx' is null for cuCtxGetCurrent");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxGetCurrent\n");

    CUcontext nativePctx;
    int result = cuCtxGetCurrent(&nativePctx);
    setNativePointerValue(env, pctx, (jlong)nativePctx);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxGetDeviceNative
 * Signature: (LCUDAWrapper/driver/CUdevice;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxGetDeviceNative
  (JNIEnv *env, jclass cls, jobject device)
{
    if (device == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'device' is null for cuCtxGetDevice");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxGetDevice\n");

    CUdevice nativeDevice = (CUdevice)(intptr_t)getNativePointerValue(env, device);
    int result = cuCtxGetDevice(&nativeDevice);
    setNativePointerValue(env, device, (jlong)nativeDevice);
    return result;
}

/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuCtxGetFlagsNative
* Signature: ([I)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxGetFlagsNative
(JNIEnv *env, jclass cls, jintArray flags)
{
    if (flags == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'flags' is null for cuCtxGetFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxGetFlags\n");

    unsigned int nativeFlags = 0;
    int result = cuCtxGetFlags(&nativeFlags);
    if (!set(env, flags, 0, nativeFlags)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxSynchronizeNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxSynchronizeNative
  (JNIEnv *env, jclass cls)
{
    Logger::log(LOG_TRACE, "Executing cuCtxSynchronize\n");

    return cuCtxSynchronize();
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuModuleLoadNative
 * Signature: (LCUDAWrapper/driver/CUmodule;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuModuleLoadNative
  (JNIEnv *env, jclass cls, jobject module, jstring fname)
{
    if (module == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'module' is null for cuModuleLoad");
        return CUDA_INTERNAL_ERROR;
    }
    if (fname == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'fname' is null for cuModuleLoad");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuModuleLoad\n");

    CUmodule nativeModule;
    char *nativeFname = convertString(env, fname);
    if (nativeFname == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuModuleLoad(&nativeModule, nativeFname);
    setNativePointerValue(env, module, (jlong)nativeModule);
    delete[] nativeFname;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuModuleLoadDataNative
 * Signature: (LCUDAWrapper/driver/CUmodule;[B)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuModuleLoadDataNative
  (JNIEnv *env, jclass cls, jobject module, jbyteArray image)
{
    if (module == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'module' is null for cuModuleLoadData");
        return CUDA_INTERNAL_ERROR;
    }
    if (image == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'image' is null for cuModuleLoadData");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuModuleLoadData\n");

    CUmodule nativeModule = (CUmodule)getNativePointerValue(env, module);
    void *nativeImage = env->GetPrimitiveArrayCritical(image, NULL);
    if (nativeImage == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuModuleLoadData(&nativeModule, nativeImage);
    env->ReleasePrimitiveArrayCritical(image, nativeImage, JNI_ABORT);
    setNativePointerValue(env, module, (jlong)nativeModule);
    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuModuleLoadDataExNative
 * Signature: (LCUDAWrapper/driver/CUmodule;LCUDAWrapper/Pointer;I[ILCUDAWrapper/Pointer;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuModuleLoadDataExNative
  (JNIEnv *env, jclass cls, jobject phMod, jobject p, jint numOptions, jintArray options, jobject optionValues)
{
    if (phMod == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'phMod' is null for cuModuleLoadDataEx");
        return CUDA_INTERNAL_ERROR;
    }
    if (p == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'p' is null for cuModuleLoadDataEx");
        return CUDA_INTERNAL_ERROR;
    }
    // Although it should be possible to pass 'null' for these parameters
    // when numOptions==0, the driver crashes when they are 'null', so
    // this case is checked here as well. 
    // At the moment, it is checked on Java side: When numOptions==0,
    // and the options or optionValues are null, then they will be 
    // replaced by non-null (but empty) arrays.
    if (options == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'options' is null for cuModuleLoadDataEx");
        return CUDA_INTERNAL_ERROR;
    }
    if (optionValues == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'optionValues' is null for cuModuleLoadDataEx");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuModuleLoadDataEx\n");


    CUjit_option *nativeOptions = NULL;
    //if (options != NULL) // See notes above
    {
        jint *optionsElements = env->GetIntArrayElements(options, NULL);
        if (optionsElements == NULL)
        {
            return CUDA_INTERNAL_ERROR;
        }

        nativeOptions = new CUjit_option[numOptions];
        for (int i=0; i<numOptions; i++)
        {
            nativeOptions[i] = (CUjit_option)optionsElements[i];
        }
        env->ReleaseIntArrayElements(options, optionsElements, JNI_ABORT);
    }

    CUmodule nativeModule;
    PointerData *pPointerData = initPointerData(env, p);
    if (pPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    PointerData *optionValuesPointerData = NULL;
    void **optionValuesPointer = NULL;
    //if (optionValues != NULL) // See notes above
    {
        optionValuesPointerData = initPointerData(env, optionValues);
        if (optionValuesPointerData == NULL)
        {
            return CUDA_INTERNAL_ERROR;
        }
        optionValuesPointer = (void**)optionValuesPointerData->getPointer(env);
    }

    int result = cuModuleLoadDataEx(&nativeModule, (void*)pPointerData->getPointer(env), (unsigned int)numOptions, nativeOptions, optionValuesPointer);

    delete[] nativeOptions;

    setNativePointerValue(env, phMod, (jlong)nativeModule);
    if (!releasePointerData(env, pPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, optionValuesPointerData, 0)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuModuleLoadDataJITNative
 * Signature: (LCUDAWrapper/driver/CUmodule;LCUDAWrapper/Pointer;LCUDAWrapper/driver/JITOptions;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuModuleLoadDataJITNative
  (JNIEnv *env, jclass cls, jobject phMod, jobject p, jobject jitOptions)
{
    if (phMod == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'phMod' is null for cuModuleLoadDataJIT");
        return CUDA_INTERNAL_ERROR;
    }
    if (p == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'p' is null for cuModuleLoadDataJIT");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuModuleLoadDataJIT\n");

    CUmodule nativeModule;
    PointerData *pPointerData = initPointerData(env, p);
    if (pPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    JITOptionsData *jitOptionsData = initJITOptionsData(env, jitOptions);
    if (jitOptionsData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuModuleLoadDataEx(&nativeModule, (void*)pPointerData->getPointer(env), (unsigned int)jitOptionsData->numOptions, jitOptionsData->options, jitOptionsData->optionValues);

    if (!releaseJITOptionsData(env, jitOptionsData, jitOptions)) return CUDA_INTERNAL_ERROR;
    setNativePointerValue(env, phMod, (jlong)nativeModule);
    if (!releasePointerData(env, pPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;

}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuModuleLoadFatBinaryNative
 * Signature: (LCUDAWrapper/driver/CUmodule;[B)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuModuleLoadFatBinaryNative
  (JNIEnv *env, jclass cls, jobject module, jbyteArray fatCubin)
{
    if (module == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'module' is null for cuModuleLoadFatBinary");
        return CUDA_INTERNAL_ERROR;
    }
    if (fatCubin == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'fatCubin' is null for cuModuleLoadFatBinary");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuModuleLoadFatBinary\n");

    CUmodule nativeModule = (CUmodule)getNativePointerValue(env, module);
    void *nativeFatCubin = env->GetPrimitiveArrayCritical(fatCubin, NULL);
    if (nativeFatCubin == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuModuleLoadFatBinary(&nativeModule, nativeFatCubin);
    env->ReleasePrimitiveArrayCritical(fatCubin, nativeFatCubin, JNI_ABORT);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuModuleUnloadNative
 * Signature: (LCUDAWrapper/driver/CUmodule;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuModuleUnloadNative
  (JNIEnv *env, jclass cls, jobject hmod)
{
    if (hmod == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hmod' is null for cuModuleUnload");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuModuleUnload\n");

    CUmodule nativeHmod = (CUmodule)getNativePointerValue(env, hmod);
    int result = cuModuleUnload(nativeHmod);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuModuleGetFunctionNative
 * Signature: (LCUDAWrapper/driver/CUfunction;LCUDAWrapper/driver/CUmodule;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuModuleGetFunctionNative
  (JNIEnv *env, jclass cls, jobject hfunc, jobject hmod, jstring name)
{
    if (hfunc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hfunc' is null for cuModuleGetFunction");
        return CUDA_INTERNAL_ERROR;
    }
    if (hmod == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hmod' is null for cuModuleGetFunction");
        return CUDA_INTERNAL_ERROR;
    }
    if (name == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'name' is null for cuModuleGetFunction");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuModuleGetFunction\n");

    CUfunction nativeHfunc;
    CUmodule nativeHmod = (CUmodule)getNativePointerValue(env, hmod);
    char *nativeName = convertString(env, name);
    if (nativeName == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuModuleGetFunction(&nativeHfunc, nativeHmod, nativeName);
    setNativePointerValue(env, hfunc, (jlong)nativeHfunc);
    delete[] nativeName;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuModuleGetGlobalNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;[JLCUDAWrapper/driver/CUmodule;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuModuleGetGlobalNative
  (JNIEnv *env, jclass cls, jobject dptr, jlongArray bytes, jobject hmod, jstring name)
{
    /* May be null
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuModuleGetGlobal");
        return CUDA_INTERNAL_ERROR;
    }
    */
    /* May be null
    if (bytes == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'bytes' is null for cuModuleGetGlobal");
        return CUDA_INTERNAL_ERROR;
    }
    */
    if (hmod == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hmod' is null for cuModuleGetGlobal");
        return CUDA_INTERNAL_ERROR;
    }
    if (name == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'name' is null for cuModuleGetGlobal");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuModuleGetGlobal\n");

    CUdeviceptr nativeDptr = (CUdeviceptr)NULL;
    size_t nativeBytes = 0;

    CUmodule nativeHmod = (CUmodule)getNativePointerValue(env, hmod);

    char *nativeName = convertString(env, name);
    if (nativeName == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuModuleGetGlobal(&nativeDptr, &nativeBytes, nativeHmod, nativeName);

    setPointer(env, dptr, (jlong)nativeDptr);
    if (!set(env, bytes, 0, nativeBytes)) return CUDA_INTERNAL_ERROR;
    delete[] nativeName;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuModuleGetTexRefNative
 * Signature: (LCUDAWrapper/driver/CUtexref;LCUDAWrapper/driver/CUmodule;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuModuleGetTexRefNative
  (JNIEnv *env, jclass cls, jobject pTexRef, jobject hmod, jstring name)
{
    if (pTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pTexRef' is null for cuModuleGetTexRef");
        return CUDA_INTERNAL_ERROR;
    }
    if (hmod == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hmod' is null for cuModuleGetTexRef");
        return CUDA_INTERNAL_ERROR;
    }
    if (name == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'name' is null for cuModuleGetTexRef");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuModuleGetTexRef\n");

    CUtexref nativePTexRef = NULL;

    CUmodule nativeHmod = (CUmodule)getNativePointerValue(env, hmod);

    char *nativeName = convertString(env, name);
    if (nativeName == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuModuleGetTexRef(&nativePTexRef, nativeHmod, nativeName);

    setNativePointerValue(env, pTexRef, (jlong)nativePTexRef);
    delete[] nativeName;
    return result;

}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuModuleGetSurfRefNative
 * Signature: (LCUDAWrapper/driver/CUsurfref;LCUDAWrapper/driver/CUmodule;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuModuleGetSurfRefNative
  (JNIEnv *env, jclass cls, jobject pSurfRef, jobject hmod, jstring name)
{
    if (pSurfRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pSurfRef' is null for cuModuleGetSurfRef");
        return CUDA_INTERNAL_ERROR;
    }
    if (hmod == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hmod' is null for cuModuleGetSurfRef");
        return CUDA_INTERNAL_ERROR;
    }
    if (name == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'name' is null for cuModuleGetSurfRef");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuModuleGetSurfRef\n");

    CUsurfref nativePSurfRef = NULL;

    CUmodule nativeHmod = (CUmodule)getNativePointerValue(env, hmod);

    char *nativeName = convertString(env, name);
    if (nativeName == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuModuleGetSurfRef(&nativePSurfRef, nativeHmod, nativeName);

    setNativePointerValue(env, pSurfRef, (jlong)nativePSurfRef);
    delete[] nativeName;
    return result;

}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuLinkCreateNative
 * Signature: (LCUDAWrapper/driver/JITOptions;LCUDAWrapper/driver/CUlinkState;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuLinkCreateNative
  (JNIEnv *env, jclass cls, jobject jitOptions, jobject stateOut)
{
    if (stateOut == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stateOut' is null for cuLinkCreate");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuLinkCreate\n");

    CUlinkState nativeStateOut;
    JITOptionsData *jitOptionsData = initJITOptionsData(env, jitOptions);
    if (jitOptionsData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuLinkCreate((unsigned int)jitOptionsData->numOptions, jitOptionsData->options, jitOptionsData->optionValues, &nativeStateOut);

    if (!releaseJITOptionsData(env, jitOptionsData, jitOptions)) return CUDA_INTERNAL_ERROR;
    setNativePointerValue(env, stateOut, (jlong)nativeStateOut);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuLinkAddDataNative
 * Signature: (LCUDAWrapper/driver/CUlinkState;ILCUDAWrapper/Pointer;JLjava/lang/String;LCUDAWrapper/driver/JITOptions;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuLinkAddDataNative
  (JNIEnv *env, jclass cls, jobject state, jint type, jobject data, jlong size, jstring name, jobject jitOptions)
{
    if (state == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'state' is null for cuLinkAddData");
        return CUDA_INTERNAL_ERROR;
    }
    // name and jitOptions may be null

    Logger::log(LOG_TRACE, "Executing cuLinkAddData\n");

    CUlinkState nativeState = (CUlinkState)getNativePointerValue(env, state);
    PointerData *dataPointerData = initPointerData(env, data);
    if (dataPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    char *nativeName = convertString(env, name);

    JITOptionsData *jitOptionsData = initJITOptionsData(env, jitOptions);
    if (jitOptionsData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cuLinkAddData(nativeState, (CUjitInputType)type, dataPointerData->getPointer(env), (size_t)size, nativeName,
        (unsigned int)jitOptionsData->numOptions, jitOptionsData->options, jitOptionsData->optionValues);

    if (!releasePointerData(env, dataPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    delete[] nativeName;
    if (!releaseJITOptionsData(env, jitOptionsData, jitOptions)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuLinkAddFileNative
 * Signature: (LCUDAWrapper/driver/CUlinkState;ILjava/lang/String;LCUDAWrapper/driver/JITOptions;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuLinkAddFileNative
  (JNIEnv *env, jclass cls, jobject state, jint type, jstring path, jobject jitOptions)
{
    if (state == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'state' is null for cuLinkAddFile");
        return CUDA_INTERNAL_ERROR;
    }
    if (path == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'state' is null for cuLinkAddFile");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuLinkAddFile\n");

    CUlinkState nativeState = (CUlinkState)getNativePointerValue(env, state);
    char *nativePath = convertString(env, path);

    JITOptionsData *jitOptionsData = initJITOptionsData(env, jitOptions);
    if (jitOptionsData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cuLinkAddFile(nativeState, (CUjitInputType)type, nativePath,
        (unsigned int)jitOptionsData->numOptions, jitOptionsData->options, jitOptionsData->optionValues);

    delete[] nativePath;
    if (!releaseJITOptionsData(env, jitOptionsData, jitOptions)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuLinkCompleteNative
 * Signature: (LCUDAWrapper/driver/CUlinkState;LCUDAWrapper/Pointer;[J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuLinkCompleteNative
  (JNIEnv *env, jclass cls, jobject state, jobject cubinOut, jlongArray sizeOut)
{
    if (state == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'state' is null for cuLinkComplete");
        return CUDA_INTERNAL_ERROR;
    }
    if (cubinOut == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'cubinOut' is null for cuLinkComplete");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuLinkComplete\n");

    CUlinkState nativeState = (CUlinkState)getNativePointerValue(env, state);
    void *nativeCubinOut;
    size_t nativeSizeOut;

    int result = cuLinkComplete(nativeState, &nativeCubinOut, &nativeSizeOut);

    setNativePointerValue(env, cubinOut, (jlong)nativeCubinOut);
    if (sizeOut != NULL)
    {
        set(env, sizeOut, 0, nativeSizeOut);
    }
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuLinkDestroyNative
 * Signature: (LCUDAWrapper/driver/CUlinkState;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuLinkDestroyNative
  (JNIEnv *env, jclass cls, jobject state)
{
    if (state == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'state' is null for cuLinkDestroy");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuLinkDestroy\n");

    CUlinkState nativeState = (CUlinkState)getNativePointerValue(env, state);

    int result = cuLinkDestroy(nativeState);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemGetInfoNative
 * Signature: ([J[J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemGetInfoNative
  (JNIEnv *env, jclass cls, jlongArray free, jlongArray total)
{
    if (free == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'free' is null for cuMemGetInfo");
        return CUDA_INTERNAL_ERROR;
    }
    if (total == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'total' is null for cuMemGetInfo");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemGetInfo\n");

    size_t nativeFree = 0;
    size_t nativeTotal = 0;
    int result = cuMemGetInfo(&nativeFree, &nativeTotal);
    if (!set(env, free, 0, nativeFree)) return CUDA_INTERNAL_ERROR;
    if (!set(env, total, 0, nativeTotal)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemHostAllocNative
 * Signature: (LCUDAWrapper/Pointer;JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemHostAllocNative
  (JNIEnv *env, jclass cls, jobject pp, jlong bytesize, jint Flags)
{
    if (pp == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pp' is null for cuMemHostAlloc");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemHostAlloc\n");

    void *nativePp;
    int result = cuMemHostAlloc(&nativePp, (size_t)bytesize, (unsigned int)Flags);
    if (result == CUDA_SUCCESS)
    {
        jobject object = env->NewDirectByteBuffer(nativePp, bytesize);
        env->SetObjectField(pp, Pointer_buffer, object);
        env->SetObjectField(pp, Pointer_pointers, NULL);
        env->SetLongField(pp, Pointer_byteOffset, 0);
        env->SetLongField(pp, NativePointerObject_nativePointer, (jlong)nativePp);
    }
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemHostGetDevicePointerNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/Pointer;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemHostGetDevicePointerNative
  (JNIEnv *env, jclass cls, jobject ret, jobject p, jint Flags)
{
    if (ret == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ret' is null for cuMemHostGetDevicePointer");
        return CUDA_INTERNAL_ERROR;
    }
    if (p == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'p' is null for cuMemHostGetDevicePointer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemHostGetDevicePointer\n");

    if (!isPointerBackedByNativeMemory(env, p))
    {
        ThrowByName(env, "java/lang/IllegalArgumentException",
            "Pointer must point to a direct buffer or native memory");
        return CUDA_INTERNAL_ERROR;
    }

    CUdeviceptr nativeRet;
    PointerData *pPointerData = initPointerData(env, p);
    if (pPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuMemHostGetDevicePointer(&nativeRet, (void*)pPointerData->getPointer(env), (unsigned int)Flags);
    setPointer(env, ret, (jlong)nativeRet);
    if (!releasePointerData(env, pPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemHostGetFlagsNative
 * Signature: ([ILCUDAWrapper/Pointer;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemHostGetFlagsNative
  (JNIEnv *env, jclass cls, jintArray pFlags, jobject p)
{
    if (pFlags == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pFlags' is null for cuMemHostGetFlags");
        return CUDA_INTERNAL_ERROR;
    }
    if (p == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'p' is null for cuMemHostGetFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemHostGetFlags\n");

    if (!isPointerBackedByNativeMemory(env, p))
    {
        ThrowByName(env, "java/lang/IllegalArgumentException",
            "Pointer must point to a direct buffer or native memory");
        return CUDA_INTERNAL_ERROR;
    }

    PointerData *pPointerData = initPointerData(env, p);
    if (pPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    unsigned int nativePFlags;
    int result = cuMemHostGetFlags(&nativePFlags, (void*)pPointerData->getPointer(env));
    if (!set(env, pFlags, 0, nativePFlags)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, pPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuDeviceGetByPCIBusIdNative
 * Signature: (LCUDAWrapper/driver/CUdevice;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDeviceGetByPCIBusIdNative
  (JNIEnv *env, jclass cls, jobject dev, jstring pciBusId)
{
    if (dev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dev' is null for cuDeviceGetByPCIBusId");
        return CUDA_INTERNAL_ERROR;
    }
    if (pciBusId == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pciBusId' is null for cuDeviceGetByPCIBusId");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuDeviceGetByPCIBusId\n");

    char *nativePciBusId = convertString(env, pciBusId);

    CUdevice nativeDev;
    int result = cuDeviceGetByPCIBusId(&nativeDev, nativePciBusId);
    setNativePointerValue(env, dev, (jlong)nativeDev);
    delete[] nativePciBusId;

    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemAllocManagedNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemAllocManagedNative
  (JNIEnv *env, jclass cls, jobject dptr, jlong bytesize, jint flags)
{
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuMemAllocManaged");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemAllocManaged of %ld bytes\n", (long)bytesize);

    CUdeviceptr nativeDptr;
    int result = cuMemAllocManaged(&nativeDptr, (size_t)bytesize, (unsigned int)flags);
    if (result == CUDA_SUCCESS)
    {
        if (flags == CU_MEM_ATTACH_HOST)
        {
            jobject object = env->NewDirectByteBuffer((void*)nativeDptr, bytesize);
            env->SetObjectField(dptr, Pointer_buffer, object);
            env->SetObjectField(dptr, Pointer_pointers, NULL);
            env->SetLongField(dptr, Pointer_byteOffset, 0);
        }
        env->SetLongField(dptr, NativePointerObject_nativePointer, (jlong)nativeDptr);
    }
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuDeviceGetPCIBusIdNative
 * Signature: ([Ljava/lang/String;ILCUDAWrapper/driver/CUdevice;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDeviceGetPCIBusIdNative
  (JNIEnv *env, jclass cls, jobjectArray pciBusId, jint len, jobject dev)
{
    if (pciBusId == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pciBusId' is null for cuDeviceGetPCIBusId");
        return CUDA_INTERNAL_ERROR;
    }
    if (dev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dev' is null for cuDeviceGetPCIBusId");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuDeviceGetPCIBusId\n");

    char *nativePciBusId = new char[(int)len];
    CUdevice nativeDev = (CUdevice)(intptr_t)getNativePointerValue(env, dev);
    int result = cuDeviceGetPCIBusId(nativePciBusId, (int)len, nativeDev);

    jstring pciBusIdElement = env->NewStringUTF(nativePciBusId);
    if (pciBusIdElement == NULL)
    {
       ThrowByName(env, "java/lang/OutOfMemoryError", "Out of memory creating result string");
       return CUDA_INTERNAL_ERROR;
    }
    delete[] nativePciBusId;
    env->SetObjectArrayElement(pciBusId, 0, pciBusIdElement);
    if (env->ExceptionCheck())
    {
        return CUDA_INTERNAL_ERROR;
    }
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuIpcGetEventHandleNative
 * Signature: (LCUDAWrapper/driver/CUipcEventHandle;LCUDAWrapper/driver/CUevent;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuIpcGetEventHandleNative
  (JNIEnv *env, jclass cls, jobject pHandle, jobject event)
{
    if (pHandle == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pHandle' is null for cuIpcGetEventHandle");
        return CUDA_INTERNAL_ERROR;
    }
    if (event == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'event' is null for cuIpcGetEventHandle");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuIpcGetEventHandle\n");

    CUevent nativeEvent = (CUevent)getNativePointerValue(env, event);
    CUipcEventHandle nativePHandle;

    int result = cuIpcGetEventHandle(&nativePHandle, nativeEvent);
    setCUipcEventHandle(env, pHandle, nativePHandle);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuIpcOpenEventHandleNative
 * Signature: (LCUDAWrapper/driver/CUevent;LCUDAWrapper/driver/CUipcEventHandle;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuIpcOpenEventHandleNative
  (JNIEnv *env, jclass cls, jobject phEvent, jobject handle)
{
    if (phEvent == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'phEvent' is null for cuIpcOpenEventHandle");
        return CUDA_INTERNAL_ERROR;
    }
    if (handle == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'handle' is null for cuIpcOpenEventHandle");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuIpcOpenEventHandle\n");

    CUevent nativePhEvent;
    CUipcEventHandle nativeHandle = getCUipcEventHandle(env, handle);
    int result = cuIpcOpenEventHandle(&nativePhEvent, nativeHandle);

    setNativePointerValue(env, phEvent, (jlong)nativePhEvent);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuIpcGetMemHandleNative
 * Signature: (LCUDAWrapper/driver/CUipcMemHandle;LCUDAWrapper/driver/CUdeviceptr;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuIpcGetMemHandleNative
  (JNIEnv *env, jclass cls, jobject pHandle, jobject dptr)
{
    if (pHandle == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pHandle' is null for cuIpcGetMemHandle");
        return CUDA_INTERNAL_ERROR;
    }
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuIpcGetMemHandle");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuIpcGetMemHandle\n");

    CUipcMemHandle nativePHandle;
    CUdeviceptr nativeDptr = (CUdeviceptr)getPointer(env, dptr);

    int result = cuIpcGetMemHandle(&nativePHandle, nativeDptr);
    setCUipcMemHandle(env, pHandle, nativePHandle);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuIpcOpenMemHandleNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUipcMemHandle;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuIpcOpenMemHandleNative
  (JNIEnv *env, jclass cls, jobject pdptr, jobject handle, jint Flags)
{
    if (pdptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pdptr' is null for cuIpcOpenMemHandle");
        return CUDA_INTERNAL_ERROR;
    }
    if (handle == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'handle' is null for cuIpcOpenMemHandle");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuIpcOpenMemHandle\n");

    CUipcMemHandle nativeHandle = getCUipcMemHandle(env, handle);
    CUdeviceptr nativePdptr = NULL;

    int result = cuIpcOpenMemHandle(&nativePdptr, nativeHandle, (int)Flags);

    setPointer(env, pdptr, (jlong)nativePdptr);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuIpcCloseMemHandleNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuIpcCloseMemHandleNative
  (JNIEnv *env, jclass cls, jobject dptr)
{
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuIpcCloseMemHandle");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuIpcCloseMemHandle\n");

    CUdeviceptr nativeDptr = (CUdeviceptr)getPointer(env, dptr);

    int result = cuIpcCloseMemHandle(nativeDptr);
    return result;
}





/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemHostRegisterNative
 * Signature: (LCUDAWrapper/Pointer;JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemHostRegisterNative
  (JNIEnv *env, jclass cls, jobject p, jlong bytesize, jint Flags)
{
    if (p == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'p' is null for cuMemHostRegister");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemHostRegister\n");

    if (!isPointerBackedByNativeMemory(env, p))
    {
        ThrowByName(env, "java/lang/IllegalArgumentException",
            "Pointer must point to a direct buffer or native memory");
        return CUDA_INTERNAL_ERROR;
    }

    PointerData *pPointerData = initPointerData(env, p);
    if (pPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuMemHostRegister((void*)pPointerData->getPointer(env), (size_t)bytesize, (unsigned int)Flags);
    if (!releasePointerData(env, pPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemHostUnregisterNative
 * Signature: (LCUDAWrapper/Pointer;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemHostUnregisterNative
  (JNIEnv *env, jclass cls, jobject p)
{
    if (p == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'p' is null for cuMemHostUnregister");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemHostUnregister\n");

    PointerData *pPointerData = initPointerData(env, p);
    if (pPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuMemHostUnregister((void*)pPointerData->getPointer(env));
    if (!releasePointerData(env, pPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUdeviceptr;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyNative
  (JNIEnv *env, jclass cls, jobject dst, jobject src, jlong ByteCount)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cuMemcpy");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cuMemcpy");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpy\n");

    CUdeviceptr nativeDst = (CUdeviceptr)getPointer(env, dst);
    CUdeviceptr nativeSrc = (CUdeviceptr)getPointer(env, src);
    int result = cuMemcpy(nativeDst, nativeSrc, (size_t)ByteCount);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyPeerNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUcontext;LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUcontext;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyPeerNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jobject dstContext, jobject srcDevice, jobject srcContext, jlong ByteCount)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemcpyPeer");
        return CUDA_INTERNAL_ERROR;
    }
    if (dstContext == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstContext' is null for cuMemcpyPeer");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemcpyPeer");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcContext == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstContext' is null for cuMemcpyPeer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpyPeer\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    CUcontext nativeDstContext = (CUcontext)getNativePointerValue(env, dstContext);
    CUdeviceptr nativeSrcDevice = (CUdeviceptr)getPointer(env, srcDevice);
    CUcontext nativeSrcContext = (CUcontext)getNativePointerValue(env, srcContext);
    int result = cuMemcpyPeer(nativeDstDevice, nativeDstContext, nativeSrcDevice, nativeSrcContext, (size_t)ByteCount);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyAsyncNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUdeviceptr;JLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyAsyncNative
  (JNIEnv *env, jclass cls, jobject dst, jobject src, jlong ByteCount, jobject hStream)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cuMemcpyAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cuMemcpyAsync");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpyAsync\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    CUdeviceptr nativeDst = (CUdeviceptr)getPointer(env, dst);
    CUdeviceptr nativeSrc = (CUdeviceptr)getPointer(env, src);
    int result = cuMemcpyAsync(nativeDst, nativeSrc, (size_t)ByteCount, nativeHStream);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyPeerAsyncNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUcontext;LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUcontext;JLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyPeerAsyncNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jobject dstContext, jobject srcDevice, jobject srcContext, jlong ByteCount, jobject hStream)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemcpyPeerAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (dstContext == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstContext' is null for cuMemcpyPeerAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemcpyPeerAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcContext == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstContext' is null for cuMemcpyPeerAsync");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpyPeerAsync\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    CUcontext nativeDstContext = (CUcontext)getNativePointerValue(env, dstContext);
    CUdeviceptr nativeSrcDevice = (CUdeviceptr)getPointer(env, srcDevice);
    CUcontext nativeSrcContext = (CUcontext)getNativePointerValue(env, srcContext);
    int result = cuMemcpyPeerAsync(nativeDstDevice, nativeDstContext, nativeSrcDevice, nativeSrcContext, (size_t)ByteCount, nativeHStream);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemAllocNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemAllocNative
  (JNIEnv *env, jclass cls, jobject dptr, jlong bytesize)
{
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuMemAlloc");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemAlloc of %ld bytes\n", (long)bytesize);

    CUdeviceptr nativeDptr;
    int result = cuMemAlloc(&nativeDptr, (size_t)bytesize);
    setPointer(env, dptr, (jlong)nativeDptr);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemAllocPitchNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;[JJJI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemAllocPitchNative
  (JNIEnv *env, jclass cls, jobject dptr, jlongArray pPitch, jlong WidthInBytes, jlong Height, jint ElementSizeBytes)
{
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuMemAllocPitch");
        return CUDA_INTERNAL_ERROR;
    }
    if (pPitch == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pPitch' is null for cuMemAllocPitch");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemAllocPitch\n");

    CUdeviceptr nativeDptr;
    size_t nativePPitch;

    int result = cuMemAllocPitch(&nativeDptr, &nativePPitch, (size_t)WidthInBytes, (size_t)Height, (unsigned int)ElementSizeBytes);

    setPointer(env, dptr, (jlong)nativeDptr);
    if (!set(env, pPitch, 0, nativePPitch)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemFreeNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemFreeNative
  (JNIEnv *env, jclass cls, jobject dptr)
{
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuMemFree");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemFree\n");

    CUdeviceptr nativeDptr = (CUdeviceptr)getPointer(env, dptr);
    int result = cuMemFree(nativeDptr);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemGetAddressRangeNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;[JLCUDAWrapper/driver/CUdeviceptr;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemGetAddressRangeNative
  (JNIEnv *env, jclass cls, jobject pbase, jlongArray psize, jobject dptr)
{
    /* May be null
    if (pbase == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pbase' is null for cuMemGetAddressRange");
        return CUDA_INTERNAL_ERROR;
    }
    if (psize == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'psize' is null for cuMemGetAddressRange");
        return CUDA_INTERNAL_ERROR;
    }
    */
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuMemGetAddressRange");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemGetAddressRange\n");

    CUdeviceptr nativeDptr = (CUdeviceptr)getPointer(env, dptr);

    size_t nativePsize;
    CUdeviceptr nativePbase;
    int result = cuMemGetAddressRange(&nativePbase, &nativePsize, nativeDptr);

    setPointer(env, pbase, nativePbase);
    if (!set(env, psize, 0, nativePsize)) return CUDA_INTERNAL_ERROR;

    return result;
}






/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemAllocHostNative
 * Signature: (LCUDAWrapper/Pointer;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemAllocHostNative
  (JNIEnv *env, jclass cls, jobject pp, jlong bytesize)
{
    if (pp == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pp' is null for cuMemAllocHost");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemAllocHost of %ld bytes\n", (size_t)bytesize);

    void *nativePp;
    int result = cuMemAllocHost(&nativePp, (size_t)bytesize);
    if (result == CUDA_SUCCESS)
    {
        jobject object = env->NewDirectByteBuffer(nativePp, bytesize);
        env->SetObjectField(pp, Pointer_buffer, object);
        env->SetObjectField(pp, Pointer_pointers, NULL);
        env->SetLongField(pp, Pointer_byteOffset, 0);
        env->SetLongField(pp, NativePointerObject_nativePointer, (jlong)nativePp);
    }
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemFreeHostNative
 * Signature: (LCUDAWrapper/Pointer;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemFreeHostNative
  (JNIEnv *env, jclass cls, jobject p)
{
    if (p == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'p' is null for cuMemFreeHost");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemFreeHost\n");

    PointerData *pPointerData = initPointerData(env, p);
    if (pPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cuMemFreeHost((void*)pPointerData->getPointer(env));
    if (!releasePointerData(env, pPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyHtoDNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/Pointer;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyHtoDNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jobject srcHost, jlong ByteCount)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemcpyHtoD");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcHost == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'srcHost' is null for cuMemcpyHtoD");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpyHtoD of %d bytes\n", (size_t)ByteCount);

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    PointerData *srcHostPointerData = initPointerData(env, srcHost);
    if (srcHostPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cuMemcpyHtoD(nativeDstDevice, (void*)srcHostPointerData->getPointer(env), (size_t)ByteCount);

    if (!releasePointerData(env, srcHostPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyDtoHNative
 * Signature: (LCUDAWrapper/Pointer;LCUDAWrapper/driver/CUdeviceptr;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyDtoHNative
  (JNIEnv *env, jclass cls, jobject dstHost, jobject srcDevice, jlong ByteCount)
{
    if (dstHost == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstHost' is null for cuMemcpyDtoH");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'srcDevice' is null for cuMemcpyDtoH");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpyDtoH of %d bytes\n", (size_t)ByteCount);


    PointerData *dstHostPointerData = initPointerData(env, dstHost);
    if (dstHostPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    CUdeviceptr nativeSrcDevice = (CUdeviceptr)getPointer(env, srcDevice);
    void *nativeDstHost = (void*)dstHostPointerData->getPointer(env);

    int result = cuMemcpyDtoH(nativeDstHost, nativeSrcDevice, (size_t)ByteCount);

    if (!releasePointerData(env, dstHostPointerData, 0)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyDtoDNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUdeviceptr;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyDtoDNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jobject srcDevice, jlong ByteCount)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemcpyDtoD");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'srcDevice' is null for cuMemcpyDtoD");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpyDtoD of %d bytes\n", (size_t)ByteCount);

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    CUdeviceptr nativeSrcDevice = (CUdeviceptr)getPointer(env, srcDevice);

    int result = cuMemcpyDtoD(nativeDstDevice, nativeSrcDevice, (size_t)ByteCount);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyDtoANative
 * Signature: (LCUDAWrapper/driver/CUarray;JLCUDAWrapper/driver/CUdeviceptr;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyDtoANative
  (JNIEnv *env, jclass cls, jobject dstArray, jlong dstIndex, jobject srcDevice, jlong ByteCount)
{
    if (dstArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstArray' is null for cuMemcpyDtoA");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'srcDevice' is null for cuMemcpyDtoA");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpyDtoA of %d bytes\n", (size_t)ByteCount);

    CUarray nativeDstArray = (CUarray)getNativePointerValue(env, dstArray);
    CUdeviceptr nativeSrcDevice = (CUdeviceptr)getPointer(env, srcDevice);

    int result = cuMemcpyDtoA(nativeDstArray, (size_t)dstIndex, nativeSrcDevice, (size_t)ByteCount);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyAtoDNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUarray;JJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyAtoDNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jobject hSrc, jlong SrcIndex, jlong ByteCount)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemcpyAtoD");
        return CUDA_INTERNAL_ERROR;
    }
    if (hSrc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hSrc' is null for cuMemcpyAtoD");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpyAtoD of %d bytes\n", (size_t)ByteCount);

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    CUarray nativeHSrc = (CUarray)getNativePointerValue(env, hSrc);

    int result = cuMemcpyAtoD(nativeDstDevice, nativeHSrc, (size_t)SrcIndex, (size_t)ByteCount);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyHtoANative
 * Signature: (LCUDAWrapper/driver/CUarray;JLCUDAWrapper/Pointer;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyHtoANative
  (JNIEnv *env, jclass cls, jobject dstArray, jlong dstIndex, jobject pSrc, jlong ByteCount)
{
    if (dstArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstArray' is null for cuMemcpyHtoA");
        return CUDA_INTERNAL_ERROR;
    }
    if (pSrc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pSrc' is null for cuMemcpyHtoA");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpyHtoA of %d bytes\n", (size_t)ByteCount);

    CUarray nativeDstArray = (CUarray)getNativePointerValue(env, dstArray);

    PointerData *pSrcPointerData = initPointerData(env, pSrc);
    if (pSrcPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cuMemcpyHtoA(nativeDstArray, (size_t)dstIndex, (void*)pSrcPointerData->getPointer(env), (size_t)ByteCount);

    if (!releasePointerData(env, pSrcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;

    return result;
}






/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyAtoHNative
 * Signature: (LCUDAWrapper/Pointer;LCUDAWrapper/driver/CUarray;JJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyAtoHNative
  (JNIEnv *env, jclass cls, jobject dstHost, jobject srcArray, jlong srcIndex, jlong ByteCount)
{
    if (dstHost == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstHost' is null for cuMemcpyAtoH");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'srcArray' is null for cuMemcpyAtoH");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpyAtoH of %d bytes\n", (size_t)ByteCount);

    PointerData *dstHostPointerData = initPointerData(env, dstHost);
    if (dstHostPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    CUarray nativeSrcArray = (CUarray)getNativePointerValue(env, srcArray);

    int result = cuMemcpyAtoH((void*)dstHostPointerData->getPointer(env), nativeSrcArray, (size_t)srcIndex, (size_t)ByteCount);

    if (!releasePointerData(env, dstHostPointerData)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyAtoANative
 * Signature: (LCUDAWrapper/driver/CUarray;JLCUDAWrapper/driver/CUarray;JJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyAtoANative
  (JNIEnv *env, jclass cls, jobject dstArray, jlong dstIndex, jobject srcArray, jlong srcIndex, jlong ByteCount)
{
    if (dstArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstArray' is null for cuMemcpyAtoA");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'srcArray' is null for cuMemcpyAtoA");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpyAtoA of %d bytes\n", (size_t)ByteCount);

    CUarray nativeDstArray = (CUarray)getNativePointerValue(env, dstArray);
    CUarray nativeSrcArray = (CUarray)getNativePointerValue(env, srcArray);

    int result = cuMemcpyAtoA(nativeDstArray, (size_t)dstIndex, nativeSrcArray, (size_t)srcIndex, (size_t)ByteCount);
    return result;
}






/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpy2DNative
 * Signature: (LCUDAWrapper/driver/CUDA_MEMCPY2D;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpy2DNative
  (JNIEnv *env, jclass cls, jobject pCopy)
{
    if (pCopy == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCopy' is null for cuMemcpy2D");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpy2D\n");

    Memcpy2DData *memcpyData = initMemcpy2DData(env, pCopy);
    if (memcpyData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cuMemcpy2D(&memcpyData->memcpy2d);

    if (!releaseMemcpy2DData(env, memcpyData)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpy2DUnalignedNative
 * Signature: (LCUDAWrapper/driver/CUDA_MEMCPY2D;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpy2DUnalignedNative
  (JNIEnv *env, jclass cls, jobject pCopy)
{
    if (pCopy == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCopy' is null for cuMemcpy2DUnaligned");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpy2DUnaligned\n");

    Memcpy2DData *memcpyData = initMemcpy2DData(env, pCopy);
    if (memcpyData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cuMemcpy2DUnaligned(&memcpyData->memcpy2d);

    if (!releaseMemcpy2DData(env, memcpyData)) return CUDA_INTERNAL_ERROR;

    return result;
}






/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpy3DNative
 * Signature: (LCUDAWrapper/driver/CUDA_MEMCPY3D;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpy3DNative
  (JNIEnv *env, jclass cls, jobject pCopy)
{
    if (pCopy == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCopy' is null for cuMemcpy3D");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpy3D\n");

    Memcpy3DData *memcpyData = initMemcpy3DData(env, pCopy);
    if (memcpyData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    /*
    Logger::log(LOG_DEBUGTRACE, "Source X in bytes %d\n", memcpyData.memcpy3d.srcXInBytes);
    Logger::log(LOG_DEBUGTRACE, "Source Y %d\n", memcpyData.memcpy3d.srcY);
    Logger::log(LOG_DEBUGTRACE, "Source Z %d\n", memcpyData.memcpy3d.srcZ);
    Logger::log(LOG_DEBUGTRACE, "Source LOD %d\n", memcpyData.memcpy3d.srcLOD);
    Logger::log(LOG_DEBUGTRACE, "Source memory type %d\n", memcpyData.memcpy3d.srcMemoryType);
    Logger::log(LOG_DEBUGTRACE, "Source host pointer %p\n", memcpyData.memcpy3d.srcHost);
    Logger::log(LOG_DEBUGTRACE, "Source device pointer %p\n", memcpyData.memcpy3d.srcDevice);
    Logger::log(LOG_DEBUGTRACE, "Source array reference %p\n", memcpyData.memcpy3d.srcArray);
    Logger::log(LOG_DEBUGTRACE, "Source pitch %d\n", memcpyData.memcpy3d.srcPitch);
    Logger::log(LOG_DEBUGTRACE, "Source height %d\n", memcpyData.memcpy3d.srcHeight);
    Logger::log(LOG_DEBUGTRACE, "Destination X in bytes %d\n", memcpyData.memcpy3d.dstXInBytes);
    Logger::log(LOG_DEBUGTRACE, "Destination Y %d\n", memcpyData.memcpy3d.dstY);
    Logger::log(LOG_DEBUGTRACE, "Destination Z %d\n", memcpyData.memcpy3d.dstZ);
    Logger::log(LOG_DEBUGTRACE, "Destination LOD %d\n", memcpyData.memcpy3d.dstLOD);
    Logger::log(LOG_DEBUGTRACE, "Destination memory type %d\n", memcpyData.memcpy3d.dstMemoryType);
    Logger::log(LOG_DEBUGTRACE, "Destination host pointer %p\n", memcpyData.memcpy3d.dstHost);
    Logger::log(LOG_DEBUGTRACE, "Destination device pointer %p\n", memcpyData.memcpy3d.dstDevice);
    Logger::log(LOG_DEBUGTRACE, "Destination array reference %p\n", memcpyData.memcpy3d.dstArray);
    Logger::log(LOG_DEBUGTRACE, "Destination pitch  %d\n", memcpyData.memcpy3d.dstPitch);
    Logger::log(LOG_DEBUGTRACE, "Destination height %d\n", memcpyData.memcpy3d.dstHeight);
    Logger::log(LOG_DEBUGTRACE, "Width of 3D memory copy in bytes %d\n", memcpyData.memcpy3d.WidthInBytes);
    Logger::log(LOG_DEBUGTRACE, "Height of 3D memory copy %d\n", memcpyData.memcpy3d.Height);
    Logger::log(LOG_DEBUGTRACE, "Depth of 3D memory copy %d\n", memcpyData.memcpy3d.Depth);
    */

    int result = cuMemcpy3D(&memcpyData->memcpy3d);

    if (!releaseMemcpy3DData(env, memcpyData)) return CUDA_INTERNAL_ERROR;

    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpy3DPeerNative
 * Signature: (LCUDAWrapper/driver/CUDA_MEMCPY3D_PEER;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpy3DPeerNative
  (JNIEnv *env, jclass cls, jobject pCopy)
{
    if (pCopy == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCopy' is null for cuMemcpy3DPeer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpy3DPeer\n");

    Memcpy3DPeerData *memcpyData = initMemcpy3DPeerData(env, pCopy);
    if (memcpyData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cuMemcpy3DPeer(&memcpyData->memcpy3d);

    if (!releaseMemcpy3DPeerData(env, memcpyData)) return CUDA_INTERNAL_ERROR;

    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpy3DPeerAsyncNative
 * Signature: (LCUDAWrapper/driver/CUDA_MEMCPY3D_PEER;LCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpy3DPeerAsyncNative
  (JNIEnv *env, jclass cls, jobject pCopy, jobject hStream)
{
    if (pCopy == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCopy' is null for cuMemcpy3DPeerAsync");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpy3DPeerAsync\n");

    Memcpy3DPeerData *memcpyData = initMemcpy3DPeerData(env, pCopy);
    if (memcpyData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemcpy3DPeerAsync(&memcpyData->memcpy3d, nativeHStream);

    if (!releaseMemcpy3DPeerData(env, memcpyData)) return CUDA_INTERNAL_ERROR;

    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyHtoDAsyncNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/Pointer;JLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyHtoDAsyncNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jobject srcHost, jlong ByteCount, jobject hStream)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemcpyHtoDAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcHost == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'srcHost' is null for cuMemcpyHtoDAsync");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemcpyHtoDAsync of %d bytes\n", (size_t)ByteCount);

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    PointerData *srcHostPointerData = initPointerData(env, srcHost);
    if (srcHostPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemcpyHtoDAsync(nativeDstDevice, (void*)srcHostPointerData->getPointer(env), (size_t)ByteCount, nativeHStream);

    if (!releasePointerData(env, srcHostPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyDtoHAsyncNative
 * Signature: (LCUDAWrapper/Pointer;LCUDAWrapper/driver/CUdeviceptr;JLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyDtoHAsyncNative
  (JNIEnv *env, jclass cls, jobject dstHost, jobject srcDevice, jlong ByteCount, jobject hStream)
{
    if (dstHost == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstHost' is null for cuMemcpyDtoHAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'srcDevice' is null for cuMemcpyDtoHAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuMemcpyDtoHAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cuMemcpyDtoHAsync of %d bytes\n", (size_t)ByteCount);

    PointerData *dstHostPointerData = initPointerData(env, dstHost);
    if (dstHostPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    CUdeviceptr nativeSrcDevice = (CUdeviceptr)getPointer(env, srcDevice);
    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemcpyDtoHAsync((void*)dstHostPointerData->getPointer(env), nativeSrcDevice, (size_t)ByteCount, nativeHStream);

    if (!releasePointerData(env, dstHostPointerData)) return CUDA_INTERNAL_ERROR;

    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyDtoDAsyncNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUdeviceptr;JLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyDtoDAsyncNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jobject srcDevice, jlong ByteCount, jobject hStream)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemcpyDtoDAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'srcDevice' is null for cuMemcpyDtoDAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuMemcpyDtoDAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cuMemcpyDtoDAsync of %d bytes\n", (size_t)ByteCount);

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    CUdeviceptr nativeSrcDevice = (CUdeviceptr)getPointer(env, srcDevice);
    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemcpyDtoDAsync(nativeDstDevice, nativeSrcDevice, (size_t)ByteCount, nativeHStream);

    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyHtoAAsyncNative
 * Signature: (LCUDAWrapper/driver/CUarray;JLCUDAWrapper/Pointer;JLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyHtoAAsyncNative
  (JNIEnv *env, jclass cls, jobject dstArray, jlong dstIndex, jobject pSrc, jlong ByteCount, jobject hStream)
{
    if (dstArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstArray' is null for cuMemcpyHtoAAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (pSrc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pSrc' is null for cuMemcpyHtoAAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuMemcpyHtoAAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cuMemcpyHtoAAsync of %d bytes\n", (size_t)ByteCount);

    CUarray nativeDstArray = (CUarray)getNativePointerValue(env, dstArray);

    PointerData *pSrcPointerData = initPointerData(env, pSrc);
    if (pSrcPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemcpyHtoAAsync(nativeDstArray, (size_t)dstIndex, (void*)pSrcPointerData->getPointer(env), (size_t)ByteCount, nativeHStream);

    if (!releasePointerData(env, pSrcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpyAtoHAsyncNative
 * Signature: (LCUDAWrapper/Pointer;LCUDAWrapper/driver/CUarray;JJLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpyAtoHAsyncNative
  (JNIEnv *env, jclass cls, jobject dstHost, jobject srcArray, jlong srcIndex, jlong ByteCount, jobject hStream)
{
    if (dstHost == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstHost' is null for cuMemcpyAtoHAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'srcArray' is null for cuMemcpyAtoHAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuMemcpyAtoHAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cuMemcpyAtoH ofAsync %d bytes\n", (size_t)ByteCount);

    PointerData *dstPointerData = initPointerData(env, dstHost);
    if (dstPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    CUarray nativeSrcArray = (CUarray)getNativePointerValue(env, srcArray);

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemcpyAtoHAsync((void*)dstPointerData->getPointer(env), nativeSrcArray, (size_t)srcIndex, (size_t)ByteCount, nativeHStream);

    if (!releasePointerData(env, dstPointerData)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpy2DAsyncNative
 * Signature: (LCUDAWrapper/driver/CUDA_MEMCPY2D;LCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpy2DAsyncNative
  (JNIEnv *env, jclass cls, jobject pCopy, jobject hStream)
{
    if (pCopy == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCopy' is null for cuMemcpy2DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuMemcpy2DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cuMemcpy2DAsync\n");

    Memcpy2DData *memcpyData = initMemcpy2DData(env, pCopy);
    if (memcpyData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemcpy2DAsync(&memcpyData->memcpy2d, nativeHStream);

    if (!releaseMemcpy2DData(env, memcpyData)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemcpy3DAsyncNative
 * Signature: (LCUDAWrapper/driver/CUDA_MEMCPY3D;LCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemcpy3DAsyncNative
  (JNIEnv *env, jclass cls, jobject pCopy, jobject hStream)
{
    if (pCopy == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCopy' is null for cuMemcpy3DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuMemcpy3DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cuMemcpy3DAsync\n");


    Memcpy3DData *memcpyData = initMemcpy3DData(env, pCopy);
    if (memcpyData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemcpy3DAsync(&memcpyData->memcpy3d, nativeHStream);

    if (!releaseMemcpy3DData(env, memcpyData)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemsetD8Native
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;BJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemsetD8Native
  (JNIEnv *env, jclass cls, jobject dstDevice, jbyte uc, jlong N)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemsetD8");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemsetD8\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);

    int result = cuMemsetD8(nativeDstDevice, (unsigned char)uc, (size_t)N);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemsetD16Native
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;SJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemsetD16Native
  (JNIEnv *env, jclass cls, jobject dstDevice, jshort us, jlong N)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemsetD16");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemsetD16\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);

    int result = cuMemsetD16(nativeDstDevice, (unsigned short)us, (size_t)N);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemsetD32Native
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;IJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemsetD32Native
  (JNIEnv *env, jclass cls, jobject dstDevice, jint ui, jlong N)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemsetD32");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemsetD32\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);

    int result = cuMemsetD32(nativeDstDevice, (unsigned int)ui, (size_t)N);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemsetD2D8Native
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;JBJJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemsetD2D8Native
  (JNIEnv *env, jclass cls, jobject dstDevice, jlong dstPitch, jbyte uc, jlong Width, jlong Height)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemsetD2D8");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemsetD2D8\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);

    int result = cuMemsetD2D8(nativeDstDevice, (size_t)dstPitch, (unsigned char)uc, (size_t)Width, (size_t)Height);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemsetD2D16Native
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;JSJJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemsetD2D16Native
  (JNIEnv *env, jclass cls, jobject dstDevice, jlong dstPitch, jshort us, jlong Width, jlong Height)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemsetD2D16");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemsetD2D16\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);

    int result = cuMemsetD2D16(nativeDstDevice, (size_t)dstPitch, (unsigned short)us, (size_t)Width, (size_t)Height);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemsetD2D32Native
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;JIJJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemsetD2D32Native
  (JNIEnv *env, jclass cls, jobject dstDevice, jlong dstPitch, jint ui, jlong Width, jlong Height)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemsetD2D32");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemsetD2D32\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);

    int result = cuMemsetD2D32(nativeDstDevice, (size_t)dstPitch, (unsigned int)ui, (size_t)Width, (size_t)Height);

    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemsetD8AsyncNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;BJLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemsetD8AsyncNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jbyte uc, jlong N, jobject hStream)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemsetD8Async");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemsetD8Async\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemsetD8Async(nativeDstDevice, (unsigned char)uc, (size_t)N, nativeHStream);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemsetD16AsyncNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;SJLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemsetD16AsyncNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jshort us, jlong N, jobject hStream)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemsetD16Async");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemsetD16Async\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemsetD16Async(nativeDstDevice, (unsigned short)us, (size_t)N, nativeHStream);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemsetD32AsyncNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;IJLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemsetD32AsyncNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jint ui, jlong N, jobject hStream)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemsetD32Async");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemsetD32Async\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemsetD32Async(nativeDstDevice, (unsigned int)ui, (size_t)N, nativeHStream);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemsetD2D8AsyncNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;JBJJLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemsetD2D8AsyncNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jlong dstPitch, jbyte uc, jlong Width, jlong Height, jobject hStream)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemsetD2D8Async");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemsetD2D8Async\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemsetD2D8Async(nativeDstDevice, (size_t)dstPitch, (unsigned char)uc, (size_t)Width, (size_t)Height, nativeHStream);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemsetD2D16AsyncNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;JSJJLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemsetD2D16AsyncNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jlong dstPitch, jshort us, jlong Width, jlong Height, jobject hStream)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemsetD2D16Async");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemsetD2D16Async\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemsetD2D16Async(nativeDstDevice, (size_t)dstPitch, (unsigned short)us, (size_t)Width, (size_t)Height, nativeHStream);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemsetD2D32AsyncNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;JIJJLCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemsetD2D32AsyncNative
  (JNIEnv *env, jclass cls, jobject dstDevice, jlong dstPitch, jint ui, jlong Width, jlong Height, jobject hStream)
{
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemsetD2D32Async");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemsetD2D32Async\n");

    CUdeviceptr nativeDstDevice = (CUdeviceptr)getPointer(env, dstDevice);
    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemsetD2D32Async(nativeDstDevice, (size_t)dstPitch, (unsigned int)ui, (size_t)Width, (size_t)Height, nativeHStream);

    return result;
}





/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuLaunchKernelNative
 * Signature: (LCUDAWrapper/driver/CUfunction;IIIIIIILCUDAWrapper/driver/CUstream;LCUDAWrapper/Pointer;LCUDAWrapper/Pointer;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuLaunchKernelNative
  (JNIEnv *env, jclass cls, jobject f, jint gridDimX, jint gridDimY, jint gridDimZ, jint blockDimX, jint blockDimY, jint blockDimZ, jint sharedMemBytes, jobject hStream, jobject kernelParams, jobject extra)
{
    if (f == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'f' is null for cuLaunchKernel");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuLaunchKernel\n");

    CUfunction nativeF = (CUfunction)getNativePointerValue(env, f);
    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    // TODO: Verify if this (especially the treatment of 'extra') is correct!

    PointerData *kernelParamsPointerData = NULL;
    void **nativeKernelParams = NULL;
    if (kernelParams != NULL)
    {
        kernelParamsPointerData = initPointerData(env, kernelParams);
        if (kernelParamsPointerData == NULL)
        {
            return CUDA_INTERNAL_ERROR;
        }
        nativeKernelParams = (void**)kernelParamsPointerData->getPointer(env);
    }

    PointerData *extraPointerData = NULL;
    void **nativeExtra = NULL;
    if (extra != NULL)
    {
        extraPointerData = initPointerData(env, extra);
        if (extraPointerData == NULL)
        {
            return CUDA_INTERNAL_ERROR;
        }
        nativeExtra = (void**)extraPointerData->getPointer(env);
    }

    int result = cuLaunchKernel(
        nativeF,
        (unsigned int)gridDimX,
        (unsigned int)gridDimY,
        (unsigned int)gridDimZ,
        (unsigned int)blockDimX,
        (unsigned int)blockDimY,
        (unsigned int)blockDimZ,
        (unsigned int)sharedMemBytes,
        nativeHStream,
        nativeKernelParams,
        nativeExtra);

    if (!releasePointerData(env, kernelParamsPointerData, 0)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, extraPointerData, 0)) return CUDA_INTERNAL_ERROR;

    return result;
}







/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuFuncGetAttributeNative
 * Signature: ([IILCUDAWrapper/driver/CUfunction;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuFuncGetAttributeNative
  (JNIEnv *env, jclass cls, jintArray pi, jint attrib, jobject func)
{
    if (pi == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pi' is null for cuFuncGetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    if (func == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'func' is null for cuFuncGetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuFuncGetAttribute\n");

    int nativePi;
    CUfunction nativeFunc = (CUfunction)getNativePointerValue(env, func);
    CUfunction_attribute nativeAttrib = (CUfunction_attribute)attrib;
    int result = cuFuncGetAttribute(&nativePi, nativeAttrib, nativeFunc);
    if (!set(env, pi, 0, nativePi)) return CUDA_INTERNAL_ERROR;
    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuFuncSetBlockShapeNative
 * Signature: (LCUDAWrapper/driver/CUfunction;III)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuFuncSetBlockShapeNative
  (JNIEnv *env, jclass cls, jobject hfunc, jint x, jint y, jint z)
{
    if (hfunc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hfunc' is null for cuFuncSetBlockShape");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuFuncSetBlockShape (%d,%d,%d)\n", (int)x, (int)y, (int)z);

    CUfunction nativeHfunc = (CUfunction)getNativePointerValue(env, hfunc);
    int result = cuFuncSetBlockShape(nativeHfunc, (int)x, (int)y, (int)z);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuFuncSetSharedSizeNative
 * Signature: (LCUDAWrapper/driver/CUfunction;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuFuncSetSharedSizeNative
  (JNIEnv *env, jclass cls, jobject hfunc, jint bytes)
{
    if (hfunc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hfunc' is null for cuFuncSetSharedSize");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuFuncSetSharedSize to %d bytes\n", (unsigned int)bytes);

    CUfunction nativeHfunc = (CUfunction)getNativePointerValue(env, hfunc);
    int result = cuFuncSetSharedSize(nativeHfunc, (unsigned int)bytes);
    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuFuncSetCacheConfigNative
 * Signature: (LCUDAWrapper/driver/CUfunction;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuFuncSetCacheConfigNative
  (JNIEnv *env, jclass cls, jobject hfunc, jint config)
{
    if (hfunc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hfunc' is null for cuFuncSetCacheConfig");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuFuncSetCacheConfig\n");

    CUfunction nativeHfunc = (CUfunction)getNativePointerValue(env, hfunc);
    int result = cuFuncSetCacheConfig(nativeHfunc, (CUfunc_cache)config);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuFuncSetSharedMemConfigNative
 * Signature: (LCUDAWrapper/driver/CUfunction;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuFuncSetSharedMemConfigNative
  (JNIEnv *env, jclass cls, jobject hfunc, jint config)
{
    if (hfunc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hfunc' is null for cuFuncSetSharedMemConfig");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuFuncSetSharedMemConfig\n");

    CUfunction nativeHfunc = (CUfunction)getNativePointerValue(env, hfunc);

    int result = cuFuncSetSharedMemConfig(nativeHfunc, (CUsharedconfig)config);
    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuArrayCreateNative
 * Signature: (LCUDAWrapper/driver/CUarray;LCUDAWrapper/driver/CUDA_ARRAY_DESCRIPTOR;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuArrayCreateNative
  (JNIEnv *env, jclass cls, jobject pHandle, jobject pAllocateArray)
{
    if (pHandle == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pHandle' is null for cuArrayCreate");
        return CUDA_INTERNAL_ERROR;
    }
    if (pAllocateArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pAllocateArray' is null for cuArrayCreate");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuArrayCreate\n");

    CUarray nativePHandle;
    CUDA_ARRAY_DESCRIPTOR nativePAllocateArray = getCUDA_ARRAY_DESCRIPTOR(env, pAllocateArray);

    int result = cuArrayCreate(&nativePHandle, &nativePAllocateArray);
    setNativePointerValue(env, pHandle, (jlong)nativePHandle);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuArrayGetDescriptorNative
 * Signature: (LCUDAWrapper/driver/CUDA_ARRAY_DESCRIPTOR;LCUDAWrapper/driver/CUarray;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuArrayGetDescriptorNative
  (JNIEnv *env, jclass cls, jobject pArrayDescriptor, jobject hArray)
{
    if (pArrayDescriptor == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pArrayDescriptor' is null for cuArrayGetDescriptor");
        return CUDA_INTERNAL_ERROR;
    }
    if (hArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hArray' is null for cuArrayGetDescriptor");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuArrayGetDescriptor\n");

    CUDA_ARRAY_DESCRIPTOR nativePArrayDescriptor;
    CUarray nativeHArray = (CUarray)getNativePointerValue(env, hArray);

    int result = cuArrayGetDescriptor(&nativePArrayDescriptor, nativeHArray);

    setCUDA_ARRAY_DESCRIPTOR(env, pArrayDescriptor, nativePArrayDescriptor);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuArrayDestroyNative
 * Signature: (LCUDAWrapper/driver/CUarray;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuArrayDestroyNative
  (JNIEnv *env, jclass cls, jobject hArray)
{
    if (hArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hArray' is null for cuArrayDestroy");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuArrayDestroy\n");

    CUarray nativeHArray = (CUarray)getNativePointerValue(env, hArray);
    int result = cuArrayDestroy(nativeHArray);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuArray3DCreateNative
 * Signature: (LCUDAWrapper/driver/CUarray;LCUDAWrapper/driver/CUDA_ARRAY3D_DESCRIPTOR;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuArray3DCreateNative
  (JNIEnv *env, jclass cls, jobject pHandle, jobject pAllocateArray)
{
    if (pHandle == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pHandle' is null for cuArray3DCreate");
        return CUDA_INTERNAL_ERROR;
    }
    if (pAllocateArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pAllocateArray' is null for cuArray3DCreate");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuArray3DCreate\n");

    CUarray nativePHandle;
    CUDA_ARRAY3D_DESCRIPTOR nativePAllocateArray = getCUDA_ARRAY3D_DESCRIPTOR(env, pAllocateArray);

    int result = cuArray3DCreate(&nativePHandle, &nativePAllocateArray);
    setNativePointerValue(env, pHandle, (jlong)nativePHandle);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuArray3DGetDescriptorNative
 * Signature: (LCUDAWrapper/driver/CUDA_ARRAY3D_DESCRIPTOR;LCUDAWrapper/driver/CUarray;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuArray3DGetDescriptorNative
  (JNIEnv *env, jclass cls, jobject pArrayDescriptor, jobject hArray)
{
    if (pArrayDescriptor == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pArrayDescriptor' is null for cuArray3DGetDescriptor");
        return CUDA_INTERNAL_ERROR;
    }
    if (hArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hArray' is null for cuArray3DGetDescriptor");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuArray3DGetDescriptor\n");

    CUDA_ARRAY3D_DESCRIPTOR nativePArrayDescriptor;
    CUarray nativeHArray = (CUarray)getNativePointerValue(env, hArray);

    int result = cuArray3DGetDescriptor(&nativePArrayDescriptor, nativeHArray);

    setCUDA_ARRAY3D_DESCRIPTOR(env, pArrayDescriptor, nativePArrayDescriptor);

    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMipmappedArrayCreateNative
 * Signature: (LCUDAWrapper/driver/CUmipmappedArray;LCUDAWrapper/driver/CUDA_ARRAY3D_DESCRIPTOR;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMipmappedArrayCreateNative
  (JNIEnv *env, jclass cls, jobject pHandle, jobject pMipmappedArrayDesc, jint numMipmapLevels)
{
    if (pHandle == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pHandle' is null for cuMipmappedArrayCreate");
        return CUDA_INTERNAL_ERROR;
    }
    if (pMipmappedArrayDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pMipmappedArrayDesc' is null for cuMipmappedArrayCreate");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMipmappedArrayCreate\n");

    CUmipmappedArray nativePHandle;

    CUDA_ARRAY3D_DESCRIPTOR nativePMipmappedArrayDesc = getCUDA_ARRAY3D_DESCRIPTOR(env, pMipmappedArrayDesc);
    int result = cuMipmappedArrayCreate(&nativePHandle, &nativePMipmappedArrayDesc, (unsigned int)numMipmapLevels);

    setNativePointerValue(env, pHandle, (jlong)nativePHandle);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMipmappedArrayGetLevelNative
 * Signature: (LCUDAWrapper/driver/CUarray;LCUDAWrapper/driver/CUmipmappedArray;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMipmappedArrayGetLevelNative
  (JNIEnv *env, jclass cls, jobject pLevelArray, jobject hMipmappedArray, jint level)
{
    if (pLevelArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pLevelArray' is null for cuMipmappedArrayGetLevel");
        return CUDA_INTERNAL_ERROR;
    }
    if (hMipmappedArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hMipmappedArray' is null for cuMipmappedArrayGetLevel");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMipmappedArrayGetLevel\n");

    CUarray nativePLevelArray;
    CUmipmappedArray nativeHMipmappedArray = (CUmipmappedArray)getNativePointerValue(env, hMipmappedArray);
    int result = cuMipmappedArrayGetLevel(&nativePLevelArray, nativeHMipmappedArray, (unsigned int)level);

    setNativePointerValue(env, pLevelArray, (jlong)nativePLevelArray);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMipmappedArrayDestroyNative
 * Signature: (LCUDAWrapper/driver/CUmipmappedArray;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMipmappedArrayDestroyNative
  (JNIEnv *env, jclass cls, jobject hMipmappedArray)
{
    if (hMipmappedArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hMipmappedArray' is null for cuMipmappedArrayDestroy");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMipmappedArrayGetLevel\n");

    CUmipmappedArray nativeHMipmappedArray = (CUmipmappedArray)getNativePointerValue(env, hMipmappedArray);
    int result = cuMipmappedArrayDestroy(nativeHMipmappedArray);
    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefCreateNative
 * Signature: (LCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefCreateNative
  (JNIEnv *env, jclass cls, jobject pTexRef)
{
    if (pTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pTexRef' is null for cuTexRefCreate");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefCreate\n");

    CUtexref nativePTexRef;
    int result = cuTexRefCreate(&nativePTexRef);
    setNativePointerValue(env, pTexRef, (jlong)nativePTexRef);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefDestroyNative
 * Signature: (LCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefDestroyNative
  (JNIEnv *env, jclass cls, jobject hTexRef)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefDestroy");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefDestroy\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    int result = cuTexRefDestroy(nativeHTexRef);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefSetArrayNative
 * Signature: (LCUDAWrapper/driver/CUtexref;LCUDAWrapper/driver/CUarray;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetArrayNative
  (JNIEnv *env, jclass cls, jobject hTexRef, jobject hArray, jint Flags)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (hArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hArray' is null for cuTexRefSetArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetArray\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    CUarray nativeHArray = (CUarray)getNativePointerValue(env, hArray);

    int result = cuTexRefSetArray(nativeHTexRef, nativeHArray, (unsigned int)Flags);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefSetMipmappedArrayNative
 * Signature: (LCUDAWrapper/driver/CUtexref;LCUDAWrapper/driver/CUmipmappedArray;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetMipmappedArrayNative
  (JNIEnv *env, jclass cls, jobject hTexRef, jobject hMipmappedArray, jint Flags)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (hMipmappedArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hMipmappedArray' is null for cuTexRefSetMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetMipmappedArray\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    CUmipmappedArray nativeHMipmappedArray = (CUmipmappedArray)getNativePointerValue(env, hMipmappedArray);
    int result = cuTexRefSetMipmappedArray(nativeHTexRef, nativeHMipmappedArray, (unsigned int)Flags);
    return result;

}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefSetAddressNative
 * Signature: ([JLCUDAWrapper/driver/CUtexref;LCUDAWrapper/driver/CUdeviceptr;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetAddressNative
  (JNIEnv *env, jclass cls, jlongArray ByteOffset, jobject hTexRef, jobject dptr, jlong bytes)
{
    if (ByteOffset == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ByteOffset' is null for cuTexRefSetAddress");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetAddress");
        return CUDA_INTERNAL_ERROR;
    }
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuTexRefSetAddress");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetAddress\n");

    size_t nativeByteOffset = 0;
    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);

    CUdeviceptr nativeDptr = (CUdeviceptr)getPointer(env, dptr);
    int result = cuTexRefSetAddress(&nativeByteOffset, nativeHTexRef, nativeDptr, (size_t)bytes);

    if (!set(env, ByteOffset, 0, nativeByteOffset)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefSetFormatNative
 * Signature: (LCUDAWrapper/driver/CUtexref;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetFormatNative
  (JNIEnv *env, jclass cls, jobject hTexRef, jint fmt, jint NumPackedComponents)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetFormat");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetFormat\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    int result = cuTexRefSetFormat(nativeHTexRef, (CUarray_format)fmt, (int)NumPackedComponents);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefSetAddress2DNative
 * Signature: (LCUDAWrapper/driver/CUtexref;LCUDAWrapper/driver/CUDA_ARRAY_DESCRIPTOR;LCUDAWrapper/driver/CUdeviceptr;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetAddress2DNative
  (JNIEnv *env, jclass cls, jobject hTexRef, jobject desc, jobject dptr, jlong PitchInBytes)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetAddress2D");
        return CUDA_INTERNAL_ERROR;
    }
    if (desc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'desc' is null for cuTexRefSetAddress2D");
        return CUDA_INTERNAL_ERROR;
    }
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuTexRefSetAddress2D");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetAddress2D\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    CUDA_ARRAY_DESCRIPTOR nativeDesc = getCUDA_ARRAY_DESCRIPTOR(env, desc);
    CUdeviceptr nativeDptr = (CUdeviceptr)getPointer(env, dptr);
    int result = cuTexRefSetAddress2D(nativeHTexRef, &nativeDesc, nativeDptr, (size_t)PitchInBytes);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefSetAddressModeNative
 * Signature: (LCUDAWrapper/driver/CUtexref;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetAddressModeNative
  (JNIEnv *env, jclass cls, jobject hTexRef, jint dim, jint am)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetAddressMode");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetAddressMode\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    int result = cuTexRefSetAddressMode(nativeHTexRef, (int)dim, (CUaddress_mode)am);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefSetFilterModeNative
 * Signature: (LCUDAWrapper/driver/CUtexref;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetFilterModeNative
  (JNIEnv *env, jclass cls, jobject hTexRef, jint fm)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetFilterMode");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetFilterMode\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    int result = cuTexRefSetFilterMode(nativeHTexRef, (CUfilter_mode)fm);
    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefSetMipmapFilterModeNative
 * Signature: (LCUDAWrapper/driver/CUtexref;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetMipmapFilterModeNative
  (JNIEnv *env, jclass cls, jobject hTexRef, jint fm)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetMipmapFilterMode");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetMipmapFilterMode\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    int result = cuTexRefSetMipmapFilterMode(nativeHTexRef, (CUfilter_mode)fm);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefSetMipmapLevelBiasNative
 * Signature: (LCUDAWrapper/driver/CUtexref;F)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetMipmapLevelBiasNative
  (JNIEnv *env, jclass cls, jobject hTexRef, jfloat bias)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetMipmapLevelBias");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetMipmapLevelBias\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    int result = cuTexRefSetMipmapLevelBias(nativeHTexRef, (float)bias);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefSetMipmapLevelClampNative
 * Signature: (LCUDAWrapper/driver/CUtexref;FF)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetMipmapLevelClampNative
  (JNIEnv *env, jclass cls, jobject hTexRef, jfloat minMipmapLevelClamp, jfloat maxMipmapLevelClamp)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetMipmapLevelClamp");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetMipmapLevelClamp\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    int result = cuTexRefSetMipmapLevelClamp(nativeHTexRef, (float)minMipmapLevelClamp, (float)maxMipmapLevelClamp);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefSetMaxAnisotropyNative
 * Signature: (LCUDAWrapper/driver/CUtexref;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetMaxAnisotropyNative
  (JNIEnv *env, jclass cls, jobject hTexRef, jint maxAniso)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetMaxAnisotropy");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetMaxAnisotropy\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    int result = cuTexRefSetMaxAnisotropy(nativeHTexRef, (unsigned int)maxAniso);
    return result;
}

/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuTexRefSetBorderColorNative
* Signature: (LCUDAWrapper/driver/CUtexref;[F)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetBorderColorNative
(JNIEnv *env, jclass cls, jobject hTexRef, jfloatArray pBorderColor)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetBorderColor");
        return CUDA_INTERNAL_ERROR;
    }
    if (pBorderColor == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pBorderColor' is null for cuTexRefSetBorderColor");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetBorderColor\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    jsize length = env->GetArrayLength(pBorderColor);
    if (length != 4)
    {
        ThrowByName(env, "java/lang/IllegalArgumentException", "Parameter 'pBorderColor' must have length 4");
        return CUDA_INTERNAL_ERROR;
    }
    jfloat *nativePBorderColor = (jfloat*)env->GetPrimitiveArrayCritical(pBorderColor, NULL);
    int result = cuTexRefSetBorderColor(nativeHTexRef, nativePBorderColor);
    env->ReleasePrimitiveArrayCritical(pBorderColor, nativePBorderColor, JNI_ABORT);

    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefSetFlagsNative
 * Signature: (LCUDAWrapper/driver/CUtexref;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefSetFlagsNative
  (JNIEnv *env, jclass cls, jobject hTexRef, jint Flags)
{
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefSetFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefSetFlags\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    int result = cuTexRefSetFlags(nativeHTexRef, (unsigned int)Flags);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefGetAddressNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefGetAddressNative
  (JNIEnv *env, jclass cls, jobject pdptr, jobject hTexRef)
{
    if (pdptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pdptr' is null for cuTexRefGetAddress");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefGetAddress");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefGetAddress\n");

    CUdeviceptr nativePdptr;
    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    int result = cuTexRefGetAddress(&nativePdptr, nativeHTexRef);

    setPointer(env, pdptr, nativePdptr);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefGetArrayNative
 * Signature: (LCUDAWrapper/driver/CUarray;LCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefGetArrayNative
  (JNIEnv *env, jclass cls, jobject phArray, jobject hTexRef)
{
    if (phArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'phArray' is null for cuTexRefGetArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefGetArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefGetArray\n");

    CUarray nativePhArray;
    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);

    int result = cuTexRefGetArray(&nativePhArray, nativeHTexRef);

    setNativePointerValue(env, phArray, (jlong)nativePhArray);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefGetMipmappedArrayNative
 * Signature: (LCUDAWrapper/driver/CUmipmappedArray;LCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefGetMipmappedArrayNative
  (JNIEnv *env, jclass cls, jobject phMipmappedArray, jobject hTexRef)
{
    if (phMipmappedArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'phMipmappedArray' is null for cuTexRefGetMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefGetMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefGetMipmappedArray\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    CUmipmappedArray nativePhMipmappedArray;

    int result = cuTexRefGetMipmappedArray(&nativePhMipmappedArray, nativeHTexRef);

    setNativePointerValue(env, phMipmappedArray, (jlong)nativePhMipmappedArray);
    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefGetAddressModeNative
 * Signature: ([ILCUDAWrapper/driver/CUtexref;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefGetAddressModeNative
  (JNIEnv *env, jclass cls, jintArray pam, jobject hTexRef, jint dim)
{
    if (pam == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pam' is null for cuTexRefGetAddressMode");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefGetAddressMode");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefGetAddressMode\n");

    CUaddress_mode nativePam;
    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);

    int result = cuTexRefGetAddressMode(&nativePam, nativeHTexRef, (int)dim);

    if (!set(env, pam, 0, nativePam)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefGetFilterModeNative
 * Signature: ([ILCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefGetFilterModeNative
  (JNIEnv *env, jclass cls, jintArray pfm, jobject hTexRef)
{
    if (pfm == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pfm' is null for cuTexRefGetFilterMode");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefGetFilterMode");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefGetFilterMode\n");

    CUfilter_mode nativePfm;
    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);

    int result = cuTexRefGetFilterMode(&nativePfm, nativeHTexRef);

    if (!set(env, pfm, 0, nativePfm)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefGetFormatNative
 * Signature: ([I[ILCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefGetFormatNative
  (JNIEnv *env, jclass cls, jintArray pFormat, jintArray pNumChannels, jobject hTexRef)
{
    if (pFormat == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pFormat' is null for cuTexRefGetFormat");
        return CUDA_INTERNAL_ERROR;
    }
    if (pNumChannels == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pNumChannels' is null for cuTexRefGetFormat");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefGetFormat");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefGetFormat\n");

    CUarray_format nativePFormat;
    int nativePNumChannels;
    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);

    int result = cuTexRefGetFormat(&nativePFormat, &nativePNumChannels, nativeHTexRef);

    if (!set(env, pFormat, 0, nativePFormat)) return CUDA_INTERNAL_ERROR;
    if (!set(env, pNumChannels, 0, nativePNumChannels)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefGetMipmapFilterModeNative
 * Signature: ([ILCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefGetMipmapFilterModeNative
  (JNIEnv *env, jclass cls, jintArray pfm, jobject hTexRef)
{
    if (pfm == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pfm' is null for cuTexRefGetMipmapFilterMode");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefGetMipmapFilterMode");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefGetMipmapFilterMode\n");

    CUfilter_mode  nativePfm;
    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);

    int result = cuTexRefGetMipmapFilterMode(&nativePfm, nativeHTexRef);

    if (!set(env, pfm, 0, (jint)nativePfm)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefGetMipmapLevelBiasNative
 * Signature: ([FLCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefGetMipmapLevelBiasNative
  (JNIEnv *env, jclass cls, jfloatArray pbias, jobject hTexRef)
{
    if (pbias == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pbias' is null for cuTexRefGetMipmapLevelBias");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefGetMipmapLevelBias");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefGetMipmapLevelBias\n");

    float nativePbias;
    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);

    int result = cuTexRefGetMipmapLevelBias(&nativePbias, nativeHTexRef);

    if (!set(env, pbias, 0, (jfloat)nativePbias)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefGetMipmapLevelClampNative
 * Signature: ([F[FLCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefGetMipmapLevelClampNative
  (JNIEnv *env, jclass cls, jfloatArray pminMipmapLevelClamp, jfloatArray pmaxMipmapLevelClamp, jobject hTexRef)
{
    if (pminMipmapLevelClamp == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pminMipmapLevelClamp' is null for cuTexRefGetMipmapLevelClamp");
        return CUDA_INTERNAL_ERROR;
    }
    if (pmaxMipmapLevelClamp == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pmaxMipmapLevelClamp' is null for cuTexRefGetMipmapLevelClamp");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefGetMipmapLevelClamp");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefGetMipmapLevelClamp\n");

    float nativePminMipmapLevelClamp;
    float nativePmaxMipmapLevelClamp;
    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);

    int result = cuTexRefGetMipmapLevelClamp(&nativePminMipmapLevelClamp, &nativePmaxMipmapLevelClamp, nativeHTexRef);

    if (!set(env, pminMipmapLevelClamp, 0, (jfloat)nativePminMipmapLevelClamp)) return CUDA_INTERNAL_ERROR;
    if (!set(env, pmaxMipmapLevelClamp, 0, (jfloat)nativePmaxMipmapLevelClamp)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefGetMaxAnisotropyNative
 * Signature: ([ILCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefGetMaxAnisotropyNative
  (JNIEnv *env, jclass cls, jintArray pMaxAniso, jobject hTexRef)
{
    if (pMaxAniso == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pMaxAniso' is null for cuTexRefGetMaxAnisotropy");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefGetMaxAnisotropy");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefGetMaxAnisotropy\n");

    int nativePmaxAniso;
    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);

    int result = cuTexRefGetMaxAnisotropy(&nativePmaxAniso, nativeHTexRef);

    if (!set(env, pMaxAniso, 0, (jint)nativePmaxAniso)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuTexRefGetBorderColorNative
* Signature: ([FLCUDAWrapper/driver/CUtexref;)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefGetBorderColorNative
(JNIEnv *env, jclass cls, jfloatArray pBorderColor, jobject hTexRef)
{
    if (pBorderColor == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pBorderColor' is null for cuTexRefGetBorderColor");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefGetBorderColor");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefGetBorderColor\n");

    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);
    jsize length = env->GetArrayLength(pBorderColor);
    if (length != 4)
    {
        ThrowByName(env, "java/lang/IllegalArgumentException", "Parameter 'pBorderColor' must have length 4");
        return CUDA_INTERNAL_ERROR;
    }
    jfloat *nativePBorderColor = (jfloat*)env->GetPrimitiveArrayCritical(pBorderColor, NULL);
    int result = cuTexRefGetBorderColor(nativePBorderColor, nativeHTexRef);
    env->ReleasePrimitiveArrayCritical(pBorderColor, nativePBorderColor, 0);

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexRefGetFlagsNative
 * Signature: ([ILCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexRefGetFlagsNative
  (JNIEnv *env, jclass cls, jintArray pFlags, jobject hTexRef)
{
    if (pFlags == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pFlags' is null for cuTexRefGetFlags");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuTexRefGetFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuTexRefGetFlags\n");

    unsigned int nativePFlags;
    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);

    int result = cuTexRefGetFlags(&nativePFlags, nativeHTexRef);

    if (!set(env, pFlags, 0, nativePFlags)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuSurfRefSetArrayNative
 * Signature: (LCUDAWrapper/driver/CUsurfref;LCUDAWrapper/driver/CUarray;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuSurfRefSetArrayNative
  (JNIEnv *env, jclass cls, jobject hSurfRef, jobject hArray, jint Flags)
{
    if (hSurfRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hSurfRef' is null for cuSurfRefSetArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (hArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hArray' is null for cuSurfRefSetArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuSurfRefSetArray\n");

    CUsurfref nativeHSurfRef = (CUsurfref)getNativePointerValue(env, hSurfRef);
    CUarray nativeHArray = (CUarray)getNativePointerValue(env, hArray);

    int result = cuSurfRefSetArray(nativeHSurfRef, nativeHArray, (unsigned int)Flags);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuSurfRefGetArrayNative
 * Signature: (LCUDAWrapper/driver/CUarray;LCUDAWrapper/driver/CUsurfref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuSurfRefGetArrayNative
  (JNIEnv *env, jclass cls, jobject phArray, jobject hSurfRef)
{
    if (phArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'phArray' is null for cuSurfRefGetArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (hSurfRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hSurfRef' is null for cuSurfRefGetArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuSurfRefGetArray\n");

    CUarray nativePhArray;
    CUsurfref nativeHSurfRef = (CUsurfref)getNativePointerValue(env, hSurfRef);

    int result = cuSurfRefGetArray(&nativePhArray, nativeHSurfRef);

    setNativePointerValue(env, phArray, (jlong)nativePhArray);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexObjectCreateNative
 * Signature: (LCUDAWrapper/driver/CUtexObject;LCUDAWrapper/driver/CUDA_RESOURCE_DESC;LCUDAWrapper/driver/CUDA_TEXTURE_DESC;LCUDAWrapper/driver/CUDA_RESOURCE_VIEW_DESC;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexObjectCreateNative
  (JNIEnv *env, jclass cls, jobject pTexObject, jobject pResDesc, jobject pTexDesc, jobject pResViewDesc)
{
    if (pTexObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pTexObject' is null for cuTexObjectCreate");
        return CUDA_INTERNAL_ERROR;
    }
    if (pResDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pResDesc' is null for cuTexObjectCreate");
        return CUDA_INTERNAL_ERROR;
    }
    if (pTexDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pTexDesc' is null for cuTexObjectCreate");
        return CUDA_INTERNAL_ERROR;
    }
    // pResViewDesc may be NULL

    Logger::log(LOG_TRACE, "Executing cuTexObjectCreate\n");

    CUtexObject *nativePTexObject = NULL;
    CUDA_RESOURCE_DESC nativePResDesc = getCUDA_RESOURCE_DESC(env, pResDesc);
    CUDA_TEXTURE_DESC nativePTexDesc = getCUDA_TEXTURE_DESC(env, pTexDesc);
    CUDA_RESOURCE_VIEW_DESC nativePResViewDesc;
    CUDA_RESOURCE_VIEW_DESC *nativePResViewDescPointer = NULL;
    if (pResViewDesc != NULL)
    {
        nativePResViewDesc = getCUDA_RESOURCE_VIEW_DESC(env, pResViewDesc);
        nativePResViewDescPointer = &nativePResViewDesc;
    }

    int result = cuTexObjectCreate(nativePTexObject, &nativePResDesc, &nativePTexDesc, nativePResViewDescPointer);

    setNativePointerValue(env, pTexObject, (jlong)nativePTexObject);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexObjectDestroyNative
 * Signature: (LCUDAWrapper/driver/CUtexObject;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexObjectDestroyNative
  (JNIEnv *env, jclass cls, jobject texObject)
{
    if (texObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texObject' is null for cuTexObjectDestroy");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuTexObjectDestroy\n");

    CUtexObject nativeTexObject = (CUtexObject)getNativePointerValue(env, texObject);

    int result = cuTexObjectDestroy(nativeTexObject);

    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexObjectGetResourceDescNative
 * Signature: (LCUDAWrapper/driver/CUDA_RESOURCE_DESC;LCUDAWrapper/driver/CUtexObject;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexObjectGetResourceDescNative
  (JNIEnv *env, jclass cls, jobject pResDesc, jobject texObject)
{
    if (pResDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pResDesc' is null for cuTexObjectGetResourceDesc");
        return CUDA_INTERNAL_ERROR;
    }
    if (texObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texObject' is null for cuTexObjectGetResourceDesc");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuTexObjectGetResourceDesc\n");

    CUDA_RESOURCE_DESC nativePResDesc;
    CUtexObject nativeTexObject = (CUtexObject)getNativePointerValue(env, texObject);
    int result = cuTexObjectGetResourceDesc(&nativePResDesc, nativeTexObject);

    setCUDA_RESOURCE_DESC(env, pResDesc, nativePResDesc);

    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexObjectGetTextureDescNative
 * Signature: (LCUDAWrapper/driver/CUDA_TEXTURE_DESC;LCUDAWrapper/driver/CUtexObject;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexObjectGetTextureDescNative
  (JNIEnv *env, jclass cls, jobject pTexDesc, jobject texObject)
{
    if (pTexDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pTexDesc' is null for cuTexObjectGetTextureDesc");
        return CUDA_INTERNAL_ERROR;
    }
    if (texObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texObject' is null for cuTexObjectGetTextureDesc");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuTexObjectGetTextureDesc\n");

    CUDA_TEXTURE_DESC nativePTexDesc;
    CUtexObject nativeTexObject = (CUtexObject)getNativePointerValue(env, texObject);
    int result = cuTexObjectGetTextureDesc(&nativePTexDesc, nativeTexObject);

    setCUDA_TEXTURE_DESC(env, pTexDesc, nativePTexDesc);

    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuTexObjectGetResourceViewDescNative
 * Signature: (LCUDAWrapper/driver/CUDA_RESOURCE_VIEW_DESC;LCUDAWrapper/driver/CUtexObject;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuTexObjectGetResourceViewDescNative
  (JNIEnv *env, jclass cls, jobject pResViewDesc, jobject texObject)
{
    if (pResViewDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pResViewDesc' is null for cuTexObjectGetResourceViewDesc");
        return CUDA_INTERNAL_ERROR;
    }
    if (texObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texObject' is null for cuTexObjectGetResourceViewDesc");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuTexObjectGetResourceViewDesc\n");

    CUDA_RESOURCE_VIEW_DESC nativePResViewDesc;
    CUtexObject nativeTexObject = (CUtexObject)getNativePointerValue(env, texObject);
    int result = cuTexObjectGetResourceViewDesc(&nativePResViewDesc, nativeTexObject);

    setCUDA_RESOURCE_VIEW_DESC(env, pResViewDesc, nativePResViewDesc);

    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuSurfObjectCreateNative
 * Signature: (LCUDAWrapper/driver/CUsurfObject;LCUDAWrapper/driver/CUDA_RESOURCE_DESC;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuSurfObjectCreateNative
  (JNIEnv *env, jclass cls, jobject pSurfObject, jobject pResDesc)
{
    if (pSurfObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pSurfObject' is null for cuSurfObjectCreate");
        return CUDA_INTERNAL_ERROR;
    }
    if (pResDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pResDesc' is null for cuSurfObjectCreate");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuSurfObjectCreate\n");

    CUsurfObject *nativePSurfObject = NULL;
    CUDA_RESOURCE_DESC nativePResDesc = getCUDA_RESOURCE_DESC(env, pResDesc);

    int result = cuSurfObjectCreate(nativePSurfObject, &nativePResDesc);

    setNativePointerValue(env, pSurfObject, (jlong)nativePSurfObject);

    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuSurfObjectDestroyNative
 * Signature: (LCUDAWrapper/driver/CUsurfObject;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuSurfObjectDestroyNative
  (JNIEnv *env, jclass cls, jobject surfObject)
{
    if (surfObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pSurfObject' is null for cuSurfObjectDestroy");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuSurfObjectDestroy\n");

    CUsurfObject nativeSurfObject = (CUsurfObject)getNativePointerValue(env, surfObject);

    int result = cuSurfObjectDestroy(nativeSurfObject);

    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuSurfObjectGetResourceDescNative
 * Signature: (LCUDAWrapper/driver/CUDA_RESOURCE_DESC;LCUDAWrapper/driver/CUsurfObject;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuSurfObjectGetResourceDescNative
  (JNIEnv *env, jclass cls, jobject pResDesc, jobject surfObject)
{
    if (pResDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pResDesc' is null for cuSurfObjectGetResourceDesc");
        return CUDA_INTERNAL_ERROR;
    }
    if (surfObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'surfObject' is null for cuSurfObjectGetResourceDesc");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuSurfObjectGetResourceDesc\n");

    CUDA_RESOURCE_DESC nativePResDesc;
    CUsurfObject nativeSurfObject = (CUsurfObject)getNativePointerValue(env, surfObject);

    int result = cuSurfObjectGetResourceDesc(&nativePResDesc, nativeSurfObject);

    setCUDA_RESOURCE_DESC(env, pResDesc, nativePResDesc);

    return result;

}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuDeviceCanAccessPeerNative
 * Signature: ([ILCUDAWrapper/driver/CUdevice;LCUDAWrapper/driver/CUdevice;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDeviceCanAccessPeerNative
  (JNIEnv *env, jclass cls, jintArray canAccessPeer, jobject dev, jobject peerDev)
{
    if (dev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dev' is null for cuDeviceCanAccessPeer");
        return CUDA_INTERNAL_ERROR;
    }
    if (peerDev == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'peerDev' is null for cuDeviceCanAccessPeer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuDeviceCanAccessPeer\n");

    CUdevice nativeDev = (CUdevice)(intptr_t)getNativePointerValue(env, dev);
    CUdevice nativePeerDev = (CUdevice)(intptr_t)getNativePointerValue(env, peerDev);
    int nativeCanAccessPeer;

    int result = cuDeviceCanAccessPeer(&nativeCanAccessPeer, nativeDev, nativePeerDev);

    if (!set(env, canAccessPeer, 0, nativeCanAccessPeer)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuDeviceGetP2PAttributeNative
* Signature: ([IILCUDAWrapper/driver/CUdevice;LCUDAWrapper/driver/CUdevice;)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDeviceGetP2PAttributeNative
(JNIEnv *env, jclass cls, jintArray value, jint attrib, jobject srcDevice, jobject dstDevice)
{
    // XXX Missing function
    ThrowByName(env, "java/lang/UnsupportedOperationException", "This function is not implemented in CUDA 8.0.27");
    return CUDA_INTERNAL_ERROR;
    /*

    if (value == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'value' is null for cuDeviceGetP2PAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    if (srcDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'srcDevice' is null for cuDeviceGetP2PAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuDeviceGetP2PAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuDeviceGetP2PAttribute\n");

    int nativeValue;
    CUdevice_P2PAttribute nativeAttrib = (CUdevice_P2PAttribute)attrib;
    CUdevice nativeSrcDevice = (CUdevice)(intptr_t)getNativePointerValue(env, srcDevice);
    CUdevice nativeDstDevice = (CUdevice)(intptr_t)getNativePointerValue(env, dstDevice);

    int result = cuDeviceGetP2PAttribute(&nativeValue, nativeAttrib, nativeSrcDevice, nativeDstDevice);

    if (!set(env, value, 0, nativeValue)) return CUDA_INTERNAL_ERROR;
    return result;

    */
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxEnablePeerAccessNative
 * Signature: (LCUDAWrapper/driver/CUcontext;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxEnablePeerAccessNative
  (JNIEnv *env, jclass cls, jobject peerContext, jint Flags)
{
    if (peerContext == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'peerContext' is null for cuCtxEnablePeerAccess");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxEnablePeerAccess\n");

    CUcontext nativePeerContext = (CUcontext)getNativePointerValue(env, peerContext);
    int result = cuCtxEnablePeerAccess(nativePeerContext, (unsigned int)Flags);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxDisablePeerAccessNative
 * Signature: (LCUDAWrapper/driver/CUcontext;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxDisablePeerAccessNative
  (JNIEnv *env, jclass cls, jobject peerContext)
{
    if (peerContext == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'peerContext' is null for cuCtxDisablePeerAccess");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxDisablePeerAccess\n");

    CUcontext nativePeerContext = (CUcontext)getNativePointerValue(env, peerContext);
    int result = cuCtxDisablePeerAccess(nativePeerContext);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemPeerRegisterNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUcontext;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemPeerRegisterNative
  (JNIEnv *env, jclass cls, jobject peerPointer, jobject peerContext, jint Flags)
{
    if (peerPointer == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'peerPointer' is null for cuMemPeerRegister");
        return CUDA_INTERNAL_ERROR;
    }
    if (peerContext == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'peerContext' is null for cuMemPeerRegister");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemPeerRegister\n");

    return CUDA_SUCCESS;
    /* Removed in CUDA 4.0RC2
    CUdeviceptr nativePeerPointer = (CUdeviceptr)getPointer(env, peerPointer);
    CUcontext nativePeerContext = (CUcontext)getNativePointerValue(env, peerContext);
    int result = cuMemPeerRegister(nativePeerPointer, nativePeerContext, (unsigned int)Flags);
    return result;
    */
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemPeerUnregisterNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUcontext;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemPeerUnregisterNative
  (JNIEnv *env, jclass cls, jobject peerPointer, jobject peerContext)
{
    if (peerPointer == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'peerPointer' is null for cuMemPeerUnregister");
        return CUDA_INTERNAL_ERROR;
    }
    if (peerContext == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'peerContext' is null for cuMemPeerUnregister");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemPeerUnregister\n");

    return CUDA_SUCCESS;
    /* Removed in CUDA 4.0RC2
    CUdeviceptr nativePeerPointer = (CUdeviceptr)getPointer(env, peerPointer);
    CUcontext nativePeerContext = (CUcontext)getNativePointerValue(env, peerContext);
    int result = cuMemPeerUnregister(nativePeerPointer, nativePeerContext);
    return result;
    */
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuMemPeerGetDevicePointerNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUdeviceptr;LCUDAWrapper/driver/CUcontext;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemPeerGetDevicePointerNative
  (JNIEnv *env, jclass cls, jobject pdptr, jobject peerPointer, jobject peerContext, jint Flags)
{
    if (pdptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pdptr' is null for cuMemPeerGetDevicePointer");
        return CUDA_INTERNAL_ERROR;
    }
    if (peerPointer == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'peerPointer' is null for cuMemPeerGetDevicePointer");
        return CUDA_INTERNAL_ERROR;
    }
    if (peerContext == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'peerContext' is null for cuMemPeerGetDevicePointer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemPeerGetDevicePointer\n");

    return CUDA_SUCCESS;
    /* Removed in CUDA 4.0RC2
    CUdeviceptr nativePeerPointer = (CUdeviceptr)getPointer(env, peerPointer);
    CUcontext nativePeerContext = (CUcontext)getNativePointerValue(env, peerContext);
    CUdeviceptr nativePdptr = NULL;
    int result = cuMemPeerGetDevicePointer(&nativePdptr, nativePeerPointer, nativePeerContext, (unsigned int)Flags);
    setPointer(env, pdptr, (jlong)nativePdptr);
    return result;
    */
}















/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuParamSetSizeNative
 * Signature: (LCUDAWrapper/driver/CUfunction;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuParamSetSizeNative
  (JNIEnv *env, jclass cls, jobject hfunc, jint numbytes)
{
    if (hfunc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hfunc' is null for cuParamSetSize");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuParamSetSize\n");

    CUfunction nativeHfunc = (CUfunction)getNativePointerValue(env, hfunc);
    int result = cuParamSetSize(nativeHfunc, (unsigned int)numbytes);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuParamSetiNative
 * Signature: (LCUDAWrapper/driver/CUfunction;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuParamSetiNative
  (JNIEnv *env, jclass cls, jobject hfunc, jint offset, jint value)
{
    if (hfunc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hfunc' is null for cuParamSeti");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuParamSeti\n");

    CUfunction nativeHfunc = (CUfunction)getNativePointerValue(env, hfunc);
    int result = cuParamSeti(nativeHfunc, (int)offset, (unsigned int)value);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuParamSetfNative
 * Signature: (LCUDAWrapper/driver/CUfunction;IF)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuParamSetfNative
  (JNIEnv *env, jclass cls, jobject hfunc, jint offset, jfloat value)
{
    if (hfunc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hfunc' is null for cuParamSetf");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuParamSetf\n");

    CUfunction nativeHfunc = (CUfunction)getNativePointerValue(env, hfunc);
    int result = cuParamSetf(nativeHfunc, (int)offset, (float)value);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuParamSetvNative
 * Signature: (LCUDAWrapper/driver/CUfunction;ILCUDAWrapper/Pointer;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuParamSetvNative
  (JNIEnv *env, jclass cls, jobject hfunc, jint offset, jobject ptr, jint numbytes)
{
    if (hfunc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hfunc' is null for cuParamSetv");
        return CUDA_INTERNAL_ERROR;
    }
    if (ptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ptr' is null for cuParamSetv");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuParamSetv\n");

    CUfunction nativeHfunc = (CUfunction)getNativePointerValue(env, hfunc);

    PointerData *ptrPointerData = initPointerData(env, ptr);
    if (ptrPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cuParamSetv(nativeHfunc, (int)offset, (void*)ptrPointerData->getPointer(env), (unsigned int)numbytes);

    if (!releasePointerData(env, ptrPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuParamSetTexRefNative
 * Signature: (LCUDAWrapper/driver/CUfunction;ILCUDAWrapper/driver/CUtexref;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuParamSetTexRefNative
  (JNIEnv *env, jclass cls, jobject hfunc, jint texunit, jobject hTexRef)
{
    if (hfunc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hfunc' is null for cuParamSetTexRef");
        return CUDA_INTERNAL_ERROR;
    }
    if (hTexRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hTexRef' is null for cuParamSetTexRef");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuParamSetTexRef\n");

    CUfunction nativeHfunc = (CUfunction)getNativePointerValue(env, hfunc);
    CUtexref nativeHTexRef = (CUtexref)getNativePointerValue(env, hTexRef);

    int result = cuParamSetTexRef(nativeHfunc, (int)texunit, nativeHTexRef);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuOccupancyMaxActiveBlocksPerMultiprocessorNative
 * Signature: ([ILCUDAWrapper/driver/CUfunction;IJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuOccupancyMaxActiveBlocksPerMultiprocessorNative
  (JNIEnv *env, jclass cls, jintArray numBlocks, jobject func, jint blockSize, jlong dynamicSMemSize)
{
    if (numBlocks == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'numBlocks' is null for cuOccupancyMaxActiveBlocksPerMultiprocessor");
        return CUDA_INTERNAL_ERROR;
    }
    if (func == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'func' is null for cuOccupancyMaxActiveBlocksPerMultiprocessor");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuOccupancyMaxActiveBlocksPerMultiprocessor\n");

    CUfunction nativeFunc = (CUfunction)getNativePointerValue(env, func);

    int nativeNumBlocks = 0;
    int result = cuOccupancyMaxActiveBlocksPerMultiprocessor(&nativeNumBlocks, nativeFunc, (int)blockSize, (size_t)dynamicSMemSize);
    if (!set(env, numBlocks, 0, nativeNumBlocks)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlagsNative
* Signature: ([ILCUDAWrapper/driver/CUfunction;IJI)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlagsNative
  (JNIEnv *env, jclass cls, jintArray numBlocks, jobject func, jint blockSize, jlong dynamicSMemSize, jint flags)
{
    if (numBlocks == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'numBlocks' is null for cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags");
        return CUDA_INTERNAL_ERROR;
    }
    if (func == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'func' is null for cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags\n");

    CUfunction nativeFunc = (CUfunction)getNativePointerValue(env, func);

    int nativeNumBlocks = 0;
    int result = cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(&nativeNumBlocks, nativeFunc, (int)blockSize, (size_t)dynamicSMemSize, (unsigned int)flags);
    if (!set(env, numBlocks, 0, nativeNumBlocks)) return CUDA_INTERNAL_ERROR;
    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuOccupancyMaxPotentialBlockSizeNative
 * Signature: ([I[ILCUDAWrapper/driver/CUfunction;LCUDAWrapper/driver/CUoccupancyB2DSize;JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuOccupancyMaxPotentialBlockSizeNative
  (JNIEnv *env, jclass cls, jintArray minGridSize, jintArray minBlockSize, jobject func, jobject blockSizeToDynamicSMemSize, jlong dynamicSMemSize, jint blockSizeLimit)
{
    if (minGridSize == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'minGridSize' is null for cuOccupancyMaxPotentialBlockSize");
        return CUDA_INTERNAL_ERROR;
    }
    if (minBlockSize == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'minBlockSize' is null for cuOccupancyMaxPotentialBlockSize");
        return CUDA_INTERNAL_ERROR;
    }
    if (func == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'func' is null for cuOccupancyMaxPotentialBlockSize");
        return CUDA_INTERNAL_ERROR;
    }
    // blockSizeToDynamicSMemSize may be NULL

    Logger::log(LOG_TRACE, "Executing cuOccupancyMaxPotentialBlockSize\n");

    int nativeMinGridSize = 0;
    int nativeMinBlockSize = 0;
    CUfunction nativeFunc = (CUfunction)getNativePointerValue(env, func);
    CUoccupancyB2DSize nativeBlockSizeToDynamicSMemSize = NULL;
    if (blockSizeToDynamicSMemSize != NULL)
    {
        currentOccupancyCallback = blockSizeToDynamicSMemSize;
        currentOccupancyEnv = env;
        nativeBlockSizeToDynamicSMemSize = &CUoccupancyB2DSizeFunction;
    }
    int result = cuOccupancyMaxPotentialBlockSize(&nativeMinGridSize, &nativeMinBlockSize, nativeFunc, nativeBlockSizeToDynamicSMemSize, (size_t)dynamicSMemSize, (int)blockSizeLimit);

    if (env->ExceptionCheck())
    {
        return CUDA_INTERNAL_ERROR;
    }

    if (!set(env, minGridSize, 0, nativeMinGridSize)) return CUDA_INTERNAL_ERROR;
    if (!set(env, minBlockSize, 0, nativeMinBlockSize)) return CUDA_INTERNAL_ERROR;

    return result;
}

/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuOccupancyMaxPotentialBlockSizeWithFlagsNative
* Signature: ([I[ILCUDAWrapper/driver/CUfunction;LCUDAWrapper/driver/CUoccupancyB2DSize;JII)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuOccupancyMaxPotentialBlockSizeWithFlagsNative
  (JNIEnv *env, jclass cls, jintArray minGridSize, jintArray minBlockSize, jobject func, jobject blockSizeToDynamicSMemSize, jlong dynamicSMemSize, jint blockSizeLimit, jint flags)
{
    if (minGridSize == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'minGridSize' is null for cuOccupancyMaxPotentialBlockSizeWithFlags");
        return CUDA_INTERNAL_ERROR;
    }
    if (minBlockSize == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'minBlockSize' is null for cuOccupancyMaxPotentialBlockSizeWithFlags");
        return CUDA_INTERNAL_ERROR;
    }
    if (func == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'func' is null for cuOccupancyMaxPotentialBlockSizeWithFlags");
        return CUDA_INTERNAL_ERROR;
    }
    // blockSizeToDynamicSMemSize may be NULL

    Logger::log(LOG_TRACE, "Executing cuOccupancyMaxPotentialBlockSizeWithFlags\n");

    int nativeMinGridSize = 0;
    int nativeMinBlockSize = 0;
    CUfunction nativeFunc = (CUfunction)getNativePointerValue(env, func);
    CUoccupancyB2DSize nativeBlockSizeToDynamicSMemSize = NULL;
    if (blockSizeToDynamicSMemSize != NULL)
    {
        currentOccupancyCallback = blockSizeToDynamicSMemSize;
        currentOccupancyEnv = env;
        nativeBlockSizeToDynamicSMemSize = &CUoccupancyB2DSizeFunction;
    }
    int result = cuOccupancyMaxPotentialBlockSizeWithFlags(&nativeMinGridSize, &nativeMinBlockSize, nativeFunc, nativeBlockSizeToDynamicSMemSize, (size_t)dynamicSMemSize, (int)blockSizeLimit, (unsigned int)flags);

    if (env->ExceptionCheck())
    {
        return CUDA_INTERNAL_ERROR;
    }

    if (!set(env, minGridSize, 0, nativeMinGridSize)) return CUDA_INTERNAL_ERROR;
    if (!set(env, minBlockSize, 0, nativeMinBlockSize)) return CUDA_INTERNAL_ERROR;

    return result;

}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuLaunchNative
 * Signature: (LCUDAWrapper/driver/CUfunction;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuLaunchNative
  (JNIEnv *env, jclass cls, jobject f)
{
    if (f == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'f' is null for cuLaunch");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuLaunch\n");

    CUfunction nativeF = (CUfunction)getNativePointerValue(env, f);
    int result = cuLaunch(nativeF);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuLaunchGridNative
 * Signature: (LCUDAWrapper/driver/CUfunction;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuLaunchGridNative
  (JNIEnv *env, jclass cls, jobject f, jint grid_width, jint grid_height)
{
    if (f == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'f' is null for cuLaunchGrid");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuLaunchGrid\n");

    CUfunction nativeF = (CUfunction)getNativePointerValue(env, f);
    int result = cuLaunchGrid(nativeF, (int)grid_width, (int)grid_height);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuLaunchGridAsyncNative
 * Signature: (LCUDAWrapper/driver/CUfunction;IILCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuLaunchGridAsyncNative
  (JNIEnv *env, jclass cls, jobject f, jint grid_width, jint grid_height, jobject hStream)
{
    if (f == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'f' is null for cuLaunchGridAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuLaunchGridAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cuLaunchGridAsync\n");

    CUfunction nativeF = (CUfunction)getNativePointerValue(env, f);
    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);
    int result = cuLaunchGridAsync(nativeF, (int)grid_width, (int)grid_height, nativeHStream);
    return result;

}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuEventCreateNative
 * Signature: (LCUDAWrapper/driver/CUevent;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuEventCreateNative
  (JNIEnv *env, jclass cls, jobject phEvent, jint Flags)
{
    if (phEvent == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'phEvent' is null for cuEventCreate");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuEventCreate\n");

    CUevent nativePhEvent;
    int result = cuEventCreate(&nativePhEvent, Flags);
    setNativePointerValue(env, phEvent, (jlong)nativePhEvent);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuEventRecordNative
 * Signature: (LCUDAWrapper/driver/CUevent;LCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuEventRecordNative
  (JNIEnv *env, jclass cls, jobject hEvent, jobject hStream)
{
    if (hEvent == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hEvent' is null for cuEventRecord");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuEventRecord");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cuEventRecord\n");

    CUevent nativeHEvent = (CUevent)getNativePointerValue(env, hEvent);
    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);
    int result = cuEventRecord(nativeHEvent, nativeHStream);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuEventQueryNative
 * Signature: (LCUDAWrapper/driver/CUevent;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuEventQueryNative
  (JNIEnv *env, jclass cls, jobject hEvent)
{
    if (hEvent == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hEvent' is null for cuEventQuery");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuEventQuery\n");

    CUevent nativeHEvent = (CUevent)getNativePointerValue(env, hEvent);
    int result = cuEventQuery(nativeHEvent);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuEventSynchronizeNative
 * Signature: (LCUDAWrapper/driver/CUevent;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuEventSynchronizeNative
  (JNIEnv *env, jclass cls, jobject hEvent)
{
    if (hEvent == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hEvent' is null for cuEventSynchronize");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuEventSynchronize\n");

    CUevent nativeHEvent = (CUevent)getNativePointerValue(env, hEvent);
    int result = cuEventSynchronize(nativeHEvent);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuEventDestroyNative
 * Signature: (LCUDAWrapper/driver/CUevent;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuEventDestroyNative
  (JNIEnv *env, jclass cls, jobject hEvent)
{
    if (hEvent == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hEvent' is null for cuEventDestroy");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuEventDestroy\n");

    CUevent nativeHEvent = (CUevent)getNativePointerValue(env, hEvent);
    int result = cuEventDestroy(nativeHEvent);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuEventElapsedTimeNative
 * Signature: ([FLCUDAWrapper/driver/CUevent;LCUDAWrapper/driver/CUevent;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuEventElapsedTimeNative
  (JNIEnv *env, jclass cls, jfloatArray pMilliseconds, jobject hStart, jobject hEnd)
{
    if (pMilliseconds == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pMilliseconds' is null for cuEventElapsedTime");
        return CUDA_INTERNAL_ERROR;
    }
    if (hStart == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStart' is null for cuEventElapsedTime");
        return CUDA_INTERNAL_ERROR;
    }
    if (hEnd == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hEnd' is null for cuEventElapsedTime");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuEventElapsedTime\n");

    CUevent nativeHStart = (CUevent)getNativePointerValue(env, hStart);
    CUevent nativeHEnd   = (CUevent)getNativePointerValue(env, hEnd  );
    float nativePMilliseconds;
    int result = cuEventElapsedTime(&nativePMilliseconds, nativeHStart, nativeHEnd);
    if (!set(env, pMilliseconds, 0, nativePMilliseconds)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuStreamWaitValue32Native
* Signature: (LCUDAWrapper/driver/CUstream;LCUDAWrapper/driver/CUdeviceptr;II)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuStreamWaitValue32Native
(JNIEnv *env, jclass cls, jobject stream, jobject addr, jint value, jint flags)
{
    if (addr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'addr' is null for cuStreamWaitValue32");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuStreamWaitValue32\n");

    CUstream nativeStream = (CUstream)getNativePointerValue(env, stream);
    CUdeviceptr nativeAddr = (CUdeviceptr)getPointer(env, addr);
    cuuint32_t nativeValue = (cuuint32_t)value;
    unsigned int nativeFlags = (unsigned int)flags;

    int result = cuStreamWaitValue32(nativeStream, nativeAddr, nativeValue, nativeFlags);

    return result;
}


/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuStreamWriteValue32Native
* Signature: (LCUDAWrapper/driver/CUstream;LCUDAWrapper/driver/CUdeviceptr;II)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuStreamWriteValue32Native
(JNIEnv *env, jclass cls, jobject stream, jobject addr, jint value, jint flags)
{
    if (addr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'addr' is null for cuStreamWriteValue32");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuStreamWriteValue32\n");

    CUstream nativeStream = (CUstream)getNativePointerValue(env, stream);
    CUdeviceptr nativeAddr = (CUdeviceptr)getPointer(env, addr);
    cuuint32_t nativeValue = (cuuint32_t)value;
    unsigned int nativeFlags = (unsigned int)flags;

    int result = cuStreamWriteValue32(nativeStream, nativeAddr, nativeValue, nativeFlags);

    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuPointerGetAttributeNative
 * Signature: (LCUDAWrapper/Pointer;ILCUDAWrapper/driver/CUdeviceptr;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuPointerGetAttributeNative
  (JNIEnv *env, jclass cls, jobject data, jint attribute, jobject ptr)
{
    if (data == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'data' is null for cuPointerGetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    if (ptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ptr' is null for cuPointerGetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuPointerGetAttribute\n");

    PointerData *dataPointerData = initPointerData(env, data);
    if (dataPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    CUdeviceptr nativePtr = (CUdeviceptr)getPointer(env, ptr);

    void *dataPointer = (void*)dataPointerData->getPointer(env);
    int result = cuPointerGetAttribute(dataPointer, (CUpointer_attribute)attribute, nativePtr);

    // XXX TEST XXX
    /*
    int result = CUDA_SUCCESS;
    if (attribute == CU_POINTER_ATTRIBUTE_CONTEXT)
    {
        CUcontext *testContext = (CUcontext*)dataPointer;
        *testContext = (CUcontext)0x0000CAFE;
    }
    else if (attribute == CU_POINTER_ATTRIBUTE_MEMORY_TYPE)
    {
        unsigned int *testMemoryType = (unsigned int*)dataPointer;
        *testMemoryType = CU_MEMORYTYPE_UNIFIED;
    }
    else if (attribute == CU_POINTER_ATTRIBUTE_DEVICE_POINTER)
    {
        CUdeviceptr *testDevicePtr = (CUdeviceptr*)dataPointer;
        *testDevicePtr = nativePtr;
    }
    else if (attribute == CU_POINTER_ATTRIBUTE_HOST_POINTER)
    {
        void **testHostPtr = (void**)dataPointer;
        *testHostPtr = (void*)0x0000BABE;
    }
    */
    // TODO: For CU_POINTER_ATTRIBUTE_HOST_POINTER it might be
    // necessary (or at least desirable) to set the "buffer"
    // of the Pointer to be a DirectByteBuffer backed by the
    // host memory.

    if (!releasePointerData(env, dataPointerData, 0)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuMemPrefetchAsyncNative
* Signature: (LCUDAWrapper/driver/CUdeviceptr;JLCUDAWrapper/driver/CUdevice;LCUDAWrapper/driver/CUstream;)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemPrefetchAsyncNative
(JNIEnv *env, jclass cls, jobject devPtr, jlong count, jobject dstDevice, jobject hStream)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cuMemPrefetchAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (dstDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dstDevice' is null for cuMemPrefetchAsync");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemPrefetchAsync\n");

    CUdeviceptr nativeDevPtr = (CUdeviceptr)getPointer(env, devPtr);
    long nativeCount = (long)count;
    CUdevice nativeDstDevice = (CUdevice)(intptr_t)getNativePointerValue(env, dstDevice);
    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int result = cuMemPrefetchAsync(nativeDevPtr, nativeCount, nativeDstDevice, nativeHStream);

    return result;
}

/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuMemAdviseNative
* Signature: (LCUDAWrapper/driver/CUdeviceptr;JILCUDAWrapper/driver/CUdevice;)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemAdviseNative
(JNIEnv *env, jclass cls, jobject devPtr, jlong count, jint advice, jobject device)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cuMemAdvise");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemAdvise\n");

    CUdeviceptr nativeDevPtr = (CUdeviceptr)getPointer(env, devPtr);
    long nativeCount = (long)count;
    CUmem_advise nativeAdvice = (CUmem_advise)advice;
    CUdevice nativeDevice = (CUdevice)(intptr_t)getNativePointerValue(env, device);

    int result = cuMemAdvise(nativeDevPtr, nativeCount, nativeAdvice, nativeDevice);

    return result;
}

/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuMemRangeGetAttributeNative
* Signature: (LCUDAWrapper/Pointer;JILCUDAWrapper/driver/CUdeviceptr;J)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemRangeGetAttributeNative
(JNIEnv *env, jclass cls, jobject data, jlong dataSize, jint attribute, jobject devPtr, jlong count)
{
    if (data == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'data' is null for cuMemRangeGetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cuMemRangeGetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemRangeGetAttribute\n");


    PointerData *dataPointerData = initPointerData(env, data);
    if (dataPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    void *nativeData = (void*)dataPointerData->getPointer(env);
    size_t nativeDataSize = (size_t)dataSize;
    CUmem_range_attribute nativeAttribute = (CUmem_range_attribute)attribute;
    CUdeviceptr nativeDevPtr = (CUdeviceptr)getPointer(env, devPtr);
    size_t nativeCount = (size_t)count;

    int result = cuMemRangeGetAttribute(nativeData, nativeDataSize, nativeAttribute, nativeDevPtr, nativeCount);

    if (!releasePointerData(env, dataPointerData, 0)) return CUDA_INTERNAL_ERROR;

    return result;
}

/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuMemRangeGetAttributesNative
* Signature: ([LCUDAWrapper/Pointer;[J[IJLCUDAWrapper/driver/CUdeviceptr;J)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuMemRangeGetAttributesNative
(JNIEnv *env, jclass cls, jobjectArray data, jlongArray dataSizes, jintArray attributes, jlong numAttributes, jobject devPtr, jlong count)
{
    if (data == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'data' is null for cuMemRangeGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    if (dataSizes == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dataSizes' is null for cuMemRangeGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    if (attributes == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'attributes' is null for cuMemRangeGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cuMemRangeGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuMemRangeGetAttributes\n");

    PointerData **dataPointerDatas = new PointerData*[numAttributes];
    void **nativeDatas = new void*[numAttributes];
    for (int i = 0; i < numAttributes; i++)
    {
        jobject element = env->GetObjectArrayElement(data, i);
        if (env->ExceptionCheck())
        {
            // ArrayIndexOutOfBoundsException may be thrown
            return CUDA_INTERNAL_ERROR;
        }
        dataPointerDatas[i] = initPointerData(env, element);
        if (dataPointerDatas[i] == NULL)
        {
            return CUDA_INTERNAL_ERROR;
        }
        nativeDatas[i] = (void*)dataPointerDatas[i]->getPointer(env);
    }

    size_t *nativeDataSizes = getArrayContentsGeneric<jlongArray, jlong, size_t>(env, dataSizes);
    CUmem_range_attribute *nativeAttributes = getArrayContentsGeneric<jintArray, jint, CUmem_range_attribute>(env, attributes);
    CUdeviceptr nativeDevPtr = (CUdeviceptr)getPointer(env, devPtr);
    size_t nativeCount = (size_t)count;

    int result = cuMemRangeGetAttributes(nativeDatas, nativeDataSizes, nativeAttributes, (size_t)numAttributes, nativeDevPtr, nativeCount);

    for (int i = 0; i < numAttributes; i++)
    {
        if (!releasePointerData(env, dataPointerDatas[i], 0)) return CUDA_INTERNAL_ERROR;
    }
    delete[] dataPointerDatas;
    delete[] nativeDatas;
    delete[] nativeDataSizes;
    delete[] nativeAttributes;

    return result;

}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuPointerSetAttributeNative
 * Signature: (LCUDAWrapper/Pointer;ILCUDAWrapper/driver/CUdeviceptr;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuPointerSetAttributeNative
  (JNIEnv *env, jclass cls, jobject value, jint attribute, jobject ptr)
{
    if (value == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'value' is null for cuPointerSetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    if (ptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ptr' is null for cuPointerSetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuPointerSetAttribute\n");

    PointerData *valuePointerData = initPointerData(env, value);
    if (valuePointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    CUdeviceptr nativePtr = (CUdeviceptr)getPointer(env, ptr);

    void *valuePointer = (void*)valuePointerData->getPointer(env);
    int result = cuPointerSetAttribute(valuePointer, (CUpointer_attribute)attribute, nativePtr);

    if (!releasePointerData(env, valuePointerData, 0)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
* Class:     CUDAWrapper_driver_CUDAWrapperDriver
* Method:    cuPointerGetAttributesNative
* Signature: (I[ILCUDAWrapper/Pointer;LCUDAWrapper/driver/CUdeviceptr;)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuPointerGetAttributesNative
  (JNIEnv *env, jclass cls, jint numAttributes, jintArray attributes, jobject data, jobject ptr)
{
    if (attributes == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'attributes' is null for cuPointerGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    if (data == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'data' is null for cuPointerGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    if (ptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ptr' is null for cuPointerGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuPointerGetAttributes\n");

    PointerData *dataPointerData = initPointerData(env, data);
    if (dataPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    CUdeviceptr nativePtr = (CUdeviceptr)getPointer(env, ptr);

    void **dataPointer = (void**)dataPointerData->getPointer(env);
    int actualNumAttributes = 0;
    CUpointer_attribute* nativeAttributes = getArrayContentsGeneric<jintArray, jint, CUpointer_attribute>(env, attributes, &actualNumAttributes);
    unsigned int usedNumAttributes = numAttributes < actualNumAttributes ? numAttributes : actualNumAttributes;
    int result = cuPointerGetAttributes(usedNumAttributes, nativeAttributes, dataPointer, nativePtr);
    delete[] nativeAttributes;

    if (!releasePointerData(env, dataPointerData, 0)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuStreamCreateNative
 * Signature: (LCUDAWrapper/driver/CUstream;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuStreamCreateNative
  (JNIEnv *env, jclass cls, jobject phStream, jint Flags)
{
    if (phStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'phStream' is null for cuStreamCreate");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuStreamCreate\n");

    CUstream nativePhStream;
    int result = cuStreamCreate(&nativePhStream, Flags);
    setNativePointerValue(env, phStream, (jlong)nativePhStream);

    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuStreamCreateWithPriorityNative
 * Signature: (LCUDAWrapper/driver/CUstream;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuStreamCreateWithPriorityNative
  (JNIEnv *env, jclass cls, jobject phStream, jint flags, jint priority)
{
    if (phStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'phStream' is null for cuStreamCreateWithPriority");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuStreamCreateWithPriority\n");

    CUstream nativePhStream;
    int result = cuStreamCreateWithPriority(&nativePhStream, (unsigned int)flags, (int)priority);
    setNativePointerValue(env, phStream, (jlong)nativePhStream);

    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuStreamGetPriorityNative
 * Signature: (LCUDAWrapper/driver/CUstream;[I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuStreamGetPriorityNative
  (JNIEnv *env, jclass cls, jobject hStream, jintArray priority)
{
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuStreamGetPriority");
        return CUDA_INTERNAL_ERROR;
    }
    if (priority == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'priority' is null for cuStreamGetPriority");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuStreamGetPriority\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);
    int nativePriority;
    int result = cuStreamGetPriority(nativeHStream, &nativePriority);
    if (!set(env, priority, 0, nativePriority)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuStreamGetFlagsNative
 * Signature: (LCUDAWrapper/driver/CUstream;[I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuStreamGetFlagsNative
  (JNIEnv *env, jclass cls, jobject hStream, jintArray flags)
{
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuStreamGetFlags");
        return CUDA_INTERNAL_ERROR;
    }
    if (flags == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'flags' is null for cuStreamGetFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuStreamGetFlags\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);
    unsigned int nativeFlags;
    int result = cuStreamGetFlags(nativeHStream, &nativeFlags);
    if (!set(env, flags, 0, nativeFlags)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuStreamWaitEventNative
 * Signature: (LCUDAWrapper/driver/CUstream;LCUDAWrapper/driver/CUevent;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuStreamWaitEventNative
  (JNIEnv *env, jclass cls, jobject hStream, jobject hEvent, jint Flags)
{
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuStreamWaitEvent");
        return CUDA_INTERNAL_ERROR;
    }
    */
    if (hEvent == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hEvent' is null for cuStreamWaitEvent");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuStreamWaitEvent\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);
    CUevent nativeHEvent = (CUevent)getNativePointerValue(env, hEvent);
    int result = cuStreamWaitEvent(nativeHStream, nativeHEvent, (unsigned int)Flags);

    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuStreamAddCallbackNative
 * Signature: (LCUDAWrapper/driver/CUstream;LCUDAWrapper/driver/CUstreamCallback;Ljava/lang/Object;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuStreamAddCallbackNative
  (JNIEnv *env, jclass cls, jobject hStream, jobject callback, jobject userData, jint flags)
{
    // hStream may be null
    if (callback == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'callback' is null for cuStreamAddCallback");
        return CUDA_INTERNAL_ERROR;
    }
    // userData may be null

    Logger::log(LOG_TRACE, "Executing cuStreamAddCallback\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    CallbackInfo *callbackInfo = NULL;
    void* nativeUserData = NULL;

    callbackInfo = initCallbackInfo(env, hStream, callback, userData);
    if (callbackInfo == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    nativeUserData = (void*)callbackInfo;

    int result = cuStreamAddCallback(nativeHStream, cuStreamAddCallback_NativeCallback, nativeUserData, (unsigned int)flags);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuStreamAttachMemAsyncNative
 * Signature: (LCUDAWrapper/driver/CUstream;LCUDAWrapper/driver/CUdeviceptr;JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuStreamAttachMemAsyncNative
  (JNIEnv *env, jclass cls, jobject hStream, jobject dptr, jlong length, jint flags)
{
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuStreamAttachMemAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuStreamAttachMemAsync");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuStreamAttachMemAsync\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);
    CUdeviceptr nativeDptr = (CUdeviceptr)getPointer(env, dptr);

    int result = cuStreamAttachMemAsync(nativeHStream, nativeDptr, (size_t)length, (unsigned int)flags);

    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuStreamQueryNative
 * Signature: (LCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuStreamQueryNative
  (JNIEnv *env, jclass cls, jobject hStream)
{
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuStreamQuery");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cuStreamQuery\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);
    int result = cuStreamQuery(nativeHStream);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuStreamSynchronizeNative
 * Signature: (LCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuStreamSynchronizeNative
  (JNIEnv *env, jclass cls, jobject hStream)
{
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuStreamSynchronize");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cuStreamSynchronize\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);
    int result = cuStreamSynchronize(nativeHStream);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuStreamDestroyNative
 * Signature: (LCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuStreamDestroyNative
  (JNIEnv *env, jclass cls, jobject hStream)
{
    /* May be null
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cuStreamDestroy");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cuStreamDestroy\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);
    int result = cuStreamDestroy(nativeHStream);
    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGLInitNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGLInitNative
  (JNIEnv *env, jclass cls)
{
    Logger::log(LOG_TRACE, "Executing cuGLInit\n");

    return cuGLInit();
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuDriverGetVersionNative
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuDriverGetVersionNative
  (JNIEnv *env, jclass cls, jintArray driverVersion)
{
    /* May be null
    if (driverVersion == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'driverVersion' is null for cuDriverGetVersion");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cuDriverGetVersion\n");

    if (driverVersion == NULL)
    {
        return CUDA_ERROR_INVALID_VALUE;
    }
    int nativeDriverVersion;
    int result = cuDriverGetVersion(&nativeDriverVersion);
    if (!set(env, driverVersion, 0, nativeDriverVersion)) return CUDA_INTERNAL_ERROR;
    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGLCtxCreateNative
 * Signature: (LCUDAWrapper/driver/CUcontext;ILCUDAWrapper/driver/CUdevice;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGLCtxCreateNative
  (JNIEnv *env, jclass cls, jobject pCtx, jint Flags, jobject device)
{
    if (pCtx == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCtx' is null for cuGLCtxCreate");
        return CUDA_INTERNAL_ERROR;
    }
    if (device == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'device' is null for cuGLCtxCreate");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuGLCtxCreate\n");

    CUdevice nativeDevice = (CUdevice)(intptr_t)getNativePointerValue(env, device);
    CUcontext nativePCtx;
    int result = cuGLCtxCreate(&nativePCtx, (unsigned int)Flags, nativeDevice);
    setNativePointerValue(env, pCtx, (jlong)nativePCtx);

    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGLGetDevicesNative
 * Signature: ([I[LCUDAWrapper/driver/CUdevice;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGLGetDevicesNative
  (JNIEnv *env, jclass cls, jintArray pCudaDeviceCount, jobjectArray pCudaDevices, jint cudaDeviceCount, jint deviceList)
{
    if (pCudaDeviceCount == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCudaDeviceCount' is null for cuGLGetDevices");
        return CUDA_INTERNAL_ERROR;
    }
    if (pCudaDevices == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCudaDevices' is null for cuGLGetDevices");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuGLGetDevices\n");

    CUdevice *nativePCudaDevices = new CUdevice[(unsigned int)cudaDeviceCount];
    unsigned int nativePCudaDeviceCount = 0;

    int result = cuGLGetDevices(&nativePCudaDeviceCount, nativePCudaDevices, (unsigned int)cudaDeviceCount, (CUGLDeviceList)deviceList);

    int len = env->GetArrayLength(pCudaDevices);
    for (unsigned int i=0; i<nativePCudaDeviceCount; i++)
    {
        jobject device = env->GetObjectArrayElement(pCudaDevices, i);
        if (device != NULL)
        {
            setNativePointerValue(env, device, (jlong)nativePCudaDevices[i]);
        }
        else
        {
            device = env->NewObject(CUdevice_class, CUdevice_constructor);
            setNativePointerValue(env, device, (jlong)nativePCudaDevices[i]);
            env->SetObjectArrayElement(pCudaDevices, i, device);
        }
    }
    delete[] nativePCudaDevices;

    if (!set(env, pCudaDeviceCount, 0, (jint)nativePCudaDeviceCount)) return CUDA_INTERNAL_ERROR;

    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGraphicsGLRegisterBufferNative
 * Signature: (LCUDAWrapper/driver/CUgraphicsResource;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGraphicsGLRegisterBufferNative
  (JNIEnv *env, jclass cls, jobject pCudaResource, jint buffer, jint Flags)
{
    if (pCudaResource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCudaResource' is null for cuGraphicsGLRegisterBuffer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuGraphicsGLRegisterBuffer\n");

    CUgraphicsResource nativePCudaResource;
    int result = cuGraphicsGLRegisterBuffer(&nativePCudaResource, (GLuint)buffer, (unsigned int)Flags);
    setNativePointerValue(env, pCudaResource, (jlong)nativePCudaResource);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGraphicsGLRegisterImageNative
 * Signature: (LCUDAWrapper/driver/CUgraphicsResource;III)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGraphicsGLRegisterImageNative
  (JNIEnv *env, jclass cls, jobject pCudaResource, jint image, jint target, jint Flags)
{
    if (pCudaResource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCudaResource' is null for cuGraphicsGLRegisterImage");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuGraphicsGLRegisterImage\n");

    CUgraphicsResource nativePCudaResource;
    int result = cuGraphicsGLRegisterImage(&nativePCudaResource, (GLuint)image, (GLenum)target, (unsigned int)Flags);
    setNativePointerValue(env, pCudaResource, (jlong)nativePCudaResource);
    return result;

}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGLRegisterBufferObjectNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGLRegisterBufferObjectNative
  (JNIEnv *env, jclass cls, jint bufferobj)
{
    Logger::log(LOG_TRACE, "Executing cuGLRegisterBufferObject\n");

    return cuGLRegisterBufferObject((GLuint)bufferobj);
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGLMapBufferObjectNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;[JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGLMapBufferObjectNative
  (JNIEnv *env, jclass cls, jobject dptr, jlongArray size, jint bufferobj)
{
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuGLMapBufferObject");
        return CUDA_INTERNAL_ERROR;
    }
    if (size == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'size' is null for cuGLMapBufferObject");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuGLMapBufferObject\n");

    CUdeviceptr nativeDptr;
    size_t nativeSize;
    int result = cuGLMapBufferObject(&nativeDptr, &nativeSize, (GLuint)bufferobj);
    setPointer(env, dptr, (jlong)nativeDptr);
    if (!set(env, size, 0, nativeSize)) return CUDA_INTERNAL_ERROR;

    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGLUnmapBufferObjectNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGLUnmapBufferObjectNative
  (JNIEnv *env, jclass cls, jint bufferobj)
{
    Logger::log(LOG_TRACE, "Executing cuGLUnmapBufferObject\n");

    return cuGLUnmapBufferObject((GLuint)bufferobj);
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGLUnregisterBufferObjectNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGLUnregisterBufferObjectNative
  (JNIEnv *env, jclass cls, jint bufferobj)
{
    Logger::log(LOG_TRACE, "Executing cuGLUnregisterBufferObject\n");

    return cuGLUnregisterBufferObject((GLuint)bufferobj);
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGLSetBufferObjectMapFlagsNative
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGLSetBufferObjectMapFlagsNative
  (JNIEnv *env, jclass cls, jint buffer, jint Flags)
{
    Logger::log(LOG_TRACE, "Executing cuGLSetBufferObjectMapFlags\n");

    return cuGLSetBufferObjectMapFlags((GLuint)buffer, (unsigned int)Flags);
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGLMapBufferObjectAsyncNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;[JILCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGLMapBufferObjectAsyncNative
  (JNIEnv *env, jclass cls, jobject dptr, jlongArray size, jint bufferobj, jobject hStream)
{
    if (dptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dptr' is null for cuGLMapBufferObjectAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (size == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'size' is null for cuGLMapBufferObjectAsync");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuGLMapBufferObjectAsync\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    CUdeviceptr nativeDptr;
    size_t nativeSize;
    int result = cuGLMapBufferObjectAsync(&nativeDptr, &nativeSize, (GLuint)bufferobj, nativeHStream);
    setPointer(env, dptr, (jlong)nativeDptr);
    if (!set(env, size, 0, nativeSize)) return CUDA_INTERNAL_ERROR;

    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGLUnmapBufferObjectAsyncNative
 * Signature: (ILCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGLUnmapBufferObjectAsyncNative
  (JNIEnv *env, jclass cls, jint bufferobj, jobject hStream)
{
    Logger::log(LOG_TRACE, "Executing cuGLUnmapBufferObjectAsync\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);
    return cuGLUnmapBufferObjectAsync((GLuint)bufferobj, nativeHStream);
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGraphicsUnregisterResourceNative
 * Signature: (LCUDAWrapper/driver/CUgraphicsResource;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGraphicsUnregisterResourceNative
  (JNIEnv *env, jclass cls, jobject resource)
{
    if (resource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resource' is null for cuGraphicsUnregisterResource");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cuGraphicsUnregisterResource\n");

    CUgraphicsResource nativeResource = (CUgraphicsResource)getNativePointerValue(env, resource);
    int result = cuGraphicsUnregisterResource(nativeResource);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGraphicsSubResourceGetMappedArrayNative
 * Signature: (LCUDAWrapper/driver/CUarray;LCUDAWrapper/driver/CUgraphicsResource;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGraphicsSubResourceGetMappedArrayNative
  (JNIEnv *env, jclass cls, jobject pArray, jobject resource, jint arrayIndex, jint mipLevel)
{
    if (pArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pArray' is null for cuGraphicsSubResourceGetMappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (resource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resource' is null for cuGraphicsSubResourceGetMappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuGraphicsSubResourceGetMappedArray\n");

    CUgraphicsResource nativeResource = (CUgraphicsResource)getNativePointerValue(env, resource);
    CUarray nativePArray = NULL;
    int result = cuGraphicsSubResourceGetMappedArray(&nativePArray, nativeResource, (unsigned int)arrayIndex, (unsigned int)mipLevel);
    setNativePointerValue(env, pArray, (jlong)nativePArray);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGraphicsResourceGetMappedMipmappedArrayNative
 * Signature: (LCUDAWrapper/driver/CUmipmappedArray;LCUDAWrapper/driver/CUgraphicsResource;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGraphicsResourceGetMappedMipmappedArrayNative
  (JNIEnv *env, jclass cls, jobject pMipmappedArray, jobject resource)
{
    if (pMipmappedArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pMipmappedArray' is null for cuGraphicsResourceGetMappedMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (resource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resource' is null for cuGraphicsResourceGetMappedMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuGraphicsResourceGetMappedMipmappedArray\n");

    CUgraphicsResource nativeResource = (CUgraphicsResource)getNativePointerValue(env, resource);
    CUmipmappedArray nativePMipmappedArray = NULL;
    int result = cuGraphicsResourceGetMappedMipmappedArray(&nativePMipmappedArray, nativeResource);
    setNativePointerValue(env, pMipmappedArray, (jlong)nativePMipmappedArray);
    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGraphicsResourceGetMappedPointerNative
 * Signature: (LCUDAWrapper/driver/CUdeviceptr;[JLCUDAWrapper/driver/CUgraphicsResource;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGraphicsResourceGetMappedPointerNative
  (JNIEnv *env, jclass cls, jobject pDevPtr, jlongArray pSize, jobject resource)
{
    if (pDevPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pDevPtr' is null for cuGraphicsResourceGetMappedPointer");
        return CUDA_INTERNAL_ERROR;
    }
    if (pSize == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pSize' is null for cuGraphicsResourceGetMappedPointer");
        return CUDA_INTERNAL_ERROR;
    }
    if (resource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resource' is null for cuGraphicsResourceGetMappedPointer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuGraphicsResourceGetMappedPointer\n");

    CUgraphicsResource nativeResource = (CUgraphicsResource)getNativePointerValue(env, resource);
    CUdeviceptr nativePointer = (CUdeviceptr)NULL;
    size_t nativeSize = 0;
    int result = cuGraphicsResourceGetMappedPointer(&nativePointer, &nativeSize, nativeResource);
    setPointer(env, pDevPtr, (jlong)nativePointer);
    if (!set(env, pSize, 0, nativeSize)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGraphicsResourceSetMapFlagsNative
 * Signature: (LCUDAWrapper/driver/CUgraphicsResource;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGraphicsResourceSetMapFlagsNative
  (JNIEnv *env, jclass cls, jobject resource, jint flags)
{
    if (resource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resource' is null for cuGraphicsResourceSetMapFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuGraphicsResourceSetMapFlags\n");

    CUgraphicsResource nativeResource = (CUgraphicsResource)getNativePointerValue(env, resource);
    int result = cuGraphicsResourceSetMapFlags(nativeResource, (unsigned int)flags);
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGraphicsMapResourcesNative
 * Signature: (I[LCUDAWrapper/driver/CUgraphicsResource;LCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGraphicsMapResourcesNative
  (JNIEnv *env, jclass cls, jint count, jobjectArray resources, jobject hStream)
{
    if (resources == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resources' is null for cuGraphicsMapResources");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuGraphicsMapResources\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int len = env->GetArrayLength(resources);
    CUgraphicsResource *nativeResources = new CUgraphicsResource[len];
    for (int i=0; i<len; i++)
    {
        jobject resource = env->GetObjectArrayElement(resources, i);
        if (resource != NULL)
        {
            CUgraphicsResource nativeResource = (CUgraphicsResource)getNativePointerValue(env, resource);
            nativeResources[i] = nativeResource;
        }
    }

    int result = cuGraphicsMapResources((unsigned int)count, nativeResources, nativeHStream);
    delete[] nativeResources;
    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuGraphicsUnmapResourcesNative
 * Signature: (I[LCUDAWrapper/driver/CUgraphicsResource;LCUDAWrapper/driver/CUstream;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuGraphicsUnmapResourcesNative
  (JNIEnv *env, jclass cls, jint count, jobjectArray resources, jobject hStream)
{
    if (resources == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resources' is null for cuGraphicsUnmapResources");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuGraphicsUnmapResources\n");

    CUstream nativeHStream = (CUstream)getNativePointerValue(env, hStream);

    int len = env->GetArrayLength(resources);
    CUgraphicsResource *nativeResources = new CUgraphicsResource[len];
    for (int i=0; i<len; i++)
    {
        jobject resource = env->GetObjectArrayElement(resources, i);
        if (resource != NULL)
        {
            CUgraphicsResource nativeResource = (CUgraphicsResource)getNativePointerValue(env, resource);
            nativeResources[i] = nativeResource;
        }
    }

    int result = cuGraphicsUnmapResources((unsigned int)count, nativeResources, nativeHStream);
    delete[] nativeResources;
    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxSetLimitNative
 * Signature: (IJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxSetLimitNative
  (JNIEnv *env, jclass cls, jint limit, jlong value)
{
    Logger::log(LOG_TRACE, "Executing cuCtxSetLimit\n");

    CUlimit nativeLimit = (CUlimit)limit;
    size_t nativeValue = (size_t)value;

    return cuCtxSetLimit(nativeLimit, nativeValue);
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxGetCacheConfigNative
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxGetCacheConfigNative
  (JNIEnv *env, jclass cls, jintArray config)
{
    if (config == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'config' is null for cuCtxGetCacheConfig");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxGetCacheConfig\n");

    CUfunc_cache nativeConfig;
    int result = cuCtxGetCacheConfig(&nativeConfig);

    if (!set(env, config, 0, (int)nativeConfig)) return CUDA_INTERNAL_ERROR;

    return result;
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxSetCacheConfigNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxSetCacheConfigNative
  (JNIEnv *env, jclass cls, jint config)
{
    Logger::log(LOG_TRACE, "Executing cuCtxSetCacheConfig\n");

    CUfunc_cache nativeConfig = (CUfunc_cache)config;

    return cuCtxSetCacheConfig(nativeConfig);
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxGetSharedMemConfigNative
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxGetSharedMemConfigNative
  (JNIEnv *env, jclass cls, jintArray pConfig)
{
    if (pConfig == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pConfig' is null for cuCtxGetSharedMemConfig");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxGetSharedMemConfig\n");

    CUsharedconfig nativeConfig = CU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE;
    int result = cuCtxGetSharedMemConfig(&nativeConfig);

    if (!set(env, pConfig, 0, (int)nativeConfig)) return CUDA_INTERNAL_ERROR;

    return result;

}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxSetSharedMemConfigNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxSetSharedMemConfigNative
  (JNIEnv *env, jclass cls, jint config)
{
    Logger::log(LOG_TRACE, "Executing cuCtxSetSharedMemConfig\n");

    CUsharedconfig nativeConfig = (CUsharedconfig)config;

    int result = cuCtxSetSharedMemConfig(nativeConfig);
    return result;
}




/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxGetApiVersionNative
 * Signature: (LCUDAWrapper/driver/CUcontext;[I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxGetApiVersionNative
  (JNIEnv *env, jclass cls, jobject ctx, jintArray version)
{
    if (ctx == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ctx' is null for cuCtxGetApiVersion");
        return CUDA_INTERNAL_ERROR;
    }
    if (version == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'version' is null for cuCtxGetApiVersion");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxGetApiVersion\n");

    CUcontext nativeCtx = (CUcontext)getNativePointerValue(env, ctx);
    unsigned int nativeVersion;
    int result = cuCtxGetApiVersion(nativeCtx, &nativeVersion);

    if (!set(env, version, 0, (int)nativeVersion)) return CUDA_INTERNAL_ERROR;

    return result;
}


/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxGetStreamPriorityRangeNative
 * Signature: ([I[I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxGetStreamPriorityRangeNative
  (JNIEnv *env, jclass cls, jintArray leastPriority, jintArray greatestPriority)
{
    if (leastPriority == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'leastPriority' is null for cuCtxGetStreamPriorityRange");
        return CUDA_INTERNAL_ERROR;
    }
    if (greatestPriority == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'greatestPriority' is null for cuCtxGetStreamPriorityRange");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxGetStreamPriorityRange\n");

    int nativeLeastPriority;
    int nativeGreatestPriority;
    int result = cuCtxGetStreamPriorityRange(&nativeLeastPriority, &nativeGreatestPriority);

    if (!set(env, leastPriority, 0, nativeLeastPriority)) return CUDA_INTERNAL_ERROR;
    if (!set(env, greatestPriority, 0, nativeGreatestPriority)) return CUDA_INTERNAL_ERROR;

    return result;
}



/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuCtxGetLimitNative
 * Signature: ([JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuCtxGetLimitNative
  (JNIEnv *env, jclass cls, jlongArray pValue, jint limit)
{
    if (pValue == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pValue' is null for cuCtxGetLimit");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuCtxGetLimit\n");

    size_t nativePvalue = 0;
    CUlimit nativeLimit = (CUlimit)limit;

    int result = cuCtxGetLimit(&nativePvalue, nativeLimit);
    if (!set(env, pValue, 0, nativePvalue)) return CUDA_INTERNAL_ERROR;
    return result;
}






/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuProfilerInitializeNative
 * Signature: (Ljava/lang/String;Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuProfilerInitializeNative
  (JNIEnv *env, jclass cls, jstring configFile, jstring outputFile, jint outputMode)
{
    if (configFile == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'configFile' is null for cuProfilerInitialize");
        return CUDA_INTERNAL_ERROR;
    }
    if (outputFile == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'outputFile' is null for cuProfilerInitialize");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cuProfilerInitialize\n");

    char *nativeConfigFile = convertString(env, configFile);
    if (nativeConfigFile == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    char *nativeOutputFile = convertString(env, outputFile);
    if (nativeOutputFile == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cuProfilerInitialize(nativeConfigFile, nativeOutputFile, (CUoutput_mode)outputMode);

    delete[] nativeConfigFile;
    delete[] nativeOutputFile;

    return result;

}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuProfilerStartNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuProfilerStartNative
  (JNIEnv *env, jclass cls)
{
    Logger::log(LOG_TRACE, "Executing cuProfilerStart\n");
    return cuProfilerStart();
}

/*
 * Class:     CUDAWrapper_driver_CUDAWrapperDriver
 * Method:    cuProfilerStopNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_driver_CUDAWrapperDriver_cuProfilerStopNative
  (JNIEnv *env, jclass cls)
{
    Logger::log(LOG_TRACE, "Executing cuProfilerStop\n");
    return cuProfilerStop();
}


