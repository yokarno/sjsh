// dan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"��ζ���"NOR, ({ "dan" }) );
        set("long",
HIR"���ƶ������ϳ˵��鵤��ҩ��\n"NOR);
        set("unit", "��");
        set("weight", 5);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");

          if( living( this_player())==0) return 0;

if( living( this_player())==0) return 0;

 ob=this_player(); 
ob->add("daoxing",100000);
ob->add("combat_exp",100000);
ob->add("potential",10000);
ob->set_skill("force",100);
ob->set_skill("spells",100);
ob->set_skill("parry",100);
ob->set_skill("dodge",100);
ob->set_skill("unarmed",100);
ob->set_skill("huomoforce",100);
ob->set_skill("moshenbu",100);
ob->set_skill("moyun-shou",100);
 ob->set_skill("dali-bang",100);
ob->set_skill("huoyun-qiang",100);
ob->set_skill("pingtian-dafa",100);
ob->set_skill("wuyue-spear",100);
ob->set_skill("spear",100);
ob->set_skill("stick",100);
ob->set_skill("literate",100);
write(HIR+"�����һ����ζ��𵤣�ֻ����һ�����������������!��ʱ��Ի��ƶ����书��������\n"NOR);

        message("vision", HIR + ob->name() + 
"����һ����ζ��𵤣�ֻ����һ������������������!��ʱ���Ի��ƶ����书��������\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}