package myojni.jni;

import myojni.Disposable;

import java.lang.reflect.ParameterizedType;

public class Vector3 implements Disposable {

    protected long nativeHandle;

    public Vector3() {
        initialize();
    }

    public Vector3(float x, float y, float z) {
        initializeXYZ(x, y, z);
    }

    public Vector3(Vector3 other) {
        this(other.X(), other.Y(), other.Z());
    }

    protected Vector3(long handle) {
        nativeHandle = handle;
    }

    private native void initialize();

    private native void initializeXYZ(float x, float y, float z);

    public native float X();

    public native float Y();

    public native float Z();

    public native float magnitude();

    public native Vector3 normalized();

    public native float dot(Vector3 rhs);

    public native Vector3 cross(Vector3 rhs);

    public native float angleTo(Vector3 rhs);

    @Override
    public native void dispose();

    @Override
    public String toString() {
        return "[" + this.X() + ", " + this.Y() + ", " + this.Z() + "]";
    }

}
