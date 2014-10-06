#include "myojni.h"
#include "myojni_jni_Vector3.h"

void Java_myojni_jni_Vector3_initialize(JNIEnv *env, jobject obj) {
	myo::Vector3<float> vector;
    myo::Vector3<float> * pVector = & vector;
	setJNIHandle(env, obj, pVector);
}

void Java_myojni_jni_Vector3_initializeXYZ(JNIEnv *env, jobject obj, jfloat x, jfloat y, jfloat z) {
	myo::Vector3<float> vector(x, y, z);
    myo::Vector3<float> * pVector = & vector;
	setJNIHandle(env, obj, pVector);
}

jfloat Java_myojni_jni_Vector3_X(JNIEnv *env, jobject obj) {
    myo::Vector3<float> * pVector = getJNIHandle<myo::Vector3<float> >(env, obj);
    return pVector->x();
}

jfloat Java_myojni_jni_Vector3_Y(JNIEnv *env, jobject obj) {
    myo::Vector3<float> * pVector = getJNIHandle<myo::Vector3<float> >(env, obj);
    return pVector->y();
}

jfloat Java_myojni_jni_Vector3_Z(JNIEnv *env, jobject obj) {
    myo::Vector3<float> * pVector = getJNIHandle<myo::Vector3<float> >(env, obj);
    return pVector->z();
}

jfloat Java_myojni_jni_Vector3_magnitude(JNIEnv *env, jobject obj) {
    myo::Vector3<float> * pVector = getJNIHandle<myo::Vector3<float> >(env, obj);
    return pVector->magnitude();
}

jobject Java_myojni_jni_Vector3_normalized(JNIEnv *env, jobject obj);

jfloat Java_myojni_jni_Vector3_dot(JNIEnv *env, jobject obj, jobject);

jobject Java_myojni_jni_Vector3_cross(JNIEnv *env, jobject obj, jobject);

jfloat Java_myojni_jni_Vector3_angleTo(JNIEnv *env, jobject obj, jobject);

void Java_myojni_jni_Vector3_dispose(JNIEnv *env, jobject obj) {
    clearJNIHandle<myo::Vector3<float> >(env, obj);
}