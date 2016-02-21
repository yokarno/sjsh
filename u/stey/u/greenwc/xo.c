// jiudai.c  酒袋

inherit ITEM;
inherit F_LIQUID;

void create()
{
         set_name("人头马", ({"ren tou ma", "xo","jiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
                 set("long", "一瓶价值不扉的洋酒。\n");
                  set("unit", "瓶");
                        set("value", 100000);
                  set("max_liquid", 1500);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
                  "name": "洋酒",
		"remaining": 15,
		"drunk_apply": 5,
	]));
}
