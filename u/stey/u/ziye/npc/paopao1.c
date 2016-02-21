#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIW"汽水泡泡"NOR,({"pao pao"}));
  set("title",HIR"紫夜的小美人"NOR);
  set("gender","女性");
  set("per",40);
  set("age",18);
  set("max_force",5000);
  set("force",10000);
  set("max_mana",5000);
  set("mana",10000);
  set_skill("dodge",700);
  set_skill("moondance",700);
  map_skill("dodge","moondance");
  set("combat_exp",50);
  set("daoxing",5000000);
  set("inquiry",([
       "name": "我叫汽水泡泡，晶晶亮的汽水泡泡。\n",
       "here":"这里是紫夜的工作室呀。\n",
       "ziye":"他是想天天陪着我啦，可是他最近好忙的，没时间陪我。inn。\n",
       "love":"我知道紫夜他爱我，可是我。。。。。\n",
       "photo":"嘻嘻，那都是我的照片啦\n",
        ]));
    setup();
   carry_object("d/moon/obj/luoyi")->wear();
   carry_object("d/ourhome/obj/shoes")->wear();
}
 
void die()
{
  if (environment())
    message("sound", "\n"+this_object()->query("name")+"怎么你们都欺负我呢?n\n", environment());

  set("eff_kee", 2000);
  set("eff_gin", 2000);
  set("eff_sen", 2000);
  set("kee", 2000);
  set("gin", 2000);
  set("sen", 2000);
  set("force", 2000);
  set("mana", 2000);
}
void unconcious()
{
  die();
}

void init()
{
  object ob;
  ::init();
  if( interactive(ob= this_player()))
    { remove_call_out("greeting");
      call_out("greeting", 1, ob);
    }
 }

void greeting (object ob)
 {
  if( !ob || environment(ob) != environment() ) return;
     {if(ob->query("id") == "shukai")
             say( HIR"警报！警报！！疯子来了！\n
                            警报！！警报！！！疯子来了！！！\n"NOR);
     else
             say(HIW"汽水泡泡"NOR HIY"赶忙说到原来是"+ob->query("name")+"来了，快请进，快请进！！\n"NOR);
     }
 }

