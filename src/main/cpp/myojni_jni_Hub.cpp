#include "myojni.h"
#include "myojni_jni_Hub.h"

void Java_myojni_jni_Hub_initialize(JNIEnv *env, jobject obj, jstring applicationIdentifier) {
	std::string appId(env->GetStringUTFChars(applicationIdentifier, 0), env->GetStringUTFLength(applicationIdentifier));
	myo::Hub hub(appId);
    myo::Hub * pHub = & hub;
	setHandle(env, obj, pHub);
}

jobject Java_myojni_jni_Hub_waitForMyo(JNIEnv *env, jobject obj, jlong milliseconds) {
    std::cout << ">>> " << "Java_jni_Hub_waitForMyo" << std::endl;
    std::cout << "milliseconds: " << milliseconds << std::endl;
    myo::Hub * hubPtr = getHandle<myo::Hub>(env, obj);
    myo::Myo * myoPtr = hubPtr->waitForMyo(milliseconds); // TODO: SIGSEGV
}

void Java_myojni_jni_Hub_dispose(JNIEnv *env, jobject obj) {
    clearHandle<myo::Hub>(env, obj);
}