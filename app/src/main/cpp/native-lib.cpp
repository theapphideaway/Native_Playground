#include <jni.h>
#include <string>
#include "./httplib.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_ianschoenrock_nativeplayground_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    httplib::Client cli("http://ianschoenrock-001-site1.htempurl.com");

    auto res = cli.Get("/weatherforecast");
    std::string str(res->body);
    return env->NewStringUTF(str.c_str());
}