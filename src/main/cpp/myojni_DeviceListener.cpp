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
    }

    void DeviceListener::onUnpair(myo::Myo * myo, uint64_t timestamp) {
    }

    void DeviceListener::onConnect(myo::Myo * myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) {
    }

    void DeviceListener::onDisconnect(myo::Myo * myo, uint64_t timestamp) {
    }

    void DeviceListener::onArmRecognized(myo::Myo * myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection) {
    }

    void DeviceListener::onArmLost(myo::Myo * myo, uint64_t timestamp) {
    }

    void DeviceListener::onPose(myo::Myo * myo, uint64_t timestamp,myo::Pose pose) {
    }

    void DeviceListener::onOrientationData(myo::Myo * myo, uint64_t timestamp, const myo::Quaternion<float> & rotation) {
    }

    void DeviceListener::onAccelerometerData(myo::Myo * myo, uint64_t timestamp, const myo::Vector3<float> & accel) {
    }

    void DeviceListener::onGyroscopeData(myo::Myo * myo, uint64_t timestamp, const myo::Vector3<float> & gyro) {
    }

    void DeviceListener::onRssi(myo::Myo * myo, uint64_t timestamp, int8_t rssi) {
       	jobject jMyo = fetchJavaMyo(myo);
        jmethodID onRssiMethod = this->env->GetMethodID(this->env->GetObjectClass(this->jDeviceListener), "onRssi", "(Lmyojni/jni/Myo;JI)V");
       	env->CallVoidMethod(this->jDeviceListener, onRssiMethod, jMyo, timestamp, rssi);
    }
}