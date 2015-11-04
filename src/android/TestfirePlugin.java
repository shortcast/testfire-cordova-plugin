package io.testfire.cordova;

import android.os.Bundle;
import android.provider.Settings;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import org.json.*;
import org.apache.cordova.*;
import io.testfire.*;
import org.apache.cordova.PluginResult.Status;
import java.util.*;
import android.os.Handler;
import android.os.Looper;
import android.app.*;

import io.testfire.*;

public class TestfirePlugin extends CordovaPlugin {
  /** Cordova Actions. */
  private static final String LOGTAG = "TestfirePlugin";
  private static final String ACTION_INITIALIZE = "initialize";
  private static final String ACTION_CONFIGURE = "configure";
  private static final String ACTION_SHOW = "show";

  /** Cordova Options. */

  @Override
  public boolean execute(final String action, final JSONArray inputs, final CallbackContext callbackContext) throws JSONException {
    Handler mainHandler = new Handler(Looper.getMainLooper());
    mainHandler.post(new Runnable() {
      @Override
      public void run() {
        Log.d(LOGTAG, String.format("Execute action: %s", action));
        PluginResult result = null;
        if (ACTION_INITIALIZE.equals(action)) {
          JSONObject options = inputs.optJSONObject(0);
          result = executeInitialize(options);
        } else if (ACTION_CONFIGURE.equals(action)) {
          JSONObject options = inputs.optJSONObject(0);
          result = executeConfigure(options);
        } else if (ACTION_SHOW.equals(action)) {
          result = executeShow();
        } else {
          Log.d(LOGTAG, String.format("Invalid action passed: %s", action));
          result = new PluginResult(Status.INVALID_ACTION);
        }
        if(result != null) callbackContext.sendPluginResult( result );
      }
    });
    return true;
  }

  private PluginResult executeInitialize( JSONObject options ) {
    Log.d(LOGTAG, String.format("Execute Initialize: %s", options));
    TestfireParams params = buildParams(options);
    if(params == null) return new PluginResult(Status.INVALID_ACTION);
    Testfire.initialize(params);
    return new PluginResult(Status.OK);
  }

  private PluginResult executeConfigure(JSONObject options) {
    Log.d(LOGTAG, String.format("Execute Configure: %s", options));
    TestfireParams params = buildParams(options);
    if(params == null) return new PluginResult(Status.INVALID_ACTION);
    Testfire.configure(params);
    return new PluginResult(Status.OK);
  }

  private PluginResult executeShow() {
    Log.d(LOGTAG, String.format("Execute Show"));
    Testfire.show();
    return new PluginResult(Status.OK);
  }

  private TestfireParams buildParams(JSONObject options) {
    if(options == null) return null;
    TestfireParams params = new TestfireParams();
    params.setApplication(this.cordova.getActivity().getApplication());
    params.setActivity(this.cordova.getActivity());
    params.setAppId(options.optString("appId"));
    params.setApiKey(options.optString("apiKey"));
    String url = options.optString("url");
    if(url != null && !url.trim().equals("")) {
      params.setUrl(url);
    }

    TestfireParamMode mode = getMappedEnum(TestfireParamMode.class, TestfireParamMode.values(), options.optString("mode"));
    if (mode != null) {
      params.setMode(mode);
    }

    TestfireParamGesture gesture = getMappedEnum(TestfireParamGesture.class, TestfireParamGesture.values(), options.optString("gesture"));
    if (gesture != null) {
      params.setGesture(gesture);
    }

    TestfireParamVideoQuality videoQuality = getMappedEnum(TestfireParamVideoQuality.class, TestfireParamVideoQuality.values(), options.optString("videoQuality"));
    if (videoQuality != null) {
      params.setVideoQuality(videoQuality);
    }

    TestfireParamPasswordMode passwordMode = getMappedEnum(TestfireParamPasswordMode.class, TestfireParamPasswordMode.values(), options.optString("passwordMode"));
    if (passwordMode != null) {
      params.setPasswordMode(passwordMode);
    }

    TestfireParamLocationTracking locationTracking = getMappedEnum(TestfireParamLocationTracking.class, TestfireParamLocationTracking.values(), options.optString("locationTracking"));
    if (locationTracking != null) {
      params.setLocationTracking(locationTracking);
    }

    TestfireParamLogLevel debugLogLevel = getMappedEnum(TestfireParamLogLevel.class, TestfireParamLogLevel.values(), options.optString("debugLogLevel"));
    if (debugLogLevel != null) {
      params.setDebugLogLevel(debugLogLevel);
    }

    TestfireParamLogIntegration logIntegration = getMappedEnum(TestfireParamLogIntegration.class, TestfireParamLogIntegration.values(), options.optString("logIntegration"));
    if (logIntegration != null) {
      params.setLogIntegration(logIntegration);
    }

    TestfireParamSettings settingsMode = getMappedEnum(TestfireParamSettings.class, TestfireParamSettings.values(), options.optString("settingsMode"));
    if (settingsMode != null) {
      params.setSettings(settingsMode);
    }

    TestfireParamCrashReporting crashReporting = getMappedEnum(TestfireParamCrashReporting.class, TestfireParamCrashReporting.values(), options.optString("crashReporting"));
    if (crashReporting != null) {
      params.setCrashReporting(crashReporting);
    }

    TestfireParamRecordMode recordMode = getMappedEnum(TestfireParamRecordMode.class, TestfireParamRecordMode.values(), options.optString("recordMode"));
    if (crashReporting != null) {
      params.setRecorderMode(recordMode);
    }

    return params;
  }

  private <T> T  getMappedEnum(Class<T> clazz, Enum[] values, String name) {
    if(name == null) {
      return null;
    }
    for(Enum e : values) {
      if(e.name().toLowerCase().equals(name.toLowerCase())) {
        return (T)e;
      }
    }
    return null;
  }
}
