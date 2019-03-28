
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
//#define INPUT
/**
    Problem:1182 - 食物链，NOI2001
    Begin Time:4th/Mar/2012 1:00 p.m.
    End Time:4th/Mar/2012 6:47 p.m.
    Cost Time:两天多，看的别人的解题报告AC的
    Reference:http://apps.hi.baidu.com/share/detail/16059767
    测试数据：
    http://poj.org/showmessage?message_id=93058
    输出：
    上方有
    教训：
        WA一次，没搞清楚先更新父节点relation还是更新当前节点relation的关系！！！
        （在最后那条犯错误了！）
    思路：
    老子决心要写一个，关于这道题的，最详细的解题报告。
    本题思路是带权并查集，我们从最开始讲起。
    Part I  - 权值(relation)的确定。
    我们根据题意，森林中有3种动物。A吃B，B吃C，C吃A。
    我们还要使用并查集，那么，我们就以动物之间的关系来作为并查集每个节点的
    权值。
    注意，我们不知道所给的动物（题目说了，输入只给编号）所属的种类。
    所以，我们可以用动物之间“相对”的关系来确定一个并查集。
    0 - 这个节点与它的父节点是同类
    1 - 这个节点被它的父节点吃
    2 - 这个节点吃它的父节点。
    注意，这个0,1,2所代表的意义不是随便制定的，我们看题目中的要求。
    说话的时候，第一个数字（下文中，设为d）指定了后面两种动物的关系：
    1 - X与Y同类
    2 - X吃Y
    我们注意到，当 d = 1的时候，( d - 1 ) = 0，也就是我们制定的意义
                当 d = 2的时候，( d - 1 ) = 1，代表Y被X吃，也是我们指定的意义。
    所以，这个0,1,2不是随便选的
    Part II - 路径压缩，以及节点间关系确定
    确定了权值之后，我们要确定有关的操作。
    我们把所有的动物全初始化。
    struct Animal
    {
        int num; //该节点（node）的编号
        int parent; //该node的父亲
        int relation; //该node与父节点的关系，0同类，1被父节点吃，2吃父节点
    }; Animal ani[50010];
        初始化为
        For i = 0 to N do
            ani[i].num = i;
            ani[i].parent = i;
            ani[i].relation = 0 ; //自己和自己是同类
        End For
        (1)路径压缩时的节点算法
        我们设A,B,C动物集合如下：（为了以后便于举例）
        A = { 1 , 2 , 3 ,4 ,5 }
        B = { 6 , 7 , 8 ,9 ,10}
        C = { 11, 12, 13,14,15}
        假如我们已经有了一个集合，分别有3个元素
        SET1 = {1,2}，我们规定集合中第一个元素为并查集的“代表”
        假如现在有语句：
        2 2 6
        这是一句真话
        2是6的父亲
         ani[6].parent = 2;
         ani[6].relation = 1;
        那么，6和1的关系如何呢？
         ani[2].parent = 1;
         ani[2].relation = 0;
        我们可以发现6与2的关系是 1.
        通过穷举我们可以发现
        ani[now].parent = ani[ani[now].parent].parent;
        ani[now].relation = ( ani[now].relation + ani[now.parent].relation ) % 3;
        这个路径压缩算法是正确的
        关于这个路径压缩算法，还有一点需要注意的地方，我们一会再谈
        注意，根据当前节点的relation和当前节点父节点的relation推出
        当前节点与其父节点的父节点的relation这个公式十分重要！！
        它推不出来下面都理解不了！！自己用穷举法推一下：
        好吧，为了方便伸手党，我给出穷举过程
                i      j
        爷爷  父亲  儿子  儿子与爷爷
               0      0       (i + j)%3 = 0
               0      1       (i + j)%3 = 1
               0      2       (i + j)%3 = 2
               1      0       (i + j)%3 = 1
               1      1       (i + j)%3 = 2
               1      2       (i + j)%3 = 0
               2      0       (i + j)%3 = 2
               2      1       (i + j)%3 = 0
               2      2       (i + j)%3 = 1
        嗯，这样可以看到，( 儿子relation + 父亲relation ) % 3 = 儿子对爷爷的relation
        这就是路径压缩的节点算法
        (2) 集合间关系的确定
        在初始化的时候，我们看到，每个集合都是一个元素，就是他本身。
        这时候，每个集合都是自洽的（集合中每个元素都不违反题目的规定）
        注意，我们使用并查集的目的就是尽量的把路径压缩，使之高度尽量矮
        假设我们已经有一个集合
        set1 = {1,2,7,10}
        set2 = {11,4,8,13},每个编号所属的物种见上文
        set3 = {12,5,4,9}
        现在有一句话
        2 13 2
        这是一句真话,X = 13,Y = 2
        我们要把这两个集合合并成一个集合。
        直接
        int a = findParent(ani[X]);
        int b = findParent(ani[Y]);
        ani[b].parent = a;
        就是把Y所在集合的根节点的父亲设置成X所在集合的根节点。
        但是，但是！！！！
        Y所在集合的根结点与X所在集合的根节点的关系！！！要怎么确定呢？
        我们设X,Y集合都是路径压缩过的，高度只有2层
        我们先给出计算的公式
        ani[b].relation = ( 3 - ani[Y].relation + ( d - 1 ) + ani[X].relation) % 3;
        这个公式，是分三部分，这么推出来的
        第一部分，好理解的一部分：
        ( d - 1 ) :这是X和Y之间的relation，X是Y的父节点时，Y的relation就是这个
        3 - ani[Y].relation = 根据Y与根节点的关系，逆推根节点与Y的关系
        这部分也是穷举法推出来的，我们举例：
        j
        子         父相对于子的relation（即假如子是父的父节点，那么父的relation应该是什么，因为父现在是根节点，所以父.relation = 0，我们只能根据父的子节点反推子跟父节点的关系）
         0             ( 3 - 0 ) % 3 = 0
         1（父吃子）   ( 3 - 1 ) % 3 = 2 //父吃子
         2（子吃父)    ( 3 - 2 ) % 3 = 1 //子吃父，一样的哦亲
        ——————————————————————————————————————————————————————
        我们的过程是这样的：
        把ani[Y]，先连接到ani[X]上，再把ani[Y]的根节点移动到ani[X]上，最后，把ani[Y]的根节点移动到ani[X]的根节点上，这样算relation的
        还记得么，如果我们有一个集合，压缩路径的时候父子关系是这么确定的
        ani[爷爷].relation = ( ani[父亲].relation + ani[儿子].relation ) % 3
        我们已知道,( d - 1 )就是X与Y的relation了
        而 (3 - ani[Y].relation)就是 以Y为根节点时，他的父亲的relation
        那么
        我们假设把Y接到X上，也就说，现在X是Y的父亲，Y原来的根节点现在是Y的儿子
          Y的relation   +     ani[Y]根节点相对于ani[Y]的relation
        ( ( d - 1 )         +    ( 3 - ani[Y].relation) ) % 3
        就是ani[Y]的父亲节点与ani[X]的relation了！
        那么，不难得到，ani[Y]的根节点与ani[X]根节点的关系是：
        ( ( d - 1 ) + ( 3 - ani[Y].relation) + ani[X].relation ) % 3 ->应用了同余定理
        注意，这个当所有集合都是初始化状态的时候也适用哦
        还是以最开头我们给的三个集合（分别代表三个物种）为例
        2 1 6
        带入公式
        ani[6].relation = ( ( 2 - 1 ) + ( 3 - 0 ) + 0 ) % 3 = 1
        也就是，6被1吃
    Part III - 算法正确性的证明
        首先，两个自洽的集合，合并以后仍然是自洽的
        这个不难想吧，数学上有个什么对称性定理跟他很像的。
        如果理解不了，就这么想！！
        当set1和set2合并之后，set2的根节点得到了自己关于set1根节点的
        正确relation值，变成了set1根节点的儿子，那么
        set2的所有儿子只要用
        ( ani[X].relation + ani[Y].relation ) % 3就能得到自己正确的relation值了
        所以说，针对不在同一集合的两个元素的话，除非违背了（2）和（3），否则永远是真的
        （无论这句话说的是什么，我们都可以根据所给X,Y推出两个子节点之间应有的关系，这个关系一确定，所有儿子的关系都可以确定）
        其实所有的不同集合到最后都会被合并成一个集合的。
        我们只要在一个集合中找那些假话就可以了。
        首先，如何判断
        1 X Y是不是假话。//此时 d = 1
        if ( X 和 Y 不在同一集合)
            Union(x,y,xroot,yroot,d)
        else
            if x.relation != y.relation  ->假话
        其次，如何判断
        2 X Y是不是假话 //此时d = 2
        if ( X 和 Y 不在同一集合）
            Union(x,y,xroot,yroot,d)
        else
            (ani[y].relation + 3 - ani[x].relation ) % 3 != 1 ->假话
        这个公式是这么来的：
        3 - ani[x].relation得到了根节点关于x的relation
        ani[y] + 3 - ani[x].relation得到了y关于x的relation
        所以，只要y关于x的relation不是1，就是y不被x吃的话，这句话肯定是假话！
        (2)路径压缩要特别注意的一点（错在这里，要检讨自己）
            路径压缩的时候，记得要
            先findParent，再给当前节点的relation赋值。
            否则有可能因为当前节点的父节点的relation不正确而导致错的稀里哗啦。
            例子：
            set1 = {1,2,7,10}
            set2 = {3,4,8,11}
            set3 = {12,5,14,9}
            Union(1,3,1,3,1)
            Union(3,12,3,12,2)
            1 5 1
            算5的relation
            如果不先更新parent的relation，算出来应该是
            ( 3 - 0 + 0 + 1 ) % 3 = 1，5被1吃，显然不对
            这里面，+ 0的那个0是指根节点 12 的relation（未更新，这里的0是指12与11的relation）
            如果更新完了的话，应该是
            ( 3 - 0 + 2 + 1 ) % 3 = 0 ,5与1是同一物种，对了
            这里面的 2 是更新节点12的relation（12与1的relation）
    后记：
        关于这道题，我在网上搜索了许多解题报告，但是都闪烁其词，大概大家都不想
        把自己辛辛苦苦推出来的公式写到网上供别人学习来节省时间吧。
        我觉得这么做不好，对初学者容易产生不良影响，ACM如果只是一个小众化的圈子，那
        岂不是太没意思了。
        于是我就把我自己总结的这道题的经验放了出来，希望可以帮得到大家
        自己总结的，对错也不知道，但是起码是“自洽”的，^ ^
        感谢那篇博文的博主，也感谢gzm,lqy两位学长的指导。
        c0de4fun
*/
using namespace std;
const int c0de4fun = 50010;//动物个数的最大值
///指明父节点与自己的关系，0同类，1被吃，2吃父
const int SAME = 0;
const int ENEMY = 1;
const int FOOD = 2;
struct Animal
{
    int parent;
    int num;
    int relation;
};
Animal ani[c0de4fun];
long ans;
int findParent(Animal* node)
{
    ///Wrong Answer 因为这个函数写错了
    ///这个函数得是“自洽的”
    ///就是说，得保证每个元素的父亲的relation是对的
    ///再算自己的relation
    ///因为自己的relation和父亲的relation有关
    ///这就是为什么要先findParent再relation更新的原因
    int tmp;
    if( node->parent == node->num )
        return node->parent;
    tmp = node->parent;
#ifdef DBG
    printf("Animal %d s Parent is %d\n",node->num,node->parent);
#endif
   // node->relation = ( ani[node->parent].relation + node->relation ) % 3;
    node->parent = findParent(&ani[node->parent]);
    node->relation = ( ani[tmp].relation + node->relation ) % 3;
    return node->parent;
}
void Union(int x,int y,int a,int b,int d)
{
    ani[b].parent = a;
    ///rootY.parent = rootX.parent;
    ani[b].relation =( (3 - ani[y].relation) + (d - 1) + ani[x].relation) % 3;
}
 
void init_Animal(int n)
{
    for(int i = 1 ; i <= n ; i++)
    {
        ani[i].num = i;
        ani[i].parent = i;
        ani[i].relation = SAME;
    }
}
int main(int argc,char* argv[])
{
    int N,K;
    int d,X,Y;
#ifdef INPUT
    freopen("b:\\acm\\poj1182\\input.txt","r",stdin);
#endif
    scanf("%d%d",&N,&K);
    init_Animal(N);
    for(int i = 0 ; i < K ; i++)
    {
        scanf("%d%d%d",&d,&X,&Y);
        if( X > N || Y > N)
            ans++;
        else
        {
            if(d == 2 && X == Y)
                ans++;
            else
            {
                int a = findParent(&ani[X]);
                int b = findParent(&ani[Y]);
                if ( a != b )
                {
                    ///x，y不在同一集合中
                    Union(X,Y,a,b,d);
                }
                else
                {
                    switch(d)
                    {
                        case 1:
                            if(ani[X].relation != ani[Y].relation)
                                ans++;
                            break;
                        case 2:
                            if(((ani[Y].relation + 3 - ani[X].relation) % 3 ) != 1)
                                ans++;
                            break;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}