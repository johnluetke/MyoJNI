#include "net_johnluetke_myojni.h"

namespace MyoJNI {

    DeviceListener::DeviceListener(JNIEnv * env, jobject jDeviceListener) {
    	this->jDeviceListener = jDeviceListener;
    	this->env = env;
    }

    jobject DeviceListener::fetchJavaMyo(myo::Myo * myo) {
        jobject jMyo = MyoJNI::myoHashMap[myo]; // Fetch saved instance
        return jMyo;
    }

    void DeviceListener::onPair(myo::Myo * myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) {
        jobject javaFirmwareVersion = MyoJNI::getJavaFirmwareVersion(this->env, firmwareVersion);
        DEVICE_LISTENER_INVOKE_VOID("onPair", "(Lnet/johnluetke/myojni/jni/Myo;JLnet/johnluetke/myojni/jni/FirmwareVersion;)V", myo, timestamp, javaFirmwareVersion);
    }

    void DeviceListener::onUnpair(myo::Myo * myo, uint64_t timestamp) {
        DEVICE_LISTENER_INVOKE_VOID("onUnpair", "(Lnet/johnluetke/myojni/jni/Myo;J)V", myo, timestamp);
    }

    void DeviceListener::onConnect(myo::Myo * myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) {
        jobject javaFirmwareVersion = MyoJNI::getJavaFirmwareVersion(this->env, firmwareVersion);
        DEVICE_LISTENER_INVOKE_VOID("onConnect", "(Lnet/johnluetke/myojni/jni/Myo;JLnet/johnluetke/myojni/jni/FirmwareVersion;)V", myo, timestamp, javaFirmwareVersion);
    }

    void DeviceListener::onDisconnect(myo::Myo * myo, uint64_t timestamp) {
        DEVICE_LISTENER_INVOKE_VOID("onDisconnect", "(Lnet/johnluetke/myojni/jni/Myo;J)V", myo, timestamp);
    }

    void DeviceListener::onArmSync(myo::Myo * myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection) {
        jobject javaArm = MyoJNI::getJavaArm(this->env, arm);
        jobject javaXDirection = MyoJNI::getJavaXDirection(this->env, xDirection);
        DEVICE_LISTENER_INVOKE_VOID("onArmSync", "(Lnet/johnluetke/myojni/jni/Myo;JLnet/johnluetke/myojni/jni/Arm;Lnet/johnluetke/myojni/jni/XDirection;)V", myo, timestamp, javaArm, javaXDirection);
    }

    void DeviceListener::onArmUnsync(myo::Myo * myo, uint64_t timestamp) {
        DEVICE_LISTENER_INVOKE_VOID("onArmUnsync", "(Lnet/johnluetke/myojni/jni/Myo;J)V", myo, timestamp);
    }

    void DeviceListener::onUnlock(myo::Myo * myo, uint64_t timestamp) {
        DEVICE_LISTENER_INVOKE_VOID("onUnlock", "(Lnet/johnluetke/myojni/jni/Myo;J)V", myo, timestamp);
    }

    void DeviceListener::onLock(myo::Myo * myo, uint64_t timestamp) {
        DEVICE_LISTENER_INVOKE_VOID("onLock", "(Lnet/johnluetke/myojni/jni/Myo;J)V", myo, timestamp);
    }

    void DeviceListener::onPose(myo::Myo * myo, uint64_t timestamp, myo::Pose pose) {
        jobject javaPose = MyoJNI::getJavaPose(this->env, pose);
        DEVICE_LISTENER_INVOKE_VOID("onPose", "(Lnet/johnluetke/myojni/jni/Myo;JLnet/johnluetke/myojni/jni/Pose;)V", myo, timestamp, javaPose);
    }

    void DeviceListener::onOrientationData(myo::Myo * myo, uint64_t timestamp, const myo::Quaternion<float> & rotation) {
        jobject javaQuaternion = MyoJNI::getJavaQuaternion(this->env, rotation);
        DEVICE_LISTENER_INVOKE_VOID("onOrientationData", "(Lnet/johnluetke/myojni/jni/Myo;JLnet/johnluetke/myojni/jni/Quaternion;)V", myo, timestamp, javaQuaternion);
    }

    void DeviceListener::onAccelerometerData(myo::Myo * myo, uint64_t timestamp, const myo::Vector3<float> & accel) {
        jobject javaVector3 = MyoJNI::getJavaVector3(this->env, accel);
        DEVICE_LISTENER_INVOKE_VOID("onAccelerometerData", "(Lnet/johnluetke/myojni/jni/Myo;JLnet/johnluetke/myojni/jni/Vector3;)V", myo, timestamp, javaVector3);
    }

    void DeviceListener::onGyroscopeData(myo::Myo * myo, uint64_t timestamp, const myo::Vector3<float> & gyro) {
        jobject javaVector3 = MyoJNI::getJavaVector3(this->env, gyro);
        DEVICE_LISTENER_INVOKE_VOID("onGyroscopeData", "(Lnet/johnluetke/myojni/jni/Myo;JLnet/johnluetke/myojni/jni/Vector3;)V", myo, timestamp, javaVector3);
    }

    void DeviceListener::onRssi(myo::Myo * myo, uint64_t timestamp, int8_t rssi) {
        DEVICE_LISTENER_INVOKE_VOID("onRssi", "(Lnet/johnluetke/myojni/jni/Myo;JI)V", myo, timestamp, rssi);
    }

    void DeviceListener::onEmgData(myo::Myo * myo, uint64_t timestamp, const int8_t * emg) {
        jintArray emgData = this->env->NewIntArray(MYOJNI_EMG_ARRAY_SIZE);
        jint emgTemp[MYOJNI_EMG_ARRAY_SIZE];

        for (int8_t i = 0; i < MYOJNI_EMG_ARRAY_SIZE; i++) {
            emgTemp[i] = emg[i];
        }

        this->env->SetIntArrayRegion(emgData, 0, MYOJNI_EMG_ARRAY_SIZE, emgTemp);

        DEVICE_LISTENER_INVOKE_VOID("onEmgData", "(Lnet/johnluetke/myojni/jni/Myo;J[I)V", myo, timestamp, emgData);
    }
}