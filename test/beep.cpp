#include <iostream>
#include <windows.h>

using namespace std;

enum fy
{
        d1 = 262, d1_ = 277, d2 = 294, d2_ = 311, d3 = 330, d4 = 349, d5 = 392, d5_= 415,
        d6 = 440, d6_= 466, d7 = 494, z1 = 523, z1_ = 554, z2 = 578, z2_ = 622, z3 = 659,
        z4 = 698, z4_ = 740, z5 = 784, z5_ = 831, z6 = 880, z6_ = 932, z7 = 988, g1 = 1046,
        g1_ = 1109, g2 = 1175, g2_ = 1245, g3 = 1318, g4 = 1397, g4_ = 1480,
        g5 = 1568, g5_ = 1661, g6 = 1760, g6_ = 1865, g7 = 1976, yaya = 0
};

struct yf
{
        enum fy s;
        int t;
};

int main()
{
        struct yf a[1000]=
        {
                {z6,50},{z7,50},{g1,150},{z7,50},{g1,100}, //5
                {g3,100},{z7,300},{z3,100},{z6,150},{z5,50}, //10
                {z6,100},{g1,100},{z5,300},{z2,50},    //14
                {z3,50},{z4,150},{z3,50},{z4,50},{g1,150}, //19
                {z3,150},{z2,50},{z3,50},{g1,150},{z7,150}, //24
                {z4_,50},{z4_,100},{z7,100},{z7,200},{z6,50}, //29
                {z7,50},{g1,150},{z7,50},{g1,100},{g3,100}, //34
                {z7,200},{z3,100},{z6,150},      //37
                {z5,50},{z6,100},{g1,100},{z5,300},{z3,100},{z4,100},{g1,50}, //44
                {z7,150},{g1,100},{g2,100},      //47
                {g3,50},{g1,150},{g1,50},{z7,50},{z6,100},{z7,100},{z5_,100}, //54
                {z6,300},{g1,50},{g2,50},   //57
                {g3,150},{g2,50},{g3,100},{g5,100},{g2,300},{z5,100}, //63
                {g1,150},{z7,50},{g1,100},{g3,100},{g3,300},{z6,50},{z7,50},{g1,150}, //71
                {z7,50},{g1,100},{g2,100},{g1,150},{z5,50}, //76
                {z5,200},{g4,100},{g3,100},{g2,100},{g1,100}, //81
                {g3,400},{yaya,50},{g3,50},{g6,200},{g5,100},{g5,100},{g3,50}, //88
                {g2,50},{g1,100},{yaya,50},{g1,50},{g2,100},{g1,50},{g2,100},{g5,100}, //96
                {g3,200},{yaya,50},{g3,50},{g6,200},{g5,200},{g3,50},{g2,50}, //103
                {g1,200},{yaya,50},{g1,50},{g2,100},{g1,50},{g2,100},{z7,100}, //110
                {z6,200},{yaya,100},{z6,50},{z7,50},{z6,500}
        };
        struct yf *atop;
        atop = a;
        int n = 194;
        while(n--)
        {
                Beep(atop->s,atop->t*5);
                atop++;
        }
        return 0;
}