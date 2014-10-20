#include "myojni.h"

namespace MyoJNI {

    std::map<jint, MyoJNI::DeviceListener *> deviceListenerHashMap;
    std::map<myo::Myo *, jobject> myoHashMap;

    jobject getJavaArm(JNIEnv * env, myo::Arm arm) {
    	std::string armString;
    	switch (arm) {
    		case myo::armLeft:
    			armString = "Left";
    			break;
    		case myo::armRight:
    			armString = "Right";
    			break;
    		case myo::armUnknown:
    		default:
    			armString = "Unknown";
    			break;
    	};

    	jclass armClass = env->FindClass("myojni/jni/Arm");
    	jfieldID armFieldID = env->GetStaticFieldID(armClass, armString.c_str(), "Lmyojni/jni/Arm;");
    	jobject javaArmObject = env->GetStaticObjectField(armClass, armFieldID);

    	return javaArmObject;
    }

    jobject getJavaFirmwareVersion(JNIEnv * env, myo::FirmwareVersion firmwareVersion) {
        jclass firmwareVersionClass = env->FindClass("myojni/jni/FirmwareVersion");
        jmethodID firmwareVersionConstructor = env->GetMethodID(firmwareVersionClass, "<init>", "(IIII)V");
        jobject javaFirmwareVersion = env->NewObject(firmwareVersionClass,
                                                     firmwareVersionConstructor,
                                                     firmwareVersion.firmwareVersionMajor,
                                                     firmwareVersion.firmwareVersionMinor,
                                                     firmwareVersion.firmwareVersionPatch,
                                                     firmwareVersion.firmwareVersionHardwareRev);

        return javaFirmwareVersion;
    }

    jobject getJavaVector3(JNIEnv * env, myo::Vector3<float> vector3) {
    	jclass vector3Class = env->FindClass("myojni/jni/Vector3");
        jmethodID vector3Constructor = env->GetMethodID(vector3Class, "<init>", "(DDD)V");
        jobject javaVector3 = env->NewObject(vector3Class,
                                             vector3Constructor,
                                             vector3.x(),
                                             vector3.y(),
                                             vector3.z());

    	return javaVector3;
    }

    jobject getJavaXDirection(JNIEnv * env, myo::XDirection xDirection) {
    	std::string xDirectionString;
    	switch(xDirection) {
    		case myo::xDirectionTowardWrist:
    			xDirectionString = "TowardsWrist";
    			break;
    		case myo::xDirectionTowardElbow:
    			xDirectionString = "TowardsElbow";
    			break;
    		case myo::xDirectionUnknown:
    		default:
    			xDirectionString = "Unknown";
    			break;
    	};

    	jclass xDirectionClass = env->FindClass("myojni/jni/XDirection");
    	jfieldID xDirectionFieldID = env->GetStaticFieldID(xDirectionClass, xDirectionString.c_str(), "Lmyojni/jni/XDirection;");
    	jobject javaXDirectionObject = env->GetStaticObjectField(xDirectionClass, xDirectionFieldID);

    	return javaXDirectionObject;
    }

    void dispose() {
    }
}