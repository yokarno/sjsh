// 紫静 by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name(HIB"紫静"NOR, ({"zi jing", "zi", "jing","tianshen"}));
       set("long", "逸仙香主本是火云洞门下的一名得道高尊,后来被封为逸仙香主。\n");
       set("title", HIW"逸仙香主"NOR);
       set("gender", "女性");
       set("age", 3000);
       set("int", 35+random(5));
  set("str", 45);
  set("per", 35);
  set("cor", 50);
  set("cps", 40);
  set("combat_exp", 3000000);
  set("daoxing", 3000000);

  set_skill("spear", 350);
  set_skill("force", 350);
  set_skill("dodge", 350);
  set_skill("stick", 350);
  set_skill("literate", 350);
  set_skill("dali-bang", 350);
  set_skill("huoyun-qiang", 350);
  set_skill("parry", 350);
  set_skill("unarmed", 350);
 set_skill("wuyue-spear", 350);
  set_skill("spells", 350);
  set_skill("pingtian-dafa", 350);
  set_skill("moshenbu", 350); 
  set_skill("huomoforce", 350);
  set_skill("moyun-shou", 350);

  map_skill("force", "huomoforce");
  map_skill("spells", "pingtian-dafa");
  map_skill("unarmed", "moyun-shou");
  map_skill("spear", "wuyue-spear");
  map_skill("parry", "wuyue-spear");
  map_skill("stick", "dali-bang");
  map_skill("dodge", "moshenbu");

  set("max_sen", 5000);
  set("max_kee", 5000);
set("force", 3000);
set("max_force", 3000);
set("mana",3000);
set("max_mana",3000);
set("force_factor", 100);
set("mana_factor", 100);
  set("chat_chance_combat", 100);
  set("chat_msg_combat", ({
                (: perform_action, "spear", "buhui" :),
                (: perform_action, "unarmed", "zhangxinlei" :),
  }) );

  create_family("火云洞", 1, "蓝");
  setup();

//carry_object("/d/city/obj/xjdan");
        carry_object("/d/zj/armor/wan")->wear();
           carry_object("/d/zj/weapon/huomo")->wield();
}

int accept_fight(object me)
{
  command("say 小神不喜欢打打杀杀,阁下还是放弃吧。\n");
  return 0;
}

int attempt_apprentice(object ob)
{
if ( (string)ob->query("family/family_name")=="火云洞") {
if (((int)ob->query("combat_exp") < 5000000 )) {
command("say " + RANK_D->query_respect(ob) +"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return 0;
   }

        command("haha "+ob->query("id"));
        command("say 看你的身手，象是见过我那孽畜，我传你些功夫，你去帮我把他pk到没道行！\n");
        command("recruit " + ob->query("id") );
return 0;
}
command("say " + RANK_D->query_respect(ob) +"还是再苦练几年枪法罢！\n");
       return 1;
}
/*
{  
string myname=RANK_D->query_respect(me);
 if ((int)me->query_skill("spear")< 250) 
    {
      command("say 这"+myname+"再苦练几年枪法罢！");
      return 0;
    }
  if ((int)me->query_skill("stick") < 250 )
    {
      command("say 这"+myname+"可真是 ....");
      return 0;
    }

  command("say 看你的身手，象是见过我那死对头，我传你些功夫，你去帮我把他杀到退出江湖吧！\n");
  command("recruit " + me->query("id") );
  return 1;
}
*/
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "yaomo");
      ob->set("title", "火云洞洞主");
}

