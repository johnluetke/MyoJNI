/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class myojni_jni_Hub */

#ifndef _Included_myojni_jni_Hub
#define _Included_myojni_jni_Hub
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     myojni_jni_Hub
 * Method:    initialize
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_myojni_jni_Hub_initialize
  (JNIEnv *, jobject, jstring);

/*
 * Class:     myojni_jni_Hub
 * Method:    waitForMyo
 * Signature: (J)Lmyojni/jni/Myo;
 */
JNIEXPORT jobject JNICALL Java_myojni_jni_Hub_waitForMyo
  (JNIEnv *, jobject, jlong);

/*
 * Class:     myojni_jni_Hub
 * Method:    run
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_myojni_jni_Hub_run
  (JNIEnv *, jobject, jlong);

/*
 * Class:     myojni_jni_Hub
 * Method:    runOnce
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_myojni_jni_Hub_runOnce
  (JNIEnv *, jobject, jlong);

/*
 * Class:     myojni_jni_Hub
 * Method:    dispose
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_myojni_jni_Hub_dispose
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif