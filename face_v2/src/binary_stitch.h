#include <Watchy.h>
#include "Px437_IBM_BIOS8pt7b.h"

class BinaryStitch : public Watchy{
    using Watchy::Watchy;
    public:
        void drawWatchFace();
        int drawHour(int, int);
        int drawMinute(int, int);
};