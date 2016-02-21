//niang.c/2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIY"春十三娘"NOR, ({"chun shisanniang", "chun", "shisanniang","niang"}));
       set("long",
"盘丝大仙座下的大弟子。本是一只蜘蛛精,随盘丝大仙修成正果,因帮助孙悟空盗取盘丝洞至宝月光宝合而
与其师妹白晶晶势成水火。很多年之后,她有个绰号叫做桃花娘子。\n");
       set("title", HIM"桃花娘子"NOR);
       set("gender", "女性");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 22);
	set("int", 30);
       set("max_kee", 2900);
//       set("max_gin", 2600);
       set("max_sen", 2800);
       set("force", 4800);
       set("max_force", 2800);
       set("force_factor", 100);
       set("max_mana", 2000);
       set("mana", 3600);
       set("mana_factor", 100);
       set("combat_exp", 1000000);
       set("daoxing", 1200000);
        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 150);
       set_skill("unarmed", 150);
       set_skill("dodge", 150);
       set_skill("force", 150);
       set_skill("parry", 150);
       set_skill("sword", 150);
       set_skill("spells", 150);
       set_skill("whip", 150);
   set_skill("pansi-dafa", 150);
   set_skill("lanhua-shou", 150);
   set_skill("jiuyin-xinjing", 150);
   set_skill("qingxia-jian", 150);
   set_skill("yueying-wubu", 150);
   set_skill("yinsuo-jinling", 150);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "qingxia-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
//   set("chat_chance_combat", 50);
   set("chat_chance",5);
    set("chat_msg", ({
        HIG"春十三娘轻声告诉你:桃花过处，寸草不生！\n"NOR,
        HIG"春十三娘轻声告诉你:我以为在这世界上有一种人是不会有忌妒心的,因为她太骄傲了。在我出道的时候,我认识一个人,他叫孙
悟空，他喜欢在东边出没，他后来有个绰号叫齐天大圣。我认识他的那年，盘丝洞的桃花开得很美。\n"HIC,
        HIG"春十三娘轻声告诉你:我叫春三十娘,我的职业是替人解决麻烦,就是帮助别人杀人！\n"NOR,
		HIG"春十三娘轻声告诉你:自从离开盘丝洞之后，我去了这个沙漠。我很想知道沙漠这边有什么，走过来发现其实什么也没有，除了
沙漠还是沙漠。我于是开始了另一种生活。在这种生活中，只有仇恨，只有杀人和被杀！\n"NOR,
		HIG"春十三娘轻声告诉你:其实醉生梦死只不过是一坛清水，你越想知道自己是不是已经忘记的时候，你反而记得越清楚。\n"NOR,
		HIG"春十三娘轻声告诉你:那个人走的当天一直在下雨。每次下雨，我就会想起他，我一直不相信自己会想他。\n"NOR,
        }));

create_family("盘丝洞", 2, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/obj/weapon/whip/jueqingwhip")->wield();
	carry_object("/d/pansi/obj/qin");
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们盘丝洞只收女徒，这位" +
RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return;}
		 if ( !ob->query_temp("denied_by_bai")){
          command("shake");
        command("say 你我无缘，这位" +
RANK_D->query_respect(ob) + "还是请教别人去吧。\n");
        return;
}
		else
         {
	  command(":D");
	  command("say 好！" + RANK_D->query_respect(ob) + "投入我的门下，包你吃香的，喝辣的！\n");
	  command("recruit " + ob->query("id") );
          ob->set("title", "盘丝洞桃花娘子座下弟子");
          ob->set("class", "yaomo");

     }

}



