#include "Comment.h"
#include "CommentTask/CommentTask.h"

Comment::Comment()
{
    CommentTask::setup();
}

Comment::~Comment()
{
    CommentTask::clear();
}

void Comment::update()
{
    CommentTask::update();
}

void Comment::draw()
{
    CommentTask::draw();
}
