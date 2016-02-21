
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get", 1);
    set("no_give", 1);
    set("no_drop", 1);
    set("no_sell", 1);
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set_name( HIY "铁马冰河入梦来的容貌丹" NOR , ({"dan", "rongmao dan"}));
     set("long", "一颗淡兰色的修改容貌的丹丸，略微能闻到些许香气。\n");
       set("value",1000000);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
   if (arg!="dan" && arg!="rongmao dan") return 0;
  
me->add("per",1);

    message_vision(HIG "$N轻轻掰开一颗容貌丹送入嘴中，一时间香气四溢。
    只见$N容光焕发，看起来好象变的好看了！\n" NOR, me);
  destruct(this_object());
  return 1;
}

