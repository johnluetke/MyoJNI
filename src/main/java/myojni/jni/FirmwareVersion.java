package myojni.jni;

public class FirmwareVersion {

    protected long firmareVersionMajor;
    protected long firmareVersionMinor;
    protected long firmareVersionPatch;
    protected long firmareVersionHardwareRev;

    public long getFirmareVersionMajor() {
        return firmareVersionMajor;
    }

    public long getFirmareVersionMinor() {
        return firmareVersionMinor;
    }

    public long getFirmareVersionPatch() {
        return firmareVersionPatch;
    }

    public long getFirmareVersionHardwareRev() {
        return firmareVersionHardwareRev;
    }
}
