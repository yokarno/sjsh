// 神话世界·西游记·版本(世纪)
 
// by jing 2000.7.14

inherit NPC;

void create()
{
  set_name("钱百万", ({"qian baiwan", "qian", "baiwan"}));
  set("gender", "男性");
  set("combat_exp", 80000);
  set("age", 48);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);

  setup();
  carry_object("/d/obj/cloth/changpao.c")->wear();
}

