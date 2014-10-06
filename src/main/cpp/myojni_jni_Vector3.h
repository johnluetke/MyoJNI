/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class myojni_jni_Vector3 */

#ifndef _Included_myojni_jni_Vector3
#define _Included_myojni_jni_Vector3
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     myojni_jni_Vector3
 * Method:    initialize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_myojni_jni_Vector3_initialize
  (JNIEnv *, jobject);

/*
 * Class:     myojni_jni_Vector3
 * Method:    initializeXYZ
 * Signature: (FFF)V
 */
JNIEXPORT void JNICALL Java_myojni_jni_Vector3_initializeXYZ
  (JNIEnv *, jobject, jfloat, jfloat, jfloat);

/*
 * Class:     myojni_jni_Vector3
 * Method:    X
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_myojni_jni_Vector3_X
  (JNIEnv *, jobject);

/*
 * Class:     myojni_jni_Vector3
 * Method:    Y
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_myojni_jni_Vector3_Y
  (JNIEnv *, jobject);

/*
 * Class:     myojni_jni_Vector3
 * Method:    Z
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_myojni_jni_Vector3_Z
  (JNIEnv *, jobject);

/*
 * Class:     myojni_jni_Vector3
 * Method:    magnitude
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_myojni_jni_Vector3_magnitude
  (JNIEnv *, jobject);

/*
 * Class:     myojni_jni_Vector3
 * Method:    normalized
 * Signature: ()Lmyojni/jni/Vector3;
 */
JNIEXPORT jobject JNICALL Java_myojni_jni_Vector3_normalized
  (JNIEnv *, jobject);

/*
 * Class:     myojni_jni_Vector3
 * Method:    dot
 * Signature: (Lmyojni/jni/Vector3;)F
 */
JNIEXPORT jfloat JNICALL Java_myojni_jni_Vector3_dot
  (JNIEnv *, jobject, jobject);

/*
 * Class:     myojni_jni_Vector3
 * Method:    cross
 * Signature: (Lmyojni/jni/Vector3;)Lmyojni/jni/Vector3;
 */
JNIEXPORT jobject JNICALL Java_myojni_jni_Vector3_cross
  (JNIEnv *, jobject, jobject);

/*
 * Class:     myojni_jni_Vector3
 * Method:    angleTo
 * Signature: (Lmyojni/jni/Vector3;)F
 */
JNIEXPORT jfloat JNICALL Java_myojni_jni_Vector3_angleTo
  (JNIEnv *, jobject, jobject);

/*
 * Class:     myojni_jni_Vector3
 * Method:    dispose
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_myojni_jni_Vector3_dispose
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif