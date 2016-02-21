#include <armor.h>

inherit BOOTS;

void create()
{
  set_name( "六气飞靴", ({ "liouqi feixue", "feixue","flyxue", "xue" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "双");
    set("long", "这是六重天神的专用装备。\n");
    set("value", 0);
    set("material", "boots");
    set("armor_prop/dodge", 30);
  }
  setup();
}
