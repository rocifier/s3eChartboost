/*
 * iphone-specific implementation of the s3eChartboost extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eChartboost_internal.h"

s3eResult s3eChartboostInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void s3eChartboostTerminate_platform()
{
    // Add any platform-specific termination code here
}

void s3eChartboostSetAppID_platform(const char* id)
{
}

void s3eChartboostSetAppSignature_platform(const char* signature)
{
}

void s3eChartboostInstall_platform()
{
}

void s3eChartboostCacheInterstitial_platform(const char* name)
{
}

void s3eChartboostShowInterstitial_platform(const char* name)
{
}

void s3eChartboostCacheMoreApps_platform()
{
}

void s3eChartboostShowMoreApps_platform()
{
}
