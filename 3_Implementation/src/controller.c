#include<stdio.h>

struct controller{

char s[10];
double freq;
double sram;
double anl_ip;
double anl_op;
double dig_io;

}c[4];

int main()
{
    double con_freq;
    printf("enter the frequency in Mhz : ");
    scanf("%lf",&con_freq);

    double analogue_input;
    printf("\nenter the number of analogue input pins required : ");
    scanf("%lf",&analogue_input);

    double analogue_output;
    printf("\nenter the number of analogue output pins required : ");
    scanf("%lf",&analogue_output);

    double digital_io;
    printf("\nenter the number of digital pins required : ");
    scanf("%lf",&digital_io);

    double stat_ram;
    printf("\nenter the size of Static RAM required in KB : ");
    scanf("%lf",&stat_ram);

    c[0].s[10]="Arduino Uno";
    c[0].freq=16;
    c[0].sram=2;
    c[0].anl_ip=6;
    c[0].anl_op=0;
    c[0].dig_io=14;

    c[1].s[10]="Arduino Due";
    c[1].freq=84;
    c[1].sram=96;
    c[1].anl_ip=12;
    c[1].anl_op=2;
    c[1].dig_io=54;

    c[2].s[10]="Arduino Mega";
    c[2].freq=16;
    c[2].sram=8;
    c[2].anl_ip=16;
    c[2].anl_op=0;
    c[2].dig_io=54;

    c[3].s[10]="Arduino Leonardo";
    c[3].freq=16;
    c[3].sram=2.5;
    c[3].anl_ip=12;
    c[3].anl_op=0;
    c[3].dig_io=20;

    int a=controller_choice(con_freq,analogue_input,analogue_output,digital_io,stat_ram);

    if(a==1)
    {
        printf("above mentioned controller/s are recommended for you");
    }
    else
    {
        printf("sorry no controllers found according your needs");
    }

}

int controller_choice(double freq,double anl_ip,double anl_op,double dig,double ram)
{
    int i,flag=0;
    for(i=0;i<4;i++)
    {
        if(freq<=c[i].freq && anl_ip<=c[i].anl_ip && anl_op<=c[i].anl_op && dig<=c[i].dig_io && ram<=c[i].sram)
        {
            flag=1;
            printf("\n %s is your one of the best choice\n",c[i].s);
            printf("\n %lf Mhz frequency",c[i].freq);
            printf("\n %lf analogue input pins",c[i].anl_ip);
            printf("\n %lf analogue output pins",c[i].anl_op);
            printf("\n %lf digital pins",c[i].dig_io);
            printf("\n %lf SRAM",c[i].sram);
        }
    }
    if(flag==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
