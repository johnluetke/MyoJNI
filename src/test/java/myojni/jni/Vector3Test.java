package myojni.jni;

import org.hamcrest.CoreMatchers;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class Vector3Test {

    Vector3 vector;

    @Before
    public void SetUp() {
        Hub hub = new Hub("myojni.junit.tests");
    }

    @Test
    public void testX() {
        Vector3 vector = new Vector3(0.1f, 0f, 0f);
        Assert.assertThat(vector.getX(), CoreMatchers.is(0.1f));
        //Assert.assertEquals(0.1f, vector.getX(), 0);
    }

    @After
    public void TearDown() {
        if (vector != null)
            vector.dispose();
    }
}
