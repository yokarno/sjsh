#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit F_AUTOLOAD;
inherit NECK;
void create()

  {
     set_name("兰花"NOR, ({ "lanhua" ,"flower","hua" }) );
     set_weight(100);
      set("long","兰花,fayu送给repoo的礼物，它代表fayu的心
，因为只有叶子才懂的兰花.\n");
     set("value", 0);
      set("material", "flower");
     set("no_drop", "多漂亮，留着吧。\n");
     set("unit", "朵");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 5);
     setup();
  }

int query_autoload() { return 1; }
