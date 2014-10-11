#include "myojni.h"
#include "myojni_jni_Hub.h"

JNIEXPORT void JNICALL Java_myojni_jni_Hub_initialize(JNIEnv *env, jobject obj, jstring applicationIdentifier) {
    try {
	    const char * appId = env->GetStringUTFChars(applicationIdentifier, 0);
	    myo::Hub * hub = new myo::Hub(appId);
	    MyoJNI::setJNIHandle(env, obj, hub);
	}
	catch (const std::exception & e) {
    	env->ThrowNew(env->FindClass("java/lang/RuntimeException"), e.what());
    }
}

JNIEXPORT jobject JNICALL Java_myojni_jni_Hub_waitForMyo(JNIEnv *env, jobject obj, jlong milliseconds) {
    myo::Hub * hub = MyoJNI::getJNIHandle<myo::Hub>(env, obj);
    myo::Myo * myo = hub->waitForMyo(milliseconds);
    // According to SDK docs, timeout produces a null return
    if (myo == NULL) {
        return NULL;
    }
    else {
        jclass jMyoClass = env->FindClass("myojni/jni/Myo");
        jmethodID jMyoConst = env->GetMethodID(jMyoClass, "<init>", "()V") ;

        jobject jMyoObj = env->NewGlobalRef(env->NewObject(jMyoClass, jMyoConst));
        MyoJNI::myoHashMap[myo] = jMyoObj; // Saves this instance for future use
        MyoJNI::setJNIHandle(env, jMyoObj, myo);
        return jMyoObj;
    }
}

JNIEXPORT void JNICALL Java_myojni_jni_Hub_addListener(JNIEnv *env, jobject obj, jobject jDeviceListener) {
    // Need to map to C++ impl
    // Need to somehow identify and save the listener instance so that it can be "removed"
    // - Cant create new map to C++ cause it would be a diff object, need to save the instance itself.
    env->ThrowNew(env->FindClass("java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT void JNICALL Java_myojni_jni_Hub_removeListener(JNIEnv *env, jobject obj, jobject jDevceListener) {
    env->ThrowNew(env->FindClass("java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT void JNICALL Java_myojni_jni_Hub_run(JNIEnv *env, jobject obj, jlong duration_ms) {
    myo::Hub * hub = MyoJNI::getJNIHandle<myo::Hub>(env, obj);
    if (hub == NULL) {
        env->ThrowNew(env->FindClass("java/lang/RuntimeException"), "No native Hub object found");
    }
    hub->run(duration_ms);
}

JNIEXPORT void JNICALL Java_myojni_jni_Hub_runOnce(JNIEnv *env, jobject obj, jlong duration_ms) {
    myo::Hub * hub = MyoJNI::getJNIHandle<myo::Hub>(env, obj);
    if (hub == NULL) {
        env->ThrowNew(env->FindClass("java/lang/RuntimeException"), "No native Hub object found");
    }
    hub->runOnce(duration_ms);
}

void Java_myojni_jni_Hub_dispose(JNIEnv *env, jobject obj) {
    MyoJNI::clearJNIHandle<myo::Hub>(env, obj);
}