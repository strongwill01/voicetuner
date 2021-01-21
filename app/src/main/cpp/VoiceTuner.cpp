#include <cwchar>
#include "VoiceTuner.h"
#include "lamemp31/lame.h"
#include <jni.h>
#include <string>

//extern "C" JNIEXPORT jstring; JNICALL
static lame_global_flags *glf = NULL;

extern "C"
JNIEXPORT void JNICALL
Java_cn_edu_voicetuner_VoiceTuner_close(JNIEnv *env, jclass type) {
    lame_close(glf);
    glf = NULL;
}

extern "C"
JNIEXPORT jint JNICALL
Java_cn_edu_voicetuner_VoiceTuner_encode(JNIEnv *env, jclass type, jshortArray buffer_l_,
                                         jshortArray buffer_r_, jint samples, jbyteArray mp3buf_) {
    jshort *buffer_l = env->GetShortArrayElements(buffer_l_, NULL);
    jshort *buffer_r = env->GetShortArrayElements(buffer_r_, NULL);
    jbyte *mp3buf = env->GetByteArrayElements(mp3buf_, NULL);

    const jsize mp3buf_size = env->GetArrayLength(mp3buf_);

    int result =lame_encode_buffer(glf, buffer_l, buffer_r, samples, (u_char*)mp3buf, mp3buf_size);

    env->ReleaseShortArrayElements(buffer_l_, buffer_l, 0);
    env->ReleaseShortArrayElements(buffer_r_, buffer_r, 0);
    env->ReleaseByteArrayElements(mp3buf_, mp3buf, 0);

    return result;
}

extern "C"
JNIEXPORT jint JNICALL
Java_cn_edu_voicetuner_VoiceTuner_flush(JNIEnv *env, jclass type, jbyteArray mp3buf_) {
    jbyte *mp3buf = env->GetByteArrayElements(mp3buf_, NULL);

    const jsize  mp3buf_size = env->GetArrayLength(mp3buf_);

    int result = lame_encode_flush(glf, (u_char*)mp3buf, mp3buf_size);

    env->ReleaseByteArrayElements(mp3buf_, mp3buf, 0);

    return result;
}

extern "C"
JNIEXPORT void JNICALL
Java_cn_edu_voicetuner_VoiceTuner_init(JNIEnv *env, jclass clazz, jint in_sample_rate,
                                       jint out_channel, jint out_sample_rate, jint out_bitrate,
                                       jint quality) {
    if(glf != NULL){
        lame_close(glf);
        glf = NULL;
    }
    glf = lame_init();
    lame_set_in_samplerate(glf, in_sample_rate);
    lame_set_num_channels(glf, out_channel);
    lame_set_out_samplerate(glf, out_sample_rate);
    lame_set_brate(glf, out_bitrate);
    lame_set_quality(glf, quality);
    lame_init_params(glf);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_cn_edu_voicetuner_VoiceTuner_getVersion(JNIEnv *env, jobject thiz) {
    std::string version = "0.0.1";
    return env->NewStringUTF(version.c_str());
}