# Testfire Cordova Plugin

Testfire SDK for PhoneGap/Cordova is currently available only for  iOS and Android.

### Installation

To add the plugin to your project, simply run the following command from Terminal:

```
cordova plugin add https://github.com/shortcast/testfire-cordova-plugin
```

### Usage

Initialize Testfire with your appId and apiKey from *onDeviceReady*. For example.

```
onDeviceReady: function() {
  app.receivedEvent('deviceready');
  Testfire.initialize({
    appId: "YOURAPPID",
    apiKey: "YOURAPIKEY",
    // gesture: 'shake'
  });
},
```

### Methods
 * `Testfire.initialize(options)` - Initialize Testfire SDK
 * `Testfire.configure(options)` - Reconfigure already initialized Testfire
 * `Testfire.show()` - Manually show the Testfire ui

### Other Options

 * `gesture` - shake, swipe, disabled for ios, and shake, notification, disabled for android
 * `videoQuality` - highest, high, medium, low, lowest
 * `passwordMode` - visible, hidden
 * `locationTracking` - enabled, disabled
 * `debugLogLevel` - none, verbose, info, warn, error, fatal
 * `logIntegration` - manual, nslog for ios, and manual, logcat for android
 * `settingsMode` - enabled, disabled
 * `crashReporting` - enabled, disabled
 * `recordMode` - manual, automatic
