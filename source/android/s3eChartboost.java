/*
java implementation of the s3eChartboost extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.chartboost.sdk.*;
import android.util.Log;

class s3eChartboost
{
    ChartBoost _cb;

    public s3eChartboost() {
        LoaderActivity.m_Activity.runOnUiThread(new Runnable() {
			@Override
			public void run()
			{
                _cb = ChartBoost.getSharedChartBoost(LoaderActivity.m_Activity);
            }
        });
    }
    
    public void s3eChartboostSetAppID(String id)
    {
        _cb.setAppId(id);
    }
    public void s3eChartboostSetAppSignature(String signature)
    {
        _cb.setAppSignature(signature);
    }
    public void s3eChartboostInstall()
    {
        _cb.install();
    }
    public void s3eChartboostCacheInterstitial(String name)
    {
        _cb.cacheInterstitial(name);
    }
    public void s3eChartboostShowInterstitial(String name)
    {
        _cb.showInterstitial(name);
    }
    public void s3eChartboostCacheMoreApps()
    {
        _cb.cacheMoreApps();
    }
    public void s3eChartboostShowMoreApps()
    {

        _cb.showMoreApps();
    }
}
