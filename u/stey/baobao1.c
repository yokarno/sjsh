//奖励npc
inherit F_VENDOR_SALE;


//inherit NPC;

#include <ansi.h>
int give_wx();
int give_wx2();
int answer_me();

void create()
{
         set_name(HIC"玉宝宝"NOR, ({"baobao"}));
   set ("long", @LONG
他是在这里负责给大家发武学奖励的可爱的玉宝宝。（ask baobao about 奖励）
LONG);
           set("gender", "男性");
        set("title",HIY"活泼可爱的"NOR);
        set("age", 28);
        set("per", 40);
        set("attitude", "peaceful");
        set("vendor_goods", ([ 
//                "ling":    "/d/obj/stey/ling.c",
                "whip":    "/d/obj/stey/yaowhip1.c",
                "hammer":    "/d/obj/stey/tianhammer.c",
               "sword":    "/d/obj/stey/sttt.c",
                "fork":    "/d/obj/stey/shenfork.c",
                "spear":    "/d/obj/stey/shenspear.c",
                "stick":    "/d/obj/stey/tianbang.c",
               "mace":    "/d/obj/stey/goldjian.c",
                "qin":    "/d/obj/stey/moqin.c",
                "blade":    "/d/obj/stey/guiblade.c",
                "staff":    "/d/obj/stey/shenstaff.c", 
                "spellsbook":    "/d/obj/book/mihou-book.c",   
                "parrybook":    "/d/obj/book/parrybook2",
                "renshenguo":    "/d/obj/drug/renshen-guo1",
                "forcebook":    "/d/obj/book/forcebook2",
        ]) );
        set("inquiry", ([
            "奖励"    :(:give_wx:),
            "武学奖励"    :(:give_wx:),
            "jiangli"    :(:give_wx:),
            "150万"    :(:give_wx2:),
   ]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}
int answer_me()
{
        command("say 小心我扁你！嘿嘿 。\n");
        return 1;
}
int give_wx()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say 什么小猫小狗也来要礼物?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 500000 ){
                command("hammer "+who->query("id") );
                command("say 你再努力努力，很快可以拿奖励的。");
                command("addoil "+who->query("id") );
                return 1;
         }
         if (this_player()->query("jjj") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 奖励只有一份！领过就不给了！\n");
        return 1;
        }
        who->add("potential",50000);
        who->add("balance",5000000);
        who->add("daoxing",50000);
        who->set("jjj",1);
message_vision("$N对着$n神秘的笑了笑，$n觉得身体发生剧烈的变化，顿时晕倒在地。\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
               你的道行增加了五十年!\n 
               你现在存款增加了500gold。\n");
          command("chat 恭喜恭喜，"+who->query("name")+"武学到了50万，给予奖励！\n");
        return 1;
}
int give_wx2()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say 什么小猫小狗也来要礼物?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 1500000 ){
                command("hammer "+who->query("id") );
                command("say 你再努力努力，很快可以拿奖励的。");
                command("addoil "+who->query("id") );
                return 1;
         }
         if (who->query("combat_exp") > 1900000 ){
                command("hammer "+who->query("id") );
                command("say 你都这么厉害，还需要吗？贪心！。");
                command("kick "+who->query("id") );
                return 1;
         }
         if (this_player()->query("jjjj") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 奖励只有一份！领过就不给了！\n");
        return 1;
        }
        who->add("potential",80000);
        who->add("balance",5000000);
        who->add("daoxing",100000);
        who->set("jjjj",1);
message_vision("$N对着$n神秘的笑了笑，$n觉得身体发生剧烈的变化，顿时晕倒在地。\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
               你的道行增加了一百年!\n 
               你现在存款增加了500gold。\n");
          command("chat 恭喜恭喜，"+who->query("name")+"武学到了150万，给予奖励！\n");
        return 1;
}
/*
void init()
{
     call_out("greeting", 1, this_player());
      ::init();
   add_action("do_vendor_list", "list");
} 
*/
void init()                            
{                                      
// 	call_out("greeting", 1, this_player());
//   	::init();
        add_action("do_vendor_list", "list");   	
        add_action("do_fight", "fight");     
        add_action("do_kill", "kill");       
        add_action("do_cast", "cast");       
        add_action("do_bian","bian");        
        add_action("do_cast", "perform");                           
        add_action("do_steal", "steal");       

}                                            
                                             
int do_kill(string arg)                                                       
{                                                                             
        object who = this_player();                                           
        object me = this_object();                                            
                                                                              
        if(!arg || present(arg,environment(me))!=me) return 0;                
                                                                              
        message_vision("$N对$n威胁道：你敢杀我，不想混了！\n", me, who);    
        return 1;                                                             
}

int do_bian(string arg)                                                                                                                              
{                                                                        
        object who = this_player();                                      
        object me = this_object();                                       
                                                                         
        if(!arg || present(arg,environment(me))!=me) return 0;           
                                                                         
        message_vision("$N嘿嘿奸笑了几声，刁穷小技，呸！\n", me);
        return 1;                                                        
}
                       
int do_cast(string arg)                                                                                                                                                         
{                                                                                                      
        object who = this_player();                                                                    
        object me = this_object(); 
//         if(!arg || present(arg,environment(me))!=me) return 0;                                                                      
        message_vision("$N对$n威胁道：你敢杀巫师，不想混了！\n", me, who);                             
        return 1;                                                                                      
}
int do_steal(string arg)
{
  object who = this_player();
  object me=this_object();

  //if(!arg || present(arg,environment(me))!=me) return 0;

  message_vision ("$N突然对$n笑道：都是同道中人，何必呢？\n",me,who);
  message_vision ("$N发现事情暴露，吓得将手缩了回去。\n",who);
  return 1;
}
                                                                             
                                                                                                                                                                                       
int do_fight(string arg)                                                                                                            
{                                                                                                                                   
        object who = this_player();                                                                                                 
        object me = this_object();                                                                                                  
                                                                                                                                    
        if(!arg || present(arg,environment(me))!=me) return 0;                                                                      
                                                                                                                                    
        message_vision("$N对$n摇了摇头：你不是我对手，滚！\n", me, who);                                                      
        return 1;                                                                                                                   
}                 
void die()
{
  if (environment())
    message("sound", "\n\n玉宝宝哈哈大笑一声，我还会再回来的！\n\n", environment());

  set("eff_kee", 1000);
  set("eff_gin", 1000);
  set("eff_sen", 1000);
  set("kee", 1000);
  set("gin", 1000);
  set("sen", 1000);
  set("force", 1000);
  set("mana", 1000);
}

void unconcious()
{
  die ();
}
