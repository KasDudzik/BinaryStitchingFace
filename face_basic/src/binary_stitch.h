#include <Watchy.h>
#include "Px437_IBM_BIOS10pt7b.h"

class BinaryStitch : public Watchy{
    using Watchy::Watchy;
    public:
        void drawWatchFace();
        void drawHour(int);
        void drawMinute(int);
};