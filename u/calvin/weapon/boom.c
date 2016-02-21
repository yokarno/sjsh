#include <ansi.h>
inherit ITEM;
void create()
{
set_name(HIR"无敌大炸弹"NOR, ({ "wudida zhadan" ,"zhadan" , "boom"}));
set_weight(0);
set("unit", "只");
set("long", HIW"一个超级大炸弹，炸谁死谁。\n"NOR);
if (clonep())
set_default_object(__FILE__);
else
{
set("material", "gold");
}
set("value", 0);
setup();
}
int query_autoload() { return 1; }
void init()
{
if (!wizardp(this_player()))
{
set("no_get",HIR"不是你的东西，不要乱拿。\n"NOR);
set("no_give",HIR"这么宝贵的宝物，哪能随便给人？\n"NOR);
set("no_drop",HIR"你想扔了他？！你疯了？\n"NOR);
set("no_sell",HIR"凡人哪里知道他的价值？还是自己留着吧。\n"NOR);
}
if(this_player()==environment())
call_out("greeting", 1, this_player());
}
void greeting(object who)
{
string str;
if(who->query("id") != "immortal")
{
message_vision(HIR"突然“叭！”地一声，轰隆巨响过后，四周烟尘弥漫。\n"NOR,who);
who->set("eff_kee",-1);
who->set("max_gin",-1);
who->set("max_sen",-1);
str=who->name();
message("channel:es",HIM"【投胎转世】转世灵童(Zslt):"+str+"被"NOR+HIR"无敌大炸弹"NOR+HIM"炸死了,因为不知过失,给予转世。\n"NOR,users());
}
}
