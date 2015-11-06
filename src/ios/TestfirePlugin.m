#import "TestfirePlugin.h"
#import "Testfire.h"
#import "TestfireParams.h"


@implementation TestfirePlugin

- (id)init {
  self = [super init];
  if (self) {
  }
  return self;
}

- (void)initialize:(CDVInvokedUrlCommand*)command {
  TestfireParams *params = [self buildParams:command];
  if(params) {
    [Testfire initialize: params];
  } else {
    [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR] callbackId:command.callbackId];
  }
}

- (void)configure:(CDVInvokedUrlCommand*)command {
  TestfireParams *params = [self buildParams:command];
  if(params) {
    [Testfire configure: params];
  } else {
    [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR] callbackId:command.callbackId];
  }
}

- (void)show:(CDVInvokedUrlCommand*)command {
  [Testfire show];
  [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_OK] callbackId:command.callbackId];
}

- (TestfireParams*) buildParams:(CDVInvokedUrlCommand*)command {
  if ( [command.arguments count] >= 1 ) {
    if ( [[command.arguments objectAtIndex:0] isKindOfClass:[NSDictionary class]] ) {
      NSDictionary *options = [command.arguments objectAtIndex:0];
      TestfireParams *params = [TestfireParams new];
      if([options objectForKey: @"url"]) {
        params.url = [options objectForKey: @"url"];
      }
      params.appId = [options objectForKey: @"appId"];
      params.apiKey = [options objectForKey: @"apiKey"];

      if([options objectForKey: @"frameworkBundlePath"]) {
        params.frameworkBundlePath = [options objectForKey: @"frameworkBundlePath"];
      }

      NSDictionary *GESTURE = @{
        @"shake" : @(TestfireGestureShake),
        @"swipe" : @(TestfireGestureSwipe),
        @"disabled" : @(TestfireGestureDisabled),
      };
      [self setParamValue: @"gesture" enums:GESTURE options:options params:params];


      NSDictionary *AUTH = @{
        @"none" : @(TestfireAuthNone),
        @"email" : @(TestfireAuthEmail)
      };
      [self setParamValue: @"auth" enums:AUTH options:options params:params];

      NSDictionary *MODE = @{
        @"feedback" : @(TestfireModeFeedback)
      };
      [self setParamValue: @"mode" enums:MODE options:options params:params];

      NSDictionary *VIDEO_QUALITY = @{
        @"highest" : @(TestfireVideoQualityHighest),
        @"high" : @(TestfireVideoQualityHigh),
        @"medium" : @(TestfireVideoQualityMedium),
        @"low" : @(TestfireVideoQualityLow),
        @"lowest" : @(TestfireVideoQualityLowest)
      };
      [self setParamValue: @"videoQuality" enums:VIDEO_QUALITY options:options params:params];

      NSDictionary *PASSWORD_MODE = @{
        @"visible" : @(TestfirePasswordModeVisible),
        @"hidden" : @(TestfirePasswordModeHidden)
      };
      [self setParamValue: @"passwordMode" enums:PASSWORD_MODE options:options params:params];

      NSDictionary *LOCATION_TRACKING = @{
        @"enabled" : @(TestfireLocationTrackingEnabled),
        @"disabled" : @(TestfireLocationTrackingDisabled)
      };
      [self setParamValue: @"locationTracking" enums:LOCATION_TRACKING options:options params:params];

      NSDictionary *DEBUG_LOG_LEVEL = @{
        @"none" : @(TestfireLogLevelNone),
        @"verbose" : @(TestfireLogLevelVerbose),
        @"debug" : @(TestfireLogLevelDebug),
        @"info" : @(TestfireLogLevelInfo),
        @"warn" : @(TestfireLogLevelWarn),
        @"error" : @(TestfireLogLevelError),
        @"fatal" : @(TestfireLogLevelFatal),
      };
      [self setParamValue: @"debugLogLevel" enums:DEBUG_LOG_LEVEL options:options params:params];

      NSDictionary *LOG_INTEGRATION = @{
        @"manual" : @(TestfireLogIntegrationManual),
        @"nslog" : @(TestfireLogIntegrationNSLog)
      };
      [self setParamValue: @"logIntegration" enums:LOG_INTEGRATION options:options params:params];

      NSDictionary *SETTINGS_MODE = @{
        @"enabled" : @(TestfireSettingsModeEnabled),
        @"disabled" : @(TestfireSettingsModeDisabled)
      };
      [self setParamValue: @"settingsMode" enums:SETTINGS_MODE options:options params:params];

      NSDictionary *CRASH_REPORTING = @{
        @"enabled" : @(TestfireCrashReportingEnabled),
        @"disabled" : @(TestfireCrashReportingDisabled)
      };
      [self setParamValue: @"crashReporting" enums:CRASH_REPORTING options:options params:params];

      NSDictionary *RECORD_MODE = @{
        @"automatic" : @(TestfireRecordModeAutomatic),
        @"manual" : @(TestfireRecordModeManual)
      };
      [self setParamValue: @"recordMode" enums:RECORD_MODE options:options params:params];
      return params;
    }
  }
  return nil;
}

-(void)setParamValue:(NSString*)key enums:(NSDictionary*)enums options:(NSDictionary*)options params:(TestfireParams*)params {
  NSString *value = [options[key] lowercaseString];
  if(value && enums[value]) {
    [params setValue:enums[value] forKey:key];
  }
}
@end
