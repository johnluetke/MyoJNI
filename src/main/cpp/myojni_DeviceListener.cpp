#include "myojni.h"

namespace MyoJNI {

    DeviceListener::DeviceListener(JNIEnv * env, jobject jDeviceListener) {
    	this->jDeviceListener = jDeviceListener;
    	this->env = env;
    }

    jobject DeviceListener::fetchJavaMyo(myo::Myo * myo) {
        jobject jMyo = MyoJNI::myoHashMap[myo]; // Fetch saved instance from Java_myojni_jni_Hub_waitForMyo
        return jMyo;
    }

    void DeviceListener::onPair(myo::Myo * myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) {
        jobject javaFirmwareVersion = MyoJNI::getJavaFirmwareVersion(this->env, firmwareVersion);
        DEVICE_LISTENER_INVOKE_VOID("onPair", "(Lmyojni/jni/Myo;JLmyojni/jni/FirmwareVersion;)V", myo, timestamp, javaFirmwareVersion);
    }

    void DeviceListener::onUnpair(myo::Myo * myo, uint64_t timestamp) {
        DEVICE_LISTENER_INVOKE_VOID("onUnpair", "(Lmyojni/jni/Myo;J)V", myo, timestamp);
    }

    void DeviceListener::onConnect(myo::Myo * myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) {
        jobject javaFirmwareVersion = MyoJNI::getJavaFirmwareVersion(this->env, firmwareVersion);
        DEVICE_LISTENER_INVOKE_VOID("onConnect", "(Lmyojni/jni/Myo;JLmyojni/jni/FirmwareVersion;)V", myo, timestamp, javaFirmwareVersion);
    }

    void DeviceListener::onDisconnect(myo::Myo * myo, uint64_t timestamp) {
        DEVICE_LISTENER_INVOKE_VOID("onDisconnect", "(Lmyojni/jni/Myo;J)V", myo, timestamp);
    }

    void DeviceListener::onArmRecognized(myo::Myo * myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection) {
        jobject javaArm = MyoJNI::getJavaArm(this->env, arm);
        jobject javaXDirection = MyoJNI::getJavaXDirection(this->env, xDirection);
        DEVICE_LISTENER_INVOKE_VOID("onArmRecognized", "(Lmyojni/jni/Myo;JLmyojni/jni/Arm;Lmyojni/jni/XDirection;)V", myo, timestamp, javaArm, javaXDirection);
    }

    void DeviceListener::onArmLost(myo::Myo * myo, uint64_t timestamp) {
        DEVICE_LISTENER_INVOKE_VOID("onArmLost", "(Lmyojni/jni/Myo;J)V", myo, timestamp);
    }

    void DeviceListener::onPose(myo::Myo * myo, uint64_t timestamp, myo::Pose pose) {
    }

    void DeviceListener::onOrientationData(myo::Myo * myo, uint64_t timestamp, const myo::Quaternion<float> & rotation) {
    }

    void DeviceListener::onAccelerometerData(myo::Myo * myo, uint64_t timestamp, const myo::Vector3<float> & accel) {
        jobject javaVector3 = MyoJNI::getJavaVector3(this->env, accel);
        DEVICE_LISTENER_INVOKE_VOID("onAccelerometerData", "(Lmyojni/jni/Myo;JLmyojni/jni/Vector3;)V", myo, timestamp, javaVector3);
    }

    void DeviceListener::onGyroscopeData(myo::Myo * myo, uint64_t timestamp, const myo::Vector3<float> & gyro) {
        jobject javaVector3 = MyoJNI::getJavaVector3(this->env, gyro);
        DEVICE_LISTENER_INVOKE_VOID("onGyroscopeData", "(Lmyojni/jni/Myo;JLmyojni/jni/Vector3;)V", myo, timestamp, javaVector3);
    }

    void DeviceListener::onRssi(myo::Myo * myo, uint64_t timestamp, int8_t rssi) {
        DEVICE_LISTENER_INVOKE_VOID("onRssi", "(Lmyojni/jni/Myo;JI)V", myo, timestamp, rssi);
    }
}