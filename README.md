Gameduino
=========

Customizable gamepad/joystick/keyboard with an Arduino Leonardo. An explanation of how it was written is available 
[here](https://enoent.fr/blog/2014/05/04/arduino-leonardo-fully-featured-keyboard/).

The circuit is up to you - each pin transition from `LOW` to `HIGH` will generate the corresponding key press event,
and `HIGH` to `LOW` will generate the key release, with a debounce delay (50ms by default). A sample circuit is
available in [Arduino samples](http://arduino.cc/en/uploads/Tutorial/KeyboardMouseControl_bb.png).
