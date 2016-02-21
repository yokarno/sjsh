
inherit F_VENDOR_SALE;

void create()
{
    reload("milinshenyi");
   set_name("密林神医", ({"milin shenyi","milin","shenyi"}));
       	set("gender", "男性");
        set("combat_exp", 10000);
       	set("age", 26);
    set("title", "老板");
       	set("per", 14);
       	set("attitude", "friendly");
       	set("shen_type", 1);
	set_skill("dodge", 30);
	set_skill("parry", 30);
       	set_skill("unarmed", 30);
        set("vendor_goods", ([
    "yao": "/d/obj/drug/jinchuang",
      "dan": "/d/obj/drug/hunyuandan",
       "yanlei": "/d/obj/drug/yanlei",
        ]) );

       	setup();
        carry_object("/d/calvin/armor/milinqingyi")->wear();
       	add_money("silver", 3);
}
void init()
{
	        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say(name()+ "笑咪咪地说道：这位" +
RANK_D->query_respect(ob)
              + "，进来看看，都是上等的好东西。\n");
                        break;
        }
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n忽然从门外冲进来个巡逻官兵，对$N大喊一声“干什么？想杀人谋财么！\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}

