#include <jni.h>

extern "C"
{
    void Java_cn_edu_voicetuner_VoiceTuner_close(JNIEnv *env, jclass type);

    jint Java_cn_edu_voicetuner_VoiceTuner_encode(JNIEnv *env, jclass type, jshortArray buffer_l_,
                                                  jshortArray buffer_r_, jint samples,
                                                  jbyteArray mp3buf_);

    jint Java_cn_edu_voicetuner_VoiceTuner_flush(JNIEnv *env, jclass type, jbyteArray mp3buf_);

    void Java_cn_edu_voicetuner_VoiceTuner_init(JNIEnv *env, jclass clazz, jint in_sample_rate,
                                                jint out_channel, jint out_sample_rate,
                                                jint out_bitrate,
                                                jint quality);

    jstring Java_cn_edu_voicetuner_VoiceTuner_getVersion(JNIEnv *env, jobject thiz);
}