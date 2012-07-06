/*
Generic implementation of the s3eChartboost extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eChartboost_internal.h"
s3eResult s3eChartboostInit()
{
    //Add any generic initialisation code here
    return s3eChartboostInit_platform();
}

void s3eChartboostTerminate()
{
    //Add any generic termination code here
    s3eChartboostTerminate_platform();
}

void s3eChartboostSetAppID(const char* id)
{
	s3eChartboostSetAppID_platform(id);
}

void s3eChartboostSetAppSignature(const char* signature)
{
	s3eChartboostSetAppSignature_platform(signature);
}

void s3eChartboostInstall()
{
	s3eChartboostInstall_platform();
}

void s3eChartboostCacheInterstitial(const char* name)
{
	s3eChartboostCacheInterstitial_platform(name);
}

void s3eChartboostShowInterstitial(const char* name)
{
	s3eChartboostShowInterstitial_platform(name);
}

void s3eChartboostCacheMoreApps()
{
	s3eChartboostCacheMoreApps_platform();
}

void s3eChartboostShowMoreApps()
{
	s3eChartboostShowMoreApps_platform();
}
