
#include "PluginYoutubeJSHelper.h"
#include "SDKBoxJSHelper.h"
#include "PluginYoutube/PluginYoutube.h"

static JSContext* s_cx = nullptr;
class YoutubeListenerJsHelper : public sdkbox::YoutubeListener, public sdkbox::JSListenerBase
{
public:
    YoutubeListenerJsHelper():sdkbox::JSListenerBase() {
    }

    virtual void onPlayEnds(bool played_ok)
    {
        std::string name("onPlayEnds");
        jsval dataVal[1];
        dataVal[0] = BOOLEAN_TO_JSVAL(played_ok);
        invokeDelegate(name, dataVal, 1);
    }

private:
    void invokeDelegate(std::string& fName, jsval dataVal[], int argc) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = fName.c_str();

        JS::RootedObject obj(cx, getJSDelegate());
        JSAutoCompartment ac(cx, obj);

#if MOZJS_MAJOR_VERSION >= 31
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#elif MOZJS_MAJOR_VERSION >= 28
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#else
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JSVAL_VOID) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            if (0 == argc) {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::empty(), &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(argc, dataVal), &retval);
            }
#else
            if (0 == argc) {
                JS_CallFunctionName(cx, obj, func_name, 0, nullptr, &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, argc, dataVal, &retval);
            }
#endif
        }
    }
};


#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginYoutubeJS_PluginYoutube_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#elif defined(JS_VERSION)
JSBool js_PluginYoutubeJS_PluginYoutube_setListener(JSContext *cx, unsigned argc, JS::Value *vp)
#endif
{
    s_cx = cx;
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    if (argc == 1) {

        if (!args.get(0).isObject())
        {
            ok = false;
        }

        JSB_PRECONDITION2(ok, cx, false, "js_PluginYoutubeJS_PluginYoutube_setListener : Error processing arguments");
        YoutubeListenerJsHelper* lis = new YoutubeListenerJsHelper();
        lis->setJSDelegate(args.get(0));
        sdkbox::PluginYoutube::setListener(lis);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginYoutubeJS_PluginYoutube_setListener : wrong number of arguments");
    return false;
}

#define REGISTE_YOUTUBE_FUNCTIONS \
JS_DefineFunction(cx, pluginObj, "setListener",                 js_PluginYoutubeJS_PluginYoutube_setListener,                 1, JSPROP_READONLY | JSPROP_PERMANENT);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginYoutubeJS_helper(JSContext* cx, JS::HandleObject global) {
    // Get the ns
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginYoutube", &pluginObj);

    REGISTE_YOUTUBE_FUNCTIONS
}
#else
void register_all_PluginYoutubeJS_helper(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject pluginObj(cx);

    std::stringstream ss("sdkbox.PluginYoutube");
    std::string sub;
    const char* subChar;

    while(getline(ss, sub, '.')) {
        if(sub.empty())continue;

        subChar = sub.c_str();

        JS_GetProperty(cx, obj, subChar, &nsval);
        if (nsval == JSVAL_VOID) {
            pluginObj = JS_NewObject(cx, NULL, NULL, NULL);
            nsval = OBJECT_TO_JSVAL(pluginObj);
            JS_SetProperty(cx, obj, subChar, nsval);
        } else {
            JS_ValueToObject(cx, nsval, &pluginObj);
        }
        obj = pluginObj;
    }

    REGISTE_YOUTUBE_FUNCTIONS
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginYoutubeJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginYoutube", &pluginObj);

    REGISTE_YOUTUBE_FUNCTIONS
}
#endif

