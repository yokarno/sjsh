// gangcha.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit FORK;

void create()
{
        set_name("�ֲ�", ({ "gang cha", "cha","fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
              set("keenness", 5);
                set("material", "iron");
                set("long", "һ�������ĸֲ档\n");
                set("wield_msg", "$N����һ��$n�������·����˲���⡣\n");
        }
        init_fork(25);
        setup();
}

