# simple-rc-shutter
Very basic photo shutter for SONY cameras.

Had no suitable opamp around, so did simple PWM-controlled photo shutter from old Arduino ProMini board.
Sides can be cut down to shrink board size, schematics in /img/ folder.

3 or 2 position switch (middle = focus), may require some delay customizing with slow lens/camera.

Multiport cable can be purchased in CN (won't work with typical 5-pin USB cable) for something like 3€, for example: https://www.aliexpress.com/item/4001231240583.html

It can also be used on many other cameras (tested on GoPro 3 and 4, Xiaomi Yi, DxO One cameras) - probably any, where shutter is shorting some signal pin to ground. Just have in mind, that in some action cams (GoPro, Yi) shutter button does several functions and long-press does not repeat photo (but switches modes, for example), so add sleep/break statements if you are not using momentary switches to trigger photo/video.
