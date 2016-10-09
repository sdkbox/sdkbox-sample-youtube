#ifndef __PLUGIN_YOUTUBE_WRAPPER_H__
#define __PLUGIN_YOUTUBE_WRAPPER_H__

#include "CocosMacros.h"
#include "PluginYoutube.h"
#include "json98.h"

#include <string>
#include <vector>

namespace sdkbox {


#define TAG "Youtube"
#define VERSION "1.0"

    class YoutubeWrapper {
    public:

        static YoutubeWrapper* getInstance();

        virtual void init()=0;
        virtual void setListener(YoutubeListener* listener)=0;
        virtual YoutubeListener* getListener()=0;
        virtual void removeListener()=0;

        virtual void playVideo( const std::string& video_id, int startMillis, bool autoplay, bool lightbox )=0;
        virtual void playPlayList( const std::string& playlist_id, int playListStartIndex, int startMillis, bool autoplay, bool lightbox )=0;
        virtual void playVideoList( const std::vector<std::string>& video_ids, int playListStartIndex, int startMillis, bool autoplay, bool lightbox )=0;
        virtual void close()=0;
        virtual void resetPlayerIf()=0;
    };

    class YoutubeWrapperDisabled : public YoutubeWrapper {
    public:
        
        void init() {}
        void setListener(YoutubeListener* listener) {}
        YoutubeListener* getListener() { return NULL; }
        void removeListener() {}
        
        void playVideo( const std::string& video_id, int startMillis, bool autoplay, bool lightbox ) {}
        void playPlayList( const std::string& playlist_id, int playListStartIndex, int startMillis, bool autoplay, bool lightbox ) {}
        void playVideoList( const std::vector<std::string>& video_ids, int playListStartIndex, int startMillis, bool autoplay, bool lightbox ) {}
        void close() {}
        void resetPlayerIf() {}
    };
    
    class YoutubeWrapperEnabled : public YoutubeWrapper {
    public:
        YoutubeWrapperEnabled();
        
        void init();
        void setListener(YoutubeListener* listener);
        YoutubeListener* getListener();
        void removeListener();
        void playVideo( const std::string& video_id, int startMillis, bool autoplay, bool lightbox );
        void playPlayList( const std::string& playlist_id, int playListStartIndex, int startMillis, bool autoplay, bool lightbox );
        void playVideoList( const std::vector<std::string>& video_ids, int playListStartIndex, int startMillis, bool autoplay, bool lightbox );
        void close();
        void resetPlayerIf();
        
    protected:
        bool nativeInit(const std::string& developer_key, bool debug, const Json& config = Json());
        
        YoutubeListener* _listener;
        bool _playerReset;
    };
    
}

#endif
