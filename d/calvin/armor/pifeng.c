// 七绝披风 pingfeng.c

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name("七绝披风", ({"qijue pifeng", "pifeng"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "这是七重天神的专用装备。\n");
    set("material", "leather");
    set("unit", "件");
    set("value", 0);
    set("armor_prop/armor", 80);
    set("armor_prop/spells", 50);
    set ("armor_prop/force", 50);
    set("armor_prop/parry", 50);
  }
  setup();
}
