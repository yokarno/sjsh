// by Xuexu 26/3/2001
#include <ansi.h>
inherit ITEM;
void create()
{
set_name( HIW "桂花糯米糕" NOR, ({"guihua gao", "gao"}));
set_weight(120);
if (clonep())
set_default_object(__FILE__);
else {
set("unit", "块");
set("long", "一块香甜的桂花糯米糕，是江南的特产，食之松甜可口。\n");
set("value", 800);
set("no_sell", 1);
}
setup();
call_out ("becoming_old",1800);
}
void becoming_old ()
{
  object me = this_object();
  object where = environment (me);
  object dan = new (__DIR__"danbad");
  dan->move(where);
  destruct (me);
}
void init()
{
  add_action("do_eat", "eat");
}
int do_eat(string arg)
{
  object me = this_player();
  if (arg!="guihua gao" && arg!="gao") 
    return 0;
  me->set("food", (int)me->max_food_capacity()*3+random(120));
  me->set("water", (int)me->max_water_capacity()*3+random(120));
  message_vision(HIW "$N仔细品了品桂花糕，一股香甜的味道透入心扉。\n" NOR, me);
tell_object(me, "你觉得肚中充满香气，不禁飘飘欲仙！\n");
  destruct(this_object());
  return 1;
}
