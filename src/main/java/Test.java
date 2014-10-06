import myojni.jni.Hub;
import myojni.jni.Vector3;

public class Test {

	public static void main(String[] args) {
		Hub hub = new Hub("com.example.test"); // Loads the native lib
        ///*Myo myo = */hub.waitForMyo(0);
        //hub.run(1000);
        //hub.runOnce(1000);
        //hub.dispose();

        Vector3 v3 = new Vector3();
        v3 = new Vector3(1f,2f,3f);
        //System.out.println(v3.getX());
        System.out.println(v3);
	}
	
}
