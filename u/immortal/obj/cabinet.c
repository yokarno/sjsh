inherit ITEM;

void create()
{
        set_name("药柜", ({ "cabinet" }) );
        set_weight(500000);
        set_max_encumbrance(40000);
        if( clonep() ) {
                object a,b,c,d,e;
                  seteuid(getuid());
               if(a=new("/u/immortal/obj/wudiguo"))
                  a->move(this_object());

                  seteuid(getuid());
               if(b=new("/u/immortal/obj/renshen-guo"))
                  b->move(this_object());

                  seteuid(getuid());
               if(c=new("/u/immortal/obj/huanyang"))
                  c->move(this_object());

                  seteuid(getuid());
               if(d=new("/u/immortal/obj/huanhun"))
                  d->move(this_object());

                  seteuid(getuid());
               if(e=new("/u/immortal/obj/shengzhu"))
                  e->move(this_object());
                set_default_object(__FILE__);
        } else {
                set("unit", "个");
                set("long", "这是一口放丹药的架子，上面摆了一些珍贵的丹药。\n");
                set("value", 0);
        }
}

int is_container() { return 1; }

