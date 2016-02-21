// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
set_name("扫地僧", ({
		"saodi seng",
		"saodi",
		"seng",
	}));
        set("gender", "男性" );
        create_family("少林寺", 16, "弟子");
        set("age", 13);
        set("title", HIG"少林寺"NOR);
set("long",
		"这是一位专职负责塔楼清埽工作的寺内杂役僧人。\n"
	);
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_kee", 150);
        set("max_gin", 150);
        set("max_sen", 150);
        setup();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
	&& !this_player()->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "扫地僧喃喃自语：这位" + RANK_D->query_respect(ob) +
"，这几天也真怪，干干净净的，不知道打哪冒出许多老鼠来！\n");
}

