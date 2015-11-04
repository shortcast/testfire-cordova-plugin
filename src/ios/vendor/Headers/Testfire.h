#import <Foundation/Foundation.h>
#import "TestfireParams.h"


/** The Testfire Library API
 
 [Download](http://testfire-downloads.s3.amazonaws.com/Testfire.zip) the latest version.
 
 Include the framework and initialize in your AppDelegate.m didFinishLaunchingWithOptions methods. The library will automatically be available when you do a 2 finger swipe or shake depending on if you have overidden the default gesture.
 
 Example Usage:
 <pre>
 <code>
 
 TestfireParams *params = [[TestfireParams alloc] init];
 params.appId = @"app id from dashboard.testfire.io";
 params.apiKey = @"api key from dashboard.testfire.io";
 [Testfire initialize: params];
 
 </code>
 </pre>
 
 */
@interface Testfire : NSObject

/** Parameters that Testfire is initialized with */
@property (readonly) TestfireParams *params;


/** Creates a singleton instance of the Testfire Library.
 
 @param params The options used when creating the library.
 @return Instance of the Testfire
 
 */
+ (id)initialize:(TestfireParams *)params;

/** Log to Testfire
 
 All logs will up uploaded into the Testfire Dashboard when issues are submitted. This is a way to better track user paths and errors your app may be experiencing.
 
 @param message string to be logged to Testfire
 */
+ (void)log:(NSString *)message;

/** Log to Testfire
 
 All logs will up uploaded into the Testfire Dashboard when issues are submitted. This is a way to better track user paths and errors your app may be experiencing.
 
 @param message string to be logged to Testfire
 @param level log level
 */
+ (void)log:(NSString *)message level: (enum TestfireLogLevel) level;

/** Log to Testfire
 
 All logs will up uploaded into the Testfire Dashboard when issues are submitted. This is a way to better track user paths and errors your app may be experiencing.
 
 @param message string to be logged to Testfire
 @param level log level
 @param context context
 */
+ (void)log:(NSString *)message level:(enum TestfireLogLevel)level context:(NSString *)context;

/** Update parameters for a Testfire instance.
 
 Normally not needed, but can be used to manually update the parameters for an already running Testfire instance.
 */
+ (void)configure:(TestfireParams *)params;

/** Show the Testfire Library manually.
 
 Normally not needed, but can be used to manually show the library when Testfire gestures are set to disabled.
 */

+ (void)show;

/** Returns the version of the Testfire Library.
 
 Normally not needed, but can be used for diagnostics & debugging.
 */
+ (NSString *)testfireVersion;

@end


/**
 This should be used if Testfire will not be used in production. This prevents strong linking to Testfire, preventing runtime errors.
 */
#define TestfireWeak (NSClassFromString(@"Testfire"))

