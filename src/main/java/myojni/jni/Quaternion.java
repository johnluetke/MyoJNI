package myojni.jni;

public class Quaternion {

    private final double x;
    private final double y;
    private final double z;
    private final double w;

    public static Quaternion fromAxisAngle(Vector3 axis, double angle) {
        return new Quaternion(
                axis.getX() * Math.sin(angle / 2),
                axis.getY() * Math.sin(angle / 2),
                axis.getZ() * Math.sin(angle / 2),
                Math.cos(angle / 2)
        );
    }

    public static Quaternion fromRotation(Vector3 from, Vector3 to) {
        Vector3 cross = from.cross(to);
        double cosTheta = from.dot(to);
        double k = Math.sqrt(from.dot(from) * to.dot(to));

        if (cosTheta >= 1 || k <= 0)
            return new Quaternion();

        if (cosTheta / k <= -1) {
            cross = from.cross(Math.abs(from.dot(Vector3.X_AXIS)) < 1 ? Vector3.X_AXIS : Vector3.Y_AXIS);
            k = cosTheta = 0;
        }

        return new Quaternion(
            cross.getX(),
            cross.getY(),
            cross.getZ(),
            k + cosTheta
        );
    }

    public Quaternion() {
        this(0, 0, 0, 0);
    }

    public Quaternion(double x, double y, double z, double w) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
    }

    public Quaternion(Quaternion other) {
        this(other.getX(), other.getY(), other.getZ(), other.getW());
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

    public double getW() {
        return w;
    }

    public Quaternion conjugate() {
        return new Quaternion(-getX(), -getY(), -getZ(), -getW());
    }

    public Quaternion multiply(Quaternion other) {
        return new Quaternion(
            getW() * other.getX() + getX() * other.getW() + getY() * other.getZ() - getZ() * other.getY(),
            getW() * other.getY() - getX() * other.getZ() + getY() * other.getW() + getZ() * other.getX(),
            getW() * other.getZ() + getX() * other.getY() - getY() * other.getX() + getZ() * other.getW(),
            getW() * other.getW() - getX() * other.getX() - getY() * other.getY() - getZ() * other.getZ()
        );
    }

    public Quaternion normalized() {
        double magnitude = Math.sqrt(Math.pow(getX(), 2) + Math.pow(getY(), 2) + Math.pow(getZ(), 2) + Math.pow(getW(), 2));
        return new Quaternion(getX() / magnitude, getY() / magnitude, getZ() / magnitude, getW() / magnitude);
    }

    public Vector3 rotate(Vector3 angle) {
        Quaternion qvec = new Quaternion(angle.getX(), angle.getY(), angle.getZ(), 0);
        qvec = this.multiply(qvec).multiply(this.conjugate());
        return new Vector3(qvec.getX(), qvec.getY(), qvec.getZ());
    }

    @Override
    public boolean equals(Object other) {
        return other instanceof Quaternion &&
               getX() == ((Quaternion)other).getX() &&
               getY() == ((Quaternion)other).getY() &&
               getZ() == ((Quaternion)other).getZ() &&
               getW() == ((Quaternion)other).getW();
    }

    @Override
    public String toString() {
        return "Quaternion [" + getX() + ", " + getY() + ", " + getZ() + ", " + getW() + "]";
    }
}
