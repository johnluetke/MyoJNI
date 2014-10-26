MyoJNI
======
Java Native Interface (JNI) bindings for the Myo SDK

Setup
-----
1. Download the [Myo SDK](https://developer.thalmic.com/downloads) for either Windows, **Mac OS X**, or Linux. _(only bolded platforms have been implemented in this binding)_
2. Create an enviroment variable `MYOSDK` that points to the local copy of the SDK
 * For **Mac OS X**, this should point to the `myo.framework` directory inside the SDK

Build the Source
----------------
1. Run `mvn package` to build the Java (.jar) and Native (.nar) artifacts.
