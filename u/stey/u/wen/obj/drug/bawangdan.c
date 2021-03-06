
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松，霸王丹从指间滑落！\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  set_name( RED "霸王丹" NOR , ({"bawang dan", "dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "粒");
    set("long", "一颗暗红的丹丸，一股刺鼻的气味扑鼻而来。\n");
    set("value", 1000000);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan" && arg!="huanhun dan")	return 0;
  
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana")+me->query("max_mana")-1);
  me->set("force", (int)me->query("max_force")+me->query("max_force")-1);
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  message_vision(RED "$N轻轻掰开外边的蜡皮，将一粒霸王丹送入嘴中，一时间香气四溢。
只见$N脸上慢慢泛出红晕，看起来有精神多了！\n" NOR, me);
  destruct(this_object());
  return 1;
}

