#include "net_johnluetke_myojni.h"

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

    	jclass armClass = env->FindClass("net/johnluetke/myojni/jni/Arm");
    	jfieldID armFieldID = env->GetStaticFieldID(armClass, armString.c_str(), "Lnet/johnluetke/myojni/jni/Arm;");
    	jobject javaArmObject = env->GetStaticObjectField(armClass, armFieldID);

    	return javaArmObject;
    }

    jobject getJavaFirmwareVersion(JNIEnv * env, myo::FirmwareVersion firmwareVersion) {
        jclass firmwareVersionClass = env->FindClass("net/johnluetke/myojni/jni/FirmwareVersion");
        jmethodID firmwareVersionConstructor = env->GetMethodID(firmwareVersionClass, "<init>", "(IIII)V");
        jobject javaFirmwareVersion = env->NewObject(firmwareVersionClass,
                                                     firmwareVersionConstructor,
                                                     firmwareVersion.firmwareVersionMajor,
                                                     firmwareVersion.firmwareVersionMinor,
                                                     firmwareVersion.firmwareVersionPatch,
                                                     firmwareVersion.firmwareVersionHardwareRev);

        return javaFirmwareVersion;
    }

    jobject getJavaPose(JNIEnv * env, myo::Pose pose) {
        std::string poseString;
        switch(pose.type()) {
            case myo::Pose::rest:
                poseString = "Rest";
                break;
            case myo::Pose::fist:
                poseString = "Fist";
                break;
            case myo::Pose::waveIn:
                poseString = "WaveIn";
                break;
            case myo::Pose::waveOut:
                poseString = "WaveOut";
                break;
            case myo::Pose::fingersSpread:
                poseString = "FingersSpread";
                break;
            case myo::Pose::doubleTap:
                poseString = "DoubleTap";
                break;
            case myo::Pose::unknown:
            default:
                poseString = "Unknown";
                break;
        };

        jclass poseClass = env->FindClass("net/johnluetke/myojni/jni/Pose");
        jfieldID poseFieldID = env->GetStaticFieldID(poseClass, poseString.c_str(), "Lnet/johnluetke/myojni/jni/Pose;");
        jobject javaPoseObject = env->GetStaticObjectField(poseClass, poseFieldID);

        return javaPoseObject;
    }

    jobject getJavaQuaternion(JNIEnv * env, myo::Quaternion<float> quaternion) {
        jclass quaternionClass = env->FindClass("net/johnluetke/myojni/jni/Quaternion");
        jmethodID quaternionConstructor = env->GetMethodID(quaternionClass, "<init>", "(DDDD)V");
        jobject javaQuaternion = env->NewObject(quaternionClass,
                                                quaternionConstructor,
                                                quaternion.x(),
                                                quaternion.y(),
                                                quaternion.z(),
                                                quaternion.w());

        return javaQuaternion;
    }

    jobject getJavaVector3(JNIEnv * env, myo::Vector3<float> vector3) {
    	jclass vector3Class = env->FindClass("net/johnluetke/myojni/jni/Vector3");
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
    	jfieldID xDirectionFieldID = env->GetStaticFieldID(xDirectionClass, xDirectionString.c_str(), "Lnet/johnluetke/myojni/jni/XDirection;");
    	jobject javaXDirectionObject = env->GetStaticObjectField(xDirectionClass, xDirectionFieldID);

    	return javaXDirectionObject;
    }
}