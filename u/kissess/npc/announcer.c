// announcer.c
//by kissess

inherit NPC;
#include <ansi.h>

string *msg = ({
"欢迎光临『三界神话』之--「泉州师院总站」！\n",
"大家遇到什么问题，post到客栈或者叫在线巫师解决\n",
"请多看看help里面有关于MUD的最新变化！\n",
"请玩家在客栈二楼多提宝贵意见。\n",
"如果玩家们对本站有何意见或好的建议，请email ＴＯ：mudfairy@mail.china.com 。\n",
});
void create()
{
set_name(HIC"神话传说"NOR, ({"shcs"}));
set("gender", "男性" );
set("age", 20);
set("title", HIM"三界神话新闻发布员"NOR);
set("long", "一个相貌俊朗的男生，负责三界神话的新闻发布。\n");
set("combat_exp", 20000);
set("attitude", "friendly");
        set_skill("dodge", 30);
set("per", 25);
set("max_kee", 100000);
set("kee",100000);
set("sen",100000);
set("max_sen", 100000);
setup();
remove_call_out("msg");
call_out("msg",3600);
}
void msg()
{
        command_function("chat  "+NOR+HBMAG+msg[random(sizeof(msg))]+NOR);

        remove_call_out("msg");
call_out("msg",3600);

}
