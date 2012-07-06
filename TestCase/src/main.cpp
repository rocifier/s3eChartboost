/*
 * This file is part of the Marmalade SDK Code Samples.
 *
 * Copyright (C) 2001-2012 Ideaworks3D Ltd.
 * All Rights Reserved.
 *
 * This source code is intended only as a supplement to Ideaworks Labs
 * Development Tools and/or on-line documentation.
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */
#include "s3e.h"
#include "IwDebug.h"
#include "s3eChartboost.h"

// "main" is the S3E entry point
int main()
{
	

	if (s3eChartboostAvailable()) {

		s3eChartboostSetAppID("app id");

		s3eChartboostSetAppSignature("app signature");

		s3eChartboostInstall();

		s3eChartboostShowInterstitial("pre-game");
	}



	// to exit correctly, applications should poll for quit requests
	while(!s3eDeviceCheckQuitRequest())
	{
		// S3E applications should yield frequently
		s3eDeviceYield();
	}


	return 0;
}
