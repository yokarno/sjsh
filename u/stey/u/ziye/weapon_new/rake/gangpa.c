// rake.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit RAKE;

void create()
{
        set_name("�ְ�", ({ "gang pa", "pa","rake" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("material", "iron");
                 set("keenness", 0);
                set("long", "һ���������߳ݸְҡ�\n");
                set("wield_msg", "$N����һ��$n����ͷ�ϻ�����һȦ��\n");
        }
        init_rake(25);
        setup();
}
