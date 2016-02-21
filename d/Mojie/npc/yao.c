// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("小妖", ({"xiao yao","xiao","yao"}));
        set("gender", "男性" );
        set("class", "mo" );
        create_family("魔界", 4, "弟子");
        set("age", 30);
        set("long", "魔界的一个吃的胖胖的小妖，正在烧火。\n");
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

void init()
{
::init();
        add_action("do_serve", "serve");
}

int do_serve(string arg)
{
        object m,mm;
        message_vision("$N向小妖问道：兄弟，开饭了吗？\n", this_player());

        if((int)this_player()->query("food") >=
(int)this_player()->max_food_capacity()*90/100 )
        return notify_fail("小妖笑道：没那，等开饭时再来吧！\n");

        if((present("bao zi", this_player())))
        return notify_fail("小妖笑道：不要拿着手里的，还看着锅里的！￥？\n");
	
	if ( present("bao zi", environment()) )
                return notify_fail("小妖笑道：那不是有一块呢嘛，吃完再说！\n");

        m=new("/d/obj/food/baozi");
        mm=new("/d/obj/food/baozi");


        m->move(this_player());
        mm->move(this_player());

        message_vision("小妖对$N笑道：饿了吧，慢点吃。\n", this_player());
return 1;
}


