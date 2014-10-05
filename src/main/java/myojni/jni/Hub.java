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

    @Override
    public native void dispose();
}
