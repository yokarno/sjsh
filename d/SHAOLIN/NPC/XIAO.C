// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("小僧人", ({"monk"}));
        set("gender", "男性" );
	create_family("少林寺", 39, "弟子");
        set("title",HIG"少林寺"NOR);
        set("age", 30);
        set("long", "一个僧人，正在练习武艺。\n");
        set("combat_exp", 30);
        set("attitude", "peaceful");
        setup();
}

