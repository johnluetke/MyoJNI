package myojni.jni;

import myojni.Disposable;

public class Myo implements Disposable {

    protected long nativeHandle;

    protected Myo(long handle) {
        nativeHandle = handle;
    }

	public native void vibrate(VibrationType vibration);
	
	public native void requestRssi();

    public native void dispose();
}
