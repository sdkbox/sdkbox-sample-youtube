
#include "HelloWorldScene.h"
#include "PluginYoutube/PluginYoutube.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    CCLOG("Sample Startup");

    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);

    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));

    // add test menu
    createTestMenu();

    return true;
}

void HelloWorld::createTestMenu()
{
    sdkbox::PluginYoutube::setListener(this);
    
    auto menu = Menu::create();

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("play video", "sans", 24), [](Ref*){
        CCLOG("play video");
        sdkbox::PluginYoutube::playVideo("sYmQQn_ZSys", 0, true, true);

    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Play a youtube playlist", "sans", 24), [](Ref*){
        CCLOG("Play a youtube playlist");
        sdkbox::PluginYoutube::playPlayList("PLF0D3A9748DC5E42D", 0, 0, true, true);
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Play a group of youtube videos", "sans", 24), [](Ref*){
        CCLOG("Play a group of youtube videos");
        std::vector<std::string> videos;
        videos.push_back("AcaBI_I0Td0");
        videos.push_back("0UjWqQPWmsY");
        videos.push_back("24i8G5a5d5Q");
        sdkbox::PluginYoutube::playVideoList(videos, 0, 0, true, true);
    }));
    
    menu->alignItemsVerticallyWithPadding(10);
    addChild(menu);
}

void HelloWorld::onPlayEnds(bool played_ok)
{
    CCLOG("onPlayEnds: %s", played_ok ? "YES" : "NO");
}
