package cn.edu.voicetuner;

public class VoiceTuner {

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    /**
     *
     * @return voice tuner version.
     */
    public native String getVersion();
}
