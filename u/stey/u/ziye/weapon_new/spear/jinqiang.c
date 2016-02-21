// jinqiang.c
// updated 5-30-97 pickle
//add keenness by ziye 2001/3


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(HIY "点金枪" NOR, ({ "golden spear","qiang","spear" }));
  set_weight(14000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "杆");
    set("value", 10000);
    set("keenness", 20);
    set("material", "silver");
    set("long", "此枪以黄金为头铜为杆。\n");
    set("wield_msg", "$N抄起一杆$n，顺手抖了个枪花。\n");
  }
  init_spear(60);
  setup();
}

