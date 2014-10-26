package net.johnluetke.myojni.jni;

import net.johnluetke.myojni.Disposable;

public class Myo implements Disposable {

    protected long nativeHandle;

    private Myo() {
    }

    protected Myo(long handle) {
        nativeHandle = handle;
    }

	private native void vibrate(int vibration);

    public void vibrate(VibrationType vibration) {
        vibrate(vibration.ordinal());
    }

	public native void requestRssi();

    public native void dispose();
}
