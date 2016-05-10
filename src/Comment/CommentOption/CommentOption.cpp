#include "CommentOption.h"

#include <fstream>
#include <string>

size_t CommentOption::lines;
int CommentOption::eraseCount;
size_t CommentOption::frameCounter;

static struct _Setup_CommentOption
{
    _Setup_CommentOption()
    {
        std::fstream input("src/Game/Comment/CommentOption.txt", std::ios::in);

        if (input.is_open())
        {
            input
                >> CommentOption::lines
                >> CommentOption::eraseCount
                >> CommentOption::frameCounter;

            input.close();
        }
        else
        {
            throw(!"Exception : CommentOption ~File is not found~");
        }
    }
}_init;

void CommentOption::update()
{
    CommentOption::frameCounter += 1;
}

void CommentOption::clear()
{
    CommentOption::frameCounter = 0;
}
