import myojni.jni.*;

public class Test {

	public static void main(String[] args) {
		Hub hub = new Hub("com.example.test"); // Loads the native lib
        //hub.dispose();
        Myo myo = hub.waitForMyo(10000);

        if (myo != null) {
            myo.vibrate(VibrationType.Short);
        }

        hub.addListener(new DeviceListener() {
            @Override
            public void onPair(Myo myo, long timestamp, FirmwareVersion firmwareVersion) {
                //To change body of implemented methods use File | Settings | File Templates.
            }

            @Override
            public void onUnpair(Myo myo, long timestamp) {
                //To change body of implemented methods use File | Settings | File Templates.
            }

            @Override
            public void onConnect(Myo myo, long timestamp, FirmwareVersion firmwareVersion) {
                //To change body of implemented methods use File | Settings | File Templates.
            }

            @Override
            public void onDisconnect(Myo myo, long timestamp) {
                //To change body of implemented methods use File | Settings | File Templates.
            }

            @Override
            public void onArmRecognized(Myo myo, long timestamp, Arm arm, XDirection xDirection) {
                //To change body of implemented methods use File | Settings | File Templates.
            }

            @Override
            public void onArmLost(Myo myo, long timestamp) {
                //To change body of implemented methods use File | Settings | File Templates.
            }

            @Override
            public void onPose(Myo myo, long timestamp, Pose pose) {
                //To change body of implemented methods use File | Settings | File Templates.
            }

            @Override
            public void onAccelerometerData(Myo myo, long timestamp, Vector3 accel) {
                //To change body of implemented methods use File | Settings | File Templates.
            }

            @Override
            public void onGyroscopeData(Myo myo, long timestamp, Vector3 gyro) {
                //To change body of implemented methods use File | Settings | File Templates.
            }

            @Override
            public void onRssi(Myo myo, long timestamp, int rssi) {
                System.out.println("[" + myo.toString() + "] RSSI: " + rssi);
            }
        });

        myo.toString();
        hub.run(1000);
        hub.runOnce(1000);
        //hub.dispose();

        while (true) {
            hub.run(1000);
            myo.requestRssi();
        }
	}
	
}
