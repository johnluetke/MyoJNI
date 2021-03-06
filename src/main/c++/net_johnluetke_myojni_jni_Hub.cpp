#include "net_johnluetke_myojni.h"
#include "net_johnluetke_myojni_jni_Hub.h"

JNIEXPORT void JNICALL Java_net_johnluetke_myojni_jni_Hub_initialize(JNIEnv *env, jobject obj, jstring applicationIdentifier) {
    try {
	    const char * appId = env->GetStringUTFChars(applicationIdentifier, 0);
	    std::cout << appId;
	    myo::Hub * hub = new myo::Hub(appId);
	    MyoJNI::setJNIHandle(env, obj, hub);
	}
	catch (const std::exception & e) {
    	env->ThrowNew(env->FindClass("java/lang/RuntimeException"), e.what());
    }
}

JNIEXPORT jobject JNICALL Java_net_johnluetke_myojni_jni_Hub_waitForMyo(JNIEnv *env, jobject obj, jlong milliseconds) {
    myo::Hub * hub = MyoJNI::getJNIHandle<myo::Hub>(env, obj);
    myo::Myo * myo = hub->waitForMyo((unsigned int)milliseconds);
    // According to SDK docs, timeout produces a null return
    if (myo == NULL) {
        return NULL;
    }
    else {
        jclass jMyoClass = env->FindClass("net/johnluetke/myojni/jni/Myo");
        jmethodID jMyoConst = env->GetMethodID(jMyoClass, "<init>", "()V") ;

        jobject jMyoObj = env->NewGlobalRef(env->NewObject(jMyoClass, jMyoConst));
        MyoJNI::myoHashMap[myo] = jMyoObj; // Saves this instance for future use
        MyoJNI::setJNIHandle(env, jMyoObj, myo);
        return jMyoObj;
    }
}

JNIEXPORT void JNICALL Java_net_johnluetke_myojni_jni_Hub_addListener(JNIEnv *env, jobject obj, jobject jDeviceListener) {
    myo::Hub * hub = MyoJNI::getJNIHandle<myo::Hub>(env, obj);
    if (hub == NULL) {
        env->ThrowNew(env->FindClass("java/lang/RuntimeException"), "Native Hub object is null");
    }
    else {
        // Java hash codes are unique per instance
        jmethodID hashCodeMethod = env->GetMethodID(env->GetObjectClass(jDeviceListener), "hashCode", "()I");
        jint jDeviceListenerHashCode = env->CallIntMethod(jDeviceListener, hashCodeMethod);

        if (MyoJNI::deviceListenerHashMap.count(jDeviceListenerHashCode) == 0) {
            // Map this Java DeviceListener to a MyoJNI one
            jobject newJObject = env->NewGlobalRef(jDeviceListener);
            MyoJNI::DeviceListener * deviceListener = new MyoJNI::DeviceListener(env, newJObject);
            MyoJNI::deviceListenerHashMap[jDeviceListenerHashCode] = deviceListener;
            hub->addListener(deviceListener);
        }
    }
}

JNIEXPORT void JNICALL Java_net_johnluetke_myojni_jni_Hub_removeListener(JNIEnv *env, jobject obj, jobject jDeviceListener) {
    myo::Hub * hub = MyoJNI::getJNIHandle<myo::Hub>(env, obj);
    if (hub == NULL) {
        env->ThrowNew(env->FindClass("java/lang/RuntimeException"), "Native Hub object is null");
    }
    else {
        jmethodID hashCodeMethod = env->GetMethodID(env->GetObjectClass(jDeviceListener), "hashCode", "()I");
        jint jDeviceListenerHashCode = env->CallIntMethod(jDeviceListener, hashCodeMethod);

        MyoJNI::deviceListenerHashMap.erase(jDeviceListenerHashCode);
    }
}

JNIEXPORT void JNICALL Java_net_johnluetke_myojni_jni_Hub_pSetLockingPolicy (JNIEnv *env, jobject obj, jint lockingPolicy) {
    myo::Hub * hub = MyoJNI::getJNIHandle<myo::Hub>(env, obj);
    if (hub == NULL) {
        env->ThrowNew(env->FindClass("java/lang/RuntimeException"), "No native Hub object found");
    }
    if (lockingPolicy == 0) {
        hub->setLockingPolicy(myo::Hub::lockingPolicyNone);
    }
    else if (lockingPolicy == 1) {
        hub->setLockingPolicy(myo::Hub::lockingPolicyStandard);
    }
    else {
        env->ThrowNew(env->FindClass("java/lang/RuntimeException"), "Invalid lock policy");
    }
}

JNIEXPORT void JNICALL Java_net_johnluetke_myojni_jni_Hub_run(JNIEnv *env, jobject obj, jlong duration_ms) {
    myo::Hub * hub = MyoJNI::getJNIHandle<myo::Hub>(env, obj);
    if (hub == NULL) {
        env->ThrowNew(env->FindClass("java/lang/RuntimeException"), "No native Hub object found");
    }
    hub->run((unsigned int)duration_ms);
}

JNIEXPORT void JNICALL Java_net_johnluetke_myojni_jni_Hub_runOnce(JNIEnv *env, jobject obj, jlong duration_ms) {
    myo::Hub * hub = MyoJNI::getJNIHandle<myo::Hub>(env, obj);
    if (hub == NULL) {
        env->ThrowNew(env->FindClass("java/lang/RuntimeException"), "No native Hub object found");
    }
    hub->runOnce((unsigned int)duration_ms);
}

void Java_net_johnluetke_myojni_jni_Hub_dispose(JNIEnv *env, jobject obj) {
    MyoJNI::clearJNIHandle<myo::Hub>(env, obj);
}