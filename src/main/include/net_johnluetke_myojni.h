#ifndef _MYOJNI_H_INCLUDED_
#define _MYOJNI_H_INCLUDED_

#include <iostream>
#include <map>
#include <string>
#include <jni.h>
#include <myo/myo.hpp>
#include <myo/cxx/Hub.hpp>

#include "net_johnluetke_myojni_DeviceListener.h"

namespace MyoJNI {

    extern std::map<jint, MyoJNI::DeviceListener *> deviceListenerHashMap;
    extern std::map<myo::Myo *, jobject> myoHashMap;

    static inline jfieldID getJNIHandleField(JNIEnv *env, jobject obj)
    {
        jclass c = env->GetObjectClass(obj);
        // J is the type signature for long:
        return env->GetFieldID(c, "nativeHandle", "J");
    }

    template <typename T>
    static T *getJNIHandle(JNIEnv *env, jobject obj)
    {
        jlong handle = env->GetLongField(obj, getJNIHandleField(env, obj));
        return reinterpret_cast<T *>(handle);
    }

    template <typename T>
    static void setJNIHandle(JNIEnv *env, jobject obj, T *t)
    {
        jlong handle = reinterpret_cast<jlong>(t);
        env->SetLongField(obj, getJNIHandleField(env, obj), handle);
    }

    template <typename T>
    static void clearJNIHandle(JNIEnv *env, jobject obj)
    {
        jlong handle = env->GetLongField(obj, getJNIHandleField(env, obj));
        T * t = reinterpret_cast<T *>(handle);
        delete t;
    }

    jobject getJavaArm(JNIEnv * env, myo::Arm arm);

    jobject getJavaFirmwareVersion(JNIEnv * env, myo::FirmwareVersion firmwareVersion);

    jobject getJavaPose(JNIEnv * env, myo::Pose pose);

    jobject getJavaQuaternion(JNIEnv * env, myo::Quaternion<float> quaternion);

    jobject getJavaVector3(JNIEnv * env, myo::Vector3<float> vector3);

    jobject getJavaXDirection(JNIEnv * env, myo::XDirection xDirection);

}

#endif // _MYOJNI_H_INCLUDED_