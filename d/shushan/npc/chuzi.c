//shushan2 by yushu@SHXY 2000.12
inherit NPC;
void create()
{
        set_name("大厨子", ({"da chuzi", "chuzi"}));
        set("gender","男性");
	 set("class", "swordsman");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",100000);
        set("attitude","heroism");
        set("chat_chance", 10);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("unarmed", 80);
        set_skill("sword", 120);
        set_skill("literate", 120);
 	 set("max_force", 200);
	 set("force", 200);
	 set("force_factor", 10);
        set("max_kee", 700);
        set("max_gin", 400);
        set("max_sen", 500);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver", 40);
}

void init()
{
::init();
        add_action("do_yao", "yao");
}

int do_yao(string arg)
{
        object m,mm;
        message_vision("$N向大厨子问道：师傅，开饭了吗？\n", this_player());

        if((int)this_player()->query("food") >=
             (int)this_player()->max_food_capacity()*90/100 )
        return notify_fail("厨子笑道：还没做好！\n");

        if((present("gongbao jiding", this_player())))
        return notify_fail("大厨子笑道：不要拿着手里的，还看着锅里的!\n");
	
	 if ( present("gongbao jiding", environment()) )
         return notify_fail("大厨子笑道：那不是有一盘嘛，吃完再说！\n");

        m=new("d/obj/food/dishes/dish10");
        mm=new("d/obj/food/dishes/dish10");


        m->move(this_player());
        mm->move(this_player());
             
        command("hoho");
        message_vision("大厨子对$N笑道：饿了吧，慢点吃！！\n", this_player());
        return 1;
}

 

�