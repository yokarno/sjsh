inherit "/std/city.c";

void create ()
{
reload("长安");
set ("short", "长安城");
set ("long", @LONG

这是一座古老的城市。
LONG);

  set("exits", ([
  "down" : __DIR__"jiuguan1",
  "up" : "/d/club/clubbar",
]));
  set("no_clean_up", 1);
  set("outdoor", 1);
  setup();
}

int clean_up()
{
      return 0;
}

