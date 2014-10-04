package jni;

public class Hub {

	public Hub(String applicationIdentifer) {
		initialize(applicationIdentifer);
	}
	
	private native void initialize(String applicationIdentifer);
	
	public native Myo waitForMyo(long milliseconds);
	
}
