#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
set_name(HIB"梦舞靴"NOR, ({"meng wuxue", "shoes"}) );
set("long", "水蓝色的舞靴，装上它会有轻舞的欲望，演绎一番绝伦的梦之幻。n");
set_weight(0);
set("wear_msg", HIB"$N将蓝色的舞靴套在脚上，仔细的系好丝带，舞动着一曲“梦的衣裳”......\n"NOR);
set("unequip_msg",HIB"$N拂掉靴上的灰尘，小心的捧在手中，不由的思念起心中的人儿来。\n"NOR);;
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "双");
set("material", "shoe");
set("armor_prop/per", 10);
set("value", 0);
set("female_only", 1);
}
setup();
}
