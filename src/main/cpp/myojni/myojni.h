#ifndef _MYOJNI_H_INCLUDED_
#define _MYOJNI_H_INCLUDED_

#include <iostream>
#include <jni.h>
#include <string>


#include <myo/cxx/Hub.hpp>
#include <myo/cxx/Myo.hpp>

namespace MyoJNI {

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

}

#endif // _MYOJNI_H_INCLUDED_