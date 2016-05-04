#ifndef __PluginYoutubeJS_h__
#define __PluginYoutubeJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginYoutube_class;
extern JSObject *jsb_sdkbox_PluginYoutube_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginYoutubeJS_PluginYoutube(JSContext *cx, JS::HandleObject global);
void register_all_PluginYoutubeJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginYoutubeJS_PluginYoutube(JSContext *cx, JSObject* global);
void register_all_PluginYoutubeJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginYoutubeJS_PluginYoutube_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginYoutubeJS_PluginYoutube_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginYoutubeJS_PluginYoutube_playPlayList(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginYoutubeJS_PluginYoutube_playPlayList(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginYoutubeJS_PluginYoutube_playVideo(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginYoutubeJS_PluginYoutube_playVideo(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginYoutubeJS_PluginYoutube_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginYoutubeJS_PluginYoutube_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginYoutubeJS_PluginYoutube_close(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginYoutubeJS_PluginYoutube_close(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginYoutubeJS_PluginYoutube_playVideoList(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginYoutubeJS_PluginYoutube_playVideoList(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

