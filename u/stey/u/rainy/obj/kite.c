#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit NECK;
void create ()
{
set_name(HIC "纸鸢" NOR, ({ "kite"}));
set_weight(100);
set("long","丝质的蝴蝶风筝,轻盈的似乎没有了重量."+query("name")+"。\n");;
set("unit", "只");;
set("armor_prop/armor", 1);
set("armor_prop/personality", 10);;
set("wear_msg","$N雀跃着一路奔跑,将手里的线越放越长,但见"+query("name")+"在空中快乐的飞舞着。\n");;
set("unequip_msg", "$N擦了擦额上的汗珠,一寸寸的收起丝线,也收起眷恋天空自由气息的"+query("name")+"。\n");;;;
setup();;
};
