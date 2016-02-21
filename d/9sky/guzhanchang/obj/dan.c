// lingzhi.c 千年朱果
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"云南白药"NOR, ({"bai yao", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("long", "这是一包武林人士梦寐以求的云南白药，据说吃一棵可得3w潜能。\n");
                set("value", 10000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        this_player()->add("potential", 30000);
        message_vision("$N吃下一包云南白药，只觉得自己变利害了一些 !\n", this_player());
        destruct(this_object());
        return 1;
}


