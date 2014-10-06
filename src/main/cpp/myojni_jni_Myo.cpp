#include "myojni.h"
#include "myojni_jni_Myo.h"

JNIEXPORT void JNICALL Java_myojni_jni_Myo_vibrate(JNIEnv *env, jobject obj, jint vibration) {
	myo::Myo * myo = getJNIHandle<myo::Myo>(env, obj);
	try {
		if (vibration == 0) {
			myo->vibrate(myo::Myo::vibrationShort);
		}
		else if (vibration == 1) {
			myo->vibrate(myo::Myo::vibrationMedium);
		}
		else if (vibration == 2) {
			myo->vibrate(myo::Myo::vibrationLong);
		}
	}
	catch (const std::exception & e) {
		env->ThrowNew(env->FindClass("java/lang/RuntimeException"), e.what());
	}
}

JNIEXPORT void JNICALL Java_myojni_jni_Myo_requestRssi(JNIEnv *env, jobject obj) {
	myo::Myo * myo = getJNIHandle<myo::Myo>(env, obj);
	try {
		myo->requestRssi();
	}
	catch (const std::exception & e) {
		env->ThrowNew(env->FindClass("java/lang/RuntimeException"), e.what());
    }
}