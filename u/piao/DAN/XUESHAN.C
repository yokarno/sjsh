// dan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"���꺮��"NOR, ({ "bing" }) );
        set("long",
HIW"��ѩɽ�����ϳ˵��鵤��ҩ��\n"NOR);
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
        ob->set_skill("force",50);
        ob->set_skill("spells",50);
        ob->set_skill("sword",50);
        ob->set_skill("parry",50);
        ob->set_skill("dodge",50);
        ob->set_skill("blade",50);
        ob->set_skill("throwing",50);
        ob->set_skill("unarmed",50);
        ob->set_skill("literate",50);
        ob->set_skill("bainiao-jian",50);
        ob->set_skill("bingpo-blade",50);
        ob->set_skill("cuixin-zhang",50);
        ob->set_skill("dengxian-dafa",50);
        ob->set_skill("ningxie-force",50);
        ob->set_skill("xiaoyaoyou",50);
write(HIW+"����һ�����꺮����ֻ����һ�����������������!��ʱ��Դ�ѩɽ���书��������\n"NOR);

        message("vision", HIW + ob->name() + 
"����һ�����꺮����ֻ����һ������������������!��ʱ���Դ�ѩɽ���书��������\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}