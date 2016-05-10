#include "CommentWindow.h"

#include <fstream>
#include <string>

Vec2f CommentWindow::pos;
Vec2f CommentWindow::size;

static struct _Setup_CommentWindow
{
    _Setup_CommentWindow()
    {
        std::fstream input("src/Game/Comment/CommentWindow.txt", std::ios::in);

        if (input.is_open())
        {
            float pos_x, pos_y;
            float size_x, size_y;

            input
                >> pos_x >> pos_y
                >> size_x >> size_y;

            CommentWindow::pos = Vec2f(pos_x, pos_y);
            CommentWindow::size = Vec2f(size_x, size_y);

            input.close();
        }
        else
        {
            throw(!"Exception : CommentWindow ~File is not found~\n");
        }
    }
}_init;