inherit ROOM;;
#include <ansi.h>
void create ()
{
set ("short",HIM"绽放的温柔");
set ("long", @LONG

    雪白的桌上很显目的摆着一台电脑，房里飘着那首
淡淡的“最浪漫的事”。一枝火红的玫瑰懒散的斜插在
花瓶中，娇艳玉滴的欲绽还休......
    一个木制的古朴相夹在阳光中发出柔和的韵。细看，
是一张三人合影。衣青紧拥着舟儿，小澜舟从两人之间
探出小头来，脸上露出一丝狡黠的笑。不知道这小小丫
头又有什么鬼点子了,每个人脸上都荡漾着幸福的微笑.
    轻风吹过，一张纸片在空中舞动着身姿，漫漫的落
到地上。捡起来，上面是行行绢秀的正楷小字，整齐的
书写着:
        如果爱你是错的话，我不想对。
        如果对是等于没有你的话，我宁愿错。 
        如果要用一生的时间来实现诺言的话，
        我希望上天给给我一生零一天与你相守。
        如果这一世终究要与你擦肩而过，
        我努力将所有的美丽绽放在与你目光
        交集的那一刹那......
        愿时光就这样永恒，
        愿我们就这样沉醉在淀放的温柔中。


          <<Forever  miss>>
LONG);;;
set("exits",([
"up" : "/d/city/kezhan",
"room" :  "/u/yiq/love",
"sea" :  "/d/changan/mufa",
"xuexu" :  "/u/xuexu/workroom",
"fayu" :  "/u/fayu/workroom",
"ziye" :  "/u/ziye/workroom",
"east" : __DIR__"kiteroom",
]));
set("objects",([
"/u/rainy/obj/rose":1,
"/u/yiq/obj/plava":1,
"/u/rainy/npc/rain":1]));
setup();
}
