#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
set_name( HIW"水晶鞋"NOR, ({ "shoes", "boot" }) );
set_weight(1000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "双");
set("long", "雪白色的水晶鞋，据说是灰姑娘所穿过的。\n");
set("value", 140);
set("material", "boots");
set("armor_prop/dodge", 200);
}
setup();
}
