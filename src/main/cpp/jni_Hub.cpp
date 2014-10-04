#include "handle.h"
#include "jni_Hub.h"
#include <string>
#include <myo/cxx/Hub.hpp>

void Java_jni_Hub_initialize(JNIEnv *env, jobject obj, jstring applicationIdentifier) {
	std::cout << "Entering Java_jni_Hub_initialize" << std::endl;
	std::string appId(env->GetStringUTFChars(applicationIdentifier, 0), 255);
	std::cout << "AppId: " << appId << std::endl;
	//myo::Hub hub(appId);
	//setHandle(env, obj, hub)
}