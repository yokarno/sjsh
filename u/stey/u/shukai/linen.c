// linen.c

#include <armor.h>

inherit CLOTH;

void init();
void shu();

void create()
{
	set_name("粗布衣", ({ "linen" }) );
set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 0);
set("armor_prop/armor", 1);

	}
	setup();
}

void init()
{
        add_action("do_shu", "shu");
}

int do_shu(string arg){
        object ob,me;
        int skill;
        me=this_player();
    skill = me->query_skill("wuxiangforce",1);
        if( skill > 250 ) {
                skill=250;
        }
        if( !this_object()->id(arg) ) return 0;
        if( (int)me->query_skill("wuxiangforce", 1) < 100 )     
                return notify_fail("你的内功修为不够。\n");
        ob=new("/u/shukai/qimeigun");
        ob->move(me);
        message_vision("$N脱下衣服，在水中用力搅来搅去，居然拧成了一根布棍。\n", me);
        destruct(this_object());
        return 1;               
}
