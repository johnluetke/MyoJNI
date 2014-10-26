import net.johnluetke.myojni.jni.*;

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
                System.out.println("Myo was paired! " + firmwareVersion);
            }

            @Override
            public void onUnpair(Myo myo, long timestamp) {
                System.out.println("Myo was unpaired!");
            }

            @Override
            public void onConnect(Myo myo, long timestamp, FirmwareVersion firmwareVersion) {
                System.out.println("Myo connected! " + firmwareVersion);
            }

            @Override
            public void onDisconnect(Myo myo, long timestamp) {
                System.out.println("Myo was disconnected!");
            }

            @Override
            public void onArmRecognized(Myo myo, long timestamp, Arm arm, XDirection xDirection) {
                System.out.println(arm + " arm was detected, XDirection is " + xDirection);
            }

            @Override
            public void onArmLost(Myo myo, long timestamp) {
                System.out.println("Arm was lost");
            }

            @Override
            public void onPose(Myo myo, long timestamp, Pose pose) {
                System.out.println("Pose: " + pose);
            }

            @Override
            public void onOrientationData(Myo myo, long timestamp, Quaternion rotation) {

            }

            @Override
            public void onAccelerometerData(Myo myo, long timestamp, Vector3 accel) {
                System.out.println("Accel data received. " + accel);
            }

            @Override
            public void onGyroscopeData(Myo myo, long timestamp, Vector3 gyro) {
                System.out.println("Gyro data received. " + gyro);
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
            //myo.requestRssi();
        }
	}
	
}
