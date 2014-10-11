#include "myojni.h"

namespace MyoJNI {

    std::map<jint, MyoJNI::DeviceListener *> deviceListenerHashMap;
    std::map<myo::Myo *, jobject> myoHashMap;

    void dispose() {
    }
}