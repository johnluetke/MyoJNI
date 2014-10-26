#ifndef __MYOJNI_DEVICELISTENER_INCLUDED__
#define __MYOJNI_DEVICELISTENER_INCLUDED__

#include "myojni.h"

#define DEVICE_LISTENER_INVOKE_VOID(methodName, javaMethodSignature, myo, javaMethodArgs...) \
            jobject jMyo = fetchJavaMyo(myo); \
            jmethodID method = this->env->GetMethodID(this->env->GetObjectClass(this->jDeviceListener), methodName, javaMethodSignature); \
            this->env->CallVoidMethod(this->jDeviceListener, method, jMyo, javaMethodArgs);

namespace MyoJNI {

    class DeviceListener : public myo::DeviceListener {

        private:
        jobject jDeviceListener;
        JNIEnv * env;

        jobject fetchJavaMyo(myo::Myo * myo);

        public:
        DeviceListener(JNIEnv *, jobject);

        void onPair(myo::Myo * myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion);

        void onUnpair(myo::Myo * myo, uint64_t timestamp);

        void onConnect(myo::Myo * myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion);

        void onDisconnect(myo::Myo * myo, uint64_t timestamp);

        void onArmRecognized(myo::Myo * myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection);

        void onArmLost(myo::Myo * myo, uint64_t timestamp);

        void onPose(myo::Myo * myo, uint64_t timestamp, myo::Pose pose);

        void onOrientationData(myo::Myo * myo, uint64_t timestamp, const myo::Quaternion<float> & rotation);

        void onAccelerometerData(myo::Myo * myo, uint64_t timestamp, const myo::Vector3<float> & accel);

        void onGyroscopeData(myo::Myo * myo, uint64_t timestamp, const myo::Vector3<float> & gyro);

        void onRssi(myo::Myo * myo, uint64_t timestamp, int8_t rssi);
    };
}

#endif // __MYOJNI_DEVICELISTENER_INCLUDED__