//cheng yaojin, updated 5/7/97, pickle

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_baishi();

void create()
{
  set_name(HIC"相乐佐之助"NOR, ({ "master xiangle", "xiangle", "zuozhizhu", "master"}));
  set("title", HIY"打架专家"NOR);
  set("gender", "男性");
  set("age", 25);
  set("str", 60);
  set("per", 20);
  set("cor", 40);
  set("cps", 35);
  set("long","
幕末时赤报队的预备队员，在队长相乐总三死于维新政府手下
后，便开始了以打架为生的浪人生涯。衣服背后绣的“恶”字
以及“斩左”的称号，让所有敌人闻风丧胆。
");
  set("combat_exp", 2500000);
  set("daoxing", 2000000);

  set_skill("unarmed", 240);
  set_skill("kongshoudao", 240);
  set_skill("force", 180);
  set_skill("guixi-force", 180);
  set_skill("dodge", 180);
  set_skill("parry", 180);
  set_skill("spells", 140);
  set_skill("renshu", 140);
  set_skill("sword", 140);
  set_skill("fengyu-piaoxiang", 180);
  map_skill("force", "guixi-force");
  map_skill("spells", "renshu");  
  map_skill("unarmed", "kongshoudao");
  map_skill("dodge", "fengyu-piaoxiang");
  set("max_sen", 2000);
  set("max_kee", 2000);
  set("force", 5000); 
  set("max_force", 2500);
  set("force_factor", 150);
  set("max_mana", 3000);
  set("mana", 1500);
  set("mana_factor", 100);
  set("inquiry", ([
	"拜师"     : (: ask_baishi :),
]) );

  create_family("剑客联盟", 2, "弟子");
  set("chat_chance", 2);
  set("chat_msg", ({ (: random_move :) }));

  setup();
  carry_object("/d/obj/cloth/zhanpao")->wear();
}


int ask_baishi()
{  
  object ob=this_player();
   if (ob->query("family/master_id")=="master xiangle" )
  {
	command("say 你已经是我弟子了，还问干什么。");
	return 1;
   }
    else
     {
   command("say 你如果能躲过我三招，我就收你为徒。你可愿意试试？(try)？");
      this_player()->add_temp("swordman/ask_zuozhizhu",1);
   return 1;
      }
}

void init()
{
    object ob;
    ::init();
        add_action("do_agree", "try");
}

int do_agree()
{
    mapping guild;
    int skee,dkee;
    object me,target;
	
	me=this_player();
	target=this_object();
	skee=me->query("kee");
     if (!me->query_temp("swordman/ask_zuozhizhu"))
       return 0;
       me->delete_temp("swordman/ask_zuozhizhu");
    if(time() - me->query("swordman/try_zuozhizhu")<72000)
   {
          command("say 我们刚打完，过两天再打。");
          return 1;
   }
  if (me->query_temp("swordman/zuozhizhu")==1 )
  {
	command("say 现在我没兴趣和你打。");
	return 1;
   }
    command("say 哈哈，有胆子！");
    me->set("swordman/try_zuozhizhu",time());
    COMBAT_D->do_attack(target, me);
    dkee=me->query("kee");
    if((dkee<skee) 
     || !present(me, environment()))
    {
	command("kick");
       command("say 你还是回去多练习练习的好。");
	return 1;
    }
    command("say 不错，再接这招看看！");
    COMBAT_D->do_attack(target, me);
    dkee=me->query("kee");
    if((dkee<skee) 
    || !present(me, environment()))
    {
	command("say 能避过我一招已算不错。");
	return 1;
    }
    command("say 看不出你打架的功夫还挺不错的！");
    COMBAT_D->do_attack(target, me);
    dkee=me->query("kee");
    if((dkee<skee) 
    || !present(me, environment()))
    {
	command("say 可惜你就差在这最后一招了。");
	return 1;
    }
    me->add_temp("swordman/zuozhizhu", 1);
    command("say 果然好身手。");
    command("say 很久没有这样痛快的打一架了，我就把空手道传授给你吧。");
     command("haha");
     command("say 好好努力。\n");
     command("recruit " + me->query("id") );
    return 1;
}

int accept_fight(object me)
{
  command("say 正好我很久没活动筋骨了。");
  return 1;
}

void attempt_apprentice(object me)
{
  if (me->query_temp("swordman/zuozhizhu")!=1)
  {
   command("say 我的空手道可不随便传给别人。");
   return 0;
  }
  command("haha");
  command("say 好好努力。\n");
  command("recruit " + me->query("id") );
    me->delete_temp("swordman/zuozhizhu");
  return;
}

int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
  ob->set("class", "swordman");
}
�
