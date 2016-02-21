#include <ansi.h>

inherit ITEM;

int do_wear(string);
void create()
{
  set_name(HIG "银牌" NOR, ({"yin pai", "pai"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "块");
    set("long", "奖给在水陆大会得第二的玩家的。\n");
    set("value", 5000);
    set("no_sell", 1);
       set("no_drop", 1);
       set("no_put", 1);
       set("no_get", 1);
  }
  
  setup();
}

void init()
{
        add_action("do_wear", "wear");
}

int do_wear(string arg)
{
  object me = this_player();
    
  if (!id(arg))
    return notify_fail("你要带什么？\n");

        message_vision(HIC"$N带上一块银牌，觉得实力大增！\n"NOR, me);  
  
        me->add("potential", 20000);
        me->add("daoxing", 20000);
        me->add("combat_exp", 20000);

  destruct(this_object());
  return 1;
}

