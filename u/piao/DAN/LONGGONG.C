// dan.c 升级丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIB"碧海神龙丹"NOR, ({ "dan" }) );
        set("long",
HIB"东海龙宫中最上乘的灵丹妙药。\n"NOR);
        set("unit", "粒");
        set("weight", 5);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

        ob=this_player(); 
        ob->set_skill("dodge",50);
        ob->set_skill("force",50);
        ob->set_skill("parry",50);
        ob->set_skill("spells",50);
        ob->set_skill("unarmed",50);
        ob->set_skill("literate",50);
        ob->set_skill("fork",50);
        ob->set_skill("hammer",50);
        ob->set_skill("dragonfight",50);
        ob->set_skill("dragonforce",50);
        ob->set_skill("dragonstep",50);
        ob->set_skill("huntian-hammer",50);
        ob->set_skill("fengbo-cha",50);
        ob->set_skill("seashentong",50);
write(HIB+"你吃下一颗碧海神龙丹，只觉得一种神力融入你的体内!顿时你对东海龙宫的武功有所大悟。\n"NOR);

        message("vision", HIB + ob->name() + 
"吃下一颗碧海神龙丹，只觉得一种神力融入他的体内!顿时他对东海龙宫的武功有所大悟。\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
