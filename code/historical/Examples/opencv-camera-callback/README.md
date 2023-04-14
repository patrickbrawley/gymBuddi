# opencv camera callback class

Callback based camera class for openCV where the client registers a callback
which then receives the frames at the framerate of the camera.


## camera.h / camera.cpp

```
class Camera {
public:
	/**
	 * Callback which needs to be implemented by the client
	 **/
	struct SceneCallback {
		virtual void nextScene(const cv::Mat &mat) = 0;
	};

	/**
	 * Default constructor
	 **/
	Camera() = default;

	/**
	 * Starts the acquisition from the camera
	 * and then the callback is called at the framerate.
	 **/
	void start(int deviceID = 0, int apiID = 0);

	/**
	 * Stops the data aqusisition
	 **/
	void stop();

	/**
	 * Registers the callback which receives the
	 * frames.
	 **/
	void registerSceneCallback(SceneCallback* sc) {
		sceneCallback = sc;
	}
```

## QT demo

Install the opencv development packages:
```
sudo apt install libopencv-dev
```

and the QT development packages:
```
sudo apt-get install qtdeclarative5-dev-tools
sudo apt-get install libqwt-qt5-dev
```

The demo displays the camera in a QT window and
also displays the grey value of the centre
pixel with a thermometer.


# Credits

 * [Ross Gardiner](https://github.com/rossGardiner)
 * [Adam Frew](https://github.com/Saweenbarra) 
 * [Alban Joseph](https://github.com/albanjoseph)
 * [Lewis Russell](https://github.com/charger4241)
 * Bernd Porr
