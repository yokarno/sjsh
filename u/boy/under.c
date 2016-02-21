// by boy
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIW"生死擂台下"NOR);
 set ("long", "
眼前数丈高的高台就是长安赫赫有名的生死擂。这擂上打架是不伤身体，不伤气血，却可以挑
战("HIY"challenge"NOR")其他人,也可以接受他人挑战("HIY"defend"NOR")用尽生平所学杀个天翻地覆.
");
 set("exits", ([
 "south" : __DIR__"wuguan",
       ]));
  set("no_fight",1);
  set("no_magic",1);
  set("no_quit",1);
  set("no_flee",1);
  set("no_spells", 1);
  setup();
}
void init ()
{
   add_action("do_accept","defend");
}
int do_accept(string arg)
{
   string myop,tempstr;
   int j;
   object ob,me; 
   me=this_player();
   if (!arg) return notify_fail("你要跟谁切磋？\n");    
   ob = LOGIN_D->find_body(arg);
   if (!ob) return notify_fail("咦．．． 有这个人吗？\n");
   if (me->query("id")==arg) return notify_fail("想和你自己切磋?\n");
   tempstr=ob->query_temp("objectob");
   if (tempstr!=me->query("id")) return notify_fail("对方并没有向你挑战。\n");  
   if ( !present(ob,environment(me)) ) return notify_fail("向你挑战的人不在这里。\n");
   if ( ob->is_busy() ) return notify_fail("对方正忙着呢！\n"); 
   if ( sizeof(all_inventory(load_object(__DIR__"ground"))) >0 ) 
{
       j=sizeof(all_inventory(load_object(__DIR__"ground")));
       while (j>0)
{
         j=j-1;
         if (userp( all_inventory(load_object(__DIR__"ground") )[j]))
         return notify_fail("擂台上已经有人了。\n");
}
}
   message_vision("$N和$n双双纵身跃上擂台,准备比武。\n",me,ob); 
     me->set_temp("objectob",ob->query("id"));
     ob->set_temp("objectob",me->query("id"));
   me->move(__DIR__"ground");
   ob->move(__DIR__"ground");
     me->start_busy(2);
     ob->start_busy(2);
   me->set_temp("statusbef/kee",(int)me->query("kee"));
   me->set_temp("statusbef/eff_kee",(int)me->query("eff_kee"));
   me->set_temp("statusbef/sen",(int)me->query("sen"));
   me->set_temp("statusbef/eff_sen",(int)me->query("eff_sen"));
   me->set_temp("statusbef/force",(int)me->query("force"));
   me->set_temp("statusbef/mana",(int)me->query("mana"));
   ob->set_temp("statusbef/kee",(int)ob->query("kee"));
   ob->set_temp("statusbef/sen",(int)ob->query("sen"));
   ob->set_temp("statusbef/eff_kee",(int)ob->query("eff_kee"));
   ob->set_temp("statusbef/eff_sen",(int)ob->query("eff_sen"));
   ob->set_temp("statusbef/force",(int)ob->query("force"));
   ob->set_temp("statusbef/mana",(int)ob->query("mana"));
   remove_call_out("wait_and_star");
   remove_call_out("finish_match");
   call_out("wait_and_start",2);
   return 1;
}
int wait_and_start()
{
 object fan;
  object me,ob;
  object *allinv;
  allinv=all_inventory(environment(this_player()) );
  if (sizeof(allinv)<2) return 1;
  me=allinv[0];
  ob=allinv[1];
  message_vision(HIW"$N与$n比武开始！限时五分钟。\n"NOR,me,ob);
  "/cmds/std/kill"->main(me,(string)ob->query("id"));
  "/cmds/std/kill"->main(ob,(string)me->query("id"));
   call_out("finish_match",300); 
  return 1;
}
int finish_match()
{
 object fan;
   int i,j;
  object me,ob;
   object *allinv,*playerinv;
   j=0;
   playerinv=({});
  allinv=all_inventory(load_object(__DIR__"ground"));
  if (sizeof(allinv)<2) return 1;
   i=sizeof(allinv);
   while (i>0)
{
   i=i-1;
   if (userp(allinv[i]))
{
     playerinv+=({allinv[i]});
     j=j+1;
}
}
   if (j<2) return 1;
   me=playerinv[0];
   ob=playerinv[1];
      message("channel:chat",HIC"【闲聊】范青屏(Fan qingping):结果"+me->query("name")+"与"+ob->query("name")+"大战三百回合，不分胜负，现各下场休息，有待来日再战。\n" NOR,users());
  message_vision(HIG"$N与$n大战三百回合，不分胜负，现各下场休息，有待来日再战。\n"NOR,me,ob);
  me->remove_killer(ob);
  ob->remove_killer(me);
    me->move(__DIR__"under");
  ob->move(__DIR__"under");
   me->set("kee",me->query_temp("statusbef/kee"));
   me->set("eff_kee",me->query_temp("statusbef/eff_kee"));
   me->set("sen",me->query_temp("statusbef/sen"));
   me->set("eff_sen",me->query_temp("statusbef/eff_sen"));
   me->set("force",me->query_temp("statusbef/force"));
   me->set("mana",me->query_temp("statusbef/mana"));
   ob->set("kee",ob->query_temp("statusbef/kee"));
   ob->set("sen",ob->query_temp("statusbef/sen"));
   ob->set("eff_kee",ob->query_temp("statusbef/eff_kee"));
   ob->set("eff_sen",ob->query_temp("statusbef/eff_sen"));
   ob->set("force",ob->query_temp("statusbef/force"));
   ob->set("mana",ob->query_temp("statusbef/mana"));
ob->delete_temp("objectob");
 me->set("no_move",0);
me->start_busy(0);
 ob->set("no_move",0);
ob->start_busy(0);
  return 1;
}
