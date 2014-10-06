#include "myojni.h"
#include "myojni_jni_Hub.h"

JNIEXPORT void JNICALL Java_myojni_jni_Hub_initialize(JNIEnv *env, jobject obj, jstring applicationIdentifier) {
    try {
	    const char * appId = env->GetStringUTFChars(applicationIdentifier, 0);
	    myo::Hub * hub = new myo::Hub(appId);
	    setJNIHandle(env, obj, hub);
	}
	catch (const std::exception & e) {
    	jclass exceptionClass = env->FindClass("java/lang/RuntimeException");
    	env->ThrowNew(exceptionClass, e.what());
    }
}

JNIEXPORT jobject JNICALL Java_myojni_jni_Hub_waitForMyo(JNIEnv *env, jobject obj, jlong milliseconds) {
    myo::Hub * hub = getJNIHandle<myo::Hub>(env, obj);
    myo::Myo * myo = hub->waitForMyo(milliseconds);
    // According to SDK docs, timeout produces a null return
    if (myo == NULL) {
        return NULL;
    }
    else {
        jclass jMyoClass = env->FindClass("myojni/jni/Myo");
        jmethodID jMyoConst = env->GetMethodID(jMyoClass, "<init>", "()V") ;

        jobject jMyoObj = env->NewGlobalRef(env->NewObject(jMyoClass, jMyoConst));
        setJNIHandle(env, jMyoObj, myo);
        return jMyoObj;
    }
}

JNIEXPORT void JNICALL Java_myojni_jni_Hub_run(JNIEnv *env, jobject obj, jlong duration_ms) {
    myo::Hub * hub = getJNIHandle<myo::Hub>(env, obj);
    if (hub == NULL) {
        env->ThrowNew(env->FindClass("java/lang/RuntimeException"), "No native Hub object found");
    }
    hub->run(duration_ms);
}

JNIEXPORT void JNICALL Java_myojni_jni_Hub_runOnce(JNIEnv *env, jobject obj, jlong duration_ms) {
    myo::Hub * hub = getJNIHandle<myo::Hub>(env, obj);
    if (hub == NULL) {
        env->ThrowNew(env->FindClass("java/lang/RuntimeException"), "No native Hub object found");
    }
    hub->runOnce(duration_ms);
}

void Java_myojni_jni_Hub_dispose(JNIEnv *env, jobject obj) {
    clearJNIHandle<myo::Hub>(env, obj);
}