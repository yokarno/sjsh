#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit NECK;
void create ()
{
set_name(MAG "紫蔷薇" NOR, ({ "rose"}));
set_weight(100);
set("long","粉紫色的花瓣盈着缕缕暗香，清晨的阳光下，淡淡的微笑着....."+query("name")+"。\n");;
set("unit", "朵");;
set("armor_prop/armor", 1);
set("armor_prop/personality", 10);;
set("unequip_msg","$N闻到一缕暗香，往花簇中探望，但见一朵淡紫色的"+query("name")+"含笑于花丛之中。\n");;
set("wear_msg", "$N巧笑倩兮，从腕上的青竹花篮中取出一枝滴着露水的"+query("name")+"，凑在鼻前，允一口新香。\n");;;
set("unit", "朵");;
set("armor_prop/armor", 1);
set("armor_prop/personality", 10);;
set("unequip_msg","$N闻到一缕暗香，往花簇中探望，但见一朵紫色的"+query("name")+"傲然于花丛之中。\n");;
set("wear_msg", "$N巧笑倩兮，从腕上的青竹花篮中取出一枝滴着露水的"+query("name")+"，凑在鼻前，允一口新香。\n");;;
setup();;
};
