#include <weapon.h>
#include <ansi.h>

inherit SWORD;
string *damage=({"gin","kee","sen"});
string *msg=({
      "你忍不住浑身打了个寒颤.\n",
        "你觉的真气的运转有些不灵活了.\n",
      "四周的空气一下子变得冰冷刺骨.\n",
      "你受了寒气的侵袭,精神有些萎靡.\n",
      "你冷得不断发抖.\n",
      "你的神志有些迷糊了.\n",
      "你觉得自己快被冻僵了.\n",
      });
void create()
{
        set_name(HIG"冰魄寒光剑"NOR, ({ "ice sword","sword","jian"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIG"这是用念青唐古拉山深埋在玄冰中的美玉制成的。\n"NOR);
                set("material", "stone");
        }
        init_sword(60);
       setup();
}
int init()
{
   add_action("do_wear","wield");
   add_action("do_remove","unwield");
}
int do_wear(string arg)
{
   string str,name;
     if (arg!="ice sword"&&arg!="sword"&&arg!="jian")
                  return 0;
    name=this_object()->query("name");
          str="$N从腰畔的剑匣中取出一把晶莹剔透的"+name+"\n";
  this_object()->set("wield_msg",str);
    remove_call_out("cool");
    call_out("cool",1,this_object());
    return 0;
}
int do_remove(string arg)
{
   string str,name;
     if (arg!="ice sword"&&arg!="sword"&&arg!="jian")
                  return 0;
    name=this_object()->query("name");
    str="$N一反手,将"+name+"插入腰间的剑匣.\n";
    this_object()->set("unwield_msg",str);
  remove_call_out("cool");
   return 0;
}
void cool(object ob)
{
   object *inv;
   int i;
   object me=this_player();
   inv=all_inventory(environment(me));
if (!sizeof(inv)) return;
message_vision("$N身上的$n发出刺骨的寒冷\n",this_player(),this_object());
for (i=0;i<sizeof(inv);i++)
    {         if (living(inv[i]))        {
              inv[i]->receive_damage(damage[random(sizeof(damage))],5+random(10));
              tell_object(inv[i],msg[random(sizeof(msg))]);
                          }
    }
call_out("cool",5+random(10),this_object());
 return;
}

