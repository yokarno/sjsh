//药材

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(RED "红花" NOR, ({"hong hua","honghua","yao"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "棵");
    set("long", "可以活血化淤的好药材。\n");
    set("value", 100);
    set("drug_type", "yaodan");
  }
  setup();
}