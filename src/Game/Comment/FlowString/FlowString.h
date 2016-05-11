#pragma once

#include "../../AppEnv.h"

#include <memory>
#include <string>
#include <vector>

class FlowString
{
    struct _m_FlowString;
    std::shared_ptr<_m_FlowString> member;
public:
    enum class Type
    {
        TOP,
        MIDDLE,
        BOTTOM
    };
    enum class Size
    {
        SMALL,
        MIDDLE,
        BIG
    };
private:
public:
    FlowString(const std::string& comment,
               const FlowString::Size size = FlowString::Size::MIDDLE,
               const FlowString::Type type = FlowString::Type::MIDDLE,
               const Color& col = Color::white);
    FlowString(const std::string& comment,
               const FlowString::Type type,
               const FlowString::Size size = FlowString::Size::MIDDLE,
               const Color& col = Color::white);
private:
    void setup(const std::string& comment,
               const FlowString::Size size = FlowString::Size::MIDDLE,
               const FlowString::Type type = FlowString::Type::MIDDLE,
               const Color& col = Color::white);
public:
    void drawFlow(std::vector<Font>& font);
    void drawStop(std::vector<Font>& font);
    void update();
    bool isActive();
public:
    FlowString::Type Get_Type();
    size_t Get_SpawnFrame();
public:
    void Set_Type(const FlowString::Type type);
    void Set_SpawnFrame(const size_t spawnFrame);
};