inherit NPC;
string expell_me(object me);
void create()
{
  set_name("香香", ({"xiang xiang", "xiang", "fox"}));
  set("gender", "女性");
  set("age", 18);
  set("long",
"她长的美艳无比，却媚而不俗——半点也看不出是狐而不是人。\n"
"因为生来的带的一股香气，使她有别于同类，所以一直很孤独。\n"
"所以这才找了这么一个省事的差事……\n");
set("title", "古墓倩狐");
set("per", 40);
set("int", 40);
set("cor",40);
set("combat_exp",400000);
  set_skill("force",120);
  set_skill("parry",120);
  set_skill("dodge",120);
  set_skill("literate",120);
  set_skill("needle",120);
  set_skill("spells",120);
  set_skill("xuanhu-xinfa",120);
  set_skill("tianyi-zhen",120);
  set_skill("huxing-step",120);
  set_skill("xuanhu-shentong",120);
  map_skill("force","xuanhu-xinfa");
  map_skill("needle","tianyi-zhen");
  map_skill("dodge","huxing-step");
  map_skill("spells","xuanhu-shentong");
  set("attitude", "heroic");
create_family("轩辕古墓", 2, "弟子");

  set("inquiry", ([
                  "叛门": (: expell_me :),
                   "leave": (: expell_me :),
                ]) );
  setup();
        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/clone/weapon/needle1")->wield();
}
string expell_me(object me)
{
  me=this_player();
 if((string)me->query("family/family_name")=="轩辕古墓")

  {
      me->set_temp("xuanyuan/betray", 1);
     return ("要走？咳……你可想好了——会让你受不了的。走吗？(zou)\n");
}
  return ("你不是我们的人吧？你要走就走好了——\n");
}
void init()
{
    add_action("do_accept", "zou");
}
void do_accept()
{
    object me=this_player();
if(!me-query_temp("xuanyuan/betray"))
message_vision("$N道：你走什么走？\n",this_object());
    message_vision("$N道：不错，我整天在这儿，鼻子都熏坏了！\n", me);
    me->add("betray/count", 1);
    me->add("betray/xuanyuan", 1);
    me->set("combat_exp", me->query("combat_exp")*95/100);
    me->delete("family");
    me->set("faith",0);
    me->delete("class");
    me->set("title", "普通百姓");
    me->save();
}
