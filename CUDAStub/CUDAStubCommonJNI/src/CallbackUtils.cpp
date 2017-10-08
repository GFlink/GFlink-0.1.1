/*
 * CUDAWrapper - Java bindings for NVIDIA CUDA driver and runtime API
 *
 * Copyright (c) 2009-2017 Marco Hutter - http://www.CUDAWrapper.org
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

#include "CallbackUtils.hpp"
#include "JNIUtils.hpp"
#include "Logger.hpp"

/**
 * Initializes and returns a CallbackInfo structure with the given
 * arguments. The javaCallbackObject is the Java callback interface object
 * (may be NULL), and userData is a java.lang.Object (may be NULL).
 * The returned CallbackInfo structure will contain global references
 * to the non-null arguments. Returns NULL if an arror occurs.
 */
CallbackInfo* initCallbackInfo(JNIEnv *env, jobject hStream, jobject javaCallbackObject, jobject userData)
{
    Logger::log(LOG_DEBUGTRACE, "Executing initCallbackInfo\n");

    CallbackInfo *callbackInfo = new CallbackInfo();
    if (callbackInfo == NULL)
    {
        ThrowByName(env, "java/lang/OutOfMemoryError",
            "Out of memory when preparing callback function");
        return NULL;
    }
    callbackInfo->globalStream = NULL;
    callbackInfo->globalJavaCallbackObject = NULL;
    callbackInfo->globalUserData = NULL;
    if (hStream != NULL)
    {
        callbackInfo->globalStream = env->NewGlobalRef(hStream);
        if (env->ExceptionCheck())
        {
            delete callbackInfo;
            return NULL;
        }
    }
    if (javaCallbackObject != NULL)
    {
        callbackInfo->globalJavaCallbackObject = env->NewGlobalRef(javaCallbackObject);
        if (env->ExceptionCheck())
        {
            delete callbackInfo;
            return NULL;
        }
    }
    if (userData != NULL)
    {
        callbackInfo->globalUserData = env->NewGlobalRef(userData);
        if (env->ExceptionCheck())
        {
            delete callbackInfo;
            return NULL;
        }
    }
    return callbackInfo;
}


/**
 * Deletes the global references stored in the given CallbackInfo
 * object and deletes the object.
 */
void deleteCallbackInfo(JNIEnv *env, CallbackInfo* &callbackInfo)
{
    Logger::log(LOG_DEBUGTRACE, "Executing deleteCallbackInfo\n");

    if (callbackInfo == NULL)
    {
        return;
    }
    if (callbackInfo->globalStream != NULL)
    {
        env->DeleteGlobalRef(callbackInfo->globalStream);
    }
    if (callbackInfo->globalJavaCallbackObject != NULL)
    {
        env->DeleteGlobalRef(callbackInfo->globalJavaCallbackObject);
    }
    if (callbackInfo->globalUserData != NULL)
    {
        env->DeleteGlobalRef(callbackInfo->globalUserData);
    }
    delete callbackInfo;
    callbackInfo = NULL;
}

/**
* This functions checks if an exception occurred, prints 
* an error message in this case, and clears all pending
* exceptions
*/
void finishCallback(JNIEnv *env)
{
    if (env->ExceptionCheck())
    {
        Logger::log(LOG_ERROR, "Exception in callback\n");
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
}


