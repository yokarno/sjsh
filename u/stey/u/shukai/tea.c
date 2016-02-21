#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIG "清茶" NOR, ({"tea"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "一杯清茗，几片茶叶飘浮在碧绿色的水中，幽幽的热着热气。\n");;
      set("value", 120);;
       set("max_liquid", 100); 
       set("liquid_supply", 80);
        }
        set("liquid", ([
                "type": "water",
                "name": "清茶",
                "remaining": 400,
                "drunk_apply": 40,
        ]));
}
