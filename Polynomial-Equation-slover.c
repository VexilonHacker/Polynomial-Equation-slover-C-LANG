#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void write_poly(int a,int b,int c,int ch){
    if (ch != 0 && ch != 1){
        printf("CH INVALAID\n");
        exit(0);
    }
    char signe_b[8];
    char signe_c[8];

    if (b > 0) {
        sprintf(signe_b, "+ %d", b);
    } else {
        sprintf(signe_b, "%d", b);
    }

    if (c > 0) {
        sprintf(signe_c, "+ %d", c);
    } else {
        sprintf(signe_c, "%d", c);
    }

    if (ch == 0){
        printf("\nP(X) = %dx² %sx %s\n", a, signe_b, signe_c);
    } else {
        printf("\nf(X) = %dx² %sx %s\n", a, signe_b, signe_c);
    }
}

void polynome(int a, int b, int c) {
    write_poly(a,b,c,0);
    float delta = (b * b) - (4 * a * c);
    printf("Delta = %.2lf\n\n", delta);

    if (delta > 0) {
        float x1 = ((-1 * b) - sqrt(delta)) / (2.0 * a);
        float x2 = ((-1 * b) + sqrt(delta)) / (2.0 * a);
        printf("Solution of P(x): S = {%.2lf, %.2lf}\n", x1, x2);
    } else if (delta == 0) {
        float x1 = (-1 * b) / (2.0 * a);
        printf("Solution of P(x): S = {%.2lf}\n", x1);
    } else {
        printf("Solution of P(x) = ø\n");
    }
}

void parabole(int a,int b,int c){
    float x = (-1 * b) / (2.0 * a);
    float y = (a * x * x) + (b * x) + c;
    char res[18];
    sprintf(res,"Ω (%.2f,%.2f)\n",x,y);
    printf("%s",res);
    if (a >0){
        printf("Sign of a = %d > 0 \n",a);
    }else if (a < 0) {
        printf("Sign of a = %d < 0 \n",a);
    }
}

void greeting() {
    printf("╔═══════════════════╗\n");
    printf("║  Polynome Solver  ║\n");
    printf("╚═══════════════════╝\n");
}

int main() {
    greeting();
    int a, b, c;
    printf("Enter \"a\" Value: ");
    scanf("%d", &a);
    printf("Enter \"b\" Value: ");
    scanf("%d", &b);
    printf("Enter \"c\" Value: ");
    scanf("%d", &c);

    polynome(a,b,c);
    return 0;
}

