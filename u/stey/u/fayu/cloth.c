#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit F_AUTOLOAD;  
inherit NECK;
void create()
  {
     set_name(blue"小晶莹的衣服"NOR, ({ "yi fu" ,"cloth" }) );
set_weight(100);
set("long","小晶莹的衣服,是妈妈做的哦!\n");
set("value", 0);
      set("material", "cloth");
set("no_drop", "就一件,不能扔啊\n");
set("unit", "件");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 5);
     setup();
  }
int query_autoload() { return 1; }
