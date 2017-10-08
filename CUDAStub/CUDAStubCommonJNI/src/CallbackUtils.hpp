

#include <jni.h>

/**
 * A structure containing the information about the arguments that have
 * been passed to establish a callback method. A pointer to this structure
 * will be passed as the *userData to the respective function. The
 * function will then use the data from the given structure
 * to call the Java callback method.
 */
typedef struct
{
    /**
    * A global reference to the strea that was given (may be NULL)
    */
    jobject globalStream;

    /**
    * A global reference to the callback function object that was given
    */
    jobject globalJavaCallbackObject;

    /**
    * A global reference to the userData that was given (may be NULL)
    */
    jobject globalUserData;

} CallbackInfo;


CallbackInfo* initCallbackInfo(JNIEnv *env, jobject hStream, jobject javaCallbackObject, jobject userData);
void deleteCallbackInfo(JNIEnv *env, CallbackInfo* &callbackInfo);
void finishCallback(JNIEnv *env);
