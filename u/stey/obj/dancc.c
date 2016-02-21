
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
//    set("no_get", 1);
 //   set("no_give", 1);
    set("no_drop", 1);
    set("no_sell", 1);
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  set_name( HIY "金宝宝的重选丹" NOR , ({"chongxuan dan", "dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗金黄色的金宝宝的pk 重选丹丸，略微能闻到些许香气。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan" && arg!="huanhun dan")	return 0;
  
  me->delete("ziyouchoose");
  me->delete("pk");
  me->delete("ziyou");

  message_vision(HIG "$N轻轻掰开一颗金宝宝的pk 重选丹送入嘴中，一时间香气四溢。
只见$N脑袋空空如也，看起来有点呆呆的！\n" NOR, me);
  destruct(this_object());
  return 1;
}

