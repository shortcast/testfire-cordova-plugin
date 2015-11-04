#import <Cordova/CDVPlugin.h>

@interface TestfirePlugin : CDVPlugin

- (void)initialize:(CDVInvokedUrlCommand*)command;
- (void)configure:(CDVInvokedUrlCommand*)command ;
- (void)show:(CDVInvokedUrlCommand*)command;

@end
