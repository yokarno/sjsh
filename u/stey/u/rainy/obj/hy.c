#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit NECK;
void create ()
{
set_name(RED "红叶" NOR, ({ "miss"}));
set_weight(100);
set("long","悠悠红叶，遥记相思之情。红叶飘飘，相思几许.....一片"+query("name")+"。\n");;
set("unit", "片");;
set("armor_prop/armor", 1);
set("armor_prop/personality", 10);;
set("wear_msg",RED"$N拿起一片红叶把玩着，不禁回想起连篇往事.....。\n");;
set("unequip_msg", RED"$N将红叶小心的夹在书中，嗅着书香，难忘桃源往事。\n");;;
set("unit", "片");;
set("armor_prop/armor", 1);
set("armor_prop/personality", 10);;
setup();;
};

