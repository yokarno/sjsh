#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit NECK;
void create ()
{
set_name(HIC "青丝簪" NOR, ({ "fazan"}));
set_weight(100);
set("long","极细的一根簪，上面精巧的锈着游龙戏凤，还有丝丝细细的雪花 ，正暗暗盈盈的飘......"+query
("name")+"。\n");
set("unit", "枝");;
set("armor_prop/armor", 1);;
set("armor_prop/personality", 10);
set("unequip_msg","$N将"+query("name")+"轻轻卸下，清泪两行，神色黯然的轻吟‘今夕是何夕’。\n");;
set("wear_msg", "$N微微一笑，婉尔的盘起丝丝秀发，将一枝 "+query("name")+"插于发中。\n");;;
setup();;
}
