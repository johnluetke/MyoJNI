#include "net_johnluetke_myojni.h"
#include "net_johnluetke_myojni_jni_Myo.h"

JNIEXPORT void JNICALL Java_net_johnluetke_myojni_jni_Myo_lock(JNIEnv *env, jobject obj) {
	myo::Myo * myo = MyoJNI::getJNIHandle<myo::Myo>(env, obj);
	myo->lock();
}

JNIEXPORT void JNICALL Java_net_johnluetke_myojni_jni_Myo_notifyUserAction (JNIEnv *env, jobject obj) {
 	myo::Myo * myo = MyoJNI::getJNIHandle<myo::Myo>(env, obj);
 	try {
 		myo->notifyUserAction();
 	}
 	catch (const std::exception & e) {
 		env->ThrowNew(env->FindClass("java/lang/RuntimeException"), e.what());
     }
}

JNIEXPORT void JNICALL Java_net_johnluetke_myojni_jni_Myo_requestRssi(JNIEnv *env, jobject obj) {
	myo::Myo * myo = MyoJNI::getJNIHandle<myo::Myo>(env, obj);
	try {
		myo->requestRssi();
	}
	catch (const std::exception & e) {
		env->ThrowNew(env->FindClass("java/lang/RuntimeException"), e.what());
    }
}

JNIEXPORT void JNICALL Java_net_johnluetke_myojni_jni_Myo_setStreamEmg(JNIEnv *env, jobject obj, jint streamEmgType) {
	myo::Myo * myo = MyoJNI::getJNIHandle<myo::Myo>(env, obj);
	try {
		if (streamEmgType == 0) {
			myo->setStreamEmg(myo::Myo::streamEmgDisabled);
		}
		else if (streamEmgType == 1) {
			myo->setStreamEmg(myo::Myo::streamEmgEnabled);
		}
		else {
			env->ThrowNew(env->FindClass("java/lang/RuntimeException"), "Invalid streamEmgType type");
		}
	}
	catch (const std::exception & e) {
		env->ThrowNew(env->FindClass("java/lang/RuntimeException"), e.what());
	}
}

JNIEXPORT void JNICALL Java_net_johnluetke_myojni_jni_Myo_unlock(JNIEnv *env, jobject obj, jint unlockType) {
	myo::Myo * myo = MyoJNI::getJNIHandle<myo::Myo>(env, obj);
	try {
		if (unlockType == 0) {
			myo->unlock(myo::Myo::unlockTimed);
		}
		else if (unlockType == 1) {
			myo->unlock(myo::Myo::unlockHold);
		}
		else {
			env->ThrowNew(env->FindClass("java/lang/RuntimeException"), "Invalid unlock type");
		}
	}
	catch (const std::exception & e) {
		env->ThrowNew(env->FindClass("java/lang/RuntimeException"), e.what());
	}
}

JNIEXPORT void JNICALL Java_net_johnluetke_myojni_jni_Myo_vibrate(JNIEnv *env, jobject obj, jint vibration) {
	myo::Myo * myo = MyoJNI::getJNIHandle<myo::Myo>(env, obj);
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