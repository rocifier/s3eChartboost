/*
 * Internal header for the s3eChartboost extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef S3ECHARTBOOST_INTERNAL_H
#define S3ECHARTBOOST_INTERNAL_H

#include "s3eTypes.h"
#include "s3eChartboost.h"
#include "s3eChartboost_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult s3eChartboostInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult s3eChartboostInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void s3eChartboostTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void s3eChartboostTerminate_platform();
void s3eChartboostSetAppID_platform(const char* id);

void s3eChartboostSetAppSignature_platform(const char* signature);

void s3eChartboostInstall_platform();

void s3eChartboostCacheInterstitial_platform(const char* name);

void s3eChartboostShowInterstitial_platform(const char* name);

void s3eChartboostCacheMoreApps_platform();

void s3eChartboostShowMoreApps_platform();


#endif /* !S3ECHARTBOOST_INTERNAL_H */