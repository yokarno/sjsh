#include <armor.h>

#include <ansi.h>
inherit HEAD;

void create()
{
  set_name(HIM"五域奇盔"NOR, ({ "wuyu qikui", "qikui", "kui" }) );
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顶");
    set("long","这是五重天神专用的装备。\n");
    set("value", 0);
    set("material", "cloth");
    set("armor_prop/armor", 45);
    set("armor_prop/personality", 1);
  }
  setup();
}
