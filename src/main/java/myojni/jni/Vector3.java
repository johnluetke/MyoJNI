package myojni.jni;

public class Vector3 {

    private final double x;
    private final double y;
    private final double z;

    public static final Vector3 X_AXIS = new Vector3(1, 0, 0);
    public static final Vector3 Y_AXIS = new Vector3(0, 1, 0);
    public static final Vector3 Z_AXIS = new Vector3(0, 0, 1);

    public Vector3() {
        this(0, 0, 0);
    }

    public Vector3(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public Vector3(float x, float y, float z) {
        this((double)x, (double)y, (double)z);
    }

    public Vector3(Vector3 other) {
        this(other.getX(), other.getY(), other.getZ());
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double getZ() {
        return z;
    }

    public double magnitude() {
        return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2) + Math.pow(z, 2));
    }

    public Vector3 normalized() {
        double magnitude = this.magnitude();
        return new Vector3(x / magnitude, y / magnitude, z / magnitude);
    }

    public double dot(Vector3 rhs) {
        return x * rhs.getX() + y * rhs.getY() + z * rhs.getZ();
    }

    public Vector3 cross(Vector3 rhs) {
        return new Vector3(x * rhs.getZ() - z * rhs.getY(),
                           z * rhs.getX() - x * rhs.getZ(),
                           x * rhs.getY() - y * rhs.getX());

    }

    public double angleTo(Vector3 rhs) {
        return Math.acos(dot(rhs) / (magnitude() * rhs.magnitude()));
    }

    @Override
    public boolean equals(Object other) {
        return other instanceof Vector3 &&
                getX() == ((Vector3)other).getX() &&
                getY() == ((Vector3)other).getY() &&
                getZ() == ((Vector3)other).getZ();
    }

    @Override
    public String toString() {
        return "Vector3 [" + this.getX() + ", " + this.getY() + ", " + this.getZ() + "]";
    }

}
