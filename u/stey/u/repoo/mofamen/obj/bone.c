//copy from bone by repoo

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIW"龙骨"NOR, ({"long gu","gu"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一堆骨龙身上骨头。\n");
    set("unit", "堆");
    set("material", "bone");
  }
  setup();
}
int init()
{
        add_action("do_zhengli","zhengli");
        return 1;
}
int do_zhengli()
{
        object who = this_player();
        object gujian;

        if(who->is_fighting())
           return notify_fail("打完了再说。\n");
        if(who->is_busy())
           return notify_fail("你正忙着呢!\n");
{
message_vision(WHT"\n$N把龙骨整理了一下，只见白光一闪，所有龙骨不由自主的合在一起，形成一把骨龙之剑。\n"NOR,who);
 message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+who->query("name")+"拿到"+HIW"骨龙"+HIM"之剑"NOR+YEL"了！\n\n"+NOR,users() );

        gujian = new("/u/repoo/mofamen/obj/gujian");
        gujian->move(who);
        destruct(this_object());
        return 1;
}
}
