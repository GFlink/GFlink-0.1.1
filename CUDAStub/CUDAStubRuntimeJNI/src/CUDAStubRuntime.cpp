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

#include "CUDAStubRuntime.hpp"

#include <cstring>
#include "CUDAStubRuntime_common.hpp"

jfieldID cudaDeviceProp_name; // byte[256]
jfieldID cudaDeviceProp_totalGlobalMem; // size_t
jfieldID cudaDeviceProp_sharedMemPerBlock; // size_t
jfieldID cudaDeviceProp_regsPerBlock; // int
jfieldID cudaDeviceProp_warpSize; // int
jfieldID cudaDeviceProp_memPitch; // size_t
jfieldID cudaDeviceProp_maxThreadsPerBlock; // int
jfieldID cudaDeviceProp_maxThreadsDim; // int[3]
jfieldID cudaDeviceProp_maxGridSize; // int[3]
jfieldID cudaDeviceProp_clockRate; // int
jfieldID cudaDeviceProp_totalConstMem; // size_t
jfieldID cudaDeviceProp_major; // int
jfieldID cudaDeviceProp_minor; // int
jfieldID cudaDeviceProp_textureAlignment; // size_t
jfieldID cudaDeviceProp_texturePitchAlignment; // size_t
jfieldID cudaDeviceProp_deviceOverlap; // int
jfieldID cudaDeviceProp_multiProcessorCount; // int
jfieldID cudaDeviceProp_kernelExecTimeoutEnabled;  // int
jfieldID cudaDeviceProp_integrated;  // int
jfieldID cudaDeviceProp_canMapHostMemory;  // int
jfieldID cudaDeviceProp_computeMode;  // int
jfieldID cudaDeviceProp_maxTexture1D;  // int
jfieldID cudaDeviceProp_maxTexture1DMipmap;  // int
jfieldID cudaDeviceProp_maxTexture1DLinear;  // int
jfieldID cudaDeviceProp_maxTexture2D; // int[2]
jfieldID cudaDeviceProp_maxTexture2DMipmap; // int[2]
jfieldID cudaDeviceProp_maxTexture2DLinear; // int[2]
jfieldID cudaDeviceProp_maxTexture2DGather; // int[2]
jfieldID cudaDeviceProp_maxTexture3D; // int[3]
jfieldID cudaDeviceProp_maxTexture3DAlt; // int[3]
jfieldID cudaDeviceProp_maxTextureCubemap; // int
jfieldID cudaDeviceProp_maxTexture1DLayered; // int[2]
jfieldID cudaDeviceProp_maxTexture2DLayered; // int[3]
jfieldID cudaDeviceProp_maxTextureCubemapLayered; // int[2]
jfieldID cudaDeviceProp_maxSurface1D; // int
jfieldID cudaDeviceProp_maxSurface2D; // int[2]
jfieldID cudaDeviceProp_maxSurface3D; // int[3]
jfieldID cudaDeviceProp_maxSurface1DLayered; // int[2]
jfieldID cudaDeviceProp_maxSurface2DLayered; // int[3]
jfieldID cudaDeviceProp_maxSurfaceCubemap; // int
jfieldID cudaDeviceProp_maxSurfaceCubemapLayered; // int[2]
jfieldID cudaDeviceProp_surfaceAlignment; // size_t
jfieldID cudaDeviceProp_concurrentKernels;  // int
jfieldID cudaDeviceProp_ECCEnabled; // int
jfieldID cudaDeviceProp_pciBusID; // int
jfieldID cudaDeviceProp_pciDeviceID; // int
jfieldID cudaDeviceProp_pciDomainID; // int
jfieldID cudaDeviceProp_tccDriver; // int
jfieldID cudaDeviceProp_asyncEngineCount; // int
jfieldID cudaDeviceProp_unifiedAddressing; // int
jfieldID cudaDeviceProp_memoryClockRate; // int
jfieldID cudaDeviceProp_memoryBusWidth; // int
jfieldID cudaDeviceProp_l2CacheSize; // int
jfieldID cudaDeviceProp_maxThreadsPerMultiProcessor; // int
jfieldID cudaDeviceProp_globalL1CacheSupported; // int
jfieldID cudaDeviceProp_localL1CacheSupported; // int
jfieldID cudaDeviceProp_sharedMemPerMultiprocessor; // size_t
jfieldID cudaDeviceProp_regsPerMultiprocessor; // int
jfieldID cudaDeviceProp_managedMemory; // int
jfieldID cudaDeviceProp_isMultiGpuBoard; // int
jfieldID cudaDeviceProp_multiGpuBoardGroupID; // int
jfieldID cudaDeviceProp_hostNativeAtomicSupported; // int
jfieldID cudaDeviceProp_singleToDoublePrecisionPerfRatio; // int
jfieldID cudaDeviceProp_pageableMemoryAccess; // int
jfieldID cudaDeviceProp_concurrentManagedAccess; // int

jfieldID cudaPitchedPtr_ptr; // CUDAWrapper.Pointer
jfieldID cudaPitchedPtr_pitch; // size_t
jfieldID cudaPitchedPtr_xsize; // size_t
jfieldID cudaPitchedPtr_ysize; // size_t

jfieldID cudaExtent_width; // size_t
jfieldID cudaExtent_height; // size_t
jfieldID cudaExtent_depth; // size_t

jclass cudaChannelFormatDesc_class;
jmethodID cudaChannelFormatDesc_constructor;

jfieldID cudaChannelFormatDesc_x; // int
jfieldID cudaChannelFormatDesc_y; // int
jfieldID cudaChannelFormatDesc_z; // int
jfieldID cudaChannelFormatDesc_w; // int
jfieldID cudaChannelFormatDesc_f;  // cudaChannelFormatKind

jfieldID cudaMemcpy3DParms_srcArray; // cudaArray
jfieldID cudaMemcpy3DParms_srcPos; // cudaPos
jfieldID cudaMemcpy3DParms_srcPtr; // cudaPitchedPtr
jfieldID cudaMemcpy3DParms_dstArray; // cudaArray
jfieldID cudaMemcpy3DParms_dstPos; // cudaPos
jfieldID cudaMemcpy3DParms_dstPtr; // cudaPitchedPtr
jfieldID cudaMemcpy3DParms_extent; // cudaExtent
jfieldID cudaMemcpy3DParms_kind; // cudaMemcpyKind

jfieldID cudaMemcpy3DPeerParms_srcArray; // cudaArray
jfieldID cudaMemcpy3DPeerParms_srcPos; // cudaPos
jfieldID cudaMemcpy3DPeerParms_srcPtr; // cudaPitchedPtr
jfieldID cudaMemcpy3DPeerParms_srcDevice; // int
jfieldID cudaMemcpy3DPeerParms_dstArray; // cudaArray
jfieldID cudaMemcpy3DPeerParms_dstPos; // cudaPos
jfieldID cudaMemcpy3DPeerParms_dstPtr; // cudaPitchedPtr
jfieldID cudaMemcpy3DPeerParms_dstDevice; // int
jfieldID cudaMemcpy3DPeerParms_extent; // cudaExtent

jfieldID cudaPos_x; // int
jfieldID cudaPos_y; // int
jfieldID cudaPos_z; // int

jfieldID textureReference_normalized; // int
jfieldID textureReference_filterMode; // cudaTextureFilterMode
jfieldID textureReference_addressMode; // cudaTextureAddressMode[3];
jfieldID textureReference_channelDesc; // cudaChannelFormatDesc
jfieldID textureReference_sRGB; // int
jfieldID textureReference_maxAnisotropy; // unsigned int
jfieldID textureReference_mipmapFilterMode; // cudaTextureFilterMode
jfieldID textureReference_mipmapLevelBias; // float
jfieldID textureReference_minMipmapLevelClamp; // float
jfieldID textureReference_maxMipmapLevelClamp; // float

jfieldID surfaceReference_channelDesc; // cudaChannelFormatDesc

jfieldID dim3_x; // size_t
jfieldID dim3_y; // size_t
jfieldID dim3_z; // size_t

jfieldID cudaFuncAttributes_sharedSizeBytes; // size_t
jfieldID cudaFuncAttributes_constSizeBytes; // size_t
jfieldID cudaFuncAttributes_localSizeBytes; // size_t
jfieldID cudaFuncAttributes_maxThreadsPerBlock; // int
jfieldID cudaFuncAttributes_numRegs; // int
jfieldID cudaFuncAttributes_ptxVersion; // int
jfieldID cudaFuncAttributes_binaryVersion; // int
jfieldID cudaFuncAttributes_cacheModeCA; // int

jfieldID cudaPointerAttributes_memoryType; // cudaMempryType
jfieldID cudaPointerAttributes_device; // int
jfieldID cudaPointerAttributes_devicePointer; // void*
jfieldID cudaPointerAttributes_hostPointer; // void*
jfieldID cudaPointerAttributes_isManaged; // int

jfieldID cudaIpcEventHandle_reserved; // byte[]
jfieldID cudaIpcMemHandle_reserved; // byte[]

jfieldID cudaResourceDesc_resType; // cudaResourceType
jfieldID cudaResourceDesc_array_array; // cudaArray_t
jfieldID cudaResourceDesc_mipmap_mipmap; // cudaMipmappedArray_t
jfieldID cudaResourceDesc_linear_devPtr; // void*
jfieldID cudaResourceDesc_linear_desc; // cudaChannelFormatDesc
jfieldID cudaResourceDesc_linear_sizeInBytes; // size_t
jfieldID cudaResourceDesc_pitch2D_devPtr; // void*
jfieldID cudaResourceDesc_pitch2D_desc; // cudaChannelFormatDesc
jfieldID cudaResourceDesc_pitch2D_width; // size_t
jfieldID cudaResourceDesc_pitch2D_height; // size_t
jfieldID cudaResourceDesc_pitch2D_pitchInBytes; // size_t

jfieldID cudaResourceViewDesc_format; // cudaResourceViewFormat
jfieldID cudaResourceViewDesc_width; // size_t
jfieldID cudaResourceViewDesc_height; // size_t
jfieldID cudaResourceViewDesc_depth; // size_t
jfieldID cudaResourceViewDesc_firstMipmapLevel; // unsigned int
jfieldID cudaResourceViewDesc_lastMipmapLevel; // unsigned int
jfieldID cudaResourceViewDesc_firstLayer; // unsigned int
jfieldID cudaResourceViewDesc_lastLayer; // unsigned int

jfieldID cudaTextureDesc_addressMode; // cudaTextureAddressMode[3]
jfieldID cudaTextureDesc_filterMode; // cudaTextureFilterMode
jfieldID cudaTextureDesc_readMode; // cudaTextureReadMode
jfieldID cudaTextureDesc_sRGB; // int
jfieldID cudaTextureDesc_borderColor; // float[4]
jfieldID cudaTextureDesc_normalizedCoords; // int
jfieldID cudaTextureDesc_maxAnisotropy; // unsigned int
jfieldID cudaTextureDesc_mipmapFilterMode; // cudaTextureFilterMode
jfieldID cudaTextureDesc_mipmapLevelBias; // float
jfieldID cudaTextureDesc_minMipmapLevelClamp; // float
jfieldID cudaTextureDesc_maxMipmapLevelClamp; // float

// Static method ID for the cudaStreamCallback#call function
static jmethodID cudaStreamCallback_call; // (LCUDAWrapper/runtime/cudaStream_t;ILjava/lang/Object;)V


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

    Logger::log(LOG_DEBUGTRACE, "Initializing CUDAWrapperRuntime\n");

    globalJvm = jvm;

    jclass cls = NULL;

    // Initialize the JNIUtils and PointerUtils
    if (initJNIUtils(env) == JNI_ERR) return JNI_ERR;
    if (initPointerUtils(env) == JNI_ERR) return JNI_ERR;


    // Obtain the fieldIDs of the cudaDeviceProp class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaDeviceProp")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_name,                        "name",                        "[B")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_totalGlobalMem,              "totalGlobalMem",              "J" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_sharedMemPerBlock,           "sharedMemPerBlock",           "J" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_regsPerBlock,                "regsPerBlock",                "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_warpSize,                    "warpSize",                    "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_memPitch,                    "memPitch",                    "J" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxThreadsPerBlock,          "maxThreadsPerBlock",          "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxThreadsDim,               "maxThreadsDim",               "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxGridSize,                 "maxGridSize",                 "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_clockRate,                   "clockRate",                   "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_totalConstMem,               "totalConstMem",               "J" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_major,                       "major",                       "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_minor,                       "minor",                       "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_textureAlignment,            "textureAlignment",            "J" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_texturePitchAlignment,       "texturePitchAlignment",       "J" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_deviceOverlap,               "deviceOverlap",               "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_multiProcessorCount,         "multiProcessorCount",         "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_kernelExecTimeoutEnabled,    "kernelExecTimeoutEnabled",    "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_integrated,                  "integrated",                  "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_canMapHostMemory,            "canMapHostMemory",            "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_computeMode,                 "computeMode",                 "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTexture1D,                "maxTexture1D",                "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTexture1DMipmap,          "maxTexture1DMipmap",          "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTexture1DLinear,          "maxTexture1DLinear",          "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTexture2D,                "maxTexture2D",                "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTexture2DMipmap,          "maxTexture2DMipmap",          "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTexture2DLinear,          "maxTexture2DLinear",          "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTexture2DGather,          "maxTexture2DGather",          "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTexture3D,                "maxTexture3D",                "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTexture3DAlt,             "maxTexture3DAlt",             "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTextureCubemap,           "maxTextureCubemap",           "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTexture1DLayered,         "maxTexture1DLayered",         "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTexture2DLayered,         "maxTexture2DLayered",         "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxTextureCubemapLayered,    "maxTextureCubemapLayered",    "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxSurface1D,                "maxSurface1D",                "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxSurface2D,                "maxSurface2D",                "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxSurface3D,                "maxSurface3D",                "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxSurface1DLayered,         "maxSurface1DLayered",         "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxSurface2DLayered,         "maxSurface2DLayered",         "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxSurfaceCubemap,           "maxSurfaceCubemap",           "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxSurfaceCubemapLayered,    "maxSurfaceCubemapLayered",    "[I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_surfaceAlignment,            "surfaceAlignment",            "J" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_concurrentKernels,           "concurrentKernels",           "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_ECCEnabled,                  "ECCEnabled",                  "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_pciBusID,                    "pciBusID",                    "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_pciDeviceID,                 "pciDeviceID",                 "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_pciDomainID,                 "pciDomainID",                 "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_tccDriver,                   "tccDriver",                   "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_asyncEngineCount,            "asyncEngineCount",            "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_unifiedAddressing,           "unifiedAddressing",           "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_memoryClockRate,             "memoryClockRate",             "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_memoryBusWidth,              "memoryBusWidth",              "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_l2CacheSize,                 "l2CacheSize",                 "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_maxThreadsPerMultiProcessor, "maxThreadsPerMultiProcessor", "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_globalL1CacheSupported,      "globalL1CacheSupported",      "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_localL1CacheSupported,       "localL1CacheSupported",       "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_sharedMemPerMultiprocessor,  "sharedMemPerMultiprocessor",  "J" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_regsPerMultiprocessor,       "regsPerMultiprocessor",       "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_managedMemory,               "managedMemory",               "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_isMultiGpuBoard,             "isMultiGpuBoard",             "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_multiGpuBoardGroupID,        "multiGpuBoardGroupID",        "I" )) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_hostNativeAtomicSupported,            "hostNativeAtomicSupported",            "I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_singleToDoublePrecisionPerfRatio,     "singleToDoublePrecisionPerfRatio",     "I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_pageableMemoryAccess,                 "pageableMemoryAccess",                 "I")) return JNI_ERR;
    if (!init(env, cls, cudaDeviceProp_concurrentManagedAccess,              "concurrentManagedAccess",              "I")) return JNI_ERR;

    // Obtain the fieldIDs of the cudaPitchedPtr class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaPitchedPtr")) return JNI_ERR;
    if (!init(env, cls, cudaPitchedPtr_ptr,   "ptr",   "LCUDAWrapper/Pointer;")) return JNI_ERR;
    if (!init(env, cls, cudaPitchedPtr_pitch, "pitch", "J"              )) return JNI_ERR;
    if (!init(env, cls, cudaPitchedPtr_xsize, "xsize", "J"              )) return JNI_ERR;
    if (!init(env, cls, cudaPitchedPtr_ysize, "ysize", "J"              )) return JNI_ERR;


    // Obtain the fieldIDs of the cudaExtent class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaExtent")) return JNI_ERR;
    if (!init(env, cls, cudaExtent_width,  "width",  "J")) return JNI_ERR;
    if (!init(env, cls, cudaExtent_height, "height", "J")) return JNI_ERR;
    if (!init(env, cls, cudaExtent_depth,  "depth",  "J")) return JNI_ERR;


    // Obtain the fieldIDs of the cudaChannelFormatDesc class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaChannelFormatDesc")) return JNI_ERR;
    cudaChannelFormatDesc_class = (jclass)env->NewGlobalRef(cls);
    if (cudaChannelFormatDesc_class == NULL)
    {
        Logger::log(LOG_ERROR, "Failed to create reference to class cudaChannelFormatDesc\n");
        return JNI_ERR;
    }
    if (!init(env, cls, cudaChannelFormatDesc_constructor, "<init>", "()V")) return JNI_ERR;
    if (!init(env, cls, cudaChannelFormatDesc_x,           "x",      "I"  )) return JNI_ERR;
    if (!init(env, cls, cudaChannelFormatDesc_y,           "y",      "I"  )) return JNI_ERR;
    if (!init(env, cls, cudaChannelFormatDesc_z,           "z",      "I"  )) return JNI_ERR;
    if (!init(env, cls, cudaChannelFormatDesc_w,           "w",      "I"  )) return JNI_ERR;
    if (!init(env, cls, cudaChannelFormatDesc_f,           "f",      "I"  )) return JNI_ERR;



    // Obtain the fieldIDs of the cudaMemcpy3DParms class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaMemcpy3DParms")) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DParms_srcArray, "srcArray", "LCUDAWrapper/runtime/cudaArray;"     )) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DParms_srcPos,   "srcPos",   "LCUDAWrapper/runtime/cudaPos;"       )) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DParms_srcPtr,   "srcPtr",   "LCUDAWrapper/runtime/cudaPitchedPtr;")) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DParms_dstArray, "dstArray", "LCUDAWrapper/runtime/cudaArray;"     )) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DParms_dstPos,   "dstPos",   "LCUDAWrapper/runtime/cudaPos;"       )) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DParms_dstPtr,   "dstPtr",   "LCUDAWrapper/runtime/cudaPitchedPtr;")) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DParms_extent,   "extent",   "LCUDAWrapper/runtime/cudaExtent;"    )) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DParms_kind,     "kind",     "I"                             )) return JNI_ERR;

    // Obtain the fieldIDs of the cudaMemcpy3DPeerParms class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaMemcpy3DPeerParms")) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DPeerParms_srcArray, "srcArray", "LCUDAWrapper/runtime/cudaArray;"     )) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DPeerParms_srcPos,   "srcPos",   "LCUDAWrapper/runtime/cudaPos;"       )) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DPeerParms_srcPtr,   "srcPtr",   "LCUDAWrapper/runtime/cudaPitchedPtr;")) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DPeerParms_srcDevice,"srcDevice","I"                             )) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DPeerParms_dstArray, "dstArray", "LCUDAWrapper/runtime/cudaArray;"     )) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DPeerParms_dstPos,   "dstPos",   "LCUDAWrapper/runtime/cudaPos;"       )) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DPeerParms_dstPtr,   "dstPtr",   "LCUDAWrapper/runtime/cudaPitchedPtr;")) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DPeerParms_dstDevice,"dstDevice","I"                             )) return JNI_ERR;
    if (!init(env, cls, cudaMemcpy3DPeerParms_extent,   "extent",   "LCUDAWrapper/runtime/cudaExtent;"    )) return JNI_ERR;


    // Obtain the fieldIDs of the cudaPos class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaPos")) return JNI_ERR;
    if (!init(env, cls, cudaPos_x, "x", "J")) return JNI_ERR;
    if (!init(env, cls, cudaPos_y, "y", "J")) return JNI_ERR;
    if (!init(env, cls, cudaPos_z, "z", "J")) return JNI_ERR;


    // Obtain the fieldIDs of the textureReference class
    if (!init(env, cls, "CUDAWrapper/runtime/textureReference")) return JNI_ERR;
    if (!init(env, cls, textureReference_normalized,    "normalized",    "I")) return JNI_ERR;
    if (!init(env, cls, textureReference_filterMode,    "filterMode",    "I")) return JNI_ERR;
    if (!init(env, cls, textureReference_addressMode,   "addressMode",   "[I")) return JNI_ERR;
    if (!init(env, cls, textureReference_channelDesc,   "channelDesc",   "LCUDAWrapper/runtime/cudaChannelFormatDesc;")) return JNI_ERR;
    if (!init(env, cls, textureReference_sRGB,          "sRGB",          "I")) return JNI_ERR;
    if (!init(env, cls, textureReference_maxAnisotropy,       "maxAnisotropy",       "I")) return JNI_ERR;
    if (!init(env, cls, textureReference_mipmapFilterMode,    "mipmapFilterMode",    "I")) return JNI_ERR;
    if (!init(env, cls, textureReference_mipmapLevelBias,     "mipmapLevelBias",     "F")) return JNI_ERR;
    if (!init(env, cls, textureReference_minMipmapLevelClamp, "minMipmapLevelClamp", "F")) return JNI_ERR;
    if (!init(env, cls, textureReference_maxMipmapLevelClamp, "maxMipmapLevelClamp", "F")) return JNI_ERR;

    // Obtain the fieldIDs of the surfaceReference class
    if (!init(env, cls, "CUDAWrapper/runtime/surfaceReference")) return JNI_ERR;
    if (!init(env, cls, surfaceReference_channelDesc,   "channelDesc",   "LCUDAWrapper/runtime/cudaChannelFormatDesc;")) return JNI_ERR;


    // Obtain the fieldIDs of the dim3 class
    if (!init(env, cls, "CUDAWrapper/runtime/dim3")) return JNI_ERR;
    if (!init(env, cls, dim3_x, "x", "I")) return JNI_ERR;
    if (!init(env, cls, dim3_y, "y", "I")) return JNI_ERR;
    if (!init(env, cls, dim3_z, "z", "I")) return JNI_ERR;


    // Obtain the fieldIDs of the cudaFuncAttributes class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaFuncAttributes")) return JNI_ERR;
    if (!init(env, cls, cudaFuncAttributes_sharedSizeBytes,    "sharedSizeBytes",    "J")) return JNI_ERR;
    if (!init(env, cls, cudaFuncAttributes_constSizeBytes,     "constSizeBytes",     "J")) return JNI_ERR;
    if (!init(env, cls, cudaFuncAttributes_localSizeBytes,     "localSizeBytes",     "J")) return JNI_ERR;
    if (!init(env, cls, cudaFuncAttributes_maxThreadsPerBlock, "maxThreadsPerBlock", "I")) return JNI_ERR;
    if (!init(env, cls, cudaFuncAttributes_numRegs,            "numRegs",            "I")) return JNI_ERR;
    if (!init(env, cls, cudaFuncAttributes_ptxVersion,         "ptxVersion",         "I")) return JNI_ERR;
    if (!init(env, cls, cudaFuncAttributes_binaryVersion,      "binaryVersion",      "I")) return JNI_ERR;
    if (!init(env, cls, cudaFuncAttributes_cacheModeCA,        "cacheModeCA",        "I")) return JNI_ERR;

    // Obtain the fieldIDs of the cudaPointerAttributes class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaPointerAttributes")) return JNI_ERR;
    if (!init(env, cls, cudaPointerAttributes_memoryType,    "memoryType",    "I"              )) return JNI_ERR;
    if (!init(env, cls, cudaPointerAttributes_device,        "device",        "I"              )) return JNI_ERR;
    if (!init(env, cls, cudaPointerAttributes_devicePointer, "devicePointer", "LCUDAWrapper/Pointer;")) return JNI_ERR;
    if (!init(env, cls, cudaPointerAttributes_hostPointer,   "hostPointer",   "LCUDAWrapper/Pointer;")) return JNI_ERR;
    if (!init(env, cls, cudaPointerAttributes_isManaged,     "isManaged",     "I"              )) return JNI_ERR;

    // Obtain the fieldIDs of the cudaIpcEventHandle class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaIpcEventHandle")) return JNI_ERR;
    if (!init(env, cls, cudaIpcEventHandle_reserved, "reserved", "[B")) return JNI_ERR;

    // Obtain the fieldIDs of the cudaIpcEventHandle class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaIpcMemHandle")) return JNI_ERR;
    if (!init(env, cls, cudaIpcMemHandle_reserved, "reserved", "[B")) return JNI_ERR;

    // Obtain the fieldIDs of the cudaResourceDesc class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaResourceDesc")) return JNI_ERR;
    if (!init(env, cls, cudaResourceDesc_resType,              "resType",              "I")) return JNI_ERR;
    if (!init(env, cls, cudaResourceDesc_array_array,          "array_array",          "LCUDAWrapper/runtime/cudaArray;")) return JNI_ERR;
    if (!init(env, cls, cudaResourceDesc_mipmap_mipmap,        "mipmap_mipmap",        "LCUDAWrapper/runtime/cudaMipmappedArray;")) return JNI_ERR;
    if (!init(env, cls, cudaResourceDesc_linear_devPtr,        "linear_devPtr",        "LCUDAWrapper/Pointer;")) return JNI_ERR;
    if (!init(env, cls, cudaResourceDesc_linear_desc,          "linear_desc",          "LCUDAWrapper/runtime/cudaChannelFormatDesc;")) return JNI_ERR;
    if (!init(env, cls, cudaResourceDesc_linear_sizeInBytes,   "linear_sizeInBytes",   "J")) return JNI_ERR;
    if (!init(env, cls, cudaResourceDesc_pitch2D_devPtr,       "pitch2D_devPtr",       "LCUDAWrapper/Pointer;")) return JNI_ERR;
    if (!init(env, cls, cudaResourceDesc_pitch2D_desc,         "pitch2D_desc",         "LCUDAWrapper/runtime/cudaChannelFormatDesc;")) return JNI_ERR;
    if (!init(env, cls, cudaResourceDesc_pitch2D_width,        "pitch2D_width",        "J")) return JNI_ERR;
    if (!init(env, cls, cudaResourceDesc_pitch2D_height,       "pitch2D_height",       "J")) return JNI_ERR;
    if (!init(env, cls, cudaResourceDesc_pitch2D_pitchInBytes, "pitch2D_pitchInBytes", "J")) return JNI_ERR;

    // Obtain the fieldIDs of the cudaResourceViewDesc class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaResourceViewDesc")) return JNI_ERR;
    if (!init(env, cls, cudaResourceViewDesc_format,           "format",           "I")) return JNI_ERR;
    if (!init(env, cls, cudaResourceViewDesc_width,            "width",            "J")) return JNI_ERR;
    if (!init(env, cls, cudaResourceViewDesc_height,           "height",           "J")) return JNI_ERR;
    if (!init(env, cls, cudaResourceViewDesc_depth,            "depth",            "J")) return JNI_ERR;
    if (!init(env, cls, cudaResourceViewDesc_firstMipmapLevel, "firstMipmapLevel", "I")) return JNI_ERR;
    if (!init(env, cls, cudaResourceViewDesc_lastMipmapLevel,  "lastMipmapLevel",  "I")) return JNI_ERR;
    if (!init(env, cls, cudaResourceViewDesc_firstLayer,       "firstLayer",       "I")) return JNI_ERR;
    if (!init(env, cls, cudaResourceViewDesc_lastLayer,        "lastLayer",        "I")) return JNI_ERR;

    // Obtain the fieldIDs of the cudaTextureDesc class
    if (!init(env, cls, "CUDAWrapper/runtime/cudaTextureDesc")) return JNI_ERR;
    if (!init(env, cls, cudaTextureDesc_addressMode,         "addressMode",         "[I")) return JNI_ERR;
    if (!init(env, cls, cudaTextureDesc_filterMode,          "filterMode",          "I")) return JNI_ERR;
    if (!init(env, cls, cudaTextureDesc_readMode,            "readMode",            "I")) return JNI_ERR;
    if (!init(env, cls, cudaTextureDesc_sRGB,                "sRGB",                "I")) return JNI_ERR;
    if (!init(env, cls, cudaTextureDesc_borderColor,         "borderColor",         "[F")) return JNI_ERR;
    if (!init(env, cls, cudaTextureDesc_normalizedCoords,    "normalizedCoords",    "I")) return JNI_ERR;
    if (!init(env, cls, cudaTextureDesc_mipmapFilterMode,    "mipmapFilterMode",    "I")) return JNI_ERR;
    if (!init(env, cls, cudaTextureDesc_mipmapFilterMode,    "mipmapFilterMode",    "I")) return JNI_ERR;
    if (!init(env, cls, cudaTextureDesc_maxAnisotropy,       "maxAnisotropy",       "I")) return JNI_ERR;
    if (!init(env, cls, cudaTextureDesc_minMipmapLevelClamp, "minMipmapLevelClamp", "F")) return JNI_ERR;
    if (!init(env, cls, cudaTextureDesc_maxMipmapLevelClamp, "maxMipmapLevelClamp", "F")) return JNI_ERR;

    // Obtain the methodID for CUDAWrapper.runtime.cudaStreamCallback#call
    if (!init(env, cls, "CUDAWrapper/runtime/cudaStreamCallback")) return JNI_ERR;
    if (!init(env, cls, cudaStreamCallback_call, "call", "(LCUDAWrapper/runtime/cudaStream_t;ILjava/lang/Object;)V")) return JNI_ERR;

    return JNI_VERSION_1_4;
}



JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved)
{
}



/**
* A pointer to this function will be passed to cudaStreamAddCallback function.
* The given callbackInfoUserData will be a pointer to the CallbackInfo that was
* created when the callback was established. The contents of this CallbackInfo
* will be extracted here, and the actual (Java) callback function will be called.
*/
void CUDART_CB cudaStreamAddCallback_NativeCallback(cudaStream_t stream, cudaError_t status, void *callbackInfoUserData)
{
    Logger::log(LOG_DEBUGTRACE, "Executing cudaStreamAddCallback_NativeCallback\n");

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
    env->CallVoidMethod(javaCallbackObject, cudaStreamCallback_call, javaStreamObject, (int)status, userData);
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
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    setLogLevel
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_setLogLevel
  (JNIEnv *env, jclass cla, jint logLevel)
{
    Logger::setLogLevel((LogLevel)logLevel);
}



//============================================================================

// TODO: The methods for struct conversions do not perform any error checks!


/**
 * Writes the contents of the array of the given object that is specified
 * by the given field into the given native array
 */
void getArray(JNIEnv *env, jobject object, jfieldID field, int *nativeArray)
{
    jintArray array   = (jintArray)env->GetObjectField(object, field);
    int length = env->GetArrayLength(array);
    jint *arrayData = (jint*)    env->GetPrimitiveArrayCritical(array, NULL);
    if (arrayData == NULL)
    {
        return;
    }
    for (int i=0; i<length; i++)
    {
        nativeArray[i] = (int)arrayData[i];
    }
    env->ReleasePrimitiveArrayCritical(array, arrayData, JNI_ABORT);
}

/**
 * Returns the native representation of the given Java object
 */
cudaDeviceProp getCudaDeviceProp(JNIEnv *env, jobject prop)
{
    cudaDeviceProp nativeProp;

    jbyteArray propName = (jbyteArray)env->GetObjectField(prop, cudaDeviceProp_name);
    char *propNameMemory = (char*)env->GetPrimitiveArrayCritical(propName, NULL);
    memcpy(nativeProp.name, propNameMemory, 256);
    env->ReleasePrimitiveArrayCritical(propName, propNameMemory, 0);

    nativeProp.totalGlobalMem      = (size_t)env->GetLongField(prop, cudaDeviceProp_totalGlobalMem);
    nativeProp.sharedMemPerBlock   = (size_t)env->GetLongField(prop, cudaDeviceProp_sharedMemPerBlock);
    nativeProp.regsPerBlock        = (int)   env->GetIntField( prop, cudaDeviceProp_regsPerBlock);
    nativeProp.warpSize            = (int)   env->GetIntField( prop, cudaDeviceProp_warpSize);
    nativeProp.memPitch            = (size_t)env->GetLongField(prop, cudaDeviceProp_memPitch);
    nativeProp.maxThreadsPerBlock  = (int)   env->GetIntField( prop, cudaDeviceProp_maxThreadsPerBlock);

    getArray(env, prop, cudaDeviceProp_maxThreadsDim, nativeProp.maxThreadsDim);
    getArray(env, prop, cudaDeviceProp_maxGridSize, nativeProp.maxGridSize);

    nativeProp.clockRate             = (int)   env->GetIntField( prop, cudaDeviceProp_clockRate);
    nativeProp.totalConstMem         = (size_t)env->GetLongField(prop, cudaDeviceProp_totalConstMem);
    nativeProp.major                 = (int)   env->GetIntField( prop, cudaDeviceProp_major);
    nativeProp.minor                 = (int)   env->GetIntField( prop, cudaDeviceProp_minor);
    nativeProp.textureAlignment      = (size_t)env->GetLongField(prop, cudaDeviceProp_textureAlignment);
    nativeProp.texturePitchAlignment = (size_t)env->GetLongField(prop, cudaDeviceProp_texturePitchAlignment);
    nativeProp.deviceOverlap         = (int)   env->GetIntField( prop, cudaDeviceProp_deviceOverlap);
    nativeProp.multiProcessorCount   = (int)   env->GetIntField( prop, cudaDeviceProp_multiProcessorCount);

    nativeProp.kernelExecTimeoutEnabled = (int)   env->GetIntField( prop, cudaDeviceProp_kernelExecTimeoutEnabled);
    nativeProp.integrated               = (int)   env->GetIntField( prop, cudaDeviceProp_integrated);
    nativeProp.canMapHostMemory         = (int)   env->GetIntField( prop, cudaDeviceProp_canMapHostMemory);
    nativeProp.computeMode              = (int)   env->GetIntField( prop, cudaDeviceProp_computeMode);
    nativeProp.maxTexture1D             = (int)   env->GetIntField( prop, cudaDeviceProp_maxTexture1D);
    nativeProp.maxTexture1DMipmap       = (int)   env->GetIntField( prop, cudaDeviceProp_maxTexture1DMipmap);
    nativeProp.maxTexture1DLinear       = (int)   env->GetIntField( prop, cudaDeviceProp_maxTexture1DLinear);

    getArray(env, prop, cudaDeviceProp_maxTexture2D, nativeProp.maxTexture2D);
    getArray(env, prop, cudaDeviceProp_maxTexture2DMipmap, nativeProp.maxTexture2DMipmap);
    getArray(env, prop, cudaDeviceProp_maxTexture2DLinear, nativeProp.maxTexture2DLinear);
    getArray(env, prop, cudaDeviceProp_maxTexture2DGather, nativeProp.maxTexture2DGather);
    getArray(env, prop, cudaDeviceProp_maxTexture3D, nativeProp.maxTexture3D);
    getArray(env, prop, cudaDeviceProp_maxTexture3DAlt, nativeProp.maxTexture3DAlt);

    nativeProp.maxTextureCubemap       = (int)   env->GetIntField( prop, cudaDeviceProp_maxTextureCubemap);

    getArray(env, prop, cudaDeviceProp_maxTexture1DLayered, nativeProp.maxTexture1DLayered);
    getArray(env, prop, cudaDeviceProp_maxTexture2DLayered, nativeProp.maxTexture2DLayered);
    getArray(env, prop, cudaDeviceProp_maxTextureCubemapLayered, nativeProp.maxTextureCubemapLayered);

    nativeProp.maxSurface1D       = (int)   env->GetIntField( prop, cudaDeviceProp_maxSurface1D);

    getArray(env, prop, cudaDeviceProp_maxSurface2D, nativeProp.maxSurface2D);
    getArray(env, prop, cudaDeviceProp_maxSurface3D, nativeProp.maxSurface3D);
    getArray(env, prop, cudaDeviceProp_maxSurface1DLayered, nativeProp.maxSurface1DLayered);
    getArray(env, prop, cudaDeviceProp_maxSurface2DLayered, nativeProp.maxSurface2DLayered);

    nativeProp.maxSurfaceCubemap       = (int)   env->GetIntField( prop, cudaDeviceProp_maxSurfaceCubemap);

    getArray(env, prop, cudaDeviceProp_maxSurfaceCubemapLayered, nativeProp.maxSurfaceCubemapLayered);

    nativeProp.surfaceAlignment         = (size_t)env->GetLongField( prop, cudaDeviceProp_surfaceAlignment);
    nativeProp.concurrentKernels        = (int)   env->GetIntField( prop, cudaDeviceProp_concurrentKernels);
    nativeProp.ECCEnabled               = (int)   env->GetIntField( prop, cudaDeviceProp_ECCEnabled);
    nativeProp.pciBusID                 = (int)   env->GetIntField( prop, cudaDeviceProp_pciBusID);
    nativeProp.pciDeviceID              = (int)   env->GetIntField( prop, cudaDeviceProp_pciDeviceID);
    nativeProp.pciDomainID              = (int)   env->GetIntField( prop, cudaDeviceProp_pciDomainID);
    nativeProp.tccDriver                = (int)   env->GetIntField( prop, cudaDeviceProp_tccDriver);
    nativeProp.asyncEngineCount         = (int)   env->GetIntField( prop, cudaDeviceProp_asyncEngineCount);
    nativeProp.unifiedAddressing        = (int)   env->GetIntField( prop, cudaDeviceProp_unifiedAddressing);
    nativeProp.memoryClockRate             = (int)env->GetIntField( prop, cudaDeviceProp_memoryClockRate);
    nativeProp.memoryBusWidth              = (int)env->GetIntField( prop, cudaDeviceProp_memoryBusWidth);
    nativeProp.l2CacheSize                 = (int)env->GetIntField( prop, cudaDeviceProp_l2CacheSize);
    nativeProp.maxThreadsPerMultiProcessor = (int)env->GetIntField( prop, cudaDeviceProp_maxThreadsPerMultiProcessor);
    nativeProp.globalL1CacheSupported      = (int)env->GetIntField( prop, cudaDeviceProp_globalL1CacheSupported);
    nativeProp.localL1CacheSupported       = (int)env->GetIntField( prop, cudaDeviceProp_localL1CacheSupported);
    nativeProp.sharedMemPerMultiprocessor  = (size_t)env->GetLongField( prop, cudaDeviceProp_sharedMemPerMultiprocessor);
    nativeProp.regsPerMultiprocessor       = (int)env->GetIntField( prop, cudaDeviceProp_regsPerMultiprocessor);
    nativeProp.managedMemory               = (int)env->GetIntField( prop, cudaDeviceProp_managedMemory);
    nativeProp.isMultiGpuBoard             = (int)env->GetIntField( prop, cudaDeviceProp_isMultiGpuBoard);
    nativeProp.multiGpuBoardGroupID = (int)env->GetIntField(prop, cudaDeviceProp_multiGpuBoardGroupID);
    nativeProp.hostNativeAtomicSupported        = (int)env->GetIntField(prop, cudaDeviceProp_hostNativeAtomicSupported);
    nativeProp.singleToDoublePrecisionPerfRatio = (int)env->GetIntField(prop, cudaDeviceProp_singleToDoublePrecisionPerfRatio);
    nativeProp.pageableMemoryAccess             = (int)env->GetIntField(prop, cudaDeviceProp_pageableMemoryAccess);
    nativeProp.concurrentManagedAccess          = (int)env->GetIntField(prop, cudaDeviceProp_concurrentManagedAccess);

    return nativeProp;
}


/**
 * Writes the contents of the given native array into the array of the given
 * object that is specified by the given field
 */
void setArray(JNIEnv *env, jobject object, jfieldID field, int *nativeArray)
{
    jintArray array   = (jintArray)env->GetObjectField(object, field);
    int length = env->GetArrayLength(array);
    jint *arrayData = (jint*)    env->GetPrimitiveArrayCritical(array, NULL);
     if (arrayData == NULL)
    {
        return;
    }
    for (int i=0; i<length; i++)
    {
        arrayData[i] = (jint)nativeArray[i];
    }
    env->ReleasePrimitiveArrayCritical(array, arrayData, 0);
}


/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCudaDeviceProp(JNIEnv *env, jobject prop, cudaDeviceProp nativeProp)
{
    jbyteArray propName = (jbyteArray)env->GetObjectField(prop, cudaDeviceProp_name);
    char *propNameMemory = (char*)env->GetPrimitiveArrayCritical(propName, NULL);
     if (propNameMemory == NULL)
    {
       return;
    }
    memcpy(propNameMemory, nativeProp.name, 256);
    env->ReleasePrimitiveArrayCritical(propName, propNameMemory, JNI_ABORT);

    env->SetLongField(prop, cudaDeviceProp_totalGlobalMem,      (jlong)nativeProp.totalGlobalMem);
    env->SetLongField(prop, cudaDeviceProp_sharedMemPerBlock,   (jlong)nativeProp.sharedMemPerBlock);
    env->SetIntField( prop, cudaDeviceProp_regsPerBlock,        (jint) nativeProp.regsPerBlock);
    env->SetIntField( prop, cudaDeviceProp_warpSize,            (jint) nativeProp.warpSize);
    env->SetLongField(prop, cudaDeviceProp_memPitch,            (jlong)nativeProp.memPitch);
    env->SetIntField( prop, cudaDeviceProp_maxThreadsPerBlock,  (jint) nativeProp.maxThreadsPerBlock);

    setArray(env, prop, cudaDeviceProp_maxThreadsDim, nativeProp.maxThreadsDim);
    setArray(env, prop, cudaDeviceProp_maxGridSize, nativeProp.maxGridSize);

    env->SetIntField( prop, cudaDeviceProp_clockRate,             (jint) nativeProp.clockRate);
    env->SetLongField(prop, cudaDeviceProp_totalConstMem,         (jlong)nativeProp.totalConstMem);
    env->SetIntField( prop, cudaDeviceProp_major,                 (jint) nativeProp.major);
    env->SetIntField( prop, cudaDeviceProp_minor,                 (jint) nativeProp.minor);
    env->SetLongField(prop, cudaDeviceProp_textureAlignment,      (jlong)nativeProp.textureAlignment);
    env->SetLongField(prop, cudaDeviceProp_texturePitchAlignment, (jlong)nativeProp.texturePitchAlignment);
    env->SetIntField( prop, cudaDeviceProp_deviceOverlap,         (jint) nativeProp.deviceOverlap);
    env->SetIntField( prop, cudaDeviceProp_multiProcessorCount,   (jint) nativeProp.multiProcessorCount);

    env->SetIntField( prop, cudaDeviceProp_kernelExecTimeoutEnabled, (jint)nativeProp.kernelExecTimeoutEnabled);
    env->SetIntField( prop, cudaDeviceProp_integrated              , (jint)nativeProp.integrated);
    env->SetIntField( prop, cudaDeviceProp_canMapHostMemory        , (jint)nativeProp.canMapHostMemory);
    env->SetIntField( prop, cudaDeviceProp_computeMode             , (jint)nativeProp.computeMode);
    env->SetIntField( prop, cudaDeviceProp_maxTexture1D            , (jint)nativeProp.maxTexture1D);
    env->SetIntField( prop, cudaDeviceProp_maxTexture1DLinear      , (jint)nativeProp.maxTexture1DLinear);
    env->SetIntField( prop, cudaDeviceProp_maxTexture1DMipmap      , (jint)nativeProp.maxTexture1DMipmap);

    setArray(env, prop, cudaDeviceProp_maxTexture2D, nativeProp.maxTexture2D);
    setArray(env, prop, cudaDeviceProp_maxTexture2DMipmap, nativeProp.maxTexture2DMipmap);
    setArray(env, prop, cudaDeviceProp_maxTexture2DLinear, nativeProp.maxTexture2DLinear);
    setArray(env, prop, cudaDeviceProp_maxTexture2DGather, nativeProp.maxTexture2DGather);
    setArray(env, prop, cudaDeviceProp_maxTexture3D, nativeProp.maxTexture3D);
    setArray(env, prop, cudaDeviceProp_maxTexture3DAlt, nativeProp.maxTexture3DAlt);

    env->SetIntField( prop, cudaDeviceProp_maxTextureCubemap      , (jint)nativeProp.maxTextureCubemap);

    setArray(env, prop, cudaDeviceProp_maxTexture1DLayered, nativeProp.maxTexture1DLayered);
    setArray(env, prop, cudaDeviceProp_maxTexture2DLayered, nativeProp.maxTexture2DLayered);
    setArray(env, prop, cudaDeviceProp_maxTextureCubemapLayered, nativeProp.maxTextureCubemapLayered);

    env->SetIntField( prop, cudaDeviceProp_maxSurface1D      , (jint)nativeProp.maxSurface1D);

    setArray(env, prop, cudaDeviceProp_maxSurface2D, nativeProp.maxSurface2D);
    setArray(env, prop, cudaDeviceProp_maxSurface3D, nativeProp.maxSurface3D);
    setArray(env, prop, cudaDeviceProp_maxSurface1DLayered, nativeProp.maxSurface1DLayered);
    setArray(env, prop, cudaDeviceProp_maxSurface2DLayered, nativeProp.maxSurface2DLayered);

    env->SetIntField( prop, cudaDeviceProp_maxSurfaceCubemap      , (jint)nativeProp.maxSurfaceCubemap);

    setArray(env, prop, cudaDeviceProp_maxSurfaceCubemapLayered, nativeProp.maxSurfaceCubemapLayered);

    env->SetLongField(prop, cudaDeviceProp_surfaceAlignment        , (jlong)nativeProp.surfaceAlignment);
    env->SetIntField( prop, cudaDeviceProp_concurrentKernels       , (jint) nativeProp.concurrentKernels);
    env->SetIntField( prop, cudaDeviceProp_ECCEnabled              , (jint) nativeProp.ECCEnabled);
    env->SetIntField( prop, cudaDeviceProp_pciBusID                , (jint) nativeProp.pciBusID);
    env->SetIntField( prop, cudaDeviceProp_pciDeviceID             , (jint) nativeProp.pciDeviceID);
    env->SetIntField( prop, cudaDeviceProp_pciDomainID             , (jint) nativeProp.pciDomainID);
    env->SetIntField( prop, cudaDeviceProp_tccDriver               , (jint) nativeProp.tccDriver);
    env->SetIntField( prop, cudaDeviceProp_asyncEngineCount        , (jint) nativeProp.asyncEngineCount);
    env->SetIntField( prop, cudaDeviceProp_unifiedAddressing       , (jint) nativeProp.unifiedAddressing);

    env->SetIntField( prop, cudaDeviceProp_memoryClockRate            , (jint) nativeProp.memoryClockRate);
    env->SetIntField( prop, cudaDeviceProp_memoryBusWidth             , (jint) nativeProp.memoryBusWidth);
    env->SetIntField( prop, cudaDeviceProp_l2CacheSize                , (jint) nativeProp.l2CacheSize);
    env->SetIntField( prop, cudaDeviceProp_maxThreadsPerMultiProcessor, (jint) nativeProp.maxThreadsPerMultiProcessor);

    env->SetIntField( prop, cudaDeviceProp_globalL1CacheSupported    , (jint) nativeProp.globalL1CacheSupported);
    env->SetIntField( prop, cudaDeviceProp_localL1CacheSupported     , (jint) nativeProp.localL1CacheSupported);
    env->SetLongField(prop, cudaDeviceProp_sharedMemPerMultiprocessor, (jlong)nativeProp.sharedMemPerMultiprocessor);
    env->SetIntField( prop, cudaDeviceProp_regsPerMultiprocessor     , (jint) nativeProp.regsPerMultiprocessor);
    env->SetIntField( prop, cudaDeviceProp_managedMemory             , (jint) nativeProp.managedMemory);
    env->SetIntField( prop, cudaDeviceProp_isMultiGpuBoard           , (jint) nativeProp.isMultiGpuBoard);
    env->SetIntField(prop, cudaDeviceProp_multiGpuBoardGroupID       , (jint)nativeProp.multiGpuBoardGroupID);

    env->SetIntField(prop, cudaDeviceProp_hostNativeAtomicSupported,        (jint)nativeProp.hostNativeAtomicSupported);
    env->SetIntField(prop, cudaDeviceProp_singleToDoublePrecisionPerfRatio, (jint)nativeProp.singleToDoublePrecisionPerfRatio);
    env->SetIntField(prop, cudaDeviceProp_pageableMemoryAccess,             (jint)nativeProp.pageableMemoryAccess);
    env->SetIntField(prop, cudaDeviceProp_concurrentManagedAccess,          (jint)nativeProp.concurrentManagedAccess);
}


/**
 * Returns the native representation of the given Java object
 */
cudaExtent getCudaExtent(JNIEnv *env, jobject extent)
{
    cudaExtent nativeExtent;
    nativeExtent.width  = (size_t)env->GetLongField(extent, cudaExtent_width);
    nativeExtent.height = (size_t)env->GetLongField(extent, cudaExtent_height);
    nativeExtent.depth  = (size_t)env->GetLongField(extent, cudaExtent_depth);
    return nativeExtent;
}

/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCudaExtent(JNIEnv *env, jobject extent, cudaExtent nativeExtent)
{
    env->SetLongField(extent, cudaExtent_width, (jlong)nativeExtent.width);
    env->SetLongField(extent, cudaExtent_height, (jlong)nativeExtent.height);
    env->SetLongField(extent, cudaExtent_depth, (jlong)nativeExtent.depth);
}

/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCudaPitchedPtr(JNIEnv *env, jobject pitchedPtr, cudaPitchedPtr nativePitchedPtr)
{
    jobject pitchedPtrPtr = env->GetObjectField(pitchedPtr, cudaPitchedPtr_ptr);
    setPointer(env, pitchedPtrPtr, (jlong)nativePitchedPtr.ptr);

    env->SetLongField(pitchedPtr, cudaPitchedPtr_pitch, (jlong)nativePitchedPtr.pitch);
    env->SetLongField(pitchedPtr, cudaPitchedPtr_xsize, (jlong)nativePitchedPtr.xsize);
    env->SetLongField(pitchedPtr, cudaPitchedPtr_ysize, (jlong)nativePitchedPtr.ysize);
}

/**
 * Assigns the properties of the given native structure to the given
 * Java Object.
 */
cudaPitchedPtr getCudaPitchedPtr(JNIEnv *env, jobject pitchedPtr, PointerData* &pointerData)
{
    cudaPitchedPtr nativePitchedPtr;

    jobject ptr = env->GetObjectField(pitchedPtr, cudaPitchedPtr_ptr);
    pointerData = initPointerData(env, ptr);
    void *nativePtr = pointerData->getPointer(env);
    nativePitchedPtr.ptr = nativePtr;

    nativePitchedPtr.pitch = (size_t)env->GetLongField(pitchedPtr, cudaPitchedPtr_pitch);
    nativePitchedPtr.xsize = (size_t)env->GetLongField(pitchedPtr, cudaPitchedPtr_xsize);
    nativePitchedPtr.ysize = (size_t)env->GetLongField(pitchedPtr, cudaPitchedPtr_ysize);

    return nativePitchedPtr;
}

/**
 * Returns the native representation of the given Java object
 */
cudaPos getCudaPos(JNIEnv *env, jobject pos)
{
    cudaPos nativePos;
    nativePos.x = (size_t)env->GetLongField(pos, cudaPos_x);
    nativePos.y = (size_t)env->GetLongField(pos, cudaPos_y);
    nativePos.z = (size_t)env->GetLongField(pos, cudaPos_z);
    return nativePos;
}


/**
 * Returns the native representation of the given Java object
 *
 * TODO Consider summarizing the cudaMemcpy3DParms and
 * the source/destination PointerData in a struct,
 * similar to Memcpy3DData in driver API
 */
cudaMemcpy3DParms getCudaMemcpy3DParms(JNIEnv *env, jobject p, PointerData* &srcPointerData, PointerData* &dstPointerData)
{
    cudaMemcpy3DParms nativeP = {0};

    jobject srcArray = env->GetObjectField(p, cudaMemcpy3DParms_srcArray);
    nativeP.srcArray = (cudaArray*)getNativePointerValue(env, srcArray);

    nativeP.srcPos = getCudaPos(       env, env->GetObjectField(p, cudaMemcpy3DParms_srcPos));
    nativeP.srcPtr = getCudaPitchedPtr(env, env->GetObjectField(p, cudaMemcpy3DParms_srcPtr), srcPointerData);

    jobject dstArray = env->GetObjectField(p, cudaMemcpy3DParms_dstArray);
    nativeP.dstArray = (cudaArray*)getNativePointerValue(env, dstArray);

    nativeP.dstPos = getCudaPos(       env, env->GetObjectField(p, cudaMemcpy3DParms_dstPos));
    nativeP.dstPtr = getCudaPitchedPtr(env, env->GetObjectField(p, cudaMemcpy3DParms_dstPtr), dstPointerData);

    jobject extent   = env->GetObjectField(p, cudaMemcpy3DParms_extent  );
    nativeP.extent = getCudaExtent(env, extent);

    nativeP.kind = (cudaMemcpyKind)env->GetIntField(p, cudaMemcpy3DParms_kind);

    return nativeP;
}

/**
 * Returns the native representation of the given Java object
 */
cudaMemcpy3DPeerParms getCudaMemcpy3DPeerParms(JNIEnv *env, jobject p, PointerData* &srcPointerData, PointerData* &dstPointerData)
{
    cudaMemcpy3DPeerParms nativeP = {0};

    jobject srcArray = env->GetObjectField(p, cudaMemcpy3DPeerParms_srcArray);
    nativeP.srcArray = (cudaArray*)getNativePointerValue(env, srcArray);

    nativeP.srcPos = getCudaPos(       env, env->GetObjectField(p, cudaMemcpy3DPeerParms_srcPos));
    nativeP.srcPtr = getCudaPitchedPtr(env, env->GetObjectField(p, cudaMemcpy3DPeerParms_srcPtr), srcPointerData);

    nativeP.srcDevice = (int)env->GetIntField(p, cudaMemcpy3DPeerParms_srcDevice);

    jobject dstArray = env->GetObjectField(p, cudaMemcpy3DPeerParms_dstArray);
    nativeP.dstArray = (cudaArray*)getNativePointerValue(env, dstArray);

    nativeP.dstPos = getCudaPos(       env, env->GetObjectField(p, cudaMemcpy3DPeerParms_dstPos));
    nativeP.dstPtr = getCudaPitchedPtr(env, env->GetObjectField(p, cudaMemcpy3DPeerParms_dstPtr), dstPointerData);

    nativeP.dstDevice = (int)env->GetIntField(p, cudaMemcpy3DPeerParms_dstDevice);

    jobject extent   = env->GetObjectField(p, cudaMemcpy3DPeerParms_extent  );
    nativeP.extent = getCudaExtent(env, extent);

    return nativeP;
}


/**
 * Returns the native representation of the given Java object
 */
cudaChannelFormatDesc getCudaChannelFormatDesc(JNIEnv *env, jobject desc)
{
    cudaChannelFormatDesc nativeDesc;
    nativeDesc.x = (int)env->GetIntField(desc, cudaChannelFormatDesc_x);
    nativeDesc.y = (int)env->GetIntField(desc, cudaChannelFormatDesc_y);
    nativeDesc.z = (int)env->GetIntField(desc, cudaChannelFormatDesc_z);
    nativeDesc.w = (int)env->GetIntField(desc, cudaChannelFormatDesc_w);
    nativeDesc.f = (cudaChannelFormatKind)env->GetIntField(desc, cudaChannelFormatDesc_f);
    return nativeDesc;
}

/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCudaChannelFormatDesc(JNIEnv *env, jobject desc, cudaChannelFormatDesc nativeDesc)
{
    env->SetIntField(desc, cudaChannelFormatDesc_x, nativeDesc.x);
    env->SetIntField(desc, cudaChannelFormatDesc_y, nativeDesc.y);
    env->SetIntField(desc, cudaChannelFormatDesc_z, nativeDesc.z);
    env->SetIntField(desc, cudaChannelFormatDesc_w, nativeDesc.w);
    env->SetIntField(desc, cudaChannelFormatDesc_f, nativeDesc.f);
}



/**
 * Returns the native representation of the given Java object
 */
textureReference getTextureReference(JNIEnv *env, jobject texref)
{
    textureReference nativeTexref;
    nativeTexref.normalized  = (int)                   env->GetIntField(texref, textureReference_normalized);
    nativeTexref.filterMode  = (cudaTextureFilterMode) env->GetIntField(texref, textureReference_filterMode);

    jintArray addressMode = (jintArray)env->GetObjectField(texref, textureReference_addressMode);
    jint *nativeAddressMode = (jint*)env->GetPrimitiveArrayCritical(addressMode, NULL);
     if (nativeAddressMode == NULL)
    {
       return nativeTexref;
    }
    for (int i=0; i<3; i++)
    {
        nativeTexref.addressMode[i] = (cudaTextureAddressMode)nativeAddressMode[i];
    }
    env->ReleasePrimitiveArrayCritical(addressMode, nativeAddressMode, JNI_ABORT);

    jobject channelDesc = env->GetObjectField(texref, textureReference_channelDesc);
    nativeTexref.channelDesc = getCudaChannelFormatDesc(env, channelDesc);
    nativeTexref.sRGB                = (int)                   env->GetIntField(texref, textureReference_sRGB);
    nativeTexref.maxAnisotropy       = (unsigned int)          env->GetIntField(texref, textureReference_maxAnisotropy);
    nativeTexref.mipmapFilterMode    = (cudaTextureFilterMode) env->GetIntField(texref, textureReference_mipmapFilterMode);
    nativeTexref.mipmapLevelBias     = (float)                 env->GetIntField(texref, textureReference_mipmapLevelBias);
    nativeTexref.minMipmapLevelClamp = (float)                 env->GetIntField(texref, textureReference_minMipmapLevelClamp);
    nativeTexref.maxMipmapLevelClamp = (float)                 env->GetIntField(texref, textureReference_maxMipmapLevelClamp);

    return nativeTexref;
}


/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setTextureReference(JNIEnv *env, jobject texref, textureReference nativeTexref)
{
    env->SetIntField(texref, textureReference_normalized, (jint)nativeTexref.normalized);
    env->SetIntField(texref, textureReference_filterMode, (jint)nativeTexref.filterMode);

    jintArray addressMode = (jintArray)env->GetObjectField(texref, textureReference_addressMode);
    jint *nativeAddressMode = (jint*)env->GetPrimitiveArrayCritical(addressMode, NULL);
     if (nativeAddressMode == NULL)
    {
       return;
    }
    for (int i=0; i<3; i++)
    {
        nativeAddressMode[i] = (jint)nativeTexref.addressMode[i];
    }
    env->ReleasePrimitiveArrayCritical(addressMode, nativeAddressMode, 0);

    jobject channelDesc = env->GetObjectField(texref, textureReference_channelDesc);
    setCudaChannelFormatDesc(env, channelDesc, nativeTexref.channelDesc);

    env->SetIntField(texref,   textureReference_sRGB,                (jint) nativeTexref.sRGB);
    env->SetIntField(texref,   textureReference_maxAnisotropy,       (jint) nativeTexref.maxAnisotropy);
    env->SetIntField(texref,   textureReference_mipmapFilterMode,    (jint) nativeTexref.mipmapFilterMode);
    env->SetFloatField(texref, textureReference_mipmapLevelBias,     (jfloat)nativeTexref.mipmapLevelBias);
    env->SetFloatField(texref, textureReference_minMipmapLevelClamp, (jfloat)nativeTexref.minMipmapLevelClamp);
    env->SetFloatField(texref, textureReference_maxMipmapLevelClamp, (jfloat)nativeTexref.maxMipmapLevelClamp);

}



/**
 * Returns the native representation of the given Java object
 */
surfaceReference getSurfaceReference(JNIEnv *env, jobject surfref)
{
    surfaceReference nativeSurfref;
    jobject channelDesc = env->GetObjectField(surfref, surfaceReference_channelDesc);
    nativeSurfref.channelDesc = getCudaChannelFormatDesc(env, channelDesc);
    return nativeSurfref;
}


/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setSurfaceReference(JNIEnv *env, jobject surfref, surfaceReference nativeSurfref)
{
    jobject channelDesc = env->GetObjectField(surfref, surfaceReference_channelDesc);
    setCudaChannelFormatDesc(env, channelDesc, nativeSurfref.channelDesc);
}



/**
 * Returns the native representation of the given Java object
 */
dim3 getDim3(JNIEnv *env, jobject dim)
{
    dim3 nativeDim;
    nativeDim.x  = (unsigned int)env->GetIntField(dim, dim3_x);
    nativeDim.y  = (unsigned int)env->GetIntField(dim, dim3_y);
    nativeDim.z  = (unsigned int)env->GetIntField(dim, dim3_z);
    return nativeDim;
}





/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCudaFuncAttributes(JNIEnv *env, jobject attr, cudaFuncAttributes nativeAttr)
{
    env->SetLongField(attr, cudaFuncAttributes_sharedSizeBytes,    (jlong)nativeAttr.sharedSizeBytes);
    env->SetLongField(attr, cudaFuncAttributes_constSizeBytes,     (jlong)nativeAttr.constSizeBytes);
    env->SetLongField(attr, cudaFuncAttributes_localSizeBytes,     (jlong)nativeAttr.localSizeBytes);

    env->SetIntField( attr, cudaFuncAttributes_maxThreadsPerBlock, (jint) nativeAttr.maxThreadsPerBlock);
    env->SetIntField( attr, cudaFuncAttributes_numRegs,            (jint) nativeAttr.numRegs);

    env->SetIntField( attr, cudaFuncAttributes_ptxVersion,         (jint) nativeAttr.ptxVersion);
    env->SetIntField( attr, cudaFuncAttributes_binaryVersion,      (jint) nativeAttr.binaryVersion);
    env->SetIntField( attr, cudaFuncAttributes_cacheModeCA,        (jint) nativeAttr.cacheModeCA);
}




/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
bool setCudaPointerAttributes(JNIEnv *env, jobject attributes, cudaPointerAttributes nativeAttributes)
{
    env->SetIntField(attributes, cudaPointerAttributes_memoryType, (jint)nativeAttributes.memoryType);
    env->SetIntField(attributes, cudaPointerAttributes_device, (jint)nativeAttributes.device);

    jobject devicePointerObject = env->GetObjectField(attributes, cudaPointerAttributes_devicePointer);
    if (devicePointerObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Field 'devicePointer' is null for cudaPointerAttributes");
        return false;
    }
    setPointer(env, devicePointerObject, (jlong)nativeAttributes.devicePointer);

    jobject hostPointerObject = env->GetObjectField(attributes, cudaPointerAttributes_hostPointer);
    if (hostPointerObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Field 'hostPointer' is null for cudaPointerAttributes");
        return false;
    }
    setPointer(env, hostPointerObject, (jlong)nativeAttributes.hostPointer);

    env->SetIntField(attributes, cudaPointerAttributes_isManaged, (jint)nativeAttributes.isManaged);
    return true;
}


/**
 * Returns the native representation of the given Java object
 */
cudaIpcEventHandle_t getCudaIpcEventHandle(JNIEnv *env, jobject handle)
{
    cudaIpcEventHandle_t nativeHandle;

    jobject reservedObject = env->GetObjectField(handle, cudaIpcEventHandle_reserved);
    jbyteArray reserved = (jbyteArray)reservedObject;
    int len = env->GetArrayLength(reserved); // Should always be CUDA_IPC_HANDLE_SIZE
    char *reservedData = (char*)env->GetPrimitiveArrayCritical(reserved, NULL);
    if (reservedData == NULL)
    {
        return nativeHandle;
    }
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
void setCudaIpcEventHandle(JNIEnv *env, jobject handle, cudaIpcEventHandle_t &nativeHandle)
{
    jobject reservedObject = env->GetObjectField(handle, cudaIpcEventHandle_reserved);
    jbyteArray reserved = (jbyteArray)reservedObject;
    int len = env->GetArrayLength(reserved); // Should always be CUDA_IPC_HANDLE_SIZE
    char *reservedData = (char*)env->GetPrimitiveArrayCritical(reserved, NULL);
    if (reservedData == NULL)
    {
        return;
    }
    for (int i=0; i<len; i++)
    {
        reservedData[i] = nativeHandle.reserved[i];
    }
    env->ReleasePrimitiveArrayCritical(reserved, reservedData, 0);
}





/**
 * Returns the native representation of the given Java object
 */
cudaIpcMemHandle_t getCudaIpcMemHandle(JNIEnv *env, jobject handle)
{
    cudaIpcMemHandle_t nativeHandle;

    jobject reservedObject = env->GetObjectField(handle, cudaIpcMemHandle_reserved);
    jbyteArray reserved = (jbyteArray)reservedObject;
    int len = env->GetArrayLength(reserved); // Should always be CUDA_IPC_HANDLE_SIZE
    char *reservedData = (char*)env->GetPrimitiveArrayCritical(reserved, NULL);
    if (reservedData == NULL)
    {
        return nativeHandle;
    }
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
void setCudaIpcMemHandle(JNIEnv *env, jobject handle, cudaIpcMemHandle_t &nativeHandle)
{
    jobject reservedObject = env->GetObjectField(handle, cudaIpcMemHandle_reserved);
    jbyteArray reserved = (jbyteArray)reservedObject;
    int len = env->GetArrayLength(reserved); // Should always be CUDA_IPC_HANDLE_SIZE
    char *reservedData = (char*)env->GetPrimitiveArrayCritical(reserved, NULL);
    if (reservedData == NULL)
    {
        return;
    }
    for (int i=0; i<len; i++)
    {
        reservedData[i] = nativeHandle.reserved[i];
    }
    env->ReleasePrimitiveArrayCritical(reserved, reservedData, 0);
}








/**
 * Returns the native representation of the given Java object
 */
cudaResourceDesc getCudaResourceDesc(JNIEnv *env, jobject resourceDesc)
{
    cudaResourceDesc nativeResourceDesc;
    memset(&nativeResourceDesc,0,sizeof(cudaResourceDesc));

    nativeResourceDesc.resType = (cudaResourceType) env->GetIntField(resourceDesc, cudaResourceDesc_resType);

    jobject array_array = NULL;
    jobject mipmap_mipmap = NULL;
    jobject linear_devPtr = NULL;
    jobject linear_desc = NULL;
    jobject pitch2D_devPtr = NULL;
    jobject pitch2D_desc = NULL;
    switch (nativeResourceDesc.resType)
    {
        case cudaResourceTypeArray:
            array_array = env->GetObjectField(resourceDesc, cudaResourceDesc_array_array);
            nativeResourceDesc.res.array.array = (cudaArray*)getNativePointerValue(env, array_array);
            break;

        case cudaResourceTypeMipmappedArray:
            mipmap_mipmap = env->GetObjectField(resourceDesc, cudaResourceDesc_mipmap_mipmap);
            nativeResourceDesc.res.mipmap.mipmap = (cudaMipmappedArray*)getNativePointerValue(env, mipmap_mipmap);
            break;

        case cudaResourceTypeLinear:
            linear_devPtr = env->GetObjectField(resourceDesc, cudaResourceDesc_linear_devPtr);
            nativeResourceDesc.res.linear.devPtr = (void*)getNativePointerValue(env, linear_devPtr);
            linear_desc = env->GetObjectField(resourceDesc, cudaResourceDesc_linear_desc);
            nativeResourceDesc.res.linear.desc = getCudaChannelFormatDesc(env, linear_desc);
            nativeResourceDesc.res.linear.sizeInBytes = (size_t)env->GetLongField(resourceDesc, cudaResourceDesc_linear_sizeInBytes);
            break;

        case cudaResourceTypePitch2D:
            pitch2D_devPtr = env->GetObjectField(resourceDesc, cudaResourceDesc_pitch2D_devPtr);
            nativeResourceDesc.res.pitch2D.devPtr = (void*)getNativePointerValue(env, pitch2D_devPtr);
            pitch2D_desc = env->GetObjectField(resourceDesc, cudaResourceDesc_pitch2D_desc);
            nativeResourceDesc.res.pitch2D.desc = getCudaChannelFormatDesc(env, pitch2D_desc);
            nativeResourceDesc.res.pitch2D.width = (size_t)env->GetLongField(resourceDesc, cudaResourceDesc_pitch2D_width);
            nativeResourceDesc.res.pitch2D.height = (size_t)env->GetLongField(resourceDesc, cudaResourceDesc_pitch2D_height);
            nativeResourceDesc.res.pitch2D.pitchInBytes = (size_t)env->GetLongField(resourceDesc, cudaResourceDesc_pitch2D_pitchInBytes);
            break;
    }

    return nativeResourceDesc;
}


/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCudaResourceDesc(JNIEnv *env, jobject resourceDesc, cudaResourceDesc &nativeResourceDesc)
{
    env->SetIntField(resourceDesc, cudaResourceDesc_resType, (jint)nativeResourceDesc.resType);

    jobject array_array = NULL;
    jobject mipmap_mipmap = NULL;
    jobject linear_devPtr = NULL;
    jobject linear_desc = NULL;
    jobject pitch2D_devPtr = NULL;
    jobject pitch2D_desc = NULL;
    switch (nativeResourceDesc.resType)
    {
        case cudaResourceTypeArray:
            array_array = env->GetObjectField(resourceDesc, cudaResourceDesc_array_array);
            setNativePointerValue(env, array_array, (jlong)nativeResourceDesc.res.array.array);
            break;

        case cudaResourceTypeMipmappedArray:
            mipmap_mipmap = env->GetObjectField(resourceDesc, cudaResourceDesc_mipmap_mipmap);
            setNativePointerValue(env, mipmap_mipmap, (jlong)nativeResourceDesc.res.mipmap.mipmap);
            break;

        case cudaResourceTypeLinear:
            linear_devPtr = env->GetObjectField(resourceDesc, cudaResourceDesc_linear_devPtr);
            setNativePointerValue(env, linear_devPtr, (jlong)nativeResourceDesc.res.linear.devPtr);
            linear_desc = env->GetObjectField(resourceDesc, cudaResourceDesc_linear_desc);
            setCudaChannelFormatDesc(env, linear_desc, nativeResourceDesc.res.linear.desc);
            env->SetLongField(resourceDesc, cudaResourceDesc_linear_sizeInBytes, (jlong)nativeResourceDesc.res.linear.sizeInBytes);
            break;

        case cudaResourceTypePitch2D:
            pitch2D_devPtr = env->GetObjectField(resourceDesc, cudaResourceDesc_pitch2D_devPtr);
            setNativePointerValue(env, pitch2D_devPtr, (jlong)nativeResourceDesc.res.pitch2D.devPtr);
            pitch2D_desc = env->GetObjectField(resourceDesc, cudaResourceDesc_pitch2D_desc);
            setCudaChannelFormatDesc(env, pitch2D_desc, nativeResourceDesc.res.pitch2D.desc);
            env->SetLongField(resourceDesc, cudaResourceDesc_pitch2D_width, nativeResourceDesc.res.pitch2D.width);
            env->SetLongField(resourceDesc, cudaResourceDesc_pitch2D_height, nativeResourceDesc.res.pitch2D.height);
            env->SetLongField(resourceDesc, cudaResourceDesc_pitch2D_pitchInBytes, nativeResourceDesc.res.pitch2D.pitchInBytes);
            break;
    }

}






/**
 * Returns the native representation of the given Java object
 */
cudaResourceViewDesc getCudaResourceViewDesc(JNIEnv *env, jobject resourceViewDesc)
{
    cudaResourceViewDesc nativeResourceViewDesc;
    memset(&nativeResourceViewDesc,0,sizeof(cudaResourceViewDesc));

    nativeResourceViewDesc.format = (cudaResourceViewFormat) env->GetIntField(resourceViewDesc, cudaResourceViewDesc_format);
    nativeResourceViewDesc.width = (size_t)env->GetLongField(resourceViewDesc, cudaResourceViewDesc_width);
    nativeResourceViewDesc.height = (size_t)env->GetLongField(resourceViewDesc, cudaResourceViewDesc_height);
    nativeResourceViewDesc.depth = (size_t)env->GetLongField(resourceViewDesc, cudaResourceViewDesc_depth);
    nativeResourceViewDesc.firstMipmapLevel = (unsigned int)env->GetIntField(resourceViewDesc, cudaResourceViewDesc_firstMipmapLevel);
    nativeResourceViewDesc.lastMipmapLevel = (unsigned int)env->GetIntField(resourceViewDesc, cudaResourceViewDesc_lastMipmapLevel);
    nativeResourceViewDesc.firstLayer = (unsigned int)env->GetIntField(resourceViewDesc, cudaResourceViewDesc_firstLayer);
    nativeResourceViewDesc.lastLayer = (unsigned int)env->GetIntField(resourceViewDesc, cudaResourceViewDesc_lastLayer);

    return nativeResourceViewDesc;
}




/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCudaResourceViewDesc(JNIEnv *env, jobject resourceViewDesc, cudaResourceViewDesc &nativeResourceViewDesc)
{
    env->SetIntField(resourceViewDesc, cudaResourceViewDesc_format, (jint)nativeResourceViewDesc.format);
    env->SetLongField(resourceViewDesc, cudaResourceViewDesc_width, (jlong)nativeResourceViewDesc.width);
    env->SetLongField(resourceViewDesc, cudaResourceViewDesc_height, (jlong)nativeResourceViewDesc.height);
    env->SetLongField(resourceViewDesc, cudaResourceViewDesc_depth, (jlong)nativeResourceViewDesc.depth);
    env->SetIntField(resourceViewDesc, cudaResourceViewDesc_firstMipmapLevel, (jint)nativeResourceViewDesc.firstMipmapLevel);
    env->SetIntField(resourceViewDesc, cudaResourceViewDesc_lastMipmapLevel, (jint)nativeResourceViewDesc.lastMipmapLevel);
    env->SetIntField(resourceViewDesc, cudaResourceViewDesc_firstLayer, (jint)nativeResourceViewDesc.firstLayer);
    env->SetIntField(resourceViewDesc, cudaResourceViewDesc_lastLayer, (jint)nativeResourceViewDesc.lastLayer);
}



/**
 * Returns the native representation of the given Java object
 */
cudaTextureDesc getCudaTextureDesc(JNIEnv *env, jobject texDesc)
{
    cudaTextureDesc nativeTexDesc;
    memset(&nativeTexDesc,0,sizeof(cudaTextureDesc));

    jintArray addressMode = (jintArray)env->GetObjectField(texDesc, cudaTextureDesc_addressMode);
    jint *nativeAddressMode = (jint*)env->GetPrimitiveArrayCritical(addressMode, NULL);
    if (nativeAddressMode == NULL)
    {
        return nativeTexDesc;
    }
    for (int i=0; i<3; i++)
    {
        nativeTexDesc.addressMode[i] = (cudaTextureAddressMode)nativeAddressMode[i];
    }
    env->ReleasePrimitiveArrayCritical(addressMode, nativeAddressMode, JNI_ABORT);

    nativeTexDesc.filterMode = (cudaTextureFilterMode) env->GetIntField(texDesc, cudaTextureDesc_filterMode);
    nativeTexDesc.readMode = (cudaTextureReadMode) env->GetIntField(texDesc, cudaTextureDesc_readMode);
    nativeTexDesc.sRGB = (int) env->GetIntField(texDesc, cudaTextureDesc_sRGB);

    jfloatArray borderColor = (jfloatArray)env->GetObjectField(texDesc, cudaTextureDesc_borderColor);
    jfloat *nativeBorderColor = (jfloat*)env->GetPrimitiveArrayCritical(borderColor, NULL);
    if (nativeBorderColor == NULL)
    {
        return nativeTexDesc;
    }
    for (int i = 0; i<4; i++)
    {
        nativeTexDesc.borderColor[i] = (float)nativeBorderColor[i];
    }
    env->ReleasePrimitiveArrayCritical(borderColor, nativeBorderColor, JNI_ABORT);

    nativeTexDesc.normalizedCoords = (int) env->GetIntField(texDesc, cudaTextureDesc_normalizedCoords);
    nativeTexDesc.maxAnisotropy = (unsigned int) env->GetIntField(texDesc, cudaTextureDesc_maxAnisotropy);
    nativeTexDesc.mipmapFilterMode = (cudaTextureFilterMode) env->GetIntField(texDesc, cudaTextureDesc_mipmapFilterMode);
    nativeTexDesc.mipmapLevelBias = (float)env->GetFloatField(texDesc, cudaTextureDesc_mipmapLevelBias);
    nativeTexDesc.minMipmapLevelClamp = (float)env->GetFloatField(texDesc, cudaTextureDesc_minMipmapLevelClamp);
    nativeTexDesc.maxMipmapLevelClamp = (float)env->GetFloatField(texDesc, cudaTextureDesc_maxMipmapLevelClamp);

    return nativeTexDesc;
}


/**
 * Assigns the properties of the given native structure to the given
 * Java Object
 */
void setCudaTextureDesc(JNIEnv *env, jobject texDesc, cudaTextureDesc &nativeTexDesc)
{
    jintArray addressMode = (jintArray)env->GetObjectField(texDesc, cudaTextureDesc_addressMode);
    jint *nativeAddressMode = (jint*)env->GetPrimitiveArrayCritical(addressMode, NULL);
    if (nativeAddressMode == NULL)
    {
        return;
    }
    for (int i=0; i<3; i++)
    {
         nativeAddressMode[i] = (jint)nativeTexDesc.addressMode[i];
    }
    env->ReleasePrimitiveArrayCritical(addressMode, nativeAddressMode, 0);

    env->SetIntField(texDesc, cudaTextureDesc_filterMode, (jint)nativeTexDesc.filterMode);
    env->SetIntField(texDesc, cudaTextureDesc_readMode, (jint)nativeTexDesc.readMode);
    env->SetIntField(texDesc, cudaTextureDesc_sRGB, (jint)nativeTexDesc.sRGB);

    jfloatArray borderColor = (jfloatArray)env->GetObjectField(texDesc, cudaTextureDesc_borderColor);
    jfloat *nativeBorderColor = (jfloat*)env->GetPrimitiveArrayCritical(borderColor, NULL);
    if (nativeBorderColor == NULL)
    {
        return;
    }
    for (int i = 0; i<4; i++)
    {
        nativeBorderColor[i] = (jfloat)nativeTexDesc.borderColor[i];
    }
    env->ReleasePrimitiveArrayCritical(borderColor, nativeBorderColor, 0);

    env->SetIntField(texDesc, cudaTextureDesc_normalizedCoords, (jint)nativeTexDesc.normalizedCoords);
    env->SetIntField(texDesc, cudaTextureDesc_maxAnisotropy, (jint)nativeTexDesc.maxAnisotropy);
    env->SetIntField(texDesc, cudaTextureDesc_mipmapFilterMode, (jint)nativeTexDesc.mipmapFilterMode);
    env->SetFloatField(texDesc, cudaTextureDesc_mipmapLevelBias, (jfloat)nativeTexDesc.mipmapLevelBias);
    env->SetFloatField(texDesc, cudaTextureDesc_minMipmapLevelClamp, (jfloat)nativeTexDesc.minMipmapLevelClamp);
    env->SetFloatField(texDesc, cudaTextureDesc_maxMipmapLevelClamp, (jfloat)nativeTexDesc.maxMipmapLevelClamp);
}








//=== CUDA functions =========================================================


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceResetNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceResetNative
  (JNIEnv *env, jclass cls)
{
    Logger::log(LOG_TRACE, "Executing cudaDeviceReset\n");

    int result = cudaDeviceReset();
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceSynchronizeNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceSynchronizeNative
  (JNIEnv *env, jclass cls)
{
    Logger::log(LOG_TRACE, "Executing cudaDeviceSynchronize\n");

    int result = cudaDeviceSynchronize();
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceSetLimitNative
 * Signature: (IJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceSetLimitNative
  (JNIEnv *env, jclass cls, jint limit, jlong value)
{
    Logger::log(LOG_TRACE, "Executing cudaDeviceSetLimit\n");

    int result = cudaDeviceSetLimit((cudaLimit)limit, (size_t)value);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceGetLimitNative
 * Signature: ([JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceGetLimitNative
  (JNIEnv *env, jclass cls, jlongArray pValue, jint limit)
{
    if (pValue == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pValue' is null for cudaDeviceGetLimit");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaDeviceGetLimit\n");

    size_t nativePValue;
    int result = cudaDeviceGetLimit(&nativePValue, (cudaLimit)limit);
    if (!set(env, pValue, 0, (size_t)nativePValue)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceGetCacheConfigNative
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceGetCacheConfigNative
  (JNIEnv *env, jclass cls, jintArray pCacheConfig)
{
    if (pCacheConfig == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCacheConfig' is null for cudaDeviceGetCacheConfig");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaDeviceGetCacheConfig\n");

    cudaFuncCache nativePCacheConfig;
    int result = cudaDeviceGetCacheConfig(&nativePCacheConfig);
    if (!set(env, pCacheConfig, 0, (jint)nativePCacheConfig)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceSetCacheConfigNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceSetCacheConfigNative
  (JNIEnv *env, jclass cls, jint cacheConfig)
{
    Logger::log(LOG_TRACE, "Executing cudaDeviceSetCacheConfig\n");

    int result = cudaDeviceSetCacheConfig((cudaFuncCache)cacheConfig);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceGetStreamPriorityRangeNative
 * Signature: ([I[I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceGetStreamPriorityRangeNative
  (JNIEnv *env, jclass cls, jintArray leastPriority, jintArray greatestPriority)
{
    if (leastPriority == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'leastPriority' is null for cudaDeviceGetStreamPriorityRange");
        return CUDA_INTERNAL_ERROR;
    }
    if (greatestPriority == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'greatestPriority' is null for cudaDeviceGetStreamPriorityRange");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaDeviceGetStreamPriorityRange\n");

    int nativeLeastPriority;
    int nativeGreatestPriority;
    int result = cudaDeviceGetStreamPriorityRange(&nativeLeastPriority, &nativeGreatestPriority);
    if (!set(env, leastPriority, 0, (jint)nativeLeastPriority)) return CUDA_INTERNAL_ERROR;
    if (!set(env, greatestPriority, 0, (jint)nativeGreatestPriority)) return CUDA_INTERNAL_ERROR;
    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceGetSharedMemConfigNative
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceGetSharedMemConfigNative
  (JNIEnv *env, jclass cls, jintArray pConfig)
{
    if (pConfig == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pConfig' is null for cudaDeviceGetSharedMemConfig");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaDeviceGetSharedMemConfig\n");

    cudaSharedMemConfig nativePConfig;
    int result = cudaDeviceGetSharedMemConfig(&nativePConfig);
    if (!set(env, pConfig, 0, (jint)nativePConfig)) return CUDA_INTERNAL_ERROR;
    return result;

}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceSetSharedMemConfigNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceSetSharedMemConfigNative
  (JNIEnv *env, jclass cls, jint config)
{
    Logger::log(LOG_TRACE, "Executing cudaDeviceSetSharedMemConfig\n");

    int result = cudaDeviceSetSharedMemConfig((cudaSharedMemConfig)config);
    return result;
}





/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceGetByPCIBusIdNative
 * Signature: ([ILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceGetByPCIBusIdNative
  (JNIEnv *env, jclass cls, jintArray device, jstring pciBusId)
{
    if (device == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'device' is null for cudaDeviceGetByPCIBusId");
        return CUDA_INTERNAL_ERROR;
    }
    if (pciBusId == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pciBusId' is null for cudaDeviceGetByPCIBusId");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaDeviceGetByPCIBusId\n");

    char *nativePciBusId = convertString(env, pciBusId);

    int nativeDevice = 0;
    int result = cudaDeviceGetByPCIBusId(&nativeDevice, nativePciBusId);

    if (!set(env, device, 0, (jint)nativeDevice)) return CUDA_INTERNAL_ERROR;
    delete[] nativePciBusId;

    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceGetPCIBusIdNative
 * Signature: ([Ljava/lang/String;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceGetPCIBusIdNative
  (JNIEnv *env, jclass cls, jobjectArray pciBusId, jint len, jint device)
{
    if (pciBusId == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pciBusId' is null for cudaDeviceGetPCIBusId");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaDeviceGetPCIBusId\n");

    char *nativePciBusId = new char[(int)len];
    int result = cudaDeviceGetPCIBusId(nativePciBusId, (int)len, (int)device);

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
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaIpcGetEventHandleNative
 * Signature: (LCUDAWrapper/runtime/cudaIpcEventHandle;LCUDAWrapper/runtime/cudaEvent_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaIpcGetEventHandleNative
  (JNIEnv *env, jclass cls, jobject handle, jobject event)
{
    if (handle == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'handle' is null for cudaIpcGetEventHandle");
        return CUDA_INTERNAL_ERROR;
    }
    if (event == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'event' is null for cudaIpcGetEventHandle");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaIpcGetEventHandle\n");

    cudaEvent_t nativeEvent = (cudaEvent_t)getNativePointerValue(env, event);
    cudaIpcEventHandle_t nativeHandle;

    int result = cudaIpcGetEventHandle(&nativeHandle, nativeEvent);
    setCudaIpcEventHandle(env, handle, nativeHandle);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaIpcOpenEventHandleNative
 * Signature: (LCUDAWrapper/runtime/cudaEvent_t;LCUDAWrapper/runtime/cudaIpcEventHandle;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaIpcOpenEventHandleNative
  (JNIEnv *env, jclass cls, jobject event, jobject handle)
{
    if (event == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'event' is null for cudaIpcOpenEventHandle");
        return CUDA_INTERNAL_ERROR;
    }
    if (handle == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'handle' is null for cudaIpcOpenEventHandle");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaIpcOpenEventHandle\n");

    cudaEvent_t nativeEvent;
    cudaIpcEventHandle_t nativeHandle = getCudaIpcEventHandle(env, handle);
    int result = cudaIpcOpenEventHandle(&nativeEvent, nativeHandle);

    setNativePointerValue(env, event, (jlong)nativeEvent);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaIpcGetMemHandleNative
 * Signature: (LCUDAWrapper/runtime/cudaIpcMemHandle;LCUDAWrapper/Pointer;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaIpcGetMemHandleNative
  (JNIEnv *env, jclass cls, jobject handle, jobject devPtr)
{
    if (handle == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'handle' is null for cudaIpcGetMemHandle");
        return CUDA_INTERNAL_ERROR;
    }
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaIpcGetMemHandle");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaIpcGetMemHandle\n");

    cudaIpcMemHandle_t nativeHandle;
    void* nativeDevPtr = getPointer(env, devPtr);

    int result = cudaIpcGetMemHandle(&nativeHandle, nativeDevPtr);
    setCudaIpcMemHandle(env, handle, nativeHandle);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaIpcOpenMemHandleNative
 * Signature: (LCUDAWrapper/Pointer;LCUDAWrapper/runtime/cudaIpcMemHandle;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaIpcOpenMemHandleNative
  (JNIEnv *env, jclass cls, jobject devPtr, jobject handle, jint flags)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaIpcOpenMemHandle");
        return CUDA_INTERNAL_ERROR;
    }
    if (handle == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'handle' is null for cudaIpcOpenMemHandle");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaIpcOpenMemHandle\n");

    cudaIpcMemHandle_t nativeHandle = getCudaIpcMemHandle(env, handle);
    void* nativeDevPtr = NULL;

    int result = cudaIpcOpenMemHandle(&nativeDevPtr, nativeHandle, (unsigned int)flags);

    setPointer(env, devPtr, (jlong)nativeDevPtr);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaIpcCloseMemHandleNative
 * Signature: (LCUDAWrapper/Pointer;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaIpcCloseMemHandleNative
  (JNIEnv *env, jclass cls, jobject devPtr)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaIpcCloseMemHandle");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaIpcCloseMemHandle\n");

    void* nativeDevPtr = getPointer(env, devPtr);

    int result = cudaIpcCloseMemHandle(nativeDevPtr);
    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetDeviceCountNative
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetDeviceCountNative
  (JNIEnv *env, jclass cls, jintArray count)
{
    if (count == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'count' is null for cudaGetDeviceCount");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGetDeviceCount\n");

    int nativeCount = 0;
    int result = cudaGetDeviceCount(&nativeCount);
    if (!set(env, count, 0, nativeCount)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaSetDeviceNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaSetDeviceNative
  (JNIEnv *env, jclass cls, jint device)
{
    Logger::log(LOG_TRACE, "Executing cudaSetDevice\n");

    return cudaSetDevice(device);
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaSetDeviceFlagsNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaSetDeviceFlagsNative
  (JNIEnv *env, jclass cls, jint flags)
{
    Logger::log(LOG_TRACE, "Executing cudaSetDeviceFlags\n");

    return cudaSetDeviceFlags((int)flags);
}


/*
* Class:     CUDAWrapper_runtime_CUDAWrapper
* Method:    cudaGetDeviceFlagsNative
* Signature: ([I)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetDeviceFlagsNative
  (JNIEnv *env, jclass cls, jintArray flags)
{
    if (flags == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'flags' is null for cudaGetDeviceFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGetDeviceFlags\n");

    unsigned int nativeFlags = 0;
    int result = cudaGetDeviceFlags(&nativeFlags);
    if (!set(env, flags, 0, (jint)nativeFlags)) return CUDA_INTERNAL_ERROR;
    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaSetValidDevicesNative
 * Signature: ([II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaSetValidDevicesNative
  (JNIEnv *env, jclass cls, jintArray device_arr, jint len)
{
    if (device_arr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'device_arr' is null for cudaSetValidDevices");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaSetValidDevices\n");

    jint *device_arrElements = (jint*)env->GetPrimitiveArrayCritical(device_arr, NULL);
    if (device_arrElements == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int *nativeDevice_arr = new int[len];
    for (int i=0; i<len; i++)
    {
        nativeDevice_arr[i] = (int)device_arrElements[i];
    }
    env->ReleasePrimitiveArrayCritical(device_arr, device_arrElements, JNI_ABORT);

    int result = cudaSetValidDevices(nativeDevice_arr, (int)len);

    delete[] nativeDevice_arr;
    return result;
}







/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetDeviceNative
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetDeviceNative
  (JNIEnv *env, jclass cls, jintArray device)
{
    if (device == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'device' is null for cudaGetDevice");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGetDevice\n");

    int nativeDevice = 0;
    int result = cudaGetDevice(&nativeDevice);
    if (!set(env, device, 0, nativeDevice)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetDevicePropertiesNative
 * Signature: (LCUDAWrapper/runtime/cudaDeviceProp;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetDevicePropertiesNative
  (JNIEnv *env, jclass cls, jobject prop, jint device)
{
    if (prop == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'prop' is null for cudaGetDeviceProperties");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGetDeviceProperties\n");

    cudaDeviceProp nativeProp;
    int result = cudaGetDeviceProperties(&nativeProp, device);

    setCudaDeviceProp(env, prop, nativeProp);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceGetAttributeNative
 * Signature: ([III)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceGetAttributeNative
  (JNIEnv *env, jclass cls, jintArray value, jint attr, jint device)
{
    if (value == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'value' is null for cudaDeviceGetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaDeviceGetAttribute\n");

    int nativeValue = 0;
    int result = cudaDeviceGetAttribute(&nativeValue, (cudaDeviceAttr)attr, (int)device);
    if (!set(env, value, 0, nativeValue)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
* Class:     CUDAWrapper_runtime_CUDAWrapper
* Method:    cudaDeviceGetP2PAttributeNative
* Signature: ([IIII)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceGetP2PAttributeNative
(JNIEnv *env, jclass cls, jintArray value, jint attr, jint srcDevice, jint dstDevice)
{
    if (value == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'value' is null for cudaDeviceGetP2PAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaDeviceGetP2PAttribute\n");

    int nativeValue = 0;
    int result = cudaDeviceGetP2PAttribute(&nativeValue, (cudaDeviceP2PAttr)attr, (int)srcDevice, (int)dstDevice);
    if (!set(env, value, 0, nativeValue)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaChooseDeviceNative
 * Signature: ([ILCUDAWrapper/runtime/cudaDeviceProp;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaChooseDeviceNative
  (JNIEnv *env, jclass cls, jintArray device, jobject prop)
{
    if (device == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'device' is null for cudaChooseDevice");
        return CUDA_INTERNAL_ERROR;
    }
    if (prop == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'prop' is null for cudaChooseDevice");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaChooseDevice\n");

    int nativeDevice;
    cudaDeviceProp nativeProp = getCudaDeviceProp(env, prop);
    int result = cudaChooseDevice(&nativeDevice, &nativeProp);
    if (!set(env, device, 0, nativeDevice)) return CUDA_INTERNAL_ERROR;
    return result;
}










//=== Memory Management ======================================================


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaHostAllocNative
 * Signature: (LCUDAWrapper/Pointer;JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaHostAllocNative
  (JNIEnv *env, jclass cls, jobject ptr, jlong size, jint flags)
{
    if (ptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ptr' is null for cudaHostAlloc");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaHostAlloc\n");

    void *nativePtr;
    int result = cudaHostAlloc(&nativePtr, (size_t)size, (unsigned int)flags);
    if (result == cudaSuccess)
    {
        jobject object = env->NewDirectByteBuffer(nativePtr, size);
        env->SetObjectField(ptr, Pointer_buffer, object);
        env->SetObjectField(ptr, Pointer_pointers, NULL);
        env->SetLongField(ptr, Pointer_byteOffset, 0);
        env->SetLongField(ptr, NativePointerObject_nativePointer, (jlong)nativePtr);
    }
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaHostRegisterNative
 * Signature: (LCUDAWrapper/Pointer;JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaHostRegisterNative
  (JNIEnv *env, jclass cls, jobject ptr, jlong size, jint flags)
{
    if (ptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ptr' is null for cudaHostRegister");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaHostRegister\n");

    if (!isPointerBackedByNativeMemory(env, ptr))
    {
        ThrowByName(env, "java/lang/IllegalArgumentException",
            "Pointer must point to a direct buffer or native memory");
        return CUDA_INTERNAL_ERROR;
    }

    PointerData *ptrPointerData = initPointerData(env, ptr);
    if (ptrPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cudaHostRegister((void*)ptrPointerData->getPointer(env), (size_t)size, (unsigned int)flags);
    if (!releasePointerData(env, ptrPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;

}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaHostUnregisterNative
 * Signature: (LCUDAWrapper/Pointer;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaHostUnregisterNative
  (JNIEnv *env, jclass cls, jobject ptr)
{
    if (ptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ptr' is null for cudaHostUnregister");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaHostUnregister\n");

    PointerData *ptrPointerData = initPointerData(env, ptr);
    if (ptrPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    int result = cudaHostUnregister((void*)ptrPointerData->getPointer(env));
    if (!releasePointerData(env, ptrPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;

}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaHostGetDevicePointerNative
 * Signature: (LCUDAWrapper/Pointer;LCUDAWrapper/Pointer;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaHostGetDevicePointerNative
  (JNIEnv *env, jclass cls, jobject pDevice, jobject pHost, jint flags)
{
    if (pDevice == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pDevice' is null for cudaHostGetDevicePointer");
        return CUDA_INTERNAL_ERROR;
    }
    if (pHost == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pHost' is null for cudaHostGetDevicePointer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaHostGetDevicePointer\n");

    void *nativePDevice;

    void *nativePHost = getPointer(env, pHost);
    int result = cudaHostGetDevicePointer(&nativePDevice, nativePHost, (unsigned int)flags);
    setPointer(env, pDevice, (jlong)nativePDevice);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMallocManagedNative
 * Signature: (LCUDAWrapper/Pointer;JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMallocManagedNative
  (JNIEnv *env, jclass cls, jobject devPtr, jlong size, jint flags)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaMallocManaged");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMallocManaged of %ld bytes\n", (long)size);

    void *nativeDevPtr = NULL;
    int result = cudaMallocManaged(&nativeDevPtr, (size_t)size, (unsigned int)flags);
    if (result == cudaSuccess)
    {
        if (flags == cudaMemAttachHost)
        {
            jobject object = env->NewDirectByteBuffer(nativeDevPtr, size);
            env->SetObjectField(devPtr, Pointer_buffer, object);
            env->SetObjectField(devPtr, Pointer_pointers, NULL);
            env->SetLongField(devPtr, Pointer_byteOffset, 0);
        }
        env->SetLongField(devPtr, NativePointerObject_nativePointer, (jlong)nativeDevPtr);
    }

    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMallocNative
 * Signature: (LCUDAWrapper/Pointer;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMallocNative
  (JNIEnv *env, jclass cls, jobject devPtr, jlong size)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaMalloc");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMalloc of %ld bytes\n", (long)size);

    void *nativeDevPtr = NULL;
    int result = cudaMalloc(&nativeDevPtr, (size_t)size);
    setPointer(env, devPtr, (jlong)nativeDevPtr);

    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaFreeNative
 * Signature: (LCUDAWrapper/Pointer;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaFreeNative
  (JNIEnv *env, jclass cls, jobject devPtr)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaFree");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaFree\n");

    void *nativeDevPtr = NULL;
    nativeDevPtr = getPointer(env, devPtr);
    int result = cudaFree(nativeDevPtr);
    return result;
}









/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMalloc3DNative
 * Signature: (LCUDAWrapper/runtime/cudaPitchedPtr;LCUDAWrapper/runtime/cudaExtent;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMalloc3DNative
  (JNIEnv *env, jclass cls, jobject pitchDevPtr, jobject extent)
{
    if (pitchDevPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pitchDevPtr' is null for cudaMalloc3D");
        return CUDA_INTERNAL_ERROR;
    }
    if (extent == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'extent' is null for cudaMalloc3D");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMalloc3D\n");

    cudaExtent nativeExtent = getCudaExtent(env, extent);

    cudaPitchedPtr nativePitchDevPtr;
    int result = cudaMalloc3D(&nativePitchDevPtr, nativeExtent);

    setCudaPitchedPtr(env, pitchDevPtr, nativePitchDevPtr);

    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpyNative
 * Signature: (LCUDAWrapper/Pointer;LCUDAWrapper/Pointer;JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpyNative
  (JNIEnv *env, jclass cls, jobject dst, jobject src, jlong count, jint kind)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpy");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpy");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemcpy of %ld bytes\n", (long)count);

    // Obtain the destination and source pointers
    PointerData *dstPointerData = initPointerData(env, dst);
    if (dstPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    PointerData *srcPointerData = initPointerData(env, src);
    if (srcPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    // Execute the cudaMemcpy operation
    int result = CUDA_INTERNAL_ERROR;
    if (kind == cudaMemcpyHostToHost)
    {
        Logger::log(LOG_TRACE, "Copying %ld bytes from host to host\n", (long)count);
        result = cudaMemcpy((void*)dstPointerData->getPointer(env), (void*)srcPointerData->getPointer(env), (size_t)count, cudaMemcpyHostToHost);
    }
    else if (kind == cudaMemcpyHostToDevice)
    {
        Logger::log(LOG_TRACE, "Copying %ld bytes from host to device\n", (long)count);
        result = cudaMemcpy((void*)dstPointerData->getPointer(env), (void*)srcPointerData->getPointer(env), (size_t)count, cudaMemcpyHostToDevice);
    }
    else if (kind == cudaMemcpyDeviceToHost)
    {
        Logger::log(LOG_TRACE, "Copying %ld bytes from device to host\n", (long)count);
        result = cudaMemcpy((void*)dstPointerData->getPointer(env), (void*)srcPointerData->getPointer(env), (size_t)count, cudaMemcpyDeviceToHost);
    }
    else if (kind == cudaMemcpyDeviceToDevice)
    {
        Logger::log(LOG_TRACE, "Copying %ld bytes from device to device\n", (long)count);
        result = cudaMemcpy((void*)dstPointerData->getPointer(env), (void*)srcPointerData->getPointer(env), (size_t)count, cudaMemcpyDeviceToDevice);
    }
    else
    {
        Logger::log(LOG_ERROR, "Invalid cudaMemcpyKind given: %d\n", kind);
        return cudaErrorInvalidMemcpyDirection;
    }

    // Release the pointer data
    if (!releasePointerData(env, dstPointerData)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpyPeerNative
 * Signature: (LCUDAWrapper/Pointer;ILCUDAWrapper/Pointer;IJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpyPeerNative
  (JNIEnv *env, jclass cls, jobject dst, jint dstDevice, jobject src, jint srcDevice, jlong count)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpyPeer");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpyPeer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemcpyPeer of %ld bytes\n", (long)count);

    // Obtain the destination and source pointers
    PointerData *dstPointerData = initPointerData(env, dst);
    if (dstPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    PointerData *srcPointerData = initPointerData(env, src);
    if (srcPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cudaMemcpyPeer((void*)dstPointerData->getPointer(env), (int)dstDevice, (void*)srcPointerData->getPointer(env), (int)srcDevice, (size_t)count);

    // Release the pointer data
    if (!releasePointerData(env, dstPointerData)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}





/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMalloc3DArrayNative
 * Signature: (LCUDAWrapper/runtime/cudaArray;LCUDAWrapper/runtime/cudaChannelFormatDesc;LCUDAWrapper/runtime/cudaExtent;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMalloc3DArrayNative
  (JNIEnv *env, jclass cls, jobject arrayPtr, jobject desc, jobject extent, jint flags)
{
    if (arrayPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'arrayPtr' is null for cudaMalloc3DArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (desc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'desc' is null for cudaMalloc3DArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (extent == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'extent' is null for cudaMalloc3DArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMalloc3DArray\n");

    cudaChannelFormatDesc nativeDesc = getCudaChannelFormatDesc(env, desc);
    cudaExtent nativeExtent = getCudaExtent(env, extent);
    unsigned int nativeFlags = (unsigned int)flags;

    cudaArray *nativeArrayPtr;
    int result = cudaMalloc3DArray(&nativeArrayPtr, &nativeDesc, nativeExtent, nativeFlags);

    setNativePointerValue(env, arrayPtr, (jlong)nativeArrayPtr);

    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMallocMipmappedArrayNative
 * Signature: (LCUDAWrapper/runtime/cudaMipmappedArray;LCUDAWrapper/runtime/cudaChannelFormatDesc;LCUDAWrapper/runtime/cudaExtent;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMallocMipmappedArrayNative
  (JNIEnv *env, jclass cls, jobject mipmappedArray, jobject desc, jobject extent, jint numLevels, jint flags)
{
    if (mipmappedArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'mipmappedArray' is null for cudaMallocMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (desc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'desc' is null for cudaMallocMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (extent == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'extent' is null for cudaMallocMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMallocMipmappedArray\n");

    cudaChannelFormatDesc nativeDesc = getCudaChannelFormatDesc(env, desc);
    cudaExtent nativeExtent = getCudaExtent(env, extent);
    unsigned int nativeFlags = (unsigned int)flags;

    cudaMipmappedArray *nativeMipmappedArray = NULL;
    int result = cudaMallocMipmappedArray(&nativeMipmappedArray, &nativeDesc, nativeExtent, nativeFlags);

    setNativePointerValue(env, mipmappedArray, (jlong)nativeMipmappedArray);

    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetMipmappedArrayLevelNative
 * Signature: (LCUDAWrapper/runtime/cudaArray;LCUDAWrapper/runtime/cudaMipmappedArray;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetMipmappedArrayLevelNative
  (JNIEnv *env, jclass cls, jobject levelArray, jobject mipmappedArray, jint level)
{
    if (levelArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'levelArray' is null for cudaGetMipmappedArrayLevel");
        return CUDA_INTERNAL_ERROR;
    }
    if (mipmappedArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'mipmappedArray' is null for cudaGetMipmappedArrayLevel");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGetMipmappedArrayLevel\n");

    cudaArray *nativeLevelArray = NULL;
    cudaMipmappedArray *nativeMipmappedArray = (cudaMipmappedArray*)getNativePointerValue(env, mipmappedArray);

    int result = cudaGetMipmappedArrayLevel(&nativeLevelArray, nativeMipmappedArray, (unsigned int)level);

    setNativePointerValue(env, levelArray, (jlong)nativeLevelArray);

    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemset3DNative
 * Signature: (LCUDAWrapper/runtime/cudaPitchedPtr;ILCUDAWrapper/runtime/cudaExtent;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemset3DNative
  (JNIEnv *env, jclass cls, jobject pitchDevPtr, jint value, jobject extent)
{
    if (pitchDevPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pitchDevPtr' is null for cudaMemset3D");
        return CUDA_INTERNAL_ERROR;
    }
    if (extent == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'extent' is null for cudaMemset3D");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemset3D\n");

    PointerData* pointerData = NULL;
    cudaPitchedPtr nativePitchDevPtr = getCudaPitchedPtr(env, pitchDevPtr, pointerData);
    cudaExtent nativeExtent = getCudaExtent(env, extent);

    int result = cudaMemset3D(nativePitchDevPtr, (int)value, nativeExtent);

    if (!releasePointerData(env, pointerData, JNI_COMMIT)) return CUDA_INTERNAL_ERROR;

    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemsetAsyncNative
 * Signature: (LCUDAWrapper/Pointer;IJLCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemsetAsyncNative
  (JNIEnv *env, jclass cls, jobject devPtr, jint value, jlong count, jobject stream)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaMemsetAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaMemsetAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaMemsetAsync\n");

    void *nativeDevPtr = getPointer(env, devPtr);
    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    int result = cudaMemsetAsync(nativeDevPtr, (int)value, (size_t)count, nativeStream);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemset2DAsyncNative
 * Signature: (LCUDAWrapper/Pointer;JIJJLCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemset2DAsyncNative
  (JNIEnv *env, jclass cls, jobject devPtr, jlong pitch, jint value, jlong width, jlong height, jobject stream)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaMemset2DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaMemset2DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaMemset2DAsync\n");

    void *nativeDevPtr = getNativePointerValue(env, devPtr);
    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);
    int result = cudaMemset2DAsync(nativeDevPtr, (size_t)pitch, (int)value, (size_t)width, (size_t)height, nativeStream);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemset3DAsyncNative
 * Signature: (LCUDAWrapper/runtime/cudaPitchedPtr;ILCUDAWrapper/runtime/cudaExtent;LCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemset3DAsyncNative
  (JNIEnv *env, jclass cls, jobject pitchedDevPtr, jint value, jobject extent, jobject stream)
{
    if (pitchedDevPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pitchedDevPtr' is null for cudaMemset3DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (extent == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'extent' is null for cudaMemset3DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaMemset2DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaMemset3DAsync\n");

    PointerData *pointerData = NULL;
    cudaPitchedPtr nativePitchedDevPtr = getCudaPitchedPtr(env, pitchedDevPtr, pointerData);
    cudaExtent nativeExtent = getCudaExtent(env, extent);
    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    int result = cudaMemset3DAsync(nativePitchedDevPtr, (int)value, nativeExtent, nativeStream);

    if (!releasePointerData(env, pointerData, JNI_COMMIT)) return CUDA_INTERNAL_ERROR;

    return result;

}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpy3DNative
 * Signature: (LCUDAWrapper/runtime/cudaMemcpy3DParms;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpy3DNative
  (JNIEnv *env, jclass cls, jobject p)
{
    if (p == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'p' is null for cudaMemcpy3D");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemcpy3D\n");

    PointerData *srcPointerData = NULL;
    PointerData *dstPointerData = NULL;

    cudaMemcpy3DParms nativeP = getCudaMemcpy3DParms(env, p, srcPointerData, dstPointerData);
    int result = cudaMemcpy3D(&nativeP);

    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, dstPointerData, JNI_COMMIT)) return CUDA_INTERNAL_ERROR;

    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpy3DPeerNative
 * Signature: (LCUDAWrapper/runtime/cudaMemcpy3DPeerParms;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpy3DPeerNative
  (JNIEnv *env, jclass cls, jobject p)
{
    if (p == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'p' is null for cudaMemcpy3DPeer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemcpy3DPeer\n");

    PointerData *srcPointerData = NULL;
    PointerData *dstPointerData = NULL;

    cudaMemcpy3DPeerParms nativeP = getCudaMemcpy3DPeerParms(env, p, srcPointerData, dstPointerData);
    int result = cudaMemcpy3DPeer(&nativeP);

    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, dstPointerData, JNI_COMMIT)) return CUDA_INTERNAL_ERROR;

    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpy3DAsyncNative
 * Signature: (LCUDAWrapper/runtime/cudaMemcpy3DParms;LCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpy3DAsyncNative
  (JNIEnv *env, jclass cls, jobject p, jobject stream)
{
    if (p == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'p' is null for cudaMemcpy3DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaMemcpy3DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaMemcpy3DAsync\n");

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    PointerData *srcPointerData = NULL;
    PointerData *dstPointerData = NULL;

    cudaMemcpy3DParms nativeP = getCudaMemcpy3DParms(env, p, srcPointerData, dstPointerData);
    int result = cudaMemcpy3DAsync(&nativeP, nativeStream);

    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, dstPointerData, JNI_COMMIT)) return CUDA_INTERNAL_ERROR;

    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpy3DPeerAsyncNative
 * Signature: (LCUDAWrapper/runtime/cudaMemcpy3DPeerParms;LCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpy3DPeerAsyncNative
  (JNIEnv *env, jclass cls, jobject p, jobject stream)
{
    if (p == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'p' is null for cudaMemcpy3DPeerAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaMemcpy3DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaMemcpy3DPeerAsync\n");

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    PointerData *srcPointerData = NULL;
    PointerData *dstPointerData = NULL;

    cudaMemcpy3DPeerParms nativeP = getCudaMemcpy3DPeerParms(env, p, srcPointerData, dstPointerData);
    int result = cudaMemcpy3DPeerAsync(&nativeP, nativeStream);

    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, dstPointerData, JNI_COMMIT)) return CUDA_INTERNAL_ERROR;

    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemGetInfoNative
 * Signature: ([J[J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemGetInfoNative
  (JNIEnv *env, jclass cls, jlongArray freeBytes, jlongArray totalBytes)
{
    if (freeBytes == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'freeBytes' is null for cudaMemGetInfo");
        return CUDA_INTERNAL_ERROR;
    }
    if (totalBytes == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'freeBytes' is null for cudaMemGetInfo");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemGetInfo\n");

    size_t nativeFreeBytes = 0;
    size_t nativeTotalBytes = 0;

    int result = cudaMemGetInfo(&nativeFreeBytes, &nativeTotalBytes);

    if (!set(env, freeBytes, 0, (jlong)nativeFreeBytes)) return CUDA_INTERNAL_ERROR;
    if (!set(env, totalBytes, 0, (jlong)nativeTotalBytes)) return CUDA_INTERNAL_ERROR;

    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaArrayGetInfoNative
 * Signature: (LCUDAWrapper/runtime/cudaChannelFormatDesc;LCUDAWrapper/runtime/cudaExtent;[ILCUDAWrapper/runtime/cudaArray;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaArrayGetInfoNative
  (JNIEnv *env, jclass cls, jobject desc, jobject extent, jintArray flags, jobject array)
{
    if (array == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'array' is null for cudaArrayGetInfo");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaArrayGetInfo\n");

    cudaChannelFormatDesc nativeDesc;
    cudaExtent nativeExtent;
    unsigned int nativeFlags;
    cudaArray *nativeArray = (cudaArray*)getNativePointerValue(env, array);

    int result = cudaArrayGetInfo(&nativeDesc, &nativeExtent, &nativeFlags, nativeArray);

    if (desc != NULL) setCudaChannelFormatDesc(env, desc, nativeDesc);
    if (extent != NULL) setCudaExtent(env, extent, nativeExtent);
    if (flags != NULL) if (!set(env, flags, 0, (jint)nativeFlags)) return CUDA_INTERNAL_ERROR;

    return result;

}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMallocHostNative
 * Signature: (LCUDAWrapper/Pointer;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMallocHostNative
  (JNIEnv *env, jclass cls, jobject ptr, jlong size)
{
    if (ptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ptr' is null for cudaMallocHost");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cudaMallocHost of %ld bytes\n", (long)size);

    void *nativePtr;
    int result = cudaMallocHost(&nativePtr, (size_t)size);
    if (result == cudaSuccess)
    {
        jobject object = env->NewDirectByteBuffer(nativePtr, size);
        env->SetObjectField(ptr, Pointer_buffer, object);
        env->SetObjectField(ptr, Pointer_pointers, NULL);
        env->SetLongField(ptr, Pointer_byteOffset, 0);
        env->SetLongField(ptr, NativePointerObject_nativePointer, (jlong)nativePtr);
    }
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMallocPitchNative
 * Signature: (LCUDAWrapper/Pointer;[JJJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMallocPitchNative
  (JNIEnv *env, jclass cls, jobject devPtr, jlongArray pitch, jlong width, jlong height)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaMallocPitch");
        return CUDA_INTERNAL_ERROR;
    }
    if (pitch == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pitch' is null for cudaMallocPitch");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMallocPitch with width %ld and height %d\n", (long)width, (long)height);

    void *nativeDevPtr = NULL;

    size_t *nativePitch = new size_t[3];
    jlong *nativePitchJava = (jlong*)env->GetPrimitiveArrayCritical(pitch, NULL);
    for (int i=0; i<3; i++)
    {
        nativePitch[i] = (size_t)nativePitchJava[i];
    }

    int result = cudaMallocPitch(&nativeDevPtr, nativePitch, (size_t)width, (size_t)height);

    setPointer(env, devPtr, (jlong)nativeDevPtr);
    for (int i=0; i<3; i++)
    {
        nativePitchJava[i] = nativePitch[i];
    }
    delete[] nativePitch;
    env->ReleasePrimitiveArrayCritical(pitch, nativePitchJava, 0);

    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMallocArrayNative
 * Signature: (LCUDAWrapper/runtime/cudaArray;LCUDAWrapper/runtime/cudaChannelFormatDesc;JJI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMallocArrayNative
  (JNIEnv *env, jclass cls, jobject array, jobject desc, jlong width, jlong height, jint flags)
{
    if (array == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'array' is null for cudaMallocArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (desc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'desc' is null for cudaMallocArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMallocArray with width %ld and height %d\n", (long)width, (long)height);

    cudaArray *nativeArray;
    cudaChannelFormatDesc nativeDesc = getCudaChannelFormatDesc(env, desc);
    unsigned int nativeFlags = (unsigned int)flags;

    int result = cudaMallocArray(&nativeArray, &nativeDesc, (size_t)width, (size_t)height, nativeFlags);

    setNativePointerValue(env, array, (jlong)nativeArray);

    return result;
}





/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaFreeHostNative
 * Signature: (Ljava/nio/ByteBuffer;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaFreeHostNative
  (JNIEnv *env, jclass cls, jobject ptr)
{
    if (ptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ptr' is null for cudaFreeHost");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaFreeHost\n");

    void *nativePtr = getPointer(env, ptr);
    int result = cudaFreeHost(nativePtr);
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaFreeArrayNative
 * Signature: (LCUDAWrapper/runtime/cudaArray;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaFreeArrayNative
  (JNIEnv *env, jclass cls, jobject array)
{
    if (array == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'array' is null for cudaFreeArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaFreeArray\n");

    cudaArray *nativeArray = (cudaArray*)getNativePointerValue(env, array);
    int result = cudaFreeArray(nativeArray);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaFreeMipmappedArrayNative
 * Signature: (LCUDAWrapper/runtime/cudaMipmappedArray;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaFreeMipmappedArrayNative
  (JNIEnv *env, jclass cls, jobject mipmappedArray)
{
    if (mipmappedArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'mipmappedArray' is null for cudaFreeMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaFreeMipmappedArray\n");

    cudaMipmappedArray *nativeMipmappedArray = (cudaMipmappedArray*)getNativePointerValue(env, mipmappedArray);
    int result = cudaFreeMipmappedArray(nativeMipmappedArray);
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpyToArrayNative
 * Signature: (LCUDAWrapper/runtime/cudaArray;JJLCUDAWrapper/Pointer;JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpyToArrayNative
  (JNIEnv *env, jclass cls, jobject dst, jlong wOffset, jlong hOffset, jobject src, jlong count, jint kind)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpyToArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpyToArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemcpyToArray\n");

    cudaArray *nativeDst = (cudaArray*)getNativePointerValue(env, dst);
    PointerData *srcPointerData = initPointerData(env, src);
    if (srcPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cudaMemcpyToArray(nativeDst, (size_t)wOffset, (size_t)hOffset, (void*)srcPointerData->getPointer(env), (size_t)count, (cudaMemcpyKind)kind);

    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpyFromArrayNative
 * Signature: (LCUDAWrapper/Pointer;LCUDAWrapper/runtime/cudaArray;JJJI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpyFromArrayNative
  (JNIEnv *env, jclass cls, jobject dst, jobject src, jlong wOffset, jlong hOffset, jlong count, jint kind)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpyFromArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpyFromArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemcpyFromArray\n");

    PointerData *dstPointerData = initPointerData(env, dst);
    if (dstPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    cudaArray *nativeSrc = (cudaArray*)getNativePointerValue(env, src);

    int result = cudaMemcpyFromArray((void*)dstPointerData->getPointer(env), nativeSrc, (size_t)wOffset, (size_t)hOffset, (size_t)count, (cudaMemcpyKind)kind);

    if (!releasePointerData(env, dstPointerData)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpyArrayToArrayNative
 * Signature: (LCUDAWrapper/runtime/cudaArray;JJLCUDAWrapper/runtime/cudaArray;JJJI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpyArrayToArrayNative
  (JNIEnv *env, jclass cls, jobject dst, jlong wOffsetDst, jlong hOffsetDst, jobject src, jlong wOffsetSrc, jlong hOffsetSrc, jlong count, jint kind)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpyArrayToArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpyArrayToArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemcpyArrayToArray\n");

    cudaArray *nativeDst = (cudaArray*)getNativePointerValue(env, dst);
    cudaArray *nativeSrc = (cudaArray*)getNativePointerValue(env, src);

    int result = cudaMemcpyArrayToArray(nativeDst, (size_t)wOffsetDst, (size_t)hOffsetDst, nativeSrc, (size_t)wOffsetSrc, (size_t)hOffsetSrc, (size_t)count, (cudaMemcpyKind)kind);
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpy2DNative
 * Signature: (LCUDAWrapper/Pointer;JLCUDAWrapper/Pointer;JJJI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpy2DNative
  (JNIEnv *env, jclass cls, jobject dst, jlong dpitch, jobject src, jlong spitch, jlong width, jlong height, jint kind)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpy2D");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpy2D");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemcpy2D\n");

    PointerData *dstPointerData = initPointerData(env, dst);
    if (dstPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    PointerData *srcPointerData = initPointerData(env, src);
    if (srcPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cudaMemcpy2D((void*)dstPointerData->getPointer(env), (size_t)dpitch, (void*)srcPointerData->getPointer(env), (size_t)spitch, (size_t)width, (size_t)height, (cudaMemcpyKind)kind);

    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, dstPointerData)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpy2DToArrayNative
 * Signature: (LCUDAWrapper/runtime/cudaArray;JJLCUDAWrapper/Pointer;JJJI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpy2DToArrayNative
  (JNIEnv *env, jclass cls, jobject dst, jlong wOffset, jlong hOffset, jobject src, jlong spitch, jlong width, jlong height, jint kind)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpy2DToArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpy2DToArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemcpy2DToArray\n");

    cudaArray *nativeDst = (cudaArray*)getNativePointerValue(env, dst);
    PointerData *srcPointerData = initPointerData(env, src);
    if (srcPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cudaMemcpy2DToArray(nativeDst, (size_t)wOffset, (size_t)hOffset, (void*)srcPointerData->getPointer(env), (size_t)spitch, (size_t)width, (size_t)height, (cudaMemcpyKind)kind);

    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpy2DFromArrayNative
 * Signature: (LCUDAWrapper/Pointer;JLCUDAWrapper/runtime/cudaArray;JJJJI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpy2DFromArrayNative
  (JNIEnv *env, jclass cls, jobject dst, jlong dpitch, jobject src, jlong wOffset, jlong hOffset, jlong width, jlong height, jint kind)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpy2DFromArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpy2DFromArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemcpy2DFromArray\n");

    PointerData *dstPointerData = initPointerData(env, dst);
    if (dstPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    cudaArray *nativeSrc = (cudaArray*)getNativePointerValue(env, src);

    int result = cudaMemcpy2DFromArray((void*)dstPointerData->getPointer(env), (size_t)dpitch, nativeSrc, (size_t)wOffset, (size_t)hOffset, (size_t)width, (size_t)height, (cudaMemcpyKind)kind);

    if (!releasePointerData(env, dstPointerData)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpy2DArrayToArrayNative
 * Signature: (LCUDAWrapper/runtime/cudaArray;JJLCUDAWrapper/runtime/cudaArray;JJJJI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpy2DArrayToArrayNative
  (JNIEnv *env, jclass cls, jobject dst, jlong wOffsetDst, jlong hOffsetDst, jobject src, jlong wOffsetSrc, jlong hOffsetSrc, jlong width, jlong height, jint kind)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpy2DArrayToArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpy2DArrayToArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemcpy2DArrayToArray\n");

    cudaArray *nativeDst = (cudaArray*)getNativePointerValue(env, dst);
    cudaArray *nativeSrc = (cudaArray*)getNativePointerValue(env, src);

    int result = cudaMemcpy2DArrayToArray(nativeDst, (size_t)wOffsetDst, (size_t)hOffsetDst, nativeSrc, (size_t)wOffsetSrc, (size_t)hOffsetSrc, (size_t)width, (size_t)height, (cudaMemcpyKind)kind);
    return result;
}







/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpyAsyncNative
 * Signature: (LCUDAWrapper/Pointer;LCUDAWrapper/Pointer;JILCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpyAsyncNative
  (JNIEnv *env, jclass cls, jobject dst, jobject src, jlong count, jint kind, jobject stream)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpyAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpyAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaMemcpyAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */

    Logger::log(LOG_TRACE, "Executing cudaMemcpyAsync of %ld bytes\n", (long)count);

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    // Obtain the destination and source pointers
    PointerData *dstPointerData = initPointerData(env, dst);
    if (dstPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    PointerData *srcPointerData = initPointerData(env, src);
    if (srcPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    // Execute the cudaMemcpy operation
    int result = CUDA_INTERNAL_ERROR;
    if (kind == cudaMemcpyHostToHost)
    {
        Logger::log(LOG_TRACE, "Copying %ld bytes from host to host (async)\n", (long)count);
        result = cudaMemcpyAsync((void*)dstPointerData->getPointer(env), (void*)srcPointerData->getPointer(env), (size_t)count, cudaMemcpyHostToHost, nativeStream);
    }
    else if (kind == cudaMemcpyHostToDevice)
    {
        Logger::log(LOG_TRACE, "Copying %ld bytes from host to device (async)\n", (long)count);
        result = cudaMemcpyAsync((void*)dstPointerData->getPointer(env), (void*)srcPointerData->getPointer(env), (size_t)count, cudaMemcpyHostToDevice, nativeStream);
    }
    else if (kind == cudaMemcpyDeviceToHost)
    {
        Logger::log(LOG_TRACE, "Copying %ld bytes from device to host (async)\n", (long)count);
        result = cudaMemcpyAsync((void*)dstPointerData->getPointer(env), (void*)srcPointerData->getPointer(env), (size_t)count, cudaMemcpyDeviceToHost, nativeStream);
    }
    else if (kind == cudaMemcpyDeviceToDevice)
    {
        Logger::log(LOG_TRACE, "Copying %ld bytes from device to device (async)\n", (long)count);
        result = cudaMemcpyAsync((void*)dstPointerData->getPointer(env), (void*)srcPointerData->getPointer(env), (size_t)count, cudaMemcpyDeviceToDevice, nativeStream);
    }
    else
    {
        Logger::log(LOG_ERROR, "Invalid cudaMemcpyKind given: %d\n", kind);
        return cudaErrorInvalidMemcpyDirection;
    }

    // Release the pointer data
    if (!releasePointerData(env, dstPointerData)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpyPeerAsyncNative
 * Signature: (LCUDAWrapper/Pointer;ILCUDAWrapper/Pointer;IJLCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpyPeerAsyncNative
  (JNIEnv *env, jclass cls, jobject dst, jint dstDevice, jobject src, jint srcDevice, jlong count, jobject stream)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpyPeerAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpyPeerAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaMemcpyPeerAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */

    Logger::log(LOG_TRACE, "Executing cudaMemcpyPeerAsync of %ld bytes\n", (long)count);

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    // Obtain the destination and source pointers
    PointerData *dstPointerData = initPointerData(env, dst);
    if (dstPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    PointerData *srcPointerData = initPointerData(env, src);
    if (srcPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    // Execute the cudaMemcpy operation
    int result = cudaMemcpyPeerAsync((void*)dstPointerData->getPointer(env), (int)dstDevice, (void*)srcPointerData->getPointer(env), (int)srcDevice, (size_t)count, nativeStream);

    // Release the pointer data
    if (!releasePointerData(env, dstPointerData)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpyToArrayAsyncNative
 * Signature: (LCUDAWrapper/runtime/cudaArray;JJLCUDAWrapper/Pointer;JILCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpyToArrayAsyncNative
  (JNIEnv *env, jclass cls, jobject dst, jlong wOffset, jlong hOffset, jobject src, jlong count, jint kind, jobject stream)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpyToArrayAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpyToArrayAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaMemcpyToArrayAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaMemcpyToArrayAsync\n");

    cudaArray *nativeDst = (cudaArray*)getNativePointerValue(env, dst);

    PointerData *srcPointerData = initPointerData(env, src);
    if (srcPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    int result = cudaMemcpyToArrayAsync(nativeDst, (size_t)wOffset, (size_t)hOffset, (void*)srcPointerData->getPointer(env), (size_t)count, (cudaMemcpyKind)kind, nativeStream);

    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpyFromArrayAsyncNative
 * Signature: (LCUDAWrapper/Pointer;LCUDAWrapper/runtime/cudaArray;JJJILCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpyFromArrayAsyncNative
  (JNIEnv *env, jclass cls, jobject dst, jobject src, jlong wOffset, jlong hOffset, jlong count, jint kind, jobject stream)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpyFromArrayAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpyFromArrayAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaMemcpyFromArrayAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaMemcpyFromArrayAsync\n");

    PointerData *dstPointerData = initPointerData(env, dst);
    if (dstPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    cudaArray *nativeSrc = (cudaArray*)getNativePointerValue(env, src);

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    int result = cudaMemcpyFromArrayAsync((void*)dstPointerData->getPointer(env), nativeSrc, (size_t)wOffset, (size_t)hOffset, (size_t)count, (cudaMemcpyKind)kind, nativeStream);

    if (!releasePointerData(env, dstPointerData)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpy2DAsyncNative
 * Signature: (LCUDAWrapper/Pointer;JLCUDAWrapper/Pointer;JJJILCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpy2DAsyncNative
  (JNIEnv *env, jclass cls, jobject dst, jlong dpitch, jobject src, jlong spitch, jlong width, jlong height, jint kind, jobject stream)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpy2DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpy2DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaMemcpy2DAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaMemcpy2DAsync\n");

    PointerData *dstPointerData = initPointerData(env, dst);
    if (dstPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    PointerData *srcPointerData = initPointerData(env, src);
    if (srcPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    int result = cudaMemcpy2DAsync((void*)dstPointerData->getPointer(env), (size_t)dpitch, (void*)srcPointerData->getPointer(env), (size_t)spitch, (size_t)width, (size_t)height, (cudaMemcpyKind)kind, nativeStream);

    if (!releasePointerData(env, dstPointerData)) return CUDA_INTERNAL_ERROR;
    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpy2DToArrayAsyncNative
 * Signature: (LCUDAWrapper/runtime/cudaArray;JJLCUDAWrapper/Pointer;JJJILCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpy2DToArrayAsyncNative
  (JNIEnv *env, jclass cls, jobject dst, jlong wOffset, jlong hOffset, jobject src, jlong spitch, jlong width, jlong height, jint kind, jobject stream)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpy2DToArrayAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpy2DToArrayAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaMemcpy2DToArrayAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaMemcpy2DToArrayAsync\n");

    cudaArray *nativeDst = (cudaArray*)getNativePointerValue(env, dst);

    PointerData *srcPointerData = initPointerData(env, src);
    if (srcPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    int result = cudaMemcpy2DToArrayAsync(nativeDst, (size_t)wOffset, (size_t)hOffset, (void*)srcPointerData->getPointer(env), (size_t)spitch, (size_t)width, (size_t)height, (cudaMemcpyKind)kind, nativeStream);

    if (!releasePointerData(env, srcPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;

    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemcpy2DFromArrayAsynNativec
 * Signature: (LCUDAWrapper/Pointer;JLCUDAWrapper/runtime/cudaArray;JJJJILCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemcpy2DFromArrayAsyncNative
  (JNIEnv *env, jclass cls, jobject dst, jlong dpitch, jobject src, jlong wOffset, jlong hOffset, jlong width, jlong height, jint kind, jobject stream)
{
    if (dst == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dst' is null for cudaMemcpy2DFromArrayAsync");
        return CUDA_INTERNAL_ERROR;
    }
    if (src == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'src' is null for cudaMemcpy2DFromArrayAsync");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaMemcpy2DFromArrayAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaMemcpy2DFromArrayAsync\n");

    PointerData *dstPointerData = initPointerData(env, dst);
    if (dstPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    cudaArray *nativeSrc = (cudaArray*)getNativePointerValue(env, src);

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    int result = cudaMemcpy2DFromArrayAsync((void*)dstPointerData->getPointer(env), (size_t)dpitch, nativeSrc, (size_t)wOffset, (size_t)hOffset, (size_t)width, (size_t)height, (cudaMemcpyKind)kind, nativeStream);

    if (!releasePointerData(env, dstPointerData)) return CUDA_INTERNAL_ERROR;

    return result;
}






/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemsetNative
 * Signature: (LCUDAWrapper/Pointer;IJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemsetNative
  (JNIEnv *env, jclass cls, jobject mem, jint c, jlong count)
{
    if (mem == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'mem' is null for cudaMemset");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemset\n");

    void *nativeMem = getPointer(env, mem);

    int result = cudaMemset(nativeMem, (int)c, (size_t)count);
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaMemset2DNative
 * Signature: (LCUDAWrapper/Pointer;JIJJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemset2DNative
  (JNIEnv *env, jclass cls, jobject mem, jlong pitch, jint c, jlong width, jlong height)
{
    if (mem == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'mem' is null for cudaMemset2D");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemset2D\n");

    void *nativeMem = getPointer(env, mem);

    int result = cudaMemset2D(nativeMem, (size_t)pitch, (int)c, (size_t)width, (size_t)height);
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetChannelDescNative
 * Signature: (LCUDAWrapper/runtime/cudaChannelFormatDesc;LCUDAWrapper/runtime/cudaArray;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetChannelDescNative
  (JNIEnv *env, jclass cls, jobject desc, jobject array)
{
    if (desc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'desc' is null for cudaGetChannelDesc");
        return CUDA_INTERNAL_ERROR;
    }
    if (array == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'array' is null for cudaGetChannelDesc");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGetChannelDesc\n");

    cudaChannelFormatDesc nativeDesc;
    cudaArray *nativeArray = (cudaArray*)getNativePointerValue(env, array);
    int result = cudaGetChannelDesc(&nativeDesc, nativeArray);
    setCudaChannelFormatDesc(env, desc, nativeDesc);
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaCreateChannelDescNative
 * Signature: (IIIII)LCUDAWrapper/runtime/cudaChannelFormatDesc;
 */
JNIEXPORT jobject JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaCreateChannelDescNative
  (JNIEnv *env, jclass cls, jint x, jint y, jint z, jint w, jint f)
{
    Logger::log(LOG_TRACE, "Executing cudaCreateChannelDesc\n");

    cudaChannelFormatDesc nativeDesc = cudaCreateChannelDesc((int)x, (int)y, (int)z, (int)w, (cudaChannelFormatKind)f);
    jobject desc = env->NewObject(cudaChannelFormatDesc_class, cudaChannelFormatDesc_constructor);
    setCudaChannelFormatDesc(env, desc, nativeDesc);
    return desc;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetLastErrorNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetLastErrorNative
  (JNIEnv *env, jclass cls)
{
    Logger::log(LOG_TRACE, "Executing cudaGetLastError\n");

    return cudaGetLastError();
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaPeekAtLastErrorNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaPeekAtLastErrorNative
  (JNIEnv *env, jclass cls)
{
    Logger::log(LOG_TRACE, "Executing cudaGetLastError\n");

    return cudaPeekAtLastError();
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetErrorNameNative
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetErrorNameNative
  (JNIEnv *env, jclass cls, jint error)
{
    Logger::log(LOG_TRACE, "Executing cudaGetErrorName\n");
    const char *nativeString = cudaGetErrorName((cudaError_t)error);
    return env->NewStringUTF(nativeString);
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetErrorStringNative
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetErrorStringNative
  (JNIEnv *env, jclass cls, jint error)
{
    Logger::log(LOG_TRACE, "Executing cudaGetErrorString\n");
    const char *nativeString = cudaGetErrorString((cudaError_t)error);
    return env->NewStringUTF(nativeString);
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaStreamCreateNative
 * Signature: (LCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaStreamCreateNative
  (JNIEnv *env, jclass cls, jobject stream)
{
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaStreamCreate");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaStreamCreate\n");

    cudaStream_t nativeStream = NULL;
    int result = cudaStreamCreate(&nativeStream);
    setNativePointerValue(env, stream, (jlong)nativeStream);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaStreamCreateWithFlagsNative
 * Signature: (LCUDAWrapper/runtime/cudaStream_t;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaStreamCreateWithFlagsNative
  (JNIEnv *env, jclass cls, jobject stream, jint flags)
{
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaStreamCreateWithFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaStreamCreateWithFlags\n");

    cudaStream_t nativeStream = NULL;
    int result = cudaStreamCreateWithFlags(&nativeStream, (unsigned int)flags);
    setNativePointerValue(env, stream, (jlong)nativeStream);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaStreamCreateWithPriorityNative
 * Signature: (LCUDAWrapper/runtime/cudaStream_t;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaStreamCreateWithPriorityNative
  (JNIEnv *env, jclass cls, jobject phStream, jint flags, jint priority)
{
    if (phStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'phStream' is null for cudaStreamCreateWithPriority");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaStreamCreateWithPriority\n");

    cudaStream_t nativePhStream = NULL;
    int result = cudaStreamCreateWithPriority(&nativePhStream, (unsigned int)flags, (int)priority);
    setNativePointerValue(env, phStream, (jlong)nativePhStream);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaStreamGetPriorityNative
 * Signature: (LCUDAWrapper/runtime/cudaStream_t;[I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaStreamGetPriorityNative
  (JNIEnv *env, jclass cls, jobject hStream, jintArray priority)
{
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cudaStreamGetPriority");
        return CUDA_INTERNAL_ERROR;
    }
    if (priority == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'priority' is null for cudaStreamGetPriority");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaStreamGetPriority\n");

    cudaStream_t nativeHStream = (cudaStream_t)getNativePointerValue(env, hStream);
    int nativePriority;
    int result = cudaStreamGetPriority(nativeHStream, &nativePriority);
    if (!set(env, priority, 0, (jint)nativePriority)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaStreamGetFlagsNative
 * Signature: (LCUDAWrapper/runtime/cudaStream_t;[I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaStreamGetFlagsNative
  (JNIEnv *env, jclass cls, jobject hStream, jintArray flags)
{
    if (hStream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'hStream' is null for cudaStreamGetFlags");
        return CUDA_INTERNAL_ERROR;
    }
    if (flags == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'flags' is null for cudaStreamGetFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaStreamGetFlags\n");

    cudaStream_t nativeHStream = (cudaStream_t)getNativePointerValue(env, hStream);
    unsigned int nativeFlags;
    int result = cudaStreamGetFlags(nativeHStream, &nativeFlags);
    if (!set(env, flags, 0, (jint)nativeFlags)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaStreamDestroyNative
 * Signature: (LCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaStreamDestroyNative
  (JNIEnv *env, jclass cls, jobject stream)
{
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaStreamDestroy");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaStreamDestroy\n");

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);
    return cudaStreamDestroy(nativeStream);
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaStreamWaitEventNative
 * Signature: (LCUDAWrapper/runtime/cudaStream_t;LCUDAWrapper/runtime/cudaEvent_t;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaStreamWaitEventNative
  (JNIEnv *env, jclass cls, jobject stream, jobject event, jint flags)
{
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaStreamWaitEvent");
        return CUDA_INTERNAL_ERROR;
    }
    */
    if (event == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'event' is null for cudaStreamWaitEvent");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaStreamWaitEvent\n");

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);
    cudaEvent_t nativeEvent = (cudaEvent_t)getNativePointerValue(env, event);

    return cudaStreamWaitEvent(nativeStream, nativeEvent, (int)flags);
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaStreamAddCallbackNative
 * Signature: (LCUDAWrapper/runtime/cudaStream_t;LCUDAWrapper/runtime/cudaStreamCallback;Ljava/lang/Object;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaStreamAddCallbackNative
  (JNIEnv *env, jclass cls, jobject stream, jobject callback, jobject userData, jint flags)
{
    // stream may be null
    if (callback == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'callback' is null for cudaStreamCallback");
        return CUDA_INTERNAL_ERROR;
    }
    // userData may be null

    Logger::log(LOG_TRACE, "Executing cudaStreamCallback\n");

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    CallbackInfo *callbackInfo = NULL;
    void* nativeUserData = NULL;

    callbackInfo = initCallbackInfo(env, stream, callback, userData);
    if (callbackInfo == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    nativeUserData = (void*)callbackInfo;

    int result = cudaStreamAddCallback(nativeStream, cudaStreamAddCallback_NativeCallback, nativeUserData, (unsigned int)flags);
    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaStreamSynchronizeNative
 * Signature: (LCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaStreamSynchronizeNative
  (JNIEnv *env, jclass cls, jobject stream)
{
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaStreamSynchronize");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaStreamSynchronize\n");

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);
    return cudaStreamSynchronize(nativeStream);
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaStreamQueryNative
 * Signature: (LCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaStreamQueryNative
  (JNIEnv *env, jclass cls, jobject stream)
{
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaStreamQuery");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaStreamQuery\n");

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);
    return cudaStreamQuery(nativeStream);
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaStreamAttachMemAsyncNative
 * Signature: (LCUDAWrapper/runtime/cudaStream_t;LCUDAWrapper/Pointer;JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaStreamAttachMemAsyncNative
  (JNIEnv *env, jclass cls, jobject stream, jobject devPtr, jlong length, jint flags)
{
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaStreamAttachMemAsync");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaStreamAttachMemAsync\n");

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);
    void *nativeDevPtr = getPointer(env, devPtr);
    int result = cudaStreamAttachMemAsync(nativeStream, nativeDevPtr, (size_t)length, (unsigned int)flags);

    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaEventCreateNative
 * Signature: (LCUDAWrapper/runtime/cudaEvent_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaEventCreateNative
  (JNIEnv *env, jclass cls, jobject event)
{
    if (event == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'event' is null for cudaEventCreate");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaEventCreate\n");

    cudaEvent_t nativeEvent = (cudaEvent_t)getNativePointerValue(env, event);
    int result = cudaEventCreate(&nativeEvent);
    setNativePointerValue(env, event, (jlong)nativeEvent);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaEventCreateWithFlagsNative
 * Signature: (LCUDAWrapper/runtime/cudaEvent_t;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaEventCreateWithFlagsNative
  (JNIEnv *env, jclass cls, jobject event, jint flags)
{
    if (event == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'event' is null for cudaEventCreateWithFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaEventCreateWithFlags\n");

    cudaEvent_t nativeEvent = (cudaEvent_t)getNativePointerValue(env, event);
    int result = cudaEventCreateWithFlags(&nativeEvent, (unsigned int)flags);
    setNativePointerValue(env, event, (jlong)nativeEvent);
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaEventRecordNative
 * Signature: (LCUDAWrapper/runtime/cudaEvent_t;LCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaEventRecordNative
  (JNIEnv *env, jclass cls, jobject event, jobject stream)
{
    if (event == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'event' is null for cudaEventRecord");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaEventRecord");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaEventRecord\n");

    cudaEvent_t nativeEvent = (cudaEvent_t)getNativePointerValue(env, event);

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    return cudaEventRecord(nativeEvent, nativeStream);
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaEventQueryNative
 * Signature: (LCUDAWrapper/runtime/cudaEvent_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaEventQueryNative
  (JNIEnv *env, jclass cls, jobject event)
{
    if (event == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'event' is null for cudaEventQuery");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaEventQuery\n");

    cudaEvent_t nativeEvent = (cudaEvent_t)getNativePointerValue(env, event);
    return cudaEventQuery(nativeEvent);
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaEventSynchronizeNative
 * Signature: (LCUDAWrapper/runtime/cudaEvent_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaEventSynchronizeNative
  (JNIEnv *env, jclass cls, jobject event)
{
    if (event == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'event' is null for cudaEventSynchronize");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaEventSynchronize\n");

    cudaEvent_t nativeEvent = (cudaEvent_t)getNativePointerValue(env, event);
    return cudaEventSynchronize(nativeEvent);
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaEventDestroyNative
 * Signature: (LCUDAWrapper/runtime/cudaEvent_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaEventDestroyNative
  (JNIEnv *env, jclass cls, jobject event)
{
    if (event == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'event' is null for cudaEventDestroy");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaEventDestroy\n");

    cudaEvent_t nativeEvent = (cudaEvent_t)getNativePointerValue(env, event);
    return cudaEventDestroy(nativeEvent);
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaEventElapsedTimeNative
 * Signature: ([FLCUDAWrapper/runtime/cudaEvent_t;LCUDAWrapper/runtime/cudaEvent_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaEventElapsedTimeNative
  (JNIEnv *env, jclass cls, jfloatArray ms, jobject start, jobject end)
{
    if (ms == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ms' is null for cudaEventElapsedTime");
        return CUDA_INTERNAL_ERROR;
    }
    if (start == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'start' is null for cudaEventElapsedTime");
        return CUDA_INTERNAL_ERROR;
    }
    if (end == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'end' is null for cudaEventElapsedTime");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaEventElapsedTime\n");

    cudaEvent_t nativeStart = (cudaEvent_t)getNativePointerValue(env, start);
    cudaEvent_t nativeEnd = (cudaEvent_t)getNativePointerValue(env, end);

    float nativeMs;
    int result = cudaEventElapsedTime(&nativeMs, nativeStart, nativeEnd);
    if (!set(env, ms, 0, nativeMs)) return CUDA_INTERNAL_ERROR;
    return result;
}






//=== Thread Management ======================================================


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaThreadExitNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaThreadExitNative
  (JNIEnv *env, jclass cls)
{
    Logger::log(LOG_TRACE, "Executing cudaThreadExit\n");

    return cudaThreadExit();
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaThreadSynchronizeNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaThreadSynchronizeNative
  (JNIEnv *env, jclass cls)
{
    Logger::log(LOG_TRACE, "Executing cudaThreadSynchronize\n");

    return cudaThreadSynchronize();
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaThreadSetLimitNative
 * Signature: (IJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaThreadSetLimitNative
  (JNIEnv *env, jclass cls, jint limit, jlong value)
{
    Logger::log(LOG_TRACE, "Executing cudaThreadSetLimit\n");

    cudaLimit nativeLimit = (cudaLimit)limit;
    size_t nativeValue = (size_t)value;
    return cudaThreadSetLimit(nativeLimit, nativeValue);
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaThreadGetCacheConfigNative
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaThreadGetCacheConfigNative
  (JNIEnv *env, jclass cls, jintArray config)
{
    if (config == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'config' is null for cudaThreadGetCacheConfig");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaThreadGetCacheConfig\n");

    cudaFuncCache nativeConfig;
    int result = cudaThreadGetCacheConfig(&nativeConfig);

    if (!set(env, config, 0, (int)nativeConfig)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaThreadSetCacheConfigNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaThreadSetCacheConfigNative
  (JNIEnv *env, jclass cls, jint config)
{
    Logger::log(LOG_TRACE, "Executing cudaThreadSetCacheConfig\n");

    cudaFuncCache nativeConfig = (cudaFuncCache)config;
    return cudaThreadSetCacheConfig(nativeConfig);
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaThreadGetLimitNative
 * Signature: ([JI)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaThreadGetLimitNative
  (JNIEnv *env, jclass cls, jlongArray value, jint limit)
{
    Logger::log(LOG_TRACE, "Executing cudaThreadSetLimit\n");

    cudaLimit nativeLimit = (cudaLimit)limit;
    size_t nativeValue = 0;
    int result = cudaThreadGetLimit(&nativeValue, nativeLimit);
    if (!set(env, value, 0, (long)nativeValue)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
* Class:     CUDAWrapper_runtime_CUDAWrapper
* Method:    cudaMemPrefetchAsyncNative
* Signature: (LCUDAWrapper/Pointer;JILCUDAWrapper/runtime/cudaStream_t;)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemPrefetchAsyncNative
(JNIEnv *env, jclass cls, jobject devPtr, jlong count, jint dstDevice, jobject stream)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaMemPrefetchAsync");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemPrefetchAsync\n");

    void *nativeDevPtr = getPointer(env, devPtr);
    long nativeCount = (long)count;
    int nativeDstDevice = (int)dstDevice;
    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    int result = cudaMemPrefetchAsync(nativeDevPtr, nativeCount, nativeDstDevice, nativeStream);

    return result;
}

/*
* Class:     CUDAWrapper_runtime_CUDAWrapper
* Method:    cudaMemAdviseNative
* Signature: (LCUDAWrapper/Pointer;JII)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemAdviseNative
(JNIEnv *env, jclass cls, jobject devPtr, jlong count, jint advice, jint device)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaMemAdvise");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemAdvise\n");

    void *nativeDevPtr = getPointer(env, devPtr);
    long nativeCount = (long)count;
    cudaMemoryAdvise nativeAdvice = (cudaMemoryAdvise)advice;
    int nativeDevice = (int)device;

    int result = cudaMemAdvise(nativeDevPtr, nativeCount, nativeAdvice, nativeDevice);

    return result;
}


/*
* Class:     CUDAWrapper_runtime_CUDAWrapper
* Method:    cudaMemRangeGetAttributeNative
* Signature: (LCUDAWrapper/Pointer;JILCUDAWrapper/Pointer;J)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemRangeGetAttributeNative
(JNIEnv *env, jclass cls, jobject data, jlong dataSize, jint attribute, jobject devPtr, jlong count)
{
    if (data == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'data' is null for cudaMemRangeGetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaMemRangeGetAttribute");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemRangeGetAttribute\n");

    
    PointerData *dataPointerData = initPointerData(env, data);
    if (dataPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    void *nativeData = (void*)dataPointerData->getPointer(env);
    size_t nativeDataSize = (size_t)dataSize;
    cudaMemRangeAttribute nativeAttribute = (cudaMemRangeAttribute)attribute;
    void *nativeDevPtr = getPointer(env, devPtr);
    size_t nativeCount = (size_t)count;

    int result = cudaMemRangeGetAttribute(nativeData, nativeDataSize, nativeAttribute, nativeDevPtr, nativeCount);

    if (!releasePointerData(env, dataPointerData, 0)) return CUDA_INTERNAL_ERROR;

    return result;
}

/*
* Class:     CUDAWrapper_runtime_CUDAWrapper
* Method:    cudaMemRangeGetAttributesNative
* Signature: ([LCUDAWrapper/Pointer;[J[IJLCUDAWrapper/Pointer;J)I
*/
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaMemRangeGetAttributesNative
(JNIEnv *env, jclass cls, jobjectArray data, jlongArray dataSizes, jintArray attributes, jlong numAttributes, jobject devPtr, jlong count)
{
    if (data == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'data' is null for cudaMemRangeGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    if (dataSizes == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'dataSizes' is null for cudaMemRangeGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    if (attributes == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'attributes' is null for cudaMemRangeGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaMemRangeGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaMemRangeGetAttributes\n");

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
    cudaMemRangeAttribute *nativeAttributes = getArrayContentsGeneric<jintArray, jint, cudaMemRangeAttribute>(env, attributes);
    void *nativeDevPtr = getPointer(env, devPtr);
    size_t nativeCount = (size_t)count;

    int result = cudaMemRangeGetAttributes(nativeDatas, nativeDataSizes, nativeAttributes, (size_t)numAttributes, nativeDevPtr, nativeCount);

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
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaBindTextureNative
 * Signature: ([JLCUDAWrapper/runtime/textureReference;LCUDAWrapper/Pointer;LCUDAWrapper/runtime/cudaChannelFormatDesc;J)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaBindTextureNative
  (JNIEnv *env, jclass cls, jlongArray offset, jobject texRef, jobject devPtr, jobject desc, jlong size)
{
    /* May be null
    if (offset == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'offset' is null for cudaBindTexture");
        return CUDA_INTERNAL_ERROR;
    }
    */
    if (texRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texRef' is null for cudaBindTexture");
        return CUDA_INTERNAL_ERROR;
    }
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaBindTexture");
        return CUDA_INTERNAL_ERROR;
    }
    if (desc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'desc' is null for cudaBindTexture");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaBindTexture\n");

    size_t nativeOffset;
    textureReference nativeTexRef = getTextureReference(env, texRef);
    void *nativeDevPtr = getPointer(env, devPtr);
    cudaChannelFormatDesc nativeDesc = getCudaChannelFormatDesc(env, desc);
    int result = cudaBindTexture(&nativeOffset, &nativeTexRef, nativeDevPtr, &nativeDesc, (size_t)size);
    if (offset != NULL)
    {
        if (!set(env, offset, 0, (long)nativeOffset)) return CUDA_INTERNAL_ERROR;
    }
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaBindTexture2DNative
 * Signature: ([JLCUDAWrapper/runtime/textureReference;LCUDAWrapper/Pointer;LCUDAWrapper/runtime/cudaChannelFormatDesc;JJJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaBindTexture2DNative
  (JNIEnv *env, jclass cls, jlongArray offset, jobject texRef, jobject devPtr, jobject desc, jlong width, jlong height, jlong pitch)
{
    if (texRef == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texRef' is null for cudaBindTexture2D");
        return CUDA_INTERNAL_ERROR;
    }
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaBindTexture2D");
        return CUDA_INTERNAL_ERROR;
    }
    if (desc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'desc' is null for cudaBindTexture2D");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaBindTexture2D\n");


    textureReference nativeTexRef = getTextureReference(env, texRef);
    cudaChannelFormatDesc nativeDesc = getCudaChannelFormatDesc(env, desc);
    void *nativeDevPtr = getPointer(env, devPtr);
    size_t nativeOffset;
    int result = cudaBindTexture2D(&nativeOffset, &nativeTexRef, nativeDevPtr, &nativeDesc, (size_t)width, (size_t)height, (size_t)pitch);
    if (!set(env, offset, 0, (long)nativeOffset)) return CUDA_INTERNAL_ERROR;
    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaBindTextureToArrayNative
 * Signature: (LCUDAWrapper/runtime/textureReference;LCUDAWrapper/runtime/cudaArray;LCUDAWrapper/runtime/cudaChannelFormatDesc;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaBindTextureToArrayNative
  (JNIEnv *env, jclass cls, jobject texref, jobject array, jobject desc)
{
    if (texref == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texref' is null for cudaBindTextureToArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (array == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'array' is null for cudaBindTextureToArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (desc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'desc' is null for cudaBindTextureToArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaBindTextureToArray\n");

    textureReference nativeTexref = getTextureReference(env, texref);
    cudaArray *nativeArray = (cudaArray*)getNativePointerValue(env, array);
    cudaChannelFormatDesc nativeDesc = getCudaChannelFormatDesc(env, desc);
    int result = cudaBindTextureToArray(&nativeTexref, nativeArray, &nativeDesc);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaBindTextureToMipmappedArrayNative
 * Signature: (LCUDAWrapper/runtime/textureReference;LCUDAWrapper/runtime/cudaMipmappedArray;LCUDAWrapper/runtime/cudaChannelFormatDesc;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaBindTextureToMipmappedArrayNative
  (JNIEnv *env, jclass cls, jobject texref, jobject mipmappedArray, jobject desc)
{
    if (texref == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texref' is null for cudaBindTextureToMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (mipmappedArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'mipmappedArray' is null for cudaBindTextureToMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (desc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'desc' is null for cudaBindTextureToMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaBindTextureToMipmappedArray\n");

    textureReference nativeTexref = getTextureReference(env, texref);
    cudaMipmappedArray *nativeMipmappedArray = (cudaMipmappedArray*)getNativePointerValue(env, mipmappedArray);
    cudaChannelFormatDesc nativeDesc = getCudaChannelFormatDesc(env, desc);
    int result = cudaBindTextureToMipmappedArray(&nativeTexref, nativeMipmappedArray, &nativeDesc);
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaUnbindTextureNative
 * Signature: (LCUDAWrapper/runtime/textureReference;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaUnbindTextureNative
  (JNIEnv *env, jclass cls, jobject texref)
{
    if (texref == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texref' is null for cudaUnbindTexture");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaUnbindTexture\n");

    textureReference nativeTexref = getTextureReference(env, texref);
    int result = cudaUnbindTexture(&nativeTexref);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetTextureAlignmentOfNativefset
 * Signature: ([JLCUDAWrapper/runtime/textureReference;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetTextureAlignmentOffsetNative
  (JNIEnv *env, jclass cls, jlongArray offset, jobject texref)
{
    if (offset == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'offset' is null for cudaGetTextureAlignmentOffset");
        return CUDA_INTERNAL_ERROR;
    }
    if (texref == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texref' is null for cudaGetTextureAlignmentOffset");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGetTextureAlignmentOffset\n");

    size_t nativeOffset;
    textureReference nativeTexref = getTextureReference(env, texref);
    int result = cudaGetTextureAlignmentOffset(&nativeOffset, &nativeTexref);
    if (!set(env, offset, 0, (long)nativeOffset)) return CUDA_INTERNAL_ERROR;
    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaBindSurfaceToArrayNative
 * Signature: (LCUDAWrapper/runtime/surfaceReference;LCUDAWrapper/runtime/cudaArray;LCUDAWrapper/runtime/cudaChannelFormatDesc;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaBindSurfaceToArrayNative
  (JNIEnv *env, jclass cls, jobject surfref, jobject array, jobject desc)
{
    if (surfref == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'surfref' is null for cudaBindSurfaceToArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (array == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'array' is null for cudaBindSurfaceToArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (desc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'desc' is null for cudaBindSurfaceToArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaBindSurfacetureToArray\n");

    surfaceReference nativeSurfref = getSurfaceReference(env, surfref);
    cudaArray *nativeArray = (cudaArray*)getNativePointerValue(env, array);
    cudaChannelFormatDesc nativeDesc = getCudaChannelFormatDesc(env, desc);
    int result = cudaBindSurfaceToArray(&nativeSurfref, nativeArray, &nativeDesc);
    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaCreateTextureObjectNative
 * Signature: (LCUDAWrapper/runtime/cudaTextureObject;LCUDAWrapper/runtime/cudaResourceDesc;LCUDAWrapper/runtime/cudaTextureDesc;LCUDAWrapper/runtime/cudaResourceViewDesc;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaCreateTextureObjectNative
  (JNIEnv *env, jclass cls, jobject pTexObject, jobject pResDesc, jobject pTexDesc, jobject pResViewDesc)
{
    if (pTexObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pTexObject' is null for cudaCreateTextureObject");
        return CUDA_INTERNAL_ERROR;
    }
    if (pResDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pResDesc' is null for cudaCreateTextureObject");
        return CUDA_INTERNAL_ERROR;
    }
    if (pTexDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pTexDesc' is null for cudaCreateTextureObject");
        return CUDA_INTERNAL_ERROR;
    }
    // pResViewDesc may be NULL
    Logger::log(LOG_TRACE, "Executing cudaCreateTextureObject\n");

    cudaTextureObject_t nativePTexObject;
    cudaResourceDesc nativePResDesc = getCudaResourceDesc(env, pResDesc);
    cudaTextureDesc nativePTexDesc = getCudaTextureDesc(env, pTexDesc);
    cudaResourceViewDesc nativePResViewDesc;
    cudaResourceViewDesc *nativePResViewDescPointer = NULL;
    if (pResViewDesc != NULL)
    {
        nativePResViewDesc = getCudaResourceViewDesc(env, pResViewDesc);
        nativePResViewDescPointer = &nativePResViewDesc;
    }

    int result = cudaCreateTextureObject(&nativePTexObject, &nativePResDesc, &nativePTexDesc, nativePResViewDescPointer);

    setNativePointerValue(env, pTexObject, (jlong)nativePTexObject);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDestroyTextureObjectNative
 * Signature: (LCUDAWrapper/runtime/cudaTextureObject;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDestroyTextureObjectNative
  (JNIEnv *env, jclass cls, jobject texObject)
{
    if (texObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texObject' is null for cudaDestroyTextureObject");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaDestroyTextureObject\n");

    cudaTextureObject_t nativeTexObject = (cudaTextureObject_t)getNativePointerValue(env, texObject);
    int result = cudaDestroyTextureObject(nativeTexObject);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetTextureObjectResourceDescNative
 * Signature: (LCUDAWrapper/runtime/cudaResourceDesc;LCUDAWrapper/runtime/cudaTextureObject;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetTextureObjectResourceDescNative
  (JNIEnv *env, jclass cls, jobject pResDesc, jobject texObject)
{
    if (pResDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pResDesc' is null for cudaGetTextureObjectResourceDesc");
        return CUDA_INTERNAL_ERROR;
    }
    if (texObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texObject' is null for cudaGetTextureObjectResourceDesc");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGetTextureObjectResourceDesc\n");

    cudaTextureObject_t nativeTexObject = (cudaTextureObject_t)getNativePointerValue(env, texObject);
    cudaResourceDesc nativePResDesc;
    int result = cudaGetTextureObjectResourceDesc(&nativePResDesc, nativeTexObject);
    setCudaResourceDesc(env, pResDesc, nativePResDesc);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetTextureObjectTextureDescNative
 * Signature: (LCUDAWrapper/runtime/cudaTextureDesc;LCUDAWrapper/runtime/cudaTextureObject;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetTextureObjectTextureDescNative
  (JNIEnv *env, jclass cls, jobject pTexDesc, jobject texObject)
{
    if (pTexDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pTexDesc' is null for cudaGetTextureObjectTextureDesc");
        return CUDA_INTERNAL_ERROR;
    }
    if (texObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texObject' is null for cudaGetTextureObjectTextureDesc");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGetTextureObjectTextureDesc\n");

    cudaTextureObject_t nativeTexObject = (cudaTextureObject_t)getNativePointerValue(env, texObject);
    cudaTextureDesc nativePTexDesc;
    int result = cudaGetTextureObjectTextureDesc(&nativePTexDesc, nativeTexObject);
    setCudaTextureDesc(env, pTexDesc, nativePTexDesc);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetTextureObjectResourceViewDescNative
 * Signature: (LCUDAWrapper/runtime/cudaResourceViewDesc;LCUDAWrapper/runtime/cudaTextureObject;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetTextureObjectResourceViewDescNative
  (JNIEnv *env, jclass cls, jobject pResViewDesc, jobject texObject)
{
    if (pResViewDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pResViewDesc' is null for cudaGetTextureObjectResourceViewDesc");
        return CUDA_INTERNAL_ERROR;
    }
    if (texObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'texObject' is null for cudaGetTextureObjectResourceViewDesc");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGetTextureObjectResourceViewDesc\n");

    cudaTextureObject_t nativeTexObject = (cudaTextureObject_t)getNativePointerValue(env, texObject);
    cudaResourceViewDesc nativePResViewDesc;
    int result = cudaGetTextureObjectResourceViewDesc(&nativePResViewDesc, nativeTexObject);
    setCudaResourceViewDesc(env, pResViewDesc, nativePResViewDesc);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaCreateSurfaceObjectNative
 * Signature: (LCUDAWrapper/runtime/cudaSurfaceObject;LCUDAWrapper/runtime/cudaResourceDesc;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaCreateSurfaceObjectNative
  (JNIEnv *env, jclass cls, jobject pSurfObject, jobject pResDesc)
{
    if (pSurfObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pSurfObject' is null for cudaCreateSurfaceObject");
        return CUDA_INTERNAL_ERROR;
    }
    if (pResDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pResDesc' is null for cudaCreateSurfaceObject");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaCreateSurfaceObject\n");

    cudaSurfaceObject_t nativePSurfObject;
    cudaResourceDesc nativePResDesc = getCudaResourceDesc(env, pResDesc);
    int result = cudaCreateSurfaceObject(&nativePSurfObject, &nativePResDesc);
    setNativePointerValue(env, pSurfObject, (jlong)nativePSurfObject);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDestroySurfaceObjectNative
 * Signature: (LCUDAWrapper/runtime/cudaSurfaceObject;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDestroySurfaceObjectNative
  (JNIEnv *env, jclass cls, jobject surfObject)
{
    if (surfObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'surfObject' is null for cudaDestroySurfaceObject");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaDestroySurfaceObject\n");

    cudaSurfaceObject_t nativeSurfObject = (cudaSurfaceObject_t)getNativePointerValue(env, surfObject);
    int result = cudaDestroySurfaceObject(nativeSurfObject);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGetSurfaceObjectResourceDescNative
 * Signature: (LCUDAWrapper/runtime/cudaResourceDesc;LCUDAWrapper/runtime/cudaSurfaceObject;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGetSurfaceObjectResourceDescNative
  (JNIEnv *env, jclass cls, jobject pResDesc, jobject surfObject)
{
    if (pResDesc == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pResDesc' is null for cudaGetSurfaceObjectResourceDesc");
        return CUDA_INTERNAL_ERROR;
    }
    if (surfObject == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'surfObject' is null for cudaGetSurfaceObjectResourceDesc");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGetSurfaceObjectResourceDesc\n");

    cudaSurfaceObject_t nativeSurfObject = (cudaSurfaceObject_t)getNativePointerValue(env, surfObject);
    cudaResourceDesc nativePResDesc;
    int result = cudaGetSurfaceObjectResourceDesc(&nativePResDesc, nativeSurfObject);
    setCudaResourceDesc(env, pResDesc, nativePResDesc);
    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaConfigureCallNative
 * Signature: (LCUDAWrapper/runtime/dim3;LCUDAWrapper/runtime/dim3;JLCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaConfigureCallNative
  (JNIEnv *env, jclass cls, jobject gridDim, jobject blockDim, jlong sharedMem, jobject stream)
{
    if (gridDim == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'gridDim' is null for cudaConfigureCall");
        return CUDA_INTERNAL_ERROR;
    }
    if (blockDim == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'blockDim' is null for cudaConfigureCall");
        return CUDA_INTERNAL_ERROR;
    }
    /* May be null
    if (stream == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'stream' is null for cudaConfigureCall");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaConfigureCall\n");

    dim3 nativeGridDim = getDim3(env, gridDim);
    dim3 nativeBlockDim = getDim3(env, blockDim);
    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    int result = cudaConfigureCall(nativeGridDim, nativeBlockDim, (size_t)sharedMem, nativeStream);
    return result;

}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaSetupArgumentNative
 * Signature: (LCUDAWrapper/Pointer;JJ)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaSetupArgumentNative
  (JNIEnv *env, jclass cls, jobject arg, jlong size, jlong offset)
{
    if (arg == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'arg' is null for cudaSetupArgument");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaSetupArgument\n");

    PointerData *argPointerData = initPointerData(env, arg);
    if (argPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }

    int result = cudaSetupArgument((void*)argPointerData->getPointer(env), (size_t)size, (size_t)offset);

    if (!releasePointerData(env, argPointerData, JNI_ABORT)) return CUDA_INTERNAL_ERROR;
    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGLGetDevicesNative
 * Signature: ([I[III)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGLGetDevicesNative
  (JNIEnv *env, jclass cls, jintArray pCudaDeviceCount, jintArray pCudaDevices, jint cudaDeviceCount, jint deviceList)
{
    if (pCudaDeviceCount == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCudaDeviceCount' is null for cudaGLGetDevices");
        return CUDA_INTERNAL_ERROR;
    }
    if (pCudaDevices == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'pCudaDevices' is null for cudaGLGetDevices");
        return CUDA_INTERNAL_ERROR;
    }

    Logger::log(LOG_TRACE, "Executing cudaGLGetDevices\n");

    int *nativePCudaDevices = new int[(unsigned int)cudaDeviceCount];
    unsigned int nativePCudaDeviceCount = 0;

    int result = cudaGLGetDevices(&nativePCudaDeviceCount, nativePCudaDevices, (unsigned int)cudaDeviceCount, (cudaGLDeviceList)deviceList);

    jint *pCudaDevicesElements = (jint*)env->GetPrimitiveArrayCritical(pCudaDevices, NULL);
    if (pCudaDevicesElements == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    for (unsigned int i=0; i<nativePCudaDeviceCount; i++)
    {
        pCudaDevicesElements[i] = nativePCudaDevices[i];
    }
    env->ReleasePrimitiveArrayCritical(pCudaDevices, pCudaDevicesElements, 0);
    delete[] nativePCudaDevices;
    if (!set(env, pCudaDeviceCount, 0, (jint)nativePCudaDeviceCount)) return CUDA_INTERNAL_ERROR;

    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGLSetGLDeviceNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGLSetGLDeviceNative
  (JNIEnv *env, jclass cls, jint device)
{
    Logger::log(LOG_TRACE, "Executing cudaGLSetGLDevice\n");

    return cudaGLSetGLDevice((int)device);
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGraphicsGLRegisterImageNative
 * Signature: (LCUDAWrapper/runtime/cudaGraphicsResource;III)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGraphicsGLRegisterImageNative
  (JNIEnv *env, jclass cls, jobject resource, jint image, jint target, jint Flags)
{
    if (resource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resource' is null for cudaGraphicsGLRegisterImage");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGraphicsGLRegisterImage\n");

    cudaGraphicsResource *nativeResource = NULL;
    int result = cudaGraphicsGLRegisterImage(&nativeResource, (GLuint)image, (GLenum)target, (unsigned int)Flags);
    setNativePointerValue(env, resource, (jlong)nativeResource);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGraphicsGLRegisterBufferNative
 * Signature: (LCUDAWrapper/runtime/cudaGraphicsResource;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGraphicsGLRegisterBufferNative
  (JNIEnv *env, jclass cls, jobject resource, jint buffer, jint Flags)
{
    if (resource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resource' is null for cudaGraphicsGLRegisterBuffer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGraphicsGLRegisterBuffer\n");

    cudaGraphicsResource *nativeResource = NULL;
    int result = cudaGraphicsGLRegisterBuffer(&nativeResource, (GLuint)buffer, (unsigned int)Flags);
    setNativePointerValue(env, resource, (jlong)nativeResource);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGLSetBufferObjectMapFlagsNative
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGLSetBufferObjectMapFlagsNative
  (JNIEnv *env, jclass cls, jint bufObj, jint Flags)
{
    Logger::log(LOG_TRACE, "Executing cudaGLSetBufferObjectMapFlags\n");

    return cudaGLSetBufferObjectMapFlags((GLuint)bufObj, (unsigned int)Flags);
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGLMapBufferObjectAsyncNative
 * Signature: (LCUDAWrapper/Pointer;ILCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGLMapBufferObjectAsyncNative
  (JNIEnv *env, jclass cls, jobject devPtr, jint bufObj, jobject stream)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaGLMapBufferObjectAsync");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGLMapBufferObjectAsync\n");

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    void *nativeDevPtr;
    int result = cudaGLMapBufferObjectAsync(&nativeDevPtr, (GLuint)bufObj, nativeStream);
    setPointer(env, devPtr, (jlong)nativeDevPtr);
    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGLUnmapBufferObjectAsyncNative
 * Signature: (ILCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGLUnmapBufferObjectAsyncNative
  (JNIEnv *env, jclass cls, jint bufObj, jobject stream)
{
    Logger::log(LOG_TRACE, "Executing cudaGLUnmapBufferObjectAsync\n");

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);
    return cudaGLUnmapBufferObjectAsync((GLuint)bufObj, nativeStream);
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGLMapBufferObjectNative
 * Signature: (LCUDAWrapper/Pointer;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGLMapBufferObjectNative
  (JNIEnv *env, jclass cls, jobject devPtr, jint bufObj)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaGLMapBufferObject");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGLMapBufferObject\n");

    void *nativeDevPtr;
    int result = cudaGLMapBufferObject(&nativeDevPtr, (GLuint)bufObj);
    setPointer(env, devPtr, (jlong)nativeDevPtr);
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGLUnmapBufferObjectNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGLUnmapBufferObjectNative
  (JNIEnv *env, jclass cls, jint bufObj)
{
    Logger::log(LOG_TRACE, "Executing cudaGLUnmapBufferObject\n");

    return cudaGLUnmapBufferObject((GLuint)bufObj);
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGLUnregisterBufferObjectNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGLUnregisterBufferObjectNative
  (JNIEnv *env, jclass cls, jint bufObj)
{
    Logger::log(LOG_TRACE, "Executing cudaGLUnregisterBufferObject\n");

    return cudaGLUnregisterBufferObject((GLuint)bufObj);
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDriverGetVersionNative
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDriverGetVersionNative
  (JNIEnv *env, jclass cls, jintArray driverVersion)
{
    /* May be null
    if (driverVersion == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'driverVersion' is null for cudaDriverGetVersion");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaDriverGetVersion\n");

    if (driverVersion == NULL)
    {
        return cudaErrorInvalidValue;
    }
    int nativeDriverVersion;
    int result = cudaDriverGetVersion(&nativeDriverVersion);
    if (!set(env, driverVersion, 0, nativeDriverVersion)) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaRuntimeGetVersionNative
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaRuntimeGetVersionNative
  (JNIEnv *env, jclass cls, jintArray runtimeVersion)
{
    /* May be null
    if (runtimeVersion == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'runtimeVersion' is null for cudaRuntimeGetVersion");
        return CUDA_INTERNAL_ERROR;
    }
    */
    Logger::log(LOG_TRACE, "Executing cudaRuntimeGetVersion\n");

    if (runtimeVersion == NULL)
    {
        return cudaErrorInvalidValue;
    }
    int nativeRuntimeVersion;
    int result = cudaRuntimeGetVersion(&nativeRuntimeVersion);
    if (!set(env, runtimeVersion, 0, nativeRuntimeVersion)) return CUDA_INTERNAL_ERROR;
    return result;

}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaPointerGetAttributesNative
 * Signature: (LCUDAWrapper/runtime/cudaPointerAttributes;LCUDAWrapper/Pointer;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaPointerGetAttributesNative
  (JNIEnv *env, jclass cls, jobject attributes, jobject ptr)
{
    if (attributes == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'attributes' is null for cudaPointerGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    if (ptr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'ptr' is null for cudaPointerGetAttributes");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaPointerGetAttributes\n");

    PointerData *ptrPointerData = initPointerData(env, ptr);
    if (ptrPointerData == NULL)
    {
        return CUDA_INTERNAL_ERROR;
    }
    cudaPointerAttributes nativeAttributes;
    int result = cudaPointerGetAttributes(&nativeAttributes, (void*)ptrPointerData->getPointer(env));

    if (!setCudaPointerAttributes(env, attributes, nativeAttributes)) return CUDA_INTERNAL_ERROR;

    releasePointerData(env, ptrPointerData, JNI_ABORT);

    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceCanAccessPeerNative
 * Signature: ([III)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceCanAccessPeerNative
  (JNIEnv *env, jclass cls, jintArray canAccessPeer, jint device, jint peerDevice)
{
    if (canAccessPeer == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'canAccessPeer' is null for cudaDeviceCanAccessPeer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaDeviceCanAccessPeer\n");

    int nativeCanAccessPeer;
    int result = cudaDeviceCanAccessPeer(&nativeCanAccessPeer, (int)device, (int)peerDevice);

    if (!set(env, canAccessPeer, 0, nativeCanAccessPeer)) return CUDA_INTERNAL_ERROR;

    return result;
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceEnablePeerAccessNative
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceEnablePeerAccessNative
  (JNIEnv *env, jclass cls, jint peerDevice, jint flags)
{
    Logger::log(LOG_TRACE, "Executing cudaDeviceEnablePeerAccess\n");

    int result = cudaDeviceEnablePeerAccess((int)peerDevice, (unsigned int)flags);

    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaDeviceDisablePeerAccessNative
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaDeviceDisablePeerAccessNative
  (JNIEnv *env, jclass cls, jint peerDevice)
{
    Logger::log(LOG_TRACE, "Executing cudaDeviceDisablePeerAccess\n");

    int result = cudaDeviceDisablePeerAccess((int)peerDevice);

    return result;
}




/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGraphicsUnregisterResourceNative
 * Signature: (LCUDAWrapper/runtime/cudaGraphicsResource;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGraphicsUnregisterResourceNative
  (JNIEnv *env, jclass cls, jobject resource)
{
    if (resource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resource' is null for cudaGraphicsUnregisterResource");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGraphicsUnregisterResource\n");

    cudaGraphicsResource *nativeResource = (cudaGraphicsResource*)getNativePointerValue(env, resource);
    return cudaGraphicsUnregisterResource(nativeResource);
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGraphicsResourceSetMapFlagsNative
 * Signature: (LCUDAWrapper/runtime/cudaGraphicsResource;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGraphicsResourceSetMapFlagsNative
  (JNIEnv *env, jclass cls, jobject resource, jint flags)
{
    if (resource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resource' is null for cudaGraphicsResourceSetMapFlags");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGraphicsResourceSetMapFlags\n");

    cudaGraphicsResource *nativeResource = (cudaGraphicsResource*)getNativePointerValue(env, resource);
    return cudaGraphicsResourceSetMapFlags(nativeResource, (unsigned int)flags);
}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGraphicsMapResourcesNative
 * Signature: (I[LCUDAWrapper/runtime/cudaGraphicsResource;LCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGraphicsMapResourcesNative
  (JNIEnv *env, jclass cls, jint count, jobjectArray resources, jobject stream)
{
    if (resources == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resources' is null for cudaGraphicsMapResources");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGraphicsMapResources\n");

    long size = (long)env->GetArrayLength(resources);
    cudaGraphicsResource **nativeResources = new cudaGraphicsResource*[size];
    if (nativeResources == NULL)
    {
       ThrowByName(env, "java/lang/OutOfMemoryError", "Out of memory");
       return CUDA_INTERNAL_ERROR;
    }
    for (int i=0; i<size; i++)
    {
        jobject resource = env->GetObjectArrayElement(resources, i);
        cudaGraphicsResource *nativeResource = (cudaGraphicsResource*)getNativePointerValue(env, resource);
        nativeResources[i] = nativeResource;
    }

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    int result = cudaGraphicsMapResources((int)count, nativeResources, nativeStream);
    delete[] nativeResources;
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGraphicsUnmapResourcesNative
 * Signature: (I[LCUDAWrapper/runtime/cudaGraphicsResource;LCUDAWrapper/runtime/cudaStream_t;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGraphicsUnmapResourcesNative
  (JNIEnv *env, jclass cls, jint count, jobjectArray resources, jobject stream)
{
    if (resources == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resources' is null for cudaGraphicsUnmapResources");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGraphicsUnmapResources\n");

    long size = (long)env->GetArrayLength(resources);
    cudaGraphicsResource **nativeResources = new cudaGraphicsResource*[size];
    if (nativeResources == NULL)
    {
       ThrowByName(env, "java/lang/OutOfMemoryError", "Out of memory");
       return CUDA_INTERNAL_ERROR;
    }
    for (int i=0; i<size; i++)
    {
        jobject resource = env->GetObjectArrayElement(resources, i);
        cudaGraphicsResource *nativeResource = (cudaGraphicsResource*)getNativePointerValue(env, resource);
        nativeResources[i] = nativeResource;
    }

    cudaStream_t nativeStream = (cudaStream_t)getNativePointerValue(env, stream);

    int result = cudaGraphicsUnmapResources((int)count, nativeResources, nativeStream);
    delete[] nativeResources;
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGraphicsResourceGetMappedPointerNative
 * Signature: (LCUDAWrapper/Pointer;[JLCUDAWrapper/runtime/cudaGraphicsResource;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGraphicsResourceGetMappedPointerNative
  (JNIEnv *env, jclass cls, jobject devPtr, jlongArray size, jobject resource)
{
    if (devPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'devPtr' is null for cudaGraphicsResourceGetMappedPointer");
        return CUDA_INTERNAL_ERROR;
    }
    if (resource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resource' is null for cudaGraphicsResourceGetMappedPointer");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGraphicsResourceGetMappedPointer\n");

    cudaGraphicsResource *nativeResource = (cudaGraphicsResource*)getNativePointerValue(env, resource);

    void *nativeDevPtr = NULL;
    size_t nativeSize[1];
    int result = cudaGraphicsResourceGetMappedPointer(&nativeDevPtr, nativeSize, nativeResource);
    setPointer(env, devPtr, (jlong)nativeDevPtr);
    if (!set(env, size, 0, nativeSize[0])) return CUDA_INTERNAL_ERROR;
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGraphicsSubResourceGetMappedArrayNative
 * Signature: (LCUDAWrapper/runtime/cudaArray;LCUDAWrapper/runtime/cudaGraphicsResource;II)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGraphicsSubResourceGetMappedArrayNative
  (JNIEnv *env, jclass cls, jobject arrayPtr, jobject resource, jint arrayIndex, jint mipLevel)
{
    if (arrayPtr == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'arrayPtr' is null for cudaGraphicsSubResourceGetMappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (resource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resource' is null for cudaGraphicsSubResourceGetMappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGraphicsSubResourceGetMappedArray\n");

    cudaGraphicsResource *nativeResource = (cudaGraphicsResource*)getNativePointerValue(env, resource);

    cudaArray *nativeArrayPtr;
    int result = cudaGraphicsSubResourceGetMappedArray(&nativeArrayPtr, nativeResource, (unsigned int)arrayIndex, (unsigned int)mipLevel);
    setNativePointerValue(env, arrayPtr, (jlong)nativeArrayPtr);

    return result;

}


/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaGraphicsResourceGetMappedMipmappedArrayNative
 * Signature: (LCUDAWrapper/runtime/cudaMipmappedArray;LCUDAWrapper/runtime/cudaGraphicsResource;)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaGraphicsResourceGetMappedMipmappedArrayNative
  (JNIEnv *env, jclass cls, jobject mipmappedArray, jobject resource)
{
    if (mipmappedArray == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'mipmappedArray' is null for cudaGraphicsResourceGetMappedMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    if (resource == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'resource' is null for cudaGraphicsResourceGetMappedMipmappedArray");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaGraphicsResourceGetMappedMipmappedArray\n");

    cudaGraphicsResource *nativeResource = (cudaGraphicsResource*)getNativePointerValue(env, resource);

    cudaMipmappedArray *nativeMipmappedArray;
    int result = cudaGraphicsResourceGetMappedMipmappedArray(&nativeMipmappedArray, nativeResource);
    setNativePointerValue(env, mipmappedArray, (jlong)nativeMipmappedArray);

    return result;
}



/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaProfilerInitializeNative
 * Signature: (Ljava/lang/String;Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaProfilerInitializeNative
  (JNIEnv *env, jclass cls, jstring configFile, jstring outputFile, jint outputMode)
{
    if (configFile == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'configFile' is null for cudaProfilerInitialize");
        return CUDA_INTERNAL_ERROR;
    }
    if (outputFile == NULL)
    {
        ThrowByName(env, "java/lang/NullPointerException", "Parameter 'outputFile' is null for cudaProfilerInitialize");
        return CUDA_INTERNAL_ERROR;
    }
    Logger::log(LOG_TRACE, "Executing cudaProfilerInitialize\n");

    char *nativeConfigFile = convertString(env, configFile);
    char *nativeOutputFile = convertString(env, outputFile);

    int result = cudaProfilerInitialize(nativeConfigFile, nativeOutputFile, (cudaOutputMode_t)outputMode);

    delete[] nativeConfigFile;
    delete[] nativeOutputFile;
    return result;
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaProfilerStartNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaProfilerStartNative
  (JNIEnv *env, jclass cls)
{
    Logger::log(LOG_TRACE, "Executing cudaProfilerStart\n");
    return cudaProfilerStart();
}

/*
 * Class:     CUDAWrapper_runtime_CUDAWrapper
 * Method:    cudaProfilerStopNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CUDAWrapper_runtime_CUDAWrapper_cudaProfilerStopNative
  (JNIEnv *env, jclass cls)
{
    Logger::log(LOG_TRACE, "Executing cudaProfilerStop\n");
    return cudaProfilerStop();
}


