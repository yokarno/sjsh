#include <ansi.h>
inherit ITEM;
void init();
void init()
{
if (!wizardp(this_player())) {
  set("no_drop","这么宝贵的东西，哪能乱扔! \n");
  set("no_give","这么宝贵的东西，还是自己留着吧! \n");
}
add_action("do_eat", "eat");
}
void create()
{
set_name(HIR"愚人丹" NOR, ({HIY"yuren dan"NOR, "dan"}));
set_weight(20);
if (clonep())
set_default_object(__FILE__);
else {
set("unit", "粒");
 set("long", "一粒愚人丹，是xlqy巫师组发给大家的愚人节礼物!\n");
set("value", 0);
}
setup();
}
int do_eat(string arg)
{
object victim = this_player();
if (!id(arg))
return notify_fail("你要吃什么？\n");
 victim->add("potential",1);
 victim->add("combat_exp",1);
 victim->add("daoxing",1);
victim->save();
 message_vision(HIM "\n$N吃下一粒愚人丹,大呼：上当，上当!\n\n" NOR, victim);
destruct(this_object());
return 1;
}
