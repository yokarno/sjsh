#include <ansi.h>
#include <armor.h>

inherit BOOTS;


void create()
{
        set_name(HIW"泰山独脚鞋——左"NOR,({ "left shoe", "xie","shoes" }) );
        set_weight(1000);
                set("unit", "只");
                set("value", 0);
                set("material", "cloth");
        set("armor_prop/armor", 10 );
        set("armor_prop/dodge", 15 );
        setup();
}

void init()
{
   add_action("do_he", "he");
}

int do_he()
{
     object me,ob, obj, shoes;
     me = this_player();
     ob = this_object();
     obj = present("right shoe", me);
     if(!objectp(obj))
           return notify_fail("一只鞋怎么合？\n");
     if((int)me->query("force") < 500)
                return notify_fail("你内力不够！\n");
     me->add("force", -100);
     message_vision(HIY"\n合体完毕。\n"NOR, me);
     destruct(obj);   
     shoes = new("/u/shukai/shoes")->move(me, 1);     
     destruct(ob);
     return 1;
}
