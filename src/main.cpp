#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

static void applyFPS() {
    float fps = geode::utils::numFromString<float>(
        Mod::get()->getSettingValue<std::string>("fps")
    ).unwrapOr(60.f);

    if (fps < 1.f) fps = 60.f;

    auto gm = GameManager::get();
    gm->setGameVariable("0116", true);   // "Unlock FPS"
    gm->m_customFPSTarget = fps;

    CCApplication::sharedApplication()->setAnimationInterval(1.0 / fps);
    log::info("Target FPS: {}", fps);
}

$on_mod(Loaded) {
    listenForSettingChanges<std::string>("fps", [](std::string) {
        applyFPS();
    });
}

class $modify(FPSMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;
        applyFPS();
        return true;
    }
};

// The game sometimes resets the interval when entering a level
class $modify(FPSPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;
        applyFPS();
        return true;
    }
};
