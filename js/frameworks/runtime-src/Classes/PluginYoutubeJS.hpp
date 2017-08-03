#ifndef __PluginYoutubeJS_h__
#define __PluginYoutubeJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginYoutubeJS_PluginYoutube(JSContext *cx, JS::HandleObject global);
void register_all_PluginYoutubeJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginYoutubeJS_PluginYoutube(JSContext *cx, JSObject* global);
void register_all_PluginYoutubeJS(JSContext* cx, JSObject* obj);
#endif
#endif

