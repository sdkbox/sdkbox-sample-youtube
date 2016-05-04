
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    sdkbox.PluginYoutube:init()
    sdkbox.PluginYoutube:setListener(function(args)
        dump(args)
    end)
    local menu = cc.Menu:create()

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("play video", "sans", 28)):onClicked(function()
        print("play video")
        sdkbox.PluginYoutube:playVideo("sYmQQn_ZSys", 0, true, true)
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Play a youtube playlist", "sans", 28)):onClicked(function()
        print("Play a youtube playlist")
        sdkbox.PluginYoutube:playPlayList("PLF0D3A9748DC5E42D", 0, 0, true, true)
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("Play a group of youtube videos", "sans", 28)):onClicked(function()
        print("Play a group of youtube videos")
        local videos = {
            "AcaBI_I0Td0",
            "0UjWqQPWmsY",
            "24i8G5a5d5Q"
        }
        sdkbox.PluginYoutube:playVideoList(videos, 0, 0, true, true)
    end))

    menu:alignItemsVerticallyWithPadding(24)
    self:addChild(menu)
end

return MainScene
