//药材系列-duhuo.c

#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(RED "独活" NOR, ({"du huo"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "块");
    set("long", "一块老虎的骨头。\n");
    set("value", 0);
    set("drug_type", "yandan");
   // set("yaocai_remaining", 3);
  }
  setup();
}




