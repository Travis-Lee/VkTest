#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <vulkan_wrapper.h>
#include <jni.h>
#include <android/log.h>
#include <android/asset_manager.h>

#define APP_NAME "VKDemo"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, APP_NAME, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, APP_NAME, __VA_ARGS__))

class VKDe {
public:

    void run(ANativeWindow *window) {
        initWindow(window);
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    ANativeWindow *window;
    void initWindow(ANativeWindow *window) {
       this->window = window;
    }

    void initVulkan() {
        char info[20]="init vulkan";
        __android_log_print(ANDROID_LOG_INFO,APP_NAME,"INFO:%s",info);
    }

    void mainLoop() {
        int name=0;
        __android_log_print(ANDROID_LOG_INFO,APP_NAME,"INFO:%d",name);

    }

    void cleanup() {
    
        ANativeWindow_release(window);

    }
};
extern "C" {
JNIEXPORT jlong JNICALL
Java_com_leon_graph_test_VkDemo_create(JNIEnv *env,jclass type) {
    VKDe *app = new VKDe();
    return (jlong) app;
}

JNIEXPORT void JNICALL
Java_com_leon_graph_test_VkDemo_setSurface(JNIEnv *env, jclass type,jlong nativeHandle,jobject surface) {
    ANativeWindow *window = ANativeWindow_fromSurface(env, surface);
    if (window == nullptr) {
        LOGE("get window from surface fail!");
    return;
    }
    VKDe *app = reinterpret_cast<VKDe *>(nativeHandle);
    app->run(window);
}
}