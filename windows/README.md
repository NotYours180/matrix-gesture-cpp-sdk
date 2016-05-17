# Matrix Gesture C++ SDK -- Windows
![alt text](https://github.com/matrix-io/matrix-gesture-node-sdk/raw/master/docker/examples/logo.png "Gesture.ai Logo")

#### Dependencies 
MSVC C++ distribution
MSVC 14 (May work on others, only tested with VS 14)
OpenCV 3.1.0 (DLL included)
Libcurl/pthreads (DLL included)

To start your own developement, you must statically link against `gesture.lib` and include the header file `gesture_manager.h`. The required dependency .dll are also included for OpenCV/libcurl/pthreads. These are only necessary at runntime. 

`gesture_test.exe` is an example executable demonstrating the capability of the gesture tracking methods. It will pop up a window with the feed from your default camera and runs the tracking algorithm looking for and boxing whenever it detects a flat palm. It will also look for a thumbs up or a closed fist if the palm briefly disappears. It will also open a separate window in which you will be able to reveal the gesture.ai logo by erasing with your hand. Turn erasing on and off by making a fist and restart by giving a thumbs up. Stdout should print detection time and hand information

### Documentation
The documentation can be found [here](http://gesture.ai/#/develop "Gesture.ai Documentation")

### Community
Visit and join our community [here](http://community.gesture.ai "Gesture.ai Community")