// ī�ӽ� mozi sword.c        created 17-06-2001 ����Ʈ(piao)


#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(BLK"ī�ӽ�"NOR, ({"mozi sword","sword","mozi"}));
	set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ�Ѻ�ɫ��ľ���������������°ٽ�ǽ��м�Ʒ��\n");
                set("unit", "��");
                set("value", 40000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(130);
        setup();
}
