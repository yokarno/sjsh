#include <ansi.h>
#include <weapon.h> 
#include <dbase.h>
inherit SWORD;
 void create()
  {
     set_name(HIW"百合"NOR, ({ "bai he" ,"flower","hua" }) );
     set_weight(100);
     set("long","一束洁白的百合,一般是在结婚时才用的，象征着百年合好。\n");
     set("value", 0);
     set("material", "flower");
     set("no_drop", "多漂亮，留着吧。\n");
     set("unit", "束");
     set("wield_msg", "$N轻轻拿出一束$n，捧在手中。\n");
     set("unequip_msg", "$N轻轻的把$n放在桌子上。\n");
     set("weapon_prop/armor", 1); 
     set("weapon_prop/per", 20);     set("weapon_prop/personality", 5);
     setup();
  }

