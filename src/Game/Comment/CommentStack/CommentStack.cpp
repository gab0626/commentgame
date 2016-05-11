#include "CommentStack.h"
#include "../CommentOption/CommentOption.h"

struct CommentStack::_m_CommentStack
{
    std::vector<std::pair<bool, size_t>> stack = std::vector<std::pair<bool, size_t>>(10);
};

CommentStack::CommentStack()
{
    member = std::make_shared<CommentStack::_m_CommentStack>();
}

void CommentStack::update()
{
    for (auto& obj : member->stack)
    {
        if (obj.second == 0) continue;
        if (CommentOption::eraseCount / 2.0f < CommentOption::frameCounter - obj.second)
        {
            obj = { false, 0 };
        }
    }
}

size_t CommentStack::regist()
{
    for (size_t i = 0; i < member->stack.size(); ++i)
    {
        if (member->stack.at(i).first == false)
        {
            member->stack.at(i) = { true, CommentOption::frameCounter };
            return i;
        }
    }
    return interrupt();
}

size_t CommentStack::interrupt()
{
    size_t min = member->stack.begin()->second;
    size_t num = 0;
    for (size_t i = 1; i < member->stack.size(); ++i)
    {
        if (member->stack.at(i).second < min)
        {
            min = member->stack.at(i).second;
            num = i;
        }
    }
    bool allMin = true;
    for (size_t i = 0; i < member->stack.size(); ++i)
    {
        if (member->stack.at(i).second != min)
        {
            allMin = false;
            break;
        }
    }
    if (allMin) 
    {
        CommentOption::frameCounter += 1;
        member->stack.at(num).second = CommentOption::frameCounter;
    }
    else
    {
        member->stack.at(num).second = CommentOption::frameCounter;
    }

    return num;
}

CommentStack& CommentStack::Access(const FlowString::Type type)
{
    return CommentStack::stackList.at(static_cast<size_t>(type));
}

void CommentStack::clear()
{
    CommentStack::stackList.clear();
    CommentStack::stackList = std::vector<CommentStack>(3);
}

std::vector<CommentStack> CommentStack::stackList = std::vector<CommentStack>(3);