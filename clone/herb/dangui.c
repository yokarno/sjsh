// dangui.c

#include "herb.h"

void create()
{
	set_name(HIG "����" NOR, ({ "danggui", "herb_dangui" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("base_unit", "��");
		set("base_value", 10000);
        	set("base_weight", 70);
	}
	setup();
}
