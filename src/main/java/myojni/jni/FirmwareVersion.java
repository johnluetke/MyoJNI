package myojni.jni;

public class FirmwareVersion {

    protected int firmareVersionMajor;
    protected int firmareVersionMinor;
    protected int firmareVersionPatch;
    protected int firmareVersionHardwareRev;

    public FirmwareVersion(int firmareVersionMajor, int firmareVersionMinor, int firmareVersionPatch, int firmareVersionHardwareRev) {
        this.firmareVersionMajor = firmareVersionMajor;
        this.firmareVersionMinor = firmareVersionMinor;
        this.firmareVersionPatch = firmareVersionPatch;
        this.firmareVersionHardwareRev = firmareVersionHardwareRev;
    }

    public int getFirmareVersionMajor() {
        return firmareVersionMajor;
    }

    public int getFirmareVersionMinor() {
        return firmareVersionMinor;
    }

    public int getFirmareVersionPatch() {
        return firmareVersionPatch;
    }

    public int getFirmareVersionHardwareRev() {
        return firmareVersionHardwareRev;
    }

    public String toString() {
        return "[FirmwareVersion: " + getFirmareVersionMajor() + "." +
                                      getFirmareVersionMinor() + "." +
                                      getFirmareVersionPatch() + "." +
                                      getFirmareVersionHardwareRev() + "]";
    }
}
