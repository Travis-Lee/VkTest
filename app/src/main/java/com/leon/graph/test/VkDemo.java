package com.leon.graph.test;

import android.view.Surface;

public class VkDemo {

    static {
        System.loadLibrary("vktuts");
    }

    private long mNativeHandle;

    public VkDemo() {
        mNativeHandle = create();
    }
    private static native long create();
    private static native void setSurface(long nativeHandle,Surface surface);

    public void run(final Surface surface) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                VkDemo.setSurface(mNativeHandle,surface);
            }
        }).start();
    }

}
