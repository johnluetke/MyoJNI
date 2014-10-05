package myojni.jni;

import myojni.Disposable;

public class Hub implements Disposable {

    static {
        System.load(System.getProperty("user.dir") + "/libmyojni.so");
    }

    protected long nativeHandle;

	public Hub(String applicationIdentifier) {
		initialize(applicationIdentifier);
	}

    protected Hub(long handle) {
        nativeHandle = handle;
    }

	private native void initialize(String applicationIdentifier);
	
	public native Myo waitForMyo(long milliseconds);

    public native void run(long duration_ms);

    public native void runOnce(long duration_ms);

    @Override
    public native void dispose();
}
