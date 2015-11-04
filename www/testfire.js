'use strict';

var argscheck = require('cordova/argscheck'),
utils = require('cordova/utils'),
exec = require('cordova/exec');

var Testfire = function() {
	this.serviceName = "Testfire";
}

Testfire.prototype.initialize = function(options) {
	if (options) {
		exec(function(){}, function(){}, this.serviceName, "initialize", [ options ]);
	} else {
		var errorString = "Options are required.";
		if (failureCallback) {
			failureCallback(errorString);
		} else {
			console.error(errorString);
		}
	}
};

Testfire.prototype.configure = function(options) {
	if (options) {
		exec(function(){}, function(){}, this.serviceName, "configure", [ options ]);
	} else {
		var errorString = "Options are required.";
		if (failureCallback) {
			failureCallback(errorString);
		} else {
			console.error(errorString);
		}
	}
};

Testfire.prototype.show = function(options) {
	options = options || {};
	exec(function(){}, function(){}, this.serviceName, "show", [ options ]);
};

module.exports = new Testfire();
