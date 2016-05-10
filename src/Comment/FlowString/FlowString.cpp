#include "FlowString.h"
#include "../CommentOption/CommentOption.h"
#include "../CommentWindow/CommentWindow.h"
#include "../CommentStack/CommentStack.h"

struct FlowString::_m_FlowString
{
    int eraseCount;
    size_t spawnFrame;
    Vec2f pos;
    Type type;
    Size size;
    Color col;
    std::string comment;
};

FlowString::FlowString(const std::string& comment, const FlowString::Size size, const FlowString::Type type, const Color& col)
{
    setup(comment, size, type, col);
}

FlowString::FlowString(const std::string & comment, const FlowString::Type type, const FlowString::Size size, const Color & col)
{
    setup(comment, size, type, col);
}

void FlowString::setup(const std::string& comment, const FlowString::Size size, const FlowString::Type type, const Color& col)
{
    member = std::make_shared<FlowString::_m_FlowString>();

    member->eraseCount = CommentOption::eraseCount;
    member->spawnFrame = CommentOption::frameCounter;
    member->pos.x() = CommentWindow::size.x();
    member->pos.y() = 0.0f;
    member->type = type;
    member->size = size;
    member->col = col;
    member->comment = comment;

    double commentHeight = CommentWindow::size.y() / CommentOption::lines;
    switch (member->type)
    {
    case FlowString::Type::TOP:
        member->pos.y() = CommentWindow::size.y() - commentHeight - (commentHeight * CommentStack::Access(member->type).regist());
        break;
    case FlowString::Type::MIDDLE:
        member->pos.y() = CommentWindow::size.y() - commentHeight - (commentHeight * CommentStack::Access(member->type).regist());
        break;
    case FlowString::Type::BOTTOM:
        member->pos.y() =  + (commentHeight * CommentStack::Access(member->type).regist());
        break;
    default:
        break;
    }
}

void FlowString::drawFlow(std::vector<Font>& font)
{
    size_t access = static_cast<size_t>(member->size);
    member->pos.x() = CommentWindow::size.x() - (font.at(access).drawSize(member->comment).x() + CommentWindow::size.x()) / CommentOption::eraseCount * (CommentOption::frameCounter - member->spawnFrame);
    font.at(access).draw(member->comment, member->pos, member->col);
}

void FlowString::drawStop(std::vector<Font>& font)
{
    size_t access = static_cast<size_t>(member->size);
    member->pos.x() = (CommentWindow::size.x() - font.at(access).drawSize(member->comment).x()) / 2.0f;
    font.at(access).draw(member->comment, member->pos, member->col);
}

void FlowString::update()
{
    member->eraseCount -= 1;
}

bool FlowString::isActive()
{
    return 0 <= member->eraseCount ? true : false;
}

FlowString::Type FlowString::Get_Type()
{
    return member->type;
}

size_t FlowString::Get_SpawnFrame()
{
    return member->spawnFrame;
}

void FlowString::Set_Type(const FlowString::Type type)
{
    member->type = type;
}

void FlowString::Set_SpawnFrame(const size_t spawnFrame)
{
    member->spawnFrame = spawnFrame;
}
