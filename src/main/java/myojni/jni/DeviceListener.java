package myojni.jni;

import myojni.Disposable;

public abstract class DeviceListener implements Disposable {

    public abstract void onPair(Myo myo, long timestamp, FirmwareVersion firmwareVersion);

    public abstract void onUnpair(Myo myo, long timestamp);

    public abstract void onConnect(Myo myo, long timestamp, FirmwareVersion firmwareVersion);

    public abstract void onDisconnect(Myo myo, long timestamp);

    public abstract void onArmRecognized(Myo myo, long timestamp, Arm arm, XDirection xDirection);

    public abstract void onArmLost(Myo myo, long timestamp);

    public abstract void onPose(Myo myo, long timestamp, Pose pose);

    //public abstract void onOrientationData(Myo myo, long timestamp, Quaternion<float> rotation);

    public abstract void onAccelerometerData(Myo myo, long timestamp, Vector3 accel);

    public abstract void onGyroscopeData(Myo myo, long timestamp, Vector3 gyro);

    public abstract void onRssi(Myo myo, long timestamp, byte rssi);

    public native void dispose();
}
