//youxiaer.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string apply_youxia(object me);
string answer_leaving(object me);
int do_yes(string arg);
void do_something();
void do_drink();



void create()
{
        set_name("游侠儿", ({ "youxia er","er","xia", "man"}) );
        set("title", HIW"江湖浪子"NOR);
        set("gender", "男性");
        set("class","youxia");
        set("age", 25);
	  set("per", 20+random(10));
        set("long","时下游侠之风甚重，连长安街头也可看到华装佩剑少年。\n\
此人为游侠中的杰出人物。武功高深莫测，喜欢行侠仗义，除强扶弱。\n\
长安城中声望极高，不少普通百姓即拜他为师。\n");
        set("combat_exp", 3500000);
        set("attitude", "heroism");
        set("str", 30);
        set("str", 50);    
        set("max_kee", 1500);
        set("max_gin", 1400);
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 15);
        create_family("江湖浪子", 2, "绿");
        set_skill("piaoxiang", 180);
        set_skill("sword", 180);
        set_skill("force", 180);
        set_skill("spells", 180);
        set_skill("lingxiyizhi", 180);
        set_skill("tianjijue", 180);
              set_skill("wuji-force", 180);
        set_skill("spells", 180);
        set_skill("literate", 150);
	 set_skill("baiyun-sword", 180);
           set_skill("unarmed", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
            map_skill("force", "wuji-force");
            map_skill("unarmed", "lingxiyizhi");
            map_skill("spells", "tianjijue");
            map_skill("dodge", "piaoxiang");
	map_skill("sword", "baiyun-sword");
        map_skill("parry", "baiyun-sword");

	set("inquiry", ([
		"name" : "我只不过是乱世中一位侠客而已，喜欢四处游荡，人称「游侠儿」，至于我的名字早已忘记了...\n",
		"here" : "哈哈...本人游遍天下美景不胜数，只为长安此处最繁华。\n",
		"游侠" : (: apply_youxia :),
		"侠客" : (: apply_youxia :),
		"剑客" : (: apply_youxia :),
		"浪子" : (: apply_youxia :),
		"leave" : (: answer_leaving :),
		"离开" : (: answer_leaving :),
	]) );
setup();

	add_money("gold", 5);
        carry_object("/d/youxia/obj/xiakesword")->wield();
        carry_object("/d/youxia/obj/bai")->wear();
              
}




void init()
{
        object ob;

        ::init();
      set("chat_chance", 10);
     add_action("do_yes", "yes");
        set("chat_msg", ({
            "游侠儿哈哈地笑了笑。\n",
(: do_drink :),
            "游侠儿上上下下打量了你几眼，眼中甚是不屑。\n",
(: do_drink :),

            "游侠儿扛着手中的"HIW"浪子游侠剑"NOR"喊道：哈哈...本人游遍天下美景不胜数，
只为长安此处最繁华。\n",
(: do_drink :),

            "游侠儿扛着手中的"HIW"浪子游侠剑"NOR"唱道：不要问我从哪里来,我的故乡在远方！\n",
(: do_drink :),

            "游侠儿扛着手中的"HIW"浪子游侠剑"NOR"念道：我只不过是乱世中一位侠客而已，喜欢四处游荡。\n",
(: do_drink :),

            "游侠儿扛着手中的"HIW"浪子游侠剑"NOR"抱怨道：不要以为我只会除强扶弱，吴刚的斧子掉了，都是我找回来的！\n",
(: do_drink :),

            "游侠儿扛着手中的"HIW"浪子游侠剑"NOR"吆喝道：身为一名侠客,为人处事一定要行侠仗义！\n",
(: do_drink :),

            (: random_move :),
            (: random_move :),
            (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
"游侠儿哈哈地笑了笑。\n",
(: do_drink :),
            "游侠儿上上下下打量了你几眼，眼中甚是不屑。\n",
(: do_drink :),

            "游侠儿扛着手中的"HIW"浪子游侠剑"NOR"喊道：哈哈...本人游遍天下美景不胜数，
只为长安此处最繁华。\n",
(: do_drink :),

            "游侠儿扛着手中的"HIW"浪子游侠剑"NOR"唱道：不要问我从哪里来,我的故乡在远方！\n",
(: do_drink :),

            "游侠儿扛着手中的"HIW"浪子游侠剑"NOR"念道：我只不过是乱世中一位侠客而已，喜欢四处游荡。\n",
(: do_drink :),

            "游侠儿扛着手中的"HIW"浪子游侠剑"NOR"抱怨道：不要以为我只会除强扶弱，吴刚的斧子掉了，都是我找回来的！\n",
(: do_drink :),

            "游侠儿扛着手中的"HIW"浪子游侠剑"NOR"吆喝道：身为一名侠客,为人处事一定要行侠仗义！\n",
(: do_drink :),

            (: random_move :),
            (: random_move :),
            (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),       
        }) );
}

void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop "+(string)ob->query("id"));
    }
    else {
        command("sigh");
        command("say 听说长安的桂花酒远近闻名，真想弄来尝尝，喝它个五斤。");
    }
    return;
}


int accept_object(object who, object ob)
{	object m;
        m=new("/d/youxia/obj/qin.c");
    if ((string)ob->query("liquid/type")=="alcohol")
    {
        if ((int)ob->query("liquid/remaining") == 0)
        {
            command("shake");
            command("say 大哥，我想喝酒呀!空酒袋我可不要．．．");
            return notify_fail("好象游侠儿不是收破烂的，不要空瓶子。\n");
        }
        else
                if ( (string)ob->name()=="牛皮酒袋" )
                {
                        command ("frown");
                        command ("say 这酒还是您留着自己喝吧。");
                        return
notify_fail("好象游侠儿看不起你给他的酒。\n");
                }
                else
                {
                        command("smile");
                        command("say 多谢!");
			if ((int)who->query_temp("mark/游侠儿") < 1){
			who->set_temp("mark/游侠儿", 1 ); 
			}
                        if(present("qin", this_object())) {
			return 0;
			}
                        who->add_temp("mark/游侠儿", 1 );
                        call_out("destroy", 1, ob);
                if ((int)who->query_temp("mark/游侠儿") >= 5+random(5))
                        {
command ( "whisper " + who->query("id") + 
" 我看你也是位行侠仗义之人，也算咱们有缘，这把"HIW"留香琴"HIG"就送给你吧。"NOR"\n");
				m->move(who);
                                who->set_temp("mark/游侠儿", 0 );
				return 1;
                        }
                        return 1;
                }
        }
    }



int accept_fight(object me)

{
             me=this_player();
        message_vision("游侠儿看着$N笑了笑：本人是乱世中一位游侠,承蒙阁下赐教，小生得罪了！\n", me);
        return 1;
}



         


void do_something()

{
	command(sprintf("bet %d silver", 1+random(5)));
	if(sizeof(filter_array(all_inventory(environment(this_object())), (:userp:))))
	call_out ("do_something", 120);
       
       add_action("do_yes", "yes");	
}

string apply_youxia(object me)
{
        me=this_player();
                if( (int)me->query("age") >= 100 )
			return "岁月不饶人，" + RANK_D->query_respect(me) + "还是回家歇着吧。\n";

		message_vision("游侠儿看了$N一眼惊喜道：幻世中门派无数,$N看破世道决心作一世游侠可不是容易呀!\n", me);	
		me->set_temp("youxia_applied", 1);
		return "" + RANK_D->query_respect(me) + "果真是下了决心作一世的游侠？(yes)\n";
}


string answer_leaving(object me)
{
	me=this_player();
		if( (string)me->query("class") == "youxia" )
			return "既然拜得我门下决心一世行侠仗义，除强扶弱为何又要离开？不准!\n";
		else return "" + RANK_D->query_respect(me) + "并非我们侠客中人，何出此言。\n";
	}



int do_yes(string arg)
{
	object me;

	me=this_player();
	
	if(me->query_temp("youxia_applied")) 
	{
		message_vision("$N答道：我都想清楚了！我愿作一世侠客,准备着为侠客事业而奋斗!\n\n", me);
		message_vision("游侠儿拍了拍$N的头道：好好干！身为一名侠客,为人处事一定要行侠仗义！\n", me);
		me->delete_temp("youxia_applied");
		me->set("class", "youxia");
		return 1;
	}

	return 0;
}


void attempt_apprentice(object ob)
{   ob=this_player();
   if( (string)ob->query("title")=="普通百姓") {
   if ((int)ob->query("daoxing") < 1000 ) {
     command("say 我们虽然是无门无派，但没有几年道行怎能除强扶弱，" + RANK_D->query_respect(ob) + "还是几年后再来找我吧。\n");
   return;
   }
   if ((int)ob->query_int() < 25) {
   command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你作徒弟,也很难有作为！\n");
   command("sigh");
   return;
   }
   if( (int)ob->query_skill("unarmed", 1) < 10 ) {
   command("say 这位" + RANK_D->query_respect(ob) + "对扑击格斗之技领会还不够深，还是不要勉强学我功夫！\n");
   command("sigh");
   return;
   }
        command("say 既然" + RANK_D->query_respect(ob) +
"无心加入任何门派，今日起本侠收你为弟子，日后一定要除强扶弱。\n");
        command("recruit " + ob->query("id") );
        message("system", HIY"普通百姓"+this_player()->name()+"无心加入任何门派,成为一世游侠。\n"NOR,users());
	return;
   }
        command("shake");
        command("say " + RANK_D->query_respect(ob) + "既然已经派入他门,应去斩妖除魔,除强扶弱之事交与我们就行了！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youxia");
                ob->set("title", HIW"游 侠"NOR);
}

