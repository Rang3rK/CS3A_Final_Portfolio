#include "Portfolio.h"
#include "GreenCircle.h"
#include "BouncingBall.h"
#include "ProgramCal.h"
#include "Clock.h"
#include "PokerDisplay.h"
#include "Screen.h"

int main() {


    GreenCircle gc;
    BouncingBall bb;
    ProgramCal pc;
    Clock cl;
    PokerDisplay pd;
    Screen srn; ///snake
    Portfolio pf;

    pf.load(gc);
    pf.load(bb);
    pf.load(pc);
    pf.load(cl);
    pf.load(pd);
    pf.load(srn);

    pf.run();

    return 0;
}

