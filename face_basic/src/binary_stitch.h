#include <Watchy.h>
#include "Px437_IBM_BIOS5pt7b.h"
#include "Px437_IBM_BIOS12pt7b.h"
#include "Px437_IBM_BIOS10pt7b.h"

class BinaryStitch : public Watchy{
    using Watchy::Watchy;
    public:
        void drawWatchFace();
};