#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
set_name(WHT "冰魄寒光剑" NOR,({"iceword","icy"}));
  set_weight(1);
   if(clonep())
       set_default_object(__FILE__);
   else{
               set("unit", "把");
                set("value", 1);
                set("rigidity", 10);
                set("sharpness", 10);
                set("unique", 1);
                set("no_give",1);
                set("no_get",1);
                set("material", "steel");
                set("weapon_prop/dodge", 50);
                set("weapon_prop/parry", 50);
                set("treasure",1);
                set("wield_neili", 300);
                set("wield_maxneili", 700);
                set("wield_str", 22);
         set("long","一把晶莹剔透，用千年寒冰做成的剑，定力不够的多看一眼也会冷得受不了。\n");
         set("wield_msg", "忽然四周出现一阵寒气，一把洁白的"WHT"冰魄寒光剑"NOR"出现在$N手中。\n"  );
         set("unwield_msg","$N怜爱地把手中的"WHT"冰魄寒光剑"NOR"擦洗了一遍，然后手一挥，剑消失在空气中。\n" );
         set("unequip_msg","你怜爱地把手中的"WHT"冰魄寒光剑"NOR"擦洗了一遍，然后手一挥，把剑收回在剑匣里。\n" );
       }
   init_sword(200);
   setup();
}

