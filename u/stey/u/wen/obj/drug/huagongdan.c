#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
  set_name(MAG "特大化功丹" NOR, ({"huagong dan", "dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "乌乌的一颗化功丹。\n");
	set("value", 20000000);  
    set("value", 20000000);
    set("no_sell", 1);
  }
  
  setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
    
  if (!id(arg))
    return notify_fail("你要吃什么？\n");

	
if ((int)me->query("combat_exp") < 100000)  
 return notify_fail("以你的装态现在没法吃化功丹\n");

	else {
 
  	message_vision(MAG"$N吃下一颗特大化功丹，脸色大变，但觉体内发生了莫名的变化。\n"NOR, me);  
  
	me->add("bellicosity", -random( (int)me->query_kar() * 10));
	if ((int)me->query("bellicosity") < 0 ) me->set("bellicosity", 0);
    me->add("combat_exp",-100000);
	me->add("potential", 100000);


}
  destruct(this_object());
  return 1;
}
