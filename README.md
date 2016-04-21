# Matrix Gesture C++ SDK
![alt text](https://github.com/matrix-io/matrix-gesture-node-sdk/raw/master/examples/logo.png "Gesture.ai Logo")

A high performance C++ library with node bindings to easily incorporate gesture recognition into any project. It uses a trained object detection method (with over 100,000 samples per gesture!) and is therefore robust to different skin colors and lighting changes. 

For the initial release the SDK is only linux compatible, but this means it can be extended to other systems via Docker.

There are currently three detectable gestures: open PALM, THUMB UP, and FIST. Tracking options are available so it can track changes between hands. Smoothing filters are available so fine control can be used.

![alt text](https://github.com/matrix-io/matrix-gesture-node-sdk/raw/master/examples/palm.jpg "Palm")
![alt text](https://github.com/matrix-io/matrix-gesture-node-sdk/raw/master/examples/fist.jpg "Fist")
![alt text](https://github.com/matrix-io/matrix-gesture-node-sdk/raw/master/examples/thumb_up.jpg "Thumb Up")

### Dependences:
Linux, 
OpenCV 3.1.0, 
Cmake 2.8+

## Examples (with Docker)

As it is currently only linux compatible we have created an image on DockerHub which includes all required dependencies. If you would like to build the Dockerfile yourself it is included in the repository.

* First give root access to Docker as an X server. This will allow the camera feed to be accessed.

```xhost local:root```

* Download the image and create and run a daemon container, giving it access to your default camera and a port through which to host a webserver. 

```sudo docker run -itd -p 8080:8080 -p 3000:3000 --privileged \
-name gesture \
-v /dev/video0:/dev/video0 \
-v /tmp/.X11-unix:/tmp/.X11-unix \
-e DISPLAY=$DISPLAY admobilize/gesture```

* Execute a command inside the docker, to run the C++ executable: `gesture_example`

```sudo docker exec -it gesture /bin/sh -c 'cd ~/matrix-gesture-cpp-sdk/; ./gesture_example'```

This pops up a window with the feed from your default camera and runs the tracking algorithm looking for and boxing whenever it detects a flat palm. It will also look for a thumbs up or a closed fist if the palm briefly disappears. Try out some of the examples or write your own using the documentation!

It will return to stdout a Detected_Object with the location (X x Y), hand type, unique id, and time to process an image exposed.

```
---- Detected Objects: 
212 x 306
hand type: 0 - ID: 1
Time: 17.9579
```

For those running mac/windows, you would have to create a VirtualBox running linux to be able to access the camera from docker. Docker-engine runs a basic linux that doesn't recognize the camera. Docker is currently beta testing their new mac/windows docker which will be compatible with this library and you will be able to access your camera. 

#### Usage and Compiling

To use this library in your project all that is required is OpenCV 3.1 and for you to `#include "gesture_manager.h" where you want to call gesture methods.

You need to compile the C++ project using cmake. In Docker, a precompiled project awaits you in the docker SDK. In the SDK, an example `CMakeLists.txt` is included with proper linking of the library and openCV. all that is required is for you to exchange your main file with `example.cpp` or if your project is more complex, integrate it as source files. Keep in mind that the `classifiers/` folder must be in the same directory as the libgesture.so.

### Usage without Docker

The functionality is the same as long as you have the required dependencies this should work outside of Docker with gcc 4.9+. I have included the static lib `libgesture.a` to help ease compilation outside of docker.

### Documentation
The documentation can be found [here](http://gesture.ai/#/develop "Gesture.ai Documentation")

### Community
Visit and join our community [here](http://community.gesture.ai "Gesture.ai Community")
