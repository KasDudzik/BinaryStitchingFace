#include "binary_stitch.h"

int * convertToBinary(int n) {
    static int a[6];
    int i;
    for(i=0; n>0; i++)    
    {    
        a[i]={n%2};    
        n= n/2;
    }
    if(i != 5){
        for(;i<6; i++){
            a[i]=0;
        }
    }
    return a;
}

void BinaryStitch::drawWatchFace(){
    const int lineLength = 27, space = 24;
    display.fillScreen(GxEPD_BLACK);
    display.setTextColor(GxEPD_WHITE);
    display.setFont(&Px437_IBM_BIOS10pt7b);
    int *hourArr;
    hourArr = convertToBinary(currentTime.Hour);
    display.setCursor(20, 20);
    int hourPositionCount = 0;
    // Drawing hour lines
    for(int i=5; i>=0; i--){
        display.setCursor(45 + 25*hourPositionCount, 30);
        display.print(hourArr[i]);
        for(int j=0; j<6; j++){
            if(hourArr[i] == 1){
                if(j%2 == 0){
                   display.writeFastVLine(55 + space*hourPositionCount, 34+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(56 + space*hourPositionCount, 34+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(57 + space*hourPositionCount, 34+space*j, lineLength, GxEPD_WHITE);
                }
            }
            if(hourArr[i] == 0){
                if(j%2 != 0){
                   display.writeFastVLine(55 + space*hourPositionCount, 34+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(56 + space*hourPositionCount, 34+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(57 + space*hourPositionCount, 34+space*j, lineLength, GxEPD_WHITE);
                }
            }
        }
        hourPositionCount++;
    }
    int *minuteArr;
    minuteArr = convertToBinary(currentTime.Minute);
    int minutePositionCount = 0;
    // Drawing minute lines
    for(int i=5; i>=0; i--){
        display.setCursor(10, (40+25*(minutePositionCount+1)));
        display.println(minuteArr[i]);
        for(int j=0; j<6; j++){
            if(minuteArr[i] == 1){
                if(j%2 == 0){
                   display.writeFastHLine(31 + space*j, 58+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(31 + space*j, 59+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(31 + space*j, 60+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                }
            }
            if(minuteArr[i] == 0){
                if(j%2 != 0){
                   display.writeFastHLine(31 + space*j, 58+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(31 + space*j, 59+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(31 + space*j, 60+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                }
            }
        }
        minutePositionCount++;
    }
}

