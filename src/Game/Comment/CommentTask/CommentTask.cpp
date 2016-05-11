#include "CommentTask.h"
#include "../FlowString/FlowString.h"
#include "../CommentOption/CommentOption.h"
#include "../CommentWindow/CommentWindow.h"
#include "../CommentStack/CommentStack.h"

#include "../../AppEnv.h"

#include <vector>
#include <set>

using Comments = std::vector<FlowString>;
using Fonts = std::vector<Font>;

struct CommentTask::_m_CommentTask
{
    Comments comments;
private:
    Font temp = Font("res/Font/meiryo.ttc");    // 一回Fontのコンストラクタを呼んでおかないとメモリーアクセス違反になります。理由は知りません。
public:
    Fonts fonts;
};

std::shared_ptr<CommentTask::_m_CommentTask> CommentTask::member = std::make_shared<CommentTask::_m_CommentTask>();

void CommentTask::setup()
{
    member->fonts = { Font("res/Font/meiryo.ttc"), Font("res/Font/meiryo.ttc"), Font("res/Font/meiryo.ttc") };
    member->fonts.at(0).size((CommentWindow::size.y() / CommentOption::lines) * 0.5f);
    member->fonts.at(1).size((CommentWindow::size.y() / CommentOption::lines) * 0.8f);
    member->fonts.at(2).size((CommentWindow::size.y() / CommentOption::lines) * 1.0f);

    member->comments.push_back(FlowString("wwwwwwwwwwwwwwwwww", FlowString::Size::SMALL));
    member->comments.push_back(FlowString("↓草", FlowString::Size::BIG));
    member->comments.push_back(FlowString("適当なコメントです"));
    member->comments.push_back(FlowString("トキメキ☆ボムラッシュ"));
    member->comments.push_back(FlowString("い　つ　も　の"));
    member->comments.push_back(FlowString("どうしてこうなった"));
    member->comments.push_back(FlowString("テスト"));
    member->comments.push_back(FlowString("よくわからん"));
    member->comments.push_back(FlowString("お腹すいた"));
    member->comments.push_back(FlowString("(´・ω・｀)"));
    member->comments.push_back(FlowString("スプラトゥーン"));
    member->comments.push_back(FlowString("おｋ"));
    member->comments.push_back(FlowString("同時にコメントを打つと重なってしまうのか"));
    member->comments.push_back(FlowString("どうしたらいいものかねー"));
    member->comments.push_back(FlowString("でもまあなんとかなるっしょ"));

    member->comments.push_back(FlowString("wwwwwwwwwww", FlowString::Type::BOTTOM));
    member->comments.push_back(FlowString("コメント", FlowString::Type::BOTTOM));
}

void CommentTask::clear()
{
    member->comments.clear();
    member->fonts.clear();

    CommentOption::clear();
    CommentStack::clear();
}

void CommentTask::draw()    //　コメントの描画は上コメ→下コメ→中央コメの順でします。
{
    glPushMatrix();

    glTranslatef(CommentWindow::pos.x(), CommentWindow::pos.y(), 0);

    for (auto& obj : member->comments)
    {
        switch (obj.Get_Type())
        {
        case FlowString::Type::TOP:
            obj.drawStop(member->fonts);
            break;
        case FlowString::Type::MIDDLE:
            obj.drawFlow(member->fonts);
            break;
        case FlowString::Type::BOTTOM:
            obj.drawStop(member->fonts);
            break;
        default:
            break;
        }
    }

    drawBox(0, 0, CommentWindow::size.x(), CommentWindow::size.y(), 1, Color::red);
    drawLine(CommentWindow::size.x() - CommentWindow::size.x() * 1.1f, CommentWindow::size.y() / 2.0f,
             CommentWindow::size.x() * 1.1f, CommentWindow::size.y() / 2.0f,
             1, Color::red);
    drawLine(CommentWindow::size.x() / 2.0f, CommentWindow::size.y() - CommentWindow::size.y() * 1.1f,
             CommentWindow::size.x() / 2.0f, CommentWindow::size.y() * 1.1f,
             1, Color::red);

    glPopMatrix();
}

void CommentTask::update()
{
    CommentStack::Access(FlowString::Type::TOP).update();
    CommentStack::Access(FlowString::Type::MIDDLE).update();
    CommentStack::Access(FlowString::Type::BOTTOM).update();

    CommentOption::update();

    for (auto itr = member->comments.begin(); itr != member->comments.end();)
    {
        itr->update();
        if (!itr->isActive())
        {
            member->comments.erase(itr);
        }
        else
        {
            ++itr;
            continue;
        }
    }

    if (env.isPressKey(GLFW_KEY_LEFT_CONTROL) && env.isPushKey(GLFW_KEY_C))
    {
        member->comments.push_back(FlowString("wwwwwwwwwww"));
    }
}
