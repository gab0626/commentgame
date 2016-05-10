#pragma once

class CommentOption
{
public:
    static size_t lines;
    static int eraseCount;
    static size_t frameCounter;
public:
    static void update();
    static void clear();
};