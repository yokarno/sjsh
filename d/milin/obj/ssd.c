// 生死丹 by Calvin

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
int do_drink(string);
void init();

void init()
{
    if(this_player()==environment())
add_action("do_eat", "eat");
}
void create()
{
set_name(CYN"生死丹"NOR, ({"shengsi dan","dan"}));
set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
  set("long", "一颗奇异的丹药。\n");
set("unit", "颗");
 set("value", 0);
        }
}
int do_eat(string arg)
{
  object me = this_player();
if (arg!="dan") return 0;
                this_player()->set("potential", this_player()->query("potential")*80/100);
         this_player()->set("office_number", this_player()->query("office_number")*101/100);
message_vision("$N把生死丹往嘴里一丢,也不知道会有什么样的后果。\n", me);
  destruct(this_object());
  return 1;
}
