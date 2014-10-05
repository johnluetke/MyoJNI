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
    std::cout << "milliseconds: " << (unsigned int)milliseconds << std::endl;
    myo::Hub * hubPtr = getHandle<myo::Hub>(env, obj);
    //myo::Myo * myoPtr = hubPtr->waitForMyo((unsigned int)milliseconds); // TODO: SIGSEGV
}

void Java_myojni_jni_Hub_run(JNIEnv *env, jobject obj, jlong duration_ms) {
    std::cout << ">>> " << "Java_myojni_jni_Hub_run" << std::endl;
    std::cout << "duration_ms: " << (unsigned int)duration_ms << std::endl;
    myo::Hub * pHub = getHandle<myo::Hub>(env, obj);
    //pHub->run((unsigned int)duration_ms); // TODO: SIGSEGV
}

void Java_myojni_jni_Hub_runOnce(JNIEnv *env, jobject obj, jlong duration_ms) {
    std::cout << ">>> " << "Java_myojni_jni_Hub_runOnce" << std::endl;
    std::cout << "duration_ms: " << (unsigned int)duration_ms << std::endl;
    myo::Hub * pHub = getHandle<myo::Hub>(env, obj);
    //pHub->runOnce((unsigned int)duration_ms); // TODO: SIGSEGV
}

void Java_myojni_jni_Hub_dispose(JNIEnv *env, jobject obj) {
    clearHandle<myo::Hub>(env, obj);
}