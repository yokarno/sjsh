#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",HIR "紫夜的工作室" NOR);
 set("long", @LONG
 这里是紫夜的工作室，里面除了台电脑，就没有其他什么东西了，
只是墙上大大小小的贴满了照片，看来都有是一个女孩子的，也许是挂
了很久了，上面的字有此看不清了，不过,每张照片都很干净的，看来
紫夜经常会把照片擦一擦的。
LONG); 
    set("no_time", 1);
    set("no_fight", 1);
    set("no_magic", 1);
    set("exits",([ 
       "shukai" : "/u/shukai/workroom.c",
       "kz" : "/d/city/kezhan.c",
       "repoo" : "/u/repoo/workroom.c",
       "wizroom" : "/d/wiz/wizroom.c",
       "33tian" : "/d/33tian/west1.c",
       "fayu" : "/u/fayu/workroom.c", 
         "xuexu" : "u/xuexu/workroom" ,]));      set("objects",([
            "/u/ziye/npc/paopao":1]));
setup();
}
