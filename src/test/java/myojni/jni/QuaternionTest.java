package myojni.jni;

import org.hamcrest.CoreMatchers;
import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;

public class QuaternionTest {

    static Hub hub;
    Quaternion quat;

    @BeforeClass
    public static void SetUp() {
        hub = new Hub("myojni.junit.tests");
    }

    @Test
    public void testX() {
        quat = new Quaternion(0.1f, 0f, 0f, 0f);
        Assert.assertEquals(0.1, quat.getX(), 0.001);

        quat = new Quaternion(0.1, 0, 0, 0);
        Assert.assertThat(quat.getX(), CoreMatchers.is(0.1));
    }

    @Test
    public void testY() {
        quat = new Quaternion(0f, 0.1f, 0f, 0f);
        Assert.assertEquals(0.1, quat.getY(), 0.001);

        quat = new Quaternion(0, 0.1, 0, 0);
        Assert.assertThat(quat.getY(), CoreMatchers.is(0.1));
    }

    @Test
    public void testZ() {
        quat = new Quaternion(0f, 0f, 0.1f, 0f);
        Assert.assertEquals(0.1, quat.getZ(), 0.001);

        quat = new Quaternion(0, 0, 0.1, 0);
        Assert.assertThat(quat.getZ(), CoreMatchers.is(0.1));
    }

    @Test
    public void testW() {
        quat = new Quaternion(0f, 0f, 0f, 0.1f);
        Assert.assertEquals(0.1, quat.getW(), 0.001);

        quat = new Quaternion(0, 0, 0, 0.1);
        Assert.assertThat(quat.getW(), CoreMatchers.is(0.1));
    }

    @Test
    public void testConjugate() {
        quat = new Quaternion(0.5, -0.5, 0.5, -0.25);
        Quaternion expected = new Quaternion(-0.5, 0.5, -0.5, 0.25);
        Assert.assertThat(quat.conjugate(), CoreMatchers.is(expected));
    }

    @Test
    public void testFromAxisAngle() {
        Vector3 axis = Vector3.X_AXIS;
        double angle = Math.PI / 2;
        Quaternion expected = new Quaternion(Math.sin(angle / 2),
                                             0,
                                             0,
                                             Math.cos(angle / 2));
        Assert.assertThat(Quaternion.fromAxisAngle(axis, angle), CoreMatchers.is(expected));
    }

    @Test
    public void testMultiply() {
        quat = new Quaternion(1, 1, 1, 1);
        Quaternion other = new Quaternion(-1, -1, -1, -1);
        Assert.assertThat(quat.multiply(other), CoreMatchers.is(new Quaternion(-2, -2, -2, 2)));
    }

    @Test
    public void testNormalized() {
        quat = new Quaternion(1, 1, 1, 1);
        Assert.assertThat(quat.normalized(), CoreMatchers.is(new Quaternion(.5, .5, .5, .5)));
    }

    @Test
    public void testRotate() {
        quat = new Quaternion(1, 1, 1, 1);
        Assert.assertThat(quat.rotate(Vector3.X_AXIS), CoreMatchers.is(new Vector3(-2, 2, 2)));
    }

    @AfterClass
    public static void TearDown() {
        //hub.dispose();
    }

}
