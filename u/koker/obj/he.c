#include <ansi.h>
#include <dbase.h>


void create()
{
	set_name("箱子", ({ "box" }) );
	set("long",
			"这是一个黑呼呼的箱子，你可以打开它(open box)。\n" );
	set_weight(5000000);
	if( clonep() )
        set_default_object(__FILE__);
    else {
	set("unit", "个");
	set("value", 0);
        set("no_get",1);
     }
}

void init()
{
   add_action("do_combine", "combine");
   add_action("do_put","put");
}

int do_put(string arg)
{
    string target, item;
    object dest, *inv,me=this_player();

    if(!arg) return 0;

    if( sscanf(arg, "%s in %s", item, target)!=3)
           return 0;

    dest = present(target, me);
    if (dest!=this_object()) return 0;

    inv = all_inventory(dest);
    if (inv && sizeof(inv)) {
       write("铁盒里已经有东西了。\n");
       return 1;
    }
    return 0;
}

