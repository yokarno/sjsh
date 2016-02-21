// 礼品盒

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
     
    string *red_object=({
                      "/u/view/happy/obj/xhhd",
                      "/u/view/happy/obj/neidan",
                      "/u/view/happy/obj/gaozhi",
                      "/u/view/happy/obj/luckdog",
                      "/u/view/happy/obj/jinnang",
                      });
              

void create()
{
	set_name(HIR"礼品盒"NOR, ({"happy box", "box"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个精致的"+HIR"礼品盒，"NOR+"似乎可以打开(tearoff)。\n");
		set("unit", "个");
		set("value", "100000");
	}
}


   void init()
  { if(query("teared"))return;
    set("no_give","每个人只有一个，你都这么大方！\n");
//    set("no_get","每个人只有一个，不要这么贪心！\n");
    set("no_drop","这么珍贵的东西你也扔？！\n");
    add_action("do_open","tearoff");
  }

   

  int do_open(string arg)
  { 
      object me=this_player(),ob;
         int rand;

    if(query("teared"))              
         return 0;
    set("teared",1);
    set("value", "100");

    set("no_give",0);
//    set("no_get",0);
    set("no_drop",0);

    set("long", "一个精致的"+HIR"礼品盒，"NOR+"已经被打开了。\n");
        if(me->query("gender")=="男性")
    tell_object(me,"你迫不及待地将"+HIR+"礼品盒"NOR+"打开，\n");
        else
    tell_object(me,"你小心翼翼地将"+HIR+"礼品盒"NOR+"打开，\n");


       rand=random(sizeof(red_object)*2);

      if(rand<sizeof(red_object))
      {
           ob=new(red_object[rand]);
            if(!ob)
             tell_object(me,"结果什么也没有。\n"NOR);
            else   
             {
             if(present(ob->query("id"),me))
              { destruct(ob);
                if(present("gold card",me))
                  {
                   tell_object(me,"你的金卡加了五十两"HIY+"黄金。\n"NOR);
                    me->add("card_money",500000);
                  }
                   else
                        { ob=new("/u/view/happy/obj/goldcard");
                          ob->move(me);
                          tell_object(me,"发现了一张"+HIY"金卡"NOR+"。\n"NOR);
       			  me->add("card_money",500000);		               
                        }  
              }
               else
                 {  
                    tell_object(me,"你发现有一"+ob->query("unit")+ob->query("name")+"。\n"NOR);
                    if(ob->query("id")=="haba gou")
                        {
                          ob->set("boss_id",me->query("id"));
			  ob->set("name",me->name(1)+"的哈巴狗");
                          ob->set("mud_age",200000);
                          ob->set("gender","雄性");
                          ob->set_leader(me);
                          ob->move(environment(me));
                         }
                     else ob->move(me);
                 }
             }
        
      }
      else 
      {
      if(present("gold card",me))
                 {
                   tell_object(me,"你的金卡加了五十两"HIY+"黄金"NOR+"。\n"NOR);
                   me->add("card_money",500000);
                 }

                   else
                        { ob=new("/u/view/happy/obj/goldcard");
                          ob->move(me);
                          tell_object(me,"发现了一张"+HIY"金卡"NOR+"。\n"NOR);
                          me->add("card_money",500000);                                
                        }  
      } 
         return 1;
  }  

  
