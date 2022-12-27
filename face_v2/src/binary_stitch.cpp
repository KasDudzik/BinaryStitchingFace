#include "binary_stitch.h"

int * convertToBinary(int n) {
    static int a[4];
    int i;
    for(i=0; n>0; i++)    
    {    
        a[i]={n%2};    
        n= n/2;
    }
    if(i != 4){
        for(;i<5; i++){
            a[i]=0;
        }
    }
    return a;
}

void BinaryStitch::drawWatchFace(){
    const int lineLength = 22, space = 19;
    display.fillScreen(GxEPD_BLACK);
    display.setTextColor(GxEPD_WHITE);
    display.setFont(&Px437_IBM_BIOS8pt7b);
    int *hourArrFstDigit, *hourArrScndDigit;
    hourArrFstDigit = convertToBinary(currentTime.Hour/10);
    int hourPositionCount = 0;
    for(int i = 3; i>=0; i--){
        display.setCursor(35 + 20*hourPositionCount, 23);
        display.print(hourArrFstDigit[i]);
        for(int j=0; j<8; j++){
            if(hourArrFstDigit[i] == 1){
                if(j%2 == 0){
                   display.writeFastVLine(45 + space*hourPositionCount, 26+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(46 + space*hourPositionCount, 26+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(47 + space*hourPositionCount, 26+space*j, lineLength, GxEPD_WHITE);
                }
            }
            if(hourArrFstDigit[i] == 0){
                if(j%2 != 0){
                   display.writeFastVLine(45 + space*hourPositionCount, 26+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(46 + space*hourPositionCount, 26+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(47 + space*hourPositionCount, 26+space*j, lineLength, GxEPD_WHITE);
                }
            }
        }
        hourPositionCount++;
    }
    hourArrScndDigit = convertToBinary(currentTime.Hour%10);
    for(int i = 3; i>=0; i--){
        display.setCursor(35 + 20*hourPositionCount, 23);
        display.print(hourArrScndDigit[i]);
        for(int j=0; j<8; j++){
            if(hourArrFstDigit[i] == 1){
                if(j%2 == 0){
                   display.writeFastVLine(45 + space*hourPositionCount, 26+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(46 + space*hourPositionCount, 26+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(47 + space*hourPositionCount, 26+space*j, lineLength, GxEPD_WHITE);
                }
            }
            if(hourArrFstDigit[i] == 0){
                if(j%2 != 0){
                   display.writeFastVLine(45 + space*hourPositionCount, 26+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(46 + space*hourPositionCount, 26+space*j, lineLength, GxEPD_WHITE);
                   display.writeFastVLine(47 + space*hourPositionCount, 26+space*j, lineLength, GxEPD_WHITE);
                }
            }
        }
        hourPositionCount++;
    }
    int *minuteArrFstDigit, *minuteArrScndDigit;
    minuteArrFstDigit = convertToBinary(currentTime.Minute/10);
    int minutePositionCount = 0;
    for(int i = 3; i>=0; i--){
        display.setCursor(9, 28+20*(minutePositionCount+1));
        display.print(minuteArrFstDigit[i]);
        for(int j=0; j<8; j++){
            if(minuteArrFstDigit[i] == 1){
                if(j%2 == 0){
                   display.writeFastHLine(26 + space*j, 45+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(26 + space*j, 46+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(26 + space*j, 47+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                }
            }
            if(minuteArrFstDigit[i] == 0){
                if(j%2 != 0){
                   display.writeFastHLine(26 + space*j, 45+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(26 + space*j, 46+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(26 + space*j, 47+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                }
            }
        }
        minutePositionCount++;
    }
    minuteArrScndDigit = convertToBinary(currentTime.Minute%10);
    for(int i = 3; i>=0; i--){
        display.setCursor(9, 28+20*(minutePositionCount+1));
        display.print(minuteArrScndDigit[i]);
        for(int j=0; j<8; j++){
            if(minuteArrFstDigit[i] == 1){
                if(j%2 == 0){
                   display.writeFastHLine(26 + space*j, 45+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(26 + space*j, 46+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(26 + space*j, 47+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                }
            }
            if(minuteArrFstDigit[i] == 0){
                if(j%2 != 0){
                   display.writeFastHLine(26 + space*j, 45+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(26 + space*j, 46+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                   display.writeFastHLine(26 + space*j, 47+space*minutePositionCount, lineLength, GxEPD_WHITE); 
                }
            }
        }
        minutePositionCount++;
    }
}

