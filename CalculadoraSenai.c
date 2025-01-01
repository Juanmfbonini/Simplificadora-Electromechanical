#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){

char RPM = get_char("Do you want to calculate RPM? ");

// RPM formula
    if(RPM == 'y' || RPM == 'Y'){
        // RPM formulas
        char Vrpm = get_char("With cutting speed? ");
            if(Vrpm == 'y' || Vrpm == 'Y'){
                int Vc = get_int("What is the cutting speed? ");
                int D = get_int("What is the diameter value? ");

                float z = ((float) Vc * 1000) / ((float) 3.1415 * (float) D); // 3.1415 is the value of pi
                printf("%.4fRPM\n", z);
            }
        if(Vrpm == 'n' || Vrpm == 'N'){
        // Formula with frequency and poles
            char Prpm = get_char("With frequency and number of poles? ");
            if(Prpm == 'Y' || Prpm == 'y'){
                int f = get_int("What is the frequency value? ");
                int p = get_int("What is the number of poles? ");

                float z = ((float) f * 120) / ((float) p);
                printf("%.2fRPM\n", z);
            }
            if(Prpm == 'N' || Prpm == 'n'){
        // Formula with frequency only
            char Frpm = get_char("With frequency only? ");
                if(Frpm == 'Y' || Frpm == 'y'){
                    int f = get_int("What is the frequency value? ");

                    float z = ((float) f * 60);
                    printf("%.2fRPM\n", z);
                }
                if(Frpm == 'N' || Frpm == 'n'){
        // Rotation formula
                    int w = get_int("What is the rotation value? ");

                    float z = ((float) 30 * w) / 3.1415;
                    printf("%.2fRPM\n", z);
                }
            }
        }
    }
        // Electric Force Formula
    if(RPM == 'N' || RPM == 'n'){
      char FE = get_char("Do you want to calculate Electric Force? ");

        if(FE == 'Y' || FE == 'y'){
            char Q1 = get_char("What is the value of the first particle (use only the base number)? ");
            char Q2 = get_char("What is the value of the second particle (use only the base number)? ");
            char d = get_char("What is the distance value (use only the base number)? ");
            int Q1_power = get_int("What is the power value of the first particle? ");
            int Q2_power = get_int("What is the power value of the second particle? ");
            int d_power = get_int("What is the power value of the distance? ");

            if(d >= 3.2){
                char x = d_power + 1;
                double z = ((double) (float) Q1 * (double) (float) Q2 * 9) / ((double) (float) d * d);
                int h = (9 + Q1_power + Q2_power) - d_power + 1;

                printf("%.2f*10^%iN\n", z, h);
            }

            if(d < 3.2){
                double z = ((double) (float) Q1 * (double) (float) Q2 * 9) / ((double) (float) d * d);
                int h = (9 + Q1_power + Q2_power) - d_power;

                printf("%.2f*10^%iN\n", z, h);
        }
    }
    if(FE == 'N' || FE == 'n'){
        // Gravitational Force Formula
    char gravitational_force = get_char("Do you want to calculate Gravitational Force? ");
        if(gravitational_force == 'Y' || gravitational_force == 'y'){
            char M = get_char("What is the value of the first Mass (use only the base number)? ");
            char m = get_char("What is the value of the second mass (use only the base number)? ");
            char d = get_char("What is the distance value (use only the base number)? ");
            int M_power = get_int("What is the power value of the first mass? ");
            int m_power = get_int("What is the power value of the second mass? ");
            int d_power = get_int("What is the power value of the distance? ");

            if(d >= 3.2){
                char x = d_power + 1;
                double z = ((double) M * (double) m * 6.6743) / ((double) d * d);
                int h = ((-11) + M_power + m_power) - d_power + 1;

                printf("%.2f*10^%iN\n", z, h);
            }

            if(d < 3.2){
                double z = ((double) M * (double) m * 6.6743) / ((double) d * d);
                int h = ((-11) + M_power + m_power) - d_power;

                printf("%.2f*10^%iN\n", z, h);
        }
   }
    if(gravitational_force == 'N' || gravitational_force == 'n'){
        // Trigonometry Formula
        char trigonometry = get_char("Do you want to use Trigonometry? ");

        if(trigonometry == 'Y' || trigonometry == 'y'){
        // Pythagoras Formula
        char pythagoras = get_char("Do you want to use Pythagoras? ");
            if(pythagoras == 'Y' || pythagoras == 'y'){
                int A = get_int("What is the value of A? ");
                int B = get_int("What is the value of B? ");

                double C = sqrt((double) A * A + (double) B * B);
                printf("The value of C is %f\n", C);
            }
            if(pythagoras == 'N' || pythagoras == 'n'){
        // Sine Formula
        char sine = get_char("Do you want to use Sine? ");
            if(sine == 'Y' || sine == 'y'){
                int DegreesS = get_int("Do you want to calculate with how many degrees [30, 45, 60]?\n");
                    if(DegreesS == 30){
                        char Co = get_char("What is the value of the opposite side? ");
                        char H = get_char("What is the value of the Hypotenuse? ");

                        char Co2 = get_char("What do you want to find Opposite Side? ");
                        if(Co2 == 'y'|| Co2 == 'Y'){
                            double Opp_Side = (double) H * .5;
                            printf("The value of the Opposite Side is %f", Opp_Side);
                        }
                        else{
                            double Hyp = (double) Co / .5;
                            printf("The value of the Hypotenuse is %f", Hyp);
                        }
                    }
                    if(DegreesS == 45){
                        char Co = get_char("What is the value of the opposite side? ");
                        char H = get_char("What is the value of the Hypotenuse? ");

                        char Co2 = get_char("What do you want to find Opposite Side? ");
                        if(Co2 == 'y'|| Co2 == 'Y'){
                            double Opp_Side = (double) H * (sqrt(2)/2);
                            printf("The value of the Opposite Side is %f", Opp_Side);
                        }
                        else{
                            double Hyp = (double) Co / (sqrt(2)/2);
                            printf("The value of the Hypotenuse is %f", Hyp);
                        }
                    }
                    if(DegreesS == 60){
                        char Co = get_char("What is the value of the opposite side? ");
                        char H = get_char("What is the value of the Hypotenuse? ");

                       char Co2 = get_char("Do you want to find the Opposite Side? ");
if (Co2 == 'y' || Co2 == 'Y') {
    double Cat_O = (double)H * (sqrt(3) / 2);
    printf("The value of the Opposite Side is %f", Cat_O);
} else {
    double Hyp = (double)Co / (sqrt(3) / 2);
    printf("The value of the Hypotenuse is %f", Hyp);
}
}
}
if (sine == 'N' || sine == 'n') {
// Cosine Formula
char cosseno = get_char("Do you want to use Cosine? ");
if (cosseno == 'Y' || cosseno == 'y') {
    int GrausC = get_int("Do you want to calculate for how many degrees [30, 45, 60]?\n");
    if (GrausC == 30) {
        char Ca = get_char("What is the value of the adjacent side? ");
        char H = get_char("What is the value of the hypotenuse? ");

        char Ca2 = get_char("Do you want to find the Adjacent Side? ");
        if (Ca2 == 'y' || Ca2 == 'Y') {
            double Cat_A = (double)H * (sqrt(3) / 2);
            printf("The value of the Adjacent Side is %f", Cat_A);
        } else {
            double Hyp = (double)Ca / (sqrt(3) / 2);
            printf("The value of the Hypotenuse is %f", Hyp);
        }
    } else if (GrausC == 45) {
        char Ca = get_char("What is the value of the adjacent side? ");
        char H = get_char("What is the value of the hypotenuse? ");

        char Ca2 = get_char("Do you want to find the Adjacent Side? ");
        if (Ca2 == 'y' || Ca2 == 'Y') {
            double Cat_A = (double)H * (sqrt(2) / 2);
            printf("The value of the Adjacent Side is %f", Cat_A);
        } else {
            double Hyp = (double)Ca / (sqrt(2) / 2);
            printf("The value of the Hypotenuse is %f", Hyp);
        }
    } else if (GrausC == 60) {
        char Ca = get_char("What is the value of the adjacent side? ");
        char H = get_char("What is the value of the hypotenuse? ");

        char Ca2 = get_char("Do you want to find the Adjacent Side? ");
        if (Ca2 == 'y' || Ca2 == 'Y') {
            double Cat_A = (double)H * .5;
            printf("The value of the Adjacent Side is %f", Cat_A);
        } else {
            double Hyp = (double)Ca / .5;
            printf("The value of the Hypotenuse is %f", Hyp);
        }
    }
}
if (cosseno == 'N' || cosseno == 'n') {
// Tangent Formula
char tangente = get_char("Do you want to use Tangent? ");
if (tangente == 'Y' || tangente == 'y') {
    char GrausT = get_char("Do you want to calculate for how many degrees [30, 45, 60]?\n");
    if (GrausT == 30) {
        char Co = get_char("What is the value of the opposite side? ");
        char Ca = get_char("What is the value of the adjacent side? ");

        char Co2 = get_char("Do you want to find the Opposite Side? ");
        if (Co2 == 'y' || Co2 == 'Y') {
            double Cat_O = (double)Ca * (sqrt(3) / 3);
            printf("The value of the Opposite Side is %f", Cat_O);
        } else {
            double Cat_A = (double)Ca / (sqrt(3) / 3);
            printf("The value of the Adjacent Side is %f", Cat_A);
        }
    } else if (GrausT == 45) {
        char Co = get_char("What is the value of the opposite side? ");
        char Ca = get_char("What is the value of the adjacent side? ");

        char Co2 = get_char("Do you want to find the Opposite Side? ");
        if (Co2 == 'y' || Co2 == 'Y') {
            double Cat_O = (double)Co * 1;
            printf("The value of the Opposite Side is %f", Cat_O);
        } else {
            double Cat_A = (double)Ca / 1;
            printf("The value of the Adjacent Side is %f", Cat_A);
        }
    } else if (GrausT == 60) {
        char Co = get_char("What is the value of the opposite side? ");
        char Ca = get_char("What is the value of the adjacent side? ");

        char Co2 = get_char("Do you want to find the Opposite Side? ");
        if (Co2 == 'y' || Co2 == 'Y') {
            double Cat_O = (double)Co * sqrt(3);
            printf("The value of the Opposite Side is %f", Cat_O);
        } else {
            double Cat_A = (double)Ca / sqrt(3);
            printf("The value of the Adjacent Side is %f", Cat_A);
        }
    }
}
}
}
if (trigonometry == 'N' || trigonometry == 'n') {
// Electric Resistance Formula
char Resistencia = get_char("Do you want to calculate Electric Resistance? ");
if (Resistencia == 'Y' || Resistencia == 'y') {
    int U = get_int("What is the Voltage value? \n");
    int I = get_int("What is the Current value? \n");
    float R = (float)U / (float)I;

    printf("The value of the resistance is %fΩ\n", R);
}
if (Resistencia == 'N' || Resistencia == 'n') {
// Electric Voltage Formula
char Tensao = get_char("Do you want to calculate Electric Voltage? ");
if (Tensao == 'Y' || Tensao == 'y') {
    int R = get_int("What is the Resistance value? \n");
    int I = get_int("What is the Current value? \n");

    float U = (float)R * (float)I;
    printf("The value of the Voltage is %fV\n", U);
}
if (Tensao == 'N' || Tensao == 'n') {
// Electric Current Formula
char Corrente = get_char("Do you want to calculate Electric Current? ");

if (Corrente == 'Y' || Corrente == 'y') {
    int U = get_int("What is the Voltage value? \n");
    int R = get_int("What is the Resistance value? \n");

    float I = (float)U * (float)R;
    printf("The value of the Current is %fA\n", I);
}
if (Corrente == 'N' || Corrente == 'n') {
    char Potencia = get_char("Do you want to calculate Power? ");
    if (Potencia == 'Y' || Potencia == 'y') {
        char basica = get_char("Do you want to use the Basic Power Formula? ");
        if (basica == 'Y' || basica == 'y') {
            float U = get_int("What is the Voltage value? ");
            float I = get_int("What is the Current value? ");

            float P = (float)U * (float)I;
            printf("The value of the Power is %f\n", P);
        }
    }
}
}
}
}
}
}
}
}
}
}
