// by snowcat oct
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name("绣锦披风", ({"xioujin pifeng", "pifeng", "cloth"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "这是一件被王母娘娘不小心丢弃的披风。\n");
    set("material", "leather");
    set("unit", "件");
    set("value", 150000);
    set("armor_prop/armor", 80);
  }
  setup();
}
