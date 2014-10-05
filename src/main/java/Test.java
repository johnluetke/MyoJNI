import myojni.jni.Hub;

public class Test {

	public static void main(String[] args) {
		Hub hub = new Hub("com.example.test");
        /*Myo myo = */hub.waitForMyo(0);
	}
	
}
