/*
 * android-specific implementation of the s3eChartboost extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eChartboost_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_s3eChartboostSetAppID;
static jmethodID g_s3eChartboostSetAppSignature;
static jmethodID g_s3eChartboostInstall;
static jmethodID g_s3eChartboostCacheInterstitial;
static jmethodID g_s3eChartboostShowInterstitial;
static jmethodID g_s3eChartboostCacheMoreApps;
static jmethodID g_s3eChartboostShowMoreApps;

s3eResult s3eChartboostInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("s3eChartboost");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_s3eChartboostSetAppID = env->GetMethodID(cls, "s3eChartboostSetAppID", "(Ljava/lang/String;)V");
    if (!g_s3eChartboostSetAppID)
        goto fail;

    g_s3eChartboostSetAppSignature = env->GetMethodID(cls, "s3eChartboostSetAppSignature", "(Ljava/lang/String;)V");
    if (!g_s3eChartboostSetAppSignature)
        goto fail;

    g_s3eChartboostInstall = env->GetMethodID(cls, "s3eChartboostInstall", "()V");
    if (!g_s3eChartboostInstall)
        goto fail;

    g_s3eChartboostCacheInterstitial = env->GetMethodID(cls, "s3eChartboostCacheInterstitial", "(Ljava/lang/String;)V");
    if (!g_s3eChartboostCacheInterstitial)
        goto fail;

    g_s3eChartboostShowInterstitial = env->GetMethodID(cls, "s3eChartboostShowInterstitial", "(Ljava/lang/String;)V");
    if (!g_s3eChartboostShowInterstitial)
        goto fail;

    g_s3eChartboostCacheMoreApps = env->GetMethodID(cls, "s3eChartboostCacheMoreApps", "()V");
    if (!g_s3eChartboostCacheMoreApps)
        goto fail;

    g_s3eChartboostShowMoreApps = env->GetMethodID(cls, "s3eChartboostShowMoreApps", "()V");
    if (!g_s3eChartboostShowMoreApps)
        goto fail;



    IwTrace(CHARTBOOST, ("CHARTBOOST init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(s3eChartboost, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void s3eChartboostTerminate_platform()
{
    // Add any platform-specific termination code here
}

void s3eChartboostSetAppID_platform(const char* id)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring id_jstr = env->NewStringUTF(id);
    env->CallVoidMethod(g_Obj, g_s3eChartboostSetAppID, id_jstr);
}

void s3eChartboostSetAppSignature_platform(const char* signature)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring signature_jstr = env->NewStringUTF(signature);
    env->CallVoidMethod(g_Obj, g_s3eChartboostSetAppSignature, signature_jstr);
}

void s3eChartboostInstall_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eChartboostInstall);
}

void s3eChartboostCacheInterstitial_platform(const char* name)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring name_jstr = env->NewStringUTF(name);
    env->CallVoidMethod(g_Obj, g_s3eChartboostCacheInterstitial, name_jstr);
}

void s3eChartboostShowInterstitial_platform(const char* name)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring name_jstr = env->NewStringUTF(name);
    env->CallVoidMethod(g_Obj, g_s3eChartboostShowInterstitial, name_jstr);
}

void s3eChartboostCacheMoreApps_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eChartboostCacheMoreApps);
}

void s3eChartboostShowMoreApps_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eChartboostShowMoreApps);
}
