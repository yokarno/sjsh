// sgzl

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

int do_install(string);
int do_uninstall(string);

string ori_long="一柄巨大而外形古老的利刃，剑柄处似乎有些机关能装(install)些暗器进去。\n";


void create()
{
        set_name("巨厥剑", ({"jujue jian","jian","sword"}));
	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",ori_long);
                set("orilong",ori_long);
                set("unit", "把");
                set("value", 500000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声从背后出一柄$n握在手中，一丝诡异之色遍及$N全身。\n");
                set("unwield_msg", "$N将手中的$n放回身后，$N的脸色也随即开朗了。\n");

                set("anqi/allow", 1);
                set("anqi/max", 100);
                set("anqi/now", 0);
        }
        init_sword(100);
        setup();
}

void init()
{                                             
        add_action("do_install", "install");
        add_action("do_uninstall", "uninstall");
}


int do_install(string arg)
  {
   object me=this_object();
   object who=this_player();
   object aq;
   int remain;

   if( !arg)  return notify_fail("你想装什么？\n");

   aq=present(arg, who);
   if (! present(arg, who)) 
        return notify_fail("你身上没有这东西。\n");
   else if( aq->query("name") == me->query("name") ) return notify_fail("装自己？\n");
   else if (aq->query("name") != "银针" && aq->query("name") != "毒针" && aq->query("name") != "孔雀翎") 
        return notify_fail("这玩艺太大了，装不进去。\n");
   else if (me->query("anqi/now") == me->query("anqi/max"))
        return notify_fail(me->query("name")+"已经装满暗器了。\n");
   else if (me->query("anqi/now") >0 && 
            me->query("anqi/type") != aq->query("name") )
        return notify_fail(me->query("name")+"不能装不同的暗器。\n");
   else  
     {
     message_vision( "$N打开"+me->query("name")+"的机关，将一"+aq->query("unit")+aq->query("name")+"装了进去。\n",who);
     who->start_busy(3);
     if (me->query("anqi/now") ==0) me->set("anqi/type",aq->query("name"));
     if (me->query("anqi/now") + aq->query_amount() > me->query("anqi/max")) 
         {
         remain=me->query("anqi/now") + aq->query_amount() - me->query("anqi/max");
         me->set("anqi/now",me->query("anqi/max"));
         me->set("long",me->query("orilong")+"里面已经装了" +chinese_number(me->query("anqi/now"))+aq->query("base_unit")+aq->query("name")+"，想拆掉用uninstall。\n");
         aq->set_amount(remain);
         }
     else 
         {
         me->set("anqi/now",me->query("anqi/now") + aq->query_amount());
         me->set("long",me->query("orilong")+"里面已经装了"
           +chinese_number(me->query("anqi/now"))+aq->query("base_unit")+aq->query("name")+"，想拆掉用uninstall。\n");
         destruct(aq);
         }
     return 1;
     }
  }

int do_uninstall(string arg)
  {
   object ob;
   object me=this_object();
   object who=this_player();

   if( !this_object()->id(arg) ) return notify_fail("你想拆什么？\n");
   else if (me->query("anqi/now") ==0) return notify_fail(me->query("name")+"里面什么也没有。\n");
   else 
     {
      if (me->query("anqi/type") =="银针") ob=new("/d/obj/weapon/throwing/yinzhen");
//      else if (me->query("anqi/type") =="孔雀翎") ob=new("/d/obj/weapon/throwing/kongqueling");
      else ob=new("/d/obj/weapon/throwing/kongqueling");
      ob->set_amount(me->query("anqi/now"));
      ob->move(who);
      me->set("long",ori_long);
      me->set("anqi/now", 0);
      message_vision("$N从"+me->query("name")+"里面拆出一"+ob->query("unit")+ob->query("name")+"。\n", who);
      who->start_busy(3);
      return 1;               
     }
  }
