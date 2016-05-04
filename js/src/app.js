
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        // var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
        //     cc.log("QUIT");
        // });
        // var menu = new cc.Menu(quit);
        // var size = quit.getContentSize();
        // menu.x = winsize.width - size.width / 2 - 16;
        // menu.y = size.height / 2 + 16;
        // this.addChild(menu);

        return true;
    },

    createTestMenu:function() {
        sdkbox.PluginYoutube.init();
        sdkbox.PluginYoutube.setListener({
            onPlayEnds: function() {
                cc.log("Video finished playing");
            }
        });

        var menu = new cc.Menu();

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("play video", "sans", 28), function() {
            cc.log("play video");
            sdkbox.PluginYoutube.playVideo("sYmQQn_ZSys", 0, true, true);
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Play a youtube playlist", "sans", 28), function() {
            cc.log("Play a youtube playlist");
            sdkbox.PluginYoutube.playPlayList("PLF0D3A9748DC5E42D", 0, 0, true, true);
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("Play a group of youtube videos", "sans", 28), function() {
            cc.log("Play a group of youtube videos");
            var videos = [
                "AcaBI_I0Td0",
                "0UjWqQPWmsY",
                "24i8G5a5d5Q"
            ];
            sdkbox.PluginYoutube.playVideoList(videos, 0, 0, true, true);
        }));

        var winsize = cc.winSize;
        menu.x = winsize.width / 2;
        menu.y = winsize.height / 2;
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu);
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

