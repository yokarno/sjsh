// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("妖兵", ({"yaobing","bing"}));
        set("gender", "男性" );
        set("class", "mo" );
        create_family("魔界", 4, "弟子");
        set("age", 30);
        set("long", "魔界的士兵。\n");
        set("combat_exp", 300000);
        set("daoxing", 300000);
        set("max_mana", 1000);
        set("max_force", 1000);
        set_skill("dodge",100);
        set_skill("moshenbu",100);
        set_skill("shifo-zhi",100);
        set_skill("unarmed",100);
        map_skill("dodge","moshenbu");              
        map_skill("unarmed","shifo-zhi");              

        set("attitude", "peaceful");
        setup();
}

