#pragma once

#include <memory>

class CommentTask
{
    struct _m_CommentTask;
    static std::shared_ptr<_m_CommentTask> member;
public:
    static void setup();
    static void clear();
    static void draw();
    static void update();
};