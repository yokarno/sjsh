// created 17/3/2001 by xuexu
#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit NECK;
void create ()
{
set_name(HIW "雪花" NOR, ({ "xuehua"}));
set_weight(100);
set("long","晶晶亮的"+query("name")+"。\n");
set("unit", "朵");
set("armor_prop/armor", 1);
set("armor_prop/personality", 2);
set("unequip_msg","$N将"+query("name")+"轻轻地抚摩了几下，雪花化做了美丽的水珠……。\n");
set("wear_msg", "$N戴上"+query("name")+"，雪花如同美丽的水晶在身上闪耀着晶净的光芒。\n");
setup();
}
