
# How to run sdkbox samples

Steps:

~~~bash
mkdir samples
cd samples

# must clone this repo
git clone --depth 1 https://github.com/sdkbox/sdkbox-cocos2d-x-binary.git

# clone sample repo
git clone --depth 1 https://github.com/sdkbox/sdkbox-sample-youtube.git

# run sample with specified language and platform
# eg: cpp and ios
./sdkbox-cocos2d-x-binary/run_sample.sh youtube cpp ios
## or
cd cpp && cocos run -p ios

# javascript and android
./sdkbox-cocos2d-x-binary/run_sample.sh youtube js android
## or
cd js && cocos run -p android

# <optional> if exists "download-depends.sh" in sample repo, execute it
# ./sdkbox-sample-youtube/download-depends.sh

~~~

Memo:

1.  Sample repo and cocos2dx repo must be in same level directory

~~~
+-- sdkbox-cocos2d-x-binary
+-- sdkbox-sample-youtube
| +-- cpp
| +-- lua
| \-- js
~~~

# config close button on iOS

- "show_close_button":true
- "close_button_text":"-X-"
- "close_button_image":"res/button.png"

"close_button_image" takes priority over "close_button_text"
