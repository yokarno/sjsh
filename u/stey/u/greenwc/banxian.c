inherit NPC;
int give_cola();
void create()
{
                  set_name("小半仙", ({"xiao ban xian","xian", "banxian"}));
   set ("long", @LONG

一个有名的神医，据说能“起死回生”呢！
不信你就去问问(ask)他。
LONG);
       set("gender", "男性");
               set("age", 60);
        set("per", 10);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("inquiry", ([
          "起死回生":(:give_cola:),
]));
        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
}
}
int give_cola()
{
object wan;
object who=this_player();
         if (this_player()->query("yudian/cola")=="over")
{
           message_vision("$N对着$n叹了口气。\n",this_object(),this_player());
       command("say 你病得太重，我也无能为力了！");
 return 1;
}
wan=new("/u/greenwc/wan");
  wan->move(who);
  message_vision("$N给$n一粒气血大补丸。\n",this_object(),this_player());
       command("say 这药不多了，快吃了吧！");
     who->set("yudian/cola","over");
return 1;
}
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
say(name()+"说倒：“你病得不轻啊！我帮你治治吧！”\n");
}
