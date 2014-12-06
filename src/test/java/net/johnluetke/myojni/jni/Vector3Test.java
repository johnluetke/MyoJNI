package net.johnluetke.myojni.jni;

import org.hamcrest.CoreMatchers;
import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;

public class Vector3Test {

    Vector3 vector;

    @Test
    public void testX() {
        vector = new Vector3(0.1f, 0f, 0f);
        Assert.assertEquals(0.1, vector.getX(), 0.001);

        vector = new Vector3(0.1, 0, 0);
        Assert.assertThat(vector.getX(), CoreMatchers.is(0.1));
    }

    @Test
    public void testY() {
        vector = new Vector3(0f, 0.1f, 0f);
        Assert.assertEquals(0.1, vector.getY(), 0.001);

        vector = new Vector3(0, 0.1, 0);
        Assert.assertThat(vector.getY(), CoreMatchers.is(0.1));
    }

    @Test
    public void testZ() {
        vector = new Vector3(0f, 0f, 0.1f);
        Assert.assertEquals(0.1, vector.getZ(), 0.001);

        vector = new Vector3(0, 0, 0.1);
        Assert.assertThat(vector.getZ(), CoreMatchers.is(0.1));
    }

    @Test
    public void testMagnitude() {
        vector = new Vector3(0, -0.5, 2);
        Assert.assertEquals(2.061, vector.magnitude(), 0.001);
    }

    @Test
    public void testNormalized() {
        vector = new Vector3(0, -0.5, 2);
        Assert.assertEquals(0, vector.normalized().getX(), 0.001);
        Assert.assertEquals(-0.242, vector.normalized().getY(), 0.001);
        Assert.assertEquals(0.970, vector.normalized().getZ(), 0.001);
    }

    @Test
    public void testDot() {
        vector = new Vector3(0, -0.5, 2);
        Vector3 other = new Vector3(1, 0.5, 1);
        Assert.assertEquals(1.75, vector.dot(other), 0.001);
    }

    @Test
    public void testCross() {
        vector = new Vector3(0, -0.5, 2);
        Vector3 other = new Vector3(1, 0.5, 1);
        Assert.assertEquals(-1, vector.cross(other).getX(), 0.001);
        Assert.assertEquals(2, vector.cross(other).getY(), 0.001);
        Assert.assertEquals(0.5, vector.cross(other).getZ(), 0.001);
    }

    @Test
    public void testAngleTo() {
        vector = new Vector3(0, -0.5, 2);
        Vector3 other = new Vector3(1, 0.5, 1);
        Assert.assertEquals(0.969, vector.angleTo(other), 0.001);
    }

    @AfterClass
    public static void TearDown() {
        //hub.dispose();
    }
}
