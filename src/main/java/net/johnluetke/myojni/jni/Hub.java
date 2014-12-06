package net.johnluetke.myojni.jni;

import net.johnluetke.myojni.Disposable;

public class Hub implements Disposable {

    static {
        NarSystem.loadLibrary();
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

    public native void addListener(DeviceListener listener);

    public native void removeListener(DeviceListener listener);

    public void setLockingPolicy(LockingPolicy policy) {
        pSetLockingPolicy(policy.ordinal());
    }

    private native void pSetLockingPolicy(int policy);

    public native void run(long duration_ms);

    public native void runOnce(long duration_ms);

    @Override
    public native void dispose();
}
