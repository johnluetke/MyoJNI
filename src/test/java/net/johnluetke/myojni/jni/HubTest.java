package net.johnluetke.myojni.jni;

import org.hamcrest.CoreMatchers;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;

public class HubTest {

    static Hub hub;

    @BeforeClass
    public static void SetUp() {
        hub = new Hub("myojni.junit.tests");
    }

    @Test
    public void test() {
    }
}
