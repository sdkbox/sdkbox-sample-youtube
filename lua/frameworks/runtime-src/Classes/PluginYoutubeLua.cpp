#include "PluginYoutubeLua.hpp"
#include "PluginYoutube/PluginYoutube.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginYoutubeLua_PluginYoutube_playPlayList(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginYoutube",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 5)
    {
        std::string arg0;
        int arg1;
        int arg2;
        bool arg3;
        bool arg4;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginYoutube:playPlayList");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginYoutube:playPlayList");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "sdkbox.PluginYoutube:playPlayList");
        ok &= luaval_to_boolean(tolua_S, 5,&arg3, "sdkbox.PluginYoutube:playPlayList");
        ok &= luaval_to_boolean(tolua_S, 6,&arg4, "sdkbox.PluginYoutube:playPlayList");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginYoutubeLua_PluginYoutube_playPlayList'", nullptr);
            return 0;
        }
        sdkbox::PluginYoutube::playPlayList(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginYoutube:playPlayList",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginYoutubeLua_PluginYoutube_playPlayList'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginYoutubeLua_PluginYoutube_playVideo(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginYoutube",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        std::string arg0;
        int arg1;
        bool arg2;
        bool arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginYoutube:playVideo");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginYoutube:playVideo");
        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "sdkbox.PluginYoutube:playVideo");
        ok &= luaval_to_boolean(tolua_S, 5,&arg3, "sdkbox.PluginYoutube:playVideo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginYoutubeLua_PluginYoutube_playVideo'", nullptr);
            return 0;
        }
        sdkbox::PluginYoutube::playVideo(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginYoutube:playVideo",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginYoutubeLua_PluginYoutube_playVideo'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginYoutubeLua_PluginYoutube_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginYoutube",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginYoutubeLua_PluginYoutube_init'", nullptr);
            return 0;
        }
        sdkbox::PluginYoutube::init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginYoutube:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginYoutubeLua_PluginYoutube_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginYoutubeLua_PluginYoutube_close(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginYoutube",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginYoutubeLua_PluginYoutube_close'", nullptr);
            return 0;
        }
        sdkbox::PluginYoutube::close();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginYoutube:close",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginYoutubeLua_PluginYoutube_close'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginYoutubeLua_PluginYoutube_playVideoList(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginYoutube",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 5)
    {
        std::vector<std::string> arg0;
        int arg1;
        int arg2;
        bool arg3;
        bool arg4;
        ok &= luaval_to_std_vector_string(tolua_S, 2, &arg0, "sdkbox.PluginYoutube:playVideoList");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginYoutube:playVideoList");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "sdkbox.PluginYoutube:playVideoList");
        ok &= luaval_to_boolean(tolua_S, 5,&arg3, "sdkbox.PluginYoutube:playVideoList");
        ok &= luaval_to_boolean(tolua_S, 6,&arg4, "sdkbox.PluginYoutube:playVideoList");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginYoutubeLua_PluginYoutube_playVideoList'", nullptr);
            return 0;
        }
        sdkbox::PluginYoutube::playVideoList(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginYoutube:playVideoList",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginYoutubeLua_PluginYoutube_playVideoList'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginYoutubeLua_PluginYoutube_removeListener(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginYoutube",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginYoutubeLua_PluginYoutube_removeListener'", nullptr);
            return 0;
        }
        sdkbox::PluginYoutube::removeListener();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginYoutube:removeListener",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginYoutubeLua_PluginYoutube_removeListener'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginYoutubeLua_PluginYoutube_getListener(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginYoutube",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginYoutubeLua_PluginYoutube_getListener'", nullptr);
            return 0;
        }
        sdkbox::YoutubeListener* ret = sdkbox::PluginYoutube::getListener();
        object_to_luaval<sdkbox::YoutubeListener>(tolua_S, "sdkbox.YoutubeListener",(sdkbox::YoutubeListener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginYoutube:getListener",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginYoutubeLua_PluginYoutube_getListener'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginYoutubeLua_PluginYoutube_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginYoutube)");
    return 0;
}

int lua_register_PluginYoutubeLua_PluginYoutube(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginYoutube");
    tolua_cclass(tolua_S,"PluginYoutube","sdkbox.PluginYoutube","",nullptr);

    tolua_beginmodule(tolua_S,"PluginYoutube");
        tolua_function(tolua_S,"playPlayList", lua_PluginYoutubeLua_PluginYoutube_playPlayList);
        tolua_function(tolua_S,"playVideo", lua_PluginYoutubeLua_PluginYoutube_playVideo);
        tolua_function(tolua_S,"init", lua_PluginYoutubeLua_PluginYoutube_init);
        tolua_function(tolua_S,"close", lua_PluginYoutubeLua_PluginYoutube_close);
        tolua_function(tolua_S,"playVideoList", lua_PluginYoutubeLua_PluginYoutube_playVideoList);
        tolua_function(tolua_S,"removeListener", lua_PluginYoutubeLua_PluginYoutube_removeListener);
        tolua_function(tolua_S,"getListener", lua_PluginYoutubeLua_PluginYoutube_getListener);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginYoutube).name();
    g_luaType[typeName] = "sdkbox.PluginYoutube";
    g_typeCast["PluginYoutube"] = "sdkbox.PluginYoutube";
    return 1;
}
TOLUA_API int register_all_PluginYoutubeLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginYoutubeLua_PluginYoutube(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

