#import <Foundation/Foundation.h>

/** The different gestures for initializing the SDK
 */
typedef NS_ENUM(NSInteger, TestfireGesture) {
    /** Two finger swipe in any direction (default) */
    TestfireGestureShake = 0, //default
    /** Shaking the device */
    TestfireGestureSwipe = 1,
    /** Disable gestures, manually call show yourself */
    TestfireGestureDisabled = -1
};

/** The different modes for the SDK, users can override the default mode via using an unlock code in their settings screen
 */
typedef NS_ENUM(NSInteger, TestfireMode) {
    /** Feedback mode, screenshots and videos only (default) */
    TestfireModeFeedback = 0, //default
};

/** What must the user do before they are allowed to use the SDK
 */
typedef NS_ENUM(NSInteger, TestfireAuth) {
    /** None, Default to no authentication required */
    TestfireAuthNone = 0, //default
    /** Email, The user must supply a valid email */
    TestfireAuthEmail = 1,
};

/** The different modes for api access
 */
typedef NS_ENUM(NSInteger, TestfireApiMode) {
    /** Public, default only use public apple apis */
    TestfireApiModePublic = 0, //default
    /** Private, allow using private apple apis when available, this will result in your app not being app store compatible */
    TestfireApiModePrivate = -1,
};

typedef NS_ENUM(NSInteger, TestfireSettingsMode) {
    /**Enable all setting changes (default) */
    TestfireSettingsModeEnabled = 0, //default
    /** Disable all setting changes */
    TestfireSettingsModeDisabled = -1,
};

/** The different resolution qualities. Higher quality consumes more memory on user devices as well as increase upload times.
 */
typedef NS_ENUM(NSInteger, TestfireVideoQuality) {
    /** Highest, consumes most memory and increases upload times, but provides best playback quality */
    TestfireVideoQualityHighest = 0, //default
    /** High, consumes more memory and increases upload times, but provides better playback quality */
    TestfireVideoQualityHigh = 1,
    /** Medium, a compromise between the benefits of low quality and the resolution of high quality */
    TestfireVideoQualityMedium = 2,
    /** Low, default quality setting, allowing low memory consumption and fast upload times */
    TestfireVideoQualityLow = 3,
    /** Lowest, default quality setting, allowing low memory consumption and fast upload times */
    TestfireVideoQualityLowest = 4
};

/** The flag to enable/disable password hiding
 */
typedef NS_ENUM(NSInteger, TestfirePasswordMode) {
    /** Hidden, video covers screen when the user is entering a password (default) */
    TestfirePasswordModeHidden = 0, //default
    /** Visible, video is never covered and user passwords can be seen in the video */
    TestfirePasswordModeVisible = -1
};

/** The flag to enable location tracking (will only work with apps that already use CoreLocation)
 */
typedef NS_ENUM(NSInteger, TestfireLocationTracking) {
    TestfireLocationTrackingEnabled = 0, // default
    TestfireLocationTrackingDisabled = 1
};

/** The different log levels for internal Testfire logging
 */
typedef NS_ENUM(NSInteger, TestfireLogLevel) {
    TestfireLogLevelNone = 0, //default
    TestfireLogLevelVerbose = 1,
    TestfireLogLevelDebug = 2,
    TestfireLogLevelInfo = 3,
    TestfireLogLevelWarn = 4,
    TestfireLogLevelError = 5,
    TestfireLogLevelFatal = 6
};

typedef NS_ENUM(NSInteger, TestfireLogIntegration) {
    TestfireLogIntegrationManual = 0, //default
    TestfireLogIntegrationNSLog = 1
};

typedef NS_ENUM(NSInteger, TestfireCrashReporting) {
    /** Enable Crash Reporting */
    TestfireCrashReportingEnabled = 0,

    /** Disable Crash Reporting */
    TestfireCrashReportingDisabled = 1
};

typedef NS_ENUM(NSInteger, TestfireRecordMode) {
    /** Manual Record Mode */
    TestfireRecordModeManual = 0,
    
    /** Automatic Record Mod */
    TestfireRecordModeAutomatic = 1
};

@interface TestfireParams : NSObject

/** App ID for your project (required) */
@property (nonatomic, strong) NSString *appId;

/** API Key for your project (required) */
@property (nonatomic, strong) NSString *apiKey;

/** API Key for your user (optional) 
 Only used if you are authenticating as a user with a project_id and user_key
 */
@property (nonatomic, strong) NSString *userKey;

/** URL for Testfire SDK endpoints (internal use only) */
@property (nonatomic, strong) NSString *url;

/** Alternate path for framework resources (optional) */
@property (nonatomic, strong) NSString *frameworkBundlePath;

/** Mode for Testfire, alters how users interact with the SDK (optional) */
@property (nonatomic) enum TestfireMode mode;

/** Gesture for Testfire, alters command for initiating the SDK (optional) */
@property (nonatomic) enum TestfireGesture gesture;

/** Option for the Testfire authentication (optional) */
@property (nonatomic) enum TestfireAuth auth;

/** Resolution/FPS quality for video capture */
@property (nonatomic) enum TestfireVideoQuality videoQuality;

/** Mode whether or not password fields are protected in the video (optional) */
@property (nonatomic) enum TestfirePasswordMode passwordMode;

/** Location tracking for internal Testfire SDK (optional) */
@property (nonatomic) enum TestfireLocationTracking locationTracking;

/** Log level for internal Testfire SDK (optional) */
@property (nonatomic) enum TestfireLogLevel debugLogLevel;

/** Automatically send NSLog to Testfire (optional) */
@property (nonatomic) enum TestfireLogIntegration logIntegration;

/** Settings mode for Testfire SDK (optional) */
@property (nonatomic) enum TestfireSettingsMode settingsMode;

/** Crash Reporting for Testfire SDK (optional) */
@property (nonatomic) enum TestfireCrashReporting crashReporting;

/** Record Mode for Testfire SDK (optional) */
@property (nonatomic) enum TestfireRecordMode recordMode;

@end

#define TestfireParamsWeak (NSClassFromString(@"TestfireParams"))

