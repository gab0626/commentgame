#pragma once

#include "../FlowString/FlowString.h"

#include <memory>
#include <vector>

class CommentStack
{
    struct _m_CommentStack;
    std::shared_ptr<_m_CommentStack> member;
public:
    CommentStack();
public:
    void update();
    size_t regist();
private:
    size_t interrupt();

private:
    static std::vector<CommentStack> stackList;
public:
    static CommentStack& Access(const FlowString::Type type);
    static void clear();
};