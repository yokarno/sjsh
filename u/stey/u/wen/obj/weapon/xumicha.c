// xumicha.c
//weiwei

#include <weapon.h>

inherit FORK;

void create()
{
        set_name("须弥叉", ({ "xumi cha", "cha","fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500000);
                set("material", "iron");
                set("long", "化须弥于介子之气，转九龙于万丈之神，端的一个神兵利器。\n");
                set("wield_msg", "$N抄起一柄$n，登时须弥之气弥漫于四野。\n");
				 set("unwield_msg", "$N放下手中的$n，须弥顿收，周围的人仿佛感觉少了点什么。\n");
        }
        init_fork(125);
        setup();
}

