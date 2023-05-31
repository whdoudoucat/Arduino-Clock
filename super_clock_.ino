#include<LiquidCrystal.h>

LiquidCrystal lcd(7/*rs*/,6/*en*/,5/*d4*/,4/*d5*/,3/*d6*/,2/*d7*/);

long timer=0;
int timerloss;
int year=2023;
char seco=0;
char minu=0;
char hour=0;
char week=1;
char date=1;
char moth=1;
int mode=0;
int val[14];
int oldval[14];

void setup()
{
    lcd.begin(16,2);
    lcd.clear();
    pinMode(13,OUTPUT);
    pinMode(12,INPUT_PULLUP);
    pinMode(11,INPUT_PULLUP);
    pinMode(10,INPUT_PULLUP);
    pinMode(9,INPUT_PULLUP);
}

int checkbutton(int PIN)
{
    val[PIN]=digitalRead(PIN);
    if((val[PIN] == LOW) && (oldval[PIN] == HIGH))
    {
        oldval[PIN] = val[PIN];
        return 1;
    }
    oldval[PIN] = val[PIN];
    return 0;
}

void checktime()
{
    if(seco>59)
    {
        seco=0;
        minu++;
    }
    if(minu>59)
    {
        minu=0;
        hour++;
    }
    if(hour>23)
    {
        hour=0;
        date++;
        week++;
    }
    if(week>7)
    {
        week=1;
    }
    switch(moth)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        if(date>31)
        {
            date=1;
            moth++;
        }
        break;
        case 4:case 6:case 9:case 11:
        if(date>30)
        {
            date=1;
            moth++;
        }
        break;
        case 2:
        if(year%4==0 && year%100!=0)
        {
            if(date>29)
            {
                date=1;
                moth++;
            }
        }
        else
        {
            if(year%400==0)
            {
                if(date>29)
                {
                    date=1;
                    moth++;
                }
            }
            else
            {
                if(date>28)
                {
                    date=1;
                    moth++;
                }
            }
        }
        break;
    }
}

void clock()
{
    checktime();
    lcd.setCursor(0,0);
    lcd.print(" ");
    lcd.print(year);
    lcd.print("--");
    if(moth<10)
    {
        lcd.print("0");
    }
    lcd.print((int)moth);
    lcd.print("--");
    if(date<10)
    {
        lcd.print("0");
    }
    lcd.print((int)date);
    lcd.setCursor(0,1);
    lcd.print(" ");
    if(hour<10)
    {
        lcd.print("0");
    }
    lcd.print((int)hour);
    lcd.print(":");
    if(minu<10)
    {
        lcd.print("0");
    }
    lcd.print((int)minu);
    lcd.print(":");
    if(seco<10)
    {
        lcd.print("0");
    }
    lcd.print((int)seco);
    lcd.print("   ");
    switch(week)
    {
        case 1:
        lcd.print("MON");
        break;
        case 2:
        lcd.print("TUE");
        break;
        case 3:
        lcd.print("WED");
        break;
        case 4:
        lcd.print("THU");
        break;
        case 5:
        lcd.print("FRI");
        break;
        case 6:
        lcd.print("SAT");
        break;
        case 7:
        lcd.print("SUN");
        break;
    }
}

void correctime()
{
    static int mode_ct=0;
    lcd.setCursor(0,0);
    lcd.print("Correct time ");
    if(mode_ct==0)
    {
        lcd.setCursor(0,1);
        lcd.print("SECOND:");
        if(seco<10)
    {
        lcd.print("0");
    }
        lcd.print((int)seco);
        if(checkbutton(10)==1)
        {
            seco++;
        }
    }
    if(mode_ct==1)
    {
        lcd.setCursor(0,1);
        lcd.print("MINUTE:");
        if(minu<10)
    {
        lcd.print("0");
    }
        lcd.print((int)minu);
        if(checkbutton(10)==1)
        {
            minu++;
        }
    }
    if(mode_ct==2)
    {
        lcd.setCursor(0,1);
        lcd.print("HOUR  :");
        if(hour<10)
    {
        lcd.print("0");
    }
        lcd.print((int)hour);
        if(checkbutton(10)==1)
        {
            hour++;
        }
    }
    if(mode_ct==3)
    {
        lcd.setCursor(0,1);
        lcd.print("DATE  :");
        if(date<10)
    {
        lcd.print("0");
    }
        lcd.print((int)date);
        if(checkbutton(10)==1)
        {
            date++;
        }
    }
    if(mode_ct==4)
    {
        lcd.setCursor(0,1);
        lcd.print("MONTH :");
        if(moth<10)
    {
        lcd.print("0");
    }
        lcd.print((int)moth);
        if(checkbutton(10)==1)
        {
            moth++;
        }
    }
    if(mode_ct==5)
    {
        lcd.setCursor(0,1);
        lcd.print("YEAR:");
        lcd.print((int)year);
        if(checkbutton(10)==1)
        {
            year++;
        }
    }
    if(mode_ct==6)
    {
        lcd.setCursor(0,1);
        lcd.print("WEEK:");
        if(week<10)
    {
        lcd.print("0");
    }
        lcd.print((int)week);
        if(checkbutton(10)==1)
        {
            week++;
        }
    }
    /*(checktime();*/
    if(seco>59)
    {
        seco=0;
    }
    if(minu>59)
    {
        minu=0;
    }
    if(hour>23)
    {
        hour=0;
    }
    if(week>7)
    {
        week=1;
    }
    switch(moth)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        if(date>31)
        {
            date=1;
        }
        break;
        case 4:case 6:case 9:case 11:
        if(date>30)
        {
            date=1;
        }
        break;
        case 2:
        if(year%4==0 && year%100!=0)
        {
            if(date>29)
            {
                date=1;
            }
        }
        else
        {
            if(year%400==0)
            {
                if(date>29)
                {
                    date=1;
                }
            }
            else
            {
                if(date>28)
                {
                    date=1;
                }
            }
        }
        break;
    }
    if(checkbutton(11)==1)
    {
        mode_ct++;
        lcd.setCursor(0,1);
        lcd.print("                ");
    }
    if(mode_ct>6)
    {
        mode_ct=0;
    }
}

void voltmeter()
{
    
}

void loop()
{
    timer=millis()+1000;
    seco++;
    timer -= timerloss;
    while(timer>millis())
    {
        switch(mode)
        {
            case 0:
            clock();
            break;
            case 1:
            correctime();
            break;
        }
        if(checkbutton(12)==1)
        {
            mode++;
            lcd.clean();
        }
        if(mode>1)
        {
            mode=0;
        }
        if(digitalRead(9)==LOW)
        {
            digitalWrite(13,HIGH);
        }
        else
        {
            digitalWrite(13,LOW);
        }
    }
    timerloss=millis()-timer;
}