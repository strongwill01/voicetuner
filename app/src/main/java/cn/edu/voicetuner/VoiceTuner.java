package cn.edu.voicetuner;

public class VoiceTuner {

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
//    public native String stringFromJNI();

    /**
     *
     * @return voice tuner version.
     */
    public native String getVersion();

    public native static void close();

    public native static int encode(short[] buffer_l, short[] buffer_r, int samples, byte[] mp3buf);

    public native static int flush(byte[] mp3buf);

    public native static void init(int inSampleRate, int outChannel, int outSampleRate, int outBitrate, int quality);

    public static void init(int inSampleRate, int outChannel, int outSampleRate, int outBitrate) {
        init(inSampleRate, outChannel, outSampleRate, outBitrate, 7);
    }
}
