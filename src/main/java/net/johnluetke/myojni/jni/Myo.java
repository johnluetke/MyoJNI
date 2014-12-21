package net.johnluetke.myojni.jni;

import net.johnluetke.myojni.Disposable;

public class Myo {

    protected long nativeHandle;

    private Myo() {
    }

    protected Myo(long handle) {
        nativeHandle = handle;
    }

    private native void setStreamEmg(int streamEmgType);

	private native void vibrate(int vibration);

    private native void unlock(int unlockType);

    public native void lock();

    public native void notifyUserAction();

    public native void requestRssi();

    public void setStreamEmg(StreamEmgType type) { setStreamEmg(type.ordinal()); }

    public void unlock(UnlockType type) { unlock(type.ordinal()); }

    public void vibrate(VibrationType vibration) { vibrate(vibration.ordinal()); }

}
